/**
	* \file PnlWznmNavUix_evals.cpp
	* job handler for job PnlWznmNavUix (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavUix::evalLstPstAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButPstViewActive(
			DbsWznm* dbswznm
		) {
	// LstPst.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPst != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButPstNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstMdlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMdl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButMdlViewActive(
			DbsWznm* dbswznm
		) {
	// LstMdl.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMdl != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButMdlNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstCarAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCar()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButCarViewActive(
			DbsWznm* dbswznm
		) {
	// LstCar.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCar != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButCarNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstDlgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccDlg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButDlgViewActive(
			DbsWznm* dbswznm
		) {
	// LstDlg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDlg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButDlgNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstPnlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButPnlViewActive(
			DbsWznm* dbswznm
		) {
	// LstPnl.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPnl != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButPnlNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstQryAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQry()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButQryViewActive(
			DbsWznm* dbswznm
		) {
	// LstQry.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstQry != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButQryNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstQcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButQcoViewActive(
			DbsWznm* dbswznm
		) {
	// LstQco.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstQco != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButQcoNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstQmdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButQmdViewActive(
			DbsWznm* dbswznm
		) {
	// LstQmd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstQmd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButQmdNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalLstConAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButConViewActive(
			DbsWznm* dbswznm
		) {
	// LstCon.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCon != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavUix::evalButConNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};
