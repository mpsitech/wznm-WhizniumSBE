/**
	* \file WznmMImpexp.cpp
	* database access for table TblWznmMImpexp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMImpexp.h"

#include "WznmMImpexp_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMImpexp
 ******************************************************************************/

WznmMImpexp::WznmMImpexp(
			const ubigint ref
			, const ubigint refWznmMImpexpcplx
			, const ubigint supRefWznmMImpexp
			, const usmallint supLvl
			, const ubigint refWznmMTable
			, const string sref
			, const uint ixWIop
			, const string rtrSrefsWznmMImpexpcol
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMImpexpcplx = refWznmMImpexpcplx;
	this->supRefWznmMImpexp = supRefWznmMImpexp;
	this->supLvl = supLvl;
	this->refWznmMTable = refWznmMTable;
	this->sref = sref;
	this->ixWIop = ixWIop;
	this->rtrSrefsWznmMImpexpcol = rtrSrefsWznmMImpexpcol;
	this->Comment = Comment;
};

bool WznmMImpexp::operator==(
			const WznmMImpexp& comp
		) {
	return false;
};

bool WznmMImpexp::operator!=(
			const WznmMImpexp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMImpexp
 ******************************************************************************/

ListWznmMImpexp::ListWznmMImpexp() {
};

ListWznmMImpexp::ListWznmMImpexp(
			const ListWznmMImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMImpexp(*(src.nodes[i]));
};

ListWznmMImpexp::~ListWznmMImpexp() {
	clear();
};

void ListWznmMImpexp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMImpexp::size() const {
	return(nodes.size());
};

void ListWznmMImpexp::append(
			WznmMImpexp* rec
		) {
	nodes.push_back(rec);
};

WznmMImpexp* ListWznmMImpexp::operator[](
			const uint ix
		) {
	WznmMImpexp* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMImpexp& ListWznmMImpexp::operator=(
			const ListWznmMImpexp& src
		) {
	WznmMImpexp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMImpexp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMImpexp::operator==(
			const ListWznmMImpexp& comp
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

bool ListWznmMImpexp::operator!=(
			const ListWznmMImpexp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMImpexp
 ******************************************************************************/

TblWznmMImpexp::TblWznmMImpexp() {
};

TblWznmMImpexp::~TblWznmMImpexp() {
};

bool TblWznmMImpexp::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexp** rec
		) {
	return false;
};

ubigint TblWznmMImpexp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexp& rst
		) {
	return 0;
};

ubigint TblWznmMImpexp::insertRec(
			WznmMImpexp* rec
		) {
	return 0;
};

ubigint TblWznmMImpexp::insertNewRec(
			WznmMImpexp** rec
			, const ubigint refWznmMImpexpcplx
			, const ubigint supRefWznmMImpexp
			, const usmallint supLvl
			, const ubigint refWznmMTable
			, const string sref
			, const uint ixWIop
			, const string rtrSrefsWznmMImpexpcol
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMImpexp* _rec = NULL;

	_rec = new WznmMImpexp(0, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMImpexp::appendNewRecToRst(
			ListWznmMImpexp& rst
			, WznmMImpexp** rec
			, const ubigint refWznmMImpexpcplx
			, const ubigint supRefWznmMImpexp
			, const usmallint supLvl
			, const ubigint refWznmMTable
			, const string sref
			, const uint ixWIop
			, const string rtrSrefsWznmMImpexpcol
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMImpexp* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMImpexp::insertRst(
			ListWznmMImpexp& rst
			, bool transact
		) {
};

void TblWznmMImpexp::updateRec(
			WznmMImpexp* rec
		) {
};

void TblWznmMImpexp::updateRst(
			ListWznmMImpexp& rst
			, bool transact
		) {
};

void TblWznmMImpexp::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMImpexp::loadRecByRef(
			ubigint ref
			, WznmMImpexp** rec
		) {
	return false;
};

bool TblWznmMImpexp::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblWznmMImpexp::loadRefsByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMImpexp::loadRefsBySup(
			ubigint supRefWznmMImpexp
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMImpexp::loadRstByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, ListWznmMImpexp& rst
		) {
	return 0;
};

ubigint TblWznmMImpexp::loadRstBySup(
			ubigint supRefWznmMImpexp
			, const bool append
			, ListWznmMImpexp& rst
		) {
	return 0;
};

bool TblWznmMImpexp::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWznmMImpexp::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMImpexp
		) {
	return false;
};

ubigint TblWznmMImpexp::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMImpexp& rst
		) {
	ubigint numload = 0;
	WznmMImpexp* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWznmMImpexp::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWznmMImpexp::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

ubigint TblWznmMImpexp::loadHrstup(
			ubigint ref
			, ListWznmMImpexp& rst
		) {
	WznmMImpexp* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWznmMImpexp;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWznmMImpexp::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWznmMImpexp& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WznmMImpexp* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMImpexp
 ******************************************************************************/

MyTblWznmMImpexp::MyTblWznmMImpexp() :
			TblWznmMImpexp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMImpexp::~MyTblWznmMImpexp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMImpexp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMImpexp (refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMImpexp SET refWznmMImpexpcplx = ?, supRefWznmMImpexp = ?, supLvl = ?, refWznmMTable = ?, sref = ?, ixWIop = ?, rtrSrefsWznmMImpexpcol = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMImpexp WHERE ref = ?", false);
};

bool MyTblWznmMImpexp::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMImpexp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMImpexp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMImpexp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMImpexp();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMImpexpcplx = atoll((char*) dbrow[1]); else _rec->refWznmMImpexpcplx = 0;
		if (dbrow[2]) _rec->supRefWznmMImpexp = atoll((char*) dbrow[2]); else _rec->supRefWznmMImpexp = 0;
		if (dbrow[3]) _rec->supLvl = atoi((char*) dbrow[3]); else _rec->supLvl = 0;
		if (dbrow[4]) _rec->refWznmMTable = atoll((char*) dbrow[4]); else _rec->refWznmMTable = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWIop = atol((char*) dbrow[6]); else _rec->ixWIop = 0;
		if (dbrow[7]) _rec->rtrSrefsWznmMImpexpcol.assign(dbrow[7], dblengths[7]); else _rec->rtrSrefsWznmMImpexpcol = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMImpexp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMImpexp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMImpexp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMImpexp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMImpexp();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMImpexpcplx = atoll((char*) dbrow[1]); else rec->refWznmMImpexpcplx = 0;
			if (dbrow[2]) rec->supRefWznmMImpexp = atoll((char*) dbrow[2]); else rec->supRefWznmMImpexp = 0;
			if (dbrow[3]) rec->supLvl = atoi((char*) dbrow[3]); else rec->supLvl = 0;
			if (dbrow[4]) rec->refWznmMTable = atoll((char*) dbrow[4]); else rec->refWznmMTable = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWIop = atol((char*) dbrow[6]); else rec->ixWIop = 0;
			if (dbrow[7]) rec->rtrSrefsWznmMImpexpcol.assign(dbrow[7], dblengths[7]); else rec->rtrSrefsWznmMImpexpcol = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMImpexp::insertRec(
			WznmMImpexp* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[6] = rec->rtrSrefsWznmMImpexpcol.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMImpexpcplx,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->supRefWznmMImpexp,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->supLvl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMTable,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWIop,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->rtrSrefsWznmMImpexpcol.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMImpexp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMImpexp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMImpexp::insertRst(
			ListWznmMImpexp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMImpexp::updateRec(
			WznmMImpexp* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[6] = rec->rtrSrefsWznmMImpexpcol.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMImpexpcplx,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->supRefWznmMImpexp,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->supLvl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMTable,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWIop,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->rtrSrefsWznmMImpexpcol.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMImpexp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMImpexp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMImpexp::updateRst(
			ListWznmMImpexp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMImpexp::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMImpexp::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMImpexp::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMImpexp::loadRecByRef(
			ubigint ref
			, WznmMImpexp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMImpexp WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMImpexp::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWznmMImpexp WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblWznmMImpexp::loadRefsByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(refWznmMImpexpcplx) + "", append, refs);
};

ubigint MyTblWznmMImpexp::loadRefsBySup(
			ubigint supRefWznmMImpexp
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(supRefWznmMImpexp) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWznmMImpexp::loadRstByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, ListWznmMImpexp& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(refWznmMImpexpcplx) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWznmMImpexp::loadRstBySup(
			ubigint supRefWznmMImpexp
			, const bool append
			, ListWznmMImpexp& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(supRefWznmMImpexp) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMImpexp::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMImpexp WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWznmMImpexp::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMImpexp
		) {
	return loadRefBySQL("SELECT supRefWznmMImpexp FROM TblWznmMImpexp WHERE ref = " + to_string(ref) + "", supRefWznmMImpexp);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMImpexp
 ******************************************************************************/

PgTblWznmMImpexp::PgTblWznmMImpexp() :
			TblWznmMImpexp()
			, PgTable()
		{
};

PgTblWznmMImpexp::~PgTblWznmMImpexp() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMImpexp::initStatements() {
	createStatement("TblWznmMImpexp_insertRec", "INSERT INTO TblWznmMImpexp (refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMImpexp_updateRec", "UPDATE TblWznmMImpexp SET refWznmMImpexpcplx = $1, supRefWznmMImpexp = $2, supLvl = $3, refWznmMTable = $4, sref = $5, ixWIop = $6, rtrSrefsWznmMImpexpcol = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMImpexp_removeRecByRef", "DELETE FROM TblWznmMImpexp WHERE ref = $1", 1);

	createStatement("TblWznmMImpexp_loadRecByRef", "SELECT ref, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment FROM TblWznmMImpexp WHERE ref = $1", 1);
	createStatement("TblWznmMImpexp_confirmByRef", "SELECT ref FROM TblWznmMImpexp WHERE ref = $1", 1);
	createStatement("TblWznmMImpexp_loadRefsByIex", "SELECT ref FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = $1", 1);
	createStatement("TblWznmMImpexp_loadRefsBySup", "SELECT ref FROM TblWznmMImpexp WHERE supRefWznmMImpexp = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMImpexp_loadRstByIex", "SELECT ref, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMImpexp_loadRstBySup", "SELECT ref, refWznmMImpexpcplx, supRefWznmMImpexp, supLvl, refWznmMTable, sref, ixWIop, rtrSrefsWznmMImpexpcol, Comment FROM TblWznmMImpexp WHERE supRefWznmMImpexp = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMImpexp_loadSrfByRef", "SELECT sref FROM TblWznmMImpexp WHERE ref = $1", 1);
	createStatement("TblWznmMImpexp_loadSupByRef", "SELECT supRefWznmMImpexp FROM TblWznmMImpexp WHERE ref = $1", 1);
};

bool PgTblWznmMImpexp::loadRec(
			PGresult* res
			, WznmMImpexp** rec
		) {
	char* ptr;

	WznmMImpexp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMImpexp();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmimpexpcplx"),
			PQfnumber(res, "suprefwznmmimpexp"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwiop"),
			PQfnumber(res, "rtrsrefswznmmimpexpcol"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMImpexpcplx = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->supRefWznmMImpexp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWIop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->rtrSrefsWznmMImpexpcol.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMImpexp::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMImpexp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMImpexp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmimpexpcplx"),
			PQfnumber(res, "suprefwznmmimpexp"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwiop"),
			PQfnumber(res, "rtrsrefswznmmimpexpcol"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMImpexp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMImpexpcplx = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->supRefWznmMImpexp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWIop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->rtrSrefsWznmMImpexpcol.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMImpexp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMImpexp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMImpexp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMImpexp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMImpexp::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMImpexp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMImpexp::insertRec(
			WznmMImpexp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMImpexpcplx = htonl64(rec->refWznmMImpexpcplx);
	ubigint _supRefWznmMImpexp = htonl64(rec->supRefWznmMImpexp);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	uint _ixWIop = htonl(rec->ixWIop);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx,
		(char*) &_supRefWznmMImpexp,
		(char*) &_supLvl,
		(char*) &_refWznmMTable,
		rec->sref.c_str(),
		(char*) &_ixWIop,
		rec->rtrSrefsWznmMImpexpcol.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMImpexp_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMImpexp::insertRst(
			ListWznmMImpexp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMImpexp::updateRec(
			WznmMImpexp* rec
		) {
	PGresult* res;

	ubigint _refWznmMImpexpcplx = htonl64(rec->refWznmMImpexpcplx);
	ubigint _supRefWznmMImpexp = htonl64(rec->supRefWznmMImpexp);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	uint _ixWIop = htonl(rec->ixWIop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx,
		(char*) &_supRefWznmMImpexp,
		(char*) &_supLvl,
		(char*) &_refWznmMTable,
		rec->sref.c_str(),
		(char*) &_ixWIop,
		rec->rtrSrefsWznmMImpexpcol.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMImpexp_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMImpexp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMImpexp::updateRst(
			ListWznmMImpexp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMImpexp::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMImpexp_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMImpexp::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMImpexp::loadRecByRef(
			ubigint ref
			, WznmMImpexp** rec
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

	return loadRecByStmt("TblWznmMImpexp_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMImpexp::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmMImpexp_confirmByRef", 1, vals, l, f, _ref);
};

ubigint PgTblWznmMImpexp::loadRefsByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMImpexpcplx = htonl64(refWznmMImpexpcplx);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMImpexp_loadRefsByIex", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMImpexp::loadRefsBySup(
			ubigint supRefWznmMImpexp
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWznmMImpexp = htonl64(supRefWznmMImpexp);

	const char* vals[] = {
		(char*) &_supRefWznmMImpexp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMImpexp_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMImpexp::loadRstByIex(
			ubigint refWznmMImpexpcplx
			, const bool append
			, ListWznmMImpexp& rst
		) {
	ubigint _refWznmMImpexpcplx = htonl64(refWznmMImpexpcplx);

	const char* vals[] = {
		(char*) &_refWznmMImpexpcplx
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMImpexp_loadRstByIex", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmMImpexp::loadRstBySup(
			ubigint supRefWznmMImpexp
			, const bool append
			, ListWznmMImpexp& rst
		) {
	ubigint _supRefWznmMImpexp = htonl64(supRefWznmMImpexp);

	const char* vals[] = {
		(char*) &_supRefWznmMImpexp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMImpexp_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWznmMImpexp::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMImpexp_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWznmMImpexp::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMImpexp
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmMImpexp_loadSupByRef", 1, vals, l, f, supRefWznmMImpexp);
};

#endif

