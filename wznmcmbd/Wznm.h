/**
	* \file Wznm.h
	* Wznm global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNM_H
#define WZNM_H

#define WZNM_VERSION "1.1.6"
#define WZNM_VERSION_MAJOR 1
#define WZNM_VERSION_MINOR 1
#define WZNM_VERSION_SUB 6

// IP include.cust --- IBEGIN
#include <sys/wait.h>
// IP include.cust --- IEND

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "VecWznmVBasereptype.h"
#include "VecWznmVCall.h"
#include "VecWznmVDpch.h"
#include "VecWznmVError.h"
#include "VecWznmVExpstate.h"
#include "VecWznmVIop.h"
#include "VecWznmVJob.h"
#include "VecWznmVMimetype.h"
#include "VecWznmVOpengtype.h"
#include "VecWznmVOppack.h"
#include "VecWznmVQrystate.h"
#include "VecWznmVReqitmode.h"
#include "VecWznmVStub.h"
#include "VecWznmVTag.h"

#include <DbsWznm.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Stub.h>

/**
	* Acv
	*/
namespace Acv {
	Sbecore::ubigint addfile(DbsWznm* dbswznm, const std::string& acvpath, const std::string& path, const Sbecore::ubigint grp, const Sbecore::ubigint own, const Sbecore::uint refIxVTbl, const Sbecore::ubigint refUref, const std::string& osrefKContent, const std::string& Filename, const std::string& srefKMimetype, const std::string& Comment);
	void alterfile(DbsWznm* dbswznm, const std::string& acvpath, const std::string& path, const Sbecore::ubigint ref);
	std::string getfile(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMFile);
};

/**
	* Lop
	*/
namespace Lop {
	void apply(const Sbecore::uint ixWznmVLop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);

	void insert(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
};

/**
	* Oolop
	*/
namespace Oolop {
	void apply(const Sbecore::uint ixWznmVOolop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);

