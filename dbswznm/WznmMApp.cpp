/**
	* \file WznmMApp.cpp
	* database access for table TblWznmMApp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMApp.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMApp
 ******************************************************************************/

WznmMApp::WznmMApp(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixWznmVApptarget
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string Short
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixWznmVApptarget = ixWznmVApptarget;
	this->verRefWznmMVersion = verRefWznmMVersion;
	this->verNum = verNum;
	this->Short = Short;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmMApp::operator==(
			const WznmMApp& comp
		) {
	return false;
};

bool WznmMApp::operator!=(
			const WznmMApp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMApp
 ******************************************************************************/

ListWznmMApp::ListWznmMApp() {
};

ListWznmMApp::ListWznmMApp(
			const ListWznmMApp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMApp(*(src.nodes[i]));
};

ListWznmMApp::~ListWznmMApp() {
	clear();
};

void ListWznmMApp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMApp::size() const {
	return(nodes.size());
};

void ListWznmMApp::append(
			WznmMApp* rec
		) {
	nodes.push_back(rec);
};

WznmMApp* ListWznmMApp::operator[](
			const uint ix
		) {
	WznmMApp* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMApp& ListWznmMApp::operator=(
			const ListWznmMApp& src
		) {
	WznmMApp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMApp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMApp::operator==(
			const ListWznmMApp& comp
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

bool ListWznmMApp::operator!=(
			const ListWznmMApp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMApp
 ******************************************************************************/

TblWznmMApp::TblWznmMApp() {
};

TblWznmMApp::~TblWznmMApp() {
};

bool TblWznmMApp::loadRecBySQL(
			const string& sqlstr
			, WznmMApp** rec
		) {
	return false;
};

ubigint TblWznmMApp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMApp& rst
		) {
	return 0;
};

ubigint TblWznmMApp::insertRec(
			WznmMApp* rec
		) {
	return 0;
};

ubigint TblWznmMApp::insertNewRec(
			WznmMApp** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWznmVApptarget
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string Short
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMApp* _rec = NULL;

	_rec = new WznmMApp(0, grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMApp::appendNewRecToRst(
			ListWznmMApp& rst
			, WznmMApp** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWznmVApptarget
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string Short
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMApp* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMApp::insertRst(
			ListWznmMApp& rst
			, bool transact
		) {
};

void TblWznmMApp::updateRec(
			WznmMApp* rec
		) {
};

void TblWznmMApp::updateRst(
			ListWznmMApp& rst
			, bool transact
		) {
};

void TblWznmMApp::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMApp::loadRecByRef(
			ubigint ref
			, WznmMApp** rec
		) {
	return false;
};

ubigint TblWznmMApp::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMApp& rst
		) {
	return 0;
};

ubigint TblWznmMApp::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMApp& rst
		) {
	ubigint numload = 0;
	WznmMApp* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMApp
 ******************************************************************************/

MyTblWznmMApp::MyTblWznmMApp() :
			TblWznmMApp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMApp::~MyTblWznmMApp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMApp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMApp (grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMApp SET grp = ?, own = ?, ixWznmVApptarget = ?, verRefWznmMVersion = ?, verNum = ?, Short = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMApp WHERE ref = ?", false);
};

bool MyTblWznmMApp::loadRecBySQL(
			const string& sqlstr
			, WznmMApp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMApp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMApp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMApp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMApp();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixWznmVApptarget = atol((char*) dbrow[3]); else _rec->ixWznmVApptarget = 0;
		if (dbrow[4]) _rec->verRefWznmMVersion = atoll((char*) dbrow[4]); else _rec->verRefWznmMVersion = 0;
		if (dbrow[5]) _rec->verNum = atol((char*) dbrow[5]); else _rec->verNum = 0;
		if (dbrow[6]) _rec->Short.assign(dbrow[6], dblengths[6]); else _rec->Short = "";
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMApp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMApp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMApp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMApp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMApp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMApp();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixWznmVApptarget = atol((char*) dbrow[3]); else rec->ixWznmVApptarget = 0;
			if (dbrow[4]) rec->verRefWznmMVersion = atoll((char*) dbrow[4]); else rec->verRefWznmMVersion = 0;
			if (dbrow[5]) rec->verNum = atol((char*) dbrow[5]); else rec->verNum = 0;
			if (dbrow[6]) rec->Short.assign(dbrow[6], dblengths[6]); else rec->Short = "";
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMApp::insertRec(
			WznmMApp* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->Short.length();
	l[6] = rec->Title.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWznmVApptarget,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->verNum,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Short.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMApp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMApp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMApp::insertRst(
			ListWznmMApp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMApp::updateRec(
			WznmMApp* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->Short.length();
	l[6] = rec->Title.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWznmVApptarget,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->verNum,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Short.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMApp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMApp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMApp::updateRst(
			ListWznmMApp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMApp::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMApp::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMApp::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMApp::loadRecByRef(
			ubigint ref
			, WznmMApp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMApp WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMApp::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMApp& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment FROM TblWznmMApp WHERE verRefWznmMVersion = " + to_string(verRefWznmMVersion) + " ORDER BY verNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMApp
 ******************************************************************************/

PgTblWznmMApp::PgTblWznmMApp() :
			TblWznmMApp()
			, PgTable()
		{
};

PgTblWznmMApp::~PgTblWznmMApp() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMApp::initStatements() {
	createStatement("TblWznmMApp_insertRec", "INSERT INTO TblWznmMApp (grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMApp_updateRec", "UPDATE TblWznmMApp SET grp = $1, own = $2, ixWznmVApptarget = $3, verRefWznmMVersion = $4, verNum = $5, Short = $6, Title = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMApp_removeRecByRef", "DELETE FROM TblWznmMApp WHERE ref = $1", 1);

	createStatement("TblWznmMApp_loadRecByRef", "SELECT ref, grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment FROM TblWznmMApp WHERE ref = $1", 1);
	createStatement("TblWznmMApp_loadRstByVer", "SELECT ref, grp, own, ixWznmVApptarget, verRefWznmMVersion, verNum, Short, Title, Comment FROM TblWznmMApp WHERE verRefWznmMVersion = $1 ORDER BY verNum ASC", 1);
};

bool PgTblWznmMApp::loadRec(
			PGresult* res
			, WznmMApp** rec
		) {
	char* ptr;

	WznmMApp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMApp();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwznmvapptarget"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWznmVApptarget = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->verRefWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->verNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMApp::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMApp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMApp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwznmvapptarget"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMApp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWznmVApptarget = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->verRefWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->verNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMApp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMApp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMApp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMApp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMApp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMApp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMApp::loadRecBySQL(
			const string& sqlstr
			, WznmMApp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMApp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMApp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMApp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMApp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMApp::insertRec(
			WznmMApp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWznmVApptarget = htonl(rec->ixWznmVApptarget);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWznmVApptarget,
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->Short.c_str(),
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMApp_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMApp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMApp::insertRst(
			ListWznmMApp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMApp::updateRec(
			WznmMApp* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWznmVApptarget = htonl(rec->ixWznmVApptarget);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWznmVApptarget,
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->Short.c_str(),
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMApp_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMApp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMApp::updateRst(
			ListWznmMApp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMApp::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMApp_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMApp::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMApp::loadRecByRef(
			ubigint ref
			, WznmMApp** rec
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

	return loadRecByStmt("TblWznmMApp_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMApp::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMApp& rst
		) {
	ubigint _verRefWznmMVersion = htonl64(verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMApp_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

