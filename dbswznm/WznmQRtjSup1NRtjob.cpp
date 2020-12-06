/**
	* \file WznmQRtjSup1NRtjob.cpp
	* Dbs and XML wrapper for table TblWznmQRtjSup1NRtjob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRtjSup1NRtjob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtjSup1NRtjob
 ******************************************************************************/

WznmQRtjSup1NRtjob::WznmQRtjSup1NRtjob(
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

void WznmQRtjSup1NRtjob::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQRtjSup1NRtjob";

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
 class ListWznmQRtjSup1NRtjob
 ******************************************************************************/

ListWznmQRtjSup1NRtjob::ListWznmQRtjSup1NRtjob() {
};

ListWznmQRtjSup1NRtjob::ListWznmQRtjSup1NRtjob(
			const ListWznmQRtjSup1NRtjob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtjSup1NRtjob(*(src.nodes[i]));
};

ListWznmQRtjSup1NRtjob::~ListWznmQRtjSup1NRtjob() {
	clear();
};

void ListWznmQRtjSup1NRtjob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQRtjSup1NRtjob::size() const {
	return(nodes.size());
};

void ListWznmQRtjSup1NRtjob::append(
			WznmQRtjSup1NRtjob* rec
		) {
	nodes.push_back(rec);
};

ListWznmQRtjSup1NRtjob& ListWznmQRtjSup1NRtjob::operator=(
			const ListWznmQRtjSup1NRtjob& src
		) {
	WznmQRtjSup1NRtjob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQRtjSup1NRtjob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQRtjSup1NRtjob::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQRtjSup1NRtjob";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQRtjSup1NRtjob
 ******************************************************************************/

TblWznmQRtjSup1NRtjob::TblWznmQRtjSup1NRtjob() {
};

TblWznmQRtjSup1NRtjob::~TblWznmQRtjSup1NRtjob() {
};

bool TblWznmQRtjSup1NRtjob::loadRecBySQL(
			const string& sqlstr
			, WznmQRtjSup1NRtjob** rec
		) {
	return false;
};

ubigint TblWznmQRtjSup1NRtjob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	return 0;
};

ubigint TblWznmQRtjSup1NRtjob::insertRec(
			WznmQRtjSup1NRtjob* rec
		) {
	return 0;
};

ubigint TblWznmQRtjSup1NRtjob::insertNewRec(
			WznmQRtjSup1NRtjob** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQRtjSup1NRtjob* _rec = NULL;

	_rec = new WznmQRtjSup1NRtjob(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQRtjSup1NRtjob::appendNewRecToRst(
			ListWznmQRtjSup1NRtjob& rst
			, WznmQRtjSup1NRtjob** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQRtjSup1NRtjob* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQRtjSup1NRtjob::insertRst(
			ListWznmQRtjSup1NRtjob& rst
		) {
};

void TblWznmQRtjSup1NRtjob::updateRec(
			WznmQRtjSup1NRtjob* rec
		) {
};

void TblWznmQRtjSup1NRtjob::updateRst(
			ListWznmQRtjSup1NRtjob& rst
		) {
};

void TblWznmQRtjSup1NRtjob::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQRtjSup1NRtjob::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQRtjSup1NRtjob::loadRecByQref(
			ubigint qref
			, WznmQRtjSup1NRtjob** rec
		) {
	return false;
};

ubigint TblWznmQRtjSup1NRtjob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQRtjSup1NRtjob
 ******************************************************************************/

MyTblWznmQRtjSup1NRtjob::MyTblWznmQRtjSup1NRtjob() :
			TblWznmQRtjSup1NRtjob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQRtjSup1NRtjob::~MyTblWznmQRtjSup1NRtjob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQRtjSup1NRtjob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQRtjSup1NRtjob (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQRtjSup1NRtjob SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQRtjSup1NRtjob WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQRtjSup1NRtjob WHERE jref = ?", false);
};

bool MyTblWznmQRtjSup1NRtjob::loadRecBySQL(
			const string& sqlstr
			, WznmQRtjSup1NRtjob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQRtjSup1NRtjob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQRtjSup1NRtjob();

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

ubigint MyTblWznmQRtjSup1NRtjob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQRtjSup1NRtjob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQRtjSup1NRtjob();

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

ubigint MyTblWznmQRtjSup1NRtjob::insertRec(
			WznmQRtjSup1NRtjob* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQRtjSup1NRtjob::insertRst(
			ListWznmQRtjSup1NRtjob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQRtjSup1NRtjob::updateRec(
			WznmQRtjSup1NRtjob* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRtjSup1NRtjob::updateRst(
			ListWznmQRtjSup1NRtjob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQRtjSup1NRtjob::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRtjSup1NRtjob::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQRtjSup1NRtjob::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQRtjSup1NRtjob::loadRecByQref(
			ubigint qref
			, WznmQRtjSup1NRtjob** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQRtjSup1NRtjob WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQRtjSup1NRtjob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQRtjSup1NRtjob WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQRtjSup1NRtjob
 ******************************************************************************/

PgTblWznmQRtjSup1NRtjob::PgTblWznmQRtjSup1NRtjob() :
			TblWznmQRtjSup1NRtjob()
			, PgTable()
		{
};

PgTblWznmQRtjSup1NRtjob::~PgTblWznmQRtjSup1NRtjob() {
};

void PgTblWznmQRtjSup1NRtjob::initStatements() {
	createStatement("TblWznmQRtjSup1NRtjob_insertRec", "INSERT INTO TblWznmQRtjSup1NRtjob (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQRtjSup1NRtjob_updateRec", "UPDATE TblWznmQRtjSup1NRtjob SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQRtjSup1NRtjob_removeRecByQref", "DELETE FROM TblWznmQRtjSup1NRtjob WHERE qref = $1", 1);
	createStatement("TblWznmQRtjSup1NRtjob_removeRstByJref", "DELETE FROM TblWznmQRtjSup1NRtjob WHERE jref = $1", 1);

	createStatement("TblWznmQRtjSup1NRtjob_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQRtjSup1NRtjob WHERE qref = $1", 1);
	createStatement("TblWznmQRtjSup1NRtjob_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQRtjSup1NRtjob WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQRtjSup1NRtjob::loadRec(
			PGresult* res
			, WznmQRtjSup1NRtjob** rec
		) {
	char* ptr;

	WznmQRtjSup1NRtjob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQRtjSup1NRtjob();

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

ubigint PgTblWznmQRtjSup1NRtjob::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQRtjSup1NRtjob* rec;

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
			rec = new WznmQRtjSup1NRtjob();

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

bool PgTblWznmQRtjSup1NRtjob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQRtjSup1NRtjob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtjSup1NRtjob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRtjSup1NRtjob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtjSup1NRtjob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQRtjSup1NRtjob::loadRecBySQL(
			const string& sqlstr
			, WznmQRtjSup1NRtjob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRtjSup1NRtjob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRtjSup1NRtjob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRtjSup1NRtjob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQRtjSup1NRtjob::insertRec(
			WznmQRtjSup1NRtjob* rec
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

	res = PQexecPrepared(dbs, "TblWznmQRtjSup1NRtjob_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtjSup1NRtjob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQRtjSup1NRtjob::insertRst(
			ListWznmQRtjSup1NRtjob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQRtjSup1NRtjob::updateRec(
			WznmQRtjSup1NRtjob* rec
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

	res = PQexecPrepared(dbs, "TblWznmQRtjSup1NRtjob_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtjSup1NRtjob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRtjSup1NRtjob::updateRst(
			ListWznmQRtjSup1NRtjob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQRtjSup1NRtjob::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQRtjSup1NRtjob_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtjSup1NRtjob::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRtjSup1NRtjob::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQRtjSup1NRtjob_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtjSup1NRtjob::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQRtjSup1NRtjob::loadRecByQref(
			ubigint qref
			, WznmQRtjSup1NRtjob** rec
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

	return loadRecByStmt("TblWznmQRtjSup1NRtjob_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQRtjSup1NRtjob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtjSup1NRtjob& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQRtjSup1NRtjob_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
