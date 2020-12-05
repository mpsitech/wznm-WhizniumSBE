/**
	* \file WznmQRelSup1NRelation.h
	* Dbs and XML wrapper for table TblWznmQRelSup1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRELSUP1NRELATION_H
#define WZNMQRELSUP1NRELATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRelSup1NRelation: record of TblWznmQRelSup1NRelation
	*/
class WznmQRelSup1NRelation {

public:
	WznmQRelSup1NRelation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQRelSup1NRelation: recordset of TblWznmQRelSup1NRelation
	*/
class ListWznmQRelSup1NRelation {

public:
	ListWznmQRelSup1NRelation();
	ListWznmQRelSup1NRelation(const ListWznmQRelSup1NRelation& src);
	~ListWznmQRelSup1NRelation();

	void clear();
	unsigned int size() const;
	void append(WznmQRelSup1NRelation* rec);

	ListWznmQRelSup1NRelation& operator=(const ListWznmQRelSup1NRelation& src);

public:
	std::vector<WznmQRelSup1NRelation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRelSup1NRelation: C++ wrapper for table TblWznmQRelSup1NRelation
	*/
class TblWznmQRelSup1NRelation {

public:
	TblWznmQRelSup1NRelation();
	virtual ~TblWznmQRelSup1NRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRelSup1NRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelSup1NRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmQRelSup1NRelation* rec);
	Sbecore::ubigint insertNewRec(WznmQRelSup1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRelSup1NRelation& rst, WznmQRelSup1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRelSup1NRelation& rst);
	virtual void updateRec(WznmQRelSup1NRelation* rec);
	virtual void updateRst(ListWznmQRelSup1NRelation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRelSup1NRelation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelSup1NRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRelSup1NRelation: C++ wrapper for table TblWznmQRelSup1NRelation (MySQL database)
	*/
class MyTblWznmQRelSup1NRelation : public TblWznmQRelSup1NRelation, public Sbecore::MyTable {

public:
	MyTblWznmQRelSup1NRelation();
	~MyTblWznmQRelSup1NRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelSup1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelSup1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQRelSup1NRelation* rec);
	void insertRst(ListWznmQRelSup1NRelation& rst);
	void updateRec(WznmQRelSup1NRelation* rec);
	void updateRst(ListWznmQRelSup1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelSup1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelSup1NRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRelSup1NRelation: C++ wrapper for table TblWznmQRelSup1NRelation (PgSQL database)
	*/
class PgTblWznmQRelSup1NRelation : public TblWznmQRelSup1NRelation, public Sbecore::PgTable {

public:
	PgTblWznmQRelSup1NRelation();
	~PgTblWznmQRelSup1NRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRelSup1NRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRelSup1NRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRelSup1NRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRelSup1NRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelSup1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelSup1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQRelSup1NRelation* rec);
	void insertRst(ListWznmQRelSup1NRelation& rst);
	void updateRec(WznmQRelSup1NRelation* rec);
	void updateRst(ListWznmQRelSup1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelSup1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelSup1NRelation& rst);
};
#endif

#endif

