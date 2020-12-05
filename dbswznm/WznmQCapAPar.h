/**
	* \file WznmQCapAPar.h
	* Dbs and XML wrapper for table TblWznmQCapAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCAPAPAR_H
#define WZNMQCAPAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCapAPar: record of TblWznmQCapAPar
	*/
class WznmQCapAPar {

public:
	WznmQCapAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

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
	* ListWznmQCapAPar: recordset of TblWznmQCapAPar
	*/
class ListWznmQCapAPar {

public:
	ListWznmQCapAPar();
	ListWznmQCapAPar(const ListWznmQCapAPar& src);
	~ListWznmQCapAPar();

	void clear();
	unsigned int size() const;
	void append(WznmQCapAPar* rec);

	ListWznmQCapAPar& operator=(const ListWznmQCapAPar& src);

public:
	std::vector<WznmQCapAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCapAPar: C++ wrapper for table TblWznmQCapAPar
	*/
class TblWznmQCapAPar {

public:
	TblWznmQCapAPar();
	virtual ~TblWznmQCapAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCapAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCapAPar& rst);

	virtual Sbecore::ubigint insertRec(WznmQCapAPar* rec);
	Sbecore::ubigint insertNewRec(WznmQCapAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCapAPar& rst, WznmQCapAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWznmQCapAPar& rst);
	virtual void updateRec(WznmQCapAPar* rec);
	virtual void updateRst(ListWznmQCapAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCapAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCapAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCapAPar: C++ wrapper for table TblWznmQCapAPar (MySQL database)
	*/
class MyTblWznmQCapAPar : public TblWznmQCapAPar, public Sbecore::MyTable {

public:
	MyTblWznmQCapAPar();
	~MyTblWznmQCapAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCapAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCapAPar& rst);

	Sbecore::ubigint insertRec(WznmQCapAPar* rec);
	void insertRst(ListWznmQCapAPar& rst);
	void updateRec(WznmQCapAPar* rec);
	void updateRst(ListWznmQCapAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCapAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCapAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCapAPar: C++ wrapper for table TblWznmQCapAPar (PgSQL database)
	*/
class PgTblWznmQCapAPar : public TblWznmQCapAPar, public Sbecore::PgTable {

public:
	PgTblWznmQCapAPar();
	~PgTblWznmQCapAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCapAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCapAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCapAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCapAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCapAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCapAPar& rst);

	Sbecore::ubigint insertRec(WznmQCapAPar* rec);
	void insertRst(ListWznmQCapAPar& rst);
	void updateRec(WznmQCapAPar* rec);
	void updateRst(ListWznmQCapAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCapAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCapAPar& rst);
};
#endif

#endif

