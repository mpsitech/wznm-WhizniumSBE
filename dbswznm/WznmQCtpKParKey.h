/**
	* \file WznmQCtpKParKey.h
	* Dbs and XML wrapper for table TblWznmQCtpKParKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTPKPARKEY_H
#define WZNMQCTPKPARKEY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCtpKParKey: record of TblWznmQCtpKParKey
	*/
class WznmQCtpKParKey {

public:
	WznmQCtpKParKey(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint klsNum;
	bool Fixed;
	std::string yesnoFixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCtpKParKey: recordset of TblWznmQCtpKParKey
	*/
class ListWznmQCtpKParKey {

public:
	ListWznmQCtpKParKey();
	ListWznmQCtpKParKey(const ListWznmQCtpKParKey& src);
	~ListWznmQCtpKParKey();

	void clear();
	unsigned int size() const;
	void append(WznmQCtpKParKey* rec);

	ListWznmQCtpKParKey& operator=(const ListWznmQCtpKParKey& src);

public:
	std::vector<WznmQCtpKParKey*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCtpKParKey: C++ wrapper for table TblWznmQCtpKParKey
	*/
class TblWznmQCtpKParKey {

public:
	TblWznmQCtpKParKey();
	virtual ~TblWznmQCtpKParKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCtpKParKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpKParKey& rst);

	virtual Sbecore::ubigint insertRec(WznmQCtpKParKey* rec);
	Sbecore::ubigint insertNewRec(WznmQCtpKParKey** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCtpKParKey& rst, WznmQCtpKParKey** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQCtpKParKey& rst);
	virtual void updateRec(WznmQCtpKParKey* rec);
	virtual void updateRst(ListWznmQCtpKParKey& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpKParKey** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpKParKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCtpKParKey: C++ wrapper for table TblWznmQCtpKParKey (MySQL database)
	*/
class MyTblWznmQCtpKParKey : public TblWznmQCtpKParKey, public Sbecore::MyTable {

public:
	MyTblWznmQCtpKParKey();
	~MyTblWznmQCtpKParKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpKParKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpKParKey& rst);

	Sbecore::ubigint insertRec(WznmQCtpKParKey* rec);
	void insertRst(ListWznmQCtpKParKey& rst);
	void updateRec(WznmQCtpKParKey* rec);
	void updateRst(ListWznmQCtpKParKey& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpKParKey** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpKParKey& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCtpKParKey: C++ wrapper for table TblWznmQCtpKParKey (PgSQL database)
	*/
class PgTblWznmQCtpKParKey : public TblWznmQCtpKParKey, public Sbecore::PgTable {

public:
	PgTblWznmQCtpKParKey();
	~PgTblWznmQCtpKParKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCtpKParKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCtpKParKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCtpKParKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCtpKParKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpKParKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpKParKey& rst);

	Sbecore::ubigint insertRec(WznmQCtpKParKey* rec);
	void insertRst(ListWznmQCtpKParKey& rst);
	void updateRec(WznmQCtpKParKey* rec);
	void updateRst(ListWznmQCtpKParKey& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpKParKey** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpKParKey& rst);
};
#endif

#endif
