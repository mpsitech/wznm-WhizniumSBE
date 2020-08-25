/**
	* \file WznmMImpexpcol.cpp
	* database access for table TblWznmMImpexpcol (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMImpexpcol.h"

#include "WznmMImpexpcol_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMImpexpcol
 ******************************************************************************/

WznmMImpexpcol::WznmMImpexpcol(
			const ubigint ref
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const ubigint imeRefWznmMImpexp
			, const uint imeNum
			, const ubigint refWznmMTablecol
			, const string sref
			, const string Short
			, const ubigint refWznmMImpexp
			, const uint ixVConvtype
			, const string Defval
			, const ubigint refWznmMPreset
			, const ubigint refJStub
			, const ubigint refWznmMStub
			, const ubigint refWznmMVectoritem
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->ixWOccurrence = ixWOccurrence;
	this->imeRefWznmMImpexp = imeRefWznmMImpexp;
	this->imeNum = imeNum;
	this->refWznmMTablecol = refWznmMTablecol;
	this->sref = sref;
	this->Short = Short;
	this->refWznmMImpexp = refWznmMImpexp;
	this->ixVConvtype = ixVConvtype;
	this->Defval = Defval;
	this->refWznmMPreset = refWznmMPreset;
	this->refJStub = refJStub;
	this->refWznmMStub = refWznmMStub;
	this->refWznmMVectoritem = refWznmMVectoritem;
};

bool WznmMImpexpcol::operator==(
			const WznmMImpexpcol& comp
		) {
	return false;
};

