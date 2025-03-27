/**
	* \file WznmQOpxAInvarg.cpp
	* Dbs and XML wrapper for table TblWznmQOpxAInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpxAInvarg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpxAInvarg
 ******************************************************************************/

WznmQOpxAInvarg::WznmQOpxAInvarg(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint opxNum
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
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, opxNum(opxNum)
			, sref(sref)
			, ixWznmVVartype(ixWznmVVartype)
			, srefIxWznmVVartype(srefIxWznmVVartype)
			, titIxWznmVVartype(titIxWznmVVartype)
			, refWznmMVector(refWznmMVector)
			, stubRefWznmMVector(stubRefWznmMVector)
			, Defval(Defval)
			, refWznmMVectoritem(refWznmMVectoritem)
			, stubRefWznmMVectoritem(stubRefWznmMVectoritem)
			, Comment(Comment)
		{
};

void WznmQOpxAInvarg::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["vty"] = srefIxWznmVVartype;
		me["vty2"] = titIxWznmVVartype;
		me["vec"] = stubRefWznmMVector;
		me["dvl"] = Defval;
		me["vit"] = stubRefWznmMVectoritem;
		me["cmt"] = Comment;
	} else {
		me["sref"] = sref;
		me["srefIxWznmVVartype"] = srefIxWznmVVartype;
		me["titIxWznmVVartype"] = titIxWznmVVartype;
		me["stubRefWznmMVector"] = stubRefWznmMVector;
		me["Defval"] = Defval;
		me["stubRefWznmMVectoritem"] = stubRefWznmMVectoritem;
		me["Comment"] = Comment;
	};
};

void WznmQOpxAInvarg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQOpxAInvarg";

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
 class ListWznmQOpxAInvarg
 ******************************************************************************/

ListWznmQOpxAInvarg::ListWznmQOpxAInvarg() {
};

ListWznmQOpxAInvarg::ListWznmQOpxAInvarg(
			const ListWznmQOpxAInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxAInvarg(*(src.nodes[i]));
};

ListWznmQOpxAInvarg::~ListWznmQOpxAInvarg() {
	clear();
};

void ListWznmQOpxAInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQOpxAInvarg::size() const {
	return(nodes.size());
};

void ListWznmQOpxAInvarg::append(
			WznmQOpxAInvarg* rec
		) {
	nodes.push_back(rec);
};

ListWznmQOpxAInvarg& ListWznmQOpxAInvarg::operator=(
			const ListWznmQOpxAInvarg& src
		) {
	WznmQOpxAInvarg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQOpxAInvarg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQOpxAInvarg::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQOpxAInvarg";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQOpxAInvarg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQOpxAInvarg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQOpxAInvarg
 ******************************************************************************/

TblWznmQOpxAInvarg::TblWznmQOpxAInvarg() {
};

TblWznmQOpxAInvarg::~TblWznmQOpxAInvarg() {
};

bool TblWznmQOpxAInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmQOpxAInvarg** rec
		) {
	return false;
};

ubigint TblWznmQOpxAInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	return 0;
};

ubigint TblWznmQOpxAInvarg::insertRec(
			WznmQOpxAInvarg* rec
		) {
	return 0;
};

ubigint TblWznmQOpxAInvarg::insertNewRec(
			WznmQOpxAInvarg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint opxNum
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
	WznmQOpxAInvarg* _rec = NULL;

	_rec = new WznmQOpxAInvarg(0, jref, jnum, ref, opxNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Defval, refWznmMVectoritem, stubRefWznmMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQOpxAInvarg::appendNewRecToRst(
			ListWznmQOpxAInvarg& rst
			, WznmQOpxAInvarg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint opxNum
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
	WznmQOpxAInvarg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, opxNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Defval, refWznmMVectoritem, stubRefWznmMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQOpxAInvarg::insertRst(
			ListWznmQOpxAInvarg& rst
		) {
};

void TblWznmQOpxAInvarg::updateRec(
			WznmQOpxAInvarg* rec
		) {
};

void TblWznmQOpxAInvarg::updateRst(
			ListWznmQOpxAInvarg& rst
		) {
};

void TblWznmQOpxAInvarg::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQOpxAInvarg::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQOpxAInvarg::loadRecByQref(
			ubigint qref
			, WznmQOpxAInvarg** rec
		) {
	return false;
};

ubigint TblWznmQOpxAInvarg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQOpxAInvarg
 ******************************************************************************/

MyTblWznmQOpxAInvarg::MyTblWznmQOpxAInvarg() :
			TblWznmQOpxAInvarg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQOpxAInvarg::~MyTblWznmQOpxAInvarg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQOpxAInvarg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQOpxAInvarg (jref, jnum, ref, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQOpxAInvarg SET jref = ?, jnum = ?, ref = ?, opxNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Defval = ?, refWznmMVectoritem = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQOpxAInvarg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQOpxAInvarg WHERE jref = ?", false);
};

bool MyTblWznmQOpxAInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmQOpxAInvarg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQOpxAInvarg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpxAInvarg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpxAInvarg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQOpxAInvarg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->opxNum = atol((char*) dbrow[4]); else _rec->opxNum = 0;
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

ubigint MyTblWznmQOpxAInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQOpxAInvarg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpxAInvarg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpxAInvarg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQOpxAInvarg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->opxNum = atol((char*) dbrow[4]); else rec->opxNum = 0;
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

ubigint MyTblWznmQOpxAInvarg::insertRec(
			WznmQOpxAInvarg* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[7] = rec->Defval.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->opxNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQOpxAInvarg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQOpxAInvarg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQOpxAInvarg::insertRst(
			ListWznmQOpxAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQOpxAInvarg::updateRec(
			WznmQOpxAInvarg* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	l[7] = rec->Defval.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->opxNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQOpxAInvarg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQOpxAInvarg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpxAInvarg::updateRst(
			ListWznmQOpxAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQOpxAInvarg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQOpxAInvarg::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQOpxAInvarg::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpxAInvarg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQOpxAInvarg::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQOpxAInvarg::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQOpxAInvarg::loadRecByQref(
			ubigint qref
			, WznmQOpxAInvarg** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQOpxAInvarg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQOpxAInvarg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQOpxAInvarg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQOpxAInvarg
 ******************************************************************************/

PgTblWznmQOpxAInvarg::PgTblWznmQOpxAInvarg() :
			TblWznmQOpxAInvarg()
			, PgTable()
		{
};

PgTblWznmQOpxAInvarg::~PgTblWznmQOpxAInvarg() {
};

void PgTblWznmQOpxAInvarg::initStatements() {
	createStatement("TblWznmQOpxAInvarg_insertRec", "INSERT INTO TblWznmQOpxAInvarg (jref, jnum, ref, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQOpxAInvarg_updateRec", "UPDATE TblWznmQOpxAInvarg SET jref = $1, jnum = $2, ref = $3, opxNum = $4, sref = $5, ixWznmVVartype = $6, refWznmMVector = $7, Defval = $8, refWznmMVectoritem = $9, Comment = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQOpxAInvarg_removeRecByQref", "DELETE FROM TblWznmQOpxAInvarg WHERE qref = $1", 1);
	createStatement("TblWznmQOpxAInvarg_removeRstByJref", "DELETE FROM TblWznmQOpxAInvarg WHERE jref = $1", 1);

	createStatement("TblWznmQOpxAInvarg_loadRecByQref", "SELECT qref, jref, jnum, ref, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmQOpxAInvarg WHERE qref = $1", 1);
	createStatement("TblWznmQOpxAInvarg_loadRstByJref", "SELECT qref, jref, jnum, ref, opxNum, sref, ixWznmVVartype, refWznmMVector, Defval, refWznmMVectoritem, Comment FROM TblWznmQOpxAInvarg WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQOpxAInvarg::loadRec(
			PGresult* res
			, WznmQOpxAInvarg** rec
		) {
	char* ptr;

	WznmQOpxAInvarg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQOpxAInvarg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "opxnum"),
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
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->opxNum = atol(ptr);
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

ubigint PgTblWznmQOpxAInvarg::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQOpxAInvarg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "opxnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmQOpxAInvarg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->opxNum = atol(ptr);
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

bool PgTblWznmQOpxAInvarg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQOpxAInvarg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpxAInvarg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpxAInvarg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpxAInvarg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQOpxAInvarg::loadRecBySQL(
			const string& sqlstr
			, WznmQOpxAInvarg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpxAInvarg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpxAInvarg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpxAInvarg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQOpxAInvarg::insertRec(
			WznmQOpxAInvarg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _opxNum = htonl(rec->opxNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_opxNum,
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

	res = PQexecPrepared(dbs, "TblWznmQOpxAInvarg_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpxAInvarg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQOpxAInvarg::insertRst(
			ListWznmQOpxAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQOpxAInvarg::updateRec(
			WznmQOpxAInvarg* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _opxNum = htonl(rec->opxNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_opxNum,
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

	res = PQexecPrepared(dbs, "TblWznmQOpxAInvarg_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpxAInvarg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpxAInvarg::updateRst(
			ListWznmQOpxAInvarg& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQOpxAInvarg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpxAInvarg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpxAInvarg::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpxAInvarg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpxAInvarg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpxAInvarg::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQOpxAInvarg::loadRecByQref(
			ubigint qref
			, WznmQOpxAInvarg** rec
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

	return loadRecByStmt("TblWznmQOpxAInvarg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQOpxAInvarg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpxAInvarg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQOpxAInvarg_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
