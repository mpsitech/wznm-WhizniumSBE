/**
	* \file WznmJMLocaleTitle.cpp
	* database access for table TblWznmJMLocaleTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMLocaleTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMLocaleTitle
 ******************************************************************************/

WznmJMLocaleTitle::WznmJMLocaleTitle(
			const ubigint ref
			, const ubigint refWznmMLocale
			, const ubigint x1RefWznmMLocale
			, const string Title
		) :
			ref(ref)
			, refWznmMLocale(refWznmMLocale)
			, x1RefWznmMLocale(x1RefWznmMLocale)
			, Title(Title)
		{
};

bool WznmJMLocaleTitle::operator==(
			const WznmJMLocaleTitle& comp
		) {
	return false;
};

bool WznmJMLocaleTitle::operator!=(
			const WznmJMLocaleTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMLocaleTitle
 ******************************************************************************/

ListWznmJMLocaleTitle::ListWznmJMLocaleTitle() {
};

ListWznmJMLocaleTitle::ListWznmJMLocaleTitle(
			const ListWznmJMLocaleTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMLocaleTitle(*(src.nodes[i]));
};

ListWznmJMLocaleTitle::~ListWznmJMLocaleTitle() {
	clear();
};

void ListWznmJMLocaleTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMLocaleTitle::size() const {
	return(nodes.size());
};

void ListWznmJMLocaleTitle::append(
			WznmJMLocaleTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMLocaleTitle* ListWznmJMLocaleTitle::operator[](
			const uint ix
		) {
	WznmJMLocaleTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMLocaleTitle& ListWznmJMLocaleTitle::operator=(
			const ListWznmJMLocaleTitle& src
		) {
	WznmJMLocaleTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMLocaleTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMLocaleTitle::operator==(
			const ListWznmJMLocaleTitle& comp
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

bool ListWznmJMLocaleTitle::operator!=(
			const ListWznmJMLocaleTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMLocaleTitle
 ******************************************************************************/

TblWznmJMLocaleTitle::TblWznmJMLocaleTitle() {
};

TblWznmJMLocaleTitle::~TblWznmJMLocaleTitle() {
};

bool TblWznmJMLocaleTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMLocaleTitle** rec
		) {
	return false;
};

ubigint TblWznmJMLocaleTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMLocaleTitle::insertRec(
			WznmJMLocaleTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMLocaleTitle::insertNewRec(
			WznmJMLocaleTitle** rec
			, const ubigint refWznmMLocale
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMLocaleTitle* _rec = NULL;

	_rec = new WznmJMLocaleTitle(0, refWznmMLocale, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMLocaleTitle::appendNewRecToRst(
			ListWznmJMLocaleTitle& rst
			, WznmJMLocaleTitle** rec
			, const ubigint refWznmMLocale
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMLocaleTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMLocale, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMLocaleTitle::insertRst(
			ListWznmJMLocaleTitle& rst
			, bool transact
		) {
};

void TblWznmJMLocaleTitle::updateRec(
			WznmJMLocaleTitle* rec
		) {
};

void TblWznmJMLocaleTitle::updateRst(
			ListWznmJMLocaleTitle& rst
			, bool transact
		) {
};

void TblWznmJMLocaleTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMLocaleTitle::loadRecByRef(
			ubigint ref
			, WznmJMLocaleTitle** rec
		) {
	return false;
};

bool TblWznmJMLocaleTitle::loadRecByLocLo2(
			ubigint refWznmMLocale
			, ubigint x1RefWznmMLocale
			, WznmJMLocaleTitle** rec
		) {
	return false;
};

ubigint TblWznmJMLocaleTitle::loadRefsByLoc(
			ubigint refWznmMLocale
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMLocaleTitle::loadRstByLoc(
			ubigint refWznmMLocale
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	return 0;
};

bool TblWznmJMLocaleTitle::loadTitByLocLo2(
			ubigint refWznmMLocale
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMLocaleTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	ubigint numload = 0;
	WznmJMLocaleTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMLocaleTitle
 ******************************************************************************/

MyTblWznmJMLocaleTitle::MyTblWznmJMLocaleTitle() :
			TblWznmJMLocaleTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMLocaleTitle::~MyTblWznmJMLocaleTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMLocaleTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMLocaleTitle (refWznmMLocale, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMLocaleTitle SET refWznmMLocale = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMLocaleTitle WHERE ref = ?", false);
};

bool MyTblWznmJMLocaleTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMLocaleTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMLocaleTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMLocaleTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMLocaleTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMLocaleTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMLocale = atoll((char*) dbrow[1]); else _rec->refWznmMLocale = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMLocaleTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMLocaleTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMLocaleTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMLocaleTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMLocaleTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMLocale = atoll((char*) dbrow[1]); else rec->refWznmMLocale = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMLocaleTitle::insertRec(
			WznmJMLocaleTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLocale,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMLocaleTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMLocaleTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMLocaleTitle::insertRst(
			ListWznmJMLocaleTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMLocaleTitle::updateRec(
			WznmJMLocaleTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLocale,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMLocaleTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMLocaleTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMLocaleTitle::updateRst(
			ListWznmJMLocaleTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMLocaleTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMLocaleTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMLocaleTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMLocaleTitle::loadRecByRef(
			ubigint ref
			, WznmJMLocaleTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMLocaleTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMLocaleTitle::loadRecByLocLo2(
			ubigint refWznmMLocale
			, ubigint x1RefWznmMLocale
			, WznmJMLocaleTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMLocale, x1RefWznmMLocale, Title FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = " + to_string(refWznmMLocale) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMLocaleTitle::loadRefsByLoc(
			ubigint refWznmMLocale
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = " + to_string(refWznmMLocale) + "", append, refs);
};

ubigint MyTblWznmJMLocaleTitle::loadRstByLoc(
			ubigint refWznmMLocale
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMLocale, x1RefWznmMLocale, Title FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = " + to_string(refWznmMLocale) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMLocaleTitle::loadTitByLocLo2(
			ubigint refWznmMLocale
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = " + to_string(refWznmMLocale) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMLocaleTitle
 ******************************************************************************/

PgTblWznmJMLocaleTitle::PgTblWznmJMLocaleTitle() :
			TblWznmJMLocaleTitle()
			, PgTable()
		{
};

PgTblWznmJMLocaleTitle::~PgTblWznmJMLocaleTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMLocaleTitle::initStatements() {
	createStatement("TblWznmJMLocaleTitle_insertRec", "INSERT INTO TblWznmJMLocaleTitle (refWznmMLocale, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMLocaleTitle_updateRec", "UPDATE TblWznmJMLocaleTitle SET refWznmMLocale = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMLocaleTitle_removeRecByRef", "DELETE FROM TblWznmJMLocaleTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMLocaleTitle_loadRecByRef", "SELECT ref, refWznmMLocale, x1RefWznmMLocale, Title FROM TblWznmJMLocaleTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMLocaleTitle_loadRecByLocLo2", "SELECT ref, refWznmMLocale, x1RefWznmMLocale, Title FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMLocaleTitle_loadRefsByLoc", "SELECT ref FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = $1", 1);
	createStatement("TblWznmJMLocaleTitle_loadRstByLoc", "SELECT ref, refWznmMLocale, x1RefWznmMLocale, Title FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMLocaleTitle_loadTitByLocLo2", "SELECT Title FROM TblWznmJMLocaleTitle WHERE refWznmMLocale = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMLocaleTitle::loadRec(
			PGresult* res
			, WznmJMLocaleTitle** rec
		) {
	char* ptr;

	WznmJMLocaleTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMLocaleTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMLocaleTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMLocaleTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMLocaleTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMLocaleTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMLocaleTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMLocaleTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMLocaleTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMLocaleTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMLocaleTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMLocaleTitle::insertRec(
			WznmJMLocaleTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMLocale,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMLocaleTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMLocaleTitle::insertRst(
			ListWznmJMLocaleTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMLocaleTitle::updateRec(
			WznmJMLocaleTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMLocale,
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

	res = PQexecPrepared(dbs, "TblWznmJMLocaleTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMLocaleTitle::updateRst(
			ListWznmJMLocaleTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMLocaleTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMLocaleTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMLocaleTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMLocaleTitle::loadRecByRef(
			ubigint ref
			, WznmJMLocaleTitle** rec
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

	return loadRecByStmt("TblWznmJMLocaleTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMLocaleTitle::loadRecByLocLo2(
			ubigint refWznmMLocale
			, ubigint x1RefWznmMLocale
			, WznmJMLocaleTitle** rec
		) {
	ubigint _refWznmMLocale = htonl64(refWznmMLocale);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMLocale,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMLocaleTitle_loadRecByLocLo2", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMLocaleTitle::loadRefsByLoc(
			ubigint refWznmMLocale
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMLocale = htonl64(refWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMLocaleTitle_loadRefsByLoc", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMLocaleTitle::loadRstByLoc(
			ubigint refWznmMLocale
			, const bool append
			, ListWznmJMLocaleTitle& rst
		) {
	ubigint _refWznmMLocale = htonl64(refWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMLocaleTitle_loadRstByLoc", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMLocaleTitle::loadTitByLocLo2(
			ubigint refWznmMLocale
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMLocale = htonl64(refWznmMLocale);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMLocale,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMLocaleTitle_loadTitByLocLo2", 2, vals, l, f, Title);
};

#endif
