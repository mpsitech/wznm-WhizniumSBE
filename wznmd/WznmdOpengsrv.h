/**
	* \file WznmdOpengsrv.h
	* op engine server for Wznm daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMDOPENGSRV_H
#define WZNMDOPENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

/**
	* WznmdOpengsrv
	*/
namespace WznmdOpengsrv {
	MHD_Daemon* start(XchgWznm* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpch(XchgWznmd* xchg, ReqopengconWznm* req);
	void writeDpchAck(ReqopengconWznm* req);
	void writeDpchReg(XchgWznmd* xchg, ReqopengconWznm* req, const Sbecore::ubigint nref);
};

#endif




