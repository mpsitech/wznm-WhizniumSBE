/**
	* \file WznmMControl.cpp
	* database access for table TblWznmMControl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMControl.h"

#include "WznmMControl_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMControl
 ******************************************************************************/

WznmMControl::WznmMControl(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmCControl
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const uint hkIxVSection
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint supRefWznmMControl
			, const usmallint supLvl
			, const uint supNum
			, const uint ixVScope
			, const ubigint refWznmMFeed
			, const string sref
			, const uint ixVSubtype
			, const string srefsWznmMTag
			, const ubigint refJTitle
			, const string Title
			, const ubigint refJ
			, const ubigint stdRefWznmMStub
			, const ubigint shoRefWznmMStub
			, const string Avail
			, const string Active
			, const string srefsKOption
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmCControl = refWznmCControl;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->hkNum = hkNum;
	this->hkIxVSection = hkIxVSection;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->supRefWznmMControl = supRefWznmMControl;
	this->supLvl = supLvl;
	this->supNum = supNum;
	this->ixVScope = ixVScope;
	this->refWznmMFeed = refWznmMFeed;
	this->sref = sref;
	this->ixVSubtype = ixVSubtype;
	this->srefsWznmMTag = srefsWznmMTag;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->refJ = refJ;
	this->stdRefWznmMStub = stdRefWznmMStub;
	this->shoRefWznmMStub = shoRefWznmMStub;
	this->Avail = Avail;
	this->Active = Active;
	this->srefsKOption = srefsKOption;
};

bool WznmMControl::operator==(
			const WznmMControl& comp
		) {
	return false;
};

