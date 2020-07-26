/**
	* \file WznmMMachine.cpp
	* database access for table TblWznmMMachine (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMMachine.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMMachine
 ******************************************************************************/

WznmMMachine::WznmMMachine(
			const ubigint ref
			, const ubigint refWznmMMachtype
			, const string sref
			, const uint ixWznmWCloudtype
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMMachtype = refWznmMMachtype;
	this->sref = sref;
	this->ixWznmWCloudtype = ixWznmWCloudtype;
	this->Comment = Comment;
};

bool WznmMMachine::operator==(
			const WznmMMachine& comp
		) {
	return false;
};

bool WznmMMachine::operator!=(
			const WznmMMachine& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMMachine
 ******************************************************************************/

ListWznmMMachine::ListWznmMMachine() {
};

ListWznmMMachine::ListWznmMMachine(
			const ListWznmMMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMMachine(*(src.nodes[i]));
};

ListWznmMMachine::~ListWznmMMachine() {
	clear();
};

void ListWznmMMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMMachine::size() const {
	return(nodes.size());
};

void ListWznmMMachine::append(
			WznmMMachine* rec
		) {
	nodes.push_back(rec);
};

WznmMMachine* ListWznmMMachine::operator[](
			const uint ix
		) {
	WznmMMachine* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMMachine& ListWznmMMachine::operator=(
			const ListWznmMMachine& src
		) {
	WznmMMachine* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMMachine(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMMachine::operator==(
			const ListWznmMMachine& comp
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

bool ListWznmMMachine::operator!=(
			const ListWznmMMachine& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMMachine
 ******************************************************************************/

TblWznmMMachine::TblWznmMMachine() {
};

TblWznmMMachine::~TblWznmMMachine() {
};

bool TblWznmMMachine::loadRecBySQL(
			const string& sqlstr
			, WznmMMachine** rec
		) {
	return false;
};

ubigint TblWznmMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachine& rst
		) {
	return 0;
};

ubigint TblWznmMMachine::insertRec(
			WznmMMachine* rec
		) {
	return 0;
};

ubigint TblWznmMMachine::insertNewRec(
			WznmMMachine** rec
			, const ubigint refWznmMMachtype
			, const string sref
			, const uint ixWznmWCloudtype
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMachine* _rec = NULL;

	_rec = new WznmMMachine(0, refWznmMMachtype, sref, ixWznmWCloudtype, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMMachine::appendNewRecToRst(
			ListWznmMMachine& rst
			, WznmMMachine** rec
			, const ubigint refWznmMMachtype
			, const string sref
			, const uint ixWznmWCloudtype
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMachine* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMMachtype, sref, ixWznmWCloudtype, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMMachine::insertRst(
			ListWznmMMachine& rst
			, bool transact
		) {
};

void TblWznmMMachine::updateRec(
			WznmMMachine* rec
		) {
};

void TblWznmMMachine::updateRst(
			ListWznmMMachine& rst
			, bool transact
		) {
};

void TblWznmMMachine::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMMachine::loadRecByRef(
			ubigint ref
			, WznmMMachine** rec
		) {
	return false;
};

bool TblWznmMMachine::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMMachine::loadRefsByTbl(
			ubigint refWznmMMachtype
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMMachine::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMMachine& rst
		) {
	ubigint numload = 0;
	WznmMMachine* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMMachine
 ******************************************************************************/

MyTblWznmMMachine::MyTblWznmMMachine() :
			TblWznmMMachine()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMMachine::~MyTblWznmMMachine() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMMachine::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMMachine (refWznmMMachtype, sref, ixWznmWCloudtype, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMMachine SET refWznmMMachtype = ?, sref = ?, ixWznmWCloudtype = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMMachine WHERE ref = ?", false);
};

bool MyTblWznmMMachine::loadRecBySQL(
			const string& sqlstr
			, WznmMMachine** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMMachine* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMachine::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMachine::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMMachine();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMMachtype = atoll((char*) dbrow[1]); else _rec->refWznmMMachtype = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->ixWznmWCloudtype = atol((char*) dbrow[3]); else _rec->ixWznmWCloudtype = 0;
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachine& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMMachine* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMachine::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMachine::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMMachine();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMMachtype = atoll((char*) dbrow[1]); else rec->refWznmMMachtype = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->ixWznmWCloudtype = atol((char*) dbrow[3]); else rec->ixWznmWCloudtype = 0;
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMMachine::insertRec(
			WznmMMachine* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachtype,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWznmWCloudtype,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMMachine::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMMachine::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMMachine::insertRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMMachine::updateRec(
			WznmMMachine* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachtype,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWznmWCloudtype,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMMachine::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMMachine::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMMachine::updateRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMMachine::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMMachine::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMMachine::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMMachine::loadRecByRef(
			ubigint ref
			, WznmMMachine** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMMachine WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMMachine::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMMachine WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMMachine::loadRefsByTbl(
			ubigint refWznmMMachtype
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMMachine WHERE refWznmMMachtype = " + to_string(refWznmMMachtype) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMMachine
 ******************************************************************************/

PgTblWznmMMachine::PgTblWznmMMachine() :
			TblWznmMMachine()
			, PgTable()
		{
};

PgTblWznmMMachine::~PgTblWznmMMachine() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMMachine::initStatements() {
	createStatement("TblWznmMMachine_insertRec", "INSERT INTO TblWznmMMachine (refWznmMMachtype, sref, ixWznmWCloudtype, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmMMachine_updateRec", "UPDATE TblWznmMMachine SET refWznmMMachtype = $1, sref = $2, ixWznmWCloudtype = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmMMachine_removeRecByRef", "DELETE FROM TblWznmMMachine WHERE ref = $1", 1);

	createStatement("TblWznmMMachine_loadRecByRef", "SELECT ref, refWznmMMachtype, sref, ixWznmWCloudtype, Comment FROM TblWznmMMachine WHERE ref = $1", 1);
	createStatement("TblWznmMMachine_loadRefBySrf", "SELECT ref FROM TblWznmMMachine WHERE sref = $1", 1);
	createStatement("TblWznmMMachine_loadRefsByTbl", "SELECT ref FROM TblWznmMMachine WHERE refWznmMMachtype = $1", 1);
};

bool PgTblWznmMMachine::loadRec(
			PGresult* res
			, WznmMMachine** rec
		) {
	char* ptr;

	WznmMMachine* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMMachine();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachtype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmwcloudtype"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMMachtype = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWznmWCloudtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMMachine::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMMachine& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMMachine* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachtype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmwcloudtype"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMMachine();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMMachtype = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWznmWCloudtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMMachine::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMMachine** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMMachine::loadRecBySQL(
			const string& sqlstr
			, WznmMMachine** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachine& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMMachine::insertRec(
			WznmMMachine* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMMachtype = htonl64(rec->refWznmMMachtype);
	uint _ixWznmWCloudtype = htonl(rec->ixWznmWCloudtype);

	const char* vals[] = {
		(char*) &_refWznmMMachtype,
		rec->sref.c_str(),
		(char*) &_ixWznmWCloudtype,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMMachine_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMMachine::insertRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMMachine::updateRec(
			WznmMMachine* rec
		) {
	PGresult* res;

	ubigint _refWznmMMachtype = htonl64(rec->refWznmMMachtype);
	uint _ixWznmWCloudtype = htonl(rec->ixWznmWCloudtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMMachtype,
		rec->sref.c_str(),
		(char*) &_ixWznmWCloudtype,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMMachine_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMachine::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMMachine::updateRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMMachine::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMMachine_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMachine::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMMachine::loadRecByRef(
			ubigint ref
			, WznmMMachine** rec
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

	return loadRecByStmt("TblWznmMMachine_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMMachine::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWznmMMachine_loadRefBySrf", 1, vals, l, f, ref);
};

ubigint PgTblWznmMMachine::loadRefsByTbl(
			ubigint refWznmMMachtype
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMMachtype = htonl64(refWznmMMachtype);

	const char* vals[] = {
		(char*) &_refWznmMMachtype
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMMachine_loadRefsByTbl", 1, vals, l, f, append, refs);
};

#endif

