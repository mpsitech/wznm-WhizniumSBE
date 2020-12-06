/**
	* \file WznmAMUserAccess.cpp
	* database access for table TblWznmAMUserAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMUserAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMUserAccess
 ******************************************************************************/

WznmAMUserAccess::WznmAMUserAccess(
			const ubigint ref
			, const ubigint refWznmMUser
			, const uint x1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
		) {

	this->ref = ref;
	this->refWznmMUser = refWznmMUser;
	this->x1IxWznmVFeatgroup = x1IxWznmVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWznmWAccess = ixWznmWAccess;
};

bool WznmAMUserAccess::operator==(
			const WznmAMUserAccess& comp
		) {
	return false;
};

bool WznmAMUserAccess::operator!=(
			const WznmAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMUserAccess
 ******************************************************************************/

ListWznmAMUserAccess::ListWznmAMUserAccess() {
};

ListWznmAMUserAccess::ListWznmAMUserAccess(
			const ListWznmAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMUserAccess(*(src.nodes[i]));
};

ListWznmAMUserAccess::~ListWznmAMUserAccess() {
	clear();
};

void ListWznmAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMUserAccess::size() const {
	return(nodes.size());
};

void ListWznmAMUserAccess::append(
			WznmAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

WznmAMUserAccess* ListWznmAMUserAccess::operator[](
			const uint ix
		) {
	WznmAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMUserAccess& ListWznmAMUserAccess::operator=(
			const ListWznmAMUserAccess& src
		) {
	WznmAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMUserAccess::operator==(
			const ListWznmAMUserAccess& comp
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

bool ListWznmAMUserAccess::operator!=(
			const ListWznmAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMUserAccess
 ******************************************************************************/

TblWznmAMUserAccess::TblWznmAMUserAccess() {
};

TblWznmAMUserAccess::~TblWznmAMUserAccess() {
};

bool TblWznmAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WznmAMUserAccess** rec
		) {
	return false;
};

ubigint TblWznmAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWznmAMUserAccess::insertRec(
			WznmAMUserAccess* rec
		) {
	return 0;
};

ubigint TblWznmAMUserAccess::insertNewRec(
			WznmAMUserAccess** rec
			, const ubigint refWznmMUser
			, const uint x1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
		) {
	ubigint retval = 0;
	WznmAMUserAccess* _rec = NULL;

	_rec = new WznmAMUserAccess(0, refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMUserAccess::appendNewRecToRst(
			ListWznmAMUserAccess& rst
			, WznmAMUserAccess** rec
			, const ubigint refWznmMUser
			, const uint x1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
		) {
	ubigint retval = 0;
	WznmAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMUserAccess::insertRst(
			ListWznmAMUserAccess& rst
			, bool transact
		) {
};

void TblWznmAMUserAccess::updateRec(
			WznmAMUserAccess* rec
		) {
};

void TblWznmAMUserAccess::updateRst(
			ListWznmAMUserAccess& rst
			, bool transact
		) {
};

void TblWznmAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMUserAccess::loadRecByRef(
			ubigint ref
			, WznmAMUserAccess** rec
		) {
	return false;
};

ubigint TblWznmAMUserAccess::loadRefsByUsr(
			ubigint refWznmMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMUserAccess::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWznmAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	ubigint numload = 0;
	WznmAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMUserAccess
 ******************************************************************************/

MyTblWznmAMUserAccess::MyTblWznmAMUserAccess() :
			TblWznmAMUserAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMUserAccess::~MyTblWznmAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMUserAccess (refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMUserAccess SET refWznmMUser = ?, x1IxWznmVFeatgroup = ?, x2FeaSrefUix = ?, ixWznmWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMUserAccess WHERE ref = ?", false);
};

bool MyTblWznmAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WznmAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMUserAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMUserAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMUser = atoll((char*) dbrow[1]); else _rec->refWznmMUser = 0;
		if (dbrow[2]) _rec->x1IxWznmVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWznmVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWznmWAccess = atol((char*) dbrow[4]); else _rec->ixWznmWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMUserAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMUserAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMUser = atoll((char*) dbrow[1]); else rec->refWznmMUser = 0;
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

ubigint MyTblWznmAMUserAccess::insertRec(
			WznmAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMUserAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMUserAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMUserAccess::insertRst(
			ListWznmAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMUserAccess::updateRec(
			WznmAMUserAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMUserAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMUserAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMUserAccess::updateRst(
			ListWznmAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMUserAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMUserAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMUserAccess::loadRecByRef(
			ubigint ref
			, WznmAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMUserAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMUserAccess::loadRefsByUsr(
			ubigint refWznmMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMUserAccess WHERE refWznmMUser = " + to_string(refWznmMUser) + "", append, refs);
};

ubigint MyTblWznmAMUserAccess::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmAMUserAccess WHERE refWznmMUser = " + to_string(refWznmMUser) + " ORDER BY x1IxWznmVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMUserAccess
 ******************************************************************************/

PgTblWznmAMUserAccess::PgTblWznmAMUserAccess() :
			TblWznmAMUserAccess()
			, PgTable()
		{
};

PgTblWznmAMUserAccess::~PgTblWznmAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMUserAccess::initStatements() {
	createStatement("TblWznmAMUserAccess_insertRec", "INSERT INTO TblWznmAMUserAccess (refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMUserAccess_updateRec", "UPDATE TblWznmAMUserAccess SET refWznmMUser = $1, x1IxWznmVFeatgroup = $2, x2FeaSrefUix = $3, ixWznmWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMUserAccess_removeRecByRef", "DELETE FROM TblWznmAMUserAccess WHERE ref = $1", 1);

	createStatement("TblWznmAMUserAccess_loadRecByRef", "SELECT ref, refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmAMUserAccess WHERE ref = $1", 1);
	createStatement("TblWznmAMUserAccess_loadRefsByUsr", "SELECT ref FROM TblWznmAMUserAccess WHERE refWznmMUser = $1", 1);
	createStatement("TblWznmAMUserAccess_loadRstByUsr", "SELECT ref, refWznmMUser, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmAMUserAccess WHERE refWznmMUser = $1 ORDER BY x1IxWznmVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblWznmAMUserAccess::loadRec(
			PGresult* res
			, WznmAMUserAccess** rec
		) {
	char* ptr;

	WznmAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "x1ixwznmvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwznmwaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWznmVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmuser"),
			PQfnumber(res, "x1ixwznmvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwznmwaccess")
		};

		while (numread < numrow) {
			rec = new WznmAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMUser = atoll(ptr);
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

bool PgTblWznmAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUserAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMUserAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUserAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WznmAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUserAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUserAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMUserAccess::insertRec(
			WznmAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _x1IxWznmVFeatgroup = htonl(rec->x1IxWznmVFeatgroup);
	uint _ixWznmWAccess = htonl(rec->ixWznmWAccess);

	const char* vals[] = {
		(char*) &_refWznmMUser,
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

	res = PQexecPrepared(dbs, "TblWznmAMUserAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMUserAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMUserAccess::insertRst(
			ListWznmAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMUserAccess::updateRec(
			WznmAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refWznmMUser = htonl64(rec->refWznmMUser);
	uint _x1IxWznmVFeatgroup = htonl(rec->x1IxWznmVFeatgroup);
	uint _ixWznmWAccess = htonl(rec->ixWznmWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMUser,
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

	res = PQexecPrepared(dbs, "TblWznmAMUserAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMUserAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMUserAccess::updateRst(
			ListWznmAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMUserAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMUserAccess::loadRecByRef(
			ubigint ref
			, WznmAMUserAccess** rec
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

	return loadRecByStmt("TblWznmAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMUserAccess::loadRefsByUsr(
			ubigint refWznmMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);

	const char* vals[] = {
		(char*) &_refWznmMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMUserAccess_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMUserAccess::loadRstByUsr(
			ubigint refWznmMUser
			, const bool append
			, ListWznmAMUserAccess& rst
		) {
	ubigint _refWznmMUser = htonl64(refWznmMUser);

	const char* vals[] = {
		(char*) &_refWznmMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMUserAccess_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif
