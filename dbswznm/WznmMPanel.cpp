/**
	* \file WznmMPanel.cpp
	* database access for table TblWznmMPanel (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMPanel.h"

#include "WznmMPanel_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMPanel
 ******************************************************************************/

WznmMPanel::WznmMPanel(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint carRefWznmMCard
			, const uint carNum
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const bool Detach
			, const string Avail
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->carRefWznmMCard = carRefWznmMCard;
	this->carNum = carNum;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refWznmMJob = refWznmMJob;
	this->sref = sref;
	this->Detach = Detach;
	this->Avail = Avail;
	this->Comment = Comment;
};

bool WznmMPanel::operator==(
			const WznmMPanel& comp
		) {
	return false;
};

bool WznmMPanel::operator!=(
			const WznmMPanel& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMPanel
 ******************************************************************************/

ListWznmMPanel::ListWznmMPanel() {
};

ListWznmMPanel::ListWznmMPanel(
			const ListWznmMPanel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMPanel(*(src.nodes[i]));
};

ListWznmMPanel::~ListWznmMPanel() {
	clear();
};

void ListWznmMPanel::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMPanel::size() const {
	return(nodes.size());
};

void ListWznmMPanel::append(
			WznmMPanel* rec
		) {
	nodes.push_back(rec);
};

WznmMPanel* ListWznmMPanel::operator[](
			const uint ix
		) {
	WznmMPanel* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMPanel& ListWznmMPanel::operator=(
			const ListWznmMPanel& src
		) {
	WznmMPanel* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMPanel(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMPanel::operator==(
			const ListWznmMPanel& comp
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

bool ListWznmMPanel::operator!=(
			const ListWznmMPanel& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMPanel
 ******************************************************************************/

TblWznmMPanel::TblWznmMPanel() {
};

TblWznmMPanel::~TblWznmMPanel() {
};

bool TblWznmMPanel::loadRecBySQL(
			const string& sqlstr
			, WznmMPanel** rec
		) {
	return false;
};

ubigint TblWznmMPanel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPanel& rst
		) {
	return 0;
};

ubigint TblWznmMPanel::insertRec(
			WznmMPanel* rec
		) {
	return 0;
};

ubigint TblWznmMPanel::insertNewRec(
			WznmMPanel** rec
			, const uint ixVBasetype
			, const ubigint carRefWznmMCard
			, const uint carNum
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const bool Detach
			, const string Avail
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMPanel* _rec = NULL;

	_rec = new WznmMPanel(0, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMPanel::appendNewRecToRst(
			ListWznmMPanel& rst
			, WznmMPanel** rec
			, const uint ixVBasetype
			, const ubigint carRefWznmMCard
			, const uint carNum
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMJob
			, const string sref
			, const bool Detach
			, const string Avail
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMPanel* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMPanel::insertRst(
			ListWznmMPanel& rst
			, bool transact
		) {
};

void TblWznmMPanel::updateRec(
			WznmMPanel* rec
		) {
};

void TblWznmMPanel::updateRst(
			ListWznmMPanel& rst
			, bool transact
		) {
};

void TblWznmMPanel::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMPanel::loadRecByRef(
			ubigint ref
			, WznmMPanel** rec
		) {
	return false;
};

bool TblWznmMPanel::loadRecByJob(
			ubigint refWznmMJob
			, WznmMPanel** rec
		) {
	return false;
};

ubigint TblWznmMPanel::loadRefsByCar(
			ubigint carRefWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMPanel::loadRstByCar(
			ubigint carRefWznmMCard
			, const bool append
			, ListWznmMPanel& rst
		) {
	return 0;
};

bool TblWznmMPanel::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMPanel::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMPanel& rst
		) {
	ubigint numload = 0;
	WznmMPanel* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMPanel
 ******************************************************************************/

MyTblWznmMPanel::MyTblWznmMPanel() :
			TblWznmMPanel()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMPanel::~MyTblWznmMPanel() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMPanel::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMPanel (ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMPanel SET ixVBasetype = ?, carRefWznmMCard = ?, carNum = ?, refIxVTbl = ?, refUref = ?, refWznmMJob = ?, sref = ?, Detach = ?, Avail = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMPanel WHERE ref = ?", false);
};

bool MyTblWznmMPanel::loadRecBySQL(
			const string& sqlstr
			, WznmMPanel** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMPanel* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMPanel::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMPanel::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMPanel();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->carRefWznmMCard = atoll((char*) dbrow[2]); else _rec->carRefWznmMCard = 0;
		if (dbrow[3]) _rec->carNum = atol((char*) dbrow[3]); else _rec->carNum = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->refWznmMJob = atoll((char*) dbrow[6]); else _rec->refWznmMJob = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->Detach = (atoi((char*) dbrow[8]) != 0); else _rec->Detach = false;
		if (dbrow[9]) _rec->Avail.assign(dbrow[9], dblengths[9]); else _rec->Avail = "";
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMPanel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPanel& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMPanel* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMPanel::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMPanel::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMPanel();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->carRefWznmMCard = atoll((char*) dbrow[2]); else rec->carRefWznmMCard = 0;
			if (dbrow[3]) rec->carNum = atol((char*) dbrow[3]); else rec->carNum = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->refWznmMJob = atoll((char*) dbrow[6]); else rec->refWznmMJob = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->Detach = (atoi((char*) dbrow[8]) != 0); else rec->Detach = false;
			if (dbrow[9]) rec->Avail.assign(dbrow[9], dblengths[9]); else rec->Avail = "";
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMPanel::insertRec(
			WznmMPanel* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[6] = rec->sref.length();
	tinyint Detach = rec->Detach;
	l[8] = rec->Avail.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->carRefWznmMCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->carNum,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMJob,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Detach,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMPanel::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMPanel::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMPanel::insertRst(
			ListWznmMPanel& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMPanel::updateRec(
			WznmMPanel* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();
	tinyint Detach = rec->Detach;
	l[8] = rec->Avail.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->carRefWznmMCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->carNum,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMJob,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Detach,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMPanel::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMPanel::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMPanel::updateRst(
			ListWznmMPanel& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMPanel::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMPanel::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMPanel::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMPanel::loadRecByRef(
			ubigint ref
			, WznmMPanel** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMPanel WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMPanel::loadRecByJob(
			ubigint refWznmMJob
			, WznmMPanel** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment FROM TblWznmMPanel WHERE refWznmMJob = " + to_string(refWznmMJob) + "", rec);
};

ubigint MyTblWznmMPanel::loadRefsByCar(
			ubigint carRefWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(carRefWznmMCard) + "", append, refs);
};

ubigint MyTblWznmMPanel::loadRstByCar(
			ubigint carRefWznmMCard
			, const bool append
			, ListWznmMPanel& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(carRefWznmMCard) + " ORDER BY carNum ASC", append, rst);
};

bool MyTblWznmMPanel::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMPanel WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMPanel
 ******************************************************************************/

PgTblWznmMPanel::PgTblWznmMPanel() :
			TblWznmMPanel()
			, PgTable()
		{
};

PgTblWznmMPanel::~PgTblWznmMPanel() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMPanel::initStatements() {
	createStatement("TblWznmMPanel_insertRec", "INSERT INTO TblWznmMPanel (ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWznmMPanel_updateRec", "UPDATE TblWznmMPanel SET ixVBasetype = $1, carRefWznmMCard = $2, carNum = $3, refIxVTbl = $4, refUref = $5, refWznmMJob = $6, sref = $7, Detach = $8, Avail = $9, Comment = $10 WHERE ref = $11", 11);
	createStatement("TblWznmMPanel_removeRecByRef", "DELETE FROM TblWznmMPanel WHERE ref = $1", 1);

	createStatement("TblWznmMPanel_loadRecByRef", "SELECT ref, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment FROM TblWznmMPanel WHERE ref = $1", 1);
	createStatement("TblWznmMPanel_loadRecByJob", "SELECT ref, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment FROM TblWznmMPanel WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMPanel_loadRefsByCar", "SELECT ref FROM TblWznmMPanel WHERE carRefWznmMCard = $1", 1);
	createStatement("TblWznmMPanel_loadRstByCar", "SELECT ref, ixVBasetype, carRefWznmMCard, carNum, refIxVTbl, refUref, refWznmMJob, sref, Detach, Avail, Comment FROM TblWznmMPanel WHERE carRefWznmMCard = $1 ORDER BY carNum ASC", 1);
	createStatement("TblWznmMPanel_loadSrfByRef", "SELECT sref FROM TblWznmMPanel WHERE ref = $1", 1);
};

bool PgTblWznmMPanel::loadRec(
			PGresult* res
			, WznmMPanel** rec
		) {
	char* ptr;

	WznmMPanel* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMPanel();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "carrefwznmmcard"),
			PQfnumber(res, "carnum"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "detach"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->carRefWznmMCard = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->carNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Detach = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMPanel::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMPanel& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMPanel* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "carrefwznmmcard"),
			PQfnumber(res, "carnum"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "detach"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMPanel();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->carRefWznmMCard = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->carNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Detach = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMPanel::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMPanel** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPanel::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMPanel::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMPanel& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPanel::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMPanel::loadRecBySQL(
			const string& sqlstr
			, WznmMPanel** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPanel::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMPanel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPanel& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPanel::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMPanel::insertRec(
			WznmMPanel* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _carRefWznmMCard = htonl64(rec->carRefWznmMCard);
	uint _carNum = htonl(rec->carNum);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Detach = htons((smallint) rec->Detach);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_carRefWznmMCard,
		(char*) &_carNum,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_Detach,
		rec->Avail.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMPanel_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPanel::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMPanel::insertRst(
			ListWznmMPanel& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMPanel::updateRec(
			WznmMPanel* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _carRefWznmMCard = htonl64(rec->carRefWznmMCard);
	uint _carNum = htonl(rec->carNum);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Detach = htons((smallint) rec->Detach);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_carRefWznmMCard,
		(char*) &_carNum,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_Detach,
		rec->Avail.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMPanel_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMPanel::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMPanel::updateRst(
			ListWznmMPanel& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMPanel::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMPanel_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMPanel::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMPanel::loadRecByRef(
			ubigint ref
			, WznmMPanel** rec
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

	return loadRecByStmt("TblWznmMPanel_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMPanel::loadRecByJob(
			ubigint refWznmMJob
			, WznmMPanel** rec
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMPanel_loadRecByJob", 1, vals, l, f, rec);
};

ubigint PgTblWznmMPanel::loadRefsByCar(
			ubigint carRefWznmMCard
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _carRefWznmMCard = htonl64(carRefWznmMCard);

	const char* vals[] = {
		(char*) &_carRefWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMPanel_loadRefsByCar", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMPanel::loadRstByCar(
			ubigint carRefWznmMCard
			, const bool append
			, ListWznmMPanel& rst
		) {
	ubigint _carRefWznmMCard = htonl64(carRefWznmMCard);

	const char* vals[] = {
		(char*) &_carRefWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMPanel_loadRstByCar", 1, vals, l, f, append, rst);
};

bool PgTblWznmMPanel::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMPanel_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

