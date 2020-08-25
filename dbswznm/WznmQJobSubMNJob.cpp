/**
	* \file WznmQJobSubMNJob.cpp
	* Dbs and XML wrapper for table TblWznmQJobSubMNJob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQJobSubMNJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobSubMNJob
 ******************************************************************************/

WznmQJobSubMNJob::WznmQJobSubMNJob(
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

void WznmQJobSubMNJob::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQJobSubMNJob";

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
 class ListWznmQJobSubMNJob
 ******************************************************************************/

ListWznmQJobSubMNJob::ListWznmQJobSubMNJob() {
};

ListWznmQJobSubMNJob::ListWznmQJobSubMNJob(
			const ListWznmQJobSubMNJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobSubMNJob(*(src.nodes[i]));
};

ListWznmQJobSubMNJob::~ListWznmQJobSubMNJob() {
	clear();
};

void ListWznmQJobSubMNJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQJobSubMNJob::size() const {
	return(nodes.size());
};

void ListWznmQJobSubMNJob::append(
			WznmQJobSubMNJob* rec
		) {
	nodes.push_back(rec);
};

ListWznmQJobSubMNJob& ListWznmQJobSubMNJob::operator=(
			const ListWznmQJobSubMNJob& src
		) {
	WznmQJobSubMNJob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQJobSubMNJob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQJobSubMNJob::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQJobSubMNJob";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQJobSubMNJob
 ******************************************************************************/

TblWznmQJobSubMNJob::TblWznmQJobSubMNJob() {
};

TblWznmQJobSubMNJob::~TblWznmQJobSubMNJob() {
};

bool TblWznmQJobSubMNJob::loadRecBySQL(
			const string& sqlstr
			, WznmQJobSubMNJob** rec
		) {
	return false;
};

ubigint TblWznmQJobSubMNJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	return 0;
};

ubigint TblWznmQJobSubMNJob::insertRec(
			WznmQJobSubMNJob* rec
		) {
	return 0;
};

ubigint TblWznmQJobSubMNJob::insertNewRec(
			WznmQJobSubMNJob** rec
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
	WznmQJobSubMNJob* _rec = NULL;

	_rec = new WznmQJobSubMNJob(0, jref, jnum, mref, stubMref, ref, Short, Multi, yesnoMulti, ixVConstract, srefIxVConstract, titIxVConstract);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQJobSubMNJob::appendNewRecToRst(
			ListWznmQJobSubMNJob& rst
			, WznmQJobSubMNJob** rec
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
	WznmQJobSubMNJob* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, Short, Multi, yesnoMulti, ixVConstract, srefIxVConstract, titIxVConstract);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQJobSubMNJob::insertRst(
			ListWznmQJobSubMNJob& rst
		) {
};

void TblWznmQJobSubMNJob::updateRec(
			WznmQJobSubMNJob* rec
		) {
};

void TblWznmQJobSubMNJob::updateRst(
			ListWznmQJobSubMNJob& rst
		) {
};

void TblWznmQJobSubMNJob::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQJobSubMNJob::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQJobSubMNJob::loadRecByQref(
			ubigint qref
			, WznmQJobSubMNJob** rec
		) {
	return false;
};

ubigint TblWznmQJobSubMNJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQJobSubMNJob
 ******************************************************************************/

MyTblWznmQJobSubMNJob::MyTblWznmQJobSubMNJob() :
			TblWznmQJobSubMNJob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQJobSubMNJob::~MyTblWznmQJobSubMNJob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQJobSubMNJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQJobSubMNJob (jref, jnum, mref, ref, Short, Multi, ixVConstract) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQJobSubMNJob SET jref = ?, jnum = ?, mref = ?, ref = ?, Short = ?, Multi = ?, ixVConstract = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQJobSubMNJob WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQJobSubMNJob WHERE jref = ?", false);
};

bool MyTblWznmQJobSubMNJob::loadRecBySQL(
			const string& sqlstr
			, WznmQJobSubMNJob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQJobSubMNJob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQJobSubMNJob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQJobSubMNJob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQJobSubMNJob();

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

ubigint MyTblWznmQJobSubMNJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQJobSubMNJob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQJobSubMNJob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQJobSubMNJob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQJobSubMNJob();

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

ubigint MyTblWznmQJobSubMNJob::insertRec(
			WznmQJobSubMNJob* rec
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
		string dbms = "MyTblWznmQJobSubMNJob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQJobSubMNJob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQJobSubMNJob::insertRst(
			ListWznmQJobSubMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQJobSubMNJob::updateRec(
			WznmQJobSubMNJob* rec
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
		string dbms = "MyTblWznmQJobSubMNJob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQJobSubMNJob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQJobSubMNJob::updateRst(
			ListWznmQJobSubMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQJobSubMNJob::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQJobSubMNJob::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQJobSubMNJob::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQJobSubMNJob::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQJobSubMNJob::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQJobSubMNJob::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQJobSubMNJob::loadRecByQref(
			ubigint qref
			, WznmQJobSubMNJob** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQJobSubMNJob WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQJobSubMNJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQJobSubMNJob WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQJobSubMNJob
 ******************************************************************************/

PgTblWznmQJobSubMNJob::PgTblWznmQJobSubMNJob() :
			TblWznmQJobSubMNJob()
			, PgTable()
		{
};

PgTblWznmQJobSubMNJob::~PgTblWznmQJobSubMNJob() {
};

void PgTblWznmQJobSubMNJob::initStatements() {
	createStatement("TblWznmQJobSubMNJob_insertRec", "INSERT INTO TblWznmQJobSubMNJob (jref, jnum, mref, ref, Short, Multi, ixVConstract) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQJobSubMNJob_updateRec", "UPDATE TblWznmQJobSubMNJob SET jref = $1, jnum = $2, mref = $3, ref = $4, Short = $5, Multi = $6, ixVConstract = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQJobSubMNJob_removeRecByQref", "DELETE FROM TblWznmQJobSubMNJob WHERE qref = $1", 1);
	createStatement("TblWznmQJobSubMNJob_removeRstByJref", "DELETE FROM TblWznmQJobSubMNJob WHERE jref = $1", 1);

	createStatement("TblWznmQJobSubMNJob_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, Short, Multi, ixVConstract FROM TblWznmQJobSubMNJob WHERE qref = $1", 1);
	createStatement("TblWznmQJobSubMNJob_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, Short, Multi, ixVConstract FROM TblWznmQJobSubMNJob WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQJobSubMNJob::loadRec(
			PGresult* res
			, WznmQJobSubMNJob** rec
		) {
	char* ptr;

	WznmQJobSubMNJob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQJobSubMNJob();

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

ubigint PgTblWznmQJobSubMNJob::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQJobSubMNJob* rec;

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
			rec = new WznmQJobSubMNJob();

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

bool PgTblWznmQJobSubMNJob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQJobSubMNJob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobSubMNJob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQJobSubMNJob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobSubMNJob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQJobSubMNJob::loadRecBySQL(
			const string& sqlstr
			, WznmQJobSubMNJob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQJobSubMNJob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQJobSubMNJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQJobSubMNJob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQJobSubMNJob::insertRec(
			WznmQJobSubMNJob* rec
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

	res = PQexecPrepared(dbs, "TblWznmQJobSubMNJob_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQJobSubMNJob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQJobSubMNJob::insertRst(
			ListWznmQJobSubMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQJobSubMNJob::updateRec(
			WznmQJobSubMNJob* rec
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

	res = PQexecPrepared(dbs, "TblWznmQJobSubMNJob_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobSubMNJob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQJobSubMNJob::updateRst(
			ListWznmQJobSubMNJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQJobSubMNJob::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQJobSubMNJob_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobSubMNJob::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQJobSubMNJob::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQJobSubMNJob_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQJobSubMNJob::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQJobSubMNJob::loadRecByQref(
			ubigint qref
			, WznmQJobSubMNJob** rec
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

	return loadRecByStmt("TblWznmQJobSubMNJob_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQJobSubMNJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQJobSubMNJob& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQJobSubMNJob_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

