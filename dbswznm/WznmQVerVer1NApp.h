/**
	* \file WznmQVerVer1NApp.h
	* Dbs and XML wrapper for table TblWznmQVerVer1NApp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERVER1NAPP_H
#define WZNMQVERVER1NAPP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerVer1NApp: record of TblWznmQVerVer1NApp
	*/
class WznmQVerVer1NApp {

public:
	WznmQVerVer1NApp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint verNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVerVer1NApp: recordset of TblWznmQVerVer1NApp
	*/
class ListWznmQVerVer1NApp {

public:
	ListWznmQVerVer1NApp();
	ListWznmQVerVer1NApp(const ListWznmQVerVer1NApp& src);
	~ListWznmQVerVer1NApp();

	void clear();
	unsigned int size() const;
	void append(WznmQVerVer1NApp* rec);

	ListWznmQVerVer1NApp& operator=(const ListWznmQVerVer1NApp& src);

public:
	std::vector<WznmQVerVer1NApp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerVer1NApp: C++ wrapper for table TblWznmQVerVer1NApp
	*/
class TblWznmQVerVer1NApp {

public:
	TblWznmQVerVer1NApp();
	virtual ~TblWznmQVerVer1NApp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NApp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NApp& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerVer1NApp* rec);
	Sbecore::ubigint insertNewRec(WznmQVerVer1NApp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerVer1NApp& rst, WznmQVerVer1NApp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	virtual void insertRst(ListWznmQVerVer1NApp& rst);
	virtual void updateRec(WznmQVerVer1NApp* rec);
	virtual void updateRst(ListWznmQVerVer1NApp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NApp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NApp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerVer1NApp: C++ wrapper for table TblWznmQVerVer1NApp (MySQL database)
	*/
class MyTblWznmQVerVer1NApp : public TblWznmQVerVer1NApp, public Sbecore::MyTable {

public:
	MyTblWznmQVerVer1NApp();
	~MyTblWznmQVerVer1NApp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NApp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NApp& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NApp* rec);
	void insertRst(ListWznmQVerVer1NApp& rst);
	void updateRec(WznmQVerVer1NApp* rec);
	void updateRst(ListWznmQVerVer1NApp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NApp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NApp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerVer1NApp: C++ wrapper for table TblWznmQVerVer1NApp (PgSQL database)
	*/
class PgTblWznmQVerVer1NApp : public TblWznmQVerVer1NApp, public Sbecore::PgTable {

public:
	PgTblWznmQVerVer1NApp();
	~PgTblWznmQVerVer1NApp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerVer1NApp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerVer1NApp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerVer1NApp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerVer1NApp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NApp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NApp& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NApp* rec);
	void insertRst(ListWznmQVerVer1NApp& rst);
	void updateRec(WznmQVerVer1NApp* rec);
	void updateRst(ListWznmQVerVer1NApp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NApp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NApp& rst);
};
#endif

#endif
