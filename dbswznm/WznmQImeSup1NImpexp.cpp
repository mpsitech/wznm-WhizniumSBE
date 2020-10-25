/**
	* \file WznmQImeSup1NImpexp.cpp
	* Dbs and XML wrapper for table TblWznmQImeSup1NImpexp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQImeSup1NImpexp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeSup1NImpexp
 ******************************************************************************/

WznmQImeSup1NImpexp::WznmQImeSup1NImpexp(
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

void WznmQImeSup1NImpexp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQImeSup1NImpexp";

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
 class ListWznmQImeSup1NImpexp
 ******************************************************************************/

ListWznmQImeSup1NImpexp::ListWznmQImeSup1NImpexp() {
};

ListWznmQImeSup1NImpexp::ListWznmQImeSup1NImpexp(
			const ListWznmQImeSup1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeSup1NImpexp(*(src.nodes[i]));
};

ListWznmQImeSup1NImpexp::~ListWznmQImeSup1NImpexp() {
	clear();
};

void ListWznmQImeSup1NImpexp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQImeSup1NImpexp::size() const {
	return(nodes.size());
};

void ListWznmQImeSup1NImpexp::append(
			WznmQImeSup1NImpexp* rec
		) {
	nodes.push_back(rec);
};

ListWznmQImeSup1NImpexp& ListWznmQImeSup1NImpexp::operator=(
			const ListWznmQImeSup1NImpexp& src
		) {
	WznmQImeSup1NImpexp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQImeSup1NImpexp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQImeSup1NImpexp::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQImeSup1NImpexp";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQImeSup1NImpexp
 ******************************************************************************/

TblWznmQImeSup1NImpexp::TblWznmQImeSup1NImpexp() {
};

TblWznmQImeSup1NImpexp::~TblWznmQImeSup1NImpexp() {
};

bool TblWznmQImeSup1NImpexp::loadRecBySQL(
			const string& sqlstr
			, WznmQImeSup1NImpexp** rec
		) {
	return false;
};

ubigint TblWznmQImeSup1NImpexp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	return 0;
};

ubigint TblWznmQImeSup1NImpexp::insertRec(
			WznmQImeSup1NImpexp* rec
		) {
	return 0;
};

ubigint TblWznmQImeSup1NImpexp::insertNewRec(
			WznmQImeSup1NImpexp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQImeSup1NImpexp* _rec = NULL;

	_rec = new WznmQImeSup1NImpexp(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQImeSup1NImpexp::appendNewRecToRst(
			ListWznmQImeSup1NImpexp& rst
			, WznmQImeSup1NImpexp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQImeSup1NImpexp* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQImeSup1NImpexp::insertRst(
			ListWznmQImeSup1NImpexp& rst
		) {
};

void TblWznmQImeSup1NImpexp::updateRec(
			WznmQImeSup1NImpexp* rec
		) {
};

void TblWznmQImeSup1NImpexp::updateRst(
			ListWznmQImeSup1NImpexp& rst
		) {
};

void TblWznmQImeSup1NImpexp::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQImeSup1NImpexp::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQImeSup1NImpexp::loadRecByQref(
			ubigint qref
			, WznmQImeSup1NImpexp** rec
		) {
	return false;
};

ubigint TblWznmQImeSup1NImpexp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQImeSup1NImpexp
 ******************************************************************************/

MyTblWznmQImeSup1NImpexp::MyTblWznmQImeSup1NImpexp() :
			TblWznmQImeSup1NImpexp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQImeSup1NImpexp::~MyTblWznmQImeSup1NImpexp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQImeSup1NImpexp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQImeSup1NImpexp (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQImeSup1NImpexp SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQImeSup1NImpexp WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQImeSup1NImpexp WHERE jref = ?", false);
};

bool MyTblWznmQImeSup1NImpexp::loadRecBySQL(
			const string& sqlstr
			, WznmQImeSup1NImpexp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQImeSup1NImpexp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeSup1NImpexp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeSup1NImpexp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQImeSup1NImpexp();

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

ubigint MyTblWznmQImeSup1NImpexp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQImeSup1NImpexp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeSup1NImpexp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeSup1NImpexp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQImeSup1NImpexp();

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

ubigint MyTblWznmQImeSup1NImpexp::insertRec(
			WznmQImeSup1NImpexp* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQImeSup1NImpexp::insertRst(
			ListWznmQImeSup1NImpexp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQImeSup1NImpexp::updateRec(
			WznmQImeSup1NImpexp* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeSup1NImpexp::updateRst(
			ListWznmQImeSup1NImpexp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQImeSup1NImpexp::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeSup1NImpexp::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQImeSup1NImpexp::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQImeSup1NImpexp::loadRecByQref(
			ubigint qref
			, WznmQImeSup1NImpexp** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQImeSup1NImpexp WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQImeSup1NImpexp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQImeSup1NImpexp WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQImeSup1NImpexp
 ******************************************************************************/

PgTblWznmQImeSup1NImpexp::PgTblWznmQImeSup1NImpexp() :
			TblWznmQImeSup1NImpexp()
			, PgTable()
		{
};

PgTblWznmQImeSup1NImpexp::~PgTblWznmQImeSup1NImpexp() {
};

void PgTblWznmQImeSup1NImpexp::initStatements() {
	createStatement("TblWznmQImeSup1NImpexp_insertRec", "INSERT INTO TblWznmQImeSup1NImpexp (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQImeSup1NImpexp_updateRec", "UPDATE TblWznmQImeSup1NImpexp SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQImeSup1NImpexp_removeRecByQref", "DELETE FROM TblWznmQImeSup1NImpexp WHERE qref = $1", 1);
	createStatement("TblWznmQImeSup1NImpexp_removeRstByJref", "DELETE FROM TblWznmQImeSup1NImpexp WHERE jref = $1", 1);

	createStatement("TblWznmQImeSup1NImpexp_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQImeSup1NImpexp WHERE qref = $1", 1);
	createStatement("TblWznmQImeSup1NImpexp_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQImeSup1NImpexp WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQImeSup1NImpexp::loadRec(
			PGresult* res
			, WznmQImeSup1NImpexp** rec
		) {
	char* ptr;

	WznmQImeSup1NImpexp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQImeSup1NImpexp();

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

ubigint PgTblWznmQImeSup1NImpexp::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQImeSup1NImpexp* rec;

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
			rec = new WznmQImeSup1NImpexp();

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

bool PgTblWznmQImeSup1NImpexp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQImeSup1NImpexp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeSup1NImpexp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeSup1NImpexp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeSup1NImpexp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQImeSup1NImpexp::loadRecBySQL(
			const string& sqlstr
			, WznmQImeSup1NImpexp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeSup1NImpexp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeSup1NImpexp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeSup1NImpexp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQImeSup1NImpexp::insertRec(
			WznmQImeSup1NImpexp* rec
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

	res = PQexecPrepared(dbs, "TblWznmQImeSup1NImpexp_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeSup1NImpexp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQImeSup1NImpexp::insertRst(
			ListWznmQImeSup1NImpexp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQImeSup1NImpexp::updateRec(
			WznmQImeSup1NImpexp* rec
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

	res = PQexecPrepared(dbs, "TblWznmQImeSup1NImpexp_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeSup1NImpexp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeSup1NImpexp::updateRst(
			ListWznmQImeSup1NImpexp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQImeSup1NImpexp::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeSup1NImpexp_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeSup1NImpexp::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeSup1NImpexp::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeSup1NImpexp_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeSup1NImpexp::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQImeSup1NImpexp::loadRecByQref(
			ubigint qref
			, WznmQImeSup1NImpexp** rec
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

	return loadRecByStmt("TblWznmQImeSup1NImpexp_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQImeSup1NImpexp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeSup1NImpexp& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQImeSup1NImpexp_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

