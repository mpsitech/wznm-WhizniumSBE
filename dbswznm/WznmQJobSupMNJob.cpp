/**
	* \file WznmQJobSupMNJob.cpp
	* Dbs and XML wrapper for table TblWznmQJobSupMNJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQJobSupMNJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobSupMNJob
 ******************************************************************************/

WznmQJobSupMNJob::WznmQJobSupMNJob(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string Short
			, const bool Multi
			, const string yesnoMulti
			, const uint ixVConstract
			, const string srefIxVConstract
			, const string titIxVConstract
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->Short = Short;
	this->Multi = Multi;
	this->yesnoMulti = yesnoMulti;
	this->ixVConstract = ixVConstract;
	this->srefIxVConstract = srefIxVConstract;
	this->titIxVConstract = titIxVConstract;
};

void WznmQJobSupMNJob::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["sho"] = Short;
		me["mlt"] = yesnoMulti;
		me["csa"] = srefIxVConstract;
		me["csa2"] = titIxVConstract;
	} else {
		me["stubMref"] = stubMref;
		me["Short"] = Short;
		me["yesnoMulti"] = yesnoMulti;
		me["srefIxVConstract"] = srefIxVConstract;
		me["titIxVConstract"] = titIxVConstract;
	};
};

void WznmQJobSupMNJob::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQJobSupMNJob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sho", Short);
		writeString(wr, "mlt", yesnoMulti);
		writeString(wr, "csa", srefIxVConstract);
		writeString(wr, "csa2", titIxVConstract);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "Short", Short);
		writeString(wr, "yesnoMulti", yesnoMulti);
		writeString(wr, "srefIxVConstract", srefIxVConstract);
		writeString(wr, "titIxVConstract", titIxVConstract);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQJobSupMNJob
 ******************************************************************************/

ListWznmQJobSupMNJob::ListWznmQJobSupMNJob() {
};

ListWznmQJobSupMNJob::ListWznmQJobSupMNJob(
			const ListWznmQJobSupMNJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobSupMNJob(*(src.nodes[i]));
};

ListWznmQJobSupMNJob::~ListWznmQJobSupMNJob() {
	clear();
};

void ListWznmQJobSupMNJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQJobSupMNJob::size() const {
	return(nodes.size());
};

void ListWznmQJobSupMNJob::append(
			WznmQJobSupMNJob* rec
		) {
	nodes.push_back(rec);
};

ListWznmQJobSupMNJob& ListWznmQJobSupMNJob::operator=(
			const ListWznmQJobSupMNJob& src
		) {
	WznmQJobSupMNJob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQJobSupMNJob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQJobSupMNJob::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQJobSupMNJob";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQJobSupMNJob::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQJobSupMNJob";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQJobSupMNJob
 ******************************************************************************/

TblWznmQJobSupMNJob::TblWznmQJobSupMNJob() {
};

TblWznmQJobSupMNJob::~TblWznmQJobSupMNJob() {
};

bool TblWznmQJobSupMNJob::loadRecBySQL(
			const string& sqlstr
			, WznmQJobSupMNJob** rec
		) {
	return false;
};

ubigint TblWznmQJobSupMNJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	return 0;
};

ubigint TblWznmQJobSupMNJob::insertRec(
			WznmQJobSupMNJob* rec
		) {
	return 0;
};

ubigint TblWznmQJobSupMNJob::insertNewRec(
			WznmQJobSupMNJob** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string Short
			, const bool Multi
			, const string yesnoMulti
			, const uint ixVConstract
			, const string srefIxVConstract
			, const string titIxVConstract
		) {
	ubigint retval = 0;
	WznmQJobSupMNJob* _rec = NULL;

	_rec = new WznmQJobSupMNJob(0, jref, jnum, mref, stubMref, ref, Short, Multi, yesnoMulti, ixVConstract, srefIxVConstract, titIxVConstract);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQJobSupMNJob::appendNewRecToRst(
			ListWznmQJobSupMNJob& rst
			, WznmQJobSupMNJob** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string Short
			, const bool Multi
			, const string yesnoMulti
			, const uint ixVConstract
			, const string srefIxVConstract
			, const string titIxVConstract
		) {
	ubigint retval = 0;
	WznmQJobSupMNJob* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, Short, Multi, yesnoMulti, ixVConstract, srefIxVConstract, titIxVConstract);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQJobSupMNJob::insertRst(
			ListWznmQJobSupMNJob& rst
		) {
};

void TblWznmQJobSupMNJob::updateRec(
			WznmQJobSupMNJob* rec
		) {
};

void TblWznmQJobSupMNJob::updateRst(
			ListWznmQJobSupMNJob& rst
		) {
};

void TblWznmQJobSupMNJob::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQJobSupMNJob::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQJobSupMNJob::loadRecByQref(
			ubigint qref
			, WznmQJobSupMNJob** rec
		) {
	return false;
};

ubigint TblWznmQJobSupMNJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQJobSupMNJob
 ******************************************************************************/

MyTblWznmQJobSupMNJob::MyTblWznmQJobSupMNJob() :
			TblWznmQJobSupMNJob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQJobSupMNJob::~MyTblWznmQJobSupMNJob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQJobSupMNJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQJobSupMNJob (jref, jnum, mref, ref, Short, Multi, ixVConstract) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQJobSupMNJob SET jref = ?, jnum = ?, mref = ?, ref = ?, Short = ?, Multi = ?, ixVConstract = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQJobSupMNJob WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQJobSupMNJob WHERE jref = ?", false);
};

