## importlar arasına ekle

if app.ENABLE_TARGET_INFORMATION_SYSTEM:
	import item
	import uiToolTip
	def HAS_FLAG(value, flag):
		return (value & flag) == flag

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır.
class TargetBoard(ui.ThinBoard):

## Altına ekle.

	if app.ENABLE_TARGET_INFORMATION_SYSTEM:
		class InfoBoard(ui.ThinBoard):
			class ItemListBoxItem(ui.ListBoxExNew.Item):
				def __init__(self, width):
					ui.ListBoxExNew.Item.__init__(self)

					image = ui.ExpandedImageBox()
					image.SetParent(self)
					image.Show()
					self.image = image

					nameLine = ui.TextLine()
					nameLine.SetParent(self)
					nameLine.SetPosition(32 + 5, 0)
					nameLine.Show()
					self.nameLine = nameLine

					self.SetSize(width, 32 + 5)

				def LoadImage(self, image, name = None):
					self.image.LoadImage(image)
					self.SetSize(self.GetWidth(), self.image.GetHeight() + 5 * (self.image.GetHeight() / 32))
					if name != None:
						self.SetText(name)

				def SetText(self, text):
					self.nameLine.SetText(text)

				def RefreshHeight(self):
					ui.ListBoxExNew.Item.RefreshHeight(self)
					self.image.SetRenderingRect(0.0, 0.0 - float(self.removeTop) / float(self.GetHeight()), 0.0, 0.0 - float(self.removeBottom) / float(self.GetHeight()))
					self.image.SetPosition(0, - self.removeTop)

			MAX_ITEM_COUNT = 5

			EXP_BASE_LVDELTA = [
				1,  #  -15 0
				5,  #  -14 1
				10, #  -13 2
				20, #  -12 3
				30, #  -11 4
				50, #  -10 5
				70, #  -9  6
				80, #  -8  7
				85, #  -7  8
				90, #  -6  9
				92, #  -5  10
				94, #  -4  11
				96, #  -3  12
				98, #  -2  13
				100,	#  -1  14
				100,	#  0   15
				105,	#  1   16
				110,	#  2   17
				115,	#  3   18
				120,	#  4   19
				125,	#  5   20
				130,	#  6   21
				135,	#  7   22
				140,	#  8   23
				145,	#  9   24
				150,	#  10  25
				155,	#  11  26
				160,	#  12  27
				165,	#  13  28
				170,	#  14  29
				180,	#  15  30
			]

			RACE_FLAG_TO_NAME = {
				1 << 0  : localeInfo.TARGET_INFO_RACE_ANIMAL,
				1 << 1 	: localeInfo.TARGET_INFO_RACE_UNDEAD,
				1 << 2  : localeInfo.TARGET_INFO_RACE_DEVIL,
				1 << 3  : localeInfo.TARGET_INFO_RACE_HUMAN,
				1 << 4  : localeInfo.TARGET_INFO_RACE_ORC,
				1 << 5  : localeInfo.TARGET_INFO_RACE_MILGYO,
			}

			SUB_RACE_FLAG_TO_NAME = {
				1 << 11 : localeInfo.TARGET_INFO_RACE_ELEC,
				1 << 12 : localeInfo.TARGET_INFO_RACE_FIRE,
				1 << 13 : localeInfo.TARGET_INFO_RACE_ICE,
				1 << 14 : localeInfo.TARGET_INFO_RACE_WIND,
				1 << 15 : localeInfo.TARGET_INFO_RACE_EARTH,
				1 << 16 : localeInfo.TARGET_INFO_RACE_DARK,
			}

			STONE_START_VNUM = 28030
			STONE_LAST_VNUM = 28042

			BOARD_WIDTH = 250

			def __init__(self):
				ui.ThinBoard.__init__(self)

				self.HideCorners(self.LT)
				self.HideCorners(self.RT)
				self.HideLine(self.T)

				self.race = 0
				self.hasItems = False

				self.itemTooltip = uiToolTip.ItemToolTip()
				self.itemTooltip.HideToolTip()

				self.stoneImg = None
				self.stoneVnum = None
				self.lastStoneVnum = 0
				self.nextStoneIconChange = 0

				wndItem = ui.GridSlotWindow()
				wndItem.SetParent(self)
				wndItem.ArrangeSlot(0, 7, 5, 32, 32, 0, 0)
				wndItem.RefreshSlot()
				wndItem.SetSlotBaseImage("d:/ymir work/ui/public/Slot_Base.sub", 1.0, 1.0, 1.0, 1.0)
				wndItem.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
				wndItem.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
				wndItem.Hide()
				self.wndItem = wndItem
				self.itemArray = [0 for i in xrange(35)]
				self.itemVnums = [0 for i in xrange(35)]

				self.SetSize(self.BOARD_WIDTH, 0)

			def __del__(self):
				ui.ThinBoard.__del__(self)

			def __UpdatePosition(self, targetBoard):
				self.SetPosition(targetBoard.GetLeft() + (targetBoard.GetWidth() - self.GetWidth()) / 2, targetBoard.GetBottom() - 17)

			def Open(self, targetBoard, race):
				self.__LoadInformation(race)

				self.SetSize(self.BOARD_WIDTH, self.yPos + 10)
				self.__UpdatePosition(targetBoard)

				self.Show()

			def Refresh(self):
				self.__LoadInformation(self.race)
				self.SetSize(self.BOARD_WIDTH, self.yPos + 10)

			def Close(self):
				self.itemTooltip.HideToolTip()
				self.Hide()

			def __LoadInformation(self, race):
				self.yPos = 7
				self.children = []
				self.race = race
				self.stoneImg = None
				self.stoneVnum = None
				self.nextStoneIconChange = 0

				for i in xrange(35):
					self.wndItem.ClearSlot(i)
				self.itemArray = [0 for i in xrange(35)]
				self.itemVnums = [0 for i in xrange(35)]

				self.__LoadInformation_Default(race)
				self.__LoadInformation_Race(race)
				self.__LoadInformation_Resists(race)
				self.__LoadInformation_Drops(race)

			def __LoadInformation_Default_GetHitRate(self, race):
				attacker_dx = nonplayer.GetMonsterDX(race)
				attacker_level = nonplayer.GetMonsterLevel(race)

				self_dx = player.GetStatus(player.DX)
				self_level = player.GetStatus(player.LEVEL)

				iARSrc = min(90, (attacker_dx * 4 + attacker_level * 2) / 6)
				iERSrc = min(90, (self_dx * 4 + self_level * 2) / 6)

				fAR = (float(iARSrc) + 210.0) / 300.0
				fER = (float(iERSrc) * 2 + 5) / (float(iERSrc) + 95) * 3.0 / 10.0

				return fAR - fER

			def __LoadInformation_Default(self, race):
				self.AppendSeperator()
				self.AppendTextLine(localeInfo.TARGET_INFO_MAX_HP % localeInfo.NumberToString(nonplayer.GetMonsterMaxHP(race)))

				# calc att damage
				monsterLevel = nonplayer.GetMonsterLevel(race)
				fHitRate = self.__LoadInformation_Default_GetHitRate(race)
				iDamMin, iDamMax = nonplayer.GetMonsterDamage(race)
				iDamMin = int((iDamMin + nonplayer.GetMonsterST(race)) * 2 * fHitRate) + monsterLevel * 2
				iDamMax = int((iDamMax + nonplayer.GetMonsterST(race)) * 2 * fHitRate) + monsterLevel * 2
				iDef = player.GetStatus(player.DEF_GRADE) * (100 + player.GetStatus(player.DEF_BONUS)) / 100
				fDamMulti = nonplayer.GetMonsterDamageMultiply(race)
				iDamMin = int(max(0, iDamMin - iDef) * fDamMulti)
				iDamMax = int(max(0, iDamMax - iDef) * fDamMulti)
				if iDamMin < 1:
					iDamMin = 1
				if iDamMax < 5:
					iDamMax = 5
				self.AppendTextLine(localeInfo.TARGET_INFO_DAMAGE % (localeInfo.NumberToString(iDamMin), localeInfo.NumberToString(iDamMax)))

				idx = min(len(self.EXP_BASE_LVDELTA) - 1, max(0, (monsterLevel + 15) - player.GetStatus(player.LEVEL)))
				iExp = nonplayer.GetMonsterExp(race) * self.EXP_BASE_LVDELTA[idx] / 100
				self.AppendTextLine(localeInfo.TARGET_INFO_EXP % localeInfo.NumberToString(iExp))

				# self.AppendTextLine(localeInfo.TARGET_INFO_GOLD_MIN_MAX % (localeInfo.NumberToString(nonplayer.GetMobGoldMin(race)), localeInfo.NumberToString(nonplayer.GetMobGoldMax(race))))
				self.AppendTextLine(localeInfo.TARGET_INFO_REGEN_INFO % (nonplayer.GetMobRegenPercent(race), nonplayer.GetMobRegenCycle(race)))


			def __LoadInformation_Race(self, race):
				dwRaceFlag = nonplayer.GetMonsterRaceFlag(race)
				self.AppendSeperator()

				mainrace = ""
				subrace = ""
				for i in xrange(17):
					curFlag = 1 << i
					if HAS_FLAG(dwRaceFlag, curFlag):
						if self.RACE_FLAG_TO_NAME.has_key(curFlag):
							mainrace += self.RACE_FLAG_TO_NAME[curFlag] + ", "
						elif self.SUB_RACE_FLAG_TO_NAME.has_key(curFlag):
							subrace += self.SUB_RACE_FLAG_TO_NAME[curFlag] + ", "
				if nonplayer.IsMonsterStone(race):
					mainrace += localeInfo.TARGET_INFO_RACE_METIN + ", "
				if mainrace == "":
					mainrace = localeInfo.TARGET_INFO_NO_RACE
				else:
					mainrace = mainrace[:-2]
				if subrace == "":
					subrace = localeInfo.TARGET_INFO_NO_RACE
				else:
					subrace = subrace[:-2]

				self.AppendTextLine(localeInfo.TARGET_INFO_MAINRACE % mainrace)
				self.AppendTextLine(localeInfo.TARGET_INFO_SUBRACE % subrace)

			def __LoadInformation_Resists(self, race):
				self.AppendSeperator()
				self.AppendTextLine(localeInfo.TARGET_INFO_RESISTS)
				self.AppendTextLine(localeInfo.TARGET_INFO_RESISTS_LINE0 % (nonplayer.GetResist(race, nonplayer.MOB_RESIST_SWORD), nonplayer.GetResist(race, nonplayer.MOB_RESIST_TWOHAND), nonplayer.GetResist(race, nonplayer.MOB_RESIST_BELL)))
				self.AppendTextLine(localeInfo.TARGET_INFO_RESISTS_LINE1 % (nonplayer.GetResist(race, nonplayer.MOB_RESIST_DAGGER), nonplayer.GetResist(race, nonplayer.MOB_RESIST_FAN), nonplayer.GetResist(race, nonplayer.MOB_RESIST_BOW)))

			def SerachEmptySlot(self, size):

				for value in xrange(self.slotSize):

					if 0 == self.itemArray[value]:	# ?????

						if 1 == size:
							return value

						emptySlotIndex	= value
						searchSucceed	= True

						for i in range(size - 1):
							emptySlotIndex = emptySlotIndex + 7

							if emptySlotIndex >= self.slotSize:
								searchSucceed = False
								continue

							if 1 == self.itemArray[emptySlotIndex]:
								searchSucceed = False

						if True == searchSucceed:
							return value

				return -1

			def __LoadInformation_Drops(self, race):
				self.AppendSeperator()

				if race in constInfo.MONSTER_INFO_DATA:
					if len(constInfo.MONSTER_INFO_DATA[race]["items"]) == 0:
						self.AppendTextLine(localeInfo.TARGET_INFO_NO_ITEM_TEXT)
					else:
						itemListBox = ui.ListBoxExNew(32 + 5, self.MAX_ITEM_COUNT)
						itemListBox.SetSize(self.GetWidth() - 15 * 2 - ui.ScrollBar.SCROLLBAR_WIDTH, (32 + 5) * self.MAX_ITEM_COUNT)
						height = 0
						for curItem in constInfo.MONSTER_INFO_DATA[race]["items"]:
							if curItem.has_key("vnum_list"):
								height += self.AppendItem(itemListBox, curItem["vnum_list"], curItem["count"])
							else:
								height += self.AppendItem(itemListBox, curItem["vnum"], curItem["count"])
						if height < itemListBox.GetHeight():
							itemListBox.SetSize(itemListBox.GetWidth(), height)
						self.AppendWindow(itemListBox, 15)
						itemListBox.SetBasePos(0)

						if len(constInfo.MONSTER_INFO_DATA[race]["items"]) > itemListBox.GetViewItemCount():
							itemScrollBar = ui.ScrollBar()
							itemScrollBar.SetParent(self)
							itemScrollBar.SetPosition(itemListBox.GetRight(), itemListBox.GetTop())
							itemScrollBar.SetScrollBarSize(32 * self.MAX_ITEM_COUNT + 5 * (self.MAX_ITEM_COUNT - 1))
							itemScrollBar.SetMiddleBarSize(float(self.MAX_ITEM_COUNT) / float(height / (32 + 5)))
							itemScrollBar.Show()
							itemListBox.SetScrollBar(itemScrollBar)
				else:
					self.AppendTextLine(localeInfo.TARGET_INFO_NO_ITEM_TEXT)

			def OverInItem(self, slotIndex):
				vnum = self.itemVnums[slotIndex]
				if vnum == 0 or vnum == 50300 or vnum == 70037:
					self.itemTooltip.HideToolTip()
				elif vnum > 27999 and vnum < 28960:
					self.itemTooltip.HideToolTip()
				else:
					self.OnShowItemTooltip(vnum)

			def OverOutItem(self):
				self.OnHideItemTooltip()

			def AppendTextLine(self, text):
				textLine = ui.TextLine()
				textLine.SetParent(self)
				textLine.SetWindowHorizontalAlignCenter()
				textLine.SetHorizontalAlignCenter()
				textLine.SetText(text)
				textLine.SetPosition(0, self.yPos)
				textLine.Show()

				self.children.append(textLine)
				self.yPos += 17

			def AppendSeperator(self):
				img = ui.ImageBox()
				img.LoadImage("d:/ymir work/ui/seperator.tga")
				self.AppendWindow(img)
				img.SetPosition(img.GetLeft(), img.GetTop() - 15)
				self.yPos -= 15

			def AppendItem(self, listBox, vnums, count):
				if type(vnums) == int:
					vnum = vnums
				else:
					vnum = vnums[0]

				item.SelectItem(vnum)
				itemName = item.GetItemName()
				if type(vnums) != int and len(vnums) > 1:
					vnums = sorted(vnums)
					realName = itemName[:itemName.find("+")]
					if item.GetItemType() == item.ITEM_TYPE_METIN:
						realName = localeInfo.TARGET_INFO_STONE_NAME
						itemName = realName + "+0 - +4"
					else:
						itemName = realName + "+" + str(vnums[0] % 10) + " - +" + str(vnums[len(vnums) - 1] % 10)
					vnum = vnums[len(vnums) - 1]

				myItem = self.ItemListBoxItem(listBox.GetWidth())
				myItem.LoadImage(item.GetIconImageFileName())
				if count <= 1:
					myItem.SetText(itemName)
				else:
					myItem.SetText("%dx %s" % (count, itemName))
				myItem.SAFE_SetOverInEvent(self.OnShowItemTooltip, vnum)
				myItem.SAFE_SetOverOutEvent(self.OnHideItemTooltip)
				listBox.AppendItem(myItem)

				if item.GetItemType() == item.ITEM_TYPE_METIN:
					self.stoneImg = myItem
					self.stoneVnum = vnums
					self.lastStoneVnum = self.STONE_LAST_VNUM + vnums[len(vnums) - 1] % 1000 / 100 * 100

				return myItem.GetHeight()

			def OnShowItemTooltip(self, vnum):
				item.SelectItem(vnum)
				if item.GetItemType() == item.ITEM_TYPE_METIN:
					self.itemTooltip.isStone = True
					self.itemTooltip.isBook = False
					self.itemTooltip.isBook2 = False
					self.itemTooltip.SetItemToolTip(self.lastStoneVnum)
				else:
					self.itemTooltip.isStone = False
					self.itemTooltip.isBook = True
					self.itemTooltip.isBook2 = True
					self.itemTooltip.SetItemToolTip(vnum)

			def OnHideItemTooltip(self):
				self.itemTooltip.HideToolTip()

			def AppendWindow(self, wnd, x = 0, width = 0, height = 0):
				if width == 0:
					width = wnd.GetWidth()
				if height == 0:
					height = wnd.GetHeight()

				wnd.SetParent(self)
				if x == 0:
					wnd.SetPosition((self.GetWidth() - width) / 2, self.yPos)
				else:
					wnd.SetPosition(x, self.yPos)
				wnd.Show()

				self.children.append(wnd)
				self.yPos += height + 5

			def OnUpdate(self):
				if self.stoneImg != None and self.stoneVnum != None and app.GetTime() >= self.nextStoneIconChange:
					nextImg = self.lastStoneVnum + 1
					if nextImg % 100 > self.STONE_LAST_VNUM % 100:
						nextImg -= (self.STONE_LAST_VNUM - self.STONE_START_VNUM) + 1
					self.lastStoneVnum = nextImg
					self.nextStoneIconChange = app.GetTime() + 2.5

					item.SelectItem(nextImg)
					itemName = item.GetItemName()
					realName = itemName[:itemName.find("+")]
					realName = realName + "+0 - +4"
					self.stoneImg.LoadImage(item.GetIconImageFileName(), realName)

					if self.itemTooltip.IsShow() and self.itemTooltip.isStone:
						self.itemTooltip.SetItemToolTip(nextImg)


