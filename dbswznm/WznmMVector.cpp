/**
	* \file WznmMVector.cpp
	* database access for table TblWznmMVector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMVector.h"

#include "WznmMVector_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMVector
 ******************************************************************************/

WznmMVector::WznmMVector(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refWznmMPreset
			, const string sref
			, const string osrefWznmKTaggrp
			, const string srefsKOption
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->refWznmMPreset = refWznmMPreset;
	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->srefsKOption = srefsKOption;
};

bool WznmMVector::operator==(
			const WznmMVector& comp
		) {
	return false;
};

bool WznmMVector::operator!=(
			const WznmMVector& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMVector
 ******************************************************************************/

ListWznmMVector::ListWznmMVector() {
};

ListWznmMVector::ListWznmMVector(
			const ListWznmMVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMVector(*(src.nodes[i]));
};

ListWznmMVector::~ListWznmMVector() {
	clear();
};

void ListWznmMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMVector::size() const {
	return(nodes.size());
};

void ListWznmMVector::append(
			WznmMVector* rec
		) {
	nodes.push_back(rec);
};

WznmMVector* ListWznmMVector::operator[](
			const uint ix
		) {
	WznmMVector* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMVector& ListWznmMVector::operator=(
			const ListWznmMVector& src
		) {
	WznmMVector* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMVector(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMVector::operator==(
			const ListWznmMVector& comp
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

bool ListWznmMVector::operator!=(
			const ListWznmMVector& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMVector
 ******************************************************************************/

TblWznmMVector::TblWznmMVector() {
};

TblWznmMVector::~TblWznmMVector() {
};

bool TblWznmMVector::loadRecBySQL(
			const string& sqlstr
			, WznmMVector** rec
		) {
	return false;
};

ubigint TblWznmMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVector& rst
		) {
	return 0;
};

ubigint TblWznmMVector::insertRec(
			WznmMVector* rec
		) {
	return 0;
};

ubigint TblWznmMVector::insertNewRec(
			WznmMVector** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refWznmMPreset
			, const string sref
			, const string osrefWznmKTaggrp
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WznmMVector* _rec = NULL;

	_rec = new WznmMVector(0, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMVector::appendNewRecToRst(
			ListWznmMVector& rst
			, WznmMVector** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refWznmMPreset
			, const string sref
			, const string osrefWznmKTaggrp
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WznmMVector* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMVector::insertRst(
			ListWznmMVector& rst
			, bool transact
		) {
};

void TblWznmMVector::updateRec(
			WznmMVector* rec
		) {
};

void TblWznmMVector::updateRst(
			ListWznmMVector& rst
			, bool transact
		) {
};

void TblWznmMVector::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMVector::loadRecByRef(
			ubigint ref
			, WznmMVector** rec
		) {
	return false;
};

bool TblWznmMVector::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMVector** rec
		) {
	return false;
};

bool TblWznmMVector::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMVector::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMVector::loadRefsByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMVector::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMVector& rst
		) {
	return 0;
};

ubigint TblWznmMVector::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMVector& rst
		) {
	return 0;
};

bool TblWznmMVector::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMVector::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMVector& rst
		) {
	ubigint numload = 0;
	WznmMVector* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMVector
 ******************************************************************************/

MyTblWznmMVector::MyTblWznmMVector() :
			TblWznmMVector()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMVector::~MyTblWznmMVector() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMVector::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMVector (ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMVector SET ixVBasetype = ?, refWznmMVersion = ?, hkIxVTbl = ?, hkUref = ?, refWznmMPreset = ?, sref = ?, osrefWznmKTaggrp = ?, srefsKOption = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMVector WHERE ref = ?", false);
};

bool MyTblWznmMVector::loadRecBySQL(
			const string& sqlstr
			, WznmMVector** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMVector* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVector::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVector::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMVector();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->hkIxVTbl = atol((char*) dbrow[3]); else _rec->hkIxVTbl = 0;
		if (dbrow[4]) _rec->hkUref = atoll((char*) dbrow[4]); else _rec->hkUref = 0;
		if (dbrow[5]) _rec->refWznmMPreset = atoll((char*) dbrow[5]); else _rec->refWznmMPreset = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->osrefWznmKTaggrp.assign(dbrow[7], dblengths[7]); else _rec->osrefWznmKTaggrp = "";
		if (dbrow[8]) _rec->srefsKOption.assign(dbrow[8], dblengths[8]); else _rec->srefsKOption = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVector& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMVector* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVector::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVector::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMVector();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->hkIxVTbl = atol((char*) dbrow[3]); else rec->hkIxVTbl = 0;
			if (dbrow[4]) rec->hkUref = atoll((char*) dbrow[4]); else rec->hkUref = 0;
			if (dbrow[5]) rec->refWznmMPreset = atoll((char*) dbrow[5]); else rec->refWznmMPreset = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->osrefWznmKTaggrp.assign(dbrow[7], dblengths[7]); else rec->osrefWznmKTaggrp = "";
			if (dbrow[8]) rec->srefsKOption.assign(dbrow[8], dblengths[8]); else rec->srefsKOption = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMVector::insertRec(
			WznmMVector* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->sref.length();
	l[6] = rec->osrefWznmKTaggrp.length();
	l[7] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMPreset,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefWznmKTaggrp.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMVector::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMVector::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMVector::insertRst(
			ListWznmMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMVector::updateRec(
			WznmMVector* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->sref.length();
	l[6] = rec->osrefWznmKTaggrp.length();
	l[7] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMPreset,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefWznmKTaggrp.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMVector::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMVector::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMVector::updateRst(
			ListWznmMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMVector::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMVector::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMVector::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMVector::loadRecByRef(
			ubigint ref
			, WznmMVector** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMVector WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMVector::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMVector** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE refWznmMPreset = " + to_string(refWznmMPreset) + "", rec);
};

bool MyTblWznmMVector::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMVector::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, refs);
};

ubigint MyTblWznmMVector::loadRefsByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMVector WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + "", append, refs);
};

ubigint MyTblWznmMVector::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMVector& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWznmMVector::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMVector& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMVector::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMVector WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMVector
 ******************************************************************************/

PgTblWznmMVector::PgTblWznmMVector() :
			TblWznmMVector()
			, PgTable()
		{
};

PgTblWznmMVector::~PgTblWznmMVector() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMVector::initStatements() {
	createStatement("TblWznmMVector_insertRec", "INSERT INTO TblWznmMVector (ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMVector_updateRec", "UPDATE TblWznmMVector SET ixVBasetype = $1, refWznmMVersion = $2, hkIxVTbl = $3, hkUref = $4, refWznmMPreset = $5, sref = $6, osrefWznmKTaggrp = $7, srefsKOption = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMVector_removeRecByRef", "DELETE FROM TblWznmMVector WHERE ref = $1", 1);

	createStatement("TblWznmMVector_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE ref = $1", 1);
	createStatement("TblWznmMVector_loadRecByPst", "SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE refWznmMPreset = $1", 1);
	createStatement("TblWznmMVector_loadRefByVerSrf", "SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMVector_loadRefsByHktHku", "SELECT ref FROM TblWznmMVector WHERE hkIxVTbl = $1 AND hkUref = $2", 2);
	createStatement("TblWznmMVector_loadRefsByTypVer", "SELECT ref FROM TblWznmMVector WHERE ixVBasetype = $1 AND refWznmMVersion = $2", 2);
	createStatement("TblWznmMVector_loadRstByTypVer", "SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE ixVBasetype = $1 AND refWznmMVersion = $2 ORDER BY sref ASC", 2);
	createStatement("TblWznmMVector_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, hkIxVTbl, hkUref, refWznmMPreset, sref, osrefWznmKTaggrp, srefsKOption FROM TblWznmMVector WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMVector_loadSrfByRef", "SELECT sref FROM TblWznmMVector WHERE ref = $1", 1);
};

bool PgTblWznmMVector::loadRec(
			PGresult* res
			, WznmMVector** rec
		) {
	char* ptr;

	WznmMVector* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMVector();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "osrefwznmktaggrp"),
			PQfnumber(res, "srefskoption")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->osrefWznmKTaggrp.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMVector::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMVector& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMVector* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "osrefwznmktaggrp"),
			PQfnumber(res, "srefskoption")
		};

		while (numread < numrow) {
			rec = new WznmMVector();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->osrefWznmKTaggrp.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMVector::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMVector** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVector::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVector::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMVector& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVector::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMVector::loadRecBySQL(
			const string& sqlstr
			, WznmMVector** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVector::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVector& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVector::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMVector::insertRec(
			WznmMVector* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refWznmMPreset,
		rec->sref.c_str(),
		rec->osrefWznmKTaggrp.c_str(),
		rec->srefsKOption.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMVector_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVector::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMVector::insertRst(
			ListWznmMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMVector::updateRec(
			WznmMVector* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refWznmMPreset,
		rec->sref.c_str(),
		rec->osrefWznmKTaggrp.c_str(),
		rec->srefsKOption.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMVector_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVector::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMVector::updateRst(
			ListWznmMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMVector::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMVector_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVector::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMVector::loadRecByRef(
			ubigint ref
			, WznmMVector** rec
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

	return loadRecByStmt("TblWznmMVector_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMVector::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMVector** rec
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);

	const char* vals[] = {
		(char*) &_refWznmMPreset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMVector_loadRecByPst", 1, vals, l, f, rec);
};

bool PgTblWznmMVector::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWznmMVector_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMVector::loadRefsByHktHku(
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

	return loadRefsByStmt("TblWznmMVector_loadRefsByHktHku", 2, vals, l, f, append, refs);
};

ubigint PgTblWznmMVector::loadRefsByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWznmMVector_loadRefsByTypVer", 2, vals, l, f, append, refs);
};

ubigint PgTblWznmMVector::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMVector& rst
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWznmMVector_loadRstByTypVer", 2, vals, l, f, append, rst);
};

ubigint PgTblWznmMVector::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMVector& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMVector_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMVector::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMVector_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

