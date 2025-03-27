/**
	* \file WznmQBoxList.h
	* Dbs and XML wrapper for table TblWznmQBoxList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQBOXLIST_H
#define WZNMQBOXLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBoxList: record of TblWznmQBoxList
	*/
class WznmQBoxList {

public:
	WznmQBoxList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSheet = 0, const std::string stubRefWznmMSheet = "", const Sbecore::uint unvIxWznmVMaintable = 0, const std::string srefUnvIxWznmVMaintable = "", const std::string titUnvIxWznmVMaintable = "", const Sbecore::ubigint unvUref = 0, const std::string stubUnvUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMSheet;
	std::string stubRefWznmMSheet;
	Sbecore::uint unvIxWznmVMaintable;
	std::string srefUnvIxWznmVMaintable;
	std::string titUnvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	std::string stubUnvUref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQBoxList: recordset of TblWznmQBoxList
	*/
class ListWznmQBoxList {

public:
	ListWznmQBoxList();
	ListWznmQBoxList(const ListWznmQBoxList& src);
	~ListWznmQBoxList();

	void clear();
	unsigned int size() const;
	void append(WznmQBoxList* rec);

	ListWznmQBoxList& operator=(const ListWznmQBoxList& src);

public:
	std::vector<WznmQBoxList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBoxList: C++ wrapper for table TblWznmQBoxList
	*/
class TblWznmQBoxList {

public:
	TblWznmQBoxList();
	virtual ~TblWznmQBoxList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBoxList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxList& rst);

	virtual Sbecore::ubigint insertRec(WznmQBoxList* rec);
	Sbecore::ubigint insertNewRec(WznmQBoxList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSheet = 0, const std::string stubRefWznmMSheet = "", const Sbecore::uint unvIxWznmVMaintable = 0, const std::string srefUnvIxWznmVMaintable = "", const std::string titUnvIxWznmVMaintable = "", const Sbecore::ubigint unvUref = 0, const std::string stubUnvUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQBoxList& rst, WznmQBoxList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSheet = 0, const std::string stubRefWznmMSheet = "", const Sbecore::uint unvIxWznmVMaintable = 0, const std::string srefUnvIxWznmVMaintable = "", const std::string titUnvIxWznmVMaintable = "", const Sbecore::ubigint unvUref = 0, const std::string stubUnvUref = "");
	virtual void insertRst(ListWznmQBoxList& rst);
	virtual void updateRec(WznmQBoxList* rec);
	virtual void updateRst(ListWznmQBoxList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBoxList: C++ wrapper for table TblWznmQBoxList (MySQL database)
	*/
class MyTblWznmQBoxList : public TblWznmQBoxList, public Sbecore::MyTable {

public:
	MyTblWznmQBoxList();
	~MyTblWznmQBoxList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBoxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxList& rst);

	Sbecore::ubigint insertRec(WznmQBoxList* rec);
	void insertRst(ListWznmQBoxList& rst);
	void updateRec(WznmQBoxList* rec);
	void updateRst(ListWznmQBoxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBoxList: C++ wrapper for table TblWznmQBoxList (PgSQL database)
	*/
class PgTblWznmQBoxList : public TblWznmQBoxList, public Sbecore::PgTable {

public:
	PgTblWznmQBoxList();
	~PgTblWznmQBoxList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBoxList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBoxList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBoxList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBoxList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBoxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxList& rst);

	Sbecore::ubigint insertRec(WznmQBoxList* rec);
	void insertRst(ListWznmQBoxList& rst);
	void updateRec(WznmQBoxList* rec);
	void updateRst(ListWznmQBoxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxList& rst);
};
#endif

#endif
