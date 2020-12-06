/**
	* \file WznmJMTagTitle.cpp
	* database access for table TblWznmJMTagTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMTagTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMTagTitle
 ******************************************************************************/

WznmJMTagTitle::WznmJMTagTitle(
			const ubigint ref
			, const ubigint refWznmMTag
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMTag = refWznmMTag;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMTagTitle::operator==(
			const WznmJMTagTitle& comp
		) {
	return false;
};

bool WznmJMTagTitle::operator!=(
			const WznmJMTagTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMTagTitle
 ******************************************************************************/

ListWznmJMTagTitle::ListWznmJMTagTitle() {
};

ListWznmJMTagTitle::ListWznmJMTagTitle(
			const ListWznmJMTagTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMTagTitle(*(src.nodes[i]));
};

ListWznmJMTagTitle::~ListWznmJMTagTitle() {
	clear();
};

void ListWznmJMTagTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMTagTitle::size() const {
	return(nodes.size());
};

void ListWznmJMTagTitle::append(
			WznmJMTagTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMTagTitle* ListWznmJMTagTitle::operator[](
			const uint ix
		) {
	WznmJMTagTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMTagTitle& ListWznmJMTagTitle::operator=(
			const ListWznmJMTagTitle& src
		) {
	WznmJMTagTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMTagTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMTagTitle::operator==(
			const ListWznmJMTagTitle& comp
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

bool ListWznmJMTagTitle::operator!=(
			const ListWznmJMTagTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMTagTitle
 ******************************************************************************/

TblWznmJMTagTitle::TblWznmJMTagTitle() {
};

TblWznmJMTagTitle::~TblWznmJMTagTitle() {
};

bool TblWznmJMTagTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMTagTitle** rec
		) {
	return false;
};

ubigint TblWznmJMTagTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMTagTitle::insertRec(
			WznmJMTagTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMTagTitle::insertNewRec(
			WznmJMTagTitle** rec
			, const ubigint refWznmMTag
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMTagTitle* _rec = NULL;

	_rec = new WznmJMTagTitle(0, refWznmMTag, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMTagTitle::appendNewRecToRst(
			ListWznmJMTagTitle& rst
			, WznmJMTagTitle** rec
			, const ubigint refWznmMTag
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMTagTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMTag, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMTagTitle::insertRst(
			ListWznmJMTagTitle& rst
			, bool transact
		) {
};

void TblWznmJMTagTitle::updateRec(
			WznmJMTagTitle* rec
		) {
};

void TblWznmJMTagTitle::updateRst(
			ListWznmJMTagTitle& rst
			, bool transact
		) {
};

void TblWznmJMTagTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMTagTitle::loadRecByRef(
			ubigint ref
			, WznmJMTagTitle** rec
		) {
	return false;
};

bool TblWznmJMTagTitle::loadRecByTagLoc(
			ubigint refWznmMTag
			, ubigint x1RefWznmMLocale
			, WznmJMTagTitle** rec
		) {
	return false;
};

ubigint TblWznmJMTagTitle::loadRefsByTag(
			ubigint refWznmMTag
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMTagTitle::loadRstByTag(
			ubigint refWznmMTag
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	return 0;
};

bool TblWznmJMTagTitle::loadTitByTagLoc(
			ubigint refWznmMTag
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMTagTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	ubigint numload = 0;
	WznmJMTagTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMTagTitle
 ******************************************************************************/

MyTblWznmJMTagTitle::MyTblWznmJMTagTitle() :
			TblWznmJMTagTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMTagTitle::~MyTblWznmJMTagTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMTagTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMTagTitle (refWznmMTag, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMTagTitle SET refWznmMTag = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMTagTitle WHERE ref = ?", false);
};

bool MyTblWznmJMTagTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMTagTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMTagTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMTagTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMTagTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMTagTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMTag = atoll((char*) dbrow[1]); else _rec->refWznmMTag = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMTagTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMTagTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMTagTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMTagTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMTagTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMTag = atoll((char*) dbrow[1]); else rec->refWznmMTag = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMTagTitle::insertRec(
			WznmJMTagTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTag,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMTagTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMTagTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMTagTitle::insertRst(
			ListWznmJMTagTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMTagTitle::updateRec(
			WznmJMTagTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTag,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMTagTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMTagTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMTagTitle::updateRst(
			ListWznmJMTagTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMTagTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMTagTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMTagTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMTagTitle::loadRecByRef(
			ubigint ref
			, WznmJMTagTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMTagTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMTagTitle::loadRecByTagLoc(
			ubigint refWznmMTag
			, ubigint x1RefWznmMLocale
			, WznmJMTagTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMTag, x1RefWznmMLocale, Title FROM TblWznmJMTagTitle WHERE refWznmMTag = " + to_string(refWznmMTag) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMTagTitle::loadRefsByTag(
			ubigint refWznmMTag
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMTagTitle WHERE refWznmMTag = " + to_string(refWznmMTag) + "", append, refs);
};

ubigint MyTblWznmJMTagTitle::loadRstByTag(
			ubigint refWznmMTag
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTag, x1RefWznmMLocale, Title FROM TblWznmJMTagTitle WHERE refWznmMTag = " + to_string(refWznmMTag) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMTagTitle::loadTitByTagLoc(
			ubigint refWznmMTag
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMTagTitle WHERE refWznmMTag = " + to_string(refWznmMTag) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMTagTitle
 ******************************************************************************/

PgTblWznmJMTagTitle::PgTblWznmJMTagTitle() :
			TblWznmJMTagTitle()
			, PgTable()
		{
};

PgTblWznmJMTagTitle::~PgTblWznmJMTagTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMTagTitle::initStatements() {
	createStatement("TblWznmJMTagTitle_insertRec", "INSERT INTO TblWznmJMTagTitle (refWznmMTag, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMTagTitle_updateRec", "UPDATE TblWznmJMTagTitle SET refWznmMTag = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMTagTitle_removeRecByRef", "DELETE FROM TblWznmJMTagTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMTagTitle_loadRecByRef", "SELECT ref, refWznmMTag, x1RefWznmMLocale, Title FROM TblWznmJMTagTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMTagTitle_loadRecByTagLoc", "SELECT ref, refWznmMTag, x1RefWznmMLocale, Title FROM TblWznmJMTagTitle WHERE refWznmMTag = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMTagTitle_loadRefsByTag", "SELECT ref FROM TblWznmJMTagTitle WHERE refWznmMTag = $1", 1);
	createStatement("TblWznmJMTagTitle_loadRstByTag", "SELECT ref, refWznmMTag, x1RefWznmMLocale, Title FROM TblWznmJMTagTitle WHERE refWznmMTag = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMTagTitle_loadTitByTagLoc", "SELECT Title FROM TblWznmJMTagTitle WHERE refWznmMTag = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMTagTitle::loadRec(
			PGresult* res
			, WznmJMTagTitle** rec
		) {
	char* ptr;

	WznmJMTagTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMTagTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtag"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMTag = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMTagTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMTagTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtag"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMTagTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMTag = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMTagTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMTagTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMTagTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMTagTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMTagTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMTagTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMTagTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMTagTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMTagTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMTagTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMTagTitle::insertRec(
			WznmJMTagTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMTag = htonl64(rec->refWznmMTag);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMTag,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMTagTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMTagTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMTagTitle::insertRst(
			ListWznmJMTagTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMTagTitle::updateRec(
			WznmJMTagTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMTag = htonl64(rec->refWznmMTag);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMTag,
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

	res = PQexecPrepared(dbs, "TblWznmJMTagTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMTagTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMTagTitle::updateRst(
			ListWznmJMTagTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMTagTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMTagTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMTagTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMTagTitle::loadRecByRef(
			ubigint ref
			, WznmJMTagTitle** rec
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

	return loadRecByStmt("TblWznmJMTagTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMTagTitle::loadRecByTagLoc(
			ubigint refWznmMTag
			, ubigint x1RefWznmMLocale
			, WznmJMTagTitle** rec
		) {
	ubigint _refWznmMTag = htonl64(refWznmMTag);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMTag,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMTagTitle_loadRecByTagLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMTagTitle::loadRefsByTag(
			ubigint refWznmMTag
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMTag = htonl64(refWznmMTag);

	const char* vals[] = {
		(char*) &_refWznmMTag
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMTagTitle_loadRefsByTag", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMTagTitle::loadRstByTag(
			ubigint refWznmMTag
			, const bool append
			, ListWznmJMTagTitle& rst
		) {
	ubigint _refWznmMTag = htonl64(refWznmMTag);

	const char* vals[] = {
		(char*) &_refWznmMTag
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMTagTitle_loadRstByTag", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMTagTitle::loadTitByTagLoc(
			ubigint refWznmMTag
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMTag = htonl64(refWznmMTag);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMTag,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMTagTitle_loadTitByTagLoc", 2, vals, l, f, Title);
};

#endif
