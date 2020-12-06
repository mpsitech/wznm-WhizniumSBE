/**
	* \file WznmQCtpKKey.h
	* Dbs and XML wrapper for table TblWznmQCtpKKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTPKKEY_H
#define WZNMQCTPKKEY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCtpKKey: record of TblWznmQCtpKKey
	*/
class WznmQCtpKKey {

public:
	WznmQCtpKKey(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

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
	* ListWznmQCtpKKey: recordset of TblWznmQCtpKKey
	*/
class ListWznmQCtpKKey {

public:
	ListWznmQCtpKKey();
	ListWznmQCtpKKey(const ListWznmQCtpKKey& src);
	~ListWznmQCtpKKey();

	void clear();
	unsigned int size() const;
	void append(WznmQCtpKKey* rec);

	ListWznmQCtpKKey& operator=(const ListWznmQCtpKKey& src);

public:
	std::vector<WznmQCtpKKey*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCtpKKey: C++ wrapper for table TblWznmQCtpKKey
	*/
class TblWznmQCtpKKey {

public:
	TblWznmQCtpKKey();
	virtual ~TblWznmQCtpKKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCtpKKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpKKey& rst);

	virtual Sbecore::ubigint insertRec(WznmQCtpKKey* rec);
	Sbecore::ubigint insertNewRec(WznmQCtpKKey** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCtpKKey& rst, WznmQCtpKKey** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint klsNum = 0, const bool Fixed = false, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQCtpKKey& rst);
	virtual void updateRec(WznmQCtpKKey* rec);
	virtual void updateRst(ListWznmQCtpKKey& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpKKey** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpKKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCtpKKey: C++ wrapper for table TblWznmQCtpKKey (MySQL database)
	*/
class MyTblWznmQCtpKKey : public TblWznmQCtpKKey, public Sbecore::MyTable {

public:
	MyTblWznmQCtpKKey();
	~MyTblWznmQCtpKKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpKKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpKKey& rst);

	Sbecore::ubigint insertRec(WznmQCtpKKey* rec);
	void insertRst(ListWznmQCtpKKey& rst);
	void updateRec(WznmQCtpKKey* rec);
	void updateRst(ListWznmQCtpKKey& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpKKey** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpKKey& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCtpKKey: C++ wrapper for table TblWznmQCtpKKey (PgSQL database)
	*/
class PgTblWznmQCtpKKey : public TblWznmQCtpKKey, public Sbecore::PgTable {

public:
	PgTblWznmQCtpKKey();
	~PgTblWznmQCtpKKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCtpKKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCtpKKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCtpKKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCtpKKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpKKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpKKey& rst);

	Sbecore::ubigint insertRec(WznmQCtpKKey* rec);
	void insertRst(ListWznmQCtpKKey& rst);
	void updateRec(WznmQCtpKKey* rec);
	void updateRst(ListWznmQCtpKKey& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpKKey** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpKKey& rst);
};
#endif

#endif
