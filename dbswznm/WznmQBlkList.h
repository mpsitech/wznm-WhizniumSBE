/**
	* \file WznmQBlkList.h
	* Dbs and XML wrapper for table TblWznmQBlkList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQBLKLIST_H
#define WZNMQBLKLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBlkList: record of TblWznmQBlkList
	*/
class WznmQBlkList {

public:
	WznmQBlkList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

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
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQBlkList: recordset of TblWznmQBlkList
	*/
class ListWznmQBlkList {

public:
	ListWznmQBlkList();
	ListWznmQBlkList(const ListWznmQBlkList& src);
	~ListWznmQBlkList();

	void clear();
	unsigned int size() const;
	void append(WznmQBlkList* rec);

	ListWznmQBlkList& operator=(const ListWznmQBlkList& src);

public:
	std::vector<WznmQBlkList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBlkList: C++ wrapper for table TblWznmQBlkList
	*/
class TblWznmQBlkList {

public:
	TblWznmQBlkList();
	virtual ~TblWznmQBlkList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBlkList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkList& rst);

	virtual Sbecore::ubigint insertRec(WznmQBlkList* rec);
	Sbecore::ubigint insertNewRec(WznmQBlkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQBlkList& rst, WznmQBlkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWznmQBlkList& rst);
	virtual void updateRec(WznmQBlkList* rec);
	virtual void updateRst(ListWznmQBlkList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBlkList: C++ wrapper for table TblWznmQBlkList (MySQL database)
	*/
class MyTblWznmQBlkList : public TblWznmQBlkList, public Sbecore::MyTable {

public:
	MyTblWznmQBlkList();
	~MyTblWznmQBlkList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkList& rst);

	Sbecore::ubigint insertRec(WznmQBlkList* rec);
	void insertRst(ListWznmQBlkList& rst);
	void updateRec(WznmQBlkList* rec);
	void updateRst(ListWznmQBlkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBlkList: C++ wrapper for table TblWznmQBlkList (PgSQL database)
	*/
class PgTblWznmQBlkList : public TblWznmQBlkList, public Sbecore::PgTable {

public:
	PgTblWznmQBlkList();
	~PgTblWznmQBlkList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBlkList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBlkList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBlkList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBlkList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkList& rst);

	Sbecore::ubigint insertRec(WznmQBlkList* rec);
	void insertRst(ListWznmQBlkList& rst);
	void updateRec(WznmQBlkList* rec);
	void updateRst(ListWznmQBlkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkList& rst);
};
#endif

#endif

