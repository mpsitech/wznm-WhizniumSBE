/**
	* \file WznmWrvis.cpp
	* Wznm operation pack global code (implementation)
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

#include "WznmWrvis.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvis
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrvis::getTcoContext(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, WznmMRelation* auxprefrel
			, const ubigint refLcl
			, string& Header
			, string& Subheader
			, string& Content
		) {
	WznmMVector* vec = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	vector<string> ss;

	Header = "";

	// decision tree loosely based on WznmGenDetui::genPnldetail()
	if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		Header = getTcoContext_hdrstd(dbswznm, tco, refLcl);

	} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		if (auxprefrel) Header = getTcoContext_hdrrelauxpref(dbswznm, tco, auxprefrel, refLcl);
		else Header = getTcoContext_hdrvec(dbswznm, tco, refLcl);

	} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && rel) {
		if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) {
			Header = getTcoContext_hdrrel(dbswznm, tco, rel, refLcl);

		} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
			Header = getTcoContext_hdrreluniv(dbswznm, tco, refLcl);

		} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) {
			if (rel->ixVBasetype == VecWznmVMRelationBasetype::AU1N) {
				Header = getTcoContext_hdrreluniv(dbswznm, tco, refLcl);

			} else {
				if (rel->ixVBasetype == VecWznmVMRelationBasetype::A1N) {
					Header = getTcoContext_hdrrel(dbswznm, tco, rel, refLcl);
				};
			};
		} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) {
			Header = getTcoContext_hdrtag(dbswznm, "clust", refLcl);
		};

	} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && rel) {
		if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) {
			Header = getTcoContext_hdrrel(dbswznm, tco, rel, refLcl);

		} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) {
			Header = getTcoContext_hdrrelpl(dbswznm, tco, rel, refLcl);
		};

	} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		if (auxprefrel) Header = getTcoContext_hdrrelauxpref(dbswznm, tco, auxprefrel, refLcl);
		else Header = getTcoContext_hdrvec(dbswznm, tco, refLcl);

	} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		Header = getTcoContext_hdrstd(dbswznm, tco, refLcl);

	} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR)) {
		if (auxprefrel) Header = getTcoContext_hdrrelauxpref(dbswznm, tco, auxprefrel, refLcl);
		else Header = getTcoContext_hdrstd(dbswznm, tco, refLcl);
	};

	Subheader = "";
	Content = "";

	if ((tco->refWznmMRelation != 0) && ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF))) {
		Subheader = StubWznm::getStubRelStd(dbswznm, tco->refWznmMRelation);

	} else if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
		if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
			Subheader = StubWznm::getStubVecStd(dbswznm, tco->fctUref) + " (" + VecWznmVMVectorBasetype::getTitle(vec->ixVBasetype, 1) + ")";

			delete vec;
		};

		dbswznm->tblwznmmvectoritem->loadRstByVec(tco->fctUref, false, vits);

		ss.clear();
		for (unsigned int l = 0; l < vits.nodes.size(); l++) {
			vit = vits.nodes[l];

			if (vit->Title == "") ss.push_back(vit->sref);
			else ss.push_back(vit->Title + " (" + vit->sref + ")");
		};
		StrMod::vectorToString(ss, Content);

	} else {
		// general table column
		Subheader = VecWznmVMTablecolBasetype::getTitle(tco->ixVBasetype, 1);
		if (tco->ixVSubtype != VecWznmVMTablecolSubtype::VOID) Subheader += ", " + VecWznmVMTablecolSubtype::getTitle(tco->ixVSubtype, 1);
	};
};

string WznmWrvis::getTcoContext_hdrstd(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
		) {
	string s;

	// cf. WznmGenDetui::genPnldetail_cjtstdstr()
	// 1st try: tco full

	dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s);

	return s;
};

string WznmWrvis::getTcoContext_hdrtag(
			DbsWznm* dbswznm
			, const string& srefTag
			, const ubigint refLcl
		) {
	WznmMTag* tag = NULL;

	string s;

	if (dbswznm->tblwznmmtag->loadRecByCpbSrfGrp(0, srefTag, "", &tag)) {
		if (!dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, refLcl, s)) s = tag->Title;

		delete tag;
	};

	return s;
};

string WznmWrvis::getTcoContext_hdrvec(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
		) {
	string s;

	// cf. WznmGenDetui::genPnldetail_cjtvecstr()
	// 1st try: tco full; 2nd try: vec full

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s))
		dbswznm->tblwznmamvectortitle->loadTitByVecTypLoc(tco->fctUref, VecWznmVAMVectorTitleType::FULL, refLcl, s);

	return s;
};

string WznmWrvis::getTcoContext_hdrrel(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
		) {
	string s;

	bool toNotFr;

	// cf. WznmGenDetui::genPnldetail_cjtrelstr()
	// 1st try: tco full; 2nd try: rel {from/to}sngfull; 3rd try: {from/to}tbl full

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s)) {
		toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

		if (toNotFr) {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::TOSNGFULL, refLcl, s))
				dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->toRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s);

		} else {
			if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s))
				dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::SNGFULL, refLcl, s);
		};
	};

	return s;
};

string WznmWrvis::getTcoContext_hdrrelpl(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
		) {
	string s;

	// cf. WznmGenDetui::genPnldetail_cjtrelplstr()
	// 1st try: tco full; 2nd try: rel fromplfull; 3rd try: tbl plfull

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s))
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMPLFULL, refLcl, s))
			dbswznm->tblwznmamtabletitle->loadTitByTblTypLoc(rel->frRefWznmMTable, VecWznmVAMTableTitleType::PLFULL, refLcl, s);

	return s;
};

string WznmWrvis::getTcoContext_hdrreluniv(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, const ubigint refLcl
		) {
	string s;

	// cf. WznmGenDetui::genPnldetail_cjtrelunivstr()
	// 1st try: tco full; 2nd try: rel fromsngfull

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s))
		dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(tco->refWznmMRelation, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s);

	return s;
};

string WznmWrvis::getTcoContext_hdrrelauxpref(
			DbsWznm* dbswznm
			, WznmMTablecol* tco
			, WznmMRelation* rel
			, const ubigint refLcl
		) {
	string s;

	// cf. WznmGenDetui::genPnldetail_cjtrelauxprefstr()
	// 1st try: tco full; 2nd try: rel fromsngfull; 3rd try: vitJtit->Title of aux table x1 klst source

	if (!dbswznm->tblwznmamtablecoltitle->loadTitByTcoTypLoc(tco->ref, VecWznmVAMTablecolTitleType::FULL, refLcl, s))
		if (!dbswznm->tblwznmamrelationtitle->loadTitByRelTypLoc(rel->ref, VecWznmVAMRelationTitleType::FROMSNGFULL, refLcl, s))
			dbswznm->loadStringBySQL("SELECT TblWznmJMVectoritem.Title FROM TblWznmMTablecol, TblWznmMVectoritem, TblWznmJMVectoritem WHERE TblWznmMTablecol.tblRefWznmMTable = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMTablecol.ixVBasetype = "
					+ to_string(VecWznmVMTablecolBasetype::KLREF) + " AND TblWznmMTablecol.fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::VEC) + " AND TblWznmMTablecol.sref LIKE 'x1%' AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMTablecol.fctUref AND TblWznmMVectoritem.sref = '"
					+ rel->Prefix + "' AND TblWznmJMVectoritem.refWznmMVectoritem = TblWznmMVectoritem.ref AND TblWznmJMVectoritem.x1RefWznmMLocale = " + to_string(refLcl), s);

	return s;
};

void WznmWrvis::clkToXy(
			const int xctr
			, const int yctr
			, const int w
			, const int h
			, const int clk
			, int& x
			, int& y
		) {
	double phi;
	double y0r, y0l, x0t, x0b;

	if (clk == 0) {
		x = xctr;
		y = yctr;

	} else {
		// clock value to angle
		phi = (360/12*(12+3-clk))%360;
		phi = M_PI/180.0*phi; // interval 0..2*pi

		// intersections with right/left/top/bottom box boundary
		y0r = ((clk%6) == 0) ? h : w/2.0 * tan(phi);
		y0l = -y0r;
		x0t = ((clk%6) == 3) ? w : h/2.0 * tan(M_PI/2.0-phi);
		x0b = -x0t;

		if (phi <= M_PI/2.0) {
			// right or top edge
			x = w/2.0;
			y = h/2.0;

			if (y0r < h/2.0) y = y0r;
			else x = x0t;

		} else if (phi <= M_PI) {
			// top or left edge
			x = -w/2.0;
			y = h/2.0;

			if (y0l < h/2.0) y = y0l;
			else x = x0t;

		} else if (phi <= 3.0*M_PI/2.0) {
			// left or bottom edge
			x = -w/2.0;
			y = -h/2.0;

			if (h/2.0 < y0l) y = y0l;
			else x = x0b;

		} else {
			// bottom or right edge
			x = w/2.0;
			y = -h/2.0;

			if (h/2.0 < y0r) y = y0r;
			else x = x0b;
		};

		x += xctr;
		y = yctr - y; // SVG coordinate system is y-flipped
	};
};
// IP cust --- IEND