bool MyTblWznmQJobSupMNJob::loadRecBySQL(
			const string& sqlstr
			, WznmQJobSupMNJob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQJobSupMNJob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQJobSupMNJob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQJobSupMNJob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQJobSupMNJob();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->Short.assign(dbrow[5], dblengths[5]); else _rec->Short = "";
		if (dbrow[6]) _rec->Multi = (atoi((char*) dbrow[6]) != 0); else _rec->Multi = false;
		if (dbrow[7]) _rec->ixVConstract = atol((char*) dbrow[7]); else _rec->ixVConstract = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQJobSupMNJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQJobSupMNJob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQJobSupMNJob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQJobSupMNJob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQJobSupMNJob();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->Short.assign(dbrow[5], dblengths[5]); else rec->Short = "";
			if (dbrow[6]) rec->Multi = (atoi((char*) dbrow[6]) != 0); else rec->Multi = false;
			if (dbrow[7]) rec->ixVConstract = atol((char*) dbrow[7]); else rec->ixVConstract = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQJobSupMNJob::insertRec(
			WznmQJobSupMNJob* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->Short.length();
	tinyint Multi = rec->Multi;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Multi,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVConstract,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQJobSupMNJob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQJobSupMNJob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQJobSupMNJob::insertRst(
			ListWznmQJobSupMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQJobSupMNJob::updateRec(
			WznmQJobSupMNJob* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->Short.length();
	tinyint Multi = rec->Multi;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Multi,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVConstract,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQJobSupMNJob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQJobSupMNJob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQJobSupMNJob::updateRst(
			ListWznmQJobSupMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQJobSupMNJob::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQJobSupMNJob::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQJobSupMNJob::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQJobSupMNJob::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQJobSupMNJob::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQJobSupMNJob::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQJobSupMNJob::loadRecByQref(
			ubigint qref
			, WznmQJobSupMNJob** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQJobSupMNJob WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQJobSupMNJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQJobSupMNJob WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQJobSupMNJob
 ******************************************************************************/

PgTblWznmQJobSupMNJob::PgTblWznmQJobSupMNJob() :
			TblWznmQJobSupMNJob()
			, PgTable()
		{
};

PgTblWznmQJobSupMNJob::~PgTblWznmQJobSupMNJob() {
};

void PgTblWznmQJobSupMNJob::initStatements() {
	createStatement("TblWznmQJobSupMNJob_insertRec", "INSERT INTO TblWznmQJobSupMNJob (jref, jnum, mref, ref, Short, Multi, ixVConstract) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQJobSupMNJob_updateRec", "UPDATE TblWznmQJobSupMNJob SET jref = $1, jnum = $2, mref = $3, ref = $4, Short = $5, Multi = $6, ixVConstract = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQJobSupMNJob_removeRecByQref", "DELETE FROM TblWznmQJobSupMNJob WHERE qref = $1", 1);
	createStatement("TblWznmQJobSupMNJob_removeRstByJref", "DELETE FROM TblWznmQJobSupMNJob WHERE jref = $1", 1);

	createStatement("TblWznmQJobSupMNJob_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, Short, Multi, ixVConstract FROM TblWznmQJobSupMNJob WHERE qref = $1", 1);
	createStatement("TblWznmQJobSupMNJob_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, Short, Multi, ixVConstract FROM TblWznmQJobSupMNJob WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQJobSupMNJob::loadRec(
			PGresult* res
			, WznmQJobSupMNJob** rec
		) {
	char* ptr;

	WznmQJobSupMNJob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQJobSupMNJob();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "multi"),
			PQfnumber(res, "ixvconstract")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Multi = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVConstract = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQJobSupMNJob::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQJobSupMNJob* rec;

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
			PQfnumber(res, "short"),
			PQfnumber(res, "multi"),
			PQfnumber(res, "ixvconstract")
		};

		while (numread < numrow) {
			rec = new WznmQJobSupMNJob();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Multi = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVConstract = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQJobSupMNJob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQJobSupMNJob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobSupMNJob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQJobSupMNJob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobSupMNJob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQJobSupMNJob::loadRecBySQL(
			const string& sqlstr
			, WznmQJobSupMNJob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQJobSupMNJob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQJobSupMNJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQJobSupMNJob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQJobSupMNJob::insertRec(
			WznmQJobSupMNJob* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	smallint _Multi = htons((smallint) rec->Multi);
	uint _ixVConstract = htonl(rec->ixVConstract);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->Short.c_str(),
		(char*) &_Multi,
		(char*) &_ixVConstract
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQJobSupMNJob_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobSupMNJob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQJobSupMNJob::insertRst(
			ListWznmQJobSupMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQJobSupMNJob::updateRec(
			WznmQJobSupMNJob* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	smallint _Multi = htons((smallint) rec->Multi);
	uint _ixVConstract = htonl(rec->ixVConstract);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->Short.c_str(),
		(char*) &_Multi,
		(char*) &_ixVConstract,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQJobSupMNJob_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobSupMNJob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQJobSupMNJob::updateRst(
			ListWznmQJobSupMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQJobSupMNJob::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQJobSupMNJob_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobSupMNJob::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQJobSupMNJob::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQJobSupMNJob_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobSupMNJob::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQJobSupMNJob::loadRecByQref(
			ubigint qref
			, WznmQJobSupMNJob** rec
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

	return loadRecByStmt("TblWznmQJobSupMNJob_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQJobSupMNJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobSupMNJob& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQJobSupMNJob_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
