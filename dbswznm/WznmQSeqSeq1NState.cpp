/**
	* \file WznmQSeqSeq1NState.cpp
	* Dbs and XML wrapper for table TblWznmQSeqSeq1NState (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQSeqSeq1NState.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSeqSeq1NState
 ******************************************************************************/

WznmQSeqSeq1NState::WznmQSeqSeq1NState(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint seqNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->seqNum = seqNum;
};

void WznmQSeqSeq1NState::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSeqSeq1NState";

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
 class ListWznmQSeqSeq1NState
 ******************************************************************************/

ListWznmQSeqSeq1NState::ListWznmQSeqSeq1NState() {
};

ListWznmQSeqSeq1NState::ListWznmQSeqSeq1NState(
			const ListWznmQSeqSeq1NState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSeqSeq1NState(*(src.nodes[i]));
};

ListWznmQSeqSeq1NState::~ListWznmQSeqSeq1NState() {
	clear();
};

void ListWznmQSeqSeq1NState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSeqSeq1NState::size() const {
	return(nodes.size());
};

void ListWznmQSeqSeq1NState::append(
			WznmQSeqSeq1NState* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSeqSeq1NState& ListWznmQSeqSeq1NState::operator=(
			const ListWznmQSeqSeq1NState& src
		) {
	WznmQSeqSeq1NState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSeqSeq1NState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSeqSeq1NState::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSeqSeq1NState";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSeqSeq1NState
 ******************************************************************************/

TblWznmQSeqSeq1NState::TblWznmQSeqSeq1NState() {
};

TblWznmQSeqSeq1NState::~TblWznmQSeqSeq1NState() {
};

bool TblWznmQSeqSeq1NState::loadRecBySQL(
			const string& sqlstr
			, WznmQSeqSeq1NState** rec
		) {
	return false;
};

ubigint TblWznmQSeqSeq1NState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	return 0;
};

ubigint TblWznmQSeqSeq1NState::insertRec(
			WznmQSeqSeq1NState* rec
		) {
	return 0;
};

ubigint TblWznmQSeqSeq1NState::insertNewRec(
			WznmQSeqSeq1NState** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint seqNum
		) {
	ubigint retval = 0;
	WznmQSeqSeq1NState* _rec = NULL;

	_rec = new WznmQSeqSeq1NState(0, jref, jnum, ref, stubRef, seqNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSeqSeq1NState::appendNewRecToRst(
			ListWznmQSeqSeq1NState& rst
			, WznmQSeqSeq1NState** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint seqNum
		) {
	ubigint retval = 0;
	WznmQSeqSeq1NState* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, seqNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSeqSeq1NState::insertRst(
			ListWznmQSeqSeq1NState& rst
		) {
};

void TblWznmQSeqSeq1NState::updateRec(
			WznmQSeqSeq1NState* rec
		) {
};

void TblWznmQSeqSeq1NState::updateRst(
			ListWznmQSeqSeq1NState& rst
		) {
};

void TblWznmQSeqSeq1NState::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSeqSeq1NState::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSeqSeq1NState::loadRecByQref(
			ubigint qref
			, WznmQSeqSeq1NState** rec
		) {
	return false;
};

ubigint TblWznmQSeqSeq1NState::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSeqSeq1NState
 ******************************************************************************/

MyTblWznmQSeqSeq1NState::MyTblWznmQSeqSeq1NState() :
			TblWznmQSeqSeq1NState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSeqSeq1NState::~MyTblWznmQSeqSeq1NState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSeqSeq1NState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSeqSeq1NState (jref, jnum, ref, seqNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSeqSeq1NState SET jref = ?, jnum = ?, ref = ?, seqNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSeqSeq1NState WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSeqSeq1NState WHERE jref = ?", false);
};

bool MyTblWznmQSeqSeq1NState::loadRecBySQL(
			const string& sqlstr
			, WznmQSeqSeq1NState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSeqSeq1NState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSeqSeq1NState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSeqSeq1NState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQSeqSeq1NState();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->seqNum = atol((char*) dbrow[4]); else _rec->seqNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSeqSeq1NState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSeqSeq1NState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSeqSeq1NState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSeqSeq1NState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQSeqSeq1NState();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->seqNum = atol((char*) dbrow[4]); else rec->seqNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSeqSeq1NState::insertRec(
			WznmQSeqSeq1NState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->seqNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSeqSeq1NState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSeqSeq1NState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSeqSeq1NState::insertRst(
			ListWznmQSeqSeq1NState& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSeqSeq1NState::updateRec(
			WznmQSeqSeq1NState* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->seqNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSeqSeq1NState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSeqSeq1NState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSeqSeq1NState::updateRst(
			ListWznmQSeqSeq1NState& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSeqSeq1NState::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSeqSeq1NState::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSeqSeq1NState::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSeqSeq1NState::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSeqSeq1NState::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSeqSeq1NState::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSeqSeq1NState::loadRecByQref(
			ubigint qref
			, WznmQSeqSeq1NState** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSeqSeq1NState WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSeqSeq1NState::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSeqSeq1NState WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSeqSeq1NState
 ******************************************************************************/

PgTblWznmQSeqSeq1NState::PgTblWznmQSeqSeq1NState() :
			TblWznmQSeqSeq1NState()
			, PgTable()
		{
};

PgTblWznmQSeqSeq1NState::~PgTblWznmQSeqSeq1NState() {
};

void PgTblWznmQSeqSeq1NState::initStatements() {
	createStatement("TblWznmQSeqSeq1NState_insertRec", "INSERT INTO TblWznmQSeqSeq1NState (jref, jnum, ref, seqNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQSeqSeq1NState_updateRec", "UPDATE TblWznmQSeqSeq1NState SET jref = $1, jnum = $2, ref = $3, seqNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQSeqSeq1NState_removeRecByQref", "DELETE FROM TblWznmQSeqSeq1NState WHERE qref = $1", 1);
	createStatement("TblWznmQSeqSeq1NState_removeRstByJref", "DELETE FROM TblWznmQSeqSeq1NState WHERE jref = $1", 1);

	createStatement("TblWznmQSeqSeq1NState_loadRecByQref", "SELECT qref, jref, jnum, ref, seqNum FROM TblWznmQSeqSeq1NState WHERE qref = $1", 1);
	createStatement("TblWznmQSeqSeq1NState_loadRstByJref", "SELECT qref, jref, jnum, ref, seqNum FROM TblWznmQSeqSeq1NState WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSeqSeq1NState::loadRec(
			PGresult* res
			, WznmQSeqSeq1NState** rec
		) {
	char* ptr;

	WznmQSeqSeq1NState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSeqSeq1NState();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "seqnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->seqNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSeqSeq1NState::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSeqSeq1NState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "seqnum")
		};

		while (numread < numrow) {
			rec = new WznmQSeqSeq1NState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->seqNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSeqSeq1NState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSeqSeq1NState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSeqSeq1NState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSeqSeq1NState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSeqSeq1NState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSeqSeq1NState::loadRecBySQL(
			const string& sqlstr
			, WznmQSeqSeq1NState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSeqSeq1NState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSeqSeq1NState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSeqSeq1NState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSeqSeq1NState::insertRec(
			WznmQSeqSeq1NState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _seqNum = htonl(rec->seqNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_seqNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQSeqSeq1NState_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSeqSeq1NState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSeqSeq1NState::insertRst(
			ListWznmQSeqSeq1NState& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSeqSeq1NState::updateRec(
			WznmQSeqSeq1NState* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _seqNum = htonl(rec->seqNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_seqNum,
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

	res = PQexecPrepared(dbs, "TblWznmQSeqSeq1NState_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSeqSeq1NState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSeqSeq1NState::updateRst(
			ListWznmQSeqSeq1NState& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSeqSeq1NState::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSeqSeq1NState_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSeqSeq1NState::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSeqSeq1NState::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSeqSeq1NState_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSeqSeq1NState::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSeqSeq1NState::loadRecByQref(
			ubigint qref
			, WznmQSeqSeq1NState** rec
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

	return loadRecByStmt("TblWznmQSeqSeq1NState_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSeqSeq1NState::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSeqSeq1NState& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSeqSeq1NState_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

