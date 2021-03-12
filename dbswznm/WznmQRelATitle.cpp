/**
	* \file WznmQRelATitle.cpp
	* Dbs and XML wrapper for table TblWznmQRelATitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRelATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRelATitle
 ******************************************************************************/

WznmQRelATitle::WznmQRelATitle(
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

void WznmQRelATitle::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["typ"] = srefX1IxVType;
		me["typ2"] = titX1IxVType;
		me["loc"] = stubX2RefWznmMLocale;
		me["tit"] = Title;
	} else {
		me["srefX1IxVType"] = srefX1IxVType;
		me["titX1IxVType"] = titX1IxVType;
		me["stubX2RefWznmMLocale"] = stubX2RefWznmMLocale;
		me["Title"] = Title;
	};
};

void WznmQRelATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQRelATitle";

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
 class ListWznmQRelATitle
 ******************************************************************************/

ListWznmQRelATitle::ListWznmQRelATitle() {
};

ListWznmQRelATitle::ListWznmQRelATitle(
			const ListWznmQRelATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelATitle(*(src.nodes[i]));
};

ListWznmQRelATitle::~ListWznmQRelATitle() {
	clear();
};

void ListWznmQRelATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQRelATitle::size() const {
	return(nodes.size());
};

void ListWznmQRelATitle::append(
			WznmQRelATitle* rec
		) {
	nodes.push_back(rec);
};

ListWznmQRelATitle& ListWznmQRelATitle::operator=(
			const ListWznmQRelATitle& src
		) {
	WznmQRelATitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQRelATitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQRelATitle::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQRelATitle";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQRelATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQRelATitle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQRelATitle
 ******************************************************************************/

TblWznmQRelATitle::TblWznmQRelATitle() {
};

TblWznmQRelATitle::~TblWznmQRelATitle() {
};

bool TblWznmQRelATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQRelATitle** rec
		) {
	return false;
};

ubigint TblWznmQRelATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	return 0;
};

ubigint TblWznmQRelATitle::insertRec(
			WznmQRelATitle* rec
		) {
	return 0;
};

ubigint TblWznmQRelATitle::insertNewRec(
			WznmQRelATitle** rec
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
	WznmQRelATitle* _rec = NULL;

	_rec = new WznmQRelATitle(0, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQRelATitle::appendNewRecToRst(
			ListWznmQRelATitle& rst
			, WznmQRelATitle** rec
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
	WznmQRelATitle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQRelATitle::insertRst(
			ListWznmQRelATitle& rst
		) {
};

void TblWznmQRelATitle::updateRec(
			WznmQRelATitle* rec
		) {
};

void TblWznmQRelATitle::updateRst(
			ListWznmQRelATitle& rst
		) {
};

void TblWznmQRelATitle::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQRelATitle::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQRelATitle::loadRecByQref(
			ubigint qref
			, WznmQRelATitle** rec
		) {
	return false;
};

ubigint TblWznmQRelATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQRelATitle
 ******************************************************************************/

MyTblWznmQRelATitle::MyTblWznmQRelATitle() :
			TblWznmQRelATitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQRelATitle::~MyTblWznmQRelATitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQRelATitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQRelATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQRelATitle SET jref = ?, jnum = ?, ref = ?, x1IxVType = ?, x2RefWznmMLocale = ?, Title = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQRelATitle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQRelATitle WHERE jref = ?", false);
};

bool MyTblWznmQRelATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQRelATitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQRelATitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRelATitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRelATitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQRelATitle();

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

ubigint MyTblWznmQRelATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQRelATitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRelATitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRelATitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQRelATitle();

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

ubigint MyTblWznmQRelATitle::insertRec(
			WznmQRelATitle* rec
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
		string dbms = "MyTblWznmQRelATitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQRelATitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQRelATitle::insertRst(
			ListWznmQRelATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQRelATitle::updateRec(
			WznmQRelATitle* rec
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
		string dbms = "MyTblWznmQRelATitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQRelATitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRelATitle::updateRst(
			ListWznmQRelATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQRelATitle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQRelATitle::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQRelATitle::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRelATitle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQRelATitle::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQRelATitle::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQRelATitle::loadRecByQref(
			ubigint qref
			, WznmQRelATitle** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQRelATitle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQRelATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQRelATitle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQRelATitle
 ******************************************************************************/

PgTblWznmQRelATitle::PgTblWznmQRelATitle() :
			TblWznmQRelATitle()
			, PgTable()
		{
};

PgTblWznmQRelATitle::~PgTblWznmQRelATitle() {
};

void PgTblWznmQRelATitle::initStatements() {
	createStatement("TblWznmQRelATitle_insertRec", "INSERT INTO TblWznmQRelATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQRelATitle_updateRec", "UPDATE TblWznmQRelATitle SET jref = $1, jnum = $2, ref = $3, x1IxVType = $4, x2RefWznmMLocale = $5, Title = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQRelATitle_removeRecByQref", "DELETE FROM TblWznmQRelATitle WHERE qref = $1", 1);
	createStatement("TblWznmQRelATitle_removeRstByJref", "DELETE FROM TblWznmQRelATitle WHERE jref = $1", 1);

	createStatement("TblWznmQRelATitle_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmQRelATitle WHERE qref = $1", 1);
	createStatement("TblWznmQRelATitle_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmQRelATitle WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQRelATitle::loadRec(
			PGresult* res
			, WznmQRelATitle** rec
		) {
	char* ptr;

	WznmQRelATitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQRelATitle();

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

ubigint PgTblWznmQRelATitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQRelATitle* rec;

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
			rec = new WznmQRelATitle();

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

bool PgTblWznmQRelATitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQRelATitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRelATitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRelATitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRelATitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQRelATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQRelATitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRelATitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRelATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRelATitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQRelATitle::insertRec(
			WznmQRelATitle* rec
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

	res = PQexecPrepared(dbs, "TblWznmQRelATitle_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRelATitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQRelATitle::insertRst(
			ListWznmQRelATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQRelATitle::updateRec(
			WznmQRelATitle* rec
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

	res = PQexecPrepared(dbs, "TblWznmQRelATitle_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRelATitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRelATitle::updateRst(
			ListWznmQRelATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQRelATitle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQRelATitle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRelATitle::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRelATitle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQRelATitle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRelATitle::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQRelATitle::loadRecByQref(
			ubigint qref
			, WznmQRelATitle** rec
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

	return loadRecByStmt("TblWznmQRelATitle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQRelATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRelATitle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQRelATitle_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
