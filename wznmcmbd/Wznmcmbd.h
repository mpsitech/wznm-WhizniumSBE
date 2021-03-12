/**
	* \file Wznmcmbd.h
	* inter-thread exchange object for Wznm combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCMBD_H
#define WZNMCMBD_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>
#if MHD_VERSION < 0x0097002
	#define MHD_Result int
#endif

#include <sbecore/Txtrd.h>
#include <sbecore/TxtMon.h>

#include "Wznm.h"

#include "SqkWznmCompl.h"
#include "SqkWznmCtpGenjtr.h"
#include "SqkWznmCtpGenui.h"
#include "SqkWznmCtpWrsrv.h"
#include "SqkWznmCtpWrstkit.h"
#include "SqkWznmCtpWrweb.h"
#include "SqkWznmGen.h"
#include "SqkWznmPrcfile.h"
#include "SqkWznmPrctree.h"
#include "SqkWznmWrapi.h"
#include "SqkWznmWrapp.h"
#include "SqkWznmWrdbs.h"
#include "SqkWznmWrjapi.h"
#include "SqkWznmWrsrv.h"
#include "SqkWznmWrweb.h"

// IP include.cust --- INSERT

class XchgWznmcmbd;
typedef XchgWznmcmbd XchgWznm;

/**
	* DpchAppWznm
	*/
class DpchAppWznm : public DpchWznm {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchAppWznm(const Sbecore::uint ixWznmVDpch = 0);
	virtual ~DpchAppWznm();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readJSON(Json::Value& sup, bool addbasetag = false);
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWznmAlert
	*/
class DpchAppWznmAlert : public DpchAppWznm {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint NUMFMCB = 2;

public:
	DpchAppWznmAlert();

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readJSON(Json::Value& sup, bool addbasetag = false);
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWznmInit
	*/
class DpchAppWznmInit : public DpchAppWznm {

public:
	DpchAppWznmInit();
};

/**
	* DpchAppWznmResume
	*/
class DpchAppWznmResume : public DpchAppWznm {

public:
	DpchAppWznmResume();
};

/**
	* DpchEngWznm
	*/
class DpchEngWznm : public DpchWznm {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchEngWznm(const Sbecore::uint ixWznmVDpch = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchEngWznm();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();
	virtual void merge(DpchEngWznm* dpcheng);

	virtual void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
	virtual void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWznmAck
	*/
class DpchEngWznmAck : public DpchEngWznm {

public:
	DpchEngWznmAck(const Sbecore::ubigint jref = 0);
};

/**
	* DpchEngWznmAlert
	*/
class DpchEngWznmAlert : public DpchEngWznm {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWznmAlert(const Sbecore::ubigint jref = 0, ContInfWznmAlert* continf = NULL, Sbecore::Feed* feedFMcb = NULL, const std::set<Sbecore::uint>& mask = {NONE});

public:
	ContInfWznmAlert continf;
	Sbecore::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWznm* dpcheng);

	void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
	void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWznmConfirm
	*/
class DpchEngWznmConfirm : public DpchEngWznm {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREF = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWznmConfirm(const bool accepted = false, const Sbecore::ubigint jref = 0, const std::string& sref = "", const std::set<Sbecore::uint>& mask = {ALL});

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWznm* dpcheng);

	void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
	void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWznmSuspend
	*/
class DpchEngWznmSuspend : public DpchEngWznm {

public:
	DpchEngWznmSuspend(const Sbecore::ubigint jref = 0);
};

/**
	* StgWznmAppearance
	*/
class StgWznmAppearance : public Sbecore::Block {

public:
	static const Sbecore::uint HISTLENGTH = 1;
	static const Sbecore::uint SUSPSESS = 2;
	static const Sbecore::uint SESSTTERM = 3;
	static const Sbecore::uint SESSTWARN = 4;
	static const Sbecore::uint ROOTTTERM = 5;

public:
	StgWznmAppearance(const Sbecore::usmallint histlength = 20, const bool suspsess = true, const Sbecore::uint sesstterm = 0, const Sbecore::uint sesstwarn = 0, const Sbecore::uint roottterm = 0);

public:
	Sbecore::usmallint histlength;
	bool suspsess;
	Sbecore::uint sesstterm;
	Sbecore::uint sesstwarn;
	Sbecore::uint roottterm;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWznmAppearance* comp);
	std::set<Sbecore::uint> diff(const StgWznmAppearance* comp);
};

/**
	* StgWznmAppsrv
	*/
class StgWznmAppsrv : public Sbecore::Block {

public:
	static const Sbecore::uint PORT = 1;
	static const Sbecore::uint HTTPS = 2;

public:
	StgWznmAppsrv(const Sbecore::usmallint port = 13100, const bool https = false);

public:
	Sbecore::usmallint port;
	bool https;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWznmAppsrv* comp);
	std::set<Sbecore::uint> diff(const StgWznmAppsrv* comp);
};

/**
	* StgWznmcmbd
	*/
class StgWznmcmbd : public Sbecore::Block {

public:
	static const Sbecore::uint JOBPRCN = 1;
	static const Sbecore::uint OPPRCN = 2;
	static const Sbecore::uint APPSRV = 3;

public:
	StgWznmcmbd(const Sbecore::usmallint jobprcn = 4, const Sbecore::usmallint opprcn = 1, const bool appsrv = true);

public:
	Sbecore::usmallint jobprcn;
	Sbecore::usmallint opprcn;
	bool appsrv;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWznmcmbd* comp);
	std::set<Sbecore::uint> diff(const StgWznmcmbd* comp);
};

/**
	* StgWznmDatabase
	*/
class StgWznmDatabase : public Sbecore::Block {

public:
	static const Sbecore::uint IXDBSVDBSTYPE = 1;
	static const Sbecore::uint DBSPATH = 2;
	static const Sbecore::uint DBSNAME = 3;
	static const Sbecore::uint USERNAME = 4;
	static const Sbecore::uint PASSWORD = 5;
	static const Sbecore::uint IP = 6;
	static const Sbecore::uint PORT = 7;

public:
	StgWznmDatabase(const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "./DbsWznm.sql", const std::string& dbsname = "DbsWznm", const std::string& username = "default", const std::string& password = "asdf1234", const std::string& ip = "127.0.0.1", const Sbecore::usmallint port = 3306);

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWznmDatabase* comp);
	std::set<Sbecore::uint> diff(const StgWznmDatabase* comp);
};

/**
	* StgWznmPath
	*/
class StgWznmPath : public Sbecore::Block {

public:
	static const Sbecore::uint ACVPATH = 1;
	static const Sbecore::uint KEYPATH = 2;
	static const Sbecore::uint MONPATH = 3;
	static const Sbecore::uint TMPPATH = 4;
	static const Sbecore::uint WEBPATH = 5;
	static const Sbecore::uint HELPURL = 6;

public:
	StgWznmPath(const std::string& acvpath = "${WHIZROOT}/acv/wznm", const std::string& keypath = "", const std::string& monpath = "${WHIZROOT}/mon/wznm", const std::string& tmppath = "${WHIZROOT}/tmp/wznm", const std::string& webpath = "${WHIZROOT}/web/appwznm", const std::string& helpurl = "/wznm");

public:
	std::string acvpath;
	std::string keypath;
	std::string monpath;
	std::string tmppath;
	std::string webpath;
	std::string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWznmPath* comp);
	std::set<Sbecore::uint> diff(const StgWznmPath* comp);
};

/**
	* StgWznmTenant
	*/
class StgWznmTenant : public Sbecore::Block {

public:
	static const Sbecore::uint ORGNAME = 1;
	static const Sbecore::uint ORGWEB = 2;

public:
	StgWznmTenant(const std::string& orgname = "", const std::string& orgweb = "");

public:
	std::string orgname;
	std::string orgweb;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWznmTenant* comp);
	std::set<Sbecore::uint> diff(const StgWznmTenant* comp);
};

/**
	* AlrWznm
	*/
namespace AlrWznm {
	DpchEngWznmAlert* prepareAlrAbt(const Sbecore::ubigint jref, const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feedFMcbAlert);
	DpchEngWznmAlert* prepareAlrIer(const Sbecore::ubigint jref, const Sbecore::uint ixWznmVLocale, const std::string& iexsqk, Sbecore::Feed& feedFMcbAlert);
	DpchEngWznmAlert* prepareAlrPer(const Sbecore::ubigint jref, const Sbecore::uint ixWznmVLocale, const std::string& iexsqk, Sbecore::Feed& feedFMcbAlert);
	DpchEngWznmAlert* prepareAlrSav(const Sbecore::ubigint jref, const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feedFMcbAlert);
	DpchEngWznmAlert* prepareAlrTrm(const Sbecore::ubigint jref, const Sbecore::uint ixWznmVLocale, const Sbecore::uint sesstterm, const Sbecore::uint sesstwarn, Sbecore::Feed& feedFMcbAlert);
	std::string prepareAlrTrm_dtToString(const uint ixWznmVLocale, const time_t dt);
};

