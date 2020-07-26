/**
	* \file WznmMRtblock.cpp
	* database access for table TblWznmMRtblock (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMRtblock.h"

#include "WznmMRtblock_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMRtblock
 ******************************************************************************/

WznmMRtblock::WznmMRtblock(
			const ubigint ref
			, const ubigint refWznmMRtjob
			, const uint refIxVTbl
			, const ubigint refUref
			, const string sref
			, const string srcSrefsWznmAMBlockItem
		) {

	this->ref = ref;
	this->refWznmMRtjob = refWznmMRtjob;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->sref = sref;
	this->srcSrefsWznmAMBlockItem = srcSrefsWznmAMBlockItem;
};

bool WznmMRtblock::operator==(
			const WznmMRtblock& comp
		) {
	return false;
};

bool WznmMRtblock::operator!=(
			const WznmMRtblock& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMRtblock
 ******************************************************************************/

ListWznmMRtblock::ListWznmMRtblock() {
};

ListWznmMRtblock::ListWznmMRtblock(
			const ListWznmMRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMRtblock(*(src.nodes[i]));
};

ListWznmMRtblock::~ListWznmMRtblock() {
	clear();
};

void ListWznmMRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMRtblock::size() const {
	return(nodes.size());
};

void ListWznmMRtblock::append(
			WznmMRtblock* rec
		) {
	nodes.push_back(rec);
};

WznmMRtblock* ListWznmMRtblock::operator[](
			const uint ix
		) {
	WznmMRtblock* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMRtblock& ListWznmMRtblock::operator=(
			const ListWznmMRtblock& src
		) {
	WznmMRtblock* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMRtblock(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMRtblock::operator==(
			const ListWznmMRtblock& comp
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

bool ListWznmMRtblock::operator!=(
			const ListWznmMRtblock& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMRtblock
 ******************************************************************************/

TblWznmMRtblock::TblWznmMRtblock() {
};

TblWznmMRtblock::~TblWznmMRtblock() {
};

bool TblWznmMRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmMRtblock** rec
		) {
	return false;
};

ubigint TblWznmMRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtblock& rst
		) {
	return 0;
};

ubigint TblWznmMRtblock::insertRec(
			WznmMRtblock* rec
		) {
	return 0;
};

ubigint TblWznmMRtblock::insertNewRec(
			WznmMRtblock** rec
			, const ubigint refWznmMRtjob
			, const uint refIxVTbl
			, const ubigint refUref
			, const string sref
			, const string srcSrefsWznmAMBlockItem
		) {
	ubigint retval = 0;
	WznmMRtblock* _rec = NULL;

	_rec = new WznmMRtblock(0, refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMRtblock::appendNewRecToRst(
			ListWznmMRtblock& rst
			, WznmMRtblock** rec
			, const ubigint refWznmMRtjob
			, const uint refIxVTbl
			, const ubigint refUref
			, const string sref
			, const string srcSrefsWznmAMBlockItem
		) {
	ubigint retval = 0;
	WznmMRtblock* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMRtblock::insertRst(
			ListWznmMRtblock& rst
			, bool transact
		) {
};

void TblWznmMRtblock::updateRec(
			WznmMRtblock* rec
		) {
};

void TblWznmMRtblock::updateRst(
			ListWznmMRtblock& rst
			, bool transact
		) {
};

void TblWznmMRtblock::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMRtblock::loadRecByRef(
			ubigint ref
			, WznmMRtblock** rec
		) {
	return false;
};

ubigint TblWznmMRtblock::loadRefsByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMRtblock::loadRstByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, ListWznmMRtblock& rst
		) {
	return 0;
};

bool TblWznmMRtblock::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMRtblock::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMRtblock& rst
		) {
	ubigint numload = 0;
	WznmMRtblock* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMRtblock
 ******************************************************************************/

MyTblWznmMRtblock::MyTblWznmMRtblock() :
			TblWznmMRtblock()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMRtblock::~MyTblWznmMRtblock() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMRtblock::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMRtblock (refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMRtblock SET refWznmMRtjob = ?, refIxVTbl = ?, refUref = ?, sref = ?, srcSrefsWznmAMBlockItem = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMRtblock WHERE ref = ?", false);
};

bool MyTblWznmMRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmMRtblock** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMRtblock* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRtblock::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRtblock::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMRtblock();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMRtjob = atoll((char*) dbrow[1]); else _rec->refWznmMRtjob = 0;
		if (dbrow[2]) _rec->refIxVTbl = atol((char*) dbrow[2]); else _rec->refIxVTbl = 0;
		if (dbrow[3]) _rec->refUref = atoll((char*) dbrow[3]); else _rec->refUref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srcSrefsWznmAMBlockItem.assign(dbrow[5], dblengths[5]); else _rec->srcSrefsWznmAMBlockItem = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtblock& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMRtblock* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRtblock::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRtblock::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMRtblock();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMRtjob = atoll((char*) dbrow[1]); else rec->refWznmMRtjob = 0;
			if (dbrow[2]) rec->refIxVTbl = atol((char*) dbrow[2]); else rec->refIxVTbl = 0;
			if (dbrow[3]) rec->refUref = atoll((char*) dbrow[3]); else rec->refUref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srcSrefsWznmAMBlockItem.assign(dbrow[5], dblengths[5]); else rec->srcSrefsWznmAMBlockItem = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMRtblock::insertRec(
			WznmMRtblock* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->sref.length();
	l[4] = rec->srcSrefsWznmAMBlockItem.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMRtjob,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->refIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srcSrefsWznmAMBlockItem.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMRtblock::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMRtblock::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMRtblock::insertRst(
			ListWznmMRtblock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMRtblock::updateRec(
			WznmMRtblock* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	l[4] = rec->srcSrefsWznmAMBlockItem.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMRtjob,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->refIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srcSrefsWznmAMBlockItem.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMRtblock::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMRtblock::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMRtblock::updateRst(
			ListWznmMRtblock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMRtblock::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMRtblock::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMRtblock::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMRtblock::loadRecByRef(
			ubigint ref
			, WznmMRtblock** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMRtblock WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMRtblock::loadRefsByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMRtblock WHERE refWznmMRtjob = " + to_string(refWznmMRtjob) + "", append, refs);
};

ubigint MyTblWznmMRtblock::loadRstByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, ListWznmMRtblock& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem FROM TblWznmMRtblock WHERE refWznmMRtjob = " + to_string(refWznmMRtjob) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMRtblock::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMRtblock WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMRtblock
 ******************************************************************************/

PgTblWznmMRtblock::PgTblWznmMRtblock() :
			TblWznmMRtblock()
			, PgTable()
		{
};

PgTblWznmMRtblock::~PgTblWznmMRtblock() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMRtblock::initStatements() {
	createStatement("TblWznmMRtblock_insertRec", "INSERT INTO TblWznmMRtblock (refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMRtblock_updateRec", "UPDATE TblWznmMRtblock SET refWznmMRtjob = $1, refIxVTbl = $2, refUref = $3, sref = $4, srcSrefsWznmAMBlockItem = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMRtblock_removeRecByRef", "DELETE FROM TblWznmMRtblock WHERE ref = $1", 1);

	createStatement("TblWznmMRtblock_loadRecByRef", "SELECT ref, refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem FROM TblWznmMRtblock WHERE ref = $1", 1);
	createStatement("TblWznmMRtblock_loadRefsByRtj", "SELECT ref FROM TblWznmMRtblock WHERE refWznmMRtjob = $1", 1);
	createStatement("TblWznmMRtblock_loadRstByRtj", "SELECT ref, refWznmMRtjob, refIxVTbl, refUref, sref, srcSrefsWznmAMBlockItem FROM TblWznmMRtblock WHERE refWznmMRtjob = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMRtblock_loadSrfByRef", "SELECT sref FROM TblWznmMRtblock WHERE ref = $1", 1);
};

bool PgTblWznmMRtblock::loadRec(
			PGresult* res
			, WznmMRtblock** rec
		) {
	char* ptr;

	WznmMRtblock* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMRtblock();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srcsrefswznmamblockitem")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srcSrefsWznmAMBlockItem.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMRtblock::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMRtblock& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMRtblock* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srcsrefswznmamblockitem")
		};

		while (numread < numrow) {
			rec = new WznmMRtblock();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srcSrefsWznmAMBlockItem.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMRtblock::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMRtblock** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtblock::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRtblock::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMRtblock& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtblock::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmMRtblock** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtblock::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRtblock& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtblock::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMRtblock::insertRec(
			WznmMRtblock* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);

	const char* vals[] = {
		(char*) &_refWznmMRtjob,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->sref.c_str(),
		rec->srcSrefsWznmAMBlockItem.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMRtblock_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRtblock::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMRtblock::insertRst(
			ListWznmMRtblock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMRtblock::updateRec(
			WznmMRtblock* rec
		) {
	PGresult* res;

	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMRtjob,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->sref.c_str(),
		rec->srcSrefsWznmAMBlockItem.c_str(),
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

	res = PQexecPrepared(dbs, "TblWznmMRtblock_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRtblock::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMRtblock::updateRst(
			ListWznmMRtblock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMRtblock::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMRtblock_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRtblock::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMRtblock::loadRecByRef(
			ubigint ref
			, WznmMRtblock** rec
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

	return loadRecByStmt("TblWznmMRtblock_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMRtblock::loadRefsByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMRtjob = htonl64(refWznmMRtjob);

	const char* vals[] = {
		(char*) &_refWznmMRtjob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMRtblock_loadRefsByRtj", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMRtblock::loadRstByRtj(
			ubigint refWznmMRtjob
			, const bool append
			, ListWznmMRtblock& rst
		) {
	ubigint _refWznmMRtjob = htonl64(refWznmMRtjob);

	const char* vals[] = {
		(char*) &_refWznmMRtjob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRtblock_loadRstByRtj", 1, vals, l, f, append, rst);
};

bool PgTblWznmMRtblock::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMRtblock_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

