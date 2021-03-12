/**
	* \file CrdWznmVer.cpp
	* job handler for job CrdWznmVer (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "CrdWznmVer.h"

#include "CrdWznmVer_blks.cpp"
#include "CrdWznmVer_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWznmVer
 ******************************************************************************/

CrdWznmVer::CrdWznmVer(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
			, const ubigint ref
			, const uint ixWznmVPreset
			, const ubigint preUref
		) :
			JobWznm(xchg, VecWznmVJob::CRDWZNMVER, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;
	dlgbscui = NULL;
	dlgcustjob = NULL;
	dlgcustjtr = NULL;
	dlgcustui = NULL;
	dlgglobal = NULL;
	dlggenjtr = NULL;
	dlggenui = NULL;
	dlgfinmod = NULL;
	dlgdeploy = NULL;
	dlgnew = NULL;
	dlgimpexp = NULL;
	dlgdbstr = NULL;
	dlgoppack = NULL;
	dlgwrinimdl = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref, ixWznmVPreset);
	if (ixWznmVPreset != VecWznmVPreset::VOID) xchg->addRefPreset(ixWznmVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFVER, ref);

	// initialize according to ref
	changeRef(dbswznm, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWznmVerList(xchg, dbswznm, jref, ixWznmVLocale);
	pnlrec = new PnlWznmVerRec(xchg, dbswznm, jref, ixWznmVLocale);
	pnlheadbar = new PnlWznmVerHeadbar(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswznm, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWznmVerNew(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswznm, VecVSge::IDLE);

	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWznmVer::~CrdWznmVer() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void CrdWznmVer::handleShowJobtree_subjobs(
			DbsWznm* dbswznm
			, const ubigint supRefWznmMJob
			, const unsigned int il
		) {
	WznmMJob* job = NULL;

	ListWznmRMJobMJob jrjs;
	WznmRMJobMJob* jrj = NULL;

	if (dbswznm->tblwznmmjob->loadRecByRef(supRefWznmMJob, &job)) {
		for (unsigned int i = 0; i < il; i++) cout << "\t";
		cout << job->sref << endl;

		delete job;

		dbswznm->tblwznmrmjobmjob->loadRstBySup(supRefWznmMJob, false, jrjs);
		for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
			jrj = jrjs.nodes[i];
			handleShowJobtree_subjobs(dbswznm, jrj->subRefWznmMJob, il+1);
		};
	};
};

string CrdWznmVer::handleWriteHtml_tcotit(
			DbsWznm* dbswznm
			, const ubigint refWznmMTablecol
			, const ubigint refLocEnus
		) {
	// cf. various WznmGenDetui.genPnldetail_cjt*

	// 1st try: tco full; 2nd try: rel {to/from}full; 3rd try: vec/tbl full/sref
	string retval;

	WznmMTablecol* tco = NULL;
	WznmMRelation* rel = NULL;

	bool found;

	bool toNotFr;

	if (dbswznm->tblwznmmtablecol->loadRecByRef(refWznmMTablecol, &tco)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLocEnus, retval)) {
			found = false;

			if (tco->refWznmMRelation != 0) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
					found = true;

					toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

					if (toNotFr) {
						if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOSNGFULL, refLocEnus, retval))
							if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->toRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval)) found = false;

					} else {
						if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLocEnus, retval))
							if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval)) found = false;
					};
				};
			};

			if (!found) {
				if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) {
					found = dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tco->fctUref, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval);
					if (!found) found = dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tco->fctUref, VecWznmVAMTableTitleType::PLFULL, refLocEnus, retval);
					if (!found) found = dbswznm->tblwznmmtable->loadSrfByRef(tco->fctUref, retval);

				} else if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
					found = dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(tco->fctUref, VecWznmVAMVectorTitleType::FULL, refLocEnus, retval);
				};
			};
		};

		delete tco;
	};

	return retval;
};

string CrdWznmVer::handleWriteDbsHtml_tbltit(
			DbsWznm* dbswznm
			, WznmMTable* tbl
			, const ubigint refLocEnus
		) {
	string retval = tbl->sref;

	WznmMRelation* rel = NULL;
	WznmMTable* tbl2 = NULL;

	if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST) {
		retval = "Cluster table";

	} else if ((tbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) || (tbl->ixVBasetype == VecWznmVMTableBasetype::AUX)) {
		// plfull
		dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::PLFULL, refLocEnus, retval);

	} else if (tbl->ixVBasetype == VecWznmVMTableBasetype::JUMP) {
		// sngfull
		dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tbl->ref, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval);

	} else if (tbl->ixVBasetype == VecWznmVMTableBasetype::REL) {
		// fromtable.plfull M:N totable.plfull
		if (dbswznm->tblwznmmrelation->loadRecByRef(tbl->refUref, &rel)) {
			retval = "M:N";

			if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
				retval = handleWriteDbsHtml_tbltit(dbswznm, tbl2, refLocEnus) + " " + retval;
				delete tbl2;
			};

			if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &tbl2)) {
				retval = retval + " " + handleWriteDbsHtml_tbltit(dbswznm, tbl2, refLocEnus);
				delete tbl2;
			};

			delete rel;
		};
	};

	retval = StrMod::cap(retval);

	return retval;
};

void CrdWznmVer::handleWriteDbsHtml_tcos(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& tblsref
			, ListWznmMTablecol& tcos
			, map<ubigint, string>& anchorsTbls
			, const ubigint refLocEnus
		) {
	string head = "<table width=\"100%\" cellpadding=\"3\" cellspacing=\"0\">\n";
	head += "\t<col width=\"90*\"/>\n";
	head += "\t<col width=\"166*\"/>\n";
	head += "\t<tr valign=\"top\">\n";
	head += "\t\t<th width=\"35%\" bgcolor=\"#000000\" style=\"background: #000000; border: 1px solid #000000; padding-top: 0.1cm; padding-bottom: 0.1cm; padding-left: 0.1cm; padding-right: 0cm\">\n";
	head += "\t\t\t<font color=\"#ffffff\" face=\"Liberation Serif, serif\" size=\"3\" style=\"font-size: 12pt\"><span style=\"text-decoration: underline\">Column</span></font>\n";
	head += "\t\t</th>\n";
	head += "\t\t<th width=\"65%\" bgcolor=\"#000000\" style=\"background: #000000\" style=\"border: 1px solid #000000; padding: 0.1cm\">\n";
	head += "\t\t\t<font color=\"#ffffff\" face=\"Liberation Serif, serif\" size=\"3\" style=\"font-size: 12pt\"><span style=\"text-decoration: underline\">Content</span></font>\n";
	head += "\t\t</th>\n";
	head += "\t</tr>\n";

	string foot = "</table>\n";
	foot += "<br>\n\n";

	WznmMTablecol* tco = NULL;

	WznmMTable* tbl = NULL;

	WznmMVector* vec = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	string s;

	outfile << head;

	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];

		outfile << "\t<tr valign=\"top\">" << endl;

		outfile << "\t\t<td width=\"35%\" style=\"background: transparent; border: 1px solid #000000; padding-top: 0cm; padding-bottom: 0.1cm; padding-left: 0.1cm; padding-right: 0cm\">" << endl;

		outfile << "\t\t\t<font color=\"#000000\" face=\"Liberation Serif, serif\" size=\"3\" style=\"font-size: 12pt\"><span style=\"text-decoration: none; font-style: normal; font-weight: normal\">" << tco->sref << "</span></font><br>" << endl;

		outfile << "\t\t\t<font color=\"#000000\" face=\"Liberation Serif, serif\" size=\"2\" style=\"font-size: 9pt\"><span style=\"text-decoration: none\">";
		outfile << VecWznmVMTablecolBasetype::getTitle(tco->ixVBasetype, VecWznmVLocale::ENUS);
		if (tco->ixVSubtype > 1) outfile << " / " << VecWznmVMTablecolSubtype::getTitle(tco->ixVSubtype, VecWznmVLocale::ENUS);
		outfile << "</span></font>" << endl;

		outfile << "\t\t</td>" << endl;

		outfile << "\t\t<td width=\"65%\" style=\"background: transparent; border: 1px solid #000000; padding-top: 0cm; padding-bottom: 0.1cm; padding-left: 0.1cm; padding-right: 0cm\">" << endl;
		outfile << "\t\t\t<!-- IP " << tblsref << "." << tco->sref << " - BEGIN -->" << endl;

		s = handleWriteHtml_tcotit(dbswznm, tco->ref, refLocEnus);
		if (s != "") outfile << s << "<br>" << endl;

		if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) {
			if (dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl)) {
				auto it = anchorsTbls.find(tbl->ref);

				outfile << "\t\t\treference to <font face=\"FreeMono, monospace\"><span style=\"font-style: normal; font-weight: normal\">";
				if (it != anchorsTbls.end()) outfile << "<a href=\"#" << StrMod::replaceChar(it->second, '.', '_') << "\">";
				outfile << tbl->sref;
				if (it != anchorsTbls.end()) outfile << "</a>";
				outfile << "</span></font><br>" << endl;

				delete tbl;
			};

		} else if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
			if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
				outfile << "\t\t\treference to <font face=\"FreeMono, monospace\"><span style=\"font-style: normal; font-weight: normal\">" << vec->sref << "</span></font><br>" << endl;

				dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

				for (unsigned int j = 0; j < vits.nodes.size(); j++) {
					vit = vits.nodes[j];
					outfile << vit->sref;
					if (vit->Title != "") outfile << ": " << vit->Title;
					outfile << "<br>" << endl;
				};

				delete vec;
			};
		};

		outfile << "\t\t\t<!-- IP " << tblsref << "." << tco->sref << " - END -->" << endl;

		outfile << "\t\t</td>" << endl;

		outfile << "\t</tr>" << endl;
	};

	outfile << foot;
};

