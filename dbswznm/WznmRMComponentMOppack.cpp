/**
	* \file WznmRMComponentMOppack.cpp
	* database access for table TblWznmRMComponentMOppack (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmRMComponentMOppack.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMComponentMOppack
 ******************************************************************************/

WznmRMComponentMOppack::WznmRMComponentMOppack(
			const ubigint ref
			, const ubigint refWznmMComponent
			, const ubigint refWznmMOppack
		) {

	this->ref = ref;
	this->refWznmMComponent = refWznmMComponent;
	this->refWznmMOppack = refWznmMOppack;
};

bool WznmRMComponentMOppack::operator==(
			const WznmRMComponentMOppack& comp
		) {
	return false;
};

bool WznmRMComponentMOppack::operator!=(
			const WznmRMComponentMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMComponentMOppack
 ******************************************************************************/

ListWznmRMComponentMOppack::ListWznmRMComponentMOppack() {
};

ListWznmRMComponentMOppack::ListWznmRMComponentMOppack(
			const ListWznmRMComponentMOppack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMComponentMOppack(*(src.nodes[i]));
};

ListWznmRMComponentMOppack::~ListWznmRMComponentMOppack() {
	clear();
};

void ListWznmRMComponentMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMComponentMOppack::size() const {
	return(nodes.size());
};

void ListWznmRMComponentMOppack::append(
			WznmRMComponentMOppack* rec
		) {
	nodes.push_back(rec);
};

WznmRMComponentMOppack* ListWznmRMComponentMOppack::operator[](
			const uint ix
		) {
	WznmRMComponentMOppack* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMComponentMOppack& ListWznmRMComponentMOppack::operator=(
			const ListWznmRMComponentMOppack& src
		) {
	WznmRMComponentMOppack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMComponentMOppack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMComponentMOppack::operator==(
			const ListWznmRMComponentMOppack& comp
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

bool ListWznmRMComponentMOppack::operator!=(
			const ListWznmRMComponentMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMComponentMOppack
 ******************************************************************************/

TblWznmRMComponentMOppack::TblWznmRMComponentMOppack() {
};

TblWznmRMComponentMOppack::~TblWznmRMComponentMOppack() {
};

bool TblWznmRMComponentMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMComponentMOppack** rec
		) {
	return false;
};

ubigint TblWznmRMComponentMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMComponentMOppack& rst
		) {
	return 0;
};

ubigint TblWznmRMComponentMOppack::insertRec(
			WznmRMComponentMOppack* rec
		) {
	return 0;
};

ubigint TblWznmRMComponentMOppack::insertNewRec(
			WznmRMComponentMOppack** rec
			, const ubigint refWznmMComponent
			, const ubigint refWznmMOppack
		) {
	ubigint retval = 0;
	WznmRMComponentMOppack* _rec = NULL;

	_rec = new WznmRMComponentMOppack(0, refWznmMComponent, refWznmMOppack);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMComponentMOppack::appendNewRecToRst(
			ListWznmRMComponentMOppack& rst
			, WznmRMComponentMOppack** rec
			, const ubigint refWznmMComponent
			, const ubigint refWznmMOppack
		) {
	ubigint retval = 0;
	WznmRMComponentMOppack* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMComponent, refWznmMOppack);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMComponentMOppack::insertRst(
			ListWznmRMComponentMOppack& rst
			, bool transact
		) {
};

void TblWznmRMComponentMOppack::updateRec(
			WznmRMComponentMOppack* rec
		) {
};

void TblWznmRMComponentMOppack::updateRst(
			ListWznmRMComponentMOppack& rst
			, bool transact
		) {
};

void TblWznmRMComponentMOppack::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMComponentMOppack::loadRecByRef(
			ubigint ref
			, WznmRMComponentMOppack** rec
		) {
	return false;
};

ubigint TblWznmRMComponentMOppack::loadCmpsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMComponents
		) {
	return 0;
};

ubigint TblWznmRMComponentMOppack::loadOpksByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	return 0;
};

ubigint TblWznmRMComponentMOppack::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMComponentMOppack::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMComponentMOppack& rst
		) {
	ubigint numload = 0;
	WznmRMComponentMOppack* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMComponentMOppack
 ******************************************************************************/

MyTblWznmRMComponentMOppack::MyTblWznmRMComponentMOppack() :
			TblWznmRMComponentMOppack()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMComponentMOppack::~MyTblWznmRMComponentMOppack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMComponentMOppack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMComponentMOppack (refWznmMComponent, refWznmMOppack) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMComponentMOppack SET refWznmMComponent = ?, refWznmMOppack = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMComponentMOppack WHERE ref = ?", false);
};

bool MyTblWznmRMComponentMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMComponentMOppack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMComponentMOppack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMComponentMOppack::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMComponentMOppack::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMComponentMOppack();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMComponent = atoll((char*) dbrow[1]); else _rec->refWznmMComponent = 0;
		if (dbrow[2]) _rec->refWznmMOppack = atoll((char*) dbrow[2]); else _rec->refWznmMOppack = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMComponentMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMComponentMOppack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMComponentMOppack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMComponentMOppack::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMComponentMOppack::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMComponentMOppack();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMComponent = atoll((char*) dbrow[1]); else rec->refWznmMComponent = 0;
			if (dbrow[2]) rec->refWznmMOppack = atoll((char*) dbrow[2]); else rec->refWznmMOppack = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMComponentMOppack::insertRec(
			WznmRMComponentMOppack* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOppack,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMComponentMOppack::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMComponentMOppack::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMComponentMOppack::insertRst(
			ListWznmRMComponentMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMComponentMOppack::updateRec(
			WznmRMComponentMOppack* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMComponentMOppack::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMComponentMOppack::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMComponentMOppack::updateRst(
			ListWznmRMComponentMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMComponentMOppack::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMComponentMOppack::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMComponentMOppack::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMComponentMOppack::loadRecByRef(
			ubigint ref
			, WznmRMComponentMOppack** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMComponentMOppack WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMComponentMOppack::loadCmpsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMComponents
		) {
	return loadRefsBySQL("SELECT refWznmMComponent FROM TblWznmRMComponentMOppack WHERE refWznmMOppack = " + to_string(refWznmMOppack) + "", append, refWznmMComponents);
};

ubigint MyTblWznmRMComponentMOppack::loadOpksByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	return loadRefsBySQL("SELECT refWznmMOppack FROM TblWznmRMComponentMOppack WHERE refWznmMComponent = " + to_string(refWznmMComponent) + "", append, refWznmMOppacks);
};

ubigint MyTblWznmRMComponentMOppack::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMComponentMOppack WHERE refWznmMOppack = " + to_string(refWznmMOppack) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMComponentMOppack
 ******************************************************************************/

PgTblWznmRMComponentMOppack::PgTblWznmRMComponentMOppack() :
			TblWznmRMComponentMOppack()
			, PgTable()
		{
};

PgTblWznmRMComponentMOppack::~PgTblWznmRMComponentMOppack() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMComponentMOppack::initStatements() {
	createStatement("TblWznmRMComponentMOppack_insertRec", "INSERT INTO TblWznmRMComponentMOppack (refWznmMComponent, refWznmMOppack) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMComponentMOppack_updateRec", "UPDATE TblWznmRMComponentMOppack SET refWznmMComponent = $1, refWznmMOppack = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMComponentMOppack_removeRecByRef", "DELETE FROM TblWznmRMComponentMOppack WHERE ref = $1", 1);

	createStatement("TblWznmRMComponentMOppack_loadRecByRef", "SELECT ref, refWznmMComponent, refWznmMOppack FROM TblWznmRMComponentMOppack WHERE ref = $1", 1);
	createStatement("TblWznmRMComponentMOppack_loadCmpsByOpk", "SELECT refWznmMComponent FROM TblWznmRMComponentMOppack WHERE refWznmMOppack = $1", 1);
	createStatement("TblWznmRMComponentMOppack_loadOpksByCmp", "SELECT refWznmMOppack FROM TblWznmRMComponentMOppack WHERE refWznmMComponent = $1", 1);
	createStatement("TblWznmRMComponentMOppack_loadRefsByOpk", "SELECT ref FROM TblWznmRMComponentMOppack WHERE refWznmMOppack = $1", 1);
};

bool PgTblWznmRMComponentMOppack::loadRec(
			PGresult* res
			, WznmRMComponentMOppack** rec
		) {
	char* ptr;

	WznmRMComponentMOppack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMComponentMOppack();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmoppack")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMComponent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMOppack = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMComponentMOppack::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMComponentMOppack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMComponentMOppack* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmoppack")
		};

		while (numread < numrow) {
			rec = new WznmRMComponentMOppack();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMComponent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMOppack = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMComponentMOppack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMComponentMOppack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMOppack::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMComponentMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmRMComponentMOppack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMOppack::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMComponentMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMComponentMOppack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMOppack::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMComponentMOppack::insertRec(
			WznmRMComponentMOppack* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMComponentMOppack_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMOppack::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMComponentMOppack::insertRst(
			ListWznmRMComponentMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMComponentMOppack::updateRec(
			WznmRMComponentMOppack* rec
		) {
	PGresult* res;

	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMOppack,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMComponentMOppack_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMComponentMOppack::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMComponentMOppack::updateRst(
			ListWznmRMComponentMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMComponentMOppack::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMComponentMOppack_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMComponentMOppack::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMComponentMOppack::loadRecByRef(
			ubigint ref
			, WznmRMComponentMOppack** rec
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

	return loadRecByStmt("TblWznmRMComponentMOppack_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMComponentMOppack::loadCmpsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refWznmMComponents
		) {
	ubigint _refWznmMOppack = htonl64(refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMComponentMOppack_loadCmpsByOpk", 1, vals, l, f, append, refWznmMComponents);
};

ubigint PgTblWznmRMComponentMOppack::loadOpksByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refWznmMOppacks
		) {
	ubigint _refWznmMComponent = htonl64(refWznmMComponent);

	const char* vals[] = {
		(char*) &_refWznmMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMComponentMOppack_loadOpksByCmp", 1, vals, l, f, append, refWznmMOppacks);
};

ubigint PgTblWznmRMComponentMOppack::loadRefsByOpk(
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

	return loadRefsByStmt("TblWznmRMComponentMOppack_loadRefsByOpk", 1, vals, l, f, append, refs);
};

#endif

