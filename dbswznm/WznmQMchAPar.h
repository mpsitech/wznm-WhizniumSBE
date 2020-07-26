/**
	* \file WznmQMchAPar.h
	* Dbs and XML wrapper for table TblWznmQMchAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQMCHAPAR_H
#define WZNMQMCHAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMchAPar: record of TblWznmQMchAPar
	*/
class WznmQMchAPar {

public:
	WznmQMchAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMchAPar: recordset of TblWznmQMchAPar
	*/
class ListWznmQMchAPar {

public:
	ListWznmQMchAPar();
	ListWznmQMchAPar(const ListWznmQMchAPar& src);
	~ListWznmQMchAPar();

	void clear();
	unsigned int size() const;
	void append(WznmQMchAPar* rec);

	ListWznmQMchAPar& operator=(const ListWznmQMchAPar& src);

public:
	std::vector<WznmQMchAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMchAPar: C++ wrapper for table TblWznmQMchAPar
	*/
class TblWznmQMchAPar {

public:
	TblWznmQMchAPar();
	virtual ~TblWznmQMchAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMchAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchAPar& rst);

	virtual Sbecore::ubigint insertRec(WznmQMchAPar* rec);
	Sbecore::ubigint insertNewRec(WznmQMchAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMchAPar& rst, WznmQMchAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWznmQMchAPar& rst);
	virtual void updateRec(WznmQMchAPar* rec);
	virtual void updateRst(ListWznmQMchAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMchAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMchAPar: C++ wrapper for table TblWznmQMchAPar (MySQL database)
	*/
class MyTblWznmQMchAPar : public TblWznmQMchAPar, public Sbecore::MyTable {

public:
	MyTblWznmQMchAPar();
	~MyTblWznmQMchAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchAPar& rst);

	Sbecore::ubigint insertRec(WznmQMchAPar* rec);
	void insertRst(ListWznmQMchAPar& rst);
	void updateRec(WznmQMchAPar* rec);
	void updateRst(ListWznmQMchAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchAPar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMchAPar: C++ wrapper for table TblWznmQMchAPar (PgSQL database)
	*/
class PgTblWznmQMchAPar : public TblWznmQMchAPar, public Sbecore::PgTable {

public:
	PgTblWznmQMchAPar();
	~PgTblWznmQMchAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMchAPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMchAPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMchAPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMchAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchAPar& rst);

	Sbecore::ubigint insertRec(WznmQMchAPar* rec);
	void insertRst(ListWznmQMchAPar& rst);
	void updateRec(WznmQMchAPar* rec);
	void updateRst(ListWznmQMchAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchAPar& rst);
};
#endif

#endif

