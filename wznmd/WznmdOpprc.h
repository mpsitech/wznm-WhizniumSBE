/**
	* \file WznmdOpprc.h
	* operation processor for Wznm daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMDOPPRC_H
#define WZNMDOPPRC_H

/**
	* WznmdOpprc
	*/
namespace WznmdOpprc {
	void* run(void* arg);
	void cleanup(void* _arg);

	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _ret);

	void writeDpchInv(CURL* curl, XchgWznmd* xchg, ReqWznm* req);
	Sbecore::uint readDpchRet(XchgWznmd* xchg, ReqWznm* req);
};

/**
	* WznmdOpprc_arg
	*/
struct WznmdOpprc_arg {
	XchgWznmd* xchg;
	NodeWznm* node;
};

/**
	* WznmdOpprc_cuarg
	*/
struct WznmdOpprc_cuarg {
	XchgWznmd* xchg;
	ReqWznm** req;
	Sbecore::ubigint* oref;
	Sbecore::ubigint* jref;
};

#endif

