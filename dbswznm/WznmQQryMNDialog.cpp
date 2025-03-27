/**
	* \file WznmQQryMNDialog.cpp
	* Dbs and XML wrapper for table TblWznmQQryMNDialog (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryMNDialog.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryMNDialog
 ******************************************************************************/

WznmQQryMNDialog::WznmQQryMNDialog(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, mref(mref)
			, stubMref(stubMref)
			, ref(ref)
		{
};

void WznmQQryMNDialog::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
	} else {
		me["stubMref"] = stubMref;
	};
};

void WznmQQryMNDialog::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQryMNDialog";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
	} else {
		writeString(wr, "stubMref", stubMref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQQryMNDialog
 ******************************************************************************/

ListWznmQQryMNDialog::ListWznmQQryMNDialog() {
};

ListWznmQQryMNDialog::ListWznmQQryMNDialog(
			const ListWznmQQryMNDialog& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryMNDialog(*(src.nodes[i]));
};

ListWznmQQryMNDialog::~ListWznmQQryMNDialog() {
	clear();
};

void ListWznmQQryMNDialog::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQryMNDialog::size() const {
	return(nodes.size());
};

void ListWznmQQryMNDialog::append(
			WznmQQryMNDialog* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQryMNDialog& ListWznmQQryMNDialog::operator=(
			const ListWznmQQryMNDialog& src
		) {
	WznmQQryMNDialog* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQryMNDialog(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQryMNDialog::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQQryMNDialog";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQQryMNDialog::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQryMNDialog";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQryMNDialog
 ******************************************************************************/

TblWznmQQryMNDialog::TblWznmQQryMNDialog() {
};

TblWznmQQryMNDialog::~TblWznmQQryMNDialog() {
};

bool TblWznmQQryMNDialog::loadRecBySQL(
			const string& sqlstr
			, WznmQQryMNDialog** rec
		) {
	return false;
};

ubigint TblWznmQQryMNDialog::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	return 0;
};

ubigint TblWznmQQryMNDialog::insertRec(
			WznmQQryMNDialog* rec
		) {
	return 0;
};

ubigint TblWznmQQryMNDialog::insertNewRec(
			WznmQQryMNDialog** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	WznmQQryMNDialog* _rec = NULL;

	_rec = new WznmQQryMNDialog(0, jref, jnum, mref, stubMref, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQryMNDialog::appendNewRecToRst(
			ListWznmQQryMNDialog& rst
			, WznmQQryMNDialog** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	WznmQQryMNDialog* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQryMNDialog::insertRst(
			ListWznmQQryMNDialog& rst
		) {
};

void TblWznmQQryMNDialog::updateRec(
			WznmQQryMNDialog* rec
		) {
};

void TblWznmQQryMNDialog::updateRst(
			ListWznmQQryMNDialog& rst
		) {
};

void TblWznmQQryMNDialog::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQryMNDialog::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQryMNDialog::loadRecByQref(
			ubigint qref
			, WznmQQryMNDialog** rec
		) {
	return false;
};

ubigint TblWznmQQryMNDialog::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQryMNDialog
 ******************************************************************************/

MyTblWznmQQryMNDialog::MyTblWznmQQryMNDialog() :
			TblWznmQQryMNDialog()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQryMNDialog::~MyTblWznmQQryMNDialog() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQryMNDialog::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQryMNDialog (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQryMNDialog SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQryMNDialog WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQryMNDialog WHERE jref = ?", false);
};

bool MyTblWznmQQryMNDialog::loadRecBySQL(
			const string& sqlstr
			, WznmQQryMNDialog** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQryMNDialog* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryMNDialog::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryMNDialog::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQQryMNDialog();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQryMNDialog::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQryMNDialog* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryMNDialog::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryMNDialog::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQQryMNDialog();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQryMNDialog::insertRec(
			WznmQQryMNDialog* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQryMNDialog::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQryMNDialog::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQryMNDialog::insertRst(
			ListWznmQQryMNDialog& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQryMNDialog::updateRec(
			WznmQQryMNDialog* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQryMNDialog::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQryMNDialog::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryMNDialog::updateRst(
			ListWznmQQryMNDialog& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQryMNDialog::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQryMNDialog::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQryMNDialog::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryMNDialog::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQryMNDialog::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQryMNDialog::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQryMNDialog::loadRecByQref(
			ubigint qref
			, WznmQQryMNDialog** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQryMNDialog WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQryMNDialog::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQryMNDialog WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQryMNDialog
 ******************************************************************************/

PgTblWznmQQryMNDialog::PgTblWznmQQryMNDialog() :
			TblWznmQQryMNDialog()
			, PgTable()
		{
};

PgTblWznmQQryMNDialog::~PgTblWznmQQryMNDialog() {
};

void PgTblWznmQQryMNDialog::initStatements() {
	createStatement("TblWznmQQryMNDialog_insertRec", "INSERT INTO TblWznmQQryMNDialog (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQQryMNDialog_updateRec", "UPDATE TblWznmQQryMNDialog SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQQryMNDialog_removeRecByQref", "DELETE FROM TblWznmQQryMNDialog WHERE qref = $1", 1);
	createStatement("TblWznmQQryMNDialog_removeRstByJref", "DELETE FROM TblWznmQQryMNDialog WHERE jref = $1", 1);

	createStatement("TblWznmQQryMNDialog_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblWznmQQryMNDialog WHERE qref = $1", 1);
	createStatement("TblWznmQQryMNDialog_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblWznmQQryMNDialog WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQryMNDialog::loadRec(
			PGresult* res
			, WznmQQryMNDialog** rec
		) {
	char* ptr;

	WznmQQryMNDialog* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQryMNDialog();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQryMNDialog::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQryMNDialog* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WznmQQryMNDialog();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQryMNDialog::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQryMNDialog** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryMNDialog::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryMNDialog::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryMNDialog::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQryMNDialog::loadRecBySQL(
			const string& sqlstr
			, WznmQQryMNDialog** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryMNDialog::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryMNDialog::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryMNDialog::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQryMNDialog::insertRec(
			WznmQQryMNDialog* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryMNDialog_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryMNDialog::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQryMNDialog::insertRst(
			ListWznmQQryMNDialog& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQryMNDialog::updateRec(
			WznmQQryMNDialog* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryMNDialog_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryMNDialog::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryMNDialog::updateRst(
			ListWznmQQryMNDialog& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQryMNDialog::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryMNDialog_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryMNDialog::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryMNDialog::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryMNDialog_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryMNDialog::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQryMNDialog::loadRecByQref(
			ubigint qref
			, WznmQQryMNDialog** rec
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

	return loadRecByStmt("TblWznmQQryMNDialog_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQryMNDialog::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryMNDialog& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQryMNDialog_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
