/**
	* \file WznmMStage.cpp
	* database access for table TblWznmMStage (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMStage.h"

#include "WznmMStage_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMStage
 ******************************************************************************/

WznmMStage::WznmMStage(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint jobRefWznmMJob
			, const uint jobNum
			, const ubigint refWznmMSquawk
			, const string sref
			, const uint Monitvl
			, const ubigint snxRefWznmMStage
			, const ubigint fnxRefWznmMStage
			, const ubigint enxRefWznmMStage
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->jobRefWznmMJob = jobRefWznmMJob;
	this->jobNum = jobNum;
	this->refWznmMSquawk = refWznmMSquawk;
	this->sref = sref;
	this->Monitvl = Monitvl;
	this->snxRefWznmMStage = snxRefWznmMStage;
	this->fnxRefWznmMStage = fnxRefWznmMStage;
	this->enxRefWznmMStage = enxRefWznmMStage;
	this->Comment = Comment;
};

bool WznmMStage::operator==(
			const WznmMStage& comp
		) {
	return false;
};

bool WznmMStage::operator!=(
			const WznmMStage& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMStage
 ******************************************************************************/

ListWznmMStage::ListWznmMStage() {
};

ListWznmMStage::ListWznmMStage(
			const ListWznmMStage& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMStage(*(src.nodes[i]));
};

ListWznmMStage::~ListWznmMStage() {
	clear();
};

void ListWznmMStage::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMStage::size() const {
	return(nodes.size());
};

void ListWznmMStage::append(
			WznmMStage* rec
		) {
	nodes.push_back(rec);
};

WznmMStage* ListWznmMStage::operator[](
			const uint ix
		) {
	WznmMStage* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMStage& ListWznmMStage::operator=(
			const ListWznmMStage& src
		) {
	WznmMStage* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMStage(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMStage::operator==(
			const ListWznmMStage& comp
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

bool ListWznmMStage::operator!=(
			const ListWznmMStage& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMStage
 ******************************************************************************/

TblWznmMStage::TblWznmMStage() {
};

TblWznmMStage::~TblWznmMStage() {
};

bool TblWznmMStage::loadRecBySQL(
			const string& sqlstr
			, WznmMStage** rec
		) {
	return false;
};

ubigint TblWznmMStage::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMStage& rst
		) {
	return 0;
};

ubigint TblWznmMStage::insertRec(
			WznmMStage* rec
		) {
	return 0;
};

ubigint TblWznmMStage::insertNewRec(
			WznmMStage** rec
			, const uint ixVBasetype
			, const ubigint jobRefWznmMJob
			, const uint jobNum
			, const ubigint refWznmMSquawk
			, const string sref
			, const uint Monitvl
			, const ubigint snxRefWznmMStage
			, const ubigint fnxRefWznmMStage
			, const ubigint enxRefWznmMStage
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMStage* _rec = NULL;

	_rec = new WznmMStage(0, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMStage::appendNewRecToRst(
			ListWznmMStage& rst
			, WznmMStage** rec
			, const uint ixVBasetype
			, const ubigint jobRefWznmMJob
			, const uint jobNum
			, const ubigint refWznmMSquawk
			, const string sref
			, const uint Monitvl
			, const ubigint snxRefWznmMStage
			, const ubigint fnxRefWznmMStage
			, const ubigint enxRefWznmMStage
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMStage* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMStage::insertRst(
			ListWznmMStage& rst
			, bool transact
		) {
};

void TblWznmMStage::updateRec(
			WznmMStage* rec
		) {
};

void TblWznmMStage::updateRst(
			ListWznmMStage& rst
			, bool transact
		) {
};

void TblWznmMStage::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMStage::loadRecByRef(
			ubigint ref
			, WznmMStage** rec
		) {
	return false;
};

bool TblWznmMStage::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMStage** rec
		) {
	return false;
};

ubigint TblWznmMStage::loadRefsByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMStage::loadRstByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, ListWznmMStage& rst
		) {
	return 0;
};

ubigint TblWznmMStage::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMStage& rst
		) {
	ubigint numload = 0;
	WznmMStage* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMStage
 ******************************************************************************/

MyTblWznmMStage::MyTblWznmMStage() :
			TblWznmMStage()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMStage::~MyTblWznmMStage() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMStage::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMStage (ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMStage SET ixVBasetype = ?, jobRefWznmMJob = ?, jobNum = ?, refWznmMSquawk = ?, sref = ?, Monitvl = ?, snxRefWznmMStage = ?, fnxRefWznmMStage = ?, enxRefWznmMStage = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMStage WHERE ref = ?", false);
};

bool MyTblWznmMStage::loadRecBySQL(
			const string& sqlstr
			, WznmMStage** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMStage* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMStage::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMStage::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMStage();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->jobRefWznmMJob = atoll((char*) dbrow[2]); else _rec->jobRefWznmMJob = 0;
		if (dbrow[3]) _rec->jobNum = atol((char*) dbrow[3]); else _rec->jobNum = 0;
		if (dbrow[4]) _rec->refWznmMSquawk = atoll((char*) dbrow[4]); else _rec->refWznmMSquawk = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Monitvl = atol((char*) dbrow[6]); else _rec->Monitvl = 0;
		if (dbrow[7]) _rec->snxRefWznmMStage = atoll((char*) dbrow[7]); else _rec->snxRefWznmMStage = 0;
		if (dbrow[8]) _rec->fnxRefWznmMStage = atoll((char*) dbrow[8]); else _rec->fnxRefWznmMStage = 0;
		if (dbrow[9]) _rec->enxRefWznmMStage = atoll((char*) dbrow[9]); else _rec->enxRefWznmMStage = 0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMStage::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMStage& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMStage* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMStage::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMStage::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMStage();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->jobRefWznmMJob = atoll((char*) dbrow[2]); else rec->jobRefWznmMJob = 0;
			if (dbrow[3]) rec->jobNum = atol((char*) dbrow[3]); else rec->jobNum = 0;
			if (dbrow[4]) rec->refWznmMSquawk = atoll((char*) dbrow[4]); else rec->refWznmMSquawk = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Monitvl = atol((char*) dbrow[6]); else rec->Monitvl = 0;
			if (dbrow[7]) rec->snxRefWznmMStage = atoll((char*) dbrow[7]); else rec->snxRefWznmMStage = 0;
			if (dbrow[8]) rec->fnxRefWznmMStage = atoll((char*) dbrow[8]); else rec->fnxRefWznmMStage = 0;
			if (dbrow[9]) rec->enxRefWznmMStage = atoll((char*) dbrow[9]); else rec->enxRefWznmMStage = 0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMStage::insertRec(
			WznmMStage* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jobRefWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jobNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMSquawk,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->Monitvl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->snxRefWznmMStage,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->fnxRefWznmMStage,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->enxRefWznmMStage,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMStage::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMStage::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMStage::insertRst(
			ListWznmMStage& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMStage::updateRec(
			WznmMStage* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jobRefWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jobNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMSquawk,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->Monitvl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->snxRefWznmMStage,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->fnxRefWznmMStage,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->enxRefWznmMStage,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMStage::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMStage::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMStage::updateRst(
			ListWznmMStage& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMStage::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMStage::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMStage::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMStage::loadRecByRef(
			ubigint ref
			, WznmMStage** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMStage WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMStage::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMStage** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment FROM TblWznmMStage WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + "", rec);
};

ubigint MyTblWznmMStage::loadRefsByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(jobRefWznmMJob) + "", append, refs);
};

ubigint MyTblWznmMStage::loadRstByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, ListWznmMStage& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(jobRefWznmMJob) + " ORDER BY jobNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMStage
 ******************************************************************************/

PgTblWznmMStage::PgTblWznmMStage() :
			TblWznmMStage()
			, PgTable()
		{
};

PgTblWznmMStage::~PgTblWznmMStage() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMStage::initStatements() {
	createStatement("TblWznmMStage_insertRec", "INSERT INTO TblWznmMStage (ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWznmMStage_updateRec", "UPDATE TblWznmMStage SET ixVBasetype = $1, jobRefWznmMJob = $2, jobNum = $3, refWznmMSquawk = $4, sref = $5, Monitvl = $6, snxRefWznmMStage = $7, fnxRefWznmMStage = $8, enxRefWznmMStage = $9, Comment = $10 WHERE ref = $11", 11);
	createStatement("TblWznmMStage_removeRecByRef", "DELETE FROM TblWznmMStage WHERE ref = $1", 1);

	createStatement("TblWznmMStage_loadRecByRef", "SELECT ref, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment FROM TblWznmMStage WHERE ref = $1", 1);
	createStatement("TblWznmMStage_loadRecBySqk", "SELECT ref, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment FROM TblWznmMStage WHERE refWznmMSquawk = $1", 1);
	createStatement("TblWznmMStage_loadRefsByJob", "SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = $1", 1);
	createStatement("TblWznmMStage_loadRstByJob", "SELECT ref, ixVBasetype, jobRefWznmMJob, jobNum, refWznmMSquawk, sref, Monitvl, snxRefWznmMStage, fnxRefWznmMStage, enxRefWznmMStage, Comment FROM TblWznmMStage WHERE jobRefWznmMJob = $1 ORDER BY jobNum ASC", 1);
};

bool PgTblWznmMStage::loadRec(
			PGresult* res
			, WznmMStage** rec
		) {
	char* ptr;

	WznmMStage* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMStage();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "jobrefwznmmjob"),
			PQfnumber(res, "jobnum"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "monitvl"),
			PQfnumber(res, "snxrefwznmmstage"),
			PQfnumber(res, "fnxrefwznmmstage"),
			PQfnumber(res, "enxrefwznmmstage"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jobRefWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jobNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMSquawk = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Monitvl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->snxRefWznmMStage = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->fnxRefWznmMStage = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->enxRefWznmMStage = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMStage::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMStage& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMStage* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "jobrefwznmmjob"),
			PQfnumber(res, "jobnum"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "monitvl"),
			PQfnumber(res, "snxrefwznmmstage"),
			PQfnumber(res, "fnxrefwznmmstage"),
			PQfnumber(res, "enxrefwznmmstage"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMStage();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jobRefWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jobNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMSquawk = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Monitvl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->snxRefWznmMStage = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->fnxRefWznmMStage = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->enxRefWznmMStage = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMStage::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMStage** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStage::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMStage::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMStage& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStage::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMStage::loadRecBySQL(
			const string& sqlstr
			, WznmMStage** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStage::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMStage::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMStage& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStage::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMStage::insertRec(
			WznmMStage* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _jobRefWznmMJob = htonl64(rec->jobRefWznmMJob);
	uint _jobNum = htonl(rec->jobNum);
	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	uint _Monitvl = htonl(rec->Monitvl);
	ubigint _snxRefWznmMStage = htonl64(rec->snxRefWznmMStage);
	ubigint _fnxRefWznmMStage = htonl64(rec->fnxRefWznmMStage);
	ubigint _enxRefWznmMStage = htonl64(rec->enxRefWznmMStage);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_jobRefWznmMJob,
		(char*) &_jobNum,
		(char*) &_refWznmMSquawk,
		rec->sref.c_str(),
		(char*) &_Monitvl,
		(char*) &_snxRefWznmMStage,
		(char*) &_fnxRefWznmMStage,
		(char*) &_enxRefWznmMStage,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMStage_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMStage::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMStage::insertRst(
			ListWznmMStage& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMStage::updateRec(
			WznmMStage* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _jobRefWznmMJob = htonl64(rec->jobRefWznmMJob);
	uint _jobNum = htonl(rec->jobNum);
	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	uint _Monitvl = htonl(rec->Monitvl);
	ubigint _snxRefWznmMStage = htonl64(rec->snxRefWznmMStage);
	ubigint _fnxRefWznmMStage = htonl64(rec->fnxRefWznmMStage);
	ubigint _enxRefWznmMStage = htonl64(rec->enxRefWznmMStage);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_jobRefWznmMJob,
		(char*) &_jobNum,
		(char*) &_refWznmMSquawk,
		rec->sref.c_str(),
		(char*) &_Monitvl,
		(char*) &_snxRefWznmMStage,
		(char*) &_fnxRefWznmMStage,
		(char*) &_enxRefWznmMStage,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMStage_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMStage::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMStage::updateRst(
			ListWznmMStage& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMStage::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMStage_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMStage::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMStage::loadRecByRef(
			ubigint ref
			, WznmMStage** rec
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

	return loadRecByStmt("TblWznmMStage_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMStage::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMStage** rec
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMStage_loadRecBySqk", 1, vals, l, f, rec);
};

ubigint PgTblWznmMStage::loadRefsByJob(
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

	return loadRefsByStmt("TblWznmMStage_loadRefsByJob", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMStage::loadRstByJob(
			ubigint jobRefWznmMJob
			, const bool append
			, ListWznmMStage& rst
		) {
	ubigint _jobRefWznmMJob = htonl64(jobRefWznmMJob);

	const char* vals[] = {
		(char*) &_jobRefWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMStage_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

