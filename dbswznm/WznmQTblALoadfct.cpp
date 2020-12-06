/**
	* \file WznmQTblALoadfct.cpp
	* Dbs and XML wrapper for table TblWznmQTblALoadfct (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblALoadfct.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblALoadfct
 ******************************************************************************/

WznmQTblALoadfct::WznmQTblALoadfct(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVLoadtype
			, const string srefIxVLoadtype
			, const string titIxVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const uint ixVLimtype
			, const string srefIxVLimtype
			, const string titIxVLimtype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->ixVLoadtype = ixVLoadtype;
	this->srefIxVLoadtype = srefIxVLoadtype;
	this->titIxVLoadtype = titIxVLoadtype;
	this->Fctname = Fctname;
	this->ldSrefWznmMTablecol = ldSrefWznmMTablecol;
	this->lbySrefsWznmMTablecol = lbySrefsWznmMTablecol;
	this->ordSrefsWznmMTablecol = ordSrefsWznmMTablecol;
	this->ixVLimtype = ixVLimtype;
	this->srefIxVLimtype = srefIxVLimtype;
	this->titIxVLimtype = titIxVLimtype;
};

void WznmQTblALoadfct::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTblALoadfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "lot", srefIxVLoadtype);
		writeString(wr, "lot2", titIxVLoadtype);
		writeString(wr, "fna", Fctname);
		writeString(wr, "ldx", ldSrefWznmMTablecol);
		writeString(wr, "lby", lbySrefsWznmMTablecol);
		writeString(wr, "ord", ordSrefsWznmMTablecol);
		writeString(wr, "lit", srefIxVLimtype);
		writeString(wr, "lit2", titIxVLimtype);
	} else {
		writeString(wr, "srefIxVLoadtype", srefIxVLoadtype);
		writeString(wr, "titIxVLoadtype", titIxVLoadtype);
		writeString(wr, "Fctname", Fctname);
		writeString(wr, "ldSrefWznmMTablecol", ldSrefWznmMTablecol);
		writeString(wr, "lbySrefsWznmMTablecol", lbySrefsWznmMTablecol);
		writeString(wr, "ordSrefsWznmMTablecol", ordSrefsWznmMTablecol);
		writeString(wr, "srefIxVLimtype", srefIxVLimtype);
		writeString(wr, "titIxVLimtype", titIxVLimtype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQTblALoadfct
 ******************************************************************************/

ListWznmQTblALoadfct::ListWznmQTblALoadfct() {
};

ListWznmQTblALoadfct::ListWznmQTblALoadfct(
			const ListWznmQTblALoadfct& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblALoadfct(*(src.nodes[i]));
};

ListWznmQTblALoadfct::~ListWznmQTblALoadfct() {
	clear();
};

void ListWznmQTblALoadfct::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTblALoadfct::size() const {
	return(nodes.size());
};

void ListWznmQTblALoadfct::append(
			WznmQTblALoadfct* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTblALoadfct& ListWznmQTblALoadfct::operator=(
			const ListWznmQTblALoadfct& src
		) {
	WznmQTblALoadfct* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTblALoadfct(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTblALoadfct::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTblALoadfct";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTblALoadfct
 ******************************************************************************/

TblWznmQTblALoadfct::TblWznmQTblALoadfct() {
};

TblWznmQTblALoadfct::~TblWznmQTblALoadfct() {
};

bool TblWznmQTblALoadfct::loadRecBySQL(
			const string& sqlstr
			, WznmQTblALoadfct** rec
		) {
	return false;
};

ubigint TblWznmQTblALoadfct::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	return 0;
};

ubigint TblWznmQTblALoadfct::insertRec(
			WznmQTblALoadfct* rec
		) {
	return 0;
};

ubigint TblWznmQTblALoadfct::insertNewRec(
			WznmQTblALoadfct** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVLoadtype
			, const string srefIxVLoadtype
			, const string titIxVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const uint ixVLimtype
			, const string srefIxVLimtype
			, const string titIxVLimtype
		) {
	ubigint retval = 0;
	WznmQTblALoadfct* _rec = NULL;

	_rec = new WznmQTblALoadfct(0, jref, jnum, ref, ixVLoadtype, srefIxVLoadtype, titIxVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype, srefIxVLimtype, titIxVLimtype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTblALoadfct::appendNewRecToRst(
			ListWznmQTblALoadfct& rst
			, WznmQTblALoadfct** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVLoadtype
			, const string srefIxVLoadtype
			, const string titIxVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const uint ixVLimtype
			, const string srefIxVLimtype
			, const string titIxVLimtype
		) {
	ubigint retval = 0;
	WznmQTblALoadfct* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, ixVLoadtype, srefIxVLoadtype, titIxVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype, srefIxVLimtype, titIxVLimtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTblALoadfct::insertRst(
			ListWznmQTblALoadfct& rst
		) {
};

void TblWznmQTblALoadfct::updateRec(
			WznmQTblALoadfct* rec
		) {
};

void TblWznmQTblALoadfct::updateRst(
			ListWznmQTblALoadfct& rst
		) {
};

void TblWznmQTblALoadfct::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTblALoadfct::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTblALoadfct::loadRecByQref(
			ubigint qref
			, WznmQTblALoadfct** rec
		) {
	return false;
};

ubigint TblWznmQTblALoadfct::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTblALoadfct
 ******************************************************************************/

MyTblWznmQTblALoadfct::MyTblWznmQTblALoadfct() :
			TblWznmQTblALoadfct()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTblALoadfct::~MyTblWznmQTblALoadfct() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTblALoadfct::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTblALoadfct (jref, jnum, ref, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTblALoadfct SET jref = ?, jnum = ?, ref = ?, ixVLoadtype = ?, Fctname = ?, ldSrefWznmMTablecol = ?, lbySrefsWznmMTablecol = ?, ordSrefsWznmMTablecol = ?, ixVLimtype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTblALoadfct WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTblALoadfct WHERE jref = ?", false);
};

bool MyTblWznmQTblALoadfct::loadRecBySQL(
			const string& sqlstr
			, WznmQTblALoadfct** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTblALoadfct* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblALoadfct::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblALoadfct::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQTblALoadfct();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->ixVLoadtype = atol((char*) dbrow[4]); else _rec->ixVLoadtype = 0;
		if (dbrow[5]) _rec->Fctname.assign(dbrow[5], dblengths[5]); else _rec->Fctname = "";
		if (dbrow[6]) _rec->ldSrefWznmMTablecol.assign(dbrow[6], dblengths[6]); else _rec->ldSrefWznmMTablecol = "";
		if (dbrow[7]) _rec->lbySrefsWznmMTablecol.assign(dbrow[7], dblengths[7]); else _rec->lbySrefsWznmMTablecol = "";
		if (dbrow[8]) _rec->ordSrefsWznmMTablecol.assign(dbrow[8], dblengths[8]); else _rec->ordSrefsWznmMTablecol = "";
		if (dbrow[9]) _rec->ixVLimtype = atol((char*) dbrow[9]); else _rec->ixVLimtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQTblALoadfct::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTblALoadfct* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblALoadfct::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblALoadfct::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQTblALoadfct();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->ixVLoadtype = atol((char*) dbrow[4]); else rec->ixVLoadtype = 0;
			if (dbrow[5]) rec->Fctname.assign(dbrow[5], dblengths[5]); else rec->Fctname = "";
			if (dbrow[6]) rec->ldSrefWznmMTablecol.assign(dbrow[6], dblengths[6]); else rec->ldSrefWznmMTablecol = "";
			if (dbrow[7]) rec->lbySrefsWznmMTablecol.assign(dbrow[7], dblengths[7]); else rec->lbySrefsWznmMTablecol = "";
			if (dbrow[8]) rec->ordSrefsWznmMTablecol.assign(dbrow[8], dblengths[8]); else rec->ordSrefsWznmMTablecol = "";
			if (dbrow[9]) rec->ixVLimtype = atol((char*) dbrow[9]); else rec->ixVLimtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQTblALoadfct::insertRec(
			WznmQTblALoadfct* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->Fctname.length();
	l[5] = rec->ldSrefWznmMTablecol.length();
	l[6] = rec->lbySrefsWznmMTablecol.length();
	l[7] = rec->ordSrefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVLoadtype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fctname.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->ldSrefWznmMTablecol.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->lbySrefsWznmMTablecol.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->ordSrefsWznmMTablecol.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVLimtype,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTblALoadfct::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTblALoadfct::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTblALoadfct::insertRst(
			ListWznmQTblALoadfct& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTblALoadfct::updateRec(
			WznmQTblALoadfct* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->Fctname.length();
	l[5] = rec->ldSrefWznmMTablecol.length();
	l[6] = rec->lbySrefsWznmMTablecol.length();
	l[7] = rec->ordSrefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVLoadtype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fctname.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->ldSrefWznmMTablecol.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->lbySrefsWznmMTablecol.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->ordSrefsWznmMTablecol.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVLimtype,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTblALoadfct::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTblALoadfct::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblALoadfct::updateRst(
			ListWznmQTblALoadfct& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTblALoadfct::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTblALoadfct::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTblALoadfct::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblALoadfct::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTblALoadfct::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTblALoadfct::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTblALoadfct::loadRecByQref(
			ubigint qref
			, WznmQTblALoadfct** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTblALoadfct WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTblALoadfct::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTblALoadfct WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTblALoadfct
 ******************************************************************************/

PgTblWznmQTblALoadfct::PgTblWznmQTblALoadfct() :
			TblWznmQTblALoadfct()
			, PgTable()
		{
};

PgTblWznmQTblALoadfct::~PgTblWznmQTblALoadfct() {
};

void PgTblWznmQTblALoadfct::initStatements() {
	createStatement("TblWznmQTblALoadfct_insertRec", "INSERT INTO TblWznmQTblALoadfct (jref, jnum, ref, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWznmQTblALoadfct_updateRec", "UPDATE TblWznmQTblALoadfct SET jref = $1, jnum = $2, ref = $3, ixVLoadtype = $4, Fctname = $5, ldSrefWznmMTablecol = $6, lbySrefsWznmMTablecol = $7, ordSrefsWznmMTablecol = $8, ixVLimtype = $9 WHERE qref = $10", 10);
	createStatement("TblWznmQTblALoadfct_removeRecByQref", "DELETE FROM TblWznmQTblALoadfct WHERE qref = $1", 1);
	createStatement("TblWznmQTblALoadfct_removeRstByJref", "DELETE FROM TblWznmQTblALoadfct WHERE jref = $1", 1);

	createStatement("TblWznmQTblALoadfct_loadRecByQref", "SELECT qref, jref, jnum, ref, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype FROM TblWznmQTblALoadfct WHERE qref = $1", 1);
	createStatement("TblWznmQTblALoadfct_loadRstByJref", "SELECT qref, jref, jnum, ref, ixVLoadtype, Fctname, ldSrefWznmMTablecol, lbySrefsWznmMTablecol, ordSrefsWznmMTablecol, ixVLimtype FROM TblWznmQTblALoadfct WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTblALoadfct::loadRec(
			PGresult* res
			, WznmQTblALoadfct** rec
		) {
	char* ptr;

	WznmQTblALoadfct* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTblALoadfct();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvloadtype"),
			PQfnumber(res, "fctname"),
			PQfnumber(res, "ldsrefwznmmtablecol"),
			PQfnumber(res, "lbysrefswznmmtablecol"),
			PQfnumber(res, "ordsrefswznmmtablecol"),
			PQfnumber(res, "ixvlimtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVLoadtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fctname.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ldSrefWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->lbySrefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ordSrefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVLimtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQTblALoadfct::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTblALoadfct* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvloadtype"),
			PQfnumber(res, "fctname"),
			PQfnumber(res, "ldsrefwznmmtablecol"),
			PQfnumber(res, "lbysrefswznmmtablecol"),
			PQfnumber(res, "ordsrefswznmmtablecol"),
			PQfnumber(res, "ixvlimtype")
		};

		while (numread < numrow) {
			rec = new WznmQTblALoadfct();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVLoadtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fctname.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ldSrefWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->lbySrefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ordSrefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVLimtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQTblALoadfct::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTblALoadfct** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblALoadfct::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblALoadfct::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblALoadfct::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTblALoadfct::loadRecBySQL(
			const string& sqlstr
			, WznmQTblALoadfct** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblALoadfct::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblALoadfct::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblALoadfct::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTblALoadfct::insertRec(
			WznmQTblALoadfct* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVLoadtype = htonl(rec->ixVLoadtype);
	uint _ixVLimtype = htonl(rec->ixVLimtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_ixVLoadtype,
		rec->Fctname.c_str(),
		rec->ldSrefWznmMTablecol.c_str(),
		rec->lbySrefsWznmMTablecol.c_str(),
		rec->ordSrefsWznmMTablecol.c_str(),
		(char*) &_ixVLimtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQTblALoadfct_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblALoadfct::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTblALoadfct::insertRst(
			ListWznmQTblALoadfct& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTblALoadfct::updateRec(
			WznmQTblALoadfct* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVLoadtype = htonl(rec->ixVLoadtype);
	uint _ixVLimtype = htonl(rec->ixVLimtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_ixVLoadtype,
		rec->Fctname.c_str(),
		rec->ldSrefWznmMTablecol.c_str(),
		rec->lbySrefsWznmMTablecol.c_str(),
		rec->ordSrefsWznmMTablecol.c_str(),
		(char*) &_ixVLimtype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQTblALoadfct_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblALoadfct::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblALoadfct::updateRst(
			ListWznmQTblALoadfct& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTblALoadfct::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblALoadfct_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblALoadfct::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblALoadfct::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblALoadfct_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblALoadfct::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTblALoadfct::loadRecByQref(
			ubigint qref
			, WznmQTblALoadfct** rec
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

	return loadRecByStmt("TblWznmQTblALoadfct_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTblALoadfct::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblALoadfct& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTblALoadfct_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
