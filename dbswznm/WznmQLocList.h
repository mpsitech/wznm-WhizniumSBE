/**
	* \file WznmQLocList.h
	* Dbs and XML wrapper for table TblWznmQLocList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQLOCLIST_H
#define WZNMQLOCLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLocList: record of TblWznmQLocList
	*/
class WznmQLocList {

public:
	WznmQLocList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQLocList: recordset of TblWznmQLocList
	*/
class ListWznmQLocList {

public:
	ListWznmQLocList();
	ListWznmQLocList(const ListWznmQLocList& src);
	~ListWznmQLocList();

	void clear();
	unsigned int size() const;
	void append(WznmQLocList* rec);

	ListWznmQLocList& operator=(const ListWznmQLocList& src);

public:
	std::vector<WznmQLocList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLocList: C++ wrapper for table TblWznmQLocList
	*/
class TblWznmQLocList {

public:
	TblWznmQLocList();
	virtual ~TblWznmQLocList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLocList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLocList& rst);

	virtual Sbecore::ubigint insertRec(WznmQLocList* rec);
	Sbecore::ubigint insertNewRec(WznmQLocList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQLocList& rst, WznmQLocList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "");
	virtual void insertRst(ListWznmQLocList& rst);
	virtual void updateRec(WznmQLocList* rec);
	virtual void updateRst(ListWznmQLocList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLocList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLocList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLocList: C++ wrapper for table TblWznmQLocList (MySQL database)
	*/
class MyTblWznmQLocList : public TblWznmQLocList, public Sbecore::MyTable {

public:
	MyTblWznmQLocList();
	~MyTblWznmQLocList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLocList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLocList& rst);

	Sbecore::ubigint insertRec(WznmQLocList* rec);
	void insertRst(ListWznmQLocList& rst);
	void updateRec(WznmQLocList* rec);
	void updateRst(ListWznmQLocList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLocList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLocList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLocList: C++ wrapper for table TblWznmQLocList (PgSQL database)
	*/
class PgTblWznmQLocList : public TblWznmQLocList, public Sbecore::PgTable {

public:
	PgTblWznmQLocList();
	~PgTblWznmQLocList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLocList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLocList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLocList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLocList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLocList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLocList& rst);

	Sbecore::ubigint insertRec(WznmQLocList* rec);
	void insertRst(ListWznmQLocList& rst);
	void updateRec(WznmQLocList* rec);
	void updateRst(ListWznmQLocList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLocList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLocList& rst);
};
#endif

#endif

