/**
	* \file PnlWznmTblRec_evals.cpp
	* job handler for job PnlWznmTblRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmTblRec::evalPnlatitleAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlaloadfctAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnl1nstubAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(mtb)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLEMTB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnl1ncheckAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnl1nsubsetAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(mtb)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLEMTB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnl1nimpexpAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlto1nrelationAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlfr1nrelationAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlfct1ntablecolAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlref1ncallAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlref1ndialogAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(mtb)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLEMTB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlpst1nquerymodAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlmnvectorAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalPnlmnqueryAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refTbl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

