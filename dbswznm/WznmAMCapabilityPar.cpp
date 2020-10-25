/**
	* \file WznmAMCapabilityPar.cpp
	* database access for table TblWznmAMCapabilityPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAMCapabilityPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMCapabilityPar
 ******************************************************************************/

WznmAMCapabilityPar::WznmAMCapabilityPar(
			const ubigint ref
			, const ubigint cpbRefWznmMCapability
			, const uint cpbNum
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->cpbRefWznmMCapability = cpbRefWznmMCapability;
	this->cpbNum = cpbNum;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WznmAMCapabilityPar::operator==(
			const WznmAMCapabilityPar& comp
		) {
	return false;
};

bool WznmAMCapabilityPar::operator!=(
			const WznmAMCapabilityPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMCapabilityPar
 ******************************************************************************/

ListWznmAMCapabilityPar::ListWznmAMCapabilityPar() {
};

ListWznmAMCapabilityPar::ListWznmAMCapabilityPar(
			const ListWznmAMCapabilityPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMCapabilityPar(*(src.nodes[i]));
};

ListWznmAMCapabilityPar::~ListWznmAMCapabilityPar() {
	clear();
};

void ListWznmAMCapabilityPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMCapabilityPar::size() const {
	return(nodes.size());
};

void ListWznmAMCapabilityPar::append(
			WznmAMCapabilityPar* rec
		) {
	nodes.push_back(rec);
};

WznmAMCapabilityPar* ListWznmAMCapabilityPar::operator[](
			const uint ix
		) {
	WznmAMCapabilityPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMCapabilityPar& ListWznmAMCapabilityPar::operator=(
			const ListWznmAMCapabilityPar& src
		) {
	WznmAMCapabilityPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMCapabilityPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMCapabilityPar::operator==(
			const ListWznmAMCapabilityPar& comp
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

bool ListWznmAMCapabilityPar::operator!=(
			const ListWznmAMCapabilityPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMCapabilityPar
 ******************************************************************************/

TblWznmAMCapabilityPar::TblWznmAMCapabilityPar() {
};

TblWznmAMCapabilityPar::~TblWznmAMCapabilityPar() {
};

bool TblWznmAMCapabilityPar::loadRecBySQL(
			const string& sqlstr
			, WznmAMCapabilityPar** rec
		) {
	return false;
};

ubigint TblWznmAMCapabilityPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	return 0;
};

ubigint TblWznmAMCapabilityPar::insertRec(
			WznmAMCapabilityPar* rec
		) {
	return 0;
};

ubigint TblWznmAMCapabilityPar::insertNewRec(
			WznmAMCapabilityPar** rec
			, const ubigint cpbRefWznmMCapability
			, const uint cpbNum
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMCapabilityPar* _rec = NULL;

	_rec = new WznmAMCapabilityPar(0, cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMCapabilityPar::appendNewRecToRst(
			ListWznmAMCapabilityPar& rst
			, WznmAMCapabilityPar** rec
			, const ubigint cpbRefWznmMCapability
			, const uint cpbNum
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMCapabilityPar* _rec = NULL;

	retval = insertNewRec(&_rec, cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMCapabilityPar::insertRst(
			ListWznmAMCapabilityPar& rst
			, bool transact
		) {
};

void TblWznmAMCapabilityPar::updateRec(
			WznmAMCapabilityPar* rec
		) {
};

void TblWznmAMCapabilityPar::updateRst(
			ListWznmAMCapabilityPar& rst
			, bool transact
		) {
};

void TblWznmAMCapabilityPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMCapabilityPar::loadRecByRef(
			ubigint ref
			, WznmAMCapabilityPar** rec
		) {
	return false;
};

ubigint TblWznmAMCapabilityPar::loadRefsByCpb(
			ubigint cpbRefWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMCapabilityPar::loadRstByCpb(
			ubigint cpbRefWznmMCapability
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	return 0;
};

bool TblWznmAMCapabilityPar::loadValByCpbKey(
			ubigint cpbRefWznmMCapability
			, string x1SrefKKey
			, string& Val
		) {
	return false;
};

ubigint TblWznmAMCapabilityPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	ubigint numload = 0;
	WznmAMCapabilityPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMCapabilityPar
 ******************************************************************************/

MyTblWznmAMCapabilityPar::MyTblWznmAMCapabilityPar() :
			TblWznmAMCapabilityPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMCapabilityPar::~MyTblWznmAMCapabilityPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMCapabilityPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMCapabilityPar (cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMCapabilityPar SET cpbRefWznmMCapability = ?, cpbNum = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMCapabilityPar WHERE ref = ?", false);
};

bool MyTblWznmAMCapabilityPar::loadRecBySQL(
			const string& sqlstr
			, WznmAMCapabilityPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMCapabilityPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMCapabilityPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMCapabilityPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMCapabilityPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->cpbRefWznmMCapability = atoll((char*) dbrow[1]); else _rec->cpbRefWznmMCapability = 0;
		if (dbrow[2]) _rec->cpbNum = atol((char*) dbrow[2]); else _rec->cpbNum = 0;
		if (dbrow[3]) _rec->x1SrefKKey.assign(dbrow[3], dblengths[3]); else _rec->x1SrefKKey = "";
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMCapabilityPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMCapabilityPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMCapabilityPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMCapabilityPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMCapabilityPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->cpbRefWznmMCapability = atoll((char*) dbrow[1]); else rec->cpbRefWznmMCapability = 0;
			if (dbrow[2]) rec->cpbNum = atol((char*) dbrow[2]); else rec->cpbNum = 0;
			if (dbrow[3]) rec->x1SrefKKey.assign(dbrow[3], dblengths[3]); else rec->x1SrefKKey = "";
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMCapabilityPar::insertRec(
			WznmAMCapabilityPar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x1SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cpbRefWznmMCapability,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cpbNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMCapabilityPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMCapabilityPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMCapabilityPar::insertRst(
			ListWznmAMCapabilityPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMCapabilityPar::updateRec(
			WznmAMCapabilityPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x1SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cpbRefWznmMCapability,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cpbNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMCapabilityPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMCapabilityPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMCapabilityPar::updateRst(
			ListWznmAMCapabilityPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMCapabilityPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMCapabilityPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMCapabilityPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMCapabilityPar::loadRecByRef(
			ubigint ref
			, WznmAMCapabilityPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMCapabilityPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMCapabilityPar::loadRefsByCpb(
			ubigint cpbRefWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = " + to_string(cpbRefWznmMCapability) + "", append, refs);
};

ubigint MyTblWznmAMCapabilityPar::loadRstByCpb(
			ubigint cpbRefWznmMCapability
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	return loadRstBySQL("SELECT ref, cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = " + to_string(cpbRefWznmMCapability) + " ORDER BY cpbNum ASC", append, rst);
};

bool MyTblWznmAMCapabilityPar::loadValByCpbKey(
			ubigint cpbRefWznmMCapability
			, string x1SrefKKey
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = " + to_string(cpbRefWznmMCapability) + " AND x1SrefKKey = '" + x1SrefKKey + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMCapabilityPar
 ******************************************************************************/

PgTblWznmAMCapabilityPar::PgTblWznmAMCapabilityPar() :
			TblWznmAMCapabilityPar()
			, PgTable()
		{
};

PgTblWznmAMCapabilityPar::~PgTblWznmAMCapabilityPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMCapabilityPar::initStatements() {
	createStatement("TblWznmAMCapabilityPar_insertRec", "INSERT INTO TblWznmAMCapabilityPar (cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMCapabilityPar_updateRec", "UPDATE TblWznmAMCapabilityPar SET cpbRefWznmMCapability = $1, cpbNum = $2, x1SrefKKey = $3, Val = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMCapabilityPar_removeRecByRef", "DELETE FROM TblWznmAMCapabilityPar WHERE ref = $1", 1);

	createStatement("TblWznmAMCapabilityPar_loadRecByRef", "SELECT ref, cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val FROM TblWznmAMCapabilityPar WHERE ref = $1", 1);
	createStatement("TblWznmAMCapabilityPar_loadRefsByCpb", "SELECT ref FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = $1", 1);
	createStatement("TblWznmAMCapabilityPar_loadRstByCpb", "SELECT ref, cpbRefWznmMCapability, cpbNum, x1SrefKKey, Val FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = $1 ORDER BY cpbNum ASC", 1);
	createStatement("TblWznmAMCapabilityPar_loadValByCpbKey", "SELECT Val FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = $1 AND x1SrefKKey = $2", 2);
};

bool PgTblWznmAMCapabilityPar::loadRec(
			PGresult* res
			, WznmAMCapabilityPar** rec
		) {
	char* ptr;

	WznmAMCapabilityPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMCapabilityPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cpbrefwznmmcapability"),
			PQfnumber(res, "cpbnum"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->cpbRefWznmMCapability = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->cpbNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMCapabilityPar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMCapabilityPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cpbrefwznmmcapability"),
			PQfnumber(res, "cpbnum"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAMCapabilityPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->cpbRefWznmMCapability = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->cpbNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMCapabilityPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMCapabilityPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMCapabilityPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMCapabilityPar::loadRecBySQL(
			const string& sqlstr
			, WznmAMCapabilityPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMCapabilityPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMCapabilityPar::insertRec(
			WznmAMCapabilityPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _cpbRefWznmMCapability = htonl64(rec->cpbRefWznmMCapability);
	uint _cpbNum = htonl(rec->cpbNum);

	const char* vals[] = {
		(char*) &_cpbRefWznmMCapability,
		(char*) &_cpbNum,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMCapabilityPar_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMCapabilityPar::insertRst(
			ListWznmAMCapabilityPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMCapabilityPar::updateRec(
			WznmAMCapabilityPar* rec
		) {
	PGresult* res;

	ubigint _cpbRefWznmMCapability = htonl64(rec->cpbRefWznmMCapability);
	uint _cpbNum = htonl(rec->cpbNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_cpbRefWznmMCapability,
		(char*) &_cpbNum,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str(),
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

	res = PQexecPrepared(dbs, "TblWznmAMCapabilityPar_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMCapabilityPar::updateRst(
			ListWznmAMCapabilityPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMCapabilityPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMCapabilityPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMCapabilityPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMCapabilityPar::loadRecByRef(
			ubigint ref
			, WznmAMCapabilityPar** rec
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

	return loadRecByStmt("TblWznmAMCapabilityPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMCapabilityPar::loadRefsByCpb(
			ubigint cpbRefWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _cpbRefWznmMCapability = htonl64(cpbRefWznmMCapability);

	const char* vals[] = {
		(char*) &_cpbRefWznmMCapability
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMCapabilityPar_loadRefsByCpb", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMCapabilityPar::loadRstByCpb(
			ubigint cpbRefWznmMCapability
			, const bool append
			, ListWznmAMCapabilityPar& rst
		) {
	ubigint _cpbRefWznmMCapability = htonl64(cpbRefWznmMCapability);

	const char* vals[] = {
		(char*) &_cpbRefWznmMCapability
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMCapabilityPar_loadRstByCpb", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMCapabilityPar::loadValByCpbKey(
			ubigint cpbRefWznmMCapability
			, string x1SrefKKey
			, string& Val
		) {
	ubigint _cpbRefWznmMCapability = htonl64(cpbRefWznmMCapability);

	const char* vals[] = {
		(char*) &_cpbRefWznmMCapability,
		x1SrefKKey.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadStringByStmt("TblWznmAMCapabilityPar_loadValByCpbKey", 2, vals, l, f, Val);
};

#endif

