/**
	* \file WznmQPrjPrj1NVersion.cpp
	* Dbs and XML wrapper for table TblWznmQPrjPrj1NVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPrjPrj1NVersion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrjPrj1NVersion
 ******************************************************************************/

WznmQPrjPrj1NVersion::WznmQPrjPrj1NVersion(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prjNum
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, stubRef(stubRef)
			, prjNum(prjNum)
		{
};

void WznmQPrjPrj1NVersion::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ref"] = stubRef;
	} else {
		me["stubRef"] = stubRef;
	};
};

void WznmQPrjPrj1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQPrjPrj1NVersion";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQPrjPrj1NVersion
 ******************************************************************************/

ListWznmQPrjPrj1NVersion::ListWznmQPrjPrj1NVersion() {
};

ListWznmQPrjPrj1NVersion::ListWznmQPrjPrj1NVersion(
			const ListWznmQPrjPrj1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjPrj1NVersion(*(src.nodes[i]));
};

ListWznmQPrjPrj1NVersion::~ListWznmQPrjPrj1NVersion() {
	clear();
};

void ListWznmQPrjPrj1NVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQPrjPrj1NVersion::size() const {
	return(nodes.size());
};

void ListWznmQPrjPrj1NVersion::append(
			WznmQPrjPrj1NVersion* rec
		) {
	nodes.push_back(rec);
};

ListWznmQPrjPrj1NVersion& ListWznmQPrjPrj1NVersion::operator=(
			const ListWznmQPrjPrj1NVersion& src
		) {
	WznmQPrjPrj1NVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQPrjPrj1NVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQPrjPrj1NVersion::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQPrjPrj1NVersion";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQPrjPrj1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQPrjPrj1NVersion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQPrjPrj1NVersion
 ******************************************************************************/

TblWznmQPrjPrj1NVersion::TblWznmQPrjPrj1NVersion() {
};

TblWznmQPrjPrj1NVersion::~TblWznmQPrjPrj1NVersion() {
};

bool TblWznmQPrjPrj1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQPrjPrj1NVersion** rec
		) {
	return false;
};

ubigint TblWznmQPrjPrj1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	return 0;
};

ubigint TblWznmQPrjPrj1NVersion::insertRec(
			WznmQPrjPrj1NVersion* rec
		) {
	return 0;
};

