/**
	* \file PnlWznmNavAppdev_evals.cpp
	* job handler for job PnlWznmNavAppdev (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavAppdev::evalLstAppAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButAppViewActive(
			DbsWznm* dbswznm
		) {
	// LstApp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstApp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalLstRtjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButRtjViewActive(
			DbsWznm* dbswznm
		) {
	// LstRtj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRtj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButRtjNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalLstEvtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButEvtViewActive(
			DbsWznm* dbswznm
		) {
	// LstEvt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstEvt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButEvtNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalLstSeqAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSeq()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButSeqViewActive(
			DbsWznm* dbswznm
		) {
	// LstSeq.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSeq != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButSeqNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalLstSteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSte()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButSteViewActive(
			DbsWznm* dbswznm
		) {
	// LstSte.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSte != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavAppdev::evalButSteNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};
