/**
	* \file WznmAMTableLoadfct.cpp
	* database access for table TblWznmAMTableLoadfct (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMTableLoadfct.h"

#include "WznmAMTableLoadfct_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMTableLoadfct
 ******************************************************************************/

WznmAMTableLoadfct::WznmAMTableLoadfct(
			const ubigint ref
			, const ubigint refWznmMTable
			, const uint ixVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const uint ixVLimtype
		) {

	this->ref = ref;
	this->refWznmMTable = refWznmMTable;
	this->ixVLoadtype = ixVLoadtype;
	this->Fctname = Fctname;
	this->ldSrefWznmMTablecol = ldSrefWznmMTablecol;
	this->lbySrefsWznmMTablecol = lbySrefsWznmMTablecol;
	this->ordSrefsWznmMTablecol = ordSrefsWznmMTablecol;
	this->ixVLimtype = ixVLimtype;
};

bool WznmAMTableLoadfct::operator==(
			const WznmAMTableLoadfct& comp
		) {
	return false;
};

bool WznmAMTableLoadfct::operator!=(
			const WznmAMTableLoadfct& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMTableLoadfct
 ******************************************************************************/

ListWznmAMTableLoadfct::ListWznmAMTableLoadfct() {
};

ListWznmAMTableLoadfct::ListWznmAMTableLoadfct(
			const ListWznmAMTableLoadfct& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMTableLoadfct(*(src.nodes[i]));
};

ListWznmAMTableLoadfct::~ListWznmAMTableLoadfct() {
	clear();
};

void ListWznmAMTableLoadfct::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMTableLoadfct::size() const {
	return(nodes.size());
};

void ListWznmAMTableLoadfct::append(
			WznmAMTableLoadfct* rec
		) {
	nodes.push_back(rec);
};

WznmAMTableLoadfct* ListWznmAMTableLoadfct::operator[](
			const uint ix
		) {
	WznmAMTableLoadfct* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMTableLoadfct& ListWznmAMTableLoadfct::operator=(
			const ListWznmAMTableLoadfct& src
		) {
	WznmAMTableLoadfct* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMTableLoadfct(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMTableLoadfct::operator==(
			const ListWznmAMTableLoadfct& comp
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

bool ListWznmAMTableLoadfct::operator!=(
			const ListWznmAMTableLoadfct& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMTableLoadfct
 ******************************************************************************/

TblWznmAMTableLoadfct::TblWznmAMTableLoadfct() {
};

TblWznmAMTableLoadfct::~TblWznmAMTableLoadfct() {
};

bool TblWznmAMTableLoadfct::loadRecBySQL(
			const string& sqlstr
			, WznmAMTableLoadfct** rec
		) {
	return false;
};

ubigint TblWznmAMTableLoadfct::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	return 0;
};

ubigint TblWznmAMTableLoadfct::insertRec(
			WznmAMTableLoadfct* rec
		) {
	return 0;
};

ubigint TblWznmAMTableLoadfct::insertNewRec(
			WznmAMTableLoadfct** rec
			, const ubigint refWznmMTable
			, const uint ixVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const uint ixVLimtype
		) {
	ubigint retval = 0;
	WznmAMTableLoadfct* _rec = NULL;

	_rec = new WznmAMTableLoadfct(0, refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMTableLoadfct::appendNewRecToRst(
			ListWznmAMTableLoadfct& rst
			, WznmAMTableLoadfct** rec
			, const ubigint refWznmMTable
			, const uint ixVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const uint ixVLimtype
		) {
	ubigint retval = 0;
	WznmAMTableLoadfct* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMTableLoadfct::insertRst(
			ListWznmAMTableLoadfct& rst
			, bool transact
		) {
};

void TblWznmAMTableLoadfct::updateRec(
			WznmAMTableLoadfct* rec
		) {
};

void TblWznmAMTableLoadfct::updateRst(
			ListWznmAMTableLoadfct& rst
			, bool transact
		) {
};

void TblWznmAMTableLoadfct::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMTableLoadfct::loadRecByRef(
			ubigint ref
			, WznmAMTableLoadfct** rec
		) {
	return false;
};

ubigint TblWznmAMTableLoadfct::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMTableLoadfct::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	return 0;
};

ubigint TblWznmAMTableLoadfct::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	ubigint numload = 0;
	WznmAMTableLoadfct* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMTableLoadfct
 ******************************************************************************/

MyTblWznmAMTableLoadfct::MyTblWznmAMTableLoadfct() :
			TblWznmAMTableLoadfct()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMTableLoadfct::~MyTblWznmAMTableLoadfct() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMTableLoadfct::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMTableLoadfct (refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMTableLoadfct SET refWznmMTable = ?, ixVLoadtype = ?, Fctname = ?, ldSrefWznmMTablecol = ?, lbySrefsWznmMTablecol = ?, ordSrefsWznmMTablecol = ?, ixVLimtype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMTableLoadfct WHERE ref = ?", false);
};

bool MyTblWznmAMTableLoadfct::loadRecBySQL(
			const string& sqlstr
			, WznmAMTableLoadfct** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMTableLoadfct* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMTableLoadfct::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMTableLoadfct::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMTableLoadfct();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMTable = atoll((char*) dbrow[1]); else _rec->refWznmMTable = 0;
		if (dbrow[2]) _rec->ixVLoadtype = atol((char*) dbrow[2]); else _rec->ixVLoadtype = 0;
		if (dbrow[3]) _rec->Fctname.assign(dbrow[3], dblengths[3]); else _rec->Fctname = "";
		if (dbrow[4]) _rec->ldSrefWznmMTablecol.assign(dbrow[4], dblengths[4]); else _rec->ldSrefWznmMTablecol = "";
		if (dbrow[5]) _rec->lbySrefsWznmMTablecol.assign(dbrow[5], dblengths[5]); else _rec->lbySrefsWznmMTablecol = "";
		if (dbrow[6]) _rec->ordSrefsWznmMTablecol.assign(dbrow[6], dblengths[6]); else _rec->ordSrefsWznmMTablecol = "";
		if (dbrow[7]) _rec->ixVLimtype = atol((char*) dbrow[7]); else _rec->ixVLimtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMTableLoadfct::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMTableLoadfct* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMTableLoadfct::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMTableLoadfct::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMTableLoadfct();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMTable = atoll((char*) dbrow[1]); else rec->refWznmMTable = 0;
			if (dbrow[2]) rec->ixVLoadtype = atol((char*) dbrow[2]); else rec->ixVLoadtype = 0;
			if (dbrow[3]) rec->Fctname.assign(dbrow[3], dblengths[3]); else rec->Fctname = "";
			if (dbrow[4]) rec->ldSrefWznmMTablecol.assign(dbrow[4], dblengths[4]); else rec->ldSrefWznmMTablecol = "";
			if (dbrow[5]) rec->lbySrefsWznmMTablecol.assign(dbrow[5], dblengths[5]); else rec->lbySrefsWznmMTablecol = "";
			if (dbrow[6]) rec->ordSrefsWznmMTablecol.assign(dbrow[6], dblengths[6]); else rec->ordSrefsWznmMTablecol = "";
			if (dbrow[7]) rec->ixVLimtype = atol((char*) dbrow[7]); else rec->ixVLimtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMTableLoadfct::insertRec(
			WznmAMTableLoadfct* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->Fctname.length();
	l[3] = rec->ldSrefWznmMTablecol.length();
	l[4] = rec->lbySrefsWznmMTablecol.length();
	l[5] = rec->ordSrefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixVLoadtype,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Fctname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->ldSrefWznmMTablecol.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->lbySrefsWznmMTablecol.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->ordSrefsWznmMTablecol.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVLimtype,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMTableLoadfct::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMTableLoadfct::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMTableLoadfct::insertRst(
			ListWznmAMTableLoadfct& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMTableLoadfct::updateRec(
			WznmAMTableLoadfct* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->Fctname.length();
	l[3] = rec->ldSrefWznmMTablecol.length();
	l[4] = rec->lbySrefsWznmMTablecol.length();
	l[5] = rec->ordSrefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMTable,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixVLoadtype,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Fctname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->ldSrefWznmMTablecol.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->lbySrefsWznmMTablecol.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->ordSrefsWznmMTablecol.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVLimtype,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMTableLoadfct::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMTableLoadfct::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMTableLoadfct::updateRst(
			ListWznmAMTableLoadfct& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMTableLoadfct::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMTableLoadfct::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMTableLoadfct::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMTableLoadfct::loadRecByRef(
			ubigint ref
			, WznmAMTableLoadfct** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMTableLoadfct WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMTableLoadfct::loadRefsByTbl(
			ubigint refWznmMTable
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(refWznmMTable) + "", append, refs);
};

ubigint MyTblWznmAMTableLoadfct::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(refWznmMTable) + " ORDER BY Fctname ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMTableLoadfct
 ******************************************************************************/

PgTblWznmAMTableLoadfct::PgTblWznmAMTableLoadfct() :
			TblWznmAMTableLoadfct()
			, PgTable()
		{
};

PgTblWznmAMTableLoadfct::~PgTblWznmAMTableLoadfct() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMTableLoadfct::initStatements() {
	createStatement("TblWznmAMTableLoadfct_insertRec", "INSERT INTO TblWznmAMTableLoadfct (refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmAMTableLoadfct_updateRec", "UPDATE TblWznmAMTableLoadfct SET refWznmMTable = $1, ixVLoadtype = $2, Fctname = $3, ldSrefWznmMTablecol = $4, lbySrefsWznmMTablecol = $5, ordSrefsWznmMTablecol = $6, ixVLimtype = $7 WHERE ref = $8", 8);
	createStatement("TblWznmAMTableLoadfct_removeRecByRef", "DELETE FROM TblWznmAMTableLoadfct WHERE ref = $1", 1);

	createStatement("TblWznmAMTableLoadfct_loadRecByRef", "SELECT ref, refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype FROM TblWznmAMTableLoadfct WHERE ref = $1", 1);
	createStatement("TblWznmAMTableLoadfct_loadRefsByTbl", "SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = $1", 1);
	createStatement("TblWznmAMTableLoadfct_loadRstByTbl", "SELECT ref, refWznmMTable, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype FROM TblWznmAMTableLoadfct WHERE refWznmMTable = $1 ORDER BY Fctname ASC", 1);
};

bool PgTblWznmAMTableLoadfct::loadRec(
			PGresult* res
			, WznmAMTableLoadfct** rec
		) {
	char* ptr;

	WznmAMTableLoadfct* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMTableLoadfct();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "ixvloadtype"),
			PQfnumber(res, "fctname"),
			PQfnumber(res, "ldsrefwznmmtablecol"),
			PQfnumber(res, "lbysrefswznmmtablecol"),
			PQfnumber(res, "ordsrefswznmmtablecol"),
			PQfnumber(res, "ixvlimtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->ixVLoadtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Fctname.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ldSrefWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->lbySrefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ordSrefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVLimtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMTableLoadfct::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMTableLoadfct* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "ixvloadtype"),
			PQfnumber(res, "fctname"),
			PQfnumber(res, "ldsrefwznmmtablecol"),
			PQfnumber(res, "lbysrefswznmmtablecol"),
			PQfnumber(res, "ordsrefswznmmtablecol"),
			PQfnumber(res, "ixvlimtype")
		};

		while (numread < numrow) {
			rec = new WznmAMTableLoadfct();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->ixVLoadtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Fctname.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ldSrefWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->lbySrefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ordSrefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVLimtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMTableLoadfct::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMTableLoadfct** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMTableLoadfct::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMTableLoadfct::loadRecBySQL(
			const string& sqlstr
			, WznmAMTableLoadfct** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMTableLoadfct::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMTableLoadfct::insertRec(
			WznmAMTableLoadfct* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	uint _ixVLoadtype = htonl(rec->ixVLoadtype);
	uint _ixVLimtype = htonl(rec->ixVLimtype);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_ixVLoadtype,
		rec->Fctname.c_str(),
		rec->ldSrefWznmMTablecol.c_str(),
		rec->lbySrefsWznmMTablecol.c_str(),
		rec->ordSrefsWznmMTablecol.c_str(),
		(char*) &_ixVLimtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMTableLoadfct_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMTableLoadfct::insertRst(
			ListWznmAMTableLoadfct& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMTableLoadfct::updateRec(
			WznmAMTableLoadfct* rec
		) {
	PGresult* res;

	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	uint _ixVLoadtype = htonl(rec->ixVLoadtype);
	uint _ixVLimtype = htonl(rec->ixVLimtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMTable,
		(char*) &_ixVLoadtype,
		rec->Fctname.c_str(),
		rec->ldSrefWznmMTablecol.c_str(),
		rec->lbySrefsWznmMTablecol.c_str(),
		rec->ordSrefsWznmMTablecol.c_str(),
		(char*) &_ixVLimtype,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmAMTableLoadfct_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMTableLoadfct::updateRst(
			ListWznmAMTableLoadfct& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMTableLoadfct::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMTableLoadfct_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMTableLoadfct::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMTableLoadfct::loadRecByRef(
			ubigint ref
			, WznmAMTableLoadfct** rec
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

	return loadRecByStmt("TblWznmAMTableLoadfct_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMTableLoadfct::loadRefsByTbl(
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

	return loadRefsByStmt("TblWznmAMTableLoadfct_loadRefsByTbl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMTableLoadfct::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmAMTableLoadfct& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMTableLoadfct_loadRstByTbl", 1, vals, l, f, append, rst);
};

#endif
