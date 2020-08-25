/**
	* \file WznmAMJobVar.cpp
	* database access for table TblWznmAMJobVar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmAMJobVar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMJobVar
 ******************************************************************************/

WznmAMJobVar::WznmAMJobVar(
			const ubigint ref
			, const ubigint refWznmCAMJobVar
			, const ubigint jobRefWznmMJob
			, const uint jobNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const uint Length
			, const bool Shr
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmCAMJobVar = refWznmCAMJobVar;
	this->jobRefWznmMJob = jobRefWznmMJob;
	this->jobNum = jobNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->Length = Length;
	this->Shr = Shr;
	this->Comment = Comment;
};

bool WznmAMJobVar::operator==(
			const WznmAMJobVar& comp
		) {
	return false;
};

bool WznmAMJobVar::operator!=(
			const WznmAMJobVar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMJobVar
 ******************************************************************************/

ListWznmAMJobVar::ListWznmAMJobVar() {
};

ListWznmAMJobVar::ListWznmAMJobVar(
			const ListWznmAMJobVar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMJobVar(*(src.nodes[i]));
};

ListWznmAMJobVar::~ListWznmAMJobVar() {
	clear();
};

void ListWznmAMJobVar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMJobVar::size() const {
	return(nodes.size());
};

void ListWznmAMJobVar::append(
			WznmAMJobVar* rec
		) {
	nodes.push_back(rec);
};

WznmAMJobVar* ListWznmAMJobVar::operator[](
			const uint ix
		) {
	WznmAMJobVar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMJobVar& ListWznmAMJobVar::operator=(
			const ListWznmAMJobVar& src
		) {
	WznmAMJobVar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMJobVar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMJobVar::operator==(
			const ListWznmAMJobVar& comp
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

bool ListWznmAMJobVar::operator!=(
			const ListWznmAMJobVar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMJobVar
 ******************************************************************************/

TblWznmAMJobVar::TblWznmAMJobVar() {
};

TblWznmAMJobVar::~TblWznmAMJobVar() {
};

bool TblWznmAMJobVar::loadRecBySQL(
			const string& sqlstr
			, WznmAMJobVar** rec
		) {
	return false;
};

ubigint TblWznmAMJobVar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	return 0;
};

ubigint TblWznmAMJobVar::insertRec(
			WznmAMJobVar* rec
		) {
	return 0;
};

ubigint TblWznmAMJobVar::insertNewRec(
			WznmAMJobVar** rec
			, const ubigint refWznmCAMJobVar
			, const ubigint jobRefWznmMJob
			, const uint jobNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const uint Length
			, const bool Shr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMJobVar* _rec = NULL;

	_rec = new WznmAMJobVar(0, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMJobVar::appendNewRecToRst(
			ListWznmAMJobVar& rst
			, WznmAMJobVar** rec
			, const ubigint refWznmCAMJobVar
			, const ubigint jobRefWznmMJob
			, const uint jobNum
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMVector
			, const uint Length
			, const bool Shr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMJobVar* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMJobVar::insertRst(
			ListWznmAMJobVar& rst
			, bool transact
		) {
};

void TblWznmAMJobVar::updateRec(
			WznmAMJobVar* rec
		) {
};

void TblWznmAMJobVar::updateRst(
			ListWznmAMJobVar& rst
			, bool transact
		) {
};

void TblWznmAMJobVar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMJobVar::loadRecByRef(
			ubigint ref
			, WznmAMJobVar** rec
		) {
	return false;
};

ubigint TblWznmAMJobVar::loadRefsByClu(
			ubigint refWznmCAMJobVar
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMJobVar::loadRefsByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMJobVar::loadRstByClu(
			ubigint refWznmCAMJobVar
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	return 0;
};

ubigint TblWznmAMJobVar::loadRstByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	return 0;
};

ubigint TblWznmAMJobVar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	ubigint numload = 0;
	WznmAMJobVar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMJobVar
 ******************************************************************************/

MyTblWznmAMJobVar::MyTblWznmAMJobVar() :
			TblWznmAMJobVar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMJobVar::~MyTblWznmAMJobVar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMJobVar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMJobVar (refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMJobVar SET refWznmCAMJobVar = ?, jobRefWznmMJob = ?, jobNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Length = ?, Shr = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMJobVar WHERE ref = ?", false);
};

bool MyTblWznmAMJobVar::loadRecBySQL(
			const string& sqlstr
			, WznmAMJobVar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMJobVar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMJobVar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMJobVar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMJobVar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmCAMJobVar = atoll((char*) dbrow[1]); else _rec->refWznmCAMJobVar = 0;
		if (dbrow[2]) _rec->jobRefWznmMJob = atoll((char*) dbrow[2]); else _rec->jobRefWznmMJob = 0;
		if (dbrow[3]) _rec->jobNum = atol((char*) dbrow[3]); else _rec->jobNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixWznmVVartype = atol((char*) dbrow[5]); else _rec->ixWznmVVartype = 0;
		if (dbrow[6]) _rec->refWznmMVector = atoll((char*) dbrow[6]); else _rec->refWznmMVector = 0;
		if (dbrow[7]) _rec->Length = atol((char*) dbrow[7]); else _rec->Length = 0;
		if (dbrow[8]) _rec->Shr = (atoi((char*) dbrow[8]) != 0); else _rec->Shr = false;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMJobVar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMJobVar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMJobVar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMJobVar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMJobVar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmCAMJobVar = atoll((char*) dbrow[1]); else rec->refWznmCAMJobVar = 0;
			if (dbrow[2]) rec->jobRefWznmMJob = atoll((char*) dbrow[2]); else rec->jobRefWznmMJob = 0;
			if (dbrow[3]) rec->jobNum = atol((char*) dbrow[3]); else rec->jobNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixWznmVVartype = atol((char*) dbrow[5]); else rec->ixWznmVVartype = 0;
			if (dbrow[6]) rec->refWznmMVector = atoll((char*) dbrow[6]); else rec->refWznmMVector = 0;
			if (dbrow[7]) rec->Length = atol((char*) dbrow[7]); else rec->Length = 0;
			if (dbrow[8]) rec->Shr = (atoi((char*) dbrow[8]) != 0); else rec->Shr = false;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMJobVar::insertRec(
			WznmAMJobVar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	tinyint Shr = rec->Shr;
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMJobVar,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jobRefWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jobNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Length,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Shr,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMJobVar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMJobVar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMJobVar::insertRst(
			ListWznmAMJobVar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMJobVar::updateRec(
			WznmAMJobVar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	tinyint Shr = rec->Shr;
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMJobVar,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jobRefWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jobNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVVartype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Length,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Shr,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMJobVar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMJobVar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMJobVar::updateRst(
			ListWznmAMJobVar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMJobVar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMJobVar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMJobVar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMJobVar::loadRecByRef(
			ubigint ref
			, WznmAMJobVar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMJobVar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMJobVar::loadRefsByClu(
			ubigint refWznmCAMJobVar
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMJobVar WHERE refWznmCAMJobVar = " + to_string(refWznmCAMJobVar) + "", append, refs);
};

ubigint MyTblWznmAMJobVar::loadRefsByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMJobVar WHERE jobRefWznmMJob = " + to_string(jobRefWznmMJob) + "", append, refs);
};

ubigint MyTblWznmAMJobVar::loadRstByClu(
			ubigint refWznmCAMJobVar
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmAMJobVar WHERE refWznmCAMJobVar = " + to_string(refWznmCAMJobVar) + "", append, rst);
};

ubigint MyTblWznmAMJobVar::loadRstByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmAMJobVar WHERE jobRefWznmMJob = " + to_string(jobRefWznmMJob) + " ORDER BY jobNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMJobVar
 ******************************************************************************/

PgTblWznmAMJobVar::PgTblWznmAMJobVar() :
			TblWznmAMJobVar()
			, PgTable()
		{
};

PgTblWznmAMJobVar::~PgTblWznmAMJobVar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMJobVar::initStatements() {
	createStatement("TblWznmAMJobVar_insertRec", "INSERT INTO TblWznmAMJobVar (refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWznmAMJobVar_updateRec", "UPDATE TblWznmAMJobVar SET refWznmCAMJobVar = $1, jobRefWznmMJob = $2, jobNum = $3, sref = $4, ixWznmVVartype = $5, refWznmMVector = $6, Length = $7, Shr = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWznmAMJobVar_removeRecByRef", "DELETE FROM TblWznmAMJobVar WHERE ref = $1", 1);

	createStatement("TblWznmAMJobVar_loadRecByRef", "SELECT ref, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmAMJobVar WHERE ref = $1", 1);
	createStatement("TblWznmAMJobVar_loadRefsByClu", "SELECT ref FROM TblWznmAMJobVar WHERE refWznmCAMJobVar = $1", 1);
	createStatement("TblWznmAMJobVar_loadRefsByJob", "SELECT ref FROM TblWznmAMJobVar WHERE jobRefWznmMJob = $1", 1);
	createStatement("TblWznmAMJobVar_loadRstByClu", "SELECT ref, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmAMJobVar WHERE refWznmCAMJobVar = $1", 1);
	createStatement("TblWznmAMJobVar_loadRstByJob", "SELECT ref, refWznmCAMJobVar, jobRefWznmMJob, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmAMJobVar WHERE jobRefWznmMJob = $1 ORDER BY jobNum ASC", 1);
};

bool PgTblWznmAMJobVar::loadRec(
			PGresult* res
			, WznmAMJobVar** rec
		) {
	char* ptr;

	WznmAMJobVar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMJobVar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamjobvar"),
			PQfnumber(res, "jobrefwznmmjob"),
			PQfnumber(res, "jobnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "shr"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmCAMJobVar = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jobRefWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jobNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Length = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Shr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMJobVar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMJobVar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamjobvar"),
			PQfnumber(res, "jobrefwznmmjob"),
			PQfnumber(res, "jobnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "shr"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMJobVar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmCAMJobVar = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jobRefWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jobNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Length = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Shr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMJobVar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMJobVar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobVar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMJobVar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobVar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMJobVar::loadRecBySQL(
			const string& sqlstr
			, WznmAMJobVar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobVar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMJobVar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobVar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMJobVar::insertRec(
			WznmAMJobVar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmCAMJobVar = htonl64(rec->refWznmCAMJobVar);
	ubigint _jobRefWznmMJob = htonl64(rec->jobRefWznmMJob);
	uint _jobNum = htonl(rec->jobNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);
	smallint _Shr = htons((smallint) rec->Shr);

	const char* vals[] = {
		(char*) &_refWznmCAMJobVar,
		(char*) &_jobRefWznmMJob,
		(char*) &_jobNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
		(char*) &_Shr,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMJobVar_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMJobVar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMJobVar::insertRst(
			ListWznmAMJobVar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMJobVar::updateRec(
			WznmAMJobVar* rec
		) {
	PGresult* res;

	ubigint _refWznmCAMJobVar = htonl64(rec->refWznmCAMJobVar);
	ubigint _jobRefWznmMJob = htonl64(rec->jobRefWznmMJob);
	uint _jobNum = htonl(rec->jobNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);
	smallint _Shr = htons((smallint) rec->Shr);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmCAMJobVar,
		(char*) &_jobRefWznmMJob,
		(char*) &_jobNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
		(char*) &_Shr,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMJobVar_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMJobVar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMJobVar::updateRst(
			ListWznmAMJobVar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMJobVar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMJobVar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMJobVar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMJobVar::loadRecByRef(
			ubigint ref
			, WznmAMJobVar** rec
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

	return loadRecByStmt("TblWznmAMJobVar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMJobVar::loadRefsByClu(
			ubigint refWznmCAMJobVar
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCAMJobVar = htonl64(refWznmCAMJobVar);

	const char* vals[] = {
		(char*) &_refWznmCAMJobVar
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMJobVar_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMJobVar::loadRefsByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _jobRefWznmMJob = htonl64(jobRefWznmMJob);

	const char* vals[] = {
		(char*) &_jobRefWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMJobVar_loadRefsByJob", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMJobVar::loadRstByClu(
			ubigint refWznmCAMJobVar
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	ubigint _refWznmCAMJobVar = htonl64(refWznmCAMJobVar);

	const char* vals[] = {
		(char*) &_refWznmCAMJobVar
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMJobVar_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMJobVar::loadRstByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, ListWznmAMJobVar& rst
		) {
	ubigint _jobRefWznmMJob = htonl64(jobRefWznmMJob);

	const char* vals[] = {
		(char*) &_jobRefWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMJobVar_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

