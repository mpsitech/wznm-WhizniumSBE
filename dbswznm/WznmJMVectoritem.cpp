/**
	* \file WznmJMVectoritem.cpp
	* database access for table TblWznmJMVectoritem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMVectoritem.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMVectoritem
 ******************************************************************************/

WznmJMVectoritem::WznmJMVectoritem(
			const ubigint ref
			, const ubigint refWznmMVectoritem
			, const ubigint x1RefWznmMLocale
			, const string Title
			, const string Comment
		) :
			ref(ref)
			, refWznmMVectoritem(refWznmMVectoritem)
			, x1RefWznmMLocale(x1RefWznmMLocale)
			, Title(Title)
			, Comment(Comment)
		{
};

bool WznmJMVectoritem::operator==(
			const WznmJMVectoritem& comp
		) {
	return false;
};

bool WznmJMVectoritem::operator!=(
			const WznmJMVectoritem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMVectoritem
 ******************************************************************************/

ListWznmJMVectoritem::ListWznmJMVectoritem() {
};

ListWznmJMVectoritem::ListWznmJMVectoritem(
			const ListWznmJMVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMVectoritem(*(src.nodes[i]));
};

ListWznmJMVectoritem::~ListWznmJMVectoritem() {
	clear();
};

void ListWznmJMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMVectoritem::size() const {
	return(nodes.size());
};

void ListWznmJMVectoritem::append(
			WznmJMVectoritem* rec
		) {
	nodes.push_back(rec);
};

WznmJMVectoritem* ListWznmJMVectoritem::operator[](
			const uint ix
		) {
	WznmJMVectoritem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMVectoritem& ListWznmJMVectoritem::operator=(
			const ListWznmJMVectoritem& src
		) {
	WznmJMVectoritem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMVectoritem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMVectoritem::operator==(
			const ListWznmJMVectoritem& comp
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

bool ListWznmJMVectoritem::operator!=(
			const ListWznmJMVectoritem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMVectoritem
 ******************************************************************************/

TblWznmJMVectoritem::TblWznmJMVectoritem() {
};

TblWznmJMVectoritem::~TblWznmJMVectoritem() {
};

bool TblWznmJMVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmJMVectoritem** rec
		) {
	return false;
};

ubigint TblWznmJMVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	return 0;
};

ubigint TblWznmJMVectoritem::insertRec(
			WznmJMVectoritem* rec
		) {
	return 0;
};

ubigint TblWznmJMVectoritem::insertNewRec(
			WznmJMVectoritem** rec
			, const ubigint refWznmMVectoritem
			, const ubigint x1RefWznmMLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmJMVectoritem* _rec = NULL;

	_rec = new WznmJMVectoritem(0, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMVectoritem::appendNewRecToRst(
			ListWznmJMVectoritem& rst
			, WznmJMVectoritem** rec
			, const ubigint refWznmMVectoritem
			, const ubigint x1RefWznmMLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmJMVectoritem* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMVectoritem::insertRst(
			ListWznmJMVectoritem& rst
			, bool transact
		) {
};

void TblWznmJMVectoritem::updateRec(
			WznmJMVectoritem* rec
		) {
};

void TblWznmJMVectoritem::updateRst(
			ListWznmJMVectoritem& rst
			, bool transact
		) {
};

void TblWznmJMVectoritem::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMVectoritem::loadRecByRef(
			ubigint ref
			, WznmJMVectoritem** rec
		) {
	return false;
};

bool TblWznmJMVectoritem::loadRecByVitLoc(
			ubigint refWznmMVectoritem
			, ubigint x1RefWznmMLocale
			, WznmJMVectoritem** rec
		) {
	return false;
};

ubigint TblWznmJMVectoritem::loadRefsByVit(
			ubigint refWznmMVectoritem
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMVectoritem::loadRstByVit(
			ubigint refWznmMVectoritem
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	return 0;
};

ubigint TblWznmJMVectoritem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	ubigint numload = 0;
	WznmJMVectoritem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMVectoritem
 ******************************************************************************/

MyTblWznmJMVectoritem::MyTblWznmJMVectoritem() :
			TblWznmJMVectoritem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMVectoritem::~MyTblWznmJMVectoritem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMVectoritem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMVectoritem (refWznmMVectoritem, x1RefWznmMLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMVectoritem SET refWznmMVectoritem = ?, x1RefWznmMLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMVectoritem WHERE ref = ?", false);
};

bool MyTblWznmJMVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmJMVectoritem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMVectoritem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMVectoritem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMVectoritem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMVectoritem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVectoritem = atoll((char*) dbrow[1]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMVectoritem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMVectoritem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMVectoritem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMVectoritem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVectoritem = atoll((char*) dbrow[1]); else rec->refWznmMVectoritem = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMVectoritem::insertRec(
			WznmJMVectoritem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVectoritem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMVectoritem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMVectoritem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMVectoritem::insertRst(
			ListWznmJMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMVectoritem::updateRec(
			WznmJMVectoritem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVectoritem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMVectoritem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMVectoritem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMVectoritem::updateRst(
			ListWznmJMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMVectoritem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMVectoritem::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMVectoritem::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMVectoritem::loadRecByRef(
			ubigint ref
			, WznmJMVectoritem** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMVectoritem WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMVectoritem::loadRecByVitLoc(
			ubigint refWznmMVectoritem
			, ubigint x1RefWznmMLocale
			, WznmJMVectoritem** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(refWznmMVectoritem) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMVectoritem::loadRefsByVit(
			ubigint refWznmMVectoritem
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(refWznmMVectoritem) + "", append, refs);
};

ubigint MyTblWznmJMVectoritem::loadRstByVit(
			ubigint refWznmMVectoritem
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(refWznmMVectoritem) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMVectoritem
 ******************************************************************************/

PgTblWznmJMVectoritem::PgTblWznmJMVectoritem() :
			TblWznmJMVectoritem()
			, PgTable()
		{
};

PgTblWznmJMVectoritem::~PgTblWznmJMVectoritem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMVectoritem::initStatements() {
	createStatement("TblWznmJMVectoritem_insertRec", "INSERT INTO TblWznmJMVectoritem (refWznmMVectoritem, x1RefWznmMLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmJMVectoritem_updateRec", "UPDATE TblWznmJMVectoritem SET refWznmMVectoritem = $1, x1RefWznmMLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmJMVectoritem_removeRecByRef", "DELETE FROM TblWznmJMVectoritem WHERE ref = $1", 1);

	createStatement("TblWznmJMVectoritem_loadRecByRef", "SELECT ref, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment FROM TblWznmJMVectoritem WHERE ref = $1", 1);
	createStatement("TblWznmJMVectoritem_loadRecByVitLoc", "SELECT ref, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMVectoritem_loadRefsByVit", "SELECT ref FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = $1", 1);
	createStatement("TblWznmJMVectoritem_loadRstByVit", "SELECT ref, refWznmMVectoritem, x1RefWznmMLocale, Title, Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = $1 ORDER BY x1RefWznmMLocale ASC", 1);
};

bool PgTblWznmJMVectoritem::loadRec(
			PGresult* res
			, WznmJMVectoritem** rec
		) {
	char* ptr;

	WznmJMVectoritem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMVectoritem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMVectoritem::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMVectoritem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmJMVectoritem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMVectoritem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMVectoritem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVectoritem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMVectoritem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVectoritem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmJMVectoritem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVectoritem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVectoritem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMVectoritem::insertRec(
			WznmJMVectoritem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMVectoritem,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmJMVectoritem_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVectoritem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMVectoritem::insertRst(
			ListWznmJMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMVectoritem::updateRec(
			WznmJMVectoritem* rec
		) {
	PGresult* res;

	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVectoritem,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJMVectoritem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMVectoritem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMVectoritem::updateRst(
			ListWznmJMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMVectoritem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMVectoritem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMVectoritem::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMVectoritem::loadRecByRef(
			ubigint ref
			, WznmJMVectoritem** rec
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

	return loadRecByStmt("TblWznmJMVectoritem_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMVectoritem::loadRecByVitLoc(
			ubigint refWznmMVectoritem
			, ubigint x1RefWznmMLocale
			, WznmJMVectoritem** rec
		) {
	ubigint _refWznmMVectoritem = htonl64(refWznmMVectoritem);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMVectoritem,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMVectoritem_loadRecByVitLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMVectoritem::loadRefsByVit(
			ubigint refWznmMVectoritem
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVectoritem = htonl64(refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMVectoritem_loadRefsByVit", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMVectoritem::loadRstByVit(
			ubigint refWznmMVectoritem
			, const bool append
			, ListWznmJMVectoritem& rst
		) {
	ubigint _refWznmMVectoritem = htonl64(refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMVectoritem_loadRstByVit", 1, vals, l, f, append, rst);
};

#endif