/**
	* ReqWznm
	*/
class ReqWznm {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint REDIRECT = 1; // web client triggered root request (GET)
		static const Sbecore::uint WEB = 2; // web client triggered ui file request (GET)
		static const Sbecore::uint CMD = 3; // command line request
		static const Sbecore::uint DPCHAPP = 4; // web client triggered Dpch request (POST+DpchApp)
		static const Sbecore::uint NOTIFY = 5; // web client triggered notify-on-Dpch request (GET)
		static const Sbecore::uint POLL = 6; // web client triggered Dpch poll request (GET)
		static const Sbecore::uint UPLOAD = 7; // web client triggered file upload request (POST)
		static const Sbecore::uint DOWNLOAD = 8; // web client triggered file download request (GET)
		static const Sbecore::uint DPCHRET = 9; // op engine or opprc triggered op return (DpchRet)
		static const Sbecore::uint METHOD = 10; // M2M interface triggered method request
		static const Sbecore::uint TIMER = 11; // timer triggered request
		static const Sbecore::uint EXTCALL = 12; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint RECEIVE = 1; // during data reception - appsrv internal
		static const Sbecore::uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const Sbecore::uint PRC = 3; // while being processesd by job processor ; appsrv thread waiting on cReply
		static const Sbecore::uint REPLY = 4; // after being processed by job processor
	};

public:
	ReqWznm(const Sbecore::uint ixVBasetype = VecVBasetype::NONE, const Sbecore::uint ixVState = VecVState::RECEIVE, const std::string& ip = "");
	~ReqWznm();

public:
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixVState;

	// specific data for base type CMD
	std::string cmd;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD
	std::string ip;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, DPCHAPP, NOTIFY, UPLOAD, DOWNLOAD, METHOD
	bool retain;
	Sbecore::Cond cReady; // mutex also protects compare/set of ixVState to REPLY

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	std::string filename; // full path
	std::fstream* file;
	size_t filelen;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* request;
	size_t requestlen;

	// specifc data for base types DPCHAPP, NOTIFY, POLL
	bool jsonNotXml;

	// specific data for base types CMD, DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	Sbecore::ubigint jref;

	// specific data for base type TIMER
	Sbecore::ubigint wref;
	std::string sref;

	// specific data for base type EXTCALL
	Sbecore::Call* call;

	// specific data for base types CMD, DPCHAPP, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	bool weak;

	// specific data for base type DPCHAPP
	DpchAppWznm* dpchapp;

	// specific data for base types DPCHAPP, NOTIFY, POLL
	DpchEngWznm* dpcheng;
	Sbecore::uint ixWznmVLocale;

	// specific data for base type DPCHRET
	DpchInvWznm* dpchinv;
	DpchRetWznm* dpchret;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* reply;
	size_t replylen;

	// specific data for base type METHOD
	Sbecore::Method* method;

public:
	void setStateReply();
};

/**
	* DcolWznm
	*/
class DcolWznm {

public:
	DcolWznm(const Sbecore::ubigint jref = 0, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS);
	~DcolWznm();

public:
	Sbecore::ubigint jref;

	Sbecore::uint ixWznmVLocale;

	Sbecore::Mutex mAccess;

	bool hot;

	std::list<DpchEngWznm*> dpchs;

	ReqWznm* req;

public:
	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* JobWznm
	*/
class JobWznm {

public:
	JobWznm(XchgWznm* xchg, const Sbecore::uint ixWznmVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS);
	virtual ~JobWznm();

public:
	XchgWznm* xchg;

	Sbecore::ubigint jref;

	Sbecore::uint ixWznmVJob;

	Sbecore::uint ixWznmVLocale;

	Sbecore::Mutex mAccess;

	bool muteRefresh;

	Sbecore::uint ixVSge;
	Sbecore::uint nextIxVSgeSuccess;
	Sbecore::uint nextIxVSgeFailure;

	std::string lasterror;

