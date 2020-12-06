/**
	* \file WznmRMDialogMQuery.cpp
	* database access for table TblWznmRMDialogMQuery (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMDialogMQuery.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMDialogMQuery
 ******************************************************************************/

WznmRMDialogMQuery::WznmRMDialogMQuery(
			const ubigint ref
			, const ubigint refWznmMDialog
			, const ubigint refWznmMQuery
		) {

	this->ref = ref;
	this->refWznmMDialog = refWznmMDialog;
	this->refWznmMQuery = refWznmMQuery;
};

bool WznmRMDialogMQuery::operator==(
			const WznmRMDialogMQuery& comp
		) {
	return false;
};

bool WznmRMDialogMQuery::operator!=(
			const WznmRMDialogMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMDialogMQuery
 ******************************************************************************/

ListWznmRMDialogMQuery::ListWznmRMDialogMQuery() {
};

ListWznmRMDialogMQuery::ListWznmRMDialogMQuery(
			const ListWznmRMDialogMQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMDialogMQuery(*(src.nodes[i]));
};

ListWznmRMDialogMQuery::~ListWznmRMDialogMQuery() {
	clear();
};

void ListWznmRMDialogMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMDialogMQuery::size() const {
	return(nodes.size());
};

void ListWznmRMDialogMQuery::append(
			WznmRMDialogMQuery* rec
		) {
	nodes.push_back(rec);
};

WznmRMDialogMQuery* ListWznmRMDialogMQuery::operator[](
			const uint ix
		) {
	WznmRMDialogMQuery* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMDialogMQuery& ListWznmRMDialogMQuery::operator=(
			const ListWznmRMDialogMQuery& src
		) {
	WznmRMDialogMQuery* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMDialogMQuery(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMDialogMQuery::operator==(
			const ListWznmRMDialogMQuery& comp
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

bool ListWznmRMDialogMQuery::operator!=(
			const ListWznmRMDialogMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMDialogMQuery
 ******************************************************************************/

TblWznmRMDialogMQuery::TblWznmRMDialogMQuery() {
};

TblWznmRMDialogMQuery::~TblWznmRMDialogMQuery() {
};

bool TblWznmRMDialogMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmRMDialogMQuery** rec
		) {
	return false;
};

ubigint TblWznmRMDialogMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMDialogMQuery& rst
		) {
	return 0;
};

ubigint TblWznmRMDialogMQuery::insertRec(
			WznmRMDialogMQuery* rec
		) {
	return 0;
};

ubigint TblWznmRMDialogMQuery::insertNewRec(
			WznmRMDialogMQuery** rec
			, const ubigint refWznmMDialog
			, const ubigint refWznmMQuery
		) {
	ubigint retval = 0;
	WznmRMDialogMQuery* _rec = NULL;

	_rec = new WznmRMDialogMQuery(0, refWznmMDialog, refWznmMQuery);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMDialogMQuery::appendNewRecToRst(
			ListWznmRMDialogMQuery& rst
			, WznmRMDialogMQuery** rec
			, const ubigint refWznmMDialog
			, const ubigint refWznmMQuery
		) {
	ubigint retval = 0;
	WznmRMDialogMQuery* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMDialog, refWznmMQuery);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMDialogMQuery::insertRst(
			ListWznmRMDialogMQuery& rst
			, bool transact
		) {
};

void TblWznmRMDialogMQuery::updateRec(
			WznmRMDialogMQuery* rec
		) {
};

void TblWznmRMDialogMQuery::updateRst(
			ListWznmRMDialogMQuery& rst
			, bool transact
		) {
};

void TblWznmRMDialogMQuery::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMDialogMQuery::loadRecByRef(
			ubigint ref
			, WznmRMDialogMQuery** rec
		) {
	return false;
};

ubigint TblWznmRMDialogMQuery::loadDlgsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refWznmMDialogs
		) {
	return 0;
};

ubigint TblWznmRMDialogMQuery::loadQrysByDlg(
			ubigint refWznmMDialog
			, const bool append
			, vector<ubigint>& refWznmMQuerys
		) {
	return 0;
};

ubigint TblWznmRMDialogMQuery::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMDialogMQuery& rst
		) {
	ubigint numload = 0;
	WznmRMDialogMQuery* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMDialogMQuery
 ******************************************************************************/

MyTblWznmRMDialogMQuery::MyTblWznmRMDialogMQuery() :
			TblWznmRMDialogMQuery()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMDialogMQuery::~MyTblWznmRMDialogMQuery() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMDialogMQuery::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMDialogMQuery (refWznmMDialog, refWznmMQuery) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMDialogMQuery SET refWznmMDialog = ?, refWznmMQuery = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMDialogMQuery WHERE ref = ?", false);
};

bool MyTblWznmRMDialogMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmRMDialogMQuery** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMDialogMQuery* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMDialogMQuery::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMDialogMQuery::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMDialogMQuery();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMDialog = atoll((char*) dbrow[1]); else _rec->refWznmMDialog = 0;
		if (dbrow[2]) _rec->refWznmMQuery = atoll((char*) dbrow[2]); else _rec->refWznmMQuery = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMDialogMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMDialogMQuery& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMDialogMQuery* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMDialogMQuery::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMDialogMQuery::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMDialogMQuery();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMDialog = atoll((char*) dbrow[1]); else rec->refWznmMDialog = 0;
			if (dbrow[2]) rec->refWznmMQuery = atoll((char*) dbrow[2]); else rec->refWznmMQuery = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMDialogMQuery::insertRec(
			WznmRMDialogMQuery* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMDialog,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMQuery,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMDialogMQuery::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMDialogMQuery::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMDialogMQuery::insertRst(
			ListWznmRMDialogMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMDialogMQuery::updateRec(
			WznmRMDialogMQuery* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMDialog,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMQuery,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMDialogMQuery::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMDialogMQuery::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMDialogMQuery::updateRst(
			ListWznmRMDialogMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMDialogMQuery::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMDialogMQuery::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMDialogMQuery::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMDialogMQuery::loadRecByRef(
			ubigint ref
			, WznmRMDialogMQuery** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMDialogMQuery WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMDialogMQuery::loadDlgsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refWznmMDialogs
		) {
	return loadRefsBySQL("SELECT refWznmMDialog FROM TblWznmRMDialogMQuery WHERE refWznmMQuery = " + to_string(refWznmMQuery) + "", append, refWznmMDialogs);
};

ubigint MyTblWznmRMDialogMQuery::loadQrysByDlg(
			ubigint refWznmMDialog
			, const bool append
			, vector<ubigint>& refWznmMQuerys
		) {
	return loadRefsBySQL("SELECT refWznmMQuery FROM TblWznmRMDialogMQuery WHERE refWznmMDialog = " + to_string(refWznmMDialog) + "", append, refWznmMQuerys);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMDialogMQuery
 ******************************************************************************/

PgTblWznmRMDialogMQuery::PgTblWznmRMDialogMQuery() :
			TblWznmRMDialogMQuery()
			, PgTable()
		{
};

PgTblWznmRMDialogMQuery::~PgTblWznmRMDialogMQuery() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMDialogMQuery::initStatements() {
	createStatement("TblWznmRMDialogMQuery_insertRec", "INSERT INTO TblWznmRMDialogMQuery (refWznmMDialog, refWznmMQuery) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMDialogMQuery_updateRec", "UPDATE TblWznmRMDialogMQuery SET refWznmMDialog = $1, refWznmMQuery = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMDialogMQuery_removeRecByRef", "DELETE FROM TblWznmRMDialogMQuery WHERE ref = $1", 1);

	createStatement("TblWznmRMDialogMQuery_loadRecByRef", "SELECT ref, refWznmMDialog, refWznmMQuery FROM TblWznmRMDialogMQuery WHERE ref = $1", 1);
	createStatement("TblWznmRMDialogMQuery_loadDlgsByQry", "SELECT refWznmMDialog FROM TblWznmRMDialogMQuery WHERE refWznmMQuery = $1", 1);
	createStatement("TblWznmRMDialogMQuery_loadQrysByDlg", "SELECT refWznmMQuery FROM TblWznmRMDialogMQuery WHERE refWznmMDialog = $1", 1);
};

bool PgTblWznmRMDialogMQuery::loadRec(
			PGresult* res
			, WznmRMDialogMQuery** rec
		) {
	char* ptr;

	WznmRMDialogMQuery* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMDialogMQuery();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmdialog"),
			PQfnumber(res, "refwznmmquery")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMDialog = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMQuery = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMDialogMQuery::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMDialogMQuery& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMDialogMQuery* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmdialog"),
			PQfnumber(res, "refwznmmquery")
		};

		while (numread < numrow) {
			rec = new WznmRMDialogMQuery();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMDialog = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMQuery = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMDialogMQuery::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMDialogMQuery** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMDialogMQuery::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMDialogMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmRMDialogMQuery** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMDialogMQuery::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMDialogMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMDialogMQuery& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMDialogMQuery::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMDialogMQuery::insertRec(
			WznmRMDialogMQuery* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMDialog = htonl64(rec->refWznmMDialog);
	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMDialog,
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMDialogMQuery_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMDialogMQuery::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMDialogMQuery::insertRst(
			ListWznmRMDialogMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMDialogMQuery::updateRec(
			WznmRMDialogMQuery* rec
		) {
	PGresult* res;

	ubigint _refWznmMDialog = htonl64(rec->refWznmMDialog);
	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMDialog,
		(char*) &_refWznmMQuery,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMDialogMQuery_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMDialogMQuery::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMDialogMQuery::updateRst(
			ListWznmRMDialogMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMDialogMQuery::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMDialogMQuery_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMDialogMQuery::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMDialogMQuery::loadRecByRef(
			ubigint ref
			, WznmRMDialogMQuery** rec
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

	return loadRecByStmt("TblWznmRMDialogMQuery_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMDialogMQuery::loadDlgsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refWznmMDialogs
		) {
	ubigint _refWznmMQuery = htonl64(refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMDialogMQuery_loadDlgsByQry", 1, vals, l, f, append, refWznmMDialogs);
};

ubigint PgTblWznmRMDialogMQuery::loadQrysByDlg(
			ubigint refWznmMDialog
			, const bool append
			, vector<ubigint>& refWznmMQuerys
		) {
	ubigint _refWznmMDialog = htonl64(refWznmMDialog);

	const char* vals[] = {
		(char*) &_refWznmMDialog
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMDialogMQuery_loadQrysByDlg", 1, vals, l, f, append, refWznmMQuerys);
};

#endif
