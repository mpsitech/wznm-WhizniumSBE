/**
	* \file WznmAMVectorTitle.cpp
	* database access for table TblWznmAMVectorTitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMVectorTitle.h"

#include "WznmAMVectorTitle_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMVectorTitle
 ******************************************************************************/

WznmAMVectorTitle::WznmAMVectorTitle(
			const ubigint ref
			, const ubigint refWznmMVector
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMVector = refWznmMVector;
	this->x1IxVType = x1IxVType;
	this->x2RefWznmMLocale = x2RefWznmMLocale;
	this->Title = Title;
};

bool WznmAMVectorTitle::operator==(
			const WznmAMVectorTitle& comp
		) {
	return false;
};

bool WznmAMVectorTitle::operator!=(
			const WznmAMVectorTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMVectorTitle
 ******************************************************************************/

ListWznmAMVectorTitle::ListWznmAMVectorTitle() {
};

ListWznmAMVectorTitle::ListWznmAMVectorTitle(
			const ListWznmAMVectorTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMVectorTitle(*(src.nodes[i]));
};

ListWznmAMVectorTitle::~ListWznmAMVectorTitle() {
	clear();
};

void ListWznmAMVectorTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMVectorTitle::size() const {
	return(nodes.size());
};

void ListWznmAMVectorTitle::append(
			WznmAMVectorTitle* rec
		) {
	nodes.push_back(rec);
};

WznmAMVectorTitle* ListWznmAMVectorTitle::operator[](
			const uint ix
		) {
	WznmAMVectorTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMVectorTitle& ListWznmAMVectorTitle::operator=(
			const ListWznmAMVectorTitle& src
		) {
	WznmAMVectorTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMVectorTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMVectorTitle::operator==(
			const ListWznmAMVectorTitle& comp
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

bool ListWznmAMVectorTitle::operator!=(
			const ListWznmAMVectorTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMVectorTitle
 ******************************************************************************/

TblWznmAMVectorTitle::TblWznmAMVectorTitle() {
};

TblWznmAMVectorTitle::~TblWznmAMVectorTitle() {
};

bool TblWznmAMVectorTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMVectorTitle** rec
		) {
	return false;
};

ubigint TblWznmAMVectorTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	return 0;
};

ubigint TblWznmAMVectorTitle::insertRec(
			WznmAMVectorTitle* rec
		) {
	return 0;
};

ubigint TblWznmAMVectorTitle::insertNewRec(
			WznmAMVectorTitle** rec
			, const ubigint refWznmMVector
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMVectorTitle* _rec = NULL;

	_rec = new WznmAMVectorTitle(0, refWznmMVector, x1IxVType, x2RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMVectorTitle::appendNewRecToRst(
			ListWznmAMVectorTitle& rst
			, WznmAMVectorTitle** rec
			, const ubigint refWznmMVector
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMVectorTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVector, x1IxVType, x2RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMVectorTitle::insertRst(
			ListWznmAMVectorTitle& rst
			, bool transact
		) {
};

void TblWznmAMVectorTitle::updateRec(
			WznmAMVectorTitle* rec
		) {
};

void TblWznmAMVectorTitle::updateRst(
			ListWznmAMVectorTitle& rst
			, bool transact
		) {
};

void TblWznmAMVectorTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMVectorTitle::loadRecByRef(
			ubigint ref
			, WznmAMVectorTitle** rec
		) {
	return false;
};

ubigint TblWznmAMVectorTitle::loadRefsByVec(
			ubigint refWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMVectorTitle::loadRstByVec(
			ubigint refWznmMVector
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	return 0;
};

bool TblWznmAMVectorTitle::loadTitByVecTypLoc(
			ubigint refWznmMVector
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmAMVectorTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	ubigint numload = 0;
	WznmAMVectorTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMVectorTitle
 ******************************************************************************/

MyTblWznmAMVectorTitle::MyTblWznmAMVectorTitle() :
			TblWznmAMVectorTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMVectorTitle::~MyTblWznmAMVectorTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMVectorTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMVectorTitle (refWznmMVector, x1IxVType, x2RefWznmMLocale, Title) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMVectorTitle SET refWznmMVector = ?, x1IxVType = ?, x2RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMVectorTitle WHERE ref = ?", false);
};

bool MyTblWznmAMVectorTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMVectorTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMVectorTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMVectorTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMVectorTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMVectorTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVector = atoll((char*) dbrow[1]); else _rec->refWznmMVector = 0;
		if (dbrow[2]) _rec->x1IxVType = atol((char*) dbrow[2]); else _rec->x1IxVType = 0;
		if (dbrow[3]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMVectorTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMVectorTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMVectorTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMVectorTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMVectorTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVector = atoll((char*) dbrow[1]); else rec->refWznmMVector = 0;
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

ubigint MyTblWznmAMVectorTitle::insertRec(
			WznmAMVectorTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVector,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMVectorTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMVectorTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMVectorTitle::insertRst(
			ListWznmAMVectorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMVectorTitle::updateRec(
			WznmAMVectorTitle* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVector,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMVectorTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMVectorTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMVectorTitle::updateRst(
			ListWznmAMVectorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMVectorTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMVectorTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMVectorTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMVectorTitle::loadRecByRef(
			ubigint ref
			, WznmAMVectorTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMVectorTitle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMVectorTitle::loadRefsByVec(
			ubigint refWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMVectorTitle WHERE refWznmMVector = " + to_string(refWznmMVector) + "", append, refs);
};

ubigint MyTblWznmAMVectorTitle::loadRstByVec(
			ubigint refWznmMVector
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVector, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMVectorTitle WHERE refWznmMVector = " + to_string(refWznmMVector) + " ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmAMVectorTitle::loadTitByVecTypLoc(
			ubigint refWznmMVector
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmAMVectorTitle WHERE refWznmMVector = " + to_string(refWznmMVector) + " AND x1IxVType = " + to_string(x1IxVType) + " AND x2RefWznmMLocale = " + to_string(x2RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMVectorTitle
 ******************************************************************************/

PgTblWznmAMVectorTitle::PgTblWznmAMVectorTitle() :
			TblWznmAMVectorTitle()
			, PgTable()
		{
};

PgTblWznmAMVectorTitle::~PgTblWznmAMVectorTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMVectorTitle::initStatements() {
	createStatement("TblWznmAMVectorTitle_insertRec", "INSERT INTO TblWznmAMVectorTitle (refWznmMVector, x1IxVType, x2RefWznmMLocale, Title) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMVectorTitle_updateRec", "UPDATE TblWznmAMVectorTitle SET refWznmMVector = $1, x1IxVType = $2, x2RefWznmMLocale = $3, Title = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMVectorTitle_removeRecByRef", "DELETE FROM TblWznmAMVectorTitle WHERE ref = $1", 1);

	createStatement("TblWznmAMVectorTitle_loadRecByRef", "SELECT ref, refWznmMVector, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMVectorTitle WHERE ref = $1", 1);
	createStatement("TblWznmAMVectorTitle_loadRefsByVec", "SELECT ref FROM TblWznmAMVectorTitle WHERE refWznmMVector = $1", 1);
	createStatement("TblWznmAMVectorTitle_loadRstByVec", "SELECT ref, refWznmMVector, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMVectorTitle WHERE refWznmMVector = $1 ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", 1);
	createStatement("TblWznmAMVectorTitle_loadTitByVecTypLoc", "SELECT Title FROM TblWznmAMVectorTitle WHERE refWznmMVector = $1 AND x1IxVType = $2 AND x2RefWznmMLocale = $3", 3);
};

bool PgTblWznmAMVectorTitle::loadRec(
			PGresult* res
			, WznmAMVectorTitle** rec
		) {
	char* ptr;

	WznmAMVectorTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMVectorTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMVectorTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMVectorTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmAMVectorTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVector = atoll(ptr);
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

bool PgTblWznmAMVectorTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMVectorTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMVectorTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMVectorTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMVectorTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMVectorTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMVectorTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMVectorTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMVectorTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMVectorTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMVectorTitle::insertRec(
			WznmAMVectorTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMVector,
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

	res = PQexecPrepared(dbs, "TblWznmAMVectorTitle_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMVectorTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMVectorTitle::insertRst(
			ListWznmAMVectorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMVectorTitle::updateRec(
			WznmAMVectorTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVector,
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

	res = PQexecPrepared(dbs, "TblWznmAMVectorTitle_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMVectorTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMVectorTitle::updateRst(
			ListWznmAMVectorTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMVectorTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMVectorTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMVectorTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMVectorTitle::loadRecByRef(
			ubigint ref
			, WznmAMVectorTitle** rec
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

	return loadRecByStmt("TblWznmAMVectorTitle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMVectorTitle::loadRefsByVec(
			ubigint refWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVector = htonl64(refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMVectorTitle_loadRefsByVec", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMVectorTitle::loadRstByVec(
			ubigint refWznmMVector
			, const bool append
			, ListWznmAMVectorTitle& rst
		) {
	ubigint _refWznmMVector = htonl64(refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMVectorTitle_loadRstByVec", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMVectorTitle::loadTitByVecTypLoc(
			ubigint refWznmMVector
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMVector = htonl64(refWznmMVector);
	uint _x1IxVType = htonl(x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMVector,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadStringByStmt("TblWznmAMVectorTitle_loadTitByVecTypLoc", 3, vals, l, f, Title);
};

#endif
