/**
	* \file WznmQConAPar.h
	* Dbs and XML wrapper for table TblWznmQConAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCONAPAR_H
#define WZNMQCONAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQConAPar: record of TblWznmQConAPar
	*/
class WznmQConAPar {

public:
	WznmQConAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string osrefKVal = "", const std::string titOsrefKVal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	Sbecore::ubigint x2RefWznmMLocale;
	std::string stubX2RefWznmMLocale;
	std::string osrefKVal;
	std::string titOsrefKVal;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQConAPar: recordset of TblWznmQConAPar
	*/
class ListWznmQConAPar {

public:
	ListWznmQConAPar();
	ListWznmQConAPar(const ListWznmQConAPar& src);
	~ListWznmQConAPar();

	void clear();
	unsigned int size() const;
	void append(WznmQConAPar* rec);

	ListWznmQConAPar& operator=(const ListWznmQConAPar& src);

public:
	std::vector<WznmQConAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQConAPar: C++ wrapper for table TblWznmQConAPar
	*/
class TblWznmQConAPar {

public:
	TblWznmQConAPar();
	virtual ~TblWznmQConAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQConAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConAPar& rst);

	virtual Sbecore::ubigint insertRec(WznmQConAPar* rec);
	Sbecore::ubigint insertNewRec(WznmQConAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string osrefKVal = "", const std::string titOsrefKVal = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQConAPar& rst, WznmQConAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string osrefKVal = "", const std::string titOsrefKVal = "");
	virtual void insertRst(ListWznmQConAPar& rst);
	virtual void updateRec(WznmQConAPar* rec);
	virtual void updateRst(ListWznmQConAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQConAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQConAPar: C++ wrapper for table TblWznmQConAPar (MySQL database)
	*/
class MyTblWznmQConAPar : public TblWznmQConAPar, public Sbecore::MyTable {

public:
	MyTblWznmQConAPar();
	~MyTblWznmQConAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConAPar& rst);

	Sbecore::ubigint insertRec(WznmQConAPar* rec);
	void insertRst(ListWznmQConAPar& rst);
	void updateRec(WznmQConAPar* rec);
	void updateRst(ListWznmQConAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQConAPar: C++ wrapper for table TblWznmQConAPar (PgSQL database)
	*/
class PgTblWznmQConAPar : public TblWznmQConAPar, public Sbecore::PgTable {

public:
	PgTblWznmQConAPar();
	~PgTblWznmQConAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQConAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQConAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQConAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQConAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConAPar& rst);

	Sbecore::ubigint insertRec(WznmQConAPar* rec);
	void insertRst(ListWznmQConAPar& rst);
	void updateRec(WznmQConAPar* rec);
	void updateRst(ListWznmQConAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConAPar& rst);
};
#endif

#endif

