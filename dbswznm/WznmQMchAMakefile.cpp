/**
	* \file WznmQMchAMakefile.cpp
	* Dbs and XML wrapper for table TblWznmQMchAMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMchAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMchAMakefile
 ******************************************************************************/

WznmQMchAMakefile::WznmQMchAMakefile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKTag
			, const string titX1SrefKTag
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1SrefKTag = x1SrefKTag;
	this->titX1SrefKTag = titX1SrefKTag;
	this->Val = Val;
};

void WznmQMchAMakefile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQMchAMakefile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tag", x1SrefKTag);
		writeString(wr, "tag2", titX1SrefKTag);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x1SrefKTag", x1SrefKTag);
		writeString(wr, "titX1SrefKTag", titX1SrefKTag);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQMchAMakefile
 ******************************************************************************/

ListWznmQMchAMakefile::ListWznmQMchAMakefile() {
};

ListWznmQMchAMakefile::ListWznmQMchAMakefile(
			const ListWznmQMchAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchAMakefile(*(src.nodes[i]));
};

ListWznmQMchAMakefile::~ListWznmQMchAMakefile() {
	clear();
};

void ListWznmQMchAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQMchAMakefile::size() const {
	return(nodes.size());
};

void ListWznmQMchAMakefile::append(
			WznmQMchAMakefile* rec
		) {
	nodes.push_back(rec);
};

ListWznmQMchAMakefile& ListWznmQMchAMakefile::operator=(
			const ListWznmQMchAMakefile& src
		) {
	WznmQMchAMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQMchAMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQMchAMakefile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQMchAMakefile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQMchAMakefile
 ******************************************************************************/

TblWznmQMchAMakefile::TblWznmQMchAMakefile() {
};

TblWznmQMchAMakefile::~TblWznmQMchAMakefile() {
};

bool TblWznmQMchAMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmQMchAMakefile** rec
		) {
	return false;
};

ubigint TblWznmQMchAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	return 0;
};

ubigint TblWznmQMchAMakefile::insertRec(
			WznmQMchAMakefile* rec
		) {
	return 0;
};

ubigint TblWznmQMchAMakefile::insertNewRec(
			WznmQMchAMakefile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKTag
			, const string titX1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmQMchAMakefile* _rec = NULL;

	_rec = new WznmQMchAMakefile(0, jref, jnum, ref, x1SrefKTag, titX1SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQMchAMakefile::appendNewRecToRst(
			ListWznmQMchAMakefile& rst
			, WznmQMchAMakefile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKTag
			, const string titX1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmQMchAMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKTag, titX1SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQMchAMakefile::insertRst(
			ListWznmQMchAMakefile& rst
		) {
};

void TblWznmQMchAMakefile::updateRec(
			WznmQMchAMakefile* rec
		) {
};

void TblWznmQMchAMakefile::updateRst(
			ListWznmQMchAMakefile& rst
		) {
};

void TblWznmQMchAMakefile::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQMchAMakefile::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQMchAMakefile::loadRecByQref(
			ubigint qref
			, WznmQMchAMakefile** rec
		) {
	return false;
};

ubigint TblWznmQMchAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQMchAMakefile
 ******************************************************************************/

MyTblWznmQMchAMakefile::MyTblWznmQMchAMakefile() :
			TblWznmQMchAMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQMchAMakefile::~MyTblWznmQMchAMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQMchAMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQMchAMakefile (jref, jnum, ref, x1SrefKTag, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQMchAMakefile SET jref = ?, jnum = ?, ref = ?, x1SrefKTag = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQMchAMakefile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQMchAMakefile WHERE jref = ?", false);
};

bool MyTblWznmQMchAMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmQMchAMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQMchAMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMchAMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMchAMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQMchAMakefile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKTag.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKTag = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQMchAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQMchAMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMchAMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMchAMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQMchAMakefile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKTag.assign(dbrow[4], dblengths[4]); else rec->x1SrefKTag = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQMchAMakefile::insertRec(
			WznmQMchAMakefile* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x1SrefKTag.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQMchAMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQMchAMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQMchAMakefile::insertRst(
			ListWznmQMchAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQMchAMakefile::updateRec(
			WznmQMchAMakefile* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKTag.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQMchAMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQMchAMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMchAMakefile::updateRst(
			ListWznmQMchAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQMchAMakefile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQMchAMakefile::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQMchAMakefile::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMchAMakefile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQMchAMakefile::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQMchAMakefile::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQMchAMakefile::loadRecByQref(
			ubigint qref
			, WznmQMchAMakefile** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQMchAMakefile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQMchAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQMchAMakefile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQMchAMakefile
 ******************************************************************************/

PgTblWznmQMchAMakefile::PgTblWznmQMchAMakefile() :
			TblWznmQMchAMakefile()
			, PgTable()
		{
};

PgTblWznmQMchAMakefile::~PgTblWznmQMchAMakefile() {
};

void PgTblWznmQMchAMakefile::initStatements() {
	createStatement("TblWznmQMchAMakefile_insertRec", "INSERT INTO TblWznmQMchAMakefile (jref, jnum, ref, x1SrefKTag, Val) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWznmQMchAMakefile_updateRec", "UPDATE TblWznmQMchAMakefile SET jref = $1, jnum = $2, ref = $3, x1SrefKTag = $4, Val = $5 WHERE qref = $6", 6);
	createStatement("TblWznmQMchAMakefile_removeRecByQref", "DELETE FROM TblWznmQMchAMakefile WHERE qref = $1", 1);
	createStatement("TblWznmQMchAMakefile_removeRstByJref", "DELETE FROM TblWznmQMchAMakefile WHERE jref = $1", 1);

	createStatement("TblWznmQMchAMakefile_loadRecByQref", "SELECT qref, jref, jnum, ref, x1SrefKTag, Val FROM TblWznmQMchAMakefile WHERE qref = $1", 1);
	createStatement("TblWznmQMchAMakefile_loadRstByJref", "SELECT qref, jref, jnum, ref, x1SrefKTag, Val FROM TblWznmQMchAMakefile WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQMchAMakefile::loadRec(
			PGresult* res
			, WznmQMchAMakefile** rec
		) {
	char* ptr;

	WznmQMchAMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQMchAMakefile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQMchAMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQMchAMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmQMchAMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQMchAMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQMchAMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMchAMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMchAMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMchAMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQMchAMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmQMchAMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMchAMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMchAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMchAMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQMchAMakefile::insertRec(
			WznmQMchAMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQMchAMakefile_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMchAMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQMchAMakefile::insertRst(
			ListWznmQMchAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQMchAMakefile::updateRec(
			WznmQMchAMakefile* rec
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
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQMchAMakefile_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMchAMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMchAMakefile::updateRst(
			ListWznmQMchAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQMchAMakefile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQMchAMakefile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMchAMakefile::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMchAMakefile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQMchAMakefile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMchAMakefile::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQMchAMakefile::loadRecByQref(
			ubigint qref
			, WznmQMchAMakefile** rec
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

	return loadRecByStmt("TblWznmQMchAMakefile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQMchAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMchAMakefile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQMchAMakefile_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

