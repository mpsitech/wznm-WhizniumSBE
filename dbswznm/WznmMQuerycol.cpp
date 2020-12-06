/**
	* \file WznmMQuerycol.cpp
	* database access for table TblWznmMQuerycol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMQuerycol.h"

#include "WznmMQuerycol_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMQuerycol
 ******************************************************************************/

WznmMQuerycol::WznmMQuerycol(
			const ubigint ref
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint refWznmMTablecol
			, const string sref
			, const string Short
			, const ubigint refWznmMStub
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->ixWOccurrence = ixWOccurrence;
	this->qryRefWznmMQuery = qryRefWznmMQuery;
	this->qryNum = qryNum;
	this->refWznmMTablecol = refWznmMTablecol;
	this->sref = sref;
	this->Short = Short;
	this->refWznmMStub = refWznmMStub;
};

bool WznmMQuerycol::operator==(
			const WznmMQuerycol& comp
		) {
	return false;
};

bool WznmMQuerycol::operator!=(
			const WznmMQuerycol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMQuerycol
 ******************************************************************************/

ListWznmMQuerycol::ListWznmMQuerycol() {
};

ListWznmMQuerycol::ListWznmMQuerycol(
			const ListWznmMQuerycol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMQuerycol(*(src.nodes[i]));
};

ListWznmMQuerycol::~ListWznmMQuerycol() {
	clear();
};

void ListWznmMQuerycol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMQuerycol::size() const {
	return(nodes.size());
};

void ListWznmMQuerycol::append(
			WznmMQuerycol* rec
		) {
	nodes.push_back(rec);
};

WznmMQuerycol* ListWznmMQuerycol::operator[](
			const uint ix
		) {
	WznmMQuerycol* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMQuerycol& ListWznmMQuerycol::operator=(
			const ListWznmMQuerycol& src
		) {
	WznmMQuerycol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMQuerycol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMQuerycol::operator==(
			const ListWznmMQuerycol& comp
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

bool ListWznmMQuerycol::operator!=(
			const ListWznmMQuerycol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMQuerycol
 ******************************************************************************/

TblWznmMQuerycol::TblWznmMQuerycol() {
};

TblWznmMQuerycol::~TblWznmMQuerycol() {
};

bool TblWznmMQuerycol::loadRecBySQL(
			const string& sqlstr
			, WznmMQuerycol** rec
		) {
	return false;
};

ubigint TblWznmMQuerycol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	return 0;
};

ubigint TblWznmMQuerycol::insertRec(
			WznmMQuerycol* rec
		) {
	return 0;
};

ubigint TblWznmMQuerycol::insertNewRec(
			WznmMQuerycol** rec
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint refWznmMTablecol
			, const string sref
			, const string Short
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmMQuerycol* _rec = NULL;

	_rec = new WznmMQuerycol(0, ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMQuerycol::appendNewRecToRst(
			ListWznmMQuerycol& rst
			, WznmMQuerycol** rec
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint refWznmMTablecol
			, const string sref
			, const string Short
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmMQuerycol* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMQuerycol::insertRst(
			ListWznmMQuerycol& rst
			, bool transact
		) {
};

void TblWznmMQuerycol::updateRec(
			WznmMQuerycol* rec
		) {
};

void TblWznmMQuerycol::updateRst(
			ListWznmMQuerycol& rst
			, bool transact
		) {
};

void TblWznmMQuerycol::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMQuerycol::loadRecByRef(
			ubigint ref
			, WznmMQuerycol** rec
		) {
	return false;
};

ubigint TblWznmMQuerycol::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMQuerycol::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	return 0;
};

ubigint TblWznmMQuerycol::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	ubigint numload = 0;
	WznmMQuerycol* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMQuerycol
 ******************************************************************************/

MyTblWznmMQuerycol::MyTblWznmMQuerycol() :
			TblWznmMQuerycol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMQuerycol::~MyTblWznmMQuerycol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMQuerycol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMQuerycol (ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMQuerycol SET ixVBasetype = ?, ixWOccurrence = ?, qryRefWznmMQuery = ?, qryNum = ?, refWznmMTablecol = ?, sref = ?, Short = ?, refWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMQuerycol WHERE ref = ?", false);
};

bool MyTblWznmMQuerycol::loadRecBySQL(
			const string& sqlstr
			, WznmMQuerycol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMQuerycol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMQuerycol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMQuerycol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMQuerycol();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->ixWOccurrence = atol((char*) dbrow[2]); else _rec->ixWOccurrence = 0;
		if (dbrow[3]) _rec->qryRefWznmMQuery = atoll((char*) dbrow[3]); else _rec->qryRefWznmMQuery = 0;
		if (dbrow[4]) _rec->qryNum = atol((char*) dbrow[4]); else _rec->qryNum = 0;
		if (dbrow[5]) _rec->refWznmMTablecol = atoll((char*) dbrow[5]); else _rec->refWznmMTablecol = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Short.assign(dbrow[7], dblengths[7]); else _rec->Short = "";
		if (dbrow[8]) _rec->refWznmMStub = atoll((char*) dbrow[8]); else _rec->refWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMQuerycol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMQuerycol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMQuerycol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMQuerycol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMQuerycol();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->ixWOccurrence = atol((char*) dbrow[2]); else rec->ixWOccurrence = 0;
			if (dbrow[3]) rec->qryRefWznmMQuery = atoll((char*) dbrow[3]); else rec->qryRefWznmMQuery = 0;
			if (dbrow[4]) rec->qryNum = atol((char*) dbrow[4]); else rec->qryNum = 0;
			if (dbrow[5]) rec->refWznmMTablecol = atoll((char*) dbrow[5]); else rec->refWznmMTablecol = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Short.assign(dbrow[7], dblengths[7]); else rec->Short = "";
			if (dbrow[8]) rec->refWznmMStub = atoll((char*) dbrow[8]); else rec->refWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMQuerycol::insertRec(
			WznmMQuerycol* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->sref.length();
	l[6] = rec->Short.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixWOccurrence,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMTablecol,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Short.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMStub,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMQuerycol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMQuerycol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMQuerycol::insertRst(
			ListWznmMQuerycol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMQuerycol::updateRec(
			WznmMQuerycol* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->sref.length();
	l[6] = rec->Short.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixWOccurrence,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMTablecol,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Short.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMStub,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMQuerycol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMQuerycol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMQuerycol::updateRst(
			ListWznmMQuerycol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMQuerycol::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMQuerycol::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMQuerycol::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMQuerycol::loadRecByRef(
			ubigint ref
			, WznmMQuerycol** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMQuerycol WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMQuerycol::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = " + to_string(qryRefWznmMQuery) + "", append, refs);
};

ubigint MyTblWznmMQuerycol::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = " + to_string(qryRefWznmMQuery) + " ORDER BY qryNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMQuerycol
 ******************************************************************************/

PgTblWznmMQuerycol::PgTblWznmMQuerycol() :
			TblWznmMQuerycol()
			, PgTable()
		{
};

PgTblWznmMQuerycol::~PgTblWznmMQuerycol() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMQuerycol::initStatements() {
	createStatement("TblWznmMQuerycol_insertRec", "INSERT INTO TblWznmMQuerycol (ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMQuerycol_updateRec", "UPDATE TblWznmMQuerycol SET ixVBasetype = $1, ixWOccurrence = $2, qryRefWznmMQuery = $3, qryNum = $4, refWznmMTablecol = $5, sref = $6, Short = $7, refWznmMStub = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMQuerycol_removeRecByRef", "DELETE FROM TblWznmMQuerycol WHERE ref = $1", 1);

	createStatement("TblWznmMQuerycol_loadRecByRef", "SELECT ref, ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub FROM TblWznmMQuerycol WHERE ref = $1", 1);
	createStatement("TblWznmMQuerycol_loadRefsByQry", "SELECT ref FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = $1", 1);
	createStatement("TblWznmMQuerycol_loadRstByQry", "SELECT ref, ixVBasetype, ixWOccurrence, qryRefWznmMQuery, qryNum, refWznmMTablecol, sref, Short, refWznmMStub FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = $1 ORDER BY qryNum ASC", 1);
};

bool PgTblWznmMQuerycol::loadRec(
			PGresult* res
			, WznmMQuerycol** rec
		) {
	char* ptr;

	WznmMQuerycol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMQuerycol();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixwoccurrence"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "refwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->ixWOccurrence = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->qryRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->qryNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMTablecol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMQuerycol::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMQuerycol* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixwoccurrence"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "refwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmMQuerycol();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->ixWOccurrence = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->qryRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->qryNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMTablecol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMQuerycol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMQuerycol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerycol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMQuerycol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerycol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMQuerycol::loadRecBySQL(
			const string& sqlstr
			, WznmMQuerycol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerycol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMQuerycol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerycol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMQuerycol::insertRec(
			WznmMQuerycol* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixWOccurrence = htonl(rec->ixWOccurrence);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_ixWOccurrence,
		(char*) &_qryRefWznmMQuery,
		(char*) &_qryNum,
		(char*) &_refWznmMTablecol,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMQuerycol_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerycol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMQuerycol::insertRst(
			ListWznmMQuerycol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMQuerycol::updateRec(
			WznmMQuerycol* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixWOccurrence = htonl(rec->ixWOccurrence);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_ixWOccurrence,
		(char*) &_qryRefWznmMQuery,
		(char*) &_qryNum,
		(char*) &_refWznmMTablecol,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_refWznmMStub,
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
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmMQuerycol_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMQuerycol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMQuerycol::updateRst(
			ListWznmMQuerycol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMQuerycol::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMQuerycol_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMQuerycol::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMQuerycol::loadRecByRef(
			ubigint ref
			, WznmMQuerycol** rec
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

	return loadRecByStmt("TblWznmMQuerycol_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMQuerycol::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _qryRefWznmMQuery = htonl64(qryRefWznmMQuery);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMQuerycol_loadRefsByQry", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMQuerycol::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmMQuerycol& rst
		) {
	ubigint _qryRefWznmMQuery = htonl64(qryRefWznmMQuery);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMQuerycol_loadRstByQry", 1, vals, l, f, append, rst);
};

#endif
