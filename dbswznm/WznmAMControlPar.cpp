/**
	* \file WznmAMControlPar.cpp
	* database access for table TblWznmAMControlPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAMControlPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMControlPar
 ******************************************************************************/

WznmAMControlPar::WznmAMControlPar(
			const ubigint ref
			, const ubigint refWznmMControl
			, const string x1SrefKKey
			, const ubigint x2RefWznmMLocale
			, const string osrefKVal
		) {

	this->ref = ref;
	this->refWznmMControl = refWznmMControl;
	this->x1SrefKKey = x1SrefKKey;
	this->x2RefWznmMLocale = x2RefWznmMLocale;
	this->osrefKVal = osrefKVal;
};

bool WznmAMControlPar::operator==(
			const WznmAMControlPar& comp
		) {
	return false;
};

bool WznmAMControlPar::operator!=(
			const WznmAMControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMControlPar
 ******************************************************************************/

ListWznmAMControlPar::ListWznmAMControlPar() {
};

ListWznmAMControlPar::ListWznmAMControlPar(
			const ListWznmAMControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMControlPar(*(src.nodes[i]));
};

ListWznmAMControlPar::~ListWznmAMControlPar() {
	clear();
};

void ListWznmAMControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMControlPar::size() const {
	return(nodes.size());
};

void ListWznmAMControlPar::append(
			WznmAMControlPar* rec
		) {
	nodes.push_back(rec);
};

WznmAMControlPar* ListWznmAMControlPar::operator[](
			const uint ix
		) {
	WznmAMControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMControlPar& ListWznmAMControlPar::operator=(
			const ListWznmAMControlPar& src
		) {
	WznmAMControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMControlPar::operator==(
			const ListWznmAMControlPar& comp
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

bool ListWznmAMControlPar::operator!=(
			const ListWznmAMControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMControlPar
 ******************************************************************************/

TblWznmAMControlPar::TblWznmAMControlPar() {
};

TblWznmAMControlPar::~TblWznmAMControlPar() {
};

bool TblWznmAMControlPar::loadRecBySQL(
			const string& sqlstr
			, WznmAMControlPar** rec
		) {
	return false;
};

ubigint TblWznmAMControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	return 0;
};

ubigint TblWznmAMControlPar::insertRec(
			WznmAMControlPar* rec
		) {
	return 0;
};

ubigint TblWznmAMControlPar::insertNewRec(
			WznmAMControlPar** rec
			, const ubigint refWznmMControl
			, const string x1SrefKKey
			, const ubigint x2RefWznmMLocale
			, const string osrefKVal
		) {
	ubigint retval = 0;
	WznmAMControlPar* _rec = NULL;

	_rec = new WznmAMControlPar(0, refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMControlPar::appendNewRecToRst(
			ListWznmAMControlPar& rst
			, WznmAMControlPar** rec
			, const ubigint refWznmMControl
			, const string x1SrefKKey
			, const ubigint x2RefWznmMLocale
			, const string osrefKVal
		) {
	ubigint retval = 0;
	WznmAMControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMControlPar::insertRst(
			ListWznmAMControlPar& rst
			, bool transact
		) {
};

void TblWznmAMControlPar::updateRec(
			WznmAMControlPar* rec
		) {
};

void TblWznmAMControlPar::updateRst(
			ListWznmAMControlPar& rst
			, bool transact
		) {
};

void TblWznmAMControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMControlPar::loadRecByRef(
			ubigint ref
			, WznmAMControlPar** rec
		) {
	return false;
};

ubigint TblWznmAMControlPar::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMControlPar::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	return 0;
};

bool TblWznmAMControlPar::loadValByConKeyLoc(
			ubigint refWznmMControl
			, string x1SrefKKey
			, ubigint x2RefWznmMLocale
			, string& osrefKVal
		) {
	return false;
};

ubigint TblWznmAMControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	ubigint numload = 0;
	WznmAMControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMControlPar
 ******************************************************************************/

MyTblWznmAMControlPar::MyTblWznmAMControlPar() :
			TblWznmAMControlPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMControlPar::~MyTblWznmAMControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMControlPar (refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMControlPar SET refWznmMControl = ?, x1SrefKKey = ?, x2RefWznmMLocale = ?, osrefKVal = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMControlPar WHERE ref = ?", false);
};

bool MyTblWznmAMControlPar::loadRecBySQL(
			const string& sqlstr
			, WznmAMControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMControlPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMControlPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMControl = atoll((char*) dbrow[1]); else _rec->refWznmMControl = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[4]) _rec->osrefKVal.assign(dbrow[4], dblengths[4]); else _rec->osrefKVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMControlPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMControlPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMControl = atoll((char*) dbrow[1]); else rec->refWznmMControl = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[4]) rec->osrefKVal.assign(dbrow[4], dblengths[4]); else rec->osrefKVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMControlPar::insertRec(
			WznmAMControlPar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[3] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMControlPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMControlPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMControlPar::insertRst(
			ListWznmAMControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMControlPar::updateRec(
			WznmAMControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->x1SrefKKey.length();
	l[3] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMControlPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMControlPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMControlPar::updateRst(
			ListWznmAMControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMControlPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMControlPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMControlPar::loadRecByRef(
			ubigint ref
			, WznmAMControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMControlPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMControlPar::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMControlPar WHERE refWznmMControl = " + to_string(refWznmMControl) + "", append, refs);
};

ubigint MyTblWznmAMControlPar::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal FROM TblWznmAMControlPar WHERE refWznmMControl = " + to_string(refWznmMControl) + " ORDER BY x1SrefKKey ASC, x2RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmAMControlPar::loadValByConKeyLoc(
			ubigint refWznmMControl
			, string x1SrefKKey
			, ubigint x2RefWznmMLocale
			, string& osrefKVal
		) {
	return loadStringBySQL("SELECT osrefKVal FROM TblWznmAMControlPar WHERE refWznmMControl = " + to_string(refWznmMControl) + " AND x1SrefKKey = '" + x1SrefKKey + "' AND x2RefWznmMLocale = " + to_string(x2RefWznmMLocale) + "", osrefKVal);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMControlPar
 ******************************************************************************/

PgTblWznmAMControlPar::PgTblWznmAMControlPar() :
			TblWznmAMControlPar()
			, PgTable()
		{
};

PgTblWznmAMControlPar::~PgTblWznmAMControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMControlPar::initStatements() {
	createStatement("TblWznmAMControlPar_insertRec", "INSERT INTO TblWznmAMControlPar (refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMControlPar_updateRec", "UPDATE TblWznmAMControlPar SET refWznmMControl = $1, x1SrefKKey = $2, x2RefWznmMLocale = $3, osrefKVal = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMControlPar_removeRecByRef", "DELETE FROM TblWznmAMControlPar WHERE ref = $1", 1);

	createStatement("TblWznmAMControlPar_loadRecByRef", "SELECT ref, refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal FROM TblWznmAMControlPar WHERE ref = $1", 1);
	createStatement("TblWznmAMControlPar_loadRefsByCon", "SELECT ref FROM TblWznmAMControlPar WHERE refWznmMControl = $1", 1);
	createStatement("TblWznmAMControlPar_loadRstByCon", "SELECT ref, refWznmMControl, x1SrefKKey, x2RefWznmMLocale, osrefKVal FROM TblWznmAMControlPar WHERE refWznmMControl = $1 ORDER BY x1SrefKKey ASC, x2RefWznmMLocale ASC", 1);
	createStatement("TblWznmAMControlPar_loadValByConKeyLoc", "SELECT osrefKVal FROM TblWznmAMControlPar WHERE refWznmMControl = $1 AND x1SrefKKey = $2 AND x2RefWznmMLocale = $3", 3);
};

bool PgTblWznmAMControlPar::loadRec(
			PGresult* res
			, WznmAMControlPar** rec
		) {
	char* ptr;

	WznmAMControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "osrefkval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->osrefKVal.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "osrefkval")
		};

		while (numread < numrow) {
			rec = new WznmAMControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->osrefKVal.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMControlPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMControlPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMControlPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMControlPar::loadRecBySQL(
			const string& sqlstr
			, WznmAMControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMControlPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMControlPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMControlPar::insertRec(
			WznmAMControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		rec->x1SrefKKey.c_str(),
		(char*) &_x2RefWznmMLocale,
		rec->osrefKVal.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMControlPar_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMControlPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMControlPar::insertRst(
			ListWznmAMControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMControlPar::updateRec(
			WznmAMControlPar* rec
		) {
	PGresult* res;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		rec->x1SrefKKey.c_str(),
		(char*) &_x2RefWznmMLocale,
		rec->osrefKVal.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMControlPar_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMControlPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMControlPar::updateRst(
			ListWznmAMControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMControlPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMControlPar::loadRecByRef(
			ubigint ref
			, WznmAMControlPar** rec
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

	return loadRecByStmt("TblWznmAMControlPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMControlPar::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMControlPar_loadRefsByCon", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMControlPar::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmAMControlPar& rst
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMControlPar_loadRstByCon", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMControlPar::loadValByConKeyLoc(
			ubigint refWznmMControl
			, string x1SrefKKey
			, ubigint x2RefWznmMLocale
			, string& osrefKVal
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);
	ubigint _x2RefWznmMLocale = htonl64(x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		x1SrefKKey.c_str(),
		(char*) &_x2RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1,0,1};

	return loadStringByStmt("TblWznmAMControlPar_loadValByConKeyLoc", 3, vals, l, f, osrefKVal);
};

#endif