	void insertBefore(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void insertAfter(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void toBefore(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void toAfter(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void swap(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
};

/**
	* Tmp
	*/
namespace Tmp {
	std::string newfile(const std::string& tmppath, const std::string& ext);
	std::string newfolder(const std::string& tmppath);
	std::string random();
};

// IP cust --- IBEGIN
/**
  * Concplxtype
  */
namespace Concplxtype {
	const unsigned int INVALID = 1;
	const unsigned int BUT_CLUST = 2;
	const unsigned int CHK = 3;
	const unsigned int CUS = 4;
	const unsigned int DLD = 5;
	const unsigned int HDG = 6;
	const unsigned int LST = 7;
	const unsigned int LST_NOALT = 8;
	const unsigned int LST_TXFALT = 9;
	const unsigned int LST_TXTALT = 10;
	const unsigned int PUP = 11;
	const unsigned int PUP_PUP = 12;
	const unsigned int PUP_TXFALT = 13;
	const unsigned int PUP_VBAR = 14;
	const unsigned int RBU = 15;
	const unsigned int SEP = 16;
	const unsigned int SLD = 17;
	const unsigned int SPC = 18;
	const unsigned int TXF = 19;
	const unsigned int TXT = 20;
	const unsigned int TXT_PUP = 21;
	const unsigned int TXT_TXFALT = 22;
	const unsigned int ULD = 23;
	const unsigned int UPD = 24;
	
	std::string getSref(const unsigned int ix);
};

/**
  * Trg
  */
class Trg {

public:
	Trg(const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint incRefWznmMTablecol = 0, const std::string& cond1 = "", const std::string& cond2 = "", const std::string& srefWznmMCard = "", const std::string& carrecpstcond = "", const std::string carpstcond = "", const std::string& sesspstcond = "");

public:
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint refWznmMSubset;
	Sbecore::ubigint incRefWznmMTablecol;
	std::string cond1;
	std::string cond2;
	std::string srefWznmMCard;
	std::string carrecpstcond;
	std::string carpstcond;
	std::string sesspstcond;
};
// IP cust --- IEND

/**
	* Wznm
	*/
namespace Wznm {
	// IP gbl --- IBEGIN
	std::string getPrjshort(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);

	void getVerlclref(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, Sbecore::ubigint& refLcl);
	void getVerlclsref(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, std::string& srefLcl);
	void getVerlclrefs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, Sbecore::ubigint& refLcl, std::vector<Sbecore::ubigint>& refsLcl);
	void getVerlcls(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, Sbecore::ubigint& refLcl, std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void updateVerste(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const Sbecore::uint ixVState);
	void getTagtits(DbsWznm* dbswznm, const std::string& sref, const std::string& osrefWznmKTaggrp, const std::string& prj, const std::map<Sbecore::ubigint,std::string>& iextits, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, std::map<Sbecore::ubigint,std::string>& tagTits, const bool esc = true);
	void fillVecFromTaggrp(DbsWznm* dbswznm, WznmMVector* vec, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	bool hasSubset(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMTable);
	void getSbsrels(DbsWznm* dbswznm, const Sbecore::ubigint refTbl, const Sbecore::ubigint refAsb, std::set<Sbecore::ubigint>& refsSbsainb, std::set<Sbecore::ubigint>& refsSbsbina, std::set<Sbecore::ubigint>& refsSbsxsec); // used @ WznmGenDetui
	bool getPnlconAvail(DbsWznm* dbswznm, const Sbecore::ubigint refSbs, std::set<Sbecore::ubigint>& refsSbsainb, std::set<Sbecore::ubigint>& refsSbsbina, std::set<Sbecore::ubigint>& refsSbsxsec, WznmMTable* basetbl, const Sbecore::ubigint refSbsTest, std::string& Avail); // used for pnlavail/conavail @ WznmGenDetui

	void getSesspsts(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, std::vector<std::string>& sesspsts);

	Sbecore::ubigint getRefCtp(DbsWznm* dbswznm, const std::string& sref);
	void getSrefsCtpCustops(DbsWznm* dbswznm, std::map<Sbecore::ubigint,std::string>& srefsCtpCustops, const Sbecore::uint ixWznmVKeylist);

	bool getCpa(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMCapability, const std::string& x1SrefKKey, std::string& Val);

	bool getLibmkf(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMLibrary, const Sbecore::ubigint x1RefWznmMMachine, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x2SrefKTag, std::string& Val);

	bool getMchmkf(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMMachine, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x1SrefKTag, std::string& Val);
	bool getMchpar(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMMachine, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& x1SrefKKey, std::string& Val);

	void getCarincs(DbsWznm* dbswznm, WznmMCard* car, ListWznmMTable& inctbls, std::map<Sbecore::ubigint,std::string>& incconds, std::map<Sbecore::ubigint,std::string>& incsbsconds);
	void getCarrecpsts(DbsWznm* dbswznm, WznmMCard* car, std::vector<std::string>& carrecpsts);
	void getCarpsts(const std::vector<std::string>& sesspsts, WznmMCard* car, std::vector<std::string>& carsesspsts, std::vector<std::string>& carpsts, bool& always, bool& never);
	void getCarpsts_collect(const std::vector<std::string>& sesspsts, WznmMCard* car, Sbecore::Expr::Node* node, std::vector<std::string>& carsesspsts, std::vector<std::string>& carpsts);

	void collectTrgs(DbsWznm* dbswznm, const std::vector<std::string>& sesspsts, WznmMCard* basecar, const std::vector<std::string>& basecarrecpsts, const std::vector<std::string>& basecarpsts, WznmMTable* basetbl, WznmMTablecol* basetco, WznmMRelation* rel, const bool toNotFr, std::list<Trg*>& trgs); // used for ButNew/ButView @ WznmGenDetui, WznmWrsrvPnl
	void collectTrgs_matchPsts(const std::vector<std::string>& sesspsts, const std::vector<std::string>& basecarrecpsts, const std::vector<std::string>& basecarpsts, WznmMCard* trgcar, const std::string& cond2, std::list<Trg*>& trgs, std::list<Trg*>::iterator it);

	void getCrdsubjobs(DbsWznm* dbswznm, ListWznmMJob& jobs, const Sbecore::ubigint refWznmMJob);

	void getPnlrecs(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, WznmMPanel* pnl, ListWznmMTable& tbls, const bool jump = false); // used @ WznmGenChk, WznmWrsrvPnl
	void collectPsts(Sbecore::Expr::Node* node, std::set<std::string>& psts); // recursive, in analogy to writePnlCpp_collectIcsCarpst()
	void collectChks(std::set<std::string>& tblshorts, std::set<std::string>& skiptblshorts, Sbecore::Expr::Node* node, std::set<std::string>& chks); // recursive, used in WznmGenChk

	Sbecore::uint getPnlreltype(DbsWznm* dbswznm, WznmMPanel* pnl);
	bool getPnllhs(DbsWznm* dbswznm, WznmMPanel* pnl);
	bool getPnlrhs(DbsWznm* dbswznm, WznmMPanel* pnl);
	std::string getConsref(WznmMControl* con, const std::string& ditshort);
	std::string getConstatblk(WznmMControl* con);
	unsigned int getConheight(DbsWznm* dbswznm, WznmMControl* con);
	void loadDitcons(DbsWznm* dbswznm, const Sbecore::ubigint refDit, ListWznmMControl& cons);
	void getBasecons(DbsWznm* dbswznm, ListWznmMControl& cons, const std::set<Sbecore::uint>& hkIcsVSection, const Sbecore::ubigint refDit, std::vector<unsigned int>& icsBasecons);
	void analyzeBasecon(DbsWznm* dbswznm, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const unsigned int ixIcsBasecons, const std::string& ditshort, unsigned int& cplxtype, std::string& baseconsref, std::string& baseconshort, bool& ldyn, bool& dyn, bool& rdyn, bool& vbar, unsigned int& ix0, unsigned int& ix1, unsigned int& ixBut, unsigned int& ixButCollapse, unsigned int& ixButEdit, unsigned int& ixButExpand, unsigned int& ixButToggle, unsigned int& ixButView, std::vector<unsigned int>& icsButs, unsigned int& ixChk, unsigned int& ixCpt, unsigned int& ixHdg, unsigned int& ixLsb, unsigned int& ixPup, unsigned int& ixTxf, unsigned int& ixTxt, std::vector<unsigned int>& icsVbarcons);
	void showBasecons(DbsWznm* dbswznm, ListWznmMControl& cons, std::vector<unsigned int>& icsBasecons, const std::string& ditshort);

	void getJobvars(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMJob, ListWznmAMJobVar& vars, std::vector<std::string>& varsrefs, std::vector<bool>& Shrs, std::vector<unsigned int>& Ns);
	void getJobevals(DbsWznm* dbswznm, WznmMJob* job, std::vector<std::string>& bitsEval, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval);
	std::string getSubsref(WznmMJob* job, const std::string& sref);

	int run(const std::string& cmd);
	bool tgz(const std::string& infolder, const std::string& tgzfile, const bool verbose = false);
	bool untgz(const std::string& tgzfile, const std::string& outfolder, const bool verbose = false);

	std::string encrypt(const std::string& s);
	std::string decrypt(const std::string& s);
	// IP gbl --- IEND
};

/**
	* OpengWznm
	*/
namespace OpengWznm {
	void getIcsWznmVOppackByIxWznmVOpengtype(const Sbecore::uint ixWznmVOpengtype, std::vector<Sbecore::uint>& icsWznmVOppack);
	void getIcsWznmVDpchByIxWznmVOppack(const Sbecore::uint ixWznmVOppack, std::set<Sbecore::uint>& icsWznmVDpch);
};

/**
	* StubWznm
	*/
namespace StubWznm {
	std::string getStub(DbsWznm* dbswznm, const Sbecore::uint ixWznmVStub, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);

	std::string getStubAppStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubBlkStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCalStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCapStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCarStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubChkStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCmpStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubConSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubConStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCpbSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCpbStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCtpSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubCtpStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubDlgStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubEvtStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFedSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFedStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubFilStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubGroup(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubIelStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubIexStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubImeStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubJobStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLibSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLibStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLocSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubLocStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMchSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMchStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMdlStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubMtdStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOpkStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOpxStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOwner(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPnlStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrjShort(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrjStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrsStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPstStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubQcoStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubQmdStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubQryStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRelStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRlsStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRtbStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRtdStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubRtjStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSbsStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSeqStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesMenu(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSgeStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSqkStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubStbStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSteStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTagStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTblStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTcoSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubTcoStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsgStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsrStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVecStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVerNo(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVerShort(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVerStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVitSref(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubVitStd(DbsWznm* dbswznm, const Sbecore::ubigint ref, const Sbecore::uint ixWznmVLocale = VecWznmVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
	* WznmException
	*/
class WznmException : public Sbecore::SbeException {

public:
	static const Sbecore::uint LIC_AUTH = 1001;
	static const Sbecore::uint LIC_CTWARN = 1002;
	static const Sbecore::uint LIC_CTLOST = 1003;

public:
	WznmException(const Sbecore::uint ix, const std::map<std::string,std::string>& vals);

public:
	std::string getSref();
};

/**
	* ContInfWznmAlert
	*/
class ContInfWznmAlert : public Sbecore::Block {

public:
	static const Sbecore::uint TXTCPT = 1;
	static const Sbecore::uint TXTMSG1 = 2;
	static const Sbecore::uint TXTMSG2 = 3;
	static const Sbecore::uint TXTMSG3 = 4;
	static const Sbecore::uint TXTMSG4 = 5;
	static const Sbecore::uint TXTMSG5 = 6;
	static const Sbecore::uint TXTMSG6 = 7;
	static const Sbecore::uint TXTMSG7 = 8;
	static const Sbecore::uint TXTMSG8 = 9;
	static const Sbecore::uint TXTMSG9 = 10;
	static const Sbecore::uint TXTMSG10 = 11;
	static const Sbecore::uint TXTMSG11 = 12;
	static const Sbecore::uint TXTMSG12 = 13;

public:
	ContInfWznmAlert(const std::string& TxtCpt = "", const std::string& TxtMsg1 = "", const std::string& TxtMsg2 = "", const std::string& TxtMsg3 = "", const std::string& TxtMsg4 = "", const std::string& TxtMsg5 = "", const std::string& TxtMsg6 = "", const std::string& TxtMsg7 = "", const std::string& TxtMsg8 = "", const std::string& TxtMsg9 = "", const std::string& TxtMsg10 = "", const std::string& TxtMsg11 = "", const std::string& TxtMsg12 = "");

public:
	std::string TxtCpt;
	std::string TxtMsg1;
	std::string TxtMsg2;
	std::string TxtMsg3;
	std::string TxtMsg4;
	std::string TxtMsg5;
	std::string TxtMsg6;
	std::string TxtMsg7;
	std::string TxtMsg8;
	std::string TxtMsg9;
	std::string TxtMsg10;
	std::string TxtMsg11;
	std::string TxtMsg12;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const ContInfWznmAlert* comp);
};

/**
	* DpchWznm
	*/
class DpchWznm : public Sbecore::Block {

public:
	DpchWznm(const Sbecore::uint ixWznmVDpch = 0);
	virtual ~DpchWznm();

public:
	Sbecore::uint ixWznmVDpch;
};

/**
	* DpchInvWznm
	*/
class DpchInvWznm : public DpchWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchInvWznm(const Sbecore::uint ixWznmVDpch = VecWznmVDpch::DPCHINVWZNM, const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchInvWznm();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWznm
	*/
class DpchRetWznm : public DpchWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;

public:
	DpchRetWznm(const Sbecore::uint ixWznmVDpch = VecWznmVDpch::DPCHRETWZNM, const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::utinyint ixOpVOpres = Sbecore::VecOpVOpres::PROGRESS, const Sbecore::utinyint pdone = 0);
	virtual ~DpchRetWznm();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;
	Sbecore::utinyint ixOpVOpres;
	Sbecore::utinyint pdone;

public:
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif
