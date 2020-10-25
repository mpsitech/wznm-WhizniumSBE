/**
	* \file WznmAMMachtypeMakefile.cpp
	* database access for table TblWznmAMMachtypeMakefile (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAMMachtypeMakefile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMMachtypeMakefile
 ******************************************************************************/

WznmAMMachtypeMakefile::WznmAMMachtypeMakefile(
			const ubigint ref
			, const ubigint refWznmMMachtype
			, const string x1SrefKTag
			, const string Val
		) {

	this->ref = ref;
	this->refWznmMMachtype = refWznmMMachtype;
	this->x1SrefKTag = x1SrefKTag;
	this->Val = Val;
};

bool WznmAMMachtypeMakefile::operator==(
			const WznmAMMachtypeMakefile& comp
		) {
	return false;
};

bool WznmAMMachtypeMakefile::operator!=(
			const WznmAMMachtypeMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMMachtypeMakefile
 ******************************************************************************/

ListWznmAMMachtypeMakefile::ListWznmAMMachtypeMakefile() {
};

ListWznmAMMachtypeMakefile::ListWznmAMMachtypeMakefile(
			const ListWznmAMMachtypeMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMMachtypeMakefile(*(src.nodes[i]));
};

ListWznmAMMachtypeMakefile::~ListWznmAMMachtypeMakefile() {
	clear();
};

void ListWznmAMMachtypeMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMMachtypeMakefile::size() const {
	return(nodes.size());
};

void ListWznmAMMachtypeMakefile::append(
			WznmAMMachtypeMakefile* rec
		) {
	nodes.push_back(rec);
};

WznmAMMachtypeMakefile* ListWznmAMMachtypeMakefile::operator[](
			const uint ix
		) {
	WznmAMMachtypeMakefile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMMachtypeMakefile& ListWznmAMMachtypeMakefile::operator=(
			const ListWznmAMMachtypeMakefile& src
		) {
	WznmAMMachtypeMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMMachtypeMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMMachtypeMakefile::operator==(
			const ListWznmAMMachtypeMakefile& comp
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

bool ListWznmAMMachtypeMakefile::operator!=(
			const ListWznmAMMachtypeMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMMachtypeMakefile
 ******************************************************************************/

TblWznmAMMachtypeMakefile::TblWznmAMMachtypeMakefile() {
};

TblWznmAMMachtypeMakefile::~TblWznmAMMachtypeMakefile() {
};

bool TblWznmAMMachtypeMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachtypeMakefile** rec
		) {
	return false;
};

ubigint TblWznmAMMachtypeMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	return 0;
};

ubigint TblWznmAMMachtypeMakefile::insertRec(
			WznmAMMachtypeMakefile* rec
		) {
	return 0;
};

ubigint TblWznmAMMachtypeMakefile::insertNewRec(
			WznmAMMachtypeMakefile** rec
			, const ubigint refWznmMMachtype
			, const string x1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMMachtypeMakefile* _rec = NULL;

	_rec = new WznmAMMachtypeMakefile(0, refWznmMMachtype, x1SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMMachtypeMakefile::appendNewRecToRst(
			ListWznmAMMachtypeMakefile& rst
			, WznmAMMachtypeMakefile** rec
			, const ubigint refWznmMMachtype
			, const string x1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMMachtypeMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMMachtype, x1SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMMachtypeMakefile::insertRst(
			ListWznmAMMachtypeMakefile& rst
			, bool transact
		) {
};

void TblWznmAMMachtypeMakefile::updateRec(
			WznmAMMachtypeMakefile* rec
		) {
};

void TblWznmAMMachtypeMakefile::updateRst(
			ListWznmAMMachtypeMakefile& rst
			, bool transact
		) {
};

void TblWznmAMMachtypeMakefile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMMachtypeMakefile::loadRecByRef(
			ubigint ref
			, WznmAMMachtypeMakefile** rec
		) {
	return false;
};

ubigint TblWznmAMMachtypeMakefile::loadRefsByMty(
			ubigint refWznmMMachtype
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMMachtypeMakefile::loadRstByMty(
			ubigint refWznmMMachtype
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	return 0;
};

bool TblWznmAMMachtypeMakefile::loadValByMtyTag(
			ubigint refWznmMMachtype
			, string x1SrefKTag
			, string& Val
		) {
	return false;
};

ubigint TblWznmAMMachtypeMakefile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	ubigint numload = 0;
	WznmAMMachtypeMakefile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMMachtypeMakefile
 ******************************************************************************/

MyTblWznmAMMachtypeMakefile::MyTblWznmAMMachtypeMakefile() :
			TblWznmAMMachtypeMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMMachtypeMakefile::~MyTblWznmAMMachtypeMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMMachtypeMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMMachtypeMakefile (refWznmMMachtype, x1SrefKTag, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMMachtypeMakefile SET refWznmMMachtype = ?, x1SrefKTag = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMMachtypeMakefile WHERE ref = ?", false);
};

bool MyTblWznmAMMachtypeMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachtypeMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMMachtypeMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMachtypeMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMachtypeMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMMachtypeMakefile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMMachtype = atoll((char*) dbrow[1]); else _rec->refWznmMMachtype = 0;
		if (dbrow[2]) _rec->x1SrefKTag.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKTag = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMMachtypeMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMMachtypeMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMachtypeMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMachtypeMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMMachtypeMakefile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMMachtype = atoll((char*) dbrow[1]); else rec->refWznmMMachtype = 0;
			if (dbrow[2]) rec->x1SrefKTag.assign(dbrow[2], dblengths[2]); else rec->x1SrefKTag = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMMachtypeMakefile::insertRec(
			WznmAMMachtypeMakefile* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKTag.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachtype,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMMachtypeMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMMachtypeMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMMachtypeMakefile::insertRst(
			ListWznmAMMachtypeMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMMachtypeMakefile::updateRec(
			WznmAMMachtypeMakefile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKTag.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMMachtype,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMMachtypeMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMMachtypeMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMMachtypeMakefile::updateRst(
			ListWznmAMMachtypeMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMMachtypeMakefile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMMachtypeMakefile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMMachtypeMakefile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMMachtypeMakefile::loadRecByRef(
			ubigint ref
			, WznmAMMachtypeMakefile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMMachtypeMakefile WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMMachtypeMakefile::loadRefsByMty(
			ubigint refWznmMMachtype
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMMachtypeMakefile WHERE refWznmMMachtype = " + to_string(refWznmMMachtype) + "", append, refs);
};

ubigint MyTblWznmAMMachtypeMakefile::loadRstByMty(
			ubigint refWznmMMachtype
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMMachtype, x1SrefKTag, Val FROM TblWznmAMMachtypeMakefile WHERE refWznmMMachtype = " + to_string(refWznmMMachtype) + " ORDER BY x1SrefKTag ASC", append, rst);
};

bool MyTblWznmAMMachtypeMakefile::loadValByMtyTag(
			ubigint refWznmMMachtype
			, string x1SrefKTag
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWznmAMMachtypeMakefile WHERE refWznmMMachtype = " + to_string(refWznmMMachtype) + " AND x1SrefKTag = '" + x1SrefKTag + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMMachtypeMakefile
 ******************************************************************************/

PgTblWznmAMMachtypeMakefile::PgTblWznmAMMachtypeMakefile() :
			TblWznmAMMachtypeMakefile()
			, PgTable()
		{
};

PgTblWznmAMMachtypeMakefile::~PgTblWznmAMMachtypeMakefile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMMachtypeMakefile::initStatements() {
	createStatement("TblWznmAMMachtypeMakefile_insertRec", "INSERT INTO TblWznmAMMachtypeMakefile (refWznmMMachtype, x1SrefKTag, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmAMMachtypeMakefile_updateRec", "UPDATE TblWznmAMMachtypeMakefile SET refWznmMMachtype = $1, x1SrefKTag = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWznmAMMachtypeMakefile_removeRecByRef", "DELETE FROM TblWznmAMMachtypeMakefile WHERE ref = $1", 1);

	createStatement("TblWznmAMMachtypeMakefile_loadRecByRef", "SELECT ref, refWznmMMachtype, x1SrefKTag, Val FROM TblWznmAMMachtypeMakefile WHERE ref = $1", 1);
	createStatement("TblWznmAMMachtypeMakefile_loadRefsByMty", "SELECT ref FROM TblWznmAMMachtypeMakefile WHERE refWznmMMachtype = $1", 1);
	createStatement("TblWznmAMMachtypeMakefile_loadRstByMty", "SELECT ref, refWznmMMachtype, x1SrefKTag, Val FROM TblWznmAMMachtypeMakefile WHERE refWznmMMachtype = $1 ORDER BY x1SrefKTag ASC", 1);
	createStatement("TblWznmAMMachtypeMakefile_loadValByMtyTag", "SELECT Val FROM TblWznmAMMachtypeMakefile WHERE refWznmMMachtype = $1 AND x1SrefKTag = $2", 2);
};

bool PgTblWznmAMMachtypeMakefile::loadRec(
			PGresult* res
			, WznmAMMachtypeMakefile** rec
		) {
	char* ptr;

	WznmAMMachtypeMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMMachtypeMakefile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachtype"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMMachtype = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMMachtypeMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMMachtypeMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmmachtype"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAMMachtypeMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMMachtype = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMMachtypeMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMMachtypeMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMachtypeMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMMachtypeMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMMachtypeMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMachtypeMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMMachtypeMakefile::insertRec(
			WznmAMMachtypeMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMMachtype = htonl64(rec->refWznmMMachtype);

	const char* vals[] = {
		(char*) &_refWznmMMachtype,
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMMachtypeMakefile_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMMachtypeMakefile::insertRst(
			ListWznmAMMachtypeMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMMachtypeMakefile::updateRec(
			WznmAMMachtypeMakefile* rec
		) {
	PGresult* res;

	ubigint _refWznmMMachtype = htonl64(rec->refWznmMMachtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMMachtype,
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

	res = PQexecPrepared(dbs, "TblWznmAMMachtypeMakefile_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMMachtypeMakefile::updateRst(
			ListWznmAMMachtypeMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMMachtypeMakefile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMMachtypeMakefile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMachtypeMakefile::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMMachtypeMakefile::loadRecByRef(
			ubigint ref
			, WznmAMMachtypeMakefile** rec
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

	return loadRecByStmt("TblWznmAMMachtypeMakefile_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMMachtypeMakefile::loadRefsByMty(
			ubigint refWznmMMachtype
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMMachtype = htonl64(refWznmMMachtype);

	const char* vals[] = {
		(char*) &_refWznmMMachtype
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMMachtypeMakefile_loadRefsByMty", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMMachtypeMakefile::loadRstByMty(
			ubigint refWznmMMachtype
			, const bool append
			, ListWznmAMMachtypeMakefile& rst
		) {
	ubigint _refWznmMMachtype = htonl64(refWznmMMachtype);

	const char* vals[] = {
		(char*) &_refWznmMMachtype
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMMachtypeMakefile_loadRstByMty", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMMachtypeMakefile::loadValByMtyTag(
			ubigint refWznmMMachtype
			, string x1SrefKTag
			, string& Val
		) {
	ubigint _refWznmMMachtype = htonl64(refWznmMMachtype);

	const char* vals[] = {
		(char*) &_refWznmMMachtype,
		x1SrefKTag.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadStringByStmt("TblWznmAMMachtypeMakefile_loadValByMtyTag", 2, vals, l, f, Val);
};

#endif

