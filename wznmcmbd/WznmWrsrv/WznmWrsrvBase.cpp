/**
	* \file WznmWrsrvBase.cpp
	* Wznm operation processor - write server C++ code basics (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvBase
 ******************************************************************************/

DpchRetWznm* WznmWrsrvBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;

	WznmMVersion* ver = NULL;

	fstream hfile;
	fstream cppfile;

	string s;

	Wznm::getVerlcls(dbswznm, refWznmMVersion, refLcl, refsLcl, lcls);

	if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
		// create files
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeGblH(dbswznm, hfile, ver, Prjshort);
		writeGblCpp(dbswznm, cppfile, ver, Prjshort, refLcl, refsLcl, lcls);

		cppfile.close();
		hfile.close();

		delete ver;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvBase::writeGblH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, const string& Prjshort
		) {
	vector<ubigint> refs;
	ubigint ref;

	string srefLcl;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMStub stbs;
	WznmMStub* stb = NULL;

	ListWznmMError errs;
	WznmMError* err = NULL;

	// --- include.vecs
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ((ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = "
				+ to_string(VecWznmVMVectorBasetype::OR) + ")) AND ((hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::VOID) + ") OR (hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + ")) AND hkUref = 0 ORDER BY sref ASC", false, vecs);

	outfile << "// IP include.vecs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		outfile << "#include \"" << vec->sref << ".h\"" << endl;
	};
	outfile << "// IP include.vecs --- IEND" << endl;

/// prelim.
	// --- acv*
	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(ver->ref) + " AND tplRefWznmMCapability = " + to_string(Wznm::getRefCtp(dbswznm, "acv")), ref)) outfile << "// IP acv --- AFFIRM" << endl;
	else outfile << "// IP acv --- REMOVE" << endl;

	// --- stubs
	dbswznm->loadStringBySQL("SELECT TblWznmMLocale.sref FROM TblWznmMVersion, TblWznmMLocale WHERE TblWznmMLocale.ref = TblWznmMVersion.refWznmMLocale AND TblWznmMVersion.ref = "
				+ to_string(ver->ref), srefLcl);

	dbswznm->loadRefsBySQL("SELECT TblWznmMStub.ref FROM TblWznmMTable, TblWznmMStub WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = "
				+ to_string(ver->ref) + " ORDER BY TblWznmMStub.sref ASC", false, refs);
	dbswznm->tblwznmmstub->loadRstByRefs(refs, false, stbs);

	outfile << "// IP stubs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
		stb = stbs.nodes[i];

		outfile << "\tstd::string getStub" << stb->sref.substr(4+4) << "(Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", const Sbecore::ubigint ref, const Sbecore::uint ix" << Prjshort << "VLocale = Vec" << Prjshort << "VLocale::" << StrMod::uc(srefLcl)
					<< ", const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);" << endl;
	};
	outfile << "// IP stubs --- IEND" << endl;

	// --- exc.consts
	dbswznm->tblwznmmerror->loadRstByVer(ver->ref, false, errs);

	outfile << "// IP exc.consts --- IBEGIN" << endl;
	for (unsigned int i = 0; i < errs.nodes.size(); i++) {
		err = errs.nodes[i];

		outfile << "\tstatic const Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(err->sref)) << " = " << (1000+err->verNum) << ";" << endl;
	};
	outfile << "// IP exc.consts --- IEND" << endl;
};

void WznmWrsrvBase::writeGblCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, const string& Prjshort
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	vector<ubigint> refs;
	ubigint ref;

	ListWznmMComponent cmps;
	WznmMComponent* cmp = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ListWznmMStub stbs;
	WznmMStub* stb = NULL;

	ListWznmMError errs;
	WznmMError* err = NULL;

	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;

	WznmMLocale* lcl = NULL;

	map<ubigint,string> nonenTits;
	map<ubigint,string> nonemTits;
	map<ubigint,string> nonefTits;

	map<ubigint,string> nonTits;
	map<ubigint,string> nomTits;
	map<ubigint,string> nofTits;

	map<ubigint,string> tagTits;
	map<ubigint,string> tagTits2;
	map<ubigint,string> tagTits3;

	WznmAMTableTitle* tat = NULL;
	WznmAMSubsetTitle* sat = NULL;

	vector<string> shorts;
	vector<string> fulls;

	uint ixWznmVGender;

	vector<string> ss;
	string s, s2;

	bool first;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	dbswznm->loadRefsBySQL("SELECT TblWznmMStub.ref FROM TblWznmMTable, TblWznmMStub WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = "
				+ to_string(ver->ref) + " ORDER BY TblWznmMStub.sref ASC", false, refs);
	dbswznm->tblwznmmstub->loadRstByRefs(refs, false, stbs);

