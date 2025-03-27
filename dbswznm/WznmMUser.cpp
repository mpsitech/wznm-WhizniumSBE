/**
	* \file WznmMUser.cpp
	* database access for table TblWznmMUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMUser.h"

#include "WznmMUser_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMUser
 ******************************************************************************/

WznmMUser::WznmMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWznmMUsergroup
			, const ubigint refWznmMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWznmVLocale
			, const uint ixWznmVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, refRUsergroup(refRUsergroup)
			, refWznmMUsergroup(refWznmMUsergroup)
			, refWznmMPerson(refWznmMPerson)
			, sref(sref)
			, refJState(refJState)
			, ixVState(ixVState)
			, ixWznmVLocale(ixWznmVLocale)
			, ixWznmVUserlevel(ixWznmVUserlevel)
			, Password(Password)
			, Fullkey(Fullkey)
			, Comment(Comment)
		{
};

bool WznmMUser::operator==(
			const WznmMUser& comp
		) {
	return false;
};

bool WznmMUser::operator!=(
			const WznmMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMUser
 ******************************************************************************/

ListWznmMUser::ListWznmMUser() {
};

ListWznmMUser::ListWznmMUser(
			const ListWznmMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMUser(*(src.nodes[i]));
};

ListWznmMUser::~ListWznmMUser() {
	clear();
};

void ListWznmMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMUser::size() const {
	return(nodes.size());
};

void ListWznmMUser::append(
			WznmMUser* rec
		) {
	nodes.push_back(rec);
};

WznmMUser* ListWznmMUser::operator[](
			const uint ix
		) {
	WznmMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMUser& ListWznmMUser::operator=(
			const ListWznmMUser& src
		) {
	WznmMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMUser::operator==(
			const ListWznmMUser& comp
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

bool ListWznmMUser::operator!=(
			const ListWznmMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMUser
 ******************************************************************************/

TblWznmMUser::TblWznmMUser() {
};

TblWznmMUser::~TblWznmMUser() {
};

bool TblWznmMUser::loadRecBySQL(
			const string& sqlstr
			, WznmMUser** rec
		) {
	return false;
};

ubigint TblWznmMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMUser& rst
		) {
	return 0;
};

ubigint TblWznmMUser::insertRec(
			WznmMUser* rec
		) {
	return 0;
};

ubigint TblWznmMUser::insertNewRec(
			WznmMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWznmMUsergroup
			, const ubigint refWznmMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWznmVLocale
			, const uint ixWznmVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMUser* _rec = NULL;

	_rec = new WznmMUser(0, grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMUser::appendNewRecToRst(
			ListWznmMUser& rst
			, WznmMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWznmMUsergroup
			, const ubigint refWznmMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWznmVLocale
			, const uint ixWznmVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMUser::insertRst(
			ListWznmMUser& rst
			, bool transact
		) {
};

void TblWznmMUser::updateRec(
			WznmMUser* rec
		) {
};

void TblWznmMUser::updateRst(
			ListWznmMUser& rst
			, bool transact
		) {
};

void TblWznmMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMUser::loadRecByRef(
			ubigint ref
			, WznmMUser** rec
		) {
	return false;
};

bool TblWznmMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WznmMUser** rec
		) {
	return false;
};

bool TblWznmMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMUser::loadRefsByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblWznmMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMUser& rst
		) {
	ubigint numload = 0;
	WznmMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMUser
 ******************************************************************************/

MyTblWznmMUser::MyTblWznmMUser() :
			TblWznmMUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMUser::~MyTblWznmMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMUser (grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMUser SET grp = ?, own = ?, refRUsergroup = ?, refWznmMUsergroup = ?, refWznmMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixWznmVLocale = ?, ixWznmVUserlevel = ?, Password = ?, Fullkey = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMUser WHERE ref = ?", false);
};

bool MyTblWznmMUser::loadRecBySQL(
			const string& sqlstr
			, WznmMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refWznmMUsergroup = atoll((char*) dbrow[4]); else _rec->refWznmMUsergroup = 0;
		if (dbrow[5]) _rec->refWznmMPerson = atoll((char*) dbrow[5]); else _rec->refWznmMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixWznmVLocale = atol((char*) dbrow[9]); else _rec->ixWznmVLocale = 0;
		if (dbrow[10]) _rec->ixWznmVUserlevel = atol((char*) dbrow[10]); else _rec->ixWznmVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";
		if (dbrow[12]) _rec->Fullkey.assign(dbrow[12], dblengths[12]); else _rec->Fullkey = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refWznmMUsergroup = atoll((char*) dbrow[4]); else rec->refWznmMUsergroup = 0;
			if (dbrow[5]) rec->refWznmMPerson = atoll((char*) dbrow[5]); else rec->refWznmMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixWznmVLocale = atol((char*) dbrow[9]); else rec->ixWznmVLocale = 0;
			if (dbrow[10]) rec->ixWznmVUserlevel = atol((char*) dbrow[10]); else rec->ixWznmVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			if (dbrow[12]) rec->Fullkey.assign(dbrow[12], dblengths[12]); else rec->Fullkey = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMUser::insertRec(
			WznmMUser* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWznmVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWznmVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMUser::insertRst(
			ListWznmMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMUser::updateRec(
			WznmMUser* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWznmVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWznmVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMUser::updateRst(
			ListWznmMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMUser::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMUser::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMUser::loadRecByRef(
			ubigint ref
			, WznmMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WznmMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment FROM TblWznmMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", rec);
};

bool MyTblWznmMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMUser WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMUser::loadRefsByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMUser WHERE refWznmMUsergroup = " + to_string(refWznmMUsergroup) + "", append, refs);
};

bool MyTblWznmMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMUser WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMUser
 ******************************************************************************/

PgTblWznmMUser::PgTblWznmMUser() :
			TblWznmMUser()
			, PgTable()
		{
};

PgTblWznmMUser::~PgTblWznmMUser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMUser::initStatements() {
	createStatement("TblWznmMUser_insertRec", "INSERT INTO TblWznmMUser (grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWznmMUser_updateRec", "UPDATE TblWznmMUser SET grp = $1, own = $2, refRUsergroup = $3, refWznmMUsergroup = $4, refWznmMPerson = $5, sref = $6, refJState = $7, ixVState = $8, ixWznmVLocale = $9, ixWznmVUserlevel = $10, Password = $11, Fullkey = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblWznmMUser_removeRecByRef", "DELETE FROM TblWznmMUser WHERE ref = $1", 1);

	createStatement("TblWznmMUser_loadRecByRef", "SELECT ref, grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment FROM TblWznmMUser WHERE ref = $1", 1);
	createStatement("TblWznmMUser_loadRecBySrfPwd", "SELECT ref, grp, own, refRUsergroup, refWznmMUsergroup, refWznmMPerson, sref, refJState, ixVState, ixWznmVLocale, ixWznmVUserlevel, Password, Fullkey, Comment FROM TblWznmMUser WHERE sref = $1 AND Password = $2", 2);
	createStatement("TblWznmMUser_loadRefBySrf", "SELECT ref FROM TblWznmMUser WHERE sref = $1", 1);
	createStatement("TblWznmMUser_loadRefsByUsg", "SELECT ref FROM TblWznmMUser WHERE refWznmMUsergroup = $1", 1);
	createStatement("TblWznmMUser_loadSrfByRef", "SELECT sref FROM TblWznmMUser WHERE ref = $1", 1);
};

bool PgTblWznmMUser::loadRec(
			PGresult* res
			, WznmMUser** rec
		) {
	char* ptr;

	WznmMUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMUser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwznmvlocale"),
			PQfnumber(res, "ixwznmvuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refRUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixWznmVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWznmVUserlevel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Password.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Fullkey.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMUser::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMUser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwznmvlocale"),
			PQfnumber(res, "ixwznmvuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refRUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixWznmVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWznmVUserlevel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Password.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Fullkey.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUser::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMUser::loadRecBySQL(
			const string& sqlstr
			, WznmMUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUser::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUser::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMUser::insertRec(
			WznmMUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWznmVLocale = htonl(rec->ixWznmVLocale);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refWznmMUsergroup,
		(char*) &_refWznmMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWznmVLocale,
		(char*) &_ixWznmVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMUser_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMUser::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMUser::insertRst(
			ListWznmMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMUser::updateRec(
			WznmMUser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWznmVLocale = htonl(rec->ixWznmVLocale);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refWznmMUsergroup,
		(char*) &_refWznmMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWznmVLocale,
		(char*) &_ixWznmVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMUser_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMUser::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMUser::updateRst(
			ListWznmMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMUser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMUser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMUser::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMUser::loadRecByRef(
			ubigint ref
			, WznmMUser** rec
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

	return loadRecByStmt("TblWznmMUser_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WznmMUser** rec
		) {

	const char* vals[] = {
		sref.c_str(),
		Password.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadRecByStmt("TblWznmMUser_loadRecBySrfPwd", 2, vals, l, f, rec);
};

bool PgTblWznmMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWznmMUser_loadRefBySrf", 1, vals, l, f, ref);
};

ubigint PgTblWznmMUser::loadRefsByUsg(
			ubigint refWznmMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMUsergroup = htonl64(refWznmMUsergroup);

	const char* vals[] = {
		(char*) &_refWznmMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMUser_loadRefsByUsg", 1, vals, l, f, append, refs);
};

bool PgTblWznmMUser::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMUser_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
