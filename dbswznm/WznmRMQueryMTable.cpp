/**
	* \file WznmRMQueryMTable.cpp
	* database access for table TblWznmRMQueryMTable (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmRMQueryMTable.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMQueryMTable
 ******************************************************************************/

WznmRMQueryMTable::WznmRMQueryMTable(
			const ubigint ref
			, const ubigint refWznmMQuery
			, const ubigint refWznmMTable
			, const bool Source
			, const string Prefix
		) {

	this->ref = ref;
	this->refWznmMQuery = refWznmMQuery;
	this->refWznmMTable = refWznmMTable;
	this->Source = Source;
	this->Prefix = Prefix;
};

bool WznmRMQueryMTable::operator==(
			const WznmRMQueryMTable& comp
		) {
	return false;
};

bool WznmRMQueryMTable::operator!=(
			const WznmRMQueryMTable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMQueryMTable
 ******************************************************************************/

ListWznmRMQueryMTable::ListWznmRMQueryMTable() {
};

ListWznmRMQueryMTable::ListWznmRMQueryMTable(
			const ListWznmRMQueryMTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMQueryMTable(*(src.nodes[i]));
};

ListWznmRMQueryMTable::~ListWznmRMQueryMTable() {
	clear();
};

void ListWznmRMQueryMTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMQueryMTable::size() const {
	return(nodes.size());
};

void ListWznmRMQueryMTable::append(
			WznmRMQueryMTable* rec
		) {
	nodes.push_back(rec);
};

WznmRMQueryMTable* ListWznmRMQueryMTable::operator[](
			const uint ix
		) {
	WznmRMQueryMTable* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMQueryMTable& ListWznmRMQueryMTable::operator=(
			const ListWznmRMQueryMTable& src
		) {
	WznmRMQueryMTable* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMQueryMTable(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMQueryMTable::operator==(
			const ListWznmRMQueryMTable& comp
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

bool ListWznmRMQueryMTable::operator!=(
			const ListWznmRMQueryMTable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMQueryMTable
 ******************************************************************************/

TblWznmRMQueryMTable::TblWznmRMQueryMTable() {
};

TblWznmRMQueryMTable::~TblWznmRMQueryMTable() {
};

bool TblWznmRMQueryMTable::loadRecBySQL(
			const string& sqlstr
			, WznmRMQueryMTable** rec
		) {
	return false;
};

ubigint TblWznmRMQueryMTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	return 0;
};

ubigint TblWznmRMQueryMTable::insertRec(
			WznmRMQueryMTable* rec
		) {
	return 0;
};

ubigint TblWznmRMQueryMTable::insertNewRec(
			WznmRMQueryMTable** rec
			, const ubigint refWznmMQuery
			, const ubigint refWznmMTable
			, const bool Source
			, const string Prefix
		) {
	ubigint retval = 0;
	WznmRMQueryMTable* _rec = NULL;

	_rec = new WznmRMQueryMTable(0, refWznmMQuery, refWznmMTable, Source, Prefix);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMQueryMTable::appendNewRecToRst(
			ListWznmRMQueryMTable& rst
			, WznmRMQueryMTable** rec
			, const ubigint refWznmMQuery
			, const ubigint refWznmMTable
			, const bool Source
			, const string Prefix
		) {
	ubigint retval = 0;
	WznmRMQueryMTable* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMQuery, refWznmMTable, Source, Prefix);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMQueryMTable::insertRst(
			ListWznmRMQueryMTable& rst
			, bool transact
		) {
};

void TblWznmRMQueryMTable::updateRec(
			WznmRMQueryMTable* rec
		) {
};

void TblWznmRMQueryMTable::updateRst(
			ListWznmRMQueryMTable& rst
			, bool transact
		) {
};

void TblWznmRMQueryMTable::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMQueryMTable::loadRecByRef(
			ubigint ref
			, WznmRMQueryMTable** rec
		) {
	return false;
};

ubigint TblWznmRMQueryMTable::loadRefsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMQueryMTable::loadRstByQry(
			ubigint refWznmMQuery
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	return 0;
};

ubigint TblWznmRMQueryMTable::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	return 0;
};

ubigint TblWznmRMQueryMTable::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	ubigint numload = 0;
	WznmRMQueryMTable* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMQueryMTable
 ******************************************************************************/

MyTblWznmRMQueryMTable::MyTblWznmRMQueryMTable() :
			TblWznmRMQueryMTable()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMQueryMTable::~MyTblWznmRMQueryMTable() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMQueryMTable::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMQueryMTable (refWznmMQuery, refWznmMTable, Source, Prefix) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMQueryMTable SET refWznmMQuery = ?, refWznmMTable = ?, Source = ?, Prefix = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMQueryMTable WHERE ref = ?", false);
};

bool MyTblWznmRMQueryMTable::loadRecBySQL(
			const string& sqlstr
			, WznmRMQueryMTable** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMQueryMTable* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMQueryMTable::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMQueryMTable::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmRMQueryMTable();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMQuery = atoll((char*) dbrow[1]); else _rec->refWznmMQuery = 0;
		if (dbrow[2]) _rec->refWznmMTable = atoll((char*) dbrow[2]); else _rec->refWznmMTable = 0;
		if (dbrow[3]) _rec->Source = (atoi((char*) dbrow[3]) != 0); else _rec->Source = false;
		if (dbrow[4]) _rec->Prefix.assign(dbrow[4], dblengths[4]); else _rec->Prefix = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMQueryMTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMQueryMTable* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMQueryMTable::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMQueryMTable::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmRMQueryMTable();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMQuery = atoll((char*) dbrow[1]); else rec->refWznmMQuery = 0;
			if (dbrow[2]) rec->refWznmMTable = atoll((char*) dbrow[2]); else rec->refWznmMTable = 0;
			if (dbrow[3]) rec->Source = (atoi((char*) dbrow[3]) != 0); else rec->Source = false;
			if (dbrow[4]) rec->Prefix.assign(dbrow[4], dblengths[4]); else rec->Prefix = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMQueryMTable::insertRec(
			WznmRMQueryMTable* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	tinyint Source = rec->Source;
	l[3] = rec->Prefix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuery,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindTinyint(&Source,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMQueryMTable::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMQueryMTable::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMQueryMTable::insertRst(
			ListWznmRMQueryMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMQueryMTable::updateRec(
			WznmRMQueryMTable* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	tinyint Source = rec->Source;
	l[3] = rec->Prefix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuery,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindTinyint(&Source,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMQueryMTable::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMQueryMTable::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMQueryMTable::updateRst(
			ListWznmRMQueryMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMQueryMTable::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMQueryMTable::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMQueryMTable::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMQueryMTable::loadRecByRef(
			ubigint ref
			, WznmRMQueryMTable** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMQueryMTable WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMQueryMTable::loadRefsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMQueryMTable WHERE refWznmMQuery = " + to_string(refWznmMQuery) + "", append, refs);
};

ubigint MyTblWznmRMQueryMTable::loadRstByQry(
			ubigint refWznmMQuery
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMQuery, refWznmMTable, Source, Prefix FROM TblWznmRMQueryMTable WHERE refWznmMQuery = " + to_string(refWznmMQuery) + "", append, rst);
};

ubigint MyTblWznmRMQueryMTable::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMQuery, refWznmMTable, Source, Prefix FROM TblWznmRMQueryMTable WHERE refWznmMTable = " + to_string(refWznmMTable) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMQueryMTable
 ******************************************************************************/

PgTblWznmRMQueryMTable::PgTblWznmRMQueryMTable() :
			TblWznmRMQueryMTable()
			, PgTable()
		{
};

PgTblWznmRMQueryMTable::~PgTblWznmRMQueryMTable() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMQueryMTable::initStatements() {
	createStatement("TblWznmRMQueryMTable_insertRec", "INSERT INTO TblWznmRMQueryMTable (refWznmMQuery, refWznmMTable, Source, Prefix) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmRMQueryMTable_updateRec", "UPDATE TblWznmRMQueryMTable SET refWznmMQuery = $1, refWznmMTable = $2, Source = $3, Prefix = $4 WHERE ref = $5", 5);
	createStatement("TblWznmRMQueryMTable_removeRecByRef", "DELETE FROM TblWznmRMQueryMTable WHERE ref = $1", 1);

	createStatement("TblWznmRMQueryMTable_loadRecByRef", "SELECT ref, refWznmMQuery, refWznmMTable, Source, Prefix FROM TblWznmRMQueryMTable WHERE ref = $1", 1);
	createStatement("TblWznmRMQueryMTable_loadRefsByQry", "SELECT ref FROM TblWznmRMQueryMTable WHERE refWznmMQuery = $1", 1);
	createStatement("TblWznmRMQueryMTable_loadRstByQry", "SELECT ref, refWznmMQuery, refWznmMTable, Source, Prefix FROM TblWznmRMQueryMTable WHERE refWznmMQuery = $1", 1);
	createStatement("TblWznmRMQueryMTable_loadRstByTbl", "SELECT ref, refWznmMQuery, refWznmMTable, Source, Prefix FROM TblWznmRMQueryMTable WHERE refWznmMTable = $1", 1);
};

bool PgTblWznmRMQueryMTable::loadRec(
			PGresult* res
			, WznmRMQueryMTable** rec
		) {
	char* ptr;

	WznmRMQueryMTable* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMQueryMTable();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquery"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "source"),
			PQfnumber(res, "prefix")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Source = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Prefix.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMQueryMTable::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMQueryMTable* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquery"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "source"),
			PQfnumber(res, "prefix")
		};

		while (numread < numrow) {
			rec = new WznmRMQueryMTable();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Source = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Prefix.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMQueryMTable::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMQueryMTable** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMQueryMTable::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMQueryMTable::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMQueryMTable::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmRMQueryMTable::loadRecBySQL(
			const string& sqlstr
			, WznmRMQueryMTable** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMQueryMTable::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMQueryMTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMQueryMTable::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMQueryMTable::insertRec(
			WznmRMQueryMTable* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	smallint _Source = htons((smallint) rec->Source);

	const char* vals[] = {
		(char*) &_refWznmMQuery,
		(char*) &_refWznmMTable,
		(char*) &_Source,
		rec->Prefix.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmRMQueryMTable_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMQueryMTable::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMQueryMTable::insertRst(
			ListWznmRMQueryMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMQueryMTable::updateRec(
			WznmRMQueryMTable* rec
		) {
	PGresult* res;

	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	smallint _Source = htons((smallint) rec->Source);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMQuery,
		(char*) &_refWznmMTable,
		(char*) &_Source,
		rec->Prefix.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmRMQueryMTable_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMQueryMTable::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMQueryMTable::updateRst(
			ListWznmRMQueryMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMQueryMTable::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMQueryMTable_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMQueryMTable::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMQueryMTable::loadRecByRef(
			ubigint ref
			, WznmRMQueryMTable** rec
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

	return loadRecByStmt("TblWznmRMQueryMTable_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMQueryMTable::loadRefsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMQuery = htonl64(refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMQueryMTable_loadRefsByQry", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMQueryMTable::loadRstByQry(
			ubigint refWznmMQuery
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	ubigint _refWznmMQuery = htonl64(refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMQueryMTable_loadRstByQry", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmRMQueryMTable::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmRMQueryMTable& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMQueryMTable_loadRstByTbl", 1, vals, l, f, append, rst);
};

#endif

