/**
	* \file WznmQBlkAItem.h
	* Dbs and XML wrapper for table TblWznmQBlkAItem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQBLKAITEM_H
#define WZNMQBLKAITEM_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBlkAItem: record of TblWznmQBlkAItem
	*/
class WznmQBlkAItem {

public:
	WznmQBlkAItem(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint blkNum = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMControl = 0, const std::string stubRefWznmMControl = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMFeed = 0, const std::string stubRefWznmMFeed = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMBlock = 0, const std::string stubRefWznmMBlock = "", const Sbecore::ubigint refJ = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint blkNum;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	Sbecore::ubigint refWznmMControl;
	std::string stubRefWznmMControl;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	Sbecore::ubigint refWznmMFeed;
	std::string stubRefWznmMFeed;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;
	Sbecore::ubigint refWznmMBlock;
	std::string stubRefWznmMBlock;
	Sbecore::ubigint refJ;
	std::string Defval;
	Sbecore::ubigint refWznmMVectoritem;
	std::string stubRefWznmMVectoritem;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQBlkAItem: recordset of TblWznmQBlkAItem
	*/
class ListWznmQBlkAItem {

public:
	ListWznmQBlkAItem();
	ListWznmQBlkAItem(const ListWznmQBlkAItem& src);
	~ListWznmQBlkAItem();

	void clear();
	unsigned int size() const;
	void append(WznmQBlkAItem* rec);

	ListWznmQBlkAItem& operator=(const ListWznmQBlkAItem& src);

public:
	std::vector<WznmQBlkAItem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBlkAItem: C++ wrapper for table TblWznmQBlkAItem
	*/
class TblWznmQBlkAItem {

public:
	TblWznmQBlkAItem();
	virtual ~TblWznmQBlkAItem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBlkAItem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkAItem& rst);

	virtual Sbecore::ubigint insertRec(WznmQBlkAItem* rec);
	Sbecore::ubigint insertNewRec(WznmQBlkAItem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint blkNum = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMControl = 0, const std::string stubRefWznmMControl = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMFeed = 0, const std::string stubRefWznmMFeed = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMBlock = 0, const std::string stubRefWznmMBlock = "", const Sbecore::ubigint refJ = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQBlkAItem& rst, WznmQBlkAItem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint blkNum = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMControl = 0, const std::string stubRefWznmMControl = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMFeed = 0, const std::string stubRefWznmMFeed = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMBlock = 0, const std::string stubRefWznmMBlock = "", const Sbecore::ubigint refJ = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQBlkAItem& rst);
	virtual void updateRec(WznmQBlkAItem* rec);
	virtual void updateRst(ListWznmQBlkAItem& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkAItem** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkAItem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBlkAItem: C++ wrapper for table TblWznmQBlkAItem (MySQL database)
	*/
class MyTblWznmQBlkAItem : public TblWznmQBlkAItem, public Sbecore::MyTable {

public:
	MyTblWznmQBlkAItem();
	~MyTblWznmQBlkAItem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlkAItem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkAItem& rst);

	Sbecore::ubigint insertRec(WznmQBlkAItem* rec);
	void insertRst(ListWznmQBlkAItem& rst);
	void updateRec(WznmQBlkAItem* rec);
	void updateRst(ListWznmQBlkAItem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkAItem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkAItem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBlkAItem: C++ wrapper for table TblWznmQBlkAItem (PgSQL database)
	*/
class PgTblWznmQBlkAItem : public TblWznmQBlkAItem, public Sbecore::PgTable {

public:
	PgTblWznmQBlkAItem();
	~PgTblWznmQBlkAItem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBlkAItem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBlkAItem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBlkAItem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBlkAItem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlkAItem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkAItem& rst);

	Sbecore::ubigint insertRec(WznmQBlkAItem* rec);
	void insertRst(ListWznmQBlkAItem& rst);
	void updateRec(WznmQBlkAItem* rec);
	void updateRst(ListWznmQBlkAItem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkAItem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkAItem& rst);
};
#endif

#endif

