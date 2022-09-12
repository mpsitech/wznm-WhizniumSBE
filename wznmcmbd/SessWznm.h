/**
	* \file SessWznm.h
	* job handler for job SessWznm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef SESSWZNM_H
#define SESSWZNM_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "CrdWznmUtl.h"
#include "CrdWznmSte.h"
#include "CrdWznmSeq.h"
#include "CrdWznmEvt.h"
#include "CrdWznmRtj.h"
#include "CrdWznmApp.h"
#include "CrdWznmRls.h"
#include "CrdWznmCmp.h"
#include "CrdWznmCal.h"
#include "CrdWznmBlk.h"
#include "CrdWznmMtd.h"
#include "CrdWznmSge.h"
#include "CrdWznmJob.h"
#include "CrdWznmOpx.h"
#include "CrdWznmOpk.h"
#include "CrdWznmCon.h"
#include "CrdWznmQmd.h"
#include "CrdWznmQco.h"
#include "CrdWznmQry.h"
#include "CrdWznmPnl.h"
#include "CrdWznmDlg.h"
#include "CrdWznmCar.h"
#include "CrdWznmMdl.h"
#include "CrdWznmPst.h"
#include "CrdWznmIel.h"
#include "CrdWznmIme.h"
#include "CrdWznmIex.h"
#include "CrdWznmStb.h"
#include "CrdWznmChk.h"
#include "CrdWznmVit.h"
#include "CrdWznmVec.h"
#include "CrdWznmRel.h"
#include "CrdWznmSbs.h"
#include "CrdWznmTco.h"
#include "CrdWznmTbl.h"
#include "CrdWznmErr.h"
#include "CrdWznmCap.h"
#include "CrdWznmVer.h"
#include "CrdWznmPrj.h"
#include "CrdWznmLib.h"
#include "CrdWznmMch.h"
#include "CrdWznmCtp.h"
#include "CrdWznmTag.h"
#include "CrdWznmLoc.h"
#include "CrdWznmFil.h"
#include "CrdWznmPrs.h"
#include "CrdWznmUsr.h"
#include "CrdWznmUsg.h"
#include "CrdWznmNav.h"

#define StatShrSessWznm SessWznm::StatShr

#define DpchEngSessWznmData SessWznm::DpchEngData

/**
	* SessWznm
	*/
