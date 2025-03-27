/**
	* \file WznmQPrjMNPerson.cpp
	* Dbs and XML wrapper for table TblWznmQPrjMNPerson (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPrjMNPerson.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrjMNPerson
 ******************************************************************************/

WznmQPrjMNPerson::WznmQPrjMNPerson(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, mref(mref)
			, stubMref(stubMref)
			, ref(ref)
			, x1Startd(x1Startd)
			, ftmX1Startd(ftmX1Startd)
			, x1Stopd(x1Stopd)
			, ftmX1Stopd(ftmX1Stopd)
			, srefKFunction(srefKFunction)
			, titSrefKFunction(titSrefKFunction)
		{
};

void WznmQPrjMNPerson::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["sta"] = ftmX1Startd;
		me["sto"] = ftmX1Stopd;
		me["fct"] = srefKFunction;
		me["fct2"] = titSrefKFunction;
	} else {
		me["stubMref"] = stubMref;
		me["ftmX1Startd"] = ftmX1Startd;
		me["ftmX1Stopd"] = ftmX1Stopd;
		me["srefKFunction"] = srefKFunction;
		me["titSrefKFunction"] = titSrefKFunction;
	};
};

void WznmQPrjMNPerson::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQPrjMNPerson";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1Startd);
		writeString(wr, "sto", ftmX1Stopd);
		writeString(wr, "fct", srefKFunction);
		writeString(wr, "fct2", titSrefKFunction);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1Startd", ftmX1Startd);
		writeString(wr, "ftmX1Stopd", ftmX1Stopd);
		writeString(wr, "srefKFunction", srefKFunction);
		writeString(wr, "titSrefKFunction", titSrefKFunction);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQPrjMNPerson
 ******************************************************************************/

ListWznmQPrjMNPerson::ListWznmQPrjMNPerson() {
};

ListWznmQPrjMNPerson::ListWznmQPrjMNPerson(
			const ListWznmQPrjMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjMNPerson(*(src.nodes[i]));
};

ListWznmQPrjMNPerson::~ListWznmQPrjMNPerson() {
	clear();
};

void ListWznmQPrjMNPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQPrjMNPerson::size() const {
	return(nodes.size());
};

void ListWznmQPrjMNPerson::append(
			WznmQPrjMNPerson* rec
		) {
	nodes.push_back(rec);
};

ListWznmQPrjMNPerson& ListWznmQPrjMNPerson::operator=(
			const ListWznmQPrjMNPerson& src
		) {
	WznmQPrjMNPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQPrjMNPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQPrjMNPerson::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQPrjMNPerson";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQPrjMNPerson::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQPrjMNPerson";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQPrjMNPerson
 ******************************************************************************/

TblWznmQPrjMNPerson::TblWznmQPrjMNPerson() {
};

TblWznmQPrjMNPerson::~TblWznmQPrjMNPerson() {
};

bool TblWznmQPrjMNPerson::loadRecBySQL(
			const string& sqlstr
			, WznmQPrjMNPerson** rec
		) {
	return false;
};

ubigint TblWznmQPrjMNPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	return 0;
};

ubigint TblWznmQPrjMNPerson::insertRec(
			WznmQPrjMNPerson* rec
		) {
	return 0;
};

