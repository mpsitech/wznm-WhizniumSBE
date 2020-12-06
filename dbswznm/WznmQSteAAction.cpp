/**
	* \file WznmQSteAAction.cpp
	* Dbs and XML wrapper for table TblWznmQSteAAction (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSteAAction.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteAAction
 ******************************************************************************/

WznmQSteAAction::WznmQSteAAction(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint steNum
			, const uint ixVSection
			, const string srefIxVSection
			, const string titIxVSection
			, const uint ixVType
			, const string srefIxVType
			, const string titIxVType
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const ubigint snxRefWznmMState
			, const string stubSnxRefWznmMState
			, const ubigint refWznmMSequence
			, const string stubRefWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->steNum = steNum;
	this->ixVSection = ixVSection;
	this->srefIxVSection = srefIxVSection;
	this->titIxVSection = titIxVSection;
	this->ixVType = ixVType;
	this->srefIxVType = srefIxVType;
	this->titIxVType = titIxVType;
	this->refWznmMRtjob = refWznmMRtjob;
	this->stubRefWznmMRtjob = stubRefWznmMRtjob;
	this->refWznmMVector = refWznmMVector;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->snxRefWznmMState = snxRefWznmMState;
	this->stubSnxRefWznmMState = stubSnxRefWznmMState;
	this->refWznmMSequence = refWznmMSequence;
	this->stubRefWznmMSequence = stubRefWznmMSequence;
	this->tr1SrefATrig = tr1SrefATrig;
	this->Ip1 = Ip1;
	this->tr2SrefATrig = tr2SrefATrig;
	this->Ip2 = Ip2;
	this->tr3SrefATrig = tr3SrefATrig;
	this->Ip3 = Ip3;
	this->tr4SrefATrig = tr4SrefATrig;
	this->Ip4 = Ip4;
};