/// prelim.
	// --- acv*
	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(ver->ref) + " AND tplRefWznmMCapability = " + to_string(Wznm::getRefCtp(dbswznm, "acv")), ref)) outfile << "// IP acv --- AFFIRM" << endl;
	else outfile << "// IP acv --- REMOVE" << endl;

	// --- getIcsXxxxVOppackByIxXxxxVOpengtype
	outfile << "// IP getIcs" << Prjshort << "VOppackByIx" << Prjshort << "VOpengtype --- IBEGIN" << endl;

	dbswznm->tblwznmmcomponent->loadRstBySQL("SELECT * FROM TblWznmMComponent WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMComponentBasetype::OPENG)
					+ " ORDER BY sref ASC", false, cmps);

	for (unsigned int i = 0; i < cmps.nodes.size(); i++) {
		cmp = cmps.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ix" << Prjshort << "VOpengtype == Vec" << Prjshort << "VOpengtype::" << StrMod::uc(cmp->sref) << ") {" << endl;

		dbswznm->tblwznmmoppack->loadRstBySQL("SELECT TblWznmMOppack.* FROM TblWznmRMComponentMOppack, TblWznmMOppack WHERE TblWznmRMComponentMOppack.refWznmMComponent = "
					+ to_string(cmp->ref) + " AND TblWznmMOppack.ref = TblWznmRMComponentMOppack.refWznmMOppack ORDER BY TblWznmMOppack.sref ASC", false, opks);

		for (unsigned int j = 0; j < opks.nodes.size(); j++) {
			opk = opks.nodes[j];
			outfile << "\t\tpush_back(ics" << Prjshort << "VOppack, Vec" << Prjshort << "VOppack::" << StrMod::uc(opk->sref) << ");" << endl;
		};
	};
	if (cmps.nodes.size() > 0) outfile << "\t};" << endl;

	outfile << "// IP getIcs" << Prjshort << "VOppackByIx" << Prjshort << "VOpengtype --- IEND" << endl;

	// --- getIcsXxxxVDpchByIxXxxxVOppack
	outfile << "// IP getIcs" << Prjshort << "VDpchByIx" << Prjshort << "VOppack --- IBEGIN" << endl;

		dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(ver->ref) + " ORDER BY sref ASC", false, opks);

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ix" << Prjshort << "VOppack == Vec" << Prjshort << "VOppack::" << StrMod::uc(opk->sref) << ") {" << endl;

		if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
			outfile << "\t\tinsert(ics" << Prjshort << "VDpch, Vec" << Prjshort << "VDpch::DPCHINV" << StrMod::uc(opk->sref) << ");" << endl;

		} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
			dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);

			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];
				outfile << "\t\tinsert(ics" << Prjshort << "VDpch, Vec" << Prjshort << "VDpch::DPCHINV" << StrMod::uc(op->sref) << ");" << endl;
			};
		};
	};
	if (opks.nodes.size() > 0) outfile << "\t};" << endl;

	outfile << "// IP getIcs" << Prjshort << "VDpchByIx" << Prjshort << "VOppack --- IEND" << endl;

	// --- stub.getStub
	outfile << "// IP stub.getStub --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
		stb = stbs.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (ix" << Prjshort << "VStub == Vec" << Prjshort << "VStub::" << StrMod::uc(stb->sref) << ") return getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", ref, ix" << Prjshort << "VLocale, ixVNonetype, stcch, strefSub, refresh);" << endl;
	};
	outfile << "// IP stub.getStub --- IEND" << endl;

	// --- stubs
	outfile << "// IP stubs --- IBEGIN" << endl;

	// prepare "none"/"no" strings by locale upfront
	Wznm::getTagtits(dbswznm, "n", "none", "", {}, refLcl, refsLcl, nonenTits);
	Wznm::getTagtits(dbswznm, "m", "none", "", {}, refLcl, refsLcl, nonemTits);
	Wznm::getTagtits(dbswznm, "f", "none", "", {}, refLcl, refsLcl, nonefTits);

	Wznm::getTagtits(dbswznm, "n", "no", "", {}, refLcl, refsLcl, nonTits);
	Wznm::getTagtits(dbswznm, "m", "no", "", {}, refLcl, refsLcl, nomTits);
	Wznm::getTagtits(dbswznm, "f", "no", "", {}, refLcl, refsLcl, nofTits);

	for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
		stb = stbs.nodes[i];

		shorts.resize(0);
		fulls.resize(0);

		for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
			lcl = lcls.nodes[j];

			ixWznmVGender = VecWznmVGender::N;
			s = "";

			// find localized table/subset title (sngfull)
			if (stb->refWznmMSubset != 0) {
				// subset title
				if (dbswznm->tblwznmamsubsettitle->loadRecBySQL("SELECT * FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = " + to_string(stb->refWznmMSubset) + " AND x1IxVType = "
							+ to_string(VecWznmVAMSubsetTitleType::SNGFULL) + " AND x2RefWznmMLocale = " + to_string(lcl->ref), &sat)) {
					ixWznmVGender = sat->ixWznmVGender;
					s = sat->Title;

					delete sat;
				};

			} else {
				// table title
				if (dbswznm->tblwznmamtabletitle->loadRecBySQL("SELECT * FROM TblWznmAMTableTitle WHERE refWznmMTable = " + to_string(stb->refWznmMTable) + " AND x1IxVType = "
							+ to_string(VecWznmVAMTableTitleType::SNGFULL) + " AND x2RefWznmMLocale = " + to_string(lcl->ref), &tat)) {
					ixWznmVGender = tat->ixWznmVGender;
					s = tat->Title;

					delete tat;
				};
			};

			s2 = "-";
			if (ixWznmVGender == VecWznmVGender::N) s2 = nonenTits[lcl->ref];
			else if (ixWznmVGender == VecWznmVGender::M) s2 = nonemTits[lcl->ref];
			else if (ixWznmVGender == VecWznmVGender::F) s2 = nonefTits[lcl->ref];
			shorts.push_back(s2);

			s2 = "-";
			if (ixWznmVGender == VecWznmVGender::N) s2 = nonTits[lcl->ref];
			else if (ixWznmVGender == VecWznmVGender::M) s2 = nomTits[lcl->ref];
			else if (ixWznmVGender == VecWznmVGender::F) s2 = nofTits[lcl->ref];
			s2 = StrMod::replacePlh(s2, "title", s);
			fulls.push_back(s2);
		};

		dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMTable WHERE ref = " + to_string(stb->refWznmMTable), s);

		outfile << "string Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, const ubigint ref" << endl;
		outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t\t, const uint ixVNonetype" << endl;
		outfile << "\t\t\t, Stcch* stcch" << endl;
		outfile << "\t\t\t, stcchitemref_t* strefSub" << endl;
		outfile << "\t\t\t, const bool refresh" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\t// example: \"" << stb->Example << "\"" << endl;

		outfile << "\tstring stub;" << endl;
		outfile << endl;

		if ((stb->ixVBasetype == VecWznmVMStubBasetype::CUST) || stb->Hierarch) {
			outfile << "\t" << s.substr(3) << "* rec = NULL;" << endl;
			outfile << endl;
		};

		outfile << "\tstcchitemref_t stref(Vec" << Prjshort << "VStub::" << StrMod::uc(stb->sref) << ", ref, ix" << Prjshort << "VLocale);" << endl;
		outfile << "\tStcchitem* stit = NULL;" << endl;
		outfile << endl;

		outfile << "\tif (stcch) {" << endl;
		outfile << "\t\tstit = stcch->getStitByStref(stref);" << endl;
		outfile << "\t\tif (stit && !refresh) {" << endl;
		outfile << "\t\t\tif (strefSub) stcch->link(stref, *strefSub);" << endl;
		outfile << "\t\t\treturn stit->stub;" << endl;
		outfile << "\t\t};" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tif (ixVNonetype == Stub::VecVNonetype::DASH) stub = \"-\";" << endl;
		outfile << "\telse if (ixVNonetype == Stub::VecVNonetype::SHORT) {" << endl;

		for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
			lcl = lcls.nodes[j];

			outfile << "\t\t";
			if (j != 0) outfile << "else ";
			outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") stub = \"" << StrMod::esc(shorts[j]) << "\";" << endl;
		};

		outfile << "\t} else if (ixVNonetype == Stub::VecVNonetype::FULL) {" << endl;

		for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
			lcl = lcls.nodes[j];

			outfile << "\t\t";
			if (j != 0) outfile << "else ";
			outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") stub = \"" << StrMod::esc(fulls[j]) << "\";" << endl;
		};

		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tif (ref != 0) {" << endl;
		if ((stb->ixVBasetype == VecWznmVMStubBasetype::CUST) || stb->Hierarch) {
			outfile << "\t\tif (dbs" << prjshort << "->" << StrMod::lc(s) << "->loadRecByRef(ref, &rec)) {" << endl;
			outfile << "\t\t\tif (stcch && !stit) stit = stcch->addStit(stref);" << endl;

			if ((stb->ixVBasetype == VecWznmVMStubBasetype::TCO) && stb->Hierarch) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(stb->refWznmMTablecol, &tco)) {
					outfile << "\t\t\tstub = rec->" << tco->sref << ";" << endl;

					if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(tco->tblRefWznmMTable) + " AND TblWznmMTablecol.ixVBasetype = "
								+ to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMRelation.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::H1N) + " AND TblWznmMRelation.toRefWznmMTable = "
								+ to_string(tco->tblRefWznmMTable), &tco2)) {
						outfile << "\t\t\tif (rec->" << tco2->sref << " != 0) stub = getStub" << stb->sref.substr(4+4) << "(dbs" + prjshort + ", rec->" << tco2->sref << ", ix" << Prjshort << "VLocale, ixVNonetype, stcch, &stref) + \";\" + stub;" << endl;
						delete tco2;
					};

					delete tco;
				};

			} else {
				if (stb->sref == ("Stub" + Prjshort + "AdrStd")) {
					outfile << "\t\t\t// IP getStub" << Prjshort << "AdrStd --- BEGIN" << endl;
					outfile << "\t\t\tstub = dbs" << prjshort << "->getKlstTitleBySref(Vec" << Prjshort << "VKeylist::KLST" << PRJSHORT << "KMADDRESSCOUNTRY, rec->srefKCountry, ix" << Prjshort << "VLocale);" << endl;
					outfile << "\t\t\tif (stub.length() > 0) stub = \", \" + stub;" << endl;
					outfile << "\t\t\tstub = rec->City + stub;" << endl;
					outfile << "\t\t\tif (rec->Zipcode.length() > 0) stub = rec->Zipcode + \" \" + stub;" << endl;
					outfile << "\t\t\tif (rec->Address1.length() > 0) stub = rec->Address1 + \", \" + stub;" << endl;
					outfile << "\t\t\t// IP getStub" << Prjshort << "AdrStd --- END" << endl;

				} else if (stb->sref == ("Stub" + Prjshort + "PrsStd")) {
					outfile << "\t\t\t// IP getStub" << Prjshort << "PrsStd --- BEGIN" << endl;
					outfile << "\t\t\tstub = rec->Lastname;" << endl;
					outfile << "\t\t\tif (rec->Firstname.length() > 0) stub = rec->Firstname + \" \" + stub;" << endl;
					outfile << "\t\t\t// IP getStub" << Prjshort << "PrsStd --- END" << endl;

				} else if (stb->sref == ("Stub" + Prjshort + "SesMenu")) {
					outfile << "\t\t\t// IP getStub" << Prjshort << "SesMenu --- BEGIN" << endl;

					Wznm::getTagtits(dbswznm, "usr.sngfull", "stdtbl", "", {}, refLcl, refsLcl, tagTits, false);
					Wznm::getTagtits(dbswznm, "logfrom", "", "", {}, refLcl, refsLcl, tagTits2, false);
					Wznm::getTagtits(dbswznm, "since", "", "", {}, refLcl, refsLcl, tagTits3, false);

					first = true;

					for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
						lcl = lcls.nodes[j];

						StrMod::stringToVector(tagTits[lcl->ref], ss);

						if (ss.size() == 2) {
							outfile << "\t\t\t";

							if (first) first = false;
							else outfile << "else ";

							outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") stub = \"";
							outfile << ss[1] << " \" + getStubUsrStd(dbs" << prjshort << ", rec->ref" << Prjshort << "MUser, ix" << Prjshort << "VLocale, ixVNonetype, stcch, &stref) + \";";
							outfile << tagTits2[lcl->ref] << " \" + rec->Ip + \";";
							outfile << tagTits3[lcl->ref] << " \" + Ftm::stamp(rec->start);" << endl;
						};
					};

					outfile << "\t\t\t// IP getStub" << Prjshort << "SesMenu --- END" << endl;

				} else if (stb->sref == ("Stub" + Prjshort + "SesStd")) {
					outfile << "\t\t\t// IP getStub" << Prjshort << "SesStd --- BEGIN" << endl;

					Wznm::getTagtits(dbswznm, "from", "", "", {}, refLcl, refsLcl, tagTits, false);

					for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
						lcl = lcls.nodes[j];

						outfile << "\t\t\t";
						if (j != 0) outfile << "else ";

						outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") stub = Ftm::stamp(rec->start) + \" ";
						outfile << tagTits[lcl->ref] << " \" + rec->Ip;" << endl;
					};

					outfile << "\t\t\t// IP getStub" << Prjshort << "SesStd --- END" << endl;

				} else if (stb->sref == ("Stub" + Prjshort + "UsrStd")) {
					outfile << "\t\t\t// IP getStub" << Prjshort << "UsrStd --- BEGIN" << endl;
					outfile << "\t\t\tstub = rec->sref + \" / \" + getStubPrsStd(dbs" << prjshort << ", rec->ref" << Prjshort << "MPerson, ix" << Prjshort << "VLocale, ixVNonetype, stcch, &stref);" << endl;
					outfile << "\t\t\t// IP getStub" << Prjshort << "UsrStd --- END" << endl;

				} else {
					outfile << "\t\t\t// IP getStub" << stb->sref.substr(4+4) << " --- INSERT" << endl;
				};
			};

			outfile << "\t\t\tif (stit) stit->stub = stub;" << endl;
			outfile << "\t\t\tdelete rec;" << endl;
			outfile << "\t\t};" << endl;

		} else {
			if (dbswznm->tblwznmmtablecol->loadRecByRef(stb->refWznmMTablecol, &tco)) {
				outfile << "\t\tif (dbs" << StrMod::lc(Prjshort) << "->" << StrMod::lc(s) << "->load" << StrMod::cap(tco->Short) << "ByRef(ref, stub)) {" << endl;
				outfile << "\t\t\tif (stcch) {" << endl;
				outfile << "\t\t\t\tif (!stit) stit = stcch->addStit(stref);" << endl;
				outfile << "\t\t\t\tstit->stub = stub;" << endl;
				outfile << "\t\t\t};" << endl;
				outfile << "\t\t};" << endl;

				delete tco;
			};
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn stub;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP stubs --- IEND" << endl;

	// --- exc.getSref
	dbswznm->tblwznmmerror->loadRstByVer(ver->ref, false, errs);

	outfile << "// IP exc.getSref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < errs.nodes.size(); i++) {
		err = errs.nodes[i];

		outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(err->sref)) << ") return(\"" << err->sref << "\");" << endl;
	};
	outfile << "// IP exc.getSref --- IEND" << endl;
};

void WznmWrsrvBase::writeVecappH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, WznmMVector* vec
		) {
	outfile << "// IP vec --- IBEGIN" << endl;
	writeVecH(dbswznm, Prjshort, outfile, vec, false, "");
	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrsrvBase::writeVecappCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, WznmMVector* vec
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
		) {
	outfile << "// IP vec --- IBEGIN" << endl;
	writeVecCpp(dbswznm, Prjshort, outfile, vec, false, "", "", refLcl, refsLcl);
	outfile << "// IP vec --- IEND" << endl;
};
// IP cust --- IEND