ubigint TblWznmQPrjMNPerson::insertNewRec(
			WznmQPrjMNPerson** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	WznmQPrjMNPerson* _rec = NULL;

	_rec = new WznmQPrjMNPerson(0, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQPrjMNPerson::appendNewRecToRst(
			ListWznmQPrjMNPerson& rst
			, WznmQPrjMNPerson** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	WznmQPrjMNPerson* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQPrjMNPerson::insertRst(
			ListWznmQPrjMNPerson& rst
		) {
};

void TblWznmQPrjMNPerson::updateRec(
			WznmQPrjMNPerson* rec
		) {
};

void TblWznmQPrjMNPerson::updateRst(
			ListWznmQPrjMNPerson& rst
		) {
};

void TblWznmQPrjMNPerson::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQPrjMNPerson::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQPrjMNPerson::loadRecByQref(
			ubigint qref
			, WznmQPrjMNPerson** rec
		) {
	return false;
};

ubigint TblWznmQPrjMNPerson::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQPrjMNPerson
 ******************************************************************************/

MyTblWznmQPrjMNPerson::MyTblWznmQPrjMNPerson() :
			TblWznmQPrjMNPerson()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQPrjMNPerson::~MyTblWznmQPrjMNPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQPrjMNPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQPrjMNPerson (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQPrjMNPerson SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Startd = ?, x1Stopd = ?, srefKFunction = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQPrjMNPerson WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQPrjMNPerson WHERE jref = ?", false);
};

bool MyTblWznmQPrjMNPerson::loadRecBySQL(
			const string& sqlstr
			, WznmQPrjMNPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQPrjMNPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrjMNPerson::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrjMNPerson::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQPrjMNPerson();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Startd = atol((char*) dbrow[5]); else _rec->x1Startd = 0;
		if (dbrow[6]) _rec->x1Stopd = atol((char*) dbrow[6]); else _rec->x1Stopd = 0;
		if (dbrow[7]) _rec->srefKFunction.assign(dbrow[7], dblengths[7]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQPrjMNPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQPrjMNPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrjMNPerson::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrjMNPerson::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQPrjMNPerson();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Startd = atol((char*) dbrow[5]); else rec->x1Startd = 0;
			if (dbrow[6]) rec->x1Stopd = atol((char*) dbrow[6]); else rec->x1Stopd = 0;
			if (dbrow[7]) rec->srefKFunction.assign(dbrow[7], dblengths[7]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQPrjMNPerson::insertRec(
			WznmQPrjMNPerson* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Startd,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stopd,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQPrjMNPerson::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQPrjMNPerson::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQPrjMNPerson::insertRst(
			ListWznmQPrjMNPerson& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQPrjMNPerson::updateRec(
			WznmQPrjMNPerson* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Startd,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stopd,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQPrjMNPerson::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQPrjMNPerson::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrjMNPerson::updateRst(
			ListWznmQPrjMNPerson& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQPrjMNPerson::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQPrjMNPerson::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQPrjMNPerson::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrjMNPerson::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQPrjMNPerson::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQPrjMNPerson::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQPrjMNPerson::loadRecByQref(
			ubigint qref
			, WznmQPrjMNPerson** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQPrjMNPerson WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQPrjMNPerson::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQPrjMNPerson WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQPrjMNPerson
 ******************************************************************************/

PgTblWznmQPrjMNPerson::PgTblWznmQPrjMNPerson() :
			TblWznmQPrjMNPerson()
			, PgTable()
		{
};

PgTblWznmQPrjMNPerson::~PgTblWznmQPrjMNPerson() {
};

void PgTblWznmQPrjMNPerson::initStatements() {
	createStatement("TblWznmQPrjMNPerson_insertRec", "INSERT INTO TblWznmQPrjMNPerson (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQPrjMNPerson_updateRec", "UPDATE TblWznmQPrjMNPerson SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Startd = $5, x1Stopd = $6, srefKFunction = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQPrjMNPerson_removeRecByQref", "DELETE FROM TblWznmQPrjMNPerson WHERE qref = $1", 1);
	createStatement("TblWznmQPrjMNPerson_removeRstByJref", "DELETE FROM TblWznmQPrjMNPerson WHERE jref = $1", 1);

	createStatement("TblWznmQPrjMNPerson_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblWznmQPrjMNPerson WHERE qref = $1", 1);
	createStatement("TblWznmQPrjMNPerson_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblWznmQPrjMNPerson WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQPrjMNPerson::loadRec(
			PGresult* res
			, WznmQPrjMNPerson** rec
		) {
	char* ptr;

	WznmQPrjMNPerson* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQPrjMNPerson();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQPrjMNPerson::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQPrjMNPerson* rec;

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
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WznmQPrjMNPerson();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQPrjMNPerson::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQPrjMNPerson** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrjMNPerson::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrjMNPerson::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrjMNPerson::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQPrjMNPerson::loadRecBySQL(
			const string& sqlstr
			, WznmQPrjMNPerson** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrjMNPerson::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrjMNPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrjMNPerson::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQPrjMNPerson::insertRec(
			WznmQPrjMNPerson* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQPrjMNPerson_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrjMNPerson::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQPrjMNPerson::insertRst(
			ListWznmQPrjMNPerson& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQPrjMNPerson::updateRec(
			WznmQPrjMNPerson* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		rec->srefKFunction.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQPrjMNPerson_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrjMNPerson::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrjMNPerson::updateRst(
			ListWznmQPrjMNPerson& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQPrjMNPerson::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrjMNPerson_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrjMNPerson::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrjMNPerson::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrjMNPerson_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrjMNPerson::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQPrjMNPerson::loadRecByQref(
			ubigint qref
			, WznmQPrjMNPerson** rec
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

	return loadRecByStmt("TblWznmQPrjMNPerson_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQPrjMNPerson::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrjMNPerson& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQPrjMNPerson_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
