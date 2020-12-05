/**
	* \file WznmJMErrorTitle.cpp
	* database access for table TblWznmJMErrorTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMErrorTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMErrorTitle
 ******************************************************************************/

WznmJMErrorTitle::WznmJMErrorTitle(
			const ubigint ref
			, const ubigint refWznmMError
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMError = refWznmMError;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMErrorTitle::operator==(
			const WznmJMErrorTitle& comp
		) {
	return false;
};

bool WznmJMErrorTitle::operator!=(
			const WznmJMErrorTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMErrorTitle
 ******************************************************************************/

ListWznmJMErrorTitle::ListWznmJMErrorTitle() {
};

ListWznmJMErrorTitle::ListWznmJMErrorTitle(
			const ListWznmJMErrorTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMErrorTitle(*(src.nodes[i]));
};

ListWznmJMErrorTitle::~ListWznmJMErrorTitle() {
	clear();
};

void ListWznmJMErrorTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMErrorTitle::size() const {
	return(nodes.size());
};

void ListWznmJMErrorTitle::append(
			WznmJMErrorTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMErrorTitle* ListWznmJMErrorTitle::operator[](
			const uint ix
		) {
	WznmJMErrorTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMErrorTitle& ListWznmJMErrorTitle::operator=(
			const ListWznmJMErrorTitle& src
		) {
	WznmJMErrorTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMErrorTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMErrorTitle::operator==(
			const ListWznmJMErrorTitle& comp
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

bool ListWznmJMErrorTitle::operator!=(
			const ListWznmJMErrorTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMErrorTitle
 ******************************************************************************/

TblWznmJMErrorTitle::TblWznmJMErrorTitle() {
};

TblWznmJMErrorTitle::~TblWznmJMErrorTitle() {
};

bool TblWznmJMErrorTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMErrorTitle** rec
		) {
	return false;
};

ubigint TblWznmJMErrorTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMErrorTitle::insertRec(
			WznmJMErrorTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMErrorTitle::insertNewRec(
			WznmJMErrorTitle** rec
			, const ubigint refWznmMError
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMErrorTitle* _rec = NULL;

	_rec = new WznmJMErrorTitle(0, refWznmMError, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMErrorTitle::appendNewRecToRst(
			ListWznmJMErrorTitle& rst
			, WznmJMErrorTitle** rec
			, const ubigint refWznmMError
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMErrorTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMError, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMErrorTitle::insertRst(
			ListWznmJMErrorTitle& rst
			, bool transact
		) {
};

void TblWznmJMErrorTitle::updateRec(
			WznmJMErrorTitle* rec
		) {
};

void TblWznmJMErrorTitle::updateRst(
			ListWznmJMErrorTitle& rst
			, bool transact
		) {
};

void TblWznmJMErrorTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMErrorTitle::loadRecByRef(
			ubigint ref
			, WznmJMErrorTitle** rec
		) {
	return false;
};

bool TblWznmJMErrorTitle::loadRecByErrLoc(
			ubigint refWznmMError
			, ubigint x1RefWznmMLocale
			, WznmJMErrorTitle** rec
		) {
	return false;
};

ubigint TblWznmJMErrorTitle::loadRefsByErr(
			ubigint refWznmMError
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMErrorTitle::loadRstByErr(
			ubigint refWznmMError
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	return 0;
};

bool TblWznmJMErrorTitle::loadTitByErrLoc(
			ubigint refWznmMError
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMErrorTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	ubigint numload = 0;
	WznmJMErrorTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMErrorTitle
 ******************************************************************************/

MyTblWznmJMErrorTitle::MyTblWznmJMErrorTitle() :
			TblWznmJMErrorTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMErrorTitle::~MyTblWznmJMErrorTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMErrorTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMErrorTitle (refWznmMError, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMErrorTitle SET refWznmMError = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMErrorTitle WHERE ref = ?", false);
};

bool MyTblWznmJMErrorTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMErrorTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMErrorTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMErrorTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMErrorTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMErrorTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMError = atoll((char*) dbrow[1]); else _rec->refWznmMError = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMErrorTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMErrorTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMErrorTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMErrorTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMErrorTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMError = atoll((char*) dbrow[1]); else rec->refWznmMError = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMErrorTitle::insertRec(
			WznmJMErrorTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMError,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMErrorTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMErrorTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMErrorTitle::insertRst(
			ListWznmJMErrorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMErrorTitle::updateRec(
			WznmJMErrorTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMError,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMErrorTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMErrorTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMErrorTitle::updateRst(
			ListWznmJMErrorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMErrorTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMErrorTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMErrorTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMErrorTitle::loadRecByRef(
			ubigint ref
			, WznmJMErrorTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMErrorTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMErrorTitle::loadRecByErrLoc(
			ubigint refWznmMError
			, ubigint x1RefWznmMLocale
			, WznmJMErrorTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMError, x1RefWznmMLocale, Title FROM TblWznmJMErrorTitle WHERE refWznmMError = " + to_string(refWznmMError) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMErrorTitle::loadRefsByErr(
			ubigint refWznmMError
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMErrorTitle WHERE refWznmMError = " + to_string(refWznmMError) + "", append, refs);
};

ubigint MyTblWznmJMErrorTitle::loadRstByErr(
			ubigint refWznmMError
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMError, x1RefWznmMLocale, Title FROM TblWznmJMErrorTitle WHERE refWznmMError = " + to_string(refWznmMError) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMErrorTitle::loadTitByErrLoc(
			ubigint refWznmMError
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMErrorTitle WHERE refWznmMError = " + to_string(refWznmMError) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMErrorTitle
 ******************************************************************************/

PgTblWznmJMErrorTitle::PgTblWznmJMErrorTitle() :
			TblWznmJMErrorTitle()
			, PgTable()
		{
};

PgTblWznmJMErrorTitle::~PgTblWznmJMErrorTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMErrorTitle::initStatements() {
	createStatement("TblWznmJMErrorTitle_insertRec", "INSERT INTO TblWznmJMErrorTitle (refWznmMError, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMErrorTitle_updateRec", "UPDATE TblWznmJMErrorTitle SET refWznmMError = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMErrorTitle_removeRecByRef", "DELETE FROM TblWznmJMErrorTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMErrorTitle_loadRecByRef", "SELECT ref, refWznmMError, x1RefWznmMLocale, Title FROM TblWznmJMErrorTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMErrorTitle_loadRecByErrLoc", "SELECT ref, refWznmMError, x1RefWznmMLocale, Title FROM TblWznmJMErrorTitle WHERE refWznmMError = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMErrorTitle_loadRefsByErr", "SELECT ref FROM TblWznmJMErrorTitle WHERE refWznmMError = $1", 1);
	createStatement("TblWznmJMErrorTitle_loadRstByErr", "SELECT ref, refWznmMError, x1RefWznmMLocale, Title FROM TblWznmJMErrorTitle WHERE refWznmMError = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMErrorTitle_loadTitByErrLoc", "SELECT Title FROM TblWznmJMErrorTitle WHERE refWznmMError = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMErrorTitle::loadRec(
			PGresult* res
			, WznmJMErrorTitle** rec
		) {
	char* ptr;

	WznmJMErrorTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMErrorTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmerror"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMError = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMErrorTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMErrorTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmerror"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMErrorTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMError = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMErrorTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMErrorTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMErrorTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMErrorTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMErrorTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMErrorTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMErrorTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMErrorTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMErrorTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMErrorTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMErrorTitle::insertRec(
			WznmJMErrorTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMError = htonl64(rec->refWznmMError);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMError,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMErrorTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMErrorTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMErrorTitle::insertRst(
			ListWznmJMErrorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMErrorTitle::updateRec(
			WznmJMErrorTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMError = htonl64(rec->refWznmMError);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMError,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJMErrorTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMErrorTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMErrorTitle::updateRst(
			ListWznmJMErrorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMErrorTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMErrorTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMErrorTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMErrorTitle::loadRecByRef(
			ubigint ref
			, WznmJMErrorTitle** rec
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

	return loadRecByStmt("TblWznmJMErrorTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMErrorTitle::loadRecByErrLoc(
			ubigint refWznmMError
			, ubigint x1RefWznmMLocale
			, WznmJMErrorTitle** rec
		) {
	ubigint _refWznmMError = htonl64(refWznmMError);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMError,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMErrorTitle_loadRecByErrLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMErrorTitle::loadRefsByErr(
			ubigint refWznmMError
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMError = htonl64(refWznmMError);

	const char* vals[] = {
		(char*) &_refWznmMError
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMErrorTitle_loadRefsByErr", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMErrorTitle::loadRstByErr(
			ubigint refWznmMError
			, const bool append
			, ListWznmJMErrorTitle& rst
		) {
	ubigint _refWznmMError = htonl64(refWznmMError);

	const char* vals[] = {
		(char*) &_refWznmMError
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMErrorTitle_loadRstByErr", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMErrorTitle::loadTitByErrLoc(
			ubigint refWznmMError
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMError = htonl64(refWznmMError);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMError,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMErrorTitle_loadTitByErrLoc", 2, vals, l, f, Title);
};

#endif

