/**
	* \file WznmQVerVer1NVisual.h
	* Dbs and XML wrapper for table TblWznmQVerVer1NVisual (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVERVER1NVISUAL_H
#define WZNMQVERVER1NVISUAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerVer1NVisual: record of TblWznmQVerVer1NVisual
	*/
class WznmQVerVer1NVisual {

public:
	WznmQVerVer1NVisual(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint verNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVerVer1NVisual: recordset of TblWznmQVerVer1NVisual
	*/
class ListWznmQVerVer1NVisual {

public:
	ListWznmQVerVer1NVisual();
	ListWznmQVerVer1NVisual(const ListWznmQVerVer1NVisual& src);
	~ListWznmQVerVer1NVisual();

	void clear();
	unsigned int size() const;
	void append(WznmQVerVer1NVisual* rec);

	ListWznmQVerVer1NVisual& operator=(const ListWznmQVerVer1NVisual& src);

public:
	std::vector<WznmQVerVer1NVisual*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerVer1NVisual: C++ wrapper for table TblWznmQVerVer1NVisual
	*/
class TblWznmQVerVer1NVisual {

public:
	TblWznmQVerVer1NVisual();
	virtual ~TblWznmQVerVer1NVisual();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NVisual** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NVisual& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerVer1NVisual* rec);
	Sbecore::ubigint insertNewRec(WznmQVerVer1NVisual** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerVer1NVisual& rst, WznmQVerVer1NVisual** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint verNum = 0);
	virtual void insertRst(ListWznmQVerVer1NVisual& rst);
	virtual void updateRec(WznmQVerVer1NVisual* rec);
	virtual void updateRst(ListWznmQVerVer1NVisual& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NVisual** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NVisual& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerVer1NVisual: C++ wrapper for table TblWznmQVerVer1NVisual (MySQL database)
	*/
class MyTblWznmQVerVer1NVisual : public TblWznmQVerVer1NVisual, public Sbecore::MyTable {

public:
	MyTblWznmQVerVer1NVisual();
	~MyTblWznmQVerVer1NVisual();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NVisual** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NVisual& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NVisual* rec);
	void insertRst(ListWznmQVerVer1NVisual& rst);
	void updateRec(WznmQVerVer1NVisual* rec);
	void updateRst(ListWznmQVerVer1NVisual& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NVisual** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NVisual& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerVer1NVisual: C++ wrapper for table TblWznmQVerVer1NVisual (PgSQL database)
	*/
class PgTblWznmQVerVer1NVisual : public TblWznmQVerVer1NVisual, public Sbecore::PgTable {

public:
	PgTblWznmQVerVer1NVisual();
	~PgTblWznmQVerVer1NVisual();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerVer1NVisual** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerVer1NVisual& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerVer1NVisual** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerVer1NVisual& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerVer1NVisual** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerVer1NVisual& rst);

	Sbecore::ubigint insertRec(WznmQVerVer1NVisual* rec);
	void insertRst(ListWznmQVerVer1NVisual& rst);
	void updateRec(WznmQVerVer1NVisual* rec);
	void updateRst(ListWznmQVerVer1NVisual& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerVer1NVisual** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerVer1NVisual& rst);
};
#endif

#endif
