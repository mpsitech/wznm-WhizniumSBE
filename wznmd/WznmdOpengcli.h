/**
	* \file WznmdOpengcli.h
	* operation engine client for Wznm daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMDOPENGCLI_H
#define WZNMDOPENGCLI_H

#include "WznmdOpprc.h"

/**
	* WznmdOpengcli
	*/
namespace WznmdOpengcli {
	void* run(void* arg);
	bool run_checkNodes(XchgWznm* xchg);

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _arg);
};

/**
	* WznmdOpengcli_curlarg
	*/
struct WznmdOpengcli_curlarg {
	char* buf;
	size_t buflen;
};

#endif
