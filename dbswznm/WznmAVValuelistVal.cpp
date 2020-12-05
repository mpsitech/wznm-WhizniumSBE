/**
	* \file WznmAVValuelistVal.cpp
	* database access for table TblWznmAVValuelistVal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAVValuelistVal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAVValuelistVal
 ******************************************************************************/

WznmAVValuelistVal::WznmAVValuelistVal(
			const ubigint ref
			, const uint vlsIxWznmVValuelist
			, const uint vlsNum
			, const uint x1IxWznmVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxWznmVValuelist = vlsIxWznmVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxWznmVLocale = x1IxWznmVLocale;
	this->Val = Val;
};

bool WznmAVValuelistVal::operator==(
			const WznmAVValuelistVal& comp
		) {
	return false;
};

bool WznmAVValuelistVal::operator!=(
			const WznmAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAVValuelistVal
 ******************************************************************************/

ListWznmAVValuelistVal::ListWznmAVValuelistVal() {
};

ListWznmAVValuelistVal::ListWznmAVValuelistVal(
			const ListWznmAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAVValuelistVal(*(src.nodes[i]));
};

ListWznmAVValuelistVal::~ListWznmAVValuelistVal() {
	clear();
};

void ListWznmAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAVValuelistVal::size() const {
	return(nodes.size());
};

void ListWznmAVValuelistVal::append(
			WznmAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

WznmAVValuelistVal* ListWznmAVValuelistVal::operator[](
			const uint ix
		) {
	WznmAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAVValuelistVal& ListWznmAVValuelistVal::operator=(
			const ListWznmAVValuelistVal& src
		) {
	WznmAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAVValuelistVal::operator==(
			const ListWznmAVValuelistVal& comp
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

bool ListWznmAVValuelistVal::operator!=(
			const ListWznmAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAVValuelistVal
 ******************************************************************************/

TblWznmAVValuelistVal::TblWznmAVValuelistVal() {
};

TblWznmAVValuelistVal::~TblWznmAVValuelistVal() {
};

bool TblWznmAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WznmAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWznmAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWznmAVValuelistVal::insertRec(
			WznmAVValuelistVal* rec
		) {
	return 0;
};

ubigint TblWznmAVValuelistVal::insertNewRec(
			WznmAVValuelistVal** rec
			, const uint vlsIxWznmVValuelist
			, const uint vlsNum
			, const uint x1IxWznmVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WznmAVValuelistVal* _rec = NULL;

	_rec = new WznmAVValuelistVal(0, vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAVValuelistVal::appendNewRecToRst(
			ListWznmAVValuelistVal& rst
			, WznmAVValuelistVal** rec
			, const uint vlsIxWznmVValuelist
			, const uint vlsNum
			, const uint x1IxWznmVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WznmAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAVValuelistVal::insertRst(
			ListWznmAVValuelistVal& rst
			, bool transact
		) {
};

void TblWznmAVValuelistVal::updateRec(
			WznmAVValuelistVal* rec
		) {
};

void TblWznmAVValuelistVal::updateRst(
			ListWznmAVValuelistVal& rst
			, bool transact
		) {
};

void TblWznmAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAVValuelistVal::loadRecByRef(
			ubigint ref
			, WznmAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWznmAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWznmVValuelist
			, uint x1IxWznmVLocale
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWznmAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	ubigint numload = 0;
	WznmAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAVValuelistVal
 ******************************************************************************/

MyTblWznmAVValuelistVal::MyTblWznmAVValuelistVal() :
			TblWznmAVValuelistVal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAVValuelistVal::~MyTblWznmAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAVValuelistVal (vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAVValuelistVal SET vlsIxWznmVValuelist = ?, vlsNum = ?, x1IxWznmVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAVValuelistVal WHERE ref = ?", false);
};

bool MyTblWznmAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WznmAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAVValuelistVal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAVValuelistVal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxWznmVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxWznmVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxWznmVLocale = atol((char*) dbrow[3]); else _rec->x1IxWznmVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAVValuelistVal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAVValuelistVal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxWznmVValuelist = atol((char*) dbrow[1]); else rec->vlsIxWznmVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxWznmVLocale = atol((char*) dbrow[3]); else rec->x1IxWznmVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAVValuelistVal::insertRec(
			WznmAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWznmVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWznmVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAVValuelistVal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAVValuelistVal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAVValuelistVal::insertRst(
			ListWznmAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAVValuelistVal::updateRec(
			WznmAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWznmVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWznmVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAVValuelistVal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAVValuelistVal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAVValuelistVal::updateRst(
			ListWznmAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAVValuelistVal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAVValuelistVal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAVValuelistVal::loadRecByRef(
			ubigint ref
			, WznmAVValuelistVal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWznmVValuelist
			, uint x1IxWznmVLocale
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val FROM TblWznmAVValuelistVal WHERE vlsIxWznmVValuelist = " + to_string(vlsIxWznmVValuelist) + " AND x1IxWznmVLocale = " + to_string(x1IxWznmVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAVValuelistVal
 ******************************************************************************/

PgTblWznmAVValuelistVal::PgTblWznmAVValuelistVal() :
			TblWznmAVValuelistVal()
			, PgTable()
		{
};

PgTblWznmAVValuelistVal::~PgTblWznmAVValuelistVal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAVValuelistVal::initStatements() {
	createStatement("TblWznmAVValuelistVal_insertRec", "INSERT INTO TblWznmAVValuelistVal (vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAVValuelistVal_updateRec", "UPDATE TblWznmAVValuelistVal SET vlsIxWznmVValuelist = $1, vlsNum = $2, x1IxWznmVLocale = $3, Val = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAVValuelistVal_removeRecByRef", "DELETE FROM TblWznmAVValuelistVal WHERE ref = $1", 1);

	createStatement("TblWznmAVValuelistVal_loadRecByRef", "SELECT ref, vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val FROM TblWznmAVValuelistVal WHERE ref = $1", 1);
	createStatement("TblWznmAVValuelistVal_loadRstByVlsLcl", "SELECT ref, vlsIxWznmVValuelist, vlsNum, x1IxWznmVLocale, Val FROM TblWznmAVValuelistVal WHERE vlsIxWznmVValuelist = $1 AND x1IxWznmVLocale = $2 ORDER BY vlsNum ASC", 2);
};

bool PgTblWznmAVValuelistVal::loadRec(
			PGresult* res
			, WznmAVValuelistVal** rec
		) {
	char* ptr;

	WznmAVValuelistVal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAVValuelistVal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixwznmvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixwznmvlocale"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vlsIxWznmVValuelist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vlsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxWznmVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAVValuelistVal::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAVValuelistVal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixwznmvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixwznmvlocale"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAVValuelistVal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vlsIxWznmVValuelist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vlsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxWznmVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAVValuelistVal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVValuelistVal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAVValuelistVal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVValuelistVal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WznmAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVValuelistVal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVValuelistVal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAVValuelistVal::insertRec(
			WznmAVValuelistVal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _vlsIxWznmVValuelist = htonl(rec->vlsIxWznmVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxWznmVLocale = htonl(rec->x1IxWznmVLocale);

	const char* vals[] = {
		(char*) &_vlsIxWznmVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxWznmVLocale,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAVValuelistVal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVValuelistVal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAVValuelistVal::insertRst(
			ListWznmAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAVValuelistVal::updateRec(
			WznmAVValuelistVal* rec
		) {
	PGresult* res;

	uint _vlsIxWznmVValuelist = htonl(rec->vlsIxWznmVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxWznmVLocale = htonl(rec->x1IxWznmVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vlsIxWznmVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxWznmVLocale,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAVValuelistVal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAVValuelistVal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAVValuelistVal::updateRst(
			ListWznmAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAVValuelistVal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAVValuelistVal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAVValuelistVal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAVValuelistVal::loadRecByRef(
			ubigint ref
			, WznmAVValuelistVal** rec
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

	return loadRecByStmt("TblWznmAVValuelistVal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWznmVValuelist
			, uint x1IxWznmVLocale
			, const bool append
			, ListWznmAVValuelistVal& rst
		) {
	uint _vlsIxWznmVValuelist = htonl(vlsIxWznmVValuelist);
	uint _x1IxWznmVLocale = htonl(x1IxWznmVLocale);

	const char* vals[] = {
		(char*) &_vlsIxWznmVValuelist,
		(char*) &_x1IxWznmVLocale
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWznmAVValuelistVal_loadRstByVlsLcl", 2, vals, l, f, append, rst);
};

#endif

