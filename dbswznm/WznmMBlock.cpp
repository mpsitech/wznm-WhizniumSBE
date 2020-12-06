/**
	* \file WznmMBlock.cpp
	* database access for table TblWznmMBlock (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMBlock.h"

#include "WznmMBlock_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMBlock
 ******************************************************************************/

WznmMBlock::WznmMBlock(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint reaIxWznmWScope
			, const uint wriIxWznmWScope
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->reaIxWznmWScope = reaIxWznmWScope;
	this->wriIxWznmWScope = wriIxWznmWScope;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmMBlock::operator==(
			const WznmMBlock& comp
		) {
	return false;
};

bool WznmMBlock::operator!=(
			const WznmMBlock& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMBlock
 ******************************************************************************/

ListWznmMBlock::ListWznmMBlock() {
};

ListWznmMBlock::ListWznmMBlock(
			const ListWznmMBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMBlock(*(src.nodes[i]));
};

ListWznmMBlock::~ListWznmMBlock() {
	clear();
};

void ListWznmMBlock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMBlock::size() const {
	return(nodes.size());
};

void ListWznmMBlock::append(
			WznmMBlock* rec
		) {
	nodes.push_back(rec);
};

WznmMBlock* ListWznmMBlock::operator[](
			const uint ix
		) {
	WznmMBlock* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMBlock& ListWznmMBlock::operator=(
			const ListWznmMBlock& src
		) {
	WznmMBlock* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMBlock(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMBlock::operator==(
			const ListWznmMBlock& comp
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

bool ListWznmMBlock::operator!=(
			const ListWznmMBlock& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMBlock
 ******************************************************************************/

TblWznmMBlock::TblWznmMBlock() {
};

TblWznmMBlock::~TblWznmMBlock() {
};

bool TblWznmMBlock::loadRecBySQL(
			const string& sqlstr
			, WznmMBlock** rec
		) {
	return false;
};

ubigint TblWznmMBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMBlock& rst
		) {
	return 0;
};

ubigint TblWznmMBlock::insertRec(
			WznmMBlock* rec
		) {
	return 0;
};

ubigint TblWznmMBlock::insertNewRec(
			WznmMBlock** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint reaIxWznmWScope
			, const uint wriIxWznmWScope
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMBlock* _rec = NULL;

	_rec = new WznmMBlock(0, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMBlock::appendNewRecToRst(
			ListWznmMBlock& rst
			, WznmMBlock** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint reaIxWznmWScope
			, const uint wriIxWznmWScope
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMBlock* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMBlock::insertRst(
			ListWznmMBlock& rst
			, bool transact
		) {
};

void TblWznmMBlock::updateRec(
			WznmMBlock* rec
		) {
};

void TblWznmMBlock::updateRst(
			ListWznmMBlock& rst
			, bool transact
		) {
};

void TblWznmMBlock::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMBlock::loadRecByRef(
			ubigint ref
			, WznmMBlock** rec
		) {
	return false;
};

ubigint TblWznmMBlock::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMBlock::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWznmMBlock& rst
		) {
	return 0;
};

ubigint TblWznmMBlock::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMBlock& rst
		) {
	return 0;
};

ubigint TblWznmMBlock::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMBlock& rst
		) {
	return 0;
};

bool TblWznmMBlock::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMBlock::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMBlock& rst
		) {
	ubigint numload = 0;
	WznmMBlock* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMBlock
 ******************************************************************************/

MyTblWznmMBlock::MyTblWznmMBlock() :
			TblWznmMBlock()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMBlock::~MyTblWznmMBlock() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMBlock::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMBlock (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMBlock SET ixVBasetype = ?, refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, reaIxWznmWScope = ?, wriIxWznmWScope = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMBlock WHERE ref = ?", false);
};

bool MyTblWznmMBlock::loadRecBySQL(
			const string& sqlstr
			, WznmMBlock** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMBlock* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMBlock::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMBlock::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMBlock();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->reaIxWznmWScope = atol((char*) dbrow[5]); else _rec->reaIxWznmWScope = 0;
		if (dbrow[6]) _rec->wriIxWznmWScope = atol((char*) dbrow[6]); else _rec->wriIxWznmWScope = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMBlock& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMBlock* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMBlock::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMBlock::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMBlock();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->reaIxWznmWScope = atol((char*) dbrow[5]); else rec->reaIxWznmWScope = 0;
			if (dbrow[6]) rec->wriIxWznmWScope = atol((char*) dbrow[6]); else rec->wriIxWznmWScope = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMBlock::insertRec(
			WznmMBlock* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->sref.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->reaIxWznmWScope,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->wriIxWznmWScope,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMBlock::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMBlock::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMBlock::insertRst(
			ListWznmMBlock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMBlock::updateRec(
			WznmMBlock* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[6] = rec->sref.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->reaIxWznmWScope,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->wriIxWznmWScope,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMBlock::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMBlock::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMBlock::updateRst(
			ListWznmMBlock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMBlock::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMBlock::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMBlock::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMBlock::loadRecByRef(
			ubigint ref
			, WznmMBlock** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMBlock WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMBlock::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

ubigint MyTblWznmMBlock::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWznmMBlock& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWznmMBlock::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMBlock& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWznmMBlock::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMBlock& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMBlock::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMBlock WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMBlock
 ******************************************************************************/

PgTblWznmMBlock::PgTblWznmMBlock() :
			TblWznmMBlock()
			, PgTable()
		{
};

PgTblWznmMBlock::~PgTblWznmMBlock() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMBlock::initStatements() {
	createStatement("TblWznmMBlock_insertRec", "INSERT INTO TblWznmMBlock (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMBlock_updateRec", "UPDATE TblWznmMBlock SET ixVBasetype = $1, refWznmMVersion = $2, refIxVTbl = $3, refUref = $4, reaIxWznmWScope = $5, wriIxWznmWScope = $6, sref = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMBlock_removeRecByRef", "DELETE FROM TblWznmMBlock WHERE ref = $1", 1);

	createStatement("TblWznmMBlock_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE ref = $1", 1);
	createStatement("TblWznmMBlock_loadRefsByRetReu", "SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWznmMBlock_loadRstByRetReu", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY sref ASC", 2);
	createStatement("TblWznmMBlock_loadRstByTypVer", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE ixVBasetype = $1 AND refWznmMVersion = $2 ORDER BY sref ASC", 2);
	createStatement("TblWznmMBlock_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, reaIxWznmWScope, wriIxWznmWScope, sref, Comment FROM TblWznmMBlock WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMBlock_loadSrfByRef", "SELECT sref FROM TblWznmMBlock WHERE ref = $1", 1);
};

bool PgTblWznmMBlock::loadRec(
			PGresult* res
			, WznmMBlock** rec
		) {
	char* ptr;

	WznmMBlock* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMBlock();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "reaixwznmwscope"),
			PQfnumber(res, "wriixwznmwscope"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->reaIxWznmWScope = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->wriIxWznmWScope = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMBlock::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMBlock& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMBlock* rec;

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
			PQfnumber(res, "reaixwznmwscope"),
			PQfnumber(res, "wriixwznmwscope"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMBlock();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->reaIxWznmWScope = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->wriIxWznmWScope = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMBlock::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMBlock** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBlock::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMBlock::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMBlock& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBlock::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMBlock::loadRecBySQL(
			const string& sqlstr
			, WznmMBlock** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBlock::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMBlock& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBlock::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMBlock::insertRec(
			WznmMBlock* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _reaIxWznmWScope = htonl(rec->reaIxWznmWScope);
	uint _wriIxWznmWScope = htonl(rec->wriIxWznmWScope);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_reaIxWznmWScope,
		(char*) &_wriIxWznmWScope,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMBlock_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMBlock::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMBlock::insertRst(
			ListWznmMBlock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMBlock::updateRec(
			WznmMBlock* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _reaIxWznmWScope = htonl(rec->reaIxWznmWScope);
	uint _wriIxWznmWScope = htonl(rec->wriIxWznmWScope);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_reaIxWznmWScope,
		(char*) &_wriIxWznmWScope,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMBlock_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMBlock::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMBlock::updateRst(
			ListWznmMBlock& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMBlock::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMBlock_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMBlock::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMBlock::loadRecByRef(
			ubigint ref
			, WznmMBlock** rec
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

	return loadRecByStmt("TblWznmMBlock_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMBlock::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
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

	return loadRefsByStmt("TblWznmMBlock_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblWznmMBlock::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWznmMBlock& rst
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

	return loadRstByStmt("TblWznmMBlock_loadRstByRetReu", 2, vals, l, f, append, rst);
};

ubigint PgTblWznmMBlock::loadRstByTypVer(
			uint ixVBasetype
			, ubigint refWznmMVersion
			, const bool append
			, ListWznmMBlock& rst
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

	return loadRstByStmt("TblWznmMBlock_loadRstByTypVer", 2, vals, l, f, append, rst);
};

ubigint PgTblWznmMBlock::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMBlock& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMBlock_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMBlock::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMBlock_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
