/**
	* \file WznmQVer1NRelation.h
	* Dbs and XML wrapper for table TblWznmQVer1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NRELATION_H
#define WZNMQVER1NRELATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NRelation: record of TblWznmQVer1NRelation
	*/
class WznmQVer1NRelation {

public:
	WznmQVer1NRelation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NRelation: recordset of TblWznmQVer1NRelation
	*/
class ListWznmQVer1NRelation {

public:
	ListWznmQVer1NRelation();
	ListWznmQVer1NRelation(const ListWznmQVer1NRelation& src);
	~ListWznmQVer1NRelation();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NRelation* rec);

	ListWznmQVer1NRelation& operator=(const ListWznmQVer1NRelation& src);

public:
	std::vector<WznmQVer1NRelation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NRelation: C++ wrapper for table TblWznmQVer1NRelation
	*/
class TblWznmQVer1NRelation {

public:
	TblWznmQVer1NRelation();
	virtual ~TblWznmQVer1NRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NRelation* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NRelation& rst, WznmQVer1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NRelation& rst);
	virtual void updateRec(WznmQVer1NRelation* rec);
	virtual void updateRst(ListWznmQVer1NRelation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NRelation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NRelation: C++ wrapper for table TblWznmQVer1NRelation (MySQL database)
	*/
class MyTblWznmQVer1NRelation : public TblWznmQVer1NRelation, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NRelation();
	~MyTblWznmQVer1NRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQVer1NRelation* rec);
	void insertRst(ListWznmQVer1NRelation& rst);
	void updateRec(WznmQVer1NRelation* rec);
	void updateRst(ListWznmQVer1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NRelation: C++ wrapper for table TblWznmQVer1NRelation (PgSQL database)
	*/
class PgTblWznmQVer1NRelation : public TblWznmQVer1NRelation, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NRelation();
	~PgTblWznmQVer1NRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQVer1NRelation* rec);
	void insertRst(ListWznmQVer1NRelation& rst);
	void updateRec(WznmQVer1NRelation* rec);
	void updateRst(ListWznmQVer1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NRelation& rst);
};
#endif

#endif

