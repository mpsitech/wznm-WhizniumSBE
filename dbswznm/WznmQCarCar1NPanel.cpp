/**
	* \file WznmQCarCar1NPanel.cpp
	* Dbs and XML wrapper for table TblWznmQCarCar1NPanel (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCarCar1NPanel.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCarCar1NPanel
 ******************************************************************************/

WznmQCarCar1NPanel::WznmQCarCar1NPanel(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint carNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->carNum = carNum;
};

void WznmQCarCar1NPanel::writeJSON(
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

void WznmQCarCar1NPanel::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQCarCar1NPanel";

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
 class ListWznmQCarCar1NPanel
 ******************************************************************************/

ListWznmQCarCar1NPanel::ListWznmQCarCar1NPanel() {
};

ListWznmQCarCar1NPanel::ListWznmQCarCar1NPanel(
			const ListWznmQCarCar1NPanel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCarCar1NPanel(*(src.nodes[i]));
};

ListWznmQCarCar1NPanel::~ListWznmQCarCar1NPanel() {
	clear();
};

void ListWznmQCarCar1NPanel::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQCarCar1NPanel::size() const {
	return(nodes.size());
};

void ListWznmQCarCar1NPanel::append(
			WznmQCarCar1NPanel* rec
		) {
	nodes.push_back(rec);
};

ListWznmQCarCar1NPanel& ListWznmQCarCar1NPanel::operator=(
			const ListWznmQCarCar1NPanel& src
		) {
	WznmQCarCar1NPanel* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQCarCar1NPanel(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQCarCar1NPanel::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQCarCar1NPanel";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQCarCar1NPanel::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQCarCar1NPanel";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQCarCar1NPanel
 ******************************************************************************/

TblWznmQCarCar1NPanel::TblWznmQCarCar1NPanel() {
};

TblWznmQCarCar1NPanel::~TblWznmQCarCar1NPanel() {
};

bool TblWznmQCarCar1NPanel::loadRecBySQL(
			const string& sqlstr
			, WznmQCarCar1NPanel** rec
		) {
	return false;
};

ubigint TblWznmQCarCar1NPanel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	return 0;
};

ubigint TblWznmQCarCar1NPanel::insertRec(
			WznmQCarCar1NPanel* rec
		) {
	return 0;
};

ubigint TblWznmQCarCar1NPanel::insertNewRec(
			WznmQCarCar1NPanel** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint carNum
		) {
	ubigint retval = 0;
	WznmQCarCar1NPanel* _rec = NULL;

	_rec = new WznmQCarCar1NPanel(0, jref, jnum, ref, stubRef, carNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQCarCar1NPanel::appendNewRecToRst(
			ListWznmQCarCar1NPanel& rst
			, WznmQCarCar1NPanel** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint carNum
		) {
	ubigint retval = 0;
	WznmQCarCar1NPanel* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, carNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQCarCar1NPanel::insertRst(
			ListWznmQCarCar1NPanel& rst
		) {
};

void TblWznmQCarCar1NPanel::updateRec(
			WznmQCarCar1NPanel* rec
		) {
};

void TblWznmQCarCar1NPanel::updateRst(
			ListWznmQCarCar1NPanel& rst
		) {
};

void TblWznmQCarCar1NPanel::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQCarCar1NPanel::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQCarCar1NPanel::loadRecByQref(
			ubigint qref
			, WznmQCarCar1NPanel** rec
		) {
	return false;
};

ubigint TblWznmQCarCar1NPanel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQCarCar1NPanel
 ******************************************************************************/

MyTblWznmQCarCar1NPanel::MyTblWznmQCarCar1NPanel() :
			TblWznmQCarCar1NPanel()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQCarCar1NPanel::~MyTblWznmQCarCar1NPanel() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQCarCar1NPanel::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQCarCar1NPanel (jref, jnum, ref, carNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQCarCar1NPanel SET jref = ?, jnum = ?, ref = ?, carNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQCarCar1NPanel WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQCarCar1NPanel WHERE jref = ?", false);
};

bool MyTblWznmQCarCar1NPanel::loadRecBySQL(
			const string& sqlstr
			, WznmQCarCar1NPanel** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQCarCar1NPanel* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCarCar1NPanel::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCarCar1NPanel::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQCarCar1NPanel();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->carNum = atol((char*) dbrow[4]); else _rec->carNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQCarCar1NPanel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQCarCar1NPanel* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCarCar1NPanel::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCarCar1NPanel::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQCarCar1NPanel();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->carNum = atol((char*) dbrow[4]); else rec->carNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQCarCar1NPanel::insertRec(
			WznmQCarCar1NPanel* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->carNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQCarCar1NPanel::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQCarCar1NPanel::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQCarCar1NPanel::insertRst(
			ListWznmQCarCar1NPanel& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQCarCar1NPanel::updateRec(
			WznmQCarCar1NPanel* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->carNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQCarCar1NPanel::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQCarCar1NPanel::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCarCar1NPanel::updateRst(
			ListWznmQCarCar1NPanel& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQCarCar1NPanel::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQCarCar1NPanel::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQCarCar1NPanel::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCarCar1NPanel::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQCarCar1NPanel::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQCarCar1NPanel::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQCarCar1NPanel::loadRecByQref(
			ubigint qref
			, WznmQCarCar1NPanel** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQCarCar1NPanel WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQCarCar1NPanel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQCarCar1NPanel WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQCarCar1NPanel
 ******************************************************************************/

PgTblWznmQCarCar1NPanel::PgTblWznmQCarCar1NPanel() :
			TblWznmQCarCar1NPanel()
			, PgTable()
		{
};

PgTblWznmQCarCar1NPanel::~PgTblWznmQCarCar1NPanel() {
};

void PgTblWznmQCarCar1NPanel::initStatements() {
	createStatement("TblWznmQCarCar1NPanel_insertRec", "INSERT INTO TblWznmQCarCar1NPanel (jref, jnum, ref, carNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQCarCar1NPanel_updateRec", "UPDATE TblWznmQCarCar1NPanel SET jref = $1, jnum = $2, ref = $3, carNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQCarCar1NPanel_removeRecByQref", "DELETE FROM TblWznmQCarCar1NPanel WHERE qref = $1", 1);
	createStatement("TblWznmQCarCar1NPanel_removeRstByJref", "DELETE FROM TblWznmQCarCar1NPanel WHERE jref = $1", 1);

	createStatement("TblWznmQCarCar1NPanel_loadRecByQref", "SELECT qref, jref, jnum, ref, carNum FROM TblWznmQCarCar1NPanel WHERE qref = $1", 1);
	createStatement("TblWznmQCarCar1NPanel_loadRstByJref", "SELECT qref, jref, jnum, ref, carNum FROM TblWznmQCarCar1NPanel WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQCarCar1NPanel::loadRec(
			PGresult* res
			, WznmQCarCar1NPanel** rec
		) {
	char* ptr;

	WznmQCarCar1NPanel* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQCarCar1NPanel();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "carnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->carNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQCarCar1NPanel::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQCarCar1NPanel* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "carnum")
		};

		while (numread < numrow) {
			rec = new WznmQCarCar1NPanel();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->carNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQCarCar1NPanel::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQCarCar1NPanel** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCarCar1NPanel::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCarCar1NPanel::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCarCar1NPanel::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQCarCar1NPanel::loadRecBySQL(
			const string& sqlstr
			, WznmQCarCar1NPanel** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCarCar1NPanel::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCarCar1NPanel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCarCar1NPanel::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQCarCar1NPanel::insertRec(
			WznmQCarCar1NPanel* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _carNum = htonl(rec->carNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_carNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQCarCar1NPanel_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCarCar1NPanel::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQCarCar1NPanel::insertRst(
			ListWznmQCarCar1NPanel& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQCarCar1NPanel::updateRec(
			WznmQCarCar1NPanel* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _carNum = htonl(rec->carNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_carNum,
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

	res = PQexecPrepared(dbs, "TblWznmQCarCar1NPanel_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCarCar1NPanel::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCarCar1NPanel::updateRst(
			ListWznmQCarCar1NPanel& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQCarCar1NPanel::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQCarCar1NPanel_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCarCar1NPanel::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCarCar1NPanel::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQCarCar1NPanel_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCarCar1NPanel::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQCarCar1NPanel::loadRecByQref(
			ubigint qref
			, WznmQCarCar1NPanel** rec
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

	return loadRecByStmt("TblWznmQCarCar1NPanel_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQCarCar1NPanel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCarCar1NPanel& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQCarCar1NPanel_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