bool WznmMControl::operator!=(
			const WznmMControl& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMControl
 ******************************************************************************/

ListWznmMControl::ListWznmMControl() {
};

ListWznmMControl::ListWznmMControl(
			const ListWznmMControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMControl(*(src.nodes[i]));
};

ListWznmMControl::~ListWznmMControl() {
	clear();
};

void ListWznmMControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMControl::size() const {
	return(nodes.size());
};

void ListWznmMControl::append(
			WznmMControl* rec
		) {
	nodes.push_back(rec);
};

WznmMControl* ListWznmMControl::operator[](
			const uint ix
		) {
	WznmMControl* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMControl& ListWznmMControl::operator=(
			const ListWznmMControl& src
		) {
	WznmMControl* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMControl(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMControl::operator==(
			const ListWznmMControl& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWznmMControl::operator!=(
			const ListWznmMControl& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMControl
 ******************************************************************************/

TblWznmMControl::TblWznmMControl() {
};

TblWznmMControl::~TblWznmMControl() {
};

bool TblWznmMControl::loadRecBySQL(
			const string& sqlstr
			, WznmMControl** rec
		) {
	return false;
};

ubigint TblWznmMControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMControl& rst
		) {
	return 0;
};

ubigint TblWznmMControl::insertRec(
			WznmMControl* rec
		) {
	return 0;
};

ubigint TblWznmMControl::insertNewRec(
			WznmMControl** rec
			, const uint ixVBasetype
			, const ubigint refWznmCControl
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const uint hkIxVSection
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint supRefWznmMControl
			, const usmallint supLvl
			, const uint supNum
			, const uint ixVScope
			, const ubigint refWznmMFeed
			, const string sref
			, const uint ixVSubtype
			, const string srefsWznmMTag
			, const ubigint refJTitle
			, const string Title
			, const ubigint refJ
			, const ubigint stdRefWznmMStub
			, const ubigint shoRefWznmMStub
			, const string Avail
			, const string Active
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WznmMControl* _rec = NULL;

	_rec = new WznmMControl(0, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMControl::appendNewRecToRst(
			ListWznmMControl& rst
			, WznmMControl** rec
			, const uint ixVBasetype
			, const ubigint refWznmCControl
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const uint hkIxVSection
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint supRefWznmMControl
			, const usmallint supLvl
			, const uint supNum
			, const uint ixVScope
			, const ubigint refWznmMFeed
			, const string sref
			, const uint ixVSubtype
			, const string srefsWznmMTag
			, const ubigint refJTitle
			, const string Title
			, const ubigint refJ
			, const ubigint stdRefWznmMStub
			, const ubigint shoRefWznmMStub
			, const string Avail
			, const string Active
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WznmMControl* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMControl::insertRst(
			ListWznmMControl& rst
			, bool transact
		) {
};

void TblWznmMControl::updateRec(
			WznmMControl* rec
		) {
};

void TblWznmMControl::updateRst(
			ListWznmMControl& rst
			, bool transact
		) {
};

void TblWznmMControl::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMControl::loadRecByRef(
			ubigint ref
			, WznmMControl** rec
		) {
	return false;
};

bool TblWznmMControl::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblWznmMControl::loadRecByFed(
			ubigint refWznmMFeed
			, WznmMControl** rec
		) {
	return false;
};

ubigint TblWznmMControl::loadRefsByClu(
			ubigint refWznmCControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMControl::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMControl::loadRefsBySup(
			ubigint supRefWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMControl::loadRstByClu(
			ubigint refWznmCControl
			, const bool append
			, ListWznmMControl& rst
		) {
	return 0;
};

ubigint TblWznmMControl::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWznmMControl& rst
		) {
	return 0;
};

ubigint TblWznmMControl::loadRstBySup(
			ubigint supRefWznmMControl
			, const bool append
			, ListWznmMControl& rst
		) {
	return 0;
};

bool TblWznmMControl::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWznmMControl::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMControl
		) {
	return false;
};

ubigint TblWznmMControl::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMControl& rst
		) {
	ubigint numload = 0;
	WznmMControl* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWznmMControl::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWznmMControl::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

ubigint TblWznmMControl::loadHrstup(
			ubigint ref
			, ListWznmMControl& rst
		) {
	WznmMControl* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWznmMControl;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWznmMControl::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWznmMControl& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WznmMControl* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMControl
 ******************************************************************************/

MyTblWznmMControl::MyTblWznmMControl() :
			TblWznmMControl()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMControl::~MyTblWznmMControl() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMControl::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMControl (ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMControl SET ixVBasetype = ?, refWznmCControl = ?, hkIxVTbl = ?, hkUref = ?, hkNum = ?, hkIxVSection = ?, refIxVTbl = ?, refUref = ?, supRefWznmMControl = ?, supLvl = ?, supNum = ?, ixVScope = ?, refWznmMFeed = ?, sref = ?, ixVSubtype = ?, srefsWznmMTag = ?, refJTitle = ?, Title = ?, refJ = ?, stdRefWznmMStub = ?, shoRefWznmMStub = ?, Avail = ?, Active = ?, srefsKOption = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMControl WHERE ref = ?", false);
};

bool MyTblWznmMControl::loadRecBySQL(
			const string& sqlstr
			, WznmMControl** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMControl* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMControl::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMControl::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMControl();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmCControl = atoll((char*) dbrow[2]); else _rec->refWznmCControl = 0;
		if (dbrow[3]) _rec->hkIxVTbl = atol((char*) dbrow[3]); else _rec->hkIxVTbl = 0;
		if (dbrow[4]) _rec->hkUref = atoll((char*) dbrow[4]); else _rec->hkUref = 0;
		if (dbrow[5]) _rec->hkNum = atol((char*) dbrow[5]); else _rec->hkNum = 0;
		if (dbrow[6]) _rec->hkIxVSection = atol((char*) dbrow[6]); else _rec->hkIxVSection = 0;
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;
		if (dbrow[9]) _rec->supRefWznmMControl = atoll((char*) dbrow[9]); else _rec->supRefWznmMControl = 0;
		if (dbrow[10]) _rec->supLvl = atoi((char*) dbrow[10]); else _rec->supLvl = 0;
		if (dbrow[11]) _rec->supNum = atol((char*) dbrow[11]); else _rec->supNum = 0;
		if (dbrow[12]) _rec->ixVScope = atol((char*) dbrow[12]); else _rec->ixVScope = 0;
		if (dbrow[13]) _rec->refWznmMFeed = atoll((char*) dbrow[13]); else _rec->refWznmMFeed = 0;
		if (dbrow[14]) _rec->sref.assign(dbrow[14], dblengths[14]); else _rec->sref = "";
		if (dbrow[15]) _rec->ixVSubtype = atol((char*) dbrow[15]); else _rec->ixVSubtype = 0;
		if (dbrow[16]) _rec->srefsWznmMTag.assign(dbrow[16], dblengths[16]); else _rec->srefsWznmMTag = "";
		if (dbrow[17]) _rec->refJTitle = atoll((char*) dbrow[17]); else _rec->refJTitle = 0;
		if (dbrow[18]) _rec->Title.assign(dbrow[18], dblengths[18]); else _rec->Title = "";
		if (dbrow[19]) _rec->refJ = atoll((char*) dbrow[19]); else _rec->refJ = 0;
		if (dbrow[20]) _rec->stdRefWznmMStub = atoll((char*) dbrow[20]); else _rec->stdRefWznmMStub = 0;
		if (dbrow[21]) _rec->shoRefWznmMStub = atoll((char*) dbrow[21]); else _rec->shoRefWznmMStub = 0;
		if (dbrow[22]) _rec->Avail.assign(dbrow[22], dblengths[22]); else _rec->Avail = "";
		if (dbrow[23]) _rec->Active.assign(dbrow[23], dblengths[23]); else _rec->Active = "";
		if (dbrow[24]) _rec->srefsKOption.assign(dbrow[24], dblengths[24]); else _rec->srefsKOption = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMControl& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMControl* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMControl::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMControl::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMControl();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmCControl = atoll((char*) dbrow[2]); else rec->refWznmCControl = 0;
			if (dbrow[3]) rec->hkIxVTbl = atol((char*) dbrow[3]); else rec->hkIxVTbl = 0;
			if (dbrow[4]) rec->hkUref = atoll((char*) dbrow[4]); else rec->hkUref = 0;
			if (dbrow[5]) rec->hkNum = atol((char*) dbrow[5]); else rec->hkNum = 0;
			if (dbrow[6]) rec->hkIxVSection = atol((char*) dbrow[6]); else rec->hkIxVSection = 0;
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			if (dbrow[9]) rec->supRefWznmMControl = atoll((char*) dbrow[9]); else rec->supRefWznmMControl = 0;
			if (dbrow[10]) rec->supLvl = atoi((char*) dbrow[10]); else rec->supLvl = 0;
			if (dbrow[11]) rec->supNum = atol((char*) dbrow[11]); else rec->supNum = 0;
			if (dbrow[12]) rec->ixVScope = atol((char*) dbrow[12]); else rec->ixVScope = 0;
			if (dbrow[13]) rec->refWznmMFeed = atoll((char*) dbrow[13]); else rec->refWznmMFeed = 0;
			if (dbrow[14]) rec->sref.assign(dbrow[14], dblengths[14]); else rec->sref = "";
			if (dbrow[15]) rec->ixVSubtype = atol((char*) dbrow[15]); else rec->ixVSubtype = 0;
			if (dbrow[16]) rec->srefsWznmMTag.assign(dbrow[16], dblengths[16]); else rec->srefsWznmMTag = "";
			if (dbrow[17]) rec->refJTitle = atoll((char*) dbrow[17]); else rec->refJTitle = 0;
			if (dbrow[18]) rec->Title.assign(dbrow[18], dblengths[18]); else rec->Title = "";
			if (dbrow[19]) rec->refJ = atoll((char*) dbrow[19]); else rec->refJ = 0;
			if (dbrow[20]) rec->stdRefWznmMStub = atoll((char*) dbrow[20]); else rec->stdRefWznmMStub = 0;
			if (dbrow[21]) rec->shoRefWznmMStub = atoll((char*) dbrow[21]); else rec->shoRefWznmMStub = 0;
			if (dbrow[22]) rec->Avail.assign(dbrow[22], dblengths[22]); else rec->Avail = "";
			if (dbrow[23]) rec->Active.assign(dbrow[23], dblengths[23]); else rec->Active = "";
			if (dbrow[24]) rec->srefsKOption.assign(dbrow[24], dblengths[24]); else rec->srefsKOption = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMControl::insertRec(
			WznmMControl* rec
		) {
	unsigned long l[24]; my_bool n[24]; my_bool e[24];

	l[13] = rec->sref.length();
	l[15] = rec->srefsWznmMTag.length();
	l[17] = rec->Title.length();
	l[21] = rec->Avail.length();
	l[22] = rec->Active.length();
	l[23] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmCControl,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->hkNum,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->hkIxVSection,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->supRefWznmMControl,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->supLvl,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->supNum,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->ixVScope,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->refWznmMFeed,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->sref.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindUint(&rec->ixVSubtype,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->srefsWznmMTag.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindUbigint(&rec->refJTitle,&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->Title.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindUbigint(&rec->refJ,&(l[18]),&(n[18]),&(e[18])),
		bindUbigint(&rec->stdRefWznmMStub,&(l[19]),&(n[19]),&(e[19])),
		bindUbigint(&rec->shoRefWznmMStub,&(l[20]),&(n[20]),&(e[20])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[21]),&(n[21]),&(e[21])),
		bindCstring((char*) (rec->Active.c_str()),&(l[22]),&(n[22]),&(e[22])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[23]),&(n[23]),&(e[23]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMControl::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMControl::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMControl::insertRst(
			ListWznmMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMControl::updateRec(
			WznmMControl* rec
		) {
	unsigned long l[25]; my_bool n[25]; my_bool e[25];

	l[13] = rec->sref.length();
	l[15] = rec->srefsWznmMTag.length();
	l[17] = rec->Title.length();
	l[21] = rec->Avail.length();
	l[22] = rec->Active.length();
	l[23] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmCControl,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->hkNum,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->hkIxVSection,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->supRefWznmMControl,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->supLvl,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->supNum,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->ixVScope,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->refWznmMFeed,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->sref.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindUint(&rec->ixVSubtype,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->srefsWznmMTag.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindUbigint(&rec->refJTitle,&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->Title.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindUbigint(&rec->refJ,&(l[18]),&(n[18]),&(e[18])),
		bindUbigint(&rec->stdRefWznmMStub,&(l[19]),&(n[19]),&(e[19])),
		bindUbigint(&rec->shoRefWznmMStub,&(l[20]),&(n[20]),&(e[20])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[21]),&(n[21]),&(e[21])),
		bindCstring((char*) (rec->Active.c_str()),&(l[22]),&(n[22]),&(e[22])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[23]),&(n[23]),&(e[23])),
		bindUbigint(&rec->ref,&(l[24]),&(n[24]),&(e[24]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMControl::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMControl::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMControl::updateRst(
			ListWznmMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMControl::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMControl::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMControl::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMControl::loadRecByRef(
			ubigint ref
			, WznmMControl** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMControl WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMControl::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblWznmMControl::loadRecByFed(
			ubigint refWznmMFeed
			, WznmMControl** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE refWznmMFeed = " + to_string(refWznmMFeed) + "", rec);
};

ubigint MyTblWznmMControl::loadRefsByClu(
			ubigint refWznmCControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMControl WHERE refWznmCControl = " + to_string(refWznmCControl) + "", append, refs);
};

ubigint MyTblWznmMControl::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, refs);
};

ubigint MyTblWznmMControl::loadRefsBySup(
			ubigint supRefWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(supRefWznmMControl) + " ORDER BY supNum ASC", append, refs);
};

ubigint MyTblWznmMControl::loadRstByClu(
			ubigint refWznmCControl
			, const bool append
			, ListWznmMControl& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE refWznmCControl = " + to_string(refWznmCControl) + "", append, rst);
};

ubigint MyTblWznmMControl::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWznmMControl& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY hkNum ASC", append, rst);
};

ubigint MyTblWznmMControl::loadRstBySup(
			ubigint supRefWznmMControl
			, const bool append
			, ListWznmMControl& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(supRefWznmMControl) + " ORDER BY supNum ASC", append, rst);
};

bool MyTblWznmMControl::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMControl WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWznmMControl::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMControl
		) {
	return loadRefBySQL("SELECT supRefWznmMControl FROM TblWznmMControl WHERE ref = " + to_string(ref) + "", supRefWznmMControl);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMControl
 ******************************************************************************/

PgTblWznmMControl::PgTblWznmMControl() :
			TblWznmMControl()
			, PgTable()
		{
};

PgTblWznmMControl::~PgTblWznmMControl() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMControl::initStatements() {
	createStatement("TblWznmMControl_insertRec", "INSERT INTO TblWznmMControl (ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$20,$21,$22,$23,$24) RETURNING ref", 24);
	createStatement("TblWznmMControl_updateRec", "UPDATE TblWznmMControl SET ixVBasetype = $1, refWznmCControl = $2, hkIxVTbl = $3, hkUref = $4, hkNum = $5, hkIxVSection = $6, refIxVTbl = $7, refUref = $8, supRefWznmMControl = $9, supLvl = $10, supNum = $11, ixVScope = $12, refWznmMFeed = $13, sref = $14, ixVSubtype = $15, srefsWznmMTag = $16, refJTitle = $17, Title = $18, refJ = $19, stdRefWznmMStub = $20, shoRefWznmMStub = $21, Avail = $22, Active = $23, srefsKOption = $24 WHERE ref = $25", 25);
	createStatement("TblWznmMControl_removeRecByRef", "DELETE FROM TblWznmMControl WHERE ref = $1", 1);

	createStatement("TblWznmMControl_loadRecByRef", "SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE ref = $1", 1);
	createStatement("TblWznmMControl_confirmByRef", "SELECT ref FROM TblWznmMControl WHERE ref = $1", 1);
	createStatement("TblWznmMControl_loadRecByFed", "SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE refWznmMFeed = $1", 1);
	createStatement("TblWznmMControl_loadRefsByClu", "SELECT ref FROM TblWznmMControl WHERE refWznmCControl = $1", 1);
	createStatement("TblWznmMControl_loadRefsByHktHku", "SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = $1 AND hkUref = $2", 2);
	createStatement("TblWznmMControl_loadRefsBySup", "SELECT ref FROM TblWznmMControl WHERE supRefWznmMControl = $1 ORDER BY supNum ASC", 1);
	createStatement("TblWznmMControl_loadRstByClu", "SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE refWznmCControl = $1", 1);
	createStatement("TblWznmMControl_loadRstByHktHku", "SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE hkIxVTbl = $1 AND hkUref = $2 ORDER BY hkNum ASC", 2);
	createStatement("TblWznmMControl_loadRstBySup", "SELECT ref, ixVBasetype, refWznmCControl, hkIxVTbl, hkUref, hkNum, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, supLvl, supNum, ixVScope, refWznmMFeed, sref, ixVSubtype, srefsWznmMTag, refJTitle, Title, refJ, stdRefWznmMStub, shoRefWznmMStub, Avail, Active, srefsKOption FROM TblWznmMControl WHERE supRefWznmMControl = $1 ORDER BY supNum ASC", 1);
	createStatement("TblWznmMControl_loadSrfByRef", "SELECT sref FROM TblWznmMControl WHERE ref = $1", 1);
	createStatement("TblWznmMControl_loadSupByRef", "SELECT supRefWznmMControl FROM TblWznmMControl WHERE ref = $1", 1);
};

bool PgTblWznmMControl::loadRec(
			PGresult* res
			, WznmMControl** rec
		) {
	char* ptr;

	WznmMControl* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMControl();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmccontrol"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hknum"),
			PQfnumber(res, "hkixvsection"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "suprefwznmmcontrol"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "supnum"),
			PQfnumber(res, "ixvscope"),
			PQfnumber(res, "refwznmmfeed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvsubtype"),
			PQfnumber(res, "srefswznmmtag"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "stdrefwznmmstub"),
			PQfnumber(res, "shorefwznmmstub"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "active"),
			PQfnumber(res, "srefskoption")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmCControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->hkIxVSection = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->supRefWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->supNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->ixVScope = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->refWznmMFeed = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->ixVSubtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->srefsWznmMTag.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[18]));
		ptr = PQgetvalue(res, 0, fnum[19]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[20]); _rec->stdRefWznmMStub = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[21]); _rec->shoRefWznmMStub = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[22]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[22]));
		ptr = PQgetvalue(res, 0, fnum[23]); _rec->Active.assign(ptr, PQgetlength(res, 0, fnum[23]));
		ptr = PQgetvalue(res, 0, fnum[24]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[24]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMControl::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMControl& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMControl* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmccontrol"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hknum"),
			PQfnumber(res, "hkixvsection"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "suprefwznmmcontrol"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "supnum"),
			PQfnumber(res, "ixvscope"),
			PQfnumber(res, "refwznmmfeed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvsubtype"),
			PQfnumber(res, "srefswznmmtag"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "stdrefwznmmstub"),
			PQfnumber(res, "shorefwznmmstub"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "active"),
			PQfnumber(res, "srefskoption")
		};

		while (numread < numrow) {
			rec = new WznmMControl();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmCControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->hkIxVSection = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->supRefWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->supNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->ixVScope = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->refWznmMFeed = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->ixVSubtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->srefsWznmMTag.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[18]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[18]));
			ptr = PQgetvalue(res, numread, fnum[19]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[20]); rec->stdRefWznmMStub = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[21]); rec->shoRefWznmMStub = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[22]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[22]));
			ptr = PQgetvalue(res, numread, fnum[23]); rec->Active.assign(ptr, PQgetlength(res, numread, fnum[23]));
			ptr = PQgetvalue(res, numread, fnum[24]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[24]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMControl::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMControl** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMControl::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMControl::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMControl& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMControl::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMControl::loadRecBySQL(
			const string& sqlstr
			, WznmMControl** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMControl::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMControl& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMControl::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMControl::insertRec(
			WznmMControl* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmCControl = htonl64(rec->refWznmCControl);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkNum = htonl(rec->hkNum);
	uint _hkIxVSection = htonl(rec->hkIxVSection);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _supRefWznmMControl = htonl64(rec->supRefWznmMControl);
	usmallint _supLvl = htons(rec->supLvl);
	uint _supNum = htonl(rec->supNum);
	uint _ixVScope = htonl(rec->ixVScope);
	ubigint _refWznmMFeed = htonl64(rec->refWznmMFeed);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _stdRefWznmMStub = htonl64(rec->stdRefWznmMStub);
	ubigint _shoRefWznmMStub = htonl64(rec->shoRefWznmMStub);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmCControl,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkNum,
		(char*) &_hkIxVSection,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_supRefWznmMControl,
		(char*) &_supLvl,
		(char*) &_supNum,
		(char*) &_ixVScope,
		(char*) &_refWznmMFeed,
		rec->sref.c_str(),
		(char*) &_ixVSubtype,
		rec->srefsWznmMTag.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_refJ,
		(char*) &_stdRefWznmMStub,
		(char*) &_shoRefWznmMStub,
		rec->Avail.c_str(),
		rec->Active.c_str(),
		rec->srefsKOption.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMControl_insertRec", 24, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMControl::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMControl::insertRst(
			ListWznmMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMControl::updateRec(
			WznmMControl* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmCControl = htonl64(rec->refWznmCControl);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkNum = htonl(rec->hkNum);
	uint _hkIxVSection = htonl(rec->hkIxVSection);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _supRefWznmMControl = htonl64(rec->supRefWznmMControl);
	usmallint _supLvl = htons(rec->supLvl);
	uint _supNum = htonl(rec->supNum);
	uint _ixVScope = htonl(rec->ixVScope);
	ubigint _refWznmMFeed = htonl64(rec->refWznmMFeed);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _stdRefWznmMStub = htonl64(rec->stdRefWznmMStub);
	ubigint _shoRefWznmMStub = htonl64(rec->shoRefWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmCControl,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkNum,
		(char*) &_hkIxVSection,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_supRefWznmMControl,
		(char*) &_supLvl,
		(char*) &_supNum,
		(char*) &_ixVScope,
		(char*) &_refWznmMFeed,
		rec->sref.c_str(),
		(char*) &_ixVSubtype,
		rec->srefsWznmMTag.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_refJ,
		(char*) &_stdRefWznmMStub,
		(char*) &_shoRefWznmMStub,
		rec->Avail.c_str(),
		rec->Active.c_str(),
		rec->srefsKOption.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMControl_updateRec", 25, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMControl::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMControl::updateRst(
			ListWznmMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMControl::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmMControl_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMControl::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMControl::loadRecByRef(
			ubigint ref
			, WznmMControl** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMControl_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMControl::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmMControl_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblWznmMControl::loadRecByFed(
			ubigint refWznmMFeed
			, WznmMControl** rec
		) {
	ubigint _refWznmMFeed = htonl64(refWznmMFeed);

	const char* vals[] = {
		(char*) &_refWznmMFeed
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMControl_loadRecByFed", 1, vals, l, f, rec);
};

ubigint PgTblWznmMControl::loadRefsByClu(
			ubigint refWznmCControl
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCControl = htonl64(refWznmCControl);

	const char* vals[] = {
		(char*) &_refWznmCControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMControl_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMControl::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWznmMControl_loadRefsByHktHku", 2, vals, l, f, append, refs);
};

ubigint PgTblWznmMControl::loadRefsBySup(
			ubigint supRefWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWznmMControl = htonl64(supRefWznmMControl);

	const char* vals[] = {
		(char*) &_supRefWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMControl_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMControl::loadRstByClu(
			ubigint refWznmCControl
			, const bool append
			, ListWznmMControl& rst
		) {
	ubigint _refWznmCControl = htonl64(refWznmCControl);

	const char* vals[] = {
		(char*) &_refWznmCControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMControl_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmMControl::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWznmMControl& rst
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWznmMControl_loadRstByHktHku", 2, vals, l, f, append, rst);
};

ubigint PgTblWznmMControl::loadRstBySup(
			ubigint supRefWznmMControl
			, const bool append
			, ListWznmMControl& rst
		) {
	ubigint _supRefWznmMControl = htonl64(supRefWznmMControl);

	const char* vals[] = {
		(char*) &_supRefWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMControl_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWznmMControl::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMControl_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWznmMControl::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMControl
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmMControl_loadSupByRef", 1, vals, l, f, supRefWznmMControl);
};

#endif
