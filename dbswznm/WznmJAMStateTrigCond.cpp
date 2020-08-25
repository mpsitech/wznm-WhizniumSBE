/**
	* \file WznmJAMStateTrigCond.cpp
	* database access for table TblWznmJAMStateTrigCond (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmJAMStateTrigCond.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJAMStateTrigCond
 ******************************************************************************/

WznmJAMStateTrigCond::WznmJAMStateTrigCond(
			const ubigint ref
			, const ubigint refWznmAMStateTrig
			, const uint x1IxWznmVApptarget
			, const string Cond
		) {

	this->ref = ref;
	this->refWznmAMStateTrig = refWznmAMStateTrig;
	this->x1IxWznmVApptarget = x1IxWznmVApptarget;
	this->Cond = Cond;
};

bool WznmJAMStateTrigCond::operator==(
			const WznmJAMStateTrigCond& comp
		) {
	return false;
};

bool WznmJAMStateTrigCond::operator!=(
			const WznmJAMStateTrigCond& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJAMStateTrigCond
 ******************************************************************************/

ListWznmJAMStateTrigCond::ListWznmJAMStateTrigCond() {
};

ListWznmJAMStateTrigCond::ListWznmJAMStateTrigCond(
			const ListWznmJAMStateTrigCond& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJAMStateTrigCond(*(src.nodes[i]));
};

ListWznmJAMStateTrigCond::~ListWznmJAMStateTrigCond() {
	clear();
};

void ListWznmJAMStateTrigCond::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJAMStateTrigCond::size() const {
	return(nodes.size());
};

void ListWznmJAMStateTrigCond::append(
			WznmJAMStateTrigCond* rec
		) {
	nodes.push_back(rec);
};

WznmJAMStateTrigCond* ListWznmJAMStateTrigCond::operator[](
			const uint ix
		) {
	WznmJAMStateTrigCond* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJAMStateTrigCond& ListWznmJAMStateTrigCond::operator=(
			const ListWznmJAMStateTrigCond& src
		) {
	WznmJAMStateTrigCond* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJAMStateTrigCond(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJAMStateTrigCond::operator==(
			const ListWznmJAMStateTrigCond& comp
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

bool ListWznmJAMStateTrigCond::operator!=(
			const ListWznmJAMStateTrigCond& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJAMStateTrigCond
 ******************************************************************************/

TblWznmJAMStateTrigCond::TblWznmJAMStateTrigCond() {
};

TblWznmJAMStateTrigCond::~TblWznmJAMStateTrigCond() {
};

bool TblWznmJAMStateTrigCond::loadRecBySQL(
			const string& sqlstr
			, WznmJAMStateTrigCond** rec
		) {
	return false;
};

ubigint TblWznmJAMStateTrigCond::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	return 0;
};

ubigint TblWznmJAMStateTrigCond::insertRec(
			WznmJAMStateTrigCond* rec
		) {
	return 0;
};

ubigint TblWznmJAMStateTrigCond::insertNewRec(
			WznmJAMStateTrigCond** rec
			, const ubigint refWznmAMStateTrig
			, const uint x1IxWznmVApptarget
			, const string Cond
		) {
	ubigint retval = 0;
	WznmJAMStateTrigCond* _rec = NULL;

	_rec = new WznmJAMStateTrigCond(0, refWznmAMStateTrig, x1IxWznmVApptarget, Cond);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJAMStateTrigCond::appendNewRecToRst(
			ListWznmJAMStateTrigCond& rst
			, WznmJAMStateTrigCond** rec
			, const ubigint refWznmAMStateTrig
			, const uint x1IxWznmVApptarget
			, const string Cond
		) {
	ubigint retval = 0;
	WznmJAMStateTrigCond* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmAMStateTrig, x1IxWznmVApptarget, Cond);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJAMStateTrigCond::insertRst(
			ListWznmJAMStateTrigCond& rst
			, bool transact
		) {
};

void TblWznmJAMStateTrigCond::updateRec(
			WznmJAMStateTrigCond* rec
		) {
};

void TblWznmJAMStateTrigCond::updateRst(
			ListWznmJAMStateTrigCond& rst
			, bool transact
		) {
};

void TblWznmJAMStateTrigCond::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJAMStateTrigCond::loadRecByRef(
			ubigint ref
			, WznmJAMStateTrigCond** rec
		) {
	return false;
};

bool TblWznmJAMStateTrigCond::loadCndByStrTrg(
			ubigint refWznmAMStateTrig
			, uint x1IxWznmVApptarget
			, string& Cond
		) {
	return false;
};

bool TblWznmJAMStateTrigCond::loadRecByStrTrg(
			ubigint refWznmAMStateTrig
			, uint x1IxWznmVApptarget
			, WznmJAMStateTrigCond** rec
		) {
	return false;
};

ubigint TblWznmJAMStateTrigCond::loadRefsByStr(
			ubigint refWznmAMStateTrig
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJAMStateTrigCond::loadRstByStr(
			ubigint refWznmAMStateTrig
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	return 0;
};

ubigint TblWznmJAMStateTrigCond::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	ubigint numload = 0;
	WznmJAMStateTrigCond* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJAMStateTrigCond
 ******************************************************************************/

MyTblWznmJAMStateTrigCond::MyTblWznmJAMStateTrigCond() :
			TblWznmJAMStateTrigCond()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJAMStateTrigCond::~MyTblWznmJAMStateTrigCond() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJAMStateTrigCond::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJAMStateTrigCond (refWznmAMStateTrig, x1IxWznmVApptarget, Cond) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJAMStateTrigCond SET refWznmAMStateTrig = ?, x1IxWznmVApptarget = ?, Cond = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJAMStateTrigCond WHERE ref = ?", false);
};

bool MyTblWznmJAMStateTrigCond::loadRecBySQL(
			const string& sqlstr
			, WznmJAMStateTrigCond** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJAMStateTrigCond* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJAMStateTrigCond::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJAMStateTrigCond::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJAMStateTrigCond();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmAMStateTrig = atoll((char*) dbrow[1]); else _rec->refWznmAMStateTrig = 0;
		if (dbrow[2]) _rec->x1IxWznmVApptarget = atol((char*) dbrow[2]); else _rec->x1IxWznmVApptarget = 0;
		if (dbrow[3]) _rec->Cond.assign(dbrow[3], dblengths[3]); else _rec->Cond = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJAMStateTrigCond::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJAMStateTrigCond* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJAMStateTrigCond::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJAMStateTrigCond::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJAMStateTrigCond();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmAMStateTrig = atoll((char*) dbrow[1]); else rec->refWznmAMStateTrig = 0;
			if (dbrow[2]) rec->x1IxWznmVApptarget = atol((char*) dbrow[2]); else rec->x1IxWznmVApptarget = 0;
			if (dbrow[3]) rec->Cond.assign(dbrow[3], dblengths[3]); else rec->Cond = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJAMStateTrigCond::insertRec(
			WznmJAMStateTrigCond* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Cond.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmAMStateTrig,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVApptarget,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJAMStateTrigCond::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJAMStateTrigCond::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJAMStateTrigCond::insertRst(
			ListWznmJAMStateTrigCond& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJAMStateTrigCond::updateRec(
			WznmJAMStateTrigCond* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Cond.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmAMStateTrig,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWznmVApptarget,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJAMStateTrigCond::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJAMStateTrigCond::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJAMStateTrigCond::updateRst(
			ListWznmJAMStateTrigCond& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJAMStateTrigCond::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJAMStateTrigCond::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJAMStateTrigCond::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJAMStateTrigCond::loadRecByRef(
			ubigint ref
			, WznmJAMStateTrigCond** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJAMStateTrigCond WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJAMStateTrigCond::loadCndByStrTrg(
			ubigint refWznmAMStateTrig
			, uint x1IxWznmVApptarget
			, string& Cond
		) {
	return loadStringBySQL("SELECT Cond FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = " + to_string(refWznmAMStateTrig) + " AND x1IxWznmVApptarget = " + to_string(x1IxWznmVApptarget) + "", Cond);
};

bool MyTblWznmJAMStateTrigCond::loadRecByStrTrg(
			ubigint refWznmAMStateTrig
			, uint x1IxWznmVApptarget
			, WznmJAMStateTrigCond** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmAMStateTrig, x1IxWznmVApptarget, Cond FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = " + to_string(refWznmAMStateTrig) + " AND x1IxWznmVApptarget = " + to_string(x1IxWznmVApptarget) + "", rec);
};

ubigint MyTblWznmJAMStateTrigCond::loadRefsByStr(
			ubigint refWznmAMStateTrig
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = " + to_string(refWznmAMStateTrig) + "", append, refs);
};

ubigint MyTblWznmJAMStateTrigCond::loadRstByStr(
			ubigint refWznmAMStateTrig
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmAMStateTrig, x1IxWznmVApptarget, Cond FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = " + to_string(refWznmAMStateTrig) + " ORDER BY x1IxWznmVApptarget ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJAMStateTrigCond
 ******************************************************************************/

PgTblWznmJAMStateTrigCond::PgTblWznmJAMStateTrigCond() :
			TblWznmJAMStateTrigCond()
			, PgTable()
		{
};

PgTblWznmJAMStateTrigCond::~PgTblWznmJAMStateTrigCond() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJAMStateTrigCond::initStatements() {
	createStatement("TblWznmJAMStateTrigCond_insertRec", "INSERT INTO TblWznmJAMStateTrigCond (refWznmAMStateTrig, x1IxWznmVApptarget, Cond) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJAMStateTrigCond_updateRec", "UPDATE TblWznmJAMStateTrigCond SET refWznmAMStateTrig = $1, x1IxWznmVApptarget = $2, Cond = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJAMStateTrigCond_removeRecByRef", "DELETE FROM TblWznmJAMStateTrigCond WHERE ref = $1", 1);

	createStatement("TblWznmJAMStateTrigCond_loadRecByRef", "SELECT ref, refWznmAMStateTrig, x1IxWznmVApptarget, Cond FROM TblWznmJAMStateTrigCond WHERE ref = $1", 1);
	createStatement("TblWznmJAMStateTrigCond_loadCndByStrTrg", "SELECT Cond FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = $1 AND x1IxWznmVApptarget = $2", 2);
	createStatement("TblWznmJAMStateTrigCond_loadRecByStrTrg", "SELECT ref, refWznmAMStateTrig, x1IxWznmVApptarget, Cond FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = $1 AND x1IxWznmVApptarget = $2", 2);
	createStatement("TblWznmJAMStateTrigCond_loadRefsByStr", "SELECT ref FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = $1", 1);
	createStatement("TblWznmJAMStateTrigCond_loadRstByStr", "SELECT ref, refWznmAMStateTrig, x1IxWznmVApptarget, Cond FROM TblWznmJAMStateTrigCond WHERE refWznmAMStateTrig = $1 ORDER BY x1IxWznmVApptarget ASC", 1);
};

bool PgTblWznmJAMStateTrigCond::loadRec(
			PGresult* res
			, WznmJAMStateTrigCond** rec
		) {
	char* ptr;

	WznmJAMStateTrigCond* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJAMStateTrigCond();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmamstatetrig"),
			PQfnumber(res, "x1ixwznmvapptarget"),
			PQfnumber(res, "cond")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmAMStateTrig = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWznmVApptarget = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Cond.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJAMStateTrigCond::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJAMStateTrigCond* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmamstatetrig"),
			PQfnumber(res, "x1ixwznmvapptarget"),
			PQfnumber(res, "cond")
		};

		while (numread < numrow) {
			rec = new WznmJAMStateTrigCond();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmAMStateTrig = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWznmVApptarget = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Cond.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJAMStateTrigCond::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJAMStateTrigCond** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJAMStateTrigCond::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJAMStateTrigCond::loadRecBySQL(
			const string& sqlstr
			, WznmJAMStateTrigCond** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJAMStateTrigCond::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJAMStateTrigCond::insertRec(
			WznmJAMStateTrigCond* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmAMStateTrig = htonl64(rec->refWznmAMStateTrig);
	uint _x1IxWznmVApptarget = htonl(rec->x1IxWznmVApptarget);

	const char* vals[] = {
		(char*) &_refWznmAMStateTrig,
		(char*) &_x1IxWznmVApptarget,
		rec->Cond.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJAMStateTrigCond_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJAMStateTrigCond::insertRst(
			ListWznmJAMStateTrigCond& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJAMStateTrigCond::updateRec(
			WznmJAMStateTrigCond* rec
		) {
	PGresult* res;

	ubigint _refWznmAMStateTrig = htonl64(rec->refWznmAMStateTrig);
	uint _x1IxWznmVApptarget = htonl(rec->x1IxWznmVApptarget);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmAMStateTrig,
		(char*) &_x1IxWznmVApptarget,
		rec->Cond.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJAMStateTrigCond_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJAMStateTrigCond::updateRst(
			ListWznmJAMStateTrigCond& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJAMStateTrigCond::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJAMStateTrigCond_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJAMStateTrigCond::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJAMStateTrigCond::loadRecByRef(
			ubigint ref
			, WznmJAMStateTrigCond** rec
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

	return loadRecByStmt("TblWznmJAMStateTrigCond_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJAMStateTrigCond::loadCndByStrTrg(
			ubigint refWznmAMStateTrig
			, uint x1IxWznmVApptarget
			, string& Cond
		) {
	ubigint _refWznmAMStateTrig = htonl64(refWznmAMStateTrig);
	uint _x1IxWznmVApptarget = htonl(x1IxWznmVApptarget);

	const char* vals[] = {
		(char*) &_refWznmAMStateTrig,
		(char*) &_x1IxWznmVApptarget
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJAMStateTrigCond_loadCndByStrTrg", 2, vals, l, f, Cond);
};

bool PgTblWznmJAMStateTrigCond::loadRecByStrTrg(
			ubigint refWznmAMStateTrig
			, uint x1IxWznmVApptarget
			, WznmJAMStateTrigCond** rec
		) {
	ubigint _refWznmAMStateTrig = htonl64(refWznmAMStateTrig);
	uint _x1IxWznmVApptarget = htonl(x1IxWznmVApptarget);

	const char* vals[] = {
		(char*) &_refWznmAMStateTrig,
		(char*) &_x1IxWznmVApptarget
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJAMStateTrigCond_loadRecByStrTrg", 2, vals, l, f, rec);
};

ubigint PgTblWznmJAMStateTrigCond::loadRefsByStr(
			ubigint refWznmAMStateTrig
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmAMStateTrig = htonl64(refWznmAMStateTrig);

	const char* vals[] = {
		(char*) &_refWznmAMStateTrig
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJAMStateTrigCond_loadRefsByStr", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJAMStateTrigCond::loadRstByStr(
			ubigint refWznmAMStateTrig
			, const bool append
			, ListWznmJAMStateTrigCond& rst
		) {
	ubigint _refWznmAMStateTrig = htonl64(refWznmAMStateTrig);

	const char* vals[] = {
		(char*) &_refWznmAMStateTrig
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJAMStateTrigCond_loadRstByStr", 1, vals, l, f, append, rst);
};

#endif

