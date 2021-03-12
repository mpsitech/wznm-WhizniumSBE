/**
	* \file WznmQBlkAItem.cpp
	* Dbs and XML wrapper for table TblWznmQBlkAItem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQBlkAItem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBlkAItem
 ******************************************************************************/

WznmQBlkAItem::WznmQBlkAItem(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint blkNum
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMControl
			, const string stubRefWznmMControl
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMFeed
			, const string stubRefWznmMFeed
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint refWznmMBlock
			, const string stubRefWznmMBlock
			, const ubigint refJ
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->blkNum = blkNum;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->refWznmMControl = refWznmMControl;
	this->stubRefWznmMControl = stubRefWznmMControl;
	this->refWznmMVector = refWznmMVector;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->refWznmMFeed = refWznmMFeed;
	this->stubRefWznmMFeed = stubRefWznmMFeed;
	this->refWznmMTable = refWznmMTable;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->refWznmMBlock = refWznmMBlock;
	this->stubRefWznmMBlock = stubRefWznmMBlock;
	this->refJ = refJ;
	this->Defval = Defval;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->Comment = Comment;
};

void WznmQBlkAItem::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["typ"] = srefIxVBasetype;
		me["typ2"] = titIxVBasetype;
		me["srf"] = sref;
		me["vty"] = srefIxWznmVVartype;
		me["vty2"] = titIxWznmVVartype;
		me["con"] = stubRefWznmMControl;
		me["vec"] = stubRefWznmMVector;
		me["fed"] = stubRefWznmMFeed;
		me["tbl"] = stubRefWznmMTable;
		me["bl2"] = stubRefWznmMBlock;
		me["dfv"] = Defval;
		me["vit"] = stubRefWznmMVectoritem;
		me["cmt"] = Comment;
	} else {
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["sref"] = sref;
		me["srefIxWznmVVartype"] = srefIxWznmVVartype;
		me["titIxWznmVVartype"] = titIxWznmVVartype;
		me["stubRefWznmMControl"] = stubRefWznmMControl;
		me["stubRefWznmMVector"] = stubRefWznmMVector;
		me["stubRefWznmMFeed"] = stubRefWznmMFeed;
		me["stubRefWznmMTable"] = stubRefWznmMTable;
		me["stubRefWznmMBlock"] = stubRefWznmMBlock;
		me["Defval"] = Defval;
		me["stubRefWznmMVectoritem"] = stubRefWznmMVectoritem;
		me["Comment"] = Comment;
	};
};

void WznmQBlkAItem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQBlkAItem";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "srf", sref);
		writeString(wr, "vty", srefIxWznmVVartype);
		writeString(wr, "vty2", titIxWznmVVartype);
		writeString(wr, "con", stubRefWznmMControl);
		writeString(wr, "vec", stubRefWznmMVector);
		writeString(wr, "fed", stubRefWznmMFeed);
		writeString(wr, "tbl", stubRefWznmMTable);
		writeString(wr, "bl2", stubRefWznmMBlock);
		writeString(wr, "dfv", Defval);
		writeString(wr, "vit", stubRefWznmMVectoritem);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWznmVVartype", srefIxWznmVVartype);
		writeString(wr, "titIxWznmVVartype", titIxWznmVVartype);
		writeString(wr, "stubRefWznmMControl", stubRefWznmMControl);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeString(wr, "stubRefWznmMFeed", stubRefWznmMFeed);
		writeString(wr, "stubRefWznmMTable", stubRefWznmMTable);
		writeString(wr, "stubRefWznmMBlock", stubRefWznmMBlock);
		writeString(wr, "Defval", Defval);
		writeString(wr, "stubRefWznmMVectoritem", stubRefWznmMVectoritem);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQBlkAItem
 ******************************************************************************/

ListWznmQBlkAItem::ListWznmQBlkAItem() {
};

