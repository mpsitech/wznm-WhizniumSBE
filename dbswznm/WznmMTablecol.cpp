/**
	* \file WznmMTablecol.cpp
	* database access for table TblWznmMTablecol (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMTablecol.h"

#include "WznmMTablecol_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMTablecol
 ******************************************************************************/

WznmMTablecol::WznmMTablecol(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint tblRefWznmMTable
			, const uint tblNum
			, const ubigint refWznmMSubset
			, const ubigint refWznmMRelation
			, const uint fctIxVTbl
			, const ubigint fctUref
			, const string sref
			, const string Short
			, const uint ixVSubtype
			, const uint ixVAxisfct
			, const string srefsKOption
			, const bool Principal
			, const bool Eponymous
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->tblRefWznmMTable = tblRefWznmMTable;
	this->tblNum = tblNum;
	this->refWznmMSubset = refWznmMSubset;
	this->refWznmMRelation = refWznmMRelation;
	this->fctIxVTbl = fctIxVTbl;
	this->fctUref = fctUref;
	this->sref = sref;
	this->Short = Short;
	this->ixVSubtype = ixVSubtype;
	this->ixVAxisfct = ixVAxisfct;
	this->srefsKOption = srefsKOption;
	this->Principal = Principal;
	this->Eponymous = Eponymous;
};

bool WznmMTablecol::operator==(
			const WznmMTablecol& comp
		) {
	return false;
};