#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır class TargetBoard(ui.ThinBoard) ın içinde sakın başka yere eklemeyin bi kaç tane var dikkat edin:
.

	def __init__(self):
		ui.ThinBoard.__init__(self)

		name = ui.TextLine()
		name.SetParent(self)
		name.SetDefaultFontName()
		name.SetOutline()
		name.Show()


## Altına eklenir.

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			infoButton = ui.Button()
			infoButton.SetParent(self)
			infoButton.SetUpVisual("d:/ymir work/ui/pattern/q_mark_01.tga")
			infoButton.SetOverVisual("d:/ymir work/ui/pattern/q_mark_02.tga")
			infoButton.SetDownVisual("d:/ymir work/ui/pattern/q_mark_01.tga")
			infoButton.SetEvent(ui.__mem_func__(self.OnPressedInfoButton))
			infoButton.Hide()

			infoBoard = self.InfoBoard()
			infoBoard.Hide()
			infoButton.showWnd = infoBoard

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır
		self.hpGauge = hpGauge

## Altına eklenir.

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.infoButton = infoButton
			self.vnum = 0

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır. 	def __Initialize(self): içinde

		self.vid = 0

## Altına eklenir.

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.vnum = 0

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Hemen altında tekrar aratılır 	def Destroy(self): içinde

		self.buttonDict = None
		self.name = None
		self.hpGauge = None

