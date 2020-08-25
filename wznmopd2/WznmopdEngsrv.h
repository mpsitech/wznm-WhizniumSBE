/**
	* \file WznmopdEngsrv.h
	* engine server for Wznm operation daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMOPDENGSRV_H
#define WZNMOPDENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "WznmCtpWrweb_blks.h"
#include "WznmCtpWrsrv_blks.h"
#include "WznmCtpWrstkit_blks.h"
#include "WznmCtpGenui_blks.h"
#include "WznmCtpGenjtr_blks.h"

/**
	* WznmopdEngsrv
	*/
namespace WznmopdEngsrv {
	MHD_Daemon* start(XchgWznmopd* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpchInv(ReqopWznm* req);
	void writeDpchAck(ReqopWznm* req);
	void writeDpchRet(ReqopWznm* req);
};

#endif

