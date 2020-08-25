/**
	* \file WznmRMJobMOppack.cpp
	* database access for table TblWznmRMJobMOppack (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmRMJobMOppack.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMJobMOppack
 ******************************************************************************/

WznmRMJobMOppack::WznmRMJobMOppack(
			const ubigint ref
			, const ubigint refWznmMJob
			, const ubigint refWznmMOppack
		) {

	this->ref = ref;
	this->refWznmMJob = refWznmMJob;
	this->refWznmMOppack = refWznmMOppack;
};

bool WznmRMJobMOppack::operator==(
			const WznmRMJobMOppack& comp
		) {
	return false;
};

bool WznmRMJobMOppack::operator!=(
			const WznmRMJobMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMJobMOppack
 ******************************************************************************/

ListWznmRMJobMOppack::ListWznmRMJobMOppack() {
};

ListWznmRMJobMOppack::ListWznmRMJobMOppack(
			const ListWznmRMJobMOppack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMJobMOppack(*(src.nodes[i]));
};

ListWznmRMJobMOppack::~ListWznmRMJobMOppack() {
	clear();
};

void ListWznmRMJobMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMJobMOppack::size() const {
	return(nodes.size());
};

void ListWznmRMJobMOppack::append(
			WznmRMJobMOppack* rec
		) {
	nodes.push_back(rec);
};

WznmRMJobMOppack* ListWznmRMJobMOppack::operator[](
			const uint ix
		) {
	WznmRMJobMOppack* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMJobMOppack& ListWznmRMJobMOppack::operator=(
			const ListWznmRMJobMOppack& src
		) {
	WznmRMJobMOppack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMJobMOppack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMJobMOppack::operator==(
			const ListWznmRMJobMOppack& comp
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

bool ListWznmRMJobMOppack::operator!=(
			const ListWznmRMJobMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMJobMOppack
 ******************************************************************************/

TblWznmRMJobMOppack::TblWznmRMJobMOppack() {
};

TblWznmRMJobMOppack::~TblWznmRMJobMOppack() {
};

bool TblWznmRMJobMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMOppack** rec
		) {
	return false;
};

ubigint TblWznmRMJobMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMOppack& rst
		) {
	return 0;
};

ubigint TblWznmRMJobMOppack::insertRec(
			WznmRMJobMOppack* rec
		) {
	return 0;
};

ubigint TblWznmRMJobMOppack::insertNewRec(
			WznmRMJobMOppack** rec
			, const ubigint refWznmMJob
			, const ubigint refWznmMOppack
		) {
	ubigint retval = 0;
	WznmRMJobMOppack* _rec = NULL;

	_rec = new WznmRMJobMOppack(0, refWznmMJob, refWznmMOppack);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMJobMOppack::appendNewRecToRst(
			ListWznmRMJobMOppack& rst
			, WznmRMJobMOppack** rec
			, const ubigint refWznmMJob
			, const ubigint refWznmMOppack
		) {
	ubigint retval = 0;
	WznmRMJobMOppack* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMJob, refWznmMOppack);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMJobMOppack::insertRst(
			ListWznmRMJobMOppack& rst
			, bool transact
		) {
};

void TblWznmRMJobMOppack::updateRec(
			WznmRMJobMOppack* rec
		) {
};

void TblWznmRMJobMOppack::updateRst(
			ListWznmRMJobMOppack& rst
			, bool transact
		) {
};

void TblWznmRMJobMOppack::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMJobMOppack::loadRecByRef(
			ubigint ref
			, WznmRMJobMOppack** rec
		) {
	return false;
};

ubigint TblWznmRMJobMOppack::loadJobsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMJobs
		) {
	return 0;
};

ubigint TblWznmRMJobMOppack::loadOpksByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	return 0;
};

ubigint TblWznmRMJobMOppack::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMJobMOppack::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMJobMOppack& rst
		) {
	ubigint numload = 0;
	WznmRMJobMOppack* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMJobMOppack
 ******************************************************************************/

MyTblWznmRMJobMOppack::MyTblWznmRMJobMOppack() :
			TblWznmRMJobMOppack()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMJobMOppack::~MyTblWznmRMJobMOppack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMJobMOppack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMJobMOppack (refWznmMJob, refWznmMOppack) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMJobMOppack SET refWznmMJob = ?, refWznmMOppack = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMJobMOppack WHERE ref = ?", false);
};

bool MyTblWznmRMJobMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMOppack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMJobMOppack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMJobMOppack::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMJobMOppack::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMJobMOppack();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMJob = atoll((char*) dbrow[1]); else _rec->refWznmMJob = 0;
		if (dbrow[2]) _rec->refWznmMOppack = atoll((char*) dbrow[2]); else _rec->refWznmMOppack = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMJobMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMOppack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMJobMOppack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMJobMOppack::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMJobMOppack::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMJobMOppack();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMJob = atoll((char*) dbrow[1]); else rec->refWznmMJob = 0;
			if (dbrow[2]) rec->refWznmMOppack = atoll((char*) dbrow[2]); else rec->refWznmMOppack = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMJobMOppack::insertRec(
			WznmRMJobMOppack* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOppack,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMJobMOppack::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMJobMOppack::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMJobMOppack::insertRst(
			ListWznmRMJobMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMJobMOppack::updateRec(
			WznmRMJobMOppack* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMJobMOppack::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMJobMOppack::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMJobMOppack::updateRst(
			ListWznmRMJobMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMJobMOppack::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMJobMOppack::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMJobMOppack::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMJobMOppack::loadRecByRef(
			ubigint ref
			, WznmRMJobMOppack** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMJobMOppack WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMJobMOppack::loadJobsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMJobs
		) {
	return loadRefsBySQL("SELECT refWznmMJob FROM TblWznmRMJobMOppack WHERE refWznmMOppack = " + to_string(refWznmMOppack) + "", append, refWznmMJobs);
};

ubigint MyTblWznmRMJobMOppack::loadOpksByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	return loadRefsBySQL("SELECT refWznmMOppack FROM TblWznmRMJobMOppack WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refWznmMOppacks);
};

ubigint MyTblWznmRMJobMOppack::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMJobMOppack WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMJobMOppack
 ******************************************************************************/

PgTblWznmRMJobMOppack::PgTblWznmRMJobMOppack() :
			TblWznmRMJobMOppack()
			, PgTable()
		{
};

PgTblWznmRMJobMOppack::~PgTblWznmRMJobMOppack() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMJobMOppack::initStatements() {
	createStatement("TblWznmRMJobMOppack_insertRec", "INSERT INTO TblWznmRMJobMOppack (refWznmMJob, refWznmMOppack) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMJobMOppack_updateRec", "UPDATE TblWznmRMJobMOppack SET refWznmMJob = $1, refWznmMOppack = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMJobMOppack_removeRecByRef", "DELETE FROM TblWznmRMJobMOppack WHERE ref = $1", 1);

	createStatement("TblWznmRMJobMOppack_loadRecByRef", "SELECT ref, refWznmMJob, refWznmMOppack FROM TblWznmRMJobMOppack WHERE ref = $1", 1);
	createStatement("TblWznmRMJobMOppack_loadJobsByOpk", "SELECT refWznmMJob FROM TblWznmRMJobMOppack WHERE refWznmMOppack = $1", 1);
	createStatement("TblWznmRMJobMOppack_loadOpksByJob", "SELECT refWznmMOppack FROM TblWznmRMJobMOppack WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmRMJobMOppack_loadRefsByJob", "SELECT ref FROM TblWznmRMJobMOppack WHERE refWznmMJob = $1", 1);
};

bool PgTblWznmRMJobMOppack::loadRec(
			PGresult* res
			, WznmRMJobMOppack** rec
		) {
	char* ptr;

	WznmRMJobMOppack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMJobMOppack();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "refwznmmoppack")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMOppack = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMJobMOppack::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMJobMOppack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMJobMOppack* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "refwznmmoppack")
		};

		while (numread < numrow) {
			rec = new WznmRMJobMOppack();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMOppack = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMJobMOppack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMJobMOppack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOppack::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMJobMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMOppack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOppack::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMJobMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMOppack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOppack::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMJobMOppack::insertRec(
			WznmRMJobMOppack* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMJobMOppack_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMOppack::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMJobMOppack::insertRst(
			ListWznmRMJobMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMJobMOppack::updateRec(
			WznmRMJobMOppack* rec
		) {
	PGresult* res;

	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMJob,
		(char*) &_refWznmMOppack,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMJobMOppack_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMJobMOppack::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMJobMOppack::updateRst(
			ListWznmRMJobMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMJobMOppack::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMJobMOppack_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMJobMOppack::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMJobMOppack::loadRecByRef(
			ubigint ref
			, WznmRMJobMOppack** rec
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

	return loadRecByStmt("TblWznmRMJobMOppack_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMJobMOppack::loadJobsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMJobs
		) {
	ubigint _refWznmMOppack = htonl64(refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMJobMOppack_loadJobsByOpk", 1, vals, l, f, append, refWznmMJobs);
};

ubigint PgTblWznmRMJobMOppack::loadOpksByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMJobMOppack_loadOpksByJob", 1, vals, l, f, append, refWznmMOppacks);
};

ubigint PgTblWznmRMJobMOppack::loadRefsByJob(
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

	return loadRefsByStmt("TblWznmRMJobMOppack_loadRefsByJob", 1, vals, l, f, append, refs);
};

#endif