void CrdWznmVer::handleWriteIexHtml_struct(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexp* sup
			, const ubigint refWznmMImpexp
			, const std::string& prefix
			, vector<unsigned int>& ics
			, const ubigint refLocEnus
		) {
	vector<ubigint> refs;

	WznmMImpexp* ime = NULL;

	if (dbswznm->tblwznmmimpexp->loadRecByRef(refWznmMImpexp, &ime)) {
		dbswznm->tblwznmmimpexp->loadRefsBySup(refWznmMImpexp, false, refs);

		for (unsigned int i = 2; i < ics.size(); i++) outfile << "&nbsp;&nbsp;&nbsp;&nbsp;";

		if (refs.size() == 0) outfile << "- ";
		else outfile << "+ ";

		outfile << StrMod::cap(handleWriteIexHtml_imetit(dbswznm, ime, refLocEnus));

		outfile << " <font face=\"FreeMono, monospace\"><span style=\"font-style: normal; font-weight: normal\"><a href=\"#" << StrMod::replaceChar(handleWriteIexHtml_anchor(prefix, ics), '.', '_') << "\">[" << ime->sref << "]</a></span></font><br>" << endl;

		ics.push_back(1);
		for (unsigned int i = 0; i < refs.size(); i++) {
			handleWriteIexHtml_struct(dbswznm, outfile, ime, refs[i], prefix, ics, refLocEnus);
			ics[ics.size()-1]++;
		};
		ics.pop_back();

		delete ime;
	};
};

void CrdWznmVer::handleWriteIexHtml_descr(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& iexsref
			, WznmMImpexp* sup
			, const ubigint refWznmMImpexp
			, const string& prefix
			, vector<unsigned int>& ics
			, const ubigint refLocEnus
		) {
	string p_hdr_minor = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\"><u>";
	string p_hdr_minor_close = "</u></p><br>";

	string p_body = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\">";
	string p_body_close = "</p><br>";

	string head = "<table width=\"100%\" cellpadding=\"3\" cellspacing=\"0\">\n";
	head += "\t<col width=\"90*\"/>\n";
	head += "\t<col width=\"166*\"/>\n";
	head += "\t<tr valign=\"top\">\n";
	head += "\t\t<th width=\"35%\" bgcolor=\"#000000\" style=\"background: #000000; border: 1px solid #000000; padding-top: 0.1cm; padding-bottom: 0.1cm; padding-left: 0.1cm; padding-right: 0cm\">\n";
	head += "\t\t\t<font color=\"#ffffff\" face=\"Liberation Serif, serif\" size=\"3\" style=\"font-size: 12pt\"><span style=\"text-decoration: underline\">Column</span></font>\n";
	head += "\t\t</th>\n";
	head += "\t\t<th width=\"65%\" bgcolor=\"#000000\" style=\"background: #000000\" style=\"border: 1px solid #000000; padding: 0.1cm\">\n";
	head += "\t\t\t<font color=\"#ffffff\" face=\"Liberation Serif, serif\" size=\"3\" style=\"font-size: 12pt\"><span style=\"text-decoration: underline\">Content</span></font>\n";
	head += "\t\t</th>\n";
	head += "\t</tr>\n";

	string foot = "</table>\n";
	foot += "<br>\n\n";

	vector<ubigint> refs;

	WznmMImpexp* ime = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	vector<unsigned int> ics2;

	set<uint> icsWIop;

	string s;

	if (dbswznm->tblwznmmimpexp->loadRecByRef(refWznmMImpexp, &ime)) {
		dbswznm->tblwznmmimpexpcol->loadRstByIme(ime->ref, false, iels);

		outfile << "<a name=\"" << StrMod::replaceChar(handleWriteIexHtml_anchor(prefix, ics), '.', '_') << "\">";
		outfile << p_hdr_minor << handleWriteIexHtml_anchor(prefix, ics) << " " << StrMod::cap(handleWriteIexHtml_imetit(dbswznm, ime, refLocEnus)) << " [" << ime->sref << "]" << p_hdr_minor_close;
		outfile << "</a>" << endl << endl;

		outfile << p_body << endl;
		outfile << "\t<!-- IP " << iexsref << "." << ime->sref <<  " - BEGIN -->" << endl;

		if (sup) {
			ics2 = ics;
			ics2.pop_back();

			outfile << "\tSuper import/export: ";

			outfile << " <font face=\"FreeMono, monospace\"><span style=\"font-style: normal; font-weight: normal\"><a href=\"#" << StrMod::replaceChar(handleWriteIexHtml_anchor(prefix, ics2), '.', '_') << "\">" << sup->sref << "</a></span></font><br>" << endl;
		};

		outfile << "\t<!-- IP " << iexsref << "." << ime->sref <<  " - END -->" << endl;
		outfile << p_body_close << endl;

		outfile << head;

		for (unsigned int i = 0; i < iels.nodes.size(); i++) {
			iel = iels.nodes[i];

			if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
				outfile << "\t<tr valign=\"top\">" << endl;

				outfile << "\t\t<td width=\"35%\" style=\"background: transparent; border: 1px solid #000000; padding-top: 0cm; padding-bottom: 0.1cm; padding-left: 0.1cm; padding-right: 0cm\">" << endl;

				outfile << "\t\t\t<font color=\"#000000\" face=\"Liberation Serif, serif\" size=\"3\" style=\"font-size: 12pt\"><span style=\"text-decoration: none; font-style: normal; font-weight: normal\">" << iel->sref << "</span></font><br>" << endl;

				outfile << "\t\t\t<font color=\"#000000\" face=\"Liberation Serif, serif\" size=\"2\" style=\"font-size: 9pt\"><span style=\"text-decoration: none\">";
				outfile << handleWriteIexHtml_ieltype(dbswznm, iel);
				outfile << "</span></font>" << endl;

				outfile << "\t\t</td>" << endl;

				outfile << "\t\t<td width=\"65%\" style=\"background: transparent; border: 1px solid #000000; padding-top: 0cm; padding-bottom: 0.1cm; padding-left: 0.1cm; padding-right: 0cm\">" << endl;
				outfile << "\t\t\t<!-- IP " << iexsref << "." << ime->sref << "." << iel->sref << " - BEGIN -->" << endl;

				if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
					outfile << "import operation<br>" << endl;

					VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);
					for (auto it = icsWIop.begin(); it != icsWIop.end(); it++) outfile << VecWznmWMImpexpIop::getSrefs(*it) << ": " << VecWznmWMImpexpIop::getTitle(*it, VecWznmVLocale::ENUS) << "<br>" << endl;

				} else {
					s = handleWriteHtml_tcotit(dbswznm, iel->refWznmMTablecol, refLocEnus);
					if (s != "") outfile << s << "<br>" << endl;

					if (iel->refWznmMTablecol != 0) {
						dbswznm->tblwznmmvectoritem->loadRstBySQL("SELECT TblWznmMVectoritem.* FROM TblWznmMTablecol, TblWznmMVectoritem WHERE TblWznmMTablecol.ref = " + to_string(iel->refWznmMTablecol)
									+ " AND TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC) + " AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMTablecol.fctUref ORDER BY TblWznmMVectoritem.vecNum ASC", false, vits);

						for (unsigned int j = 0; j < vits.nodes.size(); j++) {
							vit = vits.nodes[j];
							outfile << vit->sref;
							if (vit->Title != "") outfile << ": " << vit->Title;
							outfile << "<br>" << endl;
						};
					};
				};

				outfile << "\t\t\t<!-- IP " << iexsref << "." << ime->sref << "." << iel->sref << " - END -->" << endl;
				outfile << "\t\t</td>" << endl;

				outfile << "\t</tr>" << endl;
			};
		};

		outfile << foot;

		dbswznm->tblwznmmimpexp->loadRefsBySup(refWznmMImpexp, false, refs);
		ics.push_back(1);
		for (unsigned int i = 0; i < refs.size(); i++) {
			handleWriteIexHtml_descr(dbswznm, outfile, iexsref, ime, refs[i], prefix, ics, refLocEnus);
			ics[ics.size()-1]++;
		};
		ics.pop_back();

		delete ime;
	};
};

