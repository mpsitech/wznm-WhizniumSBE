/**
	* \file WznmQErrList.h
	* Dbs and XML wrapper for table TblWznmQErrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQERRLIST_H
#define WZNMQERRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQErrList: record of TblWznmQErrList
	*/
class WznmQErrList {

public:
	WznmQErrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint verRefWznmMVersion;
	std::string stubVerRefWznmMVersion;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQErrList: recordset of TblWznmQErrList
	*/
class ListWznmQErrList {

public:
	ListWznmQErrList();
	ListWznmQErrList(const ListWznmQErrList& src);
	~ListWznmQErrList();

	void clear();
	unsigned int size() const;
	void append(WznmQErrList* rec);

	ListWznmQErrList& operator=(const ListWznmQErrList& src);

public:
	std::vector<WznmQErrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQErrList: C++ wrapper for table TblWznmQErrList
	*/
class TblWznmQErrList {

public:
	TblWznmQErrList();
	virtual ~TblWznmQErrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQErrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQErrList& rst);

	virtual Sbecore::ubigint insertRec(WznmQErrList* rec);
	Sbecore::ubigint insertNewRec(WznmQErrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQErrList& rst, WznmQErrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	virtual void insertRst(ListWznmQErrList& rst);
	virtual void updateRec(WznmQErrList* rec);
	virtual void updateRst(ListWznmQErrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQErrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQErrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQErrList: C++ wrapper for table TblWznmQErrList (MySQL database)
	*/
class MyTblWznmQErrList : public TblWznmQErrList, public Sbecore::MyTable {

public:
	MyTblWznmQErrList();
	~MyTblWznmQErrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQErrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQErrList& rst);

	Sbecore::ubigint insertRec(WznmQErrList* rec);
	void insertRst(ListWznmQErrList& rst);
	void updateRec(WznmQErrList* rec);
	void updateRst(ListWznmQErrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQErrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQErrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQErrList: C++ wrapper for table TblWznmQErrList (PgSQL database)
	*/
class PgTblWznmQErrList : public TblWznmQErrList, public Sbecore::PgTable {

public:
	PgTblWznmQErrList();
	~PgTblWznmQErrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQErrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQErrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQErrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQErrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQErrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQErrList& rst);

	Sbecore::ubigint insertRec(WznmQErrList* rec);
	void insertRst(ListWznmQErrList& rst);
	void updateRec(WznmQErrList* rec);
	void updateRst(ListWznmQErrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQErrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQErrList& rst);
};
#endif

#endif

