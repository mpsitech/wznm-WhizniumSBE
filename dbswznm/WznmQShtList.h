/**
	* \file WznmQShtList.h
	* Dbs and XML wrapper for table TblWznmQShtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQSHTLIST_H
#define WZNMQSHTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQShtList: record of TblWznmQShtList
	*/
class WznmQShtList {

public:
	WznmQShtList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint visRefWznmMVisual = 0, const std::string stubVisRefWznmMVisual = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string Title;
	Sbecore::ubigint visRefWznmMVisual;
	std::string stubVisRefWznmMVisual;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQShtList: recordset of TblWznmQShtList
	*/
class ListWznmQShtList {

public:
	ListWznmQShtList();
	ListWznmQShtList(const ListWznmQShtList& src);
	~ListWznmQShtList();

	void clear();
	unsigned int size() const;
	void append(WznmQShtList* rec);

	ListWznmQShtList& operator=(const ListWznmQShtList& src);

public:
	std::vector<WznmQShtList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQShtList: C++ wrapper for table TblWznmQShtList
	*/
class TblWznmQShtList {

public:
	TblWznmQShtList();
	virtual ~TblWznmQShtList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQShtList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQShtList& rst);

	virtual Sbecore::ubigint insertRec(WznmQShtList* rec);
	Sbecore::ubigint insertNewRec(WznmQShtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint visRefWznmMVisual = 0, const std::string stubVisRefWznmMVisual = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQShtList& rst, WznmQShtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint visRefWznmMVisual = 0, const std::string stubVisRefWznmMVisual = "");
	virtual void insertRst(ListWznmQShtList& rst);
	virtual void updateRec(WznmQShtList* rec);
	virtual void updateRst(ListWznmQShtList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQShtList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQShtList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQShtList: C++ wrapper for table TblWznmQShtList (MySQL database)
	*/
class MyTblWznmQShtList : public TblWznmQShtList, public Sbecore::MyTable {

public:
	MyTblWznmQShtList();
	~MyTblWznmQShtList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQShtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQShtList& rst);

	Sbecore::ubigint insertRec(WznmQShtList* rec);
	void insertRst(ListWznmQShtList& rst);
	void updateRec(WznmQShtList* rec);
	void updateRst(ListWznmQShtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQShtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQShtList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQShtList: C++ wrapper for table TblWznmQShtList (PgSQL database)
	*/
class PgTblWznmQShtList : public TblWznmQShtList, public Sbecore::PgTable {

public:
	PgTblWznmQShtList();
	~PgTblWznmQShtList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQShtList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQShtList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQShtList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQShtList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQShtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQShtList& rst);

	Sbecore::ubigint insertRec(WznmQShtList* rec);
	void insertRst(ListWznmQShtList& rst);
	void updateRec(WznmQShtList* rec);
	void updateRst(ListWznmQShtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQShtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQShtList& rst);
};
#endif

#endif