string CrdWznmVer::handleWriteIexHtml_anchor(
			const string& prefix
			, vector<unsigned int>& ics
		) {
	string retval = prefix;

	for (unsigned int i = 0; i < ics.size(); i++) {
		if (i != 0) retval += ".";
		retval += to_string(ics[i]);
	};

	return retval;
};

string CrdWznmVer::handleWriteIexHtml_imetit(
			DbsWznm* dbswznm
			, WznmMImpexp* ime
			, const ubigint refLocEnus
		) {
	// 1st try: tbl sngfull; 2nd try: tbl plfull; 3rd try: tbl->sref
	string retval = ime->sref;

	if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(ime->refWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval))
		if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(ime->refWznmMTable, VecWznmVAMTableTitleType::PLFULL, refLocEnus, retval))
			dbswznm->tblwznmmtable->loadSrfByRef(ime->refWznmMTable, retval);

	return retval;
};

string CrdWznmVer::handleWriteIexHtml_supreltype(
			DbsWznm* dbswznm
			, WznmMImpexp* sup
			, ListWznmMImpexpcol& iels
			, const ubigint refLocEnus
		) {
	string retval = "1:N";

	WznmMImpexpcol* iel = NULL;
	WznmMRelation* rel = NULL;

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::SUP) {
			if (dbswznm->tblwznmmrelation->loadRecBySQL("SELECT TblWznmMRelation.* FROM TblWznmMRelation, TblWznmMTablecol WHERE TblWznmMRelation.ref = TblWznmMTablecol.refWznmMRelation AND TblWznmMTablecol.ref = "
						+ to_string(iel->refWznmMTablecol), &rel)) {

				if ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) || (rel->ixVBasetype == VecWznmVMRelationBasetype::_1NPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::MNPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::INC)
							|| (rel->ixVBasetype == VecWznmVMRelationBasetype::JPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC)
							|| (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11)) retval = "1:1";

				delete rel;
			};
		};
	};

	return retval;
};

string CrdWznmVer::handleWriteIexHtml_ieltype(
			DbsWznm* dbswznm
			, WznmMImpexpcol* iel
		) {
	// cf. WznmWrsrvIex.writeIexblksH_imeDecl
	string retval;

	WznmMTablecol* tco = NULL;

	if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) retval = "string";
	else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) retval = "ubigint";
	else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
		if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
			if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) retval = "uint";
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) retval = VecWznmVMTablecolSubtype::getSref(tco->ixVSubtype);
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) retval = "double";
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) retval = "bool";
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "double";
				else retval = "uint";
			} else retval = "string"; // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR

			delete tco;
		};

	} else retval = "string"; // VSREF, FTM, TSREF, THSREF, THINT, IARG

	return retval;
};

void CrdWznmVer::handleWriteIexMd_struct(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexp* sup
			, const ubigint refWznmMImpexp
			, vector<unsigned int>& ics
			, const ubigint refLocEnus
		) {
	vector<ubigint> refs;

	WznmMImpexp* ime = NULL;

	if (dbswznm->tblwznmmimpexp->loadRecByRef(refWznmMImpexp, &ime)) {
		dbswznm->tblwznmmimpexp->loadRefsBySup(refWznmMImpexp, false, refs);

		for (unsigned int i = 0; i < ics.size(); i++) outfile << "&nbsp;&nbsp;&nbsp;&nbsp;";

		if (refs.size() == 0) outfile << "\\- ";
		else outfile << "\\+ ";

		outfile << StrMod::cap(handleWriteIexMd_imetit(dbswznm, ime, refLocEnus)) << " [``[" << ime->sref << "]``](#" << ime->sref << ")" << endl;

		ics.push_back(1);
		for (unsigned int i = 0; i < refs.size(); i++) {
			handleWriteIexMd_struct(dbswznm, outfile, ime, refs[i], ics, refLocEnus);
			ics[ics.size()-1]++;
		};
		ics.pop_back();

		delete ime;
	};
};

void CrdWznmVer::handleWriteIexMd_descr(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexp* sup
			, const ubigint refWznmMImpexp
			, vector<unsigned int>& ics
			, const ubigint refLocEnus
		) {
	vector<ubigint> refs;

	WznmMImpexp* ime = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	set<uint> icsWIop;

	if (dbswznm->tblwznmmimpexp->loadRecByRef(refWznmMImpexp, &ime)) {
		dbswznm->tblwznmmimpexpcol->loadRstByIme(ime->ref, false, iels);

		outfile << "<span id=\"" << ime->sref << "\"></span>" << endl;
		outfile << endl;

		outfile << "### ";
		for (unsigned int i = 0; i < ics.size(); i++) {
			if (i != 0) outfile << ".";
			outfile << ics[i];
		};

		outfile << " " << StrMod::cap(handleWriteIexMd_imetit(dbswznm, ime, refLocEnus)) << " ``[" << ime->sref << "]``" << endl;
		outfile << endl;

		outfile << "[//]: # (IP " << ime->sref << ".superUse - BEGIN)" << endl;
		outfile << endl;

		if (sup) {
			outfile << "Super import: " << handleWriteIexMd_imetit(dbswznm, sup, refLocEnus);

			outfile << " (" << handleWriteIexMd_supreltype(dbswznm, sup, iels, refLocEnus) << ")" << endl;

			outfile << endl;
		};

		outfile << "Use:" << endl;
		outfile << endl;

		outfile << "[//]: # (IP " << ime->sref << ".superUse - END)" << endl;
		outfile << endl;

		outfile << "[//]: # (IP " << ime->sref << ".columns - BEGIN)" << endl;
		outfile << endl;

		outfile << "Column|Content|" << endl;
		outfile << "-|-|" << endl;

		for (unsigned int i = 0; i < iels.nodes.size(); i++) {
			iel = iels.nodes[i];

			if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
				outfile << iel->sref << " (" << handleWriteIexMd_ieltype(dbswznm, iel) << ")|";

				if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
					outfile << "import operation";

					VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);
					for (auto it = icsWIop.begin(); it != icsWIop.end(); it++) outfile << "<br>" << VecWznmWMImpexpIop::getSrefs(*it) << ": " << VecWznmWMImpexpIop::getTitle(*it, VecWznmVLocale::ENUS);

				} else {
					outfile << handleWriteIexMd_ieltit(dbswznm, iel, refLocEnus);

					if (iel->refWznmMTablecol != 0) {
						dbswznm->tblwznmmvectoritem->loadRstBySQL("SELECT TblWznmMVectoritem.* FROM TblWznmMTablecol, TblWznmMVectoritem WHERE TblWznmMTablecol.ref = " + to_string(iel->refWznmMTablecol)
									+ " AND TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC) + " AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMTablecol.fctUref ORDER BY TblWznmMVectoritem.vecNum ASC", false, vits);

						for (unsigned int j = 0; j < vits.nodes.size(); j++) {
							vit = vits.nodes[j];
							outfile << "<br>" << vit->sref << ": " << vit->Title;
						};
					};
				};

				outfile << "|" << endl;
			};
		};
		outfile << endl;

		outfile << "[//]: # (IP " << ime->sref << ".columns - END)" << endl;
		outfile << endl;

		dbswznm->tblwznmmimpexp->loadRefsBySup(refWznmMImpexp, false, refs);
		ics.push_back(1);
		for (unsigned int i = 0; i < refs.size(); i++) {
			handleWriteIexMd_descr(dbswznm, outfile, ime, refs[i], ics, refLocEnus);
			ics[ics.size()-1]++;
		};
		ics.pop_back();

		delete ime;
	};
};

