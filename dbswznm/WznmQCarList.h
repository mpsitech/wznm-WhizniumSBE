/**
	* \file WznmQCarList.h
	* Dbs and XML wrapper for table TblWznmQCarList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCARLIST_H
#define WZNMQCARLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCarList: record of TblWznmQCarList
	*/
class WznmQCarList {

public:
	WznmQCarList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint mdlRefWznmMModule = 0, const std::string stubMdlRefWznmMModule = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint mdlRefWznmMModule;
	std::string stubMdlRefWznmMModule;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCarList: recordset of TblWznmQCarList
	*/
class ListWznmQCarList {

public:
	ListWznmQCarList();
	ListWznmQCarList(const ListWznmQCarList& src);
	~ListWznmQCarList();

	void clear();
	unsigned int size() const;
	void append(WznmQCarList* rec);

	ListWznmQCarList& operator=(const ListWznmQCarList& src);

public:
	std::vector<WznmQCarList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCarList: C++ wrapper for table TblWznmQCarList
	*/
class TblWznmQCarList {

public:
	TblWznmQCarList();
	virtual ~TblWznmQCarList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCarList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarList& rst);

	virtual Sbecore::ubigint insertRec(WznmQCarList* rec);
	Sbecore::ubigint insertNewRec(WznmQCarList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint mdlRefWznmMModule = 0, const std::string stubMdlRefWznmMModule = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCarList& rst, WznmQCarList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint mdlRefWznmMModule = 0, const std::string stubMdlRefWznmMModule = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWznmQCarList& rst);
	virtual void updateRec(WznmQCarList* rec);
	virtual void updateRst(ListWznmQCarList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCarList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCarList: C++ wrapper for table TblWznmQCarList (MySQL database)
	*/
class MyTblWznmQCarList : public TblWznmQCarList, public Sbecore::MyTable {

public:
	MyTblWznmQCarList();
	~MyTblWznmQCarList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCarList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarList& rst);

	Sbecore::ubigint insertRec(WznmQCarList* rec);
	void insertRst(ListWznmQCarList& rst);
	void updateRec(WznmQCarList* rec);
	void updateRst(ListWznmQCarList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCarList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCarList: C++ wrapper for table TblWznmQCarList (PgSQL database)
	*/
class PgTblWznmQCarList : public TblWznmQCarList, public Sbecore::PgTable {

public:
	PgTblWznmQCarList();
	~PgTblWznmQCarList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCarList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCarList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCarList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCarList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCarList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarList& rst);

	Sbecore::ubigint insertRec(WznmQCarList* rec);
	void insertRst(ListWznmQCarList& rst);
	void updateRec(WznmQCarList* rec);
	void updateRst(ListWznmQCarList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCarList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarList& rst);
};
#endif

#endif