	Sbecore::uint opN;
	Sbecore::uint opNSuccess;
	Sbecore::uint opNFailure;

	std::vector<DpchInvWznm*> invs;

	Sbecore::Mutex mOps;
	std::list<Sbecore::Op*> ops;
	std::string opsqkLast;

	Sbecore::ubigint wrefLast;
	Sbecore::ubigint wrefMin;

	ReqWznm* reqCmd;

public:
	virtual DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	virtual void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void refreshWithDpchEng(DbsWznm* dbswznm, DpchEngWznm** dpcheng = NULL, const bool unmute = false);

	virtual std::string getSquawk(DbsWznm* dbswznm);

	virtual void handleRequest(DbsWznm* dbswznm, ReqWznm* req);
	virtual void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

	void lockAccess(const std::string& srefObject, const std::string& srefMember);
	bool trylockAccess(const std::string& srefObject, const std::string& srefMember);
	void unlockAccess(const std::string& srefObject, const std::string& srefMember);

	void lockAccess(const std::string& srefMember);
	bool trylockAccess(const std::string& srefMember);
	void unlockAccess(const std::string& srefMember);

	void setStage(DbsWznm* dbswznm, const Sbecore::uint _ixVSge);

	void clearInvs();
	Sbecore::ubigint addInv(DpchInvWznm* inv);
	void addInvs(std::vector<DpchInvWznm*>& _invs);
	void submitInvs(DbsWznm* dbswznm, const Sbecore::uint nextIxVSgeEmpty, Sbecore::uint& _ixVSge);

	void clearOps();
	void addOp(DbsWznm* dbswznm, DpchInvWznm* inv);
	void removeOp(const Sbecore::ubigint oref);
	std::string getOpsqkLast();

	void callback(const Sbecore::uint nextIxVSge);
	void invalidateWakeups();
};

/**
	* CsjobWznm
	*/
class CsjobWznm : public JobWznm {

public:
	CsjobWznm(XchgWznm* xchg, const Sbecore::uint ixWznmVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS);

public:
	bool srvNotCli;
	CsjobWznm* srv; // client

public:
	virtual bool handleClaim(DbsWznm* dbswznm, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest); // server
};

/**
	* ShrdatWznm
	*/
class ShrdatWznm {

public:
	ShrdatWznm(const std::string& srefSupclass, const std::string& srefObject);
	~ShrdatWznm();

public:
	std::string srefSupclass;
	std::string srefObject;

	Sbecore::Rwmutex rwmAccess;

public:
	virtual void init(XchgWznm* xchg, DbsWznm* dbswznm);
	virtual void term(XchgWznm* xchg);

	void rlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void runlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void rlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void runlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);

	void wlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wunlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void wunlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
};

/**
	* StmgrWznm
	*/
class StmgrWznm {

public:
	StmgrWznm(XchgWznm* xchg, const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	~StmgrWznm();

public:
	XchgWznm* xchg;

	Sbecore::ubigint jref;
	Sbecore::uint ixVNonetype;

	Sbecore::Stcch* stcch;

	Sbecore::Mutex mAccess;

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);
	bool refresh(DbsWznm* dbswznm, Sbecore::Stcchitem* stit);

	void begin();
	void commit();

	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* WakeupWznm
	*/
class WakeupWznm {

public:
	WakeupWznm(XchgWznm* xchg, const Sbecore::ubigint wref, const Sbecore::ubigint jref, const std::string sref, const uint64_t deltat = 0, const bool weak = false);

public:
	XchgWznm* xchg;

	Sbecore::ubigint wref;

	Sbecore::ubigint jref;
	std::string sref;
	uint64_t deltat;
	bool weak;
};

/**
	* ExtcallWznm
	*/
class ExtcallWznm {

public:
	ExtcallWznm(XchgWznm* xchg, Sbecore::Call* call);

public:
	XchgWznm* xchg;
	Sbecore::Call* call;
};

/**
	* XchgWznmcmbd
	*/
class XchgWznmcmbd {

public:
	/**
		* ShrdatJobprc
		*/
	class ShrdatJobprc : public ShrdatWznm {

	public:
		// IP ShrdatJobprc.subs --- INSERT

	public:
		ShrdatJobprc();

	public:
		// IP ShrdatJobprc.vars --- INSERT

	public:
		void init(XchgWznm* xchg, DbsWznm* dbswznm);
		void term(XchgWznm* xchg);
	};

