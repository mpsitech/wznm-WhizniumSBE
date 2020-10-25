/**
	* \file WznmJMSquawkTitle.cpp
	* database access for table TblWznmJMSquawkTitle (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmJMSquawkTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMSquawkTitle
 ******************************************************************************/

WznmJMSquawkTitle::WznmJMSquawkTitle(
			const ubigint ref
			, const ubigint refWznmMSquawk
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMSquawk = refWznmMSquawk;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMSquawkTitle::operator==(
			const WznmJMSquawkTitle& comp
		) {
	return false;
};

bool WznmJMSquawkTitle::operator!=(
			const WznmJMSquawkTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMSquawkTitle
 ******************************************************************************/

ListWznmJMSquawkTitle::ListWznmJMSquawkTitle() {
};

ListWznmJMSquawkTitle::ListWznmJMSquawkTitle(
			const ListWznmJMSquawkTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMSquawkTitle(*(src.nodes[i]));
};

ListWznmJMSquawkTitle::~ListWznmJMSquawkTitle() {
	clear();
};

void ListWznmJMSquawkTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMSquawkTitle::size() const {
	return(nodes.size());
};

void ListWznmJMSquawkTitle::append(
			WznmJMSquawkTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMSquawkTitle* ListWznmJMSquawkTitle::operator[](
			const uint ix
		) {
	WznmJMSquawkTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMSquawkTitle& ListWznmJMSquawkTitle::operator=(
			const ListWznmJMSquawkTitle& src
		) {
	WznmJMSquawkTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMSquawkTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMSquawkTitle::operator==(
			const ListWznmJMSquawkTitle& comp
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

bool ListWznmJMSquawkTitle::operator!=(
			const ListWznmJMSquawkTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMSquawkTitle
 ******************************************************************************/

TblWznmJMSquawkTitle::TblWznmJMSquawkTitle() {
};

TblWznmJMSquawkTitle::~TblWznmJMSquawkTitle() {
};

bool TblWznmJMSquawkTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMSquawkTitle** rec
		) {
	return false;
};

ubigint TblWznmJMSquawkTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMSquawkTitle::insertRec(
			WznmJMSquawkTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMSquawkTitle::insertNewRec(
			WznmJMSquawkTitle** rec
			, const ubigint refWznmMSquawk
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMSquawkTitle* _rec = NULL;

	_rec = new WznmJMSquawkTitle(0, refWznmMSquawk, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMSquawkTitle::appendNewRecToRst(
			ListWznmJMSquawkTitle& rst
			, WznmJMSquawkTitle** rec
			, const ubigint refWznmMSquawk
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMSquawkTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMSquawk, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMSquawkTitle::insertRst(
			ListWznmJMSquawkTitle& rst
			, bool transact
		) {
};

void TblWznmJMSquawkTitle::updateRec(
			WznmJMSquawkTitle* rec
		) {
};

void TblWznmJMSquawkTitle::updateRst(
			ListWznmJMSquawkTitle& rst
			, bool transact
		) {
};

void TblWznmJMSquawkTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMSquawkTitle::loadRecByRef(
			ubigint ref
			, WznmJMSquawkTitle** rec
		) {
	return false;
};

bool TblWznmJMSquawkTitle::loadRecBySqkLoc(
			ubigint refWznmMSquawk
			, ubigint x1RefWznmMLocale
			, WznmJMSquawkTitle** rec
		) {
	return false;
};

ubigint TblWznmJMSquawkTitle::loadRefsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMSquawkTitle::loadRstBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	return 0;
};

bool TblWznmJMSquawkTitle::loadTitBySqkLoc(
			ubigint refWznmMSquawk
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMSquawkTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	ubigint numload = 0;
	WznmJMSquawkTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMSquawkTitle
 ******************************************************************************/

MyTblWznmJMSquawkTitle::MyTblWznmJMSquawkTitle() :
			TblWznmJMSquawkTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMSquawkTitle::~MyTblWznmJMSquawkTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMSquawkTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMSquawkTitle (refWznmMSquawk, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMSquawkTitle SET refWznmMSquawk = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMSquawkTitle WHERE ref = ?", false);
};

bool MyTblWznmJMSquawkTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMSquawkTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMSquawkTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMSquawkTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMSquawkTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMSquawkTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMSquawk = atoll((char*) dbrow[1]); else _rec->refWznmMSquawk = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMSquawkTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMSquawkTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMSquawkTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMSquawkTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMSquawkTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMSquawk = atoll((char*) dbrow[1]); else rec->refWznmMSquawk = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMSquawkTitle::insertRec(
			WznmJMSquawkTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSquawk,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMSquawkTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMSquawkTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMSquawkTitle::insertRst(
			ListWznmJMSquawkTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMSquawkTitle::updateRec(
			WznmJMSquawkTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSquawk,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMSquawkTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMSquawkTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMSquawkTitle::updateRst(
			ListWznmJMSquawkTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMSquawkTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMSquawkTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMSquawkTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMSquawkTitle::loadRecByRef(
			ubigint ref
			, WznmJMSquawkTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMSquawkTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMSquawkTitle::loadRecBySqkLoc(
			ubigint refWznmMSquawk
			, ubigint x1RefWznmMLocale
			, WznmJMSquawkTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMSquawk, x1RefWznmMLocale, Title FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMSquawkTitle::loadRefsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + "", append, refs);
};

ubigint MyTblWznmJMSquawkTitle::loadRstBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMSquawk, x1RefWznmMLocale, Title FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMSquawkTitle::loadTitBySqkLoc(
			ubigint refWznmMSquawk
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMSquawkTitle
 ******************************************************************************/

PgTblWznmJMSquawkTitle::PgTblWznmJMSquawkTitle() :
			TblWznmJMSquawkTitle()
			, PgTable()
		{
};

PgTblWznmJMSquawkTitle::~PgTblWznmJMSquawkTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMSquawkTitle::initStatements() {
	createStatement("TblWznmJMSquawkTitle_insertRec", "INSERT INTO TblWznmJMSquawkTitle (refWznmMSquawk, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMSquawkTitle_updateRec", "UPDATE TblWznmJMSquawkTitle SET refWznmMSquawk = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMSquawkTitle_removeRecByRef", "DELETE FROM TblWznmJMSquawkTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMSquawkTitle_loadRecByRef", "SELECT ref, refWznmMSquawk, x1RefWznmMLocale, Title FROM TblWznmJMSquawkTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMSquawkTitle_loadRecBySqkLoc", "SELECT ref, refWznmMSquawk, x1RefWznmMLocale, Title FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMSquawkTitle_loadRefsBySqk", "SELECT ref FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = $1", 1);
	createStatement("TblWznmJMSquawkTitle_loadRstBySqk", "SELECT ref, refWznmMSquawk, x1RefWznmMLocale, Title FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMSquawkTitle_loadTitBySqkLoc", "SELECT Title FROM TblWznmJMSquawkTitle WHERE refWznmMSquawk = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMSquawkTitle::loadRec(
			PGresult* res
			, WznmJMSquawkTitle** rec
		) {
	char* ptr;

	WznmJMSquawkTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMSquawkTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMSquawk = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMSquawkTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMSquawkTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMSquawkTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMSquawk = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMSquawkTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMSquawkTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMSquawkTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMSquawkTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMSquawkTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMSquawkTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMSquawkTitle::insertRec(
			WznmJMSquawkTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMSquawk,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMSquawkTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMSquawkTitle::insertRst(
			ListWznmJMSquawkTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMSquawkTitle::updateRec(
			WznmJMSquawkTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMSquawk,
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

	res = PQexecPrepared(dbs, "TblWznmJMSquawkTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMSquawkTitle::updateRst(
			ListWznmJMSquawkTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMSquawkTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMSquawkTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMSquawkTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMSquawkTitle::loadRecByRef(
			ubigint ref
			, WznmJMSquawkTitle** rec
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

	return loadRecByStmt("TblWznmJMSquawkTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMSquawkTitle::loadRecBySqkLoc(
			ubigint refWznmMSquawk
			, ubigint x1RefWznmMLocale
			, WznmJMSquawkTitle** rec
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMSquawk,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMSquawkTitle_loadRecBySqkLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMSquawkTitle::loadRefsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMSquawkTitle_loadRefsBySqk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMSquawkTitle::loadRstBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, ListWznmJMSquawkTitle& rst
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMSquawkTitle_loadRstBySqk", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMSquawkTitle::loadTitBySqkLoc(
			ubigint refWznmMSquawk
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMSquawk,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMSquawkTitle_loadTitBySqkLoc", 2, vals, l, f, Title);
};

#endif

