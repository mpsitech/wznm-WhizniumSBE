/**
	* \file WznmQSteATrig.cpp
	* Dbs and XML wrapper for table TblWznmQSteATrig (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQSteATrig.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteATrig
 ******************************************************************************/

WznmQSteATrig::WznmQSteATrig(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVType
			, const string srefIxVType
			, const string titIxVType
			, const ubigint refWznmMEvent
			, const string stubRefWznmMEvent
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVType = ixVType;
	this->srefIxVType = srefIxVType;
	this->titIxVType = titIxVType;
	this->refWznmMEvent = refWznmMEvent;
	this->stubRefWznmMEvent = stubRefWznmMEvent;
	this->refWznmMRtjob = refWznmMRtjob;
	this->stubRefWznmMRtjob = stubRefWznmMRtjob;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->xsref = xsref;
	this->refWznmMRtdpch = refWznmMRtdpch;
	this->stubRefWznmMRtdpch = stubRefWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
};

void WznmQSteATrig::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSteATrig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVType);
		writeString(wr, "typ2", titIxVType);
		writeString(wr, "evt", stubRefWznmMEvent);
		writeString(wr, "rtj", stubRefWznmMRtjob);
		writeString(wr, "vit", stubRefWznmMVectoritem);
		writeString(wr, "xsr", xsref);
		writeString(wr, "rtd", stubRefWznmMRtdpch);
		writeString(wr, "msk", srefsMask);
		writeString(wr, "cnd", Cond);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVType", srefIxVType);
		writeString(wr, "titIxVType", titIxVType);
		writeString(wr, "stubRefWznmMEvent", stubRefWznmMEvent);
		writeString(wr, "stubRefWznmMRtjob", stubRefWznmMRtjob);
		writeString(wr, "stubRefWznmMVectoritem", stubRefWznmMVectoritem);
		writeString(wr, "xsref", xsref);
		writeString(wr, "stubRefWznmMRtdpch", stubRefWznmMRtdpch);
		writeString(wr, "srefsMask", srefsMask);
		writeString(wr, "Cond", Cond);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQSteATrig
 ******************************************************************************/

ListWznmQSteATrig::ListWznmQSteATrig() {
};

ListWznmQSteATrig::ListWznmQSteATrig(
			const ListWznmQSteATrig& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteATrig(*(src.nodes[i]));
};

ListWznmQSteATrig::~ListWznmQSteATrig() {
	clear();
};

void ListWznmQSteATrig::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSteATrig::size() const {
	return(nodes.size());
};

