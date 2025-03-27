/**
	* \file WznmMVisual.cpp
	* database access for table TblWznmMVisual (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmMVisual.h"

#include "WznmMVisual_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMVisual
 ******************************************************************************/

WznmMVisual::WznmMVisual(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string Comment
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, ixVBasetype(ixVBasetype)
			, verRefWznmMVersion(verRefWznmMVersion)
			, verNum(verNum)
			, Comment(Comment)
		{
};

bool WznmMVisual::operator==(
			const WznmMVisual& comp
		) {
	return false;
};

bool WznmMVisual::operator!=(
			const WznmMVisual& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMVisual
 ******************************************************************************/

ListWznmMVisual::ListWznmMVisual() {
};

ListWznmMVisual::ListWznmMVisual(
			const ListWznmMVisual& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMVisual(*(src.nodes[i]));
};

ListWznmMVisual::~ListWznmMVisual() {
	clear();
};

void ListWznmMVisual::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMVisual::size() const {
	return(nodes.size());
};

void ListWznmMVisual::append(
			WznmMVisual* rec
		) {
	nodes.push_back(rec);
};

WznmMVisual* ListWznmMVisual::operator[](
			const uint ix
		) {
	WznmMVisual* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMVisual& ListWznmMVisual::operator=(
			const ListWznmMVisual& src
		) {
	WznmMVisual* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMVisual(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMVisual::operator==(
			const ListWznmMVisual& comp
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

bool ListWznmMVisual::operator!=(
			const ListWznmMVisual& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMVisual
 ******************************************************************************/

TblWznmMVisual::TblWznmMVisual() {
};

TblWznmMVisual::~TblWznmMVisual() {
};

bool TblWznmMVisual::loadRecBySQL(
			const string& sqlstr
			, WznmMVisual** rec
		) {
	return false;
};

ubigint TblWznmMVisual::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVisual& rst
		) {
	return 0;
};

ubigint TblWznmMVisual::insertRec(
			WznmMVisual* rec
		) {
	return 0;
};

ubigint TblWznmMVisual::insertNewRec(
			WznmMVisual** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMVisual* _rec = NULL;

	_rec = new WznmMVisual(0, grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMVisual::appendNewRecToRst(
			ListWznmMVisual& rst
			, WznmMVisual** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMVisual* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMVisual::insertRst(
			ListWznmMVisual& rst
			, bool transact
		) {
};

void TblWznmMVisual::updateRec(
			WznmMVisual* rec
		) {
};

void TblWznmMVisual::updateRst(
			ListWznmMVisual& rst
			, bool transact
		) {
};

void TblWznmMVisual::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMVisual::loadRecByRef(
			ubigint ref
			, WznmMVisual** rec
		) {
	return false;
};

ubigint TblWznmMVisual::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMVisual& rst
		) {
	return 0;
};

ubigint TblWznmMVisual::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMVisual& rst
		) {
	ubigint numload = 0;
	WznmMVisual* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMVisual
 ******************************************************************************/

MyTblWznmMVisual::MyTblWznmMVisual() :
			TblWznmMVisual()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMVisual::~MyTblWznmMVisual() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMVisual::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMVisual (grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMVisual SET grp = ?, own = ?, ixVBasetype = ?, verRefWznmMVersion = ?, verNum = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMVisual WHERE ref = ?", false);
};

bool MyTblWznmMVisual::loadRecBySQL(
			const string& sqlstr
			, WznmMVisual** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMVisual* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVisual::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVisual::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMVisual();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixVBasetype = atol((char*) dbrow[3]); else _rec->ixVBasetype = 0;
		if (dbrow[4]) _rec->verRefWznmMVersion = atoll((char*) dbrow[4]); else _rec->verRefWznmMVersion = 0;
		if (dbrow[5]) _rec->verNum = atol((char*) dbrow[5]); else _rec->verNum = 0;
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMVisual::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVisual& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMVisual* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVisual::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVisual::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMVisual();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixVBasetype = atol((char*) dbrow[3]); else rec->ixVBasetype = 0;
			if (dbrow[4]) rec->verRefWznmMVersion = atoll((char*) dbrow[4]); else rec->verRefWznmMVersion = 0;
			if (dbrow[5]) rec->verNum = atol((char*) dbrow[5]); else rec->verNum = 0;
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMVisual::insertRec(
			WznmMVisual* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->verNum,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMVisual::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMVisual::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMVisual::insertRst(
			ListWznmMVisual& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMVisual::updateRec(
			WznmMVisual* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->verNum,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMVisual::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMVisual::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMVisual::updateRst(
			ListWznmMVisual& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMVisual::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMVisual::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMVisual::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMVisual::loadRecByRef(
			ubigint ref
			, WznmMVisual** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMVisual WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMVisual::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMVisual& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment FROM TblWznmMVisual WHERE verRefWznmMVersion = " + to_string(verRefWznmMVersion) + " ORDER BY verNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMVisual
 ******************************************************************************/

PgTblWznmMVisual::PgTblWznmMVisual() :
			TblWznmMVisual()
			, PgTable()
		{
};

PgTblWznmMVisual::~PgTblWznmMVisual() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMVisual::initStatements() {
	createStatement("TblWznmMVisual_insertRec", "INSERT INTO TblWznmMVisual (grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWznmMVisual_updateRec", "UPDATE TblWznmMVisual SET grp = $1, own = $2, ixVBasetype = $3, verRefWznmMVersion = $4, verNum = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWznmMVisual_removeRecByRef", "DELETE FROM TblWznmMVisual WHERE ref = $1", 1);

	createStatement("TblWznmMVisual_loadRecByRef", "SELECT ref, grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment FROM TblWznmMVisual WHERE ref = $1", 1);
	createStatement("TblWznmMVisual_loadRstByVer", "SELECT ref, grp, own, ixVBasetype, verRefWznmMVersion, verNum, Comment FROM TblWznmMVisual WHERE verRefWznmMVersion = $1 ORDER BY verNum ASC", 1);
};

bool PgTblWznmMVisual::loadRec(
			PGresult* res
			, WznmMVisual** rec
		) {
	char* ptr;

	WznmMVisual* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMVisual();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->verRefWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->verNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMVisual::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMVisual& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMVisual* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMVisual();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->verRefWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->verNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMVisual::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMVisual** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVisual::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVisual::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMVisual& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVisual::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMVisual::loadRecBySQL(
			const string& sqlstr
			, WznmMVisual** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVisual::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVisual::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVisual& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVisual::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMVisual::insertRec(
			WznmMVisual* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMVisual_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVisual::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMVisual::insertRst(
			ListWznmMVisual& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMVisual::updateRec(
			WznmMVisual* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMVisual_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVisual::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMVisual::updateRst(
			ListWznmMVisual& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMVisual::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMVisual_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVisual::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMVisual::loadRecByRef(
			ubigint ref
			, WznmMVisual** rec
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

	return loadRecByStmt("TblWznmMVisual_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMVisual::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMVisual& rst
		) {
	ubigint _verRefWznmMVersion = htonl64(verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMVisual_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif
