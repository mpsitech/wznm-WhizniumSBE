/**
	* \file WznmQJobAVar.cpp
	* Dbs and XML wrapper for table TblWznmQJobAVar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQJobAVar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobAVar
 ******************************************************************************/

WznmQJobAVar::WznmQJobAVar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint jobNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const uint Length
			, const bool Shr
			, const string yesnoShr
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->jobNum = jobNum;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->refWznmMVector = refWznmMVector;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->Length = Length;
	this->Shr = Shr;
	this->yesnoShr = yesnoShr;
	this->Comment = Comment;
};

void WznmQJobAVar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQJobAVar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "vty", srefIxWznmVVartype);
		writeString(wr, "vty2", titIxWznmVVartype);
		writeString(wr, "vec", stubRefWznmMVector);
		writeUint(wr, "len", Length);
		writeString(wr, "shr", yesnoShr);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWznmVVartype", srefIxWznmVVartype);
		writeString(wr, "titIxWznmVVartype", titIxWznmVVartype);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeUint(wr, "Length", Length);
		writeString(wr, "yesnoShr", yesnoShr);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQJobAVar
 ******************************************************************************/

ListWznmQJobAVar::ListWznmQJobAVar() {
};

ListWznmQJobAVar::ListWznmQJobAVar(
			const ListWznmQJobAVar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobAVar(*(src.nodes[i]));
};

ListWznmQJobAVar::~ListWznmQJobAVar() {
	clear();
};

void ListWznmQJobAVar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQJobAVar::size() const {
	return(nodes.size());
};

void ListWznmQJobAVar::append(
			WznmQJobAVar* rec
		) {
	nodes.push_back(rec);
};

ListWznmQJobAVar& ListWznmQJobAVar::operator=(
			const ListWznmQJobAVar& src
		) {
	WznmQJobAVar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQJobAVar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQJobAVar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQJobAVar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQJobAVar
 ******************************************************************************/

TblWznmQJobAVar::TblWznmQJobAVar() {
};

TblWznmQJobAVar::~TblWznmQJobAVar() {
};

bool TblWznmQJobAVar::loadRecBySQL(
			const string& sqlstr
			, WznmQJobAVar** rec
		) {
	return false;
};

ubigint TblWznmQJobAVar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	return 0;
};

ubigint TblWznmQJobAVar::insertRec(
			WznmQJobAVar* rec
		) {
	return 0;
};

