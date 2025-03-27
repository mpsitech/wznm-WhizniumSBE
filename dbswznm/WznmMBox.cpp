/**
	* \file WznmMBox.cpp
	* database access for table TblWznmMBox (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmMBox.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMBox
 ******************************************************************************/

WznmMBox::WznmMBox(
			const ubigint ref
			, const ubigint refWznmMSheet
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const smallint x
			, const smallint y
		) :
			ref(ref)
			, refWznmMSheet(refWznmMSheet)
			, unvIxWznmVMaintable(unvIxWznmVMaintable)
			, unvUref(unvUref)
			, x(x)
			, y(y)
		{
};

bool WznmMBox::operator==(
			const WznmMBox& comp
		) {
	return false;
};

bool WznmMBox::operator!=(
			const WznmMBox& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMBox
 ******************************************************************************/

ListWznmMBox::ListWznmMBox() {
};

ListWznmMBox::ListWznmMBox(
			const ListWznmMBox& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMBox(*(src.nodes[i]));
};

ListWznmMBox::~ListWznmMBox() {
	clear();
};

void ListWznmMBox::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMBox::size() const {
	return(nodes.size());
};

void ListWznmMBox::append(
			WznmMBox* rec
		) {
	nodes.push_back(rec);
};

WznmMBox* ListWznmMBox::operator[](
			const uint ix
		) {
	WznmMBox* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMBox& ListWznmMBox::operator=(
			const ListWznmMBox& src
		) {
	WznmMBox* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMBox(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMBox::operator==(
			const ListWznmMBox& comp
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

bool ListWznmMBox::operator!=(
			const ListWznmMBox& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMBox
 ******************************************************************************/

TblWznmMBox::TblWznmMBox() {
};

TblWznmMBox::~TblWznmMBox() {
};

bool TblWznmMBox::loadRecBySQL(
			const string& sqlstr
			, WznmMBox** rec
		) {
	return false;
};

ubigint TblWznmMBox::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMBox& rst
		) {
	return 0;
};

ubigint TblWznmMBox::insertRec(
			WznmMBox* rec
		) {
	return 0;
};

ubigint TblWznmMBox::insertNewRec(
			WznmMBox** rec
			, const ubigint refWznmMSheet
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const smallint x
			, const smallint y
		) {
	ubigint retval = 0;
	WznmMBox* _rec = NULL;

	_rec = new WznmMBox(0, refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMBox::appendNewRecToRst(
			ListWznmMBox& rst
			, WznmMBox** rec
			, const ubigint refWznmMSheet
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const smallint x
			, const smallint y
		) {
	ubigint retval = 0;
	WznmMBox* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMBox::insertRst(
			ListWznmMBox& rst
			, bool transact
		) {
};

void TblWznmMBox::updateRec(
			WznmMBox* rec
		) {
};

void TblWznmMBox::updateRst(
			ListWznmMBox& rst
			, bool transact
		) {
};

void TblWznmMBox::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMBox::loadRecByRef(
			ubigint ref
			, WznmMBox** rec
		) {
	return false;
};

ubigint TblWznmMBox::loadRefsBySht(
			ubigint refWznmMSheet
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMBox::loadRstBySht(
			ubigint refWznmMSheet
			, const bool append
			, ListWznmMBox& rst
		) {
	return 0;
};

ubigint TblWznmMBox::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMBox& rst
		) {
	ubigint numload = 0;
	WznmMBox* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMBox
 ******************************************************************************/

MyTblWznmMBox::MyTblWznmMBox() :
			TblWznmMBox()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMBox::~MyTblWznmMBox() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMBox::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMBox (refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMBox SET refWznmMSheet = ?, unvIxWznmVMaintable = ?, unvUref = ?, x = ?, y = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMBox WHERE ref = ?", false);
};

bool MyTblWznmMBox::loadRecBySQL(
			const string& sqlstr
			, WznmMBox** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMBox* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMBox::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMBox::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmMBox();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMSheet = atoll((char*) dbrow[1]); else _rec->refWznmMSheet = 0;
		if (dbrow[2]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->x = atoi((char*) dbrow[4]); else _rec->x = 0;
		if (dbrow[5]) _rec->y = atoi((char*) dbrow[5]); else _rec->y = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMBox::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMBox& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMBox* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMBox::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMBox::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmMBox();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMSheet = atoll((char*) dbrow[1]); else rec->refWznmMSheet = 0;
			if (dbrow[2]) rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else rec->unvIxWznmVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->x = atoi((char*) dbrow[4]); else rec->x = 0;
			if (dbrow[5]) rec->y = atoi((char*) dbrow[5]); else rec->y = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMBox::insertRec(
			WznmMBox* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSheet,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindSmallint(&rec->x,&(l[3]),&(n[3]),&(e[3])),
		bindSmallint(&rec->y,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMBox::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMBox::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMBox::insertRst(
			ListWznmMBox& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMBox::updateRec(
			WznmMBox* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSheet,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindSmallint(&rec->x,&(l[3]),&(n[3]),&(e[3])),
		bindSmallint(&rec->y,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMBox::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMBox::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMBox::updateRst(
			ListWznmMBox& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMBox::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMBox::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMBox::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMBox::loadRecByRef(
			ubigint ref
			, WznmMBox** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMBox WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMBox::loadRefsBySht(
			ubigint refWznmMSheet
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMBox WHERE refWznmMSheet = " + to_string(refWznmMSheet) + "", append, refs);
};

ubigint MyTblWznmMBox::loadRstBySht(
			ubigint refWznmMSheet
			, const bool append
			, ListWznmMBox& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y FROM TblWznmMBox WHERE refWznmMSheet = " + to_string(refWznmMSheet) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMBox
 ******************************************************************************/

PgTblWznmMBox::PgTblWznmMBox() :
			TblWznmMBox()
			, PgTable()
		{
};

PgTblWznmMBox::~PgTblWznmMBox() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMBox::initStatements() {
	createStatement("TblWznmMBox_insertRec", "INSERT INTO TblWznmMBox (refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMBox_updateRec", "UPDATE TblWznmMBox SET refWznmMSheet = $1, unvIxWznmVMaintable = $2, unvUref = $3, x = $4, y = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMBox_removeRecByRef", "DELETE FROM TblWznmMBox WHERE ref = $1", 1);

	createStatement("TblWznmMBox_loadRecByRef", "SELECT ref, refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y FROM TblWznmMBox WHERE ref = $1", 1);
	createStatement("TblWznmMBox_loadRefsBySht", "SELECT ref FROM TblWznmMBox WHERE refWznmMSheet = $1", 1);
	createStatement("TblWznmMBox_loadRstBySht", "SELECT ref, refWznmMSheet, unvIxWznmVMaintable, unvUref, x, y FROM TblWznmMBox WHERE refWznmMSheet = $1", 1);
};

bool PgTblWznmMBox::loadRec(
			PGresult* res
			, WznmMBox** rec
		) {
	char* ptr;

	WznmMBox* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMBox();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsheet"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMSheet = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->y = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMBox::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMBox& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMBox* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsheet"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new WznmMBox();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMSheet = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->y = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMBox::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMBox** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBox::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMBox::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMBox& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBox::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMBox::loadRecBySQL(
			const string& sqlstr
			, WznmMBox** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBox::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMBox::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMBox& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBox::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMBox::insertRec(
			WznmMBox* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMSheet = htonl64(rec->refWznmMSheet);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	smallint _x = htons(rec->x);
	smallint _y = htons(rec->y);

	const char* vals[] = {
		(char*) &_refWznmMSheet,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_x,
		(char*) &_y
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMBox_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBox::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMBox::insertRst(
			ListWznmMBox& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMBox::updateRec(
			WznmMBox* rec
		) {
	PGresult* res;

	ubigint _refWznmMSheet = htonl64(rec->refWznmMSheet);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	smallint _x = htons(rec->x);
	smallint _y = htons(rec->y);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMSheet,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_x,
		(char*) &_y,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMBox_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMBox::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMBox::updateRst(
			ListWznmMBox& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMBox::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMBox_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMBox::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMBox::loadRecByRef(
			ubigint ref
			, WznmMBox** rec
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

	return loadRecByStmt("TblWznmMBox_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMBox::loadRefsBySht(
			ubigint refWznmMSheet
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMSheet = htonl64(refWznmMSheet);

	const char* vals[] = {
		(char*) &_refWznmMSheet
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMBox_loadRefsBySht", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMBox::loadRstBySht(
			ubigint refWznmMSheet
			, const bool append
			, ListWznmMBox& rst
		) {
	ubigint _refWznmMSheet = htonl64(refWznmMSheet);

	const char* vals[] = {
		(char*) &_refWznmMSheet
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMBox_loadRstBySht", 1, vals, l, f, append, rst);
};

#endif
