/**
	* \file WznmMSession.cpp
	* database access for table TblWznmMSession (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMSession.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMSession
 ******************************************************************************/

WznmMSession::WznmMSession(
			const ubigint ref
			, const ubigint refWznmMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refWznmMUser = refWznmMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool WznmMSession::operator==(
			const WznmMSession& comp
		) {
	return false;
};

bool WznmMSession::operator!=(
			const WznmMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMSession
 ******************************************************************************/

ListWznmMSession::ListWznmMSession() {
};

ListWznmMSession::ListWznmMSession(
			const ListWznmMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMSession(*(src.nodes[i]));
};

ListWznmMSession::~ListWznmMSession() {
	clear();
};

void ListWznmMSession::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMSession::size() const {
	return(nodes.size());
};

void ListWznmMSession::append(
			WznmMSession* rec
		) {
	nodes.push_back(rec);
};

WznmMSession* ListWznmMSession::operator[](
			const uint ix
		) {
	WznmMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMSession& ListWznmMSession::operator=(
			const ListWznmMSession& src
		) {
	WznmMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMSession::operator==(
			const ListWznmMSession& comp
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

bool ListWznmMSession::operator!=(
			const ListWznmMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMSession
 ******************************************************************************/

TblWznmMSession::TblWznmMSession() {
};

TblWznmMSession::~TblWznmMSession() {
};

bool TblWznmMSession::loadRecBySQL(
			const string& sqlstr
			, WznmMSession** rec
		) {
	return false;
};

ubigint TblWznmMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSession& rst
		) {
	return 0;
};

ubigint TblWznmMSession::insertRec(
			WznmMSession* rec
		) {
	return 0;
};

ubigint TblWznmMSession::insertNewRec(
			WznmMSession** rec
			, const ubigint refWznmMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WznmMSession* _rec = NULL;

	_rec = new WznmMSession(0, refWznmMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMSession::appendNewRecToRst(
			ListWznmMSession& rst
			, WznmMSession** rec
			, const ubigint refWznmMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WznmMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMSession::insertRst(
			ListWznmMSession& rst
			, bool transact
		) {
};

void TblWznmMSession::updateRec(
			WznmMSession* rec
		) {
};

void TblWznmMSession::updateRst(
			ListWznmMSession& rst
			, bool transact
		) {
};

void TblWznmMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMSession::loadRecByRef(
			ubigint ref
			, WznmMSession** rec
		) {
	return false;
};

ubigint TblWznmMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMSession& rst
		) {
	ubigint numload = 0;
	WznmMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMSession
 ******************************************************************************/

MyTblWznmMSession::MyTblWznmMSession() :
			TblWznmMSession()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMSession::~MyTblWznmMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMSession (refWznmMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMSession SET refWznmMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMSession WHERE ref = ?", false);
};

bool MyTblWznmMSession::loadRecBySQL(
			const string& sqlstr
			, WznmMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSession::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSession::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUser = atoll((char*) dbrow[1]); else _rec->refWznmMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSession::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSession::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUser = atoll((char*) dbrow[1]); else rec->refWznmMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMSession::insertRec(
			WznmMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMSession::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMSession::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMSession::insertRst(
			ListWznmMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMSession::updateRec(
			WznmMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMSession::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMSession::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMSession::updateRst(
			ListWznmMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMSession::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMSession::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMSession::loadRecByRef(
			ubigint ref
			, WznmMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMSession WHERE ref = " + to_string(ref), rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMSession
 ******************************************************************************/

PgTblWznmMSession::PgTblWznmMSession() :
			TblWznmMSession()
			, PgTable()
		{
};

PgTblWznmMSession::~PgTblWznmMSession() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMSession::initStatements() {
	createStatement("TblWznmMSession_insertRec", "INSERT INTO TblWznmMSession (refWznmMUser, start, stop, Ip) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmMSession_updateRec", "UPDATE TblWznmMSession SET refWznmMUser = $1, start = $2, stop = $3, Ip = $4 WHERE ref = $5", 5);
	createStatement("TblWznmMSession_removeRecByRef", "DELETE FROM TblWznmMSession WHERE ref = $1", 1);

	createStatement("TblWznmMSession_loadRecByRef", "SELECT ref, refWznmMUser, start, stop, Ip FROM TblWznmMSession WHERE ref = $1", 1);
};

bool PgTblWznmMSession::loadRec(
			PGresult* res
			, WznmMSession** rec
		) {
	char* ptr;

	WznmMSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMSession();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMSession::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		while (numread < numrow) {
			rec = new WznmMSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSession::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMSession::loadRecBySQL(
			const string& sqlstr
			, WznmMSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSession::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSession::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMSession::insertRec(
			WznmMSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMSession_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSession::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMSession::insertRst(
			ListWznmMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMSession::updateRec(
			WznmMSession* rec
		) {
	PGresult* res;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMSession_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSession::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMSession::updateRst(
			ListWznmMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMSession::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMSession_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSession::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMSession::loadRecByRef(
			ubigint ref
			, WznmMSession** rec
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

	return loadRecByStmt("TblWznmMSession_loadRecByRef", 1, vals, l, f, rec);
};

#endif

