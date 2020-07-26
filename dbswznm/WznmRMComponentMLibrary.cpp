/**
	* \file WznmRMComponentMLibrary.cpp
	* database access for table TblWznmRMComponentMLibrary (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmRMComponentMLibrary.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMComponentMLibrary
 ******************************************************************************/

WznmRMComponentMLibrary::WznmRMComponentMLibrary(
			const ubigint ref
			, const ubigint refWznmMComponent
			, const ubigint refWznmMLibrary
		) {

	this->ref = ref;
	this->refWznmMComponent = refWznmMComponent;
	this->refWznmMLibrary = refWznmMLibrary;
};

bool WznmRMComponentMLibrary::operator==(
			const WznmRMComponentMLibrary& comp
		) {
	return false;
};

bool WznmRMComponentMLibrary::operator!=(
			const WznmRMComponentMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMComponentMLibrary
 ******************************************************************************/

ListWznmRMComponentMLibrary::ListWznmRMComponentMLibrary() {
};

ListWznmRMComponentMLibrary::ListWznmRMComponentMLibrary(
			const ListWznmRMComponentMLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMComponentMLibrary(*(src.nodes[i]));
};

ListWznmRMComponentMLibrary::~ListWznmRMComponentMLibrary() {
	clear();
};

void ListWznmRMComponentMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMComponentMLibrary::size() const {
	return(nodes.size());
};

void ListWznmRMComponentMLibrary::append(
			WznmRMComponentMLibrary* rec
		) {
	nodes.push_back(rec);
};

WznmRMComponentMLibrary* ListWznmRMComponentMLibrary::operator[](
			const uint ix
		) {
	WznmRMComponentMLibrary* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMComponentMLibrary& ListWznmRMComponentMLibrary::operator=(
			const ListWznmRMComponentMLibrary& src
		) {
	WznmRMComponentMLibrary* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMComponentMLibrary(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMComponentMLibrary::operator==(
			const ListWznmRMComponentMLibrary& comp
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

bool ListWznmRMComponentMLibrary::operator!=(
			const ListWznmRMComponentMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMComponentMLibrary
 ******************************************************************************/

TblWznmRMComponentMLibrary::TblWznmRMComponentMLibrary() {
};

TblWznmRMComponentMLibrary::~TblWznmRMComponentMLibrary() {
};

bool TblWznmRMComponentMLibrary::loadRecBySQL(
			const string& sqlstr
			, WznmRMComponentMLibrary** rec
		) {
	return false;
};

ubigint TblWznmRMComponentMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMComponentMLibrary& rst
		) {
	return 0;
};

ubigint TblWznmRMComponentMLibrary::insertRec(
			WznmRMComponentMLibrary* rec
		) {
	return 0;
};

ubigint TblWznmRMComponentMLibrary::insertNewRec(
			WznmRMComponentMLibrary** rec
			, const ubigint refWznmMComponent
			, const ubigint refWznmMLibrary
		) {
	ubigint retval = 0;
	WznmRMComponentMLibrary* _rec = NULL;

	_rec = new WznmRMComponentMLibrary(0, refWznmMComponent, refWznmMLibrary);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMComponentMLibrary::appendNewRecToRst(
			ListWznmRMComponentMLibrary& rst
			, WznmRMComponentMLibrary** rec
			, const ubigint refWznmMComponent
			, const ubigint refWznmMLibrary
		) {
	ubigint retval = 0;
	WznmRMComponentMLibrary* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMComponent, refWznmMLibrary);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMComponentMLibrary::insertRst(
			ListWznmRMComponentMLibrary& rst
			, bool transact
		) {
};

void TblWznmRMComponentMLibrary::updateRec(
			WznmRMComponentMLibrary* rec
		) {
};

void TblWznmRMComponentMLibrary::updateRst(
			ListWznmRMComponentMLibrary& rst
			, bool transact
		) {
};

void TblWznmRMComponentMLibrary::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMComponentMLibrary::loadRecByRef(
			ubigint ref
			, WznmRMComponentMLibrary** rec
		) {
	return false;
};

ubigint TblWznmRMComponentMLibrary::loadCmpsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refWznmMComponents
		) {
	return 0;
};

ubigint TblWznmRMComponentMLibrary::loadLibsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refWznmMLibrarys
		) {
	return 0;
};

ubigint TblWznmRMComponentMLibrary::loadRefsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMComponentMLibrary::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMComponentMLibrary& rst
		) {
	ubigint numload = 0;
	WznmRMComponentMLibrary* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMComponentMLibrary
 ******************************************************************************/

MyTblWznmRMComponentMLibrary::MyTblWznmRMComponentMLibrary() :
			TblWznmRMComponentMLibrary()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMComponentMLibrary::~MyTblWznmRMComponentMLibrary() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMComponentMLibrary::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMComponentMLibrary (refWznmMComponent, refWznmMLibrary) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMComponentMLibrary SET refWznmMComponent = ?, refWznmMLibrary = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMComponentMLibrary WHERE ref = ?", false);
};

bool MyTblWznmRMComponentMLibrary::loadRecBySQL(
			const string& sqlstr
			, WznmRMComponentMLibrary** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMComponentMLibrary* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMComponentMLibrary::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMComponentMLibrary::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMComponentMLibrary();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMComponent = atoll((char*) dbrow[1]); else _rec->refWznmMComponent = 0;
		if (dbrow[2]) _rec->refWznmMLibrary = atoll((char*) dbrow[2]); else _rec->refWznmMLibrary = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMComponentMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMComponentMLibrary& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMComponentMLibrary* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMComponentMLibrary::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMComponentMLibrary::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMComponentMLibrary();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMComponent = atoll((char*) dbrow[1]); else rec->refWznmMComponent = 0;
			if (dbrow[2]) rec->refWznmMLibrary = atoll((char*) dbrow[2]); else rec->refWznmMLibrary = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMComponentMLibrary::insertRec(
			WznmRMComponentMLibrary* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMLibrary,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMComponentMLibrary::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMComponentMLibrary::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMComponentMLibrary::insertRst(
			ListWznmRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMComponentMLibrary::updateRec(
			WznmRMComponentMLibrary* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMLibrary,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMComponentMLibrary::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMComponentMLibrary::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMComponentMLibrary::updateRst(
			ListWznmRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMComponentMLibrary::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMComponentMLibrary::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMComponentMLibrary::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMComponentMLibrary::loadRecByRef(
			ubigint ref
			, WznmRMComponentMLibrary** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMComponentMLibrary WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMComponentMLibrary::loadCmpsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refWznmMComponents
		) {
	return loadRefsBySQL("SELECT refWznmMComponent FROM TblWznmRMComponentMLibrary WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + "", append, refWznmMComponents);
};

ubigint MyTblWznmRMComponentMLibrary::loadLibsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refWznmMLibrarys
		) {
	return loadRefsBySQL("SELECT refWznmMLibrary FROM TblWznmRMComponentMLibrary WHERE refWznmMComponent = " + to_string(refWznmMComponent) + "", append, refWznmMLibrarys);
};

ubigint MyTblWznmRMComponentMLibrary::loadRefsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMComponentMLibrary WHERE refWznmMComponent = " + to_string(refWznmMComponent) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMComponentMLibrary
 ******************************************************************************/

PgTblWznmRMComponentMLibrary::PgTblWznmRMComponentMLibrary() :
			TblWznmRMComponentMLibrary()
			, PgTable()
		{
};

PgTblWznmRMComponentMLibrary::~PgTblWznmRMComponentMLibrary() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMComponentMLibrary::initStatements() {
	createStatement("TblWznmRMComponentMLibrary_insertRec", "INSERT INTO TblWznmRMComponentMLibrary (refWznmMComponent, refWznmMLibrary) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMComponentMLibrary_updateRec", "UPDATE TblWznmRMComponentMLibrary SET refWznmMComponent = $1, refWznmMLibrary = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMComponentMLibrary_removeRecByRef", "DELETE FROM TblWznmRMComponentMLibrary WHERE ref = $1", 1);

	createStatement("TblWznmRMComponentMLibrary_loadRecByRef", "SELECT ref, refWznmMComponent, refWznmMLibrary FROM TblWznmRMComponentMLibrary WHERE ref = $1", 1);
	createStatement("TblWznmRMComponentMLibrary_loadCmpsByLib", "SELECT refWznmMComponent FROM TblWznmRMComponentMLibrary WHERE refWznmMLibrary = $1", 1);
	createStatement("TblWznmRMComponentMLibrary_loadLibsByCmp", "SELECT refWznmMLibrary FROM TblWznmRMComponentMLibrary WHERE refWznmMComponent = $1", 1);
	createStatement("TblWznmRMComponentMLibrary_loadRefsByCmp", "SELECT ref FROM TblWznmRMComponentMLibrary WHERE refWznmMComponent = $1", 1);
};

bool PgTblWznmRMComponentMLibrary::loadRec(
			PGresult* res
			, WznmRMComponentMLibrary** rec
		) {
	char* ptr;

	WznmRMComponentMLibrary* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMComponentMLibrary();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmlibrary")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMComponent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMLibrary = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMComponentMLibrary::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMComponentMLibrary& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMComponentMLibrary* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmlibrary")
		};

		while (numread < numrow) {
			rec = new WznmRMComponentMLibrary();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMComponent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMLibrary = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMComponentMLibrary::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMComponentMLibrary** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMLibrary::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMComponentMLibrary::loadRecBySQL(
			const string& sqlstr
			, WznmRMComponentMLibrary** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMLibrary::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMComponentMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMComponentMLibrary& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMLibrary::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMComponentMLibrary::insertRec(
			WznmRMComponentMLibrary* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMLibrary = htonl64(rec->refWznmMLibrary);

	const char* vals[] = {
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMLibrary
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMComponentMLibrary_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMComponentMLibrary::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMComponentMLibrary::insertRst(
			ListWznmRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMComponentMLibrary::updateRec(
			WznmRMComponentMLibrary* rec
		) {
	PGresult* res;

	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMLibrary = htonl64(rec->refWznmMLibrary);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMLibrary,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMComponentMLibrary_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMComponentMLibrary::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMComponentMLibrary::updateRst(
			ListWznmRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMComponentMLibrary::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMComponentMLibrary_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMComponentMLibrary::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMComponentMLibrary::loadRecByRef(
			ubigint ref
			, WznmRMComponentMLibrary** rec
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

	return loadRecByStmt("TblWznmRMComponentMLibrary_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMComponentMLibrary::loadCmpsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refWznmMComponents
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);

	const char* vals[] = {
		(char*) &_refWznmMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMComponentMLibrary_loadCmpsByLib", 1, vals, l, f, append, refWznmMComponents);
};

ubigint PgTblWznmRMComponentMLibrary::loadLibsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refWznmMLibrarys
		) {
	ubigint _refWznmMComponent = htonl64(refWznmMComponent);

	const char* vals[] = {
		(char*) &_refWznmMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMComponentMLibrary_loadLibsByCmp", 1, vals, l, f, append, refWznmMLibrarys);
};

ubigint PgTblWznmRMComponentMLibrary::loadRefsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMComponent = htonl64(refWznmMComponent);

	const char* vals[] = {
		(char*) &_refWznmMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMComponentMLibrary_loadRefsByCmp", 1, vals, l, f, append, refs);
};

#endif

