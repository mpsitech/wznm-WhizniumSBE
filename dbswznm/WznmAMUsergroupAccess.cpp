/**
	* \file WznmAMUsergroupAccess.cpp
	* database access for table TblWznmAMUsergroupAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMUsergroupAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMUsergroupAccess
 ******************************************************************************/

WznmAMUsergroupAccess::WznmAMUsergroupAccess(
			const ubigint ref
			, const ubigint refWznmMUsergroup
			, const uint x1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
		) :
			ref(ref)
			, refWznmMUsergroup(refWznmMUsergroup)
			, x1IxWznmVFeatgroup(x1IxWznmVFeatgroup)
			, x2FeaSrefUix(x2FeaSrefUix)
			, ixWznmWAccess(ixWznmWAccess)
		{
};

bool WznmAMUsergroupAccess::operator==(
			const WznmAMUsergroupAccess& comp
		) {
	return false;
};

bool WznmAMUsergroupAccess::operator!=(
			const WznmAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMUsergroupAccess
 ******************************************************************************/

ListWznmAMUsergroupAccess::ListWznmAMUsergroupAccess() {
};

ListWznmAMUsergroupAccess::ListWznmAMUsergroupAccess(
			const ListWznmAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMUsergroupAccess(*(src.nodes[i]));
};

ListWznmAMUsergroupAccess::~ListWznmAMUsergroupAccess() {
	clear();
};

void ListWznmAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListWznmAMUsergroupAccess::append(
			WznmAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

WznmAMUsergroupAccess* ListWznmAMUsergroupAccess::operator[](
			const uint ix
		) {
	WznmAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMUsergroupAccess& ListWznmAMUsergroupAccess::operator=(
			const ListWznmAMUsergroupAccess& src
		) {
	WznmAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMUsergroupAccess::operator==(
			const ListWznmAMUsergroupAccess& comp
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

bool ListWznmAMUsergroupAccess::operator!=(
			const ListWznmAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMUsergroupAccess
 ******************************************************************************/

TblWznmAMUsergroupAccess::TblWznmAMUsergroupAccess() {
};

TblWznmAMUsergroupAccess::~TblWznmAMUsergroupAccess() {
};

bool TblWznmAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WznmAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWznmAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWznmAMUsergroupAccess::insertRec(
			WznmAMUsergroupAccess* rec
		) {
	return 0;
};

ubigint TblWznmAMUsergroupAccess::insertNewRec(
			WznmAMUsergroupAccess** rec
			, const ubigint refWznmMUsergroup
			, const uint x1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
		) {
	ubigint retval = 0;
	WznmAMUsergroupAccess* _rec = NULL;

	_rec = new WznmAMUsergroupAccess(0, refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMUsergroupAccess::appendNewRecToRst(
			ListWznmAMUsergroupAccess& rst
			, WznmAMUsergroupAccess** rec
			, const ubigint refWznmMUsergroup
			, const uint x1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
		) {
	ubigint retval = 0;
	WznmAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMUsergroupAccess::insertRst(
			ListWznmAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWznmAMUsergroupAccess::updateRec(
			WznmAMUsergroupAccess* rec
		) {
};

void TblWznmAMUsergroupAccess::updateRst(
			ListWznmAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWznmAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WznmAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWznmAMUsergroupAccess::loadRefsByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMUsergroupAccess::loadRstByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWznmAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	WznmAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMUsergroupAccess
 ******************************************************************************/

MyTblWznmAMUsergroupAccess::MyTblWznmAMUsergroupAccess() :
			TblWznmAMUsergroupAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMUsergroupAccess::~MyTblWznmAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMUsergroupAccess (refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMUsergroupAccess SET refWznmMUsergroup = ?, x1IxWznmVFeatgroup = ?, x2FeaSrefUix = ?, ixWznmWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblWznmAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WznmAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMUsergroupAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMUsergroupAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUsergroup = atoll((char*) dbrow[1]); else _rec->refWznmMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxWznmVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWznmVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWznmWAccess = atol((char*) dbrow[4]); else _rec->ixWznmWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMUsergroupAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMUsergroupAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUsergroup = atoll((char*) dbrow[1]); else rec->refWznmMUsergroup = 0;
			if (dbrow[2]) rec->x1IxWznmVFeatgroup = atol((char*) dbrow[2]); else rec->x1IxWznmVFeatgroup = 0;
			if (dbrow[3]) rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else rec->x2FeaSrefUix = "";
			if (dbrow[4]) rec->ixWznmWAccess = atol((char*) dbrow[4]); else rec->ixWznmWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMUsergroupAccess::insertRec(
			WznmAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMUsergroupAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMUsergroupAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMUsergroupAccess::insertRst(
			ListWznmAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMUsergroupAccess::updateRec(
			WznmAMUsergroupAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMUsergroupAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMUsergroupAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMUsergroupAccess::updateRst(
			ListWznmAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMUsergroupAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMUsergroupAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WznmAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMUsergroupAccess::loadRefsByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMUsergroupAccess WHERE refWznmMUsergroup = " + to_string(refWznmMUsergroup) + "", append, refs);
};

ubigint MyTblWznmAMUsergroupAccess::loadRstByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmAMUsergroupAccess WHERE refWznmMUsergroup = " + to_string(refWznmMUsergroup) + " ORDER BY x1IxWznmVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMUsergroupAccess
 ******************************************************************************/

PgTblWznmAMUsergroupAccess::PgTblWznmAMUsergroupAccess() :
			TblWznmAMUsergroupAccess()
			, PgTable()
		{
};

PgTblWznmAMUsergroupAccess::~PgTblWznmAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMUsergroupAccess::initStatements() {
	createStatement("TblWznmAMUsergroupAccess_insertRec", "INSERT INTO TblWznmAMUsergroupAccess (refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMUsergroupAccess_updateRec", "UPDATE TblWznmAMUsergroupAccess SET refWznmMUsergroup = $1, x1IxWznmVFeatgroup = $2, x2FeaSrefUix = $3, ixWznmWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMUsergroupAccess_removeRecByRef", "DELETE FROM TblWznmAMUsergroupAccess WHERE ref = $1", 1);

	createStatement("TblWznmAMUsergroupAccess_loadRecByRef", "SELECT ref, refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmAMUsergroupAccess WHERE ref = $1", 1);
	createStatement("TblWznmAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblWznmAMUsergroupAccess WHERE refWznmMUsergroup = $1", 1);
	createStatement("TblWznmAMUsergroupAccess_loadRstByUsg", "SELECT ref, refWznmMUsergroup, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmAMUsergroupAccess WHERE refWznmMUsergroup = $1 ORDER BY x1IxWznmVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblWznmAMUsergroupAccess::loadRec(
			PGresult* res
			, WznmAMUsergroupAccess** rec
		) {
	char* ptr;

	WznmAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "x1ixwznmvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwznmwaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWznmVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "x1ixwznmvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwznmwaccess")
		};

		while (numread < numrow) {
			rec = new WznmAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWznmVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWznmWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMUsergroupAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WznmAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMUsergroupAccess::insertRec(
			WznmAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _x1IxWznmVFeatgroup = htonl(rec->x1IxWznmVFeatgroup);
	uint _ixWznmWAccess = htonl(rec->ixWznmWAccess);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup,
		(char*) &_x1IxWznmVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWznmWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMUsergroupAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMUsergroupAccess::insertRst(
			ListWznmAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMUsergroupAccess::updateRec(
			WznmAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _x1IxWznmVFeatgroup = htonl(rec->x1IxWznmVFeatgroup);
	uint _ixWznmWAccess = htonl(rec->ixWznmWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup,
		(char*) &_x1IxWznmVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWznmWAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAMUsergroupAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMUsergroupAccess::updateRst(
			ListWznmAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMUsergroupAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WznmAMUsergroupAccess** rec
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

	return loadRecByStmt("TblWznmAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMUsergroupAccess::loadRefsByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMUsergroup = htonl64(refWznmMUsergroup);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMUsergroupAccess::loadRstByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, ListWznmAMUsergroupAccess& rst
		) {
	ubigint _refWznmMUsergroup = htonl64(refWznmMUsergroup);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMUsergroupAccess_loadRstByUsg", 1, vals, l, f, append, rst);
};

#endif
