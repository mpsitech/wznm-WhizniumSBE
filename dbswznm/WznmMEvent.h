/**
	* \file WznmMEvent.h
	* database access for table TblWznmMEvent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMEVENT_H
#define WZNMMEVENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMEvent: record of TblWznmMEvent
	*/
class WznmMEvent {

public:
	WznmMEvent(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMApp = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMApp;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMEvent& comp);
	bool operator!=(const WznmMEvent& comp);
};

/**
	* ListWznmMEvent: recordset of TblWznmMEvent
	*/
class ListWznmMEvent {

public:
	ListWznmMEvent();
	ListWznmMEvent(const ListWznmMEvent& src);
	~ListWznmMEvent();

	void clear();
	unsigned int size() const;
	void append(WznmMEvent* rec);

	WznmMEvent* operator[](const Sbecore::uint ix);
	ListWznmMEvent& operator=(const ListWznmMEvent& src);
	bool operator==(const ListWznmMEvent& comp);
	bool operator!=(const ListWznmMEvent& comp);

public:
	std::vector<WznmMEvent*> nodes;
};

/**
	* TblWznmMEvent: C++ wrapper for table TblWznmMEvent
	*/
class TblWznmMEvent {

public:

public:
	TblWznmMEvent();
	virtual ~TblWznmMEvent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMEvent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMEvent& rst);

	virtual Sbecore::ubigint insertRec(WznmMEvent* rec);
	Sbecore::ubigint insertNewRec(WznmMEvent** rec = NULL, const Sbecore::ubigint refWznmMApp = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMEvent& rst, WznmMEvent** rec = NULL, const Sbecore::ubigint refWznmMApp = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMEvent& rst, bool transact = false);
	virtual void updateRec(WznmMEvent* rec);
	virtual void updateRst(ListWznmMEvent& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMEvent** rec);
	virtual Sbecore::ubigint loadRstByApp(Sbecore::ubigint refWznmMApp, const bool append, ListWznmMEvent& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMEvent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMEvent: C++ wrapper for table TblWznmMEvent (MySQL database)
	*/
class MyTblWznmMEvent : public TblWznmMEvent, public Sbecore::MyTable {

public:
	MyTblWznmMEvent();
	~MyTblWznmMEvent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMEvent& rst);

	Sbecore::ubigint insertRec(WznmMEvent* rec);
	void insertRst(ListWznmMEvent& rst, bool transact = false);
	void updateRec(WznmMEvent* rec);
	void updateRst(ListWznmMEvent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMEvent** rec);
	Sbecore::ubigint loadRstByApp(Sbecore::ubigint refWznmMApp, const bool append, ListWznmMEvent& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMEvent: C++ wrapper for table TblWznmMEvent (PgSQL database)
	*/
class PgTblWznmMEvent : public TblWznmMEvent, public Sbecore::PgTable {

public:
	PgTblWznmMEvent();
	~PgTblWznmMEvent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMEvent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMEvent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMEvent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMEvent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMEvent& rst);

	Sbecore::ubigint insertRec(WznmMEvent* rec);
	void insertRst(ListWznmMEvent& rst, bool transact = false);
	void updateRec(WznmMEvent* rec);
	void updateRst(ListWznmMEvent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMEvent** rec);
	Sbecore::ubigint loadRstByApp(Sbecore::ubigint refWznmMApp, const bool append, ListWznmMEvent& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

