/**
	* \file WznmJMControlTitle.cpp
	* database access for table TblWznmJMControlTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMControlTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMControlTitle
 ******************************************************************************/

WznmJMControlTitle::WznmJMControlTitle(
			const ubigint ref
			, const ubigint refWznmMControl
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMControl = refWznmMControl;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMControlTitle::operator==(
			const WznmJMControlTitle& comp
		) {
	return false;
};

bool WznmJMControlTitle::operator!=(
			const WznmJMControlTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMControlTitle
 ******************************************************************************/

ListWznmJMControlTitle::ListWznmJMControlTitle() {
};

ListWznmJMControlTitle::ListWznmJMControlTitle(
			const ListWznmJMControlTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMControlTitle(*(src.nodes[i]));
};

ListWznmJMControlTitle::~ListWznmJMControlTitle() {
	clear();
};

void ListWznmJMControlTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMControlTitle::size() const {
	return(nodes.size());
};

void ListWznmJMControlTitle::append(
			WznmJMControlTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMControlTitle* ListWznmJMControlTitle::operator[](
			const uint ix
		) {
	WznmJMControlTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMControlTitle& ListWznmJMControlTitle::operator=(
			const ListWznmJMControlTitle& src
		) {
	WznmJMControlTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMControlTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMControlTitle::operator==(
			const ListWznmJMControlTitle& comp
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

bool ListWznmJMControlTitle::operator!=(
			const ListWznmJMControlTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMControlTitle
 ******************************************************************************/

TblWznmJMControlTitle::TblWznmJMControlTitle() {
};

TblWznmJMControlTitle::~TblWznmJMControlTitle() {
};

bool TblWznmJMControlTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMControlTitle** rec
		) {
	return false;
};

ubigint TblWznmJMControlTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMControlTitle::insertRec(
			WznmJMControlTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMControlTitle::insertNewRec(
			WznmJMControlTitle** rec
			, const ubigint refWznmMControl
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMControlTitle* _rec = NULL;

	_rec = new WznmJMControlTitle(0, refWznmMControl, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMControlTitle::appendNewRecToRst(
			ListWznmJMControlTitle& rst
			, WznmJMControlTitle** rec
			, const ubigint refWznmMControl
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMControlTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMControl, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMControlTitle::insertRst(
			ListWznmJMControlTitle& rst
			, bool transact
		) {
};

void TblWznmJMControlTitle::updateRec(
			WznmJMControlTitle* rec
		) {
};

void TblWznmJMControlTitle::updateRst(
			ListWznmJMControlTitle& rst
			, bool transact
		) {
};

void TblWznmJMControlTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMControlTitle::loadRecByRef(
			ubigint ref
			, WznmJMControlTitle** rec
		) {
	return false;
};

bool TblWznmJMControlTitle::loadRecByConLoc(
			ubigint refWznmMControl
			, ubigint x1RefWznmMLocale
			, WznmJMControlTitle** rec
		) {
	return false;
};

ubigint TblWznmJMControlTitle::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMControlTitle::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	return 0;
};

bool TblWznmJMControlTitle::loadTitByConLoc(
			ubigint refWznmMControl
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMControlTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	ubigint numload = 0;
	WznmJMControlTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMControlTitle
 ******************************************************************************/

MyTblWznmJMControlTitle::MyTblWznmJMControlTitle() :
			TblWznmJMControlTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMControlTitle::~MyTblWznmJMControlTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMControlTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMControlTitle (refWznmMControl, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMControlTitle SET refWznmMControl = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMControlTitle WHERE ref = ?", false);
};

bool MyTblWznmJMControlTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMControlTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMControlTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMControlTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMControlTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMControlTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMControl = atoll((char*) dbrow[1]); else _rec->refWznmMControl = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMControlTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMControlTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMControlTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMControlTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMControlTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMControl = atoll((char*) dbrow[1]); else rec->refWznmMControl = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMControlTitle::insertRec(
			WznmJMControlTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMControlTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMControlTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMControlTitle::insertRst(
			ListWznmJMControlTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMControlTitle::updateRec(
			WznmJMControlTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMControlTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMControlTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMControlTitle::updateRst(
			ListWznmJMControlTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMControlTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMControlTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMControlTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMControlTitle::loadRecByRef(
			ubigint ref
			, WznmJMControlTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMControlTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMControlTitle::loadRecByConLoc(
			ubigint refWznmMControl
			, ubigint x1RefWznmMLocale
			, WznmJMControlTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMControl, x1RefWznmMLocale, Title FROM TblWznmJMControlTitle WHERE refWznmMControl = " + to_string(refWznmMControl) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMControlTitle::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMControlTitle WHERE refWznmMControl = " + to_string(refWznmMControl) + "", append, refs);
};

ubigint MyTblWznmJMControlTitle::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMControl, x1RefWznmMLocale, Title FROM TblWznmJMControlTitle WHERE refWznmMControl = " + to_string(refWznmMControl) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMControlTitle::loadTitByConLoc(
			ubigint refWznmMControl
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMControlTitle WHERE refWznmMControl = " + to_string(refWznmMControl) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMControlTitle
 ******************************************************************************/

PgTblWznmJMControlTitle::PgTblWznmJMControlTitle() :
			TblWznmJMControlTitle()
			, PgTable()
		{
};

PgTblWznmJMControlTitle::~PgTblWznmJMControlTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMControlTitle::initStatements() {
	createStatement("TblWznmJMControlTitle_insertRec", "INSERT INTO TblWznmJMControlTitle (refWznmMControl, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMControlTitle_updateRec", "UPDATE TblWznmJMControlTitle SET refWznmMControl = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMControlTitle_removeRecByRef", "DELETE FROM TblWznmJMControlTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMControlTitle_loadRecByRef", "SELECT ref, refWznmMControl, x1RefWznmMLocale, Title FROM TblWznmJMControlTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMControlTitle_loadRecByConLoc", "SELECT ref, refWznmMControl, x1RefWznmMLocale, Title FROM TblWznmJMControlTitle WHERE refWznmMControl = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMControlTitle_loadRefsByCon", "SELECT ref FROM TblWznmJMControlTitle WHERE refWznmMControl = $1", 1);
	createStatement("TblWznmJMControlTitle_loadRstByCon", "SELECT ref, refWznmMControl, x1RefWznmMLocale, Title FROM TblWznmJMControlTitle WHERE refWznmMControl = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMControlTitle_loadTitByConLoc", "SELECT Title FROM TblWznmJMControlTitle WHERE refWznmMControl = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMControlTitle::loadRec(
			PGresult* res
			, WznmJMControlTitle** rec
		) {
	char* ptr;

	WznmJMControlTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMControlTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMControlTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMControlTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMControlTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMControlTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMControlTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControlTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMControlTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControlTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMControlTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMControlTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControlTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMControlTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControlTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMControlTitle::insertRec(
			WznmJMControlTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMControlTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControlTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMControlTitle::insertRst(
			ListWznmJMControlTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMControlTitle::updateRec(
			WznmJMControlTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMControl,
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

	res = PQexecPrepared(dbs, "TblWznmJMControlTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMControlTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMControlTitle::updateRst(
			ListWznmJMControlTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMControlTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMControlTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMControlTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMControlTitle::loadRecByRef(
			ubigint ref
			, WznmJMControlTitle** rec
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

	return loadRecByStmt("TblWznmJMControlTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMControlTitle::loadRecByConLoc(
			ubigint refWznmMControl
			, ubigint x1RefWznmMLocale
			, WznmJMControlTitle** rec
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMControlTitle_loadRecByConLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMControlTitle::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMControlTitle_loadRefsByCon", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMControlTitle::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmJMControlTitle& rst
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMControlTitle_loadRstByCon", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMControlTitle::loadTitByConLoc(
			ubigint refWznmMControl
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMControlTitle_loadTitByConLoc", 2, vals, l, f, Title);
};

#endif
