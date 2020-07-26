/**
	* \file WznmJAVKeylistKey.cpp
	* database access for table TblWznmJAVKeylistKey (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmJAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJAVKeylistKey
 ******************************************************************************/

WznmJAVKeylistKey::WznmJAVKeylistKey(
			const ubigint ref
			, const ubigint refWznmAVKeylistKey
			, const uint x1IxWznmVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmAVKeylistKey = refWznmAVKeylistKey;
	this->x1IxWznmVLocale = x1IxWznmVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmJAVKeylistKey::operator==(
			const WznmJAVKeylistKey& comp
		) {
	return false;
};

bool WznmJAVKeylistKey::operator!=(
			const WznmJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJAVKeylistKey
 ******************************************************************************/

ListWznmJAVKeylistKey::ListWznmJAVKeylistKey() {
};

ListWznmJAVKeylistKey::ListWznmJAVKeylistKey(
			const ListWznmJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJAVKeylistKey(*(src.nodes[i]));
};

ListWznmJAVKeylistKey::~ListWznmJAVKeylistKey() {
	clear();
};

void ListWznmJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWznmJAVKeylistKey::append(
			WznmJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WznmJAVKeylistKey* ListWznmJAVKeylistKey::operator[](
			const uint ix
		) {
	WznmJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJAVKeylistKey& ListWznmJAVKeylistKey::operator=(
			const ListWznmJAVKeylistKey& src
		) {
	WznmJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJAVKeylistKey::operator==(
			const ListWznmJAVKeylistKey& comp
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

bool ListWznmJAVKeylistKey::operator!=(
			const ListWznmJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJAVKeylistKey
 ******************************************************************************/

TblWznmJAVKeylistKey::TblWznmJAVKeylistKey() {
};

TblWznmJAVKeylistKey::~TblWznmJAVKeylistKey() {
};

bool TblWznmJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WznmJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWznmJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWznmJAVKeylistKey::insertRec(
			WznmJAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWznmJAVKeylistKey::insertNewRec(
			WznmJAVKeylistKey** rec
			, const ubigint refWznmAVKeylistKey
			, const uint x1IxWznmVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmJAVKeylistKey* _rec = NULL;

	_rec = new WznmJAVKeylistKey(0, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJAVKeylistKey::appendNewRecToRst(
			ListWznmJAVKeylistKey& rst
			, WznmJAVKeylistKey** rec
			, const ubigint refWznmAVKeylistKey
			, const uint x1IxWznmVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJAVKeylistKey::insertRst(
			ListWznmJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWznmJAVKeylistKey::updateRec(
			WznmJAVKeylistKey* rec
		) {
};

void TblWznmJAVKeylistKey::updateRst(
			ListWznmJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWznmJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WznmJAVKeylistKey** rec
		) {
	return false;
};

bool TblWznmJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWznmAVKeylistKey
			, uint x1IxWznmVLocale
			, WznmJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWznmJAVKeylistKey::loadRefsByKlk(
			ubigint refWznmAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJAVKeylistKey::loadRstByKlk(
			ubigint refWznmAVKeylistKey
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	return 0;
};

bool TblWznmJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWznmAVKeylistKey
			, uint x1IxWznmVLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WznmJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJAVKeylistKey
 ******************************************************************************/

MyTblWznmJAVKeylistKey::MyTblWznmJAVKeylistKey() :
			TblWznmJAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJAVKeylistKey::~MyTblWznmJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJAVKeylistKey (refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJAVKeylistKey SET refWznmAVKeylistKey = ?, x1IxWznmVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWznmJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WznmJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refWznmAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxWznmVLocale = atol((char*) dbrow[2]); else _rec->x1IxWznmVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmAVKeylistKey = atoll((char*) dbrow[1]); else rec->refWznmAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxWznmVLocale = atol((char*) dbrow[2]); else rec->x1IxWznmVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJAVKeylistKey::insertRec(
			WznmJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJAVKeylistKey::insertRst(
			ListWznmJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJAVKeylistKey::updateRec(
			WznmJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJAVKeylistKey::updateRst(
			ListWznmJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WznmJAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWznmAVKeylistKey
			, uint x1IxWznmVLocale
			, WznmJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = " + to_string(refWznmAVKeylistKey) + " AND x1IxWznmVLocale = " + to_string(x1IxWznmVLocale) + "", rec);
};

ubigint MyTblWznmJAVKeylistKey::loadRefsByKlk(
			ubigint refWznmAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = " + to_string(refWznmAVKeylistKey) + "", append, refs);
};

ubigint MyTblWznmJAVKeylistKey::loadRstByKlk(
			ubigint refWznmAVKeylistKey
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = " + to_string(refWznmAVKeylistKey) + " ORDER BY x1IxWznmVLocale ASC", append, rst);
};

bool MyTblWznmJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWznmAVKeylistKey
			, uint x1IxWznmVLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = " + to_string(refWznmAVKeylistKey) + " AND x1IxWznmVLocale = " + to_string(x1IxWznmVLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJAVKeylistKey
 ******************************************************************************/

PgTblWznmJAVKeylistKey::PgTblWznmJAVKeylistKey() :
			TblWznmJAVKeylistKey()
			, PgTable()
		{
};

PgTblWznmJAVKeylistKey::~PgTblWznmJAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJAVKeylistKey::initStatements() {
	createStatement("TblWznmJAVKeylistKey_insertRec", "INSERT INTO TblWznmJAVKeylistKey (refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmJAVKeylistKey_updateRec", "UPDATE TblWznmJAVKeylistKey SET refWznmAVKeylistKey = $1, x1IxWznmVLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmJAVKeylistKey_removeRecByRef", "DELETE FROM TblWznmJAVKeylistKey WHERE ref = $1", 1);

	createStatement("TblWznmJAVKeylistKey_loadRecByRef", "SELECT ref, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment FROM TblWznmJAVKeylistKey WHERE ref = $1", 1);
	createStatement("TblWznmJAVKeylistKey_loadRecByKlkLcl", "SELECT ref, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = $1 AND x1IxWznmVLocale = $2", 2);
	createStatement("TblWznmJAVKeylistKey_loadRefsByKlk", "SELECT ref FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = $1", 1);
	createStatement("TblWznmJAVKeylistKey_loadRstByKlk", "SELECT ref, refWznmAVKeylistKey, x1IxWznmVLocale, Title, Comment FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = $1 ORDER BY x1IxWznmVLocale ASC", 1);
	createStatement("TblWznmJAVKeylistKey_loadTitByKlkLcl", "SELECT Title FROM TblWznmJAVKeylistKey WHERE refWznmAVKeylistKey = $1 AND x1IxWznmVLocale = $2", 2);
};

bool PgTblWznmJAVKeylistKey::loadRec(
			PGresult* res
			, WznmJAVKeylistKey** rec
		) {
	char* ptr;

	WznmJAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmavkeylistkey"),
			PQfnumber(res, "x1ixwznmvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmAVKeylistKey = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWznmVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmavkeylistkey"),
			PQfnumber(res, "x1ixwznmvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmJAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmAVKeylistKey = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWznmVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WznmJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJAVKeylistKey::insertRec(
			WznmJAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmAVKeylistKey = htonl64(rec->refWznmAVKeylistKey);
	uint _x1IxWznmVLocale = htonl(rec->x1IxWznmVLocale);

	const char* vals[] = {
		(char*) &_refWznmAVKeylistKey,
		(char*) &_x1IxWznmVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmJAVKeylistKey_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJAVKeylistKey::insertRst(
			ListWznmJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJAVKeylistKey::updateRec(
			WznmJAVKeylistKey* rec
		) {
	PGresult* res;

	ubigint _refWznmAVKeylistKey = htonl64(rec->refWznmAVKeylistKey);
	uint _x1IxWznmVLocale = htonl(rec->x1IxWznmVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmAVKeylistKey,
		(char*) &_x1IxWznmVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJAVKeylistKey_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJAVKeylistKey::updateRst(
			ListWznmJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJAVKeylistKey::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WznmJAVKeylistKey** rec
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

	return loadRecByStmt("TblWznmJAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWznmAVKeylistKey
			, uint x1IxWznmVLocale
			, WznmJAVKeylistKey** rec
		) {
	ubigint _refWznmAVKeylistKey = htonl64(refWznmAVKeylistKey);
	uint _x1IxWznmVLocale = htonl(x1IxWznmVLocale);

	const char* vals[] = {
		(char*) &_refWznmAVKeylistKey,
		(char*) &_x1IxWznmVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJAVKeylistKey_loadRecByKlkLcl", 2, vals, l, f, rec);
};

ubigint PgTblWznmJAVKeylistKey::loadRefsByKlk(
			ubigint refWznmAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmAVKeylistKey = htonl64(refWznmAVKeylistKey);

	const char* vals[] = {
		(char*) &_refWznmAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJAVKeylistKey_loadRefsByKlk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJAVKeylistKey::loadRstByKlk(
			ubigint refWznmAVKeylistKey
			, const bool append
			, ListWznmJAVKeylistKey& rst
		) {
	ubigint _refWznmAVKeylistKey = htonl64(refWznmAVKeylistKey);

	const char* vals[] = {
		(char*) &_refWznmAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJAVKeylistKey_loadRstByKlk", 1, vals, l, f, append, rst);
};

bool PgTblWznmJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWznmAVKeylistKey
			, uint x1IxWznmVLocale
			, string& Title
		) {
	ubigint _refWznmAVKeylistKey = htonl64(refWznmAVKeylistKey);
	uint _x1IxWznmVLocale = htonl(x1IxWznmVLocale);

	const char* vals[] = {
		(char*) &_refWznmAVKeylistKey,
		(char*) &_x1IxWznmVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJAVKeylistKey_loadTitByKlkLcl", 2, vals, l, f, Title);
};

#endif

