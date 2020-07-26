/**
	* \file WznmQSteAStep.cpp
	* Dbs and XML wrapper for table TblWznmQSteAStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQSteAStep.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteAStep
 ******************************************************************************/

WznmQSteAStep::WznmQSteAStep(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint snxRefWznmMState
			, const string stubSnxRefWznmMState
			, const uint ixVTrigger
			, const string srefIxVTrigger
			, const string titIxVTrigger
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const bool Custcode
			, const string yesnoCustcode
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->snxRefWznmMState = snxRefWznmMState;
	this->stubSnxRefWznmMState = stubSnxRefWznmMState;
	this->ixVTrigger = ixVTrigger;
	this->srefIxVTrigger = srefIxVTrigger;
	this->titIxVTrigger = titIxVTrigger;
	this->refWznmMRtjob = refWznmMRtjob;
	this->stubRefWznmMRtjob = stubRefWznmMRtjob;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->xsref = xsref;
	this->refWznmMRtdpch = refWznmMRtdpch;
	this->stubRefWznmMRtdpch = stubRefWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
	this->Custcode = Custcode;
	this->yesnoCustcode = yesnoCustcode;
};

void WznmQSteAStep::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSteAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "snx", stubSnxRefWznmMState);
		writeString(wr, "trg", srefIxVTrigger);
		writeString(wr, "trg2", titIxVTrigger);
		writeString(wr, "rtj", stubRefWznmMRtjob);
		writeString(wr, "vit", stubRefWznmMVectoritem);
		writeString(wr, "xsr", xsref);
		writeString(wr, "rtd", stubRefWznmMRtdpch);
		writeString(wr, "msk", srefsMask);
		writeString(wr, "cnd", Cond);
		writeString(wr, "ccd", yesnoCustcode);
	} else {
		writeString(wr, "stubSnxRefWznmMState", stubSnxRefWznmMState);
		writeString(wr, "srefIxVTrigger", srefIxVTrigger);
		writeString(wr, "titIxVTrigger", titIxVTrigger);
		writeString(wr, "stubRefWznmMRtjob", stubRefWznmMRtjob);
		writeString(wr, "stubRefWznmMVectoritem", stubRefWznmMVectoritem);
		writeString(wr, "xsref", xsref);
		writeString(wr, "stubRefWznmMRtdpch", stubRefWznmMRtdpch);
		writeString(wr, "srefsMask", srefsMask);
		writeString(wr, "Cond", Cond);
		writeString(wr, "yesnoCustcode", yesnoCustcode);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQSteAStep
 ******************************************************************************/

ListWznmQSteAStep::ListWznmQSteAStep() {
};

ListWznmQSteAStep::ListWznmQSteAStep(
			const ListWznmQSteAStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteAStep(*(src.nodes[i]));
};

ListWznmQSteAStep::~ListWznmQSteAStep() {
	clear();
};

void ListWznmQSteAStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSteAStep::size() const {
	return(nodes.size());
};

void ListWznmQSteAStep::append(
			WznmQSteAStep* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSteAStep& ListWznmQSteAStep::operator=(
			const ListWznmQSteAStep& src
		) {
	WznmQSteAStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSteAStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSteAStep::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSteAStep";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSteAStep
 ******************************************************************************/

TblWznmQSteAStep::TblWznmQSteAStep() {
};

TblWznmQSteAStep::~TblWznmQSteAStep() {
};

bool TblWznmQSteAStep::loadRecBySQL(
			const string& sqlstr
			, WznmQSteAStep** rec
		) {
	return false;
};

ubigint TblWznmQSteAStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	return 0;
};

ubigint TblWznmQSteAStep::insertRec(
			WznmQSteAStep* rec
		) {
	return 0;
};

ubigint TblWznmQSteAStep::insertNewRec(
			WznmQSteAStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint snxRefWznmMState
			, const string stubSnxRefWznmMState
			, const uint ixVTrigger
			, const string srefIxVTrigger
			, const string titIxVTrigger
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const bool Custcode
			, const string yesnoCustcode
		) {
	ubigint retval = 0;
	WznmQSteAStep* _rec = NULL;

	_rec = new WznmQSteAStep(0, jref, jnum, ref, snxRefWznmMState, stubSnxRefWznmMState, ixVTrigger, srefIxVTrigger, titIxVTrigger, refWznmMRtjob, stubRefWznmMRtjob, refWznmMVectoritem, stubRefWznmMVectoritem, xsref, refWznmMRtdpch, stubRefWznmMRtdpch, srefsMask, Cond, Custcode, yesnoCustcode);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSteAStep::appendNewRecToRst(
			ListWznmQSteAStep& rst
			, WznmQSteAStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint snxRefWznmMState
			, const string stubSnxRefWznmMState
			, const uint ixVTrigger
			, const string srefIxVTrigger
			, const string titIxVTrigger
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const ubigint refWznmMRtdpch
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const bool Custcode
			, const string yesnoCustcode
		) {
	ubigint retval = 0;
	WznmQSteAStep* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, snxRefWznmMState, stubSnxRefWznmMState, ixVTrigger, srefIxVTrigger, titIxVTrigger, refWznmMRtjob, stubRefWznmMRtjob, refWznmMVectoritem, stubRefWznmMVectoritem, xsref, refWznmMRtdpch, stubRefWznmMRtdpch, srefsMask, Cond, Custcode, yesnoCustcode);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSteAStep::insertRst(
			ListWznmQSteAStep& rst
		) {
};

void TblWznmQSteAStep::updateRec(
			WznmQSteAStep* rec
		) {
};

void TblWznmQSteAStep::updateRst(
			ListWznmQSteAStep& rst
		) {
};

void TblWznmQSteAStep::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSteAStep::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSteAStep::loadRecByQref(
			ubigint qref
			, WznmQSteAStep** rec
		) {
	return false;
};

ubigint TblWznmQSteAStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSteAStep
 ******************************************************************************/

MyTblWznmQSteAStep::MyTblWznmQSteAStep() :
			TblWznmQSteAStep()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSteAStep::~MyTblWznmQSteAStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSteAStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSteAStep (jref, jnum, ref, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSteAStep SET jref = ?, jnum = ?, ref = ?, snxRefWznmMState = ?, ixVTrigger = ?, refWznmMRtjob = ?, refWznmMVectoritem = ?, xsref = ?, refWznmMRtdpch = ?, srefsMask = ?, Cond = ?, Custcode = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSteAStep WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSteAStep WHERE jref = ?", false);
};

bool MyTblWznmQSteAStep::loadRecBySQL(
			const string& sqlstr
			, WznmQSteAStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSteAStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSteAStep::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSteAStep::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQSteAStep();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->snxRefWznmMState = atoll((char*) dbrow[4]); else _rec->snxRefWznmMState = 0;
		if (dbrow[5]) _rec->ixVTrigger = atol((char*) dbrow[5]); else _rec->ixVTrigger = 0;
		if (dbrow[6]) _rec->refWznmMRtjob = atoll((char*) dbrow[6]); else _rec->refWznmMRtjob = 0;
		if (dbrow[7]) _rec->refWznmMVectoritem = atoll((char*) dbrow[7]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[8]) _rec->xsref.assign(dbrow[8], dblengths[8]); else _rec->xsref = "";
		if (dbrow[9]) _rec->refWznmMRtdpch = atoll((char*) dbrow[9]); else _rec->refWznmMRtdpch = 0;
		if (dbrow[10]) _rec->srefsMask.assign(dbrow[10], dblengths[10]); else _rec->srefsMask = "";
		if (dbrow[11]) _rec->Cond.assign(dbrow[11], dblengths[11]); else _rec->Cond = "";
		if (dbrow[12]) _rec->Custcode = (atoi((char*) dbrow[12]) != 0); else _rec->Custcode = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSteAStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSteAStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSteAStep::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSteAStep::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQSteAStep();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->snxRefWznmMState = atoll((char*) dbrow[4]); else rec->snxRefWznmMState = 0;
			if (dbrow[5]) rec->ixVTrigger = atol((char*) dbrow[5]); else rec->ixVTrigger = 0;
			if (dbrow[6]) rec->refWznmMRtjob = atoll((char*) dbrow[6]); else rec->refWznmMRtjob = 0;
			if (dbrow[7]) rec->refWznmMVectoritem = atoll((char*) dbrow[7]); else rec->refWznmMVectoritem = 0;
			if (dbrow[8]) rec->xsref.assign(dbrow[8], dblengths[8]); else rec->xsref = "";
			if (dbrow[9]) rec->refWznmMRtdpch = atoll((char*) dbrow[9]); else rec->refWznmMRtdpch = 0;
			if (dbrow[10]) rec->srefsMask.assign(dbrow[10], dblengths[10]); else rec->srefsMask = "";
			if (dbrow[11]) rec->Cond.assign(dbrow[11], dblengths[11]); else rec->Cond = "";
			if (dbrow[12]) rec->Custcode = (atoi((char*) dbrow[12]) != 0); else rec->Custcode = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSteAStep::insertRec(
			WznmQSteAStep* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[7] = rec->xsref.length();
	l[9] = rec->srefsMask.length();
	l[10] = rec->Cond.length();
	tinyint Custcode = rec->Custcode;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->snxRefWznmMState,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVTrigger,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMRtjob,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindTinyint(&Custcode,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSteAStep::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSteAStep::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSteAStep::insertRst(
			ListWznmQSteAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSteAStep::updateRec(
			WznmQSteAStep* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[7] = rec->xsref.length();
	l[9] = rec->srefsMask.length();
	l[10] = rec->Cond.length();
	tinyint Custcode = rec->Custcode;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->snxRefWznmMState,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVTrigger,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMRtjob,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMRtdpch,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Cond.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindTinyint(&Custcode,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->qref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSteAStep::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSteAStep::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSteAStep::updateRst(
			ListWznmQSteAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSteAStep::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSteAStep::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSteAStep::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSteAStep::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSteAStep::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSteAStep::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSteAStep::loadRecByQref(
			ubigint qref
			, WznmQSteAStep** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSteAStep WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSteAStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSteAStep WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSteAStep
 ******************************************************************************/

PgTblWznmQSteAStep::PgTblWznmQSteAStep() :
			TblWznmQSteAStep()
			, PgTable()
		{
};

PgTblWznmQSteAStep::~PgTblWznmQSteAStep() {
};

void PgTblWznmQSteAStep::initStatements() {
	createStatement("TblWznmQSteAStep_insertRec", "INSERT INTO TblWznmQSteAStep (jref, jnum, ref, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING qref", 12);
	createStatement("TblWznmQSteAStep_updateRec", "UPDATE TblWznmQSteAStep SET jref = $1, jnum = $2, ref = $3, snxRefWznmMState = $4, ixVTrigger = $5, refWznmMRtjob = $6, refWznmMVectoritem = $7, xsref = $8, refWznmMRtdpch = $9, srefsMask = $10, Cond = $11, Custcode = $12 WHERE qref = $13", 13);
	createStatement("TblWznmQSteAStep_removeRecByQref", "DELETE FROM TblWznmQSteAStep WHERE qref = $1", 1);
	createStatement("TblWznmQSteAStep_removeRstByJref", "DELETE FROM TblWznmQSteAStep WHERE jref = $1", 1);

	createStatement("TblWznmQSteAStep_loadRecByQref", "SELECT qref, jref, jnum, ref, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode FROM TblWznmQSteAStep WHERE qref = $1", 1);
	createStatement("TblWznmQSteAStep_loadRstByJref", "SELECT qref, jref, jnum, ref, snxRefWznmMState, ixVTrigger, refWznmMRtjob, refWznmMVectoritem, xsref, refWznmMRtdpch, srefsMask, Cond, Custcode FROM TblWznmQSteAStep WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSteAStep::loadRec(
			PGresult* res
			, WznmQSteAStep** rec
		) {
	char* ptr;

	WznmQSteAStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSteAStep();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "ixvtrigger"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond"),
			PQfnumber(res, "custcode")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->snxRefWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVTrigger = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->xsref.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMRtdpch = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefsMask.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Cond.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Custcode = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSteAStep::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSteAStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "ixvtrigger"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "xsref"),
			PQfnumber(res, "refwznmmrtdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "cond"),
			PQfnumber(res, "custcode")
		};

		while (numread < numrow) {
			rec = new WznmQSteAStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->snxRefWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVTrigger = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->xsref.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMRtdpch = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefsMask.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Cond.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Custcode = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSteAStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSteAStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteAStep::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSteAStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteAStep::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSteAStep::loadRecBySQL(
			const string& sqlstr
			, WznmQSteAStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSteAStep::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSteAStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSteAStep::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSteAStep::insertRec(
			WznmQSteAStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	uint _ixVTrigger = htonl(rec->ixVTrigger);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);
	smallint _Custcode = htons((smallint) rec->Custcode);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_snxRefWznmMState,
		(char*) &_ixVTrigger,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str(),
		(char*) &_Custcode
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQSteAStep_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteAStep::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSteAStep::insertRst(
			ListWznmQSteAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSteAStep::updateRec(
			WznmQSteAStep* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	uint _ixVTrigger = htonl(rec->ixVTrigger);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _refWznmMRtdpch = htonl64(rec->refWznmMRtdpch);
	smallint _Custcode = htons((smallint) rec->Custcode);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_snxRefWznmMState,
		(char*) &_ixVTrigger,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVectoritem,
		rec->xsref.c_str(),
		(char*) &_refWznmMRtdpch,
		rec->srefsMask.c_str(),
		rec->Cond.c_str(),
		(char*) &_Custcode,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQSteAStep_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteAStep::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSteAStep::updateRst(
			ListWznmQSteAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSteAStep::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSteAStep_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteAStep::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSteAStep::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSteAStep_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteAStep::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSteAStep::loadRecByQref(
			ubigint qref
			, WznmQSteAStep** rec
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

	return loadRecByStmt("TblWznmQSteAStep_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSteAStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteAStep& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSteAStep_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

