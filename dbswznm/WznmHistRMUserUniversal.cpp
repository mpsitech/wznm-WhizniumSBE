/**
	* \file WznmHistRMUserUniversal.cpp
	* database access for table TblWznmHistRMUserUniversal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmHistRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmHistRMUserUniversal
 ******************************************************************************/

WznmHistRMUserUniversal::WznmHistRMUserUniversal(
			const ubigint ref
			, const ubigint refWznmMUser
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVCard
			, const uint ixWznmVPreset
			, const uint preIxWznmVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refWznmMUser = refWznmMUser;
	this->unvIxWznmVMaintable = unvIxWznmVMaintable;
	this->unvUref = unvUref;
	this->ixWznmVCard = ixWznmVCard;
	this->ixWznmVPreset = ixWznmVPreset;
	this->preIxWznmVMaintable = preIxWznmVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool WznmHistRMUserUniversal::operator==(
			const WznmHistRMUserUniversal& comp
		) {
	return false;
};

bool WznmHistRMUserUniversal::operator!=(
			const WznmHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmHistRMUserUniversal
 ******************************************************************************/

ListWznmHistRMUserUniversal::ListWznmHistRMUserUniversal() {
};

ListWznmHistRMUserUniversal::ListWznmHistRMUserUniversal(
			const ListWznmHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmHistRMUserUniversal(*(src.nodes[i]));
};

ListWznmHistRMUserUniversal::~ListWznmHistRMUserUniversal() {
	clear();
};

void ListWznmHistRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWznmHistRMUserUniversal::append(
			WznmHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WznmHistRMUserUniversal* ListWznmHistRMUserUniversal::operator[](
			const uint ix
		) {
	WznmHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmHistRMUserUniversal& ListWznmHistRMUserUniversal::operator=(
			const ListWznmHistRMUserUniversal& src
		) {
	WznmHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmHistRMUserUniversal::operator==(
			const ListWznmHistRMUserUniversal& comp
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

bool ListWznmHistRMUserUniversal::operator!=(
			const ListWznmHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmHistRMUserUniversal
 ******************************************************************************/

TblWznmHistRMUserUniversal::TblWznmHistRMUserUniversal() {
};

TblWznmHistRMUserUniversal::~TblWznmHistRMUserUniversal() {
};

bool TblWznmHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWznmHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWznmHistRMUserUniversal::insertRec(
			WznmHistRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWznmHistRMUserUniversal::insertNewRec(
			WznmHistRMUserUniversal** rec
			, const ubigint refWznmMUser
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVCard
			, const uint ixWznmVPreset
			, const uint preIxWznmVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WznmHistRMUserUniversal* _rec = NULL;

	_rec = new WznmHistRMUserUniversal(0, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmHistRMUserUniversal::appendNewRecToRst(
			ListWznmHistRMUserUniversal& rst
			, WznmHistRMUserUniversal** rec
			, const ubigint refWznmMUser
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVCard
			, const uint ixWznmVPreset
			, const uint preIxWznmVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WznmHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmHistRMUserUniversal::insertRst(
			ListWznmHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWznmHistRMUserUniversal::updateRec(
			WznmHistRMUserUniversal* rec
		) {
};

void TblWznmHistRMUserUniversal::updateRst(
			ListWznmHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWznmHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WznmHistRMUserUniversal** rec
		) {
	return false;
};

bool TblWznmHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, uint ixWznmVCard
			, WznmHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWznmHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, uint ixWznmVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblWznmHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWznmMUser
			, uint ixWznmVCard
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblWznmHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return false;
};

ubigint TblWznmHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WznmHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmHistRMUserUniversal
 ******************************************************************************/

MyTblWznmHistRMUserUniversal::MyTblWznmHistRMUserUniversal() :
			TblWznmHistRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmHistRMUserUniversal::~MyTblWznmHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmHistRMUserUniversal (refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmHistRMUserUniversal SET refWznmMUser = ?, unvIxWznmVMaintable = ?, unvUref = ?, ixWznmVCard = ?, ixWznmVPreset = ?, preIxWznmVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWznmHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmHistRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmHistRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUser = atoll((char*) dbrow[1]); else _rec->refWznmMUser = 0;
		if (dbrow[2]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWznmVCard = atol((char*) dbrow[4]); else _rec->ixWznmVCard = 0;
		if (dbrow[5]) _rec->ixWznmVPreset = atol((char*) dbrow[5]); else _rec->ixWznmVPreset = 0;
		if (dbrow[6]) _rec->preIxWznmVMaintable = atol((char*) dbrow[6]); else _rec->preIxWznmVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmHistRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmHistRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUser = atoll((char*) dbrow[1]); else rec->refWznmMUser = 0;
			if (dbrow[2]) rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else rec->unvIxWznmVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWznmVCard = atol((char*) dbrow[4]); else rec->ixWznmVCard = 0;
			if (dbrow[5]) rec->ixWznmVPreset = atol((char*) dbrow[5]); else rec->ixWznmVPreset = 0;
			if (dbrow[6]) rec->preIxWznmVMaintable = atol((char*) dbrow[6]); else rec->preIxWznmVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmHistRMUserUniversal::insertRec(
			WznmHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWznmVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmHistRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmHistRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmHistRMUserUniversal::insertRst(
			ListWznmHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmHistRMUserUniversal::updateRec(
			WznmHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWznmVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmHistRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmHistRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmHistRMUserUniversal::updateRst(
			ListWznmHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmHistRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmHistRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WznmHistRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, uint ixWznmVCard
			, WznmHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start FROM TblWznmHistRMUserUniversal WHERE refWznmMUser = " + to_string(refWznmMUser) + " AND unvIxWznmVMaintable = " + to_string(unvIxWznmVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixWznmVCard = " + to_string(ixWznmVCard) + "", rec);
};

ubigint MyTblWznmHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, uint ixWznmVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRefsBySQL("SELECT ref FROM TblWznmHistRMUserUniversal WHERE refWznmMUser = " + to_string(refWznmMUser) + " AND unvIxWznmVMaintable = " + to_string(unvIxWznmVMaintable) + " AND ixWznmVCard = " + to_string(ixWznmVCard) + " ORDER BY start DESC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, refs);
};

ubigint MyTblWznmHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWznmMUser
			, uint ixWznmVCard
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start FROM TblWznmHistRMUserUniversal WHERE refWznmMUser = " + to_string(refWznmMUser) + " AND ixWznmVCard = " + to_string(ixWznmVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblWznmHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return loadRefBySQL("SELECT unvUref FROM TblWznmHistRMUserUniversal WHERE ref = " + to_string(ref) + "", unvUref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmHistRMUserUniversal
 ******************************************************************************/

PgTblWznmHistRMUserUniversal::PgTblWznmHistRMUserUniversal() :
			TblWznmHistRMUserUniversal()
			, PgTable()
		{
};

PgTblWznmHistRMUserUniversal::~PgTblWznmHistRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmHistRMUserUniversal::initStatements() {
	createStatement("TblWznmHistRMUserUniversal_insertRec", "INSERT INTO TblWznmHistRMUserUniversal (refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmHistRMUserUniversal_updateRec", "UPDATE TblWznmHistRMUserUniversal SET refWznmMUser = $1, unvIxWznmVMaintable = $2, unvUref = $3, ixWznmVCard = $4, ixWznmVPreset = $5, preIxWznmVMaintable = $6, preUref = $7, start = $8 WHERE ref = $9", 9);
	createStatement("TblWznmHistRMUserUniversal_removeRecByRef", "DELETE FROM TblWznmHistRMUserUniversal WHERE ref = $1", 1);

	createStatement("TblWznmHistRMUserUniversal_loadRecByRef", "SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start FROM TblWznmHistRMUserUniversal WHERE ref = $1", 1);
	createStatement("TblWznmHistRMUserUniversal_loadRecByUsrMtbUnvCrd", "SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start FROM TblWznmHistRMUserUniversal WHERE refWznmMUser = $1 AND unvIxWznmVMaintable = $2 AND unvUref = $3 AND ixWznmVCard = $4", 4);
	createStatement("TblWznmHistRMUserUniversal_loadRefsByUsrMtbCrd", "SELECT ref FROM TblWznmHistRMUserUniversal WHERE refWznmMUser = $1 AND unvIxWznmVMaintable = $2 AND ixWznmVCard = $3 ORDER BY start DESC OFFSET $4 LIMIT $5", 5);
	createStatement("TblWznmHistRMUserUniversal_loadRstByUsrCrd", "SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, start FROM TblWznmHistRMUserUniversal WHERE refWznmMUser = $1 AND ixWznmVCard = $2 ORDER BY start DESC", 2);
	createStatement("TblWznmHistRMUserUniversal_loadUnuByRef", "SELECT unvUref FROM TblWznmHistRMUserUniversal WHERE ref = $1", 1);
};

bool PgTblWznmHistRMUserUniversal::loadRec(
			PGresult* res
			, WznmHistRMUserUniversal** rec
		) {
	char* ptr;

	WznmHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmHistRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwznmvcard"),
			PQfnumber(res, "ixwznmvpreset"),
			PQfnumber(res, "preixwznmvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWznmVPreset = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->preIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->preUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmHistRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmHistRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwznmvcard"),
			PQfnumber(res, "ixwznmvpreset"),
			PQfnumber(res, "preixwznmvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new WznmHistRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWznmVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWznmVPreset = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->preIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->preUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmHistRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmHistRMUserUniversal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmHistRMUserUniversal::insertRec(
			WznmHistRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWznmVCard = htonl(rec->ixWznmVCard);
	uint _ixWznmVPreset = htonl(rec->ixWznmVPreset);
	uint _preIxWznmVMaintable = htonl(rec->preIxWznmVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWznmVCard,
		(char*) &_ixWznmVPreset,
		(char*) &_preIxWznmVMaintable,
		(char*) &_preUref,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmHistRMUserUniversal_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmHistRMUserUniversal::insertRst(
			ListWznmHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmHistRMUserUniversal::updateRec(
			WznmHistRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWznmVCard = htonl(rec->ixWznmVCard);
	uint _ixWznmVPreset = htonl(rec->ixWznmVPreset);
	uint _preIxWznmVMaintable = htonl(rec->preIxWznmVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWznmVCard,
		(char*) &_ixWznmVPreset,
		(char*) &_preIxWznmVMaintable,
		(char*) &_preUref,
		(char*) &_start,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmHistRMUserUniversal_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmHistRMUserUniversal::updateRst(
			ListWznmHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmHistRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmHistRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmHistRMUserUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WznmHistRMUserUniversal** rec
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

	return loadRecByStmt("TblWznmHistRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, uint ixWznmVCard
			, WznmHistRMUserUniversal** rec
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(unvUref);
	uint _ixWznmVCard = htonl(ixWznmVCard);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWznmVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1,1,1};

	return loadRecByStmt("TblWznmHistRMUserUniversal_loadRecByUsrMtbUnvCrd", 4, vals, l, f, rec);
};

ubigint PgTblWznmHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, uint ixWznmVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(unvIxWznmVMaintable);
	uint _ixWznmVCard = htonl(ixWznmVCard);
	ubigint _offset = htonl64(offset);

	ubigint _limit = htonl64(limit);
	char* _limitptr = NULL;
	int _limitl = 0;

	if (limit != 0) {
		_limitptr = (char*) &_limit;
		_limitl = sizeof(ubigint);
	};

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_ixWznmVCard,
		(char*) &_offset,
		_limitptr
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		_limitl
	};
	const int f[] = {1,1,1,1,1};

	return loadRefsByStmt("TblWznmHistRMUserUniversal_loadRefsByUsrMtbCrd", 3, vals, l, f, append, refs);
};

ubigint PgTblWznmHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWznmMUser
			, uint ixWznmVCard
			, const bool append
			, ListWznmHistRMUserUniversal& rst
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);
	uint _ixWznmVCard = htonl(ixWznmVCard);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_ixWznmVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWznmHistRMUserUniversal_loadRstByUsrCrd", 2, vals, l, f, append, rst);
};

bool PgTblWznmHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmHistRMUserUniversal_loadUnuByRef", 1, vals, l, f, unvUref);
};

#endif
