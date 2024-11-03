// Ara

static int __deposit_limit()
{
	return (1000*10000); // 1Ãµ¸¸
}

// Altýna ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
void CInputMain::TargetInfoLoad(LPCHARACTER ch, const char* c_pData)
{
	TPacketCGTargetInfoLoad* p = (TPacketCGTargetInfoLoad*)c_pData;
	TPacketGCTargetInfo pInfo;
	pInfo.header = HEADER_GC_TARGET_INFO;
	static std::vector<LPITEM> s_vec_item;
	s_vec_item.clear();
	LPITEM pkInfoItem;
	LPCHARACTER m_pkChrTarget = CHARACTER_MANAGER::instance().Find(p->dwVID);
	if (!ch || !m_pkChrTarget)
		return;
	if (!ch->GetDesc())
		return;
	if (ITEM_MANAGER::instance().CreateDropItemVector(m_pkChrTarget, ch, s_vec_item) && (m_pkChrTarget->IsMonster() || m_pkChrTarget->IsStone()))
	{
		if (s_vec_item.size() == 0);
		else if (s_vec_item.size() == 1)
		{
			pkInfoItem = s_vec_item[0];
			pInfo.dwVID = m_pkChrTarget->GetVID();
			pInfo.race = m_pkChrTarget->GetRaceNum();
			pInfo.dwVnum = pkInfoItem->GetVnum();
			pInfo.count = pkInfoItem->GetCount();
			ch->GetDesc()->Packet(&pInfo, sizeof(TPacketGCTargetInfo));
		}
		else
		{
			int iItemIdx = s_vec_item.size() - 1;
			while (iItemIdx >= 0)
			{
				pkInfoItem = s_vec_item[iItemIdx--];
				if (!pkInfoItem)
				{
					sys_err("pkInfoItem NULL in vector idx %d", iItemIdx + 1);
					continue;
				}
				pInfo.dwVID = m_pkChrTarget->GetVID();
				pInfo.race = m_pkChrTarget->GetRaceNum();
				pInfo.dwVnum = pkInfoItem->GetVnum();
				pInfo.count = pkInfoItem->GetCount();
				ch->GetDesc()->Packet(&pInfo, sizeof(TPacketGCTargetInfo));
			}
		}
	}
}
#endif

//#####################/*/-*/-*/*-/-*/-*/-//-/ ?RcT ?YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

//Arat

		case HEADER_CG_ITEM_MOVE:
			if (!ch->IsObserverMode())
				ItemMove(ch, c_pData);
			break;

// Üstüne ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	case HEADER_CG_TARGET_INFO_LOAD:
		TargetInfoLoad(ch, c_pData);
		break;
#endif