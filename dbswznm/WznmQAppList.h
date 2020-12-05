/**
	* \file WznmQAppList.h
	* Dbs and XML wrapper for table TblWznmQAppList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQAPPLIST_H
#define WZNMQAPPLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQAppList: record of TblWznmQAppList
	*/
class WznmQAppList {

public:
	WznmQAppList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::uint ixWznmVApptarget = 0, const std::string srefIxWznmVApptarget = "", const std::string titIxWznmVApptarget = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");

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
	Sbecore::uint ixWznmVApptarget;
	std::string srefIxWznmVApptarget;
	std::string titIxWznmVApptarget;
	Sbecore::ubigint verRefWznmMVersion;
	std::string stubVerRefWznmMVersion;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQAppList: recordset of TblWznmQAppList
	*/
class ListWznmQAppList {

public:
	ListWznmQAppList();
	ListWznmQAppList(const ListWznmQAppList& src);
	~ListWznmQAppList();

	void clear();
	unsigned int size() const;
	void append(WznmQAppList* rec);

	ListWznmQAppList& operator=(const ListWznmQAppList& src);

public:
	std::vector<WznmQAppList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQAppList: C++ wrapper for table TblWznmQAppList
	*/
class TblWznmQAppList {

public:
	TblWznmQAppList();
	virtual ~TblWznmQAppList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQAppList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppList& rst);

	virtual Sbecore::ubigint insertRec(WznmQAppList* rec);
	Sbecore::ubigint insertNewRec(WznmQAppList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::uint ixWznmVApptarget = 0, const std::string srefIxWznmVApptarget = "", const std::string titIxWznmVApptarget = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQAppList& rst, WznmQAppList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const Sbecore::uint ixWznmVApptarget = 0, const std::string srefIxWznmVApptarget = "", const std::string titIxWznmVApptarget = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	virtual void insertRst(ListWznmQAppList& rst);
	virtual void updateRec(WznmQAppList* rec);
	virtual void updateRst(ListWznmQAppList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQAppList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQAppList: C++ wrapper for table TblWznmQAppList (MySQL database)
	*/
class MyTblWznmQAppList : public TblWznmQAppList, public Sbecore::MyTable {

public:
	MyTblWznmQAppList();
	~MyTblWznmQAppList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQAppList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppList& rst);

	Sbecore::ubigint insertRec(WznmQAppList* rec);
	void insertRst(ListWznmQAppList& rst);
	void updateRec(WznmQAppList* rec);
	void updateRst(ListWznmQAppList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQAppList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQAppList: C++ wrapper for table TblWznmQAppList (PgSQL database)
	*/
class PgTblWznmQAppList : public TblWznmQAppList, public Sbecore::PgTable {

public:
	PgTblWznmQAppList();
	~PgTblWznmQAppList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQAppList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQAppList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQAppList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQAppList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQAppList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppList& rst);

	Sbecore::ubigint insertRec(WznmQAppList* rec);
	void insertRst(ListWznmQAppList& rst);
	void updateRec(WznmQAppList* rec);
	void updateRst(ListWznmQAppList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQAppList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppList& rst);
};
#endif

#endif

