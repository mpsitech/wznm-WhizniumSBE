/**
	* \file WznmQCmpList.h
	* Dbs and XML wrapper for table TblWznmQCmpList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCMPLIST_H
#define WZNMQCMPLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCmpList: record of TblWznmQCmpList
	*/
class WznmQCmpList {

public:
	WznmQCmpList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCmpList: recordset of TblWznmQCmpList
	*/
class ListWznmQCmpList {

public:
	ListWznmQCmpList();
	ListWznmQCmpList(const ListWznmQCmpList& src);
	~ListWznmQCmpList();

	void clear();
	unsigned int size() const;
	void append(WznmQCmpList* rec);

	ListWznmQCmpList& operator=(const ListWznmQCmpList& src);

public:
	std::vector<WznmQCmpList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCmpList: C++ wrapper for table TblWznmQCmpList
	*/
class TblWznmQCmpList {

public:
	TblWznmQCmpList();
	virtual ~TblWznmQCmpList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCmpList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpList& rst);

	virtual Sbecore::ubigint insertRec(WznmQCmpList* rec);
	Sbecore::ubigint insertNewRec(WznmQCmpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCmpList& rst, WznmQCmpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "");
	virtual void insertRst(ListWznmQCmpList& rst);
	virtual void updateRec(WznmQCmpList* rec);
	virtual void updateRst(ListWznmQCmpList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCmpList: C++ wrapper for table TblWznmQCmpList (MySQL database)
	*/
class MyTblWznmQCmpList : public TblWznmQCmpList, public Sbecore::MyTable {

public:
	MyTblWznmQCmpList();
	~MyTblWznmQCmpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpList& rst);

	Sbecore::ubigint insertRec(WznmQCmpList* rec);
	void insertRst(ListWznmQCmpList& rst);
	void updateRec(WznmQCmpList* rec);
	void updateRst(ListWznmQCmpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCmpList: C++ wrapper for table TblWznmQCmpList (PgSQL database)
	*/
class PgTblWznmQCmpList : public TblWznmQCmpList, public Sbecore::PgTable {

public:
	PgTblWznmQCmpList();
	~PgTblWznmQCmpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCmpList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCmpList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCmpList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCmpList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpList& rst);

	Sbecore::ubigint insertRec(WznmQCmpList* rec);
	void insertRst(ListWznmQCmpList& rst);
	void updateRec(WznmQCmpList* rec);
	void updateRst(ListWznmQCmpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpList& rst);
};
#endif

#endif

