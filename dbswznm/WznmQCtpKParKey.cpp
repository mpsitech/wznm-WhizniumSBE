/**
	* \file WznmQCtpKParKey.cpp
	* Dbs and XML wrapper for table TblWznmQCtpKParKey (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCtpKParKey.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpKParKey
 ******************************************************************************/

WznmQCtpKParKey::WznmQCtpKParKey(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->klsNum = klsNum;
	this->Fixed = Fixed;
	this->yesnoFixed = yesnoFixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

void WznmQCtpKParKey::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["fix"] = yesnoFixed;
		me["srf"] = sref;
		me["avl"] = Avail;
		me["imp"] = Implied;
		me["tit"] = Title;
		me["cmt"] = Comment;
	} else {
		me["yesnoFixed"] = yesnoFixed;
		me["sref"] = sref;
		me["Avail"] = Avail;
		me["Implied"] = Implied;
		me["Title"] = Title;
		me["Comment"] = Comment;
	};
};

void WznmQCtpKParKey::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQCtpKParKey";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fix", yesnoFixed);
		writeString(wr, "srf", sref);
		writeString(wr, "avl", Avail);
		writeString(wr, "imp", Implied);
		writeString(wr, "tit", Title);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "yesnoFixed", yesnoFixed);
		writeString(wr, "sref", sref);
		writeString(wr, "Avail", Avail);
		writeString(wr, "Implied", Implied);
		writeString(wr, "Title", Title);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQCtpKParKey
 ******************************************************************************/

ListWznmQCtpKParKey::ListWznmQCtpKParKey() {
};

ListWznmQCtpKParKey::ListWznmQCtpKParKey(
			const ListWznmQCtpKParKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpKParKey(*(src.nodes[i]));
};

ListWznmQCtpKParKey::~ListWznmQCtpKParKey() {
	clear();
};

void ListWznmQCtpKParKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQCtpKParKey::size() const {
	return(nodes.size());
};

void ListWznmQCtpKParKey::append(
			WznmQCtpKParKey* rec
		) {
	nodes.push_back(rec);
};

ListWznmQCtpKParKey& ListWznmQCtpKParKey::operator=(
			const ListWznmQCtpKParKey& src
		) {
	WznmQCtpKParKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQCtpKParKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQCtpKParKey::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQCtpKParKey";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQCtpKParKey::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQCtpKParKey";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQCtpKParKey
 ******************************************************************************/

TblWznmQCtpKParKey::TblWznmQCtpKParKey() {
};

TblWznmQCtpKParKey::~TblWznmQCtpKParKey() {
};

bool TblWznmQCtpKParKey::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpKParKey** rec
		) {
	return false;
};

ubigint TblWznmQCtpKParKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	return 0;
};

ubigint TblWznmQCtpKParKey::insertRec(
			WznmQCtpKParKey* rec
		) {
	return 0;
};

