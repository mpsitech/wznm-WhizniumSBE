/**
	* \file WznmQVisVis1NSheet.h
	* Dbs and XML wrapper for table TblWznmQVisVis1NSheet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISVIS1NSHEET_H
#define WZNMQVISVIS1NSHEET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVisVis1NSheet: record of TblWznmQVisVis1NSheet
	*/
class WznmQVisVis1NSheet {

public:
	WznmQVisVis1NSheet(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint visNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint visNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVisVis1NSheet: recordset of TblWznmQVisVis1NSheet
	*/
class ListWznmQVisVis1NSheet {

public:
	ListWznmQVisVis1NSheet();
	ListWznmQVisVis1NSheet(const ListWznmQVisVis1NSheet& src);
	~ListWznmQVisVis1NSheet();

	void clear();
	unsigned int size() const;
	void append(WznmQVisVis1NSheet* rec);

	ListWznmQVisVis1NSheet& operator=(const ListWznmQVisVis1NSheet& src);

public:
	std::vector<WznmQVisVis1NSheet*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVisVis1NSheet: C++ wrapper for table TblWznmQVisVis1NSheet
	*/
class TblWznmQVisVis1NSheet {

public:
	TblWznmQVisVis1NSheet();
	virtual ~TblWznmQVisVis1NSheet();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVisVis1NSheet** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisVis1NSheet& rst);

	virtual Sbecore::ubigint insertRec(WznmQVisVis1NSheet* rec);
	Sbecore::ubigint insertNewRec(WznmQVisVis1NSheet** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint visNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVisVis1NSheet& rst, WznmQVisVis1NSheet** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint visNum = 0);
	virtual void insertRst(ListWznmQVisVis1NSheet& rst);
	virtual void updateRec(WznmQVisVis1NSheet* rec);
	virtual void updateRst(ListWznmQVisVis1NSheet& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVisVis1NSheet** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisVis1NSheet& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVisVis1NSheet: C++ wrapper for table TblWznmQVisVis1NSheet (MySQL database)
	*/
class MyTblWznmQVisVis1NSheet : public TblWznmQVisVis1NSheet, public Sbecore::MyTable {

public:
	MyTblWznmQVisVis1NSheet();
	~MyTblWznmQVisVis1NSheet();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisVis1NSheet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisVis1NSheet& rst);

	Sbecore::ubigint insertRec(WznmQVisVis1NSheet* rec);
	void insertRst(ListWznmQVisVis1NSheet& rst);
	void updateRec(WznmQVisVis1NSheet* rec);
	void updateRst(ListWznmQVisVis1NSheet& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisVis1NSheet** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisVis1NSheet& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVisVis1NSheet: C++ wrapper for table TblWznmQVisVis1NSheet (PgSQL database)
	*/
class PgTblWznmQVisVis1NSheet : public TblWznmQVisVis1NSheet, public Sbecore::PgTable {

public:
	PgTblWznmQVisVis1NSheet();
	~PgTblWznmQVisVis1NSheet();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVisVis1NSheet** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVisVis1NSheet& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVisVis1NSheet** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVisVis1NSheet& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisVis1NSheet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisVis1NSheet& rst);

	Sbecore::ubigint insertRec(WznmQVisVis1NSheet* rec);
	void insertRst(ListWznmQVisVis1NSheet& rst);
	void updateRec(WznmQVisVis1NSheet* rec);
	void updateRst(ListWznmQVisVis1NSheet& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisVis1NSheet** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisVis1NSheet& rst);
};
#endif

#endif