void ListWznmQSteATrig::append(
			WznmQSteATrig* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSteATrig& ListWznmQSteATrig::operator=(
			const ListWznmQSteATrig& src
		) {
	WznmQSteATrig* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSteATrig(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSteATrig::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSteATrig";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSteATrig
 ******************************************************************************/

TblWznmQSteATrig::TblWznmQSteATrig() {
};

TblWznmQSteATrig::~TblWznmQSteATrig() {
};

bool TblWznmQSteATrig::loadRecBySQL(
			const string& sqlstr
			, WznmQSteATrig** rec
		) {
	return false;
};

ubigint TblWznmQSteATrig::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	return 0;
};

ubigint TblWznmQSteATrig::insertRec(
			WznmQSteATrig* rec
		) {
	return 0;
};

ubigint TblWznmQSteATrig::insertNewRec(
			WznmQSteATrig** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVType
			, const string srefIxVType
			, const string titIxVType
			, const ubigint refWznmMEvent
			, const string stubRefWznmMEvent
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) {
	ubigint retval = 0;
	WznmQSteATrig* _rec = NULL;

	_rec = new WznmQSteATrig(0, jref, jnum, ref, sref, ixVType, srefIxVType, titIxVType, refWznmMEvent, stubRefWznmMEvent, refWznmMRtjob, stubRefWznmMRtjob, refWznmMVectoritem, stubRefWznmMVectoritem, xsref, refWznmMRtdpch, stubRefWznmMRtdpch, srefsMask, Cond);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSteATrig::appendNewRecToRst(
			ListWznmQSteATrig& rst
			, WznmQSteATrig** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVType
			, const string srefIxVType
			, const string titIxVType
			, const ubigint refWznmMEvent
			, const string stubRefWznmMEvent
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) {
	ubigint retval = 0;
	WznmQSteATrig* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVType, srefIxVType, titIxVType, refWznmMEvent, stubRefWznmMEvent, refWznmMRtjob, stubRefWznmMRtjob, refWznmMVectoritem, stubRefWznmMVectoritem, xsref, refWznmMRtdpch, stubRefWznmMRtdpch, srefsMask, Cond);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSteATrig::insertRst(
			ListWznmQSteATrig& rst
		) {
};

void TblWznmQSteATrig::updateRec(
			WznmQSteATrig* rec
		) {
};

void TblWznmQSteATrig::updateRst(
			ListWznmQSteATrig& rst
		) {
};

void TblWznmQSteATrig::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSteATrig::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSteATrig::loadRecByQref(
			ubigint qref
			, WznmQSteATrig** rec
		) {
	return false;
};

ubigint TblWznmQSteATrig::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSteATrig
 ******************************************************************************/

MyTblWznmQSteATrig::MyTblWznmQSteATrig() :
			TblWznmQSteATrig()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSteATrig::~MyTblWznmQSteATrig() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSteATrig::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSteATrig (jref, jnum, ref, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSteATrig SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVType = ?, refWznmMEvent = ?, refWznmMRtjob = ?, refWznmMVectoritem = ?, xsref = ?, refWznmMRtdpch = ?, srefsMask = ?, Cond = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSteATrig WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSteATrig WHERE jref = ?", false);
};

bool MyTblWznmQSteATrig::loadRecBySQL(
			const string& sqlstr
			, WznmQSteATrig** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSteATrig* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSteATrig::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSteATrig::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQSteATrig();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVType = atol((char*) dbrow[5]); else _rec->ixVType = 0;
		if (dbrow[6]) _rec->refWznmMEvent = atoll((char*) dbrow[6]); else _rec->refWznmMEvent = 0;
		if (dbrow[7]) _rec->refWznmMRtjob = atoll((char*) dbrow[7]); else _rec->refWznmMRtjob = 0;
		if (dbrow[8]) _rec->refWznmMVectoritem = atoll((char*) dbrow[8]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[9]) _rec->xsref.assign(dbrow[9], dblengths[9]); else _rec->xsref = "";
		if (dbrow[10]) _rec->refWznmMRtdpch = atoll((char*) dbrow[10]); else _rec->refWznmMRtdpch = 0;
		if (dbrow[11]) _rec->srefsMask.assign(dbrow[11], dblengths[11]); else _rec->srefsMask = "";
		if (dbrow[12]) _rec->Cond.assign(dbrow[12], dblengths[12]); else _rec->Cond = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSteATrig::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSteATrig* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSteATrig::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSteATrig::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQSteATrig();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVType = atol((char*) dbrow[5]); else rec->ixVType = 0;
			if (dbrow[6]) rec->refWznmMEvent = atoll((char*) dbrow[6]); else rec->refWznmMEvent = 0;
			if (dbrow[7]) rec->refWznmMRtjob = atoll((char*) dbrow[7]); else rec->refWznmMRtjob = 0;
			if (dbrow[8]) rec->refWznmMVectoritem = atoll((char*) dbrow[8]); else rec->refWznmMVectoritem = 0;
			if (dbrow[9]) rec->xsref.assign(dbrow[9], dblengths[9]); else rec->xsref = "";
			if (dbrow[10]) rec->refWznmMRtdpch = atoll((char*) dbrow[10]); else rec->refWznmMRtdpch = 0;
			if (dbrow[11]) rec->srefsMask.assign(dbrow[11], dblengths[11]); else rec->srefsMask = "";
			if (dbrow[12]) rec->Cond.assign(dbrow[12], dblengths[12]); else rec->Cond = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSteATrig::insertRec(
			WznmQSteATrig* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();
	l[8] = rec->xsref.length();
	l[10] = rec->srefsMask.length();
	l[11] = rec->Cond.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVType,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMEvent,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMRtjob,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSteATrig::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSteATrig::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSteATrig::insertRst(
			ListWznmQSteATrig& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSteATrig::updateRec(
			WznmQSteATrig* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	l[8] = rec->xsref.length();
	l[10] = rec->srefsMask.length();
	l[11] = rec->Cond.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVType,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMEvent,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMRtjob,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->qref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSteATrig::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSteATrig::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSteATrig::updateRst(
			ListWznmQSteATrig& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSteATrig::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSteATrig::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSteATrig::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSteATrig::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSteATrig::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSteATrig::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSteATrig::loadRecByQref(
			ubigint qref
			, WznmQSteATrig** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSteATrig WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSteATrig::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSteATrig WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSteATrig
 ******************************************************************************/

PgTblWznmQSteATrig::PgTblWznmQSteATrig() :
			TblWznmQSteATrig()
			, PgTable()
		{
};

PgTblWznmQSteATrig::~PgTblWznmQSteATrig() {
};

void PgTblWznmQSteATrig::initStatements() {
	createStatement("TblWznmQSteATrig_insertRec", "INSERT INTO TblWznmQSteATrig (jref, jnum, ref, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING qref", 12);
	createStatement("TblWznmQSteATrig_updateRec", "UPDATE TblWznmQSteATrig SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVType = $5, refWznmMEvent = $6, refWznmMRtjob = $7, refWznmMVectoritem = $8, xsref = $9, refWznmMRtdpch = $10, srefsMask = $11, Cond = $12 WHERE qref = $13", 13);
	createStatement("TblWznmQSteATrig_removeRecByQref", "DELETE FROM TblWznmQSteATrig WHERE qref = $1", 1);
	createStatement("TblWznmQSteATrig_removeRstByJref", "DELETE FROM TblWznmQSteATrig WHERE jref = $1", 1);

	createStatement("TblWznmQSteATrig_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond FROM TblWznmQSteATrig WHERE qref = $1", 1);
	createStatement("TblWznmQSteATrig_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVType, refWznmMEvent, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond FROM TblWznmQSteATrig WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSteATrig::loadRec(
			PGresult* res
			, WznmQSteATrig** rec
		) {
	char* ptr;

	WznmQSteATrig* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSteATrig();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmevent"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMEvent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->xsref.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWznmMRtdpch = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->srefsMask.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Cond.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSteATrig::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSteATrig* rec;

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
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmevent"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond")
		};

		while (numread < numrow) {
			rec = new WznmQSteATrig();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMEvent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->xsref.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWznmMRtdpch = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->srefsMask.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Cond.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSteATrig::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSteATrig** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteATrig::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSteATrig::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteATrig::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSteATrig::loadRecBySQL(
			const string& sqlstr
			, WznmQSteATrig** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSteATrig::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSteATrig::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSteATrig::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSteATrig::insertRec(
			WznmQSteATrig* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMEvent = htonl64(rec->refWznmMEvent);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVType,
		(char*) &_refWznmMEvent,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQSteATrig_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteATrig::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSteATrig::insertRst(
			ListWznmQSteATrig& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSteATrig::updateRec(
			WznmQSteATrig* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMEvent = htonl64(rec->refWznmMEvent);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVType,
		(char*) &_refWznmMEvent,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQSteATrig_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteATrig::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSteATrig::updateRst(
			ListWznmQSteATrig& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSteATrig::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSteATrig_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteATrig::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSteATrig::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSteATrig_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteATrig::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSteATrig::loadRecByQref(
			ubigint qref
			, WznmQSteATrig** rec
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

	return loadRecByStmt("TblWznmQSteATrig_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSteATrig::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteATrig& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSteATrig_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

