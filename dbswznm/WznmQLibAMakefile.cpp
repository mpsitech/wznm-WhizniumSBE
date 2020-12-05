/**
	* \file WznmQLibAMakefile.cpp
	* Dbs and XML wrapper for table TblWznmQLibAMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQLibAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQLibAMakefile
 ******************************************************************************/

WznmQLibAMakefile::WznmQLibAMakefile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefWznmMMachine
			, const string stubX1RefWznmMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefWznmMMachine = x1RefWznmMMachine;
	this->stubX1RefWznmMMachine = stubX1RefWznmMMachine;
	this->x2SrefKTag = x2SrefKTag;
	this->titX2SrefKTag = titX2SrefKTag;
	this->Val = Val;
};

void WznmQLibAMakefile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQLibAMakefile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mch", stubX1RefWznmMMachine);
		writeString(wr, "tag", x2SrefKTag);
		writeString(wr, "tag2", titX2SrefKTag);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "stubX1RefWznmMMachine", stubX1RefWznmMMachine);
		writeString(wr, "x2SrefKTag", x2SrefKTag);
		writeString(wr, "titX2SrefKTag", titX2SrefKTag);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQLibAMakefile
 ******************************************************************************/

ListWznmQLibAMakefile::ListWznmQLibAMakefile() {
};

ListWznmQLibAMakefile::ListWznmQLibAMakefile(
			const ListWznmQLibAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAMakefile(*(src.nodes[i]));
};

ListWznmQLibAMakefile::~ListWznmQLibAMakefile() {
	clear();
};

void ListWznmQLibAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQLibAMakefile::size() const {
	return(nodes.size());
};

void ListWznmQLibAMakefile::append(
			WznmQLibAMakefile* rec
		) {
	nodes.push_back(rec);
};

ListWznmQLibAMakefile& ListWznmQLibAMakefile::operator=(
			const ListWznmQLibAMakefile& src
		) {
	WznmQLibAMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQLibAMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQLibAMakefile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQLibAMakefile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQLibAMakefile
 ******************************************************************************/

TblWznmQLibAMakefile::TblWznmQLibAMakefile() {
};

TblWznmQLibAMakefile::~TblWznmQLibAMakefile() {
};

bool TblWznmQLibAMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmQLibAMakefile** rec
		) {
	return false;
};

ubigint TblWznmQLibAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	return 0;
};

ubigint TblWznmQLibAMakefile::insertRec(
			WznmQLibAMakefile* rec
		) {
	return 0;
};

