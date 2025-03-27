/**
	* \file WznmCtpWrsrvDbeterm.cpp
	* Wznm operation processor - implement terminal panel (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpWrsrvDbeterm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrsrvDbeterm
 ******************************************************************************/

DpchRetWznm* WznmCtpWrsrvDbeterm::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrsrv* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	WznmMCapability* cpb = NULL;

	string Untsref, srcjobshort;

	string s;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		dbswznm->loadStringBySQL("SELECT Val FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = " + to_string(cpb->ref) + " AND x1SrefKKey = 'unt'", Untsref);

		if (dbswznm->loadStringBySQL("SELECT TblWznmMJob.sref FROM TblWznmRMCapabilityUniversal, TblWznmMJob WHERE TblWznmRMCapabilityUniversal.refWznmMCapability = " + to_string(cpb->ref) + " AND TblWznmRMCapabilityUniversal.unvIxWznmVMaintable = "
					+ to_string(VecWznmVMaintable::TBLWZNMMJOB) + " AND TblWznmMJob.ref = TblWznmRMCapabilityUniversal.unvUref", s)) srcjobshort = StrMod::lc(s.substr(3+4));

		// PnlXxxxYyyZzzzz.h, PnlXxxxYyyZzzzz.cpp
		s = xchg->tmppath + "/" + folder + "/Crd" + cpb->sref.substr(3, 4+3) + "/" + cpb->sref + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/Crd" + cpb->sref.substr(3, 4+3) + "/" + cpb->sref + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeCpbH(hfile, Untsref);
		writeCpbCpp(cppfile, Prjshort, cpb->sref, Untsref, srcjobshort);

		hfile.close();
		cppfile.close();

		delete cpb;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmCtpWrsrvDbeterm::writeCpbH(
			fstream& outfile
			, const string& Untsref
		) {
	// --- vars.cust
	outfile << "// IP vars.cust --- IBEGIN" << endl;
	outfile << "\t// IP vars.cust --- BEGIN" << endl;

	outfile << "\tstd::vector<std::string> hist;" << endl;

	outfile << "\t// IP vars.cust --- END" << endl;
	outfile << "// IP vars.cust --- IEND" << endl;

	// --- cust
	outfile << "// IP cust --- IBEGIN" << endl;
	outfile << "\t// IP cust --- BEGIN" << endl;

	outfile << "\tvoid parseCmd(" << Untsref.substr(0, 3+4) << "& unt, std::string s, Dbecore::Cmd*& cmd);" << endl;
	outfile << "\tSbecore::uint getCmdix(" << Untsref.substr(0, 3+4) << "& unt, const std::string& cmdsref);" << endl;
	outfile << "\tstd::string getCmdsref(" << Untsref.substr(0, 3+4) << "& unt, const Sbecore::uint cmdix);" << endl;

	outfile << "\t// IP cust --- END" << endl;
	outfile << "// IP cust --- IEND" << endl;
};

