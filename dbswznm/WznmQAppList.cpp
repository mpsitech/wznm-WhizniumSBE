/**
	* \file WznmQAppList.cpp
	* Dbs and XML wrapper for table TblWznmQAppList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQAppList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQAppList
 ******************************************************************************/

WznmQAppList::WznmQAppList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Short
			, const string Title
			, const uint ixWznmVApptarget
			, const string srefIxWznmVApptarget
			, const string titIxWznmVApptarget
			, const ubigint verRefWznmMVersion
			, const string stubVerRefWznmMVersion
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->Short = Short;
	this->Title = Title;
	this->ixWznmVApptarget = ixWznmVApptarget;
	this->srefIxWznmVApptarget = srefIxWznmVApptarget;
	this->titIxWznmVApptarget = titIxWznmVApptarget;
	this->verRefWznmMVersion = verRefWznmMVersion;
	this->stubVerRefWznmMVersion = stubVerRefWznmMVersion;
};

void WznmQAppList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQAppList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "sho", Short);
		writeString(wr, "tit", Title);
		writeString(wr, "trg", srefIxWznmVApptarget);
		writeString(wr, "trg2", titIxWznmVApptarget);
		writeString(wr, "ver", stubVerRefWznmMVersion);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "Short", Short);
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxWznmVApptarget", srefIxWznmVApptarget);
		writeString(wr, "titIxWznmVApptarget", titIxWznmVApptarget);
		writeString(wr, "stubVerRefWznmMVersion", stubVerRefWznmMVersion);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQAppList
 ******************************************************************************/

ListWznmQAppList::ListWznmQAppList() {
};

ListWznmQAppList::ListWznmQAppList(
			const ListWznmQAppList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQAppList(*(src.nodes[i]));
};

ListWznmQAppList::~ListWznmQAppList() {
	clear();
};

void ListWznmQAppList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQAppList::size() const {
	return(nodes.size());
};

void ListWznmQAppList::append(
			WznmQAppList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQAppList& ListWznmQAppList::operator=(
			const ListWznmQAppList& src
		) {
	WznmQAppList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQAppList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQAppList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQAppList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQAppList
 ******************************************************************************/

TblWznmQAppList::TblWznmQAppList() {
};

TblWznmQAppList::~TblWznmQAppList() {
};

bool TblWznmQAppList::loadRecBySQL(
			const string& sqlstr
			, WznmQAppList** rec
		) {
	return false;
};

ubigint TblWznmQAppList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQAppList& rst
		) {
	return 0;
};

ubigint TblWznmQAppList::insertRec(
			WznmQAppList* rec
		) {
	return 0;
};

ubigint TblWznmQAppList::insertNewRec(
			WznmQAppList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Short
			, const string Title
			, const uint ixWznmVApptarget
			, const string srefIxWznmVApptarget
			, const string titIxWznmVApptarget
			, const ubigint verRefWznmMVersion
			, const string stubVerRefWznmMVersion
		) {
	ubigint retval = 0;
	WznmQAppList* _rec = NULL;

	_rec = new WznmQAppList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, Short, Title, ixWznmVApptarget, srefIxWznmVApptarget, titIxWznmVApptarget, verRefWznmMVersion, stubVerRefWznmMVersion);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQAppList::appendNewRecToRst(
			ListWznmQAppList& rst
			, WznmQAppList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Short
			, const string Title
			, const uint ixWznmVApptarget
			, const string srefIxWznmVApptarget
			, const string titIxWznmVApptarget
			, const ubigint verRefWznmMVersion
			, const string stubVerRefWznmMVersion
		) {
	ubigint retval = 0;
	WznmQAppList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, Short, Title, ixWznmVApptarget, srefIxWznmVApptarget, titIxWznmVApptarget, verRefWznmMVersion, stubVerRefWznmMVersion);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQAppList::insertRst(
			ListWznmQAppList& rst
		) {
};

void TblWznmQAppList::updateRec(
			WznmQAppList* rec
		) {
};

void TblWznmQAppList::updateRst(
			ListWznmQAppList& rst
		) {
};

void TblWznmQAppList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQAppList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQAppList::loadRecByQref(
			ubigint qref
			, WznmQAppList** rec
		) {
	return false;
};

ubigint TblWznmQAppList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQAppList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQAppList
 ******************************************************************************/

MyTblWznmQAppList::MyTblWznmQAppList() :
			TblWznmQAppList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQAppList::~MyTblWznmQAppList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQAppList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQAppList (jref, jnum, ref, grp, own, Short, Title, ixWznmVApptarget, verRefWznmMVersion) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQAppList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, Short = ?, Title = ?, ixWznmVApptarget = ?, verRefWznmMVersion = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQAppList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQAppList WHERE jref = ?", false);
};

