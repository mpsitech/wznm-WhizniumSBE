/**
	* \file WznmQConAPar.cpp
	* Dbs and XML wrapper for table TblWznmQConAPar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQConAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQConAPar
 ******************************************************************************/

WznmQConAPar::WznmQConAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const string osrefKVal
			, const string titOsrefKVal
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, x1SrefKKey(x1SrefKKey)
			, titX1SrefKKey(titX1SrefKKey)
			, x2RefWznmMLocale(x2RefWznmMLocale)
			, stubX2RefWznmMLocale(stubX2RefWznmMLocale)
			, osrefKVal(osrefKVal)
			, titOsrefKVal(titOsrefKVal)
		{
};

void WznmQConAPar::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["key"] = x1SrefKKey;
		me["key2"] = titX1SrefKKey;
		me["loc"] = stubX2RefWznmMLocale;
		me["val"] = osrefKVal;
		me["val2"] = titOsrefKVal;
	} else {
		me["x1SrefKKey"] = x1SrefKKey;
		me["titX1SrefKKey"] = titX1SrefKKey;
		me["stubX2RefWznmMLocale"] = stubX2RefWznmMLocale;
		me["osrefKVal"] = osrefKVal;
		me["titOsrefKVal"] = titOsrefKVal;
	};
};

void WznmQConAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQConAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "key", x1SrefKKey);
		writeString(wr, "key2", titX1SrefKKey);
		writeString(wr, "loc", stubX2RefWznmMLocale);
		writeString(wr, "val", osrefKVal);
		writeString(wr, "val2", titOsrefKVal);
	} else {
		writeString(wr, "x1SrefKKey", x1SrefKKey);
		writeString(wr, "titX1SrefKKey", titX1SrefKKey);
		writeString(wr, "stubX2RefWznmMLocale", stubX2RefWznmMLocale);
		writeString(wr, "osrefKVal", osrefKVal);
		writeString(wr, "titOsrefKVal", titOsrefKVal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQConAPar
 ******************************************************************************/

ListWznmQConAPar::ListWznmQConAPar() {
};

ListWznmQConAPar::ListWznmQConAPar(
			const ListWznmQConAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConAPar(*(src.nodes[i]));
};

ListWznmQConAPar::~ListWznmQConAPar() {
	clear();
};

void ListWznmQConAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQConAPar::size() const {
	return(nodes.size());
};

void ListWznmQConAPar::append(
			WznmQConAPar* rec
		) {
	nodes.push_back(rec);
};

ListWznmQConAPar& ListWznmQConAPar::operator=(
			const ListWznmQConAPar& src
		) {
	WznmQConAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQConAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQConAPar::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQConAPar";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQConAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQConAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQConAPar
 ******************************************************************************/

TblWznmQConAPar::TblWznmQConAPar() {
};

TblWznmQConAPar::~TblWznmQConAPar() {
};

bool TblWznmQConAPar::loadRecBySQL(
			const string& sqlstr
			, WznmQConAPar** rec
		) {
	return false;
};

ubigint TblWznmQConAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQConAPar& rst
		) {
	return 0;
};

ubigint TblWznmQConAPar::insertRec(
			WznmQConAPar* rec
		) {
	return 0;
};

ubigint TblWznmQConAPar::insertNewRec(
			WznmQConAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	ubigint retval = 0;
	WznmQConAPar* _rec = NULL;

	_rec = new WznmQConAPar(0, jref, jnum, ref, x1SrefKKey, titX1SrefKKey, x2RefWznmMLocale, stubX2RefWznmMLocale, osrefKVal, titOsrefKVal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQConAPar::appendNewRecToRst(
			ListWznmQConAPar& rst
			, WznmQConAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	ubigint retval = 0;
	WznmQConAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKKey, titX1SrefKKey, x2RefWznmMLocale, stubX2RefWznmMLocale, osrefKVal, titOsrefKVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQConAPar::insertRst(
			ListWznmQConAPar& rst
		) {
};

void TblWznmQConAPar::updateRec(
			WznmQConAPar* rec
		) {
};

void TblWznmQConAPar::updateRst(
			ListWznmQConAPar& rst
		) {
};

void TblWznmQConAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQConAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQConAPar::loadRecByQref(
			ubigint qref
			, WznmQConAPar** rec
		) {
	return false;
};

ubigint TblWznmQConAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQConAPar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQConAPar
 ******************************************************************************/

MyTblWznmQConAPar::MyTblWznmQConAPar() :
			TblWznmQConAPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQConAPar::~MyTblWznmQConAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQConAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQConAPar (jref, jnum, ref, x1SrefKKey, x2RefWznmMLocale, osrefKVal) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQConAPar SET jref = ?, jnum = ?, ref = ?, x1SrefKKey = ?, x2RefWznmMLocale = ?, osrefKVal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQConAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQConAPar WHERE jref = ?", false);
};

bool MyTblWznmQConAPar::loadRecBySQL(
			const string& sqlstr
			, WznmQConAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQConAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQConAPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQConAPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQConAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKKey.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKKey = "";
		if (dbrow[5]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[6]) _rec->osrefKVal.assign(dbrow[6], dblengths[6]); else _rec->osrefKVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQConAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQConAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQConAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQConAPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQConAPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQConAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKKey.assign(dbrow[4], dblengths[4]); else rec->x1SrefKKey = "";
			if (dbrow[5]) rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[6]) rec->osrefKVal.assign(dbrow[6], dblengths[6]); else rec->osrefKVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQConAPar::insertRec(
			WznmQConAPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKKey.length();
	l[5] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQConAPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQConAPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQConAPar::insertRst(
			ListWznmQConAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQConAPar::updateRec(
			WznmQConAPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->x1SrefKKey.length();
	l[5] = rec->osrefKVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKVal.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQConAPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQConAPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQConAPar::updateRst(
			ListWznmQConAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQConAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQConAPar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQConAPar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQConAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQConAPar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQConAPar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQConAPar::loadRecByQref(
			ubigint qref
			, WznmQConAPar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQConAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQConAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQConAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQConAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQConAPar
 ******************************************************************************/

PgTblWznmQConAPar::PgTblWznmQConAPar() :
			TblWznmQConAPar()
			, PgTable()
		{
};

PgTblWznmQConAPar::~PgTblWznmQConAPar() {
};

void PgTblWznmQConAPar::initStatements() {
	createStatement("TblWznmQConAPar_insertRec", "INSERT INTO TblWznmQConAPar (jref, jnum, ref, x1SrefKKey, x2RefWznmMLocale, osrefKVal) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQConAPar_updateRec", "UPDATE TblWznmQConAPar SET jref = $1, jnum = $2, ref = $3, x1SrefKKey = $4, x2RefWznmMLocale = $5, osrefKVal = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQConAPar_removeRecByQref", "DELETE FROM TblWznmQConAPar WHERE qref = $1", 1);
	createStatement("TblWznmQConAPar_removeRstByJref", "DELETE FROM TblWznmQConAPar WHERE jref = $1", 1);

	createStatement("TblWznmQConAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1SrefKKey, x2RefWznmMLocale, osrefKVal FROM TblWznmQConAPar WHERE qref = $1", 1);
	createStatement("TblWznmQConAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1SrefKKey, x2RefWznmMLocale, osrefKVal FROM TblWznmQConAPar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQConAPar::loadRec(
			PGresult* res
			, WznmQConAPar** rec
		) {
	char* ptr;

	WznmQConAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQConAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "osrefkval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->osrefKVal.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQConAPar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQConAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQConAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "osrefkval")
		};

		while (numread < numrow) {
			rec = new WznmQConAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->osrefKVal.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQConAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQConAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQConAPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQConAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQConAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQConAPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQConAPar::loadRecBySQL(
			const string& sqlstr
			, WznmQConAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQConAPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQConAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQConAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQConAPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQConAPar::insertRec(
			WznmQConAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1SrefKKey.c_str(),
		(char*) &_x2RefWznmMLocale,
		rec->osrefKVal.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQConAPar_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQConAPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQConAPar::insertRst(
			ListWznmQConAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQConAPar::updateRec(
			WznmQConAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x1SrefKKey.c_str(),
		(char*) &_x2RefWznmMLocale,
		rec->osrefKVal.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQConAPar_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQConAPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQConAPar::updateRst(
			ListWznmQConAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQConAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQConAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQConAPar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQConAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQConAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQConAPar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQConAPar::loadRecByQref(
			ubigint qref
			, WznmQConAPar** rec
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

	return loadRecByStmt("TblWznmQConAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQConAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQConAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQConAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
