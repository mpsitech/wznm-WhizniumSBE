/**
	* \file WznmMCheck.cpp
	* database access for table TblWznmMCheck (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMCheck.h"

#include "WznmMCheck_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMCheck
 ******************************************************************************/

WznmMCheck::WznmMCheck(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMTable
			, const ubigint refWznmMTablecol
			, const ubigint refWznmMCall
			, const string sref
			, const string Comment
		) :
			ref(ref)
			, ixVBasetype(ixVBasetype)
			, refWznmMTable(refWznmMTable)
			, refWznmMTablecol(refWznmMTablecol)
			, refWznmMCall(refWznmMCall)
			, sref(sref)
			, Comment(Comment)
		{
};

bool WznmMCheck::operator==(
			const WznmMCheck& comp
		) {
	return false;
};

bool WznmMCheck::operator!=(
			const WznmMCheck& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMCheck
 ******************************************************************************/

ListWznmMCheck::ListWznmMCheck() {
};

ListWznmMCheck::ListWznmMCheck(
			const ListWznmMCheck& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMCheck(*(src.nodes[i]));
};

ListWznmMCheck::~ListWznmMCheck() {
	clear();
};

void ListWznmMCheck::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMCheck::size() const {
	return(nodes.size());
};

void ListWznmMCheck::append(
			WznmMCheck* rec
		) {
	nodes.push_back(rec);
};

WznmMCheck* ListWznmMCheck::operator[](
			const uint ix
		) {
	WznmMCheck* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMCheck& ListWznmMCheck::operator=(
			const ListWznmMCheck& src
		) {
	WznmMCheck* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMCheck(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMCheck::operator==(
			const ListWznmMCheck& comp
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

bool ListWznmMCheck::operator!=(
			const ListWznmMCheck& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMCheck
 ******************************************************************************/

TblWznmMCheck::TblWznmMCheck() {
};

TblWznmMCheck::~TblWznmMCheck() {
};

bool TblWznmMCheck::loadRecBySQL(
			const string& sqlstr
			, WznmMCheck** rec
		) {
	return false;
};

ubigint TblWznmMCheck::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCheck& rst
		) {
	return 0;
};

ubigint TblWznmMCheck::insertRec(
			WznmMCheck* rec
		) {
	return 0;
};

ubigint TblWznmMCheck::insertNewRec(
			WznmMCheck** rec
			, const uint ixVBasetype
			, const ubigint refWznmMTable
			, const ubigint refWznmMTablecol
			, const ubigint refWznmMCall
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMCheck* _rec = NULL;

	_rec = new WznmMCheck(0, ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMCheck::appendNewRecToRst(
			ListWznmMCheck& rst
			, WznmMCheck** rec
			, const uint ixVBasetype
			, const ubigint refWznmMTable
			, const ubigint refWznmMTablecol
			, const ubigint refWznmMCall
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMCheck* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMCheck::insertRst(
			ListWznmMCheck& rst
			, bool transact
		) {
};

void TblWznmMCheck::updateRec(
			WznmMCheck* rec
		) {
};

void TblWznmMCheck::updateRst(
			ListWznmMCheck& rst
			, bool transact
		) {
};

void TblWznmMCheck::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMCheck::loadRecByRef(
			ubigint ref
			, WznmMCheck** rec
		) {
	return false;
};

ubigint TblWznmMCheck::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMCheck::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMCheck& rst
		) {
	return 0;
};

bool TblWznmMCheck::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMCheck::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMCheck& rst
		) {
	ubigint numload = 0;
	WznmMCheck* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMCheck
 ******************************************************************************/

MyTblWznmMCheck::MyTblWznmMCheck() :
			TblWznmMCheck()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMCheck::~MyTblWznmMCheck() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMCheck::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMCheck (ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMCheck SET ixVBasetype = ?, refWznmMTable = ?, refWznmMTablecol = ?, refWznmMCall = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMCheck WHERE ref = ?", false);
};

bool MyTblWznmMCheck::loadRecBySQL(
			const string& sqlstr
			, WznmMCheck** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMCheck* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCheck::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCheck::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMCheck();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMTable = atoll((char*) dbrow[2]); else _rec->refWznmMTable = 0;
		if (dbrow[3]) _rec->refWznmMTablecol = atoll((char*) dbrow[3]); else _rec->refWznmMTablecol = 0;
		if (dbrow[4]) _rec->refWznmMCall = atoll((char*) dbrow[4]); else _rec->refWznmMCall = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMCheck::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCheck& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMCheck* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCheck::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCheck::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMCheck();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMTable = atoll((char*) dbrow[2]); else rec->refWznmMTable = 0;
			if (dbrow[3]) rec->refWznmMTablecol = atoll((char*) dbrow[3]); else rec->refWznmMTablecol = 0;
			if (dbrow[4]) rec->refWznmMCall = atoll((char*) dbrow[4]); else rec->refWznmMCall = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMCheck::insertRec(
			WznmMCheck* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->sref.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMTablecol,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMCall,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMCheck::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMCheck::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMCheck::insertRst(
			ListWznmMCheck& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMCheck::updateRec(
			WznmMCheck* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->sref.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMTablecol,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMCall,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMCheck::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMCheck::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMCheck::updateRst(
			ListWznmMCheck& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMCheck::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMCheck::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMCheck::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMCheck::loadRecByRef(
			ubigint ref
			, WznmMCheck** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMCheck WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMCheck::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMCheck WHERE refWznmMTable = " + to_string(refWznmMTable) + "", append, refs);
};

ubigint MyTblWznmMCheck::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMCheck& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment FROM TblWznmMCheck WHERE refWznmMTable = " + to_string(refWznmMTable) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMCheck::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMCheck WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMCheck
 ******************************************************************************/

PgTblWznmMCheck::PgTblWznmMCheck() :
			TblWznmMCheck()
			, PgTable()
		{
};

PgTblWznmMCheck::~PgTblWznmMCheck() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMCheck::initStatements() {
	createStatement("TblWznmMCheck_insertRec", "INSERT INTO TblWznmMCheck (ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWznmMCheck_updateRec", "UPDATE TblWznmMCheck SET ixVBasetype = $1, refWznmMTable = $2, refWznmMTablecol = $3, refWznmMCall = $4, sref = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWznmMCheck_removeRecByRef", "DELETE FROM TblWznmMCheck WHERE ref = $1", 1);

	createStatement("TblWznmMCheck_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment FROM TblWznmMCheck WHERE ref = $1", 1);
	createStatement("TblWznmMCheck_loadRefsByTbl", "SELECT ref FROM TblWznmMCheck WHERE refWznmMTable = $1", 1);
	createStatement("TblWznmMCheck_loadRstByTbl", "SELECT ref, ixVBasetype, refWznmMTable, refWznmMTablecol, refWznmMCall, sref, Comment FROM TblWznmMCheck WHERE refWznmMTable = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMCheck_loadSrfByRef", "SELECT sref FROM TblWznmMCheck WHERE ref = $1", 1);
};

bool PgTblWznmMCheck::loadRec(
			PGresult* res
			, WznmMCheck** rec
		) {
	char* ptr;

	WznmMCheck* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMCheck();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "refwznmmcall"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMTablecol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMCall = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMCheck::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMCheck& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMCheck* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "refwznmmcall"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMCheck();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMTablecol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMCall = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMCheck::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMCheck** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCheck::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCheck::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMCheck& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCheck::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMCheck::loadRecBySQL(
			const string& sqlstr
			, WznmMCheck** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCheck::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCheck::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCheck& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCheck::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMCheck::insertRec(
			WznmMCheck* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _refWznmMCall = htonl64(rec->refWznmMCall);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMTablecol,
		(char*) &_refWznmMCall,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMCheck_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCheck::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMCheck::insertRst(
			ListWznmMCheck& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMCheck::updateRec(
			WznmMCheck* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _refWznmMCall = htonl64(rec->refWznmMCall);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMTablecol,
		(char*) &_refWznmMCall,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMCheck_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCheck::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMCheck::updateRst(
			ListWznmMCheck& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMCheck::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMCheck_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCheck::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMCheck::loadRecByRef(
			ubigint ref
			, WznmMCheck** rec
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

	return loadRecByStmt("TblWznmMCheck_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMCheck::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMCheck_loadRefsByTbl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMCheck::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMCheck& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMCheck_loadRstByTbl", 1, vals, l, f, append, rst);
};

bool PgTblWznmMCheck::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMCheck_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
