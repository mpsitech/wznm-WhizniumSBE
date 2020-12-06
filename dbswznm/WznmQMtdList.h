/**
	* \file WznmQMtdList.h
	* Dbs and XML wrapper for table TblWznmQMtdList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMTDLIST_H
#define WZNMQMTDLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMtdList: record of TblWznmQMtdList
	*/
class WznmQMtdList {

public:
	WznmQMtdList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMJob = 0, const std::string stubRefWznmMJob = "", const bool Execsrv = false, const std::string yesnoExecsrv = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMJob;
	std::string stubRefWznmMJob;
	bool Execsrv;
	std::string yesnoExecsrv;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMtdList: recordset of TblWznmQMtdList
	*/
class ListWznmQMtdList {

public:
	ListWznmQMtdList();
	ListWznmQMtdList(const ListWznmQMtdList& src);
	~ListWznmQMtdList();

	void clear();
	unsigned int size() const;
	void append(WznmQMtdList* rec);

	ListWznmQMtdList& operator=(const ListWznmQMtdList& src);

public:
	std::vector<WznmQMtdList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMtdList: C++ wrapper for table TblWznmQMtdList
	*/
class TblWznmQMtdList {

public:
	TblWznmQMtdList();
	virtual ~TblWznmQMtdList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMtdList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdList& rst);

	virtual Sbecore::ubigint insertRec(WznmQMtdList* rec);
	Sbecore::ubigint insertNewRec(WznmQMtdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMJob = 0, const std::string stubRefWznmMJob = "", const bool Execsrv = false, const std::string yesnoExecsrv = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMtdList& rst, WznmQMtdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMJob = 0, const std::string stubRefWznmMJob = "", const bool Execsrv = false, const std::string yesnoExecsrv = "");
	virtual void insertRst(ListWznmQMtdList& rst);
	virtual void updateRec(WznmQMtdList* rec);
	virtual void updateRst(ListWznmQMtdList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMtdList: C++ wrapper for table TblWznmQMtdList (MySQL database)
	*/
class MyTblWznmQMtdList : public TblWznmQMtdList, public Sbecore::MyTable {

public:
	MyTblWznmQMtdList();
	~MyTblWznmQMtdList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdList& rst);

	Sbecore::ubigint insertRec(WznmQMtdList* rec);
	void insertRst(ListWznmQMtdList& rst);
	void updateRec(WznmQMtdList* rec);
	void updateRst(ListWznmQMtdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMtdList: C++ wrapper for table TblWznmQMtdList (PgSQL database)
	*/
class PgTblWznmQMtdList : public TblWznmQMtdList, public Sbecore::PgTable {

public:
	PgTblWznmQMtdList();
	~PgTblWznmQMtdList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMtdList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMtdList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMtdList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMtdList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdList& rst);

	Sbecore::ubigint insertRec(WznmQMtdList* rec);
	void insertRst(ListWznmQMtdList& rst);
	void updateRec(WznmQMtdList* rec);
	void updateRst(ListWznmQMtdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdList& rst);
};
#endif

#endif
