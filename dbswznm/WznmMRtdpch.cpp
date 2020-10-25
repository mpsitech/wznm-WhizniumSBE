/**
	* \file WznmMRtdpch.cpp
	* database access for table TblWznmMRtdpch (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmMRtdpch.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMRtdpch
 ******************************************************************************/

WznmMRtdpch::WznmMRtdpch(
			const ubigint ref
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMBlock
			, const string sref
			, const bool Merge
		) {

	this->ref = ref;
	this->refWznmMRtjob = refWznmMRtjob;
	this->refWznmMBlock = refWznmMBlock;
	this->sref = sref;
	this->Merge = Merge;
};

bool WznmMRtdpch::operator==(
			const WznmMRtdpch& comp
		) {
	return false;
};

bool WznmMRtdpch::operator!=(
			const WznmMRtdpch& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMRtdpch
 ******************************************************************************/

ListWznmMRtdpch::ListWznmMRtdpch() {
};

ListWznmMRtdpch::ListWznmMRtdpch(
			const ListWznmMRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMRtdpch(*(src.nodes[i]));
};

ListWznmMRtdpch::~ListWznmMRtdpch() {
	clear();
};

void ListWznmMRtdpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMRtdpch::size() const {
	return(nodes.size());
};

void ListWznmMRtdpch::append(
			WznmMRtdpch* rec
		) {
	nodes.push_back(rec);
};

WznmMRtdpch* ListWznmMRtdpch::operator[](
			const uint ix
		) {
	WznmMRtdpch* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMRtdpch& ListWznmMRtdpch::operator=(
			const ListWznmMRtdpch& src
		) {
	WznmMRtdpch* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMRtdpch(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMRtdpch::operator==(
			const ListWznmMRtdpch& comp
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

bool ListWznmMRtdpch::operator!=(
			const ListWznmMRtdpch& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMRtdpch
 ******************************************************************************/

TblWznmMRtdpch::TblWznmMRtdpch() {
};

TblWznmMRtdpch::~TblWznmMRtdpch() {
};

bool TblWznmMRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmMRtdpch** rec
		) {
	return false;
};

ubigint TblWznmMRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	return 0;
};

ubigint TblWznmMRtdpch::insertRec(
			WznmMRtdpch* rec
		) {
	return 0;
};

ubigint TblWznmMRtdpch::insertNewRec(
			WznmMRtdpch** rec
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMBlock
			, const string sref
			, const bool Merge
		) {
	ubigint retval = 0;
	WznmMRtdpch* _rec = NULL;

	_rec = new WznmMRtdpch(0, refWznmMRtjob, refWznmMBlock, sref, Merge);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMRtdpch::appendNewRecToRst(
			ListWznmMRtdpch& rst
			, WznmMRtdpch** rec
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMBlock
			, const string sref
			, const bool Merge
		) {
	ubigint retval = 0;
	WznmMRtdpch* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMRtjob, refWznmMBlock, sref, Merge);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMRtdpch::insertRst(
			ListWznmMRtdpch& rst
			, bool transact
		) {
};

void TblWznmMRtdpch::updateRec(
			WznmMRtdpch* rec
		) {
};

void TblWznmMRtdpch::updateRst(
			ListWznmMRtdpch& rst
			, bool transact
		) {
};

void TblWznmMRtdpch::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMRtdpch::loadRecByRef(
			ubigint ref
			, WznmMRtdpch** rec
		) {
	return false;
};

ubigint TblWznmMRtdpch::loadRefsByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMRtdpch::loadRstByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	return 0;
};

bool TblWznmMRtdpch::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMRtdpch::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	ubigint numload = 0;
	WznmMRtdpch* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMRtdpch
 ******************************************************************************/

MyTblWznmMRtdpch::MyTblWznmMRtdpch() :
			TblWznmMRtdpch()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMRtdpch::~MyTblWznmMRtdpch() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMRtdpch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMRtdpch (refWznmMRtjob, refWznmMBlock, sref, Merge) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMRtdpch SET refWznmMRtjob = ?, refWznmMBlock = ?, sref = ?, Merge = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMRtdpch WHERE ref = ?", false);
};

bool MyTblWznmMRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmMRtdpch** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMRtdpch* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRtdpch::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRtdpch::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMRtdpch();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMRtjob = atoll((char*) dbrow[1]); else _rec->refWznmMRtjob = 0;
		if (dbrow[2]) _rec->refWznmMBlock = atoll((char*) dbrow[2]); else _rec->refWznmMBlock = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Merge = (atoi((char*) dbrow[4]) != 0); else _rec->Merge = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMRtdpch* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRtdpch::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRtdpch::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMRtdpch();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMRtjob = atoll((char*) dbrow[1]); else rec->refWznmMRtjob = 0;
			if (dbrow[2]) rec->refWznmMBlock = atoll((char*) dbrow[2]); else rec->refWznmMBlock = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Merge = (atoi((char*) dbrow[4]) != 0); else rec->Merge = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMRtdpch::insertRec(
			WznmMRtdpch* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	tinyint Merge = rec->Merge;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMRtjob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMBlock,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Merge,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMRtdpch::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMRtdpch::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMRtdpch::insertRst(
			ListWznmMRtdpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMRtdpch::updateRec(
			WznmMRtdpch* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	tinyint Merge = rec->Merge;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMRtjob,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMBlock,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Merge,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMRtdpch::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMRtdpch::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMRtdpch::updateRst(
			ListWznmMRtdpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMRtdpch::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMRtdpch::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMRtdpch::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMRtdpch::loadRecByRef(
			ubigint ref
			, WznmMRtdpch** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMRtdpch WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMRtdpch::loadRefsByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMRtdpch WHERE refWznmMRtjob = " + to_string(refWznmMRtjob) + "", append, refs);
};

ubigint MyTblWznmMRtdpch::loadRstByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMRtjob, refWznmMBlock, sref, Merge FROM TblWznmMRtdpch WHERE refWznmMRtjob = " + to_string(refWznmMRtjob) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMRtdpch::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMRtdpch WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMRtdpch
 ******************************************************************************/

PgTblWznmMRtdpch::PgTblWznmMRtdpch() :
			TblWznmMRtdpch()
			, PgTable()
		{
};

PgTblWznmMRtdpch::~PgTblWznmMRtdpch() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMRtdpch::initStatements() {
	createStatement("TblWznmMRtdpch_insertRec", "INSERT INTO TblWznmMRtdpch (refWznmMRtjob, refWznmMBlock, sref, Merge) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmMRtdpch_updateRec", "UPDATE TblWznmMRtdpch SET refWznmMRtjob = $1, refWznmMBlock = $2, sref = $3, Merge = $4 WHERE ref = $5", 5);
	createStatement("TblWznmMRtdpch_removeRecByRef", "DELETE FROM TblWznmMRtdpch WHERE ref = $1", 1);

	createStatement("TblWznmMRtdpch_loadRecByRef", "SELECT ref, refWznmMRtjob, refWznmMBlock, sref, Merge FROM TblWznmMRtdpch WHERE ref = $1", 1);
	createStatement("TblWznmMRtdpch_loadRefsByRtj", "SELECT ref FROM TblWznmMRtdpch WHERE refWznmMRtjob = $1", 1);
	createStatement("TblWznmMRtdpch_loadRstByRtj", "SELECT ref, refWznmMRtjob, refWznmMBlock, sref, Merge FROM TblWznmMRtdpch WHERE refWznmMRtjob = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMRtdpch_loadSrfByRef", "SELECT sref FROM TblWznmMRtdpch WHERE ref = $1", 1);
};

bool PgTblWznmMRtdpch::loadRec(
			PGresult* res
			, WznmMRtdpch** rec
		) {
	char* ptr;

	WznmMRtdpch* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMRtdpch();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmblock"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "merge")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMBlock = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Merge = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMRtdpch::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMRtdpch* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmblock"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "merge")
		};

		while (numread < numrow) {
			rec = new WznmMRtdpch();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMBlock = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Merge = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMRtdpch::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMRtdpch** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtdpch::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRtdpch::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtdpch::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmMRtdpch** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtdpch::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtdpch::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMRtdpch::insertRec(
			WznmMRtdpch* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMBlock = htonl64(rec->refWznmMBlock);
	smallint _Merge = htons((smallint) rec->Merge);

	const char* vals[] = {
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMBlock,
		rec->sref.c_str(),
		(char*) &_Merge
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMRtdpch_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtdpch::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMRtdpch::insertRst(
			ListWznmMRtdpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMRtdpch::updateRec(
			WznmMRtdpch* rec
		) {
	PGresult* res;

	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMBlock = htonl64(rec->refWznmMBlock);
	smallint _Merge = htons((smallint) rec->Merge);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMBlock,
		rec->sref.c_str(),
		(char*) &_Merge,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMRtdpch_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRtdpch::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMRtdpch::updateRst(
			ListWznmMRtdpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMRtdpch::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMRtdpch_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRtdpch::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMRtdpch::loadRecByRef(
			ubigint ref
			, WznmMRtdpch** rec
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

	return loadRecByStmt("TblWznmMRtdpch_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMRtdpch::loadRefsByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMRtjob = htonl64(refWznmMRtjob);

	const char* vals[] = {
		(char*) &_refWznmMRtjob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMRtdpch_loadRefsByRtj", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMRtdpch::loadRstByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, ListWznmMRtdpch& rst
		) {
	ubigint _refWznmMRtjob = htonl64(refWznmMRtjob);

	const char* vals[] = {
		(char*) &_refWznmMRtjob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRtdpch_loadRstByRtj", 1, vals, l, f, append, rst);
};

bool PgTblWznmMRtdpch::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMRtdpch_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

