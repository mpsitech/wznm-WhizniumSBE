/**
	* \file WznmQLibList.h
	* Dbs and XML wrapper for table TblWznmQLibList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLIBLIST_H
#define WZNMQLIBLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLibList: record of TblWznmQLibList
	*/
class WznmQLibList {

public:
	WznmQLibList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string titSrefKLictype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string Version;
	std::string srefKLictype;
	std::string titSrefKLictype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQLibList: recordset of TblWznmQLibList
	*/
class ListWznmQLibList {

public:
	ListWznmQLibList();
	ListWznmQLibList(const ListWznmQLibList& src);
	~ListWznmQLibList();

	void clear();
	unsigned int size() const;
	void append(WznmQLibList* rec);

	ListWznmQLibList& operator=(const ListWznmQLibList& src);

public:
	std::vector<WznmQLibList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLibList: C++ wrapper for table TblWznmQLibList
	*/
class TblWznmQLibList {

public:
	TblWznmQLibList();
	virtual ~TblWznmQLibList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLibList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibList& rst);

	virtual Sbecore::ubigint insertRec(WznmQLibList* rec);
	Sbecore::ubigint insertNewRec(WznmQLibList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string titSrefKLictype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQLibList& rst, WznmQLibList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string titSrefKLictype = "");
	virtual void insertRst(ListWznmQLibList& rst);
	virtual void updateRec(WznmQLibList* rec);
	virtual void updateRst(ListWznmQLibList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLibList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLibList: C++ wrapper for table TblWznmQLibList (MySQL database)
	*/
class MyTblWznmQLibList : public TblWznmQLibList, public Sbecore::MyTable {

public:
	MyTblWznmQLibList();
	~MyTblWznmQLibList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibList& rst);

	Sbecore::ubigint insertRec(WznmQLibList* rec);
	void insertRst(ListWznmQLibList& rst);
	void updateRec(WznmQLibList* rec);
	void updateRst(ListWznmQLibList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLibList: C++ wrapper for table TblWznmQLibList (PgSQL database)
	*/
class PgTblWznmQLibList : public TblWznmQLibList, public Sbecore::PgTable {

public:
	PgTblWznmQLibList();
	~PgTblWznmQLibList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLibList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLibList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLibList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLibList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibList& rst);

	Sbecore::ubigint insertRec(WznmQLibList* rec);
	void insertRst(ListWznmQLibList& rst);
	void updateRec(WznmQLibList* rec);
	void updateRst(ListWznmQLibList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibList& rst);
};
#endif

#endif

