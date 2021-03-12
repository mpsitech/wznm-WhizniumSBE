/**
	* \file WznmQRlsList.h
	* Dbs and XML wrapper for table TblWznmQRlsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRLSLIST_H
#define WZNMQRLSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRlsList: record of TblWznmQRlsList
	*/
class WznmQRlsList {

public:
	WznmQRlsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMComponent = 0, const std::string stubRefWznmMComponent = "", const Sbecore::ubigint refWznmMMachine = 0, const std::string stubRefWznmMMachine = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refWznmMComponent;
	std::string stubRefWznmMComponent;
	Sbecore::ubigint refWznmMMachine;
	std::string stubRefWznmMMachine;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQRlsList: recordset of TblWznmQRlsList
	*/
class ListWznmQRlsList {

public:
	ListWznmQRlsList();
	ListWznmQRlsList(const ListWznmQRlsList& src);
	~ListWznmQRlsList();

	void clear();
	unsigned int size() const;
	void append(WznmQRlsList* rec);

	ListWznmQRlsList& operator=(const ListWznmQRlsList& src);

public:
	std::vector<WznmQRlsList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRlsList: C++ wrapper for table TblWznmQRlsList
	*/
class TblWznmQRlsList {

public:
	TblWznmQRlsList();
	virtual ~TblWznmQRlsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRlsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRlsList& rst);

	virtual Sbecore::ubigint insertRec(WznmQRlsList* rec);
	Sbecore::ubigint insertNewRec(WznmQRlsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMComponent = 0, const std::string stubRefWznmMComponent = "", const Sbecore::ubigint refWznmMMachine = 0, const std::string stubRefWznmMMachine = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRlsList& rst, WznmQRlsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refWznmMComponent = 0, const std::string stubRefWznmMComponent = "", const Sbecore::ubigint refWznmMMachine = 0, const std::string stubRefWznmMMachine = "");
	virtual void insertRst(ListWznmQRlsList& rst);
	virtual void updateRec(WznmQRlsList* rec);
	virtual void updateRst(ListWznmQRlsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRlsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRlsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRlsList: C++ wrapper for table TblWznmQRlsList (MySQL database)
	*/
class MyTblWznmQRlsList : public TblWznmQRlsList, public Sbecore::MyTable {

public:
	MyTblWznmQRlsList();
	~MyTblWznmQRlsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRlsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRlsList& rst);

	Sbecore::ubigint insertRec(WznmQRlsList* rec);
	void insertRst(ListWznmQRlsList& rst);
	void updateRec(WznmQRlsList* rec);
	void updateRst(ListWznmQRlsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRlsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRlsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRlsList: C++ wrapper for table TblWznmQRlsList (PgSQL database)
	*/
class PgTblWznmQRlsList : public TblWznmQRlsList, public Sbecore::PgTable {

public:
	PgTblWznmQRlsList();
	~PgTblWznmQRlsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRlsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRlsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRlsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRlsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRlsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRlsList& rst);

	Sbecore::ubigint insertRec(WznmQRlsList* rec);
	void insertRst(ListWznmQRlsList& rst);
	void updateRec(WznmQRlsList* rec);
	void updateRst(ListWznmQRlsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRlsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRlsList& rst);
};
#endif

#endif
