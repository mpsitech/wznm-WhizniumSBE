/**
	* \file WznmAccRMUserUniversal.cpp
	* database access for table TblWznmAccRMUserUniversal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAccRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAccRMUserUniversal
 ******************************************************************************/

WznmAccRMUserUniversal::WznmAccRMUserUniversal(
			const ubigint ref
			, const ubigint refWznmMUser
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVRecaccess
		) {

	this->ref = ref;
	this->refWznmMUser = refWznmMUser;
	this->unvIxWznmVMaintable = unvIxWznmVMaintable;
	this->unvUref = unvUref;
	this->ixWznmVRecaccess = ixWznmVRecaccess;
};

bool WznmAccRMUserUniversal::operator==(
			const WznmAccRMUserUniversal& comp
		) {
	return false;
};

bool WznmAccRMUserUniversal::operator!=(
			const WznmAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAccRMUserUniversal
 ******************************************************************************/

ListWznmAccRMUserUniversal::ListWznmAccRMUserUniversal() {
};

ListWznmAccRMUserUniversal::ListWznmAccRMUserUniversal(
			const ListWznmAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAccRMUserUniversal(*(src.nodes[i]));
};

ListWznmAccRMUserUniversal::~ListWznmAccRMUserUniversal() {
	clear();
};

void ListWznmAccRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWznmAccRMUserUniversal::append(
			WznmAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WznmAccRMUserUniversal* ListWznmAccRMUserUniversal::operator[](
			const uint ix
		) {
	WznmAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAccRMUserUniversal& ListWznmAccRMUserUniversal::operator=(
			const ListWznmAccRMUserUniversal& src
		) {
	WznmAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAccRMUserUniversal::operator==(
			const ListWznmAccRMUserUniversal& comp
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

bool ListWznmAccRMUserUniversal::operator!=(
			const ListWznmAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAccRMUserUniversal
 ******************************************************************************/

TblWznmAccRMUserUniversal::TblWznmAccRMUserUniversal() {
};

TblWznmAccRMUserUniversal::~TblWznmAccRMUserUniversal() {
};

bool TblWznmAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWznmAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAccRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWznmAccRMUserUniversal::insertRec(
			WznmAccRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWznmAccRMUserUniversal::insertNewRec(
			WznmAccRMUserUniversal** rec
			, const ubigint refWznmMUser
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVRecaccess
		) {
	ubigint retval = 0;
	WznmAccRMUserUniversal* _rec = NULL;

	_rec = new WznmAccRMUserUniversal(0, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAccRMUserUniversal::appendNewRecToRst(
			ListWznmAccRMUserUniversal& rst
			, WznmAccRMUserUniversal** rec
			, const ubigint refWznmMUser
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVRecaccess
		) {
	ubigint retval = 0;
	WznmAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAccRMUserUniversal::insertRst(
			ListWznmAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWznmAccRMUserUniversal::updateRec(
			WznmAccRMUserUniversal* rec
		) {
};

void TblWznmAccRMUserUniversal::updateRst(
			ListWznmAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWznmAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WznmAccRMUserUniversal** rec
		) {
	return false;
};

bool TblWznmAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, WznmAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWznmAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WznmAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAccRMUserUniversal
 ******************************************************************************/

MyTblWznmAccRMUserUniversal::MyTblWznmAccRMUserUniversal() :
			TblWznmAccRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAccRMUserUniversal::~MyTblWznmAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAccRMUserUniversal (refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAccRMUserUniversal SET refWznmMUser = ?, unvIxWznmVMaintable = ?, unvUref = ?, ixWznmVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWznmAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAccRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAccRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUser = atoll((char*) dbrow[1]); else _rec->refWznmMUser = 0;
		if (dbrow[2]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWznmVRecaccess = atol((char*) dbrow[4]); else _rec->ixWznmVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAccRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAccRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUser = atoll((char*) dbrow[1]); else rec->refWznmMUser = 0;
			if (dbrow[2]) rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else rec->unvIxWznmVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWznmVRecaccess = atol((char*) dbrow[4]); else rec->ixWznmVRecaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAccRMUserUniversal::insertRec(
			WznmAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAccRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAccRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAccRMUserUniversal::insertRst(
			ListWznmAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAccRMUserUniversal::updateRec(
			WznmAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAccRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAccRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAccRMUserUniversal::updateRst(
			ListWznmAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAccRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAccRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WznmAccRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, WznmAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess FROM TblWznmAccRMUserUniversal WHERE refWznmMUser = " + to_string(refWznmMUser) + " AND unvIxWznmVMaintable = " + to_string(unvIxWznmVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAccRMUserUniversal
 ******************************************************************************/

PgTblWznmAccRMUserUniversal::PgTblWznmAccRMUserUniversal() :
			TblWznmAccRMUserUniversal()
			, PgTable()
		{
};

PgTblWznmAccRMUserUniversal::~PgTblWznmAccRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAccRMUserUniversal::initStatements() {
	createStatement("TblWznmAccRMUserUniversal_insertRec", "INSERT INTO TblWznmAccRMUserUniversal (refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAccRMUserUniversal_updateRec", "UPDATE TblWznmAccRMUserUniversal SET refWznmMUser = $1, unvIxWznmVMaintable = $2, unvUref = $3, ixWznmVRecaccess = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAccRMUserUniversal_removeRecByRef", "DELETE FROM TblWznmAccRMUserUniversal WHERE ref = $1", 1);

	createStatement("TblWznmAccRMUserUniversal_loadRecByRef", "SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess FROM TblWznmAccRMUserUniversal WHERE ref = $1", 1);
	createStatement("TblWznmAccRMUserUniversal_loadRecByUsrMtbUnv", "SELECT ref, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess FROM TblWznmAccRMUserUniversal WHERE refWznmMUser = $1 AND unvIxWznmVMaintable = $2 AND unvUref = $3", 3);
};

bool PgTblWznmAccRMUserUniversal::loadRec(
			PGresult* res
			, WznmAccRMUserUniversal** rec
		) {
	char* ptr;

	WznmAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAccRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwznmvrecaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmVRecaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAccRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAccRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAccRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwznmvrecaccess")
		};

		while (numread < numrow) {
			rec = new WznmAccRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWznmVRecaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAccRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAccRMUserUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAccRMUserUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAccRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAccRMUserUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAccRMUserUniversal::insertRec(
			WznmAccRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWznmVRecaccess = htonl(rec->ixWznmVRecaccess);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWznmVRecaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAccRMUserUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAccRMUserUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAccRMUserUniversal::insertRst(
			ListWznmAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAccRMUserUniversal::updateRec(
			WznmAccRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWznmVRecaccess = htonl(rec->ixWznmVRecaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWznmVRecaccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAccRMUserUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAccRMUserUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAccRMUserUniversal::updateRst(
			ListWznmAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAccRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAccRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAccRMUserUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WznmAccRMUserUniversal** rec
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

	return loadRecByStmt("TblWznmAccRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWznmMUser
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, WznmAccRMUserUniversal** rec
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);
	uint _unvIxWznmVMaintable = htonl(unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblWznmAccRMUserUniversal_loadRecByUsrMtbUnv", 3, vals, l, f, rec);
};

#endif
