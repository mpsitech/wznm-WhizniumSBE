/**
	* \file WznmQFilList.h
	* Dbs and XML wrapper for table TblWznmQFilList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQFILLIST_H
#define WZNMQFILLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQFilList: record of TblWznmQFilList
	*/
class WznmQFilList {

public:
	WznmQFilList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::uint Size = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Filename;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::uint Size;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQFilList: recordset of TblWznmQFilList
	*/
class ListWznmQFilList {

public:
	ListWznmQFilList();
	ListWznmQFilList(const ListWznmQFilList& src);
	~ListWznmQFilList();

	void clear();
	unsigned int size() const;
	void append(WznmQFilList* rec);

	ListWznmQFilList& operator=(const ListWznmQFilList& src);

public:
	std::vector<WznmQFilList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQFilList: C++ wrapper for table TblWznmQFilList
	*/
class TblWznmQFilList {

public:
	TblWznmQFilList();
	virtual ~TblWznmQFilList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQFilList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQFilList& rst);

	virtual Sbecore::ubigint insertRec(WznmQFilList* rec);
	Sbecore::ubigint insertNewRec(WznmQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::uint Size = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQFilList& rst, WznmQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::uint Size = 0);
	virtual void insertRst(ListWznmQFilList& rst);
	virtual void updateRec(WznmQFilList* rec);
	virtual void updateRst(ListWznmQFilList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQFilList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQFilList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQFilList: C++ wrapper for table TblWznmQFilList (MySQL database)
	*/
class MyTblWznmQFilList : public TblWznmQFilList, public Sbecore::MyTable {

public:
	MyTblWznmQFilList();
	~MyTblWznmQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQFilList& rst);

	Sbecore::ubigint insertRec(WznmQFilList* rec);
	void insertRst(ListWznmQFilList& rst);
	void updateRec(WznmQFilList* rec);
	void updateRst(ListWznmQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQFilList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQFilList: C++ wrapper for table TblWznmQFilList (PgSQL database)
	*/
class PgTblWznmQFilList : public TblWznmQFilList, public Sbecore::PgTable {

public:
	PgTblWznmQFilList();
	~PgTblWznmQFilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQFilList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQFilList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQFilList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQFilList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQFilList& rst);

	Sbecore::ubigint insertRec(WznmQFilList* rec);
	void insertRst(ListWznmQFilList& rst);
	void updateRec(WznmQFilList* rec);
	void updateRst(ListWznmQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQFilList& rst);
};
#endif

#endif

