/**
	* \file WznmQVerList.h
	* Dbs and XML wrapper for table TblWznmQVerList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVERLIST_H
#define WZNMQVERLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerList: record of TblWznmQVerList
	*/
class WznmQVerList {

public:
	WznmQVerList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint prjRefWznmMProject = 0, const std::string stubPrjRefWznmMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bvrRefWznmMVersion = 0, const std::string stubBvrRefWznmMVersion = "", const Sbecore::ubigint refWznmMLocale = 0, const std::string stubRefWznmMLocale = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWDbmstype = 0, const std::string srefsIxWDbmstype = "", const std::string titsIxWDbmstype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint prjRefWznmMProject;
	std::string stubPrjRefWznmMProject;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	Sbecore::ubigint bvrRefWznmMVersion;
	std::string stubBvrRefWznmMVersion;
	Sbecore::ubigint refWznmMLocale;
	std::string stubRefWznmMLocale;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;
	Sbecore::uint ixWDbmstype;
	std::string srefsIxWDbmstype;
	std::string titsIxWDbmstype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVerList: recordset of TblWznmQVerList
	*/
class ListWznmQVerList {

public:
	ListWznmQVerList();
	ListWznmQVerList(const ListWznmQVerList& src);
	~ListWznmQVerList();

	void clear();
	unsigned int size() const;
	void append(WznmQVerList* rec);

	ListWznmQVerList& operator=(const ListWznmQVerList& src);

public:
	std::vector<WznmQVerList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerList: C++ wrapper for table TblWznmQVerList
	*/
class TblWznmQVerList {

public:
	TblWznmQVerList();
	virtual ~TblWznmQVerList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerList& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerList* rec);
	Sbecore::ubigint insertNewRec(WznmQVerList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint prjRefWznmMProject = 0, const std::string stubPrjRefWznmMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bvrRefWznmMVersion = 0, const std::string stubBvrRefWznmMVersion = "", const Sbecore::ubigint refWznmMLocale = 0, const std::string stubRefWznmMLocale = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWDbmstype = 0, const std::string srefsIxWDbmstype = "", const std::string titsIxWDbmstype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerList& rst, WznmQVerList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint prjRefWznmMProject = 0, const std::string stubPrjRefWznmMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint bvrRefWznmMVersion = 0, const std::string stubBvrRefWznmMVersion = "", const Sbecore::ubigint refWznmMLocale = 0, const std::string stubRefWznmMLocale = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWDbmstype = 0, const std::string srefsIxWDbmstype = "", const std::string titsIxWDbmstype = "");
	virtual void insertRst(ListWznmQVerList& rst);
	virtual void updateRec(WznmQVerList* rec);
	virtual void updateRst(ListWznmQVerList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerList: C++ wrapper for table TblWznmQVerList (MySQL database)
	*/
class MyTblWznmQVerList : public TblWznmQVerList, public Sbecore::MyTable {

public:
	MyTblWznmQVerList();
	~MyTblWznmQVerList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerList& rst);

	Sbecore::ubigint insertRec(WznmQVerList* rec);
	void insertRst(ListWznmQVerList& rst);
	void updateRec(WznmQVerList* rec);
	void updateRst(ListWznmQVerList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerList: C++ wrapper for table TblWznmQVerList (PgSQL database)
	*/
class PgTblWznmQVerList : public TblWznmQVerList, public Sbecore::PgTable {

public:
	PgTblWznmQVerList();
	~PgTblWznmQVerList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerList& rst);

	Sbecore::ubigint insertRec(WznmQVerList* rec);
	void insertRst(ListWznmQVerList& rst);
	void updateRec(WznmQVerList* rec);
	void updateRst(ListWznmQVerList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerList& rst);
};
#endif

#endif

