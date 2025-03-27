/**
	* \file PnlWznmNavVisual_evals.cpp
	* job handler for job PnlWznmNavVisual (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavVisual::evalLstVisAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalButVisViewActive(
			DbsWznm* dbswznm
		) {
	// LstVis.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVis != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalLstShtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalButShtViewActive(
			DbsWznm* dbswznm
		) {
	// LstSht.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSht != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalButShtNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalLstBoxAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBox()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalButBoxViewActive(
			DbsWznm* dbswznm
		) {
	// LstBox.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstBox != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavVisual::evalButBoxNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};
