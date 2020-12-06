/**
	* \file WznmJMImpexpcolStub.cpp
	* database access for table TblWznmJMImpexpcolStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMImpexpcolStub.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMImpexpcolStub
 ******************************************************************************/

WznmJMImpexpcolStub::WznmJMImpexpcolStub(
			const ubigint ref
			, const ubigint refWznmMImpexpcol
			, const ubigint x1RefWznmMVectoritem
			, const ubigint refWznmMStub
		) {

	this->ref = ref;
	this->refWznmMImpexpcol = refWznmMImpexpcol;
	this->x1RefWznmMVectoritem = x1RefWznmMVectoritem;
	this->refWznmMStub = refWznmMStub;
};

bool WznmJMImpexpcolStub::operator==(
			const WznmJMImpexpcolStub& comp
		) {
	return false;
};

bool WznmJMImpexpcolStub::operator!=(
			const WznmJMImpexpcolStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMImpexpcolStub
 ******************************************************************************/

ListWznmJMImpexpcolStub::ListWznmJMImpexpcolStub() {
};

ListWznmJMImpexpcolStub::ListWznmJMImpexpcolStub(
			const ListWznmJMImpexpcolStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMImpexpcolStub(*(src.nodes[i]));
};

ListWznmJMImpexpcolStub::~ListWznmJMImpexpcolStub() {
	clear();
};

void ListWznmJMImpexpcolStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMImpexpcolStub::size() const {
	return(nodes.size());
};

void ListWznmJMImpexpcolStub::append(
			WznmJMImpexpcolStub* rec
		) {
	nodes.push_back(rec);
};

WznmJMImpexpcolStub* ListWznmJMImpexpcolStub::operator[](
			const uint ix
		) {
	WznmJMImpexpcolStub* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMImpexpcolStub& ListWznmJMImpexpcolStub::operator=(
			const ListWznmJMImpexpcolStub& src
		) {
	WznmJMImpexpcolStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMImpexpcolStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMImpexpcolStub::operator==(
			const ListWznmJMImpexpcolStub& comp
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

bool ListWznmJMImpexpcolStub::operator!=(
			const ListWznmJMImpexpcolStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMImpexpcolStub
 ******************************************************************************/

TblWznmJMImpexpcolStub::TblWznmJMImpexpcolStub() {
};

TblWznmJMImpexpcolStub::~TblWznmJMImpexpcolStub() {
};

bool TblWznmJMImpexpcolStub::loadRecBySQL(
			const string& sqlstr
			, WznmJMImpexpcolStub** rec
		) {
	return false;
};

ubigint TblWznmJMImpexpcolStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	return 0;
};

ubigint TblWznmJMImpexpcolStub::insertRec(
			WznmJMImpexpcolStub* rec
		) {
	return 0;
};

ubigint TblWznmJMImpexpcolStub::insertNewRec(
			WznmJMImpexpcolStub** rec
			, const ubigint refWznmMImpexpcol
			, const ubigint x1RefWznmMVectoritem
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmJMImpexpcolStub* _rec = NULL;

	_rec = new WznmJMImpexpcolStub(0, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMImpexpcolStub::appendNewRecToRst(
			ListWznmJMImpexpcolStub& rst
			, WznmJMImpexpcolStub** rec
			, const ubigint refWznmMImpexpcol
			, const ubigint x1RefWznmMVectoritem
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmJMImpexpcolStub* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMImpexpcolStub::insertRst(
			ListWznmJMImpexpcolStub& rst
			, bool transact
		) {
};

void TblWznmJMImpexpcolStub::updateRec(
			WznmJMImpexpcolStub* rec
		) {
};

void TblWznmJMImpexpcolStub::updateRst(
			ListWznmJMImpexpcolStub& rst
			, bool transact
		) {
};

void TblWznmJMImpexpcolStub::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMImpexpcolStub::loadRecByRef(
			ubigint ref
			, WznmJMImpexpcolStub** rec
		) {
	return false;
};

bool TblWznmJMImpexpcolStub::loadRecByIelVit(
			ubigint refWznmMImpexpcol
			, ubigint x1RefWznmMVectoritem
			, WznmJMImpexpcolStub** rec
		) {
	return false;
};

ubigint TblWznmJMImpexpcolStub::loadRefsByIel(
			ubigint refWznmMImpexpcol
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMImpexpcolStub::loadRstByIel(
			ubigint refWznmMImpexpcol
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	return 0;
};

bool TblWznmJMImpexpcolStub::loadStbByIelVit(
			ubigint refWznmMImpexpcol
			, ubigint x1RefWznmMVectoritem
			, ubigint& refWznmMStub
		) {
	return false;
};

ubigint TblWznmJMImpexpcolStub::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	ubigint numload = 0;
	WznmJMImpexpcolStub* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMImpexpcolStub
 ******************************************************************************/

MyTblWznmJMImpexpcolStub::MyTblWznmJMImpexpcolStub() :
			TblWznmJMImpexpcolStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMImpexpcolStub::~MyTblWznmJMImpexpcolStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMImpexpcolStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMImpexpcolStub (refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMImpexpcolStub SET refWznmMImpexpcol = ?, x1RefWznmMVectoritem = ?, refWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMImpexpcolStub WHERE ref = ?", false);
};

bool MyTblWznmJMImpexpcolStub::loadRecBySQL(
			const string& sqlstr
			, WznmJMImpexpcolStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMImpexpcolStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMImpexpcolStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMImpexpcolStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmJMImpexpcolStub();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMImpexpcol = atoll((char*) dbrow[1]); else _rec->refWznmMImpexpcol = 0;
		if (dbrow[2]) _rec->x1RefWznmMVectoritem = atoll((char*) dbrow[2]); else _rec->x1RefWznmMVectoritem = 0;
		if (dbrow[3]) _rec->refWznmMStub = atoll((char*) dbrow[3]); else _rec->refWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMImpexpcolStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMImpexpcolStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMImpexpcolStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMImpexpcolStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmJMImpexpcolStub();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMImpexpcol = atoll((char*) dbrow[1]); else rec->refWznmMImpexpcol = 0;
			if (dbrow[2]) rec->x1RefWznmMVectoritem = atoll((char*) dbrow[2]); else rec->x1RefWznmMVectoritem = 0;
			if (dbrow[3]) rec->refWznmMStub = atoll((char*) dbrow[3]); else rec->refWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMImpexpcolStub::insertRec(
			WznmJMImpexpcolStub* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMImpexpcol,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMVectoritem,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMStub,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMImpexpcolStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMImpexpcolStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMImpexpcolStub::insertRst(
			ListWznmJMImpexpcolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMImpexpcolStub::updateRec(
			WznmJMImpexpcolStub* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMImpexpcol,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMVectoritem,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMStub,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMImpexpcolStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMImpexpcolStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMImpexpcolStub::updateRst(
			ListWznmJMImpexpcolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMImpexpcolStub::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMImpexpcolStub::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMImpexpcolStub::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMImpexpcolStub::loadRecByRef(
			ubigint ref
			, WznmJMImpexpcolStub** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMImpexpcolStub WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMImpexpcolStub::loadRecByIelVit(
			ubigint refWznmMImpexpcol
			, ubigint x1RefWznmMVectoritem
			, WznmJMImpexpcolStub** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = " + to_string(refWznmMImpexpcol) + " AND x1RefWznmMVectoritem = " + to_string(x1RefWznmMVectoritem) + "", rec);
};

ubigint MyTblWznmJMImpexpcolStub::loadRefsByIel(
			ubigint refWznmMImpexpcol
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = " + to_string(refWznmMImpexpcol) + "", append, refs);
};

ubigint MyTblWznmJMImpexpcolStub::loadRstByIel(
			ubigint refWznmMImpexpcol
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = " + to_string(refWznmMImpexpcol) + " ORDER BY x1RefWznmMVectoritem ASC", append, rst);
};

bool MyTblWznmJMImpexpcolStub::loadStbByIelVit(
			ubigint refWznmMImpexpcol
			, ubigint x1RefWznmMVectoritem
			, ubigint& refWznmMStub
		) {
	return loadRefBySQL("SELECT refWznmMStub FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = " + to_string(refWznmMImpexpcol) + " AND x1RefWznmMVectoritem = " + to_string(x1RefWznmMVectoritem) + "", refWznmMStub);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMImpexpcolStub
 ******************************************************************************/

PgTblWznmJMImpexpcolStub::PgTblWznmJMImpexpcolStub() :
			TblWznmJMImpexpcolStub()
			, PgTable()
		{
};

PgTblWznmJMImpexpcolStub::~PgTblWznmJMImpexpcolStub() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMImpexpcolStub::initStatements() {
	createStatement("TblWznmJMImpexpcolStub_insertRec", "INSERT INTO TblWznmJMImpexpcolStub (refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMImpexpcolStub_updateRec", "UPDATE TblWznmJMImpexpcolStub SET refWznmMImpexpcol = $1, x1RefWznmMVectoritem = $2, refWznmMStub = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMImpexpcolStub_removeRecByRef", "DELETE FROM TblWznmJMImpexpcolStub WHERE ref = $1", 1);

	createStatement("TblWznmJMImpexpcolStub_loadRecByRef", "SELECT ref, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub FROM TblWznmJMImpexpcolStub WHERE ref = $1", 1);
	createStatement("TblWznmJMImpexpcolStub_loadRecByIelVit", "SELECT ref, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = $1 AND x1RefWznmMVectoritem = $2", 2);
	createStatement("TblWznmJMImpexpcolStub_loadRefsByIel", "SELECT ref FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = $1", 1);
	createStatement("TblWznmJMImpexpcolStub_loadRstByIel", "SELECT ref, refWznmMImpexpcol, x1RefWznmMVectoritem, refWznmMStub FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = $1 ORDER BY x1RefWznmMVectoritem ASC", 1);
	createStatement("TblWznmJMImpexpcolStub_loadStbByIelVit", "SELECT refWznmMStub FROM TblWznmJMImpexpcolStub WHERE refWznmMImpexpcol = $1 AND x1RefWznmMVectoritem = $2", 2);
};

bool PgTblWznmJMImpexpcolStub::loadRec(
			PGresult* res
			, WznmJMImpexpcolStub** rec
		) {
	char* ptr;

	WznmJMImpexpcolStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMImpexpcolStub();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmimpexpcol"),
			PQfnumber(res, "x1refwznmmvectoritem"),
			PQfnumber(res, "refwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMImpexpcol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMImpexpcolStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMImpexpcolStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmimpexpcol"),
			PQfnumber(res, "x1refwznmmvectoritem"),
			PQfnumber(res, "refwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmJMImpexpcolStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMImpexpcol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMImpexpcolStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMImpexpcolStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMImpexpcolStub::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMImpexpcolStub::loadRecBySQL(
			const string& sqlstr
			, WznmJMImpexpcolStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMImpexpcolStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMImpexpcolStub::insertRec(
			WznmJMImpexpcolStub* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMImpexpcol = htonl64(rec->refWznmMImpexpcol);
	ubigint _x1RefWznmMVectoritem = htonl64(rec->x1RefWznmMVectoritem);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcol,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMImpexpcolStub_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMImpexpcolStub::insertRst(
			ListWznmJMImpexpcolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMImpexpcolStub::updateRec(
			WznmJMImpexpcolStub* rec
		) {
	PGresult* res;

	ubigint _refWznmMImpexpcol = htonl64(rec->refWznmMImpexpcol);
	ubigint _x1RefWznmMVectoritem = htonl64(rec->x1RefWznmMVectoritem);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcol,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_refWznmMStub,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMImpexpcolStub_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMImpexpcolStub::updateRst(
			ListWznmJMImpexpcolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMImpexpcolStub::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMImpexpcolStub_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMImpexpcolStub::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMImpexpcolStub::loadRecByRef(
			ubigint ref
			, WznmJMImpexpcolStub** rec
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

	return loadRecByStmt("TblWznmJMImpexpcolStub_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMImpexpcolStub::loadRecByIelVit(
			ubigint refWznmMImpexpcol
			, ubigint x1RefWznmMVectoritem
			, WznmJMImpexpcolStub** rec
		) {
	ubigint _refWznmMImpexpcol = htonl64(refWznmMImpexpcol);
	ubigint _x1RefWznmMVectoritem = htonl64(x1RefWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcol,
		(char*) &_x1RefWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMImpexpcolStub_loadRecByIelVit", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMImpexpcolStub::loadRefsByIel(
			ubigint refWznmMImpexpcol
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMImpexpcol = htonl64(refWznmMImpexpcol);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcol
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMImpexpcolStub_loadRefsByIel", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMImpexpcolStub::loadRstByIel(
			ubigint refWznmMImpexpcol
			, const bool append
			, ListWznmJMImpexpcolStub& rst
		) {
	ubigint _refWznmMImpexpcol = htonl64(refWznmMImpexpcol);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcol
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMImpexpcolStub_loadRstByIel", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMImpexpcolStub::loadStbByIelVit(
			ubigint refWznmMImpexpcol
			, ubigint x1RefWznmMVectoritem
			, ubigint& refWznmMStub
		) {
	ubigint _refWznmMImpexpcol = htonl64(refWznmMImpexpcol);
	ubigint _x1RefWznmMVectoritem = htonl64(x1RefWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcol,
		(char*) &_x1RefWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefByStmt("TblWznmJMImpexpcolStub_loadStbByIelVit", 2, vals, l, f, refWznmMStub);
};

#endif
