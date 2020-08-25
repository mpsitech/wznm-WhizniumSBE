/**
	* \file WznmRMPersonMProject.cpp
	* database access for table TblWznmRMPersonMProject (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmRMPersonMProject.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMPersonMProject
 ******************************************************************************/

WznmRMPersonMProject::WznmRMPersonMProject(
			const ubigint ref
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWznmMPerson
			, const ubigint refWznmMProject
			, const string srefKFunction
		) {

	this->ref = ref;
	this->x1Startd = x1Startd;
	this->x1Stopd = x1Stopd;
	this->refWznmMPerson = refWznmMPerson;
	this->refWznmMProject = refWznmMProject;
	this->srefKFunction = srefKFunction;
};

bool WznmRMPersonMProject::operator==(
			const WznmRMPersonMProject& comp
		) {
	return false;
};

bool WznmRMPersonMProject::operator!=(
			const WznmRMPersonMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMPersonMProject
 ******************************************************************************/

ListWznmRMPersonMProject::ListWznmRMPersonMProject() {
};

ListWznmRMPersonMProject::ListWznmRMPersonMProject(
			const ListWznmRMPersonMProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMPersonMProject(*(src.nodes[i]));
};

ListWznmRMPersonMProject::~ListWznmRMPersonMProject() {
	clear();
};

void ListWznmRMPersonMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMPersonMProject::size() const {
	return(nodes.size());
};

void ListWznmRMPersonMProject::append(
			WznmRMPersonMProject* rec
		) {
	nodes.push_back(rec);
};

WznmRMPersonMProject* ListWznmRMPersonMProject::operator[](
			const uint ix
		) {
	WznmRMPersonMProject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMPersonMProject& ListWznmRMPersonMProject::operator=(
			const ListWznmRMPersonMProject& src
		) {
	WznmRMPersonMProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMPersonMProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMPersonMProject::operator==(
			const ListWznmRMPersonMProject& comp
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

bool ListWznmRMPersonMProject::operator!=(
			const ListWznmRMPersonMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMPersonMProject
 ******************************************************************************/

TblWznmRMPersonMProject::TblWznmRMPersonMProject() {
};

TblWznmRMPersonMProject::~TblWznmRMPersonMProject() {
};

bool TblWznmRMPersonMProject::loadRecBySQL(
			const string& sqlstr
			, WznmRMPersonMProject** rec
		) {
	return false;
};

ubigint TblWznmRMPersonMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	return 0;
};

ubigint TblWznmRMPersonMProject::insertRec(
			WznmRMPersonMProject* rec
		) {
	return 0;
};

ubigint TblWznmRMPersonMProject::insertNewRec(
			WznmRMPersonMProject** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWznmMPerson
			, const ubigint refWznmMProject
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WznmRMPersonMProject* _rec = NULL;

	_rec = new WznmRMPersonMProject(0, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMPersonMProject::appendNewRecToRst(
			ListWznmRMPersonMProject& rst
			, WznmRMPersonMProject** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWznmMPerson
			, const ubigint refWznmMProject
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WznmRMPersonMProject* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMPersonMProject::insertRst(
			ListWznmRMPersonMProject& rst
			, bool transact
		) {
};

void TblWznmRMPersonMProject::updateRec(
			WznmRMPersonMProject* rec
		) {
};

void TblWznmRMPersonMProject::updateRst(
			ListWznmRMPersonMProject& rst
			, bool transact
		) {
};

void TblWznmRMPersonMProject::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMPersonMProject::loadRecByRef(
			ubigint ref
			, WznmRMPersonMProject** rec
		) {
	return false;
};

ubigint TblWznmRMPersonMProject::loadRefsByPrj(
			ubigint refWznmMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMPersonMProject::loadRstByPrj(
			ubigint refWznmMProject
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	return 0;
};

ubigint TblWznmRMPersonMProject::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	return 0;
};

ubigint TblWznmRMPersonMProject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	ubigint numload = 0;
	WznmRMPersonMProject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMPersonMProject
 ******************************************************************************/

MyTblWznmRMPersonMProject::MyTblWznmRMPersonMProject() :
			TblWznmRMPersonMProject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMPersonMProject::~MyTblWznmRMPersonMProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMPersonMProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMPersonMProject (x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMPersonMProject SET x1Startd = ?, x1Stopd = ?, refWznmMPerson = ?, refWznmMProject = ?, srefKFunction = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMPersonMProject WHERE ref = ?", false);
};

bool MyTblWznmRMPersonMProject::loadRecBySQL(
			const string& sqlstr
			, WznmRMPersonMProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMPersonMProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMPersonMProject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMPersonMProject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmRMPersonMProject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startd = atol((char*) dbrow[1]); else _rec->x1Startd = 0;
		if (dbrow[2]) _rec->x1Stopd = atol((char*) dbrow[2]); else _rec->x1Stopd = 0;
		if (dbrow[3]) _rec->refWznmMPerson = atoll((char*) dbrow[3]); else _rec->refWznmMPerson = 0;
		if (dbrow[4]) _rec->refWznmMProject = atoll((char*) dbrow[4]); else _rec->refWznmMProject = 0;
		if (dbrow[5]) _rec->srefKFunction.assign(dbrow[5], dblengths[5]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMPersonMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMPersonMProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMPersonMProject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMPersonMProject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmRMPersonMProject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startd = atol((char*) dbrow[1]); else rec->x1Startd = 0;
			if (dbrow[2]) rec->x1Stopd = atol((char*) dbrow[2]); else rec->x1Stopd = 0;
			if (dbrow[3]) rec->refWznmMPerson = atoll((char*) dbrow[3]); else rec->refWznmMPerson = 0;
			if (dbrow[4]) rec->refWznmMProject = atoll((char*) dbrow[4]); else rec->refWznmMProject = 0;
			if (dbrow[5]) rec->srefKFunction.assign(dbrow[5], dblengths[5]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMPersonMProject::insertRec(
			WznmRMPersonMProject* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMPerson,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMProject,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMPersonMProject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMPersonMProject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMPersonMProject::insertRst(
			ListWznmRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMPersonMProject::updateRec(
			WznmRMPersonMProject* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMPerson,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMProject,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMPersonMProject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMPersonMProject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMPersonMProject::updateRst(
			ListWznmRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMPersonMProject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMPersonMProject::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMPersonMProject::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMPersonMProject::loadRecByRef(
			ubigint ref
			, WznmRMPersonMProject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMPersonMProject WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMPersonMProject::loadRefsByPrj(
			ubigint refWznmMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMPersonMProject WHERE refWznmMProject = " + to_string(refWznmMProject) + "", append, refs);
};

ubigint MyTblWznmRMPersonMProject::loadRstByPrj(
			ubigint refWznmMProject
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction FROM TblWznmRMPersonMProject WHERE refWznmMProject = " + to_string(refWznmMProject) + "", append, rst);
};

ubigint MyTblWznmRMPersonMProject::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction FROM TblWznmRMPersonMProject WHERE refWznmMPerson = " + to_string(refWznmMPerson) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMPersonMProject
 ******************************************************************************/

PgTblWznmRMPersonMProject::PgTblWznmRMPersonMProject() :
			TblWznmRMPersonMProject()
			, PgTable()
		{
};

PgTblWznmRMPersonMProject::~PgTblWznmRMPersonMProject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMPersonMProject::initStatements() {
	createStatement("TblWznmRMPersonMProject_insertRec", "INSERT INTO TblWznmRMPersonMProject (x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmRMPersonMProject_updateRec", "UPDATE TblWznmRMPersonMProject SET x1Startd = $1, x1Stopd = $2, refWznmMPerson = $3, refWznmMProject = $4, srefKFunction = $5 WHERE ref = $6", 6);
	createStatement("TblWznmRMPersonMProject_removeRecByRef", "DELETE FROM TblWznmRMPersonMProject WHERE ref = $1", 1);

	createStatement("TblWznmRMPersonMProject_loadRecByRef", "SELECT ref, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction FROM TblWznmRMPersonMProject WHERE ref = $1", 1);
	createStatement("TblWznmRMPersonMProject_loadRefsByPrj", "SELECT ref FROM TblWznmRMPersonMProject WHERE refWznmMProject = $1", 1);
	createStatement("TblWznmRMPersonMProject_loadRstByPrj", "SELECT ref, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction FROM TblWznmRMPersonMProject WHERE refWznmMProject = $1", 1);
	createStatement("TblWznmRMPersonMProject_loadRstByPrs", "SELECT ref, x1Startd, x1Stopd, refWznmMPerson, refWznmMProject, srefKFunction FROM TblWznmRMPersonMProject WHERE refWznmMPerson = $1", 1);
};

bool PgTblWznmRMPersonMProject::loadRec(
			PGresult* res
			, WznmRMPersonMProject** rec
		) {
	char* ptr;

	WznmRMPersonMProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMPersonMProject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "refwznmmproject"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMPersonMProject::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMPersonMProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "refwznmmproject"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WznmRMPersonMProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMPersonMProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMPersonMProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPersonMProject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMPersonMProject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPersonMProject::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmRMPersonMProject::loadRecBySQL(
			const string& sqlstr
			, WznmRMPersonMProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPersonMProject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMPersonMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPersonMProject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMPersonMProject::insertRec(
			WznmRMPersonMProject* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _refWznmMProject = htonl64(rec->refWznmMProject);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refWznmMPerson,
		(char*) &_refWznmMProject,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmRMPersonMProject_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMPersonMProject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMPersonMProject::insertRst(
			ListWznmRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMPersonMProject::updateRec(
			WznmRMPersonMProject* rec
		) {
	PGresult* res;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _refWznmMProject = htonl64(rec->refWznmMProject);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refWznmMPerson,
		(char*) &_refWznmMProject,
		rec->srefKFunction.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmRMPersonMProject_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMPersonMProject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMPersonMProject::updateRst(
			ListWznmRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMPersonMProject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMPersonMProject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMPersonMProject::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMPersonMProject::loadRecByRef(
			ubigint ref
			, WznmRMPersonMProject** rec
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

	return loadRecByStmt("TblWznmRMPersonMProject_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMPersonMProject::loadRefsByPrj(
			ubigint refWznmMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMProject = htonl64(refWznmMProject);

	const char* vals[] = {
		(char*) &_refWznmMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMPersonMProject_loadRefsByPrj", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMPersonMProject::loadRstByPrj(
			ubigint refWznmMProject
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	ubigint _refWznmMProject = htonl64(refWznmMProject);

	const char* vals[] = {
		(char*) &_refWznmMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMPersonMProject_loadRstByPrj", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmRMPersonMProject::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmRMPersonMProject& rst
		) {
	ubigint _refWznmMPerson = htonl64(refWznmMPerson);

	const char* vals[] = {
		(char*) &_refWznmMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMPersonMProject_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif

