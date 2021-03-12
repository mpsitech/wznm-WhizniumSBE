/**
	* \file WznmQAppApp1NSequence.cpp
	* Dbs and XML wrapper for table TblWznmQAppApp1NSequence (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQAppApp1NSequence.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQAppApp1NSequence
 ******************************************************************************/

WznmQAppApp1NSequence::WznmQAppApp1NSequence(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint appNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->appNum = appNum;
};

void WznmQAppApp1NSequence::writeJSON(
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

void WznmQAppApp1NSequence::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQAppApp1NSequence";

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
 class ListWznmQAppApp1NSequence
 ******************************************************************************/

ListWznmQAppApp1NSequence::ListWznmQAppApp1NSequence() {
};

ListWznmQAppApp1NSequence::ListWznmQAppApp1NSequence(
			const ListWznmQAppApp1NSequence& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQAppApp1NSequence(*(src.nodes[i]));
};

ListWznmQAppApp1NSequence::~ListWznmQAppApp1NSequence() {
	clear();
};

void ListWznmQAppApp1NSequence::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQAppApp1NSequence::size() const {
	return(nodes.size());
};

void ListWznmQAppApp1NSequence::append(
			WznmQAppApp1NSequence* rec
		) {
	nodes.push_back(rec);
};

ListWznmQAppApp1NSequence& ListWznmQAppApp1NSequence::operator=(
			const ListWznmQAppApp1NSequence& src
		) {
	WznmQAppApp1NSequence* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQAppApp1NSequence(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQAppApp1NSequence::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQAppApp1NSequence";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQAppApp1NSequence::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQAppApp1NSequence";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQAppApp1NSequence
 ******************************************************************************/

TblWznmQAppApp1NSequence::TblWznmQAppApp1NSequence() {
};

TblWznmQAppApp1NSequence::~TblWznmQAppApp1NSequence() {
};

bool TblWznmQAppApp1NSequence::loadRecBySQL(
			const string& sqlstr
			, WznmQAppApp1NSequence** rec
		) {
	return false;
};

ubigint TblWznmQAppApp1NSequence::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	return 0;
};

ubigint TblWznmQAppApp1NSequence::insertRec(
			WznmQAppApp1NSequence* rec
		) {
	return 0;
};

ubigint TblWznmQAppApp1NSequence::insertNewRec(
			WznmQAppApp1NSequence** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint appNum
		) {
	ubigint retval = 0;
	WznmQAppApp1NSequence* _rec = NULL;

	_rec = new WznmQAppApp1NSequence(0, jref, jnum, ref, stubRef, appNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQAppApp1NSequence::appendNewRecToRst(
			ListWznmQAppApp1NSequence& rst
			, WznmQAppApp1NSequence** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint appNum
		) {
	ubigint retval = 0;
	WznmQAppApp1NSequence* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, appNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQAppApp1NSequence::insertRst(
			ListWznmQAppApp1NSequence& rst
		) {
};

void TblWznmQAppApp1NSequence::updateRec(
			WznmQAppApp1NSequence* rec
		) {
};

void TblWznmQAppApp1NSequence::updateRst(
			ListWznmQAppApp1NSequence& rst
		) {
};

void TblWznmQAppApp1NSequence::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQAppApp1NSequence::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQAppApp1NSequence::loadRecByQref(
			ubigint qref
			, WznmQAppApp1NSequence** rec
		) {
	return false;
};

ubigint TblWznmQAppApp1NSequence::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQAppApp1NSequence
 ******************************************************************************/

MyTblWznmQAppApp1NSequence::MyTblWznmQAppApp1NSequence() :
			TblWznmQAppApp1NSequence()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQAppApp1NSequence::~MyTblWznmQAppApp1NSequence() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQAppApp1NSequence::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQAppApp1NSequence (jref, jnum, ref, appNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQAppApp1NSequence SET jref = ?, jnum = ?, ref = ?, appNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQAppApp1NSequence WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQAppApp1NSequence WHERE jref = ?", false);
};

bool MyTblWznmQAppApp1NSequence::loadRecBySQL(
			const string& sqlstr
			, WznmQAppApp1NSequence** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQAppApp1NSequence* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQAppApp1NSequence::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQAppApp1NSequence::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQAppApp1NSequence();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->appNum = atol((char*) dbrow[4]); else _rec->appNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQAppApp1NSequence::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQAppApp1NSequence* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQAppApp1NSequence::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQAppApp1NSequence::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQAppApp1NSequence();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->appNum = atol((char*) dbrow[4]); else rec->appNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQAppApp1NSequence::insertRec(
			WznmQAppApp1NSequence* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->appNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQAppApp1NSequence::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQAppApp1NSequence::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQAppApp1NSequence::insertRst(
			ListWznmQAppApp1NSequence& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQAppApp1NSequence::updateRec(
			WznmQAppApp1NSequence* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->appNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQAppApp1NSequence::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQAppApp1NSequence::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQAppApp1NSequence::updateRst(
			ListWznmQAppApp1NSequence& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQAppApp1NSequence::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQAppApp1NSequence::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQAppApp1NSequence::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQAppApp1NSequence::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQAppApp1NSequence::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQAppApp1NSequence::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQAppApp1NSequence::loadRecByQref(
			ubigint qref
			, WznmQAppApp1NSequence** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQAppApp1NSequence WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQAppApp1NSequence::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQAppApp1NSequence WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQAppApp1NSequence
 ******************************************************************************/

PgTblWznmQAppApp1NSequence::PgTblWznmQAppApp1NSequence() :
			TblWznmQAppApp1NSequence()
			, PgTable()
		{
};

PgTblWznmQAppApp1NSequence::~PgTblWznmQAppApp1NSequence() {
};

void PgTblWznmQAppApp1NSequence::initStatements() {
	createStatement("TblWznmQAppApp1NSequence_insertRec", "INSERT INTO TblWznmQAppApp1NSequence (jref, jnum, ref, appNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQAppApp1NSequence_updateRec", "UPDATE TblWznmQAppApp1NSequence SET jref = $1, jnum = $2, ref = $3, appNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQAppApp1NSequence_removeRecByQref", "DELETE FROM TblWznmQAppApp1NSequence WHERE qref = $1", 1);
	createStatement("TblWznmQAppApp1NSequence_removeRstByJref", "DELETE FROM TblWznmQAppApp1NSequence WHERE jref = $1", 1);

	createStatement("TblWznmQAppApp1NSequence_loadRecByQref", "SELECT qref, jref, jnum, ref, appNum FROM TblWznmQAppApp1NSequence WHERE qref = $1", 1);
	createStatement("TblWznmQAppApp1NSequence_loadRstByJref", "SELECT qref, jref, jnum, ref, appNum FROM TblWznmQAppApp1NSequence WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQAppApp1NSequence::loadRec(
			PGresult* res
			, WznmQAppApp1NSequence** rec
		) {
	char* ptr;

	WznmQAppApp1NSequence* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQAppApp1NSequence();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "appnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->appNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQAppApp1NSequence::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQAppApp1NSequence* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "appnum")
		};

		while (numread < numrow) {
			rec = new WznmQAppApp1NSequence();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->appNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQAppApp1NSequence::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQAppApp1NSequence** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQAppApp1NSequence::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQAppApp1NSequence::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQAppApp1NSequence::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQAppApp1NSequence::loadRecBySQL(
			const string& sqlstr
			, WznmQAppApp1NSequence** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQAppApp1NSequence::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQAppApp1NSequence::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQAppApp1NSequence::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQAppApp1NSequence::insertRec(
			WznmQAppApp1NSequence* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _appNum = htonl(rec->appNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_appNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQAppApp1NSequence_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQAppApp1NSequence::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQAppApp1NSequence::insertRst(
			ListWznmQAppApp1NSequence& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQAppApp1NSequence::updateRec(
			WznmQAppApp1NSequence* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _appNum = htonl(rec->appNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_appNum,
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

	res = PQexecPrepared(dbs, "TblWznmQAppApp1NSequence_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQAppApp1NSequence::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQAppApp1NSequence::updateRst(
			ListWznmQAppApp1NSequence& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQAppApp1NSequence::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQAppApp1NSequence_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQAppApp1NSequence::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQAppApp1NSequence::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQAppApp1NSequence_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQAppApp1NSequence::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQAppApp1NSequence::loadRecByQref(
			ubigint qref
			, WznmQAppApp1NSequence** rec
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

	return loadRecByStmt("TblWznmQAppApp1NSequence_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQAppApp1NSequence::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQAppApp1NSequence& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQAppApp1NSequence_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
