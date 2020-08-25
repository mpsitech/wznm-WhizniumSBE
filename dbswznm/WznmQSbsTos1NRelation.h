/**
	* \file WznmQSbsTos1NRelation.h
	* Dbs and XML wrapper for table TblWznmQSbsTos1NRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSBSTOS1NRELATION_H
#define WZNMQSBSTOS1NRELATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsTos1NRelation: record of TblWznmQSbsTos1NRelation
	*/
class WznmQSbsTos1NRelation {

public:
	WznmQSbsTos1NRelation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQSbsTos1NRelation: recordset of TblWznmQSbsTos1NRelation
	*/
class ListWznmQSbsTos1NRelation {

public:
	ListWznmQSbsTos1NRelation();
	ListWznmQSbsTos1NRelation(const ListWznmQSbsTos1NRelation& src);
	~ListWznmQSbsTos1NRelation();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsTos1NRelation* rec);

	ListWznmQSbsTos1NRelation& operator=(const ListWznmQSbsTos1NRelation& src);

public:
	std::vector<WznmQSbsTos1NRelation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsTos1NRelation: C++ wrapper for table TblWznmQSbsTos1NRelation
	*/
class TblWznmQSbsTos1NRelation {

public:
	TblWznmQSbsTos1NRelation();
	virtual ~TblWznmQSbsTos1NRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsTos1NRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsTos1NRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsTos1NRelation* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsTos1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsTos1NRelation& rst, WznmQSbsTos1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSbsTos1NRelation& rst);
	virtual void updateRec(WznmQSbsTos1NRelation* rec);
	virtual void updateRst(ListWznmQSbsTos1NRelation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsTos1NRelation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsTos1NRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsTos1NRelation: C++ wrapper for table TblWznmQSbsTos1NRelation (MySQL database)
	*/
class MyTblWznmQSbsTos1NRelation : public TblWznmQSbsTos1NRelation, public Sbecore::MyTable {

public:
	MyTblWznmQSbsTos1NRelation();
	~MyTblWznmQSbsTos1NRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsTos1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsTos1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQSbsTos1NRelation* rec);
	void insertRst(ListWznmQSbsTos1NRelation& rst);
	void updateRec(WznmQSbsTos1NRelation* rec);
	void updateRst(ListWznmQSbsTos1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsTos1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsTos1NRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsTos1NRelation: C++ wrapper for table TblWznmQSbsTos1NRelation (PgSQL database)
	*/
class PgTblWznmQSbsTos1NRelation : public TblWznmQSbsTos1NRelation, public Sbecore::PgTable {

public:
	PgTblWznmQSbsTos1NRelation();
	~PgTblWznmQSbsTos1NRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsTos1NRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsTos1NRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsTos1NRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsTos1NRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsTos1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsTos1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQSbsTos1NRelation* rec);
	void insertRst(ListWznmQSbsTos1NRelation& rst);
	void updateRec(WznmQSbsTos1NRelation* rec);
	void updateRst(ListWznmQSbsTos1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsTos1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsTos1NRelation& rst);
};
#endif

#endif

