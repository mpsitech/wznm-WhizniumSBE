/**
	* \file WznmQMtdAInvpar.cpp
	* Dbs and XML wrapper for table TblWznmQMtdAInvpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMtdAInvpar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMtdAInvpar
 ******************************************************************************/

WznmQMtdAInvpar::WznmQMtdAInvpar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint mtdNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const uint Length
			, const string Comment
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, mtdNum(mtdNum)
			, sref(sref)
			, ixWznmVVartype(ixWznmVVartype)
			, srefIxWznmVVartype(srefIxWznmVVartype)
			, titIxWznmVVartype(titIxWznmVVartype)
			, refWznmMVector(refWznmMVector)
			, stubRefWznmMVector(stubRefWznmMVector)
			, Length(Length)
			, Comment(Comment)
		{
};

void WznmQMtdAInvpar::writeJSON(
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
		me["len"] = Length;
		me["cmt"] = Comment;
	} else {
		me["sref"] = sref;
		me["srefIxWznmVVartype"] = srefIxWznmVVartype;
		me["titIxWznmVVartype"] = titIxWznmVVartype;
		me["stubRefWznmMVector"] = stubRefWznmMVector;
		me["Length"] = Length;
		me["Comment"] = Comment;
	};
};

void WznmQMtdAInvpar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQMtdAInvpar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "vty", srefIxWznmVVartype);
		writeString(wr, "vty2", titIxWznmVVartype);
		writeString(wr, "vec", stubRefWznmMVector);
		writeUint(wr, "len", Length);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWznmVVartype", srefIxWznmVVartype);
		writeString(wr, "titIxWznmVVartype", titIxWznmVVartype);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeUint(wr, "Length", Length);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQMtdAInvpar
 ******************************************************************************/

ListWznmQMtdAInvpar::ListWznmQMtdAInvpar() {
};

ListWznmQMtdAInvpar::ListWznmQMtdAInvpar(
			const ListWznmQMtdAInvpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtdAInvpar(*(src.nodes[i]));
};

ListWznmQMtdAInvpar::~ListWznmQMtdAInvpar() {
	clear();
};

void ListWznmQMtdAInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQMtdAInvpar::size() const {
	return(nodes.size());
};

void ListWznmQMtdAInvpar::append(
			WznmQMtdAInvpar* rec
		) {
	nodes.push_back(rec);
};

ListWznmQMtdAInvpar& ListWznmQMtdAInvpar::operator=(
			const ListWznmQMtdAInvpar& src
		) {
	WznmQMtdAInvpar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQMtdAInvpar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQMtdAInvpar::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQMtdAInvpar";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQMtdAInvpar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQMtdAInvpar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQMtdAInvpar
 ******************************************************************************/

TblWznmQMtdAInvpar::TblWznmQMtdAInvpar() {
};

TblWznmQMtdAInvpar::~TblWznmQMtdAInvpar() {
};

bool TblWznmQMtdAInvpar::loadRecBySQL(
			const string& sqlstr
			, WznmQMtdAInvpar** rec
		) {
	return false;
};

ubigint TblWznmQMtdAInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	return 0;
};

ubigint TblWznmQMtdAInvpar::insertRec(
			WznmQMtdAInvpar* rec
		) {
	return 0;
};

