/**
	* \file Wznmopd_exe.h
	* Wznm operation daemon wznmopd2 main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMOPD_EXE_H
#define WZNMOPD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "WznmopdEngsrv.h"
#include "WznmopdOpprc.h"

/**
	* Wznmopd
	*/
class Wznmopd {

public:
	Wznmopd(const std::string& exedir, const Sbecore::usmallint engsrvportofs);
	~Wznmopd();

public:
	std::string exedir;

	DbsWznm dbswznm;

	XchgWznmopd* xchg;

	MHD_Daemon* engsrv;

	std::vector<pthread_t> opprcs;

public:
	char* curlbuf;
	size_t curlbuflen;

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	static Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _inst);

public:
	void loadPref();
	void storePref();
};

#endif




