/**
	* \file WznmQSeqList.h
	* Dbs and XML wrapper for table TblWznmQSeqList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSEQLIST_H
#define WZNMQSEQLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSeqList: record of TblWznmQSeqList
	*/
class WznmQSeqList {

public:
	WznmQSeqList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint appRefWznmMApp = 0, const std::string stubAppRefWznmMApp = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint appRefWznmMApp;
	std::string stubAppRefWznmMApp;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSeqList: recordset of TblWznmQSeqList
	*/
class ListWznmQSeqList {

public:
	ListWznmQSeqList();
	ListWznmQSeqList(const ListWznmQSeqList& src);
	~ListWznmQSeqList();

	void clear();
	unsigned int size() const;
	void append(WznmQSeqList* rec);

	ListWznmQSeqList& operator=(const ListWznmQSeqList& src);

public:
	std::vector<WznmQSeqList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSeqList: C++ wrapper for table TblWznmQSeqList
	*/
class TblWznmQSeqList {

public:
	TblWznmQSeqList();
	virtual ~TblWznmQSeqList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSeqList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSeqList& rst);

	virtual Sbecore::ubigint insertRec(WznmQSeqList* rec);
	Sbecore::ubigint insertNewRec(WznmQSeqList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint appRefWznmMApp = 0, const std::string stubAppRefWznmMApp = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSeqList& rst, WznmQSeqList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint appRefWznmMApp = 0, const std::string stubAppRefWznmMApp = "");
	virtual void insertRst(ListWznmQSeqList& rst);
	virtual void updateRec(WznmQSeqList* rec);
	virtual void updateRst(ListWznmQSeqList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSeqList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSeqList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSeqList: C++ wrapper for table TblWznmQSeqList (MySQL database)
	*/
class MyTblWznmQSeqList : public TblWznmQSeqList, public Sbecore::MyTable {

public:
	MyTblWznmQSeqList();
	~MyTblWznmQSeqList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSeqList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSeqList& rst);

	Sbecore::ubigint insertRec(WznmQSeqList* rec);
	void insertRst(ListWznmQSeqList& rst);
	void updateRec(WznmQSeqList* rec);
	void updateRst(ListWznmQSeqList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSeqList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSeqList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSeqList: C++ wrapper for table TblWznmQSeqList (PgSQL database)
	*/
class PgTblWznmQSeqList : public TblWznmQSeqList, public Sbecore::PgTable {

public:
	PgTblWznmQSeqList();
	~PgTblWznmQSeqList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSeqList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSeqList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSeqList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSeqList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSeqList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSeqList& rst);

	Sbecore::ubigint insertRec(WznmQSeqList* rec);
	void insertRst(ListWznmQSeqList& rst);
	void updateRec(WznmQSeqList* rec);
	void updateRst(ListWznmQSeqList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSeqList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSeqList& rst);
};
#endif

#endif

