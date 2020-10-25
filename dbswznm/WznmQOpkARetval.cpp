/**
	* \file WznmQOpkARetval.cpp
	* Dbs and XML wrapper for table TblWznmQOpkARetval (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQOpkARetval.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkARetval
 ******************************************************************************/

WznmQOpkARetval::WznmQOpkARetval(
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
	this->Comment = Comment;
};

void WznmQOpkARetval::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQOpkARetval";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "vty", srefIxWznmVVartype);
		writeString(wr, "vty2", titIxWznmVVartype);
		writeString(wr, "vec", stubRefWznmMVector);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWznmVVartype", srefIxWznmVVartype);
		writeString(wr, "titIxWznmVVartype", titIxWznmVVartype);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQOpkARetval
 ******************************************************************************/

ListWznmQOpkARetval::ListWznmQOpkARetval() {
};

ListWznmQOpkARetval::ListWznmQOpkARetval(
			const ListWznmQOpkARetval& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkARetval(*(src.nodes[i]));
};

ListWznmQOpkARetval::~ListWznmQOpkARetval() {
	clear();
};

void ListWznmQOpkARetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQOpkARetval::size() const {
	return(nodes.size());
};

void ListWznmQOpkARetval::append(
			WznmQOpkARetval* rec
		) {
	nodes.push_back(rec);
};

