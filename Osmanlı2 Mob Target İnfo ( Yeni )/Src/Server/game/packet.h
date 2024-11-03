// Arat
	// SUPPORT_BGM
	HEADER_GC_MAIN_CHARACTER3_BGM = 137,
	HEADER_GC_MAIN_CHARACTER4_BGM_VOL = 138,
	// END_OF_SUPPORT_BGM

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	HEADER_GC_TARGET_INFO = 140,
#endif

//#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

//Arat

	HEADER_CG_EMPIRE = 90,

	HEADER_CG_REFINE = 96,

// Üstüne Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	HEADER_CG_TARGET_INFO_LOAD = 89,
#endif

//#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

// Arat

typedef struct SPacketCGStateCheck
{
	BYTE header;
	unsigned long key;
	unsigned long index;
} TPacketCGStateCheck;

typedef struct SPacketGCStateCheck
{
	BYTE header;
	unsigned long key;
	unsigned long index;
	unsigned char state;
} TPacketGCStateCheck;

//Altına Ekle

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