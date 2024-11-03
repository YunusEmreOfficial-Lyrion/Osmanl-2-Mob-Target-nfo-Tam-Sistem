// Ara 
PyObject* nonplayerLoadNonPlayerData(PyObject* poSelf, PyObject* poArgs)
{
	char* szFileName;
	if (!PyTuple_GetString(poArgs, 0, &szFileName))
		return Py_BuildException();

	CPythonNonPlayer::Instance().LoadNonPlayerData(szFileName);
	return Py_BuildNone();
}

//Altına ekle


#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
PyObject* nonplayerGetMonsterMaxHP(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMonsterMaxHP(race));
}

PyObject* nonplayerGetRaceNumByVID(PyObject* poSelf, PyObject* poArgs)
{
	int iVirtualID;
	if (!PyTuple_GetInteger(poArgs, 0, &iVirtualID))
		return Py_BuildException();

	CInstanceBase* pInstance = CPythonCharacterManager::Instance().GetInstancePtr(iVirtualID);

	if (!pInstance)
		return Py_BuildValue("i", -1);

	const CPythonNonPlayer::TMobTable* pMobTable = CPythonNonPlayer::Instance().GetTable(pInstance->GetVirtualNumber());

	if (!pMobTable)
		return Py_BuildValue("i", -1);

	return Py_BuildValue("i", pMobTable->dwVnum);
}

PyObject* nonplayerGetMonsterRaceFlag(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMonsterRaceFlag(race));
}

PyObject* nonplayerGetMonsterLevel(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMonsterLevel(race));
}

PyObject* nonplayerGetMonsterDamage(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	DWORD dmg1 = rkNonPlayer.GetMonsterDamage1(race);
	DWORD dmg2 = rkNonPlayer.GetMonsterDamage2(race);

	return Py_BuildValue("ii", dmg1, dmg2);
}

PyObject* nonplayerGetMonsterExp(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMonsterExp(race));
}

PyObject* nonplayerGetMonsterDamageMultiply(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("f", rkNonPlayer.GetMonsterDamageMultiply(race));
}

PyObject* nonplayerGetMonsterST(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMonsterST(race));
}

PyObject* nonplayerGetMonsterDX(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMonsterDX(race));
}

PyObject* nonplayerIsMonsterStone(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.IsMonsterStone(race) ? 1 : 0);
}

PyObject* nonplayerGetMobRegenCycle(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMobRegenCycle(race));
}

PyObject* nonplayerGetMobRegenPercent(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMobRegenPercent(race));
}

PyObject* nonplayerGetMobGoldMin(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();
	return Py_BuildValue("i", rkNonPlayer.GetMobGoldMin(race));
}

PyObject* nonplayerGetMobGoldMax(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();
	return Py_BuildValue("i", rkNonPlayer.GetMobGoldMax(race));
}

PyObject* nonplayerGetMobResist(PyObject* poSelf, PyObject* poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	BYTE resistNum;
	if (!PyTuple_GetInteger(poArgs, 1, &resistNum))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();

	return Py_BuildValue("i", rkNonPlayer.GetMobResist(race, resistNum));
}
#endif

//#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

// Ara

		{ "GetMonsterName",				nonplayerGetMonsterName,			METH_VARARGS },

// Altına ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
		{ "GetRaceNumByVID",			nonplayerGetRaceNumByVID,			METH_VARARGS },
		{ "GetMonsterMaxHP",			nonplayerGetMonsterMaxHP,			METH_VARARGS },
		{ "GetMonsterRaceFlag",			nonplayerGetMonsterRaceFlag,		METH_VARARGS },
		{ "GetMonsterLevel",			nonplayerGetMonsterLevel,			METH_VARARGS },
		{ "GetMonsterDamage",			nonplayerGetMonsterDamage,			METH_VARARGS },
		{ "GetMonsterExp",				nonplayerGetMonsterExp,				METH_VARARGS },
		{ "GetMonsterDamageMultiply",	nonplayerGetMonsterDamageMultiply,	METH_VARARGS },
		{ "GetMonsterST",				nonplayerGetMonsterST,				METH_VARARGS },
		{ "GetMonsterDX",				nonplayerGetMonsterDX,				METH_VARARGS },
		{ "IsMonsterStone",				nonplayerIsMonsterStone,			METH_VARARGS },
		{"GetMobRegenCycle",			nonplayerGetMobRegenCycle,			METH_VARARGS},
		{"GetMobRegenPercent",			nonplayerGetMobRegenPercent,		METH_VARARGS},
		{"GetMobGoldMin",				nonplayerGetMobGoldMin,				METH_VARARGS},
		{"GetMobGoldMax",				nonplayerGetMobGoldMax,				METH_VARARGS},
		{"GetResist",					nonplayerGetMobResist,				METH_VARARGS},
#endif