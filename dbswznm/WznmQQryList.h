/**
	* \file WznmQQryList.h
	* Dbs and XML wrapper for table TblWznmQQryList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQQRYLIST_H
#define WZNMQQRYLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryList: record of TblWznmQQryList
	*/
class WznmQQryList {

public:
	WznmQQryList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint supRefWznmMQuery = 0, const std::string stubSupRefWznmMQuery = "", const Sbecore::uint supIxVSubrole = 0, const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint qtbRefWznmMTable = 0, const std::string stubQtbRefWznmMTable = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::ubigint supRefWznmMQuery;
	std::string stubSupRefWznmMQuery;
	Sbecore::uint supIxVSubrole;
	std::string srefSupIxVSubrole;
	std::string titSupIxVSubrole;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;
	Sbecore::ubigint qtbRefWznmMTable;
	std::string stubQtbRefWznmMTable;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQryList: recordset of TblWznmQQryList
	*/
class ListWznmQQryList {

public:
	ListWznmQQryList();
	ListWznmQQryList(const ListWznmQQryList& src);
	~ListWznmQQryList();

	void clear();
	unsigned int size() const;
	void append(WznmQQryList* rec);

	ListWznmQQryList& operator=(const ListWznmQQryList& src);

public:
	std::vector<WznmQQryList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryList: C++ wrapper for table TblWznmQQryList
	*/
class TblWznmQQryList {

public:
	TblWznmQQryList();
	virtual ~TblWznmQQryList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryList& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryList* rec);
	Sbecore::ubigint insertNewRec(WznmQQryList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint supRefWznmMQuery = 0, const std::string stubSupRefWznmMQuery = "", const Sbecore::uint supIxVSubrole = 0, const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint qtbRefWznmMTable = 0, const std::string stubQtbRefWznmMTable = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryList& rst, WznmQQryList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint supRefWznmMQuery = 0, const std::string stubSupRefWznmMQuery = "", const Sbecore::uint supIxVSubrole = 0, const std::string srefSupIxVSubrole = "", const std::string titSupIxVSubrole = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint qtbRefWznmMTable = 0, const std::string stubQtbRefWznmMTable = "");
	virtual void insertRst(ListWznmQQryList& rst);
	virtual void updateRec(WznmQQryList* rec);
	virtual void updateRst(ListWznmQQryList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryList: C++ wrapper for table TblWznmQQryList (MySQL database)
	*/
class MyTblWznmQQryList : public TblWznmQQryList, public Sbecore::MyTable {

public:
	MyTblWznmQQryList();
	~MyTblWznmQQryList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryList& rst);

	Sbecore::ubigint insertRec(WznmQQryList* rec);
	void insertRst(ListWznmQQryList& rst);
	void updateRec(WznmQQryList* rec);
	void updateRst(ListWznmQQryList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryList: C++ wrapper for table TblWznmQQryList (PgSQL database)
	*/
class PgTblWznmQQryList : public TblWznmQQryList, public Sbecore::PgTable {

public:
	PgTblWznmQQryList();
	~PgTblWznmQQryList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryList& rst);

	Sbecore::ubigint insertRec(WznmQQryList* rec);
	void insertRst(ListWznmQQryList& rst);
	void updateRec(WznmQQryList* rec);
	void updateRst(ListWznmQQryList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryList& rst);
};
#endif

#endif

