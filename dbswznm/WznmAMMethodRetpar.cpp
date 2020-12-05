/**
	* \file WznmAMMethodRetpar.cpp
	* database access for table TblWznmAMMethodRetpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMMethodRetpar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMMethodRetpar
 ******************************************************************************/

WznmAMMethodRetpar::WznmAMMethodRetpar(
			const ubigint ref
			, const ubigint mtdRefWznmMMethod
			, const uint mtdNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const uint Length
			, const string Comment
		) {

	this->ref = ref;
	this->mtdRefWznmMMethod = mtdRefWznmMMethod;
	this->mtdNum = mtdNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->Length = Length;
	this->Comment = Comment;
};

bool WznmAMMethodRetpar::operator==(
			const WznmAMMethodRetpar& comp
		) {
	return false;
};

bool WznmAMMethodRetpar::operator!=(
			const WznmAMMethodRetpar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMMethodRetpar
 ******************************************************************************/

ListWznmAMMethodRetpar::ListWznmAMMethodRetpar() {
};

ListWznmAMMethodRetpar::ListWznmAMMethodRetpar(
			const ListWznmAMMethodRetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMMethodRetpar(*(src.nodes[i]));
};

ListWznmAMMethodRetpar::~ListWznmAMMethodRetpar() {
	clear();
};

void ListWznmAMMethodRetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMMethodRetpar::size() const {
	return(nodes.size());
};

void ListWznmAMMethodRetpar::append(
			WznmAMMethodRetpar* rec
		) {
	nodes.push_back(rec);
};

WznmAMMethodRetpar* ListWznmAMMethodRetpar::operator[](
			const uint ix
		) {
	WznmAMMethodRetpar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMMethodRetpar& ListWznmAMMethodRetpar::operator=(
			const ListWznmAMMethodRetpar& src
		) {
	WznmAMMethodRetpar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMMethodRetpar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMMethodRetpar::operator==(
			const ListWznmAMMethodRetpar& comp
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

bool ListWznmAMMethodRetpar::operator!=(
			const ListWznmAMMethodRetpar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMMethodRetpar
 ******************************************************************************/

TblWznmAMMethodRetpar::TblWznmAMMethodRetpar() {
};

TblWznmAMMethodRetpar::~TblWznmAMMethodRetpar() {
};

bool TblWznmAMMethodRetpar::loadRecBySQL(
			const string& sqlstr
			, WznmAMMethodRetpar** rec
		) {
	return false;
};

ubigint TblWznmAMMethodRetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	return 0;
};

ubigint TblWznmAMMethodRetpar::insertRec(
			WznmAMMethodRetpar* rec
		) {
	return 0;
};

ubigint TblWznmAMMethodRetpar::insertNewRec(
			WznmAMMethodRetpar** rec
			, const ubigint mtdRefWznmMMethod
			, const uint mtdNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const uint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMMethodRetpar* _rec = NULL;

	_rec = new WznmAMMethodRetpar(0, mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMMethodRetpar::appendNewRecToRst(
			ListWznmAMMethodRetpar& rst
			, WznmAMMethodRetpar** rec
			, const ubigint mtdRefWznmMMethod
			, const uint mtdNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const uint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMMethodRetpar* _rec = NULL;

	retval = insertNewRec(&_rec, mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMMethodRetpar::insertRst(
			ListWznmAMMethodRetpar& rst
			, bool transact
		) {
};

void TblWznmAMMethodRetpar::updateRec(
			WznmAMMethodRetpar* rec
		) {
};

void TblWznmAMMethodRetpar::updateRst(
			ListWznmAMMethodRetpar& rst
			, bool transact
		) {
};

void TblWznmAMMethodRetpar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMMethodRetpar::loadRecByRef(
			ubigint ref
			, WznmAMMethodRetpar** rec
		) {
	return false;
};

ubigint TblWznmAMMethodRetpar::loadRefsByMtd(
			ubigint mtdRefWznmMMethod
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMMethodRetpar::loadRstByMtd(
			ubigint mtdRefWznmMMethod
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	return 0;
};

ubigint TblWznmAMMethodRetpar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	ubigint numload = 0;
	WznmAMMethodRetpar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMMethodRetpar
 ******************************************************************************/

MyTblWznmAMMethodRetpar::MyTblWznmAMMethodRetpar() :
			TblWznmAMMethodRetpar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMMethodRetpar::~MyTblWznmAMMethodRetpar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMMethodRetpar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMMethodRetpar (mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMMethodRetpar SET mtdRefWznmMMethod = ?, mtdNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Length = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMMethodRetpar WHERE ref = ?", false);
};

bool MyTblWznmAMMethodRetpar::loadRecBySQL(
			const string& sqlstr
			, WznmAMMethodRetpar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMMethodRetpar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMethodRetpar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMethodRetpar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMMethodRetpar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->mtdRefWznmMMethod = atoll((char*) dbrow[1]); else _rec->mtdRefWznmMMethod = 0;
		if (dbrow[2]) _rec->mtdNum = atol((char*) dbrow[2]); else _rec->mtdNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixWznmVVartype = atol((char*) dbrow[4]); else _rec->ixWznmVVartype = 0;
		if (dbrow[5]) _rec->refWznmMVector = atoll((char*) dbrow[5]); else _rec->refWznmMVector = 0;
		if (dbrow[6]) _rec->Length = atol((char*) dbrow[6]); else _rec->Length = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMMethodRetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMMethodRetpar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMMethodRetpar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMMethodRetpar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMMethodRetpar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->mtdRefWznmMMethod = atoll((char*) dbrow[1]); else rec->mtdRefWznmMMethod = 0;
			if (dbrow[2]) rec->mtdNum = atol((char*) dbrow[2]); else rec->mtdNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixWznmVVartype = atol((char*) dbrow[4]); else rec->ixWznmVVartype = 0;
			if (dbrow[5]) rec->refWznmMVector = atoll((char*) dbrow[5]); else rec->refWznmMVector = 0;
			if (dbrow[6]) rec->Length = atol((char*) dbrow[6]); else rec->Length = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMMethodRetpar::insertRec(
			WznmAMMethodRetpar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->mtdRefWznmMMethod,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->mtdNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVVartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMMethodRetpar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMMethodRetpar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMMethodRetpar::insertRst(
			ListWznmAMMethodRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMMethodRetpar::updateRec(
			WznmAMMethodRetpar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->mtdRefWznmMMethod,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->mtdNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWznmVVartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMMethodRetpar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMMethodRetpar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMMethodRetpar::updateRst(
			ListWznmAMMethodRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMMethodRetpar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMMethodRetpar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMMethodRetpar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMMethodRetpar::loadRecByRef(
			ubigint ref
			, WznmAMMethodRetpar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMMethodRetpar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMMethodRetpar::loadRefsByMtd(
			ubigint mtdRefWznmMMethod
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMMethodRetpar WHERE mtdRefWznmMMethod = " + to_string(mtdRefWznmMMethod) + "", append, refs);
};

ubigint MyTblWznmAMMethodRetpar::loadRstByMtd(
			ubigint mtdRefWznmMMethod
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	return loadRstBySQL("SELECT ref, mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment FROM TblWznmAMMethodRetpar WHERE mtdRefWznmMMethod = " + to_string(mtdRefWznmMMethod) + " ORDER BY mtdNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMMethodRetpar
 ******************************************************************************/

PgTblWznmAMMethodRetpar::PgTblWznmAMMethodRetpar() :
			TblWznmAMMethodRetpar()
			, PgTable()
		{
};

PgTblWznmAMMethodRetpar::~PgTblWznmAMMethodRetpar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMMethodRetpar::initStatements() {
	createStatement("TblWznmAMMethodRetpar_insertRec", "INSERT INTO TblWznmAMMethodRetpar (mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmAMMethodRetpar_updateRec", "UPDATE TblWznmAMMethodRetpar SET mtdRefWznmMMethod = $1, mtdNum = $2, sref = $3, ixWznmVVartype = $4, refWznmMVector = $5, Length = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmAMMethodRetpar_removeRecByRef", "DELETE FROM TblWznmAMMethodRetpar WHERE ref = $1", 1);

	createStatement("TblWznmAMMethodRetpar_loadRecByRef", "SELECT ref, mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment FROM TblWznmAMMethodRetpar WHERE ref = $1", 1);
	createStatement("TblWznmAMMethodRetpar_loadRefsByMtd", "SELECT ref FROM TblWznmAMMethodRetpar WHERE mtdRefWznmMMethod = $1", 1);
	createStatement("TblWznmAMMethodRetpar_loadRstByMtd", "SELECT ref, mtdRefWznmMMethod, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment FROM TblWznmAMMethodRetpar WHERE mtdRefWznmMMethod = $1 ORDER BY mtdNum ASC", 1);
};

bool PgTblWznmAMMethodRetpar::loadRec(
			PGresult* res
			, WznmAMMethodRetpar** rec
		) {
	char* ptr;

	WznmAMMethodRetpar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMMethodRetpar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "mtdrefwznmmmethod"),
			PQfnumber(res, "mtdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->mtdRefWznmMMethod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->mtdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Length = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMMethodRetpar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMMethodRetpar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "mtdrefwznmmmethod"),
			PQfnumber(res, "mtdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMMethodRetpar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->mtdRefWznmMMethod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->mtdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Length = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMMethodRetpar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMMethodRetpar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMethodRetpar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMMethodRetpar::loadRecBySQL(
			const string& sqlstr
			, WznmAMMethodRetpar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMMethodRetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMMethodRetpar::insertRec(
			WznmAMMethodRetpar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _mtdRefWznmMMethod = htonl64(rec->mtdRefWznmMMethod);
	uint _mtdNum = htonl(rec->mtdNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);

	const char* vals[] = {
		(char*) &_mtdRefWznmMMethod,
		(char*) &_mtdNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMMethodRetpar_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMMethodRetpar::insertRst(
			ListWznmAMMethodRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMMethodRetpar::updateRec(
			WznmAMMethodRetpar* rec
		) {
	PGresult* res;

	ubigint _mtdRefWznmMMethod = htonl64(rec->mtdRefWznmMMethod);
	uint _mtdNum = htonl(rec->mtdNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_mtdRefWznmMMethod,
		(char*) &_mtdNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMMethodRetpar_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMMethodRetpar::updateRst(
			ListWznmAMMethodRetpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMMethodRetpar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMMethodRetpar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMMethodRetpar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMMethodRetpar::loadRecByRef(
			ubigint ref
			, WznmAMMethodRetpar** rec
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

	return loadRecByStmt("TblWznmAMMethodRetpar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMMethodRetpar::loadRefsByMtd(
			ubigint mtdRefWznmMMethod
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _mtdRefWznmMMethod = htonl64(mtdRefWznmMMethod);

	const char* vals[] = {
		(char*) &_mtdRefWznmMMethod
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMMethodRetpar_loadRefsByMtd", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMMethodRetpar::loadRstByMtd(
			ubigint mtdRefWznmMMethod
			, const bool append
			, ListWznmAMMethodRetpar& rst
		) {
	ubigint _mtdRefWznmMMethod = htonl64(mtdRefWznmMMethod);

	const char* vals[] = {
		(char*) &_mtdRefWznmMMethod
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMMethodRetpar_loadRstByMtd", 1, vals, l, f, append, rst);
};

#endif

