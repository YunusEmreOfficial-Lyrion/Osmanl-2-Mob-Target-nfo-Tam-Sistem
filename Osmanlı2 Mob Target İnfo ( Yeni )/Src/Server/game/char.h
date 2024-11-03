// Ara

//////////////////////////////////////////////////////////////////////////////////
	// Basic Points

// Üstüne Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
private:
		DWORD			dwLastTargetInfoPulse;

public:
		DWORD			GetLastTargetInfoPulse() const { return dwLastTargetInfoPulse; }
		void			SetLastTargetInfoPulse(DWORD pulse) { dwLastTargetInfoPulse = pulse; }
#endif