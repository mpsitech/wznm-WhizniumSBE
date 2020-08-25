/**
	* \file WznmQTblList.h
	* Dbs and XML wrapper for table TblWznmQTblList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLLIST_H
#define WZNMQTBLLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblList: record of TblWznmQTblList
	*/
class WznmQTblList {

public:
	WznmQTblList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Short;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblList: recordset of TblWznmQTblList
	*/
class ListWznmQTblList {

public:
	ListWznmQTblList();
	ListWznmQTblList(const ListWznmQTblList& src);
	~ListWznmQTblList();

	void clear();
	unsigned int size() const;
	void append(WznmQTblList* rec);

	ListWznmQTblList& operator=(const ListWznmQTblList& src);

public:
	std::vector<WznmQTblList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblList: C++ wrapper for table TblWznmQTblList
	*/
class TblWznmQTblList {

public:
	TblWznmQTblList();
	virtual ~TblWznmQTblList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblList& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblList* rec);
	Sbecore::ubigint insertNewRec(WznmQTblList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblList& rst, WznmQTblList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWznmQTblList& rst);
	virtual void updateRec(WznmQTblList* rec);
	virtual void updateRst(ListWznmQTblList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblList: C++ wrapper for table TblWznmQTblList (MySQL database)
	*/
class MyTblWznmQTblList : public TblWznmQTblList, public Sbecore::MyTable {

public:
	MyTblWznmQTblList();
	~MyTblWznmQTblList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblList& rst);

	Sbecore::ubigint insertRec(WznmQTblList* rec);
	void insertRst(ListWznmQTblList& rst);
	void updateRec(WznmQTblList* rec);
	void updateRst(ListWznmQTblList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblList: C++ wrapper for table TblWznmQTblList (PgSQL database)
	*/
class PgTblWznmQTblList : public TblWznmQTblList, public Sbecore::PgTable {

public:
	PgTblWznmQTblList();
	~PgTblWznmQTblList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblList& rst);

	Sbecore::ubigint insertRec(WznmQTblList* rec);
	void insertRst(ListWznmQTblList& rst);
	void updateRec(WznmQTblList* rec);
	void updateRst(ListWznmQTblList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblList& rst);
};
#endif

#endif

