/**
	* \file WznmQMdlList.h
	* Dbs and XML wrapper for table TblWznmQMdlList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQMDLLIST_H
#define WZNMQMDLLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMdlList: record of TblWznmQMdlList
	*/
class WznmQMdlList {

public:
	WznmQMdlList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");

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
	* ListWznmQMdlList: recordset of TblWznmQMdlList
	*/
class ListWznmQMdlList {

public:
	ListWznmQMdlList();
	ListWznmQMdlList(const ListWznmQMdlList& src);
	~ListWznmQMdlList();

	void clear();
	unsigned int size() const;
	void append(WznmQMdlList* rec);

	ListWznmQMdlList& operator=(const ListWznmQMdlList& src);

public:
	std::vector<WznmQMdlList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMdlList: C++ wrapper for table TblWznmQMdlList
	*/
class TblWznmQMdlList {

public:
	TblWznmQMdlList();
	virtual ~TblWznmQMdlList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMdlList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlList& rst);

	virtual Sbecore::ubigint insertRec(WznmQMdlList* rec);
	Sbecore::ubigint insertNewRec(WznmQMdlList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMdlList& rst, WznmQMdlList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	virtual void insertRst(ListWznmQMdlList& rst);
	virtual void updateRec(WznmQMdlList* rec);
	virtual void updateRst(ListWznmQMdlList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMdlList: C++ wrapper for table TblWznmQMdlList (MySQL database)
	*/
class MyTblWznmQMdlList : public TblWznmQMdlList, public Sbecore::MyTable {

public:
	MyTblWznmQMdlList();
	~MyTblWznmQMdlList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMdlList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlList& rst);

	Sbecore::ubigint insertRec(WznmQMdlList* rec);
	void insertRst(ListWznmQMdlList& rst);
	void updateRec(WznmQMdlList* rec);
	void updateRst(ListWznmQMdlList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMdlList: C++ wrapper for table TblWznmQMdlList (PgSQL database)
	*/
class PgTblWznmQMdlList : public TblWznmQMdlList, public Sbecore::PgTable {

public:
	PgTblWznmQMdlList();
	~PgTblWznmQMdlList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMdlList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMdlList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMdlList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMdlList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMdlList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlList& rst);

	Sbecore::ubigint insertRec(WznmQMdlList* rec);
	void insertRst(ListWznmQMdlList& rst);
	void updateRec(WznmQMdlList* rec);
	void updateRst(ListWznmQMdlList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlList& rst);
};
#endif

#endif

