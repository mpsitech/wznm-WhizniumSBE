/**
	* \file WznmAMStateStep.cpp
	* database access for table TblWznmAMStateStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmAMStateStep.h"

#include "WznmAMStateStep_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMStateStep
 ******************************************************************************/

WznmAMStateStep::WznmAMStateStep(
			const ubigint ref
			, const ubigint refWznmMState
			, const ubigint snxRefWznmMState
			, const uint ixVTrigger
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const bool Custcode
		) {

	this->ref = ref;
	this->refWznmMState = refWznmMState;
	this->snxRefWznmMState = snxRefWznmMState;
	this->ixVTrigger = ixVTrigger;
	this->refWznmMRtjob = refWznmMRtjob;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->xsref = xsref;
	this->refWznmMRtdpch = refWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
	this->Custcode = Custcode;
};

bool WznmAMStateStep::operator==(
			const WznmAMStateStep& comp
		) {
	return false;
};

bool WznmAMStateStep::operator!=(
			const WznmAMStateStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMStateStep
 ******************************************************************************/

ListWznmAMStateStep::ListWznmAMStateStep() {
};

ListWznmAMStateStep::ListWznmAMStateStep(
			const ListWznmAMStateStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMStateStep(*(src.nodes[i]));
};

ListWznmAMStateStep::~ListWznmAMStateStep() {
	clear();
};

void ListWznmAMStateStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMStateStep::size() const {
	return(nodes.size());
};

void ListWznmAMStateStep::append(
			WznmAMStateStep* rec
		) {
	nodes.push_back(rec);
};

WznmAMStateStep* ListWznmAMStateStep::operator[](
			const uint ix
		) {
	WznmAMStateStep* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMStateStep& ListWznmAMStateStep::operator=(
			const ListWznmAMStateStep& src
		) {
	WznmAMStateStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMStateStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMStateStep::operator==(
			const ListWznmAMStateStep& comp
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

bool ListWznmAMStateStep::operator!=(
			const ListWznmAMStateStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMStateStep
 ******************************************************************************/

TblWznmAMStateStep::TblWznmAMStateStep() {
};

TblWznmAMStateStep::~TblWznmAMStateStep() {
};

bool TblWznmAMStateStep::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateStep** rec
		) {
	return false;
};

ubigint TblWznmAMStateStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	return 0;
};

ubigint TblWznmAMStateStep::insertRec(
			WznmAMStateStep* rec
		) {
	return 0;
};

ubigint TblWznmAMStateStep::insertNewRec(
			WznmAMStateStep** rec
			, const ubigint refWznmMState
			, const ubigint snxRefWznmMState
			, const uint ixVTrigger
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const bool Custcode
		) {
	ubigint retval = 0;
	WznmAMStateStep* _rec = NULL;

	_rec = new WznmAMStateStep(0, refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMStateStep::appendNewRecToRst(
			ListWznmAMStateStep& rst
			, WznmAMStateStep** rec
			, const ubigint refWznmMState
			, const ubigint snxRefWznmMState
			, const uint ixVTrigger
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const bool Custcode
		) {
	ubigint retval = 0;
	WznmAMStateStep* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMStateStep::insertRst(
			ListWznmAMStateStep& rst
			, bool transact
		) {
};

void TblWznmAMStateStep::updateRec(
			WznmAMStateStep* rec
		) {
};

void TblWznmAMStateStep::updateRst(
			ListWznmAMStateStep& rst
			, bool transact
		) {
};

void TblWznmAMStateStep::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMStateStep::loadRecByRef(
			ubigint ref
			, WznmAMStateStep** rec
		) {
	return false;
};

ubigint TblWznmAMStateStep::loadRefsBySte(
			ubigint refWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMStateStep::loadRstBySte(
			ubigint refWznmMState
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	return 0;
};

ubigint TblWznmAMStateStep::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	ubigint numload = 0;
	WznmAMStateStep* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMStateStep
 ******************************************************************************/

MyTblWznmAMStateStep::MyTblWznmAMStateStep() :
			TblWznmAMStateStep()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMStateStep::~MyTblWznmAMStateStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMStateStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMStateStep (refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMStateStep SET refWznmMState = ?, snxRefWznmMState = ?, ixVTrigger = ?, refWznmMRtjob = ?, refWznmMVectoritem = ?, xsref = ?, refWznmMRtdpch = ?, srefsMask = ?, Cond = ?, Custcode = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMStateStep WHERE ref = ?", false);
};

bool MyTblWznmAMStateStep::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMStateStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMStateStep::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMStateStep::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMStateStep();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMState = atoll((char*) dbrow[1]); else _rec->refWznmMState = 0;
		if (dbrow[2]) _rec->snxRefWznmMState = atoll((char*) dbrow[2]); else _rec->snxRefWznmMState = 0;
		if (dbrow[3]) _rec->ixVTrigger = atol((char*) dbrow[3]); else _rec->ixVTrigger = 0;
		if (dbrow[4]) _rec->refWznmMRtjob = atoll((char*) dbrow[4]); else _rec->refWznmMRtjob = 0;
		if (dbrow[5]) _rec->refWznmMVectoritem = atoll((char*) dbrow[5]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[6]) _rec->xsref.assign(dbrow[6], dblengths[6]); else _rec->xsref = "";
		if (dbrow[7]) _rec->refWznmMRtdpch = atoll((char*) dbrow[7]); else _rec->refWznmMRtdpch = 0;
		if (dbrow[8]) _rec->srefsMask.assign(dbrow[8], dblengths[8]); else _rec->srefsMask = "";
		if (dbrow[9]) _rec->Cond.assign(dbrow[9], dblengths[9]); else _rec->Cond = "";
		if (dbrow[10]) _rec->Custcode = (atoi((char*) dbrow[10]) != 0); else _rec->Custcode = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMStateStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMStateStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMStateStep::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMStateStep::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMStateStep();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMState = atoll((char*) dbrow[1]); else rec->refWznmMState = 0;
			if (dbrow[2]) rec->snxRefWznmMState = atoll((char*) dbrow[2]); else rec->snxRefWznmMState = 0;
			if (dbrow[3]) rec->ixVTrigger = atol((char*) dbrow[3]); else rec->ixVTrigger = 0;
			if (dbrow[4]) rec->refWznmMRtjob = atoll((char*) dbrow[4]); else rec->refWznmMRtjob = 0;
			if (dbrow[5]) rec->refWznmMVectoritem = atoll((char*) dbrow[5]); else rec->refWznmMVectoritem = 0;
			if (dbrow[6]) rec->xsref.assign(dbrow[6], dblengths[6]); else rec->xsref = "";
			if (dbrow[7]) rec->refWznmMRtdpch = atoll((char*) dbrow[7]); else rec->refWznmMRtdpch = 0;
			if (dbrow[8]) rec->srefsMask.assign(dbrow[8], dblengths[8]); else rec->srefsMask = "";
			if (dbrow[9]) rec->Cond.assign(dbrow[9], dblengths[9]); else rec->Cond = "";
			if (dbrow[10]) rec->Custcode = (atoi((char*) dbrow[10]) != 0); else rec->Custcode = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMStateStep::insertRec(
			WznmAMStateStep* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->xsref.length();
	l[7] = rec->srefsMask.length();
	l[8] = rec->Cond.length();
	tinyint Custcode = rec->Custcode;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMState,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->snxRefWznmMState,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVTrigger,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMRtjob,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Custcode,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMStateStep::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMStateStep::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMStateStep::insertRst(
			ListWznmAMStateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMStateStep::updateRec(
			WznmAMStateStep* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->xsref.length();
	l[7] = rec->srefsMask.length();
	l[8] = rec->Cond.length();
	tinyint Custcode = rec->Custcode;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMState,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->snxRefWznmMState,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVTrigger,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMRtjob,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Custcode,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMStateStep::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMStateStep::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMStateStep::updateRst(
			ListWznmAMStateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMStateStep::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMStateStep::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMStateStep::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMStateStep::loadRecByRef(
			ubigint ref
			, WznmAMStateStep** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMStateStep WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMStateStep::loadRefsBySte(
			ubigint refWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMStateStep WHERE refWznmMState = " + to_string(refWznmMState) + "", append, refs);
};

ubigint MyTblWznmAMStateStep::loadRstBySte(
			ubigint refWznmMState
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode FROM TblWznmAMStateStep WHERE refWznmMState = " + to_string(refWznmMState) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMStateStep
 ******************************************************************************/

PgTblWznmAMStateStep::PgTblWznmAMStateStep() :
			TblWznmAMStateStep()
			, PgTable()
		{
};

PgTblWznmAMStateStep::~PgTblWznmAMStateStep() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMStateStep::initStatements() {
	createStatement("TblWznmAMStateStep_insertRec", "INSERT INTO TblWznmAMStateStep (refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWznmAMStateStep_updateRec", "UPDATE TblWznmAMStateStep SET refWznmMState = $1, snxRefWznmMState = $2, ixVTrigger = $3, refWznmMRtjob = $4, refWznmMVectoritem = $5, xsref = $6, refWznmMRtdpch = $7, srefsMask = $8, Cond = $9, Custcode = $10 WHERE ref = $11", 11);
	createStatement("TblWznmAMStateStep_removeRecByRef", "DELETE FROM TblWznmAMStateStep WHERE ref = $1", 1);

	createStatement("TblWznmAMStateStep_loadRecByRef", "SELECT ref, refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode FROM TblWznmAMStateStep WHERE ref = $1", 1);
	createStatement("TblWznmAMStateStep_loadRefsBySte", "SELECT ref FROM TblWznmAMStateStep WHERE refWznmMState = $1", 1);
	createStatement("TblWznmAMStateStep_loadRstBySte", "SELECT ref, refWznmMState, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode FROM TblWznmAMStateStep WHERE refWznmMState = $1", 1);
};

bool PgTblWznmAMStateStep::loadRec(
			PGresult* res
			, WznmAMStateStep** rec
		) {
	char* ptr;

	WznmAMStateStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMStateStep();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmstate"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "ixvtrigger"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond"),
			PQfnumber(res, "custcode")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->snxRefWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVTrigger = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->xsref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMRtdpch = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefsMask.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Cond.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Custcode = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMStateStep::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMStateStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmstate"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "ixvtrigger"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond"),
			PQfnumber(res, "custcode")
		};

		while (numread < numrow) {
			rec = new WznmAMStateStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->snxRefWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVTrigger = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->xsref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMRtdpch = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefsMask.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Cond.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Custcode = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMStateStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMStateStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateStep::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMStateStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateStep::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMStateStep::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateStep::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMStateStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateStep::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMStateStep::insertRec(
			WznmAMStateStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMState = htonl64(rec->refWznmMState);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	uint _ixVTrigger = htonl(rec->ixVTrigger);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);
	smallint _Custcode = htons((smallint) rec->Custcode);

	const char* vals[] = {
		(char*) &_refWznmMState,
		(char*) &_snxRefWznmMState,
		(char*) &_ixVTrigger,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str(),
		(char*) &_Custcode
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMStateStep_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateStep::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMStateStep::insertRst(
			ListWznmAMStateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMStateStep::updateRec(
			WznmAMStateStep* rec
		) {
	PGresult* res;

	ubigint _refWznmMState = htonl64(rec->refWznmMState);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	uint _ixVTrigger = htonl(rec->ixVTrigger);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);
	smallint _Custcode = htons((smallint) rec->Custcode);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMState,
		(char*) &_snxRefWznmMState,
		(char*) &_ixVTrigger,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str(),
		(char*) &_Custcode,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAMStateStep_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMStateStep::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMStateStep::updateRst(
			ListWznmAMStateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMStateStep::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMStateStep_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMStateStep::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMStateStep::loadRecByRef(
			ubigint ref
			, WznmAMStateStep** rec
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

	return loadRecByStmt("TblWznmAMStateStep_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMStateStep::loadRefsBySte(
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

	return loadRefsByStmt("TblWznmAMStateStep_loadRefsBySte", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMStateStep::loadRstBySte(
			ubigint refWznmMState
			, const bool append
			, ListWznmAMStateStep& rst
		) {
	ubigint _refWznmMState = htonl64(refWznmMState);

	const char* vals[] = {
		(char*) &_refWznmMState
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMStateStep_loadRstBySte", 1, vals, l, f, append, rst);
};

#endif

