/**
	* \file WznmQEvtList.h
	* Dbs and XML wrapper for table TblWznmQEvtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQEVTLIST_H
#define WZNMQEVTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQEvtList: record of TblWznmQEvtList
	*/
class WznmQEvtList {

public:
	WznmQEvtList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMApp = 0, const std::string stubRefWznmMApp = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMApp;
	std::string stubRefWznmMApp;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQEvtList: recordset of TblWznmQEvtList
	*/
class ListWznmQEvtList {

public:
	ListWznmQEvtList();
	ListWznmQEvtList(const ListWznmQEvtList& src);
	~ListWznmQEvtList();

	void clear();
	unsigned int size() const;
	void append(WznmQEvtList* rec);

	ListWznmQEvtList& operator=(const ListWznmQEvtList& src);

public:
	std::vector<WznmQEvtList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQEvtList: C++ wrapper for table TblWznmQEvtList
	*/
class TblWznmQEvtList {

public:
	TblWznmQEvtList();
	virtual ~TblWznmQEvtList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQEvtList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQEvtList& rst);

	virtual Sbecore::ubigint insertRec(WznmQEvtList* rec);
	Sbecore::ubigint insertNewRec(WznmQEvtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMApp = 0, const std::string stubRefWznmMApp = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQEvtList& rst, WznmQEvtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMApp = 0, const std::string stubRefWznmMApp = "");
	virtual void insertRst(ListWznmQEvtList& rst);
	virtual void updateRec(WznmQEvtList* rec);
	virtual void updateRst(ListWznmQEvtList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQEvtList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQEvtList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQEvtList: C++ wrapper for table TblWznmQEvtList (MySQL database)
	*/
class MyTblWznmQEvtList : public TblWznmQEvtList, public Sbecore::MyTable {

public:
	MyTblWznmQEvtList();
	~MyTblWznmQEvtList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQEvtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQEvtList& rst);

	Sbecore::ubigint insertRec(WznmQEvtList* rec);
	void insertRst(ListWznmQEvtList& rst);
	void updateRec(WznmQEvtList* rec);
	void updateRst(ListWznmQEvtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQEvtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQEvtList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQEvtList: C++ wrapper for table TblWznmQEvtList (PgSQL database)
	*/
class PgTblWznmQEvtList : public TblWznmQEvtList, public Sbecore::PgTable {

public:
	PgTblWznmQEvtList();
	~PgTblWznmQEvtList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQEvtList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQEvtList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQEvtList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQEvtList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQEvtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQEvtList& rst);

	Sbecore::ubigint insertRec(WznmQEvtList* rec);
	void insertRst(ListWznmQEvtList& rst);
	void updateRec(WznmQEvtList* rec);
	void updateRst(ListWznmQEvtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQEvtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQEvtList& rst);
};
#endif

#endif
