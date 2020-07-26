/**
	* \file WznmRMStubMStub.cpp
	* database access for table TblWznmRMStubMStub (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmRMStubMStub.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMStubMStub
 ******************************************************************************/

WznmRMStubMStub::WznmRMStubMStub(
			const ubigint ref
			, const ubigint supRefWznmMStub
			, const ubigint subRefWznmMStub
		) {

	this->ref = ref;
	this->supRefWznmMStub = supRefWznmMStub;
	this->subRefWznmMStub = subRefWznmMStub;
};

bool WznmRMStubMStub::operator==(
			const WznmRMStubMStub& comp
		) {
	return false;
};

bool WznmRMStubMStub::operator!=(
			const WznmRMStubMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMStubMStub
 ******************************************************************************/

ListWznmRMStubMStub::ListWznmRMStubMStub() {
};

ListWznmRMStubMStub::ListWznmRMStubMStub(
			const ListWznmRMStubMStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMStubMStub(*(src.nodes[i]));
};

ListWznmRMStubMStub::~ListWznmRMStubMStub() {
	clear();
};

void ListWznmRMStubMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMStubMStub::size() const {
	return(nodes.size());
};

void ListWznmRMStubMStub::append(
			WznmRMStubMStub* rec
		) {
	nodes.push_back(rec);
};

WznmRMStubMStub* ListWznmRMStubMStub::operator[](
			const uint ix
		) {
	WznmRMStubMStub* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMStubMStub& ListWznmRMStubMStub::operator=(
			const ListWznmRMStubMStub& src
		) {
	WznmRMStubMStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMStubMStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMStubMStub::operator==(
			const ListWznmRMStubMStub& comp
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

bool ListWznmRMStubMStub::operator!=(
			const ListWznmRMStubMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMStubMStub
 ******************************************************************************/

TblWznmRMStubMStub::TblWznmRMStubMStub() {
};

TblWznmRMStubMStub::~TblWznmRMStubMStub() {
};

bool TblWznmRMStubMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMStubMStub** rec
		) {
	return false;
};

ubigint TblWznmRMStubMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMStubMStub& rst
		) {
	return 0;
};

ubigint TblWznmRMStubMStub::insertRec(
			WznmRMStubMStub* rec
		) {
	return 0;
};

ubigint TblWznmRMStubMStub::insertNewRec(
			WznmRMStubMStub** rec
			, const ubigint supRefWznmMStub
			, const ubigint subRefWznmMStub
		) {
	ubigint retval = 0;
	WznmRMStubMStub* _rec = NULL;

	_rec = new WznmRMStubMStub(0, supRefWznmMStub, subRefWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMStubMStub::appendNewRecToRst(
			ListWznmRMStubMStub& rst
			, WznmRMStubMStub** rec
			, const ubigint supRefWznmMStub
			, const ubigint subRefWznmMStub
		) {
	ubigint retval = 0;
	WznmRMStubMStub* _rec = NULL;

	retval = insertNewRec(&_rec, supRefWznmMStub, subRefWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMStubMStub::insertRst(
			ListWznmRMStubMStub& rst
			, bool transact
		) {
};

void TblWznmRMStubMStub::updateRec(
			WznmRMStubMStub* rec
		) {
};

void TblWznmRMStubMStub::updateRst(
			ListWznmRMStubMStub& rst
			, bool transact
		) {
};

void TblWznmRMStubMStub::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMStubMStub::loadRecByRef(
			ubigint ref
			, WznmRMStubMStub** rec
		) {
	return false;
};

ubigint TblWznmRMStubMStub::loadSubsBySup(
			ubigint supRefWznmMStub
			, const bool append
			, vector<ubigint>& subRefWznmMStubs
		) {
	return 0;
};

ubigint TblWznmRMStubMStub::loadSupsBySub(
			ubigint subRefWznmMStub
			, const bool append
			, vector<ubigint>& supRefWznmMStubs
		) {
	return 0;
};

ubigint TblWznmRMStubMStub::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMStubMStub& rst
		) {
	ubigint numload = 0;
	WznmRMStubMStub* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMStubMStub
 ******************************************************************************/

MyTblWznmRMStubMStub::MyTblWznmRMStubMStub() :
			TblWznmRMStubMStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMStubMStub::~MyTblWznmRMStubMStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMStubMStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMStubMStub (supRefWznmMStub, subRefWznmMStub) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMStubMStub SET supRefWznmMStub = ?, subRefWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMStubMStub WHERE ref = ?", false);
};

bool MyTblWznmRMStubMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMStubMStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMStubMStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMStubMStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMStubMStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMStubMStub();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->supRefWznmMStub = atoll((char*) dbrow[1]); else _rec->supRefWznmMStub = 0;
		if (dbrow[2]) _rec->subRefWznmMStub = atoll((char*) dbrow[2]); else _rec->subRefWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMStubMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMStubMStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMStubMStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMStubMStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMStubMStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMStubMStub();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->supRefWznmMStub = atoll((char*) dbrow[1]); else rec->supRefWznmMStub = 0;
			if (dbrow[2]) rec->subRefWznmMStub = atoll((char*) dbrow[2]); else rec->subRefWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMStubMStub::insertRec(
			WznmRMStubMStub* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWznmMStub,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->subRefWznmMStub,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMStubMStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMStubMStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMStubMStub::insertRst(
			ListWznmRMStubMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMStubMStub::updateRec(
			WznmRMStubMStub* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWznmMStub,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->subRefWznmMStub,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMStubMStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMStubMStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMStubMStub::updateRst(
			ListWznmRMStubMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMStubMStub::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMStubMStub::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMStubMStub::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMStubMStub::loadRecByRef(
			ubigint ref
			, WznmRMStubMStub** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMStubMStub WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMStubMStub::loadSubsBySup(
			ubigint supRefWznmMStub
			, const bool append
			, vector<ubigint>& subRefWznmMStubs
		) {
	return loadRefsBySQL("SELECT subRefWznmMStub FROM TblWznmRMStubMStub WHERE supRefWznmMStub = " + to_string(supRefWznmMStub) + "", append, subRefWznmMStubs);
};

ubigint MyTblWznmRMStubMStub::loadSupsBySub(
			ubigint subRefWznmMStub
			, const bool append
			, vector<ubigint>& supRefWznmMStubs
		) {
	return loadRefsBySQL("SELECT supRefWznmMStub FROM TblWznmRMStubMStub WHERE subRefWznmMStub = " + to_string(subRefWznmMStub) + "", append, supRefWznmMStubs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMStubMStub
 ******************************************************************************/

PgTblWznmRMStubMStub::PgTblWznmRMStubMStub() :
			TblWznmRMStubMStub()
			, PgTable()
		{
};

PgTblWznmRMStubMStub::~PgTblWznmRMStubMStub() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMStubMStub::initStatements() {
	createStatement("TblWznmRMStubMStub_insertRec", "INSERT INTO TblWznmRMStubMStub (supRefWznmMStub, subRefWznmMStub) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWznmRMStubMStub_updateRec", "UPDATE TblWznmRMStubMStub SET supRefWznmMStub = $1, subRefWznmMStub = $2 WHERE ref = $3", 3);
	createStatement("TblWznmRMStubMStub_removeRecByRef", "DELETE FROM TblWznmRMStubMStub WHERE ref = $1", 1);

	createStatement("TblWznmRMStubMStub_loadRecByRef", "SELECT ref, supRefWznmMStub, subRefWznmMStub FROM TblWznmRMStubMStub WHERE ref = $1", 1);
	createStatement("TblWznmRMStubMStub_loadSubsBySup", "SELECT subRefWznmMStub FROM TblWznmRMStubMStub WHERE supRefWznmMStub = $1", 1);
	createStatement("TblWznmRMStubMStub_loadSupsBySub", "SELECT supRefWznmMStub FROM TblWznmRMStubMStub WHERE subRefWznmMStub = $1", 1);
};

bool PgTblWznmRMStubMStub::loadRec(
			PGresult* res
			, WznmRMStubMStub** rec
		) {
	char* ptr;

	WznmRMStubMStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMStubMStub();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwznmmstub"),
			PQfnumber(res, "subrefwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->supRefWznmMStub = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->subRefWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMStubMStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMStubMStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMStubMStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwznmmstub"),
			PQfnumber(res, "subrefwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmRMStubMStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->supRefWznmMStub = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->subRefWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMStubMStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMStubMStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMStubMStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMStubMStub::loadRecBySQL(
			const string& sqlstr
			, WznmRMStubMStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMStubMStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMStubMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMStubMStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMStubMStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMStubMStub::insertRec(
			WznmRMStubMStub* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _supRefWznmMStub = htonl64(rec->supRefWznmMStub);
	ubigint _subRefWznmMStub = htonl64(rec->subRefWznmMStub);

	const char* vals[] = {
		(char*) &_supRefWznmMStub,
		(char*) &_subRefWznmMStub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMStubMStub_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMStubMStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMStubMStub::insertRst(
			ListWznmRMStubMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMStubMStub::updateRec(
			WznmRMStubMStub* rec
		) {
	PGresult* res;

	ubigint _supRefWznmMStub = htonl64(rec->supRefWznmMStub);
	ubigint _subRefWznmMStub = htonl64(rec->subRefWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_supRefWznmMStub,
		(char*) &_subRefWznmMStub,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMStubMStub_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMStubMStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMStubMStub::updateRst(
			ListWznmRMStubMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMStubMStub::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMStubMStub_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMStubMStub::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMStubMStub::loadRecByRef(
			ubigint ref
			, WznmRMStubMStub** rec
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

	return loadRecByStmt("TblWznmRMStubMStub_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMStubMStub::loadSubsBySup(
			ubigint supRefWznmMStub
			, const bool append
			, vector<ubigint>& subRefWznmMStubs
		) {
	ubigint _supRefWznmMStub = htonl64(supRefWznmMStub);

	const char* vals[] = {
		(char*) &_supRefWznmMStub
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMStubMStub_loadSubsBySup", 1, vals, l, f, append, subRefWznmMStubs);
};

ubigint PgTblWznmRMStubMStub::loadSupsBySub(
			ubigint subRefWznmMStub
			, const bool append
			, vector<ubigint>& supRefWznmMStubs
		) {
	ubigint _subRefWznmMStub = htonl64(subRefWznmMStub);

	const char* vals[] = {
		(char*) &_subRefWznmMStub
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMStubMStub_loadSupsBySub", 1, vals, l, f, append, supRefWznmMStubs);
};

#endif

