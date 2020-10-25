/**
	* \file WznmJMImpexpcplxTitle.cpp
	* database access for table TblWznmJMImpexpcplxTitle (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmJMImpexpcplxTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMImpexpcplxTitle
 ******************************************************************************/

WznmJMImpexpcplxTitle::WznmJMImpexpcplxTitle(
			const ubigint ref
			, const ubigint refWznmMImpexpcplx
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMImpexpcplx = refWznmMImpexpcplx;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->Title = Title;
};

bool WznmJMImpexpcplxTitle::operator==(
			const WznmJMImpexpcplxTitle& comp
		) {
	return false;
};

bool WznmJMImpexpcplxTitle::operator!=(
			const WznmJMImpexpcplxTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMImpexpcplxTitle
 ******************************************************************************/

ListWznmJMImpexpcplxTitle::ListWznmJMImpexpcplxTitle() {
};

ListWznmJMImpexpcplxTitle::ListWznmJMImpexpcplxTitle(
			const ListWznmJMImpexpcplxTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMImpexpcplxTitle(*(src.nodes[i]));
};

ListWznmJMImpexpcplxTitle::~ListWznmJMImpexpcplxTitle() {
	clear();
};

void ListWznmJMImpexpcplxTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMImpexpcplxTitle::size() const {
	return(nodes.size());
};

void ListWznmJMImpexpcplxTitle::append(
			WznmJMImpexpcplxTitle* rec
		) {
	nodes.push_back(rec);
};

WznmJMImpexpcplxTitle* ListWznmJMImpexpcplxTitle::operator[](
			const uint ix
		) {
	WznmJMImpexpcplxTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMImpexpcplxTitle& ListWznmJMImpexpcplxTitle::operator=(
			const ListWznmJMImpexpcplxTitle& src
		) {
	WznmJMImpexpcplxTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMImpexpcplxTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMImpexpcplxTitle::operator==(
			const ListWznmJMImpexpcplxTitle& comp
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

bool ListWznmJMImpexpcplxTitle::operator!=(
			const ListWznmJMImpexpcplxTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMImpexpcplxTitle
 ******************************************************************************/

TblWznmJMImpexpcplxTitle::TblWznmJMImpexpcplxTitle() {
};

TblWznmJMImpexpcplxTitle::~TblWznmJMImpexpcplxTitle() {
};

bool TblWznmJMImpexpcplxTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMImpexpcplxTitle** rec
		) {
	return false;
};

ubigint TblWznmJMImpexpcplxTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	return 0;
};

ubigint TblWznmJMImpexpcplxTitle::insertRec(
			WznmJMImpexpcplxTitle* rec
		) {
	return 0;
};

ubigint TblWznmJMImpexpcplxTitle::insertNewRec(
			WznmJMImpexpcplxTitle** rec
			, const ubigint refWznmMImpexpcplx
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMImpexpcplxTitle* _rec = NULL;

	_rec = new WznmJMImpexpcplxTitle(0, refWznmMImpexpcplx, x1RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMImpexpcplxTitle::appendNewRecToRst(
			ListWznmJMImpexpcplxTitle& rst
			, WznmJMImpexpcplxTitle** rec
			, const ubigint refWznmMImpexpcplx
			, const ubigint x1RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmJMImpexpcplxTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMImpexpcplx, x1RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMImpexpcplxTitle::insertRst(
			ListWznmJMImpexpcplxTitle& rst
			, bool transact
		) {
};

void TblWznmJMImpexpcplxTitle::updateRec(
			WznmJMImpexpcplxTitle* rec
		) {
};

void TblWznmJMImpexpcplxTitle::updateRst(
			ListWznmJMImpexpcplxTitle& rst
			, bool transact
		) {
};

void TblWznmJMImpexpcplxTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMImpexpcplxTitle::loadRecByRef(
			ubigint ref
			, WznmJMImpexpcplxTitle** rec
		) {
	return false;
};

bool TblWznmJMImpexpcplxTitle::loadRecByIexLoc(
			ubigint refWznmMImpexpcplx
			, ubigint x1RefWznmMLocale
			, WznmJMImpexpcplxTitle** rec
		) {
	return false;
};

ubigint TblWznmJMImpexpcplxTitle::loadRefsByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMImpexpcplxTitle::loadRstByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	return 0;
};

bool TblWznmJMImpexpcplxTitle::loadTitByIexLoc(
			ubigint refWznmMImpexpcplx
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJMImpexpcplxTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	ubigint numload = 0;
	WznmJMImpexpcplxTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMImpexpcplxTitle
 ******************************************************************************/

MyTblWznmJMImpexpcplxTitle::MyTblWznmJMImpexpcplxTitle() :
			TblWznmJMImpexpcplxTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMImpexpcplxTitle::~MyTblWznmJMImpexpcplxTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMImpexpcplxTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMImpexpcplxTitle (refWznmMImpexpcplx, x1RefWznmMLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMImpexpcplxTitle SET refWznmMImpexpcplx = ?, x1RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMImpexpcplxTitle WHERE ref = ?", false);
};

bool MyTblWznmJMImpexpcplxTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMImpexpcplxTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMImpexpcplxTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMImpexpcplxTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMImpexpcplx = atoll((char*) dbrow[1]); else _rec->refWznmMImpexpcplx = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMImpexpcplxTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMImpexpcplxTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMImpexpcplxTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMImpexpcplx = atoll((char*) dbrow[1]); else rec->refWznmMImpexpcplx = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMImpexpcplxTitle::insertRec(
			WznmJMImpexpcplxTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMImpexpcplx,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMImpexpcplxTitle::insertRst(
			ListWznmJMImpexpcplxTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMImpexpcplxTitle::updateRec(
			WznmJMImpexpcplxTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMImpexpcplx,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMImpexpcplxTitle::updateRst(
			ListWznmJMImpexpcplxTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMImpexpcplxTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMImpexpcplxTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMImpexpcplxTitle::loadRecByRef(
			ubigint ref
			, WznmJMImpexpcplxTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMImpexpcplxTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMImpexpcplxTitle::loadRecByIexLoc(
			ubigint refWznmMImpexpcplx
			, ubigint x1RefWznmMLocale
			, WznmJMImpexpcplxTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMImpexpcplx, x1RefWznmMLocale, Title FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = " + to_string(refWznmMImpexpcplx) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMImpexpcplxTitle::loadRefsByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = " + to_string(refWznmMImpexpcplx) + "", append, refs);
};

ubigint MyTblWznmJMImpexpcplxTitle::loadRstByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMImpexpcplx, x1RefWznmMLocale, Title FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = " + to_string(refWznmMImpexpcplx) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmJMImpexpcplxTitle::loadTitByIexLoc(
			ubigint refWznmMImpexpcplx
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = " + to_string(refWznmMImpexpcplx) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMImpexpcplxTitle
 ******************************************************************************/

PgTblWznmJMImpexpcplxTitle::PgTblWznmJMImpexpcplxTitle() :
			TblWznmJMImpexpcplxTitle()
			, PgTable()
		{
};

PgTblWznmJMImpexpcplxTitle::~PgTblWznmJMImpexpcplxTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMImpexpcplxTitle::initStatements() {
	createStatement("TblWznmJMImpexpcplxTitle_insertRec", "INSERT INTO TblWznmJMImpexpcplxTitle (refWznmMImpexpcplx, x1RefWznmMLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMImpexpcplxTitle_updateRec", "UPDATE TblWznmJMImpexpcplxTitle SET refWznmMImpexpcplx = $1, x1RefWznmMLocale = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMImpexpcplxTitle_removeRecByRef", "DELETE FROM TblWznmJMImpexpcplxTitle WHERE ref = $1", 1);

	createStatement("TblWznmJMImpexpcplxTitle_loadRecByRef", "SELECT ref, refWznmMImpexpcplx, x1RefWznmMLocale, Title FROM TblWznmJMImpexpcplxTitle WHERE ref = $1", 1);
	createStatement("TblWznmJMImpexpcplxTitle_loadRecByIexLoc", "SELECT ref, refWznmMImpexpcplx, x1RefWznmMLocale, Title FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMImpexpcplxTitle_loadRefsByIex", "SELECT ref FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = $1", 1);
	createStatement("TblWznmJMImpexpcplxTitle_loadRstByIex", "SELECT ref, refWznmMImpexpcplx, x1RefWznmMLocale, Title FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = $1 ORDER BY x1RefWznmMLocale ASC", 1);
	createStatement("TblWznmJMImpexpcplxTitle_loadTitByIexLoc", "SELECT Title FROM TblWznmJMImpexpcplxTitle WHERE refWznmMImpexpcplx = $1 AND x1RefWznmMLocale = $2", 2);
};

bool PgTblWznmJMImpexpcplxTitle::loadRec(
			PGresult* res
			, WznmJMImpexpcplxTitle** rec
		) {
	char* ptr;

	WznmJMImpexpcplxTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMImpexpcplxTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmimpexpcplx"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMImpexpcplx = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMImpexpcplxTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMImpexpcplxTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmimpexpcplx"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmJMImpexpcplxTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMImpexpcplx = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMImpexpcplxTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMImpexpcplxTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMImpexpcplxTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMImpexpcplxTitle::loadRecBySQL(
			const string& sqlstr
			, WznmJMImpexpcplxTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMImpexpcplxTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMImpexpcplxTitle::insertRec(
			WznmJMImpexpcplxTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMImpexpcplx = htonl64(rec->refWznmMImpexpcplx);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx,
		(char*) &_x1RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMImpexpcplxTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMImpexpcplxTitle::insertRst(
			ListWznmJMImpexpcplxTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMImpexpcplxTitle::updateRec(
			WznmJMImpexpcplxTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMImpexpcplx = htonl64(rec->refWznmMImpexpcplx);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx,
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

	res = PQexecPrepared(dbs, "TblWznmJMImpexpcplxTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMImpexpcplxTitle::updateRst(
			ListWznmJMImpexpcplxTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMImpexpcplxTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMImpexpcplxTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMImpexpcplxTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMImpexpcplxTitle::loadRecByRef(
			ubigint ref
			, WznmJMImpexpcplxTitle** rec
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

	return loadRecByStmt("TblWznmJMImpexpcplxTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMImpexpcplxTitle::loadRecByIexLoc(
			ubigint refWznmMImpexpcplx
			, ubigint x1RefWznmMLocale
			, WznmJMImpexpcplxTitle** rec
		) {
	ubigint _refWznmMImpexpcplx = htonl64(refWznmMImpexpcplx);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMImpexpcplxTitle_loadRecByIexLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMImpexpcplxTitle::loadRefsByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMImpexpcplx = htonl64(refWznmMImpexpcplx);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMImpexpcplxTitle_loadRefsByIex", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMImpexpcplxTitle::loadRstByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, ListWznmJMImpexpcplxTitle& rst
		) {
	ubigint _refWznmMImpexpcplx = htonl64(refWznmMImpexpcplx);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMImpexpcplxTitle_loadRstByIex", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMImpexpcplxTitle::loadTitByIexLoc(
			ubigint refWznmMImpexpcplx
			, ubigint x1RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMImpexpcplx = htonl64(refWznmMImpexpcplx);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJMImpexpcplxTitle_loadTitByIexLoc", 2, vals, l, f, Title);
};

#endif

