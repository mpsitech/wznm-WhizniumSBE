/**
	* \file WznmQIexList.h
	* Dbs and XML wrapper for table TblWznmQIexList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIEXLIST_H
#define WZNMQIEXLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQIexList: record of TblWznmQIexList
	*/
class WznmQIexList {

public:
	WznmQIexList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const std::string Minversion = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Short;
	std::string Title;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	std::string Minversion;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQIexList: recordset of TblWznmQIexList
	*/
class ListWznmQIexList {

public:
	ListWznmQIexList();
	ListWznmQIexList(const ListWznmQIexList& src);
	~ListWznmQIexList();

	void clear();
	unsigned int size() const;
	void append(WznmQIexList* rec);

	ListWznmQIexList& operator=(const ListWznmQIexList& src);

public:
	std::vector<WznmQIexList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQIexList: C++ wrapper for table TblWznmQIexList
	*/
class TblWznmQIexList {

public:
	TblWznmQIexList();
	virtual ~TblWznmQIexList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQIexList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexList& rst);

	virtual Sbecore::ubigint insertRec(WznmQIexList* rec);
	Sbecore::ubigint insertNewRec(WznmQIexList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const std::string Minversion = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQIexList& rst, WznmQIexList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const std::string Minversion = "");
	virtual void insertRst(ListWznmQIexList& rst);
	virtual void updateRec(WznmQIexList* rec);
	virtual void updateRst(ListWznmQIexList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQIexList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQIexList: C++ wrapper for table TblWznmQIexList (MySQL database)
	*/
class MyTblWznmQIexList : public TblWznmQIexList, public Sbecore::MyTable {

public:
	MyTblWznmQIexList();
	~MyTblWznmQIexList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIexList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexList& rst);

	Sbecore::ubigint insertRec(WznmQIexList* rec);
	void insertRst(ListWznmQIexList& rst);
	void updateRec(WznmQIexList* rec);
	void updateRst(ListWznmQIexList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIexList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQIexList: C++ wrapper for table TblWznmQIexList (PgSQL database)
	*/
class PgTblWznmQIexList : public TblWznmQIexList, public Sbecore::PgTable {

public:
	PgTblWznmQIexList();
	~PgTblWznmQIexList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQIexList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQIexList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQIexList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQIexList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIexList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexList& rst);

	Sbecore::ubigint insertRec(WznmQIexList* rec);
	void insertRst(ListWznmQIexList& rst);
	void updateRec(WznmQIexList* rec);
	void updateRst(ListWznmQIexList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIexList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexList& rst);
};
#endif

#endif
