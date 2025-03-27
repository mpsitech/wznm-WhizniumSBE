/**
	* \file WznmMMachine.cpp
	* database access for table TblWznmMMachine (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMMachine.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMMachine
 ******************************************************************************/

WznmMMachine::WznmMMachine(
			const ubigint ref
			, const ubigint supRefWznmMMachine
			, const string sref
			, const ubigint cchRefWznmMMachine
			, const string srefKPkgmgr
			, const string Comment
		) :
			ref(ref)
			, supRefWznmMMachine(supRefWznmMMachine)
			, sref(sref)
			, cchRefWznmMMachine(cchRefWznmMMachine)
			, srefKPkgmgr(srefKPkgmgr)
			, Comment(Comment)
		{
};

bool WznmMMachine::operator==(
			const WznmMMachine& comp
		) {
	return false;
};

bool WznmMMachine::operator!=(
			const WznmMMachine& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMMachine
 ******************************************************************************/

ListWznmMMachine::ListWznmMMachine() {
};

ListWznmMMachine::ListWznmMMachine(
			const ListWznmMMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMMachine(*(src.nodes[i]));
};

ListWznmMMachine::~ListWznmMMachine() {
	clear();
};

void ListWznmMMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMMachine::size() const {
	return(nodes.size());
};

void ListWznmMMachine::append(
			WznmMMachine* rec
		) {
	nodes.push_back(rec);
};

WznmMMachine* ListWznmMMachine::operator[](
			const uint ix
		) {
	WznmMMachine* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMMachine& ListWznmMMachine::operator=(
			const ListWznmMMachine& src
		) {
	WznmMMachine* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMMachine(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMMachine::operator==(
			const ListWznmMMachine& comp
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

bool ListWznmMMachine::operator!=(
			const ListWznmMMachine& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMMachine
 ******************************************************************************/

TblWznmMMachine::TblWznmMMachine() {
};

TblWznmMMachine::~TblWznmMMachine() {
};

bool TblWznmMMachine::loadRecBySQL(
			const string& sqlstr
			, WznmMMachine** rec
		) {
	return false;
};

ubigint TblWznmMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachine& rst
		) {
	return 0;
};

ubigint TblWznmMMachine::insertRec(
			WznmMMachine* rec
		) {
	return 0;
};

ubigint TblWznmMMachine::insertNewRec(
			WznmMMachine** rec
			, const ubigint supRefWznmMMachine
			, const string sref
			, const ubigint cchRefWznmMMachine
			, const string srefKPkgmgr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMachine* _rec = NULL;

	_rec = new WznmMMachine(0, supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMMachine::appendNewRecToRst(
			ListWznmMMachine& rst
			, WznmMMachine** rec
			, const ubigint supRefWznmMMachine
			, const string sref
			, const ubigint cchRefWznmMMachine
			, const string srefKPkgmgr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMachine* _rec = NULL;

	retval = insertNewRec(&_rec, supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMMachine::insertRst(
			ListWznmMMachine& rst
			, bool transact
		) {
};

void TblWznmMMachine::updateRec(
			WznmMMachine* rec
		) {
};

void TblWznmMMachine::updateRst(
			ListWznmMMachine& rst
			, bool transact
		) {
};

void TblWznmMMachine::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMMachine::loadRecByRef(
			ubigint ref
			, WznmMMachine** rec
		) {
	return false;
};

bool TblWznmMMachine::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblWznmMMachine::loadRefsBySup(
			ubigint supRefWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMMachine::loadRstBySup(
			ubigint supRefWznmMMachine
			, const bool append
			, ListWznmMMachine& rst
		) {
	return 0;
};

bool TblWznmMMachine::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWznmMMachine::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMMachine
		) {
	return false;
};

ubigint TblWznmMMachine::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMMachine& rst
		) {
	ubigint numload = 0;
	WznmMMachine* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWznmMMachine::loadHrefsup(
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

ubigint TblWznmMMachine::loadHrefsdown(
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

ubigint TblWznmMMachine::loadHrstup(
			ubigint ref
			, ListWznmMMachine& rst
		) {
	WznmMMachine* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWznmMMachine;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWznmMMachine::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWznmMMachine& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WznmMMachine* rec = NULL;

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
 class MyTblWznmMMachine
 ******************************************************************************/

MyTblWznmMMachine::MyTblWznmMMachine() :
			TblWznmMMachine()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMMachine::~MyTblWznmMMachine() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMMachine::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMMachine (supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMMachine SET supRefWznmMMachine = ?, sref = ?, cchRefWznmMMachine = ?, srefKPkgmgr = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMMachine WHERE ref = ?", false);
};

bool MyTblWznmMMachine::loadRecBySQL(
			const string& sqlstr
			, WznmMMachine** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMMachine* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMachine::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMachine::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMMachine();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->supRefWznmMMachine = atoll((char*) dbrow[1]); else _rec->supRefWznmMMachine = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->cchRefWznmMMachine = atoll((char*) dbrow[3]); else _rec->cchRefWznmMMachine = 0;
		if (dbrow[4]) _rec->srefKPkgmgr.assign(dbrow[4], dblengths[4]); else _rec->srefKPkgmgr = "";
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachine& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMMachine* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMachine::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMachine::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMMachine();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->supRefWznmMMachine = atoll((char*) dbrow[1]); else rec->supRefWznmMMachine = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->cchRefWznmMMachine = atoll((char*) dbrow[3]); else rec->cchRefWznmMMachine = 0;
			if (dbrow[4]) rec->srefKPkgmgr.assign(dbrow[4], dblengths[4]); else rec->srefKPkgmgr = "";
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMMachine::insertRec(
			WznmMMachine* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->sref.length();
	l[3] = rec->srefKPkgmgr.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWznmMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->cchRefWznmMMachine,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKPkgmgr.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMMachine::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMMachine::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMMachine::insertRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMMachine::updateRec(
			WznmMMachine* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[1] = rec->sref.length();
	l[3] = rec->srefKPkgmgr.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWznmMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->cchRefWznmMMachine,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKPkgmgr.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMMachine::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMMachine::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMMachine::updateRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMMachine::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMMachine::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMMachine::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMMachine::loadRecByRef(
			ubigint ref
			, WznmMMachine** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMMachine WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMMachine::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWznmMMachine WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblWznmMMachine::loadRefsBySup(
			ubigint supRefWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMMachine WHERE supRefWznmMMachine = " + to_string(supRefWznmMMachine) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWznmMMachine::loadRstBySup(
			ubigint supRefWznmMMachine
			, const bool append
			, ListWznmMMachine& rst
		) {
	return loadRstBySQL("SELECT ref, supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment FROM TblWznmMMachine WHERE supRefWznmMMachine = " + to_string(supRefWznmMMachine) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMMachine::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMMachine WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWznmMMachine::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMMachine
		) {
	return loadRefBySQL("SELECT supRefWznmMMachine FROM TblWznmMMachine WHERE ref = " + to_string(ref) + "", supRefWznmMMachine);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMMachine
 ******************************************************************************/

PgTblWznmMMachine::PgTblWznmMMachine() :
			TblWznmMMachine()
			, PgTable()
		{
};

PgTblWznmMMachine::~PgTblWznmMMachine() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMMachine::initStatements() {
	createStatement("TblWznmMMachine_insertRec", "INSERT INTO TblWznmMMachine (supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMMachine_updateRec", "UPDATE TblWznmMMachine SET supRefWznmMMachine = $1, sref = $2, cchRefWznmMMachine = $3, srefKPkgmgr = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMMachine_removeRecByRef", "DELETE FROM TblWznmMMachine WHERE ref = $1", 1);

	createStatement("TblWznmMMachine_loadRecByRef", "SELECT ref, supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment FROM TblWznmMMachine WHERE ref = $1", 1);
	createStatement("TblWznmMMachine_confirmByRef", "SELECT ref FROM TblWznmMMachine WHERE ref = $1", 1);
	createStatement("TblWznmMMachine_loadRefsBySup", "SELECT ref FROM TblWznmMMachine WHERE supRefWznmMMachine = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMMachine_loadRstBySup", "SELECT ref, supRefWznmMMachine, sref, cchRefWznmMMachine, srefKPkgmgr, Comment FROM TblWznmMMachine WHERE supRefWznmMMachine = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMMachine_loadSrfByRef", "SELECT sref FROM TblWznmMMachine WHERE ref = $1", 1);
	createStatement("TblWznmMMachine_loadSupByRef", "SELECT supRefWznmMMachine FROM TblWznmMMachine WHERE ref = $1", 1);
};

bool PgTblWznmMMachine::loadRec(
			PGresult* res
			, WznmMMachine** rec
		) {
	char* ptr;

	WznmMMachine* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMMachine();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwznmmmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "cchrefwznmmmachine"),
			PQfnumber(res, "srefkpkgmgr"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->supRefWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->cchRefWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefKPkgmgr.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMMachine::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMMachine& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMMachine* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwznmmmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "cchrefwznmmmachine"),
			PQfnumber(res, "srefkpkgmgr"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMMachine();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->supRefWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->cchRefWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefKPkgmgr.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMMachine::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMMachine** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMMachine::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMMachine& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMMachine::loadRecBySQL(
			const string& sqlstr
			, WznmMMachine** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachine& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMMachine::insertRec(
			WznmMMachine* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _supRefWznmMMachine = htonl64(rec->supRefWznmMMachine);
	ubigint _cchRefWznmMMachine = htonl64(rec->cchRefWznmMMachine);

	const char* vals[] = {
		(char*) &_supRefWznmMMachine,
		rec->sref.c_str(),
		(char*) &_cchRefWznmMMachine,
		rec->srefKPkgmgr.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMMachine_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachine::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMMachine::insertRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMMachine::updateRec(
			WznmMMachine* rec
		) {
	PGresult* res;

	ubigint _supRefWznmMMachine = htonl64(rec->supRefWznmMMachine);
	ubigint _cchRefWznmMMachine = htonl64(rec->cchRefWznmMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_supRefWznmMMachine,
		rec->sref.c_str(),
		(char*) &_cchRefWznmMMachine,
		rec->srefKPkgmgr.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMMachine_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMachine::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMMachine::updateRst(
			ListWznmMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMMachine::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMMachine_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMachine::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMMachine::loadRecByRef(
			ubigint ref
			, WznmMMachine** rec
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

	return loadRecByStmt("TblWznmMMachine_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMMachine::confirmByRef(
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

	return loadRefByStmt("TblWznmMMachine_confirmByRef", 1, vals, l, f, _ref);
};

ubigint PgTblWznmMMachine::loadRefsBySup(
			ubigint supRefWznmMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWznmMMachine = htonl64(supRefWznmMMachine);

	const char* vals[] = {
		(char*) &_supRefWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMMachine_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMMachine::loadRstBySup(
			ubigint supRefWznmMMachine
			, const bool append
			, ListWznmMMachine& rst
		) {
	ubigint _supRefWznmMMachine = htonl64(supRefWznmMMachine);

	const char* vals[] = {
		(char*) &_supRefWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMMachine_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWznmMMachine::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMMachine_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWznmMMachine::loadSupByRef(
			ubigint ref
			, ubigint& supRefWznmMMachine
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWznmMMachine_loadSupByRef", 1, vals, l, f, supRefWznmMMachine);
};

#endif
