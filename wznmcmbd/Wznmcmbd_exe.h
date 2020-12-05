/**
	* \file Wznmcmbd_exe.h
	* Wznm combined daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCMBD_EXE_H
#define WZNMCMBD_EXE_H

#include <string>
#include <vector>

#include <signal.h>

#include "WznmcmbdAppsrv.h"
#include "WznmcmbdJobprc.h"
#include "WznmcmbdOpprc.h"

/**
	* Wznmcmbd
	*/
class Wznmcmbd {

public:
	Wznmcmbd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wznmcmbd();

public:
	std::string exedir;

	DbsWznm dbswznm;

	XchgWznmcmbd* xchg;
	
	RootWznm* root;

	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	std::vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif



