// Arat

			Set(HEADER_GC_DRAGON_SOUL_REFINE, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));

// Altına ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
			Set(HEADER_GC_TARGET_INFO, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCTargetInfo), false));
#endif