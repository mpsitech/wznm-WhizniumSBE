/**
	* \file WznmAMTableTitle.cpp
	* database access for table TblWznmAMTableTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMTableTitle.h"

#include "WznmAMTableTitle_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMTableTitle
 ******************************************************************************/

WznmAMTableTitle::WznmAMTableTitle(
			const ubigint ref
			, const ubigint refWznmMTable
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const uint ixWznmVGender
			, const string Title
		) :
			ref(ref)
			, refWznmMTable(refWznmMTable)
			, x1IxVType(x1IxVType)
			, x2RefWznmMLocale(x2RefWznmMLocale)
			, ixWznmVGender(ixWznmVGender)
			, Title(Title)
		{
};

bool WznmAMTableTitle::operator==(
			const WznmAMTableTitle& comp
		) {
	return false;
};

bool WznmAMTableTitle::operator!=(
			const WznmAMTableTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMTableTitle
 ******************************************************************************/

ListWznmAMTableTitle::ListWznmAMTableTitle() {
};

ListWznmAMTableTitle::ListWznmAMTableTitle(
			const ListWznmAMTableTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMTableTitle(*(src.nodes[i]));
};

ListWznmAMTableTitle::~ListWznmAMTableTitle() {
	clear();
};

void ListWznmAMTableTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMTableTitle::size() const {
	return(nodes.size());
};

void ListWznmAMTableTitle::append(
			WznmAMTableTitle* rec
		) {
	nodes.push_back(rec);
};

WznmAMTableTitle* ListWznmAMTableTitle::operator[](
			const uint ix
		) {
	WznmAMTableTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMTableTitle& ListWznmAMTableTitle::operator=(
			const ListWznmAMTableTitle& src
		) {
	WznmAMTableTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMTableTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMTableTitle::operator==(
			const ListWznmAMTableTitle& comp
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

bool ListWznmAMTableTitle::operator!=(
			const ListWznmAMTableTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMTableTitle
 ******************************************************************************/

TblWznmAMTableTitle::TblWznmAMTableTitle() {
};

TblWznmAMTableTitle::~TblWznmAMTableTitle() {
};

bool TblWznmAMTableTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMTableTitle** rec
		) {
	return false;
};

ubigint TblWznmAMTableTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	return 0;
};

ubigint TblWznmAMTableTitle::insertRec(
			WznmAMTableTitle* rec
		) {
	return 0;
};

ubigint TblWznmAMTableTitle::insertNewRec(
			WznmAMTableTitle** rec
			, const ubigint refWznmMTable
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const uint ixWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMTableTitle* _rec = NULL;

	_rec = new WznmAMTableTitle(0, refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMTableTitle::appendNewRecToRst(
			ListWznmAMTableTitle& rst
			, WznmAMTableTitle** rec
			, const ubigint refWznmMTable
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const uint ixWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMTableTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMTableTitle::insertRst(
			ListWznmAMTableTitle& rst
			, bool transact
		) {
};

void TblWznmAMTableTitle::updateRec(
			WznmAMTableTitle* rec
		) {
};

void TblWznmAMTableTitle::updateRst(
			ListWznmAMTableTitle& rst
			, bool transact
		) {
};

void TblWznmAMTableTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMTableTitle::loadRecByRef(
			ubigint ref
			, WznmAMTableTitle** rec
		) {
	return false;
};

ubigint TblWznmAMTableTitle::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMTableTitle::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	return 0;
};

bool TblWznmAMTableTitle::loadTitByTblTypLoc(
			ubigint refWznmMTable
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmAMTableTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	ubigint numload = 0;
	WznmAMTableTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMTableTitle
 ******************************************************************************/

MyTblWznmAMTableTitle::MyTblWznmAMTableTitle() :
			TblWznmAMTableTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMTableTitle::~MyTblWznmAMTableTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMTableTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMTableTitle (refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMTableTitle SET refWznmMTable = ?, x1IxVType = ?, x2RefWznmMLocale = ?, ixWznmVGender = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMTableTitle WHERE ref = ?", false);
};

bool MyTblWznmAMTableTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMTableTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMTableTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMTableTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMTableTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMTableTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMTable = atoll((char*) dbrow[1]); else _rec->refWznmMTable = 0;
		if (dbrow[2]) _rec->x1IxVType = atol((char*) dbrow[2]); else _rec->x1IxVType = 0;
		if (dbrow[3]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[4]) _rec->ixWznmVGender = atol((char*) dbrow[4]); else _rec->ixWznmVGender = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMTableTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMTableTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMTableTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMTableTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMTableTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMTable = atoll((char*) dbrow[1]); else rec->refWznmMTable = 0;
			if (dbrow[2]) rec->x1IxVType = atol((char*) dbrow[2]); else rec->x1IxVType = 0;
			if (dbrow[3]) rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[4]) rec->ixWznmVGender = atol((char*) dbrow[4]); else rec->ixWznmVGender = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMTableTitle::insertRec(
			WznmAMTableTitle* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVGender,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMTableTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMTableTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMTableTitle::insertRst(
			ListWznmAMTableTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMTableTitle::updateRec(
			WznmAMTableTitle* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVGender,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMTableTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMTableTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMTableTitle::updateRst(
			ListWznmAMTableTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMTableTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMTableTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMTableTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMTableTitle::loadRecByRef(
			ubigint ref
			, WznmAMTableTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMTableTitle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMTableTitle::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMTableTitle WHERE refWznmMTable = " + to_string(refWznmMTable) + "", append, refs);
};

ubigint MyTblWznmAMTableTitle::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmAMTableTitle WHERE refWznmMTable = " + to_string(refWznmMTable) + " ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmAMTableTitle::loadTitByTblTypLoc(
			ubigint refWznmMTable
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmAMTableTitle WHERE refWznmMTable = " + to_string(refWznmMTable) + " AND x1IxVType = " + to_string(x1IxVType) + " AND x2RefWznmMLocale = " + to_string(x2RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMTableTitle
 ******************************************************************************/

PgTblWznmAMTableTitle::PgTblWznmAMTableTitle() :
			TblWznmAMTableTitle()
			, PgTable()
		{
};

PgTblWznmAMTableTitle::~PgTblWznmAMTableTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMTableTitle::initStatements() {
	createStatement("TblWznmAMTableTitle_insertRec", "INSERT INTO TblWznmAMTableTitle (refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmAMTableTitle_updateRec", "UPDATE TblWznmAMTableTitle SET refWznmMTable = $1, x1IxVType = $2, x2RefWznmMLocale = $3, ixWznmVGender = $4, Title = $5 WHERE ref = $6", 6);
	createStatement("TblWznmAMTableTitle_removeRecByRef", "DELETE FROM TblWznmAMTableTitle WHERE ref = $1", 1);

	createStatement("TblWznmAMTableTitle_loadRecByRef", "SELECT ref, refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmAMTableTitle WHERE ref = $1", 1);
	createStatement("TblWznmAMTableTitle_loadRefsByTbl", "SELECT ref FROM TblWznmAMTableTitle WHERE refWznmMTable = $1", 1);
	createStatement("TblWznmAMTableTitle_loadRstByTbl", "SELECT ref, refWznmMTable, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmAMTableTitle WHERE refWznmMTable = $1 ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", 1);
	createStatement("TblWznmAMTableTitle_loadTitByTblTypLoc", "SELECT Title FROM TblWznmAMTableTitle WHERE refWznmMTable = $1 AND x1IxVType = $2 AND x2RefWznmMLocale = $3", 3);
};

bool PgTblWznmAMTableTitle::loadRec(
			PGresult* res
			, WznmAMTableTitle** rec
		) {
	char* ptr;

	WznmAMTableTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMTableTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmVGender = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMTableTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMTableTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmAMTableTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWznmVGender = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMTableTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMTableTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMTableTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMTableTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMTableTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMTableTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMTableTitle::insertRec(
			WznmAMTableTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		(char*) &_ixWznmVGender,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMTableTitle_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMTableTitle::insertRst(
			ListWznmAMTableTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMTableTitle::updateRec(
			WznmAMTableTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		(char*) &_ixWznmVGender,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMTableTitle_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMTableTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMTableTitle::updateRst(
			ListWznmAMTableTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMTableTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMTableTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMTableTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMTableTitle::loadRecByRef(
			ubigint ref
			, WznmAMTableTitle** rec
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

	return loadRecByStmt("TblWznmAMTableTitle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMTableTitle::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMTableTitle_loadRefsByTbl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMTableTitle::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmAMTableTitle& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMTableTitle_loadRstByTbl", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMTableTitle::loadTitByTblTypLoc(
			ubigint refWznmMTable
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);
	uint _x1IxVType = htonl(x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadStringByStmt("TblWznmAMTableTitle_loadTitByTblTypLoc", 3, vals, l, f, Title);
};

#endif
