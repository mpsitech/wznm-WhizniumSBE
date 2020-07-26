/**
	* \file PnlWznmNavJob_evals.cpp
	* job handler for job PnlWznmNavJob (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavJob::evalLstJobAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButJobViewActive(
			DbsWznm* dbswznm
		) {
	// LstJob.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstJob != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButJobNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalLstSgeAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSge()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButSgeViewActive(
			DbsWznm* dbswznm
		) {
	// LstSge.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSge != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButSgeNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalLstMtdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMtd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButMtdViewActive(
			DbsWznm* dbswznm
		) {
	// LstMtd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMtd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButMtdNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalLstBlkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBlk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBLK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButBlkViewActive(
			DbsWznm* dbswznm
		) {
	// LstBlk.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstBlk != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButBlkNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalLstCalAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButCalViewActive(
			DbsWznm* dbswznm
		) {
	// LstCal.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCal != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavJob::evalButCalNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

