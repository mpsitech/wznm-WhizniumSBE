/**
	* \file WznmQOpkList.h
	* Dbs and XML wrapper for table TblWznmQOpkList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKLIST_H
#define WZNMQOPKLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkList: record of TblWznmQOpkList
	*/
class WznmQOpkList {

public:
	WznmQOpkList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const bool Shrdat = false, const std::string yesnoShrdat = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	bool Shrdat;
	std::string yesnoShrdat;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQOpkList: recordset of TblWznmQOpkList
	*/
class ListWznmQOpkList {

public:
	ListWznmQOpkList();
	ListWznmQOpkList(const ListWznmQOpkList& src);
	~ListWznmQOpkList();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkList* rec);

	ListWznmQOpkList& operator=(const ListWznmQOpkList& src);

public:
	std::vector<WznmQOpkList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkList: C++ wrapper for table TblWznmQOpkList
	*/
class TblWznmQOpkList {

public:
	TblWznmQOpkList();
	virtual ~TblWznmQOpkList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkList& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkList* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const bool Shrdat = false, const std::string yesnoShrdat = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkList& rst, WznmQOpkList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const bool Shrdat = false, const std::string yesnoShrdat = "");
	virtual void insertRst(ListWznmQOpkList& rst);
	virtual void updateRec(WznmQOpkList* rec);
	virtual void updateRst(ListWznmQOpkList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkList: C++ wrapper for table TblWznmQOpkList (MySQL database)
	*/
class MyTblWznmQOpkList : public TblWznmQOpkList, public Sbecore::MyTable {

public:
	MyTblWznmQOpkList();
	~MyTblWznmQOpkList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkList& rst);

	Sbecore::ubigint insertRec(WznmQOpkList* rec);
	void insertRst(ListWznmQOpkList& rst);
	void updateRec(WznmQOpkList* rec);
	void updateRst(ListWznmQOpkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkList: C++ wrapper for table TblWznmQOpkList (PgSQL database)
	*/
class PgTblWznmQOpkList : public TblWznmQOpkList, public Sbecore::PgTable {

public:
	PgTblWznmQOpkList();
	~PgTblWznmQOpkList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkList& rst);

	Sbecore::ubigint insertRec(WznmQOpkList* rec);
	void insertRst(ListWznmQOpkList& rst);
	void updateRec(WznmQOpkList* rec);
	void updateRst(ListWznmQOpkList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkList& rst);
};
#endif

#endif
