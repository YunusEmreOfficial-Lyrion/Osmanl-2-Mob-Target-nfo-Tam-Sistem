// Ara

PyObject* netConnectToAccountServer(PyObject* poSelf, PyObject* poArgs)
{
	char* addr;
	if (!PyTuple_GetString(poArgs, 0, &addr))
		return Py_BuildException();

	int port;
	if (!PyTuple_GetInteger(poArgs, 1, &port))
		return Py_BuildException();

	char* account_addr;
	if (!PyTuple_GetString(poArgs, 2, &account_addr))
		return Py_BuildException();

	int account_port;
	if (!PyTuple_GetInteger(poArgs, 3, &account_port))
		return Py_BuildException();

	CAccountConnector& rkAccountConnector = CAccountConnector::Instance();
	rkAccountConnector.Connect(addr, port, account_addr, account_port);
	return Py_BuildNone();
}

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
PyObject* netTargetInfoLoad(PyObject* poSelf, PyObject* poArgs)
{
	DWORD dwVID;
	if (!PyArg_ParseTuple(poArgs, "i", &dwVID))
	{
		return Py_BuildException();
	}
	if (dwVID < 0)
	{
		return Py_BuildNone();
	}
	CPythonNetworkStream& rns = CPythonNetworkStream::Instance();
	rns.SendTargetInfoLoadPacket(dwVID);
	return Py_BuildNone();
}
#endif

//#####################/*/-*/-*/*-/-*/-*/-//-/ 「RcT 」YunusED || Metin2House /*/-*/-*/*-/-*/-*/-//-/#####################

// Ara

		{ "ToggleGameDebugInfo",				netToggleGameDebugInfo,					METH_VARARGS },

// Altına Ekle

#ifdef ENABLE_TARGET_INFORMATION_SYSTEM
		{ "SendTargetInfoLoad", 				netTargetInfoLoad, 						METH_VARARGS },
#endif

