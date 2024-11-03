// Arat

void CPythonNonPlayer::GetMatchableMobList(int iLevel, int iInterval, TMobTableList * pMobTableList)
{
	/*
		pMobTableList->clear();

		TNonPlayerDataMap::iterator itor = m_NonPlayerDataMap.begin();
		for (; itor != m_NonPlayerDataMap.end(); ++itor)
		{
			TMobTable * pMobTable = itor->second;

			int iLowerLevelLimit = iLevel-iInterval;
			int iUpperLevelLimit = iLevel+iInterval;

			if ((pMobTable->abLevelRange[0] >= iLowerLevelLimit && pMobTable->abLevelRange[0] <= iUpperLevelLimit) ||
				(pMobTable->abLevelRange[1] >= iLowerLevelLimit && pMobTable->abLevelRange[1] <= iUpperLevelLimit))
			{
				pMobTableList->push_back(pMobTable);
			}
		}
	*/
}


// Yukardaki arattaki fonksiyonun altına eklenecek } altına yani


#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
DWORD CPythonNonPlayer::GetMonsterMaxHP(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD dwMaxHP = 0;
		return dwMaxHP;
	}

	return c_pTable->dwMaxHP;
}

DWORD CPythonNonPlayer::GetMonsterRaceFlag(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD dwRaceFlag = 0;
		return dwRaceFlag;
	}

	return c_pTable->dwRaceFlag;
}

DWORD CPythonNonPlayer::GetMonsterLevel(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable * c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD level = 0;
		return level;
	}

	return c_pTable->bLevel;
}

DWORD CPythonNonPlayer::GetMonsterDamage1(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD range = 0;
		return range;
	}

	return c_pTable->dwDamageRange[0];
}

DWORD CPythonNonPlayer::GetMonsterDamage2(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD range = 0;
		return range;
	}

	return c_pTable->dwDamageRange[1];
}

DWORD CPythonNonPlayer::GetMonsterExp(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD dwExp = 0;
		return dwExp;
	}

	return c_pTable->dwExp;
}

float CPythonNonPlayer::GetMonsterDamageMultiply(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD fDamMultiply = 0;
		return fDamMultiply;
	}

	return c_pTable->fDamMultiply;
}

DWORD CPythonNonPlayer::GetMonsterST(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD bStr = 0;
		return bStr;
	}

	return c_pTable->bStr;
}

DWORD CPythonNonPlayer::GetMonsterDX(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD bDex = 0;
		return bDex;
	}

	return c_pTable->bDex;
}

bool CPythonNonPlayer::IsMonsterStone(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
	{
		DWORD bType = 0;
		return false;
	}

	return c_pTable->bType == 2;
}
BYTE CPythonNonPlayer::GetMobRegenCycle(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return 0;

	return c_pTable->bRegenCycle;
}

BYTE CPythonNonPlayer::GetMobRegenPercent(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return 0;

	return c_pTable->bRegenPercent;
}

DWORD CPythonNonPlayer::GetMobGoldMin(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return 0;

	return c_pTable->dwGoldMin;
}

DWORD CPythonNonPlayer::GetMobGoldMax(DWORD dwVnum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return 0;

	return c_pTable->dwGoldMax;
}

DWORD CPythonNonPlayer::GetMobResist(DWORD dwVnum, BYTE bResistNum)
{
	const CPythonNonPlayer::TMobTable* c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return 0;

	if (bResistNum >= MOB_RESISTS_MAX_NUM)
		return 0;

	return c_pTable->cResists[bResistNum];
}
#endif