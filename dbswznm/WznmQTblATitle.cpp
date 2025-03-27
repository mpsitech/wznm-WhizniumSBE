/**
	* \file WznmQTblATitle.cpp
	* Dbs and XML wrapper for table TblWznmQTblATitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblATitle
 ******************************************************************************/

WznmQTblATitle::WznmQTblATitle(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, x1IxVType(x1IxVType)
			, srefX1IxVType(srefX1IxVType)
			, titX1IxVType(titX1IxVType)
			, x2RefWznmMLocale(x2RefWznmMLocale)
			, stubX2RefWznmMLocale(stubX2RefWznmMLocale)
			, ixWznmVGender(ixWznmVGender)
			, srefIxWznmVGender(srefIxWznmVGender)
			, titIxWznmVGender(titIxWznmVGender)
			, Title(Title)
		{
};

void WznmQTblATitle::writeJSON(
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
		me["gnd"] = srefIxWznmVGender;
		me["gnd2"] = titIxWznmVGender;
		me["tit"] = Title;
	} else {
		me["srefX1IxVType"] = srefX1IxVType;
		me["titX1IxVType"] = titX1IxVType;
		me["stubX2RefWznmMLocale"] = stubX2RefWznmMLocale;
		me["srefIxWznmVGender"] = srefIxWznmVGender;
		me["titIxWznmVGender"] = titIxWznmVGender;
		me["Title"] = Title;
	};
};

void WznmQTblATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTblATitle";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", srefX1IxVType);
		writeString(wr, "typ2", titX1IxVType);
		writeString(wr, "loc", stubX2RefWznmMLocale);
		writeString(wr, "gnd", srefIxWznmVGender);
		writeString(wr, "gnd2", titIxWznmVGender);
		writeString(wr, "tit", Title);
	} else {
		writeString(wr, "srefX1IxVType", srefX1IxVType);
		writeString(wr, "titX1IxVType", titX1IxVType);
		writeString(wr, "stubX2RefWznmMLocale", stubX2RefWznmMLocale);
		writeString(wr, "srefIxWznmVGender", srefIxWznmVGender);
		writeString(wr, "titIxWznmVGender", titIxWznmVGender);
		writeString(wr, "Title", Title);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQTblATitle
 ******************************************************************************/

ListWznmQTblATitle::ListWznmQTblATitle() {
};

ListWznmQTblATitle::ListWznmQTblATitle(
			const ListWznmQTblATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblATitle(*(src.nodes[i]));
};

ListWznmQTblATitle::~ListWznmQTblATitle() {
	clear();
};

void ListWznmQTblATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTblATitle::size() const {
	return(nodes.size());
};

void ListWznmQTblATitle::append(
			WznmQTblATitle* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTblATitle& ListWznmQTblATitle::operator=(
			const ListWznmQTblATitle& src
		) {
	WznmQTblATitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTblATitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTblATitle::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQTblATitle";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQTblATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTblATitle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTblATitle
 ******************************************************************************/

TblWznmQTblATitle::TblWznmQTblATitle() {
};

TblWznmQTblATitle::~TblWznmQTblATitle() {
};

bool TblWznmQTblATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQTblATitle** rec
		) {
	return false;
};

ubigint TblWznmQTblATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	return 0;
};

ubigint TblWznmQTblATitle::insertRec(
			WznmQTblATitle* rec
		) {
	return 0;
};

ubigint TblWznmQTblATitle::insertNewRec(
			WznmQTblATitle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmQTblATitle* _rec = NULL;

	_rec = new WznmQTblATitle(0, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, ixWznmVGender, srefIxWznmVGender, titIxWznmVGender, Title);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTblATitle::appendNewRecToRst(
			ListWznmQTblATitle& rst
			, WznmQTblATitle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmQTblATitle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, ixWznmVGender, srefIxWznmVGender, titIxWznmVGender, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTblATitle::insertRst(
			ListWznmQTblATitle& rst
		) {
};

void TblWznmQTblATitle::updateRec(
			WznmQTblATitle* rec
		) {
};

void TblWznmQTblATitle::updateRst(
			ListWznmQTblATitle& rst
		) {
};

void TblWznmQTblATitle::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTblATitle::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTblATitle::loadRecByQref(
			ubigint qref
			, WznmQTblATitle** rec
		) {
	return false;
};

ubigint TblWznmQTblATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTblATitle
 ******************************************************************************/

MyTblWznmQTblATitle::MyTblWznmQTblATitle() :
			TblWznmQTblATitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTblATitle::~MyTblWznmQTblATitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTblATitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTblATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTblATitle SET jref = ?, jnum = ?, ref = ?, x1IxVType = ?, x2RefWznmMLocale = ?, ixWznmVGender = ?, Title = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTblATitle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTblATitle WHERE jref = ?", false);
};

bool MyTblWznmQTblATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQTblATitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTblATitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblATitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblATitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQTblATitle();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxVType = atol((char*) dbrow[4]); else _rec->x1IxVType = 0;
		if (dbrow[5]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[6]) _rec->ixWznmVGender = atol((char*) dbrow[6]); else _rec->ixWznmVGender = 0;
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQTblATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTblATitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblATitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblATitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQTblATitle();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxVType = atol((char*) dbrow[4]); else rec->x1IxVType = 0;
			if (dbrow[5]) rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[6]) rec->ixWznmVGender = atol((char*) dbrow[6]); else rec->ixWznmVGender = 0;
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQTblATitle::insertRec(
			WznmQTblATitle* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVGender,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTblATitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTblATitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTblATitle::insertRst(
			ListWznmQTblATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTblATitle::updateRec(
			WznmQTblATitle* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVGender,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTblATitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTblATitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblATitle::updateRst(
			ListWznmQTblATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTblATitle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTblATitle::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTblATitle::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblATitle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTblATitle::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTblATitle::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTblATitle::loadRecByQref(
			ubigint qref
			, WznmQTblATitle** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTblATitle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTblATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTblATitle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTblATitle
 ******************************************************************************/

PgTblWznmQTblATitle::PgTblWznmQTblATitle() :
			TblWznmQTblATitle()
			, PgTable()
		{
};

PgTblWznmQTblATitle::~PgTblWznmQTblATitle() {
};

void PgTblWznmQTblATitle::initStatements() {
	createStatement("TblWznmQTblATitle_insertRec", "INSERT INTO TblWznmQTblATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQTblATitle_updateRec", "UPDATE TblWznmQTblATitle SET jref = $1, jnum = $2, ref = $3, x1IxVType = $4, x2RefWznmMLocale = $5, ixWznmVGender = $6, Title = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQTblATitle_removeRecByQref", "DELETE FROM TblWznmQTblATitle WHERE qref = $1", 1);
	createStatement("TblWznmQTblATitle_removeRstByJref", "DELETE FROM TblWznmQTblATitle WHERE jref = $1", 1);

	createStatement("TblWznmQTblATitle_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmQTblATitle WHERE qref = $1", 1);
	createStatement("TblWznmQTblATitle_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmQTblATitle WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTblATitle::loadRec(
			PGresult* res
			, WznmQTblATitle** rec
		) {
	char* ptr;

	WznmQTblATitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTblATitle();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmVGender = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQTblATitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTblATitle* rec;

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
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmQTblATitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVGender = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQTblATitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTblATitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblATitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblATitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblATitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTblATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQTblATitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblATitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblATitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTblATitle::insertRec(
			WznmQTblATitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		(char*) &_ixWznmVGender,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQTblATitle_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblATitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTblATitle::insertRst(
			ListWznmQTblATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTblATitle::updateRec(
			WznmQTblATitle* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		(char*) &_ixWznmVGender,
		rec->Title.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQTblATitle_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblATitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblATitle::updateRst(
			ListWznmQTblATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTblATitle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblATitle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblATitle::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblATitle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblATitle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblATitle::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTblATitle::loadRecByQref(
			ubigint qref
			, WznmQTblATitle** rec
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

	return loadRecByStmt("TblWznmQTblATitle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTblATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblATitle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTblATitle_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
