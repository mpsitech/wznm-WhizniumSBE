/**
	* \file WznmQQcoList.h
	* Dbs and XML wrapper for table TblWznmQQcoList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQQCOLIST_H
#define WZNMQQCOLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQcoList: record of TblWznmQQcoList
	*/
class WznmQQcoList {

public:
	WznmQQcoList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint qryRefWznmMQuery = 0, const std::string stubQryRefWznmMQuery = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "");

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
	Sbecore::ubigint qryRefWznmMQuery;
	std::string stubQryRefWznmMQuery;
	Sbecore::ubigint refWznmMTablecol;
	std::string stubRefWznmMTablecol;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQcoList: recordset of TblWznmQQcoList
	*/
class ListWznmQQcoList {

public:
	ListWznmQQcoList();
	ListWznmQQcoList(const ListWznmQQcoList& src);
	~ListWznmQQcoList();

	void clear();
	unsigned int size() const;
	void append(WznmQQcoList* rec);

	ListWznmQQcoList& operator=(const ListWznmQQcoList& src);

public:
	std::vector<WznmQQcoList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQcoList: C++ wrapper for table TblWznmQQcoList
	*/
class TblWznmQQcoList {

public:
	TblWznmQQcoList();
	virtual ~TblWznmQQcoList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQcoList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQcoList& rst);

	virtual Sbecore::ubigint insertRec(WznmQQcoList* rec);
	Sbecore::ubigint insertNewRec(WznmQQcoList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint qryRefWznmMQuery = 0, const std::string stubQryRefWznmMQuery = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQcoList& rst, WznmQQcoList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint qryRefWznmMQuery = 0, const std::string stubQryRefWznmMQuery = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "");
	virtual void insertRst(ListWznmQQcoList& rst);
	virtual void updateRec(WznmQQcoList* rec);
	virtual void updateRst(ListWznmQQcoList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQcoList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQcoList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQcoList: C++ wrapper for table TblWznmQQcoList (MySQL database)
	*/
class MyTblWznmQQcoList : public TblWznmQQcoList, public Sbecore::MyTable {

public:
	MyTblWznmQQcoList();
	~MyTblWznmQQcoList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQcoList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQcoList& rst);

	Sbecore::ubigint insertRec(WznmQQcoList* rec);
	void insertRst(ListWznmQQcoList& rst);
	void updateRec(WznmQQcoList* rec);
	void updateRst(ListWznmQQcoList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQcoList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQcoList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQcoList: C++ wrapper for table TblWznmQQcoList (PgSQL database)
	*/
class PgTblWznmQQcoList : public TblWznmQQcoList, public Sbecore::PgTable {

public:
	PgTblWznmQQcoList();
	~PgTblWznmQQcoList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQcoList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQcoList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQcoList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQcoList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQcoList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQcoList& rst);

	Sbecore::ubigint insertRec(WznmQQcoList* rec);
	void insertRst(ListWznmQQcoList& rst);
	void updateRec(WznmQQcoList* rec);
	void updateRst(ListWznmQQcoList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQcoList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQcoList& rst);
};
#endif

#endif

