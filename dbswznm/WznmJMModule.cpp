/**
	* \file WznmJMModule.cpp
	* database access for table TblWznmJMModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMModule.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMModule
 ******************************************************************************/

WznmJMModule::WznmJMModule(
			const ubigint ref
			, const ubigint refWznmMModule
			, const ubigint x1RefWznmMLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMModule = refWznmMModule;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmJMModule::operator==(
			const WznmJMModule& comp
		) {
	return false;
};

bool WznmJMModule::operator!=(
			const WznmJMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMModule
 ******************************************************************************/

ListWznmJMModule::ListWznmJMModule() {
};

ListWznmJMModule::ListWznmJMModule(
			const ListWznmJMModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMModule(*(src.nodes[i]));
};

ListWznmJMModule::~ListWznmJMModule() {
	clear();
};

void ListWznmJMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMModule::size() const {
	return(nodes.size());
};

void ListWznmJMModule::append(
			WznmJMModule* rec
		) {
	nodes.push_back(rec);
};

WznmJMModule* ListWznmJMModule::operator[](
			const uint ix
		) {
	WznmJMModule* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMModule& ListWznmJMModule::operator=(
			const ListWznmJMModule& src
		) {
	WznmJMModule* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMModule(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMModule::operator==(
			const ListWznmJMModule& comp
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

bool ListWznmJMModule::operator!=(
			const ListWznmJMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMModule
 ******************************************************************************/

TblWznmJMModule::TblWznmJMModule() {
};

TblWznmJMModule::~TblWznmJMModule() {
};

bool TblWznmJMModule::loadRecBySQL(
			const string& sqlstr
			, WznmJMModule** rec
		) {
	return false;
};

ubigint TblWznmJMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMModule& rst
		) {
	return 0;
};

ubigint TblWznmJMModule::insertRec(
			WznmJMModule* rec
		) {
	return 0;
};

ubigint TblWznmJMModule::insertNewRec(
			WznmJMModule** rec
			, const ubigint refWznmMModule
			, const ubigint x1RefWznmMLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmJMModule* _rec = NULL;

	_rec = new WznmJMModule(0, refWznmMModule, x1RefWznmMLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMModule::appendNewRecToRst(
			ListWznmJMModule& rst
			, WznmJMModule** rec
			, const ubigint refWznmMModule
			, const ubigint x1RefWznmMLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmJMModule* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMModule, x1RefWznmMLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMModule::insertRst(
			ListWznmJMModule& rst
			, bool transact
		) {
};

void TblWznmJMModule::updateRec(
			WznmJMModule* rec
		) {
};

void TblWznmJMModule::updateRst(
			ListWznmJMModule& rst
			, bool transact
		) {
};

void TblWznmJMModule::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMModule::loadRecByRef(
			ubigint ref
			, WznmJMModule** rec
		) {
	return false;
};

bool TblWznmJMModule::loadRecByMdlLoc(
			ubigint refWznmMModule
			, ubigint x1RefWznmMLocale
			, WznmJMModule** rec
		) {
	return false;
};

ubigint TblWznmJMModule::loadRefsByMdl(
			ubigint refWznmMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMModule::loadRstByMdl(
			ubigint refWznmMModule
			, const bool append
			, ListWznmJMModule& rst
		) {
	return 0;
};

ubigint TblWznmJMModule::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMModule& rst
		) {
	ubigint numload = 0;
	WznmJMModule* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMModule
 ******************************************************************************/

MyTblWznmJMModule::MyTblWznmJMModule() :
			TblWznmJMModule()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMModule::~MyTblWznmJMModule() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMModule::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMModule (refWznmMModule, x1RefWznmMLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMModule SET refWznmMModule = ?, x1RefWznmMLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMModule WHERE ref = ?", false);
};

bool MyTblWznmJMModule::loadRecBySQL(
			const string& sqlstr
			, WznmJMModule** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMModule* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMModule::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMModule::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMModule();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMModule = atoll((char*) dbrow[1]); else _rec->refWznmMModule = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMModule& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMModule* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMModule::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMModule::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMModule();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMModule = atoll((char*) dbrow[1]); else rec->refWznmMModule = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMModule::insertRec(
			WznmJMModule* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMModule::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMModule::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMModule::insertRst(
			ListWznmJMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMModule::updateRec(
			WznmJMModule* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMModule::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMModule::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMModule::updateRst(
			ListWznmJMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMModule::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMModule::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMModule::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMModule::loadRecByRef(
			ubigint ref
			, WznmJMModule** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMModule WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMModule::loadRecByMdlLoc(
			ubigint refWznmMModule
			, ubigint x1RefWznmMLocale
			, WznmJMModule** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMModule, x1RefWznmMLocale, Title, Comment FROM TblWznmJMModule WHERE refWznmMModule = " + to_string(refWznmMModule) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMModule::loadRefsByMdl(
			ubigint refWznmMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMModule WHERE refWznmMModule = " + to_string(refWznmMModule) + "", append, refs);
};

ubigint MyTblWznmJMModule::loadRstByMdl(
			ubigint refWznmMModule
			, const bool append
			, ListWznmJMModule& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMModule, x1RefWznmMLocale, Title, Comment FROM TblWznmJMModule WHERE refWznmMModule = " + to_string(refWznmMModule) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMModule
 ******************************************************************************/

PgTblWznmJMModule::PgTblWznmJMModule() :
			TblWznmJMModule()
			, PgTable()
		{
};

PgTblWznmJMModule::~PgTblWznmJMModule() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMModule::initStatements() {
	createStatement("TblWznmJMModule_insertRec", "INSERT INTO TblWznmJMModule (refWznmMModule, x1RefWznmMLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmJMModule_updateRec", "UPDATE TblWznmJMModule SET refWznmMModule = $1, x1RefWznmMLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmJMModule_removeRecByRef", "DELETE FROM TblWznmJMModule WHERE ref = $1", 1);

	createStatement("TblWznmJMModule_loadRecByRef", "SELECT ref, refWznmMModule, x1RefWznmMLocale, Title, Comment FROM TblWznmJMModule WHERE ref = $1", 1);
	createStatement("TblWznmJMModule_loadRecByMdlLoc", "SELECT ref, refWznmMModule, x1RefWznmMLocale, Title, Comment FROM TblWznmJMModule WHERE refWznmMModule = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMModule_loadRefsByMdl", "SELECT ref FROM TblWznmJMModule WHERE refWznmMModule = $1", 1);
	createStatement("TblWznmJMModule_loadRstByMdl", "SELECT ref, refWznmMModule, x1RefWznmMLocale, Title, Comment FROM TblWznmJMModule WHERE refWznmMModule = $1 ORDER BY x1RefWznmMLocale ASC", 1);
};

bool PgTblWznmJMModule::loadRec(
			PGresult* res
			, WznmJMModule** rec
		) {
	char* ptr;

	WznmJMModule* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMModule();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmodule"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMModule::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMModule& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMModule* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmodule"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmJMModule();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMModule::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMModule** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMModule::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMModule::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMModule& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMModule::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMModule::loadRecBySQL(
			const string& sqlstr
			, WznmJMModule** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMModule::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMModule& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMModule::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMModule::insertRec(
			WznmJMModule* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMModule = htonl64(rec->refWznmMModule);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMModule,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmJMModule_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMModule::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMModule::insertRst(
			ListWznmJMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMModule::updateRec(
			WznmJMModule* rec
		) {
	PGresult* res;

	ubigint _refWznmMModule = htonl64(rec->refWznmMModule);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMModule,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJMModule_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMModule::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMModule::updateRst(
			ListWznmJMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMModule::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMModule_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMModule::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMModule::loadRecByRef(
			ubigint ref
			, WznmJMModule** rec
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

	return loadRecByStmt("TblWznmJMModule_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMModule::loadRecByMdlLoc(
			ubigint refWznmMModule
			, ubigint x1RefWznmMLocale
			, WznmJMModule** rec
		) {
	ubigint _refWznmMModule = htonl64(refWznmMModule);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMModule,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMModule_loadRecByMdlLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMModule::loadRefsByMdl(
			ubigint refWznmMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMModule = htonl64(refWznmMModule);

	const char* vals[] = {
		(char*) &_refWznmMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMModule_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMModule::loadRstByMdl(
			ubigint refWznmMModule
			, const bool append
			, ListWznmJMModule& rst
		) {
	ubigint _refWznmMModule = htonl64(refWznmMModule);

	const char* vals[] = {
		(char*) &_refWznmMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMModule_loadRstByMdl", 1, vals, l, f, append, rst);
};

#endif
