/**
	* \file Wznmd_exe.h
	* Wznm daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMD_EXE_H
#define WZNMD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "WznmdAppsrv.h"
#include "WznmdJobprc.h"
#include "WznmdOpengcli.h"
#include "WznmdOpengsrv.h"

/**
	* Wznmd
	*/
class Wznmd {

public:
	Wznmd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wznmd();

public:
	std::string exedir;

	DbsWznm dbswznm;

	XchgWznmd* xchg;
	
	RootWznm* root;

	MHD_Daemon* opengsrv;
	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	pthread_t opengcli;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif
