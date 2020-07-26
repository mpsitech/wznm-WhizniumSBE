/**
	* \file WznmRMLibraryMOppack.cpp
	* database access for table TblWznmRMLibraryMOppack (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmRMLibraryMOppack.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMLibraryMOppack
 ******************************************************************************/

WznmRMLibraryMOppack::WznmRMLibraryMOppack(
			const ubigint ref
			, const ubigint refWznmMLibrary
			, const ubigint refWznmMOppack
		) {

	this->ref = ref;
	this->refWznmMLibrary = refWznmMLibrary;
	this->refWznmMOppack = refWznmMOppack;
};

bool WznmRMLibraryMOppack::operator==(
			const WznmRMLibraryMOppack& comp
		) {
	return false;
};

bool WznmRMLibraryMOppack::operator!=(
			const WznmRMLibraryMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMLibraryMOppack
 ******************************************************************************/

ListWznmRMLibraryMOppack::ListWznmRMLibraryMOppack() {
};

ListWznmRMLibraryMOppack::ListWznmRMLibraryMOppack(
			const ListWznmRMLibraryMOppack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMLibraryMOppack(*(src.nodes[i]));
};

ListWznmRMLibraryMOppack::~ListWznmRMLibraryMOppack() {
	clear();
};

void ListWznmRMLibraryMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMLibraryMOppack::size() const {
	return(nodes.size());
};

void ListWznmRMLibraryMOppack::append(
			WznmRMLibraryMOppack* rec
		) {
	nodes.push_back(rec);
};

WznmRMLibraryMOppack* ListWznmRMLibraryMOppack::operator[](
			const uint ix
		) {
	WznmRMLibraryMOppack* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMLibraryMOppack& ListWznmRMLibraryMOppack::operator=(
			const ListWznmRMLibraryMOppack& src
		) {
	WznmRMLibraryMOppack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMLibraryMOppack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMLibraryMOppack::operator==(
			const ListWznmRMLibraryMOppack& comp
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

bool ListWznmRMLibraryMOppack::operator!=(
			const ListWznmRMLibraryMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMLibraryMOppack
 ******************************************************************************/

TblWznmRMLibraryMOppack::TblWznmRMLibraryMOppack() {
};

TblWznmRMLibraryMOppack::~TblWznmRMLibraryMOppack() {
};

bool TblWznmRMLibraryMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMLibraryMOppack** rec
		) {
	return false;
};

ubigint TblWznmRMLibraryMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMLibraryMOppack& rst
		) {
	return 0;
};

ubigint TblWznmRMLibraryMOppack::insertRec(
			WznmRMLibraryMOppack* rec
		) {
	return 0;
};

ubigint TblWznmRMLibraryMOppack::insertNewRec(
			WznmRMLibraryMOppack** rec
			, const ubigint refWznmMLibrary
			, const ubigint refWznmMOppack
		) {
	ubigint retval = 0;
	WznmRMLibraryMOppack* _rec = NULL;

	_rec = new WznmRMLibraryMOppack(0, refWznmMLibrary, refWznmMOppack);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMLibraryMOppack::appendNewRecToRst(
			ListWznmRMLibraryMOppack& rst
			, WznmRMLibraryMOppack** rec
			, const ubigint refWznmMLibrary
			, const ubigint refWznmMOppack
		) {
	ubigint retval = 0;
	WznmRMLibraryMOppack* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMLibrary, refWznmMOppack);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMLibraryMOppack::insertRst(
			ListWznmRMLibraryMOppack& rst
			, bool transact
		) {
};

void TblWznmRMLibraryMOppack::updateRec(
			WznmRMLibraryMOppack* rec
		) {
};

void TblWznmRMLibraryMOppack::updateRst(
			ListWznmRMLibraryMOppack& rst
			, bool transact
		) {
};

void TblWznmRMLibraryMOppack::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMLibraryMOppack::loadRecByRef(
			ubigint ref
			, WznmRMLibraryMOppack** rec
		) {
	return false;
};

ubigint TblWznmRMLibraryMOppack::loadLibsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMLibrarys
		) {
	return 0;
};

ubigint TblWznmRMLibraryMOppack::loadOpksByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	return 0;
};

ubigint TblWznmRMLibraryMOppack::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMLibraryMOppack::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMLibraryMOppack& rst
		) {
	ubigint numload = 0;
	WznmRMLibraryMOppack* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMLibraryMOppack
 ******************************************************************************/

MyTblWznmRMLibraryMOppack::MyTblWznmRMLibraryMOppack() :
			TblWznmRMLibraryMOppack()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMLibraryMOppack::~MyTblWznmRMLibraryMOppack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMLibraryMOppack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMLibraryMOppack (refWznmMLibrary, refWznmMOppack) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMLibraryMOppack SET refWznmMLibrary = ?, refWznmMOppack = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMLibraryMOppack WHERE ref = ?", false);
};

bool MyTblWznmRMLibraryMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMLibraryMOppack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMLibraryMOppack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMLibraryMOppack::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMLibraryMOppack::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMLibraryMOppack();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMLibrary = atoll((char*) dbrow[1]); else _rec->refWznmMLibrary = 0;
		if (dbrow[2]) _rec->refWznmMOppack = atoll((char*) dbrow[2]); else _rec->refWznmMOppack = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMLibraryMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMLibraryMOppack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMLibraryMOppack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMLibraryMOppack::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMLibraryMOppack::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMLibraryMOppack();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMLibrary = atoll((char*) dbrow[1]); else rec->refWznmMLibrary = 0;
			if (dbrow[2]) rec->refWznmMOppack = atoll((char*) dbrow[2]); else rec->refWznmMOppack = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMLibraryMOppack::insertRec(
			WznmRMLibraryMOppack* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOppack,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMLibraryMOppack::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMLibraryMOppack::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMLibraryMOppack::insertRst(
			ListWznmRMLibraryMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMLibraryMOppack::updateRec(
			WznmRMLibraryMOppack* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMLibraryMOppack::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMLibraryMOppack::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMLibraryMOppack::updateRst(
			ListWznmRMLibraryMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMLibraryMOppack::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMLibraryMOppack::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMLibraryMOppack::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMLibraryMOppack::loadRecByRef(
			ubigint ref
			, WznmRMLibraryMOppack** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMLibraryMOppack WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMLibraryMOppack::loadLibsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMLibrarys
		) {
	return loadRefsBySQL("SELECT refWznmMLibrary FROM TblWznmRMLibraryMOppack WHERE refWznmMOppack = " + to_string(refWznmMOppack) + "", append, refWznmMLibrarys);
};

ubigint MyTblWznmRMLibraryMOppack::loadOpksByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	return loadRefsBySQL("SELECT refWznmMOppack FROM TblWznmRMLibraryMOppack WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + "", append, refWznmMOppacks);
};

ubigint MyTblWznmRMLibraryMOppack::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMLibraryMOppack WHERE refWznmMOppack = " + to_string(refWznmMOppack) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMLibraryMOppack
 ******************************************************************************/

PgTblWznmRMLibraryMOppack::PgTblWznmRMLibraryMOppack() :
			TblWznmRMLibraryMOppack()
			, PgTable()
		{
};

PgTblWznmRMLibraryMOppack::~PgTblWznmRMLibraryMOppack() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMLibraryMOppack::initStatements() {
	createStatement("TblWznmRMLibraryMOppack_insertRec", "INSERT INTO TblWznmRMLibraryMOppack (refWznmMLibrary, refWznmMOppack) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMLibraryMOppack_updateRec", "UPDATE TblWznmRMLibraryMOppack SET refWznmMLibrary = $1, refWznmMOppack = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMLibraryMOppack_removeRecByRef", "DELETE FROM TblWznmRMLibraryMOppack WHERE ref = $1", 1);

	createStatement("TblWznmRMLibraryMOppack_loadRecByRef", "SELECT ref, refWznmMLibrary, refWznmMOppack FROM TblWznmRMLibraryMOppack WHERE ref = $1", 1);
	createStatement("TblWznmRMLibraryMOppack_loadLibsByOpk", "SELECT refWznmMLibrary FROM TblWznmRMLibraryMOppack WHERE refWznmMOppack = $1", 1);
	createStatement("TblWznmRMLibraryMOppack_loadOpksByLib", "SELECT refWznmMOppack FROM TblWznmRMLibraryMOppack WHERE refWznmMLibrary = $1", 1);
	createStatement("TblWznmRMLibraryMOppack_loadRefsByOpk", "SELECT ref FROM TblWznmRMLibraryMOppack WHERE refWznmMOppack = $1", 1);
};

bool PgTblWznmRMLibraryMOppack::loadRec(
			PGresult* res
			, WznmRMLibraryMOppack** rec
		) {
	char* ptr;

	WznmRMLibraryMOppack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMLibraryMOppack();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlibrary"),
			PQfnumber(res, "refwznmmoppack")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMLibrary = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMOppack = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMLibraryMOppack::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMLibraryMOppack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMLibraryMOppack* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlibrary"),
			PQfnumber(res, "refwznmmoppack")
		};

		while (numread < numrow) {
			rec = new WznmRMLibraryMOppack();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMLibrary = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMOppack = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMLibraryMOppack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMLibraryMOppack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLibraryMOppack::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMLibraryMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMLibraryMOppack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLibraryMOppack::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMLibraryMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMLibraryMOppack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLibraryMOppack::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMLibraryMOppack::insertRec(
			WznmRMLibraryMOppack* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMLibrary = htonl64(rec->refWznmMLibrary);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMLibrary,
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMLibraryMOppack_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMLibraryMOppack::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMLibraryMOppack::insertRst(
			ListWznmRMLibraryMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMLibraryMOppack::updateRec(
			WznmRMLibraryMOppack* rec
		) {
	PGresult* res;

	ubigint _refWznmMLibrary = htonl64(rec->refWznmMLibrary);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMLibrary,
		(char*) &_refWznmMOppack,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMLibraryMOppack_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMLibraryMOppack::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMLibraryMOppack::updateRst(
			ListWznmRMLibraryMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMLibraryMOppack::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMLibraryMOppack_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMLibraryMOppack::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMLibraryMOppack::loadRecByRef(
			ubigint ref
			, WznmRMLibraryMOppack** rec
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

	return loadRecByStmt("TblWznmRMLibraryMOppack_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMLibraryMOppack::loadLibsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMLibrarys
		) {
	ubigint _refWznmMOppack = htonl64(refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMLibraryMOppack_loadLibsByOpk", 1, vals, l, f, append, refWznmMLibrarys);
};

ubigint PgTblWznmRMLibraryMOppack::loadOpksByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);

	const char* vals[] = {
		(char*) &_refWznmMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMLibraryMOppack_loadOpksByLib", 1, vals, l, f, append, refWznmMOppacks);
};

ubigint PgTblWznmRMLibraryMOppack::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMOppack = htonl64(refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMLibraryMOppack_loadRefsByOpk", 1, vals, l, f, append, refs);
};

#endif

