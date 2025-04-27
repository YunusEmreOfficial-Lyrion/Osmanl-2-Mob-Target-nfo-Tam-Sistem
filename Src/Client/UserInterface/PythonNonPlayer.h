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

// Arat

enum EMobResists

// Altına ekle -- Hepsini kopyaladım olanları geç, olmayanları ekle

            MOB_RESIST_SWORD,
            MOB_RESIST_TWOHAND,
            MOB_RESIST_DAGGER,
            MOB_RESIST_BELL,
            MOB_RESIST_FAN,
            MOB_RESIST_BOW,
            MOB_RESIST_FIRE,
            MOB_RESIST_ELECT,
            MOB_RESIST_MAGIC,
            MOB_RESIST_WIND,
            MOB_RESIST_POISON,
            MOB_RESISTS_MAX_NUM

// Not: Eğer enum EMobResists bu yoksa aşağıdakileri yap. Varsa yukardakini

// Arat

        enum EMobEnchants
        {   
            MOB_ENCHANT_CURSE,
            MOB_ENCHANT_SLOW,   
            MOB_ENCHANT_POISON,
            MOB_ENCHANT_STUN,   
            MOB_ENCHANT_CRITICAL,
            MOB_ENCHANT_PENETRATE,
            MOB_ENCHANTS_MAX_NUM
        };

// Altına ekle

        enum EMobResists
        {
            MOB_RESIST_SWORD,
            MOB_RESIST_TWOHAND,
            MOB_RESIST_DAGGER,
            MOB_RESIST_BELL,
            MOB_RESIST_FAN,
            MOB_RESIST_BOW,
            MOB_RESIST_FIRE,
            MOB_RESIST_ELECT,
            MOB_RESIST_MAGIC,
            MOB_RESIST_WIND,
            MOB_RESIST_POISON,
            MOB_RESISTS_MAX_NUM
        };
