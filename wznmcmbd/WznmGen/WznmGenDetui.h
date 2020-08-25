/**
	* \file WznmGenDetui.h
	* Wznm operation processor - generate detailed user interface (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMGENDETUI_H
#define WZNMGENDETUI_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenDetui {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenDetui* dpchinv);
	// IP cust --- IBEGIN

	/**
		* WznmGenDetui::Ap
		*/
	class Ap {

	public:
		Ap();

	public:
		bool success;

		ListWznmMRelation rels;

	public:
		void step(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMTable, const Sbecore::ubigint refWznmMSubset, const Sbecore::ubigint refPsttbl, std::vector<Ap*>& aps);
		void step_collect(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMTable, const Sbecore::ubigint refWznmMSubset, const Sbecore::uint ixVBasetype, const bool supzero, ListWznmMRelation& rels);
	};

	void run_genCarbase(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, WznmMCard* car, ListWznmMControl& cons, unsigned int& connum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	std::string run_pnlsrefklst(DbsWznm* dbswznm, const std::string& carsref, WznmMTable* tbl, WznmMVector* vec, std::map<Sbecore::ubigint,WznmMTable*>& mtbs);
	void run_addKlsts(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refSbs, const Sbecore::ubigint refPst, const std::string& cond, std::vector<Sbecore::ubigint>& refsVec, std::map<Sbecore::ubigint,WznmMTable*>& mtbs, std::map<Sbecore::ubigint,Sbecore::ubigint>& refsPst, std::map<Sbecore::ubigint,std::string>& sbsconds);
	void run_addRelauxs(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refSbs, const Sbecore::ubigint refPst, const std::string& cond, std::vector<Sbecore::ubigint>& refsRel, std::map<Sbecore::ubigint, WznmMTable*>& mtbs, std::map<Sbecore::ubigint,Sbecore::ubigint>& refsPst, std::map<Sbecore::ubigint,std::string>& sbsconds);
	void run_addRel1ns(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refSbs, const Sbecore::ubigint refPst, const std::string& cond, std::vector<Sbecore::ubigint>& refsRel, std::map<Sbecore::ubigint, WznmMTable*>& mtbs, std::map<Sbecore::ubigint,Sbecore::ubigint>& refsPst, std::map<Sbecore::ubigint,std::string>& sbsconds);
	void run_addRelmns(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refSbs, const Sbecore::ubigint refPst, const std::string& cond, std::vector<Sbecore::ubigint>& refsRel, std::map<Sbecore::ubigint, WznmMTable*>& mtbs, std::map<Sbecore::ubigint,Sbecore::ubigint>& refsPst, std::map<Sbecore::ubigint,std::string>& sbsconds);

	void genCarnav(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::vector<std::string>& sesspsts, WznmMCard* car, ListWznmMControl& cons, unsigned int& connum, ListWznmMModule& mdls, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genPnlprenav(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, const std::vector<std::string>& sesspsts, const Sbecore::uint pnlnum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genPnlnav(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::vector<std::string>& sesspsts, WznmMCard* car, WznmMModule* mdl, const Sbecore::uint pnlnum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void genPnlnav_cjtcar(DbsWznm* dbswznm, WznmMControl* con, WznmMCard* car, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genCartbl(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, ListWznmMControl& cons, unsigned int& connum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genPnllist(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, WznmMTable* cartbl, const Sbecore::ubigint refCarsbs, const Sbecore::uint pnlnum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void genPnllist_collectPsts(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, Sbecore::Expr::Node* node, std::vector<Sbecore::ubigint>& refsPst, std::vector<Sbecore::ubigint>& refsPsttbl);
	std::string genPnllist_getSbsevalsql(DbsWznm* dbswznm, WznmMTable* tbl, ListWznmMTablecol& tcos, std::map<std::string,WznmMTablecol*>& shortsTcos, Sbecore::Expr::Node* node, const bool wrtbl);

	void genPnltbl_cjtstd(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtstdstr(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl, std::string& s);
	void genPnltbl_cjtvec(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtvecstr(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl, std::string& s);
	void genPnltbl_cjtrel(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtrelstr(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, std::string& s);
	void genPnltbl_cjtrelpl(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtrelplstr(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, std::string& s);
	void genPnltbl_cjtreluniv(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtrelunivstr(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl, std::string& s);
	void genPnltbl_cjtrelauxpref(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtrelauxprefstr(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, std::string& s);
	void genPnltbl_cjtstrel(DbsWznm* dbswznm, WznmMControl* con, WznmMTable* sttbl, WznmMTable* tbl, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnltbl_cjtstrelstr(DbsWznm* dbswznm, WznmMTable* sttbl, WznmMTable* tbl, const Sbecore::ubigint refLcl, std::string& s);
	void genPnl_cjttag(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const std::string& srefTag, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void genPnltbl_qao(DbsWznm* dbswznm, WznmMQuery* qry, const std::string& tblsref, WznmMTablecol* tco);

	void genPnlrec(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, WznmMTable* tbl, WznmMSubset* sbs, const Sbecore::uint pnlnum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genPnlprerec(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, ListWznmMPreset& psts, const Sbecore::uint pnlnum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genPnldetail(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::vector<std::string>& sesspsts, WznmMCard* car, WznmMTable* cartbl, const Sbecore::ubigint refCarsbs, ListWznmMTable& inctbls, std::map<Sbecore::ubigint,std::string>& incconds, std::map<Sbecore::ubigint,std::string>& incsbsconds, const std::vector<std::string>& carrecpsts, const std::vector<std::string>& carpsts, const Sbecore::uint pnlnum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void genPnldetail_cjtstd(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnldetail_cjtstdstr(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl, std::string& s);
	void genPnldetail_cjtvec(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnldetail_cjtvecstr(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl, std::string& s);
	void genPnldetail_cjtrel(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnldetail_cjtrelstr(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, std::string& s);
	void genPnldetail_cjtrelpl(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnldetail_cjtrelplstr(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, std::string& s);
	void genPnldetail_cjtreluniv(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnldetail_cjtrelunivstr(DbsWznm* dbswznm, WznmMTablecol* tco, const Sbecore::ubigint refLcl, std::string& s);
	void genPnldetail_cjtrelauxpref(DbsWznm* dbswznm, WznmMControl* con, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnldetail_cjtrelauxprefstr(DbsWznm* dbswznm, WznmMTablecol* tco, WznmMRelation* rel, const Sbecore::ubigint refLcl, std::string& s);

	void genPnlklst(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, WznmMTable* mtb, const Sbecore::ubigint refPst, const std::string& sbscond, const Sbecore::uint pnlnum, const std::string& pnlsref, WznmMVector* vec, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnlklst_cptstr(DbsWznm* dbswznm, WznmMPanel* pnl, WznmMVector* vec, const Sbecore::ubigint refLcl, std::string& s);

	void genPnlaux(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, WznmMCard* car, const Sbecore::ubigint refPst, const std::string& sbscond, const Sbecore::uint pnlnum, const std::string& pnlsref, WznmMRelation* pnlrel, WznmMTable* reltbl, const bool relenum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnlaux_cptstr(DbsWznm* dbswznm, WznmMPanel* pnl, const Sbecore::ubigint refRel, const Sbecore::ubigint refAuxrel, const Sbecore::ubigint refTbl, const Sbecore::ubigint refLcl, std::string& s);

	void genPnl1n(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::vector<std::string>& sesspsts, WznmMCard* car, const std::vector<std::string>& carrecpsts, const std::vector<std::string>& carpsts, const Sbecore::uint pnlnum, WznmMRelation* pnlrel, const std::string& pnlsref, const Sbecore::ubigint refPst, const std::string& sbscond, WznmMTable* reltbl, const bool relenum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnl1n_cptstr(DbsWznm* dbswznm, WznmMPanel* pnl, WznmMRelation* rel, WznmMTable* tbl, const Sbecore::ubigint refLcl, std::string& s);
	bool genPnl1n_colstr(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refLcl, std::string& s);

	void genPnlmn(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const std::vector<std::string>& sesspsts, WznmMCard* car, const std::vector<std::string>& carrecpsts, const std::vector<std::string>& carpsts, const Sbecore::uint pnlnum, WznmMRelation* pnlrel, const std::string& pnlsref, const Sbecore::ubigint refPst, const std::string& sbscond, WznmMRelation* opprel, WznmMTable* reltbl, WznmMTable* maintbl, const bool relenum, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	bool genPnlmn_cptstr(DbsWznm* dbswznm, WznmMPanel* pnl, WznmMRelation* rel, WznmMTable* tbl, const Sbecore::ubigint refLcl, std::string& s);
	bool genPnlmn_colstr(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refLcl, std::string& s);

	void addQcostbuniv(DbsWznm* dbswznm, const std::string& Prjshort, const Sbecore::ubigint refQco, ListWznmMTablecol& tcos, WznmMTablecol* tco);
	void addConstbstd(DbsWznm* dbswznm, const std::string& Prjshort, WznmMControl* con, const Sbecore::ubigint refTbl, const Sbecore::ubigint refSbs = 0, const bool sho = false);

	bool getCarstrSng(DbsWznm* dbswznm, WznmMCard* car, const Sbecore::ubigint refLcl, std::string& s);
	bool getCarstrPl(DbsWznm* dbswznm, WznmMCard* car, const Sbecore::ubigint refLcl, std::string& s);
	unsigned int getTaglen(DbsWznm* dbswznm, const std::string sref, const std::string osrefWznmKTaggrp, const Sbecore::ubigint refLcl);

	Sbecore::ubigint getStbByReftblsbs(DbsWznm* dbswznm, const std::string& Prjshort, Sbecore::ubigint refTbl, const Sbecore::ubigint refSbs, const std::string& Short);

	Sbecore::uint getTcoArgtype(WznmMTablecol* tco);

	std::string andConds(const std::string& cond1, const std::string& cond2 = "", const std::string& cond3 = "", const std::string& cond4 = "", const std::string& cond5 = "", const std::string& cond6 = "");
	std::string getAvail(const std::list<Trg*>& trgs, const bool newNotView);
	// IP cust --- IEND
};

#endif