void WznmCtpWrsrvDbeterm::writeCpbCpp(
			fstream& outfile
			, const string& Prjshort
			, const string& Cpbsref
			, const string& Untsref
			, const string& srcjobshort
		) {
	string prjshort = StrMod::uncap(Prjshort);

	// --- ns.cust
	outfile << "// IP ns.cust --- IBEGIN" << endl;
	outfile << "// IP ns.cust --- BEGIN" << endl;

	outfile << "using namespace Dbecore;" << endl;

	outfile << "// IP ns.cust --- END" << endl;
	outfile << "// IP ns.cust --- IEND" << endl;

	// --- constructor.cust2
	outfile << "// IP constructor.cust2 --- IBEGIN" << endl;
	outfile << "\t// IP constructor.cust2 --- BEGIN" << endl;

	outfile << "\t" << Untsref << "& hw = " << srcjobshort << "->shrdat.hw;" << endl;
	outfile << endl;

	outfile << "\tFeed feedFCtr;" << endl;
	outfile << "\tFeed feedFCmd;" << endl;
	outfile << "\tFeeditem* fi = NULL;" << endl;
	outfile << "\tFeeditem* fi2 = NULL;" << endl;
	outfile << endl;

	outfile << "\t// establish command set" << endl;
	outfile << "\thw.fillFeedFController(feedFCtr);" << endl;
	outfile << endl;

	outfile << "\tfor (unsigned int i = 0; i < feedFCtr.size(); i++) {" << endl;
	outfile << "\t\tfi = feedFCtr.getByNum(i + 1);" << endl;
	outfile << endl;

	outfile << "\t\thw.fillFeedFCommand(fi->ix, feedFCmd);" << endl;
	outfile << endl;
		
	outfile << "\t\tfor (unsigned int j = 0; j < feedFCmd.size(); j++) {" << endl;
	outfile << "\t\t\tfi2 = feedFCmd.getByNum(j + 1);" << endl;
	outfile << "\t\t\tfeedFPupCmd.appendIxSrefTitles(256 * fi->ix + fi2->ix, fi->sref + \".\" + fi2->sref, fi->sref + \".\" + fi2->sref);" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;

	outfile << "\t// IP constructor.cust2 --- END" << endl;
	outfile << "// IP constructor.cust2 --- IEND" << endl;

	// --- refresh*
	outfile << "// IP refresh --- RBEGIN" << endl;
	outfile << "\t// IP refresh --- BEGIN" << endl;

	outfile << "\tbool takenNotAvailable, fulfilled;" << endl;
	outfile << endl;

	outfile << "\txchg->getCsjobClaim(" << srcjobshort << ", takenNotAvailable, fulfilled);" << endl;
	outfile << endl;

	outfile << "\t// continf" << endl;
	outfile << "\tContInf oldContinf(continf);" << endl;
	outfile << endl;

	outfile << "\tcontinf.ButClaimOn = fulfilled;" << endl;
	outfile << "\tcontinf.TxtCst = " << srcjobshort << "->getSquawk(dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\tif (hist.size() > 50) continf.TxtDatLog = \"(\" + to_string(hist.size() - 50) + \" previous log entries);\";" << endl;
	outfile << "\telse continf.TxtDatLog = \"\";" << endl;
	outfile << "\tfor (unsigned int i = (hist.size() > 50) ? hist.size() - 50 : 0; i < hist.size(); i++) continf.TxtDatLog += hist[i] + \";\";" << endl;
	outfile << endl;

	outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
	outfile << endl;

	outfile << "\t// statshr" << endl;
	outfile << "\tstatshr.ButClaimActive = !takenNotAvailable || fulfilled;" << endl;
	outfile << "\tstatshr.ButSmtActive = continf.ButClaimOn && (contiac.TxfCsq != \"\");" << endl;
	outfile << endl;

	outfile << "\t// IP refresh --- END" << endl;
	outfile << "// IP refresh --- REND" << endl;

	// --- handleDpchAppDataContiac
	outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;
	outfile << "\t// IP handleDpchAppDataContiac --- BEGIN" << endl;

	outfile << "\tif (has(diffitems, ContIac::NUMFPUPCMD)) {" << endl;
	outfile << "\t\tif (feedFPupCmd.getSrefByNum(_contiac->numFPupCmd) != \"\") contiac.numFPupCmd = _contiac->numFPupCmd;" << endl;
	outfile << "\t\telse contiac.numFPupCmd = 0;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (has(diffitems, ContIac::TXFCSQ)) contiac.TxfCsq = _contiac->TxfCsq;" << endl;
	outfile << endl;

	outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;

	outfile << "\t// IP handleDpchAppDataContiac --- END" << endl;
	outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;

	// --- handleDpchAppDoButClaimClick
	outfile << "// IP handleDpchAppDoButClaimClick --- IBEGIN" << endl;
	outfile << "\t// IP handleDpchAppDoButClaimClick --- BEGIN" << endl;

	outfile << "\tif (statshr.ButClaimActive) {" << endl;
	outfile << "\t\tmuteRefresh = true;" << endl;
	outfile << endl;

	outfile << "\t\tif (!continf.ButClaimOn) xchg->addCsjobClaim(dbs" << prjshort << ", " << srcjobshort << ", new Claim(true, true));" << endl;
	outfile << "\t\telse xchg->removeCsjobClaim(dbs" << prjshort << ", " << srcjobshort << ");" << endl;
	outfile << endl;

	outfile << "\t\trefreshWithDpchEng(dbs" << prjshort << ", dpcheng, true);" << endl;
	outfile << "\t};" << endl;

	outfile << "\t// IP handleDpchAppDoButClaimClick --- END" << endl;
	outfile << "// IP handleDpchAppDoButClaimClick --- IEND" << endl;

	// --- handleDpchAppDoButApdClick
	outfile << "// IP handleDpchAppDoButApdClick --- IBEGIN" << endl;
	outfile << "\t// IP handleDpchAppDoButApdClick --- BEGIN" << endl;

	outfile << "\t" << Untsref << "& hw = " << srcjobshort << "->shrdat.hw;" << endl;
	outfile << endl;

	outfile << "\tset<uint> moditems;" << endl;
	outfile << endl;

	outfile << "\tuint ix = feedFPupCmd.getIxByNum(contiac.numFPupCmd);" << endl;
	outfile << endl;
	
	outfile << "\tif (ix != 0) {" << endl;
	outfile << "\t\tif (contiac.TxfCsq != \"\") if (contiac.TxfCsq[contiac.TxfCsq.length() - 1] != ';') contiac.TxfCsq += \";\";" << endl;
	outfile << "\t\tcontiac.TxfCsq += hw.getCmdTemplate(ix >> 8, ix & 0xFF, false);" << endl;
	outfile << "\t\tinsert(moditems, DpchEngData::CONTIAC);" << endl;
	outfile << endl;

	outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
	outfile << "\t\t*dpcheng = getNewDpchEng(moditems);" << endl;
	outfile << "\t};" << endl;

	outfile << "\t// IP handleDpchAppDoButApdClick --- END" << endl;
	outfile << "// IP handleDpchAppDoButApdClick --- IEND" << endl;

	// --- handleDpchAppDoButSmtClick
	outfile << "// IP handleDpchAppDoButSmtClick --- IBEGIN" << endl;
	outfile << "\t// IP handleDpchAppDoButSmtClick --- BEGIN" << endl;

	outfile << "\tset<uint> moditems;" << endl;
	outfile << endl;

	outfile << "\t" << Untsref << "& hw = " << srcjobshort << "->shrdat.hw;" << endl;
	outfile << endl;

	outfile << "\tvector<string> ss;" << endl;
	outfile << "\tstring s;" << endl;
	outfile << endl;

	outfile << "\tCmd* cmd = NULL;" << endl;
	outfile << "\tbool truncated;" << endl;
	outfile << endl;

	outfile << "\tbool rxtxdump_old, histNotDump_old;" << endl;
	outfile << endl;

	outfile << "\tsize_t ptr;" << endl;
	outfile << endl;

	outfile << "\tif (statshr.ButSmtActive) {" << endl;
	outfile << "\t\tStrMod::stringToVector(contiac.TxfCsq, ss);" << endl;
	outfile << endl;

	outfile << "\t\tcontiac.TxfCsq = \"\";" << endl;
	outfile << "\t\tinsert(moditems, DpchEngData::CONTIAC);" << endl;
	outfile << endl;

	outfile << "\t\trxtxdump_old = hw.rxtxdump;" << endl;
	outfile << "\t\thw.rxtxdump = true;" << endl;
	outfile << endl;

	outfile << "\t\thistNotDump_old = hw.histNotDump;" << endl;
	outfile << "\t\thw.histNotDump = true;" << endl;
	outfile << endl;

	outfile << "\t\tfor (unsigned int i = 0; i < ss.size(); i++) {" << endl;
	outfile << "\t\t\thw.parseCmd(ss[i], cmd);" << endl;
	outfile << endl;

	outfile << "\t\t\tif (cmd) {" << endl;
	outfile << "\t\t\t\ts = cmd->getParsText(false, true, &truncated);" << endl;
	outfile << "\t\t\t\thist.push_back(hw.getCmdsref(256 * cmd->tixVController + cmd->tixVCommand) + \"(\" + s + \")\");" << endl;
	outfile << endl;

	outfile << "\t\t\t\thw.clearHist();" << endl;
	outfile << "\t\t\t\thw.runCmd(cmd);" << endl;
	outfile << endl;

	outfile << "\t\t\t\tptr = hist.size();" << endl;
	outfile << "\t\t\t\thw.copyHist(hist, true);" << endl;
	outfile << "\t\t\t\tfor (; ptr < hist.size(); ptr++) hist[ptr] = \"\t\" + hist[ptr];" << endl;
	outfile << endl;

	outfile << "\t\t\t\ts = cmd->getParsText(true, true, &truncated);" << endl;
	outfile << "\t\t\t\thist.push_back(\" = (\" + s + \")\");" << endl;
	outfile << endl;

	outfile << "\t\t\t\tdelete cmd;" << endl;
	outfile << "\t\t\t\tcmd = NULL;" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t\thw.rxtxdump = rxtxdump_old;" << endl;
	outfile << "\t\thw.histNotDump = histNotDump_old;" << endl;
	outfile << endl;

	outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
	outfile << "\t\t*dpcheng = getNewDpchEng(moditems);" << endl;
	outfile << "\t};" << endl;

	outfile << "\t// IP handleDpchAppDoButSmtClick --- END" << endl;
	outfile << "// IP handleDpchAppDoButSmtClick --- IEND" << endl;

	// --- handleCallXxxxClaimChgFromYyyyy
	outfile << "// IP handleCall" << Prjshort << "ClaimChgFrom" << StrMod::cap(srcjobshort) << " --- IBEGIN" << endl;
	outfile << "\t// IP handleCall" << Prjshort << "ClaimChgFrom" << StrMod::cap(srcjobshort) << " --- BEGIN" << endl;

	outfile << "\tset<uint> moditems;" << endl;
	outfile << endl;

	outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
	outfile << "\tif (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;

	outfile << "\t// IP handleCall" << Prjshort << "ClaimChgFrom" << StrMod::cap(srcjobshort) << " --- END" << endl;
	outfile << "// IP handleCall" << Prjshort << "ClaimChgFrom" << StrMod::cap(srcjobshort) << " --- IEND" << endl;
};
// IP cust --- IEND
