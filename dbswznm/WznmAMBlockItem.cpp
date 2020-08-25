/**
	* \file WznmAMBlockItem.cpp
	* database access for table TblWznmAMBlockItem (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmAMBlockItem.h"

#include "WznmAMBlockItem_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMBlockItem
 ******************************************************************************/

WznmAMBlockItem::WznmAMBlockItem(
			const ubigint ref
			, const ubigint refWznmCAMBlockItem
			, const ubigint blkRefWznmMBlock
			, const uint blkNum
			, const uint ixVBasetype
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMControl
			, const ubigint refWznmMVector
			, const ubigint refWznmMFeed
			, const ubigint refWznmMTable
			, const ubigint refWznmMBlock
			, const ubigint refJ
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmCAMBlockItem = refWznmCAMBlockItem;
	this->blkRefWznmMBlock = blkRefWznmMBlock;
	this->blkNum = blkNum;
	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->refWznmMControl = refWznmMControl;
	this->refWznmMVector = refWznmMVector;
	this->refWznmMFeed = refWznmMFeed;
	this->refWznmMTable = refWznmMTable;
	this->refWznmMBlock = refWznmMBlock;
	this->refJ = refJ;
	this->Defval = Defval;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->Comment = Comment;
};

bool WznmAMBlockItem::operator==(
			const WznmAMBlockItem& comp
		) {
	return false;
};

