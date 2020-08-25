/**
	* \file WznmMTable.cpp
	* database access for table TblWznmMTable (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMTable.h"

#include "WznmMTable_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMTable
 ******************************************************************************/

WznmMTable::WznmMTable(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMPreset
			, const ubigint refWznmMCard
			, const string sref
			, const string Short
			, const string unqSrefsWznmMTablecol
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refWznmMPreset = refWznmMPreset;
	this->refWznmMCard = refWznmMCard;
	this->sref = sref;
	this->Short = Short;
	this->unqSrefsWznmMTablecol = unqSrefsWznmMTablecol;
	this->Comment = Comment;
};

bool WznmMTable::operator==(
			const WznmMTable& comp
		) {
	return false;
};

bool WznmMTable::operator!=(
			const WznmMTable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMTable
 ******************************************************************************/

ListWznmMTable::ListWznmMTable() {
};

ListWznmMTable::ListWznmMTable(
			const ListWznmMTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMTable(*(src.nodes[i]));
};

ListWznmMTable::~ListWznmMTable() {
	clear();
};

void ListWznmMTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMTable::size() const {
	return(nodes.size());
};

void ListWznmMTable::append(
			WznmMTable* rec
		) {
	nodes.push_back(rec);
};

WznmMTable* ListWznmMTable::operator[](
			const uint ix
		) {
	WznmMTable* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMTable& ListWznmMTable::operator=(
			const ListWznmMTable& src
		) {
	WznmMTable* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMTable(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMTable::operator==(
			const ListWznmMTable& comp
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

bool ListWznmMTable::operator!=(
			const ListWznmMTable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMTable
 ******************************************************************************/

TblWznmMTable::TblWznmMTable() {
};

TblWznmMTable::~TblWznmMTable() {
};

bool TblWznmMTable::loadRecBySQL(
			const string& sqlstr
			, WznmMTable** rec
		) {
	return false;
};

ubigint TblWznmMTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTable& rst
		) {
	return 0;
};

ubigint TblWznmMTable::insertRec(
			WznmMTable* rec
		) {
	return 0;
};

ubigint TblWznmMTable::insertNewRec(
			WznmMTable** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMPreset
			, const ubigint refWznmMCard
			, const string sref
			, const string Short
			, const string unqSrefsWznmMTablecol
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMTable* _rec = NULL;

	_rec = new WznmMTable(0, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMTable::appendNewRecToRst(
			ListWznmMTable& rst
			, WznmMTable** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refWznmMPreset
			, const ubigint refWznmMCard
			, const string sref
			, const string Short
			, const string unqSrefsWznmMTablecol
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMTable* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMTable::insertRst(
			ListWznmMTable& rst
			, bool transact
		) {
};

void TblWznmMTable::updateRec(
			WznmMTable* rec
		) {
};

void TblWznmMTable::updateRst(
			ListWznmMTable& rst
			, bool transact
		) {
};

void TblWznmMTable::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMTable::loadRecByRef(
			ubigint ref
			, WznmMTable** rec
		) {
	return false;
};

bool TblWznmMTable::loadRecByCar(
			ubigint refWznmMCard
			, WznmMTable** rec
		) {
	return false;
};

bool TblWznmMTable::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMTable** rec
		) {
	return false;
};

bool TblWznmMTable::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMTable** rec
		) {
	return false;
};

bool TblWznmMTable::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMTable::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMTable::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMTable& rst
		) {
	return 0;
};

ubigint TblWznmMTable::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMTable& rst
		) {
	return 0;
};

bool TblWznmMTable::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMTable::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMTable& rst
		) {
	ubigint numload = 0;
	WznmMTable* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMTable
 ******************************************************************************/

MyTblWznmMTable::MyTblWznmMTable() :
			TblWznmMTable()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMTable::~MyTblWznmMTable() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMTable::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMTable (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMTable SET ixVBasetype = ?, refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, refWznmMPreset = ?, refWznmMCard = ?, sref = ?, Short = ?, unqSrefsWznmMTablecol = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMTable WHERE ref = ?", false);
};

bool MyTblWznmMTable::loadRecBySQL(
			const string& sqlstr
			, WznmMTable** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMTable* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMTable::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMTable::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMTable();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->refWznmMPreset = atoll((char*) dbrow[5]); else _rec->refWznmMPreset = 0;
		if (dbrow[6]) _rec->refWznmMCard = atoll((char*) dbrow[6]); else _rec->refWznmMCard = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->Short.assign(dbrow[8], dblengths[8]); else _rec->Short = "";
		if (dbrow[9]) _rec->unqSrefsWznmMTablecol.assign(dbrow[9], dblengths[9]); else _rec->unqSrefsWznmMTablecol = "";
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTable& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMTable* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMTable::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMTable::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMTable();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->refWznmMPreset = atoll((char*) dbrow[5]); else rec->refWznmMPreset = 0;
			if (dbrow[6]) rec->refWznmMCard = atoll((char*) dbrow[6]); else rec->refWznmMCard = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->Short.assign(dbrow[8], dblengths[8]); else rec->Short = "";
			if (dbrow[9]) rec->unqSrefsWznmMTablecol.assign(dbrow[9], dblengths[9]); else rec->unqSrefsWznmMTablecol = "";
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMTable::insertRec(
			WznmMTable* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[6] = rec->sref.length();
	l[7] = rec->Short.length();
	l[8] = rec->unqSrefsWznmMTablecol.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMCard,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Short.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->unqSrefsWznmMTablecol.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMTable::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMTable::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMTable::insertRst(
			ListWznmMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMTable::updateRec(
			WznmMTable* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();
	l[7] = rec->Short.length();
	l[8] = rec->unqSrefsWznmMTablecol.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMCard,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Short.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->unqSrefsWznmMTablecol.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMTable::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMTable::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMTable::updateRst(
			ListWznmMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMTable::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMTable::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMTable::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMTable::loadRecByRef(
			ubigint ref
			, WznmMTable** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMTable WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMTable::loadRecByCar(
			ubigint refWznmMCard
			, WznmMTable** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refWznmMCard = " + to_string(refWznmMCard) + "", rec);
};

bool MyTblWznmMTable::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMTable** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refWznmMPreset = " + to_string(refWznmMPreset) + "", rec);
};

bool MyTblWznmMTable::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMTable** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", rec);
};

bool MyTblWznmMTable::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMTable::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + "", append, refs);
};

ubigint MyTblWznmMTable::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMTable& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWznmMTable::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMTable& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMTable::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMTable WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMTable
 ******************************************************************************/

PgTblWznmMTable::PgTblWznmMTable() :
			TblWznmMTable()
			, PgTable()
		{
};

PgTblWznmMTable::~PgTblWznmMTable() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMTable::initStatements() {
	createStatement("TblWznmMTable_insertRec", "INSERT INTO TblWznmMTable (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWznmMTable_updateRec", "UPDATE TblWznmMTable SET ixVBasetype = $1, refWznmMVersion = $2, refIxVTbl = $3, refUref = $4, refWznmMPreset = $5, refWznmMCard = $6, sref = $7, Short = $8, unqSrefsWznmMTablecol = $9, Comment = $10 WHERE ref = $11", 11);
	createStatement("TblWznmMTable_removeRecByRef", "DELETE FROM TblWznmMTable WHERE ref = $1", 1);

	createStatement("TblWznmMTable_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE ref = $1", 1);
	createStatement("TblWznmMTable_loadRecByCar", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refWznmMCard = $1", 1);
	createStatement("TblWznmMTable_loadRecByPst", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refWznmMPreset = $1", 1);
	createStatement("TblWznmMTable_loadRecByRetReu", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWznmMTable_loadRefByVerSrf", "SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMTable_loadRefsByVer", "SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = $1", 1);
	createStatement("TblWznmMTable_loadRstByTypVer", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE ixVBasetype = $1 AND refWznmMVersion = $2 ORDER BY sref ASC", 2);
	createStatement("TblWznmMTable_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, refWznmMPreset, refWznmMCard, sref, Short, unqSrefsWznmMTablecol, Comment FROM TblWznmMTable WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMTable_loadSrfByRef", "SELECT sref FROM TblWznmMTable WHERE ref = $1", 1);
};

bool PgTblWznmMTable::loadRec(
			PGresult* res
			, WznmMTable** rec
		) {
	char* ptr;

	WznmMTable* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMTable();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "unqsrefswznmmtablecol"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMCard = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->unqSrefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMTable::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMTable& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMTable* rec;

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
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmcard"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "unqsrefswznmmtablecol"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMTable();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMCard = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->unqSrefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMTable::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMTable** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTable::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMTable::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMTable& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTable::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMTable::loadRecBySQL(
			const string& sqlstr
			, WznmMTable** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTable::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMTable& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTable::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMTable::insertRec(
			WznmMTable* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMCard,
		rec->sref.c_str(),
		rec->Short.c_str(),
		rec->unqSrefsWznmMTablecol.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMTable_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMTable::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMTable::insertRst(
			ListWznmMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMTable::updateRec(
			WznmMTable* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMCard = htonl64(rec->refWznmMCard);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMCard,
		rec->sref.c_str(),
		rec->Short.c_str(),
		rec->unqSrefsWznmMTablecol.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMTable_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMTable::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMTable::updateRst(
			ListWznmMTable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMTable::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMTable_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMTable::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMTable::loadRecByRef(
			ubigint ref
			, WznmMTable** rec
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

	return loadRecByStmt("TblWznmMTable_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMTable::loadRecByCar(
			ubigint refWznmMCard
			, WznmMTable** rec
		) {
	ubigint _refWznmMCard = htonl64(refWznmMCard);

	const char* vals[] = {
		(char*) &_refWznmMCard
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMTable_loadRecByCar", 1, vals, l, f, rec);
};

bool PgTblWznmMTable::loadRecByPst(
			ubigint refWznmMPreset
			, WznmMTable** rec
		) {
	ubigint _refWznmMPreset = htonl64(refWznmMPreset);

	const char* vals[] = {
		(char*) &_refWznmMPreset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMTable_loadRecByPst", 1, vals, l, f, rec);
};

bool PgTblWznmMTable::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMTable** rec
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

	return loadRecByStmt("TblWznmMTable_loadRecByRetReu", 2, vals, l, f, rec);
};

bool PgTblWznmMTable::loadRefByVerSrf(
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

	return loadRefByStmt("TblWznmMTable_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMTable::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMTable_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMTable::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMTable& rst
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

	return loadRstByStmt("TblWznmMTable_loadRstByTypVer", 2, vals, l, f, append, rst);
};

ubigint PgTblWznmMTable::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMTable& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMTable_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMTable::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMTable_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

