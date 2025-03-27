/**
	* \file WznmQQryMNTable.cpp
	* Dbs and XML wrapper for table TblWznmQQryMNTable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryMNTable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryMNTable
 ******************************************************************************/

WznmQQryMNTable::WznmQQryMNTable(
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
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, mref(mref)
			, stubMref(stubMref)
			, stubsTrefWznmMQuerymod(stubsTrefWznmMQuerymod)
			, ref(ref)
			, Source(Source)
			, yesnoSource(yesnoSource)
			, Prefix(Prefix)
		{
};

void WznmQQryMNTable::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["tqmd"] = stubsTrefWznmMQuerymod;
		me["src"] = yesnoSource;
		me["pfx"] = Prefix;
	} else {
		me["stubMref"] = stubMref;
		me["stubsTrefWznmMQuerymod"] = stubsTrefWznmMQuerymod;
		me["yesnoSource"] = yesnoSource;
		me["Prefix"] = Prefix;
	};
};

void WznmQQryMNTable::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQryMNTable";

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
 class ListWznmQQryMNTable
 ******************************************************************************/

ListWznmQQryMNTable::ListWznmQQryMNTable() {
};

ListWznmQQryMNTable::ListWznmQQryMNTable(
			const ListWznmQQryMNTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryMNTable(*(src.nodes[i]));
};

ListWznmQQryMNTable::~ListWznmQQryMNTable() {
	clear();
};

void ListWznmQQryMNTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQryMNTable::size() const {
	return(nodes.size());
};

void ListWznmQQryMNTable::append(
			WznmQQryMNTable* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQryMNTable& ListWznmQQryMNTable::operator=(
			const ListWznmQQryMNTable& src
		) {
	WznmQQryMNTable* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQryMNTable(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQryMNTable::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQQryMNTable";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQQryMNTable::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQryMNTable";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQryMNTable
 ******************************************************************************/

TblWznmQQryMNTable::TblWznmQQryMNTable() {
};

TblWznmQQryMNTable::~TblWznmQQryMNTable() {
};

bool TblWznmQQryMNTable::loadRecBySQL(
			const string& sqlstr
			, WznmQQryMNTable** rec
		) {
	return false;
};

ubigint TblWznmQQryMNTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	return 0;
};

ubigint TblWznmQQryMNTable::insertRec(
			WznmQQryMNTable* rec
		) {
	return 0;
};

ubigint TblWznmQQryMNTable::insertNewRec(
			WznmQQryMNTable** rec
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
	WznmQQryMNTable* _rec = NULL;

	_rec = new WznmQQryMNTable(0, jref, jnum, mref, stubMref, stubsTrefWznmMQuerymod, ref, Source, yesnoSource, Prefix);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQryMNTable::appendNewRecToRst(
			ListWznmQQryMNTable& rst
			, WznmQQryMNTable** rec
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
	WznmQQryMNTable* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, stubsTrefWznmMQuerymod, ref, Source, yesnoSource, Prefix);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQryMNTable::insertRst(
			ListWznmQQryMNTable& rst
		) {
};

void TblWznmQQryMNTable::updateRec(
			WznmQQryMNTable* rec
		) {
};

void TblWznmQQryMNTable::updateRst(
			ListWznmQQryMNTable& rst
		) {
};

void TblWznmQQryMNTable::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQryMNTable::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQryMNTable::loadRecByQref(
			ubigint qref
			, WznmQQryMNTable** rec
		) {
	return false;
};

ubigint TblWznmQQryMNTable::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQryMNTable
 ******************************************************************************/

MyTblWznmQQryMNTable::MyTblWznmQQryMNTable() :
			TblWznmQQryMNTable()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQryMNTable::~MyTblWznmQQryMNTable() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQryMNTable::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQryMNTable (jref, jnum, mref, ref, Source, Prefix) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQryMNTable SET jref = ?, jnum = ?, mref = ?, ref = ?, Source = ?, Prefix = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQryMNTable WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQryMNTable WHERE jref = ?", false);
};

bool MyTblWznmQQryMNTable::loadRecBySQL(
			const string& sqlstr
			, WznmQQryMNTable** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQryMNTable* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryMNTable::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryMNTable::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQQryMNTable();

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

ubigint MyTblWznmQQryMNTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQryMNTable* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryMNTable::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryMNTable::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQQryMNTable();

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

ubigint MyTblWznmQQryMNTable::insertRec(
			WznmQQryMNTable* rec
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
		string dbms = "MyTblWznmQQryMNTable::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQryMNTable::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQryMNTable::insertRst(
			ListWznmQQryMNTable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQryMNTable::updateRec(
			WznmQQryMNTable* rec
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
		string dbms = "MyTblWznmQQryMNTable::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQryMNTable::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryMNTable::updateRst(
			ListWznmQQryMNTable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQryMNTable::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQryMNTable::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQryMNTable::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryMNTable::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQryMNTable::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQryMNTable::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQryMNTable::loadRecByQref(
			ubigint qref
			, WznmQQryMNTable** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQryMNTable WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQryMNTable::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQryMNTable WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQryMNTable
 ******************************************************************************/

PgTblWznmQQryMNTable::PgTblWznmQQryMNTable() :
			TblWznmQQryMNTable()
			, PgTable()
		{
};

PgTblWznmQQryMNTable::~PgTblWznmQQryMNTable() {
};

void PgTblWznmQQryMNTable::initStatements() {
	createStatement("TblWznmQQryMNTable_insertRec", "INSERT INTO TblWznmQQryMNTable (jref, jnum, mref, ref, Source, Prefix) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQQryMNTable_updateRec", "UPDATE TblWznmQQryMNTable SET jref = $1, jnum = $2, mref = $3, ref = $4, Source = $5, Prefix = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQQryMNTable_removeRecByQref", "DELETE FROM TblWznmQQryMNTable WHERE qref = $1", 1);
	createStatement("TblWznmQQryMNTable_removeRstByJref", "DELETE FROM TblWznmQQryMNTable WHERE jref = $1", 1);

	createStatement("TblWznmQQryMNTable_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, Source, Prefix FROM TblWznmQQryMNTable WHERE qref = $1", 1);
	createStatement("TblWznmQQryMNTable_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, Source, Prefix FROM TblWznmQQryMNTable WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQryMNTable::loadRec(
			PGresult* res
			, WznmQQryMNTable** rec
		) {
	char* ptr;

	WznmQQryMNTable* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQryMNTable();

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

ubigint PgTblWznmQQryMNTable::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQryMNTable* rec;

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
			rec = new WznmQQryMNTable();

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

bool PgTblWznmQQryMNTable::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQryMNTable** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryMNTable::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryMNTable::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryMNTable::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQryMNTable::loadRecBySQL(
			const string& sqlstr
			, WznmQQryMNTable** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryMNTable::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryMNTable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryMNTable::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQryMNTable::insertRec(
			WznmQQryMNTable* rec
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

	res = PQexecPrepared(dbs, "TblWznmQQryMNTable_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryMNTable::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQryMNTable::insertRst(
			ListWznmQQryMNTable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQryMNTable::updateRec(
			WznmQQryMNTable* rec
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

	res = PQexecPrepared(dbs, "TblWznmQQryMNTable_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryMNTable::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryMNTable::updateRst(
			ListWznmQQryMNTable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQryMNTable::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryMNTable_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryMNTable::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryMNTable::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryMNTable_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryMNTable::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQryMNTable::loadRecByQref(
			ubigint qref
			, WznmQQryMNTable** rec
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

	return loadRecByStmt("TblWznmQQryMNTable_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQryMNTable::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryMNTable& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQryMNTable_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