class SessWznm : public JobWznm {

public:
	/**
		* StatShr (full: StatShrSessWznm)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFCRDNAV = 1;

	public:
		StatShr(const Sbecore::ubigint jrefCrdnav = 0);

	public:
		Sbecore::ubigint jrefCrdnav;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWznmData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

public:
	SessWznm(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWznmMUser, const std::string& ip);
	~SessWznm();

public:
	StatShr statshr;

	std::map<Sbecore::ubigint, JobWznm*> crdutls;
	std::map<Sbecore::ubigint, JobWznm*> crdstes;
	std::map<Sbecore::ubigint, JobWznm*> crdseqs;
	std::map<Sbecore::ubigint, JobWznm*> crdevts;
	std::map<Sbecore::ubigint, JobWznm*> crdrtjs;
	std::map<Sbecore::ubigint, JobWznm*> crdapps;
	std::map<Sbecore::ubigint, JobWznm*> crdrlss;
	std::map<Sbecore::ubigint, JobWznm*> crdcmps;
	std::map<Sbecore::ubigint, JobWznm*> crdcals;
	std::map<Sbecore::ubigint, JobWznm*> crdblks;
	std::map<Sbecore::ubigint, JobWznm*> crdmtds;
	std::map<Sbecore::ubigint, JobWznm*> crdsges;
	std::map<Sbecore::ubigint, JobWznm*> crdjobs;
	std::map<Sbecore::ubigint, JobWznm*> crdopxs;
	std::map<Sbecore::ubigint, JobWznm*> crdopks;
	std::map<Sbecore::ubigint, JobWznm*> crdcons;
	std::map<Sbecore::ubigint, JobWznm*> crdqmds;
	std::map<Sbecore::ubigint, JobWznm*> crdqcos;
	std::map<Sbecore::ubigint, JobWznm*> crdqrys;
	std::map<Sbecore::ubigint, JobWznm*> crdpnls;
	std::map<Sbecore::ubigint, JobWznm*> crddlgs;
	std::map<Sbecore::ubigint, JobWznm*> crdcars;
	std::map<Sbecore::ubigint, JobWznm*> crdmdls;
	std::map<Sbecore::ubigint, JobWznm*> crdpsts;
	std::map<Sbecore::ubigint, JobWznm*> crdiels;
	std::map<Sbecore::ubigint, JobWznm*> crdimes;
	std::map<Sbecore::ubigint, JobWznm*> crdiexs;
	std::map<Sbecore::ubigint, JobWznm*> crdstbs;
	std::map<Sbecore::ubigint, JobWznm*> crdchks;
	std::map<Sbecore::ubigint, JobWznm*> crdvits;
	std::map<Sbecore::ubigint, JobWznm*> crdvecs;
	std::map<Sbecore::ubigint, JobWznm*> crdrels;
	std::map<Sbecore::ubigint, JobWznm*> crdsbss;
	std::map<Sbecore::ubigint, JobWznm*> crdtcos;
	std::map<Sbecore::ubigint, JobWznm*> crdtbls;
	std::map<Sbecore::ubigint, JobWznm*> crderrs;
	std::map<Sbecore::ubigint, JobWznm*> crdcaps;
	std::map<Sbecore::ubigint, JobWznm*> crdvers;
	std::map<Sbecore::ubigint, JobWznm*> crdprjs;
	std::map<Sbecore::ubigint, JobWznm*> crdlibs;
	std::map<Sbecore::ubigint, JobWznm*> crdmchs;
	std::map<Sbecore::ubigint, JobWznm*> crdctps;
	std::map<Sbecore::ubigint, JobWznm*> crdtags;
	std::map<Sbecore::ubigint, JobWznm*> crdlocs;
	std::map<Sbecore::ubigint, JobWznm*> crdfils;
	std::map<Sbecore::ubigint, JobWznm*> crdprss;
	std::map<Sbecore::ubigint, JobWznm*> crdusrs;
	std::map<Sbecore::ubigint, JobWznm*> crdusgs;
	CrdWznmNav* crdnav;

	std::map<Sbecore::ubigint,Sbecore::uint> usgaccs;

	std::map<Sbecore::ubigint,std::string> scr;
	std::map<std::string,Sbecore::ubigint> descr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void warnTerm(DbsWznm* dbswznm);
	void term(DbsWznm* dbswznm);

	void eraseCrd(std::map<Sbecore::ubigint, JobWznm*>& subjobs);

	Sbecore::uint checkCrdActive(const Sbecore::uint ixWznmVCard);
	Sbecore::uint evalCrdtagActive();
	Sbecore::uint evalCrdverActive();
	Sbecore::uint evalCrdcapActive();
	Sbecore::uint evalCrderrActive();
	Sbecore::uint evalCrdtblActive();
	Sbecore::uint evalCrdtcoActive();
	Sbecore::uint evalCrdsbsActive();
	Sbecore::uint evalCrdrelActive();
	Sbecore::uint evalCrdvecActive();
	Sbecore::uint evalCrdvitActive();
	Sbecore::uint evalCrdchkActive();
	Sbecore::uint evalCrdstbActive();
	Sbecore::uint evalCrdiexActive();
	Sbecore::uint evalCrdimeActive();
	Sbecore::uint evalCrdielActive();
	Sbecore::uint evalCrdpstActive();
	Sbecore::uint evalCrdmdlActive();
	Sbecore::uint evalCrdcarActive();
	Sbecore::uint evalCrddlgActive();
	Sbecore::uint evalCrdpnlActive();
	Sbecore::uint evalCrdqryActive();
	Sbecore::uint evalCrdqcoActive();
	Sbecore::uint evalCrdqmdActive();
	Sbecore::uint evalCrdconActive();
	Sbecore::uint evalCrdopkActive();
	Sbecore::uint evalCrdopxActive();
	Sbecore::uint evalCrdjobActive();
	Sbecore::uint evalCrdsgeActive();
	Sbecore::uint evalCrdmtdActive();
	Sbecore::uint evalCrdblkActive();
	Sbecore::uint evalCrdcalActive();
	Sbecore::uint evalCrdcmpActive();
	Sbecore::uint evalCrdrlsActive();
	Sbecore::uint evalCrdrtjActive();
	Sbecore::uint evalCrdevtActive();
	Sbecore::uint evalCrdseqActive();
	Sbecore::uint evalCrdsteActive();

	Sbecore::uint checkCrdaccess(const Sbecore::uint ixWznmVCard);
	void getIxCrdacc(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCard, const bool adm, ListWznmRMUserMUsergroup& urus, const Sbecore::ubigint refWznmMUser, Sbecore::uint& ixWznmWAccess);

	Sbecore::uint checkRecaccess(DbsWznm* dbswznm, const Sbecore::uint ixWznmVCard, const Sbecore::ubigint ref);
	void logRecaccess(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint preUref, const Sbecore::uint ixWznmVCard, const Sbecore::ubigint unvUref);

	Sbecore::uint crdToMtb(const Sbecore::uint ixWznmVCard);
	Sbecore::uint preToMtb(const Sbecore::uint ixWznmVPreset);
	bool hasActive(const Sbecore::uint ixWznmVCard);
	bool hasGrpown(const Sbecore::uint ixWznmVMaintable);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleCreateCrdapp(DbsWznm* dbswznm);
	bool handleCreateCrdblk(DbsWznm* dbswznm);
	bool handleCreateCrdcal(DbsWznm* dbswznm);
	bool handleCreateCrdcap(DbsWznm* dbswznm);
	bool handleCreateCrdcar(DbsWznm* dbswznm);
	bool handleCreateCrdchk(DbsWznm* dbswznm);
	bool handleCreateCrdcmp(DbsWznm* dbswznm);
	bool handleCreateCrdcon(DbsWznm* dbswznm);
	bool handleCreateCrdctp(DbsWznm* dbswznm);
	bool handleCreateCrddlg(DbsWznm* dbswznm);
	bool handleCreateCrderr(DbsWznm* dbswznm);
	bool handleCreateCrdevt(DbsWznm* dbswznm);
	bool handleCreateCrdfil(DbsWznm* dbswznm);
	bool handleCreateCrdiel(DbsWznm* dbswznm);
	bool handleCreateCrdiex(DbsWznm* dbswznm);
	bool handleCreateCrdime(DbsWznm* dbswznm);
	bool handleCreateCrdjob(DbsWznm* dbswznm);
	bool handleCreateCrdlib(DbsWznm* dbswznm);
	bool handleCreateCrdloc(DbsWznm* dbswznm);
	bool handleCreateCrdmch(DbsWznm* dbswznm);
	bool handleCreateCrdmdl(DbsWznm* dbswznm);
	bool handleCreateCrdmtd(DbsWznm* dbswznm);
	bool handleCreateCrdopk(DbsWznm* dbswznm);
	bool handleCreateCrdopx(DbsWznm* dbswznm);
	bool handleCreateCrdpnl(DbsWznm* dbswznm);
	bool handleCreateCrdprj(DbsWznm* dbswznm);
	bool handleCreateCrdprs(DbsWznm* dbswznm);
	bool handleCreateCrdpst(DbsWznm* dbswznm);
	bool handleCreateCrdqco(DbsWznm* dbswznm);
	bool handleCreateCrdqmd(DbsWznm* dbswznm);
	bool handleCreateCrdqry(DbsWznm* dbswznm);
	bool handleCreateCrdrel(DbsWznm* dbswznm);
	bool handleCreateCrdrls(DbsWznm* dbswznm);
	bool handleCreateCrdrtj(DbsWznm* dbswznm);
	bool handleCreateCrdsbs(DbsWznm* dbswznm);
	bool handleCreateCrdseq(DbsWznm* dbswznm);
	bool handleCreateCrdsge(DbsWznm* dbswznm);
	bool handleCreateCrdstb(DbsWznm* dbswznm);
	bool handleCreateCrdste(DbsWznm* dbswznm);
	bool handleCreateCrdtag(DbsWznm* dbswznm);
	bool handleCreateCrdtbl(DbsWznm* dbswznm);
	bool handleCreateCrdtco(DbsWznm* dbswznm);
	bool handleCreateCrdusg(DbsWznm* dbswznm);
	bool handleCreateCrdusr(DbsWznm* dbswznm);
	bool handleCreateCrdutl(DbsWznm* dbswznm);
	bool handleCreateCrdvec(DbsWznm* dbswznm);
	bool handleCreateCrdver(DbsWznm* dbswznm);
	bool handleCreateCrdvit(DbsWznm* dbswznm);
	bool handleEraseCrdapp(DbsWznm* dbswznm);
	bool handleEraseCrdblk(DbsWznm* dbswznm);
	bool handleEraseCrdcal(DbsWznm* dbswznm);
	bool handleEraseCrdcap(DbsWznm* dbswznm);
	bool handleEraseCrdcar(DbsWznm* dbswznm);
	bool handleEraseCrdchk(DbsWznm* dbswznm);
	bool handleEraseCrdcmp(DbsWznm* dbswznm);
	bool handleEraseCrdcon(DbsWznm* dbswznm);
	bool handleEraseCrdctp(DbsWznm* dbswznm);
	bool handleEraseCrddlg(DbsWznm* dbswznm);
	bool handleEraseCrderr(DbsWznm* dbswznm);
	bool handleEraseCrdevt(DbsWznm* dbswznm);
	bool handleEraseCrdfil(DbsWznm* dbswznm);
	bool handleEraseCrdiel(DbsWznm* dbswznm);
	bool handleEraseCrdiex(DbsWznm* dbswznm);
	bool handleEraseCrdime(DbsWznm* dbswznm);
	bool handleEraseCrdjob(DbsWznm* dbswznm);
	bool handleEraseCrdlib(DbsWznm* dbswznm);
	bool handleEraseCrdloc(DbsWznm* dbswznm);
	bool handleEraseCrdmch(DbsWznm* dbswznm);
	bool handleEraseCrdmdl(DbsWznm* dbswznm);
	bool handleEraseCrdmtd(DbsWznm* dbswznm);
	bool handleEraseCrdopk(DbsWznm* dbswznm);
	bool handleEraseCrdopx(DbsWznm* dbswznm);
	bool handleEraseCrdpnl(DbsWznm* dbswznm);
	bool handleEraseCrdprj(DbsWznm* dbswznm);
	bool handleEraseCrdprs(DbsWznm* dbswznm);
	bool handleEraseCrdpst(DbsWznm* dbswznm);
	bool handleEraseCrdqco(DbsWznm* dbswznm);
	bool handleEraseCrdqmd(DbsWznm* dbswznm);
	bool handleEraseCrdqry(DbsWznm* dbswznm);
	bool handleEraseCrdrel(DbsWznm* dbswznm);
	bool handleEraseCrdrls(DbsWznm* dbswznm);
	bool handleEraseCrdrtj(DbsWznm* dbswznm);
	bool handleEraseCrdsbs(DbsWznm* dbswznm);
	bool handleEraseCrdseq(DbsWznm* dbswznm);
	bool handleEraseCrdsge(DbsWznm* dbswznm);
	bool handleEraseCrdstb(DbsWznm* dbswznm);
	bool handleEraseCrdste(DbsWznm* dbswznm);
	bool handleEraseCrdtag(DbsWznm* dbswznm);
	bool handleEraseCrdtbl(DbsWznm* dbswznm);
	bool handleEraseCrdtco(DbsWznm* dbswznm);
	bool handleEraseCrdusg(DbsWznm* dbswznm);
	bool handleEraseCrdusr(DbsWznm* dbswznm);
	bool handleEraseCrdutl(DbsWznm* dbswznm);
	bool handleEraseCrdvec(DbsWznm* dbswznm);
	bool handleEraseCrdver(DbsWznm* dbswznm);
	bool handleEraseCrdvit(DbsWznm* dbswznm);

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmRefPreSet(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWznmRecaccess(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool handleCallWznmLog(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool handleCallWznmCrdOpen(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool handleCallWznmCrdActive(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, Sbecore::uint& ixRet);
	bool handleCallWznmCrdClose(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);

};

#endif
