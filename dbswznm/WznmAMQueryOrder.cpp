/**
	* \file WznmAMQueryOrder.cpp
	* database access for table TblWznmAMQueryOrder (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAMQueryOrder.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMQueryOrder
 ******************************************************************************/

WznmAMQueryOrder::WznmAMQueryOrder(
			const ubigint ref
			, const ubigint refWznmMQuery
			, const string Short
			, const string srefsWznmMTablecol
		) {

	this->ref = ref;
	this->refWznmMQuery = refWznmMQuery;
	this->Short = Short;
	this->srefsWznmMTablecol = srefsWznmMTablecol;
};

bool WznmAMQueryOrder::operator==(
			const WznmAMQueryOrder& comp
		) {
	return false;
};

bool WznmAMQueryOrder::operator!=(
			const WznmAMQueryOrder& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMQueryOrder
 ******************************************************************************/

ListWznmAMQueryOrder::ListWznmAMQueryOrder() {
};

ListWznmAMQueryOrder::ListWznmAMQueryOrder(
			const ListWznmAMQueryOrder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMQueryOrder(*(src.nodes[i]));
};

ListWznmAMQueryOrder::~ListWznmAMQueryOrder() {
	clear();
};

void ListWznmAMQueryOrder::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMQueryOrder::size() const {
	return(nodes.size());
};

void ListWznmAMQueryOrder::append(
			WznmAMQueryOrder* rec
		) {
	nodes.push_back(rec);
};

WznmAMQueryOrder* ListWznmAMQueryOrder::operator[](
			const uint ix
		) {
	WznmAMQueryOrder* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMQueryOrder& ListWznmAMQueryOrder::operator=(
			const ListWznmAMQueryOrder& src
		) {
	WznmAMQueryOrder* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMQueryOrder(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMQueryOrder::operator==(
			const ListWznmAMQueryOrder& comp
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

bool ListWznmAMQueryOrder::operator!=(
			const ListWznmAMQueryOrder& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMQueryOrder
 ******************************************************************************/

TblWznmAMQueryOrder::TblWznmAMQueryOrder() {
};

TblWznmAMQueryOrder::~TblWznmAMQueryOrder() {
};

bool TblWznmAMQueryOrder::loadRecBySQL(
			const string& sqlstr
			, WznmAMQueryOrder** rec
		) {
	return false;
};

ubigint TblWznmAMQueryOrder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	return 0;
};

ubigint TblWznmAMQueryOrder::insertRec(
			WznmAMQueryOrder* rec
		) {
	return 0;
};

ubigint TblWznmAMQueryOrder::insertNewRec(
			WznmAMQueryOrder** rec
			, const ubigint refWznmMQuery
			, const string Short
			, const string srefsWznmMTablecol
		) {
	ubigint retval = 0;
	WznmAMQueryOrder* _rec = NULL;

	_rec = new WznmAMQueryOrder(0, refWznmMQuery, Short, srefsWznmMTablecol);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMQueryOrder::appendNewRecToRst(
			ListWznmAMQueryOrder& rst
			, WznmAMQueryOrder** rec
			, const ubigint refWznmMQuery
			, const string Short
			, const string srefsWznmMTablecol
		) {
	ubigint retval = 0;
	WznmAMQueryOrder* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMQuery, Short, srefsWznmMTablecol);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMQueryOrder::insertRst(
			ListWznmAMQueryOrder& rst
			, bool transact
		) {
};

void TblWznmAMQueryOrder::updateRec(
			WznmAMQueryOrder* rec
		) {
};

void TblWznmAMQueryOrder::updateRst(
			ListWznmAMQueryOrder& rst
			, bool transact
		) {
};

void TblWznmAMQueryOrder::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMQueryOrder::loadRecByRef(
			ubigint ref
			, WznmAMQueryOrder** rec
		) {
	return false;
};

ubigint TblWznmAMQueryOrder::loadRefsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMQueryOrder::loadRstByQry(
			ubigint refWznmMQuery
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	return 0;
};

ubigint TblWznmAMQueryOrder::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	ubigint numload = 0;
	WznmAMQueryOrder* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMQueryOrder
 ******************************************************************************/

MyTblWznmAMQueryOrder::MyTblWznmAMQueryOrder() :
			TblWznmAMQueryOrder()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMQueryOrder::~MyTblWznmAMQueryOrder() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMQueryOrder::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMQueryOrder (refWznmMQuery, Short, srefsWznmMTablecol) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMQueryOrder SET refWznmMQuery = ?, Short = ?, srefsWznmMTablecol = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMQueryOrder WHERE ref = ?", false);
};

bool MyTblWznmAMQueryOrder::loadRecBySQL(
			const string& sqlstr
			, WznmAMQueryOrder** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMQueryOrder* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMQueryOrder::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMQueryOrder::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMQueryOrder();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMQuery = atoll((char*) dbrow[1]); else _rec->refWznmMQuery = 0;
		if (dbrow[2]) _rec->Short.assign(dbrow[2], dblengths[2]); else _rec->Short = "";
		if (dbrow[3]) _rec->srefsWznmMTablecol.assign(dbrow[3], dblengths[3]); else _rec->srefsWznmMTablecol = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMQueryOrder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMQueryOrder* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMQueryOrder::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMQueryOrder::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMQueryOrder();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMQuery = atoll((char*) dbrow[1]); else rec->refWznmMQuery = 0;
			if (dbrow[2]) rec->Short.assign(dbrow[2], dblengths[2]); else rec->Short = "";
			if (dbrow[3]) rec->srefsWznmMTablecol.assign(dbrow[3], dblengths[3]); else rec->srefsWznmMTablecol = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMQueryOrder::insertRec(
			WznmAMQueryOrder* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->Short.length();
	l[2] = rec->srefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuery,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Short.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefsWznmMTablecol.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMQueryOrder::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMQueryOrder::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMQueryOrder::insertRst(
			ListWznmAMQueryOrder& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMQueryOrder::updateRec(
			WznmAMQueryOrder* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->Short.length();
	l[2] = rec->srefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuery,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Short.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefsWznmMTablecol.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMQueryOrder::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMQueryOrder::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMQueryOrder::updateRst(
			ListWznmAMQueryOrder& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMQueryOrder::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMQueryOrder::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMQueryOrder::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMQueryOrder::loadRecByRef(
			ubigint ref
			, WznmAMQueryOrder** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMQueryOrder WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMQueryOrder::loadRefsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMQueryOrder WHERE refWznmMQuery = " + to_string(refWznmMQuery) + "", append, refs);
};

ubigint MyTblWznmAMQueryOrder::loadRstByQry(
			ubigint refWznmMQuery
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMQuery, Short, srefsWznmMTablecol FROM TblWznmAMQueryOrder WHERE refWznmMQuery = " + to_string(refWznmMQuery) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMQueryOrder
 ******************************************************************************/

PgTblWznmAMQueryOrder::PgTblWznmAMQueryOrder() :
			TblWznmAMQueryOrder()
			, PgTable()
		{
};

PgTblWznmAMQueryOrder::~PgTblWznmAMQueryOrder() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMQueryOrder::initStatements() {
	createStatement("TblWznmAMQueryOrder_insertRec", "INSERT INTO TblWznmAMQueryOrder (refWznmMQuery, Short, srefsWznmMTablecol) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmAMQueryOrder_updateRec", "UPDATE TblWznmAMQueryOrder SET refWznmMQuery = $1, Short = $2, srefsWznmMTablecol = $3 WHERE ref = $4", 4);
	createStatement("TblWznmAMQueryOrder_removeRecByRef", "DELETE FROM TblWznmAMQueryOrder WHERE ref = $1", 1);

	createStatement("TblWznmAMQueryOrder_loadRecByRef", "SELECT ref, refWznmMQuery, Short, srefsWznmMTablecol FROM TblWznmAMQueryOrder WHERE ref = $1", 1);
	createStatement("TblWznmAMQueryOrder_loadRefsByQry", "SELECT ref FROM TblWznmAMQueryOrder WHERE refWznmMQuery = $1", 1);
	createStatement("TblWznmAMQueryOrder_loadRstByQry", "SELECT ref, refWznmMQuery, Short, srefsWznmMTablecol FROM TblWznmAMQueryOrder WHERE refWznmMQuery = $1", 1);
};

bool PgTblWznmAMQueryOrder::loadRec(
			PGresult* res
			, WznmAMQueryOrder** rec
		) {
	char* ptr;

	WznmAMQueryOrder* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMQueryOrder();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquery"),
			PQfnumber(res, "short"),
			PQfnumber(res, "srefswznmmtablecol")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMQueryOrder::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMQueryOrder* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquery"),
			PQfnumber(res, "short"),
			PQfnumber(res, "srefswznmmtablecol")
		};

		while (numread < numrow) {
			rec = new WznmAMQueryOrder();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMQueryOrder::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMQueryOrder** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryOrder::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMQueryOrder::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryOrder::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMQueryOrder::loadRecBySQL(
			const string& sqlstr
			, WznmAMQueryOrder** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryOrder::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMQueryOrder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryOrder::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMQueryOrder::insertRec(
			WznmAMQueryOrder* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery,
		rec->Short.c_str(),
		rec->srefsWznmMTablecol.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMQueryOrder_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryOrder::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMQueryOrder::insertRst(
			ListWznmAMQueryOrder& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMQueryOrder::updateRec(
			WznmAMQueryOrder* rec
		) {
	PGresult* res;

	ubigint _refWznmMQuery = htonl64(rec->refWznmMQuery);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMQuery,
		rec->Short.c_str(),
		rec->srefsWznmMTablecol.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMQueryOrder_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMQueryOrder::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMQueryOrder::updateRst(
			ListWznmAMQueryOrder& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMQueryOrder::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMQueryOrder_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMQueryOrder::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMQueryOrder::loadRecByRef(
			ubigint ref
			, WznmAMQueryOrder** rec
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

	return loadRecByStmt("TblWznmAMQueryOrder_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMQueryOrder::loadRefsByQry(
			ubigint refWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMQuery = htonl64(refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMQueryOrder_loadRefsByQry", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMQueryOrder::loadRstByQry(
			ubigint refWznmMQuery
			, const bool append
			, ListWznmAMQueryOrder& rst
		) {
	ubigint _refWznmMQuery = htonl64(refWznmMQuery);

	const char* vals[] = {
		(char*) &_refWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMQueryOrder_loadRstByQry", 1, vals, l, f, append, rst);
};

#endif

