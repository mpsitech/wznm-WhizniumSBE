/**
	* \file WznmAMStateTrig.cpp
	* database access for table TblWznmAMStateTrig (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMStateTrig.h"

#include "WznmAMStateTrig_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMStateTrig
 ******************************************************************************/

WznmAMStateTrig::WznmAMStateTrig(
			const ubigint ref
			, const ubigint refWznmMState
			, const string sref
			, const uint ixVType
			, const ubigint refWznmMEvent
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) :
			ref(ref)
			, refWznmMState(refWznmMState)
			, sref(sref)
			, ixVType(ixVType)
			, refWznmMEvent(refWznmMEvent)
			, refWznmMRtjob(refWznmMRtjob)
			, refWznmMVectoritem(refWznmMVectoritem)
			, xsref(xsref)
			, refWznmMRtdpch(refWznmMRtdpch)
			, srefsMask(srefsMask)
			, Cond(Cond)
		{
};

bool WznmAMStateTrig::operator==(
			const WznmAMStateTrig& comp
		) {
	return false;
};

bool WznmAMStateTrig::operator!=(
			const WznmAMStateTrig& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMStateTrig
 ******************************************************************************/

ListWznmAMStateTrig::ListWznmAMStateTrig() {
};

ListWznmAMStateTrig::ListWznmAMStateTrig(
			const ListWznmAMStateTrig& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMStateTrig(*(src.nodes[i]));
};

ListWznmAMStateTrig::~ListWznmAMStateTrig() {
	clear();
};

void ListWznmAMStateTrig::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMStateTrig::size() const {
	return(nodes.size());
};

void ListWznmAMStateTrig::append(
			WznmAMStateTrig* rec
		) {
	nodes.push_back(rec);
};

WznmAMStateTrig* ListWznmAMStateTrig::operator[](
			const uint ix
		) {
	WznmAMStateTrig* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMStateTrig& ListWznmAMStateTrig::operator=(
			const ListWznmAMStateTrig& src
		) {
	WznmAMStateTrig* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMStateTrig(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMStateTrig::operator==(
			const ListWznmAMStateTrig& comp
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

bool ListWznmAMStateTrig::operator!=(
			const ListWznmAMStateTrig& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMStateTrig
 ******************************************************************************/

TblWznmAMStateTrig::TblWznmAMStateTrig() {
};

TblWznmAMStateTrig::~TblWznmAMStateTrig() {
};

bool TblWznmAMStateTrig::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateTrig** rec
		) {
	return false;
};

ubigint TblWznmAMStateTrig::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	return 0;
};

ubigint TblWznmAMStateTrig::insertRec(
			WznmAMStateTrig* rec
		) {
	return 0;
};

ubigint TblWznmAMStateTrig::insertNewRec(
			WznmAMStateTrig** rec
			, const ubigint refWznmMState
			, const string sref
			, const uint ixVType
			, const ubigint refWznmMEvent
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) {
	ubigint retval = 0;
	WznmAMStateTrig* _rec = NULL;

	_rec = new WznmAMStateTrig(0, refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMStateTrig::appendNewRecToRst(
			ListWznmAMStateTrig& rst
			, WznmAMStateTrig** rec
			, const ubigint refWznmMState
			, const string sref
			, const uint ixVType
			, const ubigint refWznmMEvent
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) {
	ubigint retval = 0;
	WznmAMStateTrig* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMStateTrig::insertRst(
			ListWznmAMStateTrig& rst
			, bool transact
		) {
};

void TblWznmAMStateTrig::updateRec(
			WznmAMStateTrig* rec
		) {
};

void TblWznmAMStateTrig::updateRst(
			ListWznmAMStateTrig& rst
			, bool transact
		) {
};

void TblWznmAMStateTrig::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMStateTrig::loadRecByRef(
			ubigint ref
			, WznmAMStateTrig** rec
		) {
	return false;
};

ubigint TblWznmAMStateTrig::loadRefsBySte(
			ubigint refWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMStateTrig::loadRstBySte(
			ubigint refWznmMState
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	return 0;
};

ubigint TblWznmAMStateTrig::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	ubigint numload = 0;
	WznmAMStateTrig* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMStateTrig
 ******************************************************************************/

MyTblWznmAMStateTrig::MyTblWznmAMStateTrig() :
			TblWznmAMStateTrig()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMStateTrig::~MyTblWznmAMStateTrig() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMStateTrig::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMStateTrig (refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMStateTrig SET refWznmMState = ?, sref = ?, ixVType = ?, refWznmMEvent = ?, refWznmMRtjob = ?, refWznmMVectoritem = ?, xsref = ?, refWznmMRtdpch = ?, srefsMask = ?, Cond = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMStateTrig WHERE ref = ?", false);
};

bool MyTblWznmAMStateTrig::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateTrig** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMStateTrig* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMStateTrig::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMStateTrig::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMStateTrig();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMState = atoll((char*) dbrow[1]); else _rec->refWznmMState = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->ixVType = atol((char*) dbrow[3]); else _rec->ixVType = 0;
		if (dbrow[4]) _rec->refWznmMEvent = atoll((char*) dbrow[4]); else _rec->refWznmMEvent = 0;
		if (dbrow[5]) _rec->refWznmMRtjob = atoll((char*) dbrow[5]); else _rec->refWznmMRtjob = 0;
		if (dbrow[6]) _rec->refWznmMVectoritem = atoll((char*) dbrow[6]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[7]) _rec->xsref.assign(dbrow[7], dblengths[7]); else _rec->xsref = "";
		if (dbrow[8]) _rec->refWznmMRtdpch = atoll((char*) dbrow[8]); else _rec->refWznmMRtdpch = 0;
		if (dbrow[9]) _rec->srefsMask.assign(dbrow[9], dblengths[9]); else _rec->srefsMask = "";
		if (dbrow[10]) _rec->Cond.assign(dbrow[10], dblengths[10]); else _rec->Cond = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMStateTrig::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMStateTrig* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMStateTrig::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMStateTrig::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMStateTrig();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMState = atoll((char*) dbrow[1]); else rec->refWznmMState = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->ixVType = atol((char*) dbrow[3]); else rec->ixVType = 0;
			if (dbrow[4]) rec->refWznmMEvent = atoll((char*) dbrow[4]); else rec->refWznmMEvent = 0;
			if (dbrow[5]) rec->refWznmMRtjob = atoll((char*) dbrow[5]); else rec->refWznmMRtjob = 0;
			if (dbrow[6]) rec->refWznmMVectoritem = atoll((char*) dbrow[6]); else rec->refWznmMVectoritem = 0;
			if (dbrow[7]) rec->xsref.assign(dbrow[7], dblengths[7]); else rec->xsref = "";
			if (dbrow[8]) rec->refWznmMRtdpch = atoll((char*) dbrow[8]); else rec->refWznmMRtdpch = 0;
			if (dbrow[9]) rec->srefsMask.assign(dbrow[9], dblengths[9]); else rec->srefsMask = "";
			if (dbrow[10]) rec->Cond.assign(dbrow[10], dblengths[10]); else rec->Cond = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMStateTrig::insertRec(
			WznmAMStateTrig* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[1] = rec->sref.length();
	l[6] = rec->xsref.length();
	l[8] = rec->srefsMask.length();
	l[9] = rec->Cond.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMState,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVType,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMEvent,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMRtjob,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMStateTrig::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMStateTrig::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMStateTrig::insertRst(
			ListWznmAMStateTrig& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMStateTrig::updateRec(
			WznmAMStateTrig* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[1] = rec->sref.length();
	l[6] = rec->xsref.length();
	l[8] = rec->srefsMask.length();
	l[9] = rec->Cond.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMState,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVType,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMEvent,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMRtjob,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMStateTrig::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMStateTrig::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMStateTrig::updateRst(
			ListWznmAMStateTrig& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMStateTrig::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMStateTrig::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMStateTrig::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMStateTrig::loadRecByRef(
			ubigint ref
			, WznmAMStateTrig** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMStateTrig WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMStateTrig::loadRefsBySte(
			ubigint refWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMStateTrig WHERE refWznmMState = " + to_string(refWznmMState) + "", append, refs);
};

ubigint MyTblWznmAMStateTrig::loadRstBySte(
			ubigint refWznmMState
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond FROM TblWznmAMStateTrig WHERE refWznmMState = " + to_string(refWznmMState) + " ORDER BY sref ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMStateTrig
 ******************************************************************************/

PgTblWznmAMStateTrig::PgTblWznmAMStateTrig() :
			TblWznmAMStateTrig()
			, PgTable()
		{
};

PgTblWznmAMStateTrig::~PgTblWznmAMStateTrig() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMStateTrig::initStatements() {
	createStatement("TblWznmAMStateTrig_insertRec", "INSERT INTO TblWznmAMStateTrig (refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWznmAMStateTrig_updateRec", "UPDATE TblWznmAMStateTrig SET refWznmMState = $1, sref = $2, ixVType = $3, refWznmMEvent = $4, refWznmMRtjob = $5, refWznmMVectoritem = $6, xsref = $7, refWznmMRtdpch = $8, srefsMask = $9, Cond = $10 WHERE ref = $11", 11);
	createStatement("TblWznmAMStateTrig_removeRecByRef", "DELETE FROM TblWznmAMStateTrig WHERE ref = $1", 1);

	createStatement("TblWznmAMStateTrig_loadRecByRef", "SELECT ref, refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond FROM TblWznmAMStateTrig WHERE ref = $1", 1);
	createStatement("TblWznmAMStateTrig_loadRefsBySte", "SELECT ref FROM TblWznmAMStateTrig WHERE refWznmMState = $1", 1);
	createStatement("TblWznmAMStateTrig_loadRstBySte", "SELECT ref, refWznmMState, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond FROM TblWznmAMStateTrig WHERE refWznmMState = $1 ORDER BY sref ASC", 1);
};

bool PgTblWznmAMStateTrig::loadRec(
			PGresult* res
			, WznmAMStateTrig** rec
		) {
	char* ptr;

	WznmAMStateTrig* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMStateTrig();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmstate"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmevent"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMEvent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->xsref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMRtdpch = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->srefsMask.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Cond.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMStateTrig::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMStateTrig* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmstate"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmevent"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond")
		};

		while (numread < numrow) {
			rec = new WznmAMStateTrig();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMEvent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->xsref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMRtdpch = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->srefsMask.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Cond.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMStateTrig::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMStateTrig** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateTrig::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMStateTrig::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateTrig::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMStateTrig::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateTrig** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateTrig::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMStateTrig::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateTrig::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMStateTrig::insertRec(
			WznmAMStateTrig* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMState = htonl64(rec->refWznmMState);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMEvent = htonl64(rec->refWznmMEvent);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);

	const char* vals[] = {
		(char*) &_refWznmMState,
		rec->sref.c_str(),
		(char*) &_ixVType,
		(char*) &_refWznmMEvent,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMStateTrig_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateTrig::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMStateTrig::insertRst(
			ListWznmAMStateTrig& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMStateTrig::updateRec(
			WznmAMStateTrig* rec
		) {
	PGresult* res;

	ubigint _refWznmMState = htonl64(rec->refWznmMState);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMEvent = htonl64(rec->refWznmMEvent);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMState,
		rec->sref.c_str(),
		(char*) &_ixVType,
		(char*) &_refWznmMEvent,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMStateTrig_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMStateTrig::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMStateTrig::updateRst(
			ListWznmAMStateTrig& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMStateTrig::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMStateTrig_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMStateTrig::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMStateTrig::loadRecByRef(
			ubigint ref
			, WznmAMStateTrig** rec
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

	return loadRecByStmt("TblWznmAMStateTrig_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMStateTrig::loadRefsBySte(
			ubigint refWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMState = htonl64(refWznmMState);

	const char* vals[] = {
		(char*) &_refWznmMState
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMStateTrig_loadRefsBySte", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMStateTrig::loadRstBySte(
			ubigint refWznmMState
			, const bool append
			, ListWznmAMStateTrig& rst
		) {
	ubigint _refWznmMState = htonl64(refWznmMState);

	const char* vals[] = {
		(char*) &_refWznmMState
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMStateTrig_loadRstBySte", 1, vals, l, f, append, rst);
};

#endif
