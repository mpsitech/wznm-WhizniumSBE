/**
	* \file WznmMQuerymod.cpp
	* database access for table TblWznmMQuerymod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMQuerymod.h"

#include "WznmMQuerymod_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMQuerymod
 ******************************************************************************/

WznmMQuerymod::WznmMQuerymod(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint refWznmMPreset
			, const uint refIxVTbl
			, const ubigint refUref
			, const string Avail
		) :
			ref(ref)
			, ixVBasetype(ixVBasetype)
			, qryRefWznmMQuery(qryRefWznmMQuery)
			, qryNum(qryNum)
			, refWznmMPreset(refWznmMPreset)
			, refIxVTbl(refIxVTbl)
			, refUref(refUref)
			, Avail(Avail)
		{
};

bool WznmMQuerymod::operator==(
			const WznmMQuerymod& comp
		) {
	return false;
};

bool WznmMQuerymod::operator!=(
			const WznmMQuerymod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMQuerymod
 ******************************************************************************/

ListWznmMQuerymod::ListWznmMQuerymod() {
};

ListWznmMQuerymod::ListWznmMQuerymod(
			const ListWznmMQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMQuerymod(*(src.nodes[i]));
};

ListWznmMQuerymod::~ListWznmMQuerymod() {
	clear();
};

void ListWznmMQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMQuerymod::size() const {
	return(nodes.size());
};

void ListWznmMQuerymod::append(
			WznmMQuerymod* rec
		) {
	nodes.push_back(rec);
};

WznmMQuerymod* ListWznmMQuerymod::operator[](
			const uint ix
		) {
	WznmMQuerymod* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMQuerymod& ListWznmMQuerymod::operator=(
			const ListWznmMQuerymod& src
		) {
	WznmMQuerymod* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMQuerymod(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMQuerymod::operator==(
			const ListWznmMQuerymod& comp
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

bool ListWznmMQuerymod::operator!=(
			const ListWznmMQuerymod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMQuerymod
 ******************************************************************************/

TblWznmMQuerymod::TblWznmMQuerymod() {
};

TblWznmMQuerymod::~TblWznmMQuerymod() {
};

bool TblWznmMQuerymod::loadRecBySQL(
			const string& sqlstr
			, WznmMQuerymod** rec
		) {
	return false;
};

ubigint TblWznmMQuerymod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	return 0;
};

ubigint TblWznmMQuerymod::insertRec(
			WznmMQuerymod* rec
		) {
	return 0;
};

ubigint TblWznmMQuerymod::insertNewRec(
			WznmMQuerymod** rec
			, const uint ixVBasetype
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint refWznmMPreset
			, const uint refIxVTbl
			, const ubigint refUref
			, const string Avail
		) {
	ubigint retval = 0;
	WznmMQuerymod* _rec = NULL;

	_rec = new WznmMQuerymod(0, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMQuerymod::appendNewRecToRst(
			ListWznmMQuerymod& rst
			, WznmMQuerymod** rec
			, const uint ixVBasetype
			, const ubigint qryRefWznmMQuery
			, const uint qryNum
			, const ubigint refWznmMPreset
			, const uint refIxVTbl
			, const ubigint refUref
			, const string Avail
		) {
	ubigint retval = 0;
	WznmMQuerymod* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMQuerymod::insertRst(
			ListWznmMQuerymod& rst
			, bool transact
		) {
};

void TblWznmMQuerymod::updateRec(
			WznmMQuerymod* rec
		) {
};

void TblWznmMQuerymod::updateRst(
			ListWznmMQuerymod& rst
			, bool transact
		) {
};

void TblWznmMQuerymod::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMQuerymod::loadRecByRef(
			ubigint ref
			, WznmMQuerymod** rec
		) {
	return false;
};

ubigint TblWznmMQuerymod::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMQuerymod::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	return 0;
};

ubigint TblWznmMQuerymod::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	return 0;
};

ubigint TblWznmMQuerymod::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	ubigint numload = 0;
	WznmMQuerymod* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMQuerymod
 ******************************************************************************/

MyTblWznmMQuerymod::MyTblWznmMQuerymod() :
			TblWznmMQuerymod()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMQuerymod::~MyTblWznmMQuerymod() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMQuerymod::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMQuerymod (ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMQuerymod SET ixVBasetype = ?, qryRefWznmMQuery = ?, qryNum = ?, refWznmMPreset = ?, refIxVTbl = ?, refUref = ?, Avail = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMQuerymod WHERE ref = ?", false);
};

bool MyTblWznmMQuerymod::loadRecBySQL(
			const string& sqlstr
			, WznmMQuerymod** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMQuerymod* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMQuerymod::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMQuerymod::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMQuerymod();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->qryRefWznmMQuery = atoll((char*) dbrow[2]); else _rec->qryRefWznmMQuery = 0;
		if (dbrow[3]) _rec->qryNum = atol((char*) dbrow[3]); else _rec->qryNum = 0;
		if (dbrow[4]) _rec->refWznmMPreset = atoll((char*) dbrow[4]); else _rec->refWznmMPreset = 0;
		if (dbrow[5]) _rec->refIxVTbl = atol((char*) dbrow[5]); else _rec->refIxVTbl = 0;
		if (dbrow[6]) _rec->refUref = atoll((char*) dbrow[6]); else _rec->refUref = 0;
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMQuerymod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMQuerymod* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMQuerymod::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMQuerymod::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMQuerymod();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->qryRefWznmMQuery = atoll((char*) dbrow[2]); else rec->qryRefWznmMQuery = 0;
			if (dbrow[3]) rec->qryNum = atol((char*) dbrow[3]); else rec->qryNum = 0;
			if (dbrow[4]) rec->refWznmMPreset = atoll((char*) dbrow[4]); else rec->refWznmMPreset = 0;
			if (dbrow[5]) rec->refIxVTbl = atol((char*) dbrow[5]); else rec->refIxVTbl = 0;
			if (dbrow[6]) rec->refUref = atoll((char*) dbrow[6]); else rec->refUref = 0;
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMQuerymod::insertRec(
			WznmMQuerymod* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->Avail.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->qryNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMPreset,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMQuerymod::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMQuerymod::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMQuerymod::insertRst(
			ListWznmMQuerymod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMQuerymod::updateRec(
			WznmMQuerymod* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->Avail.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->qryNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMPreset,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMQuerymod::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMQuerymod::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMQuerymod::updateRst(
			ListWznmMQuerymod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMQuerymod::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMQuerymod::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMQuerymod::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMQuerymod::loadRecByRef(
			ubigint ref
			, WznmMQuerymod** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMQuerymod WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMQuerymod::loadRefsByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qryRefWznmMQuery) + "", append, refs);
};

ubigint MyTblWznmMQuerymod::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qryRefWznmMQuery) + " ORDER BY qryNum ASC", append, rst);
};

ubigint MyTblWznmMQuerymod::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail FROM TblWznmMQuerymod WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMQuerymod
 ******************************************************************************/

PgTblWznmMQuerymod::PgTblWznmMQuerymod() :
			TblWznmMQuerymod()
			, PgTable()
		{
};

PgTblWznmMQuerymod::~PgTblWznmMQuerymod() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMQuerymod::initStatements() {
	createStatement("TblWznmMQuerymod_insertRec", "INSERT INTO TblWznmMQuerymod (ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmMQuerymod_updateRec", "UPDATE TblWznmMQuerymod SET ixVBasetype = $1, qryRefWznmMQuery = $2, qryNum = $3, refWznmMPreset = $4, refIxVTbl = $5, refUref = $6, Avail = $7 WHERE ref = $8", 8);
	createStatement("TblWznmMQuerymod_removeRecByRef", "DELETE FROM TblWznmMQuerymod WHERE ref = $1", 1);

	createStatement("TblWznmMQuerymod_loadRecByRef", "SELECT ref, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail FROM TblWznmMQuerymod WHERE ref = $1", 1);
	createStatement("TblWznmMQuerymod_loadRefsByQry", "SELECT ref FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = $1", 1);
	createStatement("TblWznmMQuerymod_loadRstByQry", "SELECT ref, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = $1 ORDER BY qryNum ASC", 1);
	createStatement("TblWznmMQuerymod_loadRstByRetReu", "SELECT ref, ixVBasetype, qryRefWznmMQuery, qryNum, refWznmMPreset, refIxVTbl, refUref, Avail FROM TblWznmMQuerymod WHERE refIxVTbl = $1 AND refUref = $2", 2);
};

bool PgTblWznmMQuerymod::loadRec(
			PGresult* res
			, WznmMQuerymod** rec
		) {
	char* ptr;

	WznmMQuerymod* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMQuerymod();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "avail")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->qryRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->qryNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMQuerymod::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMQuerymod* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "avail")
		};

		while (numread < numrow) {
			rec = new WznmMQuerymod();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->qryRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->qryNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMQuerymod::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMQuerymod** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerymod::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMQuerymod::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerymod::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMQuerymod::loadRecBySQL(
			const string& sqlstr
			, WznmMQuerymod** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerymod::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMQuerymod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerymod::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMQuerymod::insertRec(
			WznmMQuerymod* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_qryRefWznmMQuery,
		(char*) &_qryNum,
		(char*) &_refWznmMPreset,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->Avail.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMQuerymod_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuerymod::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMQuerymod::insertRst(
			ListWznmMQuerymod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMQuerymod::updateRec(
			WznmMQuerymod* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_qryRefWznmMQuery,
		(char*) &_qryNum,
		(char*) &_refWznmMPreset,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->Avail.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMQuerymod_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMQuerymod::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMQuerymod::updateRst(
			ListWznmMQuerymod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMQuerymod::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMQuerymod_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMQuerymod::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMQuerymod::loadRecByRef(
			ubigint ref
			, WznmMQuerymod** rec
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

	return loadRecByStmt("TblWznmMQuerymod_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMQuerymod::loadRefsByQry(
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

	return loadRefsByStmt("TblWznmMQuerymod_loadRefsByQry", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMQuerymod::loadRstByQry(
			ubigint qryRefWznmMQuery
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	ubigint _qryRefWznmMQuery = htonl64(qryRefWznmMQuery);

	const char* vals[] = {
		(char*) &_qryRefWznmMQuery
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMQuerymod_loadRstByQry", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmMQuerymod::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWznmMQuerymod& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWznmMQuerymod_loadRstByRetReu", 2, vals, l, f, append, rst);
};

#endif
