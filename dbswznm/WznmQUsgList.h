/**
	* \file WznmQUsgList.h
	* Dbs and XML wrapper for table TblWznmQUsgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSGLIST_H
#define WZNMQUSGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsgList: record of TblWznmQUsgList
	*/
class WznmQUsgList {

public:
	WznmQUsgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string sref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQUsgList: recordset of TblWznmQUsgList
	*/
class ListWznmQUsgList {

public:
	ListWznmQUsgList();
	ListWznmQUsgList(const ListWznmQUsgList& src);
	~ListWznmQUsgList();

	void clear();
	unsigned int size() const;
	void append(WznmQUsgList* rec);

	ListWznmQUsgList& operator=(const ListWznmQUsgList& src);

public:
	std::vector<WznmQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsgList: C++ wrapper for table TblWznmQUsgList
	*/
class TblWznmQUsgList {

public:
	TblWznmQUsgList();
	virtual ~TblWznmQUsgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgList& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsgList* rec);
	Sbecore::ubigint insertNewRec(WznmQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsgList& rst, WznmQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	virtual void insertRst(ListWznmQUsgList& rst);
	virtual void updateRec(WznmQUsgList* rec);
	virtual void updateRst(ListWznmQUsgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsgList: C++ wrapper for table TblWznmQUsgList (MySQL database)
	*/
class MyTblWznmQUsgList : public TblWznmQUsgList, public Sbecore::MyTable {

public:
	MyTblWznmQUsgList();
	~MyTblWznmQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgList& rst);

	Sbecore::ubigint insertRec(WznmQUsgList* rec);
	void insertRst(ListWznmQUsgList& rst);
	void updateRec(WznmQUsgList* rec);
	void updateRst(ListWznmQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsgList: C++ wrapper for table TblWznmQUsgList (PgSQL database)
	*/
class PgTblWznmQUsgList : public TblWznmQUsgList, public Sbecore::PgTable {

public:
	PgTblWznmQUsgList();
	~PgTblWznmQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsgList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsgList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsgList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgList& rst);

	Sbecore::ubigint insertRec(WznmQUsgList* rec);
	void insertRst(ListWznmQUsgList& rst);
	void updateRec(WznmQUsgList* rec);
	void updateRst(ListWznmQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgList& rst);
};
#endif

#endif

