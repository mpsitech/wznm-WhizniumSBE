/**
	* \file WznmAMOpInvarg.cpp
	* database access for table TblWznmAMOpInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMOpInvarg.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMOpInvarg
 ******************************************************************************/

WznmAMOpInvarg::WznmAMOpInvarg(
			const ubigint ref
			, const ubigint refWznmCAMOpInvarg
			, const ubigint opxRefWznmMOp
			, const uint opxNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmCAMOpInvarg = refWznmCAMOpInvarg;
	this->opxRefWznmMOp = opxRefWznmMOp;
	this->opxNum = opxNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->Defval = Defval;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->Comment = Comment;
};

bool WznmAMOpInvarg::operator==(
			const WznmAMOpInvarg& comp
		) {
	return false;
};

bool WznmAMOpInvarg::operator!=(
			const WznmAMOpInvarg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMOpInvarg
 ******************************************************************************/

ListWznmAMOpInvarg::ListWznmAMOpInvarg() {
};

ListWznmAMOpInvarg::ListWznmAMOpInvarg(
			const ListWznmAMOpInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMOpInvarg(*(src.nodes[i]));
};

ListWznmAMOpInvarg::~ListWznmAMOpInvarg() {
	clear();
};

void ListWznmAMOpInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMOpInvarg::size() const {
	return(nodes.size());
};

void ListWznmAMOpInvarg::append(
			WznmAMOpInvarg* rec
		) {
	nodes.push_back(rec);
};

WznmAMOpInvarg* ListWznmAMOpInvarg::operator[](
			const uint ix
		) {
	WznmAMOpInvarg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMOpInvarg& ListWznmAMOpInvarg::operator=(
			const ListWznmAMOpInvarg& src
		) {
	WznmAMOpInvarg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMOpInvarg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMOpInvarg::operator==(
			const ListWznmAMOpInvarg& comp
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

bool ListWznmAMOpInvarg::operator!=(
			const ListWznmAMOpInvarg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMOpInvarg
 ******************************************************************************/

TblWznmAMOpInvarg::TblWznmAMOpInvarg() {
};

TblWznmAMOpInvarg::~TblWznmAMOpInvarg() {
};

bool TblWznmAMOpInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmAMOpInvarg** rec
		) {
	return false;
};

ubigint TblWznmAMOpInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	return 0;
};

ubigint TblWznmAMOpInvarg::insertRec(
			WznmAMOpInvarg* rec
		) {
	return 0;
};

ubigint TblWznmAMOpInvarg::insertNewRec(
			WznmAMOpInvarg** rec
			, const ubigint refWznmCAMOpInvarg
			, const ubigint opxRefWznmMOp
			, const uint opxNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOpInvarg* _rec = NULL;

	_rec = new WznmAMOpInvarg(0, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMOpInvarg::appendNewRecToRst(
			ListWznmAMOpInvarg& rst
			, WznmAMOpInvarg** rec
			, const ubigint refWznmCAMOpInvarg
			, const ubigint opxRefWznmMOp
			, const uint opxNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOpInvarg* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMOpInvarg::insertRst(
			ListWznmAMOpInvarg& rst
			, bool transact
		) {
};

void TblWznmAMOpInvarg::updateRec(
			WznmAMOpInvarg* rec
		) {
};

void TblWznmAMOpInvarg::updateRst(
			ListWznmAMOpInvarg& rst
			, bool transact
		) {
};

void TblWznmAMOpInvarg::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMOpInvarg::loadRecByRef(
			ubigint ref
			, WznmAMOpInvarg** rec
		) {
	return false;
};

ubigint TblWznmAMOpInvarg::loadRefsByClu(
			ubigint refWznmCAMOpInvarg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOpInvarg::loadRefsByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOpInvarg::loadRstByClu(
			ubigint refWznmCAMOpInvarg
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	return 0;
};

ubigint TblWznmAMOpInvarg::loadRstByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	return 0;
};

ubigint TblWznmAMOpInvarg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	ubigint numload = 0;
	WznmAMOpInvarg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMOpInvarg
 ******************************************************************************/

MyTblWznmAMOpInvarg::MyTblWznmAMOpInvarg() :
			TblWznmAMOpInvarg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMOpInvarg::~MyTblWznmAMOpInvarg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMOpInvarg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMOpInvarg (refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMOpInvarg SET refWznmCAMOpInvarg = ?, opxRefWznmMOp = ?, opxNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Defval = ?, refWznmMVectoritem = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMOpInvarg WHERE ref = ?", false);
};

bool MyTblWznmAMOpInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmAMOpInvarg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMOpInvarg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOpInvarg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOpInvarg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMOpInvarg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmCAMOpInvarg = atoll((char*) dbrow[1]); else _rec->refWznmCAMOpInvarg = 0;
		if (dbrow[2]) _rec->opxRefWznmMOp = atoll((char*) dbrow[2]); else _rec->opxRefWznmMOp = 0;
		if (dbrow[3]) _rec->opxNum = atol((char*) dbrow[3]); else _rec->opxNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixWznmVVartype = atol((char*) dbrow[5]); else _rec->ixWznmVVartype = 0;
		if (dbrow[6]) _rec->refWznmMVector = atoll((char*) dbrow[6]); else _rec->refWznmMVector = 0;
		if (dbrow[7]) _rec->Defval.assign(dbrow[7], dblengths[7]); else _rec->Defval = "";
		if (dbrow[8]) _rec->refWznmMVectoritem = atoll((char*) dbrow[8]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMOpInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMOpInvarg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOpInvarg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOpInvarg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMOpInvarg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmCAMOpInvarg = atoll((char*) dbrow[1]); else rec->refWznmCAMOpInvarg = 0;
			if (dbrow[2]) rec->opxRefWznmMOp = atoll((char*) dbrow[2]); else rec->opxRefWznmMOp = 0;
			if (dbrow[3]) rec->opxNum = atol((char*) dbrow[3]); else rec->opxNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixWznmVVartype = atol((char*) dbrow[5]); else rec->ixWznmVVartype = 0;
			if (dbrow[6]) rec->refWznmMVector = atoll((char*) dbrow[6]); else rec->refWznmMVector = 0;
			if (dbrow[7]) rec->Defval.assign(dbrow[7], dblengths[7]); else rec->Defval = "";
			if (dbrow[8]) rec->refWznmMVectoritem = atoll((char*) dbrow[8]); else rec->refWznmMVectoritem = 0;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMOpInvarg::insertRec(
			WznmAMOpInvarg* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[6] = rec->Defval.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOpInvarg,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opxRefWznmMOp,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opxNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMOpInvarg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMOpInvarg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMOpInvarg::insertRst(
			ListWznmAMOpInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMOpInvarg::updateRec(
			WznmAMOpInvarg* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[6] = rec->Defval.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOpInvarg,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opxRefWznmMOp,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opxNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMOpInvarg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMOpInvarg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMOpInvarg::updateRst(
			ListWznmAMOpInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMOpInvarg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMOpInvarg::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMOpInvarg::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMOpInvarg::loadRecByRef(
			ubigint ref
			, WznmAMOpInvarg** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMOpInvarg WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMOpInvarg::loadRefsByClu(
			ubigint refWznmCAMOpInvarg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOpInvarg WHERE refWznmCAMOpInvarg = " + to_string(refWznmCAMOpInvarg) + "", append, refs);
};

ubigint MyTblWznmAMOpInvarg::loadRefsByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOpInvarg WHERE opxRefWznmMOp = " + to_string(opxRefWznmMOp) + "", append, refs);
};

ubigint MyTblWznmAMOpInvarg::loadRstByClu(
			ubigint refWznmCAMOpInvarg
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOpInvarg WHERE refWznmCAMOpInvarg = " + to_string(refWznmCAMOpInvarg) + "", append, rst);
};

ubigint MyTblWznmAMOpInvarg::loadRstByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOpInvarg WHERE opxRefWznmMOp = " + to_string(opxRefWznmMOp) + " ORDER BY opxNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMOpInvarg
 ******************************************************************************/

PgTblWznmAMOpInvarg::PgTblWznmAMOpInvarg() :
			TblWznmAMOpInvarg()
			, PgTable()
		{
};

PgTblWznmAMOpInvarg::~PgTblWznmAMOpInvarg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMOpInvarg::initStatements() {
	createStatement("TblWznmAMOpInvarg_insertRec", "INSERT INTO TblWznmAMOpInvarg (refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWznmAMOpInvarg_updateRec", "UPDATE TblWznmAMOpInvarg SET refWznmCAMOpInvarg = $1, opxRefWznmMOp = $2, opxNum = $3, sref = $4, ixWznmVVartype = $5, refWznmMVector = $6, Defval = $7, refWznmMVectoritem = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWznmAMOpInvarg_removeRecByRef", "DELETE FROM TblWznmAMOpInvarg WHERE ref = $1", 1);

	createStatement("TblWznmAMOpInvarg_loadRecByRef", "SELECT ref, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOpInvarg WHERE ref = $1", 1);
	createStatement("TblWznmAMOpInvarg_loadRefsByClu", "SELECT ref FROM TblWznmAMOpInvarg WHERE refWznmCAMOpInvarg = $1", 1);
	createStatement("TblWznmAMOpInvarg_loadRefsByOpx", "SELECT ref FROM TblWznmAMOpInvarg WHERE opxRefWznmMOp = $1", 1);
	createStatement("TblWznmAMOpInvarg_loadRstByClu", "SELECT ref, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOpInvarg WHERE refWznmCAMOpInvarg = $1", 1);
	createStatement("TblWznmAMOpInvarg_loadRstByOpx", "SELECT ref, refWznmCAMOpInvarg, opxRefWznmMOp, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOpInvarg WHERE opxRefWznmMOp = $1 ORDER BY opxNum ASC", 1);
};

bool PgTblWznmAMOpInvarg::loadRec(
			PGresult* res
			, WznmAMOpInvarg** rec
		) {
	char* ptr;

	WznmAMOpInvarg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMOpInvarg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamopinvarg"),
			PQfnumber(res, "opxrefwznmmop"),
			PQfnumber(res, "opxnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmCAMOpInvarg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->opxRefWznmMOp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->opxNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMOpInvarg::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMOpInvarg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamopinvarg"),
			PQfnumber(res, "opxrefwznmmop"),
			PQfnumber(res, "opxnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMOpInvarg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmCAMOpInvarg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->opxRefWznmMOp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->opxNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMOpInvarg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMOpInvarg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpInvarg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOpInvarg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpInvarg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMOpInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmAMOpInvarg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpInvarg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOpInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpInvarg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMOpInvarg::insertRec(
			WznmAMOpInvarg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmCAMOpInvarg = htonl64(rec->refWznmCAMOpInvarg);
	ubigint _opxRefWznmMOp = htonl64(rec->opxRefWznmMOp);
	uint _opxNum = htonl(rec->opxNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmCAMOpInvarg,
		(char*) &_opxRefWznmMOp,
		(char*) &_opxNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMOpInvarg_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOpInvarg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMOpInvarg::insertRst(
			ListWznmAMOpInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMOpInvarg::updateRec(
			WznmAMOpInvarg* rec
		) {
	PGresult* res;

	ubigint _refWznmCAMOpInvarg = htonl64(rec->refWznmCAMOpInvarg);
	ubigint _opxRefWznmMOp = htonl64(rec->opxRefWznmMOp);
	uint _opxNum = htonl(rec->opxNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmCAMOpInvarg,
		(char*) &_opxRefWznmMOp,
		(char*) &_opxNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem,
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
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMOpInvarg_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOpInvarg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMOpInvarg::updateRst(
			ListWznmAMOpInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMOpInvarg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMOpInvarg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOpInvarg::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMOpInvarg::loadRecByRef(
			ubigint ref
			, WznmAMOpInvarg** rec
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

	return loadRecByStmt("TblWznmAMOpInvarg_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMOpInvarg::loadRefsByClu(
			ubigint refWznmCAMOpInvarg
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCAMOpInvarg = htonl64(refWznmCAMOpInvarg);

	const char* vals[] = {
		(char*) &_refWznmCAMOpInvarg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMOpInvarg_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOpInvarg::loadRefsByOpx(
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

	return loadRefsByStmt("TblWznmAMOpInvarg_loadRefsByOpx", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOpInvarg::loadRstByClu(
			ubigint refWznmCAMOpInvarg
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	ubigint _refWznmCAMOpInvarg = htonl64(refWznmCAMOpInvarg);

	const char* vals[] = {
		(char*) &_refWznmCAMOpInvarg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOpInvarg_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMOpInvarg::loadRstByOpx(
			ubigint opxRefWznmMOp
			, const bool append
			, ListWznmAMOpInvarg& rst
		) {
	ubigint _opxRefWznmMOp = htonl64(opxRefWznmMOp);

	const char* vals[] = {
		(char*) &_opxRefWznmMOp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOpInvarg_loadRstByOpx", 1, vals, l, f, append, rst);
};

#endif
