/**
	* \file WznmQSbsAsbMNSubset.cpp
	* Dbs and XML wrapper for table TblWznmQSbsAsbMNSubset (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQSbsAsbMNSubset.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsAsbMNSubset
 ******************************************************************************/

WznmQSbsAsbMNSubset::WznmQSbsAsbMNSubset(
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

void WznmQSbsAsbMNSubset::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSbsAsbMNSubset";

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
 class ListWznmQSbsAsbMNSubset
 ******************************************************************************/

ListWznmQSbsAsbMNSubset::ListWznmQSbsAsbMNSubset() {
};

ListWznmQSbsAsbMNSubset::ListWznmQSbsAsbMNSubset(
			const ListWznmQSbsAsbMNSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsAsbMNSubset(*(src.nodes[i]));
};

ListWznmQSbsAsbMNSubset::~ListWznmQSbsAsbMNSubset() {
	clear();
};

void ListWznmQSbsAsbMNSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSbsAsbMNSubset::size() const {
	return(nodes.size());
};

void ListWznmQSbsAsbMNSubset::append(
			WznmQSbsAsbMNSubset* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSbsAsbMNSubset& ListWznmQSbsAsbMNSubset::operator=(
			const ListWznmQSbsAsbMNSubset& src
		) {
	WznmQSbsAsbMNSubset* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSbsAsbMNSubset(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSbsAsbMNSubset::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSbsAsbMNSubset";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSbsAsbMNSubset
 ******************************************************************************/

TblWznmQSbsAsbMNSubset::TblWznmQSbsAsbMNSubset() {
};

TblWznmQSbsAsbMNSubset::~TblWznmQSbsAsbMNSubset() {
};

bool TblWznmQSbsAsbMNSubset::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsAsbMNSubset** rec
		) {
	return false;
};

ubigint TblWznmQSbsAsbMNSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	return 0;
};

ubigint TblWznmQSbsAsbMNSubset::insertRec(
			WznmQSbsAsbMNSubset* rec
		) {
	return 0;
};

ubigint TblWznmQSbsAsbMNSubset::insertNewRec(
			WznmQSbsAsbMNSubset** rec
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
	WznmQSbsAsbMNSubset* _rec = NULL;

	_rec = new WznmQSbsAsbMNSubset(0, jref, jnum, mref, stubMref, ref, ixVReltype, srefIxVReltype, titIxVReltype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSbsAsbMNSubset::appendNewRecToRst(
			ListWznmQSbsAsbMNSubset& rst
			, WznmQSbsAsbMNSubset** rec
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
	WznmQSbsAsbMNSubset* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixVReltype, srefIxVReltype, titIxVReltype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSbsAsbMNSubset::insertRst(
			ListWznmQSbsAsbMNSubset& rst
		) {
};

void TblWznmQSbsAsbMNSubset::updateRec(
			WznmQSbsAsbMNSubset* rec
		) {
};

void TblWznmQSbsAsbMNSubset::updateRst(
			ListWznmQSbsAsbMNSubset& rst
		) {
};

void TblWznmQSbsAsbMNSubset::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSbsAsbMNSubset::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSbsAsbMNSubset::loadRecByQref(
			ubigint qref
			, WznmQSbsAsbMNSubset** rec
		) {
	return false;
};

ubigint TblWznmQSbsAsbMNSubset::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSbsAsbMNSubset
 ******************************************************************************/

MyTblWznmQSbsAsbMNSubset::MyTblWznmQSbsAsbMNSubset() :
			TblWznmQSbsAsbMNSubset()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSbsAsbMNSubset::~MyTblWznmQSbsAsbMNSubset() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSbsAsbMNSubset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSbsAsbMNSubset (jref, jnum, mref, ref, ixVReltype) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSbsAsbMNSubset SET jref = ?, jnum = ?, mref = ?, ref = ?, ixVReltype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSbsAsbMNSubset WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSbsAsbMNSubset WHERE jref = ?", false);
};

bool MyTblWznmQSbsAsbMNSubset::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsAsbMNSubset** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSbsAsbMNSubset* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQSbsAsbMNSubset();

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

ubigint MyTblWznmQSbsAsbMNSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSbsAsbMNSubset* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQSbsAsbMNSubset();

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

ubigint MyTblWznmQSbsAsbMNSubset::insertRec(
			WznmQSbsAsbMNSubset* rec
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
		string dbms = "MyTblWznmQSbsAsbMNSubset::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSbsAsbMNSubset::insertRst(
			ListWznmQSbsAsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSbsAsbMNSubset::updateRec(
			WznmQSbsAsbMNSubset* rec
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
		string dbms = "MyTblWznmQSbsAsbMNSubset::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsAsbMNSubset::updateRst(
			ListWznmQSbsAsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSbsAsbMNSubset::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsAsbMNSubset::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSbsAsbMNSubset::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSbsAsbMNSubset::loadRecByQref(
			ubigint qref
			, WznmQSbsAsbMNSubset** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSbsAsbMNSubset WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSbsAsbMNSubset::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSbsAsbMNSubset WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSbsAsbMNSubset
 ******************************************************************************/

PgTblWznmQSbsAsbMNSubset::PgTblWznmQSbsAsbMNSubset() :
			TblWznmQSbsAsbMNSubset()
			, PgTable()
		{
};

PgTblWznmQSbsAsbMNSubset::~PgTblWznmQSbsAsbMNSubset() {
};

void PgTblWznmQSbsAsbMNSubset::initStatements() {
	createStatement("TblWznmQSbsAsbMNSubset_insertRec", "INSERT INTO TblWznmQSbsAsbMNSubset (jref, jnum, mref, ref, ixVReltype) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWznmQSbsAsbMNSubset_updateRec", "UPDATE TblWznmQSbsAsbMNSubset SET jref = $1, jnum = $2, mref = $3, ref = $4, ixVReltype = $5 WHERE qref = $6", 6);
	createStatement("TblWznmQSbsAsbMNSubset_removeRecByQref", "DELETE FROM TblWznmQSbsAsbMNSubset WHERE qref = $1", 1);
	createStatement("TblWznmQSbsAsbMNSubset_removeRstByJref", "DELETE FROM TblWznmQSbsAsbMNSubset WHERE jref = $1", 1);

	createStatement("TblWznmQSbsAsbMNSubset_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixVReltype FROM TblWznmQSbsAsbMNSubset WHERE qref = $1", 1);
	createStatement("TblWznmQSbsAsbMNSubset_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixVReltype FROM TblWznmQSbsAsbMNSubset WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSbsAsbMNSubset::loadRec(
			PGresult* res
			, WznmQSbsAsbMNSubset** rec
		) {
	char* ptr;

	WznmQSbsAsbMNSubset* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSbsAsbMNSubset();

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

ubigint PgTblWznmQSbsAsbMNSubset::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSbsAsbMNSubset* rec;

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
			rec = new WznmQSbsAsbMNSubset();

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

bool PgTblWznmQSbsAsbMNSubset::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSbsAsbMNSubset** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsAsbMNSubset::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsAsbMNSubset::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsAsbMNSubset::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSbsAsbMNSubset::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsAsbMNSubset** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsAsbMNSubset::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsAsbMNSubset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsAsbMNSubset::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSbsAsbMNSubset::insertRec(
			WznmQSbsAsbMNSubset* rec
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

	res = PQexecPrepared(dbs, "TblWznmQSbsAsbMNSubset_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsAsbMNSubset::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSbsAsbMNSubset::insertRst(
			ListWznmQSbsAsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSbsAsbMNSubset::updateRec(
			WznmQSbsAsbMNSubset* rec
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

	res = PQexecPrepared(dbs, "TblWznmQSbsAsbMNSubset_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsAsbMNSubset::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsAsbMNSubset::updateRst(
			ListWznmQSbsAsbMNSubset& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSbsAsbMNSubset::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsAsbMNSubset_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsAsbMNSubset::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsAsbMNSubset::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsAsbMNSubset_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsAsbMNSubset::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSbsAsbMNSubset::loadRecByQref(
			ubigint qref
			, WznmQSbsAsbMNSubset** rec
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

	return loadRecByStmt("TblWznmQSbsAsbMNSubset_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSbsAsbMNSubset::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsAsbMNSubset& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSbsAsbMNSubset_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

