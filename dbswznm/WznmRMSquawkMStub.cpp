/**
	* \file WznmRMSquawkMStub.cpp
	* database access for table TblWznmRMSquawkMStub (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmRMSquawkMStub.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMSquawkMStub
 ******************************************************************************/

WznmRMSquawkMStub::WznmRMSquawkMStub(
			const ubigint ref
			, const ubigint refWznmMSquawk
			, const ubigint refWznmMStub
		) {

	this->ref = ref;
	this->refWznmMSquawk = refWznmMSquawk;
	this->refWznmMStub = refWznmMStub;
};

bool WznmRMSquawkMStub::operator==(
			const WznmRMSquawkMStub& comp
		) {
	return false;
};

bool WznmRMSquawkMStub::operator!=(
			const WznmRMSquawkMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMSquawkMStub
 ******************************************************************************/

ListWznmRMSquawkMStub::ListWznmRMSquawkMStub() {
};

ListWznmRMSquawkMStub::ListWznmRMSquawkMStub(
			const ListWznmRMSquawkMStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMSquawkMStub(*(src.nodes[i]));
};

ListWznmRMSquawkMStub::~ListWznmRMSquawkMStub() {
	clear();
};

void ListWznmRMSquawkMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMSquawkMStub::size() const {
	return(nodes.size());
};

void ListWznmRMSquawkMStub::append(
			WznmRMSquawkMStub* rec
		) {
	nodes.push_back(rec);
};

WznmRMSquawkMStub* ListWznmRMSquawkMStub::operator[](
			const uint ix
		) {
	WznmRMSquawkMStub* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMSquawkMStub& ListWznmRMSquawkMStub::operator=(
			const ListWznmRMSquawkMStub& src
		) {
	WznmRMSquawkMStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMSquawkMStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMSquawkMStub::operator==(
			const ListWznmRMSquawkMStub& comp
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

bool ListWznmRMSquawkMStub::operator!=(
			const ListWznmRMSquawkMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMSquawkMStub
 ******************************************************************************/

TblWznmRMSquawkMStub::TblWznmRMSquawkMStub() {
};

TblWznmRMSquawkMStub::~TblWznmRMSquawkMStub() {
};

bool TblWznmRMSquawkMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMSquawkMStub** rec
		) {
	return false;
};

ubigint TblWznmRMSquawkMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMSquawkMStub& rst
		) {
	return 0;
};

ubigint TblWznmRMSquawkMStub::insertRec(
			WznmRMSquawkMStub* rec
		) {
	return 0;
};

ubigint TblWznmRMSquawkMStub::insertNewRec(
			WznmRMSquawkMStub** rec
			, const ubigint refWznmMSquawk
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmRMSquawkMStub* _rec = NULL;

	_rec = new WznmRMSquawkMStub(0, refWznmMSquawk, refWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMSquawkMStub::appendNewRecToRst(
			ListWznmRMSquawkMStub& rst
			, WznmRMSquawkMStub** rec
			, const ubigint refWznmMSquawk
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmRMSquawkMStub* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMSquawk, refWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMSquawkMStub::insertRst(
			ListWznmRMSquawkMStub& rst
			, bool transact
		) {
};

void TblWznmRMSquawkMStub::updateRec(
			WznmRMSquawkMStub* rec
		) {
};

void TblWznmRMSquawkMStub::updateRst(
			ListWznmRMSquawkMStub& rst
			, bool transact
		) {
};

void TblWznmRMSquawkMStub::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMSquawkMStub::loadRecByRef(
			ubigint ref
			, WznmRMSquawkMStub** rec
		) {
	return false;
};

ubigint TblWznmRMSquawkMStub::loadRefsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMSquawkMStub::loadSqksByStb(
			ubigint refWznmMStub
			, const bool append
			, vector<ubigint>& refWznmMSquawks
		) {
	return 0;
};

ubigint TblWznmRMSquawkMStub::loadStbsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refWznmMStubs
		) {
	return 0;
};

ubigint TblWznmRMSquawkMStub::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMSquawkMStub& rst
		) {
	ubigint numload = 0;
	WznmRMSquawkMStub* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMSquawkMStub
 ******************************************************************************/

MyTblWznmRMSquawkMStub::MyTblWznmRMSquawkMStub() :
			TblWznmRMSquawkMStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMSquawkMStub::~MyTblWznmRMSquawkMStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMSquawkMStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMSquawkMStub (refWznmMSquawk, refWznmMStub) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMSquawkMStub SET refWznmMSquawk = ?, refWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMSquawkMStub WHERE ref = ?", false);
};

bool MyTblWznmRMSquawkMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMSquawkMStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMSquawkMStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMSquawkMStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMSquawkMStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMSquawkMStub();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMSquawk = atoll((char*) dbrow[1]); else _rec->refWznmMSquawk = 0;
		if (dbrow[2]) _rec->refWznmMStub = atoll((char*) dbrow[2]); else _rec->refWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMSquawkMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMSquawkMStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMSquawkMStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMSquawkMStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMSquawkMStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMSquawkMStub();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMSquawk = atoll((char*) dbrow[1]); else rec->refWznmMSquawk = 0;
			if (dbrow[2]) rec->refWznmMStub = atoll((char*) dbrow[2]); else rec->refWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMSquawkMStub::insertRec(
			WznmRMSquawkMStub* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSquawk,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMStub,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMSquawkMStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMSquawkMStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMSquawkMStub::insertRst(
			ListWznmRMSquawkMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMSquawkMStub::updateRec(
			WznmRMSquawkMStub* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMSquawk,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMStub,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMSquawkMStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMSquawkMStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMSquawkMStub::updateRst(
			ListWznmRMSquawkMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMSquawkMStub::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMSquawkMStub::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMSquawkMStub::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMSquawkMStub::loadRecByRef(
			ubigint ref
			, WznmRMSquawkMStub** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMSquawkMStub WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMSquawkMStub::loadRefsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMSquawkMStub WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + "", append, refs);
};

ubigint MyTblWznmRMSquawkMStub::loadSqksByStb(
			ubigint refWznmMStub
			, const bool append
			, vector<ubigint>& refWznmMSquawks
		) {
	return loadRefsBySQL("SELECT refWznmMSquawk FROM TblWznmRMSquawkMStub WHERE refWznmMStub = " + to_string(refWznmMStub) + "", append, refWznmMSquawks);
};

ubigint MyTblWznmRMSquawkMStub::loadStbsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refWznmMStubs
		) {
	return loadRefsBySQL("SELECT refWznmMStub FROM TblWznmRMSquawkMStub WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + "", append, refWznmMStubs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMSquawkMStub
 ******************************************************************************/

PgTblWznmRMSquawkMStub::PgTblWznmRMSquawkMStub() :
			TblWznmRMSquawkMStub()
			, PgTable()
		{
};

PgTblWznmRMSquawkMStub::~PgTblWznmRMSquawkMStub() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMSquawkMStub::initStatements() {
	createStatement("TblWznmRMSquawkMStub_insertRec", "INSERT INTO TblWznmRMSquawkMStub (refWznmMSquawk, refWznmMStub) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMSquawkMStub_updateRec", "UPDATE TblWznmRMSquawkMStub SET refWznmMSquawk = $1, refWznmMStub = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMSquawkMStub_removeRecByRef", "DELETE FROM TblWznmRMSquawkMStub WHERE ref = $1", 1);

	createStatement("TblWznmRMSquawkMStub_loadRecByRef", "SELECT ref, refWznmMSquawk, refWznmMStub FROM TblWznmRMSquawkMStub WHERE ref = $1", 1);
	createStatement("TblWznmRMSquawkMStub_loadRefsBySqk", "SELECT ref FROM TblWznmRMSquawkMStub WHERE refWznmMSquawk = $1", 1);
	createStatement("TblWznmRMSquawkMStub_loadSqksByStb", "SELECT refWznmMSquawk FROM TblWznmRMSquawkMStub WHERE refWznmMStub = $1", 1);
	createStatement("TblWznmRMSquawkMStub_loadStbsBySqk", "SELECT refWznmMStub FROM TblWznmRMSquawkMStub WHERE refWznmMSquawk = $1", 1);
};

bool PgTblWznmRMSquawkMStub::loadRec(
			PGresult* res
			, WznmRMSquawkMStub** rec
		) {
	char* ptr;

	WznmRMSquawkMStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMSquawkMStub();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "refwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMSquawk = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMSquawkMStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMSquawkMStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMSquawkMStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "refwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmRMSquawkMStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMSquawk = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMSquawkMStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMSquawkMStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSquawkMStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMSquawkMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMSquawkMStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSquawkMStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMSquawkMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMSquawkMStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSquawkMStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMSquawkMStub::insertRec(
			WznmRMSquawkMStub* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMSquawk,
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMSquawkMStub_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSquawkMStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMSquawkMStub::insertRst(
			ListWznmRMSquawkMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMSquawkMStub::updateRec(
			WznmRMSquawkMStub* rec
		) {
	PGresult* res;

	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMSquawk,
		(char*) &_refWznmMStub,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMSquawkMStub_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMSquawkMStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMSquawkMStub::updateRst(
			ListWznmRMSquawkMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMSquawkMStub::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMSquawkMStub_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMSquawkMStub::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMSquawkMStub::loadRecByRef(
			ubigint ref
			, WznmRMSquawkMStub** rec
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

	return loadRecByStmt("TblWznmRMSquawkMStub_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMSquawkMStub::loadRefsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMSquawkMStub_loadRefsBySqk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMSquawkMStub::loadSqksByStb(
			ubigint refWznmMStub
			, const bool append
			, vector<ubigint>& refWznmMSquawks
		) {
	ubigint _refWznmMStub = htonl64(refWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMSquawkMStub_loadSqksByStb", 1, vals, l, f, append, refWznmMSquawks);
};

ubigint PgTblWznmRMSquawkMStub::loadStbsBySqk(
			ubigint refWznmMSquawk
			, const bool append
			, vector<ubigint>& refWznmMStubs
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMSquawkMStub_loadStbsBySqk", 1, vals, l, f, append, refWznmMStubs);
};

#endif

