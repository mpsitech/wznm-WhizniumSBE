/**
	* \file WznmQVer1NCapability.h
	* Dbs and XML wrapper for table TblWznmQVer1NCapability (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQVER1NCAPABILITY_H
#define WZNMQVER1NCAPABILITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NCapability: record of TblWznmQVer1NCapability
	*/
class WznmQVer1NCapability {

public:
	WznmQVer1NCapability(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NCapability: recordset of TblWznmQVer1NCapability
	*/
class ListWznmQVer1NCapability {

public:
	ListWznmQVer1NCapability();
	ListWznmQVer1NCapability(const ListWznmQVer1NCapability& src);
	~ListWznmQVer1NCapability();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NCapability* rec);

	ListWznmQVer1NCapability& operator=(const ListWznmQVer1NCapability& src);

public:
	std::vector<WznmQVer1NCapability*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NCapability: C++ wrapper for table TblWznmQVer1NCapability
	*/
class TblWznmQVer1NCapability {

public:
	TblWznmQVer1NCapability();
	virtual ~TblWznmQVer1NCapability();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NCapability** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NCapability& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NCapability* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NCapability** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NCapability& rst, WznmQVer1NCapability** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NCapability& rst);
	virtual void updateRec(WznmQVer1NCapability* rec);
	virtual void updateRst(ListWznmQVer1NCapability& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NCapability** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NCapability& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NCapability: C++ wrapper for table TblWznmQVer1NCapability (MySQL database)
	*/
class MyTblWznmQVer1NCapability : public TblWznmQVer1NCapability, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NCapability();
	~MyTblWznmQVer1NCapability();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NCapability** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NCapability& rst);

	Sbecore::ubigint insertRec(WznmQVer1NCapability* rec);
	void insertRst(ListWznmQVer1NCapability& rst);
	void updateRec(WznmQVer1NCapability* rec);
	void updateRst(ListWznmQVer1NCapability& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NCapability** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NCapability& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NCapability: C++ wrapper for table TblWznmQVer1NCapability (PgSQL database)
	*/
class PgTblWznmQVer1NCapability : public TblWznmQVer1NCapability, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NCapability();
	~PgTblWznmQVer1NCapability();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NCapability** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NCapability& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NCapability** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NCapability& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NCapability** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NCapability& rst);

	Sbecore::ubigint insertRec(WznmQVer1NCapability* rec);
	void insertRst(ListWznmQVer1NCapability& rst);
	void updateRec(WznmQVer1NCapability* rec);
	void updateRst(ListWznmQVer1NCapability& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NCapability** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NCapability& rst);
};
#endif

#endif