ubigint TblWznmQCtpKParKey::insertNewRec(
			WznmQCtpKParKey** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQCtpKParKey* _rec = NULL;

	_rec = new WznmQCtpKParKey(0, jref, jnum, ref, klsNum, Fixed, yesnoFixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQCtpKParKey::appendNewRecToRst(
			ListWznmQCtpKParKey& rst
			, WznmQCtpKParKey** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmQCtpKParKey* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, klsNum, Fixed, yesnoFixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQCtpKParKey::insertRst(
			ListWznmQCtpKParKey& rst
		) {
};

void TblWznmQCtpKParKey::updateRec(
			WznmQCtpKParKey* rec
		) {
};

void TblWznmQCtpKParKey::updateRst(
			ListWznmQCtpKParKey& rst
		) {
};

void TblWznmQCtpKParKey::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQCtpKParKey::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQCtpKParKey::loadRecByQref(
			ubigint qref
			, WznmQCtpKParKey** rec
		) {
	return false;
};

ubigint TblWznmQCtpKParKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQCtpKParKey
 ******************************************************************************/

MyTblWznmQCtpKParKey::MyTblWznmQCtpKParKey() :
			TblWznmQCtpKParKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQCtpKParKey::~MyTblWznmQCtpKParKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQCtpKParKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQCtpKParKey (jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQCtpKParKey SET jref = ?, jnum = ?, ref = ?, klsNum = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQCtpKParKey WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQCtpKParKey WHERE jref = ?", false);
};

bool MyTblWznmQCtpKParKey::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpKParKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQCtpKParKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCtpKParKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCtpKParKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQCtpKParKey();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->klsNum = atol((char*) dbrow[4]); else _rec->klsNum = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQCtpKParKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQCtpKParKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCtpKParKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCtpKParKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQCtpKParKey();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->klsNum = atol((char*) dbrow[4]); else rec->klsNum = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQCtpKParKey::insertRec(
			WznmQCtpKParKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQCtpKParKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQCtpKParKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQCtpKParKey::insertRst(
			ListWznmQCtpKParKey& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQCtpKParKey::updateRec(
			WznmQCtpKParKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQCtpKParKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQCtpKParKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCtpKParKey::updateRst(
			ListWznmQCtpKParKey& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQCtpKParKey::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQCtpKParKey::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQCtpKParKey::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCtpKParKey::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQCtpKParKey::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQCtpKParKey::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQCtpKParKey::loadRecByQref(
			ubigint qref
			, WznmQCtpKParKey** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQCtpKParKey WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQCtpKParKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQCtpKParKey WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQCtpKParKey
 ******************************************************************************/

PgTblWznmQCtpKParKey::PgTblWznmQCtpKParKey() :
			TblWznmQCtpKParKey()
			, PgTable()
		{
};

PgTblWznmQCtpKParKey::~PgTblWznmQCtpKParKey() {
};

void PgTblWznmQCtpKParKey::initStatements() {
	createStatement("TblWznmQCtpKParKey_insertRec", "INSERT INTO TblWznmQCtpKParKey (jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWznmQCtpKParKey_updateRec", "UPDATE TblWznmQCtpKParKey SET jref = $1, jnum = $2, ref = $3, klsNum = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE qref = $12", 12);
	createStatement("TblWznmQCtpKParKey_removeRecByQref", "DELETE FROM TblWznmQCtpKParKey WHERE qref = $1", 1);
	createStatement("TblWznmQCtpKParKey_removeRstByJref", "DELETE FROM TblWznmQCtpKParKey WHERE jref = $1", 1);

	createStatement("TblWznmQCtpKParKey_loadRecByQref", "SELECT qref, jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmQCtpKParKey WHERE qref = $1", 1);
	createStatement("TblWznmQCtpKParKey_loadRstByJref", "SELECT qref, jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmQCtpKParKey WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQCtpKParKey::loadRec(
			PGresult* res
			, WznmQCtpKParKey** rec
		) {
	char* ptr;

	WznmQCtpKParKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQCtpKParKey();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQCtpKParKey::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQCtpKParKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmQCtpKParKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQCtpKParKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQCtpKParKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpKParKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCtpKParKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpKParKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQCtpKParKey::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpKParKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCtpKParKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCtpKParKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCtpKParKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQCtpKParKey::insertRec(
			WznmQCtpKParKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQCtpKParKey_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpKParKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQCtpKParKey::insertRst(
			ListWznmQCtpKParKey& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQCtpKParKey::updateRec(
			WznmQCtpKParKey* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQCtpKParKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpKParKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCtpKParKey::updateRst(
			ListWznmQCtpKParKey& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQCtpKParKey::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQCtpKParKey_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpKParKey::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCtpKParKey::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQCtpKParKey_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpKParKey::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQCtpKParKey::loadRecByQref(
			ubigint qref
			, WznmQCtpKParKey** rec
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

	return loadRecByStmt("TblWznmQCtpKParKey_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQCtpKParKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpKParKey& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQCtpKParKey_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
