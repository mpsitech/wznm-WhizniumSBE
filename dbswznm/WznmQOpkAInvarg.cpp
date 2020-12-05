/**
	* \file WznmQOpkAInvarg.cpp
	* Dbs and XML wrapper for table TblWznmQOpkAInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpkAInvarg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkAInvarg
 ******************************************************************************/

WznmQOpkAInvarg::WznmQOpkAInvarg(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->opkNum = opkNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->Defval = Defval;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->Comment = Comment;
};

void WznmQOpkAInvarg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQOpkAInvarg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "vty", srefIxWznmVVartype);
		writeString(wr, "vty2", titIxWznmVVartype);
		writeString(wr, "vec", stubRefWznmMVector);
		writeString(wr, "dvl", Defval);
		writeString(wr, "vit", stubRefWznmMVectoritem);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWznmVVartype", srefIxWznmVVartype);
		writeString(wr, "titIxWznmVVartype", titIxWznmVVartype);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeString(wr, "Defval", Defval);
		writeString(wr, "stubRefWznmMVectoritem", stubRefWznmMVectoritem);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQOpkAInvarg
 ******************************************************************************/

ListWznmQOpkAInvarg::ListWznmQOpkAInvarg() {
};

ListWznmQOpkAInvarg::ListWznmQOpkAInvarg(
			const ListWznmQOpkAInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkAInvarg(*(src.nodes[i]));
};

ListWznmQOpkAInvarg::~ListWznmQOpkAInvarg() {
	clear();
};

void ListWznmQOpkAInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQOpkAInvarg::size() const {
	return(nodes.size());
};

void ListWznmQOpkAInvarg::append(
			WznmQOpkAInvarg* rec
		) {
	nodes.push_back(rec);
};

ListWznmQOpkAInvarg& ListWznmQOpkAInvarg::operator=(
			const ListWznmQOpkAInvarg& src
		) {
	WznmQOpkAInvarg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQOpkAInvarg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQOpkAInvarg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQOpkAInvarg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQOpkAInvarg
 ******************************************************************************/

TblWznmQOpkAInvarg::TblWznmQOpkAInvarg() {
};

TblWznmQOpkAInvarg::~TblWznmQOpkAInvarg() {
};

bool TblWznmQOpkAInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmQOpkAInvarg** rec
		) {
	return false;
};

ubigint TblWznmQOpkAInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	return 0;
};

ubigint TblWznmQOpkAInvarg::insertRec(
			WznmQOpkAInvarg* rec
		) {
	return 0;
};