bool WznmMTablecol::operator!=(
			const WznmMTablecol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMTablecol
 ******************************************************************************/

ListWznmMTablecol::ListWznmMTablecol() {
};

ListWznmMTablecol::ListWznmMTablecol(
			const ListWznmMTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMTablecol(*(src.nodes[i]));
};

ListWznmMTablecol::~ListWznmMTablecol() {
	clear();
};

void ListWznmMTablecol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMTablecol::size() const {
	return(nodes.size());
};

void ListWznmMTablecol::append(
			WznmMTablecol* rec
		) {
	nodes.push_back(rec);
};

WznmMTablecol* ListWznmMTablecol::operator[](
			const uint ix
		) {
	WznmMTablecol* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMTablecol& ListWznmMTablecol::operator=(
			const ListWznmMTablecol& src
		) {
	WznmMTablecol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMTablecol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMTablecol::operator==(
			const ListWznmMTablecol& comp
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

bool ListWznmMTablecol::operator!=(
			const ListWznmMTablecol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMTablecol
 ******************************************************************************/

TblWznmMTablecol::TblWznmMTablecol() {
};

TblWznmMTablecol::~TblWznmMTablecol() {
};

bool TblWznmMTablecol::loadRecBySQL(
			const string& sqlstr
			, WznmMTablecol** rec
		) {
	return false;
};

ubigint TblWznmMTablecol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTablecol& rst
		) {
	return 0;
};

ubigint TblWznmMTablecol::insertRec(
			WznmMTablecol* rec
		) {
	return 0;
};

ubigint TblWznmMTablecol::insertNewRec(
			WznmMTablecol** rec
			, const uint ixVBasetype
			, const ubigint tblRefWznmMTable
			, const uint tblNum
			, const ubigint refWznmMSubset
			, const ubigint refWznmMRelation
			, const uint fctIxVTbl
			, const ubigint fctUref
			, const string sref
			, const string Short
			, const uint ixVSubtype
			, const uint ixVAxisfct
			, const string srefsKOption
			, const bool Principal
			, const bool Eponymous
		) {
	ubigint retval = 0;
	WznmMTablecol* _rec = NULL;

	_rec = new WznmMTablecol(0, ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMTablecol::appendNewRecToRst(
			ListWznmMTablecol& rst
			, WznmMTablecol** rec
			, const uint ixVBasetype
			, const ubigint tblRefWznmMTable
			, const uint tblNum
			, const ubigint refWznmMSubset
			, const ubigint refWznmMRelation
			, const uint fctIxVTbl
			, const ubigint fctUref
			, const string sref
			, const string Short
			, const uint ixVSubtype
			, const uint ixVAxisfct
			, const string srefsKOption
			, const bool Principal
			, const bool Eponymous
		) {
	ubigint retval = 0;
	WznmMTablecol* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMTablecol::insertRst(
			ListWznmMTablecol& rst
			, bool transact
		) {
};

void TblWznmMTablecol::updateRec(
			WznmMTablecol* rec
		) {
};

void TblWznmMTablecol::updateRst(
			ListWznmMTablecol& rst
			, bool transact
		) {
};

void TblWznmMTablecol::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMTablecol::loadRecByRef(
			ubigint ref
			, WznmMTablecol** rec
		) {
	return false;
};

bool TblWznmMTablecol::loadRefByTblSrf(
			ubigint tblRefWznmMTable
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMTablecol::loadRefsByTbl(
			ubigint tblRefWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMTablecol::loadRstByTbl(
			ubigint tblRefWznmMTable
			, const bool append
			, ListWznmMTablecol& rst
		) {
	return 0;
};

bool TblWznmMTablecol::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMTablecol::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMTablecol& rst
		) {
	ubigint numload = 0;
	WznmMTablecol* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMTablecol
 ******************************************************************************/

MyTblWznmMTablecol::MyTblWznmMTablecol() :
			TblWznmMTablecol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMTablecol::~MyTblWznmMTablecol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMTablecol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMTablecol (ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMTablecol SET ixVBasetype = ?, tblRefWznmMTable = ?, tblNum = ?, refWznmMSubset = ?, refWznmMRelation = ?, fctIxVTbl = ?, fctUref = ?, sref = ?, Short = ?, ixVSubtype = ?, ixVAxisfct = ?, srefsKOption = ?, Principal = ?, Eponymous = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMTablecol WHERE ref = ?", false);
};

bool MyTblWznmMTablecol::loadRecBySQL(
			const string& sqlstr
			, WznmMTablecol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMTablecol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMTablecol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMTablecol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMTablecol();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->tblRefWznmMTable = atoll((char*) dbrow[2]); else _rec->tblRefWznmMTable = 0;
		if (dbrow[3]) _rec->tblNum = atol((char*) dbrow[3]); else _rec->tblNum = 0;
		if (dbrow[4]) _rec->refWznmMSubset = atoll((char*) dbrow[4]); else _rec->refWznmMSubset = 0;
		if (dbrow[5]) _rec->refWznmMRelation = atoll((char*) dbrow[5]); else _rec->refWznmMRelation = 0;
		if (dbrow[6]) _rec->fctIxVTbl = atol((char*) dbrow[6]); else _rec->fctIxVTbl = 0;
		if (dbrow[7]) _rec->fctUref = atoll((char*) dbrow[7]); else _rec->fctUref = 0;
		if (dbrow[8]) _rec->sref.assign(dbrow[8], dblengths[8]); else _rec->sref = "";
		if (dbrow[9]) _rec->Short.assign(dbrow[9], dblengths[9]); else _rec->Short = "";
		if (dbrow[10]) _rec->ixVSubtype = atol((char*) dbrow[10]); else _rec->ixVSubtype = 0;
		if (dbrow[11]) _rec->ixVAxisfct = atol((char*) dbrow[11]); else _rec->ixVAxisfct = 0;
		if (dbrow[12]) _rec->srefsKOption.assign(dbrow[12], dblengths[12]); else _rec->srefsKOption = "";
		if (dbrow[13]) _rec->Principal = (atoi((char*) dbrow[13]) != 0); else _rec->Principal = false;
		if (dbrow[14]) _rec->Eponymous = (atoi((char*) dbrow[14]) != 0); else _rec->Eponymous = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMTablecol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTablecol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMTablecol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMTablecol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMTablecol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMTablecol();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->tblRefWznmMTable = atoll((char*) dbrow[2]); else rec->tblRefWznmMTable = 0;
			if (dbrow[3]) rec->tblNum = atol((char*) dbrow[3]); else rec->tblNum = 0;
			if (dbrow[4]) rec->refWznmMSubset = atoll((char*) dbrow[4]); else rec->refWznmMSubset = 0;
			if (dbrow[5]) rec->refWznmMRelation = atoll((char*) dbrow[5]); else rec->refWznmMRelation = 0;
			if (dbrow[6]) rec->fctIxVTbl = atol((char*) dbrow[6]); else rec->fctIxVTbl = 0;
			if (dbrow[7]) rec->fctUref = atoll((char*) dbrow[7]); else rec->fctUref = 0;
			if (dbrow[8]) rec->sref.assign(dbrow[8], dblengths[8]); else rec->sref = "";
			if (dbrow[9]) rec->Short.assign(dbrow[9], dblengths[9]); else rec->Short = "";
			if (dbrow[10]) rec->ixVSubtype = atol((char*) dbrow[10]); else rec->ixVSubtype = 0;
			if (dbrow[11]) rec->ixVAxisfct = atol((char*) dbrow[11]); else rec->ixVAxisfct = 0;
			if (dbrow[12]) rec->srefsKOption.assign(dbrow[12], dblengths[12]); else rec->srefsKOption = "";
			if (dbrow[13]) rec->Principal = (atoi((char*) dbrow[13]) != 0); else rec->Principal = false;
			if (dbrow[14]) rec->Eponymous = (atoi((char*) dbrow[14]) != 0); else rec->Eponymous = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMTablecol::insertRec(
			WznmMTablecol* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[7] = rec->sref.length();
	l[8] = rec->Short.length();
	l[11] = rec->srefsKOption.length();
	tinyint Principal = rec->Principal;
	tinyint Eponymous = rec->Eponymous;

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->tblRefWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->tblNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMSubset,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMRelation,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->fctIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->fctUref,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->sref.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Short.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVSubtype,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVAxisfct,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Principal,&(l[12]),&(n[12]),&(e[12])),
		bindTinyint(&Eponymous,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMTablecol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMTablecol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMTablecol::insertRst(
			ListWznmMTablecol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMTablecol::updateRec(
			WznmMTablecol* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[7] = rec->sref.length();
	l[8] = rec->Short.length();
	l[11] = rec->srefsKOption.length();
	tinyint Principal = rec->Principal;
	tinyint Eponymous = rec->Eponymous;

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->tblRefWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->tblNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMSubset,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMRelation,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->fctIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->fctUref,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->sref.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Short.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVSubtype,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVAxisfct,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Principal,&(l[12]),&(n[12]),&(e[12])),
		bindTinyint(&Eponymous,&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->ref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMTablecol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMTablecol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMTablecol::updateRst(
			ListWznmMTablecol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMTablecol::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMTablecol::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMTablecol::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMTablecol::loadRecByRef(
			ubigint ref
			, WznmMTablecol** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMTablecol::loadRefByTblSrf(
			ubigint tblRefWznmMTable
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tblRefWznmMTable) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMTablecol::loadRefsByTbl(
			ubigint tblRefWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tblRefWznmMTable) + "", append, refs);
};

ubigint MyTblWznmMTablecol::loadRstByTbl(
			ubigint tblRefWznmMTable
			, const bool append
			, ListWznmMTablecol& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tblRefWznmMTable) + " ORDER BY tblNum ASC", append, rst);
};

bool MyTblWznmMTablecol::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMTablecol WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMTablecol
 ******************************************************************************/

PgTblWznmMTablecol::PgTblWznmMTablecol() :
			TblWznmMTablecol()
			, PgTable()
		{
};

PgTblWznmMTablecol::~PgTblWznmMTablecol() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMTablecol::initStatements() {
	createStatement("TblWznmMTablecol_insertRec", "INSERT INTO TblWznmMTablecol (ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING ref", 14);
	createStatement("TblWznmMTablecol_updateRec", "UPDATE TblWznmMTablecol SET ixVBasetype = $1, tblRefWznmMTable = $2, tblNum = $3, refWznmMSubset = $4, refWznmMRelation = $5, fctIxVTbl = $6, fctUref = $7, sref = $8, Short = $9, ixVSubtype = $10, ixVAxisfct = $11, srefsKOption = $12, Principal = $13, Eponymous = $14 WHERE ref = $15", 15);
	createStatement("TblWznmMTablecol_removeRecByRef", "DELETE FROM TblWznmMTablecol WHERE ref = $1", 1);

	createStatement("TblWznmMTablecol_loadRecByRef", "SELECT ref, ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous FROM TblWznmMTablecol WHERE ref = $1", 1);
	createStatement("TblWznmMTablecol_loadRefByTblSrf", "SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = $1 AND sref = $2", 2);
	createStatement("TblWznmMTablecol_loadRefsByTbl", "SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = $1", 1);
	createStatement("TblWznmMTablecol_loadRstByTbl", "SELECT ref, ixVBasetype, tblRefWznmMTable, tblNum, refWznmMSubset, refWznmMRelation, fctIxVTbl, fctUref, sref, Short, ixVSubtype, ixVAxisfct, srefsKOption, Principal, Eponymous FROM TblWznmMTablecol WHERE tblRefWznmMTable = $1 ORDER BY tblNum ASC", 1);
	createStatement("TblWznmMTablecol_loadSrfByRef", "SELECT sref FROM TblWznmMTablecol WHERE ref = $1", 1);
};

bool PgTblWznmMTablecol::loadRec(
			PGresult* res
			, WznmMTablecol** rec
		) {
	char* ptr;

	WznmMTablecol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMTablecol();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "tblrefwznmmtable"),
			PQfnumber(res, "tblnum"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "refwznmmrelation"),
			PQfnumber(res, "fctixvtbl"),
			PQfnumber(res, "fcturef"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "ixvsubtype"),
			PQfnumber(res, "ixvaxisfct"),
			PQfnumber(res, "srefskoption"),
			PQfnumber(res, "principal"),
			PQfnumber(res, "eponymous")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->tblRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->tblNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMRelation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->fctIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->fctUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixVSubtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixVAxisfct = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Principal = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Eponymous = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMTablecol::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMTablecol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMTablecol* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "tblrefwznmmtable"),
			PQfnumber(res, "tblnum"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "refwznmmrelation"),
			PQfnumber(res, "fctixvtbl"),
			PQfnumber(res, "fcturef"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "ixvsubtype"),
			PQfnumber(res, "ixvaxisfct"),
			PQfnumber(res, "srefskoption"),
			PQfnumber(res, "principal"),
			PQfnumber(res, "eponymous")
		};

		while (numread < numrow) {
			rec = new WznmMTablecol();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->tblRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->tblNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMRelation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->fctIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->fctUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixVSubtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixVAxisfct = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Principal = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Eponymous = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMTablecol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMTablecol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTablecol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMTablecol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMTablecol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTablecol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMTablecol::loadRecBySQL(
			const string& sqlstr
			, WznmMTablecol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTablecol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMTablecol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTablecol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTablecol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMTablecol::insertRec(
			WznmMTablecol* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _tblRefWznmMTable = htonl64(rec->tblRefWznmMTable);
	uint _tblNum = htonl(rec->tblNum);
	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	ubigint _refWznmMRelation = htonl64(rec->refWznmMRelation);
	uint _fctIxVTbl = htonl(rec->fctIxVTbl);
	ubigint _fctUref = htonl64(rec->fctUref);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	uint _ixVAxisfct = htonl(rec->ixVAxisfct);
	smallint _Principal = htons((smallint) rec->Principal);
	smallint _Eponymous = htons((smallint) rec->Eponymous);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_tblRefWznmMTable,
		(char*) &_tblNum,
		(char*) &_refWznmMSubset,
		(char*) &_refWznmMRelation,
		(char*) &_fctIxVTbl,
		(char*) &_fctUref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVSubtype,
		(char*) &_ixVAxisfct,
		rec->srefsKOption.c_str(),
		(char*) &_Principal,
		(char*) &_Eponymous
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(smallint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMTablecol_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTablecol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMTablecol::insertRst(
			ListWznmMTablecol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMTablecol::updateRec(
			WznmMTablecol* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _tblRefWznmMTable = htonl64(rec->tblRefWznmMTable);
	uint _tblNum = htonl(rec->tblNum);
	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	ubigint _refWznmMRelation = htonl64(rec->refWznmMRelation);
	uint _fctIxVTbl = htonl(rec->fctIxVTbl);
	ubigint _fctUref = htonl64(rec->fctUref);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	uint _ixVAxisfct = htonl(rec->ixVAxisfct);
	smallint _Principal = htons((smallint) rec->Principal);
	smallint _Eponymous = htons((smallint) rec->Eponymous);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_tblRefWznmMTable,
		(char*) &_tblNum,
		(char*) &_refWznmMSubset,
		(char*) &_refWznmMRelation,
		(char*) &_fctIxVTbl,
		(char*) &_fctUref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVSubtype,
		(char*) &_ixVAxisfct,
		rec->srefsKOption.c_str(),
		(char*) &_Principal,
		(char*) &_Eponymous,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(smallint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMTablecol_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMTablecol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMTablecol::updateRst(
			ListWznmMTablecol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMTablecol::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMTablecol_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMTablecol::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMTablecol::loadRecByRef(
			ubigint ref
			, WznmMTablecol** rec
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

	return loadRecByStmt("TblWznmMTablecol_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMTablecol::loadRefByTblSrf(
			ubigint tblRefWznmMTable
			, string sref
			, ubigint& ref
		) {
	ubigint _tblRefWznmMTable = htonl64(tblRefWznmMTable);

	const char* vals[] = {
		(char*) &_tblRefWznmMTable,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWznmMTablecol_loadRefByTblSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMTablecol::loadRefsByTbl(
			ubigint tblRefWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _tblRefWznmMTable = htonl64(tblRefWznmMTable);

	const char* vals[] = {
		(char*) &_tblRefWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMTablecol_loadRefsByTbl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMTablecol::loadRstByTbl(
			ubigint tblRefWznmMTable
			, const bool append
			, ListWznmMTablecol& rst
		) {
	ubigint _tblRefWznmMTable = htonl64(tblRefWznmMTable);

	const char* vals[] = {
		(char*) &_tblRefWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMTablecol_loadRstByTbl", 1, vals, l, f, append, rst);
};

bool PgTblWznmMTablecol::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMTablecol_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

