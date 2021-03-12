/**
	* \file WznmQTblRef1NDialog.h
	* Dbs and XML wrapper for table TblWznmQTblRef1NDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLREF1NDIALOG_H
#define WZNMQTBLREF1NDIALOG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblRef1NDialog: record of TblWznmQTblRef1NDialog
	*/
class WznmQTblRef1NDialog {

public:
	WznmQTblRef1NDialog(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblRef1NDialog: recordset of TblWznmQTblRef1NDialog
	*/
class ListWznmQTblRef1NDialog {

public:
	ListWznmQTblRef1NDialog();
	ListWznmQTblRef1NDialog(const ListWznmQTblRef1NDialog& src);
	~ListWznmQTblRef1NDialog();

	void clear();
	unsigned int size() const;
	void append(WznmQTblRef1NDialog* rec);

	ListWznmQTblRef1NDialog& operator=(const ListWznmQTblRef1NDialog& src);

public:
	std::vector<WznmQTblRef1NDialog*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblRef1NDialog: C++ wrapper for table TblWznmQTblRef1NDialog
	*/
class TblWznmQTblRef1NDialog {

public:
	TblWznmQTblRef1NDialog();
	virtual ~TblWznmQTblRef1NDialog();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NDialog** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NDialog& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblRef1NDialog* rec);
	Sbecore::ubigint insertNewRec(WznmQTblRef1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblRef1NDialog& rst, WznmQTblRef1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblRef1NDialog& rst);
	virtual void updateRec(WznmQTblRef1NDialog* rec);
	virtual void updateRst(ListWznmQTblRef1NDialog& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NDialog** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NDialog& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblRef1NDialog: C++ wrapper for table TblWznmQTblRef1NDialog (MySQL database)
	*/
class MyTblWznmQTblRef1NDialog : public TblWznmQTblRef1NDialog, public Sbecore::MyTable {

public:
	MyTblWznmQTblRef1NDialog();
	~MyTblWznmQTblRef1NDialog();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NDialog* rec);
	void insertRst(ListWznmQTblRef1NDialog& rst);
	void updateRec(WznmQTblRef1NDialog* rec);
	void updateRst(ListWznmQTblRef1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NDialog& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblRef1NDialog: C++ wrapper for table TblWznmQTblRef1NDialog (PgSQL database)
	*/
class PgTblWznmQTblRef1NDialog : public TblWznmQTblRef1NDialog, public Sbecore::PgTable {

public:
	PgTblWznmQTblRef1NDialog();
	~PgTblWznmQTblRef1NDialog();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblRef1NDialog** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblRef1NDialog& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblRef1NDialog** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblRef1NDialog& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NDialog* rec);
	void insertRst(ListWznmQTblRef1NDialog& rst);
	void updateRec(WznmQTblRef1NDialog* rec);
	void updateRst(ListWznmQTblRef1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NDialog& rst);
};
#endif

#endif
