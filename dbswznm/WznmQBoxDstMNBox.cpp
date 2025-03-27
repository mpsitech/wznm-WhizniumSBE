/**
	* \file WznmQBoxDstMNBox.cpp
	* Dbs and XML wrapper for table TblWznmQBoxDstMNBox (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQBoxDstMNBox.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBoxDstMNBox
 ******************************************************************************/

WznmQBoxDstMNBox::WznmQBoxDstMNBox(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, mref(mref)
			, stubMref(stubMref)
			, ref(ref)
			, orgClk(orgClk)
			, dstClk(dstClk)
			, Weight(Weight)
		{
};

void WznmQBoxDstMNBox::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["ocl"] = orgClk;
		me["dcl"] = dstClk;
		me["wgt"] = Weight;
	} else {
		me["stubMref"] = stubMref;
		me["orgClk"] = orgClk;
		me["dstClk"] = dstClk;
		me["Weight"] = Weight;
	};
};

void WznmQBoxDstMNBox::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQBoxDstMNBox";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeUint(wr, "ocl", orgClk);
		writeUint(wr, "dcl", dstClk);
		writeUint(wr, "wgt", Weight);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeUint(wr, "orgClk", orgClk);
		writeUint(wr, "dstClk", dstClk);
		writeUint(wr, "Weight", Weight);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQBoxDstMNBox
 ******************************************************************************/

ListWznmQBoxDstMNBox::ListWznmQBoxDstMNBox() {
};

ListWznmQBoxDstMNBox::ListWznmQBoxDstMNBox(
			const ListWznmQBoxDstMNBox& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxDstMNBox(*(src.nodes[i]));
};

ListWznmQBoxDstMNBox::~ListWznmQBoxDstMNBox() {
	clear();
};

void ListWznmQBoxDstMNBox::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQBoxDstMNBox::size() const {
	return(nodes.size());
};

void ListWznmQBoxDstMNBox::append(
			WznmQBoxDstMNBox* rec
		) {
	nodes.push_back(rec);
};

