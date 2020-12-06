/**
	* \file WznmAMPersonDetail.cpp
	* database access for table TblWznmAMPersonDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMPersonDetail.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMPersonDetail
 ******************************************************************************/

WznmAMPersonDetail::WznmAMPersonDetail(
			const ubigint ref
			, const ubigint refWznmMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refWznmMPerson = refWznmMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool WznmAMPersonDetail::operator==(
			const WznmAMPersonDetail& comp
		) {
	return false;
};

bool WznmAMPersonDetail::operator!=(
			const WznmAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMPersonDetail
 ******************************************************************************/

ListWznmAMPersonDetail::ListWznmAMPersonDetail() {
};

ListWznmAMPersonDetail::ListWznmAMPersonDetail(
			const ListWznmAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMPersonDetail(*(src.nodes[i]));
};

ListWznmAMPersonDetail::~ListWznmAMPersonDetail() {
	clear();
};

void ListWznmAMPersonDetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMPersonDetail::size() const {
	return(nodes.size());
};

void ListWznmAMPersonDetail::append(
			WznmAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

WznmAMPersonDetail* ListWznmAMPersonDetail::operator[](
			const uint ix
		) {
	WznmAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMPersonDetail& ListWznmAMPersonDetail::operator=(
			const ListWznmAMPersonDetail& src
		) {
	WznmAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMPersonDetail::operator==(
			const ListWznmAMPersonDetail& comp
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

bool ListWznmAMPersonDetail::operator!=(
			const ListWznmAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMPersonDetail
 ******************************************************************************/

TblWznmAMPersonDetail::TblWznmAMPersonDetail() {
};

TblWznmAMPersonDetail::~TblWznmAMPersonDetail() {
};

bool TblWznmAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WznmAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWznmAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWznmAMPersonDetail::insertRec(
			WznmAMPersonDetail* rec
		) {
	return 0;
};

ubigint TblWznmAMPersonDetail::insertNewRec(
			WznmAMPersonDetail** rec
			, const ubigint refWznmMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMPersonDetail* _rec = NULL;

	_rec = new WznmAMPersonDetail(0, refWznmMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMPersonDetail::appendNewRecToRst(
			ListWznmAMPersonDetail& rst
			, WznmAMPersonDetail** rec
			, const ubigint refWznmMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMPersonDetail::insertRst(
			ListWznmAMPersonDetail& rst
			, bool transact
		) {
};

void TblWznmAMPersonDetail::updateRec(
			WznmAMPersonDetail* rec
		) {
};

void TblWznmAMPersonDetail::updateRst(
			ListWznmAMPersonDetail& rst
			, bool transact
		) {
};

void TblWznmAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMPersonDetail::loadRecByRef(
			ubigint ref
			, WznmAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWznmAMPersonDetail::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWznmAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	ubigint numload = 0;
	WznmAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMPersonDetail
 ******************************************************************************/

MyTblWznmAMPersonDetail::MyTblWznmAMPersonDetail() :
			TblWznmAMPersonDetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMPersonDetail::~MyTblWznmAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMPersonDetail (refWznmMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMPersonDetail SET refWznmMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMPersonDetail WHERE ref = ?", false);
};

bool MyTblWznmAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WznmAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMPersonDetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMPersonDetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMPerson = atoll((char*) dbrow[1]); else _rec->refWznmMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMPersonDetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMPersonDetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMPerson = atoll((char*) dbrow[1]); else rec->refWznmMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMPersonDetail::insertRec(
			WznmAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMPersonDetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMPersonDetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMPersonDetail::insertRst(
			ListWznmAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMPersonDetail::updateRec(
			WznmAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMPersonDetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMPersonDetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMPersonDetail::updateRst(
			ListWznmAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMPersonDetail::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMPersonDetail::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMPersonDetail::loadRecByRef(
			ubigint ref
			, WznmAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMPersonDetail::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMPerson, x1SrefKType, Val FROM TblWznmAMPersonDetail WHERE refWznmMPerson = " + to_string(refWznmMPerson) + " ORDER BY x1SrefKType ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMPersonDetail
 ******************************************************************************/

PgTblWznmAMPersonDetail::PgTblWznmAMPersonDetail() :
			TblWznmAMPersonDetail()
			, PgTable()
		{
};

PgTblWznmAMPersonDetail::~PgTblWznmAMPersonDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMPersonDetail::initStatements() {
	createStatement("TblWznmAMPersonDetail_insertRec", "INSERT INTO TblWznmAMPersonDetail (refWznmMPerson, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmAMPersonDetail_updateRec", "UPDATE TblWznmAMPersonDetail SET refWznmMPerson = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWznmAMPersonDetail_removeRecByRef", "DELETE FROM TblWznmAMPersonDetail WHERE ref = $1", 1);

	createStatement("TblWznmAMPersonDetail_loadRecByRef", "SELECT ref, refWznmMPerson, x1SrefKType, Val FROM TblWznmAMPersonDetail WHERE ref = $1", 1);
	createStatement("TblWznmAMPersonDetail_loadRstByPrs", "SELECT ref, refWznmMPerson, x1SrefKType, Val FROM TblWznmAMPersonDetail WHERE refWznmMPerson = $1 ORDER BY x1SrefKType ASC", 1);
};

bool PgTblWznmAMPersonDetail::loadRec(
			PGresult* res
			, WznmAMPersonDetail** rec
		) {
	char* ptr;

	WznmAMPersonDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMPersonDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMPersonDetail::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMPersonDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAMPersonDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMPersonDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMPersonDetail::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMPersonDetail::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMPersonDetail::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WznmAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMPersonDetail::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMPersonDetail::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMPersonDetail::insertRec(
			WznmAMPersonDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);

	const char* vals[] = {
		(char*) &_refWznmMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMPersonDetail_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMPersonDetail::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMPersonDetail::insertRst(
			ListWznmAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMPersonDetail::updateRec(
			WznmAMPersonDetail* rec
		) {
	PGresult* res;

	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMPersonDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMPersonDetail::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMPersonDetail::updateRst(
			ListWznmAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMPersonDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMPersonDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMPersonDetail::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMPersonDetail::loadRecByRef(
			ubigint ref
			, WznmAMPersonDetail** rec
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

	return loadRecByStmt("TblWznmAMPersonDetail_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMPersonDetail::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmAMPersonDetail& rst
		) {
	ubigint _refWznmMPerson = htonl64(refWznmMPerson);

	const char* vals[] = {
		(char*) &_refWznmMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMPersonDetail_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif
