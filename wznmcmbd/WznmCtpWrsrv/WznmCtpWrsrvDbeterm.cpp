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

	// --- modify PnlXxxxYyyTerm.h
/*
	outfile << "// IP vars.cust --- IBEGIN" << endl;
	std::vector<std::string> hist;
	outfile << "// IP vars.cust --- IEND" << endl;

	outfile << "// IP cust --- IBEGIN" << endl;
	void parseCmd(UntWskd& unt, std::string s, Dbecore::Cmd*& cmd);
	Sbecore::uint getCmdix(UntWskd& unt, const std::string& cmdsref);
	std::string getCmdsref(UntWskd& unt, const Sbecore::uint cmdix);
	outfile << "// IP cust --- IEND" << endl;
*/

	// --- modify PnlXxxxYyyTerm.cpp
/*
	outfile << "// IP ns.cust --- IBEGIN" << endl;
using namespace Dbecore;
	outfile << "// IP ns.cust --- IEND" << endl;

	outfile << "// IP constructor.cust2 --- IBEGIN" << endl;
	UntWskdArty& hw = srcfpga->shrdat.hw;

	Feed feedFCtr;
	Feed feedFCmd;
	Feeditem* fi = NULL;
	Feeditem* fi2 = NULL;

	// establish command set
	hw.fillFeedFController(feedFCtr);

	for (unsigned int i = 0; i < feedFCtr.size(); i++) {
		fi = feedFCtr.getByNum(i + 1);

		hw.fillFeedFCommand(fi->ix, feedFCmd);
		
		for (unsigned int j = 0; j < feedFCmd.size(); j++) {
			fi2 = feedFCmd.getByNum(j + 1);
			feedFPupCmd.appendIxSrefTitles(256 * fi->ix + fi2->ix, fi->sref + "." + fi2->sref, fi->sref + "." + fi2->sref);
		};
	};
	outfile << "// IP constructor.cust2 --- IEND" << endl;

	outfile << "// IP cust --- IBEGIN" << endl;
void PnlWzskLlvTerm::parseCmd(
			UntWskd& unt
			, string s
			, Cmd*& cmd
		) {
	string cmdsref;
	uint cmdix;

	utinyint tixVController;
	utinyint tixVCommand;

	if (cmd) delete cmd;
	cmd = NULL;

	size_t ptr;

	if (s.length() == 0) return;
	if (s[s.length()-1] != ')') return;
	s = s.substr(0, s.length()-1);
	ptr = s.find('(');
	if (ptr == string::npos) return;

	cmdix = getCmdix(unt, s.substr(0, ptr));
	tixVController = (cmdix >> 8);
	tixVCommand = (cmdix & 0xFF);
	s = s.substr(ptr+1);

	cmd = unt.getNewCmd(tixVController, tixVCommand);
	if (cmd) cmd->parlistToParsInv(s);
};

uint PnlWzskLlvTerm::getCmdix(
			UntWskd& unt
			, const string& cmdsref
		) {
	utinyint tixVController = 0;
	utinyint tixVCommand = 0;

	size_t ptr;

	ptr = cmdsref.find('.');

	if (ptr != string::npos) {
		tixVController = unt.getTixVControllerBySref(cmdsref.substr(0, ptr));
		tixVCommand = unt.getTixVCommandBySref(tixVController, cmdsref.substr(ptr+1));

		return((tixVController << 8) + tixVCommand);

	} else return 0;
};

string PnlWzskLlvTerm::getCmdsref(
			UntWskd& unt
			, const uint cmdix
		) {
	string cmdsref;

	utinyint tixVController = (cmdix >> 8);
	utinyint tixVCommand = (cmdix & 0xFF);

	cmdsref = unt.getSrefByTixVController(tixVController);
	cmdsref += ".";
	cmdsref += unt.getSrefByTixVCommand(tixVController, tixVCommand);

	return cmdsref;
};
	outfile << "// IP cust --- IEND" << endl;

	outfile << "// IP refresh --- RBEGIN" << endl;
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(srcfpga, takenNotAvailable, fulfilled);

	// continf 
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtCst = srcfpga->getSquawk(dbswzsk);

	if (hist.size() > 50) continf.TxtDatLog = "(" + to_string(hist.size() - 50) + " previous log entries);";
	else continf.TxtDatLog = "";
	for (unsigned int i = (hist.size() > 50) ? hist.size() - 50 : 0; i < hist.size(); i++) continf.TxtDatLog += hist[i] + ";";

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;
	statshr.ButSmtActive = continf.ButClaimOn && (contiac.TxfCsq != "");
	outfile << "// IP refresh --- REND" << endl;

	outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;

	if (has(diffitems, ContIac::NUMFPUPCMD)) if (feedFPupCmd.getAvailByNum(_contiac->numFPupCmd)) contiac.numFPupCmd = _contiac->numFPupCmd;
	if (has(diffitems, ContIac::TXFCSQ)) contiac.TxfCsq = _contiac->TxfCsq;

	refresh(dbswzsk, moditems);

	outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;

	outfile << "// IP handleDpchAppDoButClaimClick --- IBEGIN" << endl;
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, srcfpga, new JobWzskSrcFpga::Claim(true, true, false, false, false, false));
		else xchg->removeCsjobClaim(dbswzsk, srcfpga);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	outfile << "// IP handleDpchAppDoButClaimClick --- IEND" << endl;

	outfile << "// IP handleDpchAppDoButApdClick --- IBEGIN" << endl;
	UntWskdArty& hw = srcfpga->shrdat.hw;

	set<uint> moditems;

	uint ix = feedFPupCmd.getIxByNum(contiac.numFPupCmd);
	
	if (ix != 0) {
		if (contiac.TxfCsq != "") if (contiac.TxfCsq[contiac.TxfCsq.length() - 1] != ';') contiac.TxfCsq += ";";
		contiac.TxfCsq += hw.getCmdTemplate(ix >> 8, ix & 0xFF, false);
		insert(moditems, DpchEngData::CONTIAC);

		refresh(dbswzsk, moditems);
		*dpcheng = getNewDpchEng(moditems);
	};
	outfile << "// IP handleDpchAppDoButApdClick --- IEND" << endl;


	outfile << "// IP handleDpchAppDoButSmtClick --- IBEGIN" << endl;
	set<uint> moditems;

	UntWskdArty& hw = srcfpga->shrdat.hw;

	vector<string> ss;
	string s;

	Cmd* cmd = NULL;
	bool truncated;

	size_t ptr;

	if (statshr.ButSmtActive) {
		StrMod::stringToVector(contiac.TxfCsq, ss);

		contiac.TxfCsq = "";
		insert(moditems, DpchEngData::CONTIAC);

		for (unsigned int i = 0; i < ss.size(); i++) {
			parseCmd(hw, ss[i], cmd);

			if (cmd) {
				s = cmd->getInvText(true, &truncated);
				hist.push_back(getCmdsref(hw, 256 * cmd->tixVController + cmd->tixVCommand) + "(" + s + ")");

				hw.clearHist();
				hw.runCmd(cmd);

				ptr = hist.size();
				hw.copyHist(hist, true);
				for (; ptr < hist.size(); ptr++) hist[ptr] = "\t" + hist[ptr];

				s = cmd->getRetText(true, &truncated);
				hist.push_back(" = (" + s + ")");

				delete cmd;
				cmd = NULL;
			};
		};

		refresh(dbswzsk, moditems);
		*dpcheng = getNewDpchEng(moditems);
	};
	outfile << "// IP handleDpchAppDoButSmtClick --- IEND" << endl;

	outfile << "// IP handleCallWzskClaimChgFromSrcfpga --- IBEGIN" << endl;
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	outfile << "// IP handleCallWzskClaimChgFromSrcfpga --- IEND" << endl;
*/

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