	/**
		* ShrdatOpprc
		*/
	class ShrdatOpprc : public ShrdatWznm {

	public:
		// IP ShrdatOpprc.subs --- INSERT

	public:
		ShrdatOpprc();

	public:
		// IP ShrdatOpprc.vars --- INSERT

	public:
		void init(XchgWznm* xchg, DbsWznm* dbswznm);
		void term(XchgWznm* xchg);
	};

public:
	XchgWznmcmbd();
	~XchgWznmcmbd();

public:
	StgWznmAppearance stgwznmappearance;
	StgWznmAppsrv stgwznmappsrv;
	StgWznmcmbd stgwznmcmbd;
	StgWznmDatabase stgwznmdatabase;
	StgWznmPath stgwznmpath;
	StgWznmTenant stgwznmtenant;

	ShrdatJobprc shrdatJobprc;
	ShrdatOpprc shrdatOpprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	std::string exedir;
	std::string acvpath;
	std::string tmppath;
	std::string helpurl;

	std::string key;
	std::string cert;

	// condition for thread start-up
	Sbecore::Cond cStable;

	// root job
	Sbecore::ubigint jrefRoot;

	// job receiving commands
	Sbecore::ubigint jrefCmd;

	// monitor object
	Sbecore::TxtMon mon;

	// log file
	Sbecore::Mutex mLogfile;

	// condition for job processors
	Sbecore::Cond cJobprcs;

	// condition for op processors
	Sbecore::Cond cOpprcs;

	// request list
	Sbecore::Mutex mReqs;
	std::list<ReqWznm*> reqs;

	// operation invocation list
	Sbecore::Refseq orefseq;
	Sbecore::Mutex mInvs;
	std::list<DpchInvWznm*> invs;

	// presetting list
	Sbecore::Rwmutex rwmPresets;
	std::multimap<Sbecore::presetref_t,Sbecore::Preset*> presets;

	// stub manager list
	Sbecore::Rwmutex rwmStmgrs;
	std::map<Sbecore::ubigint,StmgrWznm*> stmgrs;

	// call listener list
	Sbecore::Rwmutex rwmClstns;
	std::multimap<Sbecore::clstnref_t,Sbecore::Clstn*> clstns;
	std::multimap<Sbecore::clstnref2_t,Sbecore::clstnref_t> cref2sClstns;

	// dispatch collector list
	Sbecore::Rwmutex rwmDcols;
	std::map<Sbecore::ubigint,DcolWznm*> dcols;

	// job list
	Sbecore::Refseq jrefseq;
	Sbecore::Rwmutex rwmJobs;
	std::map<Sbecore::ubigint,JobWznm*> jobs;
	std::map<Sbecore::ubigint,Sbecore::uint> ixWznmVJobs;
	std::map<Sbecore::ubigint,Sbecore::Jobinfo*> jobinfos;

	// client/server job information
	Sbecore::Rwmutex rwmCsjobinfos;
	std::map<Sbecore::uint,Sbecore::Csjobinfo*> csjobinfos;

	// sequence for wakeup references
	Sbecore::Refseq wrefseq;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const std::string& str);

