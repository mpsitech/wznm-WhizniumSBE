/**
	* \file WznmQPstList.h
	* Dbs and XML wrapper for table TblWznmQPstList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPSTLIST_H
#define WZNMQPSTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPstList: record of TblWznmQPstList
	*/
class WznmQPstList {

public:
	WznmQPstList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint ixWznmWArgtype = 0, const std::string srefIxWznmWArgtype = "", const std::string titIxWznmWArgtype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	Sbecore::uint ixWznmWArgtype;
	std::string srefIxWznmWArgtype;
	std::string titIxWznmWArgtype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPstList: recordset of TblWznmQPstList
	*/
class ListWznmQPstList {

public:
	ListWznmQPstList();
	ListWznmQPstList(const ListWznmQPstList& src);
	~ListWznmQPstList();

	void clear();
	unsigned int size() const;
	void append(WznmQPstList* rec);

	ListWznmQPstList& operator=(const ListWznmQPstList& src);

public:
	std::vector<WznmQPstList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPstList: C++ wrapper for table TblWznmQPstList
	*/
class TblWznmQPstList {

public:
	TblWznmQPstList();
	virtual ~TblWznmQPstList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPstList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPstList& rst);

	virtual Sbecore::ubigint insertRec(WznmQPstList* rec);
	Sbecore::ubigint insertNewRec(WznmQPstList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint ixWznmWArgtype = 0, const std::string srefIxWznmWArgtype = "", const std::string titIxWznmWArgtype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPstList& rst, WznmQPstList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint ixWznmWArgtype = 0, const std::string srefIxWznmWArgtype = "", const std::string titIxWznmWArgtype = "");
	virtual void insertRst(ListWznmQPstList& rst);
	virtual void updateRec(WznmQPstList* rec);
	virtual void updateRst(ListWznmQPstList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPstList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPstList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPstList: C++ wrapper for table TblWznmQPstList (MySQL database)
	*/
class MyTblWznmQPstList : public TblWznmQPstList, public Sbecore::MyTable {

public:
	MyTblWznmQPstList();
	~MyTblWznmQPstList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPstList& rst);

	Sbecore::ubigint insertRec(WznmQPstList* rec);
	void insertRst(ListWznmQPstList& rst);
	void updateRec(WznmQPstList* rec);
	void updateRst(ListWznmQPstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPstList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPstList: C++ wrapper for table TblWznmQPstList (PgSQL database)
	*/
class PgTblWznmQPstList : public TblWznmQPstList, public Sbecore::PgTable {

public:
	PgTblWznmQPstList();
	~PgTblWznmQPstList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPstList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPstList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPstList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPstList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPstList& rst);

	Sbecore::ubigint insertRec(WznmQPstList* rec);
	void insertRst(ListWznmQPstList& rst);
	void updateRec(WznmQPstList* rec);
	void updateRst(ListWznmQPstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPstList& rst);
};
#endif

#endif

