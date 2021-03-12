/**
	* \file WznmQMchSup1NMachine.h
	* Dbs and XML wrapper for table TblWznmQMchSup1NMachine (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMCHSUP1NMACHINE_H
#define WZNMQMCHSUP1NMACHINE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMchSup1NMachine: record of TblWznmQMchSup1NMachine
	*/
class WznmQMchSup1NMachine {

public:
	WznmQMchSup1NMachine(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMchSup1NMachine: recordset of TblWznmQMchSup1NMachine
	*/
class ListWznmQMchSup1NMachine {

public:
	ListWznmQMchSup1NMachine();
	ListWznmQMchSup1NMachine(const ListWznmQMchSup1NMachine& src);
	~ListWznmQMchSup1NMachine();

	void clear();
	unsigned int size() const;
	void append(WznmQMchSup1NMachine* rec);

	ListWznmQMchSup1NMachine& operator=(const ListWznmQMchSup1NMachine& src);

public:
	std::vector<WznmQMchSup1NMachine*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMchSup1NMachine: C++ wrapper for table TblWznmQMchSup1NMachine
	*/
class TblWznmQMchSup1NMachine {

public:
	TblWznmQMchSup1NMachine();
	virtual ~TblWznmQMchSup1NMachine();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMchSup1NMachine** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchSup1NMachine& rst);

	virtual Sbecore::ubigint insertRec(WznmQMchSup1NMachine* rec);
	Sbecore::ubigint insertNewRec(WznmQMchSup1NMachine** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMchSup1NMachine& rst, WznmQMchSup1NMachine** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQMchSup1NMachine& rst);
	virtual void updateRec(WznmQMchSup1NMachine* rec);
	virtual void updateRst(ListWznmQMchSup1NMachine& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMchSup1NMachine** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchSup1NMachine& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMchSup1NMachine: C++ wrapper for table TblWznmQMchSup1NMachine (MySQL database)
	*/
class MyTblWznmQMchSup1NMachine : public TblWznmQMchSup1NMachine, public Sbecore::MyTable {

public:
	MyTblWznmQMchSup1NMachine();
	~MyTblWznmQMchSup1NMachine();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchSup1NMachine& rst);

	Sbecore::ubigint insertRec(WznmQMchSup1NMachine* rec);
	void insertRst(ListWznmQMchSup1NMachine& rst);
	void updateRec(WznmQMchSup1NMachine* rec);
	void updateRst(ListWznmQMchSup1NMachine& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchSup1NMachine& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMchSup1NMachine: C++ wrapper for table TblWznmQMchSup1NMachine (PgSQL database)
	*/
class PgTblWznmQMchSup1NMachine : public TblWznmQMchSup1NMachine, public Sbecore::PgTable {

public:
	PgTblWznmQMchSup1NMachine();
	~PgTblWznmQMchSup1NMachine();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMchSup1NMachine** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMchSup1NMachine& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMchSup1NMachine& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchSup1NMachine& rst);

	Sbecore::ubigint insertRec(WznmQMchSup1NMachine* rec);
	void insertRst(ListWznmQMchSup1NMachine& rst);
	void updateRec(WznmQMchSup1NMachine* rec);
	void updateRst(ListWznmQMchSup1NMachine& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchSup1NMachine** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchSup1NMachine& rst);
};
#endif

#endif
