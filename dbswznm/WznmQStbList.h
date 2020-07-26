/**
	* \file WznmQStbList.h
	* Dbs and XML wrapper for table TblWznmQStbList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSTBLIST_H
#define WZNMQSTBLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQStbList: record of TblWznmQStbList
	*/
class WznmQStbList {

public:
	WznmQStbList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "", const std::string Example = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;
	Sbecore::ubigint refWznmMSubset;
	std::string stubRefWznmMSubset;
	std::string Example;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQStbList: recordset of TblWznmQStbList
	*/
class ListWznmQStbList {

public:
	ListWznmQStbList();
	ListWznmQStbList(const ListWznmQStbList& src);
	~ListWznmQStbList();

	void clear();
	unsigned int size() const;
	void append(WznmQStbList* rec);

	ListWznmQStbList& operator=(const ListWznmQStbList& src);

public:
	std::vector<WznmQStbList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQStbList: C++ wrapper for table TblWznmQStbList
	*/
class TblWznmQStbList {

public:
	TblWznmQStbList();
	virtual ~TblWznmQStbList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQStbList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbList& rst);

	virtual Sbecore::ubigint insertRec(WznmQStbList* rec);
	Sbecore::ubigint insertNewRec(WznmQStbList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "", const std::string Example = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQStbList& rst, WznmQStbList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "", const std::string Example = "");
	virtual void insertRst(ListWznmQStbList& rst);
	virtual void updateRec(WznmQStbList* rec);
	virtual void updateRst(ListWznmQStbList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQStbList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQStbList: C++ wrapper for table TblWznmQStbList (MySQL database)
	*/
class MyTblWznmQStbList : public TblWznmQStbList, public Sbecore::MyTable {

public:
	MyTblWznmQStbList();
	~MyTblWznmQStbList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbList& rst);

	Sbecore::ubigint insertRec(WznmQStbList* rec);
	void insertRst(ListWznmQStbList& rst);
	void updateRec(WznmQStbList* rec);
	void updateRst(ListWznmQStbList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQStbList: C++ wrapper for table TblWznmQStbList (PgSQL database)
	*/
class PgTblWznmQStbList : public TblWznmQStbList, public Sbecore::PgTable {

public:
	PgTblWznmQStbList();
	~PgTblWznmQStbList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQStbList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQStbList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQStbList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQStbList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbList& rst);

	Sbecore::ubigint insertRec(WznmQStbList* rec);
	void insertRst(ListWznmQStbList& rst);
	void updateRec(WznmQStbList* rec);
	void updateRst(ListWznmQStbList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbList& rst);
};
#endif

#endif

