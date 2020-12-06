/**
	* \file WznmQCtpAPar.h
	* Dbs and XML wrapper for table TblWznmQCtpAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTPAPAR_H
#define WZNMQCTPAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCtpAPar: record of TblWznmQCtpAPar
	*/
class WznmQCtpAPar {

public:
	WznmQCtpAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint cpbNum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCtpAPar: recordset of TblWznmQCtpAPar
	*/
class ListWznmQCtpAPar {

public:
	ListWznmQCtpAPar();
	ListWznmQCtpAPar(const ListWznmQCtpAPar& src);
	~ListWznmQCtpAPar();

	void clear();
	unsigned int size() const;
	void append(WznmQCtpAPar* rec);

	ListWznmQCtpAPar& operator=(const ListWznmQCtpAPar& src);

public:
	std::vector<WznmQCtpAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCtpAPar: C++ wrapper for table TblWznmQCtpAPar
	*/
class TblWznmQCtpAPar {

public:
	TblWznmQCtpAPar();
	virtual ~TblWznmQCtpAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCtpAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpAPar& rst);

	virtual Sbecore::ubigint insertRec(WznmQCtpAPar* rec);
	Sbecore::ubigint insertNewRec(WznmQCtpAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCtpAPar& rst, WznmQCtpAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWznmQCtpAPar& rst);
	virtual void updateRec(WznmQCtpAPar* rec);
	virtual void updateRst(ListWznmQCtpAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCtpAPar: C++ wrapper for table TblWznmQCtpAPar (MySQL database)
	*/
class MyTblWznmQCtpAPar : public TblWznmQCtpAPar, public Sbecore::MyTable {

public:
	MyTblWznmQCtpAPar();
	~MyTblWznmQCtpAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpAPar& rst);

	Sbecore::ubigint insertRec(WznmQCtpAPar* rec);
	void insertRst(ListWznmQCtpAPar& rst);
	void updateRec(WznmQCtpAPar* rec);
	void updateRst(ListWznmQCtpAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCtpAPar: C++ wrapper for table TblWznmQCtpAPar (PgSQL database)
	*/
class PgTblWznmQCtpAPar : public TblWznmQCtpAPar, public Sbecore::PgTable {

public:
	PgTblWznmQCtpAPar();
	~PgTblWznmQCtpAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCtpAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCtpAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCtpAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCtpAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpAPar& rst);

	Sbecore::ubigint insertRec(WznmQCtpAPar* rec);
	void insertRst(ListWznmQCtpAPar& rst);
	void updateRec(WznmQCtpAPar* rec);
	void updateRst(ListWznmQCtpAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpAPar& rst);
};
#endif

#endif
