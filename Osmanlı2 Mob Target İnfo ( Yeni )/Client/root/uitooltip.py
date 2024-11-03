## Arat

class ItemToolTip(ToolTip):

## Altına ekle

	if app.ENABLE_TARGET_INFORMATION_SYSTEM:
		isStone = False
		isBook = False
		isBook2 = False

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Arat

	def ClearToolTip(self):
		self.isShopItem = False
		if app.ENABLE_ATTENDANCE_EVENT:
			self.isAttendanceRewardItem = False
		if constInfo.ENABLE_HIGHLIGHT_TOOLTIP == 1:
			self.isHyperLinkItem = False
		self.toolTipWidth = self.TOOL_TIP_WIDTH
		ToolTip.ClearToolTip(self)

## Altına ekle

	if app.ENABLE_TARGET_INFORMATION_SYSTEM:
		def SetItemToolTipStone(self, itemVnum):
			self.itemVnum = itemVnum
			item.SelectItem(itemVnum)
			itemType = item.GetItemType()

			itemDesc = item.GetItemDescription()
			itemSummary = item.GetItemSummary()
			attrSlot = 0
			self.__AdjustMaxWidth(attrSlot, itemDesc)
			itemName = item.GetItemName()
			realName = itemName[:itemName.find("+")]
			self.SetTitle(realName + " +0 - +4")

			## Description ###
			self.AppendDescription(itemDesc, 26)
			self.AppendDescription(itemSummary, 26, self.CONDITION_COLOR)

			if item.ITEM_TYPE_METIN == itemType:
				self.AppendMetinInformation()
				self.AppendMetinWearInformation()

			for i in xrange(item.LIMIT_MAX_NUM):
				(limitType, limitValue) = item.GetLimit(i)

				if item.LIMIT_REAL_TIME_START_FIRST_USE == limitType:
					self.AppendRealTimeStartFirstUseLastTime(item, metinSlot, i)

				elif item.LIMIT_TIMER_BASED_ON_WEAR == limitType:
					self.AppendTimerBasedOnWearLastTime(metinSlot)

			self.ShowToolTip()

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

## Arat 

	def __SetNormalItemTitle(self):

## 1 tane var zaten komple değştir

	def __SetNormalItemTitle(self):
		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			if self.isStone:
				itemName = item.GetItemName()
				realName = itemName[:itemName.find("+")]
				self.SetTitle(realName + " +0 - +4")
			else:
				self.SetTitle(item.GetItemName())
		else:
			self.SetTitle(item.GetItemName())

## Not : ENABLE_WEAPON_EVOLUTION_SYSTEM sisteminiz varsa sanırım silah evrim sistemi alttaki kodu kullanın uyarlaması çünkü

	def __SetNormalItemTitle(self):
		if app.ENABLE_TARGET_INFORMATION_SYSTEM:
			if self.isStone:
				itemName = item.GetItemName()
				realName = itemName[:itemName.find("+")]
				self.SetTitle(realName + " +0 - +4")
			else:
				if app.ENABLE_WEAPON_EVOLUTION_SYSTEM:
					self.SetTitle(self.SILAH_EVRIM_TITLE[self.itemEvolution] % (localeInfo.SILAH_EVRIM_TEXT.get(self.itemEvolution,"") + item.GetItemName()))
				else:
					self.SetTitle(item.GetItemName())
		else:
			self.SetTitle(item.GetItemName())

#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

