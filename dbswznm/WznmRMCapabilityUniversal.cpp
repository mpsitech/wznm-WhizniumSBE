/**
	* \file WznmRMCapabilityUniversal.cpp
	* database access for table TblWznmRMCapabilityUniversal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmRMCapabilityUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMCapabilityUniversal
 ******************************************************************************/

WznmRMCapabilityUniversal::WznmRMCapabilityUniversal(
			const ubigint ref
			, const ubigint refWznmMCapability
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const string srefKKey
		) {

	this->ref = ref;
	this->refWznmMCapability = refWznmMCapability;
	this->unvIxWznmVMaintable = unvIxWznmVMaintable;
	this->unvUref = unvUref;
	this->srefKKey = srefKKey;
};

bool WznmRMCapabilityUniversal::operator==(
			const WznmRMCapabilityUniversal& comp
		) {
	return false;
};

bool WznmRMCapabilityUniversal::operator!=(
			const WznmRMCapabilityUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMCapabilityUniversal
 ******************************************************************************/

ListWznmRMCapabilityUniversal::ListWznmRMCapabilityUniversal() {
};

ListWznmRMCapabilityUniversal::ListWznmRMCapabilityUniversal(
			const ListWznmRMCapabilityUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMCapabilityUniversal(*(src.nodes[i]));
};

ListWznmRMCapabilityUniversal::~ListWznmRMCapabilityUniversal() {
	clear();
};

void ListWznmRMCapabilityUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMCapabilityUniversal::size() const {
	return(nodes.size());
};

void ListWznmRMCapabilityUniversal::append(
			WznmRMCapabilityUniversal* rec
		) {
	nodes.push_back(rec);
};

WznmRMCapabilityUniversal* ListWznmRMCapabilityUniversal::operator[](
			const uint ix
		) {
	WznmRMCapabilityUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMCapabilityUniversal& ListWznmRMCapabilityUniversal::operator=(
			const ListWznmRMCapabilityUniversal& src
		) {
	WznmRMCapabilityUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMCapabilityUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMCapabilityUniversal::operator==(
			const ListWznmRMCapabilityUniversal& comp
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

bool ListWznmRMCapabilityUniversal::operator!=(
			const ListWznmRMCapabilityUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMCapabilityUniversal
 ******************************************************************************/

TblWznmRMCapabilityUniversal::TblWznmRMCapabilityUniversal() {
};

TblWznmRMCapabilityUniversal::~TblWznmRMCapabilityUniversal() {
};

bool TblWznmRMCapabilityUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmRMCapabilityUniversal** rec
		) {
	return false;
};

ubigint TblWznmRMCapabilityUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMCapabilityUniversal& rst
		) {
	return 0;
};

ubigint TblWznmRMCapabilityUniversal::insertRec(
			WznmRMCapabilityUniversal* rec
		) {
	return 0;
};

ubigint TblWznmRMCapabilityUniversal::insertNewRec(
			WznmRMCapabilityUniversal** rec
			, const ubigint refWznmMCapability
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const string srefKKey
		) {
	ubigint retval = 0;
	WznmRMCapabilityUniversal* _rec = NULL;

	_rec = new WznmRMCapabilityUniversal(0, refWznmMCapability, unvIxWznmVMaintable, unvUref, srefKKey);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMCapabilityUniversal::appendNewRecToRst(
			ListWznmRMCapabilityUniversal& rst
			, WznmRMCapabilityUniversal** rec
			, const ubigint refWznmMCapability
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const string srefKKey
		) {
	ubigint retval = 0;
	WznmRMCapabilityUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMCapability, unvIxWznmVMaintable, unvUref, srefKKey);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMCapabilityUniversal::insertRst(
			ListWznmRMCapabilityUniversal& rst
			, bool transact
		) {
};

void TblWznmRMCapabilityUniversal::updateRec(
			WznmRMCapabilityUniversal* rec
		) {
};

void TblWznmRMCapabilityUniversal::updateRst(
			ListWznmRMCapabilityUniversal& rst
			, bool transact
		) {
};

void TblWznmRMCapabilityUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMCapabilityUniversal::loadRecByRef(
			ubigint ref
			, WznmRMCapabilityUniversal** rec
		) {
	return false;
};

ubigint TblWznmRMCapabilityUniversal::loadRefsByCpb(
			ubigint refWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMCapabilityUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMCapabilityUniversal& rst
		) {
	ubigint numload = 0;
	WznmRMCapabilityUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMCapabilityUniversal
 ******************************************************************************/

MyTblWznmRMCapabilityUniversal::MyTblWznmRMCapabilityUniversal() :
			TblWznmRMCapabilityUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMCapabilityUniversal::~MyTblWznmRMCapabilityUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMCapabilityUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMCapabilityUniversal (refWznmMCapability, unvIxWznmVMaintable, unvUref, srefKKey) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMCapabilityUniversal SET refWznmMCapability = ?, unvIxWznmVMaintable = ?, unvUref = ?, srefKKey = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMCapabilityUniversal WHERE ref = ?", false);
};

bool MyTblWznmRMCapabilityUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmRMCapabilityUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMCapabilityUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMCapabilityUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMCapabilityUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmRMCapabilityUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMCapability = atoll((char*) dbrow[1]); else _rec->refWznmMCapability = 0;
		if (dbrow[2]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->srefKKey.assign(dbrow[4], dblengths[4]); else _rec->srefKKey = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMCapabilityUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMCapabilityUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMCapabilityUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMCapabilityUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMCapabilityUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmRMCapabilityUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMCapability = atoll((char*) dbrow[1]); else rec->refWznmMCapability = 0;
			if (dbrow[2]) rec->unvIxWznmVMaintable = atol((char*) dbrow[2]); else rec->unvIxWznmVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->srefKKey.assign(dbrow[4], dblengths[4]); else rec->srefKKey = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMCapabilityUniversal::insertRec(
			WznmRMCapabilityUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->srefKKey.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCapability,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKKey.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMCapabilityUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMCapabilityUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMCapabilityUniversal::insertRst(
			ListWznmRMCapabilityUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMCapabilityUniversal::updateRec(
			WznmRMCapabilityUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->srefKKey.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCapability,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMCapabilityUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMCapabilityUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMCapabilityUniversal::updateRst(
			ListWznmRMCapabilityUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMCapabilityUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMCapabilityUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMCapabilityUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMCapabilityUniversal::loadRecByRef(
			ubigint ref
			, WznmRMCapabilityUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMCapabilityUniversal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMCapabilityUniversal::loadRefsByCpb(
			ubigint refWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMCapabilityUniversal WHERE refWznmMCapability = " + to_string(refWznmMCapability) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMCapabilityUniversal
 ******************************************************************************/

PgTblWznmRMCapabilityUniversal::PgTblWznmRMCapabilityUniversal() :
			TblWznmRMCapabilityUniversal()
			, PgTable()
		{
};

PgTblWznmRMCapabilityUniversal::~PgTblWznmRMCapabilityUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMCapabilityUniversal::initStatements() {
	createStatement("TblWznmRMCapabilityUniversal_insertRec", "INSERT INTO TblWznmRMCapabilityUniversal (refWznmMCapability, unvIxWznmVMaintable, unvUref, srefKKey) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmRMCapabilityUniversal_updateRec", "UPDATE TblWznmRMCapabilityUniversal SET refWznmMCapability = $1, unvIxWznmVMaintable = $2, unvUref = $3, srefKKey = $4 WHERE ref = $5", 5);
	createStatement("TblWznmRMCapabilityUniversal_removeRecByRef", "DELETE FROM TblWznmRMCapabilityUniversal WHERE ref = $1", 1);

	createStatement("TblWznmRMCapabilityUniversal_loadRecByRef", "SELECT ref, refWznmMCapability, unvIxWznmVMaintable, unvUref, srefKKey FROM TblWznmRMCapabilityUniversal WHERE ref = $1", 1);
	createStatement("TblWznmRMCapabilityUniversal_loadRefsByCpb", "SELECT ref FROM TblWznmRMCapabilityUniversal WHERE refWznmMCapability = $1", 1);
};

bool PgTblWznmRMCapabilityUniversal::loadRec(
			PGresult* res
			, WznmRMCapabilityUniversal** rec
		) {
	char* ptr;

	WznmRMCapabilityUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMCapabilityUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcapability"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "srefkkey")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMCapability = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefKKey.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMCapabilityUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMCapabilityUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMCapabilityUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcapability"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "srefkkey")
		};

		while (numread < numrow) {
			rec = new WznmRMCapabilityUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMCapability = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefKKey.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMCapabilityUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMCapabilityUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCapabilityUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmRMCapabilityUniversal::loadRecBySQL(
			const string& sqlstr
			, WznmRMCapabilityUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCapabilityUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMCapabilityUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMCapabilityUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCapabilityUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMCapabilityUniversal::insertRec(
			WznmRMCapabilityUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMCapability = htonl64(rec->refWznmMCapability);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);

	const char* vals[] = {
		(char*) &_refWznmMCapability,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		rec->srefKKey.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmRMCapabilityUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMCapabilityUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMCapabilityUniversal::insertRst(
			ListWznmRMCapabilityUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMCapabilityUniversal::updateRec(
			WznmRMCapabilityUniversal* rec
		) {
	PGresult* res;

	ubigint _refWznmMCapability = htonl64(rec->refWznmMCapability);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMCapability,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		rec->srefKKey.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmRMCapabilityUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMCapabilityUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMCapabilityUniversal::updateRst(
			ListWznmRMCapabilityUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMCapabilityUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMCapabilityUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMCapabilityUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMCapabilityUniversal::loadRecByRef(
			ubigint ref
			, WznmRMCapabilityUniversal** rec
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

	return loadRecByStmt("TblWznmRMCapabilityUniversal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMCapabilityUniversal::loadRefsByCpb(
			ubigint refWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMCapability = htonl64(refWznmMCapability);

	const char* vals[] = {
		(char*) &_refWznmMCapability
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMCapabilityUniversal_loadRefsByCpb", 1, vals, l, f, append, refs);
};

#endif

