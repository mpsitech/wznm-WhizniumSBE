/**
	* \file WznmAMTablecolTitle.cpp
	* database access for table TblWznmAMTablecolTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMTablecolTitle.h"

#include "WznmAMTablecolTitle_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMTablecolTitle
 ******************************************************************************/

WznmAMTablecolTitle::WznmAMTablecolTitle(
			const ubigint ref
			, const ubigint refWznmMTablecol
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMTablecol = refWznmMTablecol;
	this->x1IxVType = x1IxVType;
	this->x2RefWznmMLocale = x2RefWznmMLocale;
	this->Title = Title;
};

bool WznmAMTablecolTitle::operator==(
			const WznmAMTablecolTitle& comp
		) {
	return false;
};

bool WznmAMTablecolTitle::operator!=(
			const WznmAMTablecolTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMTablecolTitle
 ******************************************************************************/

ListWznmAMTablecolTitle::ListWznmAMTablecolTitle() {
};

ListWznmAMTablecolTitle::ListWznmAMTablecolTitle(
			const ListWznmAMTablecolTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMTablecolTitle(*(src.nodes[i]));
};

ListWznmAMTablecolTitle::~ListWznmAMTablecolTitle() {
	clear();
};

void ListWznmAMTablecolTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMTablecolTitle::size() const {
	return(nodes.size());
};

void ListWznmAMTablecolTitle::append(
			WznmAMTablecolTitle* rec
		) {
	nodes.push_back(rec);
};

WznmAMTablecolTitle* ListWznmAMTablecolTitle::operator[](
			const uint ix
		) {
	WznmAMTablecolTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMTablecolTitle& ListWznmAMTablecolTitle::operator=(
			const ListWznmAMTablecolTitle& src
		) {
	WznmAMTablecolTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMTablecolTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMTablecolTitle::operator==(
			const ListWznmAMTablecolTitle& comp
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

bool ListWznmAMTablecolTitle::operator!=(
			const ListWznmAMTablecolTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMTablecolTitle
 ******************************************************************************/

TblWznmAMTablecolTitle::TblWznmAMTablecolTitle() {
};

TblWznmAMTablecolTitle::~TblWznmAMTablecolTitle() {
};

bool TblWznmAMTablecolTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMTablecolTitle** rec
		) {
	return false;
};

ubigint TblWznmAMTablecolTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	return 0;
};

ubigint TblWznmAMTablecolTitle::insertRec(
			WznmAMTablecolTitle* rec
		) {
	return 0;
};

ubigint TblWznmAMTablecolTitle::insertNewRec(
			WznmAMTablecolTitle** rec
			, const ubigint refWznmMTablecol
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMTablecolTitle* _rec = NULL;

	_rec = new WznmAMTablecolTitle(0, refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMTablecolTitle::appendNewRecToRst(
			ListWznmAMTablecolTitle& rst
			, WznmAMTablecolTitle** rec
			, const ubigint refWznmMTablecol
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMTablecolTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMTablecolTitle::insertRst(
			ListWznmAMTablecolTitle& rst
			, bool transact
		) {
};

void TblWznmAMTablecolTitle::updateRec(
			WznmAMTablecolTitle* rec
		) {
};

void TblWznmAMTablecolTitle::updateRst(
			ListWznmAMTablecolTitle& rst
			, bool transact
		) {
};

void TblWznmAMTablecolTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMTablecolTitle::loadRecByRef(
			ubigint ref
			, WznmAMTablecolTitle** rec
		) {
	return false;
};

ubigint TblWznmAMTablecolTitle::loadRefsByTco(
			ubigint refWznmMTablecol
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMTablecolTitle::loadRstByTco(
			ubigint refWznmMTablecol
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	return 0;
};

bool TblWznmAMTablecolTitle::loadTitByTcoTypLoc(
			ubigint refWznmMTablecol
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmAMTablecolTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	ubigint numload = 0;
	WznmAMTablecolTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMTablecolTitle
 ******************************************************************************/

MyTblWznmAMTablecolTitle::MyTblWznmAMTablecolTitle() :
			TblWznmAMTablecolTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMTablecolTitle::~MyTblWznmAMTablecolTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMTablecolTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMTablecolTitle (refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMTablecolTitle SET refWznmMTablecol = ?, x1IxVType = ?, x2RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMTablecolTitle WHERE ref = ?", false);
};

bool MyTblWznmAMTablecolTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMTablecolTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMTablecolTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMTablecolTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMTablecolTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMTablecolTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMTablecol = atoll((char*) dbrow[1]); else _rec->refWznmMTablecol = 0;
		if (dbrow[2]) _rec->x1IxVType = atol((char*) dbrow[2]); else _rec->x1IxVType = 0;
		if (dbrow[3]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMTablecolTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMTablecolTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMTablecolTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMTablecolTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMTablecolTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMTablecol = atoll((char*) dbrow[1]); else rec->refWznmMTablecol = 0;
			if (dbrow[2]) rec->x1IxVType = atol((char*) dbrow[2]); else rec->x1IxVType = 0;
			if (dbrow[3]) rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMTablecolTitle::insertRec(
			WznmAMTablecolTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTablecol,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMTablecolTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMTablecolTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMTablecolTitle::insertRst(
			ListWznmAMTablecolTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMTablecolTitle::updateRec(
			WznmAMTablecolTitle* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTablecol,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMTablecolTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMTablecolTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMTablecolTitle::updateRst(
			ListWznmAMTablecolTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMTablecolTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMTablecolTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMTablecolTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMTablecolTitle::loadRecByRef(
			ubigint ref
			, WznmAMTablecolTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMTablecolTitle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMTablecolTitle::loadRefsByTco(
			ubigint refWznmMTablecol
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMTablecolTitle WHERE refWznmMTablecol = " + to_string(refWznmMTablecol) + "", append, refs);
};

ubigint MyTblWznmAMTablecolTitle::loadRstByTco(
			ubigint refWznmMTablecol
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMTablecolTitle WHERE refWznmMTablecol = " + to_string(refWznmMTablecol) + " ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmAMTablecolTitle::loadTitByTcoTypLoc(
			ubigint refWznmMTablecol
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmAMTablecolTitle WHERE refWznmMTablecol = " + to_string(refWznmMTablecol) + " AND x1IxVType = " + to_string(x1IxVType) + " AND x2RefWznmMLocale = " + to_string(x2RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMTablecolTitle
 ******************************************************************************/

PgTblWznmAMTablecolTitle::PgTblWznmAMTablecolTitle() :
			TblWznmAMTablecolTitle()
			, PgTable()
		{
};

PgTblWznmAMTablecolTitle::~PgTblWznmAMTablecolTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMTablecolTitle::initStatements() {
	createStatement("TblWznmAMTablecolTitle_insertRec", "INSERT INTO TblWznmAMTablecolTitle (refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMTablecolTitle_updateRec", "UPDATE TblWznmAMTablecolTitle SET refWznmMTablecol = $1, x1IxVType = $2, x2RefWznmMLocale = $3, Title = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMTablecolTitle_removeRecByRef", "DELETE FROM TblWznmAMTablecolTitle WHERE ref = $1", 1);

	createStatement("TblWznmAMTablecolTitle_loadRecByRef", "SELECT ref, refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMTablecolTitle WHERE ref = $1", 1);
	createStatement("TblWznmAMTablecolTitle_loadRefsByTco", "SELECT ref FROM TblWznmAMTablecolTitle WHERE refWznmMTablecol = $1", 1);
	createStatement("TblWznmAMTablecolTitle_loadRstByTco", "SELECT ref, refWznmMTablecol, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMTablecolTitle WHERE refWznmMTablecol = $1 ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", 1);
	createStatement("TblWznmAMTablecolTitle_loadTitByTcoTypLoc", "SELECT Title FROM TblWznmAMTablecolTitle WHERE refWznmMTablecol = $1 AND x1IxVType = $2 AND x2RefWznmMLocale = $3", 3);
};

bool PgTblWznmAMTablecolTitle::loadRec(
			PGresult* res
			, WznmAMTablecolTitle** rec
		) {
	char* ptr;

	WznmAMTablecolTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMTablecolTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMTablecol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMTablecolTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMTablecolTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmAMTablecolTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMTablecol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMTablecolTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMTablecolTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMTablecolTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMTablecolTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMTablecolTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMTablecolTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMTablecolTitle::insertRec(
			WznmAMTablecolTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMTablecol,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMTablecolTitle_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMTablecolTitle::insertRst(
			ListWznmAMTablecolTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMTablecolTitle::updateRec(
			WznmAMTablecolTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMTablecol,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMTablecolTitle_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMTablecolTitle::updateRst(
			ListWznmAMTablecolTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMTablecolTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMTablecolTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMTablecolTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMTablecolTitle::loadRecByRef(
			ubigint ref
			, WznmAMTablecolTitle** rec
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

	return loadRecByStmt("TblWznmAMTablecolTitle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMTablecolTitle::loadRefsByTco(
			ubigint refWznmMTablecol
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMTablecol = htonl64(refWznmMTablecol);

	const char* vals[] = {
		(char*) &_refWznmMTablecol
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMTablecolTitle_loadRefsByTco", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMTablecolTitle::loadRstByTco(
			ubigint refWznmMTablecol
			, const bool append
			, ListWznmAMTablecolTitle& rst
		) {
	ubigint _refWznmMTablecol = htonl64(refWznmMTablecol);

	const char* vals[] = {
		(char*) &_refWznmMTablecol
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMTablecolTitle_loadRstByTco", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMTablecolTitle::loadTitByTcoTypLoc(
			ubigint refWznmMTablecol
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMTablecol = htonl64(refWznmMTablecol);
	uint _x1IxVType = htonl(x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMTablecol,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadStringByStmt("TblWznmAMTablecolTitle_loadTitByTcoTypLoc", 3, vals, l, f, Title);
};

#endif
