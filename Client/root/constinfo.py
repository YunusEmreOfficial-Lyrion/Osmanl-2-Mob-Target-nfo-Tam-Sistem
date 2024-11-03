##Aratılır.

import app
import net

if app.ENABLE_REFINE_RENEWAL:
	IS_AUTO_REFINE = False
	AUTO_REFINE_TYPE = 0
	AUTO_REFINE_DATA = {
		"ITEM" : [-1, -1],
		"NPC" : [0, -1, -1, 0]
	}

## Altına Ekle

if app.ENABLE_TARGET_INFORMATION_SYSTEM:
	MONSTER_INFO_DATA = {}