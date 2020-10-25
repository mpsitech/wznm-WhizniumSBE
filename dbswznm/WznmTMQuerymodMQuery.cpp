/**
	* \file WznmTMQuerymodMQuery.cpp
	* database access for table TblWznmTMQuerymodMQuery (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmTMQuerymodMQuery.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmTMQuerymodMQuery
 ******************************************************************************/

WznmTMQuerymodMQuery::WznmTMQuerymodMQuery(
			const ubigint ref
			, const ubigint refWznmMQuerymod
			, const ubigint refR
		) {

	this->ref = ref;
	this->refWznmMQuerymod = refWznmMQuerymod;
	this->refR = refR;
};

bool WznmTMQuerymodMQuery::operator==(
			const WznmTMQuerymodMQuery& comp
		) {
	return false;
};

bool WznmTMQuerymodMQuery::operator!=(
			const WznmTMQuerymodMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmTMQuerymodMQuery
 ******************************************************************************/

ListWznmTMQuerymodMQuery::ListWznmTMQuerymodMQuery() {
};

ListWznmTMQuerymodMQuery::ListWznmTMQuerymodMQuery(
			const ListWznmTMQuerymodMQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmTMQuerymodMQuery(*(src.nodes[i]));
};

ListWznmTMQuerymodMQuery::~ListWznmTMQuerymodMQuery() {
	clear();
};

void ListWznmTMQuerymodMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmTMQuerymodMQuery::size() const {
	return(nodes.size());
};

void ListWznmTMQuerymodMQuery::append(
			WznmTMQuerymodMQuery* rec
		) {
	nodes.push_back(rec);
};

WznmTMQuerymodMQuery* ListWznmTMQuerymodMQuery::operator[](
			const uint ix
		) {
	WznmTMQuerymodMQuery* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmTMQuerymodMQuery& ListWznmTMQuerymodMQuery::operator=(
			const ListWznmTMQuerymodMQuery& src
		) {
	WznmTMQuerymodMQuery* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmTMQuerymodMQuery(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmTMQuerymodMQuery::operator==(
			const ListWznmTMQuerymodMQuery& comp
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

bool ListWznmTMQuerymodMQuery::operator!=(
			const ListWznmTMQuerymodMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmTMQuerymodMQuery
 ******************************************************************************/

TblWznmTMQuerymodMQuery::TblWznmTMQuerymodMQuery() {
};

TblWznmTMQuerymodMQuery::~TblWznmTMQuerymodMQuery() {
};

bool TblWznmTMQuerymodMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmTMQuerymodMQuery** rec
		) {
	return false;
};

ubigint TblWznmTMQuerymodMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	return 0;
};

ubigint TblWznmTMQuerymodMQuery::insertRec(
			WznmTMQuerymodMQuery* rec
		) {
	return 0;
};

ubigint TblWznmTMQuerymodMQuery::insertNewRec(
			WznmTMQuerymodMQuery** rec
			, const ubigint refWznmMQuerymod
			, const ubigint refR
		) {
	ubigint retval = 0;
	WznmTMQuerymodMQuery* _rec = NULL;

	_rec = new WznmTMQuerymodMQuery(0, refWznmMQuerymod, refR);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmTMQuerymodMQuery::appendNewRecToRst(
			ListWznmTMQuerymodMQuery& rst
			, WznmTMQuerymodMQuery** rec
			, const ubigint refWznmMQuerymod
			, const ubigint refR
		) {
	ubigint retval = 0;
	WznmTMQuerymodMQuery* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMQuerymod, refR);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmTMQuerymodMQuery::insertRst(
			ListWznmTMQuerymodMQuery& rst
			, bool transact
		) {
};

void TblWznmTMQuerymodMQuery::updateRec(
			WznmTMQuerymodMQuery* rec
		) {
};

void TblWznmTMQuerymodMQuery::updateRst(
			ListWznmTMQuerymodMQuery& rst
			, bool transact
		) {
};

void TblWznmTMQuerymodMQuery::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmTMQuerymodMQuery::loadRecByRef(
			ubigint ref
			, WznmTMQuerymodMQuery** rec
		) {
	return false;
};

ubigint TblWznmTMQuerymodMQuery::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmTMQuerymodMQuery::loadRstByR(
			ubigint refR
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	return 0;
};

ubigint TblWznmTMQuerymodMQuery::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	ubigint numload = 0;
	WznmTMQuerymodMQuery* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmTMQuerymodMQuery
 ******************************************************************************/

MyTblWznmTMQuerymodMQuery::MyTblWznmTMQuerymodMQuery() :
			TblWznmTMQuerymodMQuery()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmTMQuerymodMQuery::~MyTblWznmTMQuerymodMQuery() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmTMQuerymodMQuery::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmTMQuerymodMQuery (refWznmMQuerymod, refR) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmTMQuerymodMQuery SET refWznmMQuerymod = ?, refR = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmTMQuerymodMQuery WHERE ref = ?", false);
};

bool MyTblWznmTMQuerymodMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmTMQuerymodMQuery** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmTMQuerymodMQuery* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmTMQuerymodMQuery::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmTMQuerymodMQuery::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmTMQuerymodMQuery();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMQuerymod = atoll((char*) dbrow[1]); else _rec->refWznmMQuerymod = 0;
		if (dbrow[2]) _rec->refR = atoll((char*) dbrow[2]); else _rec->refR = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmTMQuerymodMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmTMQuerymodMQuery* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmTMQuerymodMQuery::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmTMQuerymodMQuery::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmTMQuerymodMQuery();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMQuerymod = atoll((char*) dbrow[1]); else rec->refWznmMQuerymod = 0;
			if (dbrow[2]) rec->refR = atoll((char*) dbrow[2]); else rec->refR = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmTMQuerymodMQuery::insertRec(
			WznmTMQuerymodMQuery* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuerymod,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refR,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmTMQuerymodMQuery::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmTMQuerymodMQuery::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmTMQuerymodMQuery::insertRst(
			ListWznmTMQuerymodMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmTMQuerymodMQuery::updateRec(
			WznmTMQuerymodMQuery* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuerymod,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refR,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmTMQuerymodMQuery::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmTMQuerymodMQuery::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmTMQuerymodMQuery::updateRst(
			ListWznmTMQuerymodMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmTMQuerymodMQuery::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmTMQuerymodMQuery::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmTMQuerymodMQuery::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmTMQuerymodMQuery::loadRecByRef(
			ubigint ref
			, WznmTMQuerymodMQuery** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmTMQuerymodMQuery WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmTMQuerymodMQuery::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmTMQuerymodMQuery WHERE refR = " + to_string(refR) + "", append, refs);
};

ubigint MyTblWznmTMQuerymodMQuery::loadRstByR(
			ubigint refR
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMQuerymod, refR FROM TblWznmTMQuerymodMQuery WHERE refR = " + to_string(refR) + " ORDER BY refWznmMQuerymod ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmTMQuerymodMQuery
 ******************************************************************************/

PgTblWznmTMQuerymodMQuery::PgTblWznmTMQuerymodMQuery() :
			TblWznmTMQuerymodMQuery()
			, PgTable()
		{
};

PgTblWznmTMQuerymodMQuery::~PgTblWznmTMQuerymodMQuery() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmTMQuerymodMQuery::initStatements() {
	createStatement("TblWznmTMQuerymodMQuery_insertRec", "INSERT INTO TblWznmTMQuerymodMQuery (refWznmMQuerymod, refR) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmTMQuerymodMQuery_updateRec", "UPDATE TblWznmTMQuerymodMQuery SET refWznmMQuerymod = $1, refR = $2 WHERE ref = $3", 3);
	createStatement("TblWznmTMQuerymodMQuery_removeRecByRef", "DELETE FROM TblWznmTMQuerymodMQuery WHERE ref = $1", 1);

	createStatement("TblWznmTMQuerymodMQuery_loadRecByRef", "SELECT ref, refWznmMQuerymod, refR FROM TblWznmTMQuerymodMQuery WHERE ref = $1", 1);
	createStatement("TblWznmTMQuerymodMQuery_loadRefsByR", "SELECT ref FROM TblWznmTMQuerymodMQuery WHERE refR = $1", 1);
	createStatement("TblWznmTMQuerymodMQuery_loadRstByR", "SELECT ref, refWznmMQuerymod, refR FROM TblWznmTMQuerymodMQuery WHERE refR = $1 ORDER BY refWznmMQuerymod ASC", 1);
};

bool PgTblWznmTMQuerymodMQuery::loadRec(
			PGresult* res
			, WznmTMQuerymodMQuery** rec
		) {
	char* ptr;

	WznmTMQuerymodMQuery* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmTMQuerymodMQuery();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquerymod"),
			PQfnumber(res, "refr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMQuerymod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refR = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmTMQuerymodMQuery::loadRst(
			PGresult* res
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmTMQuerymodMQuery* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquerymod"),
			PQfnumber(res, "refr")
		};

		while (numread < numrow) {
			rec = new WznmTMQuerymodMQuery();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMQuerymod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refR = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmTMQuerymodMQuery::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmTMQuerymodMQuery** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmTMQuerymodMQuery::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmTMQuerymodMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmTMQuerymodMQuery** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmTMQuerymodMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmTMQuerymodMQuery::insertRec(
			WznmTMQuerymodMQuery* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMQuerymod = htonl64(rec->refWznmMQuerymod);
	ubigint _refR = htonl64(rec->refR);

	const char* vals[] = {
		(char*) &_refWznmMQuerymod,
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmTMQuerymodMQuery_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmTMQuerymodMQuery::insertRst(
			ListWznmTMQuerymodMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmTMQuerymodMQuery::updateRec(
			WznmTMQuerymodMQuery* rec
		) {
	PGresult* res;

	ubigint _refWznmMQuerymod = htonl64(rec->refWznmMQuerymod);
	ubigint _refR = htonl64(rec->refR);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMQuerymod,
		(char*) &_refR,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmTMQuerymodMQuery_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmTMQuerymodMQuery::updateRst(
			ListWznmTMQuerymodMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmTMQuerymodMQuery::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmTMQuerymodMQuery_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmTMQuerymodMQuery::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmTMQuerymodMQuery::loadRecByRef(
			ubigint ref
			, WznmTMQuerymodMQuery** rec
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

	return loadRecByStmt("TblWznmTMQuerymodMQuery_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmTMQuerymodMQuery::loadRefsByR(
			ubigint refR
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refR = htonl64(refR);

	const char* vals[] = {
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmTMQuerymodMQuery_loadRefsByR", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmTMQuerymodMQuery::loadRstByR(
			ubigint refR
			, const bool append
			, ListWznmTMQuerymodMQuery& rst
		) {
	ubigint _refR = htonl64(refR);

	const char* vals[] = {
		(char*) &_refR
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmTMQuerymodMQuery_loadRstByR", 1, vals, l, f, append, rst);
};

#endif