bool WznmAMBlockItem::operator!=(
			const WznmAMBlockItem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMBlockItem
 ******************************************************************************/

ListWznmAMBlockItem::ListWznmAMBlockItem() {
};

ListWznmAMBlockItem::ListWznmAMBlockItem(
			const ListWznmAMBlockItem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMBlockItem(*(src.nodes[i]));
};

ListWznmAMBlockItem::~ListWznmAMBlockItem() {
	clear();
};

void ListWznmAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMBlockItem::size() const {
	return(nodes.size());
};

void ListWznmAMBlockItem::append(
			WznmAMBlockItem* rec
		) {
	nodes.push_back(rec);
};

WznmAMBlockItem* ListWznmAMBlockItem::operator[](
			const uint ix
		) {
	WznmAMBlockItem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMBlockItem& ListWznmAMBlockItem::operator=(
			const ListWznmAMBlockItem& src
		) {
	WznmAMBlockItem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMBlockItem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMBlockItem::operator==(
			const ListWznmAMBlockItem& comp
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

bool ListWznmAMBlockItem::operator!=(
			const ListWznmAMBlockItem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMBlockItem
 ******************************************************************************/

TblWznmAMBlockItem::TblWznmAMBlockItem() {
};

TblWznmAMBlockItem::~TblWznmAMBlockItem() {
};

bool TblWznmAMBlockItem::loadRecBySQL(
			const string& sqlstr
			, WznmAMBlockItem** rec
		) {
	return false;
};

ubigint TblWznmAMBlockItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	return 0;
};

ubigint TblWznmAMBlockItem::insertRec(
			WznmAMBlockItem* rec
		) {
	return 0;
};

ubigint TblWznmAMBlockItem::insertNewRec(
			WznmAMBlockItem** rec
			, const ubigint refWznmCAMBlockItem
			, const ubigint blkRefWznmMBlock
			, const uint blkNum
			, const uint ixVBasetype
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMControl
			, const ubigint refWznmMVector
			, const ubigint refWznmMFeed
			, const ubigint refWznmMTable
			, const ubigint refWznmMBlock
			, const ubigint refJ
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMBlockItem* _rec = NULL;

	_rec = new WznmAMBlockItem(0, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMBlockItem::appendNewRecToRst(
			ListWznmAMBlockItem& rst
			, WznmAMBlockItem** rec
			, const ubigint refWznmCAMBlockItem
			, const ubigint blkRefWznmMBlock
			, const uint blkNum
			, const uint ixVBasetype
			, const string sref
			, const uint ixWznmVVartype
			, const ubigint refWznmMControl
			, const ubigint refWznmMVector
			, const ubigint refWznmMFeed
			, const ubigint refWznmMTable
			, const ubigint refWznmMBlock
			, const ubigint refJ
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAMBlockItem* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMBlockItem::insertRst(
			ListWznmAMBlockItem& rst
			, bool transact
		) {
};

void TblWznmAMBlockItem::updateRec(
			WznmAMBlockItem* rec
		) {
};

void TblWznmAMBlockItem::updateRst(
			ListWznmAMBlockItem& rst
			, bool transact
		) {
};

void TblWznmAMBlockItem::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMBlockItem::loadRecByRef(
			ubigint ref
			, WznmAMBlockItem** rec
		) {
	return false;
};

ubigint TblWznmAMBlockItem::loadRefsByBlk(
			ubigint blkRefWznmMBlock
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMBlockItem::loadRefsByClu(
			ubigint refWznmCAMBlockItem
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMBlockItem::loadRstByBlk(
			ubigint blkRefWznmMBlock
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	return 0;
};

ubigint TblWznmAMBlockItem::loadRstByClu(
			ubigint refWznmCAMBlockItem
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	return 0;
};

ubigint TblWznmAMBlockItem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	ubigint numload = 0;
	WznmAMBlockItem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMBlockItem
 ******************************************************************************/

MyTblWznmAMBlockItem::MyTblWznmAMBlockItem() :
			TblWznmAMBlockItem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMBlockItem::~MyTblWznmAMBlockItem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMBlockItem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMBlockItem (refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMBlockItem SET refWznmCAMBlockItem = ?, blkRefWznmMBlock = ?, blkNum = ?, ixVBasetype = ?, sref = ?, ixWznmVVartype = ?, refWznmMControl = ?, refWznmMVector = ?, refWznmMFeed = ?, refWznmMTable = ?, refWznmMBlock = ?, refJ = ?, Defval = ?, refWznmMVectoritem = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMBlockItem WHERE ref = ?", false);
};

bool MyTblWznmAMBlockItem::loadRecBySQL(
			const string& sqlstr
			, WznmAMBlockItem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMBlockItem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMBlockItem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMBlockItem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMBlockItem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmCAMBlockItem = atoll((char*) dbrow[1]); else _rec->refWznmCAMBlockItem = 0;
		if (dbrow[2]) _rec->blkRefWznmMBlock = atoll((char*) dbrow[2]); else _rec->blkRefWznmMBlock = 0;
		if (dbrow[3]) _rec->blkNum = atol((char*) dbrow[3]); else _rec->blkNum = 0;
		if (dbrow[4]) _rec->ixVBasetype = atol((char*) dbrow[4]); else _rec->ixVBasetype = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWznmVVartype = atol((char*) dbrow[6]); else _rec->ixWznmVVartype = 0;
		if (dbrow[7]) _rec->refWznmMControl = atoll((char*) dbrow[7]); else _rec->refWznmMControl = 0;
		if (dbrow[8]) _rec->refWznmMVector = atoll((char*) dbrow[8]); else _rec->refWznmMVector = 0;
		if (dbrow[9]) _rec->refWznmMFeed = atoll((char*) dbrow[9]); else _rec->refWznmMFeed = 0;
		if (dbrow[10]) _rec->refWznmMTable = atoll((char*) dbrow[10]); else _rec->refWznmMTable = 0;
		if (dbrow[11]) _rec->refWznmMBlock = atoll((char*) dbrow[11]); else _rec->refWznmMBlock = 0;
		if (dbrow[12]) _rec->refJ = atoll((char*) dbrow[12]); else _rec->refJ = 0;
		if (dbrow[13]) _rec->Defval.assign(dbrow[13], dblengths[13]); else _rec->Defval = "";
		if (dbrow[14]) _rec->refWznmMVectoritem = atoll((char*) dbrow[14]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[15]) _rec->Comment.assign(dbrow[15], dblengths[15]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMBlockItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMBlockItem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMBlockItem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMBlockItem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMBlockItem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmCAMBlockItem = atoll((char*) dbrow[1]); else rec->refWznmCAMBlockItem = 0;
			if (dbrow[2]) rec->blkRefWznmMBlock = atoll((char*) dbrow[2]); else rec->blkRefWznmMBlock = 0;
			if (dbrow[3]) rec->blkNum = atol((char*) dbrow[3]); else rec->blkNum = 0;
			if (dbrow[4]) rec->ixVBasetype = atol((char*) dbrow[4]); else rec->ixVBasetype = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWznmVVartype = atol((char*) dbrow[6]); else rec->ixWznmVVartype = 0;
			if (dbrow[7]) rec->refWznmMControl = atoll((char*) dbrow[7]); else rec->refWznmMControl = 0;
			if (dbrow[8]) rec->refWznmMVector = atoll((char*) dbrow[8]); else rec->refWznmMVector = 0;
			if (dbrow[9]) rec->refWznmMFeed = atoll((char*) dbrow[9]); else rec->refWznmMFeed = 0;
			if (dbrow[10]) rec->refWznmMTable = atoll((char*) dbrow[10]); else rec->refWznmMTable = 0;
			if (dbrow[11]) rec->refWznmMBlock = atoll((char*) dbrow[11]); else rec->refWznmMBlock = 0;
			if (dbrow[12]) rec->refJ = atoll((char*) dbrow[12]); else rec->refJ = 0;
			if (dbrow[13]) rec->Defval.assign(dbrow[13], dblengths[13]); else rec->Defval = "";
			if (dbrow[14]) rec->refWznmMVectoritem = atoll((char*) dbrow[14]); else rec->refWznmMVectoritem = 0;
			if (dbrow[15]) rec->Comment.assign(dbrow[15], dblengths[15]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMBlockItem::insertRec(
			WznmAMBlockItem* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[4] = rec->sref.length();
	l[12] = rec->Defval.length();
	l[14] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMBlockItem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->blkRefWznmMBlock,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->blkNum,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMControl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVector,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMFeed,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMTable,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMBlock,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refJ,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMBlockItem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMBlockItem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMBlockItem::insertRst(
			ListWznmAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMBlockItem::updateRec(
			WznmAMBlockItem* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	l[4] = rec->sref.length();
	l[12] = rec->Defval.length();
	l[14] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmCAMBlockItem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->blkRefWznmMBlock,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->blkNum,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMControl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVector,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMFeed,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMTable,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMBlock,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refJ,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindUbigint(&rec->ref,&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMBlockItem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMBlockItem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMBlockItem::updateRst(
			ListWznmAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMBlockItem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMBlockItem::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMBlockItem::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMBlockItem::loadRecByRef(
			ubigint ref
			, WznmAMBlockItem** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMBlockItem WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMBlockItem::loadRefsByBlk(
			ubigint blkRefWznmMBlock
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blkRefWznmMBlock) + "", append, refs);
};

ubigint MyTblWznmAMBlockItem::loadRefsByClu(
			ubigint refWznmCAMBlockItem
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMBlockItem WHERE refWznmCAMBlockItem = " + to_string(refWznmCAMBlockItem) + "", append, refs);
};

ubigint MyTblWznmAMBlockItem::loadRstByBlk(
			ubigint blkRefWznmMBlock
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blkRefWznmMBlock) + " ORDER BY blkNum ASC", append, rst);
};

ubigint MyTblWznmAMBlockItem::loadRstByClu(
			ubigint refWznmCAMBlockItem
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmAMBlockItem WHERE refWznmCAMBlockItem = " + to_string(refWznmCAMBlockItem) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMBlockItem
 ******************************************************************************/

PgTblWznmAMBlockItem::PgTblWznmAMBlockItem() :
			TblWznmAMBlockItem()
			, PgTable()
		{
};

PgTblWznmAMBlockItem::~PgTblWznmAMBlockItem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMBlockItem::initStatements() {
	createStatement("TblWznmAMBlockItem_insertRec", "INSERT INTO TblWznmAMBlockItem (refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15) RETURNING ref", 15);
	createStatement("TblWznmAMBlockItem_updateRec", "UPDATE TblWznmAMBlockItem SET refWznmCAMBlockItem = $1, blkRefWznmMBlock = $2, blkNum = $3, ixVBasetype = $4, sref = $5, ixWznmVVartype = $6, refWznmMControl = $7, refWznmMVector = $8, refWznmMFeed = $9, refWznmMTable = $10, refWznmMBlock = $11, refJ = $12, Defval = $13, refWznmMVectoritem = $14, Comment = $15 WHERE ref = $16", 16);
	createStatement("TblWznmAMBlockItem_removeRecByRef", "DELETE FROM TblWznmAMBlockItem WHERE ref = $1", 1);

	createStatement("TblWznmAMBlockItem_loadRecByRef", "SELECT ref, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmAMBlockItem WHERE ref = $1", 1);
	createStatement("TblWznmAMBlockItem_loadRefsByBlk", "SELECT ref FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = $1", 1);
	createStatement("TblWznmAMBlockItem_loadRefsByClu", "SELECT ref FROM TblWznmAMBlockItem WHERE refWznmCAMBlockItem = $1", 1);
	createStatement("TblWznmAMBlockItem_loadRstByBlk", "SELECT ref, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = $1 ORDER BY blkNum ASC", 1);
	createStatement("TblWznmAMBlockItem_loadRstByClu", "SELECT ref, refWznmCAMBlockItem, blkRefWznmMBlock, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmAMBlockItem WHERE refWznmCAMBlockItem = $1", 1);
};

bool PgTblWznmAMBlockItem::loadRec(
			PGresult* res
			, WznmAMBlockItem** rec
		) {
	char* ptr;

	WznmAMBlockItem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMBlockItem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamblockitem"),
			PQfnumber(res, "blkrefwznmmblock"),
			PQfnumber(res, "blknum"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmfeed"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmblock"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmCAMBlockItem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->blkRefWznmMBlock = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->blkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMFeed = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWznmMBlock = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[15]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMBlockItem::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMBlockItem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmcamblockitem"),
			PQfnumber(res, "blkrefwznmmblock"),
			PQfnumber(res, "blknum"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmfeed"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmblock"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAMBlockItem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmCAMBlockItem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->blkRefWznmMBlock = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->blkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMFeed = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWznmMBlock = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[15]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMBlockItem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMBlockItem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMBlockItem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMBlockItem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMBlockItem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMBlockItem::loadRecBySQL(
			const string& sqlstr
			, WznmAMBlockItem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMBlockItem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMBlockItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMBlockItem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMBlockItem::insertRec(
			WznmAMBlockItem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmCAMBlockItem = htonl64(rec->refWznmCAMBlockItem);
	ubigint _blkRefWznmMBlock = htonl64(rec->blkRefWznmMBlock);
	uint _blkNum = htonl(rec->blkNum);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMFeed = htonl64(rec->refWznmMFeed);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMBlock = htonl64(rec->refWznmMBlock);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_refWznmCAMBlockItem,
		(char*) &_blkRefWznmMBlock,
		(char*) &_blkNum,
		(char*) &_ixVBasetype,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMControl,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMFeed,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMBlock,
		(char*) &_refJ,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMBlockItem_insertRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMBlockItem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMBlockItem::insertRst(
			ListWznmAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMBlockItem::updateRec(
			WznmAMBlockItem* rec
		) {
	PGresult* res;

	ubigint _refWznmCAMBlockItem = htonl64(rec->refWznmCAMBlockItem);
	ubigint _blkRefWznmMBlock = htonl64(rec->blkRefWznmMBlock);
	uint _blkNum = htonl(rec->blkNum);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMFeed = htonl64(rec->refWznmMFeed);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMBlock = htonl64(rec->refWznmMBlock);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmCAMBlockItem,
		(char*) &_blkRefWznmMBlock,
		(char*) &_blkNum,
		(char*) &_ixVBasetype,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMControl,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMFeed,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMBlock,
		(char*) &_refJ,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMBlockItem_updateRec", 16, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMBlockItem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMBlockItem::updateRst(
			ListWznmAMBlockItem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMBlockItem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMBlockItem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMBlockItem::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMBlockItem::loadRecByRef(
			ubigint ref
			, WznmAMBlockItem** rec
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

	return loadRecByStmt("TblWznmAMBlockItem_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMBlockItem::loadRefsByBlk(
			ubigint blkRefWznmMBlock
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _blkRefWznmMBlock = htonl64(blkRefWznmMBlock);

	const char* vals[] = {
		(char*) &_blkRefWznmMBlock
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMBlockItem_loadRefsByBlk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMBlockItem::loadRefsByClu(
			ubigint refWznmCAMBlockItem
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmCAMBlockItem = htonl64(refWznmCAMBlockItem);

	const char* vals[] = {
		(char*) &_refWznmCAMBlockItem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMBlockItem_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMBlockItem::loadRstByBlk(
			ubigint blkRefWznmMBlock
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	ubigint _blkRefWznmMBlock = htonl64(blkRefWznmMBlock);

	const char* vals[] = {
		(char*) &_blkRefWznmMBlock
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMBlockItem_loadRstByBlk", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAMBlockItem::loadRstByClu(
			ubigint refWznmCAMBlockItem
			, const bool append
			, ListWznmAMBlockItem& rst
		) {
	ubigint _refWznmCAMBlockItem = htonl64(refWznmCAMBlockItem);

	const char* vals[] = {
		(char*) &_refWznmCAMBlockItem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMBlockItem_loadRstByClu", 1, vals, l, f, append, rst);
};

#endif

