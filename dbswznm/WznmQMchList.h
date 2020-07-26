/**
	* \file WznmQMchList.h
	* Dbs and XML wrapper for table TblWznmQMchList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQMCHLIST_H
#define WZNMQMCHLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMchList: record of TblWznmQMchList
	*/
class WznmQMchList {

public:
	WznmQMchList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMMachtype = 0, const std::string stubRefWznmMMachtype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMMachtype;
	std::string stubRefWznmMMachtype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMchList: recordset of TblWznmQMchList
	*/
class ListWznmQMchList {

public:
	ListWznmQMchList();
	ListWznmQMchList(const ListWznmQMchList& src);
	~ListWznmQMchList();

	void clear();
	unsigned int size() const;
	void append(WznmQMchList* rec);

	ListWznmQMchList& operator=(const ListWznmQMchList& src);

public:
	std::vector<WznmQMchList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMchList: C++ wrapper for table TblWznmQMchList
	*/
class TblWznmQMchList {

public:
	TblWznmQMchList();
	virtual ~TblWznmQMchList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMchList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchList& rst);

	virtual Sbecore::ubigint insertRec(WznmQMchList* rec);
	Sbecore::ubigint insertNewRec(WznmQMchList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMMachtype = 0, const std::string stubRefWznmMMachtype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMchList& rst, WznmQMchList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMMachtype = 0, const std::string stubRefWznmMMachtype = "");
	virtual void insertRst(ListWznmQMchList& rst);
	virtual void updateRec(WznmQMchList* rec);
	virtual void updateRst(ListWznmQMchList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMchList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMchList: C++ wrapper for table TblWznmQMchList (MySQL database)
	*/
class MyTblWznmQMchList : public TblWznmQMchList, public Sbecore::MyTable {

public:
	MyTblWznmQMchList();
	~MyTblWznmQMchList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchList& rst);

	Sbecore::ubigint insertRec(WznmQMchList* rec);
	void insertRst(ListWznmQMchList& rst);
	void updateRec(WznmQMchList* rec);
	void updateRst(ListWznmQMchList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMchList: C++ wrapper for table TblWznmQMchList (PgSQL database)
	*/
class PgTblWznmQMchList : public TblWznmQMchList, public Sbecore::PgTable {

public:
	PgTblWznmQMchList();
	~PgTblWznmQMchList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMchList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMchList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMchList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMchList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchList& rst);

	Sbecore::ubigint insertRec(WznmQMchList* rec);
	void insertRst(ListWznmQMchList& rst);
	void updateRec(WznmQMchList* rec);
	void updateRst(ListWznmQMchList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchList& rst);
};
#endif

#endif

