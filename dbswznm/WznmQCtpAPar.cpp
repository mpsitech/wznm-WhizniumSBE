/**
	* \file WznmQCtpAPar.cpp
	* Dbs and XML wrapper for table TblWznmQCtpAPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQCtpAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpAPar
 ******************************************************************************/

WznmQCtpAPar::WznmQCtpAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cpbNum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->cpbNum = cpbNum;
	this->x1SrefKKey = x1SrefKKey;
	this->titX1SrefKKey = titX1SrefKKey;
	this->Val = Val;
};

void WznmQCtpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQCtpAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "key", x1SrefKKey);
		writeString(wr, "key2", titX1SrefKKey);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x1SrefKKey", x1SrefKKey);
		writeString(wr, "titX1SrefKKey", titX1SrefKKey);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQCtpAPar
 ******************************************************************************/

ListWznmQCtpAPar::ListWznmQCtpAPar() {
};

ListWznmQCtpAPar::ListWznmQCtpAPar(
			const ListWznmQCtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpAPar(*(src.nodes[i]));
};

ListWznmQCtpAPar::~ListWznmQCtpAPar() {
	clear();
};

void ListWznmQCtpAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQCtpAPar::size() const {
	return(nodes.size());
};

void ListWznmQCtpAPar::append(
			WznmQCtpAPar* rec
		) {
	nodes.push_back(rec);
};

ListWznmQCtpAPar& ListWznmQCtpAPar::operator=(
			const ListWznmQCtpAPar& src
		) {
	WznmQCtpAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQCtpAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQCtpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQCtpAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQCtpAPar
 ******************************************************************************/

TblWznmQCtpAPar::TblWznmQCtpAPar() {
};

TblWznmQCtpAPar::~TblWznmQCtpAPar() {
};

bool TblWznmQCtpAPar::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpAPar** rec
		) {
	return false;
};

ubigint TblWznmQCtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	return 0;
};

ubigint TblWznmQCtpAPar::insertRec(
			WznmQCtpAPar* rec
		) {
	return 0;
};

ubigint TblWznmQCtpAPar::insertNewRec(
			WznmQCtpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cpbNum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WznmQCtpAPar* _rec = NULL;

	_rec = new WznmQCtpAPar(0, jref, jnum, ref, cpbNum, x1SrefKKey, titX1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQCtpAPar::appendNewRecToRst(
			ListWznmQCtpAPar& rst
			, WznmQCtpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cpbNum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WznmQCtpAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, cpbNum, x1SrefKKey, titX1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQCtpAPar::insertRst(
			ListWznmQCtpAPar& rst
		) {
};

void TblWznmQCtpAPar::updateRec(
			WznmQCtpAPar* rec
		) {
};

void TblWznmQCtpAPar::updateRst(
			ListWznmQCtpAPar& rst
		) {
};

void TblWznmQCtpAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQCtpAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQCtpAPar::loadRecByQref(
			ubigint qref
			, WznmQCtpAPar** rec
		) {
	return false;
};

ubigint TblWznmQCtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQCtpAPar
 ******************************************************************************/

MyTblWznmQCtpAPar::MyTblWznmQCtpAPar() :
			TblWznmQCtpAPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQCtpAPar::~MyTblWznmQCtpAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQCtpAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQCtpAPar (jref, jnum, ref, cpbNum, x1SrefKKey, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQCtpAPar SET jref = ?, jnum = ?, ref = ?, cpbNum = ?, x1SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQCtpAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQCtpAPar WHERE jref = ?", false);
};

bool MyTblWznmQCtpAPar::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQCtpAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCtpAPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCtpAPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQCtpAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->cpbNum = atol((char*) dbrow[4]); else _rec->cpbNum = 0;
		if (dbrow[5]) _rec->x1SrefKKey.assign(dbrow[5], dblengths[5]); else _rec->x1SrefKKey = "";
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQCtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQCtpAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCtpAPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCtpAPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQCtpAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->cpbNum = atol((char*) dbrow[4]); else rec->cpbNum = 0;
			if (dbrow[5]) rec->x1SrefKKey.assign(dbrow[5], dblengths[5]); else rec->x1SrefKKey = "";
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQCtpAPar::insertRec(
			WznmQCtpAPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x1SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cpbNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQCtpAPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQCtpAPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQCtpAPar::insertRst(
			ListWznmQCtpAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQCtpAPar::updateRec(
			WznmQCtpAPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x1SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cpbNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQCtpAPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQCtpAPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCtpAPar::updateRst(
			ListWznmQCtpAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQCtpAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQCtpAPar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQCtpAPar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCtpAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQCtpAPar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQCtpAPar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQCtpAPar::loadRecByQref(
			ubigint qref
			, WznmQCtpAPar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQCtpAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQCtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQCtpAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQCtpAPar
 ******************************************************************************/

PgTblWznmQCtpAPar::PgTblWznmQCtpAPar() :
			TblWznmQCtpAPar()
			, PgTable()
		{
};

PgTblWznmQCtpAPar::~PgTblWznmQCtpAPar() {
};

void PgTblWznmQCtpAPar::initStatements() {
	createStatement("TblWznmQCtpAPar_insertRec", "INSERT INTO TblWznmQCtpAPar (jref, jnum, ref, cpbNum, x1SrefKKey, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQCtpAPar_updateRec", "UPDATE TblWznmQCtpAPar SET jref = $1, jnum = $2, ref = $3, cpbNum = $4, x1SrefKKey = $5, Val = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQCtpAPar_removeRecByQref", "DELETE FROM TblWznmQCtpAPar WHERE qref = $1", 1);
	createStatement("TblWznmQCtpAPar_removeRstByJref", "DELETE FROM TblWznmQCtpAPar WHERE jref = $1", 1);

	createStatement("TblWznmQCtpAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, cpbNum, x1SrefKKey, Val FROM TblWznmQCtpAPar WHERE qref = $1", 1);
	createStatement("TblWznmQCtpAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, cpbNum, x1SrefKKey, Val FROM TblWznmQCtpAPar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQCtpAPar::loadRec(
			PGresult* res
			, WznmQCtpAPar** rec
		) {
	char* ptr;

	WznmQCtpAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQCtpAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cpbnum"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->cpbNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQCtpAPar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQCtpAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cpbnum"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmQCtpAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->cpbNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQCtpAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQCtpAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpAPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCtpAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpAPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQCtpAPar::loadRecBySQL(
			const string& sqlstr
			, WznmQCtpAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCtpAPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCtpAPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQCtpAPar::insertRec(
			WznmQCtpAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cpbNum = htonl(rec->cpbNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cpbNum,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQCtpAPar_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCtpAPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQCtpAPar::insertRst(
			ListWznmQCtpAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQCtpAPar::updateRec(
			WznmQCtpAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cpbNum = htonl(rec->cpbNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cpbNum,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQCtpAPar_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpAPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCtpAPar::updateRst(
			ListWznmQCtpAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQCtpAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQCtpAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpAPar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCtpAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQCtpAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCtpAPar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQCtpAPar::loadRecByQref(
			ubigint qref
			, WznmQCtpAPar** rec
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

	return loadRecByStmt("TblWznmQCtpAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQCtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCtpAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQCtpAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

