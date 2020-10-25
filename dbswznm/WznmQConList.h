/**
	* \file WznmQConList.h
	* Dbs and XML wrapper for table TblWznmQConList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQCONLIST_H
#define WZNMQCONLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQConList: record of TblWznmQConList
	*/
class WznmQConList {

public:
	WznmQConList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const Sbecore::uint hkIxVSection = 0, const std::string srefHkIxVSection = "", const std::string titHkIxVSection = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint supRefWznmMControl = 0, const std::string stubSupRefWznmMControl = "", const Sbecore::uint ixVSubtype = 0, const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "");

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
	Sbecore::uint hkIxVTbl;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	Sbecore::ubigint hkUref;
	std::string stubHkUref;
	Sbecore::uint hkIxVSection;
	std::string srefHkIxVSection;
	std::string titHkIxVSection;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	Sbecore::ubigint supRefWznmMControl;
	std::string stubSupRefWznmMControl;
	Sbecore::uint ixVSubtype;
	std::string srefIxVSubtype;
	std::string titIxVSubtype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQConList: recordset of TblWznmQConList
	*/
class ListWznmQConList {

public:
	ListWznmQConList();
	ListWznmQConList(const ListWznmQConList& src);
	~ListWznmQConList();

	void clear();
	unsigned int size() const;
	void append(WznmQConList* rec);

	ListWznmQConList& operator=(const ListWznmQConList& src);

public:
	std::vector<WznmQConList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQConList: C++ wrapper for table TblWznmQConList
	*/
class TblWznmQConList {

public:
	TblWznmQConList();
	virtual ~TblWznmQConList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQConList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConList& rst);

	virtual Sbecore::ubigint insertRec(WznmQConList* rec);
	Sbecore::ubigint insertNewRec(WznmQConList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const Sbecore::uint hkIxVSection = 0, const std::string srefHkIxVSection = "", const std::string titHkIxVSection = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint supRefWznmMControl = 0, const std::string stubSupRefWznmMControl = "", const Sbecore::uint ixVSubtype = 0, const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQConList& rst, WznmQConList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::uint hkIxVTbl = 0, const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const Sbecore::ubigint hkUref = 0, const std::string stubHkUref = "", const Sbecore::uint hkIxVSection = 0, const std::string srefHkIxVSection = "", const std::string titHkIxVSection = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::ubigint supRefWznmMControl = 0, const std::string stubSupRefWznmMControl = "", const Sbecore::uint ixVSubtype = 0, const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "");
	virtual void insertRst(ListWznmQConList& rst);
	virtual void updateRec(WznmQConList* rec);
	virtual void updateRst(ListWznmQConList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQConList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQConList: C++ wrapper for table TblWznmQConList (MySQL database)
	*/
class MyTblWznmQConList : public TblWznmQConList, public Sbecore::MyTable {

public:
	MyTblWznmQConList();
	~MyTblWznmQConList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConList& rst);

	Sbecore::ubigint insertRec(WznmQConList* rec);
	void insertRst(ListWznmQConList& rst);
	void updateRec(WznmQConList* rec);
	void updateRst(ListWznmQConList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQConList: C++ wrapper for table TblWznmQConList (PgSQL database)
	*/
class PgTblWznmQConList : public TblWznmQConList, public Sbecore::PgTable {

public:
	PgTblWznmQConList();
	~PgTblWznmQConList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQConList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQConList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQConList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQConList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConList& rst);

	Sbecore::ubigint insertRec(WznmQConList* rec);
	void insertRst(ListWznmQConList& rst);
	void updateRec(WznmQConList* rec);
	void updateRst(ListWznmQConList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConList& rst);
};
#endif

#endif

