// Ara
#include "DragonSoul.h"

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
#include <algorithm>
#include <iterator>
using namespace std;
#endif

//#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

// Ara

	memset(&m_tvLastSyncTime, 0, sizeof(m_tvLastSyncTime));
	m_iSyncHackCount = 0;



//Altına Ekle } den önce ekle 

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	dwLastTargetInfoPulse = 0;
#endif