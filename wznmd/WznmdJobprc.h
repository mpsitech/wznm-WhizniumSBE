/**
	* \file WznmdJobprc.h
	* job processor for Wznm daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
