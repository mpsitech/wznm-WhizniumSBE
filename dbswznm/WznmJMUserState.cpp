/**
	* \file WznmJMUserState.cpp
	* database access for table TblWznmJMUserState (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmJMUserState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMUserState
 ******************************************************************************/

WznmJMUserState::WznmJMUserState(
			const ubigint ref
			, const ubigint refWznmMUser
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refWznmMUser = refWznmMUser;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool WznmJMUserState::operator==(
			const WznmJMUserState& comp
		) {
	return false;
};

bool WznmJMUserState::operator!=(
			const WznmJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMUserState
 ******************************************************************************/

ListWznmJMUserState::ListWznmJMUserState() {
};

ListWznmJMUserState::ListWznmJMUserState(
			const ListWznmJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMUserState(*(src.nodes[i]));
};

ListWznmJMUserState::~ListWznmJMUserState() {
	clear();
};

void ListWznmJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMUserState::size() const {
	return(nodes.size());
};

void ListWznmJMUserState::append(
			WznmJMUserState* rec
		) {
	nodes.push_back(rec);
};

WznmJMUserState* ListWznmJMUserState::operator[](
			const uint ix
		) {
	WznmJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMUserState& ListWznmJMUserState::operator=(
			const ListWznmJMUserState& src
		) {
	WznmJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMUserState::operator==(
			const ListWznmJMUserState& comp
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

bool ListWznmJMUserState::operator!=(
			const ListWznmJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMUserState
 ******************************************************************************/

TblWznmJMUserState::TblWznmJMUserState() {
};

TblWznmJMUserState::~TblWznmJMUserState() {
};

bool TblWznmJMUserState::loadRecBySQL(
			const string& sqlstr
			, WznmJMUserState** rec
		) {
	return false;
};

ubigint TblWznmJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMUserState& rst
		) {
	return 0;
};

ubigint TblWznmJMUserState::insertRec(
			WznmJMUserState* rec
		) {
	return 0;
};

ubigint TblWznmJMUserState::insertNewRec(
			WznmJMUserState** rec
			, const ubigint refWznmMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WznmJMUserState* _rec = NULL;

	_rec = new WznmJMUserState(0, refWznmMUser, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMUserState::appendNewRecToRst(
			ListWznmJMUserState& rst
			, WznmJMUserState** rec
			, const ubigint refWznmMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WznmJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUser, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMUserState::insertRst(
			ListWznmJMUserState& rst
			, bool transact
		) {
};

void TblWznmJMUserState::updateRec(
			WznmJMUserState* rec
		) {
};

void TblWznmJMUserState::updateRst(
			ListWznmJMUserState& rst
			, bool transact
		) {
};

void TblWznmJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMUserState::loadRecByRef(
			ubigint ref
			, WznmJMUserState** rec
		) {
	return false;
};

bool TblWznmJMUserState::loadRecByUsrSta(
			ubigint refWznmMUser
			, uint x1Start
			, WznmJMUserState** rec
		) {
	return false;
};

ubigint TblWznmJMUserState::loadRefsByUsr(
			ubigint refWznmMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMUserState::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmJMUserState& rst
		) {
	return 0;
};

ubigint TblWznmJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMUserState& rst
		) {
	ubigint numload = 0;
	WznmJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMUserState
 ******************************************************************************/

MyTblWznmJMUserState::MyTblWznmJMUserState() :
			TblWznmJMUserState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMUserState::~MyTblWznmJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMUserState (refWznmMUser, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMUserState SET refWznmMUser = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMUserState WHERE ref = ?", false);
};

bool MyTblWznmJMUserState::loadRecBySQL(
			const string& sqlstr
			, WznmJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMUserState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMUserState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUser = atoll((char*) dbrow[1]); else _rec->refWznmMUser = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMUserState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMUserState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUser = atoll((char*) dbrow[1]); else rec->refWznmMUser = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMUserState::insertRec(
			WznmJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMUserState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMUserState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMUserState::insertRst(
			ListWznmJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMUserState::updateRec(
			WznmJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMUserState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMUserState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMUserState::updateRst(
			ListWznmJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMUserState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMUserState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMUserState::loadRecByRef(
			ubigint ref
			, WznmJMUserState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMUserState::loadRecByUsrSta(
			ubigint refWznmMUser
			, uint x1Start
			, WznmJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMUser, x1Start, ixVState FROM TblWznmJMUserState WHERE refWznmMUser = " + to_string(refWznmMUser) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWznmJMUserState::loadRefsByUsr(
			ubigint refWznmMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMUserState WHERE refWznmMUser = " + to_string(refWznmMUser) + "", append, refs);
};

ubigint MyTblWznmJMUserState::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMUser, x1Start, ixVState FROM TblWznmJMUserState WHERE refWznmMUser = " + to_string(refWznmMUser) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMUserState
 ******************************************************************************/

PgTblWznmJMUserState::PgTblWznmJMUserState() :
			TblWznmJMUserState()
			, PgTable()
		{
};

PgTblWznmJMUserState::~PgTblWznmJMUserState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMUserState::initStatements() {
	createStatement("TblWznmJMUserState_insertRec", "INSERT INTO TblWznmJMUserState (refWznmMUser, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMUserState_updateRec", "UPDATE TblWznmJMUserState SET refWznmMUser = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMUserState_removeRecByRef", "DELETE FROM TblWznmJMUserState WHERE ref = $1", 1);

	createStatement("TblWznmJMUserState_loadRecByRef", "SELECT ref, refWznmMUser, x1Start, ixVState FROM TblWznmJMUserState WHERE ref = $1", 1);
	createStatement("TblWznmJMUserState_loadRecByUsrSta", "SELECT ref, refWznmMUser, x1Start, ixVState FROM TblWznmJMUserState WHERE refWznmMUser = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWznmJMUserState_loadRefsByUsr", "SELECT ref FROM TblWznmJMUserState WHERE refWznmMUser = $1", 1);
	createStatement("TblWznmJMUserState_loadRstByUsr", "SELECT ref, refWznmMUser, x1Start, ixVState FROM TblWznmJMUserState WHERE refWznmMUser = $1 ORDER BY x1Start ASC", 1);
};

bool PgTblWznmJMUserState::loadRec(
			PGresult* res
			, WznmJMUserState** rec
		) {
	char* ptr;

	WznmJMUserState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMUserState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMUserState::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMUserState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMUserState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WznmJMUserState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMUserState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMUserState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMUserState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMUserState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMUserState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMUserState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMUserState::loadRecBySQL(
			const string& sqlstr
			, WznmJMUserState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMUserState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMUserState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMUserState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMUserState::insertRec(
			WznmJMUserState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMUserState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMUserState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMUserState::insertRst(
			ListWznmJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMUserState::updateRec(
			WznmJMUserState* rec
		) {
	PGresult* res;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_x1Start,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMUserState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMUserState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMUserState::updateRst(
			ListWznmJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMUserState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMUserState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMUserState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMUserState::loadRecByRef(
			ubigint ref
			, WznmJMUserState** rec
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

	return loadRecByStmt("TblWznmJMUserState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMUserState::loadRecByUsrSta(
			ubigint refWznmMUser
			, uint x1Start
			, WznmJMUserState** rec
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMUserState_loadRecByUsrSta", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMUserState::loadRefsByUsr(
			ubigint refWznmMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);

	const char* vals[] = {
		(char*) &_refWznmMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMUserState_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMUserState::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmJMUserState& rst
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);

	const char* vals[] = {
		(char*) &_refWznmMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMUserState_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

