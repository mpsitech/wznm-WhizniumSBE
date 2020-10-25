/**
	* \file WznmQVerVer1NError.h
	* Dbs and XML wrapper for table TblWznmQVerVer1NError (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVERVER1NERROR_H
#define WZNMQVERVER1NERROR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerVer1NError: record of TblWznmQVerVer1NError
	*/
class WznmQVerVer1NError {

public:
	WznmQVerVer1NError(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);

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
	* ListWznmQVerVer1NError: recordset of TblWznmQVerVer1NError
	*/
class ListWznmQVerVer1NError {

public:
	ListWznmQVerVer1NError();
	ListWznmQVerVer1NError(const ListWznmQVerVer1NError& src);
	~ListWznmQVerVer1NError();

	void clear();
	unsigned int size() const;
	void append(WznmQVerVer1NError* rec);

	ListWznmQVerVer1NError& operator=(const ListWznmQVerVer1NError& src);

public:
	std::vector<WznmQVerVer1NError*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerVer1NError: C++ wrapper for table TblWznmQVerVer1NError
	*/
class TblWznmQVerVer1NError {

public:
	TblWznmQVerVer1NError();
	virtual ~TblWznmQVerVer1NError();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NError** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NError& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerVer1NError* rec);
	Sbecore::ubigint insertNewRec(WznmQVerVer1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerVer1NError& rst, WznmQVerVer1NError** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	virtual void insertRst(ListWznmQVerVer1NError& rst);
	virtual void updateRec(WznmQVerVer1NError* rec);
	virtual void updateRst(ListWznmQVerVer1NError& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NError** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NError& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerVer1NError: C++ wrapper for table TblWznmQVerVer1NError (MySQL database)
	*/
class MyTblWznmQVerVer1NError : public TblWznmQVerVer1NError, public Sbecore::MyTable {

public:
	MyTblWznmQVerVer1NError();
	~MyTblWznmQVerVer1NError();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NError& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NError* rec);
	void insertRst(ListWznmQVerVer1NError& rst);
	void updateRec(WznmQVerVer1NError* rec);
	void updateRst(ListWznmQVerVer1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NError& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerVer1NError: C++ wrapper for table TblWznmQVerVer1NError (PgSQL database)
	*/
class PgTblWznmQVerVer1NError : public TblWznmQVerVer1NError, public Sbecore::PgTable {

public:
	PgTblWznmQVerVer1NError();
	~PgTblWznmQVerVer1NError();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerVer1NError** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerVer1NError& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerVer1NError** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerVer1NError& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NError& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NError* rec);
	void insertRst(ListWznmQVerVer1NError& rst);
	void updateRec(WznmQVerVer1NError* rec);
	void updateRst(ListWznmQVerVer1NError& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NError** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NError& rst);
};
#endif

#endif