string CrdWznmVer::handleWriteIexMd_imetit(
			DbsWznm* dbswznm
			, WznmMImpexp* ime
			, const ubigint refLocEnus
		) {
	// 1st try: tbl sngfull; 2nd try: tbl plfull; 3rd try: tbl->sref
	string retval = ime->sref;

	if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(ime->refWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval))
		if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(ime->refWznmMTable, VecWznmVAMTableTitleType::PLFULL, refLocEnus, retval))
			dbswznm->tblwznmmtable->loadSrfByRef(ime->refWznmMTable, retval);

	return retval;
};

string CrdWznmVer::handleWriteIexMd_supreltype(
			DbsWznm* dbswznm
			, WznmMImpexp* sup
			, ListWznmMImpexpcol& iels
			, const ubigint refLocEnus
		) {
	string retval = "1:N";

	WznmMImpexpcol* iel = NULL;
	WznmMRelation* rel = NULL;

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::SUP) {
			if (dbswznm->tblwznmmrelation->loadRecBySQL("SELECT TblWznmMRelation.* FROM TblWznmMRelation, TblWznmMTablecol WHERE TblWznmMRelation.ref = TblWznmMTablecol.refWznmMRelation AND TblWznmMTablecol.ref = "
						+ to_string(iel->refWznmMTablecol), &rel)) {

				if ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) || (rel->ixVBasetype == VecWznmVMRelationBasetype::_1NPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::MNPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::INC)
							|| (rel->ixVBasetype == VecWznmVMRelationBasetype::JPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBPREF) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC)
							|| (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11)) retval = "1:1";

				delete rel;
			};
		};
	};

	return retval;
};

string CrdWznmVer::handleWriteIexMd_ieltype(
			DbsWznm* dbswznm
			, WznmMImpexpcol* iel
		) {
	// cf. WznmWrsrvIex.writeIexblksH_imeDecl
	string retval;

	WznmMTablecol* tco = NULL;

	if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) retval = "string";
	else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) retval = "ubigint";
	else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
		if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
			if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) retval = "uint";
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) retval = VecWznmVMTablecolSubtype::getSref(tco->ixVSubtype);
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) retval = "double";
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) retval = "bool";
			else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "double";
				else retval = "uint";
			} else retval = "string"; // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR

			delete tco;
		};

	} else retval = "string"; // VSREF, FTM, TSREF, THSREF, THINT, IARG

	return retval;
};

string CrdWznmVer::handleWriteIexMd_ieltit(
			DbsWznm* dbswznm
			, WznmMImpexpcol* iel
			, const ubigint refLocEnus
		) {
	// cf. various WznmGenDetui.genPnldetail_cjt*

	// 1st try: tco full; 2nd try: rel {to/from}full; 3rd try: vec/tbl full/sref; 4th try: tco->sref
	string retval = iel->sref;

	WznmMTablecol* tco = NULL;
	WznmMRelation* rel = NULL;

	bool found;

	bool toNotFr;

	if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
		if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLocEnus, retval)) {
			found = false;

			if (tco->refWznmMRelation != 0) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
					found = true;

					toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

					if (toNotFr) {
						if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOSNGFULL, refLocEnus, retval))
							if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->toRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval)) found = false;

					} else {
						if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLocEnus, retval))
							if (!dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval)) found = false;
					};
				};
			};

			if (!found) {
				if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) {
					found = dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tco->fctUref, VecWznmVAMTableTitleType::SNGFULL, refLocEnus, retval);
					if (!found) found = dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(tco->fctUref, VecWznmVAMTableTitleType::PLFULL, refLocEnus, retval);
					if (!found) found = dbswznm->tblwznmmtable->loadSrfByRef(tco->fctUref, retval);

				} else if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
					found = dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(tco->fctUref, VecWznmVAMVectorTitleType::FULL, refLocEnus, retval);
				};
			};

			if (!found) retval = tco->sref;
		};

		delete tco;
	};

	return retval;
};
// IP cust --- IEND