ubigint TblWznmQMtdAInvpar::insertNewRec(
			WznmQMtdAInvpar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint mtdNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const uint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQMtdAInvpar* _rec = NULL;

	_rec = new WznmQMtdAInvpar(0, jref, jnum, ref, mtdNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Length, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQMtdAInvpar::appendNewRecToRst(
			ListWznmQMtdAInvpar& rst
			, WznmQMtdAInvpar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint mtdNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const uint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQMtdAInvpar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, mtdNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Length, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQMtdAInvpar::insertRst(
			ListWznmQMtdAInvpar& rst
		) {
};

void TblWznmQMtdAInvpar::updateRec(
			WznmQMtdAInvpar* rec
		) {
};

void TblWznmQMtdAInvpar::updateRst(
			ListWznmQMtdAInvpar& rst
		) {
};

void TblWznmQMtdAInvpar::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQMtdAInvpar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQMtdAInvpar::loadRecByQref(
			ubigint qref
			, WznmQMtdAInvpar** rec
		) {
	return false;
};

ubigint TblWznmQMtdAInvpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQMtdAInvpar
 ******************************************************************************/

MyTblWznmQMtdAInvpar::MyTblWznmQMtdAInvpar() :
			TblWznmQMtdAInvpar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQMtdAInvpar::~MyTblWznmQMtdAInvpar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQMtdAInvpar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQMtdAInvpar (jref, jnum, ref, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQMtdAInvpar SET jref = ?, jnum = ?, ref = ?, mtdNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Length = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQMtdAInvpar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQMtdAInvpar WHERE jref = ?", false);
};

bool MyTblWznmQMtdAInvpar::loadRecBySQL(
			const string& sqlstr
			, WznmQMtdAInvpar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQMtdAInvpar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMtdAInvpar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMtdAInvpar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQMtdAInvpar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->mtdNum = atol((char*) dbrow[4]); else _rec->mtdNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWznmVVartype = atol((char*) dbrow[6]); else _rec->ixWznmVVartype = 0;
		if (dbrow[7]) _rec->refWznmMVector = atoll((char*) dbrow[7]); else _rec->refWznmMVector = 0;
		if (dbrow[8]) _rec->Length = atol((char*) dbrow[8]); else _rec->Length = 0;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQMtdAInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQMtdAInvpar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMtdAInvpar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMtdAInvpar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQMtdAInvpar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->mtdNum = atol((char*) dbrow[4]); else rec->mtdNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWznmVVartype = atol((char*) dbrow[6]); else rec->ixWznmVVartype = 0;
			if (dbrow[7]) rec->refWznmMVector = atoll((char*) dbrow[7]); else rec->refWznmMVector = 0;
			if (dbrow[8]) rec->Length = atol((char*) dbrow[8]); else rec->Length = 0;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQMtdAInvpar::insertRec(
			WznmQMtdAInvpar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mtdNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQMtdAInvpar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQMtdAInvpar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQMtdAInvpar::insertRst(
			ListWznmQMtdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQMtdAInvpar::updateRec(
			WznmQMtdAInvpar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mtdNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQMtdAInvpar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQMtdAInvpar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMtdAInvpar::updateRst(
			ListWznmQMtdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQMtdAInvpar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQMtdAInvpar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQMtdAInvpar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMtdAInvpar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQMtdAInvpar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQMtdAInvpar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQMtdAInvpar::loadRecByQref(
			ubigint qref
			, WznmQMtdAInvpar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQMtdAInvpar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQMtdAInvpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQMtdAInvpar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQMtdAInvpar
 ******************************************************************************/

PgTblWznmQMtdAInvpar::PgTblWznmQMtdAInvpar() :
			TblWznmQMtdAInvpar()
			, PgTable()
		{
};

PgTblWznmQMtdAInvpar::~PgTblWznmQMtdAInvpar() {
};

void PgTblWznmQMtdAInvpar::initStatements() {
	createStatement("TblWznmQMtdAInvpar_insertRec", "INSERT INTO TblWznmQMtdAInvpar (jref, jnum, ref, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWznmQMtdAInvpar_updateRec", "UPDATE TblWznmQMtdAInvpar SET jref = $1, jnum = $2, ref = $3, mtdNum = $4, sref = $5, ixWznmVVartype = $6, refWznmMVector = $7, Length = $8, Comment = $9 WHERE qref = $10", 10);
	createStatement("TblWznmQMtdAInvpar_removeRecByQref", "DELETE FROM TblWznmQMtdAInvpar WHERE qref = $1", 1);
	createStatement("TblWznmQMtdAInvpar_removeRstByJref", "DELETE FROM TblWznmQMtdAInvpar WHERE jref = $1", 1);

	createStatement("TblWznmQMtdAInvpar_loadRecByQref", "SELECT qref, jref, jnum, ref, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment FROM TblWznmQMtdAInvpar WHERE qref = $1", 1);
	createStatement("TblWznmQMtdAInvpar_loadRstByJref", "SELECT qref, jref, jnum, ref, mtdNum, sref, ixWznmVVartype, refWznmMVector, Length, Comment FROM TblWznmQMtdAInvpar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQMtdAInvpar::loadRec(
			PGresult* res
			, WznmQMtdAInvpar** rec
		) {
	char* ptr;

	WznmQMtdAInvpar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQMtdAInvpar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "mtdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->mtdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Length = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQMtdAInvpar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQMtdAInvpar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "mtdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmQMtdAInvpar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->mtdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Length = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQMtdAInvpar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQMtdAInvpar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMtdAInvpar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMtdAInvpar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMtdAInvpar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQMtdAInvpar::loadRecBySQL(
			const string& sqlstr
			, WznmQMtdAInvpar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMtdAInvpar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMtdAInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMtdAInvpar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQMtdAInvpar::insertRec(
			WznmQMtdAInvpar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _mtdNum = htonl(rec->mtdNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_mtdNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
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
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQMtdAInvpar_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMtdAInvpar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQMtdAInvpar::insertRst(
			ListWznmQMtdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQMtdAInvpar::updateRec(
			WznmQMtdAInvpar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _mtdNum = htonl(rec->mtdNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_mtdNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
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
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQMtdAInvpar_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMtdAInvpar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMtdAInvpar::updateRst(
			ListWznmQMtdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQMtdAInvpar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQMtdAInvpar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMtdAInvpar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMtdAInvpar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQMtdAInvpar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMtdAInvpar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQMtdAInvpar::loadRecByQref(
			ubigint qref
			, WznmQMtdAInvpar** rec
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

	return loadRecByStmt("TblWznmQMtdAInvpar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQMtdAInvpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMtdAInvpar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQMtdAInvpar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
