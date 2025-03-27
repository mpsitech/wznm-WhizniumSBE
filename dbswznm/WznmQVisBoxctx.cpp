/**
	* \file WznmQVisBoxctx.cpp
	* Dbs and XML wrapper for table TblWznmQVisBoxctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisBoxctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisBoxctx
 ******************************************************************************/

WznmQVisBoxctx::WznmQVisBoxctx(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint tref
			, const ubigint ref
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const string stubUnvUref
			, const smallint x
			, const smallint y
			, const string jnumsSub
			, const string jnumsLink
			, const int w
			, const int h
			, const string Content1
			, const string Content2
		) :
			qref(qref)
			, qwr(qwr)
			, jref(jref)
			, jnum(jnum)
			, tref(tref)
			, ref(ref)
			, unvIxWznmVMaintable(unvIxWznmVMaintable)
			, unvUref(unvUref)
			, stubUnvUref(stubUnvUref)
			, x(x)
			, y(y)
			, jnumsSub(jnumsSub)
			, jnumsLink(jnumsLink)
			, w(w)
			, h(h)
			, Content1(Content1)
			, Content2(Content2)
		{
};

void WznmQVisBoxctx::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["stubUnv"] = stubUnvUref;
		me["x"] = x;
		me["y"] = y;
		me["sub"] = jnumsSub;
		me["lnk"] = jnumsLink;
		me["w"] = w;
		me["h"] = h;
		me["cnt1"] = Content1;
		me["cnt2"] = Content2;
	} else {
		me["stubUnvUref"] = stubUnvUref;
		me["x"] = x;
		me["y"] = y;
		me["jnumsSub"] = jnumsSub;
		me["jnumsLink"] = jnumsLink;
		me["w"] = w;
		me["h"] = h;
		me["Content1"] = Content1;
		me["Content2"] = Content2;
	};
};