ListWznmQBlkAItem::ListWznmQBlkAItem(
			const ListWznmQBlkAItem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlkAItem(*(src.nodes[i]));
};

ListWznmQBlkAItem::~ListWznmQBlkAItem() {
	clear();
};

void ListWznmQBlkAItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQBlkAItem::size() const {
	return(nodes.size());
};

void ListWznmQBlkAItem::append(
			WznmQBlkAItem* rec
		) {
	nodes.push_back(rec);
};

ListWznmQBlkAItem& ListWznmQBlkAItem::operator=(
			const ListWznmQBlkAItem& src
		) {
	WznmQBlkAItem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQBlkAItem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQBlkAItem::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQBlkAItem";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQBlkAItem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQBlkAItem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQBlkAItem
 ******************************************************************************/

TblWznmQBlkAItem::TblWznmQBlkAItem() {
};

TblWznmQBlkAItem::~TblWznmQBlkAItem() {
};

bool TblWznmQBlkAItem::loadRecBySQL(
			const string& sqlstr
			, WznmQBlkAItem** rec
		) {
	return false;
};

ubigint TblWznmQBlkAItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	return 0;
};

ubigint TblWznmQBlkAItem::insertRec(
			WznmQBlkAItem* rec
		) {
	return 0;
};

ubigint TblWznmQBlkAItem::insertNewRec(
			WznmQBlkAItem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint blkNum
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMControl
			, const string stubRefWznmMControl
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMFeed
			, const string stubRefWznmMFeed
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint refWznmMBlock
			, const string stubRefWznmMBlock
			, const ubigint refJ
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQBlkAItem* _rec = NULL;

	_rec = new WznmQBlkAItem(0, jref, jnum, ref, blkNum, ixVBasetype, srefIxVBasetype, titIxVBasetype, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMControl, stubRefWznmMControl, refWznmMVector, stubRefWznmMVector, refWznmMFeed, stubRefWznmMFeed, refWznmMTable, stubRefWznmMTable, refWznmMBlock, stubRefWznmMBlock, refJ, Defval, refWznmMVectoritem, stubRefWznmMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQBlkAItem::appendNewRecToRst(
			ListWznmQBlkAItem& rst
			, WznmQBlkAItem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint blkNum
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMControl
			, const string stubRefWznmMControl
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMFeed
			, const string stubRefWznmMFeed
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint refWznmMBlock
			, const string stubRefWznmMBlock
			, const ubigint refJ
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQBlkAItem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, blkNum, ixVBasetype, srefIxVBasetype, titIxVBasetype, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMControl, stubRefWznmMControl, refWznmMVector, stubRefWznmMVector, refWznmMFeed, stubRefWznmMFeed, refWznmMTable, stubRefWznmMTable, refWznmMBlock, stubRefWznmMBlock, refJ, Defval, refWznmMVectoritem, stubRefWznmMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQBlkAItem::insertRst(
			ListWznmQBlkAItem& rst
		) {
};

void TblWznmQBlkAItem::updateRec(
			WznmQBlkAItem* rec
		) {
};

void TblWznmQBlkAItem::updateRst(
			ListWznmQBlkAItem& rst
		) {
};

void TblWznmQBlkAItem::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQBlkAItem::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQBlkAItem::loadRecByQref(
			ubigint qref
			, WznmQBlkAItem** rec
		) {
	return false;
};

ubigint TblWznmQBlkAItem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQBlkAItem
 ******************************************************************************/

MyTblWznmQBlkAItem::MyTblWznmQBlkAItem() :
			TblWznmQBlkAItem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQBlkAItem::~MyTblWznmQBlkAItem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQBlkAItem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQBlkAItem (jref, jnum, ref, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQBlkAItem SET jref = ?, jnum = ?, ref = ?, blkNum = ?, ixVBasetype = ?, sref = ?, ixWznmVVartype = ?, refWznmMControl = ?, refWznmMVector = ?, refWznmMFeed = ?, refWznmMTable = ?, refWznmMBlock = ?, refJ = ?, Defval = ?, refWznmMVectoritem = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQBlkAItem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQBlkAItem WHERE jref = ?", false);
};

bool MyTblWznmQBlkAItem::loadRecBySQL(
			const string& sqlstr
			, WznmQBlkAItem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQBlkAItem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBlkAItem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBlkAItem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQBlkAItem();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->blkNum = atol((char*) dbrow[4]); else _rec->blkNum = 0;
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->ixWznmVVartype = atol((char*) dbrow[7]); else _rec->ixWznmVVartype = 0;
		if (dbrow[8]) _rec->refWznmMControl = atoll((char*) dbrow[8]); else _rec->refWznmMControl = 0;
		if (dbrow[9]) _rec->refWznmMVector = atoll((char*) dbrow[9]); else _rec->refWznmMVector = 0;
		if (dbrow[10]) _rec->refWznmMFeed = atoll((char*) dbrow[10]); else _rec->refWznmMFeed = 0;
		if (dbrow[11]) _rec->refWznmMTable = atoll((char*) dbrow[11]); else _rec->refWznmMTable = 0;
		if (dbrow[12]) _rec->refWznmMBlock = atoll((char*) dbrow[12]); else _rec->refWznmMBlock = 0;
		if (dbrow[13]) _rec->refJ = atoll((char*) dbrow[13]); else _rec->refJ = 0;
		if (dbrow[14]) _rec->Defval.assign(dbrow[14], dblengths[14]); else _rec->Defval = "";
		if (dbrow[15]) _rec->refWznmMVectoritem = atoll((char*) dbrow[15]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[16]) _rec->Comment.assign(dbrow[16], dblengths[16]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQBlkAItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQBlkAItem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBlkAItem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBlkAItem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQBlkAItem();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->blkNum = atol((char*) dbrow[4]); else rec->blkNum = 0;
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->ixWznmVVartype = atol((char*) dbrow[7]); else rec->ixWznmVVartype = 0;
			if (dbrow[8]) rec->refWznmMControl = atoll((char*) dbrow[8]); else rec->refWznmMControl = 0;
			if (dbrow[9]) rec->refWznmMVector = atoll((char*) dbrow[9]); else rec->refWznmMVector = 0;
			if (dbrow[10]) rec->refWznmMFeed = atoll((char*) dbrow[10]); else rec->refWznmMFeed = 0;
			if (dbrow[11]) rec->refWznmMTable = atoll((char*) dbrow[11]); else rec->refWznmMTable = 0;
			if (dbrow[12]) rec->refWznmMBlock = atoll((char*) dbrow[12]); else rec->refWznmMBlock = 0;
			if (dbrow[13]) rec->refJ = atoll((char*) dbrow[13]); else rec->refJ = 0;
			if (dbrow[14]) rec->Defval.assign(dbrow[14], dblengths[14]); else rec->Defval = "";
			if (dbrow[15]) rec->refWznmMVectoritem = atoll((char*) dbrow[15]); else rec->refWznmMVectoritem = 0;
			if (dbrow[16]) rec->Comment.assign(dbrow[16], dblengths[16]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQBlkAItem::insertRec(
			WznmQBlkAItem* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	l[5] = rec->sref.length();
	l[13] = rec->Defval.length();
	l[15] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->blkNum,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixWznmVVartype,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMControl,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVector,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMFeed,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMTable,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refWznmMBlock,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->refJ,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQBlkAItem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQBlkAItem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQBlkAItem::insertRst(
			ListWznmQBlkAItem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQBlkAItem::updateRec(
			WznmQBlkAItem* rec
		) {
	unsigned long l[17]; my_bool n[17]; my_bool e[17];

	l[5] = rec->sref.length();
	l[13] = rec->Defval.length();
	l[15] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->blkNum,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixWznmVVartype,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMControl,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVector,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMFeed,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMTable,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refWznmMBlock,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->refJ,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindUbigint(&rec->qref,&(l[16]),&(n[16]),&(e[16]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQBlkAItem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQBlkAItem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBlkAItem::updateRst(
			ListWznmQBlkAItem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQBlkAItem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQBlkAItem::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQBlkAItem::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBlkAItem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQBlkAItem::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQBlkAItem::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQBlkAItem::loadRecByQref(
			ubigint qref
			, WznmQBlkAItem** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQBlkAItem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQBlkAItem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQBlkAItem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQBlkAItem
 ******************************************************************************/

PgTblWznmQBlkAItem::PgTblWznmQBlkAItem() :
			TblWznmQBlkAItem()
			, PgTable()
		{
};

PgTblWznmQBlkAItem::~PgTblWznmQBlkAItem() {
};

void PgTblWznmQBlkAItem::initStatements() {
	createStatement("TblWznmQBlkAItem_insertRec", "INSERT INTO TblWznmQBlkAItem (jref, jnum, ref, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16) RETURNING qref", 16);
	createStatement("TblWznmQBlkAItem_updateRec", "UPDATE TblWznmQBlkAItem SET jref = $1, jnum = $2, ref = $3, blkNum = $4, ixVBasetype = $5, sref = $6, ixWznmVVartype = $7, refWznmMControl = $8, refWznmMVector = $9, refWznmMFeed = $10, refWznmMTable = $11, refWznmMBlock = $12, refJ = $13, Defval = $14, refWznmMVectoritem = $15, Comment = $16 WHERE qref = $17", 17);
	createStatement("TblWznmQBlkAItem_removeRecByQref", "DELETE FROM TblWznmQBlkAItem WHERE qref = $1", 1);
	createStatement("TblWznmQBlkAItem_removeRstByJref", "DELETE FROM TblWznmQBlkAItem WHERE jref = $1", 1);

	createStatement("TblWznmQBlkAItem_loadRecByQref", "SELECT qref, jref, jnum, ref, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmQBlkAItem WHERE qref = $1", 1);
	createStatement("TblWznmQBlkAItem_loadRstByJref", "SELECT qref, jref, jnum, ref, blkNum, ixVBasetype, sref, ixWznmVVartype, refWznmMControl, refWznmMVector, refWznmMFeed, refWznmMTable, refWznmMBlock, refJ, Defval, refWznmMVectoritem, Comment FROM TblWznmQBlkAItem WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQBlkAItem::loadRec(
			PGresult* res
			, WznmQBlkAItem** rec
		) {
	char* ptr;

	WznmQBlkAItem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQBlkAItem();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
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

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->blkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWznmMFeed = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->refWznmMBlock = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[16]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQBlkAItem::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQBlkAItem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
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
			rec = new WznmQBlkAItem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->blkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWznmMFeed = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->refWznmMBlock = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[16]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQBlkAItem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQBlkAItem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlkAItem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBlkAItem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlkAItem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQBlkAItem::loadRecBySQL(
			const string& sqlstr
			, WznmQBlkAItem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBlkAItem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBlkAItem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBlkAItem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQBlkAItem::insertRec(
			WznmQBlkAItem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
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
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
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
		sizeof(uint),
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
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQBlkAItem_insertRec", 16, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlkAItem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQBlkAItem::insertRst(
			ListWznmQBlkAItem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQBlkAItem::updateRec(
			WznmQBlkAItem* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
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
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
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
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
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
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQBlkAItem_updateRec", 17, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlkAItem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBlkAItem::updateRst(
			ListWznmQBlkAItem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQBlkAItem::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmQBlkAItem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlkAItem::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBlkAItem::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmQBlkAItem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlkAItem::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQBlkAItem::loadRecByQref(
			ubigint qref
			, WznmQBlkAItem** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmQBlkAItem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQBlkAItem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlkAItem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQBlkAItem_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