ubigint TblWznmQPrjPrj1NVersion::insertNewRec(
			WznmQPrjPrj1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prjNum
		) {
	ubigint retval = 0;
	WznmQPrjPrj1NVersion* _rec = NULL;

	_rec = new WznmQPrjPrj1NVersion(0, jref, jnum, ref, stubRef, prjNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQPrjPrj1NVersion::appendNewRecToRst(
			ListWznmQPrjPrj1NVersion& rst
			, WznmQPrjPrj1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prjNum
		) {
	ubigint retval = 0;
	WznmQPrjPrj1NVersion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, prjNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQPrjPrj1NVersion::insertRst(
			ListWznmQPrjPrj1NVersion& rst
		) {
};

void TblWznmQPrjPrj1NVersion::updateRec(
			WznmQPrjPrj1NVersion* rec
		) {
};

void TblWznmQPrjPrj1NVersion::updateRst(
			ListWznmQPrjPrj1NVersion& rst
		) {
};

void TblWznmQPrjPrj1NVersion::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQPrjPrj1NVersion::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQPrjPrj1NVersion::loadRecByQref(
			ubigint qref
			, WznmQPrjPrj1NVersion** rec
		) {
	return false;
};

ubigint TblWznmQPrjPrj1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQPrjPrj1NVersion
 ******************************************************************************/

MyTblWznmQPrjPrj1NVersion::MyTblWznmQPrjPrj1NVersion() :
			TblWznmQPrjPrj1NVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQPrjPrj1NVersion::~MyTblWznmQPrjPrj1NVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQPrjPrj1NVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQPrjPrj1NVersion (jref, jnum, ref, prjNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQPrjPrj1NVersion SET jref = ?, jnum = ?, ref = ?, prjNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQPrjPrj1NVersion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQPrjPrj1NVersion WHERE jref = ?", false);
};

bool MyTblWznmQPrjPrj1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQPrjPrj1NVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQPrjPrj1NVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQPrjPrj1NVersion();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->prjNum = atol((char*) dbrow[4]); else _rec->prjNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQPrjPrj1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQPrjPrj1NVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQPrjPrj1NVersion();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->prjNum = atol((char*) dbrow[4]); else rec->prjNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQPrjPrj1NVersion::insertRec(
			WznmQPrjPrj1NVersion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQPrjPrj1NVersion::insertRst(
			ListWznmQPrjPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQPrjPrj1NVersion::updateRec(
			WznmQPrjPrj1NVersion* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrjPrj1NVersion::updateRst(
			ListWznmQPrjPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQPrjPrj1NVersion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrjPrj1NVersion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQPrjPrj1NVersion::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQPrjPrj1NVersion::loadRecByQref(
			ubigint qref
			, WznmQPrjPrj1NVersion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQPrjPrj1NVersion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQPrjPrj1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQPrjPrj1NVersion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQPrjPrj1NVersion
 ******************************************************************************/

PgTblWznmQPrjPrj1NVersion::PgTblWznmQPrjPrj1NVersion() :
			TblWznmQPrjPrj1NVersion()
			, PgTable()
		{
};

PgTblWznmQPrjPrj1NVersion::~PgTblWznmQPrjPrj1NVersion() {
};

void PgTblWznmQPrjPrj1NVersion::initStatements() {
	createStatement("TblWznmQPrjPrj1NVersion_insertRec", "INSERT INTO TblWznmQPrjPrj1NVersion (jref, jnum, ref, prjNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQPrjPrj1NVersion_updateRec", "UPDATE TblWznmQPrjPrj1NVersion SET jref = $1, jnum = $2, ref = $3, prjNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQPrjPrj1NVersion_removeRecByQref", "DELETE FROM TblWznmQPrjPrj1NVersion WHERE qref = $1", 1);
	createStatement("TblWznmQPrjPrj1NVersion_removeRstByJref", "DELETE FROM TblWznmQPrjPrj1NVersion WHERE jref = $1", 1);

	createStatement("TblWznmQPrjPrj1NVersion_loadRecByQref", "SELECT qref, jref, jnum, ref, prjNum FROM TblWznmQPrjPrj1NVersion WHERE qref = $1", 1);
	createStatement("TblWznmQPrjPrj1NVersion_loadRstByJref", "SELECT qref, jref, jnum, ref, prjNum FROM TblWznmQPrjPrj1NVersion WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQPrjPrj1NVersion::loadRec(
			PGresult* res
			, WznmQPrjPrj1NVersion** rec
		) {
	char* ptr;

	WznmQPrjPrj1NVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQPrjPrj1NVersion();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "prjnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->prjNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQPrjPrj1NVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQPrjPrj1NVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "prjnum")
		};

		while (numread < numrow) {
			rec = new WznmQPrjPrj1NVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->prjNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQPrjPrj1NVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQPrjPrj1NVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrjPrj1NVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrjPrj1NVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrjPrj1NVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQPrjPrj1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQPrjPrj1NVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrjPrj1NVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrjPrj1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrjPrj1NVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQPrjPrj1NVersion::insertRec(
			WznmQPrjPrj1NVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _prjNum = htonl(rec->prjNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_prjNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPrjPrj1NVersion_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrjPrj1NVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQPrjPrj1NVersion::insertRst(
			ListWznmQPrjPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQPrjPrj1NVersion::updateRec(
			WznmQPrjPrj1NVersion* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _prjNum = htonl(rec->prjNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_prjNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPrjPrj1NVersion_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrjPrj1NVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrjPrj1NVersion::updateRst(
			ListWznmQPrjPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQPrjPrj1NVersion::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrjPrj1NVersion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrjPrj1NVersion::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrjPrj1NVersion::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrjPrj1NVersion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrjPrj1NVersion::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQPrjPrj1NVersion::loadRecByQref(
			ubigint qref
			, WznmQPrjPrj1NVersion** rec
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

	return loadRecByStmt("TblWznmQPrjPrj1NVersion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQPrjPrj1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrjPrj1NVersion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQPrjPrj1NVersion_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
