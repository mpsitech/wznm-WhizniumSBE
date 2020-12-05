/**
	* \file WznmQVecList.h
	* Dbs and XML wrapper for table TblWznmQVecList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECLIST_H
#define WZNMQVECLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecList: record of TblWznmQVecList
	*/
class WznmQVecList {

public:
	WznmQVecList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::uint hkIxVTbl;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	Sbecore::ubigint hkUref;
	std::string stubHkUref;
	std::string osrefWznmKTaggrp;
	std::string titOsrefWznmKTaggrp;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVecList: recordset of TblWznmQVecList
	*/
class ListWznmQVecList {

public:
	ListWznmQVecList();
	ListWznmQVecList(const ListWznmQVecList& src);
	~ListWznmQVecList();

	void clear();
	unsigned int size() const;
	void append(WznmQVecList* rec);

	ListWznmQVecList& operator=(const ListWznmQVecList& src);

public:
	std::vector<WznmQVecList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecList: C++ wrapper for table TblWznmQVecList
	*/
class TblWznmQVecList {

public:
	TblWznmQVecList();
	virtual ~TblWznmQVecList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecList& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecList* rec);
	Sbecore::ubigint insertNewRec(WznmQVecList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecList& rst, WznmQVecList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const std::string osrefWznmKTaggrp = "", const std::string titOsrefWznmKTaggrp = "");
	virtual void insertRst(ListWznmQVecList& rst);
	virtual void updateRec(WznmQVecList* rec);
	virtual void updateRst(ListWznmQVecList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecList: C++ wrapper for table TblWznmQVecList (MySQL database)
	*/
class MyTblWznmQVecList : public TblWznmQVecList, public Sbecore::MyTable {

public:
	MyTblWznmQVecList();
	~MyTblWznmQVecList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecList& rst);

	Sbecore::ubigint insertRec(WznmQVecList* rec);
	void insertRst(ListWznmQVecList& rst);
	void updateRec(WznmQVecList* rec);
	void updateRst(ListWznmQVecList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecList: C++ wrapper for table TblWznmQVecList (PgSQL database)
	*/
class PgTblWznmQVecList : public TblWznmQVecList, public Sbecore::PgTable {

public:
	PgTblWznmQVecList();
	~PgTblWznmQVecList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecList& rst);

	Sbecore::ubigint insertRec(WznmQVecList* rec);
	void insertRst(ListWznmQVecList& rst);
	void updateRec(WznmQVecList* rec);
	void updateRst(ListWznmQVecList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecList& rst);
};
#endif

#endif

