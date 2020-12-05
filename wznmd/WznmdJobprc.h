/**
	* \file WznmdJobprc.h
	* job processor for Wznm daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMDJOBPRC_H
#define WZNMDJOBPRC_H

/**
	* WznmdJobprc
	*/
namespace WznmdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWznmd* xchg, DbsWznm* dbswznm, ReqWznm* req);
};

#endif




