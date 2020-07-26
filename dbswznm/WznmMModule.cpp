/**
	* \file WznmMModule.cpp
	* database access for table TblWznmMModule (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMModule.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMModule
 ******************************************************************************/

WznmMModule::WznmMModule(
			const ubigint ref
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string sref
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->verRefWznmMVersion = verRefWznmMVersion;
	this->verNum = verNum;
	this->sref = sref;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmMModule::operator==(
			const WznmMModule& comp
		) {
	return false;
};

bool WznmMModule::operator!=(
			const WznmMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMModule
 ******************************************************************************/

ListWznmMModule::ListWznmMModule() {
};

ListWznmMModule::ListWznmMModule(
			const ListWznmMModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMModule(*(src.nodes[i]));
};

ListWznmMModule::~ListWznmMModule() {
	clear();
};

void ListWznmMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMModule::size() const {
	return(nodes.size());
};

void ListWznmMModule::append(
			WznmMModule* rec
		) {
	nodes.push_back(rec);
};

WznmMModule* ListWznmMModule::operator[](
			const uint ix
		) {
	WznmMModule* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMModule& ListWznmMModule::operator=(
			const ListWznmMModule& src
		) {
	WznmMModule* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMModule(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMModule::operator==(
			const ListWznmMModule& comp
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

bool ListWznmMModule::operator!=(
			const ListWznmMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMModule
 ******************************************************************************/

TblWznmMModule::TblWznmMModule() {
};

TblWznmMModule::~TblWznmMModule() {
};

bool TblWznmMModule::loadRecBySQL(
			const string& sqlstr
			, WznmMModule** rec
		) {
	return false;
};

ubigint TblWznmMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMModule& rst
		) {
	return 0;
};

ubigint TblWznmMModule::insertRec(
			WznmMModule* rec
		) {
	return 0;
};

ubigint TblWznmMModule::insertNewRec(
			WznmMModule** rec
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string sref
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMModule* _rec = NULL;

	_rec = new WznmMModule(0, verRefWznmMVersion, verNum, sref, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMModule::appendNewRecToRst(
			ListWznmMModule& rst
			, WznmMModule** rec
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string sref
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMModule* _rec = NULL;

	retval = insertNewRec(&_rec, verRefWznmMVersion, verNum, sref, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMModule::insertRst(
			ListWznmMModule& rst
			, bool transact
		) {
};

void TblWznmMModule::updateRec(
			WznmMModule* rec
		) {
};

void TblWznmMModule::updateRst(
			ListWznmMModule& rst
			, bool transact
		) {
};

void TblWznmMModule::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMModule::loadRecByRef(
			ubigint ref
			, WznmMModule** rec
		) {
	return false;
};

ubigint TblWznmMModule::loadRefsByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMModule::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMModule& rst
		) {
	return 0;
};

bool TblWznmMModule::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMModule::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMModule& rst
		) {
	ubigint numload = 0;
	WznmMModule* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMModule
 ******************************************************************************/

MyTblWznmMModule::MyTblWznmMModule() :
			TblWznmMModule()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMModule::~MyTblWznmMModule() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMModule::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMModule (verRefWznmMVersion, verNum, sref, refJ, Title, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMModule SET verRefWznmMVersion = ?, verNum = ?, sref = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMModule WHERE ref = ?", false);
};

bool MyTblWznmMModule::loadRecBySQL(
			const string& sqlstr
			, WznmMModule** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMModule* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMModule::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMModule::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMModule();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->verRefWznmMVersion = atoll((char*) dbrow[1]); else _rec->verRefWznmMVersion = 0;
		if (dbrow[2]) _rec->verNum = atol((char*) dbrow[2]); else _rec->verNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->refJ = atoll((char*) dbrow[4]); else _rec->refJ = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMModule& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMModule* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMModule::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMModule::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMModule();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->verRefWznmMVersion = atoll((char*) dbrow[1]); else rec->verRefWznmMVersion = 0;
			if (dbrow[2]) rec->verNum = atol((char*) dbrow[2]); else rec->verNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->refJ = atoll((char*) dbrow[4]); else rec->refJ = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMModule::insertRec(
			WznmMModule* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->verRefWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->verNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJ,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMModule::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMModule::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMModule::insertRst(
			ListWznmMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMModule::updateRec(
			WznmMModule* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->verRefWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->verNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJ,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMModule::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMModule::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMModule::updateRst(
			ListWznmMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMModule::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMModule::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMModule::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMModule::loadRecByRef(
			ubigint ref
			, WznmMModule** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMModule WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMModule::loadRefsByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMModule WHERE verRefWznmMVersion = " + to_string(verRefWznmMVersion) + " ORDER BY verNum ASC", append, refs);
};

ubigint MyTblWznmMModule::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMModule& rst
		) {
	return loadRstBySQL("SELECT ref, verRefWznmMVersion, verNum, sref, refJ, Title, Comment FROM TblWznmMModule WHERE verRefWznmMVersion = " + to_string(verRefWznmMVersion) + " ORDER BY verNum ASC", append, rst);
};

bool MyTblWznmMModule::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMModule WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMModule
 ******************************************************************************/

PgTblWznmMModule::PgTblWznmMModule() :
			TblWznmMModule()
			, PgTable()
		{
};

PgTblWznmMModule::~PgTblWznmMModule() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMModule::initStatements() {
	createStatement("TblWznmMModule_insertRec", "INSERT INTO TblWznmMModule (verRefWznmMVersion, verNum, sref, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWznmMModule_updateRec", "UPDATE TblWznmMModule SET verRefWznmMVersion = $1, verNum = $2, sref = $3, refJ = $4, Title = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWznmMModule_removeRecByRef", "DELETE FROM TblWznmMModule WHERE ref = $1", 1);

	createStatement("TblWznmMModule_loadRecByRef", "SELECT ref, verRefWznmMVersion, verNum, sref, refJ, Title, Comment FROM TblWznmMModule WHERE ref = $1", 1);
	createStatement("TblWznmMModule_loadRefsByVer", "SELECT ref FROM TblWznmMModule WHERE verRefWznmMVersion = $1 ORDER BY verNum ASC", 1);
	createStatement("TblWznmMModule_loadRstByVer", "SELECT ref, verRefWznmMVersion, verNum, sref, refJ, Title, Comment FROM TblWznmMModule WHERE verRefWznmMVersion = $1 ORDER BY verNum ASC", 1);
	createStatement("TblWznmMModule_loadSrfByRef", "SELECT sref FROM TblWznmMModule WHERE ref = $1", 1);
};

bool PgTblWznmMModule::loadRec(
			PGresult* res
			, WznmMModule** rec
		) {
	char* ptr;

	WznmMModule* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMModule();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->verRefWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->verNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMModule::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMModule& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMModule* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMModule();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->verRefWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->verNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMModule::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMModule** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMModule::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMModule::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMModule& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMModule::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMModule::loadRecBySQL(
			const string& sqlstr
			, WznmMModule** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMModule::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMModule& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMModule::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMModule::insertRec(
			WznmMModule* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->sref.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMModule_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMModule::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMModule::insertRst(
			ListWznmMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMModule::updateRec(
			WznmMModule* rec
		) {
	PGresult* res;

	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->sref.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMModule_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMModule::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMModule::updateRst(
			ListWznmMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMModule::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMModule_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMModule::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMModule::loadRecByRef(
			ubigint ref
			, WznmMModule** rec
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

	return loadRecByStmt("TblWznmMModule_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMModule::loadRefsByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _verRefWznmMVersion = htonl64(verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMModule_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMModule::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMModule& rst
		) {
	ubigint _verRefWznmMVersion = htonl64(verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMModule_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMModule::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMModule_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

