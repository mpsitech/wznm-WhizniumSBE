/**
	* \file WznmQTcoATitle.cpp
	* Dbs and XML wrapper for table TblWznmQTcoATitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTcoATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTcoATitle
 ******************************************************************************/

WznmQTcoATitle::WznmQTcoATitle(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const string Title
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxVType = x1IxVType;
	this->srefX1IxVType = srefX1IxVType;
	this->titX1IxVType = titX1IxVType;
	this->x2RefWznmMLocale = x2RefWznmMLocale;
	this->stubX2RefWznmMLocale = stubX2RefWznmMLocale;
	this->Title = Title;
};

void WznmQTcoATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTcoATitle";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", srefX1IxVType);
		writeString(wr, "typ2", titX1IxVType);
		writeString(wr, "loc", stubX2RefWznmMLocale);
		writeString(wr, "tit", Title);
	} else {
		writeString(wr, "srefX1IxVType", srefX1IxVType);
		writeString(wr, "titX1IxVType", titX1IxVType);
		writeString(wr, "stubX2RefWznmMLocale", stubX2RefWznmMLocale);
		writeString(wr, "Title", Title);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQTcoATitle
 ******************************************************************************/

ListWznmQTcoATitle::ListWznmQTcoATitle() {
};

ListWznmQTcoATitle::ListWznmQTcoATitle(
			const ListWznmQTcoATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoATitle(*(src.nodes[i]));
};

ListWznmQTcoATitle::~ListWznmQTcoATitle() {
	clear();
};

void ListWznmQTcoATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTcoATitle::size() const {
	return(nodes.size());
};

void ListWznmQTcoATitle::append(
			WznmQTcoATitle* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTcoATitle& ListWznmQTcoATitle::operator=(
			const ListWznmQTcoATitle& src
		) {
	WznmQTcoATitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTcoATitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTcoATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTcoATitle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTcoATitle
 ******************************************************************************/

TblWznmQTcoATitle::TblWznmQTcoATitle() {
};

TblWznmQTcoATitle::~TblWznmQTcoATitle() {
};

bool TblWznmQTcoATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQTcoATitle** rec
		) {
	return false;
};

ubigint TblWznmQTcoATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	return 0;
};

ubigint TblWznmQTcoATitle::insertRec(
			WznmQTcoATitle* rec
		) {
	return 0;
};

ubigint TblWznmQTcoATitle::insertNewRec(
			WznmQTcoATitle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmQTcoATitle* _rec = NULL;

	_rec = new WznmQTcoATitle(0, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTcoATitle::appendNewRecToRst(
			ListWznmQTcoATitle& rst
			, WznmQTcoATitle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmQTcoATitle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTcoATitle::insertRst(
			ListWznmQTcoATitle& rst
		) {
};

void TblWznmQTcoATitle::updateRec(
			WznmQTcoATitle* rec
		) {
};

void TblWznmQTcoATitle::updateRst(
			ListWznmQTcoATitle& rst
		) {
};

void TblWznmQTcoATitle::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTcoATitle::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTcoATitle::loadRecByQref(
			ubigint qref
			, WznmQTcoATitle** rec
		) {
	return false;
};

ubigint TblWznmQTcoATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTcoATitle
 ******************************************************************************/

MyTblWznmQTcoATitle::MyTblWznmQTcoATitle() :
			TblWznmQTcoATitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTcoATitle::~MyTblWznmQTcoATitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTcoATitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTcoATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTcoATitle SET jref = ?, jnum = ?, ref = ?, x1IxVType = ?, x2RefWznmMLocale = ?, Title = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTcoATitle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTcoATitle WHERE jref = ?", false);
};

bool MyTblWznmQTcoATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQTcoATitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTcoATitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTcoATitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTcoATitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQTcoATitle();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxVType = atol((char*) dbrow[4]); else _rec->x1IxVType = 0;
		if (dbrow[5]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQTcoATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTcoATitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTcoATitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTcoATitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQTcoATitle();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxVType = atol((char*) dbrow[4]); else rec->x1IxVType = 0;
			if (dbrow[5]) rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQTcoATitle::insertRec(
			WznmQTcoATitle* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTcoATitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTcoATitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTcoATitle::insertRst(
			ListWznmQTcoATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTcoATitle::updateRec(
			WznmQTcoATitle* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTcoATitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTcoATitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTcoATitle::updateRst(
			ListWznmQTcoATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTcoATitle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTcoATitle::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTcoATitle::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTcoATitle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTcoATitle::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTcoATitle::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTcoATitle::loadRecByQref(
			ubigint qref
			, WznmQTcoATitle** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTcoATitle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTcoATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTcoATitle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTcoATitle
 ******************************************************************************/

PgTblWznmQTcoATitle::PgTblWznmQTcoATitle() :
			TblWznmQTcoATitle()
			, PgTable()
		{
};

PgTblWznmQTcoATitle::~PgTblWznmQTcoATitle() {
};

void PgTblWznmQTcoATitle::initStatements() {
	createStatement("TblWznmQTcoATitle_insertRec", "INSERT INTO TblWznmQTcoATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQTcoATitle_updateRec", "UPDATE TblWznmQTcoATitle SET jref = $1, jnum = $2, ref = $3, x1IxVType = $4, x2RefWznmMLocale = $5, Title = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQTcoATitle_removeRecByQref", "DELETE FROM TblWznmQTcoATitle WHERE qref = $1", 1);
	createStatement("TblWznmQTcoATitle_removeRstByJref", "DELETE FROM TblWznmQTcoATitle WHERE jref = $1", 1);

	createStatement("TblWznmQTcoATitle_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmQTcoATitle WHERE qref = $1", 1);
	createStatement("TblWznmQTcoATitle_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmQTcoATitle WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTcoATitle::loadRec(
			PGresult* res
			, WznmQTcoATitle** rec
		) {
	char* ptr;

	WznmQTcoATitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTcoATitle();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQTcoATitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTcoATitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmQTcoATitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQTcoATitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTcoATitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTcoATitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTcoATitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTcoATitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTcoATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQTcoATitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTcoATitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTcoATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTcoATitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTcoATitle::insertRec(
			WznmQTcoATitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQTcoATitle_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTcoATitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTcoATitle::insertRst(
			ListWznmQTcoATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTcoATitle::updateRec(
			WznmQTcoATitle* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		rec->Title.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQTcoATitle_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTcoATitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTcoATitle::updateRst(
			ListWznmQTcoATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTcoATitle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTcoATitle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTcoATitle::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTcoATitle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTcoATitle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTcoATitle::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTcoATitle::loadRecByQref(
			ubigint qref
			, WznmQTcoATitle** rec
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

	return loadRecByStmt("TblWznmQTcoATitle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTcoATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTcoATitle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTcoATitle_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
