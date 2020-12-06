/**
	* \file WznmQDlgList.h
	* Dbs and XML wrapper for table TblWznmQDlgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQDLGLIST_H
#define WZNMQDLGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQDlgList: record of TblWznmQDlgList
	*/
class WznmQDlgList {

public:
	WznmQDlgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMCard = 0, const std::string stubRefWznmMCard = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMCard;
	std::string stubRefWznmMCard;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQDlgList: recordset of TblWznmQDlgList
	*/
class ListWznmQDlgList {

public:
	ListWznmQDlgList();
	ListWznmQDlgList(const ListWznmQDlgList& src);
	~ListWznmQDlgList();

	void clear();
	unsigned int size() const;
	void append(WznmQDlgList* rec);

	ListWznmQDlgList& operator=(const ListWznmQDlgList& src);

public:
	std::vector<WznmQDlgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQDlgList: C++ wrapper for table TblWznmQDlgList
	*/
class TblWznmQDlgList {

public:
	TblWznmQDlgList();
	virtual ~TblWznmQDlgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQDlgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgList& rst);

	virtual Sbecore::ubigint insertRec(WznmQDlgList* rec);
	Sbecore::ubigint insertNewRec(WznmQDlgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMCard = 0, const std::string stubRefWznmMCard = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQDlgList& rst, WznmQDlgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMCard = 0, const std::string stubRefWznmMCard = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWznmQDlgList& rst);
	virtual void updateRec(WznmQDlgList* rec);
	virtual void updateRst(ListWznmQDlgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQDlgList: C++ wrapper for table TblWznmQDlgList (MySQL database)
	*/
class MyTblWznmQDlgList : public TblWznmQDlgList, public Sbecore::MyTable {

public:
	MyTblWznmQDlgList();
	~MyTblWznmQDlgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgList& rst);

	Sbecore::ubigint insertRec(WznmQDlgList* rec);
	void insertRst(ListWznmQDlgList& rst);
	void updateRec(WznmQDlgList* rec);
	void updateRst(ListWznmQDlgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQDlgList: C++ wrapper for table TblWznmQDlgList (PgSQL database)
	*/
class PgTblWznmQDlgList : public TblWznmQDlgList, public Sbecore::PgTable {

public:
	PgTblWznmQDlgList();
	~PgTblWznmQDlgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQDlgList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQDlgList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQDlgList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQDlgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgList& rst);

	Sbecore::ubigint insertRec(WznmQDlgList* rec);
	void insertRst(ListWznmQDlgList& rst);
	void updateRec(WznmQDlgList* rec);
	void updateRst(ListWznmQDlgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgList& rst);
};
#endif

#endif
