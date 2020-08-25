/**
	* \file WznmAMLibraryMakefile.cpp
	* database access for table TblWznmAMLibraryMakefile (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmAMLibraryMakefile.h"

#include "WznmAMLibraryMakefile_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMLibraryMakefile
 ******************************************************************************/

WznmAMLibraryMakefile::WznmAMLibraryMakefile(
			const ubigint ref
			, const ubigint refWznmMLibrary
			, const uint x1RefIxVTbl
			, const ubigint x1RefUref
			, const string x2SrefKTag
			, const string Val
		) {

	this->ref = ref;
	this->refWznmMLibrary = refWznmMLibrary;
	this->x1RefIxVTbl = x1RefIxVTbl;
	this->x1RefUref = x1RefUref;
	this->x2SrefKTag = x2SrefKTag;
	this->Val = Val;
};

bool WznmAMLibraryMakefile::operator==(
			const WznmAMLibraryMakefile& comp
		) {
	return false;
};

bool WznmAMLibraryMakefile::operator!=(
			const WznmAMLibraryMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMLibraryMakefile
 ******************************************************************************/

ListWznmAMLibraryMakefile::ListWznmAMLibraryMakefile() {
};

ListWznmAMLibraryMakefile::ListWznmAMLibraryMakefile(
			const ListWznmAMLibraryMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMLibraryMakefile(*(src.nodes[i]));
};

ListWznmAMLibraryMakefile::~ListWznmAMLibraryMakefile() {
	clear();
};

void ListWznmAMLibraryMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMLibraryMakefile::size() const {
	return(nodes.size());
};

void ListWznmAMLibraryMakefile::append(
			WznmAMLibraryMakefile* rec
		) {
	nodes.push_back(rec);
};

WznmAMLibraryMakefile* ListWznmAMLibraryMakefile::operator[](
			const uint ix
		) {
	WznmAMLibraryMakefile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMLibraryMakefile& ListWznmAMLibraryMakefile::operator=(
			const ListWznmAMLibraryMakefile& src
		) {
	WznmAMLibraryMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMLibraryMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMLibraryMakefile::operator==(
			const ListWznmAMLibraryMakefile& comp
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

bool ListWznmAMLibraryMakefile::operator!=(
			const ListWznmAMLibraryMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMLibraryMakefile
 ******************************************************************************/

TblWznmAMLibraryMakefile::TblWznmAMLibraryMakefile() {
};

TblWznmAMLibraryMakefile::~TblWznmAMLibraryMakefile() {
};

bool TblWznmAMLibraryMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMLibraryMakefile** rec
		) {
	return false;
};

ubigint TblWznmAMLibraryMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	return 0;
};

ubigint TblWznmAMLibraryMakefile::insertRec(
			WznmAMLibraryMakefile* rec
		) {
	return 0;
};

ubigint TblWznmAMLibraryMakefile::insertNewRec(
			WznmAMLibraryMakefile** rec
			, const ubigint refWznmMLibrary
			, const uint x1RefIxVTbl
			, const ubigint x1RefUref
			, const string x2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMLibraryMakefile* _rec = NULL;

	_rec = new WznmAMLibraryMakefile(0, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMLibraryMakefile::appendNewRecToRst(
			ListWznmAMLibraryMakefile& rst
			, WznmAMLibraryMakefile** rec
			, const ubigint refWznmMLibrary
			, const uint x1RefIxVTbl
			, const ubigint x1RefUref
			, const string x2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmAMLibraryMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMLibraryMakefile::insertRst(
			ListWznmAMLibraryMakefile& rst
			, bool transact
		) {
};

void TblWznmAMLibraryMakefile::updateRec(
			WznmAMLibraryMakefile* rec
		) {
};

void TblWznmAMLibraryMakefile::updateRst(
			ListWznmAMLibraryMakefile& rst
			, bool transact
		) {
};

void TblWznmAMLibraryMakefile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMLibraryMakefile::loadRecByRef(
			ubigint ref
			, WznmAMLibraryMakefile** rec
		) {
	return false;
};

ubigint TblWznmAMLibraryMakefile::loadRefsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMLibraryMakefile::loadRstByLib(
			ubigint refWznmMLibrary
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	return 0;
};

ubigint TblWznmAMLibraryMakefile::loadRstByLibRetReu(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	return 0;
};

bool TblWznmAMLibraryMakefile::loadValByLibRetReuTag(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, string x2SrefKTag
			, string& Val
		) {
	return false;
};

ubigint TblWznmAMLibraryMakefile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	ubigint numload = 0;
	WznmAMLibraryMakefile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMLibraryMakefile
 ******************************************************************************/

MyTblWznmAMLibraryMakefile::MyTblWznmAMLibraryMakefile() :
			TblWznmAMLibraryMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMLibraryMakefile::~MyTblWznmAMLibraryMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMLibraryMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMLibraryMakefile (refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMLibraryMakefile SET refWznmMLibrary = ?, x1RefIxVTbl = ?, x1RefUref = ?, x2SrefKTag = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMLibraryMakefile WHERE ref = ?", false);
};

bool MyTblWznmAMLibraryMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMLibraryMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMLibraryMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMLibraryMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMLibraryMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMLibraryMakefile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMLibrary = atoll((char*) dbrow[1]); else _rec->refWznmMLibrary = 0;
		if (dbrow[2]) _rec->x1RefIxVTbl = atol((char*) dbrow[2]); else _rec->x1RefIxVTbl = 0;
		if (dbrow[3]) _rec->x1RefUref = atoll((char*) dbrow[3]); else _rec->x1RefUref = 0;
		if (dbrow[4]) _rec->x2SrefKTag.assign(dbrow[4], dblengths[4]); else _rec->x2SrefKTag = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMLibraryMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMLibraryMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMLibraryMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMLibraryMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMLibraryMakefile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMLibrary = atoll((char*) dbrow[1]); else rec->refWznmMLibrary = 0;
			if (dbrow[2]) rec->x1RefIxVTbl = atol((char*) dbrow[2]); else rec->x1RefIxVTbl = 0;
			if (dbrow[3]) rec->x1RefUref = atoll((char*) dbrow[3]); else rec->x1RefUref = 0;
			if (dbrow[4]) rec->x2SrefKTag.assign(dbrow[4], dblengths[4]); else rec->x2SrefKTag = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMLibraryMakefile::insertRec(
			WznmAMLibraryMakefile* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x2SrefKTag.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1RefIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMLibraryMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMLibraryMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMLibraryMakefile::insertRst(
			ListWznmAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMLibraryMakefile::updateRec(
			WznmAMLibraryMakefile* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x2SrefKTag.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1RefIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x1RefUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMLibraryMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMLibraryMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMLibraryMakefile::updateRst(
			ListWznmAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMLibraryMakefile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMLibraryMakefile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMLibraryMakefile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMLibraryMakefile::loadRecByRef(
			ubigint ref
			, WznmAMLibraryMakefile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMLibraryMakefile WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMLibraryMakefile::loadRefsByLib(
			ubigint refWznmMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + "", append, refs);
};

ubigint MyTblWznmAMLibraryMakefile::loadRstByLib(
			ubigint refWznmMLibrary
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + " ORDER BY x2SrefKTag ASC", append, rst);
};

ubigint MyTblWznmAMLibraryMakefile::loadRstByLibRetReu(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + " AND x1RefIxVTbl = " + to_string(x1RefIxVTbl) + " AND x1RefUref = " + to_string(x1RefUref) + " ORDER BY x2SrefKTag ASC", append, rst);
};

bool MyTblWznmAMLibraryMakefile::loadValByLibRetReuTag(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, string x2SrefKTag
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = " + to_string(refWznmMLibrary) + " AND x1RefIxVTbl = " + to_string(x1RefIxVTbl) + " AND x1RefUref = " + to_string(x1RefUref) + " AND x2SrefKTag = '" + x2SrefKTag + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMLibraryMakefile
 ******************************************************************************/

PgTblWznmAMLibraryMakefile::PgTblWznmAMLibraryMakefile() :
			TblWznmAMLibraryMakefile()
			, PgTable()
		{
};

PgTblWznmAMLibraryMakefile::~PgTblWznmAMLibraryMakefile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMLibraryMakefile::initStatements() {
	createStatement("TblWznmAMLibraryMakefile_insertRec", "INSERT INTO TblWznmAMLibraryMakefile (refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmAMLibraryMakefile_updateRec", "UPDATE TblWznmAMLibraryMakefile SET refWznmMLibrary = $1, x1RefIxVTbl = $2, x1RefUref = $3, x2SrefKTag = $4, Val = $5 WHERE ref = $6", 6);
	createStatement("TblWznmAMLibraryMakefile_removeRecByRef", "DELETE FROM TblWznmAMLibraryMakefile WHERE ref = $1", 1);

	createStatement("TblWznmAMLibraryMakefile_loadRecByRef", "SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val FROM TblWznmAMLibraryMakefile WHERE ref = $1", 1);
	createStatement("TblWznmAMLibraryMakefile_loadRefsByLib", "SELECT ref FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = $1", 1);
	createStatement("TblWznmAMLibraryMakefile_loadRstByLib", "SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = $1 ORDER BY x2SrefKTag ASC", 1);
	createStatement("TblWznmAMLibraryMakefile_loadRstByLibRetReu", "SELECT ref, refWznmMLibrary, x1RefIxVTbl, x1RefUref, x2SrefKTag, Val FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = $1 AND x1RefIxVTbl = $2 AND x1RefUref = $3 ORDER BY x2SrefKTag ASC", 3);
	createStatement("TblWznmAMLibraryMakefile_loadValByLibRetReuTag", "SELECT Val FROM TblWznmAMLibraryMakefile WHERE refWznmMLibrary = $1 AND x1RefIxVTbl = $2 AND x1RefUref = $3 AND x2SrefKTag = $4", 4);
};

bool PgTblWznmAMLibraryMakefile::loadRec(
			PGresult* res
			, WznmAMLibraryMakefile** rec
		) {
	char* ptr;

	WznmAMLibraryMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMLibraryMakefile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlibrary"),
			PQfnumber(res, "x1refixvtbl"),
			PQfnumber(res, "x1refuref"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMLibrary = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1RefUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMLibraryMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMLibraryMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmlibrary"),
			PQfnumber(res, "x1refixvtbl"),
			PQfnumber(res, "x1refuref"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAMLibraryMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMLibrary = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1RefUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMLibraryMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMLibraryMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMLibraryMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMLibraryMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmAMLibraryMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMLibraryMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMLibraryMakefile::insertRec(
			WznmAMLibraryMakefile* rec
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
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMLibraryMakefile_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMLibraryMakefile::insertRst(
			ListWznmAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMLibraryMakefile::updateRec(
			WznmAMLibraryMakefile* rec
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
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMLibraryMakefile_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMLibraryMakefile::updateRst(
			ListWznmAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMLibraryMakefile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMLibraryMakefile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMLibraryMakefile::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMLibraryMakefile::loadRecByRef(
			ubigint ref
			, WznmAMLibraryMakefile** rec
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

	return loadRecByStmt("TblWznmAMLibraryMakefile_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMLibraryMakefile::loadRefsByLib(
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

	return loadRefsByStmt("TblWznmAMLibraryMakefile_loadRefsByLib", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMLibraryMakefile::loadRstByLib(
			ubigint refWznmMLibrary
			, const bool append
			, ListWznmAMLibraryMakefile& rst
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);

	const char* vals[] = {
		(char*) &_refWznmMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMLibraryMakefile_loadRstByLib", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMLibraryMakefile::loadRstByLibRetReu(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, const bool append
			, ListWznmAMLibraryMakefile& rst
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

	return loadRstByStmt("TblWznmAMLibraryMakefile_loadRstByLibRetReu", 3, vals, l, f, append, rst);
};

bool PgTblWznmAMLibraryMakefile::loadValByLibRetReuTag(
			ubigint refWznmMLibrary
			, uint x1RefIxVTbl
			, ubigint x1RefUref
			, string x2SrefKTag
			, string& Val
		) {
	ubigint _refWznmMLibrary = htonl64(refWznmMLibrary);
	uint _x1RefIxVTbl = htonl(x1RefIxVTbl);
	ubigint _x1RefUref = htonl64(x1RefUref);

	const char* vals[] = {
		(char*) &_refWznmMLibrary,
		(char*) &_x1RefIxVTbl,
		(char*) &_x1RefUref,
		x2SrefKTag.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadStringByStmt("TblWznmAMLibraryMakefile_loadValByLibRetReuTag", 4, vals, l, f, Val);
};

#endif