bool MyTblWznmQAppList::loadRecBySQL(
			const string& sqlstr
			, WznmQAppList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQAppList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQAppList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQAppList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQAppList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->Short.assign(dbrow[6], dblengths[6]); else _rec->Short = "";
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->ixWznmVApptarget = atol((char*) dbrow[8]); else _rec->ixWznmVApptarget = 0;
		if (dbrow[9]) _rec->verRefWznmMVersion = atoll((char*) dbrow[9]); else _rec->verRefWznmMVersion = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQAppList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQAppList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQAppList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQAppList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQAppList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQAppList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->Short.assign(dbrow[6], dblengths[6]); else rec->Short = "";
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->ixWznmVApptarget = atol((char*) dbrow[8]); else rec->ixWznmVApptarget = 0;
			if (dbrow[9]) rec->verRefWznmMVersion = atoll((char*) dbrow[9]); else rec->verRefWznmMVersion = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQAppList::insertRec(
			WznmQAppList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->Short.length();
	l[6] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Short.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixWznmVApptarget,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQAppList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQAppList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQAppList::insertRst(
			ListWznmQAppList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQAppList::updateRec(
			WznmQAppList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->Short.length();
	l[6] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Short.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixWznmVApptarget,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQAppList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQAppList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQAppList::updateRst(
			ListWznmQAppList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQAppList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQAppList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQAppList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQAppList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQAppList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQAppList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQAppList::loadRecByQref(
			ubigint qref
			, WznmQAppList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQAppList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQAppList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQAppList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQAppList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQAppList
 ******************************************************************************/

PgTblWznmQAppList::PgTblWznmQAppList() :
			TblWznmQAppList()
			, PgTable()
		{
};

PgTblWznmQAppList::~PgTblWznmQAppList() {
};

void PgTblWznmQAppList::initStatements() {
	createStatement("TblWznmQAppList_insertRec", "INSERT INTO TblWznmQAppList (jref, jnum, ref, grp, own, Short, Title, ixWznmVApptarget, verRefWznmMVersion) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWznmQAppList_updateRec", "UPDATE TblWznmQAppList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, Short = $6, Title = $7, ixWznmVApptarget = $8, verRefWznmMVersion = $9 WHERE qref = $10", 10);
	createStatement("TblWznmQAppList_removeRecByQref", "DELETE FROM TblWznmQAppList WHERE qref = $1", 1);
	createStatement("TblWznmQAppList_removeRstByJref", "DELETE FROM TblWznmQAppList WHERE jref = $1", 1);

	createStatement("TblWznmQAppList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, Short, Title, ixWznmVApptarget, verRefWznmMVersion FROM TblWznmQAppList WHERE qref = $1", 1);
	createStatement("TblWznmQAppList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, Short, Title, ixWznmVApptarget, verRefWznmMVersion FROM TblWznmQAppList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQAppList::loadRec(
			PGresult* res
			, WznmQAppList** rec
		) {
	char* ptr;

	WznmQAppList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQAppList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixwznmvapptarget"),
			PQfnumber(res, "verrefwznmmversion")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixWznmVApptarget = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->verRefWznmMVersion = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQAppList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQAppList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQAppList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixwznmvapptarget"),
			PQfnumber(res, "verrefwznmmversion")
		};

		while (numread < numrow) {
			rec = new WznmQAppList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixWznmVApptarget = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->verRefWznmMVersion = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQAppList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQAppList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQAppList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQAppList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQAppList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQAppList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQAppList::loadRecBySQL(
			const string& sqlstr
			, WznmQAppList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQAppList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQAppList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQAppList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQAppList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQAppList::insertRec(
			WznmQAppList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWznmVApptarget = htonl(rec->ixWznmVApptarget);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_ixWznmVApptarget,
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQAppList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQAppList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQAppList::insertRst(
			ListWznmQAppList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQAppList::updateRec(
			WznmQAppList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWznmVApptarget = htonl(rec->ixWznmVApptarget);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_ixWznmVApptarget,
		(char*) &_verRefWznmMVersion,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQAppList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQAppList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQAppList::updateRst(
			ListWznmQAppList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQAppList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQAppList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQAppList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQAppList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQAppList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQAppList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQAppList::loadRecByQref(
			ubigint qref
			, WznmQAppList** rec
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

	return loadRecByStmt("TblWznmQAppList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQAppList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQAppList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQAppList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

