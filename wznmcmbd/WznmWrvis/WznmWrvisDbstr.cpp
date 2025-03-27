/**
	* \file WznmWrvisDbstr.cpp
	* Wznm operation processor - write SVG code for database structure sheet (implementation)
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

#include "WznmWrvisDbstr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvis;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvisDbstr
 ******************************************************************************/

DpchRetWznm* WznmWrvisDbstr::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvisDbstr* dpchinv
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

	map<ubigint,unsigned int> ixBoxs; // by ref

	WznmQVisBoxctx* org = NULL;
	WznmQVisBoxctx* dst = NULL;

	ListWznmQVisLinkctx lnks;
	WznmQVisLinkctx* lnk = NULL;

	ListWznmQVisRowctx rows;
	WznmQVisRowctx* row = NULL;

	vector<string> rowconts; // row content for .svg output
	string rowcont;
	string style;

	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	WznmMRelation* rel = NULL;
	WznmMRelation* auxprefrel = NULL;
	ubigint jtblref;
	ubigint refLcl;

	WznmMVector* vec = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	uint jnum;

	string Content1, Content2, Content3;

	const unsigned int wtot = 1600;
	const unsigned int xmargin = 15;
	const unsigned int ymargin = 15;
	const unsigned int ygap = 20;
	const unsigned int wcol = 200;
	const unsigned int wbox = 170;

	unsigned int x, y0;

	int x1, y1, x2, y2;

	vector<string> ss, ss2;
	string s;

	size_t ptr;

	// fill up columns evenly from the top
	const unsigned int NCol = wtot/wcol;
	unsigned int ixCol;

	vector<unsigned int> y0s;
	y0s.resize(NCol, ymargin);

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

			ixCol = NCol - 1;
			for (unsigned int j = NCol; j > 0; j--) if (y0s[j-1] <= y0s[ixCol]) ixCol = j-1;

			if (box->x == 0) box->x = xmargin + wcol*ixCol;
			if (box->y == 0) box->y = y0s[ixCol];

			box->w = wbox;
			box->h = 0;

			if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMTABLE) {
				if (dbswznm->tblwznmmtable->loadRecByRef(box->unvUref, &tbl)) {
					box->stubUnvUref = tbl->sref;

					dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tcos);

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

					rowconts.push_back(tbl->sref + "~bihdr");
					box->h += 22 + 2*5;

					// one row per table column
					jtblref = 0;

					for (unsigned int j = 0; j < tcos.nodes.size(); j++) {
						tco = tcos.nodes[j];

						//
						if (jtblref != 0) if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(jtblref) + " AND sref = '" + tco->sref + "'", ref)) jtblref = 0;
						if (tco->refWznmMRelation != 0) dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel);
						if (rel) {
							if (rel->ixVBasetype == VecWznmVMRelationBasetype::JPREF) jtblref = rel->frRefWznmMTable;
							else if (rel->ixVBasetype == VecWznmVMRelationBasetype::AUXPREF) auxprefrel = new WznmMRelation(*rel);
						};
						// <

						getTcoContext(dbswznm, tco, rel, auxprefrel, refLcl, Content1, Content2, Content3);

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

						style = "bi";
						if (StrMod::srefInSrefs(tco->srefsKOption, "affil")) style = "biaffil";
						else if (tco->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) style = "biaxis";
						else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->sref.rfind("Basetype") != string::npos)) style = "bityp";
						else if (jtblref != 0) style = "bijovr";
						else if (rel) {
							if (((rel->ixVBasetype == VecWznmVMRelationBasetype::INC) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC)) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) style = "biinc";
							else if ((rel->supIxVSubrole == VecWznmVMRelationSupSubrole::PREF) || (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::FROMPREF) || (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::TOPREF)) style = "bipref";
						};

						rowconts.push_back(tco->sref + "~" + style);
						box->h += 12 + 2*5;

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

					delete tbl;
				};

			} else if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMVECTOR) {
				if (dbswznm->tblwznmmvector->loadRecByRef(box->unvUref, &vec)) {
					box->stubUnvUref = vec->sref;

					dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

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

					rowconts.push_back(vec->sref + "~bihdrlite");
					box->h += 22 + 2*5;

					// one row for all vector items
					row = new WznmQVisRowctx(
								0, // qref
								true, // qwr
								jrefBoxctx, // jref
								jnum++, // jnum
								box->jnum, // jnumBox
								"", // Content1
								"", // Content2
								"" // Content3
							);
					rows.nodes.push_back(row);

					ss.clear();

					for (unsigned int j = 0; j < vits.nodes.size(); j++) {
						vit = vits.nodes[j];

						if (vit->Title == "") ss.push_back(vit->sref + "~bivec");
						else ss.push_back(vit->Title + " (" + vit->sref + ")~bivec");
					};

					StrMod::vectorToString(ss, s);
					rowconts.push_back(s);

					box->h += 12 * ss.size() + 2*5;

					delete vec;
				};
			};

			y0s[ixCol] += box->h + ygap;
		};

		// - write files
		s = xchg->tmppath + "/" + folder + "/VisDbstr" + Prjshort + Shtshort + ".svg.ip";
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

			style = "box";
			if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMVECTOR) style = "boxlite";

			svgfile << "\t<g id=\"box" << box->jnum << "\" transform=\"translate(" << box->x << "," << box->y << ")\" onmousedown=\"handleBoxMdn(event," << box->jnum << ")\">" << endl;

			x = box->w/2;
			y0 = 0;

			for (; j < rows.nodes.size(); j++) {
				row = rows.nodes[j];
				if (row->jnumBox != box->jnum) break;

				rowcont = rowconts[j];
				StrMod::stringToVector(rowcont, ss);

				svgfile << "\t\t<path d=\"M0.0," << y0 << "L" << box->w << "," << y0 << "L" << box->w << "," << (y0 + 12 * ss.size() + 2*5) << "L0.0," << (y0 + 12 * ss.size() + 2*5) << "L0.0," << y0 << "z\" class=\"" << style << "\"";
				if ((row->Content1 != "") || (row->Content2 != "") || (row->Content3 != "")) svgfile << " onmousemove=\"handleRowMov(event," << row->jnum << "," << row->jnumBox << ")\" onmouseout=\"handleRowMou(" << row->jnum << "," << row->jnumBox << ")\"";
				svgfile << "/>" << endl;

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

		s = xchg->tmppath + "/" + folder + "/VisDbstr" + Prjshort + Shtshort + "_src.xml.ip";
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

// IP cust --- INSERT
