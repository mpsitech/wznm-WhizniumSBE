/**
	* \file WznmMMethod.cpp
	* database access for table TblWznmMMethod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMMethod.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMMethod
 ******************************************************************************/

WznmMMethod::WznmMMethod(
			const ubigint ref
			, const ubigint refWznmMJob
			, const string sref
			, const bool Execsrv
			, const string Comment
		) :
			ref(ref)
			, refWznmMJob(refWznmMJob)
			, sref(sref)
			, Execsrv(Execsrv)
			, Comment(Comment)
		{
};

bool WznmMMethod::operator==(
			const WznmMMethod& comp
		) {
	return false;
};

bool WznmMMethod::operator!=(
			const WznmMMethod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMMethod
 ******************************************************************************/

ListWznmMMethod::ListWznmMMethod() {
};

ListWznmMMethod::ListWznmMMethod(
			const ListWznmMMethod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMMethod(*(src.nodes[i]));
};

ListWznmMMethod::~ListWznmMMethod() {
	clear();
};

void ListWznmMMethod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMMethod::size() const {
	return(nodes.size());
};

void ListWznmMMethod::append(
			WznmMMethod* rec
		) {
	nodes.push_back(rec);
};

WznmMMethod* ListWznmMMethod::operator[](
			const uint ix
		) {
	WznmMMethod* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMMethod& ListWznmMMethod::operator=(
			const ListWznmMMethod& src
		) {
	WznmMMethod* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMMethod(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMMethod::operator==(
			const ListWznmMMethod& comp
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

bool ListWznmMMethod::operator!=(
			const ListWznmMMethod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMMethod
 ******************************************************************************/

TblWznmMMethod::TblWznmMMethod() {
};

TblWznmMMethod::~TblWznmMMethod() {
};

bool TblWznmMMethod::loadRecBySQL(
			const string& sqlstr
			, WznmMMethod** rec
		) {
	return false;
};

ubigint TblWznmMMethod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMethod& rst
		) {
	return 0;
};

ubigint TblWznmMMethod::insertRec(
			WznmMMethod* rec
		) {
	return 0;
};

ubigint TblWznmMMethod::insertNewRec(
			WznmMMethod** rec
			, const ubigint refWznmMJob
			, const string sref
			, const bool Execsrv
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMethod* _rec = NULL;

	_rec = new WznmMMethod(0, refWznmMJob, sref, Execsrv, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMMethod::appendNewRecToRst(
			ListWznmMMethod& rst
			, WznmMMethod** rec
			, const ubigint refWznmMJob
			, const string sref
			, const bool Execsrv
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMethod* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMJob, sref, Execsrv, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMMethod::insertRst(
			ListWznmMMethod& rst
			, bool transact
		) {
};

void TblWznmMMethod::updateRec(
			WznmMMethod* rec
		) {
};

void TblWznmMMethod::updateRst(
			ListWznmMMethod& rst
			, bool transact
		) {
};

void TblWznmMMethod::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMMethod::loadRecByRef(
			ubigint ref
			, WznmMMethod** rec
		) {
	return false;
};

ubigint TblWznmMMethod::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMMethod::loadRstByJob(
			ubigint refWznmMJob
			, const bool append
			, ListWznmMMethod& rst
		) {
	return 0;
};

ubigint TblWznmMMethod::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMMethod& rst
		) {
	ubigint numload = 0;
	WznmMMethod* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMMethod
 ******************************************************************************/

MyTblWznmMMethod::MyTblWznmMMethod() :
			TblWznmMMethod()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMMethod::~MyTblWznmMMethod() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMMethod::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMMethod (refWznmMJob, sref, Execsrv, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMMethod SET refWznmMJob = ?, sref = ?, Execsrv = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMMethod WHERE ref = ?", false);
};

bool MyTblWznmMMethod::loadRecBySQL(
			const string& sqlstr
			, WznmMMethod** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMMethod* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMethod::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMethod::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMMethod();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMJob = atoll((char*) dbrow[1]); else _rec->refWznmMJob = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->Execsrv = (atoi((char*) dbrow[3]) != 0); else _rec->Execsrv = false;
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMMethod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMethod& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMMethod* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMethod::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMethod::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMMethod();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMJob = atoll((char*) dbrow[1]); else rec->refWznmMJob = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->Execsrv = (atoi((char*) dbrow[3]) != 0); else rec->Execsrv = false;
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMMethod::insertRec(
			WznmMMethod* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	tinyint Execsrv = rec->Execsrv;
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindTinyint(&Execsrv,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMMethod::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMMethod::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMMethod::insertRst(
			ListWznmMMethod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMMethod::updateRec(
			WznmMMethod* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->sref.length();
	tinyint Execsrv = rec->Execsrv;
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindTinyint(&Execsrv,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMMethod::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMMethod::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMMethod::updateRst(
			ListWznmMMethod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMMethod::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMMethod::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMMethod::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMMethod::loadRecByRef(
			ubigint ref
			, WznmMMethod** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMMethod WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMMethod::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMMethod WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refs);
};

ubigint MyTblWznmMMethod::loadRstByJob(
			ubigint refWznmMJob
			, const bool append
			, ListWznmMMethod& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMJob, sref, Execsrv, Comment FROM TblWznmMMethod WHERE refWznmMJob = " + to_string(refWznmMJob) + " ORDER BY sref ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMMethod
 ******************************************************************************/

PgTblWznmMMethod::PgTblWznmMMethod() :
			TblWznmMMethod()
			, PgTable()
		{
};

PgTblWznmMMethod::~PgTblWznmMMethod() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMMethod::initStatements() {
	createStatement("TblWznmMMethod_insertRec", "INSERT INTO TblWznmMMethod (refWznmMJob, sref, Execsrv, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmMMethod_updateRec", "UPDATE TblWznmMMethod SET refWznmMJob = $1, sref = $2, Execsrv = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmMMethod_removeRecByRef", "DELETE FROM TblWznmMMethod WHERE ref = $1", 1);

	createStatement("TblWznmMMethod_loadRecByRef", "SELECT ref, refWznmMJob, sref, Execsrv, Comment FROM TblWznmMMethod WHERE ref = $1", 1);
	createStatement("TblWznmMMethod_loadRefsByJob", "SELECT ref FROM TblWznmMMethod WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMMethod_loadRstByJob", "SELECT ref, refWznmMJob, sref, Execsrv, Comment FROM TblWznmMMethod WHERE refWznmMJob = $1 ORDER BY sref ASC", 1);
};

bool PgTblWznmMMethod::loadRec(
			PGresult* res
			, WznmMMethod** rec
		) {
	char* ptr;

	WznmMMethod* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMMethod();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "execsrv"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Execsrv = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMMethod::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMMethod& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMMethod* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "execsrv"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMMethod();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Execsrv = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMMethod::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMMethod** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMethod::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMMethod::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMMethod& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMethod::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMMethod::loadRecBySQL(
			const string& sqlstr
			, WznmMMethod** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMethod::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMMethod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMethod& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMethod::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMMethod::insertRec(
			WznmMMethod* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Execsrv = htons((smallint) rec->Execsrv);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_Execsrv,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMMethod_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMethod::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMMethod::insertRst(
			ListWznmMMethod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMMethod::updateRec(
			WznmMMethod* rec
		) {
	PGresult* res;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Execsrv = htons((smallint) rec->Execsrv);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_Execsrv,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMMethod_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMethod::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMMethod::updateRst(
			ListWznmMMethod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMMethod::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMMethod_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMethod::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMMethod::loadRecByRef(
			ubigint ref
			, WznmMMethod** rec
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

	return loadRecByStmt("TblWznmMMethod_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMMethod::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMMethod_loadRefsByJob", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMMethod::loadRstByJob(
			ubigint refWznmMJob
			, const bool append
			, ListWznmMMethod& rst
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMMethod_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif
