/**
	* \file WznmMSequence.cpp
	* database access for table TblWznmMSequence (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMSequence.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMSequence
 ******************************************************************************/

WznmMSequence::WznmMSequence(
			const ubigint ref
			, const ubigint appRefWznmMApp
			, const uint appNum
			, const string sref
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->appRefWznmMApp = appRefWznmMApp;
	this->appNum = appNum;
	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmMSequence::operator==(
			const WznmMSequence& comp
		) {
	return false;
};

bool WznmMSequence::operator!=(
			const WznmMSequence& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMSequence
 ******************************************************************************/

ListWznmMSequence::ListWznmMSequence() {
};

ListWznmMSequence::ListWznmMSequence(
			const ListWznmMSequence& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMSequence(*(src.nodes[i]));
};

ListWznmMSequence::~ListWznmMSequence() {
	clear();
};

void ListWznmMSequence::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMSequence::size() const {
	return(nodes.size());
};

void ListWznmMSequence::append(
			WznmMSequence* rec
		) {
	nodes.push_back(rec);
};

WznmMSequence* ListWznmMSequence::operator[](
			const uint ix
		) {
	WznmMSequence* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMSequence& ListWznmMSequence::operator=(
			const ListWznmMSequence& src
		) {
	WznmMSequence* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMSequence(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMSequence::operator==(
			const ListWznmMSequence& comp
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

bool ListWznmMSequence::operator!=(
			const ListWznmMSequence& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMSequence
 ******************************************************************************/

TblWznmMSequence::TblWznmMSequence() {
};

TblWznmMSequence::~TblWznmMSequence() {
};

bool TblWznmMSequence::loadRecBySQL(
			const string& sqlstr
			, WznmMSequence** rec
		) {
	return false;
};

ubigint TblWznmMSequence::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSequence& rst
		) {
	return 0;
};

ubigint TblWznmMSequence::insertRec(
			WznmMSequence* rec
		) {
	return 0;
};

ubigint TblWznmMSequence::insertNewRec(
			WznmMSequence** rec
			, const ubigint appRefWznmMApp
			, const uint appNum
			, const string sref
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMSequence* _rec = NULL;

	_rec = new WznmMSequence(0, appRefWznmMApp, appNum, sref, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMSequence::appendNewRecToRst(
			ListWznmMSequence& rst
			, WznmMSequence** rec
			, const ubigint appRefWznmMApp
			, const uint appNum
			, const string sref
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMSequence* _rec = NULL;

	retval = insertNewRec(&_rec, appRefWznmMApp, appNum, sref, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMSequence::insertRst(
			ListWznmMSequence& rst
			, bool transact
		) {
};

void TblWznmMSequence::updateRec(
			WznmMSequence* rec
		) {
};

void TblWznmMSequence::updateRst(
			ListWznmMSequence& rst
			, bool transact
		) {
};

void TblWznmMSequence::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMSequence::loadRecByRef(
			ubigint ref
			, WznmMSequence** rec
		) {
	return false;
};

ubigint TblWznmMSequence::loadRstByApp(
			ubigint appRefWznmMApp
			, const bool append
			, ListWznmMSequence& rst
		) {
	return 0;
};

bool TblWznmMSequence::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWznmMSequence::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMSequence& rst
		) {
	ubigint numload = 0;
	WznmMSequence* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMSequence
 ******************************************************************************/

MyTblWznmMSequence::MyTblWznmMSequence() :
			TblWznmMSequence()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMSequence::~MyTblWznmMSequence() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMSequence::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMSequence (appRefWznmMApp, appNum, sref, Title, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMSequence SET appRefWznmMApp = ?, appNum = ?, sref = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMSequence WHERE ref = ?", false);
};

bool MyTblWznmMSequence::loadRecBySQL(
			const string& sqlstr
			, WznmMSequence** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMSequence* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSequence::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSequence::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMSequence();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->appRefWznmMApp = atoll((char*) dbrow[1]); else _rec->appRefWznmMApp = 0;
		if (dbrow[2]) _rec->appNum = atol((char*) dbrow[2]); else _rec->appNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMSequence::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSequence& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMSequence* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSequence::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSequence::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMSequence();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->appRefWznmMApp = atoll((char*) dbrow[1]); else rec->appRefWznmMApp = 0;
			if (dbrow[2]) rec->appNum = atol((char*) dbrow[2]); else rec->appNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMSequence::insertRec(
			WznmMSequence* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Title.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->appRefWznmMApp,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->appNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMSequence::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMSequence::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMSequence::insertRst(
			ListWznmMSequence& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMSequence::updateRec(
			WznmMSequence* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[3] = rec->Title.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->appRefWznmMApp,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->appNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMSequence::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMSequence::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMSequence::updateRst(
			ListWznmMSequence& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMSequence::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMSequence::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMSequence::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMSequence::loadRecByRef(
			ubigint ref
			, WznmMSequence** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMSequence WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMSequence::loadRstByApp(
			ubigint appRefWznmMApp
			, const bool append
			, ListWznmMSequence& rst
		) {
	return loadRstBySQL("SELECT ref, appRefWznmMApp, appNum, sref, Title, Comment FROM TblWznmMSequence WHERE appRefWznmMApp = " + to_string(appRefWznmMApp) + " ORDER BY appNum ASC", append, rst);
};

bool MyTblWznmMSequence::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmMSequence WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMSequence
 ******************************************************************************/

PgTblWznmMSequence::PgTblWznmMSequence() :
			TblWznmMSequence()
			, PgTable()
		{
};

PgTblWznmMSequence::~PgTblWznmMSequence() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMSequence::initStatements() {
	createStatement("TblWznmMSequence_insertRec", "INSERT INTO TblWznmMSequence (appRefWznmMApp, appNum, sref, Title, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMSequence_updateRec", "UPDATE TblWznmMSequence SET appRefWznmMApp = $1, appNum = $2, sref = $3, Title = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMSequence_removeRecByRef", "DELETE FROM TblWznmMSequence WHERE ref = $1", 1);

	createStatement("TblWznmMSequence_loadRecByRef", "SELECT ref, appRefWznmMApp, appNum, sref, Title, Comment FROM TblWznmMSequence WHERE ref = $1", 1);
	createStatement("TblWznmMSequence_loadRstByApp", "SELECT ref, appRefWznmMApp, appNum, sref, Title, Comment FROM TblWznmMSequence WHERE appRefWznmMApp = $1 ORDER BY appNum ASC", 1);
	createStatement("TblWznmMSequence_loadTitByRef", "SELECT Title FROM TblWznmMSequence WHERE ref = $1", 1);
};

bool PgTblWznmMSequence::loadRec(
			PGresult* res
			, WznmMSequence** rec
		) {
	char* ptr;

	WznmMSequence* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMSequence();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "apprefwznmmapp"),
			PQfnumber(res, "appnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->appRefWznmMApp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->appNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMSequence::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMSequence& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMSequence* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "apprefwznmmapp"),
			PQfnumber(res, "appnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMSequence();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->appRefWznmMApp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->appNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMSequence::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMSequence** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSequence::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSequence::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMSequence& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSequence::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMSequence::loadRecBySQL(
			const string& sqlstr
			, WznmMSequence** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSequence::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSequence::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSequence& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSequence::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMSequence::insertRec(
			WznmMSequence* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _appRefWznmMApp = htonl64(rec->appRefWznmMApp);
	uint _appNum = htonl(rec->appNum);

	const char* vals[] = {
		(char*) &_appRefWznmMApp,
		(char*) &_appNum,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMSequence_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSequence::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMSequence::insertRst(
			ListWznmMSequence& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMSequence::updateRec(
			WznmMSequence* rec
		) {
	PGresult* res;

	ubigint _appRefWznmMApp = htonl64(rec->appRefWznmMApp);
	uint _appNum = htonl(rec->appNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_appRefWznmMApp,
		(char*) &_appNum,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMSequence_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSequence::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMSequence::updateRst(
			ListWznmMSequence& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMSequence::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMSequence_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSequence::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMSequence::loadRecByRef(
			ubigint ref
			, WznmMSequence** rec
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

	return loadRecByStmt("TblWznmMSequence_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMSequence::loadRstByApp(
			ubigint appRefWznmMApp
			, const bool append
			, ListWznmMSequence& rst
		) {
	ubigint _appRefWznmMApp = htonl64(appRefWznmMApp);

	const char* vals[] = {
		(char*) &_appRefWznmMApp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMSequence_loadRstByApp", 1, vals, l, f, append, rst);
};

bool PgTblWznmMSequence::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMSequence_loadTitByRef", 1, vals, l, f, Title);
};

#endif
