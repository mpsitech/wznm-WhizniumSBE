/**
	* \file WznmQJobList.h
	* Dbs and XML wrapper for table TblWznmQJobList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBLIST_H
#define WZNMQJOBLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobList: record of TblWznmQJobList
	*/
class WznmQJobList {

public:
	WznmQJobList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const bool Global = false, const std::string yesnoGlobal = "", const bool Clisrv = false, const std::string yesnoClisrv = "", const bool Shrdat = false, const std::string yesnoShrdat = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	bool Global;
	std::string yesnoGlobal;
	bool Clisrv;
	std::string yesnoClisrv;
	bool Shrdat;
	std::string yesnoShrdat;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJobList: recordset of TblWznmQJobList
	*/
class ListWznmQJobList {

public:
	ListWznmQJobList();
	ListWznmQJobList(const ListWznmQJobList& src);
	~ListWznmQJobList();

	void clear();
	unsigned int size() const;
	void append(WznmQJobList* rec);

	ListWznmQJobList& operator=(const ListWznmQJobList& src);

public:
	std::vector<WznmQJobList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobList: C++ wrapper for table TblWznmQJobList
	*/
class TblWznmQJobList {

public:
	TblWznmQJobList();
	virtual ~TblWznmQJobList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobList& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobList* rec);
	Sbecore::ubigint insertNewRec(WznmQJobList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const bool Global = false, const std::string yesnoGlobal = "", const bool Clisrv = false, const std::string yesnoClisrv = "", const bool Shrdat = false, const std::string yesnoShrdat = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobList& rst, WznmQJobList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const bool Global = false, const std::string yesnoGlobal = "", const bool Clisrv = false, const std::string yesnoClisrv = "", const bool Shrdat = false, const std::string yesnoShrdat = "");
	virtual void insertRst(ListWznmQJobList& rst);
	virtual void updateRec(WznmQJobList* rec);
	virtual void updateRst(ListWznmQJobList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobList: C++ wrapper for table TblWznmQJobList (MySQL database)
	*/
class MyTblWznmQJobList : public TblWznmQJobList, public Sbecore::MyTable {

public:
	MyTblWznmQJobList();
	~MyTblWznmQJobList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobList& rst);

	Sbecore::ubigint insertRec(WznmQJobList* rec);
	void insertRst(ListWznmQJobList& rst);
	void updateRec(WznmQJobList* rec);
	void updateRst(ListWznmQJobList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobList: C++ wrapper for table TblWznmQJobList (PgSQL database)
	*/
class PgTblWznmQJobList : public TblWznmQJobList, public Sbecore::PgTable {

public:
	PgTblWznmQJobList();
	~PgTblWznmQJobList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobList& rst);

	Sbecore::ubigint insertRec(WznmQJobList* rec);
	void insertRst(ListWznmQJobList& rst);
	void updateRec(WznmQJobList* rec);
	void updateRst(ListWznmQJobList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobList& rst);
};
#endif

#endif

