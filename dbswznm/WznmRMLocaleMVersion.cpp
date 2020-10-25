/**
	* \file WznmRMLocaleMVersion.cpp
	* database access for table TblWznmRMLocaleMVersion (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmRMLocaleMVersion.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMLocaleMVersion
 ******************************************************************************/

WznmRMLocaleMVersion::WznmRMLocaleMVersion(
			const ubigint ref
			, const ubigint refWznmMLocale
			, const ubigint refWznmMVersion
		) {

	this->ref = ref;
	this->refWznmMLocale = refWznmMLocale;
	this->refWznmMVersion = refWznmMVersion;
};

bool WznmRMLocaleMVersion::operator==(
			const WznmRMLocaleMVersion& comp
		) {
	return false;
};

bool WznmRMLocaleMVersion::operator!=(
			const WznmRMLocaleMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMLocaleMVersion
 ******************************************************************************/

ListWznmRMLocaleMVersion::ListWznmRMLocaleMVersion() {
};

ListWznmRMLocaleMVersion::ListWznmRMLocaleMVersion(
			const ListWznmRMLocaleMVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMLocaleMVersion(*(src.nodes[i]));
};

ListWznmRMLocaleMVersion::~ListWznmRMLocaleMVersion() {
	clear();
};

void ListWznmRMLocaleMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMLocaleMVersion::size() const {
	return(nodes.size());
};

void ListWznmRMLocaleMVersion::append(
			WznmRMLocaleMVersion* rec
		) {
	nodes.push_back(rec);
};

WznmRMLocaleMVersion* ListWznmRMLocaleMVersion::operator[](
			const uint ix
		) {
	WznmRMLocaleMVersion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMLocaleMVersion& ListWznmRMLocaleMVersion::operator=(
			const ListWznmRMLocaleMVersion& src
		) {
	WznmRMLocaleMVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMLocaleMVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMLocaleMVersion::operator==(
			const ListWznmRMLocaleMVersion& comp
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

bool ListWznmRMLocaleMVersion::operator!=(
			const ListWznmRMLocaleMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMLocaleMVersion
 ******************************************************************************/

TblWznmRMLocaleMVersion::TblWznmRMLocaleMVersion() {
};

TblWznmRMLocaleMVersion::~TblWznmRMLocaleMVersion() {
};

bool TblWznmRMLocaleMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmRMLocaleMVersion** rec
		) {
	return false;
};

ubigint TblWznmRMLocaleMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMLocaleMVersion& rst
		) {
	return 0;
};

ubigint TblWznmRMLocaleMVersion::insertRec(
			WznmRMLocaleMVersion* rec
		) {
	return 0;
};

ubigint TblWznmRMLocaleMVersion::insertNewRec(
			WznmRMLocaleMVersion** rec
			, const ubigint refWznmMLocale
			, const ubigint refWznmMVersion
		) {
	ubigint retval = 0;
	WznmRMLocaleMVersion* _rec = NULL;

	_rec = new WznmRMLocaleMVersion(0, refWznmMLocale, refWznmMVersion);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMLocaleMVersion::appendNewRecToRst(
			ListWznmRMLocaleMVersion& rst
			, WznmRMLocaleMVersion** rec
			, const ubigint refWznmMLocale
			, const ubigint refWznmMVersion
		) {
	ubigint retval = 0;
	WznmRMLocaleMVersion* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMLocale, refWznmMVersion);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMLocaleMVersion::insertRst(
			ListWznmRMLocaleMVersion& rst
			, bool transact
		) {
};

void TblWznmRMLocaleMVersion::updateRec(
			WznmRMLocaleMVersion* rec
		) {
};

void TblWznmRMLocaleMVersion::updateRst(
			ListWznmRMLocaleMVersion& rst
			, bool transact
		) {
};

void TblWznmRMLocaleMVersion::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMLocaleMVersion::loadRecByRef(
			ubigint ref
			, WznmRMLocaleMVersion** rec
		) {
	return false;
};

ubigint TblWznmRMLocaleMVersion::loadLocsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refWznmMLocales
		) {
	return 0;
};

ubigint TblWznmRMLocaleMVersion::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMLocaleMVersion::loadVersByLoc(
			ubigint refWznmMLocale
			, const bool append
			, vector<ubigint>& refWznmMVersions
		) {
	return 0;
};

ubigint TblWznmRMLocaleMVersion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMLocaleMVersion& rst
		) {
	ubigint numload = 0;
	WznmRMLocaleMVersion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMLocaleMVersion
 ******************************************************************************/

MyTblWznmRMLocaleMVersion::MyTblWznmRMLocaleMVersion() :
			TblWznmRMLocaleMVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMLocaleMVersion::~MyTblWznmRMLocaleMVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMLocaleMVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMLocaleMVersion (refWznmMLocale, refWznmMVersion) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMLocaleMVersion SET refWznmMLocale = ?, refWznmMVersion = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMLocaleMVersion WHERE ref = ?", false);
};

bool MyTblWznmRMLocaleMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmRMLocaleMVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMLocaleMVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMLocaleMVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMLocaleMVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMLocaleMVersion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMLocale = atoll((char*) dbrow[1]); else _rec->refWznmMLocale = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMLocaleMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMLocaleMVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMLocaleMVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMLocaleMVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMLocaleMVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMLocaleMVersion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMLocale = atoll((char*) dbrow[1]); else rec->refWznmMLocale = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMLocaleMVersion::insertRec(
			WznmRMLocaleMVersion* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLocale,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMLocaleMVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMLocaleMVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMLocaleMVersion::insertRst(
			ListWznmRMLocaleMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMLocaleMVersion::updateRec(
			WznmRMLocaleMVersion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLocale,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMLocaleMVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMLocaleMVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMLocaleMVersion::updateRst(
			ListWznmRMLocaleMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMLocaleMVersion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMLocaleMVersion::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMLocaleMVersion::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMLocaleMVersion::loadRecByRef(
			ubigint ref
			, WznmRMLocaleMVersion** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMLocaleMVersion WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMLocaleMVersion::loadLocsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refWznmMLocales
		) {
	return loadRefsBySQL("SELECT refWznmMLocale FROM TblWznmRMLocaleMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion) + "", append, refWznmMLocales);
};

ubigint MyTblWznmRMLocaleMVersion::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMLocaleMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion) + "", append, refs);
};

ubigint MyTblWznmRMLocaleMVersion::loadVersByLoc(
			ubigint refWznmMLocale
			, const bool append
			, vector<ubigint>& refWznmMVersions
		) {
	return loadRefsBySQL("SELECT refWznmMVersion FROM TblWznmRMLocaleMVersion WHERE refWznmMLocale = " + to_string(refWznmMLocale) + "", append, refWznmMVersions);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMLocaleMVersion
 ******************************************************************************/

PgTblWznmRMLocaleMVersion::PgTblWznmRMLocaleMVersion() :
			TblWznmRMLocaleMVersion()
			, PgTable()
		{
};

PgTblWznmRMLocaleMVersion::~PgTblWznmRMLocaleMVersion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMLocaleMVersion::initStatements() {
	createStatement("TblWznmRMLocaleMVersion_insertRec", "INSERT INTO TblWznmRMLocaleMVersion (refWznmMLocale, refWznmMVersion) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMLocaleMVersion_updateRec", "UPDATE TblWznmRMLocaleMVersion SET refWznmMLocale = $1, refWznmMVersion = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMLocaleMVersion_removeRecByRef", "DELETE FROM TblWznmRMLocaleMVersion WHERE ref = $1", 1);

	createStatement("TblWznmRMLocaleMVersion_loadRecByRef", "SELECT ref, refWznmMLocale, refWznmMVersion FROM TblWznmRMLocaleMVersion WHERE ref = $1", 1);
	createStatement("TblWznmRMLocaleMVersion_loadLocsByVer", "SELECT refWznmMLocale FROM TblWznmRMLocaleMVersion WHERE refWznmMVersion = $1", 1);
	createStatement("TblWznmRMLocaleMVersion_loadRefsByVer", "SELECT ref FROM TblWznmRMLocaleMVersion WHERE refWznmMVersion = $1", 1);
	createStatement("TblWznmRMLocaleMVersion_loadVersByLoc", "SELECT refWznmMVersion FROM TblWznmRMLocaleMVersion WHERE refWznmMLocale = $1", 1);
};

bool PgTblWznmRMLocaleMVersion::loadRec(
			PGresult* res
			, WznmRMLocaleMVersion** rec
		) {
	char* ptr;

	WznmRMLocaleMVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMLocaleMVersion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "refwznmmversion")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMLocaleMVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMLocaleMVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMLocaleMVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "refwznmmversion")
		};

		while (numread < numrow) {
			rec = new WznmRMLocaleMVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMLocaleMVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMLocaleMVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLocaleMVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMLocaleMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmRMLocaleMVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLocaleMVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMLocaleMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMLocaleMVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLocaleMVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMLocaleMVersion::insertRec(
			WznmRMLocaleMVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMLocale,
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMLocaleMVersion_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLocaleMVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMLocaleMVersion::insertRst(
			ListWznmRMLocaleMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMLocaleMVersion::updateRec(
			WznmRMLocaleMVersion* rec
		) {
	PGresult* res;

	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMLocale,
		(char*) &_refWznmMVersion,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMLocaleMVersion_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMLocaleMVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMLocaleMVersion::updateRst(
			ListWznmRMLocaleMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMLocaleMVersion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMLocaleMVersion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMLocaleMVersion::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMLocaleMVersion::loadRecByRef(
			ubigint ref
			, WznmRMLocaleMVersion** rec
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

	return loadRecByStmt("TblWznmRMLocaleMVersion_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMLocaleMVersion::loadLocsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refWznmMLocales
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMLocaleMVersion_loadLocsByVer", 1, vals, l, f, append, refWznmMLocales);
};

ubigint PgTblWznmRMLocaleMVersion::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMLocaleMVersion_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMLocaleMVersion::loadVersByLoc(
			ubigint refWznmMLocale
			, const bool append
			, vector<ubigint>& refWznmMVersions
		) {
	ubigint _refWznmMLocale = htonl64(refWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMLocaleMVersion_loadVersByLoc", 1, vals, l, f, append, refWznmMVersions);
};

#endif

