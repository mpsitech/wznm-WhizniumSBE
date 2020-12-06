/**
	* \file WznmJAMBlockItem.cpp
	* database access for table TblWznmJAMBlockItem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmJAMBlockItem.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJAMBlockItem
 ******************************************************************************/

WznmJAMBlockItem::WznmJAMBlockItem(
			const ubigint ref
			, const ubigint refWznmAMBlockItem
			, const ubigint x1RefWznmMRelease
			, const string Defval
			, const ubigint refWznmMVectoritem
		) {

	this->ref = ref;
	this->refWznmAMBlockItem = refWznmAMBlockItem;
	this->x1RefWznmMRelease = x1RefWznmMRelease;
	this->Defval = Defval;
	this->refWznmMVectoritem = refWznmMVectoritem;
};

bool WznmJAMBlockItem::operator==(
			const WznmJAMBlockItem& comp
		) {
	return false;
};

bool WznmJAMBlockItem::operator!=(
			const WznmJAMBlockItem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJAMBlockItem
 ******************************************************************************/

ListWznmJAMBlockItem::ListWznmJAMBlockItem() {
};

ListWznmJAMBlockItem::ListWznmJAMBlockItem(
			const ListWznmJAMBlockItem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJAMBlockItem(*(src.nodes[i]));
};

ListWznmJAMBlockItem::~ListWznmJAMBlockItem() {
	clear();
};

void ListWznmJAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJAMBlockItem::size() const {
	return(nodes.size());
};

void ListWznmJAMBlockItem::append(
			WznmJAMBlockItem* rec
		) {
	nodes.push_back(rec);
};

WznmJAMBlockItem* ListWznmJAMBlockItem::operator[](
			const uint ix
		) {
	WznmJAMBlockItem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJAMBlockItem& ListWznmJAMBlockItem::operator=(
			const ListWznmJAMBlockItem& src
		) {
	WznmJAMBlockItem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJAMBlockItem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJAMBlockItem::operator==(
			const ListWznmJAMBlockItem& comp
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

bool ListWznmJAMBlockItem::operator!=(
			const ListWznmJAMBlockItem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJAMBlockItem
 ******************************************************************************/

TblWznmJAMBlockItem::TblWznmJAMBlockItem() {
};

TblWznmJAMBlockItem::~TblWznmJAMBlockItem() {
};

bool TblWznmJAMBlockItem::loadRecBySQL(
			const string& sqlstr
			, WznmJAMBlockItem** rec
		) {
	return false;
};

ubigint TblWznmJAMBlockItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	return 0;
};

ubigint TblWznmJAMBlockItem::insertRec(
			WznmJAMBlockItem* rec
		) {
	return 0;
};

ubigint TblWznmJAMBlockItem::insertNewRec(
			WznmJAMBlockItem** rec
			, const ubigint refWznmAMBlockItem
			, const ubigint x1RefWznmMRelease
			, const string Defval
			, const ubigint refWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmJAMBlockItem* _rec = NULL;

	_rec = new WznmJAMBlockItem(0, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJAMBlockItem::appendNewRecToRst(
			ListWznmJAMBlockItem& rst
			, WznmJAMBlockItem** rec
			, const ubigint refWznmAMBlockItem
			, const ubigint x1RefWznmMRelease
			, const string Defval
			, const ubigint refWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmJAMBlockItem* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJAMBlockItem::insertRst(
			ListWznmJAMBlockItem& rst
			, bool transact
		) {
};

void TblWznmJAMBlockItem::updateRec(
			WznmJAMBlockItem* rec
		) {
};

void TblWznmJAMBlockItem::updateRst(
			ListWznmJAMBlockItem& rst
			, bool transact
		) {
};

void TblWznmJAMBlockItem::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJAMBlockItem::loadRecByRef(
			ubigint ref
			, WznmJAMBlockItem** rec
		) {
	return false;
};

bool TblWznmJAMBlockItem::loadDfvByBitRls(
			ubigint refWznmAMBlockItem
			, ubigint x1RefWznmMRelease
			, string& Defval
		) {
	return false;
};

bool TblWznmJAMBlockItem::loadRecByBitRls(
			ubigint refWznmAMBlockItem
			, ubigint x1RefWznmMRelease
			, WznmJAMBlockItem** rec
		) {
	return false;
};

ubigint TblWznmJAMBlockItem::loadRefsByBit(
			ubigint refWznmAMBlockItem
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJAMBlockItem::loadRstByBit(
			ubigint refWznmAMBlockItem
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	return 0;
};

ubigint TblWznmJAMBlockItem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	ubigint numload = 0;
	WznmJAMBlockItem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJAMBlockItem
 ******************************************************************************/

MyTblWznmJAMBlockItem::MyTblWznmJAMBlockItem() :
			TblWznmJAMBlockItem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJAMBlockItem::~MyTblWznmJAMBlockItem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJAMBlockItem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJAMBlockItem (refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJAMBlockItem SET refWznmAMBlockItem = ?, x1RefWznmMRelease = ?, Defval = ?, refWznmMVectoritem = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJAMBlockItem WHERE ref = ?", false);
};

bool MyTblWznmJAMBlockItem::loadRecBySQL(
			const string& sqlstr
			, WznmJAMBlockItem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJAMBlockItem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJAMBlockItem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJAMBlockItem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJAMBlockItem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmAMBlockItem = atoll((char*) dbrow[1]); else _rec->refWznmAMBlockItem = 0;
		if (dbrow[2]) _rec->x1RefWznmMRelease = atoll((char*) dbrow[2]); else _rec->x1RefWznmMRelease = 0;
		if (dbrow[3]) _rec->Defval.assign(dbrow[3], dblengths[3]); else _rec->Defval = "";
		if (dbrow[4]) _rec->refWznmMVectoritem = atoll((char*) dbrow[4]); else _rec->refWznmMVectoritem = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJAMBlockItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJAMBlockItem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJAMBlockItem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJAMBlockItem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJAMBlockItem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmAMBlockItem = atoll((char*) dbrow[1]); else rec->refWznmAMBlockItem = 0;
			if (dbrow[2]) rec->x1RefWznmMRelease = atoll((char*) dbrow[2]); else rec->x1RefWznmMRelease = 0;
			if (dbrow[3]) rec->Defval.assign(dbrow[3], dblengths[3]); else rec->Defval = "";
			if (dbrow[4]) rec->refWznmMVectoritem = atoll((char*) dbrow[4]); else rec->refWznmMVectoritem = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJAMBlockItem::insertRec(
			WznmJAMBlockItem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Defval.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmAMBlockItem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMRelease,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJAMBlockItem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJAMBlockItem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJAMBlockItem::insertRst(
			ListWznmJAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJAMBlockItem::updateRec(
			WznmJAMBlockItem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Defval.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmAMBlockItem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMRelease,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJAMBlockItem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJAMBlockItem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJAMBlockItem::updateRst(
			ListWznmJAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJAMBlockItem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJAMBlockItem::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJAMBlockItem::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJAMBlockItem::loadRecByRef(
			ubigint ref
			, WznmJAMBlockItem** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJAMBlockItem WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJAMBlockItem::loadDfvByBitRls(
			ubigint refWznmAMBlockItem
			, ubigint x1RefWznmMRelease
			, string& Defval
		) {
	return loadStringBySQL("SELECT Defval FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = " + to_string(refWznmAMBlockItem) + " AND x1RefWznmMRelease = " + to_string(x1RefWznmMRelease) + "", Defval);
};

bool MyTblWznmJAMBlockItem::loadRecByBitRls(
			ubigint refWznmAMBlockItem
			, ubigint x1RefWznmMRelease
			, WznmJAMBlockItem** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = " + to_string(refWznmAMBlockItem) + " AND x1RefWznmMRelease = " + to_string(x1RefWznmMRelease) + "", rec);
};

ubigint MyTblWznmJAMBlockItem::loadRefsByBit(
			ubigint refWznmAMBlockItem
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = " + to_string(refWznmAMBlockItem) + "", append, refs);
};

ubigint MyTblWznmJAMBlockItem::loadRstByBit(
			ubigint refWznmAMBlockItem
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = " + to_string(refWznmAMBlockItem) + " ORDER BY x1RefWznmMRelease ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJAMBlockItem
 ******************************************************************************/

PgTblWznmJAMBlockItem::PgTblWznmJAMBlockItem() :
			TblWznmJAMBlockItem()
			, PgTable()
		{
};

PgTblWznmJAMBlockItem::~PgTblWznmJAMBlockItem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJAMBlockItem::initStatements() {
	createStatement("TblWznmJAMBlockItem_insertRec", "INSERT INTO TblWznmJAMBlockItem (refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmJAMBlockItem_updateRec", "UPDATE TblWznmJAMBlockItem SET refWznmAMBlockItem = $1, x1RefWznmMRelease = $2, Defval = $3, refWznmMVectoritem = $4 WHERE ref = $5", 5);
	createStatement("TblWznmJAMBlockItem_removeRecByRef", "DELETE FROM TblWznmJAMBlockItem WHERE ref = $1", 1);

	createStatement("TblWznmJAMBlockItem_loadRecByRef", "SELECT ref, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem FROM TblWznmJAMBlockItem WHERE ref = $1", 1);
	createStatement("TblWznmJAMBlockItem_loadDfvByBitRls", "SELECT Defval FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = $1 AND x1RefWznmMRelease = $2", 2);
	createStatement("TblWznmJAMBlockItem_loadRecByBitRls", "SELECT ref, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = $1 AND x1RefWznmMRelease = $2", 2);
	createStatement("TblWznmJAMBlockItem_loadRefsByBit", "SELECT ref FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = $1", 1);
	createStatement("TblWznmJAMBlockItem_loadRstByBit", "SELECT ref, refWznmAMBlockItem, x1RefWznmMRelease, Defval, refWznmMVectoritem FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = $1 ORDER BY x1RefWznmMRelease ASC", 1);
};

bool PgTblWznmJAMBlockItem::loadRec(
			PGresult* res
			, WznmJAMBlockItem** rec
		) {
	char* ptr;

	WznmJAMBlockItem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJAMBlockItem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmamblockitem"),
			PQfnumber(res, "x1refwznmmrelease"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmAMBlockItem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMRelease = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMVectoritem = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJAMBlockItem::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJAMBlockItem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmamblockitem"),
			PQfnumber(res, "x1refwznmmrelease"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		while (numread < numrow) {
			rec = new WznmJAMBlockItem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmAMBlockItem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMRelease = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMVectoritem = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJAMBlockItem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJAMBlockItem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMBlockItem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJAMBlockItem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMBlockItem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJAMBlockItem::loadRecBySQL(
			const string& sqlstr
			, WznmJAMBlockItem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMBlockItem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJAMBlockItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMBlockItem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJAMBlockItem::insertRec(
			WznmJAMBlockItem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmAMBlockItem = htonl64(rec->refWznmAMBlockItem);
	ubigint _x1RefWznmMRelease = htonl64(rec->x1RefWznmMRelease);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmAMBlockItem,
		(char*) &_x1RefWznmMRelease,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJAMBlockItem_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJAMBlockItem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJAMBlockItem::insertRst(
			ListWznmJAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJAMBlockItem::updateRec(
			WznmJAMBlockItem* rec
		) {
	PGresult* res;

	ubigint _refWznmAMBlockItem = htonl64(rec->refWznmAMBlockItem);
	ubigint _x1RefWznmMRelease = htonl64(rec->x1RefWznmMRelease);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmAMBlockItem,
		(char*) &_x1RefWznmMRelease,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJAMBlockItem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJAMBlockItem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJAMBlockItem::updateRst(
			ListWznmJAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJAMBlockItem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJAMBlockItem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJAMBlockItem::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJAMBlockItem::loadRecByRef(
			ubigint ref
			, WznmJAMBlockItem** rec
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

	return loadRecByStmt("TblWznmJAMBlockItem_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJAMBlockItem::loadDfvByBitRls(
			ubigint refWznmAMBlockItem
			, ubigint x1RefWznmMRelease
			, string& Defval
		) {
	ubigint _refWznmAMBlockItem = htonl64(refWznmAMBlockItem);
	ubigint _x1RefWznmMRelease = htonl64(x1RefWznmMRelease);

	const char* vals[] = {
		(char*) &_refWznmAMBlockItem,
		(char*) &_x1RefWznmMRelease
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWznmJAMBlockItem_loadDfvByBitRls", 2, vals, l, f, Defval);
};

bool PgTblWznmJAMBlockItem::loadRecByBitRls(
			ubigint refWznmAMBlockItem
			, ubigint x1RefWznmMRelease
			, WznmJAMBlockItem** rec
		) {
	ubigint _refWznmAMBlockItem = htonl64(refWznmAMBlockItem);
	ubigint _x1RefWznmMRelease = htonl64(x1RefWznmMRelease);

	const char* vals[] = {
		(char*) &_refWznmAMBlockItem,
		(char*) &_x1RefWznmMRelease
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJAMBlockItem_loadRecByBitRls", 2, vals, l, f, rec);
};

ubigint PgTblWznmJAMBlockItem::loadRefsByBit(
			ubigint refWznmAMBlockItem
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmAMBlockItem = htonl64(refWznmAMBlockItem);

	const char* vals[] = {
		(char*) &_refWznmAMBlockItem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJAMBlockItem_loadRefsByBit", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJAMBlockItem::loadRstByBit(
			ubigint refWznmAMBlockItem
			, const bool append
			, ListWznmJAMBlockItem& rst
		) {
	ubigint _refWznmAMBlockItem = htonl64(refWznmAMBlockItem);

	const char* vals[] = {
		(char*) &_refWznmAMBlockItem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJAMBlockItem_loadRstByBit", 1, vals, l, f, append, rst);
};

#endif
