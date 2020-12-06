/**
	* \file WznmRMUsergroupUniversal.cpp
	* database access for table TblWznmRMUsergroupUniversal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMUsergroupUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMUsergroupUniversal
 ******************************************************************************/

WznmRMUsergroupUniversal::WznmRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refWznmMUsergroup
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVRecaccess
		) {

	this->ref = ref;
	this->refWznmMUsergroup = refWznmMUsergroup;
	this->unvIxWznmVMaintable = unvIxWznmVMaintable;
	this->unvUref = unvUref;
	this->ixWznmVRecaccess = ixWznmVRecaccess;
};

bool WznmRMUsergroupUniversal::operator==(
			const WznmRMUsergroupUniversal& comp
		) {
	return false;
};

bool WznmRMUsergroupUniversal::operator!=(
			const WznmRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMUsergroupUniversal
 ******************************************************************************/

ListWznmRMUsergroupUniversal::ListWznmRMUsergroupUniversal() {
};

ListWznmRMUsergroupUniversal::ListWznmRMUsergroupUniversal(
			const ListWznmRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMUsergroupUniversal(*(src.nodes[i]));
};

ListWznmRMUsergroupUniversal::~ListWznmRMUsergroupUniversal() {
	clear();
};

void ListWznmRMUsergroupUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListWznmRMUsergroupUniversal::append(
			WznmRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

WznmRMUsergroupUniversal* ListWznmRMUsergroupUniversal::operator[](
			const uint ix
		) {
	WznmRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMUsergroupUniversal& ListWznmRMUsergroupUniversal::operator=(
			const ListWznmRMUsergroupUniversal& src
		) {
	WznmRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMUsergroupUniversal::operator==(
			const ListWznmRMUsergroupUniversal& comp
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

bool ListWznmRMUsergroupUniversal::operator!=(
			const ListWznmRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMUsergroupUniversal
 ******************************************************************************/

TblWznmRMUsergroupUniversal::TblWznmRMUsergroupUniversal() {
};

TblWznmRMUsergroupUniversal::~TblWznmRMUsergroupUniversal() {
};

bool TblWznmRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWznmRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMUsergroupUniversal& rst
		) {
	return 0;
};

ubigint TblWznmRMUsergroupUniversal::insertRec(
			WznmRMUsergroupUniversal* rec
		) {
	return 0;
};

ubigint TblWznmRMUsergroupUniversal::insertNewRec(
			WznmRMUsergroupUniversal** rec
			, const ubigint refWznmMUsergroup
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVRecaccess
		) {
	ubigint retval = 0;
	WznmRMUsergroupUniversal* _rec = NULL;

	_rec = new WznmRMUsergroupUniversal(0, refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMUsergroupUniversal::appendNewRecToRst(
			ListWznmRMUsergroupUniversal& rst
			, WznmRMUsergroupUniversal** rec
			, const ubigint refWznmMUsergroup
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const uint ixWznmVRecaccess
		) {
	ubigint retval = 0;
	WznmRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMUsergroupUniversal::insertRst(
			ListWznmRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWznmRMUsergroupUniversal::updateRec(
			WznmRMUsergroupUniversal* rec
		) {
};

void TblWznmRMUsergroupUniversal::updateRst(
			ListWznmRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWznmRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WznmRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblWznmRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWznmMUsergroup
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, WznmRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWznmRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	WznmRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMUsergroupUniversal
 ******************************************************************************/

MyTblWznmRMUsergroupUniversal::MyTblWznmRMUsergroupUniversal() :
			TblWznmRMUsergroupUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMUsergroupUniversal::~MyTblWznmRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMUsergroupUniversal (refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMUsergroupUniversal SET refWznmMUsergroup = ?, unvIxWznmVMaintable = ?, unvUref = ?, ixWznmVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblWznmRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMUsergroupUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMUsergroupUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUsergroup = atoll((char*) dbrow[1]); else _rec->refWznmMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWznmVRecaccess = atol((char*) dbrow[4]); else _rec->ixWznmVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMUsergroupUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMUsergroupUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUsergroup = atoll((char*) dbrow[1]); else rec->refWznmMUsergroup = 0;
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

ubigint MyTblWznmRMUsergroupUniversal::insertRec(
			WznmRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMUsergroupUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMUsergroupUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMUsergroupUniversal::insertRst(
			ListWznmRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMUsergroupUniversal::updateRec(
			WznmRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMUsergroupUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMUsergroupUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMUsergroupUniversal::updateRst(
			ListWznmRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMUsergroupUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMUsergroupUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WznmRMUsergroupUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWznmMUsergroup
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, WznmRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess FROM TblWznmRMUsergroupUniversal WHERE refWznmMUsergroup = " + to_string(refWznmMUsergroup) + " AND unvIxWznmVMaintable = " + to_string(unvIxWznmVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMUsergroupUniversal
 ******************************************************************************/

PgTblWznmRMUsergroupUniversal::PgTblWznmRMUsergroupUniversal() :
			TblWznmRMUsergroupUniversal()
			, PgTable()
		{
};

PgTblWznmRMUsergroupUniversal::~PgTblWznmRMUsergroupUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMUsergroupUniversal::initStatements() {
	createStatement("TblWznmRMUsergroupUniversal_insertRec", "INSERT INTO TblWznmRMUsergroupUniversal (refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmRMUsergroupUniversal_updateRec", "UPDATE TblWznmRMUsergroupUniversal SET refWznmMUsergroup = $1, unvIxWznmVMaintable = $2, unvUref = $3, ixWznmVRecaccess = $4 WHERE ref = $5", 5);
	createStatement("TblWznmRMUsergroupUniversal_removeRecByRef", "DELETE FROM TblWznmRMUsergroupUniversal WHERE ref = $1", 1);

	createStatement("TblWznmRMUsergroupUniversal_loadRecByRef", "SELECT ref, refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess FROM TblWznmRMUsergroupUniversal WHERE ref = $1", 1);
	createStatement("TblWznmRMUsergroupUniversal_loadRecByUsgMtbUnv", "SELECT ref, refWznmMUsergroup, unvIxWznmVMaintable, unvUref, ixWznmVRecaccess FROM TblWznmRMUsergroupUniversal WHERE refWznmMUsergroup = $1 AND unvIxWznmVMaintable = $2 AND unvUref = $3", 3);
};

bool PgTblWznmRMUsergroupUniversal::loadRec(
			PGresult* res
			, WznmRMUsergroupUniversal** rec
		) {
	char* ptr;

	WznmRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMUsergroupUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwznmvrecaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmVRecaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMUsergroupUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMUsergroupUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwznmvrecaccess")
		};

		while (numread < numrow) {
			rec = new WznmRMUsergroupUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUsergroup = atoll(ptr);
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

bool PgTblWznmRMUsergroupUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUsergroupUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUsergroupUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMUsergroupUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUsergroupUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMUsergroupUniversal::insertRec(
			WznmRMUsergroupUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWznmVRecaccess = htonl(rec->ixWznmVRecaccess);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWznmRMUsergroupUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMUsergroupUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMUsergroupUniversal::insertRst(
			ListWznmRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMUsergroupUniversal::updateRec(
			WznmRMUsergroupUniversal* rec
		) {
	PGresult* res;

	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWznmVRecaccess = htonl(rec->ixWznmVRecaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWznmRMUsergroupUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMUsergroupUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMUsergroupUniversal::updateRst(
			ListWznmRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMUsergroupUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMUsergroupUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMUsergroupUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WznmRMUsergroupUniversal** rec
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

	return loadRecByStmt("TblWznmRMUsergroupUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWznmMUsergroup
			, uint unvIxWznmVMaintable
			, ubigint unvUref
			, WznmRMUsergroupUniversal** rec
		) {
	ubigint _refWznmMUsergroup = htonl64(refWznmMUsergroup);
	uint _unvIxWznmVMaintable = htonl(unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblWznmRMUsergroupUniversal_loadRecByUsgMtbUnv", 3, vals, l, f, rec);
};

#endif
