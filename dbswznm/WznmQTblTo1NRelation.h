/**
	* \file WznmQTblTo1NRelation.h
	* Dbs and XML wrapper for table TblWznmQTblTo1NRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLTO1NRELATION_H
#define WZNMQTBLTO1NRELATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblTo1NRelation: record of TblWznmQTblTo1NRelation
	*/
class WznmQTblTo1NRelation {

public:
	WznmQTblTo1NRelation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblTo1NRelation: recordset of TblWznmQTblTo1NRelation
	*/
class ListWznmQTblTo1NRelation {

public:
	ListWznmQTblTo1NRelation();
	ListWznmQTblTo1NRelation(const ListWznmQTblTo1NRelation& src);
	~ListWznmQTblTo1NRelation();

	void clear();
	unsigned int size() const;
	void append(WznmQTblTo1NRelation* rec);

	ListWznmQTblTo1NRelation& operator=(const ListWznmQTblTo1NRelation& src);

public:
	std::vector<WznmQTblTo1NRelation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblTo1NRelation: C++ wrapper for table TblWznmQTblTo1NRelation
	*/
class TblWznmQTblTo1NRelation {

public:
	TblWznmQTblTo1NRelation();
	virtual ~TblWznmQTblTo1NRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblTo1NRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblTo1NRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblTo1NRelation* rec);
	Sbecore::ubigint insertNewRec(WznmQTblTo1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblTo1NRelation& rst, WznmQTblTo1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblTo1NRelation& rst);
	virtual void updateRec(WznmQTblTo1NRelation* rec);
	virtual void updateRst(ListWznmQTblTo1NRelation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblTo1NRelation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblTo1NRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblTo1NRelation: C++ wrapper for table TblWznmQTblTo1NRelation (MySQL database)
	*/
class MyTblWznmQTblTo1NRelation : public TblWznmQTblTo1NRelation, public Sbecore::MyTable {

public:
	MyTblWznmQTblTo1NRelation();
	~MyTblWznmQTblTo1NRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblTo1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblTo1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQTblTo1NRelation* rec);
	void insertRst(ListWznmQTblTo1NRelation& rst);
	void updateRec(WznmQTblTo1NRelation* rec);
	void updateRst(ListWznmQTblTo1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblTo1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblTo1NRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblTo1NRelation: C++ wrapper for table TblWznmQTblTo1NRelation (PgSQL database)
	*/
class PgTblWznmQTblTo1NRelation : public TblWznmQTblTo1NRelation, public Sbecore::PgTable {

public:
	PgTblWznmQTblTo1NRelation();
	~PgTblWznmQTblTo1NRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblTo1NRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblTo1NRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblTo1NRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblTo1NRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblTo1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblTo1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQTblTo1NRelation* rec);
	void insertRst(ListWznmQTblTo1NRelation& rst);
	void updateRec(WznmQTblTo1NRelation* rec);
	void updateRst(ListWznmQTblTo1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblTo1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblTo1NRelation& rst);
};
#endif

#endif

