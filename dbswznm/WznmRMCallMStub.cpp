/**
	* \file WznmRMCallMStub.cpp
	* database access for table TblWznmRMCallMStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMCallMStub.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMCallMStub
 ******************************************************************************/

WznmRMCallMStub::WznmRMCallMStub(
			const ubigint ref
			, const ubigint refWznmMCall
			, const ubigint refWznmMStub
		) {

	this->ref = ref;
	this->refWznmMCall = refWznmMCall;
	this->refWznmMStub = refWznmMStub;
};

bool WznmRMCallMStub::operator==(
			const WznmRMCallMStub& comp
		) {
	return false;
};

bool WznmRMCallMStub::operator!=(
			const WznmRMCallMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMCallMStub
 ******************************************************************************/

ListWznmRMCallMStub::ListWznmRMCallMStub() {
};

ListWznmRMCallMStub::ListWznmRMCallMStub(
			const ListWznmRMCallMStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMCallMStub(*(src.nodes[i]));
};

ListWznmRMCallMStub::~ListWznmRMCallMStub() {
	clear();
};

void ListWznmRMCallMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMCallMStub::size() const {
	return(nodes.size());
};

void ListWznmRMCallMStub::append(
			WznmRMCallMStub* rec
		) {
	nodes.push_back(rec);
};

WznmRMCallMStub* ListWznmRMCallMStub::operator[](
			const uint ix
		) {
	WznmRMCallMStub* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMCallMStub& ListWznmRMCallMStub::operator=(
			const ListWznmRMCallMStub& src
		) {
	WznmRMCallMStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMCallMStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMCallMStub::operator==(
			const ListWznmRMCallMStub& comp
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

bool ListWznmRMCallMStub::operator!=(
			const ListWznmRMCallMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMCallMStub
 ******************************************************************************/

TblWznmRMCallMStub::TblWznmRMCallMStub() {
};

TblWznmRMCallMStub::~TblWznmRMCallMStub() {
};

bool TblWznmRMCallMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMCallMStub** rec
		) {
	return false;
};

ubigint TblWznmRMCallMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMCallMStub& rst
		) {
	return 0;
};

ubigint TblWznmRMCallMStub::insertRec(
			WznmRMCallMStub* rec
		) {
	return 0;
};

ubigint TblWznmRMCallMStub::insertNewRec(
			WznmRMCallMStub** rec
			, const ubigint refWznmMCall
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmRMCallMStub* _rec = NULL;

	_rec = new WznmRMCallMStub(0, refWznmMCall, refWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMCallMStub::appendNewRecToRst(
			ListWznmRMCallMStub& rst
			, WznmRMCallMStub** rec
			, const ubigint refWznmMCall
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmRMCallMStub* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMCall, refWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMCallMStub::insertRst(
			ListWznmRMCallMStub& rst
			, bool transact
		) {
};

void TblWznmRMCallMStub::updateRec(
			WznmRMCallMStub* rec
		) {
};

void TblWznmRMCallMStub::updateRst(
			ListWznmRMCallMStub& rst
			, bool transact
		) {
};

void TblWznmRMCallMStub::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMCallMStub::loadRecByRef(
			ubigint ref
			, WznmRMCallMStub** rec
		) {
	return false;
};

ubigint TblWznmRMCallMStub::loadCalsByStb(
			ubigint refWznmMStub
			, const bool append
			, vector<ubigint>& refWznmMCalls
		) {
	return 0;
};

ubigint TblWznmRMCallMStub::loadStbsByCal(
			ubigint refWznmMCall
			, const bool append
			, vector<ubigint>& refWznmMStubs
		) {
	return 0;
};

ubigint TblWznmRMCallMStub::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMCallMStub& rst
		) {
	ubigint numload = 0;
	WznmRMCallMStub* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMCallMStub
 ******************************************************************************/

MyTblWznmRMCallMStub::MyTblWznmRMCallMStub() :
			TblWznmRMCallMStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMCallMStub::~MyTblWznmRMCallMStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMCallMStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMCallMStub (refWznmMCall, refWznmMStub) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMCallMStub SET refWznmMCall = ?, refWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMCallMStub WHERE ref = ?", false);
};

bool MyTblWznmRMCallMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMCallMStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMCallMStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMCallMStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMCallMStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMCallMStub();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMCall = atoll((char*) dbrow[1]); else _rec->refWznmMCall = 0;
		if (dbrow[2]) _rec->refWznmMStub = atoll((char*) dbrow[2]); else _rec->refWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMCallMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMCallMStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMCallMStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMCallMStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMCallMStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMCallMStub();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMCall = atoll((char*) dbrow[1]); else rec->refWznmMCall = 0;
			if (dbrow[2]) rec->refWznmMStub = atoll((char*) dbrow[2]); else rec->refWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMCallMStub::insertRec(
			WznmRMCallMStub* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCall,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMStub,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMCallMStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMCallMStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMCallMStub::insertRst(
			ListWznmRMCallMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMCallMStub::updateRec(
			WznmRMCallMStub* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCall,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMStub,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMCallMStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMCallMStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMCallMStub::updateRst(
			ListWznmRMCallMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMCallMStub::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMCallMStub::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMCallMStub::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMCallMStub::loadRecByRef(
			ubigint ref
			, WznmRMCallMStub** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMCallMStub WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMCallMStub::loadCalsByStb(
			ubigint refWznmMStub
			, const bool append
			, vector<ubigint>& refWznmMCalls
		) {
	return loadRefsBySQL("SELECT refWznmMCall FROM TblWznmRMCallMStub WHERE refWznmMStub = " + to_string(refWznmMStub) + "", append, refWznmMCalls);
};

ubigint MyTblWznmRMCallMStub::loadStbsByCal(
			ubigint refWznmMCall
			, const bool append
			, vector<ubigint>& refWznmMStubs
		) {
	return loadRefsBySQL("SELECT refWznmMStub FROM TblWznmRMCallMStub WHERE refWznmMCall = " + to_string(refWznmMCall) + "", append, refWznmMStubs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMCallMStub
 ******************************************************************************/

PgTblWznmRMCallMStub::PgTblWznmRMCallMStub() :
			TblWznmRMCallMStub()
			, PgTable()
		{
};

PgTblWznmRMCallMStub::~PgTblWznmRMCallMStub() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMCallMStub::initStatements() {
	createStatement("TblWznmRMCallMStub_insertRec", "INSERT INTO TblWznmRMCallMStub (refWznmMCall, refWznmMStub) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMCallMStub_updateRec", "UPDATE TblWznmRMCallMStub SET refWznmMCall = $1, refWznmMStub = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMCallMStub_removeRecByRef", "DELETE FROM TblWznmRMCallMStub WHERE ref = $1", 1);

	createStatement("TblWznmRMCallMStub_loadRecByRef", "SELECT ref, refWznmMCall, refWznmMStub FROM TblWznmRMCallMStub WHERE ref = $1", 1);
	createStatement("TblWznmRMCallMStub_loadCalsByStb", "SELECT refWznmMCall FROM TblWznmRMCallMStub WHERE refWznmMStub = $1", 1);
	createStatement("TblWznmRMCallMStub_loadStbsByCal", "SELECT refWznmMStub FROM TblWznmRMCallMStub WHERE refWznmMCall = $1", 1);
};

bool PgTblWznmRMCallMStub::loadRec(
			PGresult* res
			, WznmRMCallMStub** rec
		) {
	char* ptr;

	WznmRMCallMStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMCallMStub();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcall"),
			PQfnumber(res, "refwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMCall = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMCallMStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMCallMStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMCallMStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcall"),
			PQfnumber(res, "refwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmRMCallMStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMCall = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMCallMStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMCallMStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCallMStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMCallMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMCallMStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCallMStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMCallMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMCallMStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCallMStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMCallMStub::insertRec(
			WznmRMCallMStub* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMCall = htonl64(rec->refWznmMCall);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMCall,
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMCallMStub_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCallMStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMCallMStub::insertRst(
			ListWznmRMCallMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMCallMStub::updateRec(
			WznmRMCallMStub* rec
		) {
	PGresult* res;

	ubigint _refWznmMCall = htonl64(rec->refWznmMCall);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMCall,
		(char*) &_refWznmMStub,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMCallMStub_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMCallMStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMCallMStub::updateRst(
			ListWznmRMCallMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMCallMStub::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMCallMStub_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMCallMStub::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMCallMStub::loadRecByRef(
			ubigint ref
			, WznmRMCallMStub** rec
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

	return loadRecByStmt("TblWznmRMCallMStub_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMCallMStub::loadCalsByStb(
			ubigint refWznmMStub
			, const bool append
			, vector<ubigint>& refWznmMCalls
		) {
	ubigint _refWznmMStub = htonl64(refWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMCallMStub_loadCalsByStb", 1, vals, l, f, append, refWznmMCalls);
};

ubigint PgTblWznmRMCallMStub::loadStbsByCal(
			ubigint refWznmMCall
			, const bool append
			, vector<ubigint>& refWznmMStubs
		) {
	ubigint _refWznmMCall = htonl64(refWznmMCall);

	const char* vals[] = {
		(char*) &_refWznmMCall
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMCallMStub_loadStbsByCal", 1, vals, l, f, append, refWznmMStubs);
};

#endif

