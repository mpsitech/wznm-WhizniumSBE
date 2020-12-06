/**
	* \file WznmGenJob.h
	* Wznm operation processor - generate job tree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMGENJOB_H
#define WZNMGENJOB_H

#include "WznmGen.h"

// IP include.cust --- IBEGIN
#include <algorithm>
// IP include.cust --- IEND

namespace WznmGenJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenJob* dpchinv);
	// IP cust --- IBEGIN

	Sbecore::ubigint genJobRoot(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string Prjshort);
	Sbecore::ubigint genJobSess(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string Prjshort, const Sbecore::ubigint refJobRoot);
	Sbecore::ubigint genJobM2msess(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string Prjshort, const Sbecore::ubigint refJobRoot);

	Sbecore::ubigint genJobCrd(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string Prjshort, const Sbecore::ubigint refJobSess, const std::string& crdroot, WznmMCard* crd, const Sbecore::ubigint refVecReqmod, const Sbecore::ubigint refVitRqidle);

	void genJobDlg(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const Sbecore::ubigint refJobCrd, const std::string& crdroot, WznmMDialog* dlg, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	Sbecore::ubigint genJobPnl(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string Prjshort, const Sbecore::ubigint refJobCrd, const Sbecore::ubigint refJobPnlrec, const std::string& crdroot, WznmMPanel* pnl, const Sbecore::ubigint refVecExpst, const Sbecore::ubigint refVitMind, const Sbecore::ubigint refVitRegd);

	void addBasecons(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& blks, std::map<Sbecore::ubigint,unsigned int>& bitnums, ListWznmMControl& cons, const Sbecore::ubigint refDit, const std::string& ditshort);
	void addCon(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& vecs, std::map<Sbecore::ubigint,unsigned int>& vitnums, std::map<std::string,Sbecore::ubigint>& blks, std::map<Sbecore::ubigint,unsigned int>& bitnums, std::map<std::string,Sbecore::ubigint>& feds, std::set<Sbecore::ubigint>& refsAlr, WznmMControl* con, const std::string& prefix);
	void addBit(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& blks, std::map<Sbecore::ubigint,unsigned int>& bitnums, const std::string& blkSref, const std::string& blkPostfix, const Sbecore::uint ixVBasetype, const std::string& sref, const Sbecore::uint ixWznmVVartype, const Sbecore::ubigint refWznmMControl, const Sbecore::ubigint refWznmMVector, const std::string& Defval, const Sbecore::ubigint refWznmMVectoritem);
	void addVit(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& vecs, std::map<Sbecore::ubigint,unsigned int>& vitnums, const std::string& vecSref, const std::string& sref);
	void genDpchappdata(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& blks);
	void genDpchappdo(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& vecs);
	void genDpchengdata(DbsWznm* dbswznm, WznmMJob* job, std::map<std::string,Sbecore::ubigint>& blks, std::map<std::string,Sbecore::ubigint>& feds, std::map<std::string,Sbecore::ubigint>& rsts);

	void genJobQry(DbsWznm* dbswznm, const std::string Prjshort, WznmMQuery* qry);

	void genJobIex(DbsWznm* dbswznm, const std::string Prjshort, WznmMImpexpcplx* iex, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void genJobIex_addSqk(DbsWznm* dbswznm, WznmMStage* sge, const std::map<Sbecore::ubigint,std::string>& iextits, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	void genOpkvecblks(DbsWznm* dbswznm, WznmMOppack* opk, ListWznmMOp& ops, const Sbecore::ubigint refVecKls, Sbecore::uint& vitnumKls, const Sbecore::ubigint refLcl);
	void genOpblks(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, WznmMOp* op);

	std::string getPnlqryPostfix(const std::string& pnlsref, const std::string& qrysref);

	Sbecore::ubigint convRefC(DbsWznm* dbswznm, const Sbecore::ubigint refC, std::map<Sbecore::ubigint,Sbecore::ubigint>& convRefCs);
	// IP cust --- IEND
};

#endif
