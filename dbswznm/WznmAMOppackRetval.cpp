/**
	* \file WznmAMOppackRetval.cpp
	* database access for table TblWznmAMOppackRetval (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMOppackRetval.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMOppackRetval
 ******************************************************************************/

WznmAMOppackRetval::WznmAMOppackRetval(
			const ubigint ref
			, const ubigint refWznmCAMOppackRetval
			, const ubigint opkRefWznmMOppack
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmCAMOppackRetval = refWznmCAMOppackRetval;
	this->opkRefWznmMOppack = opkRefWznmMOppack;
	this->opkNum = opkNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->Comment = Comment;
};

bool WznmAMOppackRetval::operator==(
			const WznmAMOppackRetval& comp
		) {
	return false;
};

bool WznmAMOppackRetval::operator!=(
			const WznmAMOppackRetval& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMOppackRetval
 ******************************************************************************/

ListWznmAMOppackRetval::ListWznmAMOppackRetval() {
};

ListWznmAMOppackRetval::ListWznmAMOppackRetval(
			const ListWznmAMOppackRetval& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMOppackRetval(*(src.nodes[i]));
};

ListWznmAMOppackRetval::~ListWznmAMOppackRetval() {
	clear();
};

void ListWznmAMOppackRetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMOppackRetval::size() const {
	return(nodes.size());
};

void ListWznmAMOppackRetval::append(
			WznmAMOppackRetval* rec
		) {
	nodes.push_back(rec);
};

WznmAMOppackRetval* ListWznmAMOppackRetval::operator[](
			const uint ix
		) {
	WznmAMOppackRetval* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMOppackRetval& ListWznmAMOppackRetval::operator=(
			const ListWznmAMOppackRetval& src
		) {
	WznmAMOppackRetval* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMOppackRetval(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMOppackRetval::operator==(
			const ListWznmAMOppackRetval& comp
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

bool ListWznmAMOppackRetval::operator!=(
			const ListWznmAMOppackRetval& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMOppackRetval
 ******************************************************************************/

TblWznmAMOppackRetval::TblWznmAMOppackRetval() {
};

TblWznmAMOppackRetval::~TblWznmAMOppackRetval() {
};

bool TblWznmAMOppackRetval::loadRecBySQL(
			const string& sqlstr
			, WznmAMOppackRetval** rec
		) {
	return false;
};

ubigint TblWznmAMOppackRetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	return 0;
};

ubigint TblWznmAMOppackRetval::insertRec(
			WznmAMOppackRetval* rec
		) {
	return 0;
};

ubigint TblWznmAMOppackRetval::insertNewRec(
			WznmAMOppackRetval** rec
			, const ubigint refWznmCAMOppackRetval
			, const ubigint opkRefWznmMOppack
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOppackRetval* _rec = NULL;

	_rec = new WznmAMOppackRetval(0, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMOppackRetval::appendNewRecToRst(
			ListWznmAMOppackRetval& rst
			, WznmAMOppackRetval** rec
			, const ubigint refWznmCAMOppackRetval
			, const ubigint opkRefWznmMOppack
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOppackRetval* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMOppackRetval::insertRst(
			ListWznmAMOppackRetval& rst
			, bool transact
		) {
};

void TblWznmAMOppackRetval::updateRec(
			WznmAMOppackRetval* rec
		) {
};

void TblWznmAMOppackRetval::updateRst(
			ListWznmAMOppackRetval& rst
			, bool transact
		) {
};

void TblWznmAMOppackRetval::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMOppackRetval::loadRecByRef(
			ubigint ref
			, WznmAMOppackRetval** rec
		) {
	return false;
};

ubigint TblWznmAMOppackRetval::loadRefsByClu(
			ubigint refWznmCAMOppackRetval
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOppackRetval::loadRefsByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOppackRetval::loadRstByClu(
			ubigint refWznmCAMOppackRetval
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	return 0;
};

ubigint TblWznmAMOppackRetval::loadRstByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	return 0;
};

ubigint TblWznmAMOppackRetval::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	ubigint numload = 0;
	WznmAMOppackRetval* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMOppackRetval
 ******************************************************************************/

MyTblWznmAMOppackRetval::MyTblWznmAMOppackRetval() :
			TblWznmAMOppackRetval()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMOppackRetval::~MyTblWznmAMOppackRetval() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMOppackRetval::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMOppackRetval (refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMOppackRetval SET refWznmCAMOppackRetval = ?, opkRefWznmMOppack = ?, opkNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMOppackRetval WHERE ref = ?", false);
};

bool MyTblWznmAMOppackRetval::loadRecBySQL(
			const string& sqlstr
			, WznmAMOppackRetval** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMOppackRetval* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOppackRetval::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOppackRetval::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMOppackRetval();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmCAMOppackRetval = atoll((char*) dbrow[1]); else _rec->refWznmCAMOppackRetval = 0;
		if (dbrow[2]) _rec->opkRefWznmMOppack = atoll((char*) dbrow[2]); else _rec->opkRefWznmMOppack = 0;
		if (dbrow[3]) _rec->opkNum = atol((char*) dbrow[3]); else _rec->opkNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixWznmVVartype = atol((char*) dbrow[5]); else _rec->ixWznmVVartype = 0;
		if (dbrow[6]) _rec->refWznmMVector = atoll((char*) dbrow[6]); else _rec->refWznmMVector = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMOppackRetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMOppackRetval* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOppackRetval::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOppackRetval::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMOppackRetval();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmCAMOppackRetval = atoll((char*) dbrow[1]); else rec->refWznmCAMOppackRetval = 0;
			if (dbrow[2]) rec->opkRefWznmMOppack = atoll((char*) dbrow[2]); else rec->opkRefWznmMOppack = 0;
			if (dbrow[3]) rec->opkNum = atol((char*) dbrow[3]); else rec->opkNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixWznmVVartype = atol((char*) dbrow[5]); else rec->ixWznmVVartype = 0;
			if (dbrow[6]) rec->refWznmMVector = atoll((char*) dbrow[6]); else rec->refWznmMVector = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMOppackRetval::insertRec(
			WznmAMOppackRetval* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOppackRetval,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opkRefWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opkNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMOppackRetval::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMOppackRetval::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMOppackRetval::insertRst(
			ListWznmAMOppackRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMOppackRetval::updateRec(
			WznmAMOppackRetval* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOppackRetval,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opkRefWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opkNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMOppackRetval::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMOppackRetval::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMOppackRetval::updateRst(
			ListWznmAMOppackRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMOppackRetval::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMOppackRetval::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMOppackRetval::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMOppackRetval::loadRecByRef(
			ubigint ref
			, WznmAMOppackRetval** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMOppackRetval WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMOppackRetval::loadRefsByClu(
			ubigint refWznmCAMOppackRetval
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOppackRetval WHERE refWznmCAMOppackRetval = " + to_string(refWznmCAMOppackRetval) + "", append, refs);
};

ubigint MyTblWznmAMOppackRetval::loadRefsByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOppackRetval WHERE opkRefWznmMOppack = " + to_string(opkRefWznmMOppack) + "", append, refs);
};

ubigint MyTblWznmAMOppackRetval::loadRstByClu(
			ubigint refWznmCAMOppackRetval
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOppackRetval WHERE refWznmCAMOppackRetval = " + to_string(refWznmCAMOppackRetval) + "", append, rst);
};

ubigint MyTblWznmAMOppackRetval::loadRstByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOppackRetval WHERE opkRefWznmMOppack = " + to_string(opkRefWznmMOppack) + " ORDER BY opkNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMOppackRetval
 ******************************************************************************/

PgTblWznmAMOppackRetval::PgTblWznmAMOppackRetval() :
			TblWznmAMOppackRetval()
			, PgTable()
		{
};

PgTblWznmAMOppackRetval::~PgTblWznmAMOppackRetval() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMOppackRetval::initStatements() {
	createStatement("TblWznmAMOppackRetval_insertRec", "INSERT INTO TblWznmAMOppackRetval (refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmAMOppackRetval_updateRec", "UPDATE TblWznmAMOppackRetval SET refWznmCAMOppackRetval = $1, opkRefWznmMOppack = $2, opkNum = $3, sref = $4, ixWznmVVartype = $5, refWznmMVector = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmAMOppackRetval_removeRecByRef", "DELETE FROM TblWznmAMOppackRetval WHERE ref = $1", 1);

	createStatement("TblWznmAMOppackRetval_loadRecByRef", "SELECT ref, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOppackRetval WHERE ref = $1", 1);
	createStatement("TblWznmAMOppackRetval_loadRefsByClu", "SELECT ref FROM TblWznmAMOppackRetval WHERE refWznmCAMOppackRetval = $1", 1);
	createStatement("TblWznmAMOppackRetval_loadRefsByOpk", "SELECT ref FROM TblWznmAMOppackRetval WHERE opkRefWznmMOppack = $1", 1);
	createStatement("TblWznmAMOppackRetval_loadRstByClu", "SELECT ref, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOppackRetval WHERE refWznmCAMOppackRetval = $1", 1);
	createStatement("TblWznmAMOppackRetval_loadRstByOpk", "SELECT ref, refWznmCAMOppackRetval, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOppackRetval WHERE opkRefWznmMOppack = $1 ORDER BY opkNum ASC", 1);
};

bool PgTblWznmAMOppackRetval::loadRec(
			PGresult* res
			, WznmAMOppackRetval** rec
		) {
	char* ptr;

	WznmAMOppackRetval* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMOppackRetval();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamoppackretval"),
			PQfnumber(res, "opkrefwznmmoppack"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmCAMOppackRetval = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->opkRefWznmMOppack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->opkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMOppackRetval::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMOppackRetval* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamoppackretval"),
			PQfnumber(res, "opkrefwznmmoppack"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMOppackRetval();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmCAMOppackRetval = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->opkRefWznmMOppack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->opkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMOppackRetval::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMOppackRetval** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackRetval::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOppackRetval::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackRetval::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMOppackRetval::loadRecBySQL(
			const string& sqlstr
			, WznmAMOppackRetval** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackRetval::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOppackRetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackRetval::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMOppackRetval::insertRec(
			WznmAMOppackRetval* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmCAMOppackRetval = htonl64(rec->refWznmCAMOppackRetval);
	ubigint _opkRefWznmMOppack = htonl64(rec->opkRefWznmMOppack);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackRetval,
		(char*) &_opkRefWznmMOppack,
		(char*) &_opkNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMOppackRetval_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackRetval::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMOppackRetval::insertRst(
			ListWznmAMOppackRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMOppackRetval::updateRec(
			WznmAMOppackRetval* rec
		) {
	PGresult* res;

	ubigint _refWznmCAMOppackRetval = htonl64(rec->refWznmCAMOppackRetval);
	ubigint _opkRefWznmMOppack = htonl64(rec->opkRefWznmMOppack);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackRetval,
		(char*) &_opkRefWznmMOppack,
		(char*) &_opkNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMOppackRetval_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOppackRetval::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMOppackRetval::updateRst(
			ListWznmAMOppackRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMOppackRetval::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMOppackRetval_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOppackRetval::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMOppackRetval::loadRecByRef(
			ubigint ref
			, WznmAMOppackRetval** rec
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

	return loadRecByStmt("TblWznmAMOppackRetval_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMOppackRetval::loadRefsByClu(
			ubigint refWznmCAMOppackRetval
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCAMOppackRetval = htonl64(refWznmCAMOppackRetval);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackRetval
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMOppackRetval_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOppackRetval::loadRefsByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _opkRefWznmMOppack = htonl64(opkRefWznmMOppack);

	const char* vals[] = {
		(char*) &_opkRefWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMOppackRetval_loadRefsByOpk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOppackRetval::loadRstByClu(
			ubigint refWznmCAMOppackRetval
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	ubigint _refWznmCAMOppackRetval = htonl64(refWznmCAMOppackRetval);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackRetval
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOppackRetval_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMOppackRetval::loadRstByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, ListWznmAMOppackRetval& rst
		) {
	ubigint _opkRefWznmMOppack = htonl64(opkRefWznmMOppack);

	const char* vals[] = {
		(char*) &_opkRefWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOppackRetval_loadRstByOpk", 1, vals, l, f, append, rst);
};

#endif