void WznmQSteAAction::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSteAAction";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "sct", srefIxVSection);
		writeString(wr, "sct2", titIxVSection);
		writeString(wr, "typ", srefIxVType);
		writeString(wr, "typ2", titIxVType);
		writeString(wr, "trj", stubRefWznmMRtjob);
		writeString(wr, "vec", stubRefWznmMVector);
		writeString(wr, "vit", stubRefWznmMVectoritem);
		writeString(wr, "snx", stubSnxRefWznmMState);
		writeString(wr, "seq", stubRefWznmMSequence);
		writeString(wr, "tr1", tr1SrefATrig);
		writeString(wr, "ip1", Ip1);
		writeString(wr, "tr2", tr2SrefATrig);
		writeString(wr, "ip2", Ip2);
		writeString(wr, "tr3", tr3SrefATrig);
		writeString(wr, "ip3", Ip3);
		writeString(wr, "tr4", tr4SrefATrig);
		writeString(wr, "ip4", Ip4);
	} else {
		writeString(wr, "srefIxVSection", srefIxVSection);
		writeString(wr, "titIxVSection", titIxVSection);
		writeString(wr, "srefIxVType", srefIxVType);
		writeString(wr, "titIxVType", titIxVType);
		writeString(wr, "stubRefWznmMRtjob", stubRefWznmMRtjob);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeString(wr, "stubRefWznmMVectoritem", stubRefWznmMVectoritem);
		writeString(wr, "stubSnxRefWznmMState", stubSnxRefWznmMState);
		writeString(wr, "stubRefWznmMSequence", stubRefWznmMSequence);
		writeString(wr, "tr1SrefATrig", tr1SrefATrig);
		writeString(wr, "Ip1", Ip1);
		writeString(wr, "tr2SrefATrig", tr2SrefATrig);
		writeString(wr, "Ip2", Ip2);
		writeString(wr, "tr3SrefATrig", tr3SrefATrig);
		writeString(wr, "Ip3", Ip3);
		writeString(wr, "tr4SrefATrig", tr4SrefATrig);
		writeString(wr, "Ip4", Ip4);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQSteAAction
 ******************************************************************************/

ListWznmQSteAAction::ListWznmQSteAAction() {
};

ListWznmQSteAAction::ListWznmQSteAAction(
			const ListWznmQSteAAction& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteAAction(*(src.nodes[i]));
};

ListWznmQSteAAction::~ListWznmQSteAAction() {
	clear();
};

void ListWznmQSteAAction::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSteAAction::size() const {
	return(nodes.size());
};

void ListWznmQSteAAction::append(
			WznmQSteAAction* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSteAAction& ListWznmQSteAAction::operator=(
			const ListWznmQSteAAction& src
		) {
	WznmQSteAAction* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSteAAction(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSteAAction::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSteAAction";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSteAAction
 ******************************************************************************/

TblWznmQSteAAction::TblWznmQSteAAction() {
};

TblWznmQSteAAction::~TblWznmQSteAAction() {
};

bool TblWznmQSteAAction::loadRecBySQL(
			const string& sqlstr
			, WznmQSteAAction** rec
		) {
	return false;
};

ubigint TblWznmQSteAAction::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	return 0;
};

ubigint TblWznmQSteAAction::insertRec(
			WznmQSteAAction* rec
		) {
	return 0;
};

ubigint TblWznmQSteAAction::insertNewRec(
			WznmQSteAAction** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint steNum
			, const uint ixVSection
			, const string srefIxVSection
			, const string titIxVSection
			, const uint ixVType
			, const string srefIxVType
			, const string titIxVType
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const ubigint snxRefWznmMState
			, const string stubSnxRefWznmMState
			, const ubigint refWznmMSequence
			, const string stubRefWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {
	ubigint retval = 0;
	WznmQSteAAction* _rec = NULL;

	_rec = new WznmQSteAAction(0, jref, jnum, ref, steNum, ixVSection, srefIxVSection, titIxVSection, ixVType, srefIxVType, titIxVType, refWznmMRtjob, stubRefWznmMRtjob, refWznmMVector, stubRefWznmMVector, refWznmMVectoritem, stubRefWznmMVectoritem, snxRefWznmMState, stubSnxRefWznmMState, refWznmMSequence, stubRefWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSteAAction::appendNewRecToRst(
			ListWznmQSteAAction& rst
			, WznmQSteAAction** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint steNum
			, const uint ixVSection
			, const string srefIxVSection
			, const string titIxVSection
			, const uint ixVType
			, const string srefIxVType
			, const string titIxVType
			, const ubigint refWznmMRtjob
			, const string stubRefWznmMRtjob
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
			, const ubigint snxRefWznmMState
			, const string stubSnxRefWznmMState
			, const ubigint refWznmMSequence
			, const string stubRefWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {
	ubigint retval = 0;
	WznmQSteAAction* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, steNum, ixVSection, srefIxVSection, titIxVSection, ixVType, srefIxVType, titIxVType, refWznmMRtjob, stubRefWznmMRtjob, refWznmMVector, stubRefWznmMVector, refWznmMVectoritem, stubRefWznmMVectoritem, snxRefWznmMState, stubSnxRefWznmMState, refWznmMSequence, stubRefWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSteAAction::insertRst(
			ListWznmQSteAAction& rst
		) {
};

void TblWznmQSteAAction::updateRec(
			WznmQSteAAction* rec
		) {
};

void TblWznmQSteAAction::updateRst(
			ListWznmQSteAAction& rst
		) {
};

void TblWznmQSteAAction::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSteAAction::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSteAAction::loadRecByQref(
			ubigint qref
			, WznmQSteAAction** rec
		) {
	return false;
};

ubigint TblWznmQSteAAction::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSteAAction
 ******************************************************************************/

MyTblWznmQSteAAction::MyTblWznmQSteAAction() :
			TblWznmQSteAAction()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSteAAction::~MyTblWznmQSteAAction() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSteAAction::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSteAAction (jref, jnum, ref, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSteAAction SET jref = ?, jnum = ?, ref = ?, steNum = ?, ixVSection = ?, ixVType = ?, refWznmMRtjob = ?, refWznmMVector = ?, refWznmMVectoritem = ?, snxRefWznmMState = ?, refWznmMSequence = ?, tr1SrefATrig = ?, Ip1 = ?, tr2SrefATrig = ?, Ip2 = ?, tr3SrefATrig = ?, Ip3 = ?, tr4SrefATrig = ?, Ip4 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSteAAction WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSteAAction WHERE jref = ?", false);
};

bool MyTblWznmQSteAAction::loadRecBySQL(
			const string& sqlstr
			, WznmQSteAAction** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSteAAction* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSteAAction::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSteAAction::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQSteAAction();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->steNum = atol((char*) dbrow[4]); else _rec->steNum = 0;
		if (dbrow[5]) _rec->ixVSection = atol((char*) dbrow[5]); else _rec->ixVSection = 0;
		if (dbrow[6]) _rec->ixVType = atol((char*) dbrow[6]); else _rec->ixVType = 0;
		if (dbrow[7]) _rec->refWznmMRtjob = atoll((char*) dbrow[7]); else _rec->refWznmMRtjob = 0;
		if (dbrow[8]) _rec->refWznmMVector = atoll((char*) dbrow[8]); else _rec->refWznmMVector = 0;
		if (dbrow[9]) _rec->refWznmMVectoritem = atoll((char*) dbrow[9]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[10]) _rec->snxRefWznmMState = atoll((char*) dbrow[10]); else _rec->snxRefWznmMState = 0;
		if (dbrow[11]) _rec->refWznmMSequence = atoll((char*) dbrow[11]); else _rec->refWznmMSequence = 0;
		if (dbrow[12]) _rec->tr1SrefATrig.assign(dbrow[12], dblengths[12]); else _rec->tr1SrefATrig = "";
		if (dbrow[13]) _rec->Ip1.assign(dbrow[13], dblengths[13]); else _rec->Ip1 = "";
		if (dbrow[14]) _rec->tr2SrefATrig.assign(dbrow[14], dblengths[14]); else _rec->tr2SrefATrig = "";
		if (dbrow[15]) _rec->Ip2.assign(dbrow[15], dblengths[15]); else _rec->Ip2 = "";
		if (dbrow[16]) _rec->tr3SrefATrig.assign(dbrow[16], dblengths[16]); else _rec->tr3SrefATrig = "";
		if (dbrow[17]) _rec->Ip3.assign(dbrow[17], dblengths[17]); else _rec->Ip3 = "";
		if (dbrow[18]) _rec->tr4SrefATrig.assign(dbrow[18], dblengths[18]); else _rec->tr4SrefATrig = "";
		if (dbrow[19]) _rec->Ip4.assign(dbrow[19], dblengths[19]); else _rec->Ip4 = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSteAAction::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSteAAction* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSteAAction::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSteAAction::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQSteAAction();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->steNum = atol((char*) dbrow[4]); else rec->steNum = 0;
			if (dbrow[5]) rec->ixVSection = atol((char*) dbrow[5]); else rec->ixVSection = 0;
			if (dbrow[6]) rec->ixVType = atol((char*) dbrow[6]); else rec->ixVType = 0;
			if (dbrow[7]) rec->refWznmMRtjob = atoll((char*) dbrow[7]); else rec->refWznmMRtjob = 0;
			if (dbrow[8]) rec->refWznmMVector = atoll((char*) dbrow[8]); else rec->refWznmMVector = 0;
			if (dbrow[9]) rec->refWznmMVectoritem = atoll((char*) dbrow[9]); else rec->refWznmMVectoritem = 0;
			if (dbrow[10]) rec->snxRefWznmMState = atoll((char*) dbrow[10]); else rec->snxRefWznmMState = 0;
			if (dbrow[11]) rec->refWznmMSequence = atoll((char*) dbrow[11]); else rec->refWznmMSequence = 0;
			if (dbrow[12]) rec->tr1SrefATrig.assign(dbrow[12], dblengths[12]); else rec->tr1SrefATrig = "";
			if (dbrow[13]) rec->Ip1.assign(dbrow[13], dblengths[13]); else rec->Ip1 = "";
			if (dbrow[14]) rec->tr2SrefATrig.assign(dbrow[14], dblengths[14]); else rec->tr2SrefATrig = "";
			if (dbrow[15]) rec->Ip2.assign(dbrow[15], dblengths[15]); else rec->Ip2 = "";
			if (dbrow[16]) rec->tr3SrefATrig.assign(dbrow[16], dblengths[16]); else rec->tr3SrefATrig = "";
			if (dbrow[17]) rec->Ip3.assign(dbrow[17], dblengths[17]); else rec->Ip3 = "";
			if (dbrow[18]) rec->tr4SrefATrig.assign(dbrow[18], dblengths[18]); else rec->tr4SrefATrig = "";
			if (dbrow[19]) rec->Ip4.assign(dbrow[19], dblengths[19]); else rec->Ip4 = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSteAAction::insertRec(
			WznmQSteAAction* rec
		) {
	unsigned long l[19]; my_bool n[19]; my_bool e[19];

	l[11] = rec->tr1SrefATrig.length();
	l[12] = rec->Ip1.length();
	l[13] = rec->tr2SrefATrig.length();
	l[14] = rec->Ip2.length();
	l[15] = rec->tr3SrefATrig.length();
	l[16] = rec->Ip3.length();
	l[17] = rec->tr4SrefATrig.length();
	l[18] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->steNum,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVSection,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVType,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMRtjob,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVector,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->snxRefWznmMState,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMSequence,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->tr1SrefATrig.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->tr2SrefATrig.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->tr3SrefATrig.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->tr4SrefATrig.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[18]),&(n[18]),&(e[18]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSteAAction::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSteAAction::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSteAAction::insertRst(
			ListWznmQSteAAction& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSteAAction::updateRec(
			WznmQSteAAction* rec
		) {
	unsigned long l[20]; my_bool n[20]; my_bool e[20];

	l[11] = rec->tr1SrefATrig.length();
	l[12] = rec->Ip1.length();
	l[13] = rec->tr2SrefATrig.length();
	l[14] = rec->Ip2.length();
	l[15] = rec->tr3SrefATrig.length();
	l[16] = rec->Ip3.length();
	l[17] = rec->tr4SrefATrig.length();
	l[18] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->steNum,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVSection,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVType,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMRtjob,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMVector,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->snxRefWznmMState,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMSequence,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->tr1SrefATrig.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->tr2SrefATrig.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->tr3SrefATrig.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->tr4SrefATrig.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[18]),&(n[18]),&(e[18])),
		bindUbigint(&rec->qref,&(l[19]),&(n[19]),&(e[19]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSteAAction::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSteAAction::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSteAAction::updateRst(
			ListWznmQSteAAction& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSteAAction::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSteAAction::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSteAAction::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSteAAction::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSteAAction::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSteAAction::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSteAAction::loadRecByQref(
			ubigint qref
			, WznmQSteAAction** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSteAAction WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSteAAction::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSteAAction WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSteAAction
 ******************************************************************************/

PgTblWznmQSteAAction::PgTblWznmQSteAAction() :
			TblWznmQSteAAction()
			, PgTable()
		{
};

PgTblWznmQSteAAction::~PgTblWznmQSteAAction() {
};

void PgTblWznmQSteAAction::initStatements() {
	createStatement("TblWznmQSteAAction_insertRec", "INSERT INTO TblWznmQSteAAction (jref, jnum, ref, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19) RETURNING qref", 19);
	createStatement("TblWznmQSteAAction_updateRec", "UPDATE TblWznmQSteAAction SET jref = $1, jnum = $2, ref = $3, steNum = $4, ixVSection = $5, ixVType = $6, refWznmMRtjob = $7, refWznmMVector = $8, refWznmMVectoritem = $9, snxRefWznmMState = $10, refWznmMSequence = $11, tr1SrefATrig = $12, Ip1 = $13, tr2SrefATrig = $14, Ip2 = $15, tr3SrefATrig = $16, Ip3 = $17, tr4SrefATrig = $18, Ip4 = $19 WHERE qref = $20", 20);
	createStatement("TblWznmQSteAAction_removeRecByQref", "DELETE FROM TblWznmQSteAAction WHERE qref = $1", 1);
	createStatement("TblWznmQSteAAction_removeRstByJref", "DELETE FROM TblWznmQSteAAction WHERE jref = $1", 1);

	createStatement("TblWznmQSteAAction_loadRecByQref", "SELECT qref, jref, jnum, ref, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4 FROM TblWznmQSteAAction WHERE qref = $1", 1);
	createStatement("TblWznmQSteAAction_loadRstByJref", "SELECT qref, jref, jnum, ref, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4 FROM TblWznmQSteAAction WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSteAAction::loadRec(
			PGresult* res
			, WznmQSteAAction** rec
		) {
	char* ptr;

	WznmQSteAAction* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSteAAction();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "stenum"),
			PQfnumber(res, "ixvsection"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "refwznmmsequence"),
			PQfnumber(res, "tr1srefatrig"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "tr2srefatrig"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "tr3srefatrig"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "tr4srefatrig"),
			PQfnumber(res, "ip4")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->steNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVSection = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->snxRefWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWznmMSequence = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->tr1SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Ip1.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->tr2SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->Ip2.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->tr3SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->Ip3.assign(ptr, PQgetlength(res, 0, fnum[17]));
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->tr4SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[18]));
		ptr = PQgetvalue(res, 0, fnum[19]); _rec->Ip4.assign(ptr, PQgetlength(res, 0, fnum[19]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSteAAction::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSteAAction* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "stenum"),
			PQfnumber(res, "ixvsection"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "refwznmmsequence"),
			PQfnumber(res, "tr1srefatrig"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "tr2srefatrig"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "tr3srefatrig"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "tr4srefatrig"),
			PQfnumber(res, "ip4")
		};

		while (numread < numrow) {
			rec = new WznmQSteAAction();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->steNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVSection = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->snxRefWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWznmMSequence = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->tr1SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Ip1.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->tr2SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->Ip2.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->tr3SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->Ip3.assign(ptr, PQgetlength(res, numread, fnum[17]));
			ptr = PQgetvalue(res, numread, fnum[18]); rec->tr4SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[18]));
			ptr = PQgetvalue(res, numread, fnum[19]); rec->Ip4.assign(ptr, PQgetlength(res, numread, fnum[19]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSteAAction::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSteAAction** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteAAction::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSteAAction::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteAAction::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSteAAction::loadRecBySQL(
			const string& sqlstr
			, WznmQSteAAction** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSteAAction::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSteAAction::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSteAAction::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSteAAction::insertRec(
			WznmQSteAAction* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _steNum = htonl(rec->steNum);
	uint _ixVSection = htonl(rec->ixVSection);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	ubigint _refWznmMSequence = htonl64(rec->refWznmMSequence);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_steNum,
		(char*) &_ixVSection,
		(char*) &_ixVType,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem,
		(char*) &_snxRefWznmMState,
		(char*) &_refWznmMSequence,
		rec->tr1SrefATrig.c_str(),
		rec->Ip1.c_str(),
		rec->tr2SrefATrig.c_str(),
		rec->Ip2.c_str(),
		rec->tr3SrefATrig.c_str(),
		rec->Ip3.c_str(),
		rec->tr4SrefATrig.c_str(),
		rec->Ip4.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQSteAAction_insertRec", 19, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSteAAction::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSteAAction::insertRst(
			ListWznmQSteAAction& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSteAAction::updateRec(
			WznmQSteAAction* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _steNum = htonl(rec->steNum);
	uint _ixVSection = htonl(rec->ixVSection);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	ubigint _refWznmMSequence = htonl64(rec->refWznmMSequence);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_steNum,
		(char*) &_ixVSection,
		(char*) &_ixVType,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem,
		(char*) &_snxRefWznmMState,
		(char*) &_refWznmMSequence,
		rec->tr1SrefATrig.c_str(),
		rec->Ip1.c_str(),
		rec->tr2SrefATrig.c_str(),
		rec->Ip2.c_str(),
		rec->tr3SrefATrig.c_str(),
		rec->Ip3.c_str(),
		rec->tr4SrefATrig.c_str(),
		rec->Ip4.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQSteAAction_updateRec", 20, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteAAction::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSteAAction::updateRst(
			ListWznmQSteAAction& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSteAAction::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSteAAction_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteAAction::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSteAAction::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSteAAction_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSteAAction::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSteAAction::loadRecByQref(
			ubigint qref
			, WznmQSteAAction** rec
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

	return loadRecByStmt("TblWznmQSteAAction_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSteAAction::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSteAAction& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSteAAction_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
