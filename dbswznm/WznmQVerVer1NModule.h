/**
	* \file WznmQVerVer1NModule.h
	* Dbs and XML wrapper for table TblWznmQVerVer1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQVERVER1NMODULE_H
#define WZNMQVERVER1NMODULE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerVer1NModule: record of TblWznmQVerVer1NModule
	*/
class WznmQVerVer1NModule {

public:
	WznmQVerVer1NModule(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);

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
	* ListWznmQVerVer1NModule: recordset of TblWznmQVerVer1NModule
	*/
class ListWznmQVerVer1NModule {

public:
	ListWznmQVerVer1NModule();
	ListWznmQVerVer1NModule(const ListWznmQVerVer1NModule& src);
	~ListWznmQVerVer1NModule();

	void clear();
	unsigned int size() const;
	void append(WznmQVerVer1NModule* rec);

	ListWznmQVerVer1NModule& operator=(const ListWznmQVerVer1NModule& src);

public:
	std::vector<WznmQVerVer1NModule*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerVer1NModule: C++ wrapper for table TblWznmQVerVer1NModule
	*/
class TblWznmQVerVer1NModule {

public:
	TblWznmQVerVer1NModule();
	virtual ~TblWznmQVerVer1NModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NModule& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerVer1NModule* rec);
	Sbecore::ubigint insertNewRec(WznmQVerVer1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerVer1NModule& rst, WznmQVerVer1NModule** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	virtual void insertRst(ListWznmQVerVer1NModule& rst);
	virtual void updateRec(WznmQVerVer1NModule* rec);
	virtual void updateRst(ListWznmQVerVer1NModule& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NModule** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerVer1NModule: C++ wrapper for table TblWznmQVerVer1NModule (MySQL database)
	*/
class MyTblWznmQVerVer1NModule : public TblWznmQVerVer1NModule, public Sbecore::MyTable {

public:
	MyTblWznmQVerVer1NModule();
	~MyTblWznmQVerVer1NModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NModule& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NModule* rec);
	void insertRst(ListWznmQVerVer1NModule& rst);
	void updateRec(WznmQVerVer1NModule* rec);
	void updateRst(ListWznmQVerVer1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerVer1NModule: C++ wrapper for table TblWznmQVerVer1NModule (PgSQL database)
	*/
class PgTblWznmQVerVer1NModule : public TblWznmQVerVer1NModule, public Sbecore::PgTable {

public:
	PgTblWznmQVerVer1NModule();
	~PgTblWznmQVerVer1NModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerVer1NModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerVer1NModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerVer1NModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerVer1NModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NModule& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NModule* rec);
	void insertRst(ListWznmQVerVer1NModule& rst);
	void updateRec(WznmQVerVer1NModule* rec);
	void updateRst(ListWznmQVerVer1NModule& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NModule** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NModule& rst);
};
#endif

#endif

