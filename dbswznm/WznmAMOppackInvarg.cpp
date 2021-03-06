/**
	* \file WznmAMOppackInvarg.cpp
	* database access for table TblWznmAMOppackInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMOppackInvarg.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMOppackInvarg
 ******************************************************************************/

WznmAMOppackInvarg::WznmAMOppackInvarg(
			const ubigint ref
			, const ubigint refWznmCAMOppackInvarg
			, const ubigint opkRefWznmMOppack
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmCAMOppackInvarg = refWznmCAMOppackInvarg;
	this->opkRefWznmMOppack = opkRefWznmMOppack;
	this->opkNum = opkNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->Defval = Defval;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->Comment = Comment;
};

bool WznmAMOppackInvarg::operator==(
			const WznmAMOppackInvarg& comp
		) {
	return false;
};

bool WznmAMOppackInvarg::operator!=(
			const WznmAMOppackInvarg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMOppackInvarg
 ******************************************************************************/

ListWznmAMOppackInvarg::ListWznmAMOppackInvarg() {
};

ListWznmAMOppackInvarg::ListWznmAMOppackInvarg(
			const ListWznmAMOppackInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMOppackInvarg(*(src.nodes[i]));
};

ListWznmAMOppackInvarg::~ListWznmAMOppackInvarg() {
	clear();
};

void ListWznmAMOppackInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMOppackInvarg::size() const {
	return(nodes.size());
};

void ListWznmAMOppackInvarg::append(
			WznmAMOppackInvarg* rec
		) {
	nodes.push_back(rec);
};

WznmAMOppackInvarg* ListWznmAMOppackInvarg::operator[](
			const uint ix
		) {
	WznmAMOppackInvarg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMOppackInvarg& ListWznmAMOppackInvarg::operator=(
			const ListWznmAMOppackInvarg& src
		) {
	WznmAMOppackInvarg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMOppackInvarg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMOppackInvarg::operator==(
			const ListWznmAMOppackInvarg& comp
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

bool ListWznmAMOppackInvarg::operator!=(
			const ListWznmAMOppackInvarg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMOppackInvarg
 ******************************************************************************/

TblWznmAMOppackInvarg::TblWznmAMOppackInvarg() {
};

TblWznmAMOppackInvarg::~TblWznmAMOppackInvarg() {
};

bool TblWznmAMOppackInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmAMOppackInvarg** rec
		) {
	return false;
};

ubigint TblWznmAMOppackInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	return 0;
};

ubigint TblWznmAMOppackInvarg::insertRec(
			WznmAMOppackInvarg* rec
		) {
	return 0;
};

ubigint TblWznmAMOppackInvarg::insertNewRec(
			WznmAMOppackInvarg** rec
			, const ubigint refWznmCAMOppackInvarg
			, const ubigint opkRefWznmMOppack
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOppackInvarg* _rec = NULL;

	_rec = new WznmAMOppackInvarg(0, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMOppackInvarg::appendNewRecToRst(
			ListWznmAMOppackInvarg& rst
			, WznmAMOppackInvarg** rec
			, const ubigint refWznmCAMOppackInvarg
			, const ubigint opkRefWznmMOppack
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMOppackInvarg* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMOppackInvarg::insertRst(
			ListWznmAMOppackInvarg& rst
			, bool transact
		) {
};

void TblWznmAMOppackInvarg::updateRec(
			WznmAMOppackInvarg* rec
		) {
};

void TblWznmAMOppackInvarg::updateRst(
			ListWznmAMOppackInvarg& rst
			, bool transact
		) {
};

void TblWznmAMOppackInvarg::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMOppackInvarg::loadRecByRef(
			ubigint ref
			, WznmAMOppackInvarg** rec
		) {
	return false;
};

ubigint TblWznmAMOppackInvarg::loadRefsByClu(
			ubigint refWznmCAMOppackInvarg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOppackInvarg::loadRefsByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMOppackInvarg::loadRstByClu(
			ubigint refWznmCAMOppackInvarg
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	return 0;
};

ubigint TblWznmAMOppackInvarg::loadRstByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	return 0;
};

ubigint TblWznmAMOppackInvarg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	ubigint numload = 0;
	WznmAMOppackInvarg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMOppackInvarg
 ******************************************************************************/

MyTblWznmAMOppackInvarg::MyTblWznmAMOppackInvarg() :
			TblWznmAMOppackInvarg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMOppackInvarg::~MyTblWznmAMOppackInvarg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMOppackInvarg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMOppackInvarg (refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMOppackInvarg SET refWznmCAMOppackInvarg = ?, opkRefWznmMOppack = ?, opkNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Defval = ?, refWznmMVectoritem = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMOppackInvarg WHERE ref = ?", false);
};

bool MyTblWznmAMOppackInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmAMOppackInvarg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMOppackInvarg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOppackInvarg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOppackInvarg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMOppackInvarg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmCAMOppackInvarg = atoll((char*) dbrow[1]); else _rec->refWznmCAMOppackInvarg = 0;
		if (dbrow[2]) _rec->opkRefWznmMOppack = atoll((char*) dbrow[2]); else _rec->opkRefWznmMOppack = 0;
		if (dbrow[3]) _rec->opkNum = atol((char*) dbrow[3]); else _rec->opkNum = 0;
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

ubigint MyTblWznmAMOppackInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMOppackInvarg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMOppackInvarg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMOppackInvarg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMOppackInvarg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmCAMOppackInvarg = atoll((char*) dbrow[1]); else rec->refWznmCAMOppackInvarg = 0;
			if (dbrow[2]) rec->opkRefWznmMOppack = atoll((char*) dbrow[2]); else rec->opkRefWznmMOppack = 0;
			if (dbrow[3]) rec->opkNum = atol((char*) dbrow[3]); else rec->opkNum = 0;
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

ubigint MyTblWznmAMOppackInvarg::insertRec(
			WznmAMOppackInvarg* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[6] = rec->Defval.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOppackInvarg,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opkRefWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opkNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMOppackInvarg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMOppackInvarg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMOppackInvarg::insertRst(
			ListWznmAMOppackInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMOppackInvarg::updateRec(
			WznmAMOppackInvarg* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[6] = rec->Defval.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMOppackInvarg,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->opkRefWznmMOppack,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->opkNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMOppackInvarg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMOppackInvarg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMOppackInvarg::updateRst(
			ListWznmAMOppackInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMOppackInvarg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMOppackInvarg::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMOppackInvarg::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMOppackInvarg::loadRecByRef(
			ubigint ref
			, WznmAMOppackInvarg** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMOppackInvarg WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMOppackInvarg::loadRefsByClu(
			ubigint refWznmCAMOppackInvarg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOppackInvarg WHERE refWznmCAMOppackInvarg = " + to_string(refWznmCAMOppackInvarg) + "", append, refs);
};

ubigint MyTblWznmAMOppackInvarg::loadRefsByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMOppackInvarg WHERE opkRefWznmMOppack = " + to_string(opkRefWznmMOppack) + "", append, refs);
};

ubigint MyTblWznmAMOppackInvarg::loadRstByClu(
			ubigint refWznmCAMOppackInvarg
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOppackInvarg WHERE refWznmCAMOppackInvarg = " + to_string(refWznmCAMOppackInvarg) + "", append, rst);
};

ubigint MyTblWznmAMOppackInvarg::loadRstByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOppackInvarg WHERE opkRefWznmMOppack = " + to_string(opkRefWznmMOppack) + " ORDER BY opkNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMOppackInvarg
 ******************************************************************************/

PgTblWznmAMOppackInvarg::PgTblWznmAMOppackInvarg() :
			TblWznmAMOppackInvarg()
			, PgTable()
		{
};

PgTblWznmAMOppackInvarg::~PgTblWznmAMOppackInvarg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMOppackInvarg::initStatements() {
	createStatement("TblWznmAMOppackInvarg_insertRec", "INSERT INTO TblWznmAMOppackInvarg (refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWznmAMOppackInvarg_updateRec", "UPDATE TblWznmAMOppackInvarg SET refWznmCAMOppackInvarg = $1, opkRefWznmMOppack = $2, opkNum = $3, sref = $4, ixWznmVVartype = $5, refWznmMVector = $6, Defval = $7, refWznmMVectoritem = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWznmAMOppackInvarg_removeRecByRef", "DELETE FROM TblWznmAMOppackInvarg WHERE ref = $1", 1);

	createStatement("TblWznmAMOppackInvarg_loadRecByRef", "SELECT ref, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOppackInvarg WHERE ref = $1", 1);
	createStatement("TblWznmAMOppackInvarg_loadRefsByClu", "SELECT ref FROM TblWznmAMOppackInvarg WHERE refWznmCAMOppackInvarg = $1", 1);
	createStatement("TblWznmAMOppackInvarg_loadRefsByOpk", "SELECT ref FROM TblWznmAMOppackInvarg WHERE opkRefWznmMOppack = $1", 1);
	createStatement("TblWznmAMOppackInvarg_loadRstByClu", "SELECT ref, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOppackInvarg WHERE refWznmCAMOppackInvarg = $1", 1);
	createStatement("TblWznmAMOppackInvarg_loadRstByOpk", "SELECT ref, refWznmCAMOppackInvarg, opkRefWznmMOppack, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmAMOppackInvarg WHERE opkRefWznmMOppack = $1 ORDER BY opkNum ASC", 1);
};

bool PgTblWznmAMOppackInvarg::loadRec(
			PGresult* res
			, WznmAMOppackInvarg** rec
		) {
	char* ptr;

	WznmAMOppackInvarg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMOppackInvarg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamoppackinvarg"),
			PQfnumber(res, "opkrefwznmmoppack"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmCAMOppackInvarg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->opkRefWznmMOppack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->opkNum = atol(ptr);
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

ubigint PgTblWznmAMOppackInvarg::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMOppackInvarg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamoppackinvarg"),
			PQfnumber(res, "opkrefwznmmoppack"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMOppackInvarg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmCAMOppackInvarg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->opkRefWznmMOppack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->opkNum = atol(ptr);
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

bool PgTblWznmAMOppackInvarg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMOppackInvarg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOppackInvarg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMOppackInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmAMOppackInvarg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMOppackInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMOppackInvarg::insertRec(
			WznmAMOppackInvarg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmCAMOppackInvarg = htonl64(rec->refWznmCAMOppackInvarg);
	ubigint _opkRefWznmMOppack = htonl64(rec->opkRefWznmMOppack);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackInvarg,
		(char*) &_opkRefWznmMOppack,
		(char*) &_opkNum,
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

	res = PQexecPrepared(dbs, "TblWznmAMOppackInvarg_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMOppackInvarg::insertRst(
			ListWznmAMOppackInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMOppackInvarg::updateRec(
			WznmAMOppackInvarg* rec
		) {
	PGresult* res;

	ubigint _refWznmCAMOppackInvarg = htonl64(rec->refWznmCAMOppackInvarg);
	ubigint _opkRefWznmMOppack = htonl64(rec->opkRefWznmMOppack);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackInvarg,
		(char*) &_opkRefWznmMOppack,
		(char*) &_opkNum,
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

	res = PQexecPrepared(dbs, "TblWznmAMOppackInvarg_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMOppackInvarg::updateRst(
			ListWznmAMOppackInvarg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMOppackInvarg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMOppackInvarg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMOppackInvarg::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMOppackInvarg::loadRecByRef(
			ubigint ref
			, WznmAMOppackInvarg** rec
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

	return loadRecByStmt("TblWznmAMOppackInvarg_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMOppackInvarg::loadRefsByClu(
			ubigint refWznmCAMOppackInvarg
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCAMOppackInvarg = htonl64(refWznmCAMOppackInvarg);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackInvarg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMOppackInvarg_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOppackInvarg::loadRefsByOpk(
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

	return loadRefsByStmt("TblWznmAMOppackInvarg_loadRefsByOpk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMOppackInvarg::loadRstByClu(
			ubigint refWznmCAMOppackInvarg
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	ubigint _refWznmCAMOppackInvarg = htonl64(refWznmCAMOppackInvarg);

	const char* vals[] = {
		(char*) &_refWznmCAMOppackInvarg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOppackInvarg_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMOppackInvarg::loadRstByOpk(
			ubigint opkRefWznmMOppack
			, const bool append
			, ListWznmAMOppackInvarg& rst
		) {
	ubigint _opkRefWznmMOppack = htonl64(opkRefWznmMOppack);

	const char* vals[] = {
		(char*) &_opkRefWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMOppackInvarg_loadRstByOpk", 1, vals, l, f, append, rst);
};

#endif
