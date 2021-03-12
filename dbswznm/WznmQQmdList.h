/**
	* \file WznmQQmdList.h
	* Dbs and XML wrapper for table TblWznmQQmdList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQMDLIST_H
#define WZNMQQMDLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQmdList: record of TblWznmQQmdList
	*/
class WznmQQmdList {

public:
	WznmQQmdList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint qryRefWznmMQuery = 0, const std::string stubQryRefWznmMQuery = "", const Sbecore::ubigint refWznmMPreset = 0, const std::string stubRefWznmMPreset = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint qryRefWznmMQuery;
	std::string stubQryRefWznmMQuery;
	Sbecore::ubigint refWznmMPreset;
	std::string stubRefWznmMPreset;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQmdList: recordset of TblWznmQQmdList
	*/
class ListWznmQQmdList {

public:
	ListWznmQQmdList();
	ListWznmQQmdList(const ListWznmQQmdList& src);
	~ListWznmQQmdList();

	void clear();
	unsigned int size() const;
	void append(WznmQQmdList* rec);

	ListWznmQQmdList& operator=(const ListWznmQQmdList& src);

public:
	std::vector<WznmQQmdList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQmdList: C++ wrapper for table TblWznmQQmdList
	*/
class TblWznmQQmdList {

public:
	TblWznmQQmdList();
	virtual ~TblWznmQQmdList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQmdList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQmdList& rst);

	virtual Sbecore::ubigint insertRec(WznmQQmdList* rec);
	Sbecore::ubigint insertNewRec(WznmQQmdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint qryRefWznmMQuery = 0, const std::string stubQryRefWznmMQuery = "", const Sbecore::ubigint refWznmMPreset = 0, const std::string stubRefWznmMPreset = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQmdList& rst, WznmQQmdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint qryRefWznmMQuery = 0, const std::string stubQryRefWznmMQuery = "", const Sbecore::ubigint refWznmMPreset = 0, const std::string stubRefWznmMPreset = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWznmQQmdList& rst);
	virtual void updateRec(WznmQQmdList* rec);
	virtual void updateRst(ListWznmQQmdList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQmdList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQmdList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQmdList: C++ wrapper for table TblWznmQQmdList (MySQL database)
	*/
class MyTblWznmQQmdList : public TblWznmQQmdList, public Sbecore::MyTable {

public:
	MyTblWznmQQmdList();
	~MyTblWznmQQmdList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQmdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQmdList& rst);

	Sbecore::ubigint insertRec(WznmQQmdList* rec);
	void insertRst(ListWznmQQmdList& rst);
	void updateRec(WznmQQmdList* rec);
	void updateRst(ListWznmQQmdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQmdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQmdList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQmdList: C++ wrapper for table TblWznmQQmdList (PgSQL database)
	*/
class PgTblWznmQQmdList : public TblWznmQQmdList, public Sbecore::PgTable {

public:
	PgTblWznmQQmdList();
	~PgTblWznmQQmdList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQmdList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQmdList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQmdList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQmdList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQmdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQmdList& rst);

	Sbecore::ubigint insertRec(WznmQQmdList* rec);
	void insertRst(ListWznmQQmdList& rst);
	void updateRec(WznmQQmdList* rec);
	void updateRst(ListWznmQQmdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQmdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQmdList& rst);
};
#endif

#endif
