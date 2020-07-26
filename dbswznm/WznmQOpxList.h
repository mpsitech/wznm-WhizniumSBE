/**
	* \file WznmQOpxList.h
	* Dbs and XML wrapper for table TblWznmQOpxList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQOPXLIST_H
#define WZNMQOPXLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpxList: record of TblWznmQOpxList
	*/
class WznmQOpxList {

public:
	WznmQOpxList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMOppack = 0, const std::string stubRefWznmMOppack = "", const bool Shrdat = false, const std::string yesnoShrdat = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMOppack;
	std::string stubRefWznmMOppack;
	bool Shrdat;
	std::string yesnoShrdat;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQOpxList: recordset of TblWznmQOpxList
	*/
class ListWznmQOpxList {

public:
	ListWznmQOpxList();
	ListWznmQOpxList(const ListWznmQOpxList& src);
	~ListWznmQOpxList();

	void clear();
	unsigned int size() const;
	void append(WznmQOpxList* rec);

	ListWznmQOpxList& operator=(const ListWznmQOpxList& src);

public:
	std::vector<WznmQOpxList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpxList: C++ wrapper for table TblWznmQOpxList
	*/
class TblWznmQOpxList {

public:
	TblWznmQOpxList();
	virtual ~TblWznmQOpxList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpxList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxList& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpxList* rec);
	Sbecore::ubigint insertNewRec(WznmQOpxList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMOppack = 0, const std::string stubRefWznmMOppack = "", const bool Shrdat = false, const std::string yesnoShrdat = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpxList& rst, WznmQOpxList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMOppack = 0, const std::string stubRefWznmMOppack = "", const bool Shrdat = false, const std::string yesnoShrdat = "");
	virtual void insertRst(ListWznmQOpxList& rst);
	virtual void updateRec(WznmQOpxList* rec);
	virtual void updateRst(ListWznmQOpxList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpxList: C++ wrapper for table TblWznmQOpxList (MySQL database)
	*/
class MyTblWznmQOpxList : public TblWznmQOpxList, public Sbecore::MyTable {

public:
	MyTblWznmQOpxList();
	~MyTblWznmQOpxList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxList& rst);

	Sbecore::ubigint insertRec(WznmQOpxList* rec);
	void insertRst(ListWznmQOpxList& rst);
	void updateRec(WznmQOpxList* rec);
	void updateRst(ListWznmQOpxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpxList: C++ wrapper for table TblWznmQOpxList (PgSQL database)
	*/
class PgTblWznmQOpxList : public TblWznmQOpxList, public Sbecore::PgTable {

public:
	PgTblWznmQOpxList();
	~PgTblWznmQOpxList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpxList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpxList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpxList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpxList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxList& rst);

	Sbecore::ubigint insertRec(WznmQOpxList* rec);
	void insertRst(ListWznmQOpxList& rst);
	void updateRec(WznmQOpxList* rec);
	void updateRst(ListWznmQOpxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxList& rst);
};
#endif

#endif

