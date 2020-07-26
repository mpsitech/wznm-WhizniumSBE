/**
	* \file WznmAMQueryClause.cpp
	* database access for table TblWznmAMQueryClause (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmAMQueryClause.h"

#include "WznmAMQueryClause_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMQueryClause
 ******************************************************************************/

WznmAMQueryClause::WznmAMQueryClause(
			const ubigint ref
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint x1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string Clause
			, const ubigint refWznmMPreset
			, const ubigint refWznmMVector
			, const ubigint refWznmMVectoritem
		) {

	this->ref = ref;
	this->qryRefWznmMQuery = qryRefWznmMQuery;
	this->qryNum = qryNum;
	this->x1RefWznmMQuerymod = x1RefWznmMQuerymod;
	this->ixVBasetype = ixVBasetype;
	this->Clause = Clause;
	this->refWznmMPreset = refWznmMPreset;
	this->refWznmMVector = refWznmMVector;
	this->refWznmMVectoritem = refWznmMVectoritem;
};

bool WznmAMQueryClause::operator==(
			const WznmAMQueryClause& comp
		) {
	return false;
};

bool WznmAMQueryClause::operator!=(
			const WznmAMQueryClause& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMQueryClause
 ******************************************************************************/

ListWznmAMQueryClause::ListWznmAMQueryClause() {
};

ListWznmAMQueryClause::ListWznmAMQueryClause(
			const ListWznmAMQueryClause& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMQueryClause(*(src.nodes[i]));
};

ListWznmAMQueryClause::~ListWznmAMQueryClause() {
	clear();
};

void ListWznmAMQueryClause::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMQueryClause::size() const {
	return(nodes.size());
};

void ListWznmAMQueryClause::append(
			WznmAMQueryClause* rec
		) {
	nodes.push_back(rec);
};

WznmAMQueryClause* ListWznmAMQueryClause::operator[](
			const uint ix
		) {
	WznmAMQueryClause* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMQueryClause& ListWznmAMQueryClause::operator=(
			const ListWznmAMQueryClause& src
		) {
	WznmAMQueryClause* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMQueryClause(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMQueryClause::operator==(
			const ListWznmAMQueryClause& comp
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

bool ListWznmAMQueryClause::operator!=(
			const ListWznmAMQueryClause& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMQueryClause
 ******************************************************************************/

TblWznmAMQueryClause::TblWznmAMQueryClause() {
};

TblWznmAMQueryClause::~TblWznmAMQueryClause() {
};

bool TblWznmAMQueryClause::loadRecBySQL(
			const string& sqlstr
			, WznmAMQueryClause** rec
		) {
	return false;
};

ubigint TblWznmAMQueryClause::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	return 0;
};

ubigint TblWznmAMQueryClause::insertRec(
			WznmAMQueryClause* rec
		) {
	return 0;
};

ubigint TblWznmAMQueryClause::insertNewRec(
			WznmAMQueryClause** rec
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint x1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string Clause
			, const ubigint refWznmMPreset
			, const ubigint refWznmMVector
			, const ubigint refWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmAMQueryClause* _rec = NULL;

	_rec = new WznmAMQueryClause(0, qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMQueryClause::appendNewRecToRst(
			ListWznmAMQueryClause& rst
			, WznmAMQueryClause** rec
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint x1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string Clause
			, const ubigint refWznmMPreset
			, const ubigint refWznmMVector
			, const ubigint refWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmAMQueryClause* _rec = NULL;

	retval = insertNewRec(&_rec, qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMQueryClause::insertRst(
			ListWznmAMQueryClause& rst
			, bool transact
		) {
};

void TblWznmAMQueryClause::updateRec(
			WznmAMQueryClause* rec
		) {
};

void TblWznmAMQueryClause::updateRst(
			ListWznmAMQueryClause& rst
			, bool transact
		) {
};

void TblWznmAMQueryClause::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMQueryClause::loadRecByRef(
			ubigint ref
			, WznmAMQueryClause** rec
		) {
	return false;
};

ubigint TblWznmAMQueryClause::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMQueryClause::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	return 0;
};

ubigint TblWznmAMQueryClause::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	ubigint numload = 0;
	WznmAMQueryClause* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMQueryClause
 ******************************************************************************/

MyTblWznmAMQueryClause::MyTblWznmAMQueryClause() :
			TblWznmAMQueryClause()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMQueryClause::~MyTblWznmAMQueryClause() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMQueryClause::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMQueryClause (qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMQueryClause SET qryRefWznmMQuery = ?, qryNum = ?, x1RefWznmMQuerymod = ?, ixVBasetype = ?, Clause = ?, refWznmMPreset = ?, refWznmMVector = ?, refWznmMVectoritem = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMQueryClause WHERE ref = ?", false);
};

bool MyTblWznmAMQueryClause::loadRecBySQL(
			const string& sqlstr
			, WznmAMQueryClause** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMQueryClause* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMQueryClause::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMQueryClause::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMQueryClause();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->qryRefWznmMQuery = atoll((char*) dbrow[1]); else _rec->qryRefWznmMQuery = 0;
		if (dbrow[2]) _rec->qryNum = atol((char*) dbrow[2]); else _rec->qryNum = 0;
		if (dbrow[3]) _rec->x1RefWznmMQuerymod = atoll((char*) dbrow[3]); else _rec->x1RefWznmMQuerymod = 0;
		if (dbrow[4]) _rec->ixVBasetype = atol((char*) dbrow[4]); else _rec->ixVBasetype = 0;
		if (dbrow[5]) _rec->Clause.assign(dbrow[5], dblengths[5]); else _rec->Clause = "";
		if (dbrow[6]) _rec->refWznmMPreset = atoll((char*) dbrow[6]); else _rec->refWznmMPreset = 0;
		if (dbrow[7]) _rec->refWznmMVector = atoll((char*) dbrow[7]); else _rec->refWznmMVector = 0;
		if (dbrow[8]) _rec->refWznmMVectoritem = atoll((char*) dbrow[8]); else _rec->refWznmMVectoritem = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMQueryClause::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMQueryClause* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMQueryClause::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMQueryClause::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMQueryClause();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->qryRefWznmMQuery = atoll((char*) dbrow[1]); else rec->qryRefWznmMQuery = 0;
			if (dbrow[2]) rec->qryNum = atol((char*) dbrow[2]); else rec->qryNum = 0;
			if (dbrow[3]) rec->x1RefWznmMQuerymod = atoll((char*) dbrow[3]); else rec->x1RefWznmMQuerymod = 0;
			if (dbrow[4]) rec->ixVBasetype = atol((char*) dbrow[4]); else rec->ixVBasetype = 0;
			if (dbrow[5]) rec->Clause.assign(dbrow[5], dblengths[5]); else rec->Clause = "";
			if (dbrow[6]) rec->refWznmMPreset = atoll((char*) dbrow[6]); else rec->refWznmMPreset = 0;
			if (dbrow[7]) rec->refWznmMVector = atoll((char*) dbrow[7]); else rec->refWznmMVector = 0;
			if (dbrow[8]) rec->refWznmMVectoritem = atoll((char*) dbrow[8]); else rec->refWznmMVectoritem = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMQueryClause::insertRec(
			WznmAMQueryClause* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->Clause.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->qryRefWznmMQuery,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->qryNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefWznmMQuerymod,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Clause.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMPreset,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMQueryClause::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMQueryClause::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMQueryClause::insertRst(
			ListWznmAMQueryClause& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMQueryClause::updateRec(
			WznmAMQueryClause* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->Clause.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->qryRefWznmMQuery,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->qryNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefWznmMQuerymod,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Clause.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMPreset,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMQueryClause::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMQueryClause::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMQueryClause::updateRst(
			ListWznmAMQueryClause& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMQueryClause::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMQueryClause::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMQueryClause::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMQueryClause::loadRecByRef(
			ubigint ref
			, WznmAMQueryClause** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMQueryClause WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMQueryClause::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qryRefWznmMQuery) + "", append, refs);
};

ubigint MyTblWznmAMQueryClause::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	return loadRstBySQL("SELECT ref, qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qryRefWznmMQuery) + " ORDER BY qryNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMQueryClause
 ******************************************************************************/

PgTblWznmAMQueryClause::PgTblWznmAMQueryClause() :
			TblWznmAMQueryClause()
			, PgTable()
		{
};

PgTblWznmAMQueryClause::~PgTblWznmAMQueryClause() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMQueryClause::initStatements() {
	createStatement("TblWznmAMQueryClause_insertRec", "INSERT INTO TblWznmAMQueryClause (qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmAMQueryClause_updateRec", "UPDATE TblWznmAMQueryClause SET qryRefWznmMQuery = $1, qryNum = $2, x1RefWznmMQuerymod = $3, ixVBasetype = $4, Clause = $5, refWznmMPreset = $6, refWznmMVector = $7, refWznmMVectoritem = $8 WHERE ref = $9", 9);
	createStatement("TblWznmAMQueryClause_removeRecByRef", "DELETE FROM TblWznmAMQueryClause WHERE ref = $1", 1);

	createStatement("TblWznmAMQueryClause_loadRecByRef", "SELECT ref, qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem FROM TblWznmAMQueryClause WHERE ref = $1", 1);
	createStatement("TblWznmAMQueryClause_loadRefsByQry", "SELECT ref FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = $1", 1);
	createStatement("TblWznmAMQueryClause_loadRstByQry", "SELECT ref, qryRefWznmMQuery, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = $1 ORDER BY qryNum ASC", 1);
};

bool PgTblWznmAMQueryClause::loadRec(
			PGresult* res
			, WznmAMQueryClause** rec
		) {
	char* ptr;

	WznmAMQueryClause* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMQueryClause();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "x1refwznmmquerymod"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "clause"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qryRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->qryNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1RefWznmMQuerymod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Clause.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMVectoritem = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMQueryClause::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMQueryClause* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "x1refwznmmquerymod"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "clause"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		while (numread < numrow) {
			rec = new WznmAMQueryClause();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qryRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->qryNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1RefWznmMQuerymod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Clause.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMVectoritem = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMQueryClause::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMQueryClause** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryClause::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMQueryClause::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryClause::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMQueryClause::loadRecBySQL(
			const string& sqlstr
			, WznmAMQueryClause** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryClause::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMQueryClause::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryClause::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMQueryClause::insertRec(
			WznmAMQueryClause* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _x1RefWznmMQuerymod = htonl64(rec->x1RefWznmMQuerymod);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery,
		(char*) &_qryNum,
		(char*) &_x1RefWznmMQuerymod,
		(char*) &_ixVBasetype,
		rec->Clause.c_str(),
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAMQueryClause_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMQueryClause::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMQueryClause::insertRst(
			ListWznmAMQueryClause& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMQueryClause::updateRec(
			WznmAMQueryClause* rec
		) {
	PGresult* res;

	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _x1RefWznmMQuerymod = htonl64(rec->x1RefWznmMQuerymod);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery,
		(char*) &_qryNum,
		(char*) &_x1RefWznmMQuerymod,
		(char*) &_ixVBasetype,
		rec->Clause.c_str(),
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAMQueryClause_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMQueryClause::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMQueryClause::updateRst(
			ListWznmAMQueryClause& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMQueryClause::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMQueryClause_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMQueryClause::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMQueryClause::loadRecByRef(
			ubigint ref
			, WznmAMQueryClause** rec
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

	return loadRecByStmt("TblWznmAMQueryClause_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMQueryClause::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _qryRefWznmMQuery = htonl64(qryRefWznmMQuery);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMQueryClause_loadRefsByQry", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMQueryClause::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmAMQueryClause& rst
		) {
	ubigint _qryRefWznmMQuery = htonl64(qryRefWznmMQuery);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMQueryClause_loadRstByQry", 1, vals, l, f, append, rst);
};

#endif

