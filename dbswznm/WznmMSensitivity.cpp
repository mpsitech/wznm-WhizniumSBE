/**
	* \file WznmMSensitivity.cpp
	* database access for table TblWznmMSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMSensitivity.h"

#include "WznmMSensitivity_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMSensitivity
 ******************************************************************************/

WznmMSensitivity::WznmMSensitivity(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMJob
			, const ubigint refWznmMStage
			, const ubigint refWznmMCall
			, const uint ixVJactype
			, const uint ixVJobmask
			, const string Jobshort
			, const string Argpatt
			, const ubigint refWznmMControl
			, const string Srefmask
			, const uint ixVAction
			, const ubigint csgRefWznmMStage
			, const bool Custcode
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMJob = refWznmMJob;
	this->refWznmMStage = refWznmMStage;
	this->refWznmMCall = refWznmMCall;
	this->ixVJactype = ixVJactype;
	this->ixVJobmask = ixVJobmask;
	this->Jobshort = Jobshort;
	this->Argpatt = Argpatt;
	this->refWznmMControl = refWznmMControl;
	this->Srefmask = Srefmask;
	this->ixVAction = ixVAction;
	this->csgRefWznmMStage = csgRefWznmMStage;
	this->Custcode = Custcode;
};

bool WznmMSensitivity::operator==(
			const WznmMSensitivity& comp
		) {
	return false;
};

