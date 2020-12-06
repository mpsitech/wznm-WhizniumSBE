/**
	* \file WznmQTagList.h
	* Dbs and XML wrapper for table TblWznmQTagList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTAGLIST_H
#define WZNMQTAGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTagList: record of TblWznmQTagList
	*/
class WznmQTagList {

public:
	WznmQTagList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMCapability = 0, const std::string stubRefWznmMCapability = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint refWznmMCapability;
	std::string stubRefWznmMCapability;
	std::string osrefWznmKTaggrp;
	std::string titOsrefWznmKTaggrp;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTagList: recordset of TblWznmQTagList
	*/
class ListWznmQTagList {

public:
	ListWznmQTagList();
	ListWznmQTagList(const ListWznmQTagList& src);
	~ListWznmQTagList();

	void clear();
	unsigned int size() const;
	void append(WznmQTagList* rec);

	ListWznmQTagList& operator=(const ListWznmQTagList& src);

public:
	std::vector<WznmQTagList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTagList: C++ wrapper for table TblWznmQTagList
	*/
class TblWznmQTagList {

public:
	TblWznmQTagList();
	virtual ~TblWznmQTagList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTagList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTagList& rst);

	virtual Sbecore::ubigint insertRec(WznmQTagList* rec);
	Sbecore::ubigint insertNewRec(WznmQTagList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMCapability = 0, const std::string stubRefWznmMCapability = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTagList& rst, WznmQTagList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMCapability = 0, const std::string stubRefWznmMCapability = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");
	virtual void insertRst(ListWznmQTagList& rst);
	virtual void updateRec(WznmQTagList* rec);
	virtual void updateRst(ListWznmQTagList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTagList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTagList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTagList: C++ wrapper for table TblWznmQTagList (MySQL database)
	*/
class MyTblWznmQTagList : public TblWznmQTagList, public Sbecore::MyTable {

public:
	MyTblWznmQTagList();
	~MyTblWznmQTagList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTagList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTagList& rst);

	Sbecore::ubigint insertRec(WznmQTagList* rec);
	void insertRst(ListWznmQTagList& rst);
	void updateRec(WznmQTagList* rec);
	void updateRst(ListWznmQTagList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTagList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTagList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTagList: C++ wrapper for table TblWznmQTagList (PgSQL database)
	*/
class PgTblWznmQTagList : public TblWznmQTagList, public Sbecore::PgTable {

public:
	PgTblWznmQTagList();
	~PgTblWznmQTagList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTagList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTagList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTagList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTagList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTagList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTagList& rst);

	Sbecore::ubigint insertRec(WznmQTagList* rec);
	void insertRst(ListWznmQTagList& rst);
	void updateRec(WznmQTagList* rec);
	void updateRst(ListWznmQTagList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTagList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTagList& rst);
};
#endif

#endif
