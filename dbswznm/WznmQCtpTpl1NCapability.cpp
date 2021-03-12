/**
	* \file WznmQCtpTpl1NCapability.cpp
	* Dbs and XML wrapper for table TblWznmQCtpTpl1NCapability (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCtpTpl1NCapability.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpTpl1NCapability
 ******************************************************************************/

WznmQCtpTpl1NCapability::WznmQCtpTpl1NCapability(
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

void WznmQCtpTpl1NCapability::writeJSON(
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

void WznmQCtpTpl1NCapability::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQCtpTpl1NCapability";

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
 class ListWznmQCtpTpl1NCapability
 ******************************************************************************/

ListWznmQCtpTpl1NCapability::ListWznmQCtpTpl1NCapability() {
};

ListWznmQCtpTpl1NCapability::ListWznmQCtpTpl1NCapability(
			const ListWznmQCtpTpl1NCapability& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpTpl1NCapability(*(src.nodes[i]));
};

ListWznmQCtpTpl1NCapability::~ListWznmQCtpTpl1NCapability() {
	clear();
};

void ListWznmQCtpTpl1NCapability::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQCtpTpl1NCapability::size() const {
	return(nodes.size());
};

void ListWznmQCtpTpl1NCapability::append(
			WznmQCtpTpl1NCapability* rec
		) {
	nodes.push_back(rec);
};

ListWznmQCtpTpl1NCapability& ListWznmQCtpTpl1NCapability::operator=(
			const ListWznmQCtpTpl1NCapability& src
		) {
	WznmQCtpTpl1NCapability* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQCtpTpl1NCapability(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQCtpTpl1NCapability::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQCtpTpl1NCapability";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQCtpTpl1NCapability::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQCtpTpl1NCapability";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQCtpTpl1NCapability
 ******************************************************************************/

TblWznmQCtpTpl1NCapability::TblWznmQCtpTpl1NCapability() {
};

TblWznmQCtpTpl1NCapability::~TblWznmQCtpTpl1NCapability() {
};

bool TblWznmQCtpTpl1NCapability::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpTpl1NCapability** rec
		) {
	return false;
};

ubigint TblWznmQCtpTpl1NCapability::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	return 0;
};

ubigint TblWznmQCtpTpl1NCapability::insertRec(
			WznmQCtpTpl1NCapability* rec
		) {
	return 0;
};

ubigint TblWznmQCtpTpl1NCapability::insertNewRec(
			WznmQCtpTpl1NCapability** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQCtpTpl1NCapability* _rec = NULL;

	_rec = new WznmQCtpTpl1NCapability(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQCtpTpl1NCapability::appendNewRecToRst(
			ListWznmQCtpTpl1NCapability& rst
			, WznmQCtpTpl1NCapability** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQCtpTpl1NCapability* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQCtpTpl1NCapability::insertRst(
			ListWznmQCtpTpl1NCapability& rst
		) {
};

void TblWznmQCtpTpl1NCapability::updateRec(
			WznmQCtpTpl1NCapability* rec
		) {
};

void TblWznmQCtpTpl1NCapability::updateRst(
			ListWznmQCtpTpl1NCapability& rst
		) {
};

void TblWznmQCtpTpl1NCapability::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQCtpTpl1NCapability::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQCtpTpl1NCapability::loadRecByQref(
			ubigint qref
			, WznmQCtpTpl1NCapability** rec
		) {
	return false;
};

ubigint TblWznmQCtpTpl1NCapability::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQCtpTpl1NCapability
 ******************************************************************************/

MyTblWznmQCtpTpl1NCapability::MyTblWznmQCtpTpl1NCapability() :
			TblWznmQCtpTpl1NCapability()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQCtpTpl1NCapability::~MyTblWznmQCtpTpl1NCapability() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQCtpTpl1NCapability::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQCtpTpl1NCapability (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQCtpTpl1NCapability SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQCtpTpl1NCapability WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQCtpTpl1NCapability WHERE jref = ?", false);
};

bool MyTblWznmQCtpTpl1NCapability::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpTpl1NCapability** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQCtpTpl1NCapability* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQCtpTpl1NCapability();

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

ubigint MyTblWznmQCtpTpl1NCapability::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQCtpTpl1NCapability* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQCtpTpl1NCapability();

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

ubigint MyTblWznmQCtpTpl1NCapability::insertRec(
			WznmQCtpTpl1NCapability* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQCtpTpl1NCapability::insertRst(
			ListWznmQCtpTpl1NCapability& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQCtpTpl1NCapability::updateRec(
			WznmQCtpTpl1NCapability* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCtpTpl1NCapability::updateRst(
			ListWznmQCtpTpl1NCapability& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQCtpTpl1NCapability::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCtpTpl1NCapability::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQCtpTpl1NCapability::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQCtpTpl1NCapability::loadRecByQref(
			ubigint qref
			, WznmQCtpTpl1NCapability** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQCtpTpl1NCapability WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQCtpTpl1NCapability::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQCtpTpl1NCapability WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQCtpTpl1NCapability
 ******************************************************************************/

PgTblWznmQCtpTpl1NCapability::PgTblWznmQCtpTpl1NCapability() :
			TblWznmQCtpTpl1NCapability()
			, PgTable()
		{
};

PgTblWznmQCtpTpl1NCapability::~PgTblWznmQCtpTpl1NCapability() {
};

void PgTblWznmQCtpTpl1NCapability::initStatements() {
	createStatement("TblWznmQCtpTpl1NCapability_insertRec", "INSERT INTO TblWznmQCtpTpl1NCapability (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQCtpTpl1NCapability_updateRec", "UPDATE TblWznmQCtpTpl1NCapability SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQCtpTpl1NCapability_removeRecByQref", "DELETE FROM TblWznmQCtpTpl1NCapability WHERE qref = $1", 1);
	createStatement("TblWznmQCtpTpl1NCapability_removeRstByJref", "DELETE FROM TblWznmQCtpTpl1NCapability WHERE jref = $1", 1);

	createStatement("TblWznmQCtpTpl1NCapability_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQCtpTpl1NCapability WHERE qref = $1", 1);
	createStatement("TblWznmQCtpTpl1NCapability_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQCtpTpl1NCapability WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQCtpTpl1NCapability::loadRec(
			PGresult* res
			, WznmQCtpTpl1NCapability** rec
		) {
	char* ptr;

	WznmQCtpTpl1NCapability* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQCtpTpl1NCapability();

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

ubigint PgTblWznmQCtpTpl1NCapability::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQCtpTpl1NCapability* rec;

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
			rec = new WznmQCtpTpl1NCapability();

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

bool PgTblWznmQCtpTpl1NCapability::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQCtpTpl1NCapability** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpTpl1NCapability::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCtpTpl1NCapability::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpTpl1NCapability::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQCtpTpl1NCapability::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpTpl1NCapability** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCtpTpl1NCapability::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCtpTpl1NCapability::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCtpTpl1NCapability::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQCtpTpl1NCapability::insertRec(
			WznmQCtpTpl1NCapability* rec
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

	res = PQexecPrepared(dbs, "TblWznmQCtpTpl1NCapability_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpTpl1NCapability::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQCtpTpl1NCapability::insertRst(
			ListWznmQCtpTpl1NCapability& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQCtpTpl1NCapability::updateRec(
			WznmQCtpTpl1NCapability* rec
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

	res = PQexecPrepared(dbs, "TblWznmQCtpTpl1NCapability_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpTpl1NCapability::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCtpTpl1NCapability::updateRst(
			ListWznmQCtpTpl1NCapability& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQCtpTpl1NCapability::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQCtpTpl1NCapability_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpTpl1NCapability::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCtpTpl1NCapability::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQCtpTpl1NCapability_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpTpl1NCapability::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQCtpTpl1NCapability::loadRecByQref(
			ubigint qref
			, WznmQCtpTpl1NCapability** rec
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

	return loadRecByStmt("TblWznmQCtpTpl1NCapability_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQCtpTpl1NCapability::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpTpl1NCapability& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQCtpTpl1NCapability_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
