/**
	* \file WznmRMUserMUsergroup.cpp
	* database access for table TblWznmRMUserMUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMUserMUsergroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMUserMUsergroup
 ******************************************************************************/

WznmRMUserMUsergroup::WznmRMUserMUsergroup(
			const ubigint ref
			, const ubigint refWznmMUser
			, const ubigint refWznmMUsergroup
			, const uint ixWznmVUserlevel
		) {

	this->ref = ref;
	this->refWznmMUser = refWznmMUser;
	this->refWznmMUsergroup = refWznmMUsergroup;
	this->ixWznmVUserlevel = ixWznmVUserlevel;
};

bool WznmRMUserMUsergroup::operator==(
			const WznmRMUserMUsergroup& comp
		) {
	return false;
};

bool WznmRMUserMUsergroup::operator!=(
			const WznmRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMUserMUsergroup
 ******************************************************************************/

ListWznmRMUserMUsergroup::ListWznmRMUserMUsergroup() {
};

ListWznmRMUserMUsergroup::ListWznmRMUserMUsergroup(
			const ListWznmRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMUserMUsergroup(*(src.nodes[i]));
};

ListWznmRMUserMUsergroup::~ListWznmRMUserMUsergroup() {
	clear();
};

void ListWznmRMUserMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListWznmRMUserMUsergroup::append(
			WznmRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

WznmRMUserMUsergroup* ListWznmRMUserMUsergroup::operator[](
			const uint ix
		) {
	WznmRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMUserMUsergroup& ListWznmRMUserMUsergroup::operator=(
			const ListWznmRMUserMUsergroup& src
		) {
	WznmRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMUserMUsergroup::operator==(
			const ListWznmRMUserMUsergroup& comp
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

bool ListWznmRMUserMUsergroup::operator!=(
			const ListWznmRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMUserMUsergroup
 ******************************************************************************/

TblWznmRMUserMUsergroup::TblWznmRMUserMUsergroup() {
};

TblWznmRMUserMUsergroup::~TblWznmRMUserMUsergroup() {
};

bool TblWznmRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWznmRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWznmRMUserMUsergroup::insertRec(
			WznmRMUserMUsergroup* rec
		) {
	return 0;
};

ubigint TblWznmRMUserMUsergroup::insertNewRec(
			WznmRMUserMUsergroup** rec
			, const ubigint refWznmMUser
			, const ubigint refWznmMUsergroup
			, const uint ixWznmVUserlevel
		) {
	ubigint retval = 0;
	WznmRMUserMUsergroup* _rec = NULL;

	_rec = new WznmRMUserMUsergroup(0, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMUserMUsergroup::appendNewRecToRst(
			ListWznmRMUserMUsergroup& rst
			, WznmRMUserMUsergroup** rec
			, const ubigint refWznmMUser
			, const ubigint refWznmMUsergroup
			, const uint ixWznmVUserlevel
		) {
	ubigint retval = 0;
	WznmRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMUserMUsergroup::insertRst(
			ListWznmRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWznmRMUserMUsergroup::updateRec(
			WznmRMUserMUsergroup* rec
		) {
};

void TblWznmRMUserMUsergroup::updateRst(
			ListWznmRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWznmRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WznmRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWznmRMUserMUsergroup::loadRstByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWznmRMUserMUsergroup::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWznmRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	WznmRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMUserMUsergroup
 ******************************************************************************/

MyTblWznmRMUserMUsergroup::MyTblWznmRMUserMUsergroup() :
			TblWznmRMUserMUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMUserMUsergroup::~MyTblWznmRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMUserMUsergroup (refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMUserMUsergroup SET refWznmMUser = ?, refWznmMUsergroup = ?, ixWznmVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblWznmRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMUserMUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMUserMUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUser = atoll((char*) dbrow[1]); else _rec->refWznmMUser = 0;
		if (dbrow[2]) _rec->refWznmMUsergroup = atoll((char*) dbrow[2]); else _rec->refWznmMUsergroup = 0;
		if (dbrow[3]) _rec->ixWznmVUserlevel = atol((char*) dbrow[3]); else _rec->ixWznmVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMUserMUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMUserMUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUser = atoll((char*) dbrow[1]); else rec->refWznmMUser = 0;
			if (dbrow[2]) rec->refWznmMUsergroup = atoll((char*) dbrow[2]); else rec->refWznmMUsergroup = 0;
			if (dbrow[3]) rec->ixWznmVUserlevel = atol((char*) dbrow[3]); else rec->ixWznmVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMUserMUsergroup::insertRec(
			WznmRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWznmVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMUserMUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMUserMUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMUserMUsergroup::insertRst(
			ListWznmRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMUserMUsergroup::updateRec(
			WznmRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWznmVUserlevel,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMUserMUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMUserMUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMUserMUsergroup::updateRst(
			ListWznmRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMUserMUsergroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMUserMUsergroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WznmRMUserMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMUserMUsergroup::loadRstByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel FROM TblWznmRMUserMUsergroup WHERE refWznmMUsergroup = " + to_string(refWznmMUsergroup) + "", append, rst);
};

ubigint MyTblWznmRMUserMUsergroup::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel FROM TblWznmRMUserMUsergroup WHERE refWznmMUser = " + to_string(refWznmMUser) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMUserMUsergroup
 ******************************************************************************/

PgTblWznmRMUserMUsergroup::PgTblWznmRMUserMUsergroup() :
			TblWznmRMUserMUsergroup()
			, PgTable()
		{
};

PgTblWznmRMUserMUsergroup::~PgTblWznmRMUserMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMUserMUsergroup::initStatements() {
	createStatement("TblWznmRMUserMUsergroup_insertRec", "INSERT INTO TblWznmRMUserMUsergroup (refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmRMUserMUsergroup_updateRec", "UPDATE TblWznmRMUserMUsergroup SET refWznmMUser = $1, refWznmMUsergroup = $2, ixWznmVUserlevel = $3 WHERE ref = $4", 4);
	createStatement("TblWznmRMUserMUsergroup_removeRecByRef", "DELETE FROM TblWznmRMUserMUsergroup WHERE ref = $1", 1);

	createStatement("TblWznmRMUserMUsergroup_loadRecByRef", "SELECT ref, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel FROM TblWznmRMUserMUsergroup WHERE ref = $1", 1);
	createStatement("TblWznmRMUserMUsergroup_loadRstByUsg", "SELECT ref, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel FROM TblWznmRMUserMUsergroup WHERE refWznmMUsergroup = $1", 1);
	createStatement("TblWznmRMUserMUsergroup_loadRstByUsr", "SELECT ref, refWznmMUser, refWznmMUsergroup, ixWznmVUserlevel FROM TblWznmRMUserMUsergroup WHERE refWznmMUser = $1", 1);
};

bool PgTblWznmRMUserMUsergroup::loadRec(
			PGresult* res
			, WznmRMUserMUsergroup** rec
		) {
	char* ptr;

	WznmRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMUserMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "ixwznmvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWznmVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMUserMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMUserMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "ixwznmvuserlevel")
		};

		while (numread < numrow) {
			rec = new WznmRMUserMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWznmVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMUserMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMUserMUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMUserMUsergroup::insertRec(
			WznmRMUserMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_refWznmMUsergroup,
		(char*) &_ixWznmVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMUserMUsergroup_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMUserMUsergroup::insertRst(
			ListWznmRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMUserMUsergroup::updateRec(
			WznmRMUserMUsergroup* rec
		) {
	PGresult* res;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_refWznmMUsergroup,
		(char*) &_ixWznmVUserlevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMUserMUsergroup_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMUserMUsergroup::updateRst(
			ListWznmRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMUserMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMUserMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMUserMUsergroup::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WznmRMUserMUsergroup** rec
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

	return loadRecByStmt("TblWznmRMUserMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMUserMUsergroup::loadRstByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	ubigint _refWznmMUsergroup = htonl64(refWznmMUsergroup);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMUserMUsergroup_loadRstByUsg", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmRMUserMUsergroup::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmRMUserMUsergroup& rst
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);

	const char* vals[] = {
		(char*) &_refWznmMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMUserMUsergroup_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

