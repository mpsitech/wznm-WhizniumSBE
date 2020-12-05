/**
	* \file WznmMEvent.cpp
	* database access for table TblWznmMEvent (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMEvent.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMEvent
 ******************************************************************************/

WznmMEvent::WznmMEvent(
			const ubigint ref
			, const ubigint refWznmMApp
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMApp = refWznmMApp;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmMEvent::operator==(
			const WznmMEvent& comp
		) {
	return false;
};

bool WznmMEvent::operator!=(
			const WznmMEvent& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMEvent
 ******************************************************************************/

ListWznmMEvent::ListWznmMEvent() {
};

ListWznmMEvent::ListWznmMEvent(
			const ListWznmMEvent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMEvent(*(src.nodes[i]));
};

ListWznmMEvent::~ListWznmMEvent() {
	clear();
};

void ListWznmMEvent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMEvent::size() const {
	return(nodes.size());
};

void ListWznmMEvent::append(
			WznmMEvent* rec
		) {
	nodes.push_back(rec);
};

WznmMEvent* ListWznmMEvent::operator[](
			const uint ix
		) {
	WznmMEvent* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMEvent& ListWznmMEvent::operator=(
			const ListWznmMEvent& src
		) {
	WznmMEvent* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMEvent(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMEvent::operator==(
			const ListWznmMEvent& comp
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

bool ListWznmMEvent::operator!=(
			const ListWznmMEvent& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMEvent
 ******************************************************************************/

TblWznmMEvent::TblWznmMEvent() {
};

TblWznmMEvent::~TblWznmMEvent() {
};

bool TblWznmMEvent::loadRecBySQL(
			const string& sqlstr
			, WznmMEvent** rec
		) {
	return false;
};

ubigint TblWznmMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMEvent& rst
		) {
	return 0;
};

ubigint TblWznmMEvent::insertRec(
			WznmMEvent* rec
		) {
	return 0;
};

ubigint TblWznmMEvent::insertNewRec(
			WznmMEvent** rec
			, const ubigint refWznmMApp
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMEvent* _rec = NULL;

	_rec = new WznmMEvent(0, refWznmMApp, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMEvent::appendNewRecToRst(
			ListWznmMEvent& rst
			, WznmMEvent** rec
			, const ubigint refWznmMApp
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMEvent* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMApp, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMEvent::insertRst(
			ListWznmMEvent& rst
			, bool transact
		) {
};

void TblWznmMEvent::updateRec(
			WznmMEvent* rec
		) {
};

void TblWznmMEvent::updateRst(
			ListWznmMEvent& rst
			, bool transact
		) {
};

void TblWznmMEvent::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMEvent::loadRecByRef(
			ubigint ref
			, WznmMEvent** rec
		) {
	return false;
};

ubigint TblWznmMEvent::loadRstByApp(
			ubigint refWznmMApp
			, const bool append
			, ListWznmMEvent& rst
		) {
	return 0;
};

bool TblWznmMEvent::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMEvent::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMEvent& rst
		) {
	ubigint numload = 0;
	WznmMEvent* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMEvent
 ******************************************************************************/

MyTblWznmMEvent::MyTblWznmMEvent() :
			TblWznmMEvent()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMEvent::~MyTblWznmMEvent() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMEvent::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMEvent (refWznmMApp, sref, Comment) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMEvent SET refWznmMApp = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMEvent WHERE ref = ?", false);
};

bool MyTblWznmMEvent::loadRecBySQL(
			const string& sqlstr
			, WznmMEvent** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMEvent* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMEvent::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMEvent::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMEvent();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMApp = atoll((char*) dbrow[1]); else _rec->refWznmMApp = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->Comment.assign(dbrow[3], dblengths[3]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMEvent& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMEvent* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMEvent::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMEvent::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMEvent();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMApp = atoll((char*) dbrow[1]); else rec->refWznmMApp = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->Comment.assign(dbrow[3], dblengths[3]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMEvent::insertRec(
			WznmMEvent* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMApp,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMEvent::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMEvent::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMEvent::insertRst(
			ListWznmMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMEvent::updateRec(
			WznmMEvent* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMApp,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMEvent::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMEvent::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMEvent::updateRst(
			ListWznmMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMEvent::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMEvent::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMEvent::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMEvent::loadRecByRef(
			ubigint ref
			, WznmMEvent** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMEvent WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMEvent::loadRstByApp(
			ubigint refWznmMApp
			, const bool append
			, ListWznmMEvent& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMApp, sref, Comment FROM TblWznmMEvent WHERE refWznmMApp = " + to_string(refWznmMApp) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMEvent::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMEvent WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMEvent
 ******************************************************************************/

PgTblWznmMEvent::PgTblWznmMEvent() :
			TblWznmMEvent()
			, PgTable()
		{
};

PgTblWznmMEvent::~PgTblWznmMEvent() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMEvent::initStatements() {
	createStatement("TblWznmMEvent_insertRec", "INSERT INTO TblWznmMEvent (refWznmMApp, sref, Comment) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmMEvent_updateRec", "UPDATE TblWznmMEvent SET refWznmMApp = $1, sref = $2, Comment = $3 WHERE ref = $4", 4);
	createStatement("TblWznmMEvent_removeRecByRef", "DELETE FROM TblWznmMEvent WHERE ref = $1", 1);

	createStatement("TblWznmMEvent_loadRecByRef", "SELECT ref, refWznmMApp, sref, Comment FROM TblWznmMEvent WHERE ref = $1", 1);
	createStatement("TblWznmMEvent_loadRstByApp", "SELECT ref, refWznmMApp, sref, Comment FROM TblWznmMEvent WHERE refWznmMApp = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMEvent_loadSrfByRef", "SELECT sref FROM TblWznmMEvent WHERE ref = $1", 1);
};

bool PgTblWznmMEvent::loadRec(
			PGresult* res
			, WznmMEvent** rec
		) {
	char* ptr;

	WznmMEvent* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMEvent();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmapp"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMApp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMEvent::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMEvent& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMEvent* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmapp"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMEvent();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMApp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMEvent::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMEvent** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMEvent::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMEvent::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMEvent& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMEvent::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMEvent::loadRecBySQL(
			const string& sqlstr
			, WznmMEvent** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMEvent::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMEvent& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMEvent::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMEvent::insertRec(
			WznmMEvent* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMApp = htonl64(rec->refWznmMApp);

	const char* vals[] = {
		(char*) &_refWznmMApp,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMEvent_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMEvent::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMEvent::insertRst(
			ListWznmMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMEvent::updateRec(
			WznmMEvent* rec
		) {
	PGresult* res;

	ubigint _refWznmMApp = htonl64(rec->refWznmMApp);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMApp,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMEvent_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMEvent::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMEvent::updateRst(
			ListWznmMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMEvent::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMEvent_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMEvent::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMEvent::loadRecByRef(
			ubigint ref
			, WznmMEvent** rec
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

	return loadRecByStmt("TblWznmMEvent_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMEvent::loadRstByApp(
			ubigint refWznmMApp
			, const bool append
			, ListWznmMEvent& rst
		) {
	ubigint _refWznmMApp = htonl64(refWznmMApp);

	const char* vals[] = {
		(char*) &_refWznmMApp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMEvent_loadRstByApp", 1, vals, l, f, append, rst);
};

bool PgTblWznmMEvent::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMEvent_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