ListWznmQOpkARetval& ListWznmQOpkARetval::operator=(
			const ListWznmQOpkARetval& src
		) {
	WznmQOpkARetval* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQOpkARetval(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQOpkARetval::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQOpkARetval";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQOpkARetval
 ******************************************************************************/

TblWznmQOpkARetval::TblWznmQOpkARetval() {
};

TblWznmQOpkARetval::~TblWznmQOpkARetval() {
};

bool TblWznmQOpkARetval::loadRecBySQL(
			const string& sqlstr
			, WznmQOpkARetval** rec
		) {
	return false;
};

ubigint TblWznmQOpkARetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	return 0;
};

ubigint TblWznmQOpkARetval::insertRec(
			WznmQOpkARetval* rec
		) {
	return 0;
};

ubigint TblWznmQOpkARetval::insertNewRec(
			WznmQOpkARetval** rec
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
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQOpkARetval* _rec = NULL;

	_rec = new WznmQOpkARetval(0, jref, jnum, ref, opkNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQOpkARetval::appendNewRecToRst(
			ListWznmQOpkARetval& rst
			, WznmQOpkARetval** rec
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
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQOpkARetval* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, opkNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQOpkARetval::insertRst(
			ListWznmQOpkARetval& rst
		) {
};

void TblWznmQOpkARetval::updateRec(
			WznmQOpkARetval* rec
		) {
};

void TblWznmQOpkARetval::updateRst(
			ListWznmQOpkARetval& rst
		) {
};

void TblWznmQOpkARetval::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQOpkARetval::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQOpkARetval::loadRecByQref(
			ubigint qref
			, WznmQOpkARetval** rec
		) {
	return false;
};

ubigint TblWznmQOpkARetval::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQOpkARetval
 ******************************************************************************/

MyTblWznmQOpkARetval::MyTblWznmQOpkARetval() :
			TblWznmQOpkARetval()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQOpkARetval::~MyTblWznmQOpkARetval() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQOpkARetval::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQOpkARetval (jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQOpkARetval SET jref = ?, jnum = ?, ref = ?, opkNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQOpkARetval WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQOpkARetval WHERE jref = ?", false);
};

bool MyTblWznmQOpkARetval::loadRecBySQL(
			const string& sqlstr
			, WznmQOpkARetval** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQOpkARetval* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpkARetval::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpkARetval::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQOpkARetval();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->opkNum = atol((char*) dbrow[4]); else _rec->opkNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWznmVVartype = atol((char*) dbrow[6]); else _rec->ixWznmVVartype = 0;
		if (dbrow[7]) _rec->refWznmMVector = atoll((char*) dbrow[7]); else _rec->refWznmMVector = 0;
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQOpkARetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQOpkARetval* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpkARetval::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpkARetval::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQOpkARetval();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->opkNum = atol((char*) dbrow[4]); else rec->opkNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWznmVVartype = atol((char*) dbrow[6]); else rec->ixWznmVVartype = 0;
			if (dbrow[7]) rec->refWznmMVector = atoll((char*) dbrow[7]); else rec->refWznmMVector = 0;
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQOpkARetval::insertRec(
			WznmQOpkARetval* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->opkNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQOpkARetval::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQOpkARetval::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQOpkARetval::insertRst(
			ListWznmQOpkARetval& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQOpkARetval::updateRec(
			WznmQOpkARetval* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->opkNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQOpkARetval::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQOpkARetval::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpkARetval::updateRst(
			ListWznmQOpkARetval& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQOpkARetval::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQOpkARetval::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQOpkARetval::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpkARetval::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQOpkARetval::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQOpkARetval::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQOpkARetval::loadRecByQref(
			ubigint qref
			, WznmQOpkARetval** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQOpkARetval WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQOpkARetval::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQOpkARetval WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQOpkARetval
 ******************************************************************************/

PgTblWznmQOpkARetval::PgTblWznmQOpkARetval() :
			TblWznmQOpkARetval()
			, PgTable()
		{
};

PgTblWznmQOpkARetval::~PgTblWznmQOpkARetval() {
};

void PgTblWznmQOpkARetval::initStatements() {
	createStatement("TblWznmQOpkARetval_insertRec", "INSERT INTO TblWznmQOpkARetval (jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWznmQOpkARetval_updateRec", "UPDATE TblWznmQOpkARetval SET jref = $1, jnum = $2, ref = $3, opkNum = $4, sref = $5, ixWznmVVartype = $6, refWznmMVector = $7, Comment = $8 WHERE qref = $9", 9);
	createStatement("TblWznmQOpkARetval_removeRecByQref", "DELETE FROM TblWznmQOpkARetval WHERE qref = $1", 1);
	createStatement("TblWznmQOpkARetval_removeRstByJref", "DELETE FROM TblWznmQOpkARetval WHERE jref = $1", 1);

	createStatement("TblWznmQOpkARetval_loadRecByQref", "SELECT qref, jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmQOpkARetval WHERE qref = $1", 1);
	createStatement("TblWznmQOpkARetval_loadRstByJref", "SELECT qref, jref, jnum, ref, opkNum, sref, ixWznmVVartype, refWznmMVector, Comment FROM TblWznmQOpkARetval WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQOpkARetval::loadRec(
			PGresult* res
			, WznmQOpkARetval** rec
		) {
	char* ptr;

	WznmQOpkARetval* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQOpkARetval();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "opknum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
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
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQOpkARetval::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQOpkARetval* rec;

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
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmQOpkARetval();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->opkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQOpkARetval::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQOpkARetval** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpkARetval::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpkARetval::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpkARetval::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQOpkARetval::loadRecBySQL(
			const string& sqlstr
			, WznmQOpkARetval** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpkARetval::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpkARetval::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpkARetval::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQOpkARetval::insertRec(
			WznmQOpkARetval* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_opkNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
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
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQOpkARetval_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpkARetval::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQOpkARetval::insertRst(
			ListWznmQOpkARetval& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQOpkARetval::updateRec(
			WznmQOpkARetval* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _opkNum = htonl(rec->opkNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_opkNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
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
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQOpkARetval_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpkARetval::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpkARetval::updateRst(
			ListWznmQOpkARetval& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQOpkARetval::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpkARetval_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpkARetval::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpkARetval::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpkARetval_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpkARetval::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQOpkARetval::loadRecByQref(
			ubigint qref
			, WznmQOpkARetval** rec
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

	return loadRecByStmt("TblWznmQOpkARetval_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQOpkARetval::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpkARetval& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQOpkARetval_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

