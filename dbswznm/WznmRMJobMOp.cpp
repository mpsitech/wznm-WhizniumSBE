/**
	* \file WznmRMJobMOp.cpp
	* database access for table TblWznmRMJobMOp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmRMJobMOp.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMJobMOp
 ******************************************************************************/

WznmRMJobMOp::WznmRMJobMOp(
			const ubigint ref
			, const ubigint refWznmMJob
			, const ubigint refWznmMOp
		) {

	this->ref = ref;
	this->refWznmMJob = refWznmMJob;
	this->refWznmMOp = refWznmMOp;
};

bool WznmRMJobMOp::operator==(
			const WznmRMJobMOp& comp
		) {
	return false;
};

bool WznmRMJobMOp::operator!=(
			const WznmRMJobMOp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMJobMOp
 ******************************************************************************/

ListWznmRMJobMOp::ListWznmRMJobMOp() {
};

ListWznmRMJobMOp::ListWznmRMJobMOp(
			const ListWznmRMJobMOp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMJobMOp(*(src.nodes[i]));
};

ListWznmRMJobMOp::~ListWznmRMJobMOp() {
	clear();
};

void ListWznmRMJobMOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMJobMOp::size() const {
	return(nodes.size());
};

void ListWznmRMJobMOp::append(
			WznmRMJobMOp* rec
		) {
	nodes.push_back(rec);
};

WznmRMJobMOp* ListWznmRMJobMOp::operator[](
			const uint ix
		) {
	WznmRMJobMOp* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMJobMOp& ListWznmRMJobMOp::operator=(
			const ListWznmRMJobMOp& src
		) {
	WznmRMJobMOp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMJobMOp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMJobMOp::operator==(
			const ListWznmRMJobMOp& comp
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

bool ListWznmRMJobMOp::operator!=(
			const ListWznmRMJobMOp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMJobMOp
 ******************************************************************************/

TblWznmRMJobMOp::TblWznmRMJobMOp() {
};

TblWznmRMJobMOp::~TblWznmRMJobMOp() {
};

bool TblWznmRMJobMOp::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMOp** rec
		) {
	return false;
};

ubigint TblWznmRMJobMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMOp& rst
		) {
	return 0;
};

ubigint TblWznmRMJobMOp::insertRec(
			WznmRMJobMOp* rec
		) {
	return 0;
};

ubigint TblWznmRMJobMOp::insertNewRec(
			WznmRMJobMOp** rec
			, const ubigint refWznmMJob
			, const ubigint refWznmMOp
		) {
	ubigint retval = 0;
	WznmRMJobMOp* _rec = NULL;

	_rec = new WznmRMJobMOp(0, refWznmMJob, refWznmMOp);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMJobMOp::appendNewRecToRst(
			ListWznmRMJobMOp& rst
			, WznmRMJobMOp** rec
			, const ubigint refWznmMJob
			, const ubigint refWznmMOp
		) {
	ubigint retval = 0;
	WznmRMJobMOp* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMJob, refWznmMOp);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMJobMOp::insertRst(
			ListWznmRMJobMOp& rst
			, bool transact
		) {
};

void TblWznmRMJobMOp::updateRec(
			WznmRMJobMOp* rec
		) {
};

void TblWznmRMJobMOp::updateRst(
			ListWznmRMJobMOp& rst
			, bool transact
		) {
};

void TblWznmRMJobMOp::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMJobMOp::loadRecByRef(
			ubigint ref
			, WznmRMJobMOp** rec
		) {
	return false;
};

ubigint TblWznmRMJobMOp::loadJobsByOpx(
			ubigint refWznmMOp
			, const bool append
			, vector<ubigint>& refWznmMJobs
		) {
	return 0;
};

ubigint TblWznmRMJobMOp::loadOpxsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refWznmMOps
		) {
	return 0;
};

ubigint TblWznmRMJobMOp::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMJobMOp::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMJobMOp& rst
		) {
	ubigint numload = 0;
	WznmRMJobMOp* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMJobMOp
 ******************************************************************************/

MyTblWznmRMJobMOp::MyTblWznmRMJobMOp() :
			TblWznmRMJobMOp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMJobMOp::~MyTblWznmRMJobMOp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMJobMOp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMJobMOp (refWznmMJob, refWznmMOp) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMJobMOp SET refWznmMJob = ?, refWznmMOp = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMJobMOp WHERE ref = ?", false);
};

bool MyTblWznmRMJobMOp::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMOp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMJobMOp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMJobMOp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMJobMOp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMJobMOp();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMJob = atoll((char*) dbrow[1]); else _rec->refWznmMJob = 0;
		if (dbrow[2]) _rec->refWznmMOp = atoll((char*) dbrow[2]); else _rec->refWznmMOp = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMJobMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMOp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMJobMOp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMJobMOp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMJobMOp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMJobMOp();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMJob = atoll((char*) dbrow[1]); else rec->refWznmMJob = 0;
			if (dbrow[2]) rec->refWznmMOp = atoll((char*) dbrow[2]); else rec->refWznmMOp = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMJobMOp::insertRec(
			WznmRMJobMOp* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOp,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMJobMOp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMJobMOp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMJobMOp::insertRst(
			ListWznmRMJobMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMJobMOp::updateRec(
			WznmRMJobMOp* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOp,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMJobMOp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMJobMOp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMJobMOp::updateRst(
			ListWznmRMJobMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMJobMOp::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMJobMOp::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMJobMOp::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMJobMOp::loadRecByRef(
			ubigint ref
			, WznmRMJobMOp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMJobMOp WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMJobMOp::loadJobsByOpx(
			ubigint refWznmMOp
			, const bool append
			, vector<ubigint>& refWznmMJobs
		) {
	return loadRefsBySQL("SELECT refWznmMJob FROM TblWznmRMJobMOp WHERE refWznmMOp = " + to_string(refWznmMOp) + "", append, refWznmMJobs);
};

ubigint MyTblWznmRMJobMOp::loadOpxsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refWznmMOps
		) {
	return loadRefsBySQL("SELECT refWznmMOp FROM TblWznmRMJobMOp WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refWznmMOps);
};

ubigint MyTblWznmRMJobMOp::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMJobMOp WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMJobMOp
 ******************************************************************************/

PgTblWznmRMJobMOp::PgTblWznmRMJobMOp() :
			TblWznmRMJobMOp()
			, PgTable()
		{
};

PgTblWznmRMJobMOp::~PgTblWznmRMJobMOp() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMJobMOp::initStatements() {
	createStatement("TblWznmRMJobMOp_insertRec", "INSERT INTO TblWznmRMJobMOp (refWznmMJob, refWznmMOp) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMJobMOp_updateRec", "UPDATE TblWznmRMJobMOp SET refWznmMJob = $1, refWznmMOp = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMJobMOp_removeRecByRef", "DELETE FROM TblWznmRMJobMOp WHERE ref = $1", 1);

	createStatement("TblWznmRMJobMOp_loadRecByRef", "SELECT ref, refWznmMJob, refWznmMOp FROM TblWznmRMJobMOp WHERE ref = $1", 1);
	createStatement("TblWznmRMJobMOp_loadJobsByOpx", "SELECT refWznmMJob FROM TblWznmRMJobMOp WHERE refWznmMOp = $1", 1);
	createStatement("TblWznmRMJobMOp_loadOpxsByJob", "SELECT refWznmMOp FROM TblWznmRMJobMOp WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmRMJobMOp_loadRefsByJob", "SELECT ref FROM TblWznmRMJobMOp WHERE refWznmMJob = $1", 1);
};

bool PgTblWznmRMJobMOp::loadRec(
			PGresult* res
			, WznmRMJobMOp** rec
		) {
	char* ptr;

	WznmRMJobMOp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMJobMOp();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "refwznmmop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMOp = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMJobMOp::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMJobMOp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMJobMOp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "refwznmmop")
		};

		while (numread < numrow) {
			rec = new WznmRMJobMOp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMOp = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMJobMOp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMJobMOp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMJobMOp::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMOp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMJobMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMOp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMJobMOp::insertRec(
			WznmRMJobMOp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refWznmMOp = htonl64(rec->refWznmMOp);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		(char*) &_refWznmMOp
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMJobMOp_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMJobMOp::insertRst(
			ListWznmRMJobMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMJobMOp::updateRec(
			WznmRMJobMOp* rec
		) {
	PGresult* res;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refWznmMOp = htonl64(rec->refWznmMOp);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		(char*) &_refWznmMOp,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMJobMOp_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMJobMOp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMJobMOp::updateRst(
			ListWznmRMJobMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMJobMOp::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMJobMOp_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMJobMOp::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMJobMOp::loadRecByRef(
			ubigint ref
			, WznmRMJobMOp** rec
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

	return loadRecByStmt("TblWznmRMJobMOp_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMJobMOp::loadJobsByOpx(
			ubigint refWznmMOp
			, const bool append
			, vector<ubigint>& refWznmMJobs
		) {
	ubigint _refWznmMOp = htonl64(refWznmMOp);

	const char* vals[] = {
		(char*) &_refWznmMOp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMJobMOp_loadJobsByOpx", 1, vals, l, f, append, refWznmMJobs);
};

ubigint PgTblWznmRMJobMOp::loadOpxsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refWznmMOps
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMJobMOp_loadOpxsByJob", 1, vals, l, f, append, refWznmMOps);
};

ubigint PgTblWznmRMJobMOp::loadRefsByJob(
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

	return loadRefsByStmt("TblWznmRMJobMOp_loadRefsByJob", 1, vals, l, f, append, refs);
};

#endif