## Altına eklenir.

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.infoButton = None

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır  üst kısımda eklediğimizin hemen altında yani 	def Destroy(self): içinde

		self.__Initialize()

## Altına Eklenir.

	if app.ENABLE_TARGET_INFORMATION_SYSTEM:
		def RefreshMonsterInfoBoard(self):
			if not self.infoButton.showWnd.IsShow():
				return

			self.infoButton.showWnd.Refresh()

		def OnPressedInfoButton(self):
			net.SendTargetInfoLoad(player.GetTargetVID())
			if self.infoButton.showWnd.IsShow():
				self.infoButton.showWnd.Close()
			elif self.vnum != 0:
				self.infoButton.showWnd.Open(self, self.vnum)

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır

	def Close(self):
		self.__Initialize()


## Altına Eklenir.

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.infoButton.showWnd.Close()

##Örnek

	def Close(self):
		self.__Initialize()
		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.infoButton.showWnd.Close()
		self.Hide()

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır. 	def ResetTargetBoard(self): içinde bulacaksın

		self.hpGauge.Hide()

## Altına ekle

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.infoButton.Hide()
			self.infoButton.showWnd.Close()

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır.

	def SetTargetVID(self, vid):
		self.vid = vid

## Altına ekle

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			self.vnum = 0

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Aratılır.

	def SetEnemyVID(self, vid):
		self.SetTargetVID(vid)

		name = chr.GetNameByVID(vid)

## Altına ekle

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			vnum = nonplayer.GetRaceNumByVID(vid)

## aynı defin içinde tekrar arat 

		self.SetTargetName(nameFront + name)

## Altına ekle

		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			(textWidth, textHeight) = self.name.GetTextSize()

			self.infoButton.SetPosition(textWidth + 25, 12)
			self.infoButton.SetWindowHorizontalAlignLeft()

			self.vnum = vnum
			self.infoButton.Show()

## Örnek define 

	def SetEnemyVID(self, vid):
		self.SetTargetVID(vid)

		name = chr.GetNameByVID(vid)
		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			vnum = nonplayer.GetRaceNumByVID(vid)
		level = nonplayer.GetLevelByVID(vid)
		grade = nonplayer.GetGradeByVID(vid)

		nameFront = ""
		if -1 != level:
			nameFront += "Lv." + str(level) + " "
		if self.GRADE_NAME.has_key(grade):
			nameFront += "(" + self.GRADE_NAME[grade] + ") "

		self.SetTargetName(nameFront + name)
		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			(textWidth, textHeight) = self.name.GetTextSize()

			self.infoButton.SetPosition(textWidth + 25, 12)
			self.infoButton.SetWindowHorizontalAlignLeft()

			self.vnum = vnum
			self.infoButton.Show()
