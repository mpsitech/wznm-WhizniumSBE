/**
	* \file WznmAMLibraryPkglist.cpp
	* database access for table TblWznmAMLibraryPkglist (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAMLibraryPkglist.h"

#include "WznmAMLibraryPkglist_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMLibraryPkglist
 ******************************************************************************/

WznmAMLibraryPkglist::WznmAMLibraryPkglist(
			const ubigint ref
			, const ubigint refWznmMLibrary
			, const uint x1RefIxVTbl
			, const ubigint x1RefUref
			, const string Pkglist
		) {

	this->ref = ref;
	this->refWznmMLibrary = refWznmMLibrary;
	this->x1RefIxVTbl = x1RefIxVTbl;
	this->x1RefUref = x1RefUref;
	this->Pkglist = Pkglist;
};

bool WznmAMLibraryPkglist::operator==(
			const WznmAMLibraryPkglist& comp
		) {
	return false;
};

bool WznmAMLibraryPkglist::operator!=(
			const WznmAMLibraryPkglist& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMLibraryPkglist
 ******************************************************************************/

ListWznmAMLibraryPkglist::ListWznmAMLibraryPkglist() {
};

ListWznmAMLibraryPkglist::ListWznmAMLibraryPkglist(
			const ListWznmAMLibraryPkglist& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMLibraryPkglist(*(src.nodes[i]));
};

ListWznmAMLibraryPkglist::~ListWznmAMLibraryPkglist() {
	clear();
};

void ListWznmAMLibraryPkglist::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMLibraryPkglist::size() const {
	return(nodes.size());
};

void ListWznmAMLibraryPkglist::append(
			WznmAMLibraryPkglist* rec
		) {
	nodes.push_back(rec);
};

WznmAMLibraryPkglist* ListWznmAMLibraryPkglist::operator[](
			const uint ix
		) {
	WznmAMLibraryPkglist* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMLibraryPkglist& ListWznmAMLibraryPkglist::operator=(
			const ListWznmAMLibraryPkglist& src
		) {
	WznmAMLibraryPkglist* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMLibraryPkglist(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMLibraryPkglist::operator==(
			const ListWznmAMLibraryPkglist& comp
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

bool ListWznmAMLibraryPkglist::operator!=(
			const ListWznmAMLibraryPkglist& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMLibraryPkglist
 ******************************************************************************/

TblWznmAMLibraryPkglist::TblWznmAMLibraryPkglist() {
};

TblWznmAMLibraryPkglist::~TblWznmAMLibraryPkglist() {
};

bool TblWznmAMLibraryPkglist::loadRecBySQL(
			const string& sqlstr
			, WznmAMLibraryPkglist** rec
		) {
	return false;
};

ubigint TblWznmAMLibraryPkglist::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	return 0;
};

ubigint TblWznmAMLibraryPkglist::insertRec(
			WznmAMLibraryPkglist* rec
		) {
	return 0;
};

ubigint TblWznmAMLibraryPkglist::insertNewRec(
			WznmAMLibraryPkglist** rec
			, const ubigint refWznmMLibrary
			, const uint x1RefIxVTbl
			, const ubigint x1RefUref
			, const string Pkglist
		) {
	ubigint retval = 0;
	WznmAMLibraryPkglist* _rec = NULL;

	_rec = new WznmAMLibraryPkglist(0, refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMLibraryPkglist::appendNewRecToRst(
			ListWznmAMLibraryPkglist& rst
			, WznmAMLibraryPkglist** rec
			, const ubigint refWznmMLibrary
			, const uint x1RefIxVTbl
			, const ubigint x1RefUref
			, const string Pkglist
		) {
	ubigint retval = 0;
	WznmAMLibraryPkglist* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMLibraryPkglist::insertRst(
			ListWznmAMLibraryPkglist& rst
			, bool transact
		) {
};

void TblWznmAMLibraryPkglist::updateRec(
			WznmAMLibraryPkglist* rec
		) {
};

void TblWznmAMLibraryPkglist::updateRst(
			ListWznmAMLibraryPkglist& rst
			, bool transact
		) {
};

void TblWznmAMLibraryPkglist::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMLibraryPkglist::loadRecByRef(
			ubigint ref
			, WznmAMLibraryPkglist** rec
		) {
	return false;
};

bool TblWznmAMLibraryPkglist::loadPklByLibRetReu(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, string& Pkglist
		) {
	return false;
};

ubigint TblWznmAMLibraryPkglist::loadRefsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMLibraryPkglist::loadRstByLib(
			ubigint refWznmMLibrary
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	return 0;
};

ubigint TblWznmAMLibraryPkglist::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	ubigint numload = 0;
	WznmAMLibraryPkglist* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMLibraryPkglist
 ******************************************************************************/

MyTblWznmAMLibraryPkglist::MyTblWznmAMLibraryPkglist() :
			TblWznmAMLibraryPkglist()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMLibraryPkglist::~MyTblWznmAMLibraryPkglist() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMLibraryPkglist::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMLibraryPkglist (refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMLibraryPkglist SET refWznmMLibrary = ?, x1RefIxVTbl = ?, x1RefUref = ?, Pkglist = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMLibraryPkglist WHERE ref = ?", false);
};

bool MyTblWznmAMLibraryPkglist::loadRecBySQL(
			const string& sqlstr
			, WznmAMLibraryPkglist** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMLibraryPkglist* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMLibraryPkglist::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMLibraryPkglist::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMLibraryPkglist();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMLibrary = atoll((char*) dbrow[1]); else _rec->refWznmMLibrary = 0;
		if (dbrow[2]) _rec->x1RefIxVTbl = atol((char*) dbrow[2]); else _rec->x1RefIxVTbl = 0;
		if (dbrow[3]) _rec->x1RefUref = atoll((char*) dbrow[3]); else _rec->x1RefUref = 0;
		if (dbrow[4]) _rec->Pkglist.assign(dbrow[4], dblengths[4]); else _rec->Pkglist = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMLibraryPkglist::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMLibraryPkglist* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMLibraryPkglist::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMLibraryPkglist::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMLibraryPkglist();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMLibrary = atoll((char*) dbrow[1]); else rec->refWznmMLibrary = 0;
			if (dbrow[2]) rec->x1RefIxVTbl = atol((char*) dbrow[2]); else rec->x1RefIxVTbl = 0;
			if (dbrow[3]) rec->x1RefUref = atoll((char*) dbrow[3]); else rec->x1RefUref = 0;
			if (dbrow[4]) rec->Pkglist.assign(dbrow[4], dblengths[4]); else rec->Pkglist = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMLibraryPkglist::insertRec(
			WznmAMLibraryPkglist* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Pkglist.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1RefIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Pkglist.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMLibraryPkglist::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMLibraryPkglist::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMLibraryPkglist::insertRst(
			ListWznmAMLibraryPkglist& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMLibraryPkglist::updateRec(
			WznmAMLibraryPkglist* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Pkglist.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1RefIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Pkglist.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMLibraryPkglist::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMLibraryPkglist::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMLibraryPkglist::updateRst(
			ListWznmAMLibraryPkglist& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMLibraryPkglist::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMLibraryPkglist::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMLibraryPkglist::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMLibraryPkglist::loadRecByRef(
			ubigint ref
			, WznmAMLibraryPkglist** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMLibraryPkglist WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmAMLibraryPkglist::loadPklByLibRetReu(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, string& Pkglist
		) {
	return loadStringBySQL("SELECT Pkglist FROM TblWznmAMLibraryPkglist WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + " AND x1RefIxVTbl = " + to_string(x1RefIxVTbl) + " AND x1RefUref = " + to_string(x1RefUref) + "", Pkglist);
};

ubigint MyTblWznmAMLibraryPkglist::loadRefsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMLibraryPkglist WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + "", append, refs);
};

ubigint MyTblWznmAMLibraryPkglist::loadRstByLib(
			ubigint refWznmMLibrary
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist FROM TblWznmAMLibraryPkglist WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMLibraryPkglist
 ******************************************************************************/

PgTblWznmAMLibraryPkglist::PgTblWznmAMLibraryPkglist() :
			TblWznmAMLibraryPkglist()
			, PgTable()
		{
};

PgTblWznmAMLibraryPkglist::~PgTblWznmAMLibraryPkglist() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMLibraryPkglist::initStatements() {
	createStatement("TblWznmAMLibraryPkglist_insertRec", "INSERT INTO TblWznmAMLibraryPkglist (refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMLibraryPkglist_updateRec", "UPDATE TblWznmAMLibraryPkglist SET refWznmMLibrary = $1, x1RefIxVTbl = $2, x1RefUref = $3, Pkglist = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMLibraryPkglist_removeRecByRef", "DELETE FROM TblWznmAMLibraryPkglist WHERE ref = $1", 1);

	createStatement("TblWznmAMLibraryPkglist_loadRecByRef", "SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist FROM TblWznmAMLibraryPkglist WHERE ref = $1", 1);
	createStatement("TblWznmAMLibraryPkglist_loadPklByLibRetReu", "SELECT Pkglist FROM TblWznmAMLibraryPkglist WHERE refWznmMLibrary = $1 AND x1RefIxVTbl = $2 AND x1RefUref = $3", 3);
	createStatement("TblWznmAMLibraryPkglist_loadRefsByLib", "SELECT ref FROM TblWznmAMLibraryPkglist WHERE refWznmMLibrary = $1", 1);
	createStatement("TblWznmAMLibraryPkglist_loadRstByLib", "SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, Pkglist FROM TblWznmAMLibraryPkglist WHERE refWznmMLibrary = $1", 1);
};

bool PgTblWznmAMLibraryPkglist::loadRec(
			PGresult* res
			, WznmAMLibraryPkglist** rec
		) {
	char* ptr;

	WznmAMLibraryPkglist* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMLibraryPkglist();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlibrary"),
			PQfnumber(res, "x1refixvtbl"),
			PQfnumber(res, "x1refuref"),
			PQfnumber(res, "pkglist")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMLibrary = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1RefUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Pkglist.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMLibraryPkglist::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMLibraryPkglist* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlibrary"),
			PQfnumber(res, "x1refixvtbl"),
			PQfnumber(res, "x1refuref"),
			PQfnumber(res, "pkglist")
		};

		while (numread < numrow) {
			rec = new WznmAMLibraryPkglist();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMLibrary = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1RefUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Pkglist.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMLibraryPkglist::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMLibraryPkglist** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMLibraryPkglist::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMLibraryPkglist::loadRecBySQL(
			const string& sqlstr
			, WznmAMLibraryPkglist** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMLibraryPkglist::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMLibraryPkglist::insertRec(
			WznmAMLibraryPkglist* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMLibrary = htonl64(rec->refWznmMLibrary);
	uint _x1RefIxVTbl = htonl(rec->x1RefIxVTbl);
	ubigint _x1RefUref = htonl64(rec->x1RefUref);

	const char* vals[] = {
		(char*) &_refWznmMLibrary,
		(char*) &_x1RefIxVTbl,
		(char*) &_x1RefUref,
		rec->Pkglist.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMLibraryPkglist_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMLibraryPkglist::insertRst(
			ListWznmAMLibraryPkglist& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMLibraryPkglist::updateRec(
			WznmAMLibraryPkglist* rec
		) {
	PGresult* res;

	ubigint _refWznmMLibrary = htonl64(rec->refWznmMLibrary);
	uint _x1RefIxVTbl = htonl(rec->x1RefIxVTbl);
	ubigint _x1RefUref = htonl64(rec->x1RefUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMLibrary,
		(char*) &_x1RefIxVTbl,
		(char*) &_x1RefUref,
		rec->Pkglist.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMLibraryPkglist_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMLibraryPkglist::updateRst(
			ListWznmAMLibraryPkglist& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMLibraryPkglist::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMLibraryPkglist_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMLibraryPkglist::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMLibraryPkglist::loadRecByRef(
			ubigint ref
			, WznmAMLibraryPkglist** rec
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

	return loadRecByStmt("TblWznmAMLibraryPkglist_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmAMLibraryPkglist::loadPklByLibRetReu(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, string& Pkglist
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);
	uint _x1RefIxVTbl = htonl(x1RefIxVTbl);
	ubigint _x1RefUref = htonl64(x1RefUref);

	const char* vals[] = {
		(char*) &_refWznmMLibrary,
		(char*) &_x1RefIxVTbl,
		(char*) &_x1RefUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadStringByStmt("TblWznmAMLibraryPkglist_loadPklByLibRetReu", 3, vals, l, f, Pkglist);
};

ubigint PgTblWznmAMLibraryPkglist::loadRefsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);

	const char* vals[] = {
		(char*) &_refWznmMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMLibraryPkglist_loadRefsByLib", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMLibraryPkglist::loadRstByLib(
			ubigint refWznmMLibrary
			, const bool append
			, ListWznmAMLibraryPkglist& rst
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);

	const char* vals[] = {
		(char*) &_refWznmMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMLibraryPkglist_loadRstByLib", 1, vals, l, f, append, rst);
};

#endif

