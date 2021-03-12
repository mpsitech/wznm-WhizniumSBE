/**
	* \file WznmQUsrList.h
	* Dbs and XML wrapper for table TblWznmQUsrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSRLIST_H
#define WZNMQUSRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsrList: record of TblWznmQUsrList
	*/
class WznmQUsrList {

public:
	WznmQUsrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWznmMPerson = 0, const std::string stubRefWznmMPerson = "", const std::string sref = "", const Sbecore::ubigint refWznmMUsergroup = 0, const std::string stubRefWznmMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWznmVLocale = 0, const std::string srefIxWznmVLocale = "", const std::string titIxWznmVLocale = "", const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refWznmMPerson;
	std::string stubRefWznmMPerson;
	std::string sref;
	Sbecore::ubigint refWznmMUsergroup;
	std::string stubRefWznmMUsergroup;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;
	Sbecore::uint ixWznmVLocale;
	std::string srefIxWznmVLocale;
	std::string titIxWznmVLocale;
	Sbecore::uint ixWznmVUserlevel;
	std::string srefIxWznmVUserlevel;
	std::string titIxWznmVUserlevel;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQUsrList: recordset of TblWznmQUsrList
	*/
class ListWznmQUsrList {

public:
	ListWznmQUsrList();
	ListWznmQUsrList(const ListWznmQUsrList& src);
	~ListWznmQUsrList();

	void clear();
	unsigned int size() const;
	void append(WznmQUsrList* rec);

	ListWznmQUsrList& operator=(const ListWznmQUsrList& src);

public:
	std::vector<WznmQUsrList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsrList: C++ wrapper for table TblWznmQUsrList
	*/
class TblWznmQUsrList {

public:
	TblWznmQUsrList();
	virtual ~TblWznmQUsrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrList& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsrList* rec);
	Sbecore::ubigint insertNewRec(WznmQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWznmMPerson = 0, const std::string stubRefWznmMPerson = "", const std::string sref = "", const Sbecore::ubigint refWznmMUsergroup = 0, const std::string stubRefWznmMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWznmVLocale = 0, const std::string srefIxWznmVLocale = "", const std::string titIxWznmVLocale = "", const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsrList& rst, WznmQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWznmMPerson = 0, const std::string stubRefWznmMPerson = "", const std::string sref = "", const Sbecore::ubigint refWznmMUsergroup = 0, const std::string stubRefWznmMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWznmVLocale = 0, const std::string srefIxWznmVLocale = "", const std::string titIxWznmVLocale = "", const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");
	virtual void insertRst(ListWznmQUsrList& rst);
	virtual void updateRec(WznmQUsrList* rec);
	virtual void updateRst(ListWznmQUsrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsrList: C++ wrapper for table TblWznmQUsrList (MySQL database)
	*/
class MyTblWznmQUsrList : public TblWznmQUsrList, public Sbecore::MyTable {

public:
	MyTblWznmQUsrList();
	~MyTblWznmQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrList& rst);

	Sbecore::ubigint insertRec(WznmQUsrList* rec);
	void insertRst(ListWznmQUsrList& rst);
	void updateRec(WznmQUsrList* rec);
	void updateRst(ListWznmQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsrList: C++ wrapper for table TblWznmQUsrList (PgSQL database)
	*/
class PgTblWznmQUsrList : public TblWznmQUsrList, public Sbecore::PgTable {

public:
	PgTblWznmQUsrList();
	~PgTblWznmQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrList& rst);

	Sbecore::ubigint insertRec(WznmQUsrList* rec);
	void insertRst(ListWznmQUsrList& rst);
	void updateRec(WznmQUsrList* rec);
	void updateRst(ListWznmQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrList& rst);
};
#endif

#endif
