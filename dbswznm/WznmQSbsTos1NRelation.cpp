/**
	* \file WznmQSbsTos1NRelation.cpp
	* Dbs and XML wrapper for table TblWznmQSbsTos1NRelation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSbsTos1NRelation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsTos1NRelation
 ******************************************************************************/

WznmQSbsTos1NRelation::WznmQSbsTos1NRelation(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void WznmQSbsTos1NRelation::writeJSON(
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

void WznmQSbsTos1NRelation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSbsTos1NRelation";

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
 class ListWznmQSbsTos1NRelation
 ******************************************************************************/

ListWznmQSbsTos1NRelation::ListWznmQSbsTos1NRelation() {
};

ListWznmQSbsTos1NRelation::ListWznmQSbsTos1NRelation(
			const ListWznmQSbsTos1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsTos1NRelation(*(src.nodes[i]));
};

ListWznmQSbsTos1NRelation::~ListWznmQSbsTos1NRelation() {
	clear();
};

void ListWznmQSbsTos1NRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSbsTos1NRelation::size() const {
	return(nodes.size());
};

void ListWznmQSbsTos1NRelation::append(
			WznmQSbsTos1NRelation* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSbsTos1NRelation& ListWznmQSbsTos1NRelation::operator=(
			const ListWznmQSbsTos1NRelation& src
		) {
	WznmQSbsTos1NRelation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSbsTos1NRelation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSbsTos1NRelation::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQSbsTos1NRelation";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQSbsTos1NRelation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSbsTos1NRelation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSbsTos1NRelation
 ******************************************************************************/

TblWznmQSbsTos1NRelation::TblWznmQSbsTos1NRelation() {
};

TblWznmQSbsTos1NRelation::~TblWznmQSbsTos1NRelation() {
};

bool TblWznmQSbsTos1NRelation::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsTos1NRelation** rec
		) {
	return false;
};

ubigint TblWznmQSbsTos1NRelation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	return 0;
};

ubigint TblWznmQSbsTos1NRelation::insertRec(
			WznmQSbsTos1NRelation* rec
		) {
	return 0;
};

ubigint TblWznmQSbsTos1NRelation::insertNewRec(
			WznmQSbsTos1NRelation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQSbsTos1NRelation* _rec = NULL;

	_rec = new WznmQSbsTos1NRelation(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSbsTos1NRelation::appendNewRecToRst(
			ListWznmQSbsTos1NRelation& rst
			, WznmQSbsTos1NRelation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQSbsTos1NRelation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSbsTos1NRelation::insertRst(
			ListWznmQSbsTos1NRelation& rst
		) {
};

void TblWznmQSbsTos1NRelation::updateRec(
			WznmQSbsTos1NRelation* rec
		) {
};

void TblWznmQSbsTos1NRelation::updateRst(
			ListWznmQSbsTos1NRelation& rst
		) {
};

void TblWznmQSbsTos1NRelation::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSbsTos1NRelation::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSbsTos1NRelation::loadRecByQref(
			ubigint qref
			, WznmQSbsTos1NRelation** rec
		) {
	return false;
};

ubigint TblWznmQSbsTos1NRelation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSbsTos1NRelation
 ******************************************************************************/

MyTblWznmQSbsTos1NRelation::MyTblWznmQSbsTos1NRelation() :
			TblWznmQSbsTos1NRelation()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSbsTos1NRelation::~MyTblWznmQSbsTos1NRelation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSbsTos1NRelation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSbsTos1NRelation (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSbsTos1NRelation SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSbsTos1NRelation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSbsTos1NRelation WHERE jref = ?", false);
};

bool MyTblWznmQSbsTos1NRelation::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsTos1NRelation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSbsTos1NRelation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsTos1NRelation::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsTos1NRelation::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQSbsTos1NRelation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSbsTos1NRelation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSbsTos1NRelation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsTos1NRelation::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsTos1NRelation::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQSbsTos1NRelation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSbsTos1NRelation::insertRec(
			WznmQSbsTos1NRelation* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSbsTos1NRelation::insertRst(
			ListWznmQSbsTos1NRelation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSbsTos1NRelation::updateRec(
			WznmQSbsTos1NRelation* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsTos1NRelation::updateRst(
			ListWznmQSbsTos1NRelation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSbsTos1NRelation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsTos1NRelation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSbsTos1NRelation::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSbsTos1NRelation::loadRecByQref(
			ubigint qref
			, WznmQSbsTos1NRelation** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSbsTos1NRelation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSbsTos1NRelation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSbsTos1NRelation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSbsTos1NRelation
 ******************************************************************************/

PgTblWznmQSbsTos1NRelation::PgTblWznmQSbsTos1NRelation() :
			TblWznmQSbsTos1NRelation()
			, PgTable()
		{
};

PgTblWznmQSbsTos1NRelation::~PgTblWznmQSbsTos1NRelation() {
};

void PgTblWznmQSbsTos1NRelation::initStatements() {
	createStatement("TblWznmQSbsTos1NRelation_insertRec", "INSERT INTO TblWznmQSbsTos1NRelation (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQSbsTos1NRelation_updateRec", "UPDATE TblWznmQSbsTos1NRelation SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQSbsTos1NRelation_removeRecByQref", "DELETE FROM TblWznmQSbsTos1NRelation WHERE qref = $1", 1);
	createStatement("TblWznmQSbsTos1NRelation_removeRstByJref", "DELETE FROM TblWznmQSbsTos1NRelation WHERE jref = $1", 1);

	createStatement("TblWznmQSbsTos1NRelation_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQSbsTos1NRelation WHERE qref = $1", 1);
	createStatement("TblWznmQSbsTos1NRelation_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQSbsTos1NRelation WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSbsTos1NRelation::loadRec(
			PGresult* res
			, WznmQSbsTos1NRelation** rec
		) {
	char* ptr;

	WznmQSbsTos1NRelation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSbsTos1NRelation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSbsTos1NRelation::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSbsTos1NRelation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WznmQSbsTos1NRelation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSbsTos1NRelation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSbsTos1NRelation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsTos1NRelation::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsTos1NRelation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsTos1NRelation::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSbsTos1NRelation::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsTos1NRelation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsTos1NRelation::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsTos1NRelation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsTos1NRelation::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSbsTos1NRelation::insertRec(
			WznmQSbsTos1NRelation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQSbsTos1NRelation_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsTos1NRelation::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSbsTos1NRelation::insertRst(
			ListWznmQSbsTos1NRelation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSbsTos1NRelation::updateRec(
			WznmQSbsTos1NRelation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQSbsTos1NRelation_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsTos1NRelation::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsTos1NRelation::updateRst(
			ListWznmQSbsTos1NRelation& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSbsTos1NRelation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsTos1NRelation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsTos1NRelation::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsTos1NRelation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsTos1NRelation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsTos1NRelation::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSbsTos1NRelation::loadRecByQref(
			ubigint qref
			, WznmQSbsTos1NRelation** rec
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

	return loadRecByStmt("TblWznmQSbsTos1NRelation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSbsTos1NRelation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsTos1NRelation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSbsTos1NRelation_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
