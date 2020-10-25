/**
	* \file WznmJMVersionState.cpp
	* database access for table TblWznmJMVersionState (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmJMVersionState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMVersionState
 ******************************************************************************/

WznmJMVersionState::WznmJMVersionState(
			const ubigint ref
			, const ubigint refWznmMVersion
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refWznmMVersion = refWznmMVersion;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool WznmJMVersionState::operator==(
			const WznmJMVersionState& comp
		) {
	return false;
};

bool WznmJMVersionState::operator!=(
			const WznmJMVersionState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMVersionState
 ******************************************************************************/

ListWznmJMVersionState::ListWznmJMVersionState() {
};

ListWznmJMVersionState::ListWznmJMVersionState(
			const ListWznmJMVersionState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMVersionState(*(src.nodes[i]));
};

ListWznmJMVersionState::~ListWznmJMVersionState() {
	clear();
};

void ListWznmJMVersionState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMVersionState::size() const {
	return(nodes.size());
};

void ListWznmJMVersionState::append(
			WznmJMVersionState* rec
		) {
	nodes.push_back(rec);
};

WznmJMVersionState* ListWznmJMVersionState::operator[](
			const uint ix
		) {
	WznmJMVersionState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMVersionState& ListWznmJMVersionState::operator=(
			const ListWznmJMVersionState& src
		) {
	WznmJMVersionState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMVersionState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMVersionState::operator==(
			const ListWznmJMVersionState& comp
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

bool ListWznmJMVersionState::operator!=(
			const ListWznmJMVersionState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMVersionState
 ******************************************************************************/

TblWznmJMVersionState::TblWznmJMVersionState() {
};

TblWznmJMVersionState::~TblWznmJMVersionState() {
};

bool TblWznmJMVersionState::loadRecBySQL(
			const string& sqlstr
			, WznmJMVersionState** rec
		) {
	return false;
};

ubigint TblWznmJMVersionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	return 0;
};

ubigint TblWznmJMVersionState::insertRec(
			WznmJMVersionState* rec
		) {
	return 0;
};

ubigint TblWznmJMVersionState::insertNewRec(
			WznmJMVersionState** rec
			, const ubigint refWznmMVersion
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WznmJMVersionState* _rec = NULL;

	_rec = new WznmJMVersionState(0, refWznmMVersion, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMVersionState::appendNewRecToRst(
			ListWznmJMVersionState& rst
			, WznmJMVersionState** rec
			, const ubigint refWznmMVersion
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WznmJMVersionState* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVersion, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMVersionState::insertRst(
			ListWznmJMVersionState& rst
			, bool transact
		) {
};

void TblWznmJMVersionState::updateRec(
			WznmJMVersionState* rec
		) {
};

void TblWznmJMVersionState::updateRst(
			ListWznmJMVersionState& rst
			, bool transact
		) {
};

void TblWznmJMVersionState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMVersionState::loadRecByRef(
			ubigint ref
			, WznmJMVersionState** rec
		) {
	return false;
};

bool TblWznmJMVersionState::loadRecByVerSta(
			ubigint refWznmMVersion
			, uint x1Start
			, WznmJMVersionState** rec
		) {
	return false;
};

ubigint TblWznmJMVersionState::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMVersionState::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	return 0;
};

ubigint TblWznmJMVersionState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	ubigint numload = 0;
	WznmJMVersionState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMVersionState
 ******************************************************************************/

MyTblWznmJMVersionState::MyTblWznmJMVersionState() :
			TblWznmJMVersionState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMVersionState::~MyTblWznmJMVersionState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMVersionState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMVersionState (refWznmMVersion, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMVersionState SET refWznmMVersion = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMVersionState WHERE ref = ?", false);
};

bool MyTblWznmJMVersionState::loadRecBySQL(
			const string& sqlstr
			, WznmJMVersionState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMVersionState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMVersionState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMVersionState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmJMVersionState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVersion = atoll((char*) dbrow[1]); else _rec->refWznmMVersion = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMVersionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMVersionState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMVersionState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMVersionState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmJMVersionState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVersion = atoll((char*) dbrow[1]); else rec->refWznmMVersion = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMVersionState::insertRec(
			WznmJMVersionState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMVersionState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMVersionState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMVersionState::insertRst(
			ListWznmJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMVersionState::updateRec(
			WznmJMVersionState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMVersionState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMVersionState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMVersionState::updateRst(
			ListWznmJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMVersionState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMVersionState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMVersionState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMVersionState::loadRecByRef(
			ubigint ref
			, WznmJMVersionState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMVersionState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMVersionState::loadRecByVerSta(
			ubigint refWznmMVersion
			, uint x1Start
			, WznmJMVersionState** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMVersion, x1Start, ixVState FROM TblWznmJMVersionState WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWznmJMVersionState::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMVersionState WHERE refWznmMVersion = " + to_string(refWznmMVersion) + "", append, refs);
};

ubigint MyTblWznmJMVersionState::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVersion, x1Start, ixVState FROM TblWznmJMVersionState WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMVersionState
 ******************************************************************************/

PgTblWznmJMVersionState::PgTblWznmJMVersionState() :
			TblWznmJMVersionState()
			, PgTable()
		{
};

PgTblWznmJMVersionState::~PgTblWznmJMVersionState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMVersionState::initStatements() {
	createStatement("TblWznmJMVersionState_insertRec", "INSERT INTO TblWznmJMVersionState (refWznmMVersion, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMVersionState_updateRec", "UPDATE TblWznmJMVersionState SET refWznmMVersion = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMVersionState_removeRecByRef", "DELETE FROM TblWznmJMVersionState WHERE ref = $1", 1);

	createStatement("TblWznmJMVersionState_loadRecByRef", "SELECT ref, refWznmMVersion, x1Start, ixVState FROM TblWznmJMVersionState WHERE ref = $1", 1);
	createStatement("TblWznmJMVersionState_loadRecByVerSta", "SELECT ref, refWznmMVersion, x1Start, ixVState FROM TblWznmJMVersionState WHERE refWznmMVersion = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWznmJMVersionState_loadRefsByVer", "SELECT ref FROM TblWznmJMVersionState WHERE refWznmMVersion = $1", 1);
	createStatement("TblWznmJMVersionState_loadRstByVer", "SELECT ref, refWznmMVersion, x1Start, ixVState FROM TblWznmJMVersionState WHERE refWznmMVersion = $1 ORDER BY x1Start ASC", 1);
};

bool PgTblWznmJMVersionState::loadRec(
			PGresult* res
			, WznmJMVersionState** rec
		) {
	char* ptr;

	WznmJMVersionState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMVersionState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMVersionState::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMVersionState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WznmJMVersionState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMVersionState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMVersionState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersionState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMVersionState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersionState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMVersionState::loadRecBySQL(
			const string& sqlstr
			, WznmJMVersionState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersionState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMVersionState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersionState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMVersionState::insertRec(
			WznmJMVersionState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMVersionState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersionState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMVersionState::insertRst(
			ListWznmJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMVersionState::updateRec(
			WznmJMVersionState* rec
		) {
	PGresult* res;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
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

	res = PQexecPrepared(dbs, "TblWznmJMVersionState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMVersionState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMVersionState::updateRst(
			ListWznmJMVersionState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMVersionState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMVersionState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMVersionState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMVersionState::loadRecByRef(
			ubigint ref
			, WznmJMVersionState** rec
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

	return loadRecByStmt("TblWznmJMVersionState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMVersionState::loadRecByVerSta(
			ubigint refWznmMVersion
			, uint x1Start
			, WznmJMVersionState** rec
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMVersionState_loadRecByVerSta", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMVersionState::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMVersionState_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMVersionState::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmJMVersionState& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMVersionState_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

