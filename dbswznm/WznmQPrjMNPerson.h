/**
	* \file WznmQPrjMNPerson.h
	* Dbs and XML wrapper for table TblWznmQPrjMNPerson (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQPRJMNPERSON_H
#define WZNMQPRJMNPERSON_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrjMNPerson: record of TblWznmQPrjMNPerson
	*/
class WznmQPrjMNPerson {

public:
	WznmQPrjMNPerson(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint x1Startd;
	std::string ftmX1Startd;
	Sbecore::uint x1Stopd;
	std::string ftmX1Stopd;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPrjMNPerson: recordset of TblWznmQPrjMNPerson
	*/
class ListWznmQPrjMNPerson {

public:
	ListWznmQPrjMNPerson();
	ListWznmQPrjMNPerson(const ListWznmQPrjMNPerson& src);
	~ListWznmQPrjMNPerson();

	void clear();
	unsigned int size() const;
	void append(WznmQPrjMNPerson* rec);

	ListWznmQPrjMNPerson& operator=(const ListWznmQPrjMNPerson& src);

public:
	std::vector<WznmQPrjMNPerson*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrjMNPerson: C++ wrapper for table TblWznmQPrjMNPerson
	*/
class TblWznmQPrjMNPerson {

public:
	TblWznmQPrjMNPerson();
	virtual ~TblWznmQPrjMNPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrjMNPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjMNPerson& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrjMNPerson* rec);
	Sbecore::ubigint insertNewRec(WznmQPrjMNPerson** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrjMNPerson& rst, WznmQPrjMNPerson** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWznmQPrjMNPerson& rst);
	virtual void updateRec(WznmQPrjMNPerson* rec);
	virtual void updateRst(ListWznmQPrjMNPerson& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjMNPerson** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjMNPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrjMNPerson: C++ wrapper for table TblWznmQPrjMNPerson (MySQL database)
	*/
class MyTblWznmQPrjMNPerson : public TblWznmQPrjMNPerson, public Sbecore::MyTable {

public:
	MyTblWznmQPrjMNPerson();
	~MyTblWznmQPrjMNPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrjMNPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjMNPerson& rst);

	Sbecore::ubigint insertRec(WznmQPrjMNPerson* rec);
	void insertRst(ListWznmQPrjMNPerson& rst);
	void updateRec(WznmQPrjMNPerson* rec);
	void updateRst(ListWznmQPrjMNPerson& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjMNPerson** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjMNPerson& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrjMNPerson: C++ wrapper for table TblWznmQPrjMNPerson (PgSQL database)
	*/
class PgTblWznmQPrjMNPerson : public TblWznmQPrjMNPerson, public Sbecore::PgTable {

public:
	PgTblWznmQPrjMNPerson();
	~PgTblWznmQPrjMNPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrjMNPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrjMNPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrjMNPerson** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrjMNPerson& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrjMNPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjMNPerson& rst);

	Sbecore::ubigint insertRec(WznmQPrjMNPerson* rec);
	void insertRst(ListWznmQPrjMNPerson& rst);
	void updateRec(WznmQPrjMNPerson* rec);
	void updateRst(ListWznmQPrjMNPerson& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjMNPerson** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjMNPerson& rst);
};
#endif

#endif

