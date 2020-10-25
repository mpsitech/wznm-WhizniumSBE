/**
	* \file WznmMQuery.cpp
	* database access for table TblWznmMQuery (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmMQuery.h"

#include "WznmMQuery_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMQuery
 ******************************************************************************/

WznmMQuery::WznmMQuery(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const ubigint supRefWznmMQuery
			, const uint supIxVSubrole
			, const ubigint refRTable
			, const ubigint refWznmMTable
			, const ubigint qtbRefWznmMTable
			, const ubigint refWznmMJob
			, const string sref
			, const bool Limofs
			, const ubigint inoRefAOrder
			, const string inoSrefsWznmMTablecol
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->supRefWznmMQuery = supRefWznmMQuery;
	this->supIxVSubrole = supIxVSubrole;
	this->refRTable = refRTable;
	this->refWznmMTable = refWznmMTable;
	this->qtbRefWznmMTable = qtbRefWznmMTable;
	this->refWznmMJob = refWznmMJob;
	this->sref = sref;
	this->Limofs = Limofs;
	this->inoRefAOrder = inoRefAOrder;
	this->inoSrefsWznmMTablecol = inoSrefsWznmMTablecol;
	this->Comment = Comment;
};

bool WznmMQuery::operator==(
			const WznmMQuery& comp
		) {
	return false;
};

bool WznmMQuery::operator!=(
			const WznmMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMQuery
 ******************************************************************************/

ListWznmMQuery::ListWznmMQuery() {
};

ListWznmMQuery::ListWznmMQuery(
			const ListWznmMQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMQuery(*(src.nodes[i]));
};

ListWznmMQuery::~ListWznmMQuery() {
	clear();
};

void ListWznmMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMQuery::size() const {
	return(nodes.size());
};

void ListWznmMQuery::append(
			WznmMQuery* rec
		) {
	nodes.push_back(rec);
};

WznmMQuery* ListWznmMQuery::operator[](
			const uint ix
		) {
	WznmMQuery* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMQuery& ListWznmMQuery::operator=(
			const ListWznmMQuery& src
		) {
	WznmMQuery* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMQuery(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMQuery::operator==(
			const ListWznmMQuery& comp
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

bool ListWznmMQuery::operator!=(
			const ListWznmMQuery& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMQuery
 ******************************************************************************/

TblWznmMQuery::TblWznmMQuery() {
};

TblWznmMQuery::~TblWznmMQuery() {
};

bool TblWznmMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmMQuery** rec
		) {
	return false;
};

ubigint TblWznmMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuery& rst
		) {
	return 0;
};

ubigint TblWznmMQuery::insertRec(
			WznmMQuery* rec
		) {
	return 0;
};

ubigint TblWznmMQuery::insertNewRec(
			WznmMQuery** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const ubigint supRefWznmMQuery
			, const uint supIxVSubrole
			, const ubigint refRTable
			, const ubigint refWznmMTable
			, const ubigint qtbRefWznmMTable
			, const ubigint refWznmMJob
			, const string sref
			, const bool Limofs
			, const ubigint inoRefAOrder
			, const string inoSrefsWznmMTablecol
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMQuery* _rec = NULL;

	_rec = new WznmMQuery(0, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMQuery::appendNewRecToRst(
			ListWznmMQuery& rst
			, WznmMQuery** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const ubigint supRefWznmMQuery
			, const uint supIxVSubrole
			, const ubigint refRTable
			, const ubigint refWznmMTable
			, const ubigint qtbRefWznmMTable
			, const ubigint refWznmMJob
			, const string sref
			, const bool Limofs
			, const ubigint inoRefAOrder
			, const string inoSrefsWznmMTablecol
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMQuery* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMQuery::insertRst(
			ListWznmMQuery& rst
			, bool transact
		) {
};

void TblWznmMQuery::updateRec(
			WznmMQuery* rec
		) {
};

void TblWznmMQuery::updateRst(
			ListWznmMQuery& rst
			, bool transact
		) {
};

void TblWznmMQuery::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMQuery::loadRecByRef(
			ubigint ref
			, WznmMQuery** rec
		) {
	return false;
};

bool TblWznmMQuery::loadRecByJob(
			ubigint refWznmMJob
			, WznmMQuery** rec
		) {
	return false;
};

bool TblWznmMQuery::loadRecByQtb(
			ubigint qtbRefWznmMTable
			, WznmMQuery** rec
		) {
	return false;
};

bool TblWznmMQuery::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMQuery::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMQuery& rst
		) {
	return 0;
};

bool TblWznmMQuery::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMQuery::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMQuery& rst
		) {
	ubigint numload = 0;
	WznmMQuery* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMQuery
 ******************************************************************************/

MyTblWznmMQuery::MyTblWznmMQuery() :
			TblWznmMQuery()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMQuery::~MyTblWznmMQuery() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMQuery::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMQuery (ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMQuery SET ixVBasetype = ?, refWznmMVersion = ?, supRefWznmMQuery = ?, supIxVSubrole = ?, refRTable = ?, refWznmMTable = ?, qtbRefWznmMTable = ?, refWznmMJob = ?, sref = ?, Limofs = ?, inoRefAOrder = ?, inoSrefsWznmMTablecol = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMQuery WHERE ref = ?", false);
};

bool MyTblWznmMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmMQuery** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMQuery* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMQuery::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMQuery::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMQuery();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->supRefWznmMQuery = atoll((char*) dbrow[3]); else _rec->supRefWznmMQuery = 0;
		if (dbrow[4]) _rec->supIxVSubrole = atol((char*) dbrow[4]); else _rec->supIxVSubrole = 0;
		if (dbrow[5]) _rec->refRTable = atoll((char*) dbrow[5]); else _rec->refRTable = 0;
		if (dbrow[6]) _rec->refWznmMTable = atoll((char*) dbrow[6]); else _rec->refWznmMTable = 0;
		if (dbrow[7]) _rec->qtbRefWznmMTable = atoll((char*) dbrow[7]); else _rec->qtbRefWznmMTable = 0;
		if (dbrow[8]) _rec->refWznmMJob = atoll((char*) dbrow[8]); else _rec->refWznmMJob = 0;
		if (dbrow[9]) _rec->sref.assign(dbrow[9], dblengths[9]); else _rec->sref = "";
		if (dbrow[10]) _rec->Limofs = (atoi((char*) dbrow[10]) != 0); else _rec->Limofs = false;
		if (dbrow[11]) _rec->inoRefAOrder = atoll((char*) dbrow[11]); else _rec->inoRefAOrder = 0;
		if (dbrow[12]) _rec->inoSrefsWznmMTablecol.assign(dbrow[12], dblengths[12]); else _rec->inoSrefsWznmMTablecol = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuery& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMQuery* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMQuery::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMQuery::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMQuery();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->supRefWznmMQuery = atoll((char*) dbrow[3]); else rec->supRefWznmMQuery = 0;
			if (dbrow[4]) rec->supIxVSubrole = atol((char*) dbrow[4]); else rec->supIxVSubrole = 0;
			if (dbrow[5]) rec->refRTable = atoll((char*) dbrow[5]); else rec->refRTable = 0;
			if (dbrow[6]) rec->refWznmMTable = atoll((char*) dbrow[6]); else rec->refWznmMTable = 0;
			if (dbrow[7]) rec->qtbRefWznmMTable = atoll((char*) dbrow[7]); else rec->qtbRefWznmMTable = 0;
			if (dbrow[8]) rec->refWznmMJob = atoll((char*) dbrow[8]); else rec->refWznmMJob = 0;
			if (dbrow[9]) rec->sref.assign(dbrow[9], dblengths[9]); else rec->sref = "";
			if (dbrow[10]) rec->Limofs = (atoi((char*) dbrow[10]) != 0); else rec->Limofs = false;
			if (dbrow[11]) rec->inoRefAOrder = atoll((char*) dbrow[11]); else rec->inoRefAOrder = 0;
			if (dbrow[12]) rec->inoSrefsWznmMTablecol.assign(dbrow[12], dblengths[12]); else rec->inoSrefsWznmMTablecol = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMQuery::insertRec(
			WznmMQuery* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[8] = rec->sref.length();
	tinyint Limofs = rec->Limofs;
	l[11] = rec->inoSrefsWznmMTablecol.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->supRefWznmMQuery,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supIxVSubrole,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refRTable,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qtbRefWznmMTable,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMJob,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->sref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Limofs,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->inoRefAOrder,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->inoSrefsWznmMTablecol.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMQuery::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMQuery::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMQuery::insertRst(
			ListWznmMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMQuery::updateRec(
			WznmMQuery* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[8] = rec->sref.length();
	tinyint Limofs = rec->Limofs;
	l[11] = rec->inoSrefsWznmMTablecol.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->supRefWznmMQuery,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supIxVSubrole,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refRTable,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qtbRefWznmMTable,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMJob,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->sref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Limofs,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->inoRefAOrder,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->inoSrefsWznmMTablecol.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMQuery::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMQuery::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMQuery::updateRst(
			ListWznmMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMQuery::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMQuery::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMQuery::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMQuery::loadRecByRef(
			ubigint ref
			, WznmMQuery** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMQuery WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMQuery::loadRecByJob(
			ubigint refWznmMJob
			, WznmMQuery** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE refWznmMJob = " + to_string(refWznmMJob) + "", rec);
};

bool MyTblWznmMQuery::loadRecByQtb(
			ubigint qtbRefWznmMTable
			, WznmMQuery** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE qtbRefWznmMTable = " + to_string(qtbRefWznmMTable) + "", rec);
};

bool MyTblWznmMQuery::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMQuery::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMQuery& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMQuery::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMQuery WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMQuery
 ******************************************************************************/

PgTblWznmMQuery::PgTblWznmMQuery() :
			TblWznmMQuery()
			, PgTable()
		{
};

PgTblWznmMQuery::~PgTblWznmMQuery() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMQuery::initStatements() {
	createStatement("TblWznmMQuery_insertRec", "INSERT INTO TblWznmMQuery (ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWznmMQuery_updateRec", "UPDATE TblWznmMQuery SET ixVBasetype = $1, refWznmMVersion = $2, supRefWznmMQuery = $3, supIxVSubrole = $4, refRTable = $5, refWznmMTable = $6, qtbRefWznmMTable = $7, refWznmMJob = $8, sref = $9, Limofs = $10, inoRefAOrder = $11, inoSrefsWznmMTablecol = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblWznmMQuery_removeRecByRef", "DELETE FROM TblWznmMQuery WHERE ref = $1", 1);

	createStatement("TblWznmMQuery_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE ref = $1", 1);
	createStatement("TblWznmMQuery_loadRecByJob", "SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMQuery_loadRecByQtb", "SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE qtbRefWznmMTable = $1", 1);
	createStatement("TblWznmMQuery_loadRefByVerSrf", "SELECT ref FROM TblWznmMQuery WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMQuery_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refRTable, refWznmMTable, qtbRefWznmMTable, refWznmMJob, sref, Limofs, inoRefAOrder, inoSrefsWznmMTablecol, Comment FROM TblWznmMQuery WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMQuery_loadSrfByRef", "SELECT sref FROM TblWznmMQuery WHERE ref = $1", 1);
};

bool PgTblWznmMQuery::loadRec(
			PGresult* res
			, WznmMQuery** rec
		) {
	char* ptr;

	WznmMQuery* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMQuery();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmquery"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "refrtable"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "qtbrefwznmmtable"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "limofs"),
			PQfnumber(res, "inorefaorder"),
			PQfnumber(res, "inosrefswznmmtablecol"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supIxVSubrole = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refRTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->qtbRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Limofs = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->inoRefAOrder = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->inoSrefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMQuery::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMQuery& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMQuery* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmquery"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "refrtable"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "qtbrefwznmmtable"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "limofs"),
			PQfnumber(res, "inorefaorder"),
			PQfnumber(res, "inosrefswznmmtablecol"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMQuery();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supIxVSubrole = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refRTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->qtbRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Limofs = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->inoRefAOrder = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->inoSrefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMQuery::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMQuery** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuery::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMQuery::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMQuery& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuery::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMQuery::loadRecBySQL(
			const string& sqlstr
			, WznmMQuery** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuery::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMQuery& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuery::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMQuery::insertRec(
			WznmMQuery* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMQuery = htonl64(rec->supRefWznmMQuery);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _refRTable = htonl64(rec->refRTable);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _qtbRefWznmMTable = htonl64(rec->qtbRefWznmMTable);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Limofs = htons((smallint) rec->Limofs);
	ubigint _inoRefAOrder = htonl64(rec->inoRefAOrder);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMQuery,
		(char*) &_supIxVSubrole,
		(char*) &_refRTable,
		(char*) &_refWznmMTable,
		(char*) &_qtbRefWznmMTable,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_Limofs,
		(char*) &_inoRefAOrder,
		rec->inoSrefsWznmMTablecol.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMQuery_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMQuery::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMQuery::insertRst(
			ListWznmMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMQuery::updateRec(
			WznmMQuery* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMQuery = htonl64(rec->supRefWznmMQuery);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _refRTable = htonl64(rec->refRTable);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _qtbRefWznmMTable = htonl64(rec->qtbRefWznmMTable);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Limofs = htons((smallint) rec->Limofs);
	ubigint _inoRefAOrder = htonl64(rec->inoRefAOrder);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMQuery,
		(char*) &_supIxVSubrole,
		(char*) &_refRTable,
		(char*) &_refWznmMTable,
		(char*) &_qtbRefWznmMTable,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		(char*) &_Limofs,
		(char*) &_inoRefAOrder,
		rec->inoSrefsWznmMTablecol.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMQuery_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMQuery::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMQuery::updateRst(
			ListWznmMQuery& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMQuery::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMQuery_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMQuery::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMQuery::loadRecByRef(
			ubigint ref
			, WznmMQuery** rec
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

	return loadRecByStmt("TblWznmMQuery_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMQuery::loadRecByJob(
			ubigint refWznmMJob
			, WznmMQuery** rec
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMQuery_loadRecByJob", 1, vals, l, f, rec);
};

bool PgTblWznmMQuery::loadRecByQtb(
			ubigint qtbRefWznmMTable
			, WznmMQuery** rec
		) {
	ubigint _qtbRefWznmMTable = htonl64(qtbRefWznmMTable);

	const char* vals[] = {
		(char*) &_qtbRefWznmMTable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMQuery_loadRecByQtb", 1, vals, l, f, rec);
};

bool PgTblWznmMQuery::loadRefByVerSrf(
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

	return loadRefByStmt("TblWznmMQuery_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMQuery::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMQuery& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMQuery_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMQuery::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMQuery_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

