// Arat

    HEADER_CG_GIVE_ITEM                         = 83,
	//HEADER_BLANK84								= 84,
	//HEADER_BLANK85								= 85,
	//HEADER_BLANK86								= 86,
	//HEADER_BLANK87								= 87,
	//HEADER_BLANK88								= 88,
	//HEADER_BLANK89								= 89,

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	HEADER_CG_TARGET_INFO_LOAD = 89,
#endif

//#####################//*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

// Tekrar arat

	// SUPPORT_BGM
	HEADER_GC_MAIN_CHARACTER3_BGM				= 137,
	HEADER_GC_MAIN_CHARACTER4_BGM_VOL			= 138,
	// END_OF_SUPPORT_BGM

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	HEADER_GC_TARGET_INFO = 140,
#endif

//#####################//*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

// Arat

typedef struct SChannelStatus
{
	short nPort;
	BYTE bStatus;
} TChannelStatus;

// Altına ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
typedef struct packet_target_info
{
	BYTE	header;
	DWORD	dwVID;
	DWORD	race;
	DWORD	dwVnum;
	BYTE	count;
} TPacketGCTargetInfo;
typedef struct packet_target_info_load
{
	BYTE header;
	DWORD dwVID;
} TPacketCGTargetInfoLoad;
#endif