DpchEngWznm* CrdWznmVer::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWznmVer::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWznmVer/" + VecWznmVLocale::getSref(ixWznmVLocale);
	continf.MtxCrdVer = StubWznm::getStubVerStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref), ixWznmVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswznm);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswznm);
	statshr.MitCrdPcvAvail = evalMitCrdPcvAvail(dbswznm);
	statshr.MitCrdPcvActive = evalMitCrdPcvActive(dbswznm);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbswznm);
	statshr.MitCrdIdpAvail = evalMitCrdIdpAvail(dbswznm);
	statshr.MitCrdIdpActive = evalMitCrdIdpActive(dbswznm);
	statshr.MitCrdIgbAvail = evalMitCrdIgbAvail(dbswznm);
	statshr.MitCrdIgbActive = evalMitCrdIgbActive(dbswznm);
	statshr.MspCrd4Avail = evalMspCrd4Avail(dbswznm);
	statshr.MitCrdImdAvail = evalMitCrdImdAvail(dbswznm);
	statshr.MitCrdImdActive = evalMitCrdImdActive(dbswznm);
	statshr.MspCrd5Avail = evalMspCrd5Avail(dbswznm);
	statshr.MitCrdIdbAvail = evalMitCrdIdbAvail(dbswznm);
	statshr.MitCrdIdbActive = evalMitCrdIdbActive(dbswznm);
	statshr.MitCrdIbuAvail = evalMitCrdIbuAvail(dbswznm);
	statshr.MitCrdIbuActive = evalMitCrdIbuActive(dbswznm);
	statshr.MitCrdIieAvail = evalMitCrdIieAvail(dbswznm);
	statshr.MitCrdIieActive = evalMitCrdIieActive(dbswznm);
	statshr.MitCrdIopAvail = evalMitCrdIopAvail(dbswznm);
	statshr.MitCrdIopActive = evalMitCrdIopActive(dbswznm);
	statshr.MitCrdIcjAvail = evalMitCrdIcjAvail(dbswznm);
	statshr.MitCrdIcjActive = evalMitCrdIcjActive(dbswznm);
	statshr.MspCrd6Avail = evalMspCrd6Avail(dbswznm);
	statshr.MitCrdGuiAvail = evalMitCrdGuiAvail(dbswznm);
	statshr.MitCrdGuiActive = evalMitCrdGuiActive(dbswznm);
	statshr.MitCrdAuiAvail = evalMitCrdAuiAvail(dbswznm);
	statshr.MitCrdAuiActive = evalMitCrdAuiActive(dbswznm);
	statshr.MitCrdGjtAvail = evalMitCrdGjtAvail(dbswznm);
	statshr.MitCrdGjtActive = evalMitCrdGjtActive(dbswznm);
	statshr.MitCrdAjtAvail = evalMitCrdAjtAvail(dbswznm);
	statshr.MitCrdAjtActive = evalMitCrdAjtActive(dbswznm);
	statshr.MspCrd7Avail = evalMspCrd7Avail(dbswznm);
	statshr.MitCrdFnmAvail = evalMitCrdFnmAvail(dbswznm);
	statshr.MitCrdFnmActive = evalMitCrdFnmActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWznmVer::changeRef(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWznmVPreset = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXPRE, jref);

	uint ixWznmVRecaccess;
	xchg->triggerIxRefToIxCall(dbswznm, VecWznmVCall::CALLWZNMRECACCESS, jref, VecWznmVCard::CRDWZNMVER, ref, ixWznmVRecaccess);

	if (ixWznmVRecaccess != VecWznmVRecaccess::NONE) {
		xchg->addIxPreset(VecWznmVPreset::PREWZNMIXRECACC, jref, ixWznmVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswznm, VecWznmVCall::CALLWZNMLOG, jref, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref), "CrdWznmVer", ref);
		xchg->addRefPreset(VecWznmVPreset::PREWZNMREFVER, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVER, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFVER, jrefTrig, notif);

		refresh(dbswznm, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWznmVer::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWznmVer::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tselectLocales" << endl;
			cout << "\tshowJobtree" << endl;
			cout << "\tshowMethods" << endl;
			cout << "\tshowVars" << endl;
			cout << "\twriteDbsHtml" << endl;
			cout << "\twriteIexHtml" << endl;
			cout << "\twriteIexMd" << endl;
		} else if (req->cmd == "selectLocales") {
			req->retain = handleSelectLocales(dbswznm);

		} else if (req->cmd == "showJobtree") {
			req->retain = handleShowJobtree(dbswznm);

		} else if (req->cmd == "showMethods") {
			req->retain = handleShowMethods(dbswznm);

		} else if (req->cmd == "showVars") {
			req->retain = handleShowVars(dbswznm);

		} else if (req->cmd == "writeDbsHtml") {
			req->retain = handleWriteDbsHtml(dbswznm);

		} else if (req->cmd == "writeIexHtml") {
			req->retain = handleWriteIexHtml(dbswznm);

		} else if (req->cmd == "writeIexMd") {
			req->retain = handleWriteIexMd(dbswznm);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMINIT) {
			handleDpchAppWznmInit(dbswznm, (DpchAppWznmInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPCVCLICK) {
					handleDpchAppDoMitCrdPcvClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIDPCLICK) {
					handleDpchAppDoMitCrdIdpClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIGBCLICK) {
					handleDpchAppDoMitCrdIgbClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIMDCLICK) {
					handleDpchAppDoMitCrdImdClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIDBCLICK) {
					handleDpchAppDoMitCrdIdbClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIBUCLICK) {
					handleDpchAppDoMitCrdIbuClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIIECLICK) {
					handleDpchAppDoMitCrdIieClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIOPCLICK) {
					handleDpchAppDoMitCrdIopClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDICJCLICK) {
					handleDpchAppDoMitCrdIcjClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDGUICLICK) {
					handleDpchAppDoMitCrdGuiClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDAUICLICK) {
					handleDpchAppDoMitCrdAuiClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDGJTCLICK) {
					handleDpchAppDoMitCrdGjtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDAJTCLICK) {
					handleDpchAppDoMitCrdAjtClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFNMCLICK) {
					handleDpchAppDoMitCrdFnmClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool CrdWznmVer::handleSelectLocales(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleSelectLocales --- IBEGIN
	vector<bool> sels;
	unsigned int selcnt;
	unsigned int pri;

	string input;
	ubigint iinput;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	ListWznmMLocale lcls;
	WznmMLocale* lcl = NULL;

	ListWznmRMLocaleMVersion lrvs;
	WznmRMLocaleMVersion* lrv = NULL;

	// requires version presetting
	if (refWznmMVersion == 0) {
		cout << "\tno version preset!" << endl;

	} else {
		// reset locale selection
		dbswznm->executeQuery("DELETE FROM TblWznmRMLocaleMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion));
		dbswznm->executeQuery("UPDATE TblWznmMVersion SET refRLocale = 0, refWznmMLocale = 0 WHERE ref = " + to_string(refWznmMVersion));

		// load all locales
		dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale ORDER BY sref ASC", false, lcls);

		sels.resize(lcls.nodes.size(), false);
		selcnt = 0;
		pri = lcls.nodes.size();

		// ask user to select at least one locale
		cout << "\ttoggle locales by using their respective references. Type 'done' when finished." << endl;

		while (true) {
			cout << "\t\tlist of locales:" << endl;

			for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
				lcl = lcls.nodes[i];

				cout << "\t\t\t";
				if (sels[i]) cout << "x\t"; else cout << "o\t";
				cout << lcl->ref << "\t" << lcl->sref << "\t" << lcl->Title << endl;
			};

			cout << "\t\tyour input: ";
			cin >> input;

			if (input.compare("done") == 0) {
				break;

			} else {
				iinput = atoll(input.c_str());

				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					lcl = lcls.nodes[i];

					if (lcl->ref == iinput) {
						sels[i] = !sels[i];
						if (sels[i]) selcnt++; else selcnt--;
						
						break;
					};
				};
			};			
		};

		// further processing requires at least one locale selected
		if (selcnt == 0) {
			cout << "\tno locale selected!" << endl;

		} else {
			// ask user to select one primary locale
			cout << "\tchoose one locale as primary by typing its respective reference." << endl;

			cout << "\t\tlist of selected locales:" << endl;

			for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
				lcl = lcls.nodes[i];

				if (sels[i]) {
					cout << "\t\t\t";
					cout << lcl->ref << "\t" << lcl->sref << "\t" << lcl->Title << endl;
				};
			};

			while (true) {
				cout << "\t\tyour choice: ";
				cin >> input;

				iinput = atoll(input.c_str());

				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					lcl = lcls.nodes[i];

					if ((lcl->ref == iinput) && sels[i]) {
						pri = i;
						break;
					};
				};

				if (pri < lcls.nodes.size()) {
					break;
				} else {
					cout << "\t\tinvalid input!" << endl;
				};
			};

			// modify database accordingly
			for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
				lcl = lcls.nodes[i];

				if (sels[i]) {
					lrv = new WznmRMLocaleMVersion(0, lcl->ref, refWznmMVersion);
					dbswznm->tblwznmrmlocalemversion->insertRec(lrv); lrvs.nodes.push_back(lrv);

					if (i == pri) {
						dbswznm->executeQuery("UPDATE TblWznmMVersion SET refRLocale = " + to_string(lrv->ref) + ", refWznmMLocale = " + to_string(lcl->ref) + " WHERE ref = " + to_string(refWznmMVersion));
					};
				};
			};
		};
	};

	return false;
	// IP handleSelectLocales --- IEND
	return retval;
};

bool CrdWznmVer::handleShowJobtree(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleShowJobtree --- IBEGIN
	ubigint ref;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::ROOT), ref)) handleShowJobtree_subjobs(dbswznm, ref, 0);
	// IP handleShowJobtree --- IEND
	return retval;
};

bool CrdWznmVer::handleShowMethods(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleShowMethods --- IBEGIN
	ubigint ref;

	ListWznmMMethod mtds;
	WznmMMethod* mtd = NULL;

	ListWznmAMMethodInvpar ipas;
	WznmAMMethodInvpar* ipa = NULL;

	ListWznmAMMethodRetpar rpas;
	WznmAMMethodRetpar* rpa = NULL;

	string s;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	dbswznm->tblwznmmmethod->loadRstBySQL("SELECT TblWznmMMethod.* FROM TblWznmMJob, TblWznmMMethod WHERE TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmMMethod.refWznmMJob = TblWznmMJob.ref ORDER BY TblWznmMJob.sref ASC, TblWznmMMethod.sref ASC", false, mtds);

	ref = 0;

	for (unsigned int i = 0; i < mtds.nodes.size(); i++) {
		mtd = mtds.nodes[i];

		if (mtd->refWznmMJob != ref) {
			if (dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMJob WHERE ref = " + to_string(mtd->refWznmMJob), s)) cout << s << ":" << endl;
			ref = mtd->refWznmMJob;
		};

		dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
		dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);
	
		cout << "\t(";
		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];

			if (j != 0) cout << ", ";
			cout << VecWznmVVartype::getSref(rpa->ixWznmVVartype) << " " << rpa->sref;
		};
		cout << ") = " << mtd->sref << "(";
		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];

			if (j != 0) cout << ", ";
			cout << VecWznmVVartype::getSref(ipa->ixWznmVVartype) << " " << ipa->sref;
		};
		cout << ")" << endl;
	};

	// IP handleShowMethods --- IEND
	return retval;
};

