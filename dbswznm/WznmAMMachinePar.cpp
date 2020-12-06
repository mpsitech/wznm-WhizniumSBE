/**
	* \file WznmAMMachinePar.cpp
	* database access for table TblWznmAMMachinePar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMMachinePar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMMachinePar
 ******************************************************************************/

WznmAMMachinePar::WznmAMMachinePar(
			const ubigint ref
			, const ubigint refWznmMMachine
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refWznmMMachine = refWznmMMachine;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WznmAMMachinePar::operator==(
			const WznmAMMachinePar& comp
		) {
	return false;
};

bool WznmAMMachinePar::operator!=(
			const WznmAMMachinePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMMachinePar
 ******************************************************************************/

ListWznmAMMachinePar::ListWznmAMMachinePar() {
};

ListWznmAMMachinePar::ListWznmAMMachinePar(
			const ListWznmAMMachinePar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMMachinePar(*(src.nodes[i]));
};

ListWznmAMMachinePar::~ListWznmAMMachinePar() {
	clear();
};

void ListWznmAMMachinePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMMachinePar::size() const {
	return(nodes.size());
};

void ListWznmAMMachinePar::append(
			WznmAMMachinePar* rec
		) {
	nodes.push_back(rec);
};

WznmAMMachinePar* ListWznmAMMachinePar::operator[](
			const uint ix
		) {
	WznmAMMachinePar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMMachinePar& ListWznmAMMachinePar::operator=(
			const ListWznmAMMachinePar& src
		) {
	WznmAMMachinePar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMMachinePar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMMachinePar::operator==(
			const ListWznmAMMachinePar& comp
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

bool ListWznmAMMachinePar::operator!=(
			const ListWznmAMMachinePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMMachinePar
 ******************************************************************************/

TblWznmAMMachinePar::TblWznmAMMachinePar() {
};

TblWznmAMMachinePar::~TblWznmAMMachinePar() {
};

bool TblWznmAMMachinePar::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachinePar** rec
		) {
	return false;
};

ubigint TblWznmAMMachinePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	return 0;
};

ubigint TblWznmAMMachinePar::insertRec(
			WznmAMMachinePar* rec
		) {
	return 0;
};

ubigint TblWznmAMMachinePar::insertNewRec(
			WznmAMMachinePar** rec
			, const ubigint refWznmMMachine
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMMachinePar* _rec = NULL;

	_rec = new WznmAMMachinePar(0, refWznmMMachine, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMMachinePar::appendNewRecToRst(
			ListWznmAMMachinePar& rst
			, WznmAMMachinePar** rec
			, const ubigint refWznmMMachine
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMMachinePar* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMMachine, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMMachinePar::insertRst(
			ListWznmAMMachinePar& rst
			, bool transact
		) {
};

void TblWznmAMMachinePar::updateRec(
			WznmAMMachinePar* rec
		) {
};

void TblWznmAMMachinePar::updateRst(
			ListWznmAMMachinePar& rst
			, bool transact
		) {
};

void TblWznmAMMachinePar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMMachinePar::loadRecByRef(
			ubigint ref
			, WznmAMMachinePar** rec
		) {
	return false;
};

ubigint TblWznmAMMachinePar::loadRefsByMch(
			ubigint refWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMMachinePar::loadRstByMch(
			ubigint refWznmMMachine
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	return 0;
};

bool TblWznmAMMachinePar::loadValByMchKey(
			ubigint refWznmMMachine
			, string x1SrefKKey
			, string& Val
		) {
	return false;
};

ubigint TblWznmAMMachinePar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	ubigint numload = 0;
	WznmAMMachinePar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMMachinePar
 ******************************************************************************/

MyTblWznmAMMachinePar::MyTblWznmAMMachinePar() :
			TblWznmAMMachinePar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMMachinePar::~MyTblWznmAMMachinePar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMMachinePar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMMachinePar (refWznmMMachine, x1SrefKKey, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMMachinePar SET refWznmMMachine = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMMachinePar WHERE ref = ?", false);
};

bool MyTblWznmAMMachinePar::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachinePar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMMachinePar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMachinePar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMachinePar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMMachinePar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMMachine = atoll((char*) dbrow[1]); else _rec->refWznmMMachine = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMMachinePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMMachinePar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMachinePar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMachinePar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMMachinePar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMMachine = atoll((char*) dbrow[1]); else rec->refWznmMMachine = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMMachinePar::insertRec(
			WznmAMMachinePar* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMMachinePar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMMachinePar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMMachinePar::insertRst(
			ListWznmAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMMachinePar::updateRec(
			WznmAMMachinePar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMMachinePar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMMachinePar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMMachinePar::updateRst(
			ListWznmAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMMachinePar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMMachinePar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMMachinePar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMMachinePar::loadRecByRef(
			ubigint ref
			, WznmAMMachinePar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMMachinePar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMMachinePar::loadRefsByMch(
			ubigint refWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMMachinePar WHERE refWznmMMachine = " + to_string(refWznmMMachine) + "", append, refs);
};

ubigint MyTblWznmAMMachinePar::loadRstByMch(
			ubigint refWznmMMachine
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMMachine, x1SrefKKey, Val FROM TblWznmAMMachinePar WHERE refWznmMMachine = " + to_string(refWznmMMachine) + " ORDER BY x1SrefKKey ASC", append, rst);
};

bool MyTblWznmAMMachinePar::loadValByMchKey(
			ubigint refWznmMMachine
			, string x1SrefKKey
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWznmAMMachinePar WHERE refWznmMMachine = " + to_string(refWznmMMachine) + " AND x1SrefKKey = '" + x1SrefKKey + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMMachinePar
 ******************************************************************************/

PgTblWznmAMMachinePar::PgTblWznmAMMachinePar() :
			TblWznmAMMachinePar()
			, PgTable()
		{
};

PgTblWznmAMMachinePar::~PgTblWznmAMMachinePar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMMachinePar::initStatements() {
	createStatement("TblWznmAMMachinePar_insertRec", "INSERT INTO TblWznmAMMachinePar (refWznmMMachine, x1SrefKKey, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmAMMachinePar_updateRec", "UPDATE TblWznmAMMachinePar SET refWznmMMachine = $1, x1SrefKKey = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWznmAMMachinePar_removeRecByRef", "DELETE FROM TblWznmAMMachinePar WHERE ref = $1", 1);

	createStatement("TblWznmAMMachinePar_loadRecByRef", "SELECT ref, refWznmMMachine, x1SrefKKey, Val FROM TblWznmAMMachinePar WHERE ref = $1", 1);
	createStatement("TblWznmAMMachinePar_loadRefsByMch", "SELECT ref FROM TblWznmAMMachinePar WHERE refWznmMMachine = $1", 1);
	createStatement("TblWznmAMMachinePar_loadRstByMch", "SELECT ref, refWznmMMachine, x1SrefKKey, Val FROM TblWznmAMMachinePar WHERE refWznmMMachine = $1 ORDER BY x1SrefKKey ASC", 1);
	createStatement("TblWznmAMMachinePar_loadValByMchKey", "SELECT Val FROM TblWznmAMMachinePar WHERE refWznmMMachine = $1 AND x1SrefKKey = $2", 2);
};

bool PgTblWznmAMMachinePar::loadRec(
			PGresult* res
			, WznmAMMachinePar** rec
		) {
	char* ptr;

	WznmAMMachinePar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMMachinePar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachine"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMMachinePar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMMachinePar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachine"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAMMachinePar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMMachinePar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMMachinePar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachinePar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMachinePar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachinePar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMMachinePar::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachinePar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachinePar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMachinePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachinePar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMMachinePar::insertRec(
			WznmAMMachinePar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMMachinePar_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachinePar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMMachinePar::insertRst(
			ListWznmAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMMachinePar::updateRec(
			WznmAMMachinePar* rec
		) {
	PGresult* res;

	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMMachine,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMMachinePar_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMachinePar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMMachinePar::updateRst(
			ListWznmAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMMachinePar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMMachinePar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMachinePar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMMachinePar::loadRecByRef(
			ubigint ref
			, WznmAMMachinePar** rec
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

	return loadRecByStmt("TblWznmAMMachinePar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMMachinePar::loadRefsByMch(
			ubigint refWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMMachine = htonl64(refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMMachinePar_loadRefsByMch", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMMachinePar::loadRstByMch(
			ubigint refWznmMMachine
			, const bool append
			, ListWznmAMMachinePar& rst
		) {
	ubigint _refWznmMMachine = htonl64(refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMMachinePar_loadRstByMch", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMMachinePar::loadValByMchKey(
			ubigint refWznmMMachine
			, string x1SrefKKey
			, string& Val
		) {
	ubigint _refWznmMMachine = htonl64(refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine,
		x1SrefKKey.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadStringByStmt("TblWznmAMMachinePar_loadValByMchKey", 2, vals, l, f, Val);
};

#endif
