/**
	* \file WznmcmbdJobprc.h
	* job processor for Wznm combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCMBDJOBPRC_H
#define WZNMCMBDJOBPRC_H

/**
	* WznmcmbdJobprc
	*/
namespace WznmcmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWznmcmbd* xchg, DbsWznm* dbswznm, ReqWznm* req);
};

#endif





