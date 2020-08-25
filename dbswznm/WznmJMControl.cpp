/**
	* \file WznmJMControl.cpp
	* database access for table TblWznmJMControl (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmJMControl.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMControl
 ******************************************************************************/

WznmJMControl::WznmJMControl(
			const ubigint ref
			, const ubigint refWznmMControl
			, const ubigint x1RefWznmMVectoritem
			, const ubigint x2RefWznmMPreset
			, const ubigint stdRefWznmMStub
			, const ubigint shoRefWznmMStub
		) {

	this->ref = ref;
	this->refWznmMControl = refWznmMControl;
	this->x1RefWznmMVectoritem = x1RefWznmMVectoritem;
	this->x2RefWznmMPreset = x2RefWznmMPreset;
	this->stdRefWznmMStub = stdRefWznmMStub;
	this->shoRefWznmMStub = shoRefWznmMStub;
};

bool WznmJMControl::operator==(
			const WznmJMControl& comp
		) {
	return false;
};

bool WznmJMControl::operator!=(
			const WznmJMControl& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMControl
 ******************************************************************************/

ListWznmJMControl::ListWznmJMControl() {
};

ListWznmJMControl::ListWznmJMControl(
			const ListWznmJMControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMControl(*(src.nodes[i]));
};

ListWznmJMControl::~ListWznmJMControl() {
	clear();
};

void ListWznmJMControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMControl::size() const {
	return(nodes.size());
};

void ListWznmJMControl::append(
			WznmJMControl* rec
		) {
	nodes.push_back(rec);
};

WznmJMControl* ListWznmJMControl::operator[](
			const uint ix
		) {
	WznmJMControl* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMControl& ListWznmJMControl::operator=(
			const ListWznmJMControl& src
		) {
	WznmJMControl* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMControl(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMControl::operator==(
			const ListWznmJMControl& comp
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

bool ListWznmJMControl::operator!=(
			const ListWznmJMControl& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMControl
 ******************************************************************************/

TblWznmJMControl::TblWznmJMControl() {
};

TblWznmJMControl::~TblWznmJMControl() {
};

bool TblWznmJMControl::loadRecBySQL(
			const string& sqlstr
			, WznmJMControl** rec
		) {
	return false;
};

ubigint TblWznmJMControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMControl& rst
		) {
	return 0;
};

ubigint TblWznmJMControl::insertRec(
			WznmJMControl* rec
		) {
	return 0;
};

ubigint TblWznmJMControl::insertNewRec(
			WznmJMControl** rec
			, const ubigint refWznmMControl
			, const ubigint x1RefWznmMVectoritem
			, const ubigint x2RefWznmMPreset
			, const ubigint stdRefWznmMStub
			, const ubigint shoRefWznmMStub
		) {
	ubigint retval = 0;
	WznmJMControl* _rec = NULL;

	_rec = new WznmJMControl(0, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMControl::appendNewRecToRst(
			ListWznmJMControl& rst
			, WznmJMControl** rec
			, const ubigint refWznmMControl
			, const ubigint x1RefWznmMVectoritem
			, const ubigint x2RefWznmMPreset
			, const ubigint stdRefWznmMStub
			, const ubigint shoRefWznmMStub
		) {
	ubigint retval = 0;
	WznmJMControl* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMControl::insertRst(
			ListWznmJMControl& rst
			, bool transact
		) {
};

void TblWznmJMControl::updateRec(
			WznmJMControl* rec
		) {
};

void TblWznmJMControl::updateRst(
			ListWznmJMControl& rst
			, bool transact
		) {
};

void TblWznmJMControl::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMControl::loadRecByRef(
			ubigint ref
			, WznmJMControl** rec
		) {
	return false;
};

bool TblWznmJMControl::loadRecByConVit(
			ubigint refWznmMControl
			, ubigint x1RefWznmMVectoritem
			, WznmJMControl** rec
		) {
	return false;
};

ubigint TblWznmJMControl::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMControl::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmJMControl& rst
		) {
	return 0;
};

bool TblWznmJMControl::loadStsByConVit(
			ubigint refWznmMControl
			, ubigint x1RefWznmMVectoritem
			, ubigint& stdRefWznmMStub
		) {
	return false;
};

ubigint TblWznmJMControl::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMControl& rst
		) {
	ubigint numload = 0;
	WznmJMControl* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMControl
 ******************************************************************************/

MyTblWznmJMControl::MyTblWznmJMControl() :
			TblWznmJMControl()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMControl::~MyTblWznmJMControl() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMControl::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMControl (refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMControl SET refWznmMControl = ?, x1RefWznmMVectoritem = ?, x2RefWznmMPreset = ?, stdRefWznmMStub = ?, shoRefWznmMStub = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMControl WHERE ref = ?", false);
};

bool MyTblWznmJMControl::loadRecBySQL(
			const string& sqlstr
			, WznmJMControl** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMControl* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMControl::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMControl::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmJMControl();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMControl = atoll((char*) dbrow[1]); else _rec->refWznmMControl = 0;
		if (dbrow[2]) _rec->x1RefWznmMVectoritem = atoll((char*) dbrow[2]); else _rec->x1RefWznmMVectoritem = 0;
		if (dbrow[3]) _rec->x2RefWznmMPreset = atoll((char*) dbrow[3]); else _rec->x2RefWznmMPreset = 0;
		if (dbrow[4]) _rec->stdRefWznmMStub = atoll((char*) dbrow[4]); else _rec->stdRefWznmMStub = 0;
		if (dbrow[5]) _rec->shoRefWznmMStub = atoll((char*) dbrow[5]); else _rec->shoRefWznmMStub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMControl& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMControl* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMControl::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMControl::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmJMControl();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMControl = atoll((char*) dbrow[1]); else rec->refWznmMControl = 0;
			if (dbrow[2]) rec->x1RefWznmMVectoritem = atoll((char*) dbrow[2]); else rec->x1RefWznmMVectoritem = 0;
			if (dbrow[3]) rec->x2RefWznmMPreset = atoll((char*) dbrow[3]); else rec->x2RefWznmMPreset = 0;
			if (dbrow[4]) rec->stdRefWznmMStub = atoll((char*) dbrow[4]); else rec->stdRefWznmMStub = 0;
			if (dbrow[5]) rec->shoRefWznmMStub = atoll((char*) dbrow[5]); else rec->shoRefWznmMStub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMControl::insertRec(
			WznmJMControl* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMVectoritem,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMPreset,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->stdRefWznmMStub,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->shoRefWznmMStub,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMControl::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMControl::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMControl::insertRst(
			ListWznmJMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMControl::updateRec(
			WznmJMControl* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMVectoritem,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMPreset,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->stdRefWznmMStub,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->shoRefWznmMStub,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMControl::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMControl::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMControl::updateRst(
			ListWznmJMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMControl::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMControl::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMControl::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMControl::loadRecByRef(
			ubigint ref
			, WznmJMControl** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMControl WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMControl::loadRecByConVit(
			ubigint refWznmMControl
			, ubigint x1RefWznmMVectoritem
			, WznmJMControl** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub FROM TblWznmJMControl WHERE refWznmMControl = " + to_string(refWznmMControl) + " AND x1RefWznmMVectoritem = " + to_string(x1RefWznmMVectoritem) + "", rec);
};

ubigint MyTblWznmJMControl::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMControl WHERE refWznmMControl = " + to_string(refWznmMControl) + "", append, refs);
};

ubigint MyTblWznmJMControl::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmJMControl& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub FROM TblWznmJMControl WHERE refWznmMControl = " + to_string(refWznmMControl) + " ORDER BY x1RefWznmMVectoritem ASC", append, rst);
};

bool MyTblWznmJMControl::loadStsByConVit(
			ubigint refWznmMControl
			, ubigint x1RefWznmMVectoritem
			, ubigint& stdRefWznmMStub
		) {
	return loadRefBySQL("SELECT stdRefWznmMStub FROM TblWznmJMControl WHERE refWznmMControl = " + to_string(refWznmMControl) + " AND x1RefWznmMVectoritem = " + to_string(x1RefWznmMVectoritem) + "", stdRefWznmMStub);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMControl
 ******************************************************************************/

PgTblWznmJMControl::PgTblWznmJMControl() :
			TblWznmJMControl()
			, PgTable()
		{
};

PgTblWznmJMControl::~PgTblWznmJMControl() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMControl::initStatements() {
	createStatement("TblWznmJMControl_insertRec", "INSERT INTO TblWznmJMControl (refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmJMControl_updateRec", "UPDATE TblWznmJMControl SET refWznmMControl = $1, x1RefWznmMVectoritem = $2, x2RefWznmMPreset = $3, stdRefWznmMStub = $4, shoRefWznmMStub = $5 WHERE ref = $6", 6);
	createStatement("TblWznmJMControl_removeRecByRef", "DELETE FROM TblWznmJMControl WHERE ref = $1", 1);

	createStatement("TblWznmJMControl_loadRecByRef", "SELECT ref, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub FROM TblWznmJMControl WHERE ref = $1", 1);
	createStatement("TblWznmJMControl_loadRecByConVit", "SELECT ref, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub FROM TblWznmJMControl WHERE refWznmMControl = $1 AND x1RefWznmMVectoritem = $2", 2);
	createStatement("TblWznmJMControl_loadRefsByCon", "SELECT ref FROM TblWznmJMControl WHERE refWznmMControl = $1", 1);
	createStatement("TblWznmJMControl_loadRstByCon", "SELECT ref, refWznmMControl, x1RefWznmMVectoritem, x2RefWznmMPreset, stdRefWznmMStub, shoRefWznmMStub FROM TblWznmJMControl WHERE refWznmMControl = $1 ORDER BY x1RefWznmMVectoritem ASC", 1);
	createStatement("TblWznmJMControl_loadStsByConVit", "SELECT stdRefWznmMStub FROM TblWznmJMControl WHERE refWznmMControl = $1 AND x1RefWznmMVectoritem = $2", 2);
};

bool PgTblWznmJMControl::loadRec(
			PGresult* res
			, WznmJMControl** rec
		) {
	char* ptr;

	WznmJMControl* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMControl();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "x1refwznmmvectoritem"),
			PQfnumber(res, "x2refwznmmpreset"),
			PQfnumber(res, "stdrefwznmmstub"),
			PQfnumber(res, "shorefwznmmstub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->stdRefWznmMStub = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->shoRefWznmMStub = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMControl::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMControl& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMControl* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "x1refwznmmvectoritem"),
			PQfnumber(res, "x2refwznmmpreset"),
			PQfnumber(res, "stdrefwznmmstub"),
			PQfnumber(res, "shorefwznmmstub")
		};

		while (numread < numrow) {
			rec = new WznmJMControl();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->stdRefWznmMStub = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->shoRefWznmMStub = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMControl::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMControl** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControl::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMControl::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMControl& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControl::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMControl::loadRecBySQL(
			const string& sqlstr
			, WznmJMControl** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControl::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMControl& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControl::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMControl::insertRec(
			WznmJMControl* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _x1RefWznmMVectoritem = htonl64(rec->x1RefWznmMVectoritem);
	ubigint _x2RefWznmMPreset = htonl64(rec->x2RefWznmMPreset);
	ubigint _stdRefWznmMStub = htonl64(rec->stdRefWznmMStub);
	ubigint _shoRefWznmMStub = htonl64(rec->shoRefWznmMStub);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_x2RefWznmMPreset,
		(char*) &_stdRefWznmMStub,
		(char*) &_shoRefWznmMStub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMControl_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMControl::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMControl::insertRst(
			ListWznmJMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMControl::updateRec(
			WznmJMControl* rec
		) {
	PGresult* res;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _x1RefWznmMVectoritem = htonl64(rec->x1RefWznmMVectoritem);
	ubigint _x2RefWznmMPreset = htonl64(rec->x2RefWznmMPreset);
	ubigint _stdRefWznmMStub = htonl64(rec->stdRefWznmMStub);
	ubigint _shoRefWznmMStub = htonl64(rec->shoRefWznmMStub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMVectoritem,
		(char*) &_x2RefWznmMPreset,
		(char*) &_stdRefWznmMStub,
		(char*) &_shoRefWznmMStub,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmJMControl_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMControl::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMControl::updateRst(
			ListWznmJMControl& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMControl::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMControl_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMControl::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMControl::loadRecByRef(
			ubigint ref
			, WznmJMControl** rec
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

	return loadRecByStmt("TblWznmJMControl_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMControl::loadRecByConVit(
			ubigint refWznmMControl
			, ubigint x1RefWznmMVectoritem
			, WznmJMControl** rec
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);
	ubigint _x1RefWznmMVectoritem = htonl64(x1RefWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMControl_loadRecByConVit", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMControl::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMControl_loadRefsByCon", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMControl::loadRstByCon(
			ubigint refWznmMControl
			, const bool append
			, ListWznmJMControl& rst
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMControl_loadRstByCon", 1, vals, l, f, append, rst);
};

bool PgTblWznmJMControl::loadStsByConVit(
			ubigint refWznmMControl
			, ubigint x1RefWznmMVectoritem
			, ubigint& stdRefWznmMStub
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);
	ubigint _x1RefWznmMVectoritem = htonl64(x1RefWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_x1RefWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefByStmt("TblWznmJMControl_loadStsByConVit", 2, vals, l, f, stdRefWznmMStub);
};

#endif