void WznmQVisBoxctx::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVisBoxctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "stubUnv", stubUnvUref);
		writeInt(wr, "x", x);
		writeInt(wr, "y", y);
		writeString(wr, "sub", jnumsSub);
		writeString(wr, "lnk", jnumsLink);
		writeInt(wr, "w", w);
		writeInt(wr, "h", h);
		writeString(wr, "cnt1", Content1);
		writeString(wr, "cnt2", Content2);
	} else {
		writeString(wr, "stubUnvUref", stubUnvUref);
		writeInt(wr, "x", x);
		writeInt(wr, "y", y);
		writeString(wr, "jnumsSub", jnumsSub);
		writeString(wr, "jnumsLink", jnumsLink);
		writeInt(wr, "w", w);
		writeInt(wr, "h", h);
		writeString(wr, "Content1", Content1);
		writeString(wr, "Content2", Content2);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQVisBoxctx
 ******************************************************************************/

ListWznmQVisBoxctx::ListWznmQVisBoxctx() {
};

ListWznmQVisBoxctx::ListWznmQVisBoxctx(
			const ListWznmQVisBoxctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisBoxctx(*(src.nodes[i]));
};

ListWznmQVisBoxctx::~ListWznmQVisBoxctx() {
	clear();
};

void ListWznmQVisBoxctx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVisBoxctx::size() const {
	return(nodes.size());
};

void ListWznmQVisBoxctx::append(
			WznmQVisBoxctx* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVisBoxctx& ListWznmQVisBoxctx::operator=(
			const ListWznmQVisBoxctx& src
		) {
	WznmQVisBoxctx* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVisBoxctx(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVisBoxctx::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQVisBoxctx";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQVisBoxctx::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVisBoxctx";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVisBoxctx
 ******************************************************************************/

TblWznmQVisBoxctx::TblWznmQVisBoxctx() {
};

TblWznmQVisBoxctx::~TblWznmQVisBoxctx() {
};

bool TblWznmQVisBoxctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisBoxctx** rec
		) {
	return false;
};

ubigint TblWznmQVisBoxctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	return 0;
};

ubigint TblWznmQVisBoxctx::insertRec(
			WznmQVisBoxctx* rec
		) {
	return 0;
};

ubigint TblWznmQVisBoxctx::insertNewRec(
			WznmQVisBoxctx** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint tref
			, const ubigint ref
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const string stubUnvUref
			, const smallint x
			, const smallint y
			, const string jnumsSub
			, const string jnumsLink
			, const int w
			, const int h
			, const string Content1
			, const string Content2
		) {
	ubigint retval = 0;
	WznmQVisBoxctx* _rec = NULL;

	_rec = new WznmQVisBoxctx(0, qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, stubUnvUref, x, y, jnumsSub, jnumsLink, w, h, Content1, Content2);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVisBoxctx::appendNewRecToRst(
			ListWznmQVisBoxctx& rst
			, WznmQVisBoxctx** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint tref
			, const ubigint ref
			, const uint unvIxWznmVMaintable
			, const ubigint unvUref
			, const string stubUnvUref
			, const smallint x
			, const smallint y
			, const string jnumsSub
			, const string jnumsLink
			, const int w
			, const int h
			, const string Content1
			, const string Content2
		) {
	ubigint retval = 0;
	WznmQVisBoxctx* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, stubUnvUref, x, y, jnumsSub, jnumsLink, w, h, Content1, Content2);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVisBoxctx::insertRst(
			ListWznmQVisBoxctx& rst
		) {
};

void TblWznmQVisBoxctx::updateRec(
			WznmQVisBoxctx* rec
		) {
};

void TblWznmQVisBoxctx::updateRst(
			ListWznmQVisBoxctx& rst
		) {
};

void TblWznmQVisBoxctx::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVisBoxctx::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVisBoxctx::loadRecByQref(
			ubigint qref
			, WznmQVisBoxctx** rec
		) {
	return false;
};

ubigint TblWznmQVisBoxctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVisBoxctx
 ******************************************************************************/

MyTblWznmQVisBoxctx::MyTblWznmQVisBoxctx() :
			TblWznmQVisBoxctx()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVisBoxctx::~MyTblWznmQVisBoxctx() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVisBoxctx::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVisBoxctx (qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, x, y) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVisBoxctx SET qwr = ?, jref = ?, jnum = ?, tref = ?, ref = ?, unvIxWznmVMaintable = ?, unvUref = ?, x = ?, y = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVisBoxctx WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVisBoxctx WHERE jref = ?", false);
};

bool MyTblWznmQVisBoxctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisBoxctx** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVisBoxctx* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisBoxctx::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisBoxctx::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVisBoxctx();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->tref = atoll((char*) dbrow[4]); else _rec->tref = 0;
		if (dbrow[5]) _rec->ref = atoll((char*) dbrow[5]); else _rec->ref = 0;
		if (dbrow[6]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[6]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[7]) _rec->unvUref = atoll((char*) dbrow[7]); else _rec->unvUref = 0;
		if (dbrow[8]) _rec->x = atoi((char*) dbrow[8]); else _rec->x = 0;
		if (dbrow[9]) _rec->y = atoi((char*) dbrow[9]); else _rec->y = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVisBoxctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVisBoxctx* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisBoxctx::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisBoxctx::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVisBoxctx();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->tref = atoll((char*) dbrow[4]); else rec->tref = 0;
			if (dbrow[5]) rec->ref = atoll((char*) dbrow[5]); else rec->ref = 0;
			if (dbrow[6]) rec->unvIxWznmVMaintable = atol((char*) dbrow[6]); else rec->unvIxWznmVMaintable = 0;
			if (dbrow[7]) rec->unvUref = atoll((char*) dbrow[7]); else rec->unvUref = 0;
			if (dbrow[8]) rec->x = atoi((char*) dbrow[8]); else rec->x = 0;
			if (dbrow[9]) rec->y = atoi((char*) dbrow[9]); else rec->y = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVisBoxctx::insertRec(
			WznmQVisBoxctx* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->tref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->unvUref,&(l[6]),&(n[6]),&(e[6])),
		bindSmallint(&rec->x,&(l[7]),&(n[7]),&(e[7])),
		bindSmallint(&rec->y,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVisBoxctx::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVisBoxctx::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVisBoxctx::insertRst(
			ListWznmQVisBoxctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVisBoxctx::updateRec(
			WznmQVisBoxctx* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->tref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->unvUref,&(l[6]),&(n[6]),&(e[6])),
		bindSmallint(&rec->x,&(l[7]),&(n[7]),&(e[7])),
		bindSmallint(&rec->y,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVisBoxctx::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVisBoxctx::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisBoxctx::updateRst(
			ListWznmQVisBoxctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVisBoxctx::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVisBoxctx::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVisBoxctx::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisBoxctx::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVisBoxctx::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVisBoxctx::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVisBoxctx::loadRecByQref(
			ubigint qref
			, WznmQVisBoxctx** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVisBoxctx WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVisBoxctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVisBoxctx WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVisBoxctx
 ******************************************************************************/

PgTblWznmQVisBoxctx::PgTblWznmQVisBoxctx() :
			TblWznmQVisBoxctx()
			, PgTable()
		{
};

PgTblWznmQVisBoxctx::~PgTblWznmQVisBoxctx() {
};

void PgTblWznmQVisBoxctx::initStatements() {
	createStatement("TblWznmQVisBoxctx_insertRec", "INSERT INTO TblWznmQVisBoxctx (qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, x, y) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWznmQVisBoxctx_updateRec", "UPDATE TblWznmQVisBoxctx SET qwr = $1, jref = $2, jnum = $3, tref = $4, ref = $5, unvIxWznmVMaintable = $6, unvUref = $7, x = $8, y = $9 WHERE qref = $10", 10);
	createStatement("TblWznmQVisBoxctx_removeRecByQref", "DELETE FROM TblWznmQVisBoxctx WHERE qref = $1", 1);
	createStatement("TblWznmQVisBoxctx_removeRstByJref", "DELETE FROM TblWznmQVisBoxctx WHERE jref = $1", 1);

	createStatement("TblWznmQVisBoxctx_loadRecByQref", "SELECT qref, qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, x, y FROM TblWznmQVisBoxctx WHERE qref = $1", 1);
	createStatement("TblWznmQVisBoxctx_loadRstByJref", "SELECT qref, qwr, jref, jnum, tref, ref, unvIxWznmVMaintable, unvUref, x, y FROM TblWznmQVisBoxctx WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVisBoxctx::loadRec(
			PGresult* res
			, WznmQVisBoxctx** rec
		) {
	char* ptr;

	WznmQVisBoxctx* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVisBoxctx();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "tref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->tref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->y = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVisBoxctx::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVisBoxctx* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "tref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new WznmQVisBoxctx();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->tref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->unvIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->y = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVisBoxctx::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVisBoxctx** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisBoxctx::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisBoxctx::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisBoxctx::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVisBoxctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisBoxctx** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisBoxctx::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisBoxctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisBoxctx::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVisBoxctx::insertRec(
			WznmQVisBoxctx* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _tref = htonl64(rec->tref);
	ubigint _ref = htonl64(rec->ref);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	smallint _x = htons(rec->x);
	smallint _y = htons(rec->y);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_tref,
		(char*) &_ref,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_x,
		(char*) &_y
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisBoxctx_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisBoxctx::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVisBoxctx::insertRst(
			ListWznmQVisBoxctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVisBoxctx::updateRec(
			WznmQVisBoxctx* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _tref = htonl64(rec->tref);
	ubigint _ref = htonl64(rec->ref);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	smallint _x = htons(rec->x);
	smallint _y = htons(rec->y);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_tref,
		(char*) &_ref,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_x,
		(char*) &_y,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisBoxctx_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisBoxctx::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisBoxctx::updateRst(
			ListWznmQVisBoxctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVisBoxctx::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisBoxctx_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisBoxctx::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisBoxctx::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisBoxctx_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisBoxctx::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVisBoxctx::loadRecByQref(
			ubigint qref
			, WznmQVisBoxctx** rec
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

	return loadRecByStmt("TblWznmQVisBoxctx_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVisBoxctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisBoxctx& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVisBoxctx_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
