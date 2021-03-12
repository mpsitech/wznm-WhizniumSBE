/**
	* \file WznmQCar1NDialog.h
	* Dbs and XML wrapper for table TblWznmQCar1NDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCAR1NDIALOG_H
#define WZNMQCAR1NDIALOG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCar1NDialog: record of TblWznmQCar1NDialog
	*/
class WznmQCar1NDialog {

public:
	WznmQCar1NDialog(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQCar1NDialog: recordset of TblWznmQCar1NDialog
	*/
class ListWznmQCar1NDialog {

public:
	ListWznmQCar1NDialog();
	ListWznmQCar1NDialog(const ListWznmQCar1NDialog& src);
	~ListWznmQCar1NDialog();

	void clear();
	unsigned int size() const;
	void append(WznmQCar1NDialog* rec);

	ListWznmQCar1NDialog& operator=(const ListWznmQCar1NDialog& src);

public:
	std::vector<WznmQCar1NDialog*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCar1NDialog: C++ wrapper for table TblWznmQCar1NDialog
	*/
class TblWznmQCar1NDialog {

public:
	TblWznmQCar1NDialog();
	virtual ~TblWznmQCar1NDialog();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCar1NDialog** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCar1NDialog& rst);

	virtual Sbecore::ubigint insertRec(WznmQCar1NDialog* rec);
	Sbecore::ubigint insertNewRec(WznmQCar1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCar1NDialog& rst, WznmQCar1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQCar1NDialog& rst);
	virtual void updateRec(WznmQCar1NDialog* rec);
	virtual void updateRst(ListWznmQCar1NDialog& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCar1NDialog** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCar1NDialog& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCar1NDialog: C++ wrapper for table TblWznmQCar1NDialog (MySQL database)
	*/
class MyTblWznmQCar1NDialog : public TblWznmQCar1NDialog, public Sbecore::MyTable {

public:
	MyTblWznmQCar1NDialog();
	~MyTblWznmQCar1NDialog();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCar1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCar1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQCar1NDialog* rec);
	void insertRst(ListWznmQCar1NDialog& rst);
	void updateRec(WznmQCar1NDialog* rec);
	void updateRst(ListWznmQCar1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCar1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCar1NDialog& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCar1NDialog: C++ wrapper for table TblWznmQCar1NDialog (PgSQL database)
	*/
class PgTblWznmQCar1NDialog : public TblWznmQCar1NDialog, public Sbecore::PgTable {

public:
	PgTblWznmQCar1NDialog();
	~PgTblWznmQCar1NDialog();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCar1NDialog** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCar1NDialog& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCar1NDialog** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCar1NDialog& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCar1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCar1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQCar1NDialog* rec);
	void insertRst(ListWznmQCar1NDialog& rst);
	void updateRec(WznmQCar1NDialog* rec);
	void updateRst(ListWznmQCar1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCar1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCar1NDialog& rst);
};
#endif

#endif
