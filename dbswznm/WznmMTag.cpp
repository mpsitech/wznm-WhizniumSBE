/**
	* \file WznmMTag.cpp
	* database access for table TblWznmMTag (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMTag.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMTag
 ******************************************************************************/

WznmMTag::WznmMTag(
			const ubigint ref
			, const ubigint refWznmMCapability
			, const string sref
			, const string osrefWznmKTaggrp
			, const ubigint refJTitle
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMCapability = refWznmMCapability;
	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->refJTitle = refJTitle;
	this->Title = Title;
};

bool WznmMTag::operator==(
			const WznmMTag& comp
		) {
	return false;
};

bool WznmMTag::operator!=(
			const WznmMTag& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMTag
 ******************************************************************************/

ListWznmMTag::ListWznmMTag() {
};

ListWznmMTag::ListWznmMTag(
			const ListWznmMTag& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMTag(*(src.nodes[i]));
};

ListWznmMTag::~ListWznmMTag() {
	clear();
};

void ListWznmMTag::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMTag::size() const {
	return(nodes.size());
};

void ListWznmMTag::append(
			WznmMTag* rec
		) {
	nodes.push_back(rec);
};

WznmMTag* ListWznmMTag::operator[](
			const uint ix
		) {
	WznmMTag* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMTag& ListWznmMTag::operator=(
			const ListWznmMTag& src
		) {
	WznmMTag* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMTag(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMTag::operator==(
			const ListWznmMTag& comp
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

bool ListWznmMTag::operator!=(
			const ListWznmMTag& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMTag
 ******************************************************************************/

TblWznmMTag::TblWznmMTag() {
};

TblWznmMTag::~TblWznmMTag() {
};

bool TblWznmMTag::loadRecBySQL(
			const string& sqlstr
			, WznmMTag** rec
		) {
	return false;
};

ubigint TblWznmMTag::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTag& rst
		) {
	return 0;
};

ubigint TblWznmMTag::insertRec(
			WznmMTag* rec
		) {
	return 0;
};

ubigint TblWznmMTag::insertNewRec(
			WznmMTag** rec
			, const ubigint refWznmMCapability
			, const string sref
			, const string osrefWznmKTaggrp
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMTag* _rec = NULL;

	_rec = new WznmMTag(0, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMTag::appendNewRecToRst(
			ListWznmMTag& rst
			, WznmMTag** rec
			, const ubigint refWznmMCapability
			, const string sref
			, const string osrefWznmKTaggrp
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMTag* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMTag::insertRst(
			ListWznmMTag& rst
			, bool transact
		) {
};

void TblWznmMTag::updateRec(
			WznmMTag* rec
		) {
};

void TblWznmMTag::updateRst(
			ListWznmMTag& rst
			, bool transact
		) {
};

void TblWznmMTag::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMTag::loadRecByRef(
			ubigint ref
			, WznmMTag** rec
		) {
	return false;
};

bool TblWznmMTag::loadRecBySrfGrp(
			string sref
			, string osrefWznmKTaggrp
			, WznmMTag** rec
		) {
	return false;
};

ubigint TblWznmMTag::loadRefsByCpb(
			ubigint refWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMTag::loadRstByGrp(
			string osrefWznmKTaggrp
			, const bool append
			, ListWznmMTag& rst
		) {
	return 0;
};

bool TblWznmMTag::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMTag::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMTag& rst
		) {
	ubigint numload = 0;
	WznmMTag* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMTag
 ******************************************************************************/

MyTblWznmMTag::MyTblWznmMTag() :
			TblWznmMTag()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMTag::~MyTblWznmMTag() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMTag::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMTag (refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMTag SET refWznmMCapability = ?, sref = ?, osrefWznmKTaggrp = ?, refJTitle = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMTag WHERE ref = ?", false);
};

bool MyTblWznmMTag::loadRecBySQL(
			const string& sqlstr
			, WznmMTag** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMTag* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMTag::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMTag::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMTag();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMCapability = atoll((char*) dbrow[1]); else _rec->refWznmMCapability = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->osrefWznmKTaggrp.assign(dbrow[3], dblengths[3]); else _rec->osrefWznmKTaggrp = "";
		if (dbrow[4]) _rec->refJTitle = atoll((char*) dbrow[4]); else _rec->refJTitle = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMTag::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTag& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMTag* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMTag::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMTag::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMTag();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMCapability = atoll((char*) dbrow[1]); else rec->refWznmMCapability = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->osrefWznmKTaggrp.assign(dbrow[3], dblengths[3]); else rec->osrefWznmKTaggrp = "";
			if (dbrow[4]) rec->refJTitle = atoll((char*) dbrow[4]); else rec->refJTitle = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMTag::insertRec(
			WznmMTag* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->sref.length();
	l[2] = rec->osrefWznmKTaggrp.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCapability,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->osrefWznmKTaggrp.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJTitle,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMTag::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMTag::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMTag::insertRst(
			ListWznmMTag& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMTag::updateRec(
			WznmMTag* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[1] = rec->sref.length();
	l[2] = rec->osrefWznmKTaggrp.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMCapability,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->osrefWznmKTaggrp.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJTitle,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMTag::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMTag::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMTag::updateRst(
			ListWznmMTag& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMTag::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMTag::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMTag::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMTag::loadRecByRef(
			ubigint ref
			, WznmMTag** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMTag WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMTag::loadRecBySrfGrp(
			string sref
			, string osrefWznmKTaggrp
			, WznmMTag** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title FROM TblWznmMTag WHERE sref = '" + sref + "' AND osrefWznmKTaggrp = '" + osrefWznmKTaggrp + "'", rec);
};

ubigint MyTblWznmMTag::loadRefsByCpb(
			ubigint refWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMTag WHERE refWznmMCapability = " + to_string(refWznmMCapability) + "", append, refs);
};

ubigint MyTblWznmMTag::loadRstByGrp(
			string osrefWznmKTaggrp
			, const bool append
			, ListWznmMTag& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title FROM TblWznmMTag WHERE osrefWznmKTaggrp = '" + osrefWznmKTaggrp + "' ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMTag::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMTag WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMTag
 ******************************************************************************/

PgTblWznmMTag::PgTblWznmMTag() :
			TblWznmMTag()
			, PgTable()
		{
};

PgTblWznmMTag::~PgTblWznmMTag() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMTag::initStatements() {
	createStatement("TblWznmMTag_insertRec", "INSERT INTO TblWznmMTag (refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMTag_updateRec", "UPDATE TblWznmMTag SET refWznmMCapability = $1, sref = $2, osrefWznmKTaggrp = $3, refJTitle = $4, Title = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMTag_removeRecByRef", "DELETE FROM TblWznmMTag WHERE ref = $1", 1);

	createStatement("TblWznmMTag_loadRecByRef", "SELECT ref, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title FROM TblWznmMTag WHERE ref = $1", 1);
	createStatement("TblWznmMTag_loadRecBySrfGrp", "SELECT ref, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title FROM TblWznmMTag WHERE sref = $1 AND osrefWznmKTaggrp = $2", 2);
	createStatement("TblWznmMTag_loadRefsByCpb", "SELECT ref FROM TblWznmMTag WHERE refWznmMCapability = $1", 1);
	createStatement("TblWznmMTag_loadRstByGrp", "SELECT ref, refWznmMCapability, sref, osrefWznmKTaggrp, refJTitle, Title FROM TblWznmMTag WHERE osrefWznmKTaggrp = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMTag_loadSrfByRef", "SELECT sref FROM TblWznmMTag WHERE ref = $1", 1);
};

bool PgTblWznmMTag::loadRec(
			PGresult* res
			, WznmMTag** rec
		) {
	char* ptr;

	WznmMTag* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMTag();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcapability"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "osrefwznmktaggrp"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMCapability = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->osrefWznmKTaggrp.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMTag::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMTag& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMTag* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcapability"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "osrefwznmktaggrp"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmMTag();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMCapability = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->osrefWznmKTaggrp.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMTag::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMTag** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTag::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMTag::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMTag& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTag::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMTag::loadRecBySQL(
			const string& sqlstr
			, WznmMTag** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTag::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMTag::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTag& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTag::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMTag::insertRec(
			WznmMTag* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMCapability = htonl64(rec->refWznmMCapability);
	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		(char*) &_refWznmMCapability,
		rec->sref.c_str(),
		rec->osrefWznmKTaggrp.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMTag_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTag::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMTag::insertRst(
			ListWznmMTag& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMTag::updateRec(
			WznmMTag* rec
		) {
	PGresult* res;

	ubigint _refWznmMCapability = htonl64(rec->refWznmMCapability);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMCapability,
		rec->sref.c_str(),
		rec->osrefWznmKTaggrp.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMTag_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMTag::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMTag::updateRst(
			ListWznmMTag& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMTag::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMTag_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMTag::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMTag::loadRecByRef(
			ubigint ref
			, WznmMTag** rec
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

	return loadRecByStmt("TblWznmMTag_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMTag::loadRecBySrfGrp(
			string sref
			, string osrefWznmKTaggrp
			, WznmMTag** rec
		) {

	const char* vals[] = {
		sref.c_str(),
		osrefWznmKTaggrp.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadRecByStmt("TblWznmMTag_loadRecBySrfGrp", 2, vals, l, f, rec);
};

ubigint PgTblWznmMTag::loadRefsByCpb(
			ubigint refWznmMCapability
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMCapability = htonl64(refWznmMCapability);

	const char* vals[] = {
		(char*) &_refWznmMCapability
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMTag_loadRefsByCpb", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMTag::loadRstByGrp(
			string osrefWznmKTaggrp
			, const bool append
			, ListWznmMTag& rst
		) {

	const char* vals[] = {
		osrefWznmKTaggrp.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRstByStmt("TblWznmMTag_loadRstByGrp", 1, vals, l, f, append, rst);
};

bool PgTblWznmMTag::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMTag_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

