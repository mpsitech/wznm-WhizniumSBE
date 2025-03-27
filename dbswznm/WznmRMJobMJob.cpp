/**
	* \file WznmRMJobMJob.cpp
	* database access for table TblWznmRMJobMJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMJobMJob.h"

#include "WznmRMJobMJob_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMJobMJob
 ******************************************************************************/

WznmRMJobMJob::WznmRMJobMJob(
			const ubigint ref
			, const ubigint supRefWznmMJob
			, const ubigint subRefWznmMJob
			, const string Short
			, const bool Multi
			, const uint ixVConstract
		) :
			ref(ref)
			, supRefWznmMJob(supRefWznmMJob)
			, subRefWznmMJob(subRefWznmMJob)
			, Short(Short)
			, Multi(Multi)
			, ixVConstract(ixVConstract)
		{
};

bool WznmRMJobMJob::operator==(
			const WznmRMJobMJob& comp
		) {
	return false;
};

bool WznmRMJobMJob::operator!=(
			const WznmRMJobMJob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMJobMJob
 ******************************************************************************/

ListWznmRMJobMJob::ListWznmRMJobMJob() {
};

ListWznmRMJobMJob::ListWznmRMJobMJob(
			const ListWznmRMJobMJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMJobMJob(*(src.nodes[i]));
};

ListWznmRMJobMJob::~ListWznmRMJobMJob() {
	clear();
};

void ListWznmRMJobMJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMJobMJob::size() const {
	return(nodes.size());
};

void ListWznmRMJobMJob::append(
			WznmRMJobMJob* rec
		) {
	nodes.push_back(rec);
};

WznmRMJobMJob* ListWznmRMJobMJob::operator[](
			const uint ix
		) {
	WznmRMJobMJob* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMJobMJob& ListWznmRMJobMJob::operator=(
			const ListWznmRMJobMJob& src
		) {
	WznmRMJobMJob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMJobMJob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMJobMJob::operator==(
			const ListWznmRMJobMJob& comp
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

bool ListWznmRMJobMJob::operator!=(
			const ListWznmRMJobMJob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMJobMJob
 ******************************************************************************/

TblWznmRMJobMJob::TblWznmRMJobMJob() {
};

TblWznmRMJobMJob::~TblWznmRMJobMJob() {
};

bool TblWznmRMJobMJob::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMJob** rec
		) {
	return false;
};

ubigint TblWznmRMJobMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	return 0;
};

ubigint TblWznmRMJobMJob::insertRec(
			WznmRMJobMJob* rec
		) {
	return 0;
};

ubigint TblWznmRMJobMJob::insertNewRec(
			WznmRMJobMJob** rec
			, const ubigint supRefWznmMJob
			, const ubigint subRefWznmMJob
			, const string Short
			, const bool Multi
			, const uint ixVConstract
		) {
	ubigint retval = 0;
	WznmRMJobMJob* _rec = NULL;

	_rec = new WznmRMJobMJob(0, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMJobMJob::appendNewRecToRst(
			ListWznmRMJobMJob& rst
			, WznmRMJobMJob** rec
			, const ubigint supRefWznmMJob
			, const ubigint subRefWznmMJob
			, const string Short
			, const bool Multi
			, const uint ixVConstract
		) {
	ubigint retval = 0;
	WznmRMJobMJob* _rec = NULL;

	retval = insertNewRec(&_rec, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMJobMJob::insertRst(
			ListWznmRMJobMJob& rst
			, bool transact
		) {
};

void TblWznmRMJobMJob::updateRec(
			WznmRMJobMJob* rec
		) {
};

void TblWznmRMJobMJob::updateRst(
			ListWznmRMJobMJob& rst
			, bool transact
		) {
};

void TblWznmRMJobMJob::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMJobMJob::loadRecByRef(
			ubigint ref
			, WznmRMJobMJob** rec
		) {
	return false;
};

ubigint TblWznmRMJobMJob::loadRefsBySup(
			ubigint supRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMJobMJob::loadRstBySub(
			ubigint subRefWznmMJob
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	return 0;
};

ubigint TblWznmRMJobMJob::loadRstBySup(
			ubigint supRefWznmMJob
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	return 0;
};

ubigint TblWznmRMJobMJob::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	ubigint numload = 0;
	WznmRMJobMJob* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMJobMJob
 ******************************************************************************/

MyTblWznmRMJobMJob::MyTblWznmRMJobMJob() :
			TblWznmRMJobMJob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMJobMJob::~MyTblWznmRMJobMJob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMJobMJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMJobMJob (supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMJobMJob SET supRefWznmMJob = ?, subRefWznmMJob = ?, Short = ?, Multi = ?, ixVConstract = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMJobMJob WHERE ref = ?", false);
};

bool MyTblWznmRMJobMJob::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMJob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMJobMJob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMJobMJob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMJobMJob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmRMJobMJob();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->supRefWznmMJob = atoll((char*) dbrow[1]); else _rec->supRefWznmMJob = 0;
		if (dbrow[2]) _rec->subRefWznmMJob = atoll((char*) dbrow[2]); else _rec->subRefWznmMJob = 0;
		if (dbrow[3]) _rec->Short.assign(dbrow[3], dblengths[3]); else _rec->Short = "";
		if (dbrow[4]) _rec->Multi = (atoi((char*) dbrow[4]) != 0); else _rec->Multi = false;
		if (dbrow[5]) _rec->ixVConstract = atol((char*) dbrow[5]); else _rec->ixVConstract = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMJobMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMJobMJob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMJobMJob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMJobMJob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmRMJobMJob();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->supRefWznmMJob = atoll((char*) dbrow[1]); else rec->supRefWznmMJob = 0;
			if (dbrow[2]) rec->subRefWznmMJob = atoll((char*) dbrow[2]); else rec->subRefWznmMJob = 0;
			if (dbrow[3]) rec->Short.assign(dbrow[3], dblengths[3]); else rec->Short = "";
			if (dbrow[4]) rec->Multi = (atoi((char*) dbrow[4]) != 0); else rec->Multi = false;
			if (dbrow[5]) rec->ixVConstract = atol((char*) dbrow[5]); else rec->ixVConstract = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMJobMJob::insertRec(
			WznmRMJobMJob* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Short.length();
	tinyint Multi = rec->Multi;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->subRefWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Short.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Multi,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVConstract,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMJobMJob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMJobMJob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMJobMJob::insertRst(
			ListWznmRMJobMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMJobMJob::updateRec(
			WznmRMJobMJob* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->Short.length();
	tinyint Multi = rec->Multi;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWznmMJob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->subRefWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Short.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Multi,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVConstract,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMJobMJob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMJobMJob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMJobMJob::updateRst(
			ListWznmRMJobMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMJobMJob::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMJobMJob::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMJobMJob::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMJobMJob::loadRecByRef(
			ubigint ref
			, WznmRMJobMJob** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMJobMJob WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMJobMJob::loadRefsBySup(
			ubigint supRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMJobMJob WHERE supRefWznmMJob = " + to_string(supRefWznmMJob) + "", append, refs);
};

ubigint MyTblWznmRMJobMJob::loadRstBySub(
			ubigint subRefWznmMJob
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	return loadRstBySQL("SELECT ref, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract FROM TblWznmRMJobMJob WHERE subRefWznmMJob = " + to_string(subRefWznmMJob) + "", append, rst);
};

ubigint MyTblWznmRMJobMJob::loadRstBySup(
			ubigint supRefWznmMJob
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	return loadRstBySQL("SELECT ref, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract FROM TblWznmRMJobMJob WHERE supRefWznmMJob = " + to_string(supRefWznmMJob) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMJobMJob
 ******************************************************************************/

PgTblWznmRMJobMJob::PgTblWznmRMJobMJob() :
			TblWznmRMJobMJob()
			, PgTable()
		{
};

PgTblWznmRMJobMJob::~PgTblWznmRMJobMJob() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMJobMJob::initStatements() {
	createStatement("TblWznmRMJobMJob_insertRec", "INSERT INTO TblWznmRMJobMJob (supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmRMJobMJob_updateRec", "UPDATE TblWznmRMJobMJob SET supRefWznmMJob = $1, subRefWznmMJob = $2, Short = $3, Multi = $4, ixVConstract = $5 WHERE ref = $6", 6);
	createStatement("TblWznmRMJobMJob_removeRecByRef", "DELETE FROM TblWznmRMJobMJob WHERE ref = $1", 1);

	createStatement("TblWznmRMJobMJob_loadRecByRef", "SELECT ref, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract FROM TblWznmRMJobMJob WHERE ref = $1", 1);
	createStatement("TblWznmRMJobMJob_loadRefsBySup", "SELECT ref FROM TblWznmRMJobMJob WHERE supRefWznmMJob = $1", 1);
	createStatement("TblWznmRMJobMJob_loadRstBySub", "SELECT ref, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract FROM TblWznmRMJobMJob WHERE subRefWznmMJob = $1", 1);
	createStatement("TblWznmRMJobMJob_loadRstBySup", "SELECT ref, supRefWznmMJob, subRefWznmMJob, Short, Multi, ixVConstract FROM TblWznmRMJobMJob WHERE supRefWznmMJob = $1", 1);
};

bool PgTblWznmRMJobMJob::loadRec(
			PGresult* res
			, WznmRMJobMJob** rec
		) {
	char* ptr;

	WznmRMJobMJob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMJobMJob();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwznmmjob"),
			PQfnumber(res, "subrefwznmmjob"),
			PQfnumber(res, "short"),
			PQfnumber(res, "multi"),
			PQfnumber(res, "ixvconstract")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->supRefWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->subRefWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Multi = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVConstract = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMJobMJob::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMJobMJob* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwznmmjob"),
			PQfnumber(res, "subrefwznmmjob"),
			PQfnumber(res, "short"),
			PQfnumber(res, "multi"),
			PQfnumber(res, "ixvconstract")
		};

		while (numread < numrow) {
			rec = new WznmRMJobMJob();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->supRefWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->subRefWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Multi = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVConstract = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMJobMJob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMJobMJob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMJob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMJobMJob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMJob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmRMJobMJob::loadRecBySQL(
			const string& sqlstr
			, WznmRMJobMJob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMJob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMJobMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMJob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMJobMJob::insertRec(
			WznmRMJobMJob* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _supRefWznmMJob = htonl64(rec->supRefWznmMJob);
	ubigint _subRefWznmMJob = htonl64(rec->subRefWznmMJob);
	smallint _Multi = htons((smallint) rec->Multi);
	uint _ixVConstract = htonl(rec->ixVConstract);

	const char* vals[] = {
		(char*) &_supRefWznmMJob,
		(char*) &_subRefWznmMJob,
		rec->Short.c_str(),
		(char*) &_Multi,
		(char*) &_ixVConstract
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMJobMJob_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMJobMJob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMJobMJob::insertRst(
			ListWznmRMJobMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMJobMJob::updateRec(
			WznmRMJobMJob* rec
		) {
	PGresult* res;

	ubigint _supRefWznmMJob = htonl64(rec->supRefWznmMJob);
	ubigint _subRefWznmMJob = htonl64(rec->subRefWznmMJob);
	smallint _Multi = htons((smallint) rec->Multi);
	uint _ixVConstract = htonl(rec->ixVConstract);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_supRefWznmMJob,
		(char*) &_subRefWznmMJob,
		rec->Short.c_str(),
		(char*) &_Multi,
		(char*) &_ixVConstract,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMJobMJob_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMJobMJob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMJobMJob::updateRst(
			ListWznmRMJobMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMJobMJob::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMJobMJob_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMJobMJob::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMJobMJob::loadRecByRef(
			ubigint ref
			, WznmRMJobMJob** rec
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

	return loadRecByStmt("TblWznmRMJobMJob_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMJobMJob::loadRefsBySup(
			ubigint supRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWznmMJob = htonl64(supRefWznmMJob);

	const char* vals[] = {
		(char*) &_supRefWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMJobMJob_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMJobMJob::loadRstBySub(
			ubigint subRefWznmMJob
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	ubigint _subRefWznmMJob = htonl64(subRefWznmMJob);

	const char* vals[] = {
		(char*) &_subRefWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMJobMJob_loadRstBySub", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmRMJobMJob::loadRstBySup(
			ubigint supRefWznmMJob
			, const bool append
			, ListWznmRMJobMJob& rst
		) {
	ubigint _supRefWznmMJob = htonl64(supRefWznmMJob);

	const char* vals[] = {
		(char*) &_supRefWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMJobMJob_loadRstBySup", 1, vals, l, f, append, rst);
};

#endif