bool WznmMSensitivity::operator!=(
			const WznmMSensitivity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMSensitivity
 ******************************************************************************/

ListWznmMSensitivity::ListWznmMSensitivity() {
};

ListWznmMSensitivity::ListWznmMSensitivity(
			const ListWznmMSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMSensitivity(*(src.nodes[i]));
};

ListWznmMSensitivity::~ListWznmMSensitivity() {
	clear();
};

void ListWznmMSensitivity::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMSensitivity::size() const {
	return(nodes.size());
};

void ListWznmMSensitivity::append(
			WznmMSensitivity* rec
		) {
	nodes.push_back(rec);
};

WznmMSensitivity* ListWznmMSensitivity::operator[](
			const uint ix
		) {
	WznmMSensitivity* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMSensitivity& ListWznmMSensitivity::operator=(
			const ListWznmMSensitivity& src
		) {
	WznmMSensitivity* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMSensitivity(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMSensitivity::operator==(
			const ListWznmMSensitivity& comp
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

bool ListWznmMSensitivity::operator!=(
			const ListWznmMSensitivity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMSensitivity
 ******************************************************************************/

TblWznmMSensitivity::TblWznmMSensitivity() {
};

TblWznmMSensitivity::~TblWznmMSensitivity() {
};

bool TblWznmMSensitivity::loadRecBySQL(
			const string& sqlstr
			, WznmMSensitivity** rec
		) {
	return false;
};

ubigint TblWznmMSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSensitivity& rst
		) {
	return 0;
};

ubigint TblWznmMSensitivity::insertRec(
			WznmMSensitivity* rec
		) {
	return 0;
};

ubigint TblWznmMSensitivity::insertNewRec(
			WznmMSensitivity** rec
			, const uint ixVBasetype
			, const ubigint refWznmMJob
			, const ubigint refWznmMStage
			, const ubigint refWznmMCall
			, const uint ixVJactype
			, const uint ixVJobmask
			, const string Jobshort
			, const string Argpatt
			, const ubigint refWznmMControl
			, const string Srefmask
			, const uint ixVAction
			, const ubigint csgRefWznmMStage
			, const bool Custcode
		) {
	ubigint retval = 0;
	WznmMSensitivity* _rec = NULL;

	_rec = new WznmMSensitivity(0, ixVBasetype, refWznmMJob, refWznmMStage, refWznmMCall, ixVJactype, ixVJobmask, Jobshort, Argpatt, refWznmMControl, Srefmask, ixVAction, csgRefWznmMStage, Custcode);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMSensitivity::appendNewRecToRst(
			ListWznmMSensitivity& rst
			, WznmMSensitivity** rec
			, const uint ixVBasetype
			, const ubigint refWznmMJob
			, const ubigint refWznmMStage
			, const ubigint refWznmMCall
			, const uint ixVJactype
			, const uint ixVJobmask
			, const string Jobshort
			, const string Argpatt
			, const ubigint refWznmMControl
			, const string Srefmask
			, const uint ixVAction
			, const ubigint csgRefWznmMStage
			, const bool Custcode
		) {
	ubigint retval = 0;
	WznmMSensitivity* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMJob, refWznmMStage, refWznmMCall, ixVJactype, ixVJobmask, Jobshort, Argpatt, refWznmMControl, Srefmask, ixVAction, csgRefWznmMStage, Custcode);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMSensitivity::insertRst(
			ListWznmMSensitivity& rst
			, bool transact
		) {
};

void TblWznmMSensitivity::updateRec(
			WznmMSensitivity* rec
		) {
};

void TblWznmMSensitivity::updateRst(
			ListWznmMSensitivity& rst
			, bool transact
		) {
};

void TblWznmMSensitivity::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMSensitivity::loadRecByRef(
			ubigint ref
			, WznmMSensitivity** rec
		) {
	return false;
};

ubigint TblWznmMSensitivity::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMSensitivity::loadRefsBySge(
			ubigint refWznmMStage
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMSensitivity::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMSensitivity& rst
		) {
	ubigint numload = 0;
	WznmMSensitivity* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMSensitivity
 ******************************************************************************/

MyTblWznmMSensitivity::MyTblWznmMSensitivity() :
			TblWznmMSensitivity()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMSensitivity::~MyTblWznmMSensitivity() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMSensitivity::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMSensitivity (ixVBasetype, refWznmMJob, refWznmMStage, refWznmMCall, ixVJactype, ixVJobmask, Jobshort, Argpatt, refWznmMControl, Srefmask, ixVAction, csgRefWznmMStage, Custcode) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMSensitivity SET ixVBasetype = ?, refWznmMJob = ?, refWznmMStage = ?, refWznmMCall = ?, ixVJactype = ?, ixVJobmask = ?, Jobshort = ?, Argpatt = ?, refWznmMControl = ?, Srefmask = ?, ixVAction = ?, csgRefWznmMStage = ?, Custcode = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMSensitivity WHERE ref = ?", false);
};

bool MyTblWznmMSensitivity::loadRecBySQL(
			const string& sqlstr
			, WznmMSensitivity** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMSensitivity* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSensitivity::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSensitivity::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMSensitivity();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMJob = atoll((char*) dbrow[2]); else _rec->refWznmMJob = 0;
		if (dbrow[3]) _rec->refWznmMStage = atoll((char*) dbrow[3]); else _rec->refWznmMStage = 0;
		if (dbrow[4]) _rec->refWznmMCall = atoll((char*) dbrow[4]); else _rec->refWznmMCall = 0;
		if (dbrow[5]) _rec->ixVJactype = atol((char*) dbrow[5]); else _rec->ixVJactype = 0;
		if (dbrow[6]) _rec->ixVJobmask = atol((char*) dbrow[6]); else _rec->ixVJobmask = 0;
		if (dbrow[7]) _rec->Jobshort.assign(dbrow[7], dblengths[7]); else _rec->Jobshort = "";
		if (dbrow[8]) _rec->Argpatt.assign(dbrow[8], dblengths[8]); else _rec->Argpatt = "";
		if (dbrow[9]) _rec->refWznmMControl = atoll((char*) dbrow[9]); else _rec->refWznmMControl = 0;
		if (dbrow[10]) _rec->Srefmask.assign(dbrow[10], dblengths[10]); else _rec->Srefmask = "";
		if (dbrow[11]) _rec->ixVAction = atol((char*) dbrow[11]); else _rec->ixVAction = 0;
		if (dbrow[12]) _rec->csgRefWznmMStage = atoll((char*) dbrow[12]); else _rec->csgRefWznmMStage = 0;
		if (dbrow[13]) _rec->Custcode = (atoi((char*) dbrow[13]) != 0); else _rec->Custcode = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSensitivity& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMSensitivity* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSensitivity::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSensitivity::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMSensitivity();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMJob = atoll((char*) dbrow[2]); else rec->refWznmMJob = 0;
			if (dbrow[3]) rec->refWznmMStage = atoll((char*) dbrow[3]); else rec->refWznmMStage = 0;
			if (dbrow[4]) rec->refWznmMCall = atoll((char*) dbrow[4]); else rec->refWznmMCall = 0;
			if (dbrow[5]) rec->ixVJactype = atol((char*) dbrow[5]); else rec->ixVJactype = 0;
			if (dbrow[6]) rec->ixVJobmask = atol((char*) dbrow[6]); else rec->ixVJobmask = 0;
			if (dbrow[7]) rec->Jobshort.assign(dbrow[7], dblengths[7]); else rec->Jobshort = "";
			if (dbrow[8]) rec->Argpatt.assign(dbrow[8], dblengths[8]); else rec->Argpatt = "";
			if (dbrow[9]) rec->refWznmMControl = atoll((char*) dbrow[9]); else rec->refWznmMControl = 0;
			if (dbrow[10]) rec->Srefmask.assign(dbrow[10], dblengths[10]); else rec->Srefmask = "";
			if (dbrow[11]) rec->ixVAction = atol((char*) dbrow[11]); else rec->ixVAction = 0;
			if (dbrow[12]) rec->csgRefWznmMStage = atoll((char*) dbrow[12]); else rec->csgRefWznmMStage = 0;
			if (dbrow[13]) rec->Custcode = (atoi((char*) dbrow[13]) != 0); else rec->Custcode = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMSensitivity::insertRec(
			WznmMSensitivity* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[6] = rec->Jobshort.length();
	l[7] = rec->Argpatt.length();
	l[9] = rec->Srefmask.length();
	tinyint Custcode = rec->Custcode;

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMStage,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMCall,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVJactype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVJobmask,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Jobshort.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Argpatt.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMControl,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Srefmask.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVAction,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->csgRefWznmMStage,&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Custcode,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMSensitivity::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMSensitivity::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMSensitivity::insertRst(
			ListWznmMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMSensitivity::updateRec(
			WznmMSensitivity* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[6] = rec->Jobshort.length();
	l[7] = rec->Argpatt.length();
	l[9] = rec->Srefmask.length();
	tinyint Custcode = rec->Custcode;

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMStage,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMCall,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVJactype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVJobmask,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Jobshort.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Argpatt.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMControl,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Srefmask.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVAction,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->csgRefWznmMStage,&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Custcode,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMSensitivity::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMSensitivity::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMSensitivity::updateRst(
			ListWznmMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMSensitivity::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMSensitivity::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMSensitivity::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMSensitivity::loadRecByRef(
			ubigint ref
			, WznmMSensitivity** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMSensitivity WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMSensitivity::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMSensitivity WHERE refWznmMJob = " + to_string(refWznmMJob) + "", append, refs);
};

ubigint MyTblWznmMSensitivity::loadRefsBySge(
			ubigint refWznmMStage
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMSensitivity WHERE refWznmMStage = " + to_string(refWznmMStage) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMSensitivity
 ******************************************************************************/

PgTblWznmMSensitivity::PgTblWznmMSensitivity() :
			TblWznmMSensitivity()
			, PgTable()
		{
};

PgTblWznmMSensitivity::~PgTblWznmMSensitivity() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMSensitivity::initStatements() {
	createStatement("TblWznmMSensitivity_insertRec", "INSERT INTO TblWznmMSensitivity (ixVBasetype, refWznmMJob, refWznmMStage, refWznmMCall, ixVJactype, ixVJobmask, Jobshort, Argpatt, refWznmMControl, Srefmask, ixVAction, csgRefWznmMStage, Custcode) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWznmMSensitivity_updateRec", "UPDATE TblWznmMSensitivity SET ixVBasetype = $1, refWznmMJob = $2, refWznmMStage = $3, refWznmMCall = $4, ixVJactype = $5, ixVJobmask = $6, Jobshort = $7, Argpatt = $8, refWznmMControl = $9, Srefmask = $10, ixVAction = $11, csgRefWznmMStage = $12, Custcode = $13 WHERE ref = $14", 14);
	createStatement("TblWznmMSensitivity_removeRecByRef", "DELETE FROM TblWznmMSensitivity WHERE ref = $1", 1);

	createStatement("TblWznmMSensitivity_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMJob, refWznmMStage, refWznmMCall, ixVJactype, ixVJobmask, Jobshort, Argpatt, refWznmMControl, Srefmask, ixVAction, csgRefWznmMStage, Custcode FROM TblWznmMSensitivity WHERE ref = $1", 1);
	createStatement("TblWznmMSensitivity_loadRefsByJob", "SELECT ref FROM TblWznmMSensitivity WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMSensitivity_loadRefsBySge", "SELECT ref FROM TblWznmMSensitivity WHERE refWznmMStage = $1", 1);
};

bool PgTblWznmMSensitivity::loadRec(
			PGresult* res
			, WznmMSensitivity** rec
		) {
	char* ptr;

	WznmMSensitivity* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMSensitivity();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "refwznmmstage"),
			PQfnumber(res, "refwznmmcall"),
			PQfnumber(res, "ixvjactype"),
			PQfnumber(res, "ixvjobmask"),
			PQfnumber(res, "jobshort"),
			PQfnumber(res, "argpatt"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "srefmask"),
			PQfnumber(res, "ixvaction"),
			PQfnumber(res, "csgrefwznmmstage"),
			PQfnumber(res, "custcode")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMStage = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMCall = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVJactype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVJobmask = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Jobshort.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Argpatt.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Srefmask.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixVAction = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->csgRefWznmMStage = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Custcode = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMSensitivity::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMSensitivity& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMSensitivity* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "refwznmmstage"),
			PQfnumber(res, "refwznmmcall"),
			PQfnumber(res, "ixvjactype"),
			PQfnumber(res, "ixvjobmask"),
			PQfnumber(res, "jobshort"),
			PQfnumber(res, "argpatt"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "srefmask"),
			PQfnumber(res, "ixvaction"),
			PQfnumber(res, "csgrefwznmmstage"),
			PQfnumber(res, "custcode")
		};

		while (numread < numrow) {
			rec = new WznmMSensitivity();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMStage = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMCall = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVJactype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVJobmask = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Jobshort.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Argpatt.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Srefmask.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixVAction = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->csgRefWznmMStage = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Custcode = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMSensitivity::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMSensitivity** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSensitivity::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMSensitivity::loadRecBySQL(
			const string& sqlstr
			, WznmMSensitivity** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSensitivity::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSensitivity& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSensitivity::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMSensitivity::insertRec(
			WznmMSensitivity* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refWznmMStage = htonl64(rec->refWznmMStage);
	ubigint _refWznmMCall = htonl64(rec->refWznmMCall);
	uint _ixVJactype = htonl(rec->ixVJactype);
	uint _ixVJobmask = htonl(rec->ixVJobmask);
	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	uint _ixVAction = htonl(rec->ixVAction);
	ubigint _csgRefWznmMStage = htonl64(rec->csgRefWznmMStage);
	smallint _Custcode = htons((smallint) rec->Custcode);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMJob,
		(char*) &_refWznmMStage,
		(char*) &_refWznmMCall,
		(char*) &_ixVJactype,
		(char*) &_ixVJobmask,
		rec->Jobshort.c_str(),
		rec->Argpatt.c_str(),
		(char*) &_refWznmMControl,
		rec->Srefmask.c_str(),
		(char*) &_ixVAction,
		(char*) &_csgRefWznmMStage,
		(char*) &_Custcode
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMSensitivity_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSensitivity::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMSensitivity::insertRst(
			ListWznmMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMSensitivity::updateRec(
			WznmMSensitivity* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refWznmMStage = htonl64(rec->refWznmMStage);
	ubigint _refWznmMCall = htonl64(rec->refWznmMCall);
	uint _ixVJactype = htonl(rec->ixVJactype);
	uint _ixVJobmask = htonl(rec->ixVJobmask);
	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	uint _ixVAction = htonl(rec->ixVAction);
	ubigint _csgRefWznmMStage = htonl64(rec->csgRefWznmMStage);
	smallint _Custcode = htons((smallint) rec->Custcode);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMJob,
		(char*) &_refWznmMStage,
		(char*) &_refWznmMCall,
		(char*) &_ixVJactype,
		(char*) &_ixVJobmask,
		rec->Jobshort.c_str(),
		rec->Argpatt.c_str(),
		(char*) &_refWznmMControl,
		rec->Srefmask.c_str(),
		(char*) &_ixVAction,
		(char*) &_csgRefWznmMStage,
		(char*) &_Custcode,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMSensitivity_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSensitivity::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMSensitivity::updateRst(
			ListWznmMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMSensitivity::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMSensitivity_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSensitivity::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMSensitivity::loadRecByRef(
			ubigint ref
			, WznmMSensitivity** rec
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

	return loadRecByStmt("TblWznmMSensitivity_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMSensitivity::loadRefsByJob(
			ubigint refWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMSensitivity_loadRefsByJob", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMSensitivity::loadRefsBySge(
			ubigint refWznmMStage
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMStage = htonl64(refWznmMStage);

	const char* vals[] = {
		(char*) &_refWznmMStage
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMSensitivity_loadRefsBySge", 1, vals, l, f, append, refs);
};

#endif
