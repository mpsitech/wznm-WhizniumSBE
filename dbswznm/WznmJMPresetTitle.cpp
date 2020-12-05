/**
	* \file WznmJMPresetTitle.cpp
	* database access for table TblWznmJMPresetTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMPresetTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMPresetTitle
 ******************************************************************************/

WznmJMPresetTitle::WznmJMPresetTitle(
			const ubigint ref
			, const ubigint refWznmMPreset
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMPreset = refWznmMPreset;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMPresetTitle::operator==(
			const WznmJMPresetTitle& comp
		) {
	return false;
};

bool WznmJMPresetTitle::operator!=(
			const WznmJMPresetTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMPresetTitle
 ******************************************************************************/

ListWznmJMPresetTitle::ListWznmJMPresetTitle() {
};

ListWznmJMPresetTitle::ListWznmJMPresetTitle(
			const ListWznmJMPresetTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMPresetTitle(*(src.nodes[i]));
};

ListWznmJMPresetTitle::~ListWznmJMPresetTitle() {
	clear();
};

void ListWznmJMPresetTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMPresetTitle::size() const {
	return(nodes.size());
};

void ListWznmJMPresetTitle::append(
			WznmJMPresetTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMPresetTitle* ListWznmJMPresetTitle::operator[](
			const uint ix
		) {
	WznmJMPresetTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMPresetTitle& ListWznmJMPresetTitle::operator=(
			const ListWznmJMPresetTitle& src
		) {
	WznmJMPresetTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMPresetTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMPresetTitle::operator==(
			const ListWznmJMPresetTitle& comp
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

bool ListWznmJMPresetTitle::operator!=(
			const ListWznmJMPresetTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMPresetTitle
 ******************************************************************************/

TblWznmJMPresetTitle::TblWznmJMPresetTitle() {
};

TblWznmJMPresetTitle::~TblWznmJMPresetTitle() {
};

bool TblWznmJMPresetTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMPresetTitle** rec
		) {
	return false;
};

ubigint TblWznmJMPresetTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMPresetTitle::insertRec(
			WznmJMPresetTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMPresetTitle::insertNewRec(
			WznmJMPresetTitle** rec
			, const ubigint refWznmMPreset
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMPresetTitle* _rec = NULL;

	_rec = new WznmJMPresetTitle(0, refWznmMPreset, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMPresetTitle::appendNewRecToRst(
			ListWznmJMPresetTitle& rst
			, WznmJMPresetTitle** rec
			, const ubigint refWznmMPreset
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMPresetTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMPreset, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMPresetTitle::insertRst(
			ListWznmJMPresetTitle& rst
			, bool transact
		) {
};

void TblWznmJMPresetTitle::updateRec(
			WznmJMPresetTitle* rec
		) {
};

void TblWznmJMPresetTitle::updateRst(
			ListWznmJMPresetTitle& rst
			, bool transact
		) {
};

void TblWznmJMPresetTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMPresetTitle::loadRecByRef(
			ubigint ref
			, WznmJMPresetTitle** rec
		) {
	return false;
};

bool TblWznmJMPresetTitle::loadRecByPstLoc(
			ubigint refWznmMPreset
			, ubigint x1RefWznmMLocale
			, WznmJMPresetTitle** rec
		) {
	return false;
};

ubigint TblWznmJMPresetTitle::loadRefsByPst(
			ubigint refWznmMPreset
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMPresetTitle::loadRstByPst(
			ubigint refWznmMPreset
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	return 0;
};

bool TblWznmJMPresetTitle::loadTitByPstLoc(
			ubigint refWznmMPreset
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMPresetTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	ubigint numload = 0;
	WznmJMPresetTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMPresetTitle
 ******************************************************************************/

MyTblWznmJMPresetTitle::MyTblWznmJMPresetTitle() :
			TblWznmJMPresetTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMPresetTitle::~MyTblWznmJMPresetTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMPresetTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMPresetTitle (refWznmMPreset, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMPresetTitle SET refWznmMPreset = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMPresetTitle WHERE ref = ?", false);
};

bool MyTblWznmJMPresetTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMPresetTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMPresetTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMPresetTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMPresetTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMPresetTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMPreset = atoll((char*) dbrow[1]); else _rec->refWznmMPreset = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMPresetTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMPresetTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMPresetTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMPresetTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMPresetTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMPreset = atoll((char*) dbrow[1]); else rec->refWznmMPreset = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMPresetTitle::insertRec(
			WznmJMPresetTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPreset,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMPresetTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMPresetTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMPresetTitle::insertRst(
			ListWznmJMPresetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMPresetTitle::updateRec(
			WznmJMPresetTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPreset,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMPresetTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMPresetTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMPresetTitle::updateRst(
			ListWznmJMPresetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMPresetTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMPresetTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMPresetTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMPresetTitle::loadRecByRef(
			ubigint ref
			, WznmJMPresetTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMPresetTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMPresetTitle::loadRecByPstLoc(
			ubigint refWznmMPreset
			, ubigint x1RefWznmMLocale
			, WznmJMPresetTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMPreset, x1RefWznmMLocale, Title FROM TblWznmJMPresetTitle WHERE refWznmMPreset = " + to_string(refWznmMPreset) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMPresetTitle::loadRefsByPst(
			ubigint refWznmMPreset
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMPresetTitle WHERE refWznmMPreset = " + to_string(refWznmMPreset) + "", append, refs);
};

ubigint MyTblWznmJMPresetTitle::loadRstByPst(
			ubigint refWznmMPreset
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMPreset, x1RefWznmMLocale, Title FROM TblWznmJMPresetTitle WHERE refWznmMPreset = " + to_string(refWznmMPreset) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMPresetTitle::loadTitByPstLoc(
			ubigint refWznmMPreset
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMPresetTitle WHERE refWznmMPreset = " + to_string(refWznmMPreset) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMPresetTitle
 ******************************************************************************/

PgTblWznmJMPresetTitle::PgTblWznmJMPresetTitle() :
			TblWznmJMPresetTitle()
			, PgTable()
		{
};

PgTblWznmJMPresetTitle::~PgTblWznmJMPresetTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMPresetTitle::initStatements() {
	createStatement("TblWznmJMPresetTitle_insertRec", "INSERT INTO TblWznmJMPresetTitle (refWznmMPreset, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMPresetTitle_updateRec", "UPDATE TblWznmJMPresetTitle SET refWznmMPreset = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMPresetTitle_removeRecByRef", "DELETE FROM TblWznmJMPresetTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMPresetTitle_loadRecByRef", "SELECT ref, refWznmMPreset, x1RefWznmMLocale, Title FROM TblWznmJMPresetTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMPresetTitle_loadRecByPstLoc", "SELECT ref, refWznmMPreset, x1RefWznmMLocale, Title FROM TblWznmJMPresetTitle WHERE refWznmMPreset = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMPresetTitle_loadRefsByPst", "SELECT ref FROM TblWznmJMPresetTitle WHERE refWznmMPreset = $1", 1);
	createStatement("TblWznmJMPresetTitle_loadRstByPst", "SELECT ref, refWznmMPreset, x1RefWznmMLocale, Title FROM TblWznmJMPresetTitle WHERE refWznmMPreset = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMPresetTitle_loadTitByPstLoc", "SELECT Title FROM TblWznmJMPresetTitle WHERE refWznmMPreset = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMPresetTitle::loadRec(
			PGresult* res
			, WznmJMPresetTitle** rec
		) {
	char* ptr;

	WznmJMPresetTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMPresetTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMPresetTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMPresetTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMPresetTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMPresetTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMPresetTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPresetTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMPresetTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPresetTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMPresetTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMPresetTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPresetTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMPresetTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPresetTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMPresetTitle::insertRec(
			WznmJMPresetTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMPreset,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMPresetTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPresetTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMPresetTitle::insertRst(
			ListWznmJMPresetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMPresetTitle::updateRec(
			WznmJMPresetTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMPreset,
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

	res = PQexecPrepared(dbs, "TblWznmJMPresetTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMPresetTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMPresetTitle::updateRst(
			ListWznmJMPresetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMPresetTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMPresetTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMPresetTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMPresetTitle::loadRecByRef(
			ubigint ref
			, WznmJMPresetTitle** rec
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

	return loadRecByStmt("TblWznmJMPresetTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMPresetTitle::loadRecByPstLoc(
			ubigint refWznmMPreset
			, ubigint x1RefWznmMLocale
			, WznmJMPresetTitle** rec
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMPreset,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMPresetTitle_loadRecByPstLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMPresetTitle::loadRefsByPst(
			ubigint refWznmMPreset
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);

	const char* vals[] = {
		(char*) &_refWznmMPreset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMPresetTitle_loadRefsByPst", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMPresetTitle::loadRstByPst(
			ubigint refWznmMPreset
			, const bool append
			, ListWznmJMPresetTitle& rst
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);

	const char* vals[] = {
		(char*) &_refWznmMPreset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMPresetTitle_loadRstByPst", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMPresetTitle::loadTitByPstLoc(
			ubigint refWznmMPreset
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMPreset,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMPresetTitle_loadTitByPstLoc", 2, vals, l, f, Title);
};

#endif

