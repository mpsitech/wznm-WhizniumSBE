/**
	* \file WznmMJob.cpp
	* database access for table TblWznmMJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMJob.h"

#include "WznmMJob_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMJob
 ******************************************************************************/

WznmMJob::WznmMJob(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const string sref
			, const bool Global
			, const bool Clisrv
			, const bool Shrdat
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->sref = sref;
	this->Global = Global;
	this->Clisrv = Clisrv;
	this->Shrdat = Shrdat;
	this->Comment = Comment;
};

bool WznmMJob::operator==(
			const WznmMJob& comp
		) {
	return false;
};

bool WznmMJob::operator!=(
			const WznmMJob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMJob
 ******************************************************************************/

ListWznmMJob::ListWznmMJob() {
};

ListWznmMJob::ListWznmMJob(
			const ListWznmMJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMJob(*(src.nodes[i]));
};

ListWznmMJob::~ListWznmMJob() {
	clear();
};

void ListWznmMJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMJob::size() const {
	return(nodes.size());
};

void ListWznmMJob::append(
			WznmMJob* rec
		) {
	nodes.push_back(rec);
};

WznmMJob* ListWznmMJob::operator[](
			const uint ix
		) {
	WznmMJob* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMJob& ListWznmMJob::operator=(
			const ListWznmMJob& src
		) {
	WznmMJob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMJob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMJob::operator==(
			const ListWznmMJob& comp
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

bool ListWznmMJob::operator!=(
			const ListWznmMJob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMJob
 ******************************************************************************/

TblWznmMJob::TblWznmMJob() {
};

TblWznmMJob::~TblWznmMJob() {
};

bool TblWznmMJob::loadRecBySQL(
			const string& sqlstr
			, WznmMJob** rec
		) {
	return false;
};

ubigint TblWznmMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMJob& rst
		) {
	return 0;
};

ubigint TblWznmMJob::insertRec(
			WznmMJob* rec
		) {
	return 0;
};

ubigint TblWznmMJob::insertNewRec(
			WznmMJob** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const string sref
			, const bool Global
			, const bool Clisrv
			, const bool Shrdat
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMJob* _rec = NULL;

	_rec = new WznmMJob(0, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMJob::appendNewRecToRst(
			ListWznmMJob& rst
			, WznmMJob** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const string sref
			, const bool Global
			, const bool Clisrv
			, const bool Shrdat
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMJob* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMJob::insertRst(
			ListWznmMJob& rst
			, bool transact
		) {
};

void TblWznmMJob::updateRec(
			WznmMJob* rec
		) {
};

void TblWznmMJob::updateRst(
			ListWznmMJob& rst
			, bool transact
		) {
};

void TblWznmMJob::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMJob::loadRecByRef(
			ubigint ref
			, WznmMJob** rec
		) {
	return false;
};

bool TblWznmMJob::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMJob** rec
		) {
	return false;
};

bool TblWznmMJob::loadRefByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, ubigint& ref
		) {
	return false;
};

bool TblWznmMJob::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMJob::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMJob& rst
		) {
	return 0;
};

bool TblWznmMJob::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMJob::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMJob& rst
		) {
	ubigint numload = 0;
	WznmMJob* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMJob
 ******************************************************************************/

MyTblWznmMJob::MyTblWznmMJob() :
			TblWznmMJob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMJob::~MyTblWznmMJob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMJob (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMJob SET ixVBasetype = ?, refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, sref = ?, Global = ?, Clisrv = ?, Shrdat = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMJob WHERE ref = ?", false);
};

bool MyTblWznmMJob::loadRecBySQL(
			const string& sqlstr
			, WznmMJob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMJob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMJob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMJob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMJob();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Global = (atoi((char*) dbrow[6]) != 0); else _rec->Global = false;
		if (dbrow[7]) _rec->Clisrv = (atoi((char*) dbrow[7]) != 0); else _rec->Clisrv = false;
		if (dbrow[8]) _rec->Shrdat = (atoi((char*) dbrow[8]) != 0); else _rec->Shrdat = false;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMJob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMJob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMJob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMJob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMJob();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Global = (atoi((char*) dbrow[6]) != 0); else rec->Global = false;
			if (dbrow[7]) rec->Clisrv = (atoi((char*) dbrow[7]) != 0); else rec->Clisrv = false;
			if (dbrow[8]) rec->Shrdat = (atoi((char*) dbrow[8]) != 0); else rec->Shrdat = false;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMJob::insertRec(
			WznmMJob* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	tinyint Global = rec->Global;
	tinyint Clisrv = rec->Clisrv;
	tinyint Shrdat = rec->Shrdat;
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Global,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Clisrv,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Shrdat,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMJob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMJob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMJob::insertRst(
			ListWznmMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMJob::updateRec(
			WznmMJob* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	tinyint Global = rec->Global;
	tinyint Clisrv = rec->Clisrv;
	tinyint Shrdat = rec->Shrdat;
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Global,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Clisrv,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Shrdat,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMJob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMJob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMJob::updateRst(
			ListWznmMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMJob::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMJob::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMJob::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMJob::loadRecByRef(
			ubigint ref
			, WznmMJob** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMJob WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMJob::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMJob** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment FROM TblWznmMJob WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", rec);
};

bool MyTblWznmMJob::loadRefByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + "", ref);
};

bool MyTblWznmMJob::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMJob::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMJob& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMJob::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMJob WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMJob
 ******************************************************************************/

PgTblWznmMJob::PgTblWznmMJob() :
			TblWznmMJob()
			, PgTable()
		{
};

PgTblWznmMJob::~PgTblWznmMJob() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMJob::initStatements() {
	createStatement("TblWznmMJob_insertRec", "INSERT INTO TblWznmMJob (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWznmMJob_updateRec", "UPDATE TblWznmMJob SET ixVBasetype = $1, refWznmMVersion = $2, refIxVTbl = $3, refUref = $4, sref = $5, Global = $6, Clisrv = $7, Shrdat = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWznmMJob_removeRecByRef", "DELETE FROM TblWznmMJob WHERE ref = $1", 1);

	createStatement("TblWznmMJob_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment FROM TblWznmMJob WHERE ref = $1", 1);
	createStatement("TblWznmMJob_loadRecByRetReu", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment FROM TblWznmMJob WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWznmMJob_loadRefByTypVer", "SELECT ref FROM TblWznmMJob WHERE ixVBasetype = $1 AND refWznmMVersion = $2", 2);
	createStatement("TblWznmMJob_loadRefByVerSrf", "SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMJob_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, sref, Global, Clisrv, Shrdat, Comment FROM TblWznmMJob WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMJob_loadSrfByRef", "SELECT sref FROM TblWznmMJob WHERE ref = $1", 1);
};

bool PgTblWznmMJob::loadRec(
			PGresult* res
			, WznmMJob** rec
		) {
	char* ptr;

	WznmMJob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMJob();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "global"),
			PQfnumber(res, "clisrv"),
			PQfnumber(res, "shrdat"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Global = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Clisrv = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Shrdat = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMJob::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMJob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMJob* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "global"),
			PQfnumber(res, "clisrv"),
			PQfnumber(res, "shrdat"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMJob();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Global = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Clisrv = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Shrdat = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMJob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMJob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMJob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMJob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMJob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMJob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMJob::loadRecBySQL(
			const string& sqlstr
			, WznmMJob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMJob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMJob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMJob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMJob::insertRec(
			WznmMJob* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	smallint _Global = htons((smallint) rec->Global);
	smallint _Clisrv = htons((smallint) rec->Clisrv);
	smallint _Shrdat = htons((smallint) rec->Shrdat);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->sref.c_str(),
		(char*) &_Global,
		(char*) &_Clisrv,
		(char*) &_Shrdat,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(smallint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMJob_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMJob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMJob::insertRst(
			ListWznmMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMJob::updateRec(
			WznmMJob* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	smallint _Global = htons((smallint) rec->Global);
	smallint _Clisrv = htons((smallint) rec->Clisrv);
	smallint _Shrdat = htons((smallint) rec->Shrdat);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->sref.c_str(),
		(char*) &_Global,
		(char*) &_Clisrv,
		(char*) &_Shrdat,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(smallint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMJob_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMJob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMJob::updateRst(
			ListWznmMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMJob::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMJob_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMJob::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMJob::loadRecByRef(
			ubigint ref
			, WznmMJob** rec
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

	return loadRecByStmt("TblWznmMJob_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMJob::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMJob** rec
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

	return loadRecByStmt("TblWznmMJob_loadRecByRetReu", 2, vals, l, f, rec);
};

bool PgTblWznmMJob::loadRefByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, ubigint& ref
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefByStmt("TblWznmMJob_loadRefByTypVer", 2, vals, l, f, ref);
};

bool PgTblWznmMJob::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWznmMJob_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMJob::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMJob& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMJob_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMJob::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMJob_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

