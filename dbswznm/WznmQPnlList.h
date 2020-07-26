/**
	* \file WznmQPnlList.h
	* Dbs and XML wrapper for table TblWznmQPnlList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQPNLLIST_H
#define WZNMQPNLLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPnlList: record of TblWznmQPnlList
	*/
class WznmQPnlList {

public:
	WznmQPnlList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint carRefWznmMCard = 0, const std::string stubCarRefWznmMCard = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint carRefWznmMCard;
	std::string stubCarRefWznmMCard;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPnlList: recordset of TblWznmQPnlList
	*/
class ListWznmQPnlList {

public:
	ListWznmQPnlList();
	ListWznmQPnlList(const ListWznmQPnlList& src);
	~ListWznmQPnlList();

	void clear();
	unsigned int size() const;
	void append(WznmQPnlList* rec);

	ListWznmQPnlList& operator=(const ListWznmQPnlList& src);

public:
	std::vector<WznmQPnlList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPnlList: C++ wrapper for table TblWznmQPnlList
	*/
class TblWznmQPnlList {

public:
	TblWznmQPnlList();
	virtual ~TblWznmQPnlList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPnlList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlList& rst);

	virtual Sbecore::ubigint insertRec(WznmQPnlList* rec);
	Sbecore::ubigint insertNewRec(WznmQPnlList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint carRefWznmMCard = 0, const std::string stubCarRefWznmMCard = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPnlList& rst, WznmQPnlList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint carRefWznmMCard = 0, const std::string stubCarRefWznmMCard = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "");
	virtual void insertRst(ListWznmQPnlList& rst);
	virtual void updateRec(WznmQPnlList* rec);
	virtual void updateRst(ListWznmQPnlList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPnlList: C++ wrapper for table TblWznmQPnlList (MySQL database)
	*/
class MyTblWznmQPnlList : public TblWznmQPnlList, public Sbecore::MyTable {

public:
	MyTblWznmQPnlList();
	~MyTblWznmQPnlList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPnlList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlList& rst);

	Sbecore::ubigint insertRec(WznmQPnlList* rec);
	void insertRst(ListWznmQPnlList& rst);
	void updateRec(WznmQPnlList* rec);
	void updateRst(ListWznmQPnlList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPnlList: C++ wrapper for table TblWznmQPnlList (PgSQL database)
	*/
class PgTblWznmQPnlList : public TblWznmQPnlList, public Sbecore::PgTable {

public:
	PgTblWznmQPnlList();
	~PgTblWznmQPnlList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPnlList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPnlList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPnlList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPnlList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPnlList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlList& rst);

	Sbecore::ubigint insertRec(WznmQPnlList* rec);
	void insertRst(ListWznmQPnlList& rst);
	void updateRec(WznmQPnlList* rec);
	void updateRst(ListWznmQPnlList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlList& rst);
};
#endif

#endif