bool CrdWznmVer::handleShowVars(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleShowVars --- IBEGIN
	ubigint ref, refC;

	ListWznmAMJobVar vars;
	WznmAMJobVar* var = NULL;

	string s;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	dbswznm->tblwznmamjobvar->loadRstBySQL("SELECT TblWznmAMJobVar.* FROM TblWznmMJob, TblWznmAMJobVar WHERE TblWznmMJob.refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmAMJobVar.jobRefWznmMJob = TblWznmMJob.ref ORDER BY TblWznmMJob.sref ASC, TblWznmAMJobVar.jobNum ASC", false, vars);

	ref = 0;
	refC = 0;

	for (unsigned int i = 0; i < vars.nodes.size(); i++) {
		var = vars.nodes[i];

		if (var->jobRefWznmMJob != ref) {
			if (refC != 0) cout << "}" << endl;

			if (dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMJob WHERE ref = " + to_string(var->jobRefWznmMJob), s)) cout << s << ":" << endl;
			ref = var->jobRefWznmMJob;
			refC = 0;

		} else {
			if ((refC != 0) && (var->refWznmCAMJobVar != refC)) cout << "}" << endl;
		};

		if (var->refWznmCAMJobVar == 0) cout << "\t" << VecWznmVVartype::getSref(var->ixWznmVVartype) << " " << var->sref << endl;
		else {
			if (var->refWznmCAMJobVar == refC) cout << ", " << VecWznmVVartype::getSref(var->ixWznmVVartype) << " " << var->sref;
			else cout << "\t{" << VecWznmVVartype::getSref(var->ixWznmVVartype) << " " << var->sref;
		};

		refC = var->refWznmCAMJobVar;
	};
	if (refC != 0) cout << "}" << endl;

	// IP handleShowVars --- IEND
	return retval;
};

bool CrdWznmVer::handleWriteDbsHtml(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleWriteDbsHtml --- IBEGIN
	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	time_t rawtime;
	time(&rawtime);

	string head = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n";
	head += "<html>\n";
	head += "\t<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">\n";
	head += "\t<title>" + StubWznm::getStubVerStd(dbswznm, refWznmMVersion) + " database structure as of " + StrMod::timetToString(rawtime) + "</title>\n";
	head += "\t<head>\n";
	head += "\t\t<style type=\"text/css\">\n";
	head += "\t\t\t@page { margin: 2cm }\n";
	head += "\t\t\tp { margin-bottom: 0.25cm; line-height: 115% }\n";
	head += "\t\t\ttd p { margin-bottom: 0cm }\n";
	head += "\t\t\tth p { margin-bottom: 0cm }\n";
	head += "\t\t</style>\n";
	head += "\t</head>\n";
	head += "\t<body lang=\"en-US\" dir=\"ltr\">\n";

	string foot = "\t</body>\n";
	foot += "</html>\n";

	string p_hdr_major = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\"><b>";
	string p_hdr_major_close = "</b></p><br>";

	string p_hdr_minor = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\"><u>";
	string p_hdr_minor_close = "</u></p><br>";

	string p_body = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\">";
	string p_body_close = "</p><br>";

	ifstream infile;
	char* buf = new char[1024];

	fstream outfile;

	string prefix;

	vector<ubigint> refs;

	ListWznmMTable tbls; // all tables, including sub-tables
	WznmMTable* tbl = NULL;

	map<ubigint, uint> icsTbls; // by ref
	map<ubigint, string> anchorsTbls;

	WznmMTable* mtb = NULL;
	map<string, uint> icsMtbs; // by sref

	WznmMTable* rtb = NULL;
	map<string, uint> icsRtbs; // by sref

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;	

	// chapter number / anchor: <prefix.><major>.<minor 1 for mtb, 2 for rtb>.<sub for each mtb/rtb>.<subsub for each subtbl>
	// ex. 7.1 User interface
	// ex. 7.1.2 Relation tables
	// ex. 7.1.1.1 Cards [TblWznmMCard]
	// ex. 7.1.1.1. Name by locale [TblWznmJMCardTitle]

	ubigint refLocEnus;

	unsigned int major, minor, sub, subsub;

	string s;

	string prjshort;
	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), prjshort);

	dbswznm->tblwznmmlocale->loadRefBySrf("enus", refLocEnus);

	// load and categorize version's tables
	dbswznm->tblwznmmtable->loadRstByVer(refWznmMVersion, false, tbls);

	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		icsTbls[tbl->ref] = i;

		if (tbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) icsMtbs[tbl->sref] = i;
		else if (tbl->ixVBasetype == VecWznmVMTableBasetype::REL) icsRtbs[tbl->sref] = i;
	};

	// query parameters via command line
	cout << "\tchapter prefix: ";
	cin >> prefix;

	cout << "\tstructure file path: ";
	cin >> s;

	infile.open(s.c_str(), ifstream::in);
	if (!infile.is_open()) {
		cout << "\terror opening structure file." << endl;
		return retval;
	};

	s = xchg->exedir + "/database_" + prjshort + ".html";
	outfile.open(s.c_str(), ios::out);

	outfile << head;

	for (unsigned int i = 0; i < 2; i++) { // 0: prepare structure, define anchors; 1: write HTML
		infile.clear();
		infile.seekg(0);

		major = 0;
		minor = 0;

		while (infile.good() && !infile.eof()) {
			s = StrMod::readLine(infile, buf, 1024);
			if (s == "") continue;

			mtb = NULL;
			rtb = NULL;

			auto it = icsMtbs.find(s);
			if (it != icsMtbs.end()) {
				// new main table
				mtb = tbls[it->second];

				if (minor == 0) {
					minor = 1;
					sub = 1;

					if (i == 1) {
						outfile << p_hdr_minor << prefix << major << "." << minor << " Main tables" << p_hdr_minor_close << endl;
						outfile << endl;
					};

				} else if (minor == 1) sub++;
				else continue;

			} else {
				it = icsRtbs.find(s);
				if (it != icsRtbs.end()) {
					// new relation table
					rtb = tbls[it->second];

					if (minor == 1) {
						minor = 2;
						sub = 1;

						if (i == 1) {
							outfile << p_hdr_minor << prefix << major << "." << minor << " Relation tables" << p_hdr_minor_close << endl;
							outfile << endl;
						};

					} else if (minor == 2) sub++;
					else continue;

				} else {
					// new group
					major++;

					if (i == 1) {
						outfile << p_hdr_major << prefix << major << " " << s << p_hdr_major_close << endl;
						outfile << endl;

						outfile << p_body << endl;
						outfile << "\t<!-- IP " << StrMod::replaceChar(StrMod::replaceChar(s, ' ', '_'), '.', '_') << " - BEGIN -->" << endl;
						outfile << "\t" << s << " description." << endl;
						outfile << "\t<!-- IP " << StrMod::replaceChar(StrMod::replaceChar(s, ' ', '_'), '.', '_') << " - END -->" << endl;
						outfile << p_body_close << endl;
					};

					minor = 0;
				};
			};

			if (mtb != NULL) {
				if (i == 0) {
					anchorsTbls[mtb->ref] = prefix + to_string(major) + "." + to_string(minor) + "." + to_string(sub);

				} else if (i == 1) {
					outfile << "<a name=\"" << StrMod::replaceChar(anchorsTbls[mtb->ref], '.', '_') << "\">";
					outfile << p_hdr_minor << anchorsTbls[mtb->ref] << " " << handleWriteDbsHtml_tbltit(dbswznm, mtb, refLocEnus) << " [" << mtb->sref << "]" << p_hdr_minor_close;
					outfile << "</a>" << endl << endl;

					outfile << p_body << endl;
					outfile << "\t<!-- IP " << mtb->sref << " - BEGIN -->" << endl;
					outfile << "\t" << mtb->sref << " description." << endl;
					outfile << "\t<!-- IP " << mtb->sref << " - END -->" << endl;
					outfile << p_body_close << endl;
				};

				// sub-tbls (clust, jump, aux)
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(mtb->ref) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::CLUST), false, refs);
				dbswznm->loadRefsBySQL("SELECT TblWznmMTable.ref FROM TblWznmMRelation, TblWznmMTable WHERE TblWznmMRelation.frRefWznmMTable = " + to_string(mtb->ref) + " AND TblWznmMRelation.ixVBasetype = "
							+ to_string(VecWznmVMRelationBasetype::J) + " AND TblWznmMTable.ref = TblWznmMRelation.toRefWznmMTable ORDER BY TblWznmMTable.sref ASC", true, refs);
				dbswznm->loadRefsBySQL("SELECT TblWznmMTable.ref FROM TblWznmMRelation, TblWznmMTable WHERE TblWznmMRelation.frRefWznmMTable = " + to_string(mtb->ref) + " AND TblWznmMRelation.ixVBasetype = "
							+ to_string(VecWznmVMRelationBasetype::AUX) + " AND TblWznmMTable.ref = TblWznmMRelation.toRefWznmMTable ORDER BY TblWznmMTable.sref ASC", true, refs);

				if (i == 1) {
					// tcos
					dbswznm->tblwznmmtablecol->loadRstByTbl(mtb->ref, false, tcos);
					handleWriteDbsHtml_tcos(dbswznm, outfile, mtb->sref, tcos, anchorsTbls, refLocEnus);
				};

				// sub-tbls
				subsub = 0;
				for (unsigned int j = 0; j < refs.size(); j++) {
					auto it = icsTbls.find(refs[j]);

					if (it != icsTbls.end()) {
						tbl = tbls.nodes[it->second];
						subsub++;

						if (i == 0) {
							anchorsTbls[tbl->ref] = prefix + to_string(major) + "." + to_string(minor) + "." + to_string(sub) + "." + to_string(subsub);

						} else if (i == 1) {
							outfile << "<a name=\"" << StrMod::replaceChar(anchorsTbls[tbl->ref], '.', '_') << "\">";
							outfile << p_hdr_minor << anchorsTbls[tbl->ref] << " " << handleWriteDbsHtml_tbltit(dbswznm, tbl, refLocEnus) << " [" << tbl->sref << "]" << p_hdr_minor_close;
							outfile << "</a>" << endl << endl;

							outfile << p_body << endl;
							outfile << "\t<!-- IP " << tbl->sref << " - BEGIN -->" << endl;
							outfile << "\t" << tbl->sref << " description." << endl;
							outfile << "\t<!-- IP " << tbl->sref << " - END -->" << endl;
							outfile << p_body_close << endl;

							// sub-tbl tcos
							dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);
							handleWriteDbsHtml_tcos(dbswznm, outfile, tbl->sref, tcos, anchorsTbls, refLocEnus);
						};
					};
				};

			} else if (rtb != NULL) {
				if (i == 0) {
					anchorsTbls[rtb->ref] = prefix + to_string(major) + "." + to_string(minor) + "." + to_string(sub);

				} else if (i == 1) {
					outfile << "<a name=\"" << StrMod::replaceChar(anchorsTbls[rtb->ref], '.', '_') << "\">";
					outfile << p_hdr_minor << anchorsTbls[rtb->ref] << " " << handleWriteDbsHtml_tbltit(dbswznm, rtb, refLocEnus) << " [" << rtb->sref << "]" << p_hdr_minor_close;
					outfile << "</a>" << endl << endl;

					outfile << p_body << endl;
					outfile << "\t<!-- IP " << rtb->sref << " - BEGIN -->" << endl;
					outfile << "\t" << rtb->sref << " description." << endl;
					outfile << "\t<!-- IP " << rtb->sref << " - END -->" << endl;
					outfile << p_body_close << endl;
				};

				if (i == 1) {
					// tcos
					dbswznm->tblwznmmtablecol->loadRstByTbl(rtb->ref, false, tcos);
					handleWriteDbsHtml_tcos(dbswznm, outfile, rtb->sref, tcos, anchorsTbls, refLocEnus);
				};
			};
		};
	};

	infile.close();

	outfile << foot;
	outfile.close();

	delete[] buf;
	// IP handleWriteDbsHtml --- IEND
	return retval;
};

