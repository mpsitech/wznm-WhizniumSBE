/**
	* \file WznmQCapList.cpp
	* Dbs and XML wrapper for table TblWznmQCapList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQCapList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCapList
 ******************************************************************************/

WznmQCapList::WznmQCapList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint tplRefWznmMCapability
			, const string stubTplRefWznmMCapability
			, const uint ixWArtefact
			, const string srefsIxWArtefact
			, const string titsIxWArtefact
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->refWznmMVersion = refWznmMVersion;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->tplRefWznmMCapability = tplRefWznmMCapability;
	this->stubTplRefWznmMCapability = stubTplRefWznmMCapability;
	this->ixWArtefact = ixWArtefact;
	this->srefsIxWArtefact = srefsIxWArtefact;
	this->titsIxWArtefact = titsIxWArtefact;
};

void WznmQCapList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQCapList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "ver", stubRefWznmMVersion);
		writeString(wr, "tpl", stubTplRefWznmMCapability);
		writeString(wr, "atf", srefsIxWArtefact);
		writeString(wr, "atf2", titsIxWArtefact);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefWznmMVersion", stubRefWznmMVersion);
		writeString(wr, "stubTplRefWznmMCapability", stubTplRefWznmMCapability);
		writeString(wr, "srefsIxWArtefact", srefsIxWArtefact);
		writeString(wr, "titsIxWArtefact", titsIxWArtefact);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQCapList
 ******************************************************************************/

ListWznmQCapList::ListWznmQCapList() {
};

ListWznmQCapList::ListWznmQCapList(
			const ListWznmQCapList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCapList(*(src.nodes[i]));
};

ListWznmQCapList::~ListWznmQCapList() {
	clear();
};

void ListWznmQCapList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQCapList::size() const {
	return(nodes.size());
};