bool WznmMImpexpcol::operator!=(
			const WznmMImpexpcol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMImpexpcol
 ******************************************************************************/

ListWznmMImpexpcol::ListWznmMImpexpcol() {
};

ListWznmMImpexpcol::ListWznmMImpexpcol(
			const ListWznmMImpexpcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMImpexpcol(*(src.nodes[i]));
};

ListWznmMImpexpcol::~ListWznmMImpexpcol() {
	clear();
};

void ListWznmMImpexpcol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMImpexpcol::size() const {
	return(nodes.size());
};

void ListWznmMImpexpcol::append(
			WznmMImpexpcol* rec
		) {
	nodes.push_back(rec);
};

WznmMImpexpcol* ListWznmMImpexpcol::operator[](
			const uint ix
		) {
	WznmMImpexpcol* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMImpexpcol& ListWznmMImpexpcol::operator=(
			const ListWznmMImpexpcol& src
		) {
	WznmMImpexpcol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMImpexpcol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMImpexpcol::operator==(
			const ListWznmMImpexpcol& comp
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

bool ListWznmMImpexpcol::operator!=(
			const ListWznmMImpexpcol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMImpexpcol
 ******************************************************************************/

TblWznmMImpexpcol::TblWznmMImpexpcol() {
};

TblWznmMImpexpcol::~TblWznmMImpexpcol() {
};

bool TblWznmMImpexpcol::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexpcol** rec
		) {
	return false;
};

ubigint TblWznmMImpexpcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	return 0;
};

ubigint TblWznmMImpexpcol::insertRec(
			WznmMImpexpcol* rec
		) {
	return 0;
};

ubigint TblWznmMImpexpcol::insertNewRec(
			WznmMImpexpcol** rec
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const ubigint imeRefWznmMImpexp
			, const uint imeNum
			, const ubigint refWznmMTablecol
			, const string sref
			, const string Short
			, const ubigint refWznmMImpexp
			, const uint ixVConvtype
			, const string Defval
			, const ubigint refWznmMPreset
			, const ubigint refJStub
			, const ubigint refWznmMStub
			, const ubigint refWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmMImpexpcol* _rec = NULL;

	_rec = new WznmMImpexpcol(0, ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMImpexpcol::appendNewRecToRst(
			ListWznmMImpexpcol& rst
			, WznmMImpexpcol** rec
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const ubigint imeRefWznmMImpexp
			, const uint imeNum
			, const ubigint refWznmMTablecol
			, const string sref
			, const string Short
			, const ubigint refWznmMImpexp
			, const uint ixVConvtype
			, const string Defval
			, const ubigint refWznmMPreset
			, const ubigint refJStub
			, const ubigint refWznmMStub
			, const ubigint refWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmMImpexpcol* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMImpexpcol::insertRst(
			ListWznmMImpexpcol& rst
			, bool transact
		) {
};

void TblWznmMImpexpcol::updateRec(
			WznmMImpexpcol* rec
		) {
};

void TblWznmMImpexpcol::updateRst(
			ListWznmMImpexpcol& rst
			, bool transact
		) {
};

void TblWznmMImpexpcol::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMImpexpcol::loadRecByRef(
			ubigint ref
			, WznmMImpexpcol** rec
		) {
	return false;
};

ubigint TblWznmMImpexpcol::loadRefsByIme(
			ubigint imeRefWznmMImpexp
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMImpexpcol::loadRstByIme(
			ubigint imeRefWznmMImpexp
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	return 0;
};

ubigint TblWznmMImpexpcol::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	ubigint numload = 0;
	WznmMImpexpcol* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMImpexpcol
 ******************************************************************************/

MyTblWznmMImpexpcol::MyTblWznmMImpexpcol() :
			TblWznmMImpexpcol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMImpexpcol::~MyTblWznmMImpexpcol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMImpexpcol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMImpexpcol (ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMImpexpcol SET ixVBasetype = ?, ixWOccurrence = ?, imeRefWznmMImpexp = ?, imeNum = ?, refWznmMTablecol = ?, sref = ?, Short = ?, refWznmMImpexp = ?, ixVConvtype = ?, Defval = ?, refWznmMPreset = ?, refJStub = ?, refWznmMStub = ?, refWznmMVectoritem = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMImpexpcol WHERE ref = ?", false);
};

bool MyTblWznmMImpexpcol::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexpcol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMImpexpcol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMImpexpcol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMImpexpcol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMImpexpcol();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->ixWOccurrence = atol((char*) dbrow[2]); else _rec->ixWOccurrence = 0;
		if (dbrow[3]) _rec->imeRefWznmMImpexp = atoll((char*) dbrow[3]); else _rec->imeRefWznmMImpexp = 0;
		if (dbrow[4]) _rec->imeNum = atol((char*) dbrow[4]); else _rec->imeNum = 0;
		if (dbrow[5]) _rec->refWznmMTablecol = atoll((char*) dbrow[5]); else _rec->refWznmMTablecol = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Short.assign(dbrow[7], dblengths[7]); else _rec->Short = "";
		if (dbrow[8]) _rec->refWznmMImpexp = atoll((char*) dbrow[8]); else _rec->refWznmMImpexp = 0;
		if (dbrow[9]) _rec->ixVConvtype = atol((char*) dbrow[9]); else _rec->ixVConvtype = 0;
		if (dbrow[10]) _rec->Defval.assign(dbrow[10], dblengths[10]); else _rec->Defval = "";
		if (dbrow[11]) _rec->refWznmMPreset = atoll((char*) dbrow[11]); else _rec->refWznmMPreset = 0;
		if (dbrow[12]) _rec->refJStub = atoll((char*) dbrow[12]); else _rec->refJStub = 0;
		if (dbrow[13]) _rec->refWznmMStub = atoll((char*) dbrow[13]); else _rec->refWznmMStub = 0;
		if (dbrow[14]) _rec->refWznmMVectoritem = atoll((char*) dbrow[14]); else _rec->refWznmMVectoritem = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMImpexpcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMImpexpcol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMImpexpcol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMImpexpcol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMImpexpcol();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->ixWOccurrence = atol((char*) dbrow[2]); else rec->ixWOccurrence = 0;
			if (dbrow[3]) rec->imeRefWznmMImpexp = atoll((char*) dbrow[3]); else rec->imeRefWznmMImpexp = 0;
			if (dbrow[4]) rec->imeNum = atol((char*) dbrow[4]); else rec->imeNum = 0;
			if (dbrow[5]) rec->refWznmMTablecol = atoll((char*) dbrow[5]); else rec->refWznmMTablecol = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Short.assign(dbrow[7], dblengths[7]); else rec->Short = "";
			if (dbrow[8]) rec->refWznmMImpexp = atoll((char*) dbrow[8]); else rec->refWznmMImpexp = 0;
			if (dbrow[9]) rec->ixVConvtype = atol((char*) dbrow[9]); else rec->ixVConvtype = 0;
			if (dbrow[10]) rec->Defval.assign(dbrow[10], dblengths[10]); else rec->Defval = "";
			if (dbrow[11]) rec->refWznmMPreset = atoll((char*) dbrow[11]); else rec->refWznmMPreset = 0;
			if (dbrow[12]) rec->refJStub = atoll((char*) dbrow[12]); else rec->refJStub = 0;
			if (dbrow[13]) rec->refWznmMStub = atoll((char*) dbrow[13]); else rec->refWznmMStub = 0;
			if (dbrow[14]) rec->refWznmMVectoritem = atoll((char*) dbrow[14]); else rec->refWznmMVectoritem = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMImpexpcol::insertRec(
			WznmMImpexpcol* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->sref.length();
	l[6] = rec->Short.length();
	l[9] = rec->Defval.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixWOccurrence,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->imeRefWznmMImpexp,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->imeNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMTablecol,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Short.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMImpexp,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVConvtype,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMPreset,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refJStub,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->refWznmMStub,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMImpexpcol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMImpexpcol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMImpexpcol::insertRst(
			ListWznmMImpexpcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMImpexpcol::updateRec(
			WznmMImpexpcol* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[5] = rec->sref.length();
	l[6] = rec->Short.length();
	l[9] = rec->Defval.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixWOccurrence,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->imeRefWznmMImpexp,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->imeNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMTablecol,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Short.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMImpexp,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVConvtype,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMPreset,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refJStub,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->refWznmMStub,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->ref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMImpexpcol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMImpexpcol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMImpexpcol::updateRst(
			ListWznmMImpexpcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMImpexpcol::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMImpexpcol::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMImpexpcol::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMImpexpcol::loadRecByRef(
			ubigint ref
			, WznmMImpexpcol** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMImpexpcol WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMImpexpcol::loadRefsByIme(
			ubigint imeRefWznmMImpexp
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(imeRefWznmMImpexp) + "", append, refs);
};

ubigint MyTblWznmMImpexpcol::loadRstByIme(
			ubigint imeRefWznmMImpexp
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(imeRefWznmMImpexp) + " ORDER BY imeNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMImpexpcol
 ******************************************************************************/

PgTblWznmMImpexpcol::PgTblWznmMImpexpcol() :
			TblWznmMImpexpcol()
			, PgTable()
		{
};

PgTblWznmMImpexpcol::~PgTblWznmMImpexpcol() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMImpexpcol::initStatements() {
	createStatement("TblWznmMImpexpcol_insertRec", "INSERT INTO TblWznmMImpexpcol (ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING ref", 14);
	createStatement("TblWznmMImpexpcol_updateRec", "UPDATE TblWznmMImpexpcol SET ixVBasetype = $1, ixWOccurrence = $2, imeRefWznmMImpexp = $3, imeNum = $4, refWznmMTablecol = $5, sref = $6, Short = $7, refWznmMImpexp = $8, ixVConvtype = $9, Defval = $10, refWznmMPreset = $11, refJStub = $12, refWznmMStub = $13, refWznmMVectoritem = $14 WHERE ref = $15", 15);
	createStatement("TblWznmMImpexpcol_removeRecByRef", "DELETE FROM TblWznmMImpexpcol WHERE ref = $1", 1);

	createStatement("TblWznmMImpexpcol_loadRecByRef", "SELECT ref, ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem FROM TblWznmMImpexpcol WHERE ref = $1", 1);
	createStatement("TblWznmMImpexpcol_loadRefsByIme", "SELECT ref FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = $1", 1);
	createStatement("TblWznmMImpexpcol_loadRstByIme", "SELECT ref, ixVBasetype, ixWOccurrence, imeRefWznmMImpexp, imeNum, refWznmMTablecol, sref, Short, refWznmMImpexp, ixVConvtype, Defval, refWznmMPreset, refJStub, refWznmMStub, refWznmMVectoritem FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = $1 ORDER BY imeNum ASC", 1);
};

bool PgTblWznmMImpexpcol::loadRec(
			PGresult* res
			, WznmMImpexpcol** rec
		) {
	char* ptr;

	WznmMImpexpcol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMImpexpcol();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixwoccurrence"),
			PQfnumber(res, "imerefwznmmimpexp"),
			PQfnumber(res, "imenum"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "refwznmmimpexp"),
			PQfnumber(res, "ixvconvtype"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refjstub"),
			PQfnumber(res, "refwznmmstub"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->ixWOccurrence = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->imeRefWznmMImpexp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->imeNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMTablecol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMImpexp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVConvtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->refJStub = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->refWznmMStub = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->refWznmMVectoritem = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMImpexpcol::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMImpexpcol* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixwoccurrence"),
			PQfnumber(res, "imerefwznmmimpexp"),
			PQfnumber(res, "imenum"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "refwznmmimpexp"),
			PQfnumber(res, "ixvconvtype"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refjstub"),
			PQfnumber(res, "refwznmmstub"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		while (numread < numrow) {
			rec = new WznmMImpexpcol();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->ixWOccurrence = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->imeRefWznmMImpexp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->imeNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMTablecol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMImpexp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVConvtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->refJStub = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->refWznmMStub = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->refWznmMVectoritem = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMImpexpcol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMImpexpcol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMImpexpcol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMImpexpcol::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexpcol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMImpexpcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMImpexpcol::insertRec(
			WznmMImpexpcol* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixWOccurrence = htonl(rec->ixWOccurrence);
	ubigint _imeRefWznmMImpexp = htonl64(rec->imeRefWznmMImpexp);
	uint _imeNum = htonl(rec->imeNum);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _refWznmMImpexp = htonl64(rec->refWznmMImpexp);
	uint _ixVConvtype = htonl(rec->ixVConvtype);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refJStub = htonl64(rec->refJStub);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_ixWOccurrence,
		(char*) &_imeRefWznmMImpexp,
		(char*) &_imeNum,
		(char*) &_refWznmMTablecol,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_refWznmMImpexp,
		(char*) &_ixVConvtype,
		rec->Defval.c_str(),
		(char*) &_refWznmMPreset,
		(char*) &_refJStub,
		(char*) &_refWznmMStub,
		(char*) &_refWznmMVectoritem
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMImpexpcol_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMImpexpcol::insertRst(
			ListWznmMImpexpcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMImpexpcol::updateRec(
			WznmMImpexpcol* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixWOccurrence = htonl(rec->ixWOccurrence);
	ubigint _imeRefWznmMImpexp = htonl64(rec->imeRefWznmMImpexp);
	uint _imeNum = htonl(rec->imeNum);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _refWznmMImpexp = htonl64(rec->refWznmMImpexp);
	uint _ixVConvtype = htonl(rec->ixVConvtype);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refJStub = htonl64(rec->refJStub);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_ixWOccurrence,
		(char*) &_imeRefWznmMImpexp,
		(char*) &_imeNum,
		(char*) &_refWznmMTablecol,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_refWznmMImpexp,
		(char*) &_ixVConvtype,
		rec->Defval.c_str(),
		(char*) &_refWznmMPreset,
		(char*) &_refJStub,
		(char*) &_refWznmMStub,
		(char*) &_refWznmMVectoritem,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMImpexpcol_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMImpexpcol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMImpexpcol::updateRst(
			ListWznmMImpexpcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMImpexpcol::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMImpexpcol_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMImpexpcol::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMImpexpcol::loadRecByRef(
			ubigint ref
			, WznmMImpexpcol** rec
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

	return loadRecByStmt("TblWznmMImpexpcol_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMImpexpcol::loadRefsByIme(
			ubigint imeRefWznmMImpexp
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _imeRefWznmMImpexp = htonl64(imeRefWznmMImpexp);

	const char* vals[] = {
		(char*) &_imeRefWznmMImpexp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMImpexpcol_loadRefsByIme", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMImpexpcol::loadRstByIme(
			ubigint imeRefWznmMImpexp
			, const bool append
			, ListWznmMImpexpcol& rst
		) {
	ubigint _imeRefWznmMImpexp = htonl64(imeRefWznmMImpexp);

	const char* vals[] = {
		(char*) &_imeRefWznmMImpexp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMImpexpcol_loadRstByIme", 1, vals, l, f, append, rst);
};

#endif