ubigint TblWznmQJobAVar::insertNewRec(
			WznmQJobAVar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint jobNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const uint Length
			, const bool Shr
			, const string yesnoShr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQJobAVar* _rec = NULL;

	_rec = new WznmQJobAVar(0, jref, jnum, ref, jobNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Length, Shr, yesnoShr, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQJobAVar::appendNewRecToRst(
			ListWznmQJobAVar& rst
			, WznmQJobAVar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint jobNum
			, const string sref
			, const uint ixWznmVVartype
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const uint Length
			, const bool Shr
			, const string yesnoShr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQJobAVar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, jobNum, sref, ixWznmVVartype, srefIxWznmVVartype, titIxWznmVVartype, refWznmMVector, stubRefWznmMVector, Length, Shr, yesnoShr, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQJobAVar::insertRst(
			ListWznmQJobAVar& rst
		) {
};

void TblWznmQJobAVar::updateRec(
			WznmQJobAVar* rec
		) {
};

void TblWznmQJobAVar::updateRst(
			ListWznmQJobAVar& rst
		) {
};

void TblWznmQJobAVar::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQJobAVar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQJobAVar::loadRecByQref(
			ubigint qref
			, WznmQJobAVar** rec
		) {
	return false;
};

ubigint TblWznmQJobAVar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQJobAVar
 ******************************************************************************/

MyTblWznmQJobAVar::MyTblWznmQJobAVar() :
			TblWznmQJobAVar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQJobAVar::~MyTblWznmQJobAVar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQJobAVar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQJobAVar (jref, jnum, ref, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQJobAVar SET jref = ?, jnum = ?, ref = ?, jobNum = ?, sref = ?, ixWznmVVartype = ?, refWznmMVector = ?, Length = ?, Shr = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQJobAVar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQJobAVar WHERE jref = ?", false);
};

bool MyTblWznmQJobAVar::loadRecBySQL(
			const string& sqlstr
			, WznmQJobAVar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQJobAVar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQJobAVar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQJobAVar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQJobAVar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->jobNum = atol((char*) dbrow[4]); else _rec->jobNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWznmVVartype = atol((char*) dbrow[6]); else _rec->ixWznmVVartype = 0;
		if (dbrow[7]) _rec->refWznmMVector = atoll((char*) dbrow[7]); else _rec->refWznmMVector = 0;
		if (dbrow[8]) _rec->Length = atol((char*) dbrow[8]); else _rec->Length = 0;
		if (dbrow[9]) _rec->Shr = (atoi((char*) dbrow[9]) != 0); else _rec->Shr = false;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQJobAVar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQJobAVar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQJobAVar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQJobAVar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQJobAVar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->jobNum = atol((char*) dbrow[4]); else rec->jobNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWznmVVartype = atol((char*) dbrow[6]); else rec->ixWznmVVartype = 0;
			if (dbrow[7]) rec->refWznmMVector = atoll((char*) dbrow[7]); else rec->refWznmMVector = 0;
			if (dbrow[8]) rec->Length = atol((char*) dbrow[8]); else rec->Length = 0;
			if (dbrow[9]) rec->Shr = (atoi((char*) dbrow[9]) != 0); else rec->Shr = false;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQJobAVar::insertRec(
			WznmQJobAVar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	tinyint Shr = rec->Shr;
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->jobNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Shr,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQJobAVar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQJobAVar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQJobAVar::insertRst(
			ListWznmQJobAVar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQJobAVar::updateRec(
			WznmQJobAVar* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	tinyint Shr = rec->Shr;
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->jobNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVVartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Shr,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQJobAVar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQJobAVar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQJobAVar::updateRst(
			ListWznmQJobAVar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQJobAVar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQJobAVar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQJobAVar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQJobAVar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQJobAVar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQJobAVar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQJobAVar::loadRecByQref(
			ubigint qref
			, WznmQJobAVar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQJobAVar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQJobAVar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQJobAVar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQJobAVar
 ******************************************************************************/

PgTblWznmQJobAVar::PgTblWznmQJobAVar() :
			TblWznmQJobAVar()
			, PgTable()
		{
};

PgTblWznmQJobAVar::~PgTblWznmQJobAVar() {
};

void PgTblWznmQJobAVar::initStatements() {
	createStatement("TblWznmQJobAVar_insertRec", "INSERT INTO TblWznmQJobAVar (jref, jnum, ref, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQJobAVar_updateRec", "UPDATE TblWznmQJobAVar SET jref = $1, jnum = $2, ref = $3, jobNum = $4, sref = $5, ixWznmVVartype = $6, refWznmMVector = $7, Length = $8, Shr = $9, Comment = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQJobAVar_removeRecByQref", "DELETE FROM TblWznmQJobAVar WHERE qref = $1", 1);
	createStatement("TblWznmQJobAVar_removeRstByJref", "DELETE FROM TblWznmQJobAVar WHERE jref = $1", 1);

	createStatement("TblWznmQJobAVar_loadRecByQref", "SELECT qref, jref, jnum, ref, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmQJobAVar WHERE qref = $1", 1);
	createStatement("TblWznmQJobAVar_loadRstByJref", "SELECT qref, jref, jnum, ref, jobNum, sref, ixWznmVVartype, refWznmMVector, Length, Shr, Comment FROM TblWznmQJobAVar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQJobAVar::loadRec(
			PGresult* res
			, WznmQJobAVar** rec
		) {
	char* ptr;

	WznmQJobAVar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQJobAVar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "jobnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "shr"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->jobNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmVVartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Length = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Shr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQJobAVar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQJobAVar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "jobnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmvvartype"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "shr"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmQJobAVar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->jobNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVVartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Length = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Shr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQJobAVar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQJobAVar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobAVar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQJobAVar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobAVar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQJobAVar::loadRecBySQL(
			const string& sqlstr
			, WznmQJobAVar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQJobAVar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQJobAVar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQJobAVar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQJobAVar::insertRec(
			WznmQJobAVar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _jobNum = htonl(rec->jobNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);
	smallint _Shr = htons((smallint) rec->Shr);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_jobNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
		(char*) &_Shr,
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
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQJobAVar_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobAVar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQJobAVar::insertRst(
			ListWznmQJobAVar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQJobAVar::updateRec(
			WznmQJobAVar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _jobNum = htonl(rec->jobNum);
	uint _ixWznmVVartype = htonl(rec->ixWznmVVartype);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	uint _Length = htonl(rec->Length);
	smallint _Shr = htons((smallint) rec->Shr);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_jobNum,
		rec->sref.c_str(),
		(char*) &_ixWznmVVartype,
		(char*) &_refWznmMVector,
		(char*) &_Length,
		(char*) &_Shr,
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
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQJobAVar_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobAVar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQJobAVar::updateRst(
			ListWznmQJobAVar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQJobAVar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQJobAVar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobAVar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQJobAVar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQJobAVar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobAVar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQJobAVar::loadRecByQref(
			ubigint qref
			, WznmQJobAVar** rec
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

	return loadRecByStmt("TblWznmQJobAVar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQJobAVar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobAVar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQJobAVar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

