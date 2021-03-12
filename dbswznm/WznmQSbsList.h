/**
	* \file WznmQSbsList.h
	* Dbs and XML wrapper for table TblWznmQSbsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBSLIST_H
#define WZNMQSBSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsList: record of TblWznmQSbsList
	*/
class WznmQSbsList {

public:
	WznmQSbsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Short;
	Sbecore::ubigint refWznmMTable;
	std::string stubRefWznmMTable;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSbsList: recordset of TblWznmQSbsList
	*/
class ListWznmQSbsList {

public:
	ListWznmQSbsList();
	ListWznmQSbsList(const ListWznmQSbsList& src);
	~ListWznmQSbsList();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsList* rec);

	ListWznmQSbsList& operator=(const ListWznmQSbsList& src);

public:
	std::vector<WznmQSbsList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsList: C++ wrapper for table TblWznmQSbsList
	*/
class TblWznmQSbsList {

public:
	TblWznmQSbsList();
	virtual ~TblWznmQSbsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsList& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsList* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsList& rst, WznmQSbsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMTable = 0, const std::string stubRefWznmMTable = "");
	virtual void insertRst(ListWznmQSbsList& rst);
	virtual void updateRec(WznmQSbsList* rec);
	virtual void updateRst(ListWznmQSbsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsList: C++ wrapper for table TblWznmQSbsList (MySQL database)
	*/
class MyTblWznmQSbsList : public TblWznmQSbsList, public Sbecore::MyTable {

public:
	MyTblWznmQSbsList();
	~MyTblWznmQSbsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsList& rst);

	Sbecore::ubigint insertRec(WznmQSbsList* rec);
	void insertRst(ListWznmQSbsList& rst);
	void updateRec(WznmQSbsList* rec);
	void updateRst(ListWznmQSbsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsList: C++ wrapper for table TblWznmQSbsList (PgSQL database)
	*/
class PgTblWznmQSbsList : public TblWznmQSbsList, public Sbecore::PgTable {

public:
	PgTblWznmQSbsList();
	~PgTblWznmQSbsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsList& rst);

	Sbecore::ubigint insertRec(WznmQSbsList* rec);
	void insertRst(ListWznmQSbsList& rst);
	void updateRec(WznmQSbsList* rec);
	void updateRst(ListWznmQSbsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsList& rst);
};
#endif

#endif
