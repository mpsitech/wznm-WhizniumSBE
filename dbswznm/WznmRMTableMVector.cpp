/**
	* \file WznmRMTableMVector.cpp
	* database access for table TblWznmRMTableMVector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMTableMVector.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMTableMVector
 ******************************************************************************/

WznmRMTableMVector::WznmRMTableMVector(
			const ubigint ref
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const ubigint refWznmMVector
		) {

	this->ref = ref;
	this->refWznmMTable = refWznmMTable;
	this->refWznmMSubset = refWznmMSubset;
	this->refWznmMVector = refWznmMVector;
};

bool WznmRMTableMVector::operator==(
			const WznmRMTableMVector& comp
		) {
	return false;
};

bool WznmRMTableMVector::operator!=(
			const WznmRMTableMVector& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMTableMVector
 ******************************************************************************/

ListWznmRMTableMVector::ListWznmRMTableMVector() {
};

ListWznmRMTableMVector::ListWznmRMTableMVector(
			const ListWznmRMTableMVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMTableMVector(*(src.nodes[i]));
};

ListWznmRMTableMVector::~ListWznmRMTableMVector() {
	clear();
};

void ListWznmRMTableMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMTableMVector::size() const {
	return(nodes.size());
};

void ListWznmRMTableMVector::append(
			WznmRMTableMVector* rec
		) {
	nodes.push_back(rec);
};

WznmRMTableMVector* ListWznmRMTableMVector::operator[](
			const uint ix
		) {
	WznmRMTableMVector* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMTableMVector& ListWznmRMTableMVector::operator=(
			const ListWznmRMTableMVector& src
		) {
	WznmRMTableMVector* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMTableMVector(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMTableMVector::operator==(
			const ListWznmRMTableMVector& comp
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

bool ListWznmRMTableMVector::operator!=(
			const ListWznmRMTableMVector& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMTableMVector
 ******************************************************************************/

TblWznmRMTableMVector::TblWznmRMTableMVector() {
};

TblWznmRMTableMVector::~TblWznmRMTableMVector() {
};

bool TblWznmRMTableMVector::loadRecBySQL(
			const string& sqlstr
			, WznmRMTableMVector** rec
		) {
	return false;
};

ubigint TblWznmRMTableMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	return 0;
};

ubigint TblWznmRMTableMVector::insertRec(
			WznmRMTableMVector* rec
		) {
	return 0;
};

ubigint TblWznmRMTableMVector::insertNewRec(
			WznmRMTableMVector** rec
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const ubigint refWznmMVector
		) {
	ubigint retval = 0;
	WznmRMTableMVector* _rec = NULL;

	_rec = new WznmRMTableMVector(0, refWznmMTable, refWznmMSubset, refWznmMVector);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMTableMVector::appendNewRecToRst(
			ListWznmRMTableMVector& rst
			, WznmRMTableMVector** rec
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const ubigint refWznmMVector
		) {
	ubigint retval = 0;
	WznmRMTableMVector* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMTable, refWznmMSubset, refWznmMVector);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMTableMVector::insertRst(
			ListWznmRMTableMVector& rst
			, bool transact
		) {
};

void TblWznmRMTableMVector::updateRec(
			WznmRMTableMVector* rec
		) {
};

void TblWznmRMTableMVector::updateRst(
			ListWznmRMTableMVector& rst
			, bool transact
		) {
};

void TblWznmRMTableMVector::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMTableMVector::loadRecByRef(
			ubigint ref
			, WznmRMTableMVector** rec
		) {
	return false;
};

ubigint TblWznmRMTableMVector::loadRefsByVec(
			ubigint refWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMTableMVector::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	return 0;
};

ubigint TblWznmRMTableMVector::loadRstByVec(
			ubigint refWznmMVector
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	return 0;
};

ubigint TblWznmRMTableMVector::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	ubigint numload = 0;
	WznmRMTableMVector* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMTableMVector
 ******************************************************************************/

MyTblWznmRMTableMVector::MyTblWznmRMTableMVector() :
			TblWznmRMTableMVector()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMTableMVector::~MyTblWznmRMTableMVector() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMTableMVector::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMTableMVector (refWznmMTable, refWznmMSubset, refWznmMVector) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMTableMVector SET refWznmMTable = ?, refWznmMSubset = ?, refWznmMVector = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMTableMVector WHERE ref = ?", false);
};

bool MyTblWznmRMTableMVector::loadRecBySQL(
			const string& sqlstr
			, WznmRMTableMVector** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMTableMVector* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMTableMVector::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMTableMVector::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMTableMVector();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMTable = atoll((char*) dbrow[1]); else _rec->refWznmMTable = 0;
		if (dbrow[2]) _rec->refWznmMSubset = atoll((char*) dbrow[2]); else _rec->refWznmMSubset = 0;
		if (dbrow[3]) _rec->refWznmMVector = atoll((char*) dbrow[3]); else _rec->refWznmMVector = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMTableMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMTableMVector* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMTableMVector::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMTableMVector::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMTableMVector();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMTable = atoll((char*) dbrow[1]); else rec->refWznmMTable = 0;
			if (dbrow[2]) rec->refWznmMSubset = atoll((char*) dbrow[2]); else rec->refWznmMSubset = 0;
			if (dbrow[3]) rec->refWznmMVector = atoll((char*) dbrow[3]); else rec->refWznmMVector = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMTableMVector::insertRec(
			WznmRMTableMVector* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMSubset,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMVector,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMTableMVector::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMTableMVector::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMTableMVector::insertRst(
			ListWznmRMTableMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMTableMVector::updateRec(
			WznmRMTableMVector* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMSubset,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMVector,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMTableMVector::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMTableMVector::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMTableMVector::updateRst(
			ListWznmRMTableMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMTableMVector::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMTableMVector::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMTableMVector::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMTableMVector::loadRecByRef(
			ubigint ref
			, WznmRMTableMVector** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMTableMVector WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMTableMVector::loadRefsByVec(
			ubigint refWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMTableMVector WHERE refWznmMVector = " + to_string(refWznmMVector) + "", append, refs);
};

ubigint MyTblWznmRMTableMVector::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTable, refWznmMSubset, refWznmMVector FROM TblWznmRMTableMVector WHERE refWznmMTable = " + to_string(refWznmMTable) + "", append, rst);
};

ubigint MyTblWznmRMTableMVector::loadRstByVec(
			ubigint refWznmMVector
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTable, refWznmMSubset, refWznmMVector FROM TblWznmRMTableMVector WHERE refWznmMVector = " + to_string(refWznmMVector) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMTableMVector
 ******************************************************************************/

PgTblWznmRMTableMVector::PgTblWznmRMTableMVector() :
			TblWznmRMTableMVector()
			, PgTable()
		{
};

PgTblWznmRMTableMVector::~PgTblWznmRMTableMVector() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMTableMVector::initStatements() {
	createStatement("TblWznmRMTableMVector_insertRec", "INSERT INTO TblWznmRMTableMVector (refWznmMTable, refWznmMSubset, refWznmMVector) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmRMTableMVector_updateRec", "UPDATE TblWznmRMTableMVector SET refWznmMTable = $1, refWznmMSubset = $2, refWznmMVector = $3 WHERE ref = $4", 4);
	createStatement("TblWznmRMTableMVector_removeRecByRef", "DELETE FROM TblWznmRMTableMVector WHERE ref = $1", 1);

	createStatement("TblWznmRMTableMVector_loadRecByRef", "SELECT ref, refWznmMTable, refWznmMSubset, refWznmMVector FROM TblWznmRMTableMVector WHERE ref = $1", 1);
	createStatement("TblWznmRMTableMVector_loadRefsByVec", "SELECT ref FROM TblWznmRMTableMVector WHERE refWznmMVector = $1", 1);
	createStatement("TblWznmRMTableMVector_loadRstByTbl", "SELECT ref, refWznmMTable, refWznmMSubset, refWznmMVector FROM TblWznmRMTableMVector WHERE refWznmMTable = $1", 1);
	createStatement("TblWznmRMTableMVector_loadRstByVec", "SELECT ref, refWznmMTable, refWznmMSubset, refWznmMVector FROM TblWznmRMTableMVector WHERE refWznmMVector = $1", 1);
};

bool PgTblWznmRMTableMVector::loadRec(
			PGresult* res
			, WznmRMTableMVector** rec
		) {
	char* ptr;

	WznmRMTableMVector* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMTableMVector();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "refwznmmvector")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMVector = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMTableMVector::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMTableMVector* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "refwznmmvector")
		};

		while (numread < numrow) {
			rec = new WznmRMTableMVector();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMVector = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMTableMVector::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMTableMVector** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMTableMVector::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMTableMVector::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMTableMVector::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmRMTableMVector::loadRecBySQL(
			const string& sqlstr
			, WznmRMTableMVector** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMTableMVector::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMTableMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMTableMVector::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMTableMVector::insertRec(
			WznmRMTableMVector* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_refWznmMSubset,
		(char*) &_refWznmMVector
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMTableMVector_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMTableMVector::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMTableMVector::insertRst(
			ListWznmRMTableMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMTableMVector::updateRec(
			WznmRMTableMVector* rec
		) {
	PGresult* res;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_refWznmMSubset,
		(char*) &_refWznmMVector,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMTableMVector_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMTableMVector::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMTableMVector::updateRst(
			ListWznmRMTableMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMTableMVector::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMTableMVector_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMTableMVector::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMTableMVector::loadRecByRef(
			ubigint ref
			, WznmRMTableMVector** rec
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

	return loadRecByStmt("TblWznmRMTableMVector_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMTableMVector::loadRefsByVec(
			ubigint refWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVector = htonl64(refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMTableMVector_loadRefsByVec", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMTableMVector::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMTableMVector_loadRstByTbl", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmRMTableMVector::loadRstByVec(
			ubigint refWznmMVector
			, const bool append
			, ListWznmRMTableMVector& rst
		) {
	ubigint _refWznmMVector = htonl64(refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMTableMVector_loadRstByVec", 1, vals, l, f, append, rst);
};

#endif

