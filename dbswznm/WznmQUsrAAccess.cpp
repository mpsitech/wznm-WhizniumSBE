/**
	* \file WznmQUsrAAccess.cpp
	* Dbs and XML wrapper for table TblWznmQUsrAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsrAAccess
 ******************************************************************************/

WznmQUsrAAccess::WznmQUsrAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWznmVFeatgroup
			, const string srefX1IxWznmVFeatgroup
			, const string titX1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
			, const string srefsIxWznmWAccess
			, const string titsIxWznmWAccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxWznmVFeatgroup = x1IxWznmVFeatgroup;
	this->srefX1IxWznmVFeatgroup = srefX1IxWznmVFeatgroup;
	this->titX1IxWznmVFeatgroup = titX1IxWznmVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWznmWAccess = ixWznmWAccess;
	this->srefsIxWznmWAccess = srefsIxWznmWAccess;
	this->titsIxWznmWAccess = titsIxWznmWAccess;
};

void WznmQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "feg", srefX1IxWznmVFeatgroup);
		writeString(wr, "feg2", titX1IxWznmVFeatgroup);
		writeString(wr, "fea", x2FeaSrefUix);
		writeString(wr, "acc", srefsIxWznmWAccess);
		writeString(wr, "acc2", titsIxWznmWAccess);
	} else {
		writeString(wr, "srefX1IxWznmVFeatgroup", srefX1IxWznmVFeatgroup);
		writeString(wr, "titX1IxWznmVFeatgroup", titX1IxWznmVFeatgroup);
		writeString(wr, "x2FeaSrefUix", x2FeaSrefUix);
		writeString(wr, "srefsIxWznmWAccess", srefsIxWznmWAccess);
		writeString(wr, "titsIxWznmWAccess", titsIxWznmWAccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQUsrAAccess
 ******************************************************************************/

ListWznmQUsrAAccess::ListWznmQUsrAAccess() {
};

ListWznmQUsrAAccess::ListWznmQUsrAAccess(
			const ListWznmQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrAAccess(*(src.nodes[i]));
};

ListWznmQUsrAAccess::~ListWznmQUsrAAccess() {
	clear();
};

void ListWznmQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQUsrAAccess::size() const {
	return(nodes.size());
};

void ListWznmQUsrAAccess::append(
			WznmQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListWznmQUsrAAccess& ListWznmQUsrAAccess::operator=(
			const ListWznmQUsrAAccess& src
		) {
	WznmQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQUsrAAccess
 ******************************************************************************/

TblWznmQUsrAAccess::TblWznmQUsrAAccess() {
};

TblWznmQUsrAAccess::~TblWznmQUsrAAccess() {
};

bool TblWznmQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrAAccess** rec
		) {
	return false;
};

ubigint TblWznmQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	return 0;
};

ubigint TblWznmQUsrAAccess::insertRec(
			WznmQUsrAAccess* rec
		) {
	return 0;
};

ubigint TblWznmQUsrAAccess::insertNewRec(
			WznmQUsrAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWznmVFeatgroup
			, const string srefX1IxWznmVFeatgroup
			, const string titX1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
			, const string srefsIxWznmWAccess
			, const string titsIxWznmWAccess
		) {
	ubigint retval = 0;
	WznmQUsrAAccess* _rec = NULL;

	_rec = new WznmQUsrAAccess(0, jref, jnum, ref, x1IxWznmVFeatgroup, srefX1IxWznmVFeatgroup, titX1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess, srefsIxWznmWAccess, titsIxWznmWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQUsrAAccess::appendNewRecToRst(
			ListWznmQUsrAAccess& rst
			, WznmQUsrAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWznmVFeatgroup
			, const string srefX1IxWznmVFeatgroup
			, const string titX1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWznmWAccess
			, const string srefsIxWznmWAccess
			, const string titsIxWznmWAccess
		) {
	ubigint retval = 0;
	WznmQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxWznmVFeatgroup, srefX1IxWznmVFeatgroup, titX1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess, srefsIxWznmWAccess, titsIxWznmWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQUsrAAccess::insertRst(
			ListWznmQUsrAAccess& rst
		) {
};

void TblWznmQUsrAAccess::updateRec(
			WznmQUsrAAccess* rec
		) {
};

void TblWznmQUsrAAccess::updateRst(
			ListWznmQUsrAAccess& rst
		) {
};

void TblWznmQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQUsrAAccess::loadRecByQref(
			ubigint qref
			, WznmQUsrAAccess** rec
		) {
	return false;
};

ubigint TblWznmQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQUsrAAccess
 ******************************************************************************/

MyTblWznmQUsrAAccess::MyTblWznmQUsrAAccess() :
			TblWznmQUsrAAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQUsrAAccess::~MyTblWznmQUsrAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQUsrAAccess (jref, jnum, ref, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQUsrAAccess SET jref = ?, jnum = ?, ref = ?, x1IxWznmVFeatgroup = ?, x2FeaSrefUix = ?, ixWznmWAccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQUsrAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQUsrAAccess WHERE jref = ?", false);
};

bool MyTblWznmQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQUsrAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQUsrAAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQUsrAAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQUsrAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxWznmVFeatgroup = atol((char*) dbrow[4]); else _rec->x1IxWznmVFeatgroup = 0;
		if (dbrow[5]) _rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else _rec->x2FeaSrefUix = "";
		if (dbrow[6]) _rec->ixWznmWAccess = atol((char*) dbrow[6]); else _rec->ixWznmWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQUsrAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQUsrAAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQUsrAAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQUsrAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxWznmVFeatgroup = atol((char*) dbrow[4]); else rec->x1IxWznmVFeatgroup = 0;
			if (dbrow[5]) rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else rec->x2FeaSrefUix = "";
			if (dbrow[6]) rec->ixWznmWAccess = atol((char*) dbrow[6]); else rec->ixWznmWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQUsrAAccess::insertRec(
			WznmQUsrAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWznmVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmWAccess,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQUsrAAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQUsrAAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQUsrAAccess::insertRst(
			ListWznmQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQUsrAAccess::updateRec(
			WznmQUsrAAccess* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWznmVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmWAccess,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQUsrAAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQUsrAAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQUsrAAccess::updateRst(
			ListWznmQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQUsrAAccess::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQUsrAAccess::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQUsrAAccess::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQUsrAAccess::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQUsrAAccess::loadRecByQref(
			ubigint qref
			, WznmQUsrAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQUsrAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQUsrAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQUsrAAccess
 ******************************************************************************/

PgTblWznmQUsrAAccess::PgTblWznmQUsrAAccess() :
			TblWznmQUsrAAccess()
			, PgTable()
		{
};

PgTblWznmQUsrAAccess::~PgTblWznmQUsrAAccess() {
};

void PgTblWznmQUsrAAccess::initStatements() {
	createStatement("TblWznmQUsrAAccess_insertRec", "INSERT INTO TblWznmQUsrAAccess (jref, jnum, ref, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQUsrAAccess_updateRec", "UPDATE TblWznmQUsrAAccess SET jref = $1, jnum = $2, ref = $3, x1IxWznmVFeatgroup = $4, x2FeaSrefUix = $5, ixWznmWAccess = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQUsrAAccess_removeRecByQref", "DELETE FROM TblWznmQUsrAAccess WHERE qref = $1", 1);
	createStatement("TblWznmQUsrAAccess_removeRstByJref", "DELETE FROM TblWznmQUsrAAccess WHERE jref = $1", 1);

	createStatement("TblWznmQUsrAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmQUsrAAccess WHERE qref = $1", 1);
	createStatement("TblWznmQUsrAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxWznmVFeatgroup, x2FeaSrefUix, ixWznmWAccess FROM TblWznmQUsrAAccess WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQUsrAAccess::loadRec(
			PGresult* res
			, WznmQUsrAAccess** rec
		) {
	char* ptr;

	WznmQUsrAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQUsrAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixwznmvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwznmwaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxWznmVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQUsrAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQUsrAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixwznmvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwznmwaccess")
		};

		while (numread < numrow) {
			rec = new WznmQUsrAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxWznmVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQUsrAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrAAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQUsrAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrAAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQUsrAAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQUsrAAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQUsrAAccess::insertRec(
			WznmQUsrAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxWznmVFeatgroup = htonl(rec->x1IxWznmVFeatgroup);
	uint _ixWznmWAccess = htonl(rec->ixWznmWAccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxWznmVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWznmWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQUsrAAccess_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrAAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQUsrAAccess::insertRst(
			ListWznmQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQUsrAAccess::updateRec(
			WznmQUsrAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxWznmVFeatgroup = htonl(rec->x1IxWznmVFeatgroup);
	uint _ixWznmWAccess = htonl(rec->ixWznmWAccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxWznmVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWznmWAccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQUsrAAccess_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrAAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQUsrAAccess::updateRst(
			ListWznmQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQUsrAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQUsrAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrAAccess::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQUsrAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQUsrAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrAAccess::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQUsrAAccess::loadRecByQref(
			ubigint qref
			, WznmQUsrAAccess** rec
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

	return loadRecByStmt("TblWznmQUsrAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQUsrAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

