/**
	* \file WznmQTblMNQuery.cpp
	* Dbs and XML wrapper for table TblWznmQTblMNQuery (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblMNQuery.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblMNQuery
 ******************************************************************************/

WznmQTblMNQuery::WznmQTblMNQuery(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefWznmMQuerymod
			, const ubigint ref
			, const bool Source
			, const string yesnoSource
			, const string Prefix
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->stubsTrefWznmMQuerymod = stubsTrefWznmMQuerymod;
	this->ref = ref;
	this->Source = Source;
	this->yesnoSource = yesnoSource;
	this->Prefix = Prefix;
};

void WznmQTblMNQuery::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTblMNQuery";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "tqmd", stubsTrefWznmMQuerymod);
		writeString(wr, "src", yesnoSource);
		writeString(wr, "pfx", Prefix);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubsTrefWznmMQuerymod", stubsTrefWznmMQuerymod);
		writeString(wr, "yesnoSource", yesnoSource);
		writeString(wr, "Prefix", Prefix);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQTblMNQuery
 ******************************************************************************/

ListWznmQTblMNQuery::ListWznmQTblMNQuery() {
};

ListWznmQTblMNQuery::ListWznmQTblMNQuery(
			const ListWznmQTblMNQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblMNQuery(*(src.nodes[i]));
};

ListWznmQTblMNQuery::~ListWznmQTblMNQuery() {
	clear();
};

void ListWznmQTblMNQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTblMNQuery::size() const {
	return(nodes.size());
};

