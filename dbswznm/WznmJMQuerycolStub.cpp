/**
	* \file WznmJMQuerycolStub.cpp
	* database access for table TblWznmJMQuerycolStub (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmJMQuerycolStub.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMQuerycolStub
 ******************************************************************************/

WznmJMQuerycolStub::WznmJMQuerycolStub(
			const ubigint ref
			, const ubigint refWznmMQuerycol
			, const ubigint x1RefWznmMVectoritem
			, const ubigint x2RefWznmMPreset
			, const ubigint refWznmMStub
		) {

	this->ref = ref;
	this->refWznmMQuerycol = refWznmMQuerycol;
	this->x1RefWznmMVectoritem = x1RefWznmMVectoritem;
	this->x2RefWznmMPreset = x2RefWznmMPreset;
	this->refWznmMStub = refWznmMStub;
};

bool WznmJMQuerycolStub::operator==(
			const WznmJMQuerycolStub& comp
		) {
	return false;
};

bool WznmJMQuerycolStub::operator!=(
			const WznmJMQuerycolStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMQuerycolStub
 ******************************************************************************/

ListWznmJMQuerycolStub::ListWznmJMQuerycolStub() {
};

ListWznmJMQuerycolStub::ListWznmJMQuerycolStub(
			const ListWznmJMQuerycolStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMQuerycolStub(*(src.nodes[i]));
};

ListWznmJMQuerycolStub::~ListWznmJMQuerycolStub() {
	clear();
};

void ListWznmJMQuerycolStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMQuerycolStub::size() const {
	return(nodes.size());
};

void ListWznmJMQuerycolStub::append(
			WznmJMQuerycolStub* rec
		) {
	nodes.push_back(rec);
};

WznmJMQuerycolStub* ListWznmJMQuerycolStub::operator[](
			const uint ix
		) {
	WznmJMQuerycolStub* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMQuerycolStub& ListWznmJMQuerycolStub::operator=(
			const ListWznmJMQuerycolStub& src
		) {
	WznmJMQuerycolStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMQuerycolStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMQuerycolStub::operator==(
			const ListWznmJMQuerycolStub& comp
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

bool ListWznmJMQuerycolStub::operator!=(
			const ListWznmJMQuerycolStub& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMQuerycolStub
 ******************************************************************************/

TblWznmJMQuerycolStub::TblWznmJMQuerycolStub() {
};

TblWznmJMQuerycolStub::~TblWznmJMQuerycolStub() {
};

bool TblWznmJMQuerycolStub::loadRecBySQL(
			const string& sqlstr
			, WznmJMQuerycolStub** rec
		) {
	return false;
};

ubigint TblWznmJMQuerycolStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	return 0;
};

ubigint TblWznmJMQuerycolStub::insertRec(
			WznmJMQuerycolStub* rec
		) {
	return 0;
};

ubigint TblWznmJMQuerycolStub::insertNewRec(
			WznmJMQuerycolStub** rec
			, const ubigint refWznmMQuerycol
			, const ubigint x1RefWznmMVectoritem
			, const ubigint x2RefWznmMPreset
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmJMQuerycolStub* _rec = NULL;

	_rec = new WznmJMQuerycolStub(0, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMQuerycolStub::appendNewRecToRst(
			ListWznmJMQuerycolStub& rst
			, WznmJMQuerycolStub** rec
			, const ubigint refWznmMQuerycol
			, const ubigint x1RefWznmMVectoritem
			, const ubigint x2RefWznmMPreset
			, const ubigint refWznmMStub
		) {
	ubigint retval = 0;
	WznmJMQuerycolStub* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMQuerycolStub::insertRst(
			ListWznmJMQuerycolStub& rst
			, bool transact
		) {
};

void TblWznmJMQuerycolStub::updateRec(
			WznmJMQuerycolStub* rec
		) {
};

void TblWznmJMQuerycolStub::updateRst(
			ListWznmJMQuerycolStub& rst
			, bool transact
		) {
};

void TblWznmJMQuerycolStub::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMQuerycolStub::loadRecByRef(
			ubigint ref
			, WznmJMQuerycolStub** rec
		) {
	return false;
};

bool TblWznmJMQuerycolStub::loadRecByQcoVit(
			ubigint refWznmMQuerycol
			, ubigint x1RefWznmMVectoritem
			, WznmJMQuerycolStub** rec
		) {
	return false;
};

ubigint TblWznmJMQuerycolStub::loadRefsByQco(
			ubigint refWznmMQuerycol
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMQuerycolStub::loadRstByQco(
			ubigint refWznmMQuerycol
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	return 0;
};

bool TblWznmJMQuerycolStub::loadStbByQcoVitPst(
			ubigint refWznmMQuerycol
			, ubigint x1RefWznmMVectoritem
			, ubigint x2RefWznmMPreset
			, ubigint& refWznmMStub
		) {
	return false;
};

ubigint TblWznmJMQuerycolStub::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	ubigint numload = 0;
	WznmJMQuerycolStub* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMQuerycolStub
 ******************************************************************************/

MyTblWznmJMQuerycolStub::MyTblWznmJMQuerycolStub() :
			TblWznmJMQuerycolStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMQuerycolStub::~MyTblWznmJMQuerycolStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMQuerycolStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMQuerycolStub (refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMQuerycolStub SET refWznmMQuerycol = ?, x1RefWznmMVectoritem = ?, x2RefWznmMPreset = ?, refWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMQuerycolStub WHERE ref = ?", false);
};

bool MyTblWznmJMQuerycolStub::loadRecBySQL(
			const string& sqlstr
			, WznmJMQuerycolStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMQuerycolStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMQuerycolStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMQuerycolStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmJMQuerycolStub();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMQuerycol = atoll((char*) dbrow[1]); else _rec->refWznmMQuerycol = 0;
		if (dbrow[2]) _rec->x1RefWznmMVectoritem = atoll((char*) dbrow[2]); else _rec->x1RefWznmMVectoritem = 0;
		if (dbrow[3]) _rec->x2RefWznmMPreset = atoll((char*) dbrow[3]); else _rec->x2RefWznmMPreset = 0;
		if (dbrow[4]) _rec->refWznmMStub = atoll((char*) dbrow[4]); else _rec->refWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMQuerycolStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMQuerycolStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMQuerycolStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMQuerycolStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmJMQuerycolStub();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMQuerycol = atoll((char*) dbrow[1]); else rec->refWznmMQuerycol = 0;
			if (dbrow[2]) rec->x1RefWznmMVectoritem = atoll((char*) dbrow[2]); else rec->x1RefWznmMVectoritem = 0;
			if (dbrow[3]) rec->x2RefWznmMPreset = atoll((char*) dbrow[3]); else rec->x2RefWznmMPreset = 0;
			if (dbrow[4]) rec->refWznmMStub = atoll((char*) dbrow[4]); else rec->refWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMQuerycolStub::insertRec(
			WznmJMQuerycolStub* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuerycol,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMVectoritem,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMPreset,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMStub,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMQuerycolStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMQuerycolStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMQuerycolStub::insertRst(
			ListWznmJMQuerycolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMQuerycolStub::updateRec(
			WznmJMQuerycolStub* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMQuerycol,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMVectoritem,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMPreset,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMStub,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMQuerycolStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMQuerycolStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMQuerycolStub::updateRst(
			ListWznmJMQuerycolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMQuerycolStub::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMQuerycolStub::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMQuerycolStub::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMQuerycolStub::loadRecByRef(
			ubigint ref
			, WznmJMQuerycolStub** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMQuerycolStub WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMQuerycolStub::loadRecByQcoVit(
			ubigint refWznmMQuerycol
			, ubigint x1RefWznmMVectoritem
			, WznmJMQuerycolStub** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(refWznmMQuerycol) + " AND x1RefWznmMVectoritem = " + to_string(x1RefWznmMVectoritem) + "", rec);
};

ubigint MyTblWznmJMQuerycolStub::loadRefsByQco(
			ubigint refWznmMQuerycol
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(refWznmMQuerycol) + "", append, refs);
};

ubigint MyTblWznmJMQuerycolStub::loadRstByQco(
			ubigint refWznmMQuerycol
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(refWznmMQuerycol) + " ORDER BY x1RefWznmMVectoritem ASC, x2RefWznmMPreset ASC", append, rst);
};

bool MyTblWznmJMQuerycolStub::loadStbByQcoVitPst(
			ubigint refWznmMQuerycol
			, ubigint x1RefWznmMVectoritem
			, ubigint x2RefWznmMPreset
			, ubigint& refWznmMStub
		) {
	return loadRefBySQL("SELECT refWznmMStub FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(refWznmMQuerycol) + " AND x1RefWznmMVectoritem = " + to_string(x1RefWznmMVectoritem) + " AND x2RefWznmMPreset = " + to_string(x2RefWznmMPreset) + "", refWznmMStub);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMQuerycolStub
 ******************************************************************************/

PgTblWznmJMQuerycolStub::PgTblWznmJMQuerycolStub() :
			TblWznmJMQuerycolStub()
			, PgTable()
		{
};

PgTblWznmJMQuerycolStub::~PgTblWznmJMQuerycolStub() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMQuerycolStub::initStatements() {
	createStatement("TblWznmJMQuerycolStub_insertRec", "INSERT INTO TblWznmJMQuerycolStub (refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmJMQuerycolStub_updateRec", "UPDATE TblWznmJMQuerycolStub SET refWznmMQuerycol = $1, x1RefWznmMVectoritem = $2, x2RefWznmMPreset = $3, refWznmMStub = $4 WHERE ref = $5", 5);
	createStatement("TblWznmJMQuerycolStub_removeRecByRef", "DELETE FROM TblWznmJMQuerycolStub WHERE ref = $1", 1);

	createStatement("TblWznmJMQuerycolStub_loadRecByRef", "SELECT ref, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub FROM TblWznmJMQuerycolStub WHERE ref = $1", 1);
	createStatement("TblWznmJMQuerycolStub_loadRecByQcoVit", "SELECT ref, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = $1 AND x1RefWznmMVectoritem = $2", 2);
	createStatement("TblWznmJMQuerycolStub_loadRefsByQco", "SELECT ref FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = $1", 1);
	createStatement("TblWznmJMQuerycolStub_loadRstByQco", "SELECT ref, refWznmMQuerycol, x1RefWznmMVectoritem, x2RefWznmMPreset, refWznmMStub FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = $1 ORDER BY x1RefWznmMVectoritem ASC, x2RefWznmMPreset ASC", 1);
	createStatement("TblWznmJMQuerycolStub_loadStbByQcoVitPst", "SELECT refWznmMStub FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = $1 AND x1RefWznmMVectoritem = $2 AND x2RefWznmMPreset = $3", 3);
};

bool PgTblWznmJMQuerycolStub::loadRec(
			PGresult* res
			, WznmJMQuerycolStub** rec
		) {
	char* ptr;

	WznmJMQuerycolStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMQuerycolStub();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquerycol"),
			PQfnumber(res, "x1refwznmmvectoritem"),
			PQfnumber(res, "x2refwznmmpreset"),
			PQfnumber(res, "refwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMQuerycol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMQuerycolStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMQuerycolStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmquerycol"),
			PQfnumber(res, "x1refwznmmvectoritem"),
			PQfnumber(res, "x2refwznmmpreset"),
			PQfnumber(res, "refwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmJMQuerycolStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMQuerycol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMQuerycolStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMQuerycolStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMQuerycolStub::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMQuerycolStub::loadRecBySQL(
			const string& sqlstr
			, WznmJMQuerycolStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMQuerycolStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMQuerycolStub::insertRec(
			WznmJMQuerycolStub* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMQuerycol = htonl64(rec->refWznmMQuerycol);
	ubigint _x1RefWznmMVectoritem = htonl64(rec->x1RefWznmMVectoritem);
	ubigint _x2RefWznmMPreset = htonl64(rec->x2RefWznmMPreset);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMQuerycol,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_x2RefWznmMPreset,
		(char*) &_refWznmMStub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMQuerycolStub_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMQuerycolStub::insertRst(
			ListWznmJMQuerycolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMQuerycolStub::updateRec(
			WznmJMQuerycolStub* rec
		) {
	PGresult* res;

	ubigint _refWznmMQuerycol = htonl64(rec->refWznmMQuerycol);
	ubigint _x1RefWznmMVectoritem = htonl64(rec->x1RefWznmMVectoritem);
	ubigint _x2RefWznmMPreset = htonl64(rec->x2RefWznmMPreset);
	ubigint _refWznmMStub = htonl64(rec->refWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMQuerycol,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_x2RefWznmMPreset,
		(char*) &_refWznmMStub,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMQuerycolStub_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMQuerycolStub::updateRst(
			ListWznmJMQuerycolStub& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMQuerycolStub::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMQuerycolStub_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMQuerycolStub::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMQuerycolStub::loadRecByRef(
			ubigint ref
			, WznmJMQuerycolStub** rec
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

	return loadRecByStmt("TblWznmJMQuerycolStub_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMQuerycolStub::loadRecByQcoVit(
			ubigint refWznmMQuerycol
			, ubigint x1RefWznmMVectoritem
			, WznmJMQuerycolStub** rec
		) {
	ubigint _refWznmMQuerycol = htonl64(refWznmMQuerycol);
	ubigint _x1RefWznmMVectoritem = htonl64(x1RefWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMQuerycol,
		(char*) &_x1RefWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMQuerycolStub_loadRecByQcoVit", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMQuerycolStub::loadRefsByQco(
			ubigint refWznmMQuerycol
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMQuerycol = htonl64(refWznmMQuerycol);

	const char* vals[] = {
		(char*) &_refWznmMQuerycol
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMQuerycolStub_loadRefsByQco", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMQuerycolStub::loadRstByQco(
			ubigint refWznmMQuerycol
			, const bool append
			, ListWznmJMQuerycolStub& rst
		) {
	ubigint _refWznmMQuerycol = htonl64(refWznmMQuerycol);

	const char* vals[] = {
		(char*) &_refWznmMQuerycol
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMQuerycolStub_loadRstByQco", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMQuerycolStub::loadStbByQcoVitPst(
			ubigint refWznmMQuerycol
			, ubigint x1RefWznmMVectoritem
			, ubigint x2RefWznmMPreset
			, ubigint& refWznmMStub
		) {
	ubigint _refWznmMQuerycol = htonl64(refWznmMQuerycol);
	ubigint _x1RefWznmMVectoritem = htonl64(x1RefWznmMVectoritem);
	ubigint _x2RefWznmMPreset = htonl64(x2RefWznmMPreset);

	const char* vals[] = {
		(char*) &_refWznmMQuerycol,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_x2RefWznmMPreset
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRefByStmt("TblWznmJMQuerycolStub_loadStbByQcoVitPst", 3, vals, l, f, refWznmMStub);
};

#endif

