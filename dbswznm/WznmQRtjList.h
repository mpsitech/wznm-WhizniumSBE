/**
	* \file WznmQRtjList.h
	* Dbs and XML wrapper for table TblWznmQRtjList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRTJLIST_H
#define WZNMQRTJLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRtjList: record of TblWznmQRtjList
	*/
class WznmQRtjList {

public:
	WznmQRtjList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMApp = 0, const std::string stubRefWznmMApp = "", const Sbecore::ubigint supRefWznmMRtjob = 0, const std::string stubSupRefWznmMRtjob = "", const Sbecore::ubigint refWznmMJob = 0, const std::string stubRefWznmMJob = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMApp;
	std::string stubRefWznmMApp;
	Sbecore::ubigint supRefWznmMRtjob;
	std::string stubSupRefWznmMRtjob;
	Sbecore::ubigint refWznmMJob;
	std::string stubRefWznmMJob;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQRtjList: recordset of TblWznmQRtjList
	*/
class ListWznmQRtjList {

public:
	ListWznmQRtjList();
	ListWznmQRtjList(const ListWznmQRtjList& src);
	~ListWznmQRtjList();

	void clear();
	unsigned int size() const;
	void append(WznmQRtjList* rec);

	ListWznmQRtjList& operator=(const ListWznmQRtjList& src);

public:
	std::vector<WznmQRtjList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRtjList: C++ wrapper for table TblWznmQRtjList
	*/
class TblWznmQRtjList {

public:
	TblWznmQRtjList();
	virtual ~TblWznmQRtjList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRtjList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtjList& rst);

	virtual Sbecore::ubigint insertRec(WznmQRtjList* rec);
	Sbecore::ubigint insertNewRec(WznmQRtjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMApp = 0, const std::string stubRefWznmMApp = "", const Sbecore::ubigint supRefWznmMRtjob = 0, const std::string stubSupRefWznmMRtjob = "", const Sbecore::ubigint refWznmMJob = 0, const std::string stubRefWznmMJob = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRtjList& rst, WznmQRtjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMApp = 0, const std::string stubRefWznmMApp = "", const Sbecore::ubigint supRefWznmMRtjob = 0, const std::string stubSupRefWznmMRtjob = "", const Sbecore::ubigint refWznmMJob = 0, const std::string stubRefWznmMJob = "");
	virtual void insertRst(ListWznmQRtjList& rst);
	virtual void updateRec(WznmQRtjList* rec);
	virtual void updateRst(ListWznmQRtjList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRtjList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtjList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRtjList: C++ wrapper for table TblWznmQRtjList (MySQL database)
	*/
class MyTblWznmQRtjList : public TblWznmQRtjList, public Sbecore::MyTable {

public:
	MyTblWznmQRtjList();
	~MyTblWznmQRtjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtjList& rst);

	Sbecore::ubigint insertRec(WznmQRtjList* rec);
	void insertRst(ListWznmQRtjList& rst);
	void updateRec(WznmQRtjList* rec);
	void updateRst(ListWznmQRtjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtjList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRtjList: C++ wrapper for table TblWznmQRtjList (PgSQL database)
	*/
class PgTblWznmQRtjList : public TblWznmQRtjList, public Sbecore::PgTable {

public:
	PgTblWznmQRtjList();
	~PgTblWznmQRtjList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRtjList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRtjList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRtjList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRtjList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtjList& rst);

	Sbecore::ubigint insertRec(WznmQRtjList* rec);
	void insertRst(ListWznmQRtjList& rst);
	void updateRec(WznmQRtjList* rec);
	void updateRst(ListWznmQRtjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtjList& rst);
};
#endif

#endif
