/**
	* \file WznmAMSubsetTitle.cpp
	* database access for table TblWznmAMSubsetTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMSubsetTitle.h"

#include "WznmAMSubsetTitle_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMSubsetTitle
 ******************************************************************************/

WznmAMSubsetTitle::WznmAMSubsetTitle(
			const ubigint ref
			, const ubigint refWznmMSubset
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const uint ixWznmVGender
			, const string Title
		) :
			ref(ref)
			, refWznmMSubset(refWznmMSubset)
			, x1IxVType(x1IxVType)
			, x2RefWznmMLocale(x2RefWznmMLocale)
			, ixWznmVGender(ixWznmVGender)
			, Title(Title)
		{
};

bool WznmAMSubsetTitle::operator==(
			const WznmAMSubsetTitle& comp
		) {
	return false;
};

bool WznmAMSubsetTitle::operator!=(
			const WznmAMSubsetTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMSubsetTitle
 ******************************************************************************/

ListWznmAMSubsetTitle::ListWznmAMSubsetTitle() {
};

ListWznmAMSubsetTitle::ListWznmAMSubsetTitle(
			const ListWznmAMSubsetTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMSubsetTitle(*(src.nodes[i]));
};

ListWznmAMSubsetTitle::~ListWznmAMSubsetTitle() {
	clear();
};

void ListWznmAMSubsetTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMSubsetTitle::size() const {
	return(nodes.size());
};

void ListWznmAMSubsetTitle::append(
			WznmAMSubsetTitle* rec
		) {
	nodes.push_back(rec);
};

WznmAMSubsetTitle* ListWznmAMSubsetTitle::operator[](
			const uint ix
		) {
	WznmAMSubsetTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMSubsetTitle& ListWznmAMSubsetTitle::operator=(
			const ListWznmAMSubsetTitle& src
		) {
	WznmAMSubsetTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMSubsetTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMSubsetTitle::operator==(
			const ListWznmAMSubsetTitle& comp
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

bool ListWznmAMSubsetTitle::operator!=(
			const ListWznmAMSubsetTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMSubsetTitle
 ******************************************************************************/

TblWznmAMSubsetTitle::TblWznmAMSubsetTitle() {
};

TblWznmAMSubsetTitle::~TblWznmAMSubsetTitle() {
};

bool TblWznmAMSubsetTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMSubsetTitle** rec
		) {
	return false;
};

ubigint TblWznmAMSubsetTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	return 0;
};

ubigint TblWznmAMSubsetTitle::insertRec(
			WznmAMSubsetTitle* rec
		) {
	return 0;
};

ubigint TblWznmAMSubsetTitle::insertNewRec(
			WznmAMSubsetTitle** rec
			, const ubigint refWznmMSubset
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const uint ixWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMSubsetTitle* _rec = NULL;

	_rec = new WznmAMSubsetTitle(0, refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMSubsetTitle::appendNewRecToRst(
			ListWznmAMSubsetTitle& rst
			, WznmAMSubsetTitle** rec
			, const ubigint refWznmMSubset
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const uint ixWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMSubsetTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMSubsetTitle::insertRst(
			ListWznmAMSubsetTitle& rst
			, bool transact
		) {
};

void TblWznmAMSubsetTitle::updateRec(
			WznmAMSubsetTitle* rec
		) {
};

void TblWznmAMSubsetTitle::updateRst(
			ListWznmAMSubsetTitle& rst
			, bool transact
		) {
};

void TblWznmAMSubsetTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMSubsetTitle::loadRecByRef(
			ubigint ref
			, WznmAMSubsetTitle** rec
		) {
	return false;
};

ubigint TblWznmAMSubsetTitle::loadRefsBySbs(
			ubigint refWznmMSubset
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMSubsetTitle::loadRstBySbs(
			ubigint refWznmMSubset
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	return 0;
};

bool TblWznmAMSubsetTitle::loadTitBySbsTypLoc(
			ubigint refWznmMSubset
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmAMSubsetTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	ubigint numload = 0;
	WznmAMSubsetTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMSubsetTitle
 ******************************************************************************/

MyTblWznmAMSubsetTitle::MyTblWznmAMSubsetTitle() :
			TblWznmAMSubsetTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMSubsetTitle::~MyTblWznmAMSubsetTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMSubsetTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMSubsetTitle (refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMSubsetTitle SET refWznmMSubset = ?, x1IxVType = ?, x2RefWznmMLocale = ?, ixWznmVGender = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMSubsetTitle WHERE ref = ?", false);
};

bool MyTblWznmAMSubsetTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMSubsetTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMSubsetTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMSubsetTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMSubsetTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMSubsetTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMSubset = atoll((char*) dbrow[1]); else _rec->refWznmMSubset = 0;
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

ubigint MyTblWznmAMSubsetTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMSubsetTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMSubsetTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMSubsetTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMSubsetTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMSubset = atoll((char*) dbrow[1]); else rec->refWznmMSubset = 0;
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

ubigint MyTblWznmAMSubsetTitle::insertRec(
			WznmAMSubsetTitle* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSubset,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVGender,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMSubsetTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMSubsetTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMSubsetTitle::insertRst(
			ListWznmAMSubsetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMSubsetTitle::updateRec(
			WznmAMSubsetTitle* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSubset,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVGender,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMSubsetTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMSubsetTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMSubsetTitle::updateRst(
			ListWznmAMSubsetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMSubsetTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMSubsetTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMSubsetTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMSubsetTitle::loadRecByRef(
			ubigint ref
			, WznmAMSubsetTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMSubsetTitle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMSubsetTitle::loadRefsBySbs(
			ubigint refWznmMSubset
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = " + to_string(refWznmMSubset) + "", append, refs);
};

ubigint MyTblWznmAMSubsetTitle::loadRstBySbs(
			ubigint refWznmMSubset
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = " + to_string(refWznmMSubset) + " ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmAMSubsetTitle::loadTitBySbsTypLoc(
			ubigint refWznmMSubset
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = " + to_string(refWznmMSubset) + " AND x1IxVType = " + to_string(x1IxVType) + " AND x2RefWznmMLocale = " + to_string(x2RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMSubsetTitle
 ******************************************************************************/

PgTblWznmAMSubsetTitle::PgTblWznmAMSubsetTitle() :
			TblWznmAMSubsetTitle()
			, PgTable()
		{
};

PgTblWznmAMSubsetTitle::~PgTblWznmAMSubsetTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMSubsetTitle::initStatements() {
	createStatement("TblWznmAMSubsetTitle_insertRec", "INSERT INTO TblWznmAMSubsetTitle (refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmAMSubsetTitle_updateRec", "UPDATE TblWznmAMSubsetTitle SET refWznmMSubset = $1, x1IxVType = $2, x2RefWznmMLocale = $3, ixWznmVGender = $4, Title = $5 WHERE ref = $6", 6);
	createStatement("TblWznmAMSubsetTitle_removeRecByRef", "DELETE FROM TblWznmAMSubsetTitle WHERE ref = $1", 1);

	createStatement("TblWznmAMSubsetTitle_loadRecByRef", "SELECT ref, refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmAMSubsetTitle WHERE ref = $1", 1);
	createStatement("TblWznmAMSubsetTitle_loadRefsBySbs", "SELECT ref FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = $1", 1);
	createStatement("TblWznmAMSubsetTitle_loadRstBySbs", "SELECT ref, refWznmMSubset, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = $1 ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", 1);
	createStatement("TblWznmAMSubsetTitle_loadTitBySbsTypLoc", "SELECT Title FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = $1 AND x1IxVType = $2 AND x2RefWznmMLocale = $3", 3);
};

bool PgTblWznmAMSubsetTitle::loadRec(
			PGresult* res
			, WznmAMSubsetTitle** rec
		) {
	char* ptr;

	WznmAMSubsetTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMSubsetTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMSubset = atoll(ptr);
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

ubigint PgTblWznmAMSubsetTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMSubsetTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmAMSubsetTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMSubset = atoll(ptr);
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

bool PgTblWznmAMSubsetTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMSubsetTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMSubsetTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMSubsetTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMSubsetTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMSubsetTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMSubsetTitle::insertRec(
			WznmAMSubsetTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);

	const char* vals[] = {
		(char*) &_refWznmMSubset,
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

	res = PQexecPrepared(dbs, "TblWznmAMSubsetTitle_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMSubsetTitle::insertRst(
			ListWznmAMSubsetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMSubsetTitle::updateRec(
			WznmAMSubsetTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMSubset,
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

	res = PQexecPrepared(dbs, "TblWznmAMSubsetTitle_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMSubsetTitle::updateRst(
			ListWznmAMSubsetTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMSubsetTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMSubsetTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMSubsetTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMSubsetTitle::loadRecByRef(
			ubigint ref
			, WznmAMSubsetTitle** rec
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

	return loadRecByStmt("TblWznmAMSubsetTitle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMSubsetTitle::loadRefsBySbs(
			ubigint refWznmMSubset
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMSubset = htonl64(refWznmMSubset);

	const char* vals[] = {
		(char*) &_refWznmMSubset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMSubsetTitle_loadRefsBySbs", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMSubsetTitle::loadRstBySbs(
			ubigint refWznmMSubset
			, const bool append
			, ListWznmAMSubsetTitle& rst
		) {
	ubigint _refWznmMSubset = htonl64(refWznmMSubset);

	const char* vals[] = {
		(char*) &_refWznmMSubset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMSubsetTitle_loadRstBySbs", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMSubsetTitle::loadTitBySbsTypLoc(
			ubigint refWznmMSubset
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMSubset = htonl64(refWznmMSubset);
	uint _x1IxVType = htonl(x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMSubset,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadStringByStmt("TblWznmAMSubsetTitle_loadTitBySbsTypLoc", 3, vals, l, f, Title);
};

#endif
