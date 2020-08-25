/**
	* \file WznmcmbdJobprc.h
	* job processor for Wznm combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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



