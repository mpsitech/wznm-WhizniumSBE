/**
	* \file WznmQTblFr1NRelation.h
	* Dbs and XML wrapper for table TblWznmQTblFr1NRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLFR1NRELATION_H
#define WZNMQTBLFR1NRELATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblFr1NRelation: record of TblWznmQTblFr1NRelation
	*/
class WznmQTblFr1NRelation {

public:
	WznmQTblFr1NRelation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblFr1NRelation: recordset of TblWznmQTblFr1NRelation
	*/
class ListWznmQTblFr1NRelation {

public:
	ListWznmQTblFr1NRelation();
	ListWznmQTblFr1NRelation(const ListWznmQTblFr1NRelation& src);
	~ListWznmQTblFr1NRelation();

	void clear();
	unsigned int size() const;
	void append(WznmQTblFr1NRelation* rec);

	ListWznmQTblFr1NRelation& operator=(const ListWznmQTblFr1NRelation& src);

public:
	std::vector<WznmQTblFr1NRelation*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblFr1NRelation: C++ wrapper for table TblWznmQTblFr1NRelation
	*/
class TblWznmQTblFr1NRelation {

public:
	TblWznmQTblFr1NRelation();
	virtual ~TblWznmQTblFr1NRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblFr1NRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblFr1NRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblFr1NRelation* rec);
	Sbecore::ubigint insertNewRec(WznmQTblFr1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblFr1NRelation& rst, WznmQTblFr1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblFr1NRelation& rst);
	virtual void updateRec(WznmQTblFr1NRelation* rec);
	virtual void updateRst(ListWznmQTblFr1NRelation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblFr1NRelation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblFr1NRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblFr1NRelation: C++ wrapper for table TblWznmQTblFr1NRelation (MySQL database)
	*/
class MyTblWznmQTblFr1NRelation : public TblWznmQTblFr1NRelation, public Sbecore::MyTable {

public:
	MyTblWznmQTblFr1NRelation();
	~MyTblWznmQTblFr1NRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblFr1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblFr1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQTblFr1NRelation* rec);
	void insertRst(ListWznmQTblFr1NRelation& rst);
	void updateRec(WznmQTblFr1NRelation* rec);
	void updateRst(ListWznmQTblFr1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblFr1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblFr1NRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblFr1NRelation: C++ wrapper for table TblWznmQTblFr1NRelation (PgSQL database)
	*/
class PgTblWznmQTblFr1NRelation : public TblWznmQTblFr1NRelation, public Sbecore::PgTable {

public:
	PgTblWznmQTblFr1NRelation();
	~PgTblWznmQTblFr1NRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblFr1NRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblFr1NRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblFr1NRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblFr1NRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblFr1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblFr1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQTblFr1NRelation* rec);
	void insertRst(ListWznmQTblFr1NRelation& rst);
	void updateRec(WznmQTblFr1NRelation* rec);
	void updateRst(ListWznmQTblFr1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblFr1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblFr1NRelation& rst);
};
#endif

#endif
