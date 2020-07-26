/**
	* \file WznmQMty1NMachine.h
	* Dbs and XML wrapper for table TblWznmQMty1NMachine (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQMTY1NMACHINE_H
#define WZNMQMTY1NMACHINE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMty1NMachine: record of TblWznmQMty1NMachine
	*/
class WznmQMty1NMachine {

public:
	WznmQMty1NMachine(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMty1NMachine: recordset of TblWznmQMty1NMachine
	*/
class ListWznmQMty1NMachine {

public:
	ListWznmQMty1NMachine();
	ListWznmQMty1NMachine(const ListWznmQMty1NMachine& src);
	~ListWznmQMty1NMachine();

	void clear();
	unsigned int size() const;
	void append(WznmQMty1NMachine* rec);

	ListWznmQMty1NMachine& operator=(const ListWznmQMty1NMachine& src);

public:
	std::vector<WznmQMty1NMachine*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMty1NMachine: C++ wrapper for table TblWznmQMty1NMachine
	*/
class TblWznmQMty1NMachine {

public:
	TblWznmQMty1NMachine();
	virtual ~TblWznmQMty1NMachine();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMty1NMachine** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMty1NMachine& rst);

	virtual Sbecore::ubigint insertRec(WznmQMty1NMachine* rec);
	Sbecore::ubigint insertNewRec(WznmQMty1NMachine** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMty1NMachine& rst, WznmQMty1NMachine** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQMty1NMachine& rst);
	virtual void updateRec(WznmQMty1NMachine* rec);
	virtual void updateRst(ListWznmQMty1NMachine& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMty1NMachine** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMty1NMachine& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMty1NMachine: C++ wrapper for table TblWznmQMty1NMachine (MySQL database)
	*/
class MyTblWznmQMty1NMachine : public TblWznmQMty1NMachine, public Sbecore::MyTable {

public:
	MyTblWznmQMty1NMachine();
	~MyTblWznmQMty1NMachine();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMty1NMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMty1NMachine& rst);

	Sbecore::ubigint insertRec(WznmQMty1NMachine* rec);
	void insertRst(ListWznmQMty1NMachine& rst);
	void updateRec(WznmQMty1NMachine* rec);
	void updateRst(ListWznmQMty1NMachine& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMty1NMachine** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMty1NMachine& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMty1NMachine: C++ wrapper for table TblWznmQMty1NMachine (PgSQL database)
	*/
class PgTblWznmQMty1NMachine : public TblWznmQMty1NMachine, public Sbecore::PgTable {

public:
	PgTblWznmQMty1NMachine();
	~PgTblWznmQMty1NMachine();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMty1NMachine** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMty1NMachine& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMty1NMachine** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMty1NMachine& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMty1NMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMty1NMachine& rst);

	Sbecore::ubigint insertRec(WznmQMty1NMachine* rec);
	void insertRst(ListWznmQMty1NMachine& rst);
	void updateRec(WznmQMty1NMachine* rec);
	void updateRst(ListWznmQMty1NMachine& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMty1NMachine** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMty1NMachine& rst);
};
#endif

#endif

