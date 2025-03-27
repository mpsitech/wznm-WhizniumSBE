/**
	* \file WznmQUsrMNUsergroup.cpp
	* Dbs and XML wrapper for table TblWznmQUsrMNUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsrMNUsergroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsrMNUsergroup
 ******************************************************************************/

WznmQUsrMNUsergroup::WznmQUsrMNUsergroup(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWznmVUserlevel
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, mref(mref)
			, stubMref(stubMref)
			, ref(ref)
			, ixWznmVUserlevel(ixWznmVUserlevel)
			, srefIxWznmVUserlevel(srefIxWznmVUserlevel)
			, titIxWznmVUserlevel(titIxWznmVUserlevel)
		{
};

void WznmQUsrMNUsergroup::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["ulv"] = srefIxWznmVUserlevel;
		me["ulv2"] = titIxWznmVUserlevel;
	} else {
		me["stubMref"] = stubMref;
		me["srefIxWznmVUserlevel"] = srefIxWznmVUserlevel;
		me["titIxWznmVUserlevel"] = titIxWznmVUserlevel;
	};
};

void WznmQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQUsrMNUsergroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxWznmVUserlevel);
		writeString(wr, "ulv2", titIxWznmVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxWznmVUserlevel", srefIxWznmVUserlevel);
		writeString(wr, "titIxWznmVUserlevel", titIxWznmVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQUsrMNUsergroup
 ******************************************************************************/

ListWznmQUsrMNUsergroup::ListWznmQUsrMNUsergroup() {
};

ListWznmQUsrMNUsergroup::ListWznmQUsrMNUsergroup(
			const ListWznmQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrMNUsergroup(*(src.nodes[i]));
};

ListWznmQUsrMNUsergroup::~ListWznmQUsrMNUsergroup() {
	clear();
};

void ListWznmQUsrMNUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQUsrMNUsergroup::size() const {
	return(nodes.size());
};

void ListWznmQUsrMNUsergroup::append(
			WznmQUsrMNUsergroup* rec
		) {
	nodes.push_back(rec);
};

ListWznmQUsrMNUsergroup& ListWznmQUsrMNUsergroup::operator=(
			const ListWznmQUsrMNUsergroup& src
		) {
	WznmQUsrMNUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQUsrMNUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQUsrMNUsergroup::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQUsrMNUsergroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQUsrMNUsergroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQUsrMNUsergroup
 ******************************************************************************/

TblWznmQUsrMNUsergroup::TblWznmQUsrMNUsergroup() {
};

TblWznmQUsrMNUsergroup::~TblWznmQUsrMNUsergroup() {
};

bool TblWznmQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblWznmQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	return 0;
};

ubigint TblWznmQUsrMNUsergroup::insertRec(
			WznmQUsrMNUsergroup* rec
		) {
	return 0;
};

ubigint TblWznmQUsrMNUsergroup::insertNewRec(
			WznmQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWznmVUserlevel
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	ubigint retval = 0;
	WznmQUsrMNUsergroup* _rec = NULL;

	_rec = new WznmQUsrMNUsergroup(0, jref, jnum, mref, stubMref, ref, ixWznmVUserlevel, srefIxWznmVUserlevel, titIxWznmVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQUsrMNUsergroup::appendNewRecToRst(
			ListWznmQUsrMNUsergroup& rst
			, WznmQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWznmVUserlevel
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	ubigint retval = 0;
	WznmQUsrMNUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixWznmVUserlevel, srefIxWznmVUserlevel, titIxWznmVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQUsrMNUsergroup::insertRst(
			ListWznmQUsrMNUsergroup& rst
		) {
};

void TblWznmQUsrMNUsergroup::updateRec(
			WznmQUsrMNUsergroup* rec
		) {
};

void TblWznmQUsrMNUsergroup::updateRst(
			ListWznmQUsrMNUsergroup& rst
		) {
};

void TblWznmQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WznmQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblWznmQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQUsrMNUsergroup
 ******************************************************************************/

MyTblWznmQUsrMNUsergroup::MyTblWznmQUsrMNUsergroup() :
			TblWznmQUsrMNUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQUsrMNUsergroup::~MyTblWznmQUsrMNUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQUsrMNUsergroup (jref, jnum, mref, ref, ixWznmVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQUsrMNUsergroup SET jref = ?, jnum = ?, mref = ?, ref = ?, ixWznmVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQUsrMNUsergroup WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQUsrMNUsergroup WHERE jref = ?", false);
};

bool MyTblWznmQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrMNUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQUsrMNUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQUsrMNUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQUsrMNUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQUsrMNUsergroup();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixWznmVUserlevel = atol((char*) dbrow[5]); else _rec->ixWznmVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQUsrMNUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQUsrMNUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQUsrMNUsergroup();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixWznmVUserlevel = atol((char*) dbrow[5]); else rec->ixWznmVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQUsrMNUsergroup::insertRec(
			WznmQUsrMNUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQUsrMNUsergroup::insertRst(
			ListWznmQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQUsrMNUsergroup::updateRec(
			WznmQUsrMNUsergroup* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWznmVUserlevel,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQUsrMNUsergroup::updateRst(
			ListWznmQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQUsrMNUsergroup::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WznmQUsrMNUsergroup** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQUsrMNUsergroup WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQUsrMNUsergroup WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQUsrMNUsergroup
 ******************************************************************************/

PgTblWznmQUsrMNUsergroup::PgTblWznmQUsrMNUsergroup() :
			TblWznmQUsrMNUsergroup()
			, PgTable()
		{
};

PgTblWznmQUsrMNUsergroup::~PgTblWznmQUsrMNUsergroup() {
};

void PgTblWznmQUsrMNUsergroup::initStatements() {
	createStatement("TblWznmQUsrMNUsergroup_insertRec", "INSERT INTO TblWznmQUsrMNUsergroup (jref, jnum, mref, ref, ixWznmVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWznmQUsrMNUsergroup_updateRec", "UPDATE TblWznmQUsrMNUsergroup SET jref = $1, jnum = $2, mref = $3, ref = $4, ixWznmVUserlevel = $5 WHERE qref = $6", 6);
	createStatement("TblWznmQUsrMNUsergroup_removeRecByQref", "DELETE FROM TblWznmQUsrMNUsergroup WHERE qref = $1", 1);
	createStatement("TblWznmQUsrMNUsergroup_removeRstByJref", "DELETE FROM TblWznmQUsrMNUsergroup WHERE jref = $1", 1);

	createStatement("TblWznmQUsrMNUsergroup_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixWznmVUserlevel FROM TblWznmQUsrMNUsergroup WHERE qref = $1", 1);
	createStatement("TblWznmQUsrMNUsergroup_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixWznmVUserlevel FROM TblWznmQUsrMNUsergroup WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQUsrMNUsergroup::loadRec(
			PGresult* res
			, WznmQUsrMNUsergroup** rec
		) {
	char* ptr;

	WznmQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQUsrMNUsergroup();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwznmvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWznmVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQUsrMNUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQUsrMNUsergroup* rec;

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
			PQfnumber(res, "ixwznmvuserlevel")
		};

		while (numread < numrow) {
			rec = new WznmQUsrMNUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWznmVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQUsrMNUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrMNUsergroup::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQUsrMNUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrMNUsergroup::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQUsrMNUsergroup::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQUsrMNUsergroup::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQUsrMNUsergroup::insertRec(
			WznmQUsrMNUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixWznmVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQUsrMNUsergroup_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrMNUsergroup::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQUsrMNUsergroup::insertRst(
			ListWznmQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQUsrMNUsergroup::updateRec(
			WznmQUsrMNUsergroup* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixWznmVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQUsrMNUsergroup_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrMNUsergroup::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQUsrMNUsergroup::updateRst(
			ListWznmQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQUsrMNUsergroup::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQUsrMNUsergroup_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrMNUsergroup::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQUsrMNUsergroup::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQUsrMNUsergroup_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrMNUsergroup::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WznmQUsrMNUsergroup** rec
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

	return loadRecByStmt("TblWznmQUsrMNUsergroup_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrMNUsergroup& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQUsrMNUsergroup_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