void ListWznmQTblMNQuery::append(
			WznmQTblMNQuery* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTblMNQuery& ListWznmQTblMNQuery::operator=(
			const ListWznmQTblMNQuery& src
		) {
	WznmQTblMNQuery* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTblMNQuery(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTblMNQuery::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTblMNQuery";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTblMNQuery
 ******************************************************************************/

TblWznmQTblMNQuery::TblWznmQTblMNQuery() {
};

TblWznmQTblMNQuery::~TblWznmQTblMNQuery() {
};

bool TblWznmQTblMNQuery::loadRecBySQL(
			const string& sqlstr
			, WznmQTblMNQuery** rec
		) {
	return false;
};

ubigint TblWznmQTblMNQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	return 0;
};

ubigint TblWznmQTblMNQuery::insertRec(
			WznmQTblMNQuery* rec
		) {
	return 0;
};

ubigint TblWznmQTblMNQuery::insertNewRec(
			WznmQTblMNQuery** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefWznmMQuerymod
			, const ubigint ref
			, const bool Source
			, const string yesnoSource
			, const string Prefix
		) {
	ubigint retval = 0;
	WznmQTblMNQuery* _rec = NULL;

	_rec = new WznmQTblMNQuery(0, jref, jnum, mref, stubMref, stubsTrefWznmMQuerymod, ref, Source, yesnoSource, Prefix);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTblMNQuery::appendNewRecToRst(
			ListWznmQTblMNQuery& rst
			, WznmQTblMNQuery** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const string stubsTrefWznmMQuerymod
			, const ubigint ref
			, const bool Source
			, const string yesnoSource
			, const string Prefix
		) {
	ubigint retval = 0;
	WznmQTblMNQuery* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, stubsTrefWznmMQuerymod, ref, Source, yesnoSource, Prefix);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTblMNQuery::insertRst(
			ListWznmQTblMNQuery& rst
		) {
};

void TblWznmQTblMNQuery::updateRec(
			WznmQTblMNQuery* rec
		) {
};

void TblWznmQTblMNQuery::updateRst(
			ListWznmQTblMNQuery& rst
		) {
};

void TblWznmQTblMNQuery::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTblMNQuery::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTblMNQuery::loadRecByQref(
			ubigint qref
			, WznmQTblMNQuery** rec
		) {
	return false;
};

ubigint TblWznmQTblMNQuery::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTblMNQuery
 ******************************************************************************/

MyTblWznmQTblMNQuery::MyTblWznmQTblMNQuery() :
			TblWznmQTblMNQuery()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTblMNQuery::~MyTblWznmQTblMNQuery() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTblMNQuery::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTblMNQuery (jref, jnum, mref, ref, Source, Prefix) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTblMNQuery SET jref = ?, jnum = ?, mref = ?, ref = ?, Source = ?, Prefix = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTblMNQuery WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTblMNQuery WHERE jref = ?", false);
};

bool MyTblWznmQTblMNQuery::loadRecBySQL(
			const string& sqlstr
			, WznmQTblMNQuery** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTblMNQuery* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblMNQuery::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblMNQuery::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQTblMNQuery();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->Source = (atoi((char*) dbrow[5]) != 0); else _rec->Source = false;
		if (dbrow[6]) _rec->Prefix.assign(dbrow[6], dblengths[6]); else _rec->Prefix = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQTblMNQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTblMNQuery* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblMNQuery::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblMNQuery::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQTblMNQuery();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->Source = (atoi((char*) dbrow[5]) != 0); else rec->Source = false;
			if (dbrow[6]) rec->Prefix.assign(dbrow[6], dblengths[6]); else rec->Prefix = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQTblMNQuery::insertRec(
			WznmQTblMNQuery* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	tinyint Source = rec->Source;
	l[5] = rec->Prefix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Source,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTblMNQuery::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTblMNQuery::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTblMNQuery::insertRst(
			ListWznmQTblMNQuery& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTblMNQuery::updateRec(
			WznmQTblMNQuery* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	tinyint Source = rec->Source;
	l[5] = rec->Prefix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Source,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTblMNQuery::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTblMNQuery::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblMNQuery::updateRst(
			ListWznmQTblMNQuery& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTblMNQuery::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTblMNQuery::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTblMNQuery::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblMNQuery::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTblMNQuery::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTblMNQuery::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTblMNQuery::loadRecByQref(
			ubigint qref
			, WznmQTblMNQuery** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTblMNQuery WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTblMNQuery::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTblMNQuery WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTblMNQuery
 ******************************************************************************/

PgTblWznmQTblMNQuery::PgTblWznmQTblMNQuery() :
			TblWznmQTblMNQuery()
			, PgTable()
		{
};

PgTblWznmQTblMNQuery::~PgTblWznmQTblMNQuery() {
};

void PgTblWznmQTblMNQuery::initStatements() {
	createStatement("TblWznmQTblMNQuery_insertRec", "INSERT INTO TblWznmQTblMNQuery (jref, jnum, mref, ref, Source, Prefix) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQTblMNQuery_updateRec", "UPDATE TblWznmQTblMNQuery SET jref = $1, jnum = $2, mref = $3, ref = $4, Source = $5, Prefix = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQTblMNQuery_removeRecByQref", "DELETE FROM TblWznmQTblMNQuery WHERE qref = $1", 1);
	createStatement("TblWznmQTblMNQuery_removeRstByJref", "DELETE FROM TblWznmQTblMNQuery WHERE jref = $1", 1);

	createStatement("TblWznmQTblMNQuery_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, Source, Prefix FROM TblWznmQTblMNQuery WHERE qref = $1", 1);
	createStatement("TblWznmQTblMNQuery_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, Source, Prefix FROM TblWznmQTblMNQuery WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTblMNQuery::loadRec(
			PGresult* res
			, WznmQTblMNQuery** rec
		) {
	char* ptr;

	WznmQTblMNQuery* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTblMNQuery();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "source"),
			PQfnumber(res, "prefix")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Source = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Prefix.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQTblMNQuery::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTblMNQuery* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "source"),
			PQfnumber(res, "prefix")
		};

		while (numread < numrow) {
			rec = new WznmQTblMNQuery();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Source = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Prefix.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQTblMNQuery::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTblMNQuery** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblMNQuery::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblMNQuery::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblMNQuery::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTblMNQuery::loadRecBySQL(
			const string& sqlstr
			, WznmQTblMNQuery** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblMNQuery::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblMNQuery::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblMNQuery::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTblMNQuery::insertRec(
			WznmQTblMNQuery* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	smallint _Source = htons((smallint) rec->Source);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_Source,
		rec->Prefix.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQTblMNQuery_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblMNQuery::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTblMNQuery::insertRst(
			ListWznmQTblMNQuery& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTblMNQuery::updateRec(
			WznmQTblMNQuery* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	smallint _Source = htons((smallint) rec->Source);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_Source,
		rec->Prefix.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQTblMNQuery_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblMNQuery::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblMNQuery::updateRst(
			ListWznmQTblMNQuery& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTblMNQuery::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblMNQuery_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblMNQuery::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblMNQuery::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblMNQuery_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblMNQuery::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTblMNQuery::loadRecByQref(
			ubigint qref
			, WznmQTblMNQuery** rec
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

	return loadRecByStmt("TblWznmQTblMNQuery_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTblMNQuery::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblMNQuery& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTblMNQuery_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