bool CrdWznmVer::handleWriteIexHtml(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleWriteIexHtml --- IBEGIN
	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	time_t rawtime;
	time(&rawtime);

	string head = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n";
	head += "<html>\n";
	head += "\t<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">\n";
	head += "\t<title>" + StubWznm::getStubVerStd(dbswznm, refWznmMVersion) + " import/export structure as of " + StrMod::timetToString(rawtime) + "</title>\n";
	head += "\t<head>\n";
	head += "\t\t<style type=\"text/css\">\n";
	head += "\t\t\t@page { margin: 2cm }\n";
	head += "\t\t\tp { margin-bottom: 0.25cm; line-height: 115% }\n";
	head += "\t\t\ttd p { margin-bottom: 0cm }\n";
	head += "\t\t\tth p { margin-bottom: 0cm }\n";
	head += "\t\t</style>\n";
	head += "\t</head>\n";
	head += "\t<body lang=\"en-US\" dir=\"ltr\">\n";

	string foot = "\t</body>\n";
	foot += "</html>\n";

	string p_hdr_major = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\"><b>";
	string p_hdr_major_close = "</b></p><br>";

	string p_body = "<p style=\"margin-bottom: 0cm; font-style: normal; font-weight: normal; line-height: 100%\">";
	string p_body_close = "</p><br>";

	fstream outfile;

	string prefix;

	vector<ubigint> refs;

	ListWznmMImpexpcplx iexs;
	WznmMImpexpcplx* iex = NULL;

	// chapter number / anchor: <prefix.><major>.<minor 1 for mtb, 2 for rtb>.<sub for each mtb/rtb>.<subsub for each subtbl>
	// ex. 7.1 Updates to dialogs, panels, controls and queries [IexWznmUix]
	// ex. 7.1.1 Card [ImeIMCard]
	// ex. 7.1.1.2 Panel [ImeIMPanel]
	// ex. 7.1.1.2.2 Control [ImeIMControl2]
	// ex. 7.1.1.2.2.3 Feed [ImeIMFeed2]
	// ex. 7.1.1.2.2.3.1 Vector [ImeIMVector2]

	ubigint refLocEnus;

	vector<unsigned int> ics;

	string s;

	string prjshort;
	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), prjshort);

	dbswznm->tblwznmmlocale->loadRefBySrf("enus", refLocEnus);

	dbswznm->tblwznmmimpexpcplx->loadRstByVer(refWznmMVersion, false, iexs);

	// query parameters via command line
	cout << "\tchapter prefix: ";
	cin >> prefix;

	s = xchg->exedir + "/impexp_" + prjshort + ".html";
	outfile.open(s.c_str(), ios::out);

	outfile << head;

	ics.resize(1);

	for (unsigned int i = 0; i < iexs.nodes.size(); i++) {
		iex = iexs.nodes[i];
		ics[0] = i + 1;

		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " AND supLvl = 0 ORDER BY sref ASC", false, refs);

		// --- header
		outfile << p_hdr_major << prefix << ics[0] << " " << StrMod::cap(iex->Title) << " [" << iex->sref << "]" << p_hdr_major_close << endl;
		outfile << endl;

		// - description and schema
		outfile << p_body << endl;
		outfile << "\t<!-- IP " << iex->sref << " - BEGIN -->" << endl;
		outfile << "\t" << StrMod::cap(iex->Title) << " description and schema." << endl;
		outfile << "\t<!-- IP " << iex->sref << " - END -->" << endl;
		outfile << p_body_close << endl;

		// - structure
		outfile << p_body << endl;
		outfile << "\t<!-- IP " << iex->sref << ".struct - BEGIN -->" << endl;

		ics.resize(2);
		ics[1] = 1;
		for (unsigned int j = 0; j < refs.size(); j++) {
			handleWriteIexHtml_struct(dbswznm, outfile, NULL, refs[j], prefix, ics, refLocEnus);
			ics[1]++;
		};

		outfile << "\t<!-- IP " << iex->sref << ".struct - END -->" << endl;
		outfile << p_body_close << endl;

		// --- detailed description
		ics.resize(2);
		ics[1] = 1;
		for (unsigned int j = 0; j < refs.size(); j++) {
			handleWriteIexHtml_descr(dbswznm, outfile, iex->sref, NULL, refs[j], prefix, ics, refLocEnus);
			ics[1]++;
		};
	};

	outfile << foot;

	outfile.close();
	// IP handleWriteIexHtml --- IEND
	return retval;
};

bool CrdWznmVer::handleWriteIexMd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleWriteIexMd --- IBEGIN

	vector<ubigint> refs;

	ListWznmMImpexpcplx iexs;
	WznmMImpexpcplx* iex = NULL;

	fstream outfile;

	vector<unsigned int> ics;

	time_t rawtime;
	string created;

	ubigint refLocEnus;

	string s;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	time(&rawtime);
	created = StrMod::timetToString(rawtime);

	dbswznm->tblwznmmlocale->loadRefBySrf("enus", refLocEnus);

	dbswznm->tblwznmmimpexpcplx->loadRstByVer(refWznmMVersion, false, iexs);
	for (unsigned int i = 0; i < iexs.nodes.size(); i++) {
		iex = iexs.nodes[i];

		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " AND supLvl = 0 ORDER BY sref ASC", false, refs);

		s = xchg->exedir + "/" + iex->sref + ".md";

		outfile.open(s.c_str(), ios::out);

		// --- header
		outfile << StrMod::cap(iex->Title) << " ``" << iex->sref << "``" << endl;
		outfile << "===" << endl;
		outfile << endl;

		outfile << "Schema" << endl;
		outfile << "---" << endl;
		outfile << endl;

		outfile << "![Figure 1: " << StrMod::cap(iex->Title) << " schema - table columns in light blue are part of the input file, table columns in dark blue are inferred](./" << iex->sref << ".png)" << endl;
		outfile << endl;

		// --- overview
		outfile << "Structure" << endl;
		outfile << "---" << endl;
		outfile << endl;

		outfile << "[//]: # (IP structure - BEGIN)" << endl;
		outfile << endl;

		ics.resize(1);
		ics[0] = 1;
		for (unsigned int j = 0; j < refs.size(); j++) {
			handleWriteIexMd_struct(dbswznm, outfile, NULL, refs[j], ics, refLocEnus);
			ics[0]++;
		};
		outfile << endl;

		outfile << "[//]: # (IP structure - END)" << endl;
		outfile << endl;

		// --- detailed description
		outfile << "Details" << endl;
		outfile << "---" << endl;
		outfile << endl;

		ics.resize(1);
		ics[0] = 1;
		for (unsigned int j = 0; j < refs.size(); j++) {
			handleWriteIexMd_descr(dbswznm, outfile, NULL, refs[j], ics, refLocEnus);
			ics[0]++;
		};

		// --- footer
		outfile << "<small>Markdown for " << StubWznm::getStubVerStd(dbswznm, refWznmMVersion) << " auto-generated (what else ;-) ) by WhizniumSBE on " << created << "</small>" << endl;

		outfile.close();
	};

	// IP handleWriteIexMd --- IEND
	return retval;
};

