/**
	* \file WznmQSbsFrs1NRelation.h
	* Dbs and XML wrapper for table TblWznmQSbsFrs1NRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBSFRS1NRELATION_H
#define WZNMQSBSFRS1NRELATION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsFrs1NRelation: record of TblWznmQSbsFrs1NRelation
	*/
class WznmQSbsFrs1NRelation {

public:
	WznmQSbsFrs1NRelation(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQSbsFrs1NRelation: recordset of TblWznmQSbsFrs1NRelation
	*/
class ListWznmQSbsFrs1NRelation {

public:
	ListWznmQSbsFrs1NRelation();
	ListWznmQSbsFrs1NRelation(const ListWznmQSbsFrs1NRelation& src);
	~ListWznmQSbsFrs1NRelation();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsFrs1NRelation* rec);

	ListWznmQSbsFrs1NRelation& operator=(const ListWznmQSbsFrs1NRelation& src);

public:
	std::vector<WznmQSbsFrs1NRelation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsFrs1NRelation: C++ wrapper for table TblWznmQSbsFrs1NRelation
	*/
class TblWznmQSbsFrs1NRelation {

public:
	TblWznmQSbsFrs1NRelation();
	virtual ~TblWznmQSbsFrs1NRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsFrs1NRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsFrs1NRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsFrs1NRelation* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsFrs1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsFrs1NRelation& rst, WznmQSbsFrs1NRelation** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSbsFrs1NRelation& rst);
	virtual void updateRec(WznmQSbsFrs1NRelation* rec);
	virtual void updateRst(ListWznmQSbsFrs1NRelation& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsFrs1NRelation** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsFrs1NRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsFrs1NRelation: C++ wrapper for table TblWznmQSbsFrs1NRelation (MySQL database)
	*/
class MyTblWznmQSbsFrs1NRelation : public TblWznmQSbsFrs1NRelation, public Sbecore::MyTable {

public:
	MyTblWznmQSbsFrs1NRelation();
	~MyTblWznmQSbsFrs1NRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsFrs1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsFrs1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQSbsFrs1NRelation* rec);
	void insertRst(ListWznmQSbsFrs1NRelation& rst);
	void updateRec(WznmQSbsFrs1NRelation* rec);
	void updateRst(ListWznmQSbsFrs1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsFrs1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsFrs1NRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsFrs1NRelation: C++ wrapper for table TblWznmQSbsFrs1NRelation (PgSQL database)
	*/
class PgTblWznmQSbsFrs1NRelation : public TblWznmQSbsFrs1NRelation, public Sbecore::PgTable {

public:
	PgTblWznmQSbsFrs1NRelation();
	~PgTblWznmQSbsFrs1NRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsFrs1NRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsFrs1NRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsFrs1NRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsFrs1NRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsFrs1NRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsFrs1NRelation& rst);

	Sbecore::ubigint insertRec(WznmQSbsFrs1NRelation* rec);
	void insertRst(ListWznmQSbsFrs1NRelation& rst);
	void updateRec(WznmQSbsFrs1NRelation* rec);
	void updateRst(ListWznmQSbsFrs1NRelation& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsFrs1NRelation** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsFrs1NRelation& rst);
};
#endif

#endif

