/**
	* \file WznmAMOpRetval.cpp
	* database access for table TblWznmAMOpRetval (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmAMOpRetval.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMOpRetval
 ******************************************************************************/

WznmAMOpRetval::WznmAMOpRetval(
			const ubigint ref
			, const ubigint refWznmCAMOpRetval
			, const ubigint opxRefWznmMOp
			, const uint opxNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmCAMOpRetval = refWznmCAMOpRetval;
	this->opxRefWznmMOp = opxRefWznmMOp;
	this->opxNum = opxNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->Comment = Comment;
};

bool WznmAMOpRetval::operator==(
			const WznmAMOpRetval& comp
		) {
	return false;
};

bool WznmAMOpRetval::operator!=(
			const WznmAMOpRetval& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMOpRetval
 ******************************************************************************/

ListWznmAMOpRetval::ListWznmAMOpRetval() {
};

ListWznmAMOpRetval::ListWznmAMOpRetval(
			const ListWznmAMOpRetval& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMOpRetval(*(src.nodes[i]));
};

ListWznmAMOpRetval::~ListWznmAMOpRetval() {
	clear();
};

void ListWznmAMOpRetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMOpRetval::size() const {
	return(nodes.size());
};

void ListWznmAMOpRetval::append(
			WznmAMOpRetval* rec
		) {
	nodes.push_back(rec);
};

WznmAMOpRetval* ListWznmAMOpRetval::operator[](
			const uint ix
		) {
	WznmAMOpRetval* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMOpRetval& ListWznmAMOpRetval::operator=(
			const ListWznmAMOpRetval& src
		) {
	WznmAMOpRetval* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMOpRetval(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMOpRetval::operator==(
			const ListWznmAMOpRetval& comp
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

bool ListWznmAMOpRetval::operator!=(
			const ListWznmAMOpRetval& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMOpRetval
 ******************************************************************************/

TblWznmAMOpRetval::TblWznmAMOpRetval() {
};

TblWznmAMOpRetval::~TblWznmAMOpRetval() {
};

bool TblWznmAMOpRetval::loadRecBySQL(
			const string& sqlstr
			, WznmAMOpRetval** rec
		) {
	return false;
};

ubigint TblWznmAMOpRetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	return 0;
};

ubigint TblWznmAMOpRetval::insertRec(
			WznmAMOpRetval* rec
		) {
	return 0;
};

ubigint TblWznmAMOpRetval::insertNewRec(
			WznmAMOpRetval** rec
			, const ubigint refWznmCAMOpRetval
			, const ubigint opxRefWznmMOp
			, const uint opxNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOpRetval* _rec = NULL;

	_rec = new WznmAMOpRetval(0, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMOpRetval::appendNewRecToRst(
			ListWznmAMOpRetval& rst
			, WznmAMOpRetval** rec
			, const ubigint refWznmCAMOpRetval
			, const ubigint opxRefWznmMOp
			, const uint opxNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOpRetval* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMOpRetval::insertRst(
			ListWznmAMOpRetval& rst
			, bool transact
		) {
};

void TblWznmAMOpRetval::updateRec(
			WznmAMOpRetval* rec
		) {
};

void TblWznmAMOpRetval::updateRst(
			ListWznmAMOpRetval& rst
			, bool transact
		) {
};

void TblWznmAMOpRetval::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMOpRetval::loadRecByRef(
			ubigint ref
			, WznmAMOpRetval** rec
		) {
	return false;
};

ubigint TblWznmAMOpRetval::loadRefsByClu(
			ubigint refWznmCAMOpRetval
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOpRetval::loadRefsByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOpRetval::loadRstByClu(
			ubigint refWznmCAMOpRetval
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	return 0;
};

ubigint TblWznmAMOpRetval::loadRstByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	return 0;
};

ubigint TblWznmAMOpRetval::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	ubigint numload = 0;
	WznmAMOpRetval* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMOpRetval
 ******************************************************************************/

MyTblWznmAMOpRetval::MyTblWznmAMOpRetval() :
			TblWznmAMOpRetval()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMOpRetval::~MyTblWznmAMOpRetval() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMOpRetval::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMOpRetval (refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMOpRetval SET refWznmCAMOpRetval = ?, opxRefWznmMOp = ?, opxNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMOpRetval WHERE ref = ?", false);
};

bool MyTblWznmAMOpRetval::loadRecBySQL(
			const string& sqlstr
			, WznmAMOpRetval** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMOpRetval* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOpRetval::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOpRetval::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMOpRetval();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmCAMOpRetval = atoll((char*) dbrow[1]); else _rec->refWznmCAMOpRetval = 0;
		if (dbrow[2]) _rec->opxRefWznmMOp = atoll((char*) dbrow[2]); else _rec->opxRefWznmMOp = 0;
		if (dbrow[3]) _rec->opxNum = atol((char*) dbrow[3]); else _rec->opxNum = 0;
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

ubigint MyTblWznmAMOpRetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMOpRetval* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOpRetval::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOpRetval::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMOpRetval();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmCAMOpRetval = atoll((char*) dbrow[1]); else rec->refWznmCAMOpRetval = 0;
			if (dbrow[2]) rec->opxRefWznmMOp = atoll((char*) dbrow[2]); else rec->opxRefWznmMOp = 0;
			if (dbrow[3]) rec->opxNum = atol((char*) dbrow[3]); else rec->opxNum = 0;
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

ubigint MyTblWznmAMOpRetval::insertRec(
			WznmAMOpRetval* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOpRetval,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opxRefWznmMOp,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opxNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMOpRetval::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMOpRetval::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMOpRetval::insertRst(
			ListWznmAMOpRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMOpRetval::updateRec(
			WznmAMOpRetval* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOpRetval,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opxRefWznmMOp,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opxNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMOpRetval::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMOpRetval::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMOpRetval::updateRst(
			ListWznmAMOpRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMOpRetval::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMOpRetval::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMOpRetval::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMOpRetval::loadRecByRef(
			ubigint ref
			, WznmAMOpRetval** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMOpRetval WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMOpRetval::loadRefsByClu(
			ubigint refWznmCAMOpRetval
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOpRetval WHERE refWznmCAMOpRetval = " + to_string(refWznmCAMOpRetval) + "", append, refs);
};

ubigint MyTblWznmAMOpRetval::loadRefsByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOpRetval WHERE opxRefWznmMOp = " + to_string(opxRefWznmMOp) + "", append, refs);
};

ubigint MyTblWznmAMOpRetval::loadRstByClu(
			ubigint refWznmCAMOpRetval
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOpRetval WHERE refWznmCAMOpRetval = " + to_string(refWznmCAMOpRetval) + "", append, rst);
};

ubigint MyTblWznmAMOpRetval::loadRstByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOpRetval WHERE opxRefWznmMOp = " + to_string(opxRefWznmMOp) + " ORDER BY opxNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMOpRetval
 ******************************************************************************/

PgTblWznmAMOpRetval::PgTblWznmAMOpRetval() :
			TblWznmAMOpRetval()
			, PgTable()
		{
};

PgTblWznmAMOpRetval::~PgTblWznmAMOpRetval() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMOpRetval::initStatements() {
	createStatement("TblWznmAMOpRetval_insertRec", "INSERT INTO TblWznmAMOpRetval (refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmAMOpRetval_updateRec", "UPDATE TblWznmAMOpRetval SET refWznmCAMOpRetval = $1, opxRefWznmMOp = $2, opxNum = $3, sref = $4, ixWznmVVartype = $5, refWznmMVector = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmAMOpRetval_removeRecByRef", "DELETE FROM TblWznmAMOpRetval WHERE ref = $1", 1);

	createStatement("TblWznmAMOpRetval_loadRecByRef", "SELECT ref, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOpRetval WHERE ref = $1", 1);
	createStatement("TblWznmAMOpRetval_loadRefsByClu", "SELECT ref FROM TblWznmAMOpRetval WHERE refWznmCAMOpRetval = $1", 1);
	createStatement("TblWznmAMOpRetval_loadRefsByOpx", "SELECT ref FROM TblWznmAMOpRetval WHERE opxRefWznmMOp = $1", 1);
	createStatement("TblWznmAMOpRetval_loadRstByClu", "SELECT ref, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOpRetval WHERE refWznmCAMOpRetval = $1", 1);
	createStatement("TblWznmAMOpRetval_loadRstByOpx", "SELECT ref, refWznmCAMOpRetval, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmAMOpRetval WHERE opxRefWznmMOp = $1 ORDER BY opxNum ASC", 1);
};

bool PgTblWznmAMOpRetval::loadRec(
			PGresult* res
			, WznmAMOpRetval** rec
		) {
	char* ptr;

	WznmAMOpRetval* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMOpRetval();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamopretval"),
			PQfnumber(res, "opxrefwznmmop"),
			PQfnumber(res, "opxnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmCAMOpRetval = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->opxRefWznmMOp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->opxNum = atol(ptr);
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

ubigint PgTblWznmAMOpRetval::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMOpRetval* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamopretval"),
			PQfnumber(res, "opxrefwznmmop"),
			PQfnumber(res, "opxnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMOpRetval();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmCAMOpRetval = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->opxRefWznmMOp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->opxNum = atol(ptr);
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

bool PgTblWznmAMOpRetval::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMOpRetval** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpRetval::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOpRetval::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpRetval::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMOpRetval::loadRecBySQL(
			const string& sqlstr
			, WznmAMOpRetval** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpRetval::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOpRetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpRetval::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMOpRetval::insertRec(
			WznmAMOpRetval* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmCAMOpRetval = htonl64(rec->refWznmCAMOpRetval);
	ubigint _opxRefWznmMOp = htonl64(rec->opxRefWznmMOp);
	uint _opxNum = htonl(rec->opxNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);

	const char* vals[] = {
		(char*) &_refWznmCAMOpRetval,
		(char*) &_opxRefWznmMOp,
		(char*) &_opxNum,
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

	res = PQexecPrepared(dbs, "TblWznmAMOpRetval_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpRetval::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMOpRetval::insertRst(
			ListWznmAMOpRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMOpRetval::updateRec(
			WznmAMOpRetval* rec
		) {
	PGresult* res;

	ubigint _refWznmCAMOpRetval = htonl64(rec->refWznmCAMOpRetval);
	ubigint _opxRefWznmMOp = htonl64(rec->opxRefWznmMOp);
	uint _opxNum = htonl(rec->opxNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmCAMOpRetval,
		(char*) &_opxRefWznmMOp,
		(char*) &_opxNum,
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

	res = PQexecPrepared(dbs, "TblWznmAMOpRetval_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOpRetval::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMOpRetval::updateRst(
			ListWznmAMOpRetval& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMOpRetval::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMOpRetval_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOpRetval::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMOpRetval::loadRecByRef(
			ubigint ref
			, WznmAMOpRetval** rec
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

	return loadRecByStmt("TblWznmAMOpRetval_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMOpRetval::loadRefsByClu(
			ubigint refWznmCAMOpRetval
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCAMOpRetval = htonl64(refWznmCAMOpRetval);

	const char* vals[] = {
		(char*) &_refWznmCAMOpRetval
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMOpRetval_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOpRetval::loadRefsByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _opxRefWznmMOp = htonl64(opxRefWznmMOp);

	const char* vals[] = {
		(char*) &_opxRefWznmMOp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMOpRetval_loadRefsByOpx", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOpRetval::loadRstByClu(
			ubigint refWznmCAMOpRetval
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	ubigint _refWznmCAMOpRetval = htonl64(refWznmCAMOpRetval);

	const char* vals[] = {
		(char*) &_refWznmCAMOpRetval
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOpRetval_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMOpRetval::loadRstByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, ListWznmAMOpRetval& rst
		) {
	ubigint _opxRefWznmMOp = htonl64(opxRefWznmMOp);

	const char* vals[] = {
		(char*) &_opxRefWznmMOp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOpRetval_loadRstByOpx", 1, vals, l, f, append, rst);
};

#endif

