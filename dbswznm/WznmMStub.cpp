/**
	* \file WznmMStub.cpp
	* database access for table TblWznmMStub (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMStub.h"

#include "WznmMStub_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMStub
 ******************************************************************************/

WznmMStub::WznmMStub(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const string sref
			, const bool Hierarch
			, const ubigint refWznmMTablecol
			, const bool Localized
			, const string Example
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMTable = refWznmMTable;
	this->refWznmMSubset = refWznmMSubset;
	this->sref = sref;
	this->Hierarch = Hierarch;
	this->refWznmMTablecol = refWznmMTablecol;
	this->Localized = Localized;
	this->Example = Example;
};

bool WznmMStub::operator==(
			const WznmMStub& comp
		) {
	return false;
};

bool WznmMStub::operator!=(
			const WznmMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMStub
 ******************************************************************************/

ListWznmMStub::ListWznmMStub() {
};

ListWznmMStub::ListWznmMStub(
			const ListWznmMStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMStub(*(src.nodes[i]));
};

ListWznmMStub::~ListWznmMStub() {
	clear();
};

void ListWznmMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMStub::size() const {
	return(nodes.size());
};

void ListWznmMStub::append(
			WznmMStub* rec
		) {
	nodes.push_back(rec);
};

WznmMStub* ListWznmMStub::operator[](
			const uint ix
		) {
	WznmMStub* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMStub& ListWznmMStub::operator=(
			const ListWznmMStub& src
		) {
	WznmMStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMStub::operator==(
			const ListWznmMStub& comp
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

bool ListWznmMStub::operator!=(
			const ListWznmMStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMStub
 ******************************************************************************/

TblWznmMStub::TblWznmMStub() {
};

TblWznmMStub::~TblWznmMStub() {
};

bool TblWznmMStub::loadRecBySQL(
			const string& sqlstr
			, WznmMStub** rec
		) {
	return false;
};

ubigint TblWznmMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMStub& rst
		) {
	return 0;
};

ubigint TblWznmMStub::insertRec(
			WznmMStub* rec
		) {
	return 0;
};

ubigint TblWznmMStub::insertNewRec(
			WznmMStub** rec
			, const uint ixVBasetype
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const string sref
			, const bool Hierarch
			, const ubigint refWznmMTablecol
			, const bool Localized
			, const string Example
		) {
	ubigint retval = 0;
	WznmMStub* _rec = NULL;

	_rec = new WznmMStub(0, ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMStub::appendNewRecToRst(
			ListWznmMStub& rst
			, WznmMStub** rec
			, const uint ixVBasetype
			, const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const string sref
			, const bool Hierarch
			, const ubigint refWznmMTablecol
			, const bool Localized
			, const string Example
		) {
	ubigint retval = 0;
	WznmMStub* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMStub::insertRst(
			ListWznmMStub& rst
			, bool transact
		) {
};

void TblWznmMStub::updateRec(
			WznmMStub* rec
		) {
};

void TblWznmMStub::updateRst(
			ListWznmMStub& rst
			, bool transact
		) {
};

void TblWznmMStub::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMStub::loadRecByRef(
			ubigint ref
			, WznmMStub** rec
		) {
	return false;
};

ubigint TblWznmMStub::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMStub& rst
		) {
	return 0;
};

bool TblWznmMStub::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMStub::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMStub& rst
		) {
	ubigint numload = 0;
	WznmMStub* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMStub
 ******************************************************************************/

MyTblWznmMStub::MyTblWznmMStub() :
			TblWznmMStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMStub::~MyTblWznmMStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMStub (ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMStub SET ixVBasetype = ?, refWznmMTable = ?, refWznmMSubset = ?, sref = ?, Hierarch = ?, refWznmMTablecol = ?, Localized = ?, Example = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMStub WHERE ref = ?", false);
};

bool MyTblWznmMStub::loadRecBySQL(
			const string& sqlstr
			, WznmMStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMStub();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMTable = atoll((char*) dbrow[2]); else _rec->refWznmMTable = 0;
		if (dbrow[3]) _rec->refWznmMSubset = atoll((char*) dbrow[3]); else _rec->refWznmMSubset = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Hierarch = (atoi((char*) dbrow[5]) != 0); else _rec->Hierarch = false;
		if (dbrow[6]) _rec->refWznmMTablecol = atoll((char*) dbrow[6]); else _rec->refWznmMTablecol = 0;
		if (dbrow[7]) _rec->Localized = (atoi((char*) dbrow[7]) != 0); else _rec->Localized = false;
		if (dbrow[8]) _rec->Example.assign(dbrow[8], dblengths[8]); else _rec->Example = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMStub();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMTable = atoll((char*) dbrow[2]); else rec->refWznmMTable = 0;
			if (dbrow[3]) rec->refWznmMSubset = atoll((char*) dbrow[3]); else rec->refWznmMSubset = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Hierarch = (atoi((char*) dbrow[5]) != 0); else rec->Hierarch = false;
			if (dbrow[6]) rec->refWznmMTablecol = atoll((char*) dbrow[6]); else rec->refWznmMTablecol = 0;
			if (dbrow[7]) rec->Localized = (atoi((char*) dbrow[7]) != 0); else rec->Localized = false;
			if (dbrow[8]) rec->Example.assign(dbrow[8], dblengths[8]); else rec->Example = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMStub::insertRec(
			WznmMStub* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	tinyint Hierarch = rec->Hierarch;
	tinyint Localized = rec->Localized;
	l[7] = rec->Example.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMSubset,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Hierarch,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMTablecol,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Localized,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Example.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMStub::insertRst(
			ListWznmMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMStub::updateRec(
			WznmMStub* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	tinyint Hierarch = rec->Hierarch;
	tinyint Localized = rec->Localized;
	l[7] = rec->Example.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMTable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMSubset,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Hierarch,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMTablecol,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Localized,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Example.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMStub::updateRst(
			ListWznmMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMStub::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMStub::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMStub::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMStub::loadRecByRef(
			ubigint ref
			, WznmMStub** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMStub WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMStub::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMStub& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example FROM TblWznmMStub WHERE refWznmMTable = " + to_string(refWznmMTable) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMStub::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMStub WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMStub
 ******************************************************************************/

PgTblWznmMStub::PgTblWznmMStub() :
			TblWznmMStub()
			, PgTable()
		{
};

PgTblWznmMStub::~PgTblWznmMStub() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMStub::initStatements() {
	createStatement("TblWznmMStub_insertRec", "INSERT INTO TblWznmMStub (ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMStub_updateRec", "UPDATE TblWznmMStub SET ixVBasetype = $1, refWznmMTable = $2, refWznmMSubset = $3, sref = $4, Hierarch = $5, refWznmMTablecol = $6, Localized = $7, Example = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMStub_removeRecByRef", "DELETE FROM TblWznmMStub WHERE ref = $1", 1);

	createStatement("TblWznmMStub_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example FROM TblWznmMStub WHERE ref = $1", 1);
	createStatement("TblWznmMStub_loadRstByTbl", "SELECT ref, ixVBasetype, refWznmMTable, refWznmMSubset, sref, Hierarch, refWznmMTablecol, Localized, Example FROM TblWznmMStub WHERE refWznmMTable = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMStub_loadSrfByRef", "SELECT sref FROM TblWznmMStub WHERE ref = $1", 1);
};

bool PgTblWznmMStub::loadRec(
			PGresult* res
			, WznmMStub** rec
		) {
	char* ptr;

	WznmMStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMStub();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "hierarch"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "localized"),
			PQfnumber(res, "example")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Hierarch = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMTablecol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Localized = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Example.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmsubset"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "hierarch"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "localized"),
			PQfnumber(res, "example")
		};

		while (numread < numrow) {
			rec = new WznmMStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Hierarch = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMTablecol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Localized = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Example.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMStub::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMStub& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStub::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMStub::loadRecBySQL(
			const string& sqlstr
			, WznmMStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMStub::insertRec(
			WznmMStub* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	smallint _Hierarch = htons((smallint) rec->Hierarch);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	smallint _Localized = htons((smallint) rec->Localized);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMSubset,
		rec->sref.c_str(),
		(char*) &_Hierarch,
		(char*) &_refWznmMTablecol,
		(char*) &_Localized,
		rec->Example.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMStub_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMStub::insertRst(
			ListWznmMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMStub::updateRec(
			WznmMStub* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMSubset = htonl64(rec->refWznmMSubset);
	smallint _Hierarch = htons((smallint) rec->Hierarch);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	smallint _Localized = htons((smallint) rec->Localized);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMSubset,
		rec->sref.c_str(),
		(char*) &_Hierarch,
		(char*) &_refWznmMTablecol,
		(char*) &_Localized,
		rec->Example.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMStub_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMStub::updateRst(
			ListWznmMStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMStub::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMStub_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMStub::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMStub::loadRecByRef(
			ubigint ref
			, WznmMStub** rec
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

	return loadRecByStmt("TblWznmMStub_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMStub::loadRstByTbl(
			ubigint refWznmMTable
			, const bool append
			, ListWznmMStub& rst
		) {
	ubigint _refWznmMTable = htonl64(refWznmMTable);

	const char* vals[] = {
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMStub_loadRstByTbl", 1, vals, l, f, append, rst);
};

bool PgTblWznmMStub::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMStub_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

