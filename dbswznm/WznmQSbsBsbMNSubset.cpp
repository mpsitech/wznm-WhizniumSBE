/**
	* \file WznmQSbsBsbMNSubset.cpp
	* Dbs and XML wrapper for table TblWznmQSbsBsbMNSubset (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQSbsBsbMNSubset.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsBsbMNSubset
 ******************************************************************************/

WznmQSbsBsbMNSubset::WznmQSbsBsbMNSubset(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixVReltype
			, const string srefIxVReltype
			, const string titIxVReltype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixVReltype = ixVReltype;
	this->srefIxVReltype = srefIxVReltype;
	this->titIxVReltype = titIxVReltype;
};

void WznmQSbsBsbMNSubset::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSbsBsbMNSubset";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "rty", srefIxVReltype);
		writeString(wr, "rty2", titIxVReltype);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxVReltype", srefIxVReltype);
		writeString(wr, "titIxVReltype", titIxVReltype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQSbsBsbMNSubset
 ******************************************************************************/

ListWznmQSbsBsbMNSubset::ListWznmQSbsBsbMNSubset() {
};

ListWznmQSbsBsbMNSubset::ListWznmQSbsBsbMNSubset(
			const ListWznmQSbsBsbMNSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsBsbMNSubset(*(src.nodes[i]));
};

ListWznmQSbsBsbMNSubset::~ListWznmQSbsBsbMNSubset() {
	clear();
};

void ListWznmQSbsBsbMNSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSbsBsbMNSubset::size() const {
	return(nodes.size());
};

void ListWznmQSbsBsbMNSubset::append(
			WznmQSbsBsbMNSubset* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSbsBsbMNSubset& ListWznmQSbsBsbMNSubset::operator=(
			const ListWznmQSbsBsbMNSubset& src
		) {
	WznmQSbsBsbMNSubset* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSbsBsbMNSubset(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSbsBsbMNSubset::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSbsBsbMNSubset";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSbsBsbMNSubset
 ******************************************************************************/

TblWznmQSbsBsbMNSubset::TblWznmQSbsBsbMNSubset() {
};

TblWznmQSbsBsbMNSubset::~TblWznmQSbsBsbMNSubset() {
};

bool TblWznmQSbsBsbMNSubset::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsBsbMNSubset** rec
		) {
	return false;
};

ubigint TblWznmQSbsBsbMNSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	return 0;
};

ubigint TblWznmQSbsBsbMNSubset::insertRec(
			WznmQSbsBsbMNSubset* rec
		) {
	return 0;
};

ubigint TblWznmQSbsBsbMNSubset::insertNewRec(
			WznmQSbsBsbMNSubset** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixVReltype
			, const string srefIxVReltype
			, const string titIxVReltype
		) {
	ubigint retval = 0;
	WznmQSbsBsbMNSubset* _rec = NULL;

	_rec = new WznmQSbsBsbMNSubset(0, jref, jnum, mref, stubMref, ref, ixVReltype, srefIxVReltype, titIxVReltype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSbsBsbMNSubset::appendNewRecToRst(
			ListWznmQSbsBsbMNSubset& rst
			, WznmQSbsBsbMNSubset** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixVReltype
			, const string srefIxVReltype
			, const string titIxVReltype
		) {
	ubigint retval = 0;
	WznmQSbsBsbMNSubset* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixVReltype, srefIxVReltype, titIxVReltype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSbsBsbMNSubset::insertRst(
			ListWznmQSbsBsbMNSubset& rst
		) {
};

void TblWznmQSbsBsbMNSubset::updateRec(
			WznmQSbsBsbMNSubset* rec
		) {
};

void TblWznmQSbsBsbMNSubset::updateRst(
			ListWznmQSbsBsbMNSubset& rst
		) {
};

void TblWznmQSbsBsbMNSubset::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSbsBsbMNSubset::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSbsBsbMNSubset::loadRecByQref(
			ubigint qref
			, WznmQSbsBsbMNSubset** rec
		) {
	return false;
};

ubigint TblWznmQSbsBsbMNSubset::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSbsBsbMNSubset
 ******************************************************************************/

MyTblWznmQSbsBsbMNSubset::MyTblWznmQSbsBsbMNSubset() :
			TblWznmQSbsBsbMNSubset()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSbsBsbMNSubset::~MyTblWznmQSbsBsbMNSubset() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSbsBsbMNSubset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSbsBsbMNSubset (jref, jnum, mref, ref, ixVReltype) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSbsBsbMNSubset SET jref = ?, jnum = ?, mref = ?, ref = ?, ixVReltype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSbsBsbMNSubset WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSbsBsbMNSubset WHERE jref = ?", false);
};

bool MyTblWznmQSbsBsbMNSubset::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsBsbMNSubset** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSbsBsbMNSubset* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQSbsBsbMNSubset();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixVReltype = atol((char*) dbrow[5]); else _rec->ixVReltype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSbsBsbMNSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSbsBsbMNSubset* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQSbsBsbMNSubset();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixVReltype = atol((char*) dbrow[5]); else rec->ixVReltype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSbsBsbMNSubset::insertRec(
			WznmQSbsBsbMNSubset* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVReltype,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSbsBsbMNSubset::insertRst(
			ListWznmQSbsBsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSbsBsbMNSubset::updateRec(
			WznmQSbsBsbMNSubset* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVReltype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsBsbMNSubset::updateRst(
			ListWznmQSbsBsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSbsBsbMNSubset::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsBsbMNSubset::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSbsBsbMNSubset::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSbsBsbMNSubset::loadRecByQref(
			ubigint qref
			, WznmQSbsBsbMNSubset** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSbsBsbMNSubset WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSbsBsbMNSubset::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSbsBsbMNSubset WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSbsBsbMNSubset
 ******************************************************************************/

PgTblWznmQSbsBsbMNSubset::PgTblWznmQSbsBsbMNSubset() :
			TblWznmQSbsBsbMNSubset()
			, PgTable()
		{
};

PgTblWznmQSbsBsbMNSubset::~PgTblWznmQSbsBsbMNSubset() {
};

void PgTblWznmQSbsBsbMNSubset::initStatements() {
	createStatement("TblWznmQSbsBsbMNSubset_insertRec", "INSERT INTO TblWznmQSbsBsbMNSubset (jref, jnum, mref, ref, ixVReltype) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWznmQSbsBsbMNSubset_updateRec", "UPDATE TblWznmQSbsBsbMNSubset SET jref = $1, jnum = $2, mref = $3, ref = $4, ixVReltype = $5 WHERE qref = $6", 6);
	createStatement("TblWznmQSbsBsbMNSubset_removeRecByQref", "DELETE FROM TblWznmQSbsBsbMNSubset WHERE qref = $1", 1);
	createStatement("TblWznmQSbsBsbMNSubset_removeRstByJref", "DELETE FROM TblWznmQSbsBsbMNSubset WHERE jref = $1", 1);

	createStatement("TblWznmQSbsBsbMNSubset_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixVReltype FROM TblWznmQSbsBsbMNSubset WHERE qref = $1", 1);
	createStatement("TblWznmQSbsBsbMNSubset_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixVReltype FROM TblWznmQSbsBsbMNSubset WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSbsBsbMNSubset::loadRec(
			PGresult* res
			, WznmQSbsBsbMNSubset** rec
		) {
	char* ptr;

	WznmQSbsBsbMNSubset* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSbsBsbMNSubset();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvreltype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVReltype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSbsBsbMNSubset::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSbsBsbMNSubset* rec;

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
			PQfnumber(res, "ixvreltype")
		};

		while (numread < numrow) {
			rec = new WznmQSbsBsbMNSubset();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVReltype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSbsBsbMNSubset::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSbsBsbMNSubset** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsBsbMNSubset::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsBsbMNSubset::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsBsbMNSubset::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSbsBsbMNSubset::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsBsbMNSubset** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsBsbMNSubset::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsBsbMNSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsBsbMNSubset::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSbsBsbMNSubset::insertRec(
			WznmQSbsBsbMNSubset* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVReltype = htonl(rec->ixVReltype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixVReltype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQSbsBsbMNSubset_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsBsbMNSubset::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSbsBsbMNSubset::insertRst(
			ListWznmQSbsBsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSbsBsbMNSubset::updateRec(
			WznmQSbsBsbMNSubset* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVReltype = htonl(rec->ixVReltype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixVReltype,
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

	res = PQexecPrepared(dbs, "TblWznmQSbsBsbMNSubset_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsBsbMNSubset::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsBsbMNSubset::updateRst(
			ListWznmQSbsBsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSbsBsbMNSubset::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsBsbMNSubset_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsBsbMNSubset::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsBsbMNSubset::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsBsbMNSubset_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsBsbMNSubset::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSbsBsbMNSubset::loadRecByQref(
			ubigint qref
			, WznmQSbsBsbMNSubset** rec
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

	return loadRecByStmt("TblWznmQSbsBsbMNSubset_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSbsBsbMNSubset::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsBsbMNSubset& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSbsBsbMNSubset_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

