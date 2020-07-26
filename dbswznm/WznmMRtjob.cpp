/**
	* \file WznmMRtjob.cpp
	* database access for table TblWznmMRtjob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMRtjob.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMRtjob
 ******************************************************************************/

WznmMRtjob::WznmMRtjob(
			const ubigint ref
			, const ubigint refWznmMApp
			, const ubigint supRefWznmMRtjob
			, const usmallint supLvl
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMApp = refWznmMApp;
	this->supRefWznmMRtjob = supRefWznmMRtjob;
	this->supLvl = supLvl;
	this->refWznmMJob = refWznmMJob;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmMRtjob::operator==(
			const WznmMRtjob& comp
		) {
	return false;
};

bool WznmMRtjob::operator!=(
			const WznmMRtjob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMRtjob
 ******************************************************************************/

ListWznmMRtjob::ListWznmMRtjob() {
};

ListWznmMRtjob::ListWznmMRtjob(
			const ListWznmMRtjob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMRtjob(*(src.nodes[i]));
};

ListWznmMRtjob::~ListWznmMRtjob() {
	clear();
};

void ListWznmMRtjob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMRtjob::size() const {
	return(nodes.size());
};

void ListWznmMRtjob::append(
			WznmMRtjob* rec
		) {
	nodes.push_back(rec);
};

WznmMRtjob* ListWznmMRtjob::operator[](
			const uint ix
		) {
	WznmMRtjob* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMRtjob& ListWznmMRtjob::operator=(
			const ListWznmMRtjob& src
		) {
	WznmMRtjob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMRtjob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMRtjob::operator==(
			const ListWznmMRtjob& comp
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

bool ListWznmMRtjob::operator!=(
			const ListWznmMRtjob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMRtjob
 ******************************************************************************/

TblWznmMRtjob::TblWznmMRtjob() {
};

TblWznmMRtjob::~TblWznmMRtjob() {
};

bool TblWznmMRtjob::loadRecBySQL(
			const string& sqlstr
			, WznmMRtjob** rec
		) {
	return false;
};

ubigint TblWznmMRtjob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtjob& rst
		) {
	return 0;
};

ubigint TblWznmMRtjob::insertRec(
			WznmMRtjob* rec
		) {
	return 0;
};

ubigint TblWznmMRtjob::insertNewRec(
			WznmMRtjob** rec
			, const ubigint refWznmMApp
			, const ubigint supRefWznmMRtjob
			, const usmallint supLvl
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMRtjob* _rec = NULL;

	_rec = new WznmMRtjob(0, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMRtjob::appendNewRecToRst(
			ListWznmMRtjob& rst
			, WznmMRtjob** rec
			, const ubigint refWznmMApp
			, const ubigint supRefWznmMRtjob
			, const usmallint supLvl
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMRtjob* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMRtjob::insertRst(
			ListWznmMRtjob& rst
			, bool transact
		) {
};

void TblWznmMRtjob::updateRec(
			WznmMRtjob* rec
		) {
};

void TblWznmMRtjob::updateRst(
			ListWznmMRtjob& rst
			, bool transact
		) {
};

void TblWznmMRtjob::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMRtjob::loadRecByRef(
			ubigint ref
			, WznmMRtjob** rec
		) {
	return false;
};

bool TblWznmMRtjob::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblWznmMRtjob::loadRefsBySup(
			ubigint supRefWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMRtjob::loadRstByApp(
			ubigint refWznmMApp
			, const bool append
			, ListWznmMRtjob& rst
		) {
	return 0;
};

ubigint TblWznmMRtjob::loadRstBySup(
			ubigint supRefWznmMRtjob
			, const bool append
			, ListWznmMRtjob& rst
		) {
	return 0;
};

bool TblWznmMRtjob::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWznmMRtjob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMRtjob
		) {
	return false;
};

ubigint TblWznmMRtjob::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMRtjob& rst
		) {
	ubigint numload = 0;
	WznmMRtjob* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWznmMRtjob::loadHrefsup(
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

ubigint TblWznmMRtjob::loadHrefsdown(
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

ubigint TblWznmMRtjob::loadHrstup(
			ubigint ref
			, ListWznmMRtjob& rst
		) {
	WznmMRtjob* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWznmMRtjob;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWznmMRtjob::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWznmMRtjob& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WznmMRtjob* rec = NULL;

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
 class MyTblWznmMRtjob
 ******************************************************************************/

MyTblWznmMRtjob::MyTblWznmMRtjob() :
			TblWznmMRtjob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMRtjob::~MyTblWznmMRtjob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMRtjob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMRtjob (refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMRtjob SET refWznmMApp = ?, supRefWznmMRtjob = ?, supLvl = ?, refWznmMJob = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMRtjob WHERE ref = ?", false);
};

bool MyTblWznmMRtjob::loadRecBySQL(
			const string& sqlstr
			, WznmMRtjob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMRtjob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRtjob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRtjob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMRtjob();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMApp = atoll((char*) dbrow[1]); else _rec->refWznmMApp = 0;
		if (dbrow[2]) _rec->supRefWznmMRtjob = atoll((char*) dbrow[2]); else _rec->supRefWznmMRtjob = 0;
		if (dbrow[3]) _rec->supLvl = atoi((char*) dbrow[3]); else _rec->supLvl = 0;
		if (dbrow[4]) _rec->refWznmMJob = atoll((char*) dbrow[4]); else _rec->refWznmMJob = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMRtjob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtjob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMRtjob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRtjob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRtjob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMRtjob();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMApp = atoll((char*) dbrow[1]); else rec->refWznmMApp = 0;
			if (dbrow[2]) rec->supRefWznmMRtjob = atoll((char*) dbrow[2]); else rec->supRefWznmMRtjob = 0;
			if (dbrow[3]) rec->supLvl = atoi((char*) dbrow[3]); else rec->supLvl = 0;
			if (dbrow[4]) rec->refWznmMJob = atoll((char*) dbrow[4]); else rec->refWznmMJob = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMRtjob::insertRec(
			WznmMRtjob* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->sref.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMApp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->supRefWznmMRtjob,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->supLvl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMJob,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMRtjob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMRtjob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMRtjob::insertRst(
			ListWznmMRtjob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMRtjob::updateRec(
			WznmMRtjob* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->sref.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMApp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->supRefWznmMRtjob,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->supLvl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMJob,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMRtjob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMRtjob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMRtjob::updateRst(
			ListWznmMRtjob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMRtjob::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMRtjob::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMRtjob::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMRtjob::loadRecByRef(
			ubigint ref
			, WznmMRtjob** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMRtjob WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMRtjob::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWznmMRtjob WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblWznmMRtjob::loadRefsBySup(
			ubigint supRefWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMRtjob WHERE supRefWznmMRtjob = " + to_string(supRefWznmMRtjob) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWznmMRtjob::loadRstByApp(
			ubigint refWznmMApp
			, const bool append
			, ListWznmMRtjob& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment FROM TblWznmMRtjob WHERE refWznmMApp = " + to_string(refWznmMApp) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWznmMRtjob::loadRstBySup(
			ubigint supRefWznmMRtjob
			, const bool append
			, ListWznmMRtjob& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment FROM TblWznmMRtjob WHERE supRefWznmMRtjob = " + to_string(supRefWznmMRtjob) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMRtjob::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMRtjob WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWznmMRtjob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMRtjob
		) {
	return loadRefBySQL("SELECT supRefWznmMRtjob FROM TblWznmMRtjob WHERE ref = " + to_string(ref) + "", supRefWznmMRtjob);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMRtjob
 ******************************************************************************/

PgTblWznmMRtjob::PgTblWznmMRtjob() :
			TblWznmMRtjob()
			, PgTable()
		{
};

PgTblWznmMRtjob::~PgTblWznmMRtjob() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMRtjob::initStatements() {
	createStatement("TblWznmMRtjob_insertRec", "INSERT INTO TblWznmMRtjob (refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWznmMRtjob_updateRec", "UPDATE TblWznmMRtjob SET refWznmMApp = $1, supRefWznmMRtjob = $2, supLvl = $3, refWznmMJob = $4, sref = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWznmMRtjob_removeRecByRef", "DELETE FROM TblWznmMRtjob WHERE ref = $1", 1);

	createStatement("TblWznmMRtjob_loadRecByRef", "SELECT ref, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment FROM TblWznmMRtjob WHERE ref = $1", 1);
	createStatement("TblWznmMRtjob_confirmByRef", "SELECT ref FROM TblWznmMRtjob WHERE ref = $1", 1);
	createStatement("TblWznmMRtjob_loadRefsBySup", "SELECT ref FROM TblWznmMRtjob WHERE supRefWznmMRtjob = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMRtjob_loadRstByApp", "SELECT ref, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment FROM TblWznmMRtjob WHERE refWznmMApp = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMRtjob_loadRstBySup", "SELECT ref, refWznmMApp, supRefWznmMRtjob, supLvl, refWznmMJob, sref, Comment FROM TblWznmMRtjob WHERE supRefWznmMRtjob = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMRtjob_loadSrfByRef", "SELECT sref FROM TblWznmMRtjob WHERE ref = $1", 1);
	createStatement("TblWznmMRtjob_loadSupByRef", "SELECT supRefWznmMRtjob FROM TblWznmMRtjob WHERE ref = $1", 1);
};

bool PgTblWznmMRtjob::loadRec(
			PGresult* res
			, WznmMRtjob** rec
		) {
	char* ptr;

	WznmMRtjob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMRtjob();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmapp"),
			PQfnumber(res, "suprefwznmmrtjob"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMApp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->supRefWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMRtjob::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMRtjob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMRtjob* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmapp"),
			PQfnumber(res, "suprefwznmmrtjob"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMRtjob();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMApp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->supRefWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMRtjob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMRtjob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtjob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRtjob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMRtjob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtjob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMRtjob::loadRecBySQL(
			const string& sqlstr
			, WznmMRtjob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtjob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRtjob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtjob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtjob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMRtjob::insertRec(
			WznmMRtjob* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMApp = htonl64(rec->refWznmMApp);
	ubigint _supRefWznmMRtjob = htonl64(rec->supRefWznmMRtjob);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMApp,
		(char*) &_supRefWznmMRtjob,
		(char*) &_supLvl,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMRtjob_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtjob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMRtjob::insertRst(
			ListWznmMRtjob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMRtjob::updateRec(
			WznmMRtjob* rec
		) {
	PGresult* res;

	ubigint _refWznmMApp = htonl64(rec->refWznmMApp);
	ubigint _supRefWznmMRtjob = htonl64(rec->supRefWznmMRtjob);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMApp,
		(char*) &_supRefWznmMRtjob,
		(char*) &_supLvl,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMRtjob_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRtjob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMRtjob::updateRst(
			ListWznmMRtjob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMRtjob::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMRtjob_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRtjob::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMRtjob::loadRecByRef(
			ubigint ref
			, WznmMRtjob** rec
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

	return loadRecByStmt("TblWznmMRtjob_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMRtjob::confirmByRef(
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

	return loadRefByStmt("TblWznmMRtjob_confirmByRef", 1, vals, l, f, _ref);
};

ubigint PgTblWznmMRtjob::loadRefsBySup(
			ubigint supRefWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWznmMRtjob = htonl64(supRefWznmMRtjob);

	const char* vals[] = {
		(char*) &_supRefWznmMRtjob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMRtjob_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMRtjob::loadRstByApp(
			ubigint refWznmMApp
			, const bool append
			, ListWznmMRtjob& rst
		) {
	ubigint _refWznmMApp = htonl64(refWznmMApp);

	const char* vals[] = {
		(char*) &_refWznmMApp
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRtjob_loadRstByApp", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmMRtjob::loadRstBySup(
			ubigint supRefWznmMRtjob
			, const bool append
			, ListWznmMRtjob& rst
		) {
	ubigint _supRefWznmMRtjob = htonl64(supRefWznmMRtjob);

	const char* vals[] = {
		(char*) &_supRefWznmMRtjob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRtjob_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWznmMRtjob::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMRtjob_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWznmMRtjob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMRtjob
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmMRtjob_loadSupByRef", 1, vals, l, f, supRefWznmMRtjob);
};

#endif

