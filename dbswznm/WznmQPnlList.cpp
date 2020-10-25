/**
	* \file WznmQPnlList.cpp
	* Dbs and XML wrapper for table TblWznmQPnlList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQPnlList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPnlList
 ******************************************************************************/

WznmQPnlList::WznmQPnlList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint carRefWznmMCard
			, const string stubCarRefWznmMCard
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->carRefWznmMCard = carRefWznmMCard;
	this->stubCarRefWznmMCard = stubCarRefWznmMCard;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
};

void WznmQPnlList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQPnlList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "car", stubCarRefWznmMCard);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubCarRefWznmMCard", stubCarRefWznmMCard);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQPnlList
 ******************************************************************************/

ListWznmQPnlList::ListWznmQPnlList() {
};

ListWznmQPnlList::ListWznmQPnlList(
			const ListWznmQPnlList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPnlList(*(src.nodes[i]));
};

ListWznmQPnlList::~ListWznmQPnlList() {
	clear();
};

void ListWznmQPnlList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQPnlList::size() const {
	return(nodes.size());
};

void ListWznmQPnlList::append(
			WznmQPnlList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQPnlList& ListWznmQPnlList::operator=(
			const ListWznmQPnlList& src
		) {
	WznmQPnlList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQPnlList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQPnlList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQPnlList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQPnlList
 ******************************************************************************/

TblWznmQPnlList::TblWznmQPnlList() {
};

TblWznmQPnlList::~TblWznmQPnlList() {
};

bool TblWznmQPnlList::loadRecBySQL(
			const string& sqlstr
			, WznmQPnlList** rec
		) {
	return false;
};

ubigint TblWznmQPnlList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPnlList& rst
		) {
	return 0;
};

ubigint TblWznmQPnlList::insertRec(
			WznmQPnlList* rec
		) {
	return 0;
};

ubigint TblWznmQPnlList::insertNewRec(
			WznmQPnlList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint carRefWznmMCard
			, const string stubCarRefWznmMCard
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
		) {
	ubigint retval = 0;
	WznmQPnlList* _rec = NULL;

	_rec = new WznmQPnlList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, carRefWznmMCard, stubCarRefWznmMCard, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQPnlList::appendNewRecToRst(
			ListWznmQPnlList& rst
			, WznmQPnlList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint carRefWznmMCard
			, const string stubCarRefWznmMCard
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
		) {
	ubigint retval = 0;
	WznmQPnlList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, carRefWznmMCard, stubCarRefWznmMCard, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQPnlList::insertRst(
			ListWznmQPnlList& rst
		) {
};

void TblWznmQPnlList::updateRec(
			WznmQPnlList* rec
		) {
};

void TblWznmQPnlList::updateRst(
			ListWznmQPnlList& rst
		) {
};

void TblWznmQPnlList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQPnlList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQPnlList::loadRecByQref(
			ubigint qref
			, WznmQPnlList** rec
		) {
	return false;
};

ubigint TblWznmQPnlList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPnlList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQPnlList
 ******************************************************************************/

MyTblWznmQPnlList::MyTblWznmQPnlList() :
			TblWznmQPnlList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQPnlList::~MyTblWznmQPnlList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQPnlList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQPnlList (jref, jnum, ref, sref, ixVBasetype, carRefWznmMCard, refIxVTbl, refUref) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQPnlList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, carRefWznmMCard = ?, refIxVTbl = ?, refUref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQPnlList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQPnlList WHERE jref = ?", false);
};

bool MyTblWznmQPnlList::loadRecBySQL(
			const string& sqlstr
			, WznmQPnlList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQPnlList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPnlList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPnlList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQPnlList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->carRefWznmMCard = atoll((char*) dbrow[6]); else _rec->carRefWznmMCard = 0;
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQPnlList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPnlList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQPnlList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPnlList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPnlList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQPnlList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->carRefWznmMCard = atoll((char*) dbrow[6]); else rec->carRefWznmMCard = 0;
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQPnlList::insertRec(
			WznmQPnlList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->carRefWznmMCard,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQPnlList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQPnlList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQPnlList::insertRst(
			ListWznmQPnlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQPnlList::updateRec(
			WznmQPnlList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->carRefWznmMCard,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQPnlList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQPnlList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPnlList::updateRst(
			ListWznmQPnlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQPnlList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQPnlList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQPnlList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPnlList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQPnlList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQPnlList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQPnlList::loadRecByQref(
			ubigint qref
			, WznmQPnlList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQPnlList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQPnlList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPnlList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQPnlList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQPnlList
 ******************************************************************************/

PgTblWznmQPnlList::PgTblWznmQPnlList() :
			TblWznmQPnlList()
			, PgTable()
		{
};

PgTblWznmQPnlList::~PgTblWznmQPnlList() {
};

void PgTblWznmQPnlList::initStatements() {
	createStatement("TblWznmQPnlList_insertRec", "INSERT INTO TblWznmQPnlList (jref, jnum, ref, sref, ixVBasetype, carRefWznmMCard, refIxVTbl, refUref) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWznmQPnlList_updateRec", "UPDATE TblWznmQPnlList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, carRefWznmMCard = $6, refIxVTbl = $7, refUref = $8 WHERE qref = $9", 9);
	createStatement("TblWznmQPnlList_removeRecByQref", "DELETE FROM TblWznmQPnlList WHERE qref = $1", 1);
	createStatement("TblWznmQPnlList_removeRstByJref", "DELETE FROM TblWznmQPnlList WHERE jref = $1", 1);

	createStatement("TblWznmQPnlList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, carRefWznmMCard, refIxVTbl, refUref FROM TblWznmQPnlList WHERE qref = $1", 1);
	createStatement("TblWznmQPnlList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, carRefWznmMCard, refIxVTbl, refUref FROM TblWznmQPnlList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQPnlList::loadRec(
			PGresult* res
			, WznmQPnlList** rec
		) {
	char* ptr;

	WznmQPnlList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQPnlList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "carrefwznmmcard"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->carRefWznmMCard = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refUref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQPnlList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQPnlList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQPnlList* rec;

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
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "carrefwznmmcard"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref")
		};

		while (numread < numrow) {
			rec = new WznmQPnlList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->carRefWznmMCard = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refUref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQPnlList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQPnlList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPnlList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPnlList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQPnlList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPnlList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQPnlList::loadRecBySQL(
			const string& sqlstr
			, WznmQPnlList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPnlList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPnlList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPnlList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPnlList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQPnlList::insertRec(
			WznmQPnlList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _carRefWznmMCard = htonl64(rec->carRefWznmMCard);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_carRefWznmMCard,
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPnlList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPnlList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQPnlList::insertRst(
			ListWznmQPnlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQPnlList::updateRec(
			WznmQPnlList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _carRefWznmMCard = htonl64(rec->carRefWznmMCard);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_carRefWznmMCard,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPnlList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPnlList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPnlList::updateRst(
			ListWznmQPnlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQPnlList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQPnlList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPnlList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPnlList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQPnlList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPnlList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQPnlList::loadRecByQref(
			ubigint qref
			, WznmQPnlList** rec
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

	return loadRecByStmt("TblWznmQPnlList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQPnlList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPnlList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQPnlList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

