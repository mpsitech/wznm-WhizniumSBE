/**
	* \file WznmMDialog.cpp
	* database access for table TblWznmMDialog (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMDialog.h"

#include "WznmMDialog_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMDialog
 ******************************************************************************/

WznmMDialog::WznmMDialog(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMCard
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) :
			ref(ref)
			, ixVBasetype(ixVBasetype)
			, refWznmMCard(refWznmMCard)
			, refIxVTbl(refIxVTbl)
			, refUref(refUref)
			, refWznmMJob(refWznmMJob)
			, sref(sref)
			, Comment(Comment)
		{
};

bool WznmMDialog::operator==(
			const WznmMDialog& comp
		) {
	return false;
};

bool WznmMDialog::operator!=(
			const WznmMDialog& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMDialog
 ******************************************************************************/

ListWznmMDialog::ListWznmMDialog() {
};

ListWznmMDialog::ListWznmMDialog(
			const ListWznmMDialog& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMDialog(*(src.nodes[i]));
};

ListWznmMDialog::~ListWznmMDialog() {
	clear();
};

void ListWznmMDialog::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMDialog::size() const {
	return(nodes.size());
};

void ListWznmMDialog::append(
			WznmMDialog* rec
		) {
	nodes.push_back(rec);
};

WznmMDialog* ListWznmMDialog::operator[](
			const uint ix
		) {
	WznmMDialog* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMDialog& ListWznmMDialog::operator=(
			const ListWznmMDialog& src
		) {
	WznmMDialog* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMDialog(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMDialog::operator==(
			const ListWznmMDialog& comp
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

bool ListWznmMDialog::operator!=(
			const ListWznmMDialog& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMDialog
 ******************************************************************************/

TblWznmMDialog::TblWznmMDialog() {
};

TblWznmMDialog::~TblWznmMDialog() {
};

bool TblWznmMDialog::loadRecBySQL(
			const string& sqlstr
			, WznmMDialog** rec
		) {
	return false;
};

ubigint TblWznmMDialog::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMDialog& rst
		) {
	return 0;
};

ubigint TblWznmMDialog::insertRec(
			WznmMDialog* rec
		) {
	return 0;
};

ubigint TblWznmMDialog::insertNewRec(
			WznmMDialog** rec
			, const uint ixVBasetype
			, const ubigint refWznmMCard
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMDialog* _rec = NULL;

	_rec = new WznmMDialog(0, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMDialog::appendNewRecToRst(
			ListWznmMDialog& rst
			, WznmMDialog** rec
			, const uint ixVBasetype
			, const ubigint refWznmMCard
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMDialog* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMDialog::insertRst(
			ListWznmMDialog& rst
			, bool transact
		) {
};

void TblWznmMDialog::updateRec(
			WznmMDialog* rec
		) {
};

void TblWznmMDialog::updateRst(
			ListWznmMDialog& rst
			, bool transact
		) {
};

void TblWznmMDialog::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMDialog::loadRecByRef(
			ubigint ref
			, WznmMDialog** rec
		) {
	return false;
};

bool TblWznmMDialog::loadRecByJob(
			ubigint refWznmMJob
			, WznmMDialog** rec
		) {
	return false;
};

ubigint TblWznmMDialog::loadRefsByCar(
			ubigint refWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMDialog::loadRstByCar(
			ubigint refWznmMCard
			, const bool append
			, ListWznmMDialog& rst
		) {
	return 0;
};

bool TblWznmMDialog::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMDialog::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMDialog& rst
		) {
	ubigint numload = 0;
	WznmMDialog* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMDialog
 ******************************************************************************/

MyTblWznmMDialog::MyTblWznmMDialog() :
			TblWznmMDialog()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMDialog::~MyTblWznmMDialog() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMDialog::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMDialog (ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMDialog SET ixVBasetype = ?, refWznmMCard = ?, refIxVTbl = ?, refUref = ?, refWznmMJob = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMDialog WHERE ref = ?", false);
};

bool MyTblWznmMDialog::loadRecBySQL(
			const string& sqlstr
			, WznmMDialog** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMDialog* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMDialog::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMDialog::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMDialog();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMCard = atoll((char*) dbrow[2]); else _rec->refWznmMCard = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->refWznmMJob = atoll((char*) dbrow[5]); else _rec->refWznmMJob = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMDialog::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMDialog& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMDialog* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMDialog::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMDialog::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMDialog();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMCard = atoll((char*) dbrow[2]); else rec->refWznmMCard = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->refWznmMJob = atoll((char*) dbrow[5]); else rec->refWznmMJob = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMDialog::insertRec(
			WznmMDialog* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMJob,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMDialog::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMDialog::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMDialog::insertRst(
			ListWznmMDialog& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMDialog::updateRec(
			WznmMDialog* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMJob,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMDialog::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMDialog::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMDialog::updateRst(
			ListWznmMDialog& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMDialog::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMDialog::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMDialog::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMDialog::loadRecByRef(
			ubigint ref
			, WznmMDialog** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMDialog WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMDialog::loadRecByJob(
			ubigint refWznmMJob
			, WznmMDialog** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment FROM TblWznmMDialog WHERE refWznmMJob = " + to_string(refWznmMJob) + "", rec);
};

ubigint MyTblWznmMDialog::loadRefsByCar(
			ubigint refWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(refWznmMCard) + "", append, refs);
};

ubigint MyTblWznmMDialog::loadRstByCar(
			ubigint refWznmMCard
			, const bool append
			, ListWznmMDialog& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(refWznmMCard) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMDialog::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMDialog WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMDialog
 ******************************************************************************/

PgTblWznmMDialog::PgTblWznmMDialog() :
			TblWznmMDialog()
			, PgTable()
		{
};

PgTblWznmMDialog::~PgTblWznmMDialog() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMDialog::initStatements() {
	createStatement("TblWznmMDialog_insertRec", "INSERT INTO TblWznmMDialog (ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmMDialog_updateRec", "UPDATE TblWznmMDialog SET ixVBasetype = $1, refWznmMCard = $2, refIxVTbl = $3, refUref = $4, refWznmMJob = $5, sref = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmMDialog_removeRecByRef", "DELETE FROM TblWznmMDialog WHERE ref = $1", 1);

	createStatement("TblWznmMDialog_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment FROM TblWznmMDialog WHERE ref = $1", 1);
	createStatement("TblWznmMDialog_loadRecByJob", "SELECT ref, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment FROM TblWznmMDialog WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMDialog_loadRefsByCar", "SELECT ref FROM TblWznmMDialog WHERE refWznmMCard = $1", 1);
	createStatement("TblWznmMDialog_loadRstByCar", "SELECT ref, ixVBasetype, refWznmMCard, refIxVTbl, refUref, refWznmMJob, sref, Comment FROM TblWznmMDialog WHERE refWznmMCard = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMDialog_loadSrfByRef", "SELECT sref FROM TblWznmMDialog WHERE ref = $1", 1);
};

bool PgTblWznmMDialog::loadRec(
			PGresult* res
			, WznmMDialog** rec
		) {
	char* ptr;

	WznmMDialog* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMDialog();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMCard = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMDialog::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMDialog& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMDialog* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMDialog();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMCard = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMDialog::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMDialog** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMDialog::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMDialog::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMDialog& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMDialog::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMDialog::loadRecBySQL(
			const string& sqlstr
			, WznmMDialog** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMDialog::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMDialog::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMDialog& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMDialog::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMDialog::insertRec(
			WznmMDialog* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMCard,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMDialog_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMDialog::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMDialog::insertRst(
			ListWznmMDialog& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMDialog::updateRec(
			WznmMDialog* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMCard,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMDialog_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMDialog::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMDialog::updateRst(
			ListWznmMDialog& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMDialog::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMDialog_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMDialog::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMDialog::loadRecByRef(
			ubigint ref
			, WznmMDialog** rec
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

	return loadRecByStmt("TblWznmMDialog_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMDialog::loadRecByJob(
			ubigint refWznmMJob
			, WznmMDialog** rec
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMDialog_loadRecByJob", 1, vals, l, f, rec);
};

ubigint PgTblWznmMDialog::loadRefsByCar(
			ubigint refWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMDialog_loadRefsByCar", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMDialog::loadRstByCar(
			ubigint refWznmMCard
			, const bool append
			, ListWznmMDialog& rst
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMDialog_loadRstByCar", 1, vals, l, f, append, rst);
};

bool PgTblWznmMDialog::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMDialog_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
