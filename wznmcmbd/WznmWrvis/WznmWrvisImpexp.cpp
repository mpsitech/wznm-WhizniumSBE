/**
	* \file WznmWrvisImpexp.cpp
	* Wznm operation processor - write SVG code for sheet (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrvisImpexp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvis;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvisImpexp
 ******************************************************************************/

DpchRetWznm* WznmWrvisImpexp::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvisImpexp* dpchinv
		) {
	ubigint refWznmMSheet = dpchinv->refWznmMSheet;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;
	string Shtshort = dpchinv->Shtshort;
	ubigint jrefBoxctx = dpchinv->jrefBoxctx;
	ubigint jrefLinkctx = dpchinv->jrefLinkctx;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	const ubigint jrefRowctx = 1;

	fstream svgfile;
	fstream srcfile;

	WznmMSheet* sht = NULL;

	ListWznmQVisBoxctx boxs;
	WznmQVisBoxctx* box = NULL;
	WznmQVisBoxctx* box2 = NULL;

	map<ubigint,unsigned int> ixBoxs; // by ref

	WznmQVisBoxctx* org = NULL;
	WznmQVisBoxctx* dst = NULL;

	ListWznmQVisLinkctx lnks;
	WznmQVisLinkctx* lnk = NULL;

	ListWznmQVisRowctx rows;
	WznmQVisRowctx* row = NULL;

	vector<string> rowconts; // row content for .svg output
	string rowcont;

	WznmMImpexp* ime = NULL;

	set<string> rtrUnqsrefs;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	WznmMRelation* rel = NULL;
	WznmMRelation* auxprefrel = NULL;
	ubigint refLcl;

	uint jnum;

	string Content1, Content2, Content3;

	const unsigned int ymargin = 15;
	const unsigned int ygap = 20;
	const unsigned int wbox = 170;

	unsigned int x, y0;
	map<unsigned int, unsigned int> y0s; // by x

	int x1, y1, x2, y2;

	vector<string> ss, ss2;
	string s;

	size_t ptr;

	if (dbswznm->tblwznmmsheet->loadRecByRef(refWznmMSheet, &sht)) {
		if (dbswznm->loadRefBySQL("SELECT verRefWznmMVersion FROM TblWznmMVisual WHERE ref = " + to_string(sht->visRefWznmMVisual), ref)) Wznm::getVerlclref(dbswznm, ref, refLcl);

		dbswznm->tblwznmqvisboxctx->loadRstBySQL("SELECT * FROM TblWznmQVisBoxctx WHERE jref = " + to_string(jrefBoxctx) + " AND tref = " + to_string(sht->ref)
					+ " ORDER BY jnum ASC", false, boxs);

		dbswznm->tblwznmqvislinkctx->loadRstBySQL("SELECT * FROM TblWznmQVisLinkctx WHERE jref = " + to_string(jrefLinkctx) + " AND tref = " + to_string(sht->ref)
					+ " ORDER BY jnum ASC", false, lnks);

		// - gather information
		jnum = 1;

		for (unsigned int i = 0; i < boxs.nodes.size(); i++) {
			box = boxs.nodes[i];

			ixBoxs[box->ref] = i;

			if (dbswznm->tblwznmmimpexp->loadRecByRef(box->unvUref, &ime)) {
				dbswznm->tblwznmmimpexpcol->loadRstByIme(ime->ref, false, iels);
				dbswznm->tblwznmmtablecol->loadRstByTbl(ime->refWznmMTable, false, tcos);

				rtrUnqsrefs.clear();
				StrMod::stringToVector(ime->rtrSrefsWznmMImpexpcol, ss);
				for (unsigned int j = 0; j < ss.size(); j++) rtrUnqsrefs.insert(ss[j]);

				box->stubUnvUref = Shtshort + "." + ime->sref;

				for (unsigned int j = 0; j < i; j++) {
					box2 = boxs.nodes[j];
					
					if (box2->unvUref == ime->supRefWznmMImpexp) {
						if (box2->jnumsSub != "") box2->jnumsSub += ";";
						box2->jnumsSub += to_string(box->jnum);
					};
				};

				if (box->y == 0) {
					auto it = y0s.find(box->x);
					if (it == y0s.end()) y0s[box->x] = ymargin;
				};

				box->w = wbox;
				box->h = 0;

				box->Content1 = string(ime->supLvl, '\t') + ime->sref + ".";
				ss.clear();
				for (unsigned int j = 0; j < iels.nodes.size(); j++) {
					iel = iels.nodes[j];
					if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) ss.push_back(iel->sref);
				};
				StrMod::vectorToString(ss, s);
				box->Content1 += s;

				box->Content2 = string(ime->supLvl, '\t') + ime->sref + ".end";

				// title row
				row = new WznmQVisRowctx(
							0, // qref
							true, // qwr
							jrefRowctx, // jref
							jnum++, // jnum
							box->jnum, // jnumBox
							"", // Content1
							"", // Content2
							"" // Content3
						);
				rows.nodes.push_back(row);

				rowconts.push_back(ime->sref + "~bihdr");
				box->h += 22 + 2*5;

				// one row per either tco or iel - or both
				unsigned int k = 0; // index for iels
				unsigned int ktest;

				for (unsigned int j = 0; j <= tcos.nodes.size(); j++) {
					if (j != tcos.nodes.size()) {
						tco = tcos.nodes[j];

						//
						if (tco->refWznmMRelation != 0) dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel);
						if (rel) if (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) auxprefrel = new WznmMRelation(*rel);
						// <

						for (ktest = k; ktest < iels.nodes.size(); ktest++)
							if (iels.nodes[ktest]->refWznmMTablecol == tco->ref)
								break;

						if (ktest == iels.nodes.size())
							for (ktest = k; ktest < iels.nodes.size(); ktest++)
								if (iels.nodes[ktest]->refWznmMTablecol != 0)
									break;

					} else {
						tco = NULL;
						ktest = iels.nodes.size();
					};

					// add iel-only rows (types IOP, IARG)
					if (!tco || (ktest != iels.nodes.size())) {
						for (; k < ktest; k++) {
							iel = iels.nodes[k];

							getIelContext(dbswznm, ime, iel, NULL, NULL, NULL, refLcl, Content1, Content2, Content3);

							row = new WznmQVisRowctx(
										0, // qref
										true, // qwr
										jrefRowctx, // jref
										jnum++, // jnum
										box->jnum, // jnumBox
										Content1, // Content1
										Content2, // Content2
										Content3 // Content3
									);

							rows.nodes.push_back(row);

							ss.clear();

							ss.push_back(iel->sref + " (" + iel->Short + ")~bifil");
							if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
								ss.push_back("+ ixWznmVIop~bi");
							};

							StrMod::vectorToString(ss, s);
							rowconts.push_back(s);

							box->h += 12 * ss.size() + 2*5;
						};
					};

					if (tco) {
						// add tco or tco+iel row
						iel = NULL;
						if (k != iels.nodes.size()) if (iels.nodes[k]->refWznmMTablecol == tco->ref) {
							iel = iels.nodes[k];
							k++;
						};

						getIelContext(dbswznm, ime, iel, tco, rel, auxprefrel, refLcl, Content1, Content2, Content3);

						row = new WznmQVisRowctx(
									0, // qref
									true, // qwr
									jrefBoxctx, // jref
									jnum++, // jnum
									box->jnum, // jnumBox
									Content1, // Content1
									Content2, // Content2
									Content3 // Content3
								);

						rows.nodes.push_back(row);

						ss.clear();

						if (iel) {
							if (rtrUnqsrefs.find(iel->sref) != rtrUnqsrefs.end()) s = "biretr";
							else s = "bifil";

							if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
								if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) ss.push_back("* " + iel->sref + " (" + iel->Short + ")~" + s);
								else ss.push_back("* " + iel->sref + "~bitbl");
							} else {
								ss.push_back(iel->sref + " (" + iel->Short + ")~" + s);
								ss.push_back("* "  + tco->sref + "~bi");
							};
						} else ss.push_back("* "  + tco->sref + "~bi");

						StrMod::vectorToString(ss, s);
						rowconts.push_back(s);

						box->h += 12 * ss.size() + 2*5;

						//
						if (auxprefrel && !rel) {
							delete auxprefrel;
							auxprefrel = NULL;
						} else if (auxprefrel && rel) if (auxprefrel->ref != rel->ref) {
							delete auxprefrel;
							auxprefrel = NULL;
						};

						if (rel) {
							delete rel;
							rel = NULL;
						};
						// <
					};
				};

				if (box->y == 0) {
					box->y = y0s[box->x];
					y0s[box->x] += box->h + ygap;
				};
			};

			delete ime;
		};

		// - write files
		s = xchg->tmppath + "/" + folder + "/VisImpexp" + Prjshort + Shtshort + ".svg.ip";
		svgfile.open(s.c_str(), ios::out);

		// --- lnks
		svgfile << "<!-- IP lnks - IBEGIN -->" << endl;

		for (unsigned int i = 0; i < lnks.nodes.size(); i++) {
			lnk = lnks.nodes[i];

			auto it = ixBoxs.find(lnk->orgRefWznmMBox);
			if (it != ixBoxs.end()) {
				org = boxs.nodes[it->second];
				lnk->jnumBoxOrg = org->jnum;

				it = ixBoxs.find(lnk->dstRefWznmMBox);
				if (it != ixBoxs.end()) {
					dst = boxs.nodes[it->second];
					lnk->jnumBoxDst = dst->jnum;

					clkToXy(org->x + org->w/2, org->y + org->h/2, org->w, org->h, lnk->orgClk, x1, y1);
					clkToXy(dst->x + dst->w/2, dst->y + dst->h/2, dst->w, dst->h, lnk->dstClk, x2, y2);

					svgfile << "\t<line id=\"lnk" << lnk->jnum << "\" x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" class=\"link\"/>" << endl;

					if (org->jnumsLink == "") org->jnumsLink = to_string(lnk->jnum);
					else org->jnumsLink += ";" + to_string(lnk->jnum);

					if (dst->jnumsLink == "") dst->jnumsLink = to_string(lnk->jnum);
					else dst->jnumsLink += ";" + to_string(lnk->jnum);
				};
			};
		};

		svgfile << "<!-- IP lnks - IEND -->" << endl;

		// --- boxs
		svgfile << "<!-- IP boxs - IBEGIN -->" << endl;

		unsigned int j = 0;

		for (unsigned int i = 0; i < boxs.nodes.size(); i++) {
			box = boxs.nodes[i];

			svgfile << "\t<g id=\"box" << box->jnum << "\" transform=\"translate(" << box->x << "," << box->y << ")\" onmousedown=\"handleBoxMdn(event," << box->jnum << ")\">" << endl;

			x = box->w/2;
			y0 = 0;

			for (; j < rows.nodes.size(); j++) {
				row = rows.nodes[j];
				if (row->jnumBox != box->jnum) break;

				rowcont = rowconts[j];
				StrMod::stringToVector(rowcont, ss);

				svgfile << "\t\t<path d=\"M0.0," << y0 << "L" << box->w << "," << y0 << "L" << box->w << "," << (y0 + 12 * ss.size() + 2*5) << "L0.0," << (y0 + 12 * ss.size() + 2*5) << "L0.0," << y0 << "z\" class=\"box\"";
				if ((row->Content1 != "") || (row->Content2 != "") || (row->Content3 != "")) svgfile << " onmousemove=\"handleRowMov(event," << row->jnum << "," << row->jnumBox << ")\" onmouseout=\"handleRowMou(" << row->jnum << "," << row->jnumBox << ")\"";
				svgfile << "/>" << endl;

				if (y0 == 0) {
					if ((box->Content1 != "") || (box->Content2 != "")) svgfile << "\t\t<path d=\"M150.5,3L165.5,3M150.5,18L165.5,18M154.5,6L160.5,6L160.5,12L154.5,12L154.5,6M162.5,9L165.5,9L165.5,15L159.5,15L159.5,14\" class=\"icon\" onclick=\"handleRowClick(event," << row->jnum << "," << row->jnumBox << ",1)\"/>" << endl;
					if (box->jnumsSub != "") svgfile << "\t\t<path d=\"M3.5,3L18.5,3M3.5,18L18.5,18M7.5,6L13.5,6L13.5,12L7.5,12L7.5,6M15.5,9L18.5,9L18.5,15L12.5,15L12.5,14M4.5,6L5.5,6M4.5,9L5.5,9M4.5,12L5.5,12M4.5,15L10.5,15\" class=\"icon\" onclick=\"handleRowClick(event," << row->jnum << "," << row->jnumBox << ",2)\"/>" << endl;
				};

				svgfile << "\t\t<text xml:space=\"preserve\">" << endl;

				for (unsigned int k = 0; k < ss.size(); k++) {
					StrMod::stringToVector(ss[k], ss2, '~');
					svgfile << "\t\t\t<tspan x=\"" << x << "\" y=\"" << (y0 + 2 + 12 * (k + 1)) << "\" class=\"" << ss2[1] << "\">" << ss2[0] << "</tspan>" << endl;
				};

				svgfile << "\t\t</text>" << endl;

				x = 4;
				y0 += 12 * ss.size() + 2*5;
			};

			svgfile << "\t</g>" << endl;
		};

		svgfile << "<!-- IP boxs - IEND -->" << endl;

		svgfile.close();

		s = xchg->tmppath + "/" + folder + "/VisImpexp" + Prjshort + Shtshort + "_src.xml.ip";
		srcfile.open(s.c_str(), ios::out);

		xmlBuffer* buf = NULL;
		xmlTextWriter* wr = NULL;

		// --- src
		srcfile << "<!-- IP src - IBEGIN -->" << endl;

		startwriteBuffer(&wr, &buf);
			boxs.writeXML(wr);
			lnks.writeXML(wr);
			rows.writeXML(wr);
		closewriteBuffer(wr);

		s = string((const char*) (buf->content), buf->use);

		// strip <?xml ... ?>
		ptr = s.find("?>");
		if (ptr != string::npos) ptr = s.find("<", ptr);
		if (ptr == string::npos) ptr = 0;

		srcfile << s.substr(ptr);

		xmlBufferFree(buf);

		srcfile << "<!-- IP src - IEND -->" << endl;

		srcfile.close();

		delete sht;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrvisImpexp::getIelContext(
			DbsWznm* dbswznm
			, WznmMImpexp* ime
			, WznmMImpexpcol* iel
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, WznmMRelation* auxprefrel
			, const ubigint refLcl
			, string& Header
			, string& Subheader
			, string& Content
		) {
	set<uint> ics;

	vector<string> ss;

	Header = "";
	Subheader = "";
	Content = "";

	if (iel) {
		if (!tco) {
			Header = VecWznmVMImpexpcolBasetype::getTitle(iel->ixVBasetype, 1);

			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				VecWznmWMImpexpIop::getIcs(ime->ixWIop, ics);

				ss.clear();
				for (auto it = ics.begin(); it != ics.end(); it++) ss.push_back(VecWznmWMImpexpIop::getTitle(*it, 1) + " (" + VecWznmWMImpexpIop::getSrefs(*it) + ")");
				StrMod::vectorToString(ss, Content);
			};

		} else {
			// initialize with table column context
			getTcoContext(dbswznm, tco, rel, auxprefrel, refLcl, Header, Subheader, Content);

			// overwrite depending on imp./exp. column (conversion) type
			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) {
				Header = VecWznmVMImpexpcolBasetype::getTitle(iel->ixVBasetype, 1);
				Subheader = "";

			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF) {
				Subheader = "(int ref to " + StubWznm::getStubImeStd(dbswznm, iel->refWznmMImpexp) + ")";

			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if ((iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) == 0) {
					if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::VOID) {
						if (iel->Defval != "") Subheader = "(" + iel->Defval + ")";
						else if (iel->refWznmMVectoritem != 0) Subheader = "(" + StubWznm::getStubVitStd(dbswznm, iel->refWznmMVectoritem) + ")";

						Content = "";

					} else if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::PRESET) {
						Subheader = "(presetting " + StubWznm::getStubPstStd(dbswznm, iel->refWznmMPreset) + ")";

					} else  {
						Subheader = "(" + VecWznmVMImpexpcolConvtype::getTitle(iel->ixVConvtype, 1) + ")";
					};

				} else if (iel->ixVConvtype != VecWznmVMImpexpcolConvtype::VOID) {
					Subheader = "(" + VecWznmVMImpexpcolConvtype::getTitle(iel->ixVConvtype, 1) + ")";
				};
			};
		};
	};
};
// IP cust --- IEND
