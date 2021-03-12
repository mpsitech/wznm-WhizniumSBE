/**
	* \file WznmQPrjList.h
	* Dbs and XML wrapper for table TblWznmQPrjList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRJLIST_H
#define WZNMQPRJLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrjList: record of TblWznmQPrjList
	*/
class WznmQPrjList {

public:
	WznmQPrjList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const std::string Giturl = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Short;
	std::string Title;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	std::string Giturl;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPrjList: recordset of TblWznmQPrjList
	*/
class ListWznmQPrjList {

public:
	ListWznmQPrjList();
	ListWznmQPrjList(const ListWznmQPrjList& src);
	~ListWznmQPrjList();

	void clear();
	unsigned int size() const;
	void append(WznmQPrjList* rec);

	ListWznmQPrjList& operator=(const ListWznmQPrjList& src);

public:
	std::vector<WznmQPrjList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrjList: C++ wrapper for table TblWznmQPrjList
	*/
class TblWznmQPrjList {

public:
	TblWznmQPrjList();
	virtual ~TblWznmQPrjList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrjList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjList& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrjList* rec);
	Sbecore::ubigint insertNewRec(WznmQPrjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const std::string Giturl = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrjList& rst, WznmQPrjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const std::string Giturl = "");
	virtual void insertRst(ListWznmQPrjList& rst);
	virtual void updateRec(WznmQPrjList* rec);
	virtual void updateRst(ListWznmQPrjList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrjList: C++ wrapper for table TblWznmQPrjList (MySQL database)
	*/
class MyTblWznmQPrjList : public TblWznmQPrjList, public Sbecore::MyTable {

public:
	MyTblWznmQPrjList();
	~MyTblWznmQPrjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjList& rst);

	Sbecore::ubigint insertRec(WznmQPrjList* rec);
	void insertRst(ListWznmQPrjList& rst);
	void updateRec(WznmQPrjList* rec);
	void updateRst(ListWznmQPrjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrjList: C++ wrapper for table TblWznmQPrjList (PgSQL database)
	*/
class PgTblWznmQPrjList : public TblWznmQPrjList, public Sbecore::PgTable {

public:
	PgTblWznmQPrjList();
	~PgTblWznmQPrjList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrjList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrjList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrjList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrjList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjList& rst);

	Sbecore::ubigint insertRec(WznmQPrjList* rec);
	void insertRst(ListWznmQPrjList& rst);
	void updateRec(WznmQPrjList* rec);
	void updateRst(ListWznmQPrjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjList& rst);
};
#endif

#endif
