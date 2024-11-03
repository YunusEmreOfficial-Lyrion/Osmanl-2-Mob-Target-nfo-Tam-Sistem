// Ara

	void		Fishing(LPCHARACTER ch, const char* c_pData);
	void		ItemGive(LPCHARACTER ch, const char* c_pData);
	void		Hack(LPCHARACTER ch, const char* c_pData);
	int			MyShop(LPCHARACTER ch, const char* c_pData, size_t uiBytes);

	void		Refine(LPCHARACTER ch, const char* c_pData);

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
		void		TargetInfoLoad(LPCHARACTER ch, const char* c_pData);
#endif