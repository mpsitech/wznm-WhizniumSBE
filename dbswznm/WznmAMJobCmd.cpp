/**
	* \file WznmAMJobCmd.cpp
	* database access for table TblWznmAMJobCmd (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmAMJobCmd.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMJobCmd
 ******************************************************************************/

WznmAMJobCmd::WznmAMJobCmd(
			const ubigint ref
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMJob = refWznmMJob;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmAMJobCmd::operator==(
			const WznmAMJobCmd& comp
		) {
	return false;
};

bool WznmAMJobCmd::operator!=(
			const WznmAMJobCmd& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMJobCmd
 ******************************************************************************/

ListWznmAMJobCmd::ListWznmAMJobCmd() {
};

ListWznmAMJobCmd::ListWznmAMJobCmd(
			const ListWznmAMJobCmd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMJobCmd(*(src.nodes[i]));
};

ListWznmAMJobCmd::~ListWznmAMJobCmd() {
	clear();
};

void ListWznmAMJobCmd::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMJobCmd::size() const {
	return(nodes.size());
};

void ListWznmAMJobCmd::append(
			WznmAMJobCmd* rec
		) {
	nodes.push_back(rec);
};

WznmAMJobCmd* ListWznmAMJobCmd::operator[](
			const uint ix
		) {
	WznmAMJobCmd* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMJobCmd& ListWznmAMJobCmd::operator=(
			const ListWznmAMJobCmd& src
		) {
	WznmAMJobCmd* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMJobCmd(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMJobCmd::operator==(
			const ListWznmAMJobCmd& comp
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

bool ListWznmAMJobCmd::operator!=(
			const ListWznmAMJobCmd& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMJobCmd
 ******************************************************************************/

TblWznmAMJobCmd::TblWznmAMJobCmd() {
};

TblWznmAMJobCmd::~TblWznmAMJobCmd() {
};

bool TblWznmAMJobCmd::loadRecBySQL(
			const string& sqlstr
			, WznmAMJobCmd** rec
		) {
	return false;
};

ubigint TblWznmAMJobCmd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	return 0;
};

ubigint TblWznmAMJobCmd::insertRec(
			WznmAMJobCmd* rec
		) {
	return 0;
};

ubigint TblWznmAMJobCmd::insertNewRec(
			WznmAMJobCmd** rec
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMJobCmd* _rec = NULL;

	_rec = new WznmAMJobCmd(0, refWznmMJob, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMJobCmd::appendNewRecToRst(
			ListWznmAMJobCmd& rst
			, WznmAMJobCmd** rec
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMJobCmd* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMJob, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMJobCmd::insertRst(
			ListWznmAMJobCmd& rst
			, bool transact
		) {
};

void TblWznmAMJobCmd::updateRec(
			WznmAMJobCmd* rec
		) {
};

void TblWznmAMJobCmd::updateRst(
			ListWznmAMJobCmd& rst
			, bool transact
		) {
};

void TblWznmAMJobCmd::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMJobCmd::loadRecByRef(
			ubigint ref
			, WznmAMJobCmd** rec
		) {
	return false;
};

ubigint TblWznmAMJobCmd::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMJobCmd::loadRstByJob(
			ubigint refWznmMJob
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	return 0;
};

ubigint TblWznmAMJobCmd::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	ubigint numload = 0;
	WznmAMJobCmd* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMJobCmd
 ******************************************************************************/

MyTblWznmAMJobCmd::MyTblWznmAMJobCmd() :
			TblWznmAMJobCmd()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMJobCmd::~MyTblWznmAMJobCmd() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMJobCmd::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMJobCmd (refWznmMJob, sref, Comment) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMJobCmd SET refWznmMJob = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMJobCmd WHERE ref = ?", false);
};

bool MyTblWznmAMJobCmd::loadRecBySQL(
			const string& sqlstr
			, WznmAMJobCmd** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMJobCmd* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMJobCmd::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMJobCmd::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMJobCmd();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMJob = atoll((char*) dbrow[1]); else _rec->refWznmMJob = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->Comment.assign(dbrow[3], dblengths[3]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMJobCmd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMJobCmd* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMJobCmd::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMJobCmd::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMJobCmd();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMJob = atoll((char*) dbrow[1]); else rec->refWznmMJob = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->Comment.assign(dbrow[3], dblengths[3]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMJobCmd::insertRec(
			WznmAMJobCmd* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMJobCmd::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMJobCmd::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMJobCmd::insertRst(
			ListWznmAMJobCmd& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMJobCmd::updateRec(
			WznmAMJobCmd* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMJobCmd::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMJobCmd::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMJobCmd::updateRst(
			ListWznmAMJobCmd& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMJobCmd::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMJobCmd::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMJobCmd::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMJobCmd::loadRecByRef(
			ubigint ref
			, WznmAMJobCmd** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMJobCmd WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMJobCmd::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMJobCmd WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refs);
};

ubigint MyTblWznmAMJobCmd::loadRstByJob(
			ubigint refWznmMJob
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMJob, sref, Comment FROM TblWznmAMJobCmd WHERE refWznmMJob = " + to_string(refWznmMJob) + " ORDER BY sref ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMJobCmd
 ******************************************************************************/

PgTblWznmAMJobCmd::PgTblWznmAMJobCmd() :
			TblWznmAMJobCmd()
			, PgTable()
		{
};

PgTblWznmAMJobCmd::~PgTblWznmAMJobCmd() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMJobCmd::initStatements() {
	createStatement("TblWznmAMJobCmd_insertRec", "INSERT INTO TblWznmAMJobCmd (refWznmMJob, sref, Comment) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmAMJobCmd_updateRec", "UPDATE TblWznmAMJobCmd SET refWznmMJob = $1, sref = $2, Comment = $3 WHERE ref = $4", 4);
	createStatement("TblWznmAMJobCmd_removeRecByRef", "DELETE FROM TblWznmAMJobCmd WHERE ref = $1", 1);

	createStatement("TblWznmAMJobCmd_loadRecByRef", "SELECT ref, refWznmMJob, sref, Comment FROM TblWznmAMJobCmd WHERE ref = $1", 1);
	createStatement("TblWznmAMJobCmd_loadRefsByJob", "SELECT ref FROM TblWznmAMJobCmd WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmAMJobCmd_loadRstByJob", "SELECT ref, refWznmMJob, sref, Comment FROM TblWznmAMJobCmd WHERE refWznmMJob = $1 ORDER BY sref ASC", 1);
};

bool PgTblWznmAMJobCmd::loadRec(
			PGresult* res
			, WznmAMJobCmd** rec
		) {
	char* ptr;

	WznmAMJobCmd* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMJobCmd();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMJobCmd::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMJobCmd* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMJobCmd();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMJobCmd::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMJobCmd** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobCmd::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMJobCmd::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobCmd::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMJobCmd::loadRecBySQL(
			const string& sqlstr
			, WznmAMJobCmd** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobCmd::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMJobCmd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobCmd::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMJobCmd::insertRec(
			WznmAMJobCmd* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMJobCmd_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobCmd::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMJobCmd::insertRst(
			ListWznmAMJobCmd& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMJobCmd::updateRec(
			WznmAMJobCmd* rec
		) {
	PGresult* res;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMJob,
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

	res = PQexecPrepared(dbs, "TblWznmAMJobCmd_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMJobCmd::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMJobCmd::updateRst(
			ListWznmAMJobCmd& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMJobCmd::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMJobCmd_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMJobCmd::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMJobCmd::loadRecByRef(
			ubigint ref
			, WznmAMJobCmd** rec
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

	return loadRecByStmt("TblWznmAMJobCmd_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMJobCmd::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMJobCmd_loadRefsByJob", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMJobCmd::loadRstByJob(
			ubigint refWznmMJob
			, const bool append
			, ListWznmAMJobCmd& rst
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMJobCmd_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

