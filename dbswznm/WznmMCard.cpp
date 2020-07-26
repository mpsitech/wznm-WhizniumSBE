/**
	* \file WznmMCard.cpp
	* database access for table TblWznmMCard (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMCard.h"

#include "WznmMCard_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMCard
 ******************************************************************************/

WznmMCard::WznmMCard(
			const ubigint ref
			, const ubigint mdlRefWznmMModule
			, const uint mdlNum
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const string Avail
			, const string Active
		) {

	this->ref = ref;
	this->mdlRefWznmMModule = mdlRefWznmMModule;
	this->mdlNum = mdlNum;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refWznmMJob = refWznmMJob;
	this->sref = sref;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->Avail = Avail;
	this->Active = Active;
};

bool WznmMCard::operator==(
			const WznmMCard& comp
		) {
	return false;
};

bool WznmMCard::operator!=(
			const WznmMCard& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMCard
 ******************************************************************************/

ListWznmMCard::ListWznmMCard() {
};

ListWznmMCard::ListWznmMCard(
			const ListWznmMCard& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMCard(*(src.nodes[i]));
};

ListWznmMCard::~ListWznmMCard() {
	clear();
};

void ListWznmMCard::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMCard::size() const {
	return(nodes.size());
};

void ListWznmMCard::append(
			WznmMCard* rec
		) {
	nodes.push_back(rec);
};

WznmMCard* ListWznmMCard::operator[](
			const uint ix
		) {
	WznmMCard* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMCard& ListWznmMCard::operator=(
			const ListWznmMCard& src
		) {
	WznmMCard* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMCard(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMCard::operator==(
			const ListWznmMCard& comp
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

bool ListWznmMCard::operator!=(
			const ListWznmMCard& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMCard
 ******************************************************************************/

TblWznmMCard::TblWznmMCard() {
};

TblWznmMCard::~TblWznmMCard() {
};

bool TblWznmMCard::loadRecBySQL(
			const string& sqlstr
			, WznmMCard** rec
		) {
	return false;
};

ubigint TblWznmMCard::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCard& rst
		) {
	return 0;
};

ubigint TblWznmMCard::insertRec(
			WznmMCard* rec
		) {
	return 0;
};

ubigint TblWznmMCard::insertNewRec(
			WznmMCard** rec
			, const ubigint mdlRefWznmMModule
			, const uint mdlNum
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const string Avail
			, const string Active
		) {
	ubigint retval = 0;
	WznmMCard* _rec = NULL;

	_rec = new WznmMCard(0, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMCard::appendNewRecToRst(
			ListWznmMCard& rst
			, WznmMCard** rec
			, const ubigint mdlRefWznmMModule
			, const uint mdlNum
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const string Avail
			, const string Active
		) {
	ubigint retval = 0;
	WznmMCard* _rec = NULL;

	retval = insertNewRec(&_rec, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMCard::insertRst(
			ListWznmMCard& rst
			, bool transact
		) {
};

void TblWznmMCard::updateRec(
			WznmMCard* rec
		) {
};

void TblWznmMCard::updateRst(
			ListWznmMCard& rst
			, bool transact
		) {
};

void TblWznmMCard::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMCard::loadRecByRef(
			ubigint ref
			, WznmMCard** rec
		) {
	return false;
};

bool TblWznmMCard::loadRecByJob(
			ubigint refWznmMJob
			, WznmMCard** rec
		) {
	return false;
};

bool TblWznmMCard::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMCard** rec
		) {
	return false;
};

ubigint TblWznmMCard::loadRefsByMdl(
			ubigint mdlRefWznmMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMCard::loadRstByMdl(
			ubigint mdlRefWznmMModule
			, const bool append
			, ListWznmMCard& rst
		) {
	return 0;
};

bool TblWznmMCard::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMCard::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMCard& rst
		) {
	ubigint numload = 0;
	WznmMCard* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMCard
 ******************************************************************************/

MyTblWznmMCard::MyTblWznmMCard() :
			TblWznmMCard()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMCard::~MyTblWznmMCard() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMCard::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMCard (mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMCard SET mdlRefWznmMModule = ?, mdlNum = ?, refIxVTbl = ?, refUref = ?, refWznmMJob = ?, sref = ?, refJTitle = ?, Title = ?, Avail = ?, Active = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMCard WHERE ref = ?", false);
};

bool MyTblWznmMCard::loadRecBySQL(
			const string& sqlstr
			, WznmMCard** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMCard* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCard::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCard::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMCard();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->mdlRefWznmMModule = atoll((char*) dbrow[1]); else _rec->mdlRefWznmMModule = 0;
		if (dbrow[2]) _rec->mdlNum = atol((char*) dbrow[2]); else _rec->mdlNum = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->refWznmMJob = atoll((char*) dbrow[5]); else _rec->refWznmMJob = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJTitle = atoll((char*) dbrow[7]); else _rec->refJTitle = 0;
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";
		if (dbrow[9]) _rec->Avail.assign(dbrow[9], dblengths[9]); else _rec->Avail = "";
		if (dbrow[10]) _rec->Active.assign(dbrow[10], dblengths[10]); else _rec->Active = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMCard::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCard& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMCard* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCard::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCard::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMCard();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->mdlRefWznmMModule = atoll((char*) dbrow[1]); else rec->mdlRefWznmMModule = 0;
			if (dbrow[2]) rec->mdlNum = atol((char*) dbrow[2]); else rec->mdlNum = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->refWznmMJob = atoll((char*) dbrow[5]); else rec->refWznmMJob = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJTitle = atoll((char*) dbrow[7]); else rec->refJTitle = 0;
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			if (dbrow[9]) rec->Avail.assign(dbrow[9], dblengths[9]); else rec->Avail = "";
			if (dbrow[10]) rec->Active.assign(dbrow[10], dblengths[10]); else rec->Active = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMCard::insertRec(
			WznmMCard* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->sref.length();
	l[7] = rec->Title.length();
	l[8] = rec->Avail.length();
	l[9] = rec->Active.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->mdlRefWznmMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->mdlNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMJob,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJTitle,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Active.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMCard::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMCard::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMCard::insertRst(
			ListWznmMCard& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMCard::updateRec(
			WznmMCard* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->sref.length();
	l[7] = rec->Title.length();
	l[8] = rec->Avail.length();
	l[9] = rec->Active.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->mdlRefWznmMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->mdlNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMJob,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJTitle,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Active.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMCard::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMCard::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMCard::updateRst(
			ListWznmMCard& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMCard::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMCard::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMCard::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMCard::loadRecByRef(
			ubigint ref
			, WznmMCard** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMCard WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMCard::loadRecByJob(
			ubigint refWznmMJob
			, WznmMCard** rec
		) {
	return loadRecBySQL("SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE refWznmMJob = " + to_string(refWznmMJob) + "", rec);
};

bool MyTblWznmMCard::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMCard** rec
		) {
	return loadRecBySQL("SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", rec);
};

ubigint MyTblWznmMCard::loadRefsByMdl(
			ubigint mdlRefWznmMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMCard WHERE mdlRefWznmMModule = " + to_string(mdlRefWznmMModule) + "", append, refs);
};

ubigint MyTblWznmMCard::loadRstByMdl(
			ubigint mdlRefWznmMModule
			, const bool append
			, ListWznmMCard& rst
		) {
	return loadRstBySQL("SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE mdlRefWznmMModule = " + to_string(mdlRefWznmMModule) + " ORDER BY mdlNum ASC", append, rst);
};

bool MyTblWznmMCard::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMCard WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMCard
 ******************************************************************************/

PgTblWznmMCard::PgTblWznmMCard() :
			TblWznmMCard()
			, PgTable()
		{
};

PgTblWznmMCard::~PgTblWznmMCard() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMCard::initStatements() {
	createStatement("TblWznmMCard_insertRec", "INSERT INTO TblWznmMCard (mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWznmMCard_updateRec", "UPDATE TblWznmMCard SET mdlRefWznmMModule = $1, mdlNum = $2, refIxVTbl = $3, refUref = $4, refWznmMJob = $5, sref = $6, refJTitle = $7, Title = $8, Avail = $9, Active = $10 WHERE ref = $11", 11);
	createStatement("TblWznmMCard_removeRecByRef", "DELETE FROM TblWznmMCard WHERE ref = $1", 1);

	createStatement("TblWznmMCard_loadRecByRef", "SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE ref = $1", 1);
	createStatement("TblWznmMCard_loadRecByJob", "SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMCard_loadRecByRetReu", "SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWznmMCard_loadRefsByMdl", "SELECT ref FROM TblWznmMCard WHERE mdlRefWznmMModule = $1", 1);
	createStatement("TblWznmMCard_loadRstByMdl", "SELECT ref, mdlRefWznmMModule, mdlNum, refIxVTbl, refUref, refWznmMJob, sref, refJTitle, Title, Avail, Active FROM TblWznmMCard WHERE mdlRefWznmMModule = $1 ORDER BY mdlNum ASC", 1);
	createStatement("TblWznmMCard_loadSrfByRef", "SELECT sref FROM TblWznmMCard WHERE ref = $1", 1);
};

bool PgTblWznmMCard::loadRec(
			PGresult* res
			, WznmMCard** rec
		) {
	char* ptr;

	WznmMCard* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMCard();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "mdlrefwznmmmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "active")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->mdlRefWznmMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->mdlNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Active.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMCard::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMCard& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMCard* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "mdlrefwznmmmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "active")
		};

		while (numread < numrow) {
			rec = new WznmMCard();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->mdlRefWznmMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->mdlNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Active.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMCard::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMCard** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCard::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCard::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMCard& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCard::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMCard::loadRecBySQL(
			const string& sqlstr
			, WznmMCard** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCard::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCard::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCard& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCard::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMCard::insertRec(
			WznmMCard* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _mdlRefWznmMModule = htonl64(rec->mdlRefWznmMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		(char*) &_mdlRefWznmMModule,
		(char*) &_mdlNum,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		rec->Avail.c_str(),
		rec->Active.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMCard_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCard::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMCard::insertRst(
			ListWznmMCard& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMCard::updateRec(
			WznmMCard* rec
		) {
	PGresult* res;

	ubigint _mdlRefWznmMModule = htonl64(rec->mdlRefWznmMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_mdlRefWznmMModule,
		(char*) &_mdlNum,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		rec->Avail.c_str(),
		rec->Active.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMCard_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCard::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMCard::updateRst(
			ListWznmMCard& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMCard::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMCard_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCard::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMCard::loadRecByRef(
			ubigint ref
			, WznmMCard** rec
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

	return loadRecByStmt("TblWznmMCard_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMCard::loadRecByJob(
			ubigint refWznmMJob
			, WznmMCard** rec
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMCard_loadRecByJob", 1, vals, l, f, rec);
};

bool PgTblWznmMCard::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMCard** rec
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

	return loadRecByStmt("TblWznmMCard_loadRecByRetReu", 2, vals, l, f, rec);
};

ubigint PgTblWznmMCard::loadRefsByMdl(
			ubigint mdlRefWznmMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _mdlRefWznmMModule = htonl64(mdlRefWznmMModule);

	const char* vals[] = {
		(char*) &_mdlRefWznmMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMCard_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMCard::loadRstByMdl(
			ubigint mdlRefWznmMModule
			, const bool append
			, ListWznmMCard& rst
		) {
	ubigint _mdlRefWznmMModule = htonl64(mdlRefWznmMModule);

	const char* vals[] = {
		(char*) &_mdlRefWznmMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMCard_loadRstByMdl", 1, vals, l, f, append, rst);
};

bool PgTblWznmMCard::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMCard_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

