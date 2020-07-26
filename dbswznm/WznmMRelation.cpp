/**
	* \file WznmMRelation.cpp
	* database access for table TblWznmMRelation (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMRelation.h"

#include "WznmMRelation_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMRelation
 ******************************************************************************/

WznmMRelation::WznmMRelation(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmCRelation
			, const ubigint refWznmMVersion
			, const ubigint supRefWznmMRelation
			, const uint supIxVSubrole
			, const ubigint frRefWznmMTable
			, const ubigint frsRefWznmMSubset
			, const ubigint toRefWznmMTable
			, const ubigint tosRefWznmMSubset
			, const ubigint refWznmMTable
			, const string Prefix
			, const string srefsKOption
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmCRelation = refWznmCRelation;
	this->refWznmMVersion = refWznmMVersion;
	this->supRefWznmMRelation = supRefWznmMRelation;
	this->supIxVSubrole = supIxVSubrole;
	this->frRefWznmMTable = frRefWznmMTable;
	this->frsRefWznmMSubset = frsRefWznmMSubset;
	this->toRefWznmMTable = toRefWznmMTable;
	this->tosRefWznmMSubset = tosRefWznmMSubset;
	this->refWznmMTable = refWznmMTable;
	this->Prefix = Prefix;
	this->srefsKOption = srefsKOption;
};

bool WznmMRelation::operator==(
			const WznmMRelation& comp
		) {
	return false;
};

