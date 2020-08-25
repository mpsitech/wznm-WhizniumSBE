/**
	* \file WznmQApp1NEvent.h
	* Dbs and XML wrapper for table TblWznmQApp1NEvent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQAPP1NEVENT_H
#define WZNMQAPP1NEVENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQApp1NEvent: record of TblWznmQApp1NEvent
	*/
class WznmQApp1NEvent {

public:
	WznmQApp1NEvent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQApp1NEvent: recordset of TblWznmQApp1NEvent
	*/
class ListWznmQApp1NEvent {

public:
	ListWznmQApp1NEvent();
	ListWznmQApp1NEvent(const ListWznmQApp1NEvent& src);
	~ListWznmQApp1NEvent();

	void clear();
	unsigned int size() const;
	void append(WznmQApp1NEvent* rec);

	ListWznmQApp1NEvent& operator=(const ListWznmQApp1NEvent& src);

public:
	std::vector<WznmQApp1NEvent*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQApp1NEvent: C++ wrapper for table TblWznmQApp1NEvent
	*/
class TblWznmQApp1NEvent {

public:
	TblWznmQApp1NEvent();
	virtual ~TblWznmQApp1NEvent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQApp1NEvent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQApp1NEvent& rst);

	virtual Sbecore::ubigint insertRec(WznmQApp1NEvent* rec);
	Sbecore::ubigint insertNewRec(WznmQApp1NEvent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQApp1NEvent& rst, WznmQApp1NEvent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQApp1NEvent& rst);
	virtual void updateRec(WznmQApp1NEvent* rec);
	virtual void updateRst(ListWznmQApp1NEvent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQApp1NEvent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQApp1NEvent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQApp1NEvent: C++ wrapper for table TblWznmQApp1NEvent (MySQL database)
	*/
class MyTblWznmQApp1NEvent : public TblWznmQApp1NEvent, public Sbecore::MyTable {

public:
	MyTblWznmQApp1NEvent();
	~MyTblWznmQApp1NEvent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQApp1NEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQApp1NEvent& rst);

	Sbecore::ubigint insertRec(WznmQApp1NEvent* rec);
	void insertRst(ListWznmQApp1NEvent& rst);
	void updateRec(WznmQApp1NEvent* rec);
	void updateRst(ListWznmQApp1NEvent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQApp1NEvent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQApp1NEvent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQApp1NEvent: C++ wrapper for table TblWznmQApp1NEvent (PgSQL database)
	*/
class PgTblWznmQApp1NEvent : public TblWznmQApp1NEvent, public Sbecore::PgTable {

public:
	PgTblWznmQApp1NEvent();
	~PgTblWznmQApp1NEvent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQApp1NEvent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQApp1NEvent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQApp1NEvent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQApp1NEvent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQApp1NEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQApp1NEvent& rst);

	Sbecore::ubigint insertRec(WznmQApp1NEvent* rec);
	void insertRst(ListWznmQApp1NEvent& rst);
	void updateRec(WznmQApp1NEvent* rec);
	void updateRst(ListWznmQApp1NEvent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQApp1NEvent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQApp1NEvent& rst);
};
#endif

#endif