	// request list methods
	void addReq(ReqWznm* req);
	ReqWznm* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsWznm* dbswznm, JobWznm* job, std::vector<DpchInvWznm*>& dpchinvs);
	DpchInvWznm* pullFirstInv();

	// presetting methods
	Sbecore::Preset* addPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const Sbecore::Arg& arg);

	Sbecore::Preset* addIxPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const Sbecore::uint ix);
	Sbecore::Preset* addRefPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const Sbecore::ubigint ref);
	Sbecore::Preset* addRefsPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const std::vector<Sbecore::ubigint>& refs);
	Sbecore::Preset* addSrefPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const std::string& sref);
	Sbecore::Preset* addIntvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const int intval);
	Sbecore::Preset* addDblvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const double dblval);
	Sbecore::Preset* addBoolvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const bool boolval);
	Sbecore::Preset* addTxtvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref, const std::string& txtval);

	Sbecore::Preset* getPresetByPref(const Sbecore::presetref_t& pref);

	Sbecore::Arg getPreset(const Sbecore::uint ixWznmVPreset, Sbecore::ubigint jref);

	Sbecore::uint getIxPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	Sbecore::ubigint getRefPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	std::vector<Sbecore::ubigint> getRefsPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	std::string getSrefPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	int getIntvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	double getDblvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	bool getBoolvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	std::string getTxtvalPreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);

	void getPresetsByJref(const Sbecore::ubigint jref, std::vector<Sbecore::uint>& icsWznmVPreset, std::vector<Sbecore::Arg>& args);

	void removePreset(const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jref);
	void removePresetsByJref(const Sbecore::ubigint jref);

	// stub manager methods
	StmgrWznm* addStmgr(const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	StmgrWznm* getStmgrByJref(const Sbecore::ubigint jref);
	void removeStmgrByJref(const Sbecore::ubigint jref);

	// call listener list methods
	Sbecore::Clstn* addClstn(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig = 0, const bool chgarg = false, const Sbecore::Arg& arg = Sbecore::Arg(), const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addIxClstn(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addRefClstn(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefClstn(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefSrefClstn(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const std::string& sref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addClstnStmgr(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref);

	Sbecore::Clstn* getClstnByCref(const Sbecore::clstnref_t& cref);
	void getClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget, std::vector<Sbecore::uint>& icsWznmVCall, std::vector<Sbecore::uint>& icsVJobmask);

	void removeClstns(const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);
	void removeClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);

	// call methods
	void findJrefsByCall(Sbecore::Call* call, std::vector<Sbecore::ubigint>& jrefTrigs, std::vector<Sbecore::ubigint>& jrefs, std::vector<Sbecore::uint>& icsVTarget, std::vector<Sbecore::uint>& icsVJactype);

	void triggerCall(DbsWznm* dbswznm, Sbecore::Call* call);

	bool triggerArgToArgCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::Arg& argInv, Sbecore::Arg& argRet);
	bool triggerCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref);
	bool triggerIxCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv);
	bool triggerRefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv);
	bool triggerIntvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool triggerIxSrefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv);
	bool triggerIxSrefToIxCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv, Sbecore::uint& ixRet);
	bool triggerIxIntvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& txtvalInv);
	bool triggerSrefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const std::string& srefInv);
	bool triggerToBoolvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, std::string& srefRet);
	bool triggerRefToBoolvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerIxRefToRefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::ubigint& refRet);
	bool triggerIxRefSrefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool triggerRefToIxCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerSrefToRefCall(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCall, const Sbecore::ubigint jref, const std::string& srefInv, Sbecore::ubigint& refRet);

	// dispatch collector list methods
	DcolWznm* addDcol(const Sbecore::ubigint jref);
	DcolWznm* getDcolByJref(Sbecore::ubigint jref, const bool tree = true);
	void removeDcolByJref(const Sbecore::ubigint jref);
	void removeDcolsByJref(const Sbecore::ubigint jref);

	void submitDpch(DpchEngWznm* dpcheng);
	DpchEngWznm* pullFirstDpch(DcolWznm* dcol);

	// job list methods
	Sbecore::ubigint addJob(DbsWznm* dbswznm, JobWznm* job, const Sbecore::ubigint jrefSup);
	JobWznm* getJobByJref(const Sbecore::ubigint jref);
	Sbecore::Jobinfo* getJobinfoByJref(const Sbecore::ubigint jref);
	void removeJobByJref(const Sbecore::ubigint jref);

	bool getJobSup(const Sbecore::ubigint jrefSup, Sbecore::ubigint jref);
	void setJobStage(DbsWznm* dbswznm, JobWznm* job, const Sbecore::uint ixVSge);

	// client/server job methods
	void addCsjobClaim(DbsWznm* dbswznm, CsjobWznm* csjob, Sbecore::Claim* claim);

	bool getCsjobClaim(CsjobWznm* csjob, bool& takenNotAvailable, bool& fulfilled, bool& run);
	bool getCsjobClaim(CsjobWznm* csjob, bool& takenNotAvailable, bool& fulfilled);

	void clearCsjobRun(DbsWznm* dbswznm, const Sbecore::uint ixWznmVJob);

	void removeCsjobClaim(DbsWznm* dbswznm, CsjobWznm* csjob);

	bool getCsjobNotJob(const Sbecore::uint ixWznmVJob);
	std::set<Sbecore::ubigint> getCsjobClisByJref(const Sbecore::ubigint jref);

	// timer methods
	Sbecore::ubigint addWakeup(const Sbecore::ubigint jref, const std::string sref, const uint64_t deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);
};
#endif
