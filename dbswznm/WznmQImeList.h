/**
	* \file WznmQImeList.h
	* Dbs and XML wrapper for table TblWznmQImeList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIMELIST_H
#define WZNMQIMELIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQImeList: record of TblWznmQImeList
	*/
class WznmQImeList {

public:
	WznmQImeList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMImpexpcplx = 0, const std::string stubRefWznmMImpexpcplx = "", const Sbecore::ubigint supRefWznmMImpexp = 0, const std::string stubSupRefWznmMImpexp = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMImpexpcplx;
	std::string stubRefWznmMImpexpcplx;
	Sbecore::ubigint supRefWznmMImpexp;
	std::string stubSupRefWznmMImpexp;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQImeList: recordset of TblWznmQImeList
	*/
class ListWznmQImeList {

public:
	ListWznmQImeList();
	ListWznmQImeList(const ListWznmQImeList& src);
	~ListWznmQImeList();

	void clear();
	unsigned int size() const;
	void append(WznmQImeList* rec);

	ListWznmQImeList& operator=(const ListWznmQImeList& src);

public:
	std::vector<WznmQImeList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQImeList: C++ wrapper for table TblWznmQImeList
	*/
class TblWznmQImeList {

public:
	TblWznmQImeList();
	virtual ~TblWznmQImeList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQImeList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeList& rst);

	virtual Sbecore::ubigint insertRec(WznmQImeList* rec);
	Sbecore::ubigint insertNewRec(WznmQImeList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMImpexpcplx = 0, const std::string stubRefWznmMImpexpcplx = "", const Sbecore::ubigint supRefWznmMImpexp = 0, const std::string stubSupRefWznmMImpexp = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQImeList& rst, WznmQImeList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMImpexpcplx = 0, const std::string stubRefWznmMImpexpcplx = "", const Sbecore::ubigint supRefWznmMImpexp = 0, const std::string stubSupRefWznmMImpexp = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "");
	virtual void insertRst(ListWznmQImeList& rst);
	virtual void updateRec(WznmQImeList* rec);
	virtual void updateRst(ListWznmQImeList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQImeList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQImeList: C++ wrapper for table TblWznmQImeList (MySQL database)
	*/
class MyTblWznmQImeList : public TblWznmQImeList, public Sbecore::MyTable {

public:
	MyTblWznmQImeList();
	~MyTblWznmQImeList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeList& rst);

	Sbecore::ubigint insertRec(WznmQImeList* rec);
	void insertRst(ListWznmQImeList& rst);
	void updateRec(WznmQImeList* rec);
	void updateRst(ListWznmQImeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQImeList: C++ wrapper for table TblWznmQImeList (PgSQL database)
	*/
class PgTblWznmQImeList : public TblWznmQImeList, public Sbecore::PgTable {

public:
	PgTblWznmQImeList();
	~PgTblWznmQImeList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQImeList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQImeList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQImeList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQImeList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeList& rst);

	Sbecore::ubigint insertRec(WznmQImeList* rec);
	void insertRst(ListWznmQImeList& rst);
	void updateRec(WznmQImeList* rec);
	void updateRst(ListWznmQImeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeList& rst);
};
#endif

#endif