void ListWznmQCapList::append(
			WznmQCapList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQCapList& ListWznmQCapList::operator=(
			const ListWznmQCapList& src
		) {
	WznmQCapList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQCapList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQCapList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQCapList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQCapList
 ******************************************************************************/

TblWznmQCapList::TblWznmQCapList() {
};

TblWznmQCapList::~TblWznmQCapList() {
};

bool TblWznmQCapList::loadRecBySQL(
			const string& sqlstr
			, WznmQCapList** rec
		) {
	return false;
};

ubigint TblWznmQCapList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCapList& rst
		) {
	return 0;
};

ubigint TblWznmQCapList::insertRec(
			WznmQCapList* rec
		) {
	return 0;
};

ubigint TblWznmQCapList::insertNewRec(
			WznmQCapList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint tplRefWznmMCapability
			, const string stubTplRefWznmMCapability
			, const uint ixWArtefact
			, const string srefsIxWArtefact
			, const string titsIxWArtefact
		) {
	ubigint retval = 0;
	WznmQCapList* _rec = NULL;

	_rec = new WznmQCapList(0, jref, jnum, ref, sref, Title, refWznmMVersion, stubRefWznmMVersion, tplRefWznmMCapability, stubTplRefWznmMCapability, ixWArtefact, srefsIxWArtefact, titsIxWArtefact);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQCapList::appendNewRecToRst(
			ListWznmQCapList& rst
			, WznmQCapList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint tplRefWznmMCapability
			, const string stubTplRefWznmMCapability
			, const uint ixWArtefact
			, const string srefsIxWArtefact
			, const string titsIxWArtefact
		) {
	ubigint retval = 0;
	WznmQCapList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, refWznmMVersion, stubRefWznmMVersion, tplRefWznmMCapability, stubTplRefWznmMCapability, ixWArtefact, srefsIxWArtefact, titsIxWArtefact);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQCapList::insertRst(
			ListWznmQCapList& rst
		) {
};

void TblWznmQCapList::updateRec(
			WznmQCapList* rec
		) {
};

void TblWznmQCapList::updateRst(
			ListWznmQCapList& rst
		) {
};

void TblWznmQCapList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQCapList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQCapList::loadRecByQref(
			ubigint qref
			, WznmQCapList** rec
		) {
	return false;
};

ubigint TblWznmQCapList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCapList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQCapList
 ******************************************************************************/

MyTblWznmQCapList::MyTblWznmQCapList() :
			TblWznmQCapList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQCapList::~MyTblWznmQCapList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQCapList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQCapList (jref, jnum, ref, sref, Title, refWznmMVersion, tplRefWznmMCapability, ixWArtefact) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQCapList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, refWznmMVersion = ?, tplRefWznmMCapability = ?, ixWArtefact = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQCapList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQCapList WHERE jref = ?", false);
};

bool MyTblWznmQCapList::loadRecBySQL(
			const string& sqlstr
			, WznmQCapList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQCapList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCapList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCapList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQCapList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->refWznmMVersion = atoll((char*) dbrow[6]); else _rec->refWznmMVersion = 0;
		if (dbrow[7]) _rec->tplRefWznmMCapability = atoll((char*) dbrow[7]); else _rec->tplRefWznmMCapability = 0;
		if (dbrow[8]) _rec->ixWArtefact = atol((char*) dbrow[8]); else _rec->ixWArtefact = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQCapList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCapList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQCapList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCapList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCapList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQCapList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->refWznmMVersion = atoll((char*) dbrow[6]); else rec->refWznmMVersion = 0;
			if (dbrow[7]) rec->tplRefWznmMCapability = atoll((char*) dbrow[7]); else rec->tplRefWznmMCapability = 0;
			if (dbrow[8]) rec->ixWArtefact = atol((char*) dbrow[8]); else rec->ixWArtefact = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQCapList::insertRec(
			WznmQCapList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tplRefWznmMCapability,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixWArtefact,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQCapList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQCapList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQCapList::insertRst(
			ListWznmQCapList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQCapList::updateRec(
			WznmQCapList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tplRefWznmMCapability,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixWArtefact,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQCapList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQCapList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCapList::updateRst(
			ListWznmQCapList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQCapList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQCapList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQCapList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCapList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQCapList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQCapList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQCapList::loadRecByQref(
			ubigint qref
			, WznmQCapList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQCapList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQCapList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCapList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQCapList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQCapList
 ******************************************************************************/

PgTblWznmQCapList::PgTblWznmQCapList() :
			TblWznmQCapList()
			, PgTable()
		{
};

PgTblWznmQCapList::~PgTblWznmQCapList() {
};

void PgTblWznmQCapList::initStatements() {
	createStatement("TblWznmQCapList_insertRec", "INSERT INTO TblWznmQCapList (jref, jnum, ref, sref, Title, refWznmMVersion, tplRefWznmMCapability, ixWArtefact) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWznmQCapList_updateRec", "UPDATE TblWznmQCapList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, refWznmMVersion = $6, tplRefWznmMCapability = $7, ixWArtefact = $8 WHERE qref = $9", 9);
	createStatement("TblWznmQCapList_removeRecByQref", "DELETE FROM TblWznmQCapList WHERE qref = $1", 1);
	createStatement("TblWznmQCapList_removeRstByJref", "DELETE FROM TblWznmQCapList WHERE jref = $1", 1);

	createStatement("TblWznmQCapList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, refWznmMVersion, tplRefWznmMCapability, ixWArtefact FROM TblWznmQCapList WHERE qref = $1", 1);
	createStatement("TblWznmQCapList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, refWznmMVersion, tplRefWznmMCapability, ixWArtefact FROM TblWznmQCapList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQCapList::loadRec(
			PGresult* res
			, WznmQCapList** rec
		) {
	char* ptr;

	WznmQCapList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQCapList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "tplrefwznmmcapability"),
			PQfnumber(res, "ixwartefact")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->tplRefWznmMCapability = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixWArtefact = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQCapList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQCapList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQCapList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "tplrefwznmmcapability"),
			PQfnumber(res, "ixwartefact")
		};

		while (numread < numrow) {
			rec = new WznmQCapList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->tplRefWznmMCapability = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixWArtefact = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQCapList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQCapList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCapList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCapList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQCapList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCapList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQCapList::loadRecBySQL(
			const string& sqlstr
			, WznmQCapList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCapList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCapList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCapList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCapList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQCapList::insertRec(
			WznmQCapList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _tplRefWznmMCapability = htonl64(rec->tplRefWznmMCapability);
	uint _ixWArtefact = htonl(rec->ixWArtefact);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refWznmMVersion,
		(char*) &_tplRefWznmMCapability,
		(char*) &_ixWArtefact
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQCapList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCapList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQCapList::insertRst(
			ListWznmQCapList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQCapList::updateRec(
			WznmQCapList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _tplRefWznmMCapability = htonl64(rec->tplRefWznmMCapability);
	uint _ixWArtefact = htonl(rec->ixWArtefact);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refWznmMVersion,
		(char*) &_tplRefWznmMCapability,
		(char*) &_ixWArtefact,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQCapList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCapList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCapList::updateRst(
			ListWznmQCapList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQCapList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQCapList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCapList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCapList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQCapList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCapList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQCapList::loadRecByQref(
			ubigint qref
			, WznmQCapList** rec
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

	return loadRecByStmt("TblWznmQCapList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQCapList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCapList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQCapList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