ubigint TblWznmQOpkAInvarg::insertNewRec(
			WznmQOpkAInvarg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQOpkAInvarg* _rec = NULL;

	_rec = new WznmQOpkAInvarg(0, jref, jnum, ref, opkNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Defval, refWznmMVectoritem, stubRefWznmMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQOpkAInvarg::appendNewRecToRst(
			ListWznmQOpkAInvarg& rst
			, WznmQOpkAInvarg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint opkNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const string Defval
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQOpkAInvarg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, opkNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Defval, refWznmMVectoritem, stubRefWznmMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQOpkAInvarg::insertRst(
			ListWznmQOpkAInvarg& rst
		) {
};

void TblWznmQOpkAInvarg::updateRec(
			WznmQOpkAInvarg* rec
		) {
};

void TblWznmQOpkAInvarg::updateRst(
			ListWznmQOpkAInvarg& rst
		) {
};

void TblWznmQOpkAInvarg::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQOpkAInvarg::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQOpkAInvarg::loadRecByQref(
			ubigint qref
			, WznmQOpkAInvarg** rec
		) {
	return false;
};

ubigint TblWznmQOpkAInvarg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQOpkAInvarg
 ******************************************************************************/

MyTblWznmQOpkAInvarg::MyTblWznmQOpkAInvarg() :
			TblWznmQOpkAInvarg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQOpkAInvarg::~MyTblWznmQOpkAInvarg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQOpkAInvarg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQOpkAInvarg (jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQOpkAInvarg SET jref = ?, jnum = ?, ref = ?, opkNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Defval = ?, refWznmMVectoritem = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQOpkAInvarg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQOpkAInvarg WHERE jref = ?", false);
};

bool MyTblWznmQOpkAInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmQOpkAInvarg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQOpkAInvarg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpkAInvarg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpkAInvarg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQOpkAInvarg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->opkNum = atol((char*) dbrow[4]); else _rec->opkNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWznmVVartype = atol((char*) dbrow[6]); else _rec->ixWznmVVartype = 0;
		if (dbrow[7]) _rec->refWznmMVector = atoll((char*) dbrow[7]); else _rec->refWznmMVector = 0;
		if (dbrow[8]) _rec->Defval.assign(dbrow[8], dblengths[8]); else _rec->Defval = "";
		if (dbrow[9]) _rec->refWznmMVectoritem = atoll((char*) dbrow[9]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQOpkAInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQOpkAInvarg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpkAInvarg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpkAInvarg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQOpkAInvarg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->opkNum = atol((char*) dbrow[4]); else rec->opkNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWznmVVartype = atol((char*) dbrow[6]); else rec->ixWznmVVartype = 0;
			if (dbrow[7]) rec->refWznmMVector = atoll((char*) dbrow[7]); else rec->refWznmMVector = 0;
			if (dbrow[8]) rec->Defval.assign(dbrow[8], dblengths[8]); else rec->Defval = "";
			if (dbrow[9]) rec->refWznmMVectoritem = atoll((char*) dbrow[9]); else rec->refWznmMVectoritem = 0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQOpkAInvarg::insertRec(
			WznmQOpkAInvarg* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[7] = rec->Defval.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->opkNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQOpkAInvarg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQOpkAInvarg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQOpkAInvarg::insertRst(
			ListWznmQOpkAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQOpkAInvarg::updateRec(
			WznmQOpkAInvarg* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	l[7] = rec->Defval.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->opkNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQOpkAInvarg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQOpkAInvarg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpkAInvarg::updateRst(
			ListWznmQOpkAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQOpkAInvarg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQOpkAInvarg::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQOpkAInvarg::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpkAInvarg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQOpkAInvarg::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQOpkAInvarg::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQOpkAInvarg::loadRecByQref(
			ubigint qref
			, WznmQOpkAInvarg** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQOpkAInvarg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQOpkAInvarg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQOpkAInvarg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQOpkAInvarg
 ******************************************************************************/

PgTblWznmQOpkAInvarg::PgTblWznmQOpkAInvarg() :
			TblWznmQOpkAInvarg()
			, PgTable()
		{
};

PgTblWznmQOpkAInvarg::~PgTblWznmQOpkAInvarg() {
};

void PgTblWznmQOpkAInvarg::initStatements() {
	createStatement("TblWznmQOpkAInvarg_insertRec", "INSERT INTO TblWznmQOpkAInvarg (jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQOpkAInvarg_updateRec", "UPDATE TblWznmQOpkAInvarg SET jref = $1, jnum = $2, ref = $3, opkNum = $4, sref = $5, ixWznmVVartype = $6, refWznmMVector = $7, Defval = $8, refWznmMVectoritem = $9, Comment = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQOpkAInvarg_removeRecByQref", "DELETE FROM TblWznmQOpkAInvarg WHERE qref = $1", 1);
	createStatement("TblWznmQOpkAInvarg_removeRstByJref", "DELETE FROM TblWznmQOpkAInvarg WHERE jref = $1", 1);

	createStatement("TblWznmQOpkAInvarg_loadRecByQref", "SELECT qref, jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmQOpkAInvarg WHERE qref = $1", 1);
	createStatement("TblWznmQOpkAInvarg_loadRstByJref", "SELECT qref, jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmQOpkAInvarg WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQOpkAInvarg::loadRec(
			PGresult* res
			, WznmQOpkAInvarg** rec
		) {
	char* ptr;

	WznmQOpkAInvarg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQOpkAInvarg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->opkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQOpkAInvarg::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQOpkAInvarg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmQOpkAInvarg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->opkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQOpkAInvarg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQOpkAInvarg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpkAInvarg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpkAInvarg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpkAInvarg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQOpkAInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmQOpkAInvarg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpkAInvarg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpkAInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpkAInvarg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQOpkAInvarg::insertRec(
			WznmQOpkAInvarg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_opkNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		rec->Defval.c_str(),
		(char*) &_refWznmMVectoritem,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQOpkAInvarg_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpkAInvarg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQOpkAInvarg::insertRst(
			ListWznmQOpkAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQOpkAInvarg::updateRec(
			WznmQOpkAInvarg* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_opkNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
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
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQOpkAInvarg_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpkAInvarg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpkAInvarg::updateRst(
			ListWznmQOpkAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQOpkAInvarg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpkAInvarg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpkAInvarg::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpkAInvarg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpkAInvarg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpkAInvarg::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQOpkAInvarg::loadRecByQref(
			ubigint qref
			, WznmQOpkAInvarg** rec
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

	return loadRecByStmt("TblWznmQOpkAInvarg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQOpkAInvarg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpkAInvarg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQOpkAInvarg_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

