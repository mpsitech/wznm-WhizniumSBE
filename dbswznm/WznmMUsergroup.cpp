/**
	* \file WznmMUsergroup.cpp
	* database access for table TblWznmMUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMUsergroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMUsergroup
 ******************************************************************************/

WznmMUsergroup::WznmMUsergroup(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmMUsergroup::operator==(
			const WznmMUsergroup& comp
		) {
	return false;
};

bool WznmMUsergroup::operator!=(
			const WznmMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMUsergroup
 ******************************************************************************/

ListWznmMUsergroup::ListWznmMUsergroup() {
};

ListWznmMUsergroup::ListWznmMUsergroup(
			const ListWznmMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMUsergroup(*(src.nodes[i]));
};

ListWznmMUsergroup::~ListWznmMUsergroup() {
	clear();
};

void ListWznmMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMUsergroup::size() const {
	return(nodes.size());
};

void ListWznmMUsergroup::append(
			WznmMUsergroup* rec
		) {
	nodes.push_back(rec);
};

WznmMUsergroup* ListWznmMUsergroup::operator[](
			const uint ix
		) {
	WznmMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMUsergroup& ListWznmMUsergroup::operator=(
			const ListWznmMUsergroup& src
		) {
	WznmMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMUsergroup::operator==(
			const ListWznmMUsergroup& comp
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

bool ListWznmMUsergroup::operator!=(
			const ListWznmMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMUsergroup
 ******************************************************************************/

TblWznmMUsergroup::TblWznmMUsergroup() {
};

TblWznmMUsergroup::~TblWznmMUsergroup() {
};

bool TblWznmMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmMUsergroup** rec
		) {
	return false;
};

ubigint TblWznmMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMUsergroup& rst
		) {
	return 0;
};

ubigint TblWznmMUsergroup::insertRec(
			WznmMUsergroup* rec
		) {
	return 0;
};

ubigint TblWznmMUsergroup::insertNewRec(
			WznmMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMUsergroup* _rec = NULL;

	_rec = new WznmMUsergroup(0, grp, own, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMUsergroup::appendNewRecToRst(
			ListWznmMUsergroup& rst
			, WznmMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMUsergroup::insertRst(
			ListWznmMUsergroup& rst
			, bool transact
		) {
};

void TblWznmMUsergroup::updateRec(
			WznmMUsergroup* rec
		) {
};

void TblWznmMUsergroup::updateRst(
			ListWznmMUsergroup& rst
			, bool transact
		) {
};

void TblWznmMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMUsergroup::loadRecByRef(
			ubigint ref
			, WznmMUsergroup** rec
		) {
	return false;
};

bool TblWznmMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWznmMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMUsergroup& rst
		) {
	ubigint numload = 0;
	WznmMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMUsergroup
 ******************************************************************************/

MyTblWznmMUsergroup::MyTblWznmMUsergroup() :
			TblWznmMUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMUsergroup::~MyTblWznmMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMUsergroup (grp, own, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMUsergroup SET grp = ?, own = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMUsergroup WHERE ref = ?", false);
};

bool MyTblWznmMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMUsergroup::insertRec(
			WznmMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMUsergroup::insertRst(
			ListWznmMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMUsergroup::updateRec(
			WznmMUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMUsergroup::updateRst(
			ListWznmMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMUsergroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMUsergroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMUsergroup::loadRecByRef(
			ubigint ref
			, WznmMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMUsergroup WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMUsergroup WHERE sref = '" + sref + "'", ref);
};

bool MyTblWznmMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMUsergroup WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMUsergroup
 ******************************************************************************/

PgTblWznmMUsergroup::PgTblWznmMUsergroup() :
			TblWznmMUsergroup()
			, PgTable()
		{
};

PgTblWznmMUsergroup::~PgTblWznmMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMUsergroup::initStatements() {
	createStatement("TblWznmMUsergroup_insertRec", "INSERT INTO TblWznmMUsergroup (grp, own, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmMUsergroup_updateRec", "UPDATE TblWznmMUsergroup SET grp = $1, own = $2, sref = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmMUsergroup_removeRecByRef", "DELETE FROM TblWznmMUsergroup WHERE ref = $1", 1);

	createStatement("TblWznmMUsergroup_loadRecByRef", "SELECT ref, grp, own, sref, Comment FROM TblWznmMUsergroup WHERE ref = $1", 1);
	createStatement("TblWznmMUsergroup_loadRefBySrf", "SELECT ref FROM TblWznmMUsergroup WHERE sref = $1", 1);
	createStatement("TblWznmMUsergroup_loadSrfByRef", "SELECT sref FROM TblWznmMUsergroup WHERE ref = $1", 1);
};

bool PgTblWznmMUsergroup::loadRec(
			PGresult* res
			, WznmMUsergroup** rec
		) {
	char* ptr;

	WznmMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUsergroup::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUsergroup::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUsergroup::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMUsergroup::insertRec(
			WznmMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMUsergroup_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUsergroup::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMUsergroup::insertRst(
			ListWznmMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMUsergroup::updateRec(
			WznmMUsergroup* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMUsergroup_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMUsergroup::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMUsergroup::updateRst(
			ListWznmMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMUsergroup::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMUsergroup::loadRecByRef(
			ubigint ref
			, WznmMUsergroup** rec
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

	return loadRecByStmt("TblWznmMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWznmMUsergroup_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblWznmMUsergroup::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMUsergroup_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