void CrdWznmVer::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWznmVer::handleDpchAppDoClose(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerIxCall(dbswznm, VecWznmVCall::CALLWZNMCRDCLOSE, jref, VecWznmVCard::CRDWZNMVER);
};

void CrdWznmVer::handleDpchAppDoMitAppAbtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswznm, VecVSge::ALRWZNMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWznmVer::handleDpchAppDoMitCrdNewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWznmVerNew(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdPcvClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoMitCrdPcvClick --- IBEGIN
	changeStage(dbswznm, VecVSge::ALRCVW, dpcheng);
	// IP handleDpchAppDoMitCrdPcvClick --- IEND
};

void CrdWznmVer::handleDpchAppDoMitCrdIdpClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgdeploy) {
		dlgdeploy = new DlgWznmVerDeploy(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgdeploy = dlgdeploy->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdIgbClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgglobal) {
		dlgglobal = new DlgWznmVerGlobal(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgglobal = dlgglobal->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdImdClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgwrinimdl) {
		dlgwrinimdl = new DlgWznmVerWrinimdl(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgwrinimdl = dlgwrinimdl->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdIdbClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgdbstr) {
		dlgdbstr = new DlgWznmVerDbstr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgdbstr = dlgdbstr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdIbuClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgbscui) {
		dlgbscui = new DlgWznmVerBscui(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgbscui = dlgbscui->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdIieClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgimpexp) {
		dlgimpexp = new DlgWznmVerImpexp(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgimpexp = dlgimpexp->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdIopClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgoppack) {
		dlgoppack = new DlgWznmVerOppack(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgoppack = dlgoppack->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdIcjClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgcustjob) {
		dlgcustjob = new DlgWznmVerCustjob(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgcustjob = dlgcustjob->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdGuiClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlggenui) {
		dlggenui = new DlgWznmVerGenui(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlggenui = dlggenui->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdAuiClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgcustui) {
		dlgcustui = new DlgWznmVerCustui(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgcustui = dlgcustui->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdGjtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlggenjtr) {
		dlggenjtr = new DlgWznmVerGenjtr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlggenjtr = dlggenjtr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdAjtClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgcustjtr) {
		dlgcustjtr = new DlgWznmVerCustjtr(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgcustjtr = dlgcustjtr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppDoMitCrdFnmClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	if (!dlgfinmod) {
		dlgfinmod = new DlgWznmVerFinmod(xchg, dbswznm, jref, ixWznmVLocale);
		statshr.jrefDlgfinmod = dlgfinmod->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWznmVer::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- RBEGIN
	if (ixVSge == VecVSge::ALRWZNMABT) {
		changeStage(dbswznm, VecVSge::IDLE);
	} else if (ixVSge == VecVSge::ALRCVW) {
		if (feedFMcbAlert.getSrefByNum(dpchappwznmalert->numFMcb) == "yes") {
			changeStage(dbswznm, VecVSge::SETPRJCVR);
		} else {
			changeStage(dbswznm, VecVSge::IDLE);
		};
	};

	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	// IP handleDpchAppWznmAlert --- REND
};

void CrdWznmVer::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTATCHG) {
		call->abort = handleCallWznmStatChg(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLGCLOSE) {
		call->abort = handleCallWznmDlgClose(dbswznm, call->jref);
	};
};

bool CrdWznmVer::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWznmVPreset::PREWZNMREFVER) {
		changeRef(dbswznm, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswznm, true);
		else if ((jrefTrig == statshr.jrefDlgnew) && (refInv != 0)) {
			pnllist->qry->rerun(dbswznm, true);
			pnllist->minimize(dbswznm, true);
			pnlrec->regularize(dbswznm, true);
		};
	};

	return retval;
};

bool CrdWznmVer::handleCallWznmStatChg(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD) && (pnlrec->statshr.ixWznmVExpstate == VecWznmVExpstate::REGD)) pnllist->minimize(dbswznm, true);
	return retval;
};

bool CrdWznmVer::handleCallWznmDlgClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgbscui) {
		delete dlgbscui;
		dlgbscui = NULL;
		statshr.jrefDlgbscui = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgcustjob) {
		delete dlgcustjob;
		dlgcustjob = NULL;
		statshr.jrefDlgcustjob = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgcustjtr) {
		delete dlgcustjtr;
		dlgcustjtr = NULL;
		statshr.jrefDlgcustjtr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgcustui) {
		delete dlgcustui;
		dlgcustui = NULL;
		statshr.jrefDlgcustui = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgdbstr) {
		delete dlgdbstr;
		dlgdbstr = NULL;
		statshr.jrefDlgdbstr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgdeploy) {
		delete dlgdeploy;
		dlgdeploy = NULL;
		statshr.jrefDlgdeploy = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgfinmod) {
		delete dlgfinmod;
		dlgfinmod = NULL;
		statshr.jrefDlgfinmod = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlggenjtr) {
		delete dlggenjtr;
		dlggenjtr = NULL;
		statshr.jrefDlggenjtr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlggenui) {
		delete dlggenui;
		dlggenui = NULL;
		statshr.jrefDlggenui = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgglobal) {
		delete dlgglobal;
		dlgglobal = NULL;
		statshr.jrefDlgglobal = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgimpexp) {
		delete dlgimpexp;
		dlgimpexp = NULL;
		statshr.jrefDlgimpexp = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgoppack) {
		delete dlgoppack;
		dlgoppack = NULL;
		statshr.jrefDlgoppack = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgwrinimdl) {
		delete dlgwrinimdl;
		dlgwrinimdl = NULL;
		statshr.jrefDlgwrinimdl = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWznmVer::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRWZNMABT: leaveSgeAlrwznmabt(dbswznm); break;
				case VecVSge::ALRCVW: leaveSgeAlrcvw(dbswznm); break;
				case VecVSge::SETPRJCVR: leaveSgeSetprjcvr(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRWZNMABT: _ixVSge = enterSgeAlrwznmabt(dbswznm, reenter); break;
			case VecVSge::ALRCVW: _ixVSge = enterSgeAlrcvw(dbswznm, reenter); break;
			case VecVSge::SETPRJCVR: _ixVSge = enterSgeSetprjcvr(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWznmVer::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWznmVer::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWznmVer::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWznmVer::enterSgeAlrwznmabt(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZNMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWznm::prepareAlrAbt(jref, ixWznmVLocale, feedFMcbAlert)); // IP enterSgeAlrwznmabt --- LINE

	return retval;
};

void CrdWznmVer::leaveSgeAlrwznmabt(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrwznmabt --- INSERT
};

uint CrdWznmVer::enterSgeAlrcvw(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRCVW;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrcvw --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::WARNING, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Manual repository adjustments may be required.";
		continf.TxtMsg2 = "Proceed anyway?";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::YES, ixWznmVLocale, feedFMcbAlert);
	VecWznmVTag::appendToFeed(VecWznmVTag::NO, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrcvw --- END
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void CrdWznmVer::leaveSgeAlrcvw(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrcvw --- INSERT
};

uint CrdWznmVer::enterSgeSetprjcvr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSetprjcvr --- IBEGIN
	WznmMVersion* ver = NULL;

	if (dbswznm->tblwznmmversion->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref), &ver)) {
		if (ver->ixVState == VecWznmVMVersionState::ABANDON) Wznm::updateVerste(dbswznm, ver->ref, VecWznmVMVersionState::READY);

		dbswznm->executeQuery("UPDATE TblWznmMProject SET refWznmMVersion = " + to_string(ver->ref) + " WHERE ref = " + to_string(ver->prjRefWznmMProject));
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMPRJMOD, jref);

		delete ver;
	};
	// IP enterSgeSetprjcvr --- IEND

	return retval;
};

void CrdWznmVer::leaveSgeSetprjcvr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSetprjcvr --- INSERT
};
