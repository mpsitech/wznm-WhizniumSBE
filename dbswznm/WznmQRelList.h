/**
	* \file WznmQRelList.h
	* Dbs and XML wrapper for table TblWznmQRelList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRELLIST_H
#define WZNMQRELLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRelList: record of TblWznmQRelList
	*/
class WznmQRelList {

public:
	WznmQRelList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint frRefWznmMTable = 0, const std::string stubFrRefWznmMTable = "", const Sbecore::ubigint frsRefWznmMSubset = 0, const std::string stubFrsRefWznmMSubset = "", const Sbecore::ubigint toRefWznmMTable = 0, const std::string stubToRefWznmMTable = "", const Sbecore::ubigint tosRefWznmMSubset = 0, const std::string stubTosRefWznmMSubset = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint supRefWznmMRelation = 0, const std::string stubSupRefWznmMRelation = "", const Sbecore::uint supIxVSubrole = 0, const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const std::string Prefix = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint frRefWznmMTable;
	std::string stubFrRefWznmMTable;
	Sbecore::ubigint frsRefWznmMSubset;
	std::string stubFrsRefWznmMSubset;
	Sbecore::ubigint toRefWznmMTable;
	std::string stubToRefWznmMTable;
	Sbecore::ubigint tosRefWznmMSubset;
	std::string stubTosRefWznmMSubset;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::ubigint supRefWznmMRelation;
	std::string stubSupRefWznmMRelation;
	Sbecore::uint supIxVSubrole;
	std::string srefSupIxVSubrole;
	std::string titSupIxVSubrole;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;
	std::string Prefix;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQRelList: recordset of TblWznmQRelList
	*/
class ListWznmQRelList {

public:
	ListWznmQRelList();
	ListWznmQRelList(const ListWznmQRelList& src);
	~ListWznmQRelList();

	void clear();
	unsigned int size() const;
	void append(WznmQRelList* rec);

	ListWznmQRelList& operator=(const ListWznmQRelList& src);

public:
	std::vector<WznmQRelList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRelList: C++ wrapper for table TblWznmQRelList
	*/
class TblWznmQRelList {

public:
	TblWznmQRelList();
	virtual ~TblWznmQRelList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRelList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelList& rst);

	virtual Sbecore::ubigint insertRec(WznmQRelList* rec);
	Sbecore::ubigint insertNewRec(WznmQRelList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint frRefWznmMTable = 0, const std::string stubFrRefWznmMTable = "", const Sbecore::ubigint frsRefWznmMSubset = 0, const std::string stubFrsRefWznmMSubset = "", const Sbecore::ubigint toRefWznmMTable = 0, const std::string stubToRefWznmMTable = "", const Sbecore::ubigint tosRefWznmMSubset = 0, const std::string stubTosRefWznmMSubset = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint supRefWznmMRelation = 0, const std::string stubSupRefWznmMRelation = "", const Sbecore::uint supIxVSubrole = 0, const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const std::string Prefix = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRelList& rst, WznmQRelList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint frRefWznmMTable = 0, const std::string stubFrRefWznmMTable = "", const Sbecore::ubigint frsRefWznmMSubset = 0, const std::string stubFrsRefWznmMSubset = "", const Sbecore::ubigint toRefWznmMTable = 0, const std::string stubToRefWznmMTable = "", const Sbecore::ubigint tosRefWznmMSubset = 0, const std::string stubTosRefWznmMSubset = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint supRefWznmMRelation = 0, const std::string stubSupRefWznmMRelation = "", const Sbecore::uint supIxVSubrole = 0, const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const std::string Prefix = "");
	virtual void insertRst(ListWznmQRelList& rst);
	virtual void updateRec(WznmQRelList* rec);
	virtual void updateRst(ListWznmQRelList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRelList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRelList: C++ wrapper for table TblWznmQRelList (MySQL database)
	*/
class MyTblWznmQRelList : public TblWznmQRelList, public Sbecore::MyTable {

public:
	MyTblWznmQRelList();
	~MyTblWznmQRelList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelList& rst);

	Sbecore::ubigint insertRec(WznmQRelList* rec);
	void insertRst(ListWznmQRelList& rst);
	void updateRec(WznmQRelList* rec);
	void updateRst(ListWznmQRelList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRelList: C++ wrapper for table TblWznmQRelList (PgSQL database)
	*/
class PgTblWznmQRelList : public TblWznmQRelList, public Sbecore::PgTable {

public:
	PgTblWznmQRelList();
	~PgTblWznmQRelList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRelList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRelList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRelList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRelList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelList& rst);

	Sbecore::ubigint insertRec(WznmQRelList* rec);
	void insertRst(ListWznmQRelList& rst);
	void updateRec(WznmQRelList* rec);
	void updateRst(ListWznmQRelList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelList& rst);
};
#endif

#endif

