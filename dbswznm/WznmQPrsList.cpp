/**
	* \file WznmQPrsList.cpp
	* Dbs and XML wrapper for table TblWznmQPrsList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQPrsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrsList
 ******************************************************************************/

WznmQPrsList::WznmQPrsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->ixVSex = ixVSex;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

void WznmQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "tit", Title);
		writeString(wr, "fnm", Firstname);
		writeString(wr, "lnm", Lastname);
		writeString(wr, "sex", srefIxVSex);
		writeString(wr, "sex2", titIxVSex);
		writeString(wr, "tel", telVal);
		writeString(wr, "eml", emlVal);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "Title", Title);
		writeString(wr, "Firstname", Firstname);
		writeString(wr, "Lastname", Lastname);
		writeString(wr, "srefIxVSex", srefIxVSex);
		writeString(wr, "titIxVSex", titIxVSex);
		writeString(wr, "telVal", telVal);
		writeString(wr, "emlVal", emlVal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQPrsList
 ******************************************************************************/

ListWznmQPrsList::ListWznmQPrsList() {
};

ListWznmQPrsList::ListWznmQPrsList(
			const ListWznmQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrsList(*(src.nodes[i]));
};

ListWznmQPrsList::~ListWznmQPrsList() {
	clear();
};

void ListWznmQPrsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQPrsList::size() const {
	return(nodes.size());
};

void ListWznmQPrsList::append(
			WznmQPrsList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQPrsList& ListWznmQPrsList::operator=(
			const ListWznmQPrsList& src
		) {
	WznmQPrsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQPrsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQPrsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQPrsList
 ******************************************************************************/

TblWznmQPrsList::TblWznmQPrsList() {
};

TblWznmQPrsList::~TblWznmQPrsList() {
};

bool TblWznmQPrsList::loadRecBySQL(
			const string& sqlstr
			, WznmQPrsList** rec
		) {
	return false;
};

ubigint TblWznmQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrsList& rst
		) {
	return 0;
};

ubigint TblWznmQPrsList::insertRec(
			WznmQPrsList* rec
		) {
	return 0;
};

ubigint TblWznmQPrsList::insertNewRec(
			WznmQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	WznmQPrsList* _rec = NULL;

	_rec = new WznmQPrsList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, Title, Firstname, Lastname, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQPrsList::appendNewRecToRst(
			ListWznmQPrsList& rst
			, WznmQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	WznmQPrsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, Title, Firstname, Lastname, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQPrsList::insertRst(
			ListWznmQPrsList& rst
		) {
};

void TblWznmQPrsList::updateRec(
			WznmQPrsList* rec
		) {
};

void TblWznmQPrsList::updateRst(
			ListWznmQPrsList& rst
		) {
};

void TblWznmQPrsList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQPrsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQPrsList::loadRecByQref(
			ubigint qref
			, WznmQPrsList** rec
		) {
	return false;
};

ubigint TblWznmQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrsList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQPrsList
 ******************************************************************************/

MyTblWznmQPrsList::MyTblWznmQPrsList() :
			TblWznmQPrsList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQPrsList::~MyTblWznmQPrsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQPrsList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, Title = ?, Firstname = ?, Lastname = ?, ixVSex = ?, telVal = ?, emlVal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQPrsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQPrsList WHERE jref = ?", false);
};

bool MyTblWznmQPrsList::loadRecBySQL(
			const string& sqlstr
			, WznmQPrsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQPrsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrsList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrsList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQPrsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->Firstname.assign(dbrow[7], dblengths[7]); else _rec->Firstname = "";
		if (dbrow[8]) _rec->Lastname.assign(dbrow[8], dblengths[8]); else _rec->Lastname = "";
		if (dbrow[9]) _rec->ixVSex = atol((char*) dbrow[9]); else _rec->ixVSex = 0;
		if (dbrow[10]) _rec->telVal.assign(dbrow[10], dblengths[10]); else _rec->telVal = "";
		if (dbrow[11]) _rec->emlVal.assign(dbrow[11], dblengths[11]); else _rec->emlVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQPrsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrsList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrsList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQPrsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->Firstname.assign(dbrow[7], dblengths[7]); else rec->Firstname = "";
			if (dbrow[8]) rec->Lastname.assign(dbrow[8], dblengths[8]); else rec->Lastname = "";
			if (dbrow[9]) rec->ixVSex = atol((char*) dbrow[9]); else rec->ixVSex = 0;
			if (dbrow[10]) rec->telVal.assign(dbrow[10], dblengths[10]); else rec->telVal = "";
			if (dbrow[11]) rec->emlVal.assign(dbrow[11], dblengths[11]); else rec->emlVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQPrsList::insertRec(
			WznmQPrsList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->Title.length();
	l[6] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[10] = rec->emlVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQPrsList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQPrsList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQPrsList::insertRst(
			ListWznmQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQPrsList::updateRec(
			WznmQPrsList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->Title.length();
	l[6] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[10] = rec->emlVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQPrsList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQPrsList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrsList::updateRst(
			ListWznmQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQPrsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQPrsList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQPrsList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQPrsList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQPrsList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQPrsList::loadRecByQref(
			ubigint qref
			, WznmQPrsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQPrsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQPrsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQPrsList
 ******************************************************************************/

PgTblWznmQPrsList::PgTblWznmQPrsList() :
			TblWznmQPrsList()
			, PgTable()
		{
};

PgTblWznmQPrsList::~PgTblWznmQPrsList() {
};

void PgTblWznmQPrsList::initStatements() {
	createStatement("TblWznmQPrsList_insertRec", "INSERT INTO TblWznmQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWznmQPrsList_updateRec", "UPDATE TblWznmQPrsList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, Title = $6, Firstname = $7, Lastname = $8, ixVSex = $9, telVal = $10, emlVal = $11 WHERE qref = $12", 12);
	createStatement("TblWznmQPrsList_removeRecByQref", "DELETE FROM TblWznmQPrsList WHERE qref = $1", 1);
	createStatement("TblWznmQPrsList_removeRstByJref", "DELETE FROM TblWznmQPrsList WHERE jref = $1", 1);

	createStatement("TblWznmQPrsList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblWznmQPrsList WHERE qref = $1", 1);
	createStatement("TblWznmQPrsList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblWznmQPrsList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQPrsList::loadRec(
			PGresult* res
			, WznmQPrsList** rec
		) {
	char* ptr;

	WznmQPrsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQPrsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->telVal.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->emlVal.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQPrsList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQPrsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQPrsList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlval")
		};

		while (numread < numrow) {
			rec = new WznmQPrsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->telVal.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->emlVal.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQPrsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQPrsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrsList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQPrsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrsList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQPrsList::loadRecBySQL(
			const string& sqlstr
			, WznmQPrsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrsList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrsList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQPrsList::insertRec(
			WznmQPrsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_ixVSex,
		rec->telVal.c_str(),
		rec->emlVal.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQPrsList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrsList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQPrsList::insertRst(
			ListWznmQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQPrsList::updateRec(
			WznmQPrsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_ixVSex,
		rec->telVal.c_str(),
		rec->emlVal.c_str(),
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
		0,
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQPrsList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrsList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrsList::updateRst(
			ListWznmQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQPrsList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrsList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrsList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrsList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQPrsList::loadRecByQref(
			ubigint qref
			, WznmQPrsList** rec
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

	return loadRecByStmt("TblWznmQPrsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQPrsList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

