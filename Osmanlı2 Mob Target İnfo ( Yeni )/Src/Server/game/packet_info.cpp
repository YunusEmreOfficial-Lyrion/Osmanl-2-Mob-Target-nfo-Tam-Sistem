// Ara

	Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck", false);

// Alternatif olarak çıkmassa bu şekil arayın

	Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck");


// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	Set(HEADER_CG_TARGET_INFO_LOAD, sizeof(TPacketCGTargetInfoLoad), "TargetInfoLoad");
#endif