ubigint TblWznmQLibAMakefile::insertNewRec(
			WznmQLibAMakefile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefWznmMMachine
			, const string stubX1RefWznmMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmQLibAMakefile* _rec = NULL;

	_rec = new WznmQLibAMakefile(0, jref, jnum, ref, x1RefWznmMMachine, stubX1RefWznmMMachine, x2SrefKTag, titX2SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQLibAMakefile::appendNewRecToRst(
			ListWznmQLibAMakefile& rst
			, WznmQLibAMakefile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefWznmMMachine
			, const string stubX1RefWznmMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WznmQLibAMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefWznmMMachine, stubX1RefWznmMMachine, x2SrefKTag, titX2SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQLibAMakefile::insertRst(
			ListWznmQLibAMakefile& rst
		) {
};

void TblWznmQLibAMakefile::updateRec(
			WznmQLibAMakefile* rec
		) {
};

void TblWznmQLibAMakefile::updateRst(
			ListWznmQLibAMakefile& rst
		) {
};

void TblWznmQLibAMakefile::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQLibAMakefile::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQLibAMakefile::loadRecByQref(
			ubigint qref
			, WznmQLibAMakefile** rec
		) {
	return false;
};

ubigint TblWznmQLibAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQLibAMakefile
 ******************************************************************************/

MyTblWznmQLibAMakefile::MyTblWznmQLibAMakefile() :
			TblWznmQLibAMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQLibAMakefile::~MyTblWznmQLibAMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQLibAMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQLibAMakefile (jref, jnum, ref, x1RefWznmMMachine, x2SrefKTag, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQLibAMakefile SET jref = ?, jnum = ?, ref = ?, x1RefWznmMMachine = ?, x2SrefKTag = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQLibAMakefile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQLibAMakefile WHERE jref = ?", false);
};

bool MyTblWznmQLibAMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmQLibAMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQLibAMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQLibAMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQLibAMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQLibAMakefile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefWznmMMachine = atoll((char*) dbrow[4]); else _rec->x1RefWznmMMachine = 0;
		if (dbrow[5]) _rec->x2SrefKTag.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKTag = "";
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQLibAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQLibAMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQLibAMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQLibAMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQLibAMakefile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefWznmMMachine = atoll((char*) dbrow[4]); else rec->x1RefWznmMMachine = 0;
			if (dbrow[5]) rec->x2SrefKTag.assign(dbrow[5], dblengths[5]); else rec->x2SrefKTag = "";
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQLibAMakefile::insertRec(
			WznmQLibAMakefile* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2SrefKTag.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefWznmMMachine,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQLibAMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQLibAMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQLibAMakefile::insertRst(
			ListWznmQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQLibAMakefile::updateRec(
			WznmQLibAMakefile* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2SrefKTag.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefWznmMMachine,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQLibAMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQLibAMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQLibAMakefile::updateRst(
			ListWznmQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQLibAMakefile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQLibAMakefile::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQLibAMakefile::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQLibAMakefile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQLibAMakefile::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQLibAMakefile::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQLibAMakefile::loadRecByQref(
			ubigint qref
			, WznmQLibAMakefile** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQLibAMakefile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQLibAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQLibAMakefile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQLibAMakefile
 ******************************************************************************/

PgTblWznmQLibAMakefile::PgTblWznmQLibAMakefile() :
			TblWznmQLibAMakefile()
			, PgTable()
		{
};

PgTblWznmQLibAMakefile::~PgTblWznmQLibAMakefile() {
};

void PgTblWznmQLibAMakefile::initStatements() {
	createStatement("TblWznmQLibAMakefile_insertRec", "INSERT INTO TblWznmQLibAMakefile (jref, jnum, ref, x1RefWznmMMachine, x2SrefKTag, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQLibAMakefile_updateRec", "UPDATE TblWznmQLibAMakefile SET jref = $1, jnum = $2, ref = $3, x1RefWznmMMachine = $4, x2SrefKTag = $5, Val = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQLibAMakefile_removeRecByQref", "DELETE FROM TblWznmQLibAMakefile WHERE qref = $1", 1);
	createStatement("TblWznmQLibAMakefile_removeRstByJref", "DELETE FROM TblWznmQLibAMakefile WHERE jref = $1", 1);

	createStatement("TblWznmQLibAMakefile_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefWznmMMachine, x2SrefKTag, Val FROM TblWznmQLibAMakefile WHERE qref = $1", 1);
	createStatement("TblWznmQLibAMakefile_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefWznmMMachine, x2SrefKTag, Val FROM TblWznmQLibAMakefile WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQLibAMakefile::loadRec(
			PGresult* res
			, WznmQLibAMakefile** rec
		) {
	char* ptr;

	WznmQLibAMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQLibAMakefile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refwznmmmachine"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQLibAMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQLibAMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refwznmmmachine"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmQLibAMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQLibAMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQLibAMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQLibAMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQLibAMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQLibAMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQLibAMakefile::loadRecBySQL(
			const string& sqlstr
			, WznmQLibAMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQLibAMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQLibAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQLibAMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQLibAMakefile::insertRec(
			WznmQLibAMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefWznmMMachine = htonl64(rec->x1RefWznmMMachine);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefWznmMMachine,
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQLibAMakefile_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQLibAMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQLibAMakefile::insertRst(
			ListWznmQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQLibAMakefile::updateRec(
			WznmQLibAMakefile* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefWznmMMachine = htonl64(rec->x1RefWznmMMachine);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefWznmMMachine,
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQLibAMakefile_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQLibAMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQLibAMakefile::updateRst(
			ListWznmQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQLibAMakefile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQLibAMakefile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQLibAMakefile::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQLibAMakefile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQLibAMakefile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQLibAMakefile::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQLibAMakefile::loadRecByQref(
			ubigint qref
			, WznmQLibAMakefile** rec
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

	return loadRecByStmt("TblWznmQLibAMakefile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQLibAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQLibAMakefile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQLibAMakefile_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

