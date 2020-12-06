/**
	* \file WznmAMMachineMakefile.cpp
	* database access for table TblWznmAMMachineMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMMachineMakefile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMMachineMakefile
 ******************************************************************************/

WznmAMMachineMakefile::WznmAMMachineMakefile(
			const ubigint ref
			, const ubigint refWznmMMachine
			, const string x1SrefKTag
			, const string Val
		) {

	this->ref = ref;
	this->refWznmMMachine = refWznmMMachine;
	this->x1SrefKTag = x1SrefKTag;
	this->Val = Val;
};

bool WznmAMMachineMakefile::operator==(
			const WznmAMMachineMakefile& comp
		) {
	return false;
};

bool WznmAMMachineMakefile::operator!=(
			const WznmAMMachineMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMMachineMakefile
 ******************************************************************************/

ListWznmAMMachineMakefile::ListWznmAMMachineMakefile() {
};

ListWznmAMMachineMakefile::ListWznmAMMachineMakefile(
			const ListWznmAMMachineMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMMachineMakefile(*(src.nodes[i]));
};

ListWznmAMMachineMakefile::~ListWznmAMMachineMakefile() {
	clear();
};

void ListWznmAMMachineMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMMachineMakefile::size() const {
	return(nodes.size());
};

void ListWznmAMMachineMakefile::append(
			WznmAMMachineMakefile* rec
		) {
	nodes.push_back(rec);
};

WznmAMMachineMakefile* ListWznmAMMachineMakefile::operator[](
			const uint ix
		) {
	WznmAMMachineMakefile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMMachineMakefile& ListWznmAMMachineMakefile::operator=(
			const ListWznmAMMachineMakefile& src
		) {
	WznmAMMachineMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMMachineMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMMachineMakefile::operator==(
			const ListWznmAMMachineMakefile& comp
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

bool ListWznmAMMachineMakefile::operator!=(
			const ListWznmAMMachineMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMMachineMakefile
 ******************************************************************************/

TblWznmAMMachineMakefile::TblWznmAMMachineMakefile() {
};

TblWznmAMMachineMakefile::~TblWznmAMMachineMakefile() {
};

bool TblWznmAMMachineMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachineMakefile** rec
		) {
	return false;
};

ubigint TblWznmAMMachineMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	return 0;
};

ubigint TblWznmAMMachineMakefile::insertRec(
			WznmAMMachineMakefile* rec
		) {
	return 0;
};

ubigint TblWznmAMMachineMakefile::insertNewRec(
			WznmAMMachineMakefile** rec
			, const ubigint refWznmMMachine
			, const string x1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMMachineMakefile* _rec = NULL;

	_rec = new WznmAMMachineMakefile(0, refWznmMMachine, x1SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMMachineMakefile::appendNewRecToRst(
			ListWznmAMMachineMakefile& rst
			, WznmAMMachineMakefile** rec
			, const ubigint refWznmMMachine
			, const string x1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMMachineMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMMachine, x1SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMMachineMakefile::insertRst(
			ListWznmAMMachineMakefile& rst
			, bool transact
		) {
};

void TblWznmAMMachineMakefile::updateRec(
			WznmAMMachineMakefile* rec
		) {
};

void TblWznmAMMachineMakefile::updateRst(
			ListWznmAMMachineMakefile& rst
			, bool transact
		) {
};

void TblWznmAMMachineMakefile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMMachineMakefile::loadRecByRef(
			ubigint ref
			, WznmAMMachineMakefile** rec
		) {
	return false;
};

ubigint TblWznmAMMachineMakefile::loadRefsByMch(
			ubigint refWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMMachineMakefile::loadRstByMch(
			ubigint refWznmMMachine
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	return 0;
};

bool TblWznmAMMachineMakefile::loadValByMchTag(
			ubigint refWznmMMachine
			, string x1SrefKTag
			, string& Val
		) {
	return false;
};

ubigint TblWznmAMMachineMakefile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	ubigint numload = 0;
	WznmAMMachineMakefile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMMachineMakefile
 ******************************************************************************/

MyTblWznmAMMachineMakefile::MyTblWznmAMMachineMakefile() :
			TblWznmAMMachineMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMMachineMakefile::~MyTblWznmAMMachineMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMMachineMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMMachineMakefile (refWznmMMachine, x1SrefKTag, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMMachineMakefile SET refWznmMMachine = ?, x1SrefKTag = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMMachineMakefile WHERE ref = ?", false);
};

bool MyTblWznmAMMachineMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachineMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMMachineMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMachineMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMachineMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMMachineMakefile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMMachine = atoll((char*) dbrow[1]); else _rec->refWznmMMachine = 0;
		if (dbrow[2]) _rec->x1SrefKTag.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKTag = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMMachineMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMMachineMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMachineMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMachineMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMMachineMakefile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMMachine = atoll((char*) dbrow[1]); else rec->refWznmMMachine = 0;
			if (dbrow[2]) rec->x1SrefKTag.assign(dbrow[2], dblengths[2]); else rec->x1SrefKTag = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMMachineMakefile::insertRec(
			WznmAMMachineMakefile* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKTag.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMMachineMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMMachineMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMMachineMakefile::insertRst(
			ListWznmAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMMachineMakefile::updateRec(
			WznmAMMachineMakefile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKTag.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMMachineMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMMachineMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMMachineMakefile::updateRst(
			ListWznmAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMMachineMakefile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMMachineMakefile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMMachineMakefile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMMachineMakefile::loadRecByRef(
			ubigint ref
			, WznmAMMachineMakefile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMMachineMakefile WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMMachineMakefile::loadRefsByMch(
			ubigint refWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMMachineMakefile WHERE refWznmMMachine = " + to_string(refWznmMMachine) + "", append, refs);
};

ubigint MyTblWznmAMMachineMakefile::loadRstByMch(
			ubigint refWznmMMachine
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMMachine, x1SrefKTag, Val FROM TblWznmAMMachineMakefile WHERE refWznmMMachine = " + to_string(refWznmMMachine) + " ORDER BY x1SrefKTag ASC", append, rst);
};

bool MyTblWznmAMMachineMakefile::loadValByMchTag(
			ubigint refWznmMMachine
			, string x1SrefKTag
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWznmAMMachineMakefile WHERE refWznmMMachine = " + to_string(refWznmMMachine) + " AND x1SrefKTag = '" + x1SrefKTag + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMMachineMakefile
 ******************************************************************************/

PgTblWznmAMMachineMakefile::PgTblWznmAMMachineMakefile() :
			TblWznmAMMachineMakefile()
			, PgTable()
		{
};

PgTblWznmAMMachineMakefile::~PgTblWznmAMMachineMakefile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMMachineMakefile::initStatements() {
	createStatement("TblWznmAMMachineMakefile_insertRec", "INSERT INTO TblWznmAMMachineMakefile (refWznmMMachine, x1SrefKTag, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmAMMachineMakefile_updateRec", "UPDATE TblWznmAMMachineMakefile SET refWznmMMachine = $1, x1SrefKTag = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWznmAMMachineMakefile_removeRecByRef", "DELETE FROM TblWznmAMMachineMakefile WHERE ref = $1", 1);

	createStatement("TblWznmAMMachineMakefile_loadRecByRef", "SELECT ref, refWznmMMachine, x1SrefKTag, Val FROM TblWznmAMMachineMakefile WHERE ref = $1", 1);
	createStatement("TblWznmAMMachineMakefile_loadRefsByMch", "SELECT ref FROM TblWznmAMMachineMakefile WHERE refWznmMMachine = $1", 1);
	createStatement("TblWznmAMMachineMakefile_loadRstByMch", "SELECT ref, refWznmMMachine, x1SrefKTag, Val FROM TblWznmAMMachineMakefile WHERE refWznmMMachine = $1 ORDER BY x1SrefKTag ASC", 1);
	createStatement("TblWznmAMMachineMakefile_loadValByMchTag", "SELECT Val FROM TblWznmAMMachineMakefile WHERE refWznmMMachine = $1 AND x1SrefKTag = $2", 2);
};

bool PgTblWznmAMMachineMakefile::loadRec(
			PGresult* res
			, WznmAMMachineMakefile** rec
		) {
	char* ptr;

	WznmAMMachineMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMMachineMakefile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachine"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMMachineMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMMachineMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachine"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAMMachineMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMMachineMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMMachineMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMachineMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMMachineMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachineMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMachineMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMMachineMakefile::insertRec(
			WznmAMMachineMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine,
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMMachineMakefile_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMMachineMakefile::insertRst(
			ListWznmAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMMachineMakefile::updateRec(
			WznmAMMachineMakefile* rec
		) {
	PGresult* res;

	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMMachine,
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMMachineMakefile_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMMachineMakefile::updateRst(
			ListWznmAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMMachineMakefile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMMachineMakefile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMachineMakefile::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMMachineMakefile::loadRecByRef(
			ubigint ref
			, WznmAMMachineMakefile** rec
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

	return loadRecByStmt("TblWznmAMMachineMakefile_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMMachineMakefile::loadRefsByMch(
			ubigint refWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMMachine = htonl64(refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMMachineMakefile_loadRefsByMch", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMMachineMakefile::loadRstByMch(
			ubigint refWznmMMachine
			, const bool append
			, ListWznmAMMachineMakefile& rst
		) {
	ubigint _refWznmMMachine = htonl64(refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMMachineMakefile_loadRstByMch", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMMachineMakefile::loadValByMchTag(
			ubigint refWznmMMachine
			, string x1SrefKTag
			, string& Val
		) {
	ubigint _refWznmMMachine = htonl64(refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMMachine,
		x1SrefKTag.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadStringByStmt("TblWznmAMMachineMakefile_loadValByMchTag", 2, vals, l, f, Val);
};

#endif
