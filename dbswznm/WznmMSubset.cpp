/**
	* \file WznmMSubset.cpp
	* database access for table TblWznmMSubset (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMSubset.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMSubset
 ******************************************************************************/

WznmMSubset::WznmMSubset(
			const ubigint ref
			, const ubigint refWznmMTable
			, const ubigint refWznmMPreset
			, const ubigint refWznmMCard
			, const string sref
			, const string Short
			, const string Cond
			, const string Comment
		) :
			ref(ref)
			, refWznmMTable(refWznmMTable)
			, refWznmMPreset(refWznmMPreset)
			, refWznmMCard(refWznmMCard)
			, sref(sref)
			, Short(Short)
			, Cond(Cond)
			, Comment(Comment)
		{
};

bool WznmMSubset::operator==(
			const WznmMSubset& comp
		) {
	return false;
};

bool WznmMSubset::operator!=(
			const WznmMSubset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMSubset
 ******************************************************************************/

ListWznmMSubset::ListWznmMSubset() {
};

ListWznmMSubset::ListWznmMSubset(
			const ListWznmMSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMSubset(*(src.nodes[i]));
};

ListWznmMSubset::~ListWznmMSubset() {
	clear();
};

void ListWznmMSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMSubset::size() const {
	return(nodes.size());
};

void ListWznmMSubset::append(
			WznmMSubset* rec
		) {
	nodes.push_back(rec);
};

WznmMSubset* ListWznmMSubset::operator[](
			const uint ix
		) {
	WznmMSubset* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMSubset& ListWznmMSubset::operator=(
			const ListWznmMSubset& src
		) {
	WznmMSubset* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMSubset(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMSubset::operator==(
			const ListWznmMSubset& comp
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

bool ListWznmMSubset::operator!=(
			const ListWznmMSubset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMSubset
 ******************************************************************************/

TblWznmMSubset::TblWznmMSubset() {
};

TblWznmMSubset::~TblWznmMSubset() {
};

bool TblWznmMSubset::loadRecBySQL(
			const string& sqlstr
			, WznmMSubset** rec
		) {
	return false;
};

ubigint TblWznmMSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSubset& rst
		) {
	return 0;
};

ubigint TblWznmMSubset::insertRec(
			WznmMSubset* rec
		) {
	return 0;
};

ubigint TblWznmMSubset::insertNewRec(
			WznmMSubset** rec
			, const ubigint refWznmMTable
			, const ubigint refWznmMPreset
			, const ubigint refWznmMCard
			, const string sref
			, const string Short
			, const string Cond
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMSubset* _rec = NULL;

	_rec = new WznmMSubset(0, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMSubset::appendNewRecToRst(
			ListWznmMSubset& rst
			, WznmMSubset** rec
			, const ubigint refWznmMTable
			, const ubigint refWznmMPreset
			, const ubigint refWznmMCard
			, const string sref
			, const string Short
			, const string Cond
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMSubset* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMSubset::insertRst(
			ListWznmMSubset& rst
			, bool transact
		) {
};

void TblWznmMSubset::updateRec(
			WznmMSubset* rec
		) {
};

void TblWznmMSubset::updateRst(
			ListWznmMSubset& rst
			, bool transact
		) {
};

void TblWznmMSubset::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMSubset::loadRecByRef(
			ubigint ref
			, WznmMSubset** rec
		) {
	return false;
};

bool TblWznmMSubset::loadRecByCar(
			ubigint refWznmMCard
			, WznmMSubset** rec
		) {
	return false;
};

bool TblWznmMSubset::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMSubset** rec
		) {
	return false;
};

ubigint TblWznmMSubset::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMSubset::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMSubset& rst
		) {
	return 0;
};

bool TblWznmMSubset::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMSubset::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMSubset& rst
		) {
	ubigint numload = 0;
	WznmMSubset* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMSubset
 ******************************************************************************/

MyTblWznmMSubset::MyTblWznmMSubset() :
			TblWznmMSubset()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMSubset::~MyTblWznmMSubset() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMSubset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMSubset (refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMSubset SET refWznmMTable = ?, refWznmMPreset = ?, refWznmMCard = ?, sref = ?, Short = ?, Cond = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMSubset WHERE ref = ?", false);
};

bool MyTblWznmMSubset::loadRecBySQL(
			const string& sqlstr
			, WznmMSubset** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMSubset* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSubset::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSubset::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMSubset();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMTable = atoll((char*) dbrow[1]); else _rec->refWznmMTable = 0;
		if (dbrow[2]) _rec->refWznmMPreset = atoll((char*) dbrow[2]); else _rec->refWznmMPreset = 0;
		if (dbrow[3]) _rec->refWznmMCard = atoll((char*) dbrow[3]); else _rec->refWznmMCard = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Short.assign(dbrow[5], dblengths[5]); else _rec->Short = "";
		if (dbrow[6]) _rec->Cond.assign(dbrow[6], dblengths[6]); else _rec->Cond = "";
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSubset& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMSubset* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSubset::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSubset::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMSubset();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMTable = atoll((char*) dbrow[1]); else rec->refWznmMTable = 0;
			if (dbrow[2]) rec->refWznmMPreset = atoll((char*) dbrow[2]); else rec->refWznmMPreset = 0;
			if (dbrow[3]) rec->refWznmMCard = atoll((char*) dbrow[3]); else rec->refWznmMCard = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Short.assign(dbrow[5], dblengths[5]); else rec->Short = "";
			if (dbrow[6]) rec->Cond.assign(dbrow[6], dblengths[6]); else rec->Cond = "";
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMSubset::insertRec(
			WznmMSubset* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();
	l[5] = rec->Cond.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMPreset,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMCard,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMSubset::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMSubset::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMSubset::insertRst(
			ListWznmMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMSubset::updateRec(
			WznmMSubset* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();
	l[5] = rec->Cond.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMPreset,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMCard,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMSubset::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMSubset::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMSubset::updateRst(
			ListWznmMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMSubset::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMSubset::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMSubset::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMSubset::loadRecByRef(
			ubigint ref
			, WznmMSubset** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMSubset WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMSubset::loadRecByCar(
			ubigint refWznmMCard
			, WznmMSubset** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE refWznmMCard = " + to_string(refWznmMCard) + "", rec);
};

bool MyTblWznmMSubset::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMSubset** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE refWznmMPreset = " + to_string(refWznmMPreset) + "", rec);
};

ubigint MyTblWznmMSubset::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(refWznmMTable) + "", append, refs);
};

ubigint MyTblWznmMSubset::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMSubset& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(refWznmMTable) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMSubset::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMSubset WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMSubset
 ******************************************************************************/

PgTblWznmMSubset::PgTblWznmMSubset() :
			TblWznmMSubset()
			, PgTable()
		{
};

PgTblWznmMSubset::~PgTblWznmMSubset() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMSubset::initStatements() {
	createStatement("TblWznmMSubset_insertRec", "INSERT INTO TblWznmMSubset (refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmMSubset_updateRec", "UPDATE TblWznmMSubset SET refWznmMTable = $1, refWznmMPreset = $2, refWznmMCard = $3, sref = $4, Short = $5, Cond = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmMSubset_removeRecByRef", "DELETE FROM TblWznmMSubset WHERE ref = $1", 1);

	createStatement("TblWznmMSubset_loadRecByRef", "SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE ref = $1", 1);
	createStatement("TblWznmMSubset_loadRecByCar", "SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE refWznmMCard = $1", 1);
	createStatement("TblWznmMSubset_loadRecByPst", "SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE refWznmMPreset = $1", 1);
	createStatement("TblWznmMSubset_loadRefsByTbl", "SELECT ref FROM TblWznmMSubset WHERE refWznmMTable = $1", 1);
	createStatement("TblWznmMSubset_loadRstByTbl", "SELECT ref, refWznmMTable, refWznmMPreset, refWznmMCard, sref, Short, Cond, Comment FROM TblWznmMSubset WHERE refWznmMTable = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMSubset_loadSrfByRef", "SELECT sref FROM TblWznmMSubset WHERE ref = $1", 1);
};

bool PgTblWznmMSubset::loadRec(
			PGresult* res
			, WznmMSubset** rec
		) {
	char* ptr;

	WznmMSubset* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMSubset();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "cond"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMCard = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Cond.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMSubset::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMSubset& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMSubset* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "cond"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMSubset();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMCard = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Cond.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMSubset::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMSubset** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSubset::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSubset::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMSubset& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSubset::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMSubset::loadRecBySQL(
			const string& sqlstr
			, WznmMSubset** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSubset::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSubset& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSubset::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMSubset::insertRec(
			WznmMSubset* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMCard,
		rec->sref.c_str(),
		rec->Short.c_str(),
		rec->Cond.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMSubset_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSubset::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMSubset::insertRst(
			ListWznmMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMSubset::updateRec(
			WznmMSubset* rec
		) {
	PGresult* res;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMCard,
		rec->sref.c_str(),
		rec->Short.c_str(),
		rec->Cond.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMSubset_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSubset::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMSubset::updateRst(
			ListWznmMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMSubset::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMSubset_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSubset::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMSubset::loadRecByRef(
			ubigint ref
			, WznmMSubset** rec
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

	return loadRecByStmt("TblWznmMSubset_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMSubset::loadRecByCar(
			ubigint refWznmMCard
			, WznmMSubset** rec
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMSubset_loadRecByCar", 1, vals, l, f, rec);
};

bool PgTblWznmMSubset::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMSubset** rec
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);

	const char* vals[] = {
		(char*) &_refWznmMPreset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMSubset_loadRecByPst", 1, vals, l, f, rec);
};

ubigint PgTblWznmMSubset::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMSubset_loadRefsByTbl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMSubset::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMSubset& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMSubset_loadRstByTbl", 1, vals, l, f, append, rst);
};

bool PgTblWznmMSubset::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMSubset_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
