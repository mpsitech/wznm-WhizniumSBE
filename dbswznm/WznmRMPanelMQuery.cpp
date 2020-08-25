/**
	* \file WznmRMPanelMQuery.cpp
	* database access for table TblWznmRMPanelMQuery (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmRMPanelMQuery.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMPanelMQuery
 ******************************************************************************/

WznmRMPanelMQuery::WznmRMPanelMQuery(
			const ubigint ref
			, const ubigint refWznmMPanel
			, const ubigint refWznmMQuery
		) {

	this->ref = ref;
	this->refWznmMPanel = refWznmMPanel;
	this->refWznmMQuery = refWznmMQuery;
};

bool WznmRMPanelMQuery::operator==(
			const WznmRMPanelMQuery& comp
		) {
	return false;
};

bool WznmRMPanelMQuery::operator!=(
			const WznmRMPanelMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMPanelMQuery
 ******************************************************************************/

ListWznmRMPanelMQuery::ListWznmRMPanelMQuery() {
};

ListWznmRMPanelMQuery::ListWznmRMPanelMQuery(
			const ListWznmRMPanelMQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMPanelMQuery(*(src.nodes[i]));
};

ListWznmRMPanelMQuery::~ListWznmRMPanelMQuery() {
	clear();
};

void ListWznmRMPanelMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMPanelMQuery::size() const {
	return(nodes.size());
};

void ListWznmRMPanelMQuery::append(
			WznmRMPanelMQuery* rec
		) {
	nodes.push_back(rec);
};

WznmRMPanelMQuery* ListWznmRMPanelMQuery::operator[](
			const uint ix
		) {
	WznmRMPanelMQuery* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMPanelMQuery& ListWznmRMPanelMQuery::operator=(
			const ListWznmRMPanelMQuery& src
		) {
	WznmRMPanelMQuery* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMPanelMQuery(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMPanelMQuery::operator==(
			const ListWznmRMPanelMQuery& comp
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

bool ListWznmRMPanelMQuery::operator!=(
			const ListWznmRMPanelMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMPanelMQuery
 ******************************************************************************/

TblWznmRMPanelMQuery::TblWznmRMPanelMQuery() {
};

TblWznmRMPanelMQuery::~TblWznmRMPanelMQuery() {
};

bool TblWznmRMPanelMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmRMPanelMQuery** rec
		) {
	return false;
};

ubigint TblWznmRMPanelMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMPanelMQuery& rst
		) {
	return 0;
};

ubigint TblWznmRMPanelMQuery::insertRec(
			WznmRMPanelMQuery* rec
		) {
	return 0;
};

ubigint TblWznmRMPanelMQuery::insertNewRec(
			WznmRMPanelMQuery** rec
			, const ubigint refWznmMPanel
			, const ubigint refWznmMQuery
		) {
	ubigint retval = 0;
	WznmRMPanelMQuery* _rec = NULL;

	_rec = new WznmRMPanelMQuery(0, refWznmMPanel, refWznmMQuery);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMPanelMQuery::appendNewRecToRst(
			ListWznmRMPanelMQuery& rst
			, WznmRMPanelMQuery** rec
			, const ubigint refWznmMPanel
			, const ubigint refWznmMQuery
		) {
	ubigint retval = 0;
	WznmRMPanelMQuery* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMPanel, refWznmMQuery);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMPanelMQuery::insertRst(
			ListWznmRMPanelMQuery& rst
			, bool transact
		) {
};

void TblWznmRMPanelMQuery::updateRec(
			WznmRMPanelMQuery* rec
		) {
};

void TblWznmRMPanelMQuery::updateRst(
			ListWznmRMPanelMQuery& rst
			, bool transact
		) {
};

void TblWznmRMPanelMQuery::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMPanelMQuery::loadRecByRef(
			ubigint ref
			, WznmRMPanelMQuery** rec
		) {
	return false;
};

ubigint TblWznmRMPanelMQuery::loadPnlsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refWznmMPanels
		) {
	return 0;
};

ubigint TblWznmRMPanelMQuery::loadQrysByPnl(
			ubigint refWznmMPanel
			, const bool append
			, vector<ubigint>& refWznmMQuerys
		) {
	return 0;
};

ubigint TblWznmRMPanelMQuery::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMPanelMQuery& rst
		) {
	ubigint numload = 0;
	WznmRMPanelMQuery* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMPanelMQuery
 ******************************************************************************/

MyTblWznmRMPanelMQuery::MyTblWznmRMPanelMQuery() :
			TblWznmRMPanelMQuery()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMPanelMQuery::~MyTblWznmRMPanelMQuery() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMPanelMQuery::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMPanelMQuery (refWznmMPanel, refWznmMQuery) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMPanelMQuery SET refWznmMPanel = ?, refWznmMQuery = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMPanelMQuery WHERE ref = ?", false);
};

bool MyTblWznmRMPanelMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmRMPanelMQuery** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMPanelMQuery* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMPanelMQuery::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMPanelMQuery::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMPanelMQuery();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMPanel = atoll((char*) dbrow[1]); else _rec->refWznmMPanel = 0;
		if (dbrow[2]) _rec->refWznmMQuery = atoll((char*) dbrow[2]); else _rec->refWznmMQuery = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMPanelMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMPanelMQuery& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMPanelMQuery* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMPanelMQuery::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMPanelMQuery::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMPanelMQuery();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMPanel = atoll((char*) dbrow[1]); else rec->refWznmMPanel = 0;
			if (dbrow[2]) rec->refWznmMQuery = atoll((char*) dbrow[2]); else rec->refWznmMQuery = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMPanelMQuery::insertRec(
			WznmRMPanelMQuery* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPanel,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMQuery,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMPanelMQuery::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMPanelMQuery::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMPanelMQuery::insertRst(
			ListWznmRMPanelMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMPanelMQuery::updateRec(
			WznmRMPanelMQuery* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPanel,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMQuery,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMPanelMQuery::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMPanelMQuery::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMPanelMQuery::updateRst(
			ListWznmRMPanelMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMPanelMQuery::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMPanelMQuery::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMPanelMQuery::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMPanelMQuery::loadRecByRef(
			ubigint ref
			, WznmRMPanelMQuery** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMPanelMQuery WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMPanelMQuery::loadPnlsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refWznmMPanels
		) {
	return loadRefsBySQL("SELECT refWznmMPanel FROM TblWznmRMPanelMQuery WHERE refWznmMQuery = " + to_string(refWznmMQuery) + "", append, refWznmMPanels);
};

ubigint MyTblWznmRMPanelMQuery::loadQrysByPnl(
			ubigint refWznmMPanel
			, const bool append
			, vector<ubigint>& refWznmMQuerys
		) {
	return loadRefsBySQL("SELECT refWznmMQuery FROM TblWznmRMPanelMQuery WHERE refWznmMPanel = " + to_string(refWznmMPanel) + "", append, refWznmMQuerys);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMPanelMQuery
 ******************************************************************************/

PgTblWznmRMPanelMQuery::PgTblWznmRMPanelMQuery() :
			TblWznmRMPanelMQuery()
			, PgTable()
		{
};

PgTblWznmRMPanelMQuery::~PgTblWznmRMPanelMQuery() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMPanelMQuery::initStatements() {
	createStatement("TblWznmRMPanelMQuery_insertRec", "INSERT INTO TblWznmRMPanelMQuery (refWznmMPanel, refWznmMQuery) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMPanelMQuery_updateRec", "UPDATE TblWznmRMPanelMQuery SET refWznmMPanel = $1, refWznmMQuery = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMPanelMQuery_removeRecByRef", "DELETE FROM TblWznmRMPanelMQuery WHERE ref = $1", 1);

	createStatement("TblWznmRMPanelMQuery_loadRecByRef", "SELECT ref, refWznmMPanel, refWznmMQuery FROM TblWznmRMPanelMQuery WHERE ref = $1", 1);
	createStatement("TblWznmRMPanelMQuery_loadPnlsByQry", "SELECT refWznmMPanel FROM TblWznmRMPanelMQuery WHERE refWznmMQuery = $1", 1);
	createStatement("TblWznmRMPanelMQuery_loadQrysByPnl", "SELECT refWznmMQuery FROM TblWznmRMPanelMQuery WHERE refWznmMPanel = $1", 1);
};

bool PgTblWznmRMPanelMQuery::loadRec(
			PGresult* res
			, WznmRMPanelMQuery** rec
		) {
	char* ptr;

	WznmRMPanelMQuery* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMPanelMQuery();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmpanel"),
			PQfnumber(res, "refwznmmquery")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMPanel = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMQuery = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMPanelMQuery::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMPanelMQuery& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMPanelMQuery* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmpanel"),
			PQfnumber(res, "refwznmmquery")
		};

		while (numread < numrow) {
			rec = new WznmRMPanelMQuery();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMPanel = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMQuery = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMPanelMQuery::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMPanelMQuery** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPanelMQuery::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMPanelMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmRMPanelMQuery** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPanelMQuery::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMPanelMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMPanelMQuery& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPanelMQuery::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMPanelMQuery::insertRec(
			WznmRMPanelMQuery* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMPanel = htonl64(rec->refWznmMPanel);
	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMPanel,
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMPanelMQuery_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPanelMQuery::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMPanelMQuery::insertRst(
			ListWznmRMPanelMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMPanelMQuery::updateRec(
			WznmRMPanelMQuery* rec
		) {
	PGresult* res;

	ubigint _refWznmMPanel = htonl64(rec->refWznmMPanel);
	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMPanel,
		(char*) &_refWznmMQuery,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMPanelMQuery_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMPanelMQuery::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMPanelMQuery::updateRst(
			ListWznmRMPanelMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMPanelMQuery::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMPanelMQuery_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMPanelMQuery::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMPanelMQuery::loadRecByRef(
			ubigint ref
			, WznmRMPanelMQuery** rec
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

	return loadRecByStmt("TblWznmRMPanelMQuery_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMPanelMQuery::loadPnlsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refWznmMPanels
		) {
	ubigint _refWznmMQuery = htonl64(refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMPanelMQuery_loadPnlsByQry", 1, vals, l, f, append, refWznmMPanels);
};

ubigint PgTblWznmRMPanelMQuery::loadQrysByPnl(
			ubigint refWznmMPanel
			, const bool append
			, vector<ubigint>& refWznmMQuerys
		) {
	ubigint _refWznmMPanel = htonl64(refWznmMPanel);

	const char* vals[] = {
		(char*) &_refWznmMPanel
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMPanelMQuery_loadQrysByPnl", 1, vals, l, f, append, refWznmMQuerys);
};

#endif