ListWznmQBoxDstMNBox& ListWznmQBoxDstMNBox::operator=(
			const ListWznmQBoxDstMNBox& src
		) {
	WznmQBoxDstMNBox* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQBoxDstMNBox(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQBoxDstMNBox::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQBoxDstMNBox";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQBoxDstMNBox::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQBoxDstMNBox";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQBoxDstMNBox
 ******************************************************************************/

TblWznmQBoxDstMNBox::TblWznmQBoxDstMNBox() {
};

TblWznmQBoxDstMNBox::~TblWznmQBoxDstMNBox() {
};

bool TblWznmQBoxDstMNBox::loadRecBySQL(
			const string& sqlstr
			, WznmQBoxDstMNBox** rec
		) {
	return false;
};

ubigint TblWznmQBoxDstMNBox::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	return 0;
};

ubigint TblWznmQBoxDstMNBox::insertRec(
			WznmQBoxDstMNBox* rec
		) {
	return 0;
};

ubigint TblWznmQBoxDstMNBox::insertNewRec(
			WznmQBoxDstMNBox** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
		) {
	ubigint retval = 0;
	WznmQBoxDstMNBox* _rec = NULL;

	_rec = new WznmQBoxDstMNBox(0, jref, jnum, mref, stubMref, ref, orgClk, dstClk, Weight);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQBoxDstMNBox::appendNewRecToRst(
			ListWznmQBoxDstMNBox& rst
			, WznmQBoxDstMNBox** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
		) {
	ubigint retval = 0;
	WznmQBoxDstMNBox* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, orgClk, dstClk, Weight);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQBoxDstMNBox::insertRst(
			ListWznmQBoxDstMNBox& rst
		) {
};

void TblWznmQBoxDstMNBox::updateRec(
			WznmQBoxDstMNBox* rec
		) {
};

void TblWznmQBoxDstMNBox::updateRst(
			ListWznmQBoxDstMNBox& rst
		) {
};

void TblWznmQBoxDstMNBox::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQBoxDstMNBox::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQBoxDstMNBox::loadRecByQref(
			ubigint qref
			, WznmQBoxDstMNBox** rec
		) {
	return false;
};

ubigint TblWznmQBoxDstMNBox::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQBoxDstMNBox
 ******************************************************************************/

MyTblWznmQBoxDstMNBox::MyTblWznmQBoxDstMNBox() :
			TblWznmQBoxDstMNBox()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQBoxDstMNBox::~MyTblWznmQBoxDstMNBox() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQBoxDstMNBox::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQBoxDstMNBox (jref, jnum, mref, ref, orgClk, dstClk, Weight) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQBoxDstMNBox SET jref = ?, jnum = ?, mref = ?, ref = ?, orgClk = ?, dstClk = ?, Weight = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQBoxDstMNBox WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQBoxDstMNBox WHERE jref = ?", false);
};

bool MyTblWznmQBoxDstMNBox::loadRecBySQL(
			const string& sqlstr
			, WznmQBoxDstMNBox** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQBoxDstMNBox* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBoxDstMNBox::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBoxDstMNBox::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQBoxDstMNBox();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->orgClk = atoi((char*) dbrow[5]); else _rec->orgClk = 0;
		if (dbrow[6]) _rec->dstClk = atoi((char*) dbrow[6]); else _rec->dstClk = 0;
		if (dbrow[7]) _rec->Weight = atoi((char*) dbrow[7]); else _rec->Weight = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQBoxDstMNBox::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQBoxDstMNBox* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBoxDstMNBox::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBoxDstMNBox::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQBoxDstMNBox();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->orgClk = atoi((char*) dbrow[5]); else rec->orgClk = 0;
			if (dbrow[6]) rec->dstClk = atoi((char*) dbrow[6]); else rec->dstClk = 0;
			if (dbrow[7]) rec->Weight = atoi((char*) dbrow[7]); else rec->Weight = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQBoxDstMNBox::insertRec(
			WznmQBoxDstMNBox* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUtinyint(&rec->orgClk,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->dstClk,&(l[5]),&(n[5]),&(e[5])),
		bindUtinyint(&rec->Weight,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQBoxDstMNBox::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQBoxDstMNBox::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQBoxDstMNBox::insertRst(
			ListWznmQBoxDstMNBox& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQBoxDstMNBox::updateRec(
			WznmQBoxDstMNBox* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUtinyint(&rec->orgClk,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->dstClk,&(l[5]),&(n[5]),&(e[5])),
		bindUtinyint(&rec->Weight,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQBoxDstMNBox::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQBoxDstMNBox::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBoxDstMNBox::updateRst(
			ListWznmQBoxDstMNBox& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQBoxDstMNBox::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQBoxDstMNBox::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQBoxDstMNBox::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBoxDstMNBox::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQBoxDstMNBox::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQBoxDstMNBox::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQBoxDstMNBox::loadRecByQref(
			ubigint qref
			, WznmQBoxDstMNBox** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQBoxDstMNBox WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQBoxDstMNBox::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQBoxDstMNBox WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQBoxDstMNBox
 ******************************************************************************/

PgTblWznmQBoxDstMNBox::PgTblWznmQBoxDstMNBox() :
			TblWznmQBoxDstMNBox()
			, PgTable()
		{
};

PgTblWznmQBoxDstMNBox::~PgTblWznmQBoxDstMNBox() {
};

void PgTblWznmQBoxDstMNBox::initStatements() {
	createStatement("TblWznmQBoxDstMNBox_insertRec", "INSERT INTO TblWznmQBoxDstMNBox (jref, jnum, mref, ref, orgClk, dstClk, Weight) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQBoxDstMNBox_updateRec", "UPDATE TblWznmQBoxDstMNBox SET jref = $1, jnum = $2, mref = $3, ref = $4, orgClk = $5, dstClk = $6, Weight = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQBoxDstMNBox_removeRecByQref", "DELETE FROM TblWznmQBoxDstMNBox WHERE qref = $1", 1);
	createStatement("TblWznmQBoxDstMNBox_removeRstByJref", "DELETE FROM TblWznmQBoxDstMNBox WHERE jref = $1", 1);

	createStatement("TblWznmQBoxDstMNBox_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, orgClk, dstClk, Weight FROM TblWznmQBoxDstMNBox WHERE qref = $1", 1);
	createStatement("TblWznmQBoxDstMNBox_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, orgClk, dstClk, Weight FROM TblWznmQBoxDstMNBox WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQBoxDstMNBox::loadRec(
			PGresult* res
			, WznmQBoxDstMNBox** rec
		) {
	char* ptr;

	WznmQBoxDstMNBox* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQBoxDstMNBox();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "orgclk"),
			PQfnumber(res, "dstclk"),
			PQfnumber(res, "weight")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->orgClk = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->dstClk = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Weight = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQBoxDstMNBox::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQBoxDstMNBox* rec;

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
			PQfnumber(res, "orgclk"),
			PQfnumber(res, "dstclk"),
			PQfnumber(res, "weight")
		};

		while (numread < numrow) {
			rec = new WznmQBoxDstMNBox();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->orgClk = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->dstClk = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Weight = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQBoxDstMNBox::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQBoxDstMNBox** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBoxDstMNBox::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBoxDstMNBox::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBoxDstMNBox::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQBoxDstMNBox::loadRecBySQL(
			const string& sqlstr
			, WznmQBoxDstMNBox** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBoxDstMNBox::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBoxDstMNBox::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBoxDstMNBox::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQBoxDstMNBox::insertRec(
			WznmQBoxDstMNBox* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	usmallint _orgClk = htons(rec->orgClk);
	usmallint _dstClk = htons(rec->dstClk);
	usmallint _Weight = htons(rec->Weight);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_orgClk,
		(char*) &_dstClk,
		(char*) &_Weight
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQBoxDstMNBox_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBoxDstMNBox::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQBoxDstMNBox::insertRst(
			ListWznmQBoxDstMNBox& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQBoxDstMNBox::updateRec(
			WznmQBoxDstMNBox* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	usmallint _orgClk = htons(rec->orgClk);
	usmallint _dstClk = htons(rec->dstClk);
	usmallint _Weight = htons(rec->Weight);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_orgClk,
		(char*) &_dstClk,
		(char*) &_Weight,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQBoxDstMNBox_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBoxDstMNBox::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBoxDstMNBox::updateRst(
			ListWznmQBoxDstMNBox& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQBoxDstMNBox::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQBoxDstMNBox_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBoxDstMNBox::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBoxDstMNBox::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQBoxDstMNBox_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBoxDstMNBox::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQBoxDstMNBox::loadRecByQref(
			ubigint qref
			, WznmQBoxDstMNBox** rec
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

	return loadRecByStmt("TblWznmQBoxDstMNBox_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQBoxDstMNBox::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBoxDstMNBox& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQBoxDstMNBox_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
