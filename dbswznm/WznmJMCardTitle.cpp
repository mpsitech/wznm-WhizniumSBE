/**
	* \file WznmJMCardTitle.cpp
	* database access for table TblWznmJMCardTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJMCardTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMCardTitle
 ******************************************************************************/

WznmJMCardTitle::WznmJMCardTitle(
			const ubigint ref
			, const ubigint refWznmMCard
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMCard = refWznmMCard;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMCardTitle::operator==(
			const WznmJMCardTitle& comp
		) {
	return false;
};

bool WznmJMCardTitle::operator!=(
			const WznmJMCardTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMCardTitle
 ******************************************************************************/

ListWznmJMCardTitle::ListWznmJMCardTitle() {
};

ListWznmJMCardTitle::ListWznmJMCardTitle(
			const ListWznmJMCardTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMCardTitle(*(src.nodes[i]));
};

ListWznmJMCardTitle::~ListWznmJMCardTitle() {
	clear();
};

void ListWznmJMCardTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMCardTitle::size() const {
	return(nodes.size());
};

void ListWznmJMCardTitle::append(
			WznmJMCardTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMCardTitle* ListWznmJMCardTitle::operator[](
			const uint ix
		) {
	WznmJMCardTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMCardTitle& ListWznmJMCardTitle::operator=(
			const ListWznmJMCardTitle& src
		) {
	WznmJMCardTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMCardTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMCardTitle::operator==(
			const ListWznmJMCardTitle& comp
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

bool ListWznmJMCardTitle::operator!=(
			const ListWznmJMCardTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMCardTitle
 ******************************************************************************/

TblWznmJMCardTitle::TblWznmJMCardTitle() {
};

TblWznmJMCardTitle::~TblWznmJMCardTitle() {
};

bool TblWznmJMCardTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMCardTitle** rec
		) {
	return false;
};

ubigint TblWznmJMCardTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMCardTitle::insertRec(
			WznmJMCardTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMCardTitle::insertNewRec(
			WznmJMCardTitle** rec
			, const ubigint refWznmMCard
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMCardTitle* _rec = NULL;

	_rec = new WznmJMCardTitle(0, refWznmMCard, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMCardTitle::appendNewRecToRst(
			ListWznmJMCardTitle& rst
			, WznmJMCardTitle** rec
			, const ubigint refWznmMCard
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMCardTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMCard, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMCardTitle::insertRst(
			ListWznmJMCardTitle& rst
			, bool transact
		) {
};

void TblWznmJMCardTitle::updateRec(
			WznmJMCardTitle* rec
		) {
};

void TblWznmJMCardTitle::updateRst(
			ListWznmJMCardTitle& rst
			, bool transact
		) {
};

void TblWznmJMCardTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMCardTitle::loadRecByRef(
			ubigint ref
			, WznmJMCardTitle** rec
		) {
	return false;
};

bool TblWznmJMCardTitle::loadRecByCarLoc(
			ubigint refWznmMCard
			, ubigint x1RefWznmMLocale
			, WznmJMCardTitle** rec
		) {
	return false;
};

ubigint TblWznmJMCardTitle::loadRefsByCar(
			ubigint refWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMCardTitle::loadRstByCar(
			ubigint refWznmMCard
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	return 0;
};

bool TblWznmJMCardTitle::loadTitByCarLoc(
			ubigint refWznmMCard
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMCardTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	ubigint numload = 0;
	WznmJMCardTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMCardTitle
 ******************************************************************************/

MyTblWznmJMCardTitle::MyTblWznmJMCardTitle() :
			TblWznmJMCardTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMCardTitle::~MyTblWznmJMCardTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMCardTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMCardTitle (refWznmMCard, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMCardTitle SET refWznmMCard = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMCardTitle WHERE ref = ?", false);
};

bool MyTblWznmJMCardTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMCardTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMCardTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMCardTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMCardTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMCardTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMCard = atoll((char*) dbrow[1]); else _rec->refWznmMCard = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMCardTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMCardTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMCardTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMCardTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMCardTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMCard = atoll((char*) dbrow[1]); else rec->refWznmMCard = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMCardTitle::insertRec(
			WznmJMCardTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCard,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMCardTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMCardTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMCardTitle::insertRst(
			ListWznmJMCardTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMCardTitle::updateRec(
			WznmJMCardTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCard,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMCardTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMCardTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMCardTitle::updateRst(
			ListWznmJMCardTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMCardTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMCardTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMCardTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMCardTitle::loadRecByRef(
			ubigint ref
			, WznmJMCardTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMCardTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMCardTitle::loadRecByCarLoc(
			ubigint refWznmMCard
			, ubigint x1RefWznmMLocale
			, WznmJMCardTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMCard, x1RefWznmMLocale, Title FROM TblWznmJMCardTitle WHERE refWznmMCard = " + to_string(refWznmMCard) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMCardTitle::loadRefsByCar(
			ubigint refWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMCardTitle WHERE refWznmMCard = " + to_string(refWznmMCard) + "", append, refs);
};

ubigint MyTblWznmJMCardTitle::loadRstByCar(
			ubigint refWznmMCard
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMCard, x1RefWznmMLocale, Title FROM TblWznmJMCardTitle WHERE refWznmMCard = " + to_string(refWznmMCard) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMCardTitle::loadTitByCarLoc(
			ubigint refWznmMCard
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMCardTitle WHERE refWznmMCard = " + to_string(refWznmMCard) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMCardTitle
 ******************************************************************************/

PgTblWznmJMCardTitle::PgTblWznmJMCardTitle() :
			TblWznmJMCardTitle()
			, PgTable()
		{
};

PgTblWznmJMCardTitle::~PgTblWznmJMCardTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMCardTitle::initStatements() {
	createStatement("TblWznmJMCardTitle_insertRec", "INSERT INTO TblWznmJMCardTitle (refWznmMCard, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMCardTitle_updateRec", "UPDATE TblWznmJMCardTitle SET refWznmMCard = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMCardTitle_removeRecByRef", "DELETE FROM TblWznmJMCardTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMCardTitle_loadRecByRef", "SELECT ref, refWznmMCard, x1RefWznmMLocale, Title FROM TblWznmJMCardTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMCardTitle_loadRecByCarLoc", "SELECT ref, refWznmMCard, x1RefWznmMLocale, Title FROM TblWznmJMCardTitle WHERE refWznmMCard = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMCardTitle_loadRefsByCar", "SELECT ref FROM TblWznmJMCardTitle WHERE refWznmMCard = $1", 1);
	createStatement("TblWznmJMCardTitle_loadRstByCar", "SELECT ref, refWznmMCard, x1RefWznmMLocale, Title FROM TblWznmJMCardTitle WHERE refWznmMCard = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMCardTitle_loadTitByCarLoc", "SELECT Title FROM TblWznmJMCardTitle WHERE refWznmMCard = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMCardTitle::loadRec(
			PGresult* res
			, WznmJMCardTitle** rec
		) {
	char* ptr;

	WznmJMCardTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMCardTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMCard = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMCardTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMCardTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMCardTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMCard = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMCardTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMCardTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMCardTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMCardTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMCardTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMCardTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMCardTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMCardTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMCardTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMCardTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMCardTitle::insertRec(
			WznmJMCardTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMCard,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMCardTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMCardTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMCardTitle::insertRst(
			ListWznmJMCardTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMCardTitle::updateRec(
			WznmJMCardTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMCard,
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

	res = PQexecPrepared(dbs, "TblWznmJMCardTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMCardTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMCardTitle::updateRst(
			ListWznmJMCardTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMCardTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMCardTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMCardTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMCardTitle::loadRecByRef(
			ubigint ref
			, WznmJMCardTitle** rec
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

	return loadRecByStmt("TblWznmJMCardTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMCardTitle::loadRecByCarLoc(
			ubigint refWznmMCard
			, ubigint x1RefWznmMLocale
			, WznmJMCardTitle** rec
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMCard,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMCardTitle_loadRecByCarLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMCardTitle::loadRefsByCar(
			ubigint refWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMCardTitle_loadRefsByCar", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMCardTitle::loadRstByCar(
			ubigint refWznmMCard
			, const bool append
			, ListWznmJMCardTitle& rst
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMCardTitle_loadRstByCar", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMCardTitle::loadTitByCarLoc(
			ubigint refWznmMCard
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMCard,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMCardTitle_loadTitByCarLoc", 2, vals, l, f, Title);
};

#endif

