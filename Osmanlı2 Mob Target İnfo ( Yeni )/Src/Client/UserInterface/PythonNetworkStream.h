//Arat

	bool RecvDamageInfoPacket();

//Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
		bool RecvTargetInfoPacket();

public:
		bool SendTargetInfoLoadPacket(DWORD dwVID);
protected:
#endif