bool WznmMRelation::operator!=(
			const WznmMRelation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMRelation
 ******************************************************************************/

ListWznmMRelation::ListWznmMRelation() {
};

ListWznmMRelation::ListWznmMRelation(
			const ListWznmMRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMRelation(*(src.nodes[i]));
};

ListWznmMRelation::~ListWznmMRelation() {
	clear();
};

void ListWznmMRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMRelation::size() const {
	return(nodes.size());
};

void ListWznmMRelation::append(
			WznmMRelation* rec
		) {
	nodes.push_back(rec);
};

WznmMRelation* ListWznmMRelation::operator[](
			const uint ix
		) {
	WznmMRelation* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMRelation& ListWznmMRelation::operator=(
			const ListWznmMRelation& src
		) {
	WznmMRelation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMRelation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMRelation::operator==(
			const ListWznmMRelation& comp
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

bool ListWznmMRelation::operator!=(
			const ListWznmMRelation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMRelation
 ******************************************************************************/

TblWznmMRelation::TblWznmMRelation() {
};

TblWznmMRelation::~TblWznmMRelation() {
};

bool TblWznmMRelation::loadRecBySQL(
			const string& sqlstr
			, WznmMRelation** rec
		) {
	return false;
};

ubigint TblWznmMRelation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRelation& rst
		) {
	return 0;
};

ubigint TblWznmMRelation::insertRec(
			WznmMRelation* rec
		) {
	return 0;
};

ubigint TblWznmMRelation::insertNewRec(
			WznmMRelation** rec
			, const uint ixVBasetype
			, const ubigint refWznmCRelation
			, const ubigint refWznmMVersion
			, const ubigint supRefWznmMRelation
			, const uint supIxVSubrole
			, const ubigint frRefWznmMTable
			, const ubigint frsRefWznmMSubset
			, const ubigint toRefWznmMTable
			, const ubigint tosRefWznmMSubset
			, const ubigint refWznmMTable
			, const string Prefix
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WznmMRelation* _rec = NULL;

	_rec = new WznmMRelation(0, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMRelation::appendNewRecToRst(
			ListWznmMRelation& rst
			, WznmMRelation** rec
			, const uint ixVBasetype
			, const ubigint refWznmCRelation
			, const ubigint refWznmMVersion
			, const ubigint supRefWznmMRelation
			, const uint supIxVSubrole
			, const ubigint frRefWznmMTable
			, const ubigint frsRefWznmMSubset
			, const ubigint toRefWznmMTable
			, const ubigint tosRefWznmMSubset
			, const ubigint refWznmMTable
			, const string Prefix
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WznmMRelation* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMRelation::insertRst(
			ListWznmMRelation& rst
			, bool transact
		) {
};

void TblWznmMRelation::updateRec(
			WznmMRelation* rec
		) {
};

void TblWznmMRelation::updateRst(
			ListWznmMRelation& rst
			, bool transact
		) {
};

void TblWznmMRelation::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMRelation::loadRecByRef(
			ubigint ref
			, WznmMRelation** rec
		) {
	return false;
};

bool TblWznmMRelation::loadRecByTbl(
			ubigint refWznmMTable
			, WznmMRelation** rec
		) {
	return false;
};

ubigint TblWznmMRelation::loadRefsByClu(
			ubigint refWznmCRelation
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMRelation::loadRstByClu(
			ubigint refWznmCRelation
			, const bool append
			, ListWznmMRelation& rst
		) {
	return 0;
};

ubigint TblWznmMRelation::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMRelation& rst
		) {
	return 0;
};

ubigint TblWznmMRelation::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMRelation& rst
		) {
	ubigint numload = 0;
	WznmMRelation* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMRelation
 ******************************************************************************/

MyTblWznmMRelation::MyTblWznmMRelation() :
			TblWznmMRelation()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMRelation::~MyTblWznmMRelation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMRelation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMRelation (ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMRelation SET ixVBasetype = ?, refWznmCRelation = ?, refWznmMVersion = ?, supRefWznmMRelation = ?, supIxVSubrole = ?, frRefWznmMTable = ?, frsRefWznmMSubset = ?, toRefWznmMTable = ?, tosRefWznmMSubset = ?, refWznmMTable = ?, Prefix = ?, srefsKOption = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMRelation WHERE ref = ?", false);
};

bool MyTblWznmMRelation::loadRecBySQL(
			const string& sqlstr
			, WznmMRelation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMRelation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRelation::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRelation::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMRelation();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmCRelation = atoll((char*) dbrow[2]); else _rec->refWznmCRelation = 0;
		if (dbrow[3]) _rec->refWznmMVersion = atoll((char*) dbrow[3]); else _rec->refWznmMVersion = 0;
		if (dbrow[4]) _rec->supRefWznmMRelation = atoll((char*) dbrow[4]); else _rec->supRefWznmMRelation = 0;
		if (dbrow[5]) _rec->supIxVSubrole = atol((char*) dbrow[5]); else _rec->supIxVSubrole = 0;
		if (dbrow[6]) _rec->frRefWznmMTable = atoll((char*) dbrow[6]); else _rec->frRefWznmMTable = 0;
		if (dbrow[7]) _rec->frsRefWznmMSubset = atoll((char*) dbrow[7]); else _rec->frsRefWznmMSubset = 0;
		if (dbrow[8]) _rec->toRefWznmMTable = atoll((char*) dbrow[8]); else _rec->toRefWznmMTable = 0;
		if (dbrow[9]) _rec->tosRefWznmMSubset = atoll((char*) dbrow[9]); else _rec->tosRefWznmMSubset = 0;
		if (dbrow[10]) _rec->refWznmMTable = atoll((char*) dbrow[10]); else _rec->refWznmMTable = 0;
		if (dbrow[11]) _rec->Prefix.assign(dbrow[11], dblengths[11]); else _rec->Prefix = "";
		if (dbrow[12]) _rec->srefsKOption.assign(dbrow[12], dblengths[12]); else _rec->srefsKOption = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMRelation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRelation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMRelation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRelation::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRelation::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMRelation();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmCRelation = atoll((char*) dbrow[2]); else rec->refWznmCRelation = 0;
			if (dbrow[3]) rec->refWznmMVersion = atoll((char*) dbrow[3]); else rec->refWznmMVersion = 0;
			if (dbrow[4]) rec->supRefWznmMRelation = atoll((char*) dbrow[4]); else rec->supRefWznmMRelation = 0;
			if (dbrow[5]) rec->supIxVSubrole = atol((char*) dbrow[5]); else rec->supIxVSubrole = 0;
			if (dbrow[6]) rec->frRefWznmMTable = atoll((char*) dbrow[6]); else rec->frRefWznmMTable = 0;
			if (dbrow[7]) rec->frsRefWznmMSubset = atoll((char*) dbrow[7]); else rec->frsRefWznmMSubset = 0;
			if (dbrow[8]) rec->toRefWznmMTable = atoll((char*) dbrow[8]); else rec->toRefWznmMTable = 0;
			if (dbrow[9]) rec->tosRefWznmMSubset = atoll((char*) dbrow[9]); else rec->tosRefWznmMSubset = 0;
			if (dbrow[10]) rec->refWznmMTable = atoll((char*) dbrow[10]); else rec->refWznmMTable = 0;
			if (dbrow[11]) rec->Prefix.assign(dbrow[11], dblengths[11]); else rec->Prefix = "";
			if (dbrow[12]) rec->srefsKOption.assign(dbrow[12], dblengths[12]); else rec->srefsKOption = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMRelation::insertRec(
			WznmMRelation* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[10] = rec->Prefix.length();
	l[11] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmCRelation,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMVersion,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->supRefWznmMRelation,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->supIxVSubrole,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->frRefWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->frsRefWznmMSubset,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->toRefWznmMTable,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->tosRefWznmMSubset,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMTable,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMRelation::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMRelation::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMRelation::insertRst(
			ListWznmMRelation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMRelation::updateRec(
			WznmMRelation* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[10] = rec->Prefix.length();
	l[11] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmCRelation,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMVersion,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->supRefWznmMRelation,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->supIxVSubrole,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->frRefWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->frsRefWznmMSubset,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->toRefWznmMTable,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->tosRefWznmMSubset,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMTable,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMRelation::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMRelation::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMRelation::updateRst(
			ListWznmMRelation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMRelation::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMRelation::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMRelation::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMRelation::loadRecByRef(
			ubigint ref
			, WznmMRelation** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMRelation WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMRelation::loadRecByTbl(
			ubigint refWznmMTable
			, WznmMRelation** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE refWznmMTable = " + to_string(refWznmMTable) + "", rec);
};

ubigint MyTblWznmMRelation::loadRefsByClu(
			ubigint refWznmCRelation
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMRelation WHERE refWznmCRelation = " + to_string(refWznmCRelation) + "", append, refs);
};

ubigint MyTblWznmMRelation::loadRstByClu(
			ubigint refWznmCRelation
			, const bool append
			, ListWznmMRelation& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE refWznmCRelation = " + to_string(refWznmCRelation) + "", append, rst);
};

ubigint MyTblWznmMRelation::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMRelation& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE refWznmMVersion = " + to_string(refWznmMVersion) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMRelation
 ******************************************************************************/

PgTblWznmMRelation::PgTblWznmMRelation() :
			TblWznmMRelation()
			, PgTable()
		{
};

PgTblWznmMRelation::~PgTblWznmMRelation() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMRelation::initStatements() {
	createStatement("TblWznmMRelation_insertRec", "INSERT INTO TblWznmMRelation (ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12);
	createStatement("TblWznmMRelation_updateRec", "UPDATE TblWznmMRelation SET ixVBasetype = $1, refWznmCRelation = $2, refWznmMVersion = $3, supRefWznmMRelation = $4, supIxVSubrole = $5, frRefWznmMTable = $6, frsRefWznmMSubset = $7, toRefWznmMTable = $8, tosRefWznmMSubset = $9, refWznmMTable = $10, Prefix = $11, srefsKOption = $12 WHERE ref = $13", 13);
	createStatement("TblWznmMRelation_removeRecByRef", "DELETE FROM TblWznmMRelation WHERE ref = $1", 1);

	createStatement("TblWznmMRelation_loadRecByRef", "SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE ref = $1", 1);
	createStatement("TblWznmMRelation_loadRecByTbl", "SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE refWznmMTable = $1", 1);
	createStatement("TblWznmMRelation_loadRefsByClu", "SELECT ref FROM TblWznmMRelation WHERE refWznmCRelation = $1", 1);
	createStatement("TblWznmMRelation_loadRstByClu", "SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE refWznmCRelation = $1", 1);
	createStatement("TblWznmMRelation_loadRstByVer", "SELECT ref, ixVBasetype, refWznmCRelation, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, refWznmMTable, Prefix, srefsKOption FROM TblWznmMRelation WHERE refWznmMVersion = $1", 1);
};

bool PgTblWznmMRelation::loadRec(
			PGresult* res
			, WznmMRelation** rec
		) {
	char* ptr;

	WznmMRelation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMRelation();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmcrelation"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmrelation"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "frrefwznmmtable"),
			PQfnumber(res, "frsrefwznmmsubset"),
			PQfnumber(res, "torefwznmmtable"),
			PQfnumber(res, "tosrefwznmmsubset"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "prefix"),
			PQfnumber(res, "srefskoption")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmCRelation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supRefWznmMRelation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->supIxVSubrole = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->frRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->frsRefWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->toRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->tosRefWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Prefix.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMRelation::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMRelation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMRelation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmcrelation"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmrelation"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "frrefwznmmtable"),
			PQfnumber(res, "frsrefwznmmsubset"),
			PQfnumber(res, "torefwznmmtable"),
			PQfnumber(res, "tosrefwznmmsubset"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "prefix"),
			PQfnumber(res, "srefskoption")
		};

		while (numread < numrow) {
			rec = new WznmMRelation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmCRelation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supRefWznmMRelation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->supIxVSubrole = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->frRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->frsRefWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->toRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->tosRefWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Prefix.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMRelation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMRelation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelation::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRelation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMRelation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelation::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMRelation::loadRecBySQL(
			const string& sqlstr
			, WznmMRelation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelation::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRelation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRelation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelation::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMRelation::insertRec(
			WznmMRelation* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmCRelation = htonl64(rec->refWznmCRelation);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMRelation = htonl64(rec->supRefWznmMRelation);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _frRefWznmMTable = htonl64(rec->frRefWznmMTable);
	ubigint _frsRefWznmMSubset = htonl64(rec->frsRefWznmMSubset);
	ubigint _toRefWznmMTable = htonl64(rec->toRefWznmMTable);
	ubigint _tosRefWznmMSubset = htonl64(rec->tosRefWznmMSubset);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmCRelation,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMRelation,
		(char*) &_supIxVSubrole,
		(char*) &_frRefWznmMTable,
		(char*) &_frsRefWznmMSubset,
		(char*) &_toRefWznmMTable,
		(char*) &_tosRefWznmMSubset,
		(char*) &_refWznmMTable,
		rec->Prefix.c_str(),
		rec->srefsKOption.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMRelation_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelation::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMRelation::insertRst(
			ListWznmMRelation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMRelation::updateRec(
			WznmMRelation* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmCRelation = htonl64(rec->refWznmCRelation);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMRelation = htonl64(rec->supRefWznmMRelation);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _frRefWznmMTable = htonl64(rec->frRefWznmMTable);
	ubigint _frsRefWznmMSubset = htonl64(rec->frsRefWznmMSubset);
	ubigint _toRefWznmMTable = htonl64(rec->toRefWznmMTable);
	ubigint _tosRefWznmMSubset = htonl64(rec->tosRefWznmMSubset);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmCRelation,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMRelation,
		(char*) &_supIxVSubrole,
		(char*) &_frRefWznmMTable,
		(char*) &_frsRefWznmMSubset,
		(char*) &_toRefWznmMTable,
		(char*) &_tosRefWznmMSubset,
		(char*) &_refWznmMTable,
		rec->Prefix.c_str(),
		rec->srefsKOption.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMRelation_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRelation::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMRelation::updateRst(
			ListWznmMRelation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMRelation::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMRelation_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRelation::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMRelation::loadRecByRef(
			ubigint ref
			, WznmMRelation** rec
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

	return loadRecByStmt("TblWznmMRelation_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMRelation::loadRecByTbl(
			ubigint refWznmMTable
			, WznmMRelation** rec
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMRelation_loadRecByTbl", 1, vals, l, f, rec);
};

ubigint PgTblWznmMRelation::loadRefsByClu(
			ubigint refWznmCRelation
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCRelation = htonl64(refWznmCRelation);

	const char* vals[] = {
		(char*) &_refWznmCRelation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMRelation_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMRelation::loadRstByClu(
			ubigint refWznmCRelation
			, const bool append
			, ListWznmMRelation& rst
		) {
	ubigint _refWznmCRelation = htonl64(refWznmCRelation);

	const char* vals[] = {
		(char*) &_refWznmCRelation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRelation_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmMRelation::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMRelation& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRelation_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

