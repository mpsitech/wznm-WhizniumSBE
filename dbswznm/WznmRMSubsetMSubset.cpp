/**
	* \file WznmRMSubsetMSubset.cpp
	* database access for table TblWznmRMSubsetMSubset (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmRMSubsetMSubset.h"

#include "WznmRMSubsetMSubset_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmRMSubsetMSubset
 ******************************************************************************/

WznmRMSubsetMSubset::WznmRMSubsetMSubset(
			const ubigint ref
			, const ubigint asbRefWznmMSubset
			, const ubigint bsbRefWznmMSubset
			, const uint ixVReltype
		) {

	this->ref = ref;
	this->asbRefWznmMSubset = asbRefWznmMSubset;
	this->bsbRefWznmMSubset = bsbRefWznmMSubset;
	this->ixVReltype = ixVReltype;
};

bool WznmRMSubsetMSubset::operator==(
			const WznmRMSubsetMSubset& comp
		) {
	return false;
};

bool WznmRMSubsetMSubset::operator!=(
			const WznmRMSubsetMSubset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmRMSubsetMSubset
 ******************************************************************************/

ListWznmRMSubsetMSubset::ListWznmRMSubsetMSubset() {
};

ListWznmRMSubsetMSubset::ListWznmRMSubsetMSubset(
			const ListWznmRMSubsetMSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmRMSubsetMSubset(*(src.nodes[i]));
};

ListWznmRMSubsetMSubset::~ListWznmRMSubsetMSubset() {
	clear();
};

void ListWznmRMSubsetMSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmRMSubsetMSubset::size() const {
	return(nodes.size());
};

void ListWznmRMSubsetMSubset::append(
			WznmRMSubsetMSubset* rec
		) {
	nodes.push_back(rec);
};

WznmRMSubsetMSubset* ListWznmRMSubsetMSubset::operator[](
			const uint ix
		) {
	WznmRMSubsetMSubset* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmRMSubsetMSubset& ListWznmRMSubsetMSubset::operator=(
			const ListWznmRMSubsetMSubset& src
		) {
	WznmRMSubsetMSubset* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmRMSubsetMSubset(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmRMSubsetMSubset::operator==(
			const ListWznmRMSubsetMSubset& comp
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

bool ListWznmRMSubsetMSubset::operator!=(
			const ListWznmRMSubsetMSubset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmRMSubsetMSubset
 ******************************************************************************/

TblWznmRMSubsetMSubset::TblWznmRMSubsetMSubset() {
};

TblWznmRMSubsetMSubset::~TblWznmRMSubsetMSubset() {
};

bool TblWznmRMSubsetMSubset::loadRecBySQL(
			const string& sqlstr
			, WznmRMSubsetMSubset** rec
		) {
	return false;
};

ubigint TblWznmRMSubsetMSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	return 0;
};

ubigint TblWznmRMSubsetMSubset::insertRec(
			WznmRMSubsetMSubset* rec
		) {
	return 0;
};

ubigint TblWznmRMSubsetMSubset::insertNewRec(
			WznmRMSubsetMSubset** rec
			, const ubigint asbRefWznmMSubset
			, const ubigint bsbRefWznmMSubset
			, const uint ixVReltype
		) {
	ubigint retval = 0;
	WznmRMSubsetMSubset* _rec = NULL;

	_rec = new WznmRMSubsetMSubset(0, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmRMSubsetMSubset::appendNewRecToRst(
			ListWznmRMSubsetMSubset& rst
			, WznmRMSubsetMSubset** rec
			, const ubigint asbRefWznmMSubset
			, const ubigint bsbRefWznmMSubset
			, const uint ixVReltype
		) {
	ubigint retval = 0;
	WznmRMSubsetMSubset* _rec = NULL;

	retval = insertNewRec(&_rec, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmRMSubsetMSubset::insertRst(
			ListWznmRMSubsetMSubset& rst
			, bool transact
		) {
};

void TblWznmRMSubsetMSubset::updateRec(
			WznmRMSubsetMSubset* rec
		) {
};

void TblWznmRMSubsetMSubset::updateRst(
			ListWznmRMSubsetMSubset& rst
			, bool transact
		) {
};

void TblWznmRMSubsetMSubset::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmRMSubsetMSubset::loadRecByRef(
			ubigint ref
			, WznmRMSubsetMSubset** rec
		) {
	return false;
};

ubigint TblWznmRMSubsetMSubset::loadRefsByAsb(
			ubigint asbRefWznmMSubset
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmRMSubsetMSubset::loadRstByAsb(
			ubigint asbRefWznmMSubset
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	return 0;
};

ubigint TblWznmRMSubsetMSubset::loadRstByBsb(
			ubigint bsbRefWznmMSubset
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	return 0;
};

ubigint TblWznmRMSubsetMSubset::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	ubigint numload = 0;
	WznmRMSubsetMSubset* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmRMSubsetMSubset
 ******************************************************************************/

MyTblWznmRMSubsetMSubset::MyTblWznmRMSubsetMSubset() :
			TblWznmRMSubsetMSubset()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmRMSubsetMSubset::~MyTblWznmRMSubsetMSubset() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmRMSubsetMSubset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmRMSubsetMSubset (asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmRMSubsetMSubset SET asbRefWznmMSubset = ?, bsbRefWznmMSubset = ?, ixVReltype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmRMSubsetMSubset WHERE ref = ?", false);
};

bool MyTblWznmRMSubsetMSubset::loadRecBySQL(
			const string& sqlstr
			, WznmRMSubsetMSubset** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmRMSubsetMSubset* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMSubsetMSubset::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMSubsetMSubset::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmRMSubsetMSubset();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->asbRefWznmMSubset = atoll((char*) dbrow[1]); else _rec->asbRefWznmMSubset = 0;
		if (dbrow[2]) _rec->bsbRefWznmMSubset = atoll((char*) dbrow[2]); else _rec->bsbRefWznmMSubset = 0;
		if (dbrow[3]) _rec->ixVReltype = atol((char*) dbrow[3]); else _rec->ixVReltype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmRMSubsetMSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmRMSubsetMSubset* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmRMSubsetMSubset::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmRMSubsetMSubset::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmRMSubsetMSubset();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->asbRefWznmMSubset = atoll((char*) dbrow[1]); else rec->asbRefWznmMSubset = 0;
			if (dbrow[2]) rec->bsbRefWznmMSubset = atoll((char*) dbrow[2]); else rec->bsbRefWznmMSubset = 0;
			if (dbrow[3]) rec->ixVReltype = atol((char*) dbrow[3]); else rec->ixVReltype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmRMSubsetMSubset::insertRec(
			WznmRMSubsetMSubset* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->asbRefWznmMSubset,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->bsbRefWznmMSubset,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVReltype,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmRMSubsetMSubset::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmRMSubsetMSubset::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmRMSubsetMSubset::insertRst(
			ListWznmRMSubsetMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmRMSubsetMSubset::updateRec(
			WznmRMSubsetMSubset* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->asbRefWznmMSubset,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->bsbRefWznmMSubset,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVReltype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmRMSubsetMSubset::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmRMSubsetMSubset::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmRMSubsetMSubset::updateRst(
			ListWznmRMSubsetMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmRMSubsetMSubset::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmRMSubsetMSubset::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmRMSubsetMSubset::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmRMSubsetMSubset::loadRecByRef(
			ubigint ref
			, WznmRMSubsetMSubset** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmRMSubsetMSubset WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmRMSubsetMSubset::loadRefsByAsb(
			ubigint asbRefWznmMSubset
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmRMSubsetMSubset WHERE asbRefWznmMSubset = " + to_string(asbRefWznmMSubset) + "", append, refs);
};

ubigint MyTblWznmRMSubsetMSubset::loadRstByAsb(
			ubigint asbRefWznmMSubset
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	return loadRstBySQL("SELECT ref, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype FROM TblWznmRMSubsetMSubset WHERE asbRefWznmMSubset = " + to_string(asbRefWznmMSubset) + "", append, rst);
};

ubigint MyTblWznmRMSubsetMSubset::loadRstByBsb(
			ubigint bsbRefWznmMSubset
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	return loadRstBySQL("SELECT ref, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype FROM TblWznmRMSubsetMSubset WHERE bsbRefWznmMSubset = " + to_string(bsbRefWznmMSubset) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmRMSubsetMSubset
 ******************************************************************************/

PgTblWznmRMSubsetMSubset::PgTblWznmRMSubsetMSubset() :
			TblWznmRMSubsetMSubset()
			, PgTable()
		{
};

PgTblWznmRMSubsetMSubset::~PgTblWznmRMSubsetMSubset() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmRMSubsetMSubset::initStatements() {
	createStatement("TblWznmRMSubsetMSubset_insertRec", "INSERT INTO TblWznmRMSubsetMSubset (asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmRMSubsetMSubset_updateRec", "UPDATE TblWznmRMSubsetMSubset SET asbRefWznmMSubset = $1, bsbRefWznmMSubset = $2, ixVReltype = $3 WHERE ref = $4", 4);
	createStatement("TblWznmRMSubsetMSubset_removeRecByRef", "DELETE FROM TblWznmRMSubsetMSubset WHERE ref = $1", 1);

	createStatement("TblWznmRMSubsetMSubset_loadRecByRef", "SELECT ref, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype FROM TblWznmRMSubsetMSubset WHERE ref = $1", 1);
	createStatement("TblWznmRMSubsetMSubset_loadRefsByAsb", "SELECT ref FROM TblWznmRMSubsetMSubset WHERE asbRefWznmMSubset = $1", 1);
	createStatement("TblWznmRMSubsetMSubset_loadRstByAsb", "SELECT ref, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype FROM TblWznmRMSubsetMSubset WHERE asbRefWznmMSubset = $1", 1);
	createStatement("TblWznmRMSubsetMSubset_loadRstByBsb", "SELECT ref, asbRefWznmMSubset, bsbRefWznmMSubset, ixVReltype FROM TblWznmRMSubsetMSubset WHERE bsbRefWznmMSubset = $1", 1);
};

bool PgTblWznmRMSubsetMSubset::loadRec(
			PGresult* res
			, WznmRMSubsetMSubset** rec
		) {
	char* ptr;

	WznmRMSubsetMSubset* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmRMSubsetMSubset();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "asbrefwznmmsubset"),
			PQfnumber(res, "bsbrefwznmmsubset"),
			PQfnumber(res, "ixvreltype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->asbRefWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->bsbRefWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVReltype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmRMSubsetMSubset::loadRst(
			PGresult* res
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmRMSubsetMSubset* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "asbrefwznmmsubset"),
			PQfnumber(res, "bsbrefwznmmsubset"),
			PQfnumber(res, "ixvreltype")
		};

		while (numread < numrow) {
			rec = new WznmRMSubsetMSubset();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->asbRefWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->bsbRefWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVReltype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmRMSubsetMSubset::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmRMSubsetMSubset** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMSubsetMSubset::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmRMSubsetMSubset::loadRecBySQL(
			const string& sqlstr
			, WznmRMSubsetMSubset** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmRMSubsetMSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmRMSubsetMSubset::insertRec(
			WznmRMSubsetMSubset* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _asbRefWznmMSubset = htonl64(rec->asbRefWznmMSubset);
	ubigint _bsbRefWznmMSubset = htonl64(rec->bsbRefWznmMSubset);
	uint _ixVReltype = htonl(rec->ixVReltype);

	const char* vals[] = {
		(char*) &_asbRefWznmMSubset,
		(char*) &_bsbRefWznmMSubset,
		(char*) &_ixVReltype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMSubsetMSubset_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmRMSubsetMSubset::insertRst(
			ListWznmRMSubsetMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmRMSubsetMSubset::updateRec(
			WznmRMSubsetMSubset* rec
		) {
	PGresult* res;

	ubigint _asbRefWznmMSubset = htonl64(rec->asbRefWznmMSubset);
	ubigint _bsbRefWznmMSubset = htonl64(rec->bsbRefWznmMSubset);
	uint _ixVReltype = htonl(rec->ixVReltype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_asbRefWznmMSubset,
		(char*) &_bsbRefWznmMSubset,
		(char*) &_ixVReltype,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmRMSubsetMSubset_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmRMSubsetMSubset::updateRst(
			ListWznmRMSubsetMSubset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmRMSubsetMSubset::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmRMSubsetMSubset_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmRMSubsetMSubset::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmRMSubsetMSubset::loadRecByRef(
			ubigint ref
			, WznmRMSubsetMSubset** rec
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

	return loadRecByStmt("TblWznmRMSubsetMSubset_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmRMSubsetMSubset::loadRefsByAsb(
			ubigint asbRefWznmMSubset
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _asbRefWznmMSubset = htonl64(asbRefWznmMSubset);

	const char* vals[] = {
		(char*) &_asbRefWznmMSubset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmRMSubsetMSubset_loadRefsByAsb", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmRMSubsetMSubset::loadRstByAsb(
			ubigint asbRefWznmMSubset
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	ubigint _asbRefWznmMSubset = htonl64(asbRefWznmMSubset);

	const char* vals[] = {
		(char*) &_asbRefWznmMSubset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMSubsetMSubset_loadRstByAsb", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmRMSubsetMSubset::loadRstByBsb(
			ubigint bsbRefWznmMSubset
			, const bool append
			, ListWznmRMSubsetMSubset& rst
		) {
	ubigint _bsbRefWznmMSubset = htonl64(bsbRefWznmMSubset);

	const char* vals[] = {
		(char*) &_bsbRefWznmMSubset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmRMSubsetMSubset_loadRstByBsb", 1, vals, l, f, append, rst);
};

#endif

