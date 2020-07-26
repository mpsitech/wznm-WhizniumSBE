/**
	* \file WznmQChkList.h
	* Dbs and XML wrapper for table TblWznmQChkList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCHKLIST_H
#define WZNMQCHKLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQChkList: record of TblWznmQChkList
	*/
class WznmQChkList {

public:
	WznmQChkList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;
	Sbecore::ubigint refWznmMTablecol;
	std::string stubRefWznmMTablecol;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQChkList: recordset of TblWznmQChkList
	*/
class ListWznmQChkList {

public:
	ListWznmQChkList();
	ListWznmQChkList(const ListWznmQChkList& src);
	~ListWznmQChkList();

	void clear();
	unsigned int size() const;
	void append(WznmQChkList* rec);

	ListWznmQChkList& operator=(const ListWznmQChkList& src);

public:
	std::vector<WznmQChkList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQChkList: C++ wrapper for table TblWznmQChkList
	*/
class TblWznmQChkList {

public:
	TblWznmQChkList();
	virtual ~TblWznmQChkList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQChkList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQChkList& rst);

	virtual Sbecore::ubigint insertRec(WznmQChkList* rec);
	Sbecore::ubigint insertNewRec(WznmQChkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQChkList& rst, WznmQChkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "");
	virtual void insertRst(ListWznmQChkList& rst);
	virtual void updateRec(WznmQChkList* rec);
	virtual void updateRst(ListWznmQChkList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQChkList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQChkList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQChkList: C++ wrapper for table TblWznmQChkList (MySQL database)
	*/
class MyTblWznmQChkList : public TblWznmQChkList, public Sbecore::MyTable {

public:
	MyTblWznmQChkList();
	~MyTblWznmQChkList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQChkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQChkList& rst);

	Sbecore::ubigint insertRec(WznmQChkList* rec);
	void insertRst(ListWznmQChkList& rst);
	void updateRec(WznmQChkList* rec);
	void updateRst(ListWznmQChkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQChkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQChkList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQChkList: C++ wrapper for table TblWznmQChkList (PgSQL database)
	*/
class PgTblWznmQChkList : public TblWznmQChkList, public Sbecore::PgTable {

public:
	PgTblWznmQChkList();
	~PgTblWznmQChkList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQChkList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQChkList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQChkList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQChkList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQChkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQChkList& rst);

	Sbecore::ubigint insertRec(WznmQChkList* rec);
	void insertRst(ListWznmQChkList& rst);
	void updateRec(WznmQChkList* rec);
	void updateRst(ListWznmQChkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQChkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQChkList& rst);
};
#endif

#endif

