// Ara
		const char*			GetMonsterName(DWORD dwVnum);

//Ekle Altına

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
	DWORD				GetMonsterMaxHP(DWORD dwVnum);
	DWORD				GetMonsterRaceFlag(DWORD dwVnum);
	DWORD				GetMonsterLevel(DWORD dwVnum);
	DWORD				GetMonsterDamage1(DWORD dwVnum);
	DWORD				GetMonsterDamage2(DWORD dwVnum);
	DWORD				GetMonsterExp(DWORD dwVnum);
	float				GetMonsterDamageMultiply(DWORD dwVnum);
	DWORD				GetMonsterST(DWORD dwVnum);
	DWORD				GetMonsterDX(DWORD dwVnum);
	bool				IsMonsterStone(DWORD dwVnum);
	DWORD				GetMobResist(DWORD dwVnum, BYTE bResistNum);
	BYTE				GetMobRegenCycle(DWORD dwVnum);
	BYTE				GetMobRegenPercent(DWORD dwVnum);
	DWORD				GetMobGoldMin(DWORD dwVnum);
	DWORD				GetMobGoldMax(DWORD dwVnum);
#endif