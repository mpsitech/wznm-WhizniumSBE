/**
	* \file WznmWrsrvPref.cpp
	* Wznm operation processor - write/update preferences file (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvPref.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvPref
 ******************************************************************************/

DpchRetWznm* WznmWrsrvPref::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvPref* dpchinv
		) {
	ubigint refWznmMRelease = dpchinv->refWznmMRelease;
	string infile = dpchinv->infile;
	string outfile = dpchinv->outfile;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	WznmMComponent* cmp = NULL;
	string Prjshort;

	ListWznmMBlock stgblks;
	WznmMBlock* stgblk = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmJAMBlockItem* bitJ = NULL;

	WznmMVectoritem* vit = NULL;

	fstream xmlfile;

	string tag;

	string s;

	s = xchg->tmppath + "/" + outfile;
	xmlfile.open(s.c_str(), ios::out);

	xmlfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;

	if (dbswznm->tblwznmmcomponent->loadRecBySQL("SELECT TblWznmMComponent.* FROM TblWznmMComponent, TblWznmMRelease WHERE TblWznmMComponent.ref = TblWznmMRelease.refWznmMComponent AND TblWznmMRelease.ref = "
				+ to_string(refWznmMRelease), &cmp)) {

		if (dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMVersion.prjRefWznmMProject = TblWznmMProject.ref AND TblWznmMVersion.ref = "
					+ to_string(cmp->refWznmMVersion), Prjshort)) {
			Prjshort = StrMod::cap(Prjshort);

			if (cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) {
				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID)
							+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG) + ") <> 0 ORDER BY sref ASC", false, stgblks);

				// job-specific settings
				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG) + ") <> 0 AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP)
							+ ") = 0 ORDER BY sref ASC", true, stgblks);

				tag = "Pref" + Prjshort + "d";

			} else if (cmp->ixVBasetype == VecWznmVMComponentBasetype::OPENG) {
				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID)
							+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 ORDER BY sref ASC", false, stgblks);

				// operation pack-specific / operation-specific settings
				dbswznm->loadRefsBySQL("SELECT refWznmMOppack FROM TblWznmRMComponentMOppack WHERE refWznmMComponent = " + to_string(cmp->ref), false, refs);

				for (unsigned int i = 0; i < refs.size(); i++) {
					dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
								+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(refs[i]) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 ORDER BY sref ASC", true, stgblks);

					dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMOp, TblWznmMBlock WHERE TblWznmMOp.refWznmMOppack = " + to_string(refs[i]) + " AND TblWznmMBlock.refIxVTbl = "
								+ to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmMOp.ref AND TblWznmMBlock.ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
								+ " AND (TblWznmMBlock.wriIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 ORDER BY TblWznmMBlock.sref ASC", true, stgblks);
				};

				tag = "Pref" + Prjshort + "opd";

			} else if (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG) {
				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID)
							+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", false, stgblks);

				// job-specific settings
				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP)
							+ ") = 0 ORDER BY sref ASC", true, stgblks);

				// operation pack-specific / operation-specific settings
				dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " ORDER BY sref ASC", false, refs);

				for (unsigned int i = 0; i < refs.size(); i++) {
					dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
								+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(refs[i]) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", true, stgblks);

					dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMOp, TblWznmMBlock WHERE TblWznmMOp.refWznmMOppack = " + to_string(refs[i]) + " AND TblWznmMBlock.refIxVTbl = "
								+ to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmMOp.ref AND TblWznmMBlock.ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
								+ " AND (TblWznmMBlock.wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 ORDER BY TblWznmMBlock.sref ASC", true, stgblks);
				};

				tag = "Pref" + Prjshort + "cmbd";
			};

			xmlfile << "<" << tag << ">" << endl;

			for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
				stgblk = stgblks.nodes[i];

				dbswznm->tblwznmamblockitem->loadRstByBlk(stgblk->ref, false, bits);

				xmlfile << "\t<" << stgblk->sref << ">" << endl;

				for (unsigned int j = 0; j < bits.nodes.size(); j++) {
					bit = bits.nodes[j];

					if (dbswznm->tblwznmjamblockitem->loadRecByBitRls(bit->ref, refWznmMRelease, &bitJ)) {
						bit->Defval = bitJ->Defval;
						bit->refWznmMVectoritem = bitJ->refWznmMVectoritem;

						delete bitJ;
					};

					if ( (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) || (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT)
								|| (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::INT)
								|| (bit->ixWznmVVartype == VecWznmVVartype::UINT) || (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) ||(bit->ixWznmVVartype == VecWznmVVartype::UBIGINT)
								|| (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) || (bit->ixWznmVVartype == VecWznmVVartype::STRING)
								|| (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) ) {

						xmlfile << "\t\t<Si sref=\"" << bit->sref << "\">" << bit->Defval << "</Si>" << endl;

					} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						if (dbswznm->tblwznmmvectoritem->loadRecByRef(bit->refWznmMVectoritem, &vit)) {
							xmlfile << "\t\t<Si sref=\"sref" << StrMod::cap(bit->sref) << "\">";
							xmlfile << vit->sref;
							xmlfile << "</Si>" << endl;

							delete vit;

						} else {
							xmlfile << "\t\t<Si sref=\"sref" << StrMod::cap(bit->sref) << "\"/>" << endl;
						};
	

					} else {
						// BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, FLOATMAT, DOUBLEVEC, DOUBLEMAT
						xmlfile << "\t\t<Si sref=\"" << bit->sref << "\"/>" << endl;
					};
				};

				xmlfile << "\t</" << stgblk->sref << ">" << endl;
			};

			xmlfile << "</" << tag << ">" << endl;
		};

		delete cmp;
	};

	xmlfile.close();
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


