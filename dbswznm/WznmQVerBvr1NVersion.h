/**
	* \file WznmQVerBvr1NVersion.h
	* Dbs and XML wrapper for table TblWznmQVerBvr1NVersion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQVERBVR1NVERSION_H
#define WZNMQVERBVR1NVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerBvr1NVersion: record of TblWznmQVerBvr1NVersion
	*/
class WznmQVerBvr1NVersion {

public:
	WznmQVerBvr1NVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVerBvr1NVersion: recordset of TblWznmQVerBvr1NVersion
	*/
class ListWznmQVerBvr1NVersion {

public:
	ListWznmQVerBvr1NVersion();
	ListWznmQVerBvr1NVersion(const ListWznmQVerBvr1NVersion& src);
	~ListWznmQVerBvr1NVersion();

	void clear();
	unsigned int size() const;
	void append(WznmQVerBvr1NVersion* rec);

	ListWznmQVerBvr1NVersion& operator=(const ListWznmQVerBvr1NVersion& src);

public:
	std::vector<WznmQVerBvr1NVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerBvr1NVersion: C++ wrapper for table TblWznmQVerBvr1NVersion
	*/
class TblWznmQVerBvr1NVersion {

public:
	TblWznmQVerBvr1NVersion();
	virtual ~TblWznmQVerBvr1NVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerBvr1NVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerBvr1NVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerBvr1NVersion* rec);
	Sbecore::ubigint insertNewRec(WznmQVerBvr1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerBvr1NVersion& rst, WznmQVerBvr1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVerBvr1NVersion& rst);
	virtual void updateRec(WznmQVerBvr1NVersion* rec);
	virtual void updateRst(ListWznmQVerBvr1NVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerBvr1NVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerBvr1NVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerBvr1NVersion: C++ wrapper for table TblWznmQVerBvr1NVersion (MySQL database)
	*/
class MyTblWznmQVerBvr1NVersion : public TblWznmQVerBvr1NVersion, public Sbecore::MyTable {

public:
	MyTblWznmQVerBvr1NVersion();
	~MyTblWznmQVerBvr1NVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerBvr1NVersion& rst);

	Sbecore::ubigint insertRec(WznmQVerBvr1NVersion* rec);
	void insertRst(ListWznmQVerBvr1NVersion& rst);
	void updateRec(WznmQVerBvr1NVersion* rec);
	void updateRst(ListWznmQVerBvr1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerBvr1NVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerBvr1NVersion: C++ wrapper for table TblWznmQVerBvr1NVersion (PgSQL database)
	*/
class PgTblWznmQVerBvr1NVersion : public TblWznmQVerBvr1NVersion, public Sbecore::PgTable {

public:
	PgTblWznmQVerBvr1NVersion();
	~PgTblWznmQVerBvr1NVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerBvr1NVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerBvr1NVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerBvr1NVersion& rst);

	Sbecore::ubigint insertRec(WznmQVerBvr1NVersion* rec);
	void insertRst(ListWznmQVerBvr1NVersion& rst);
	void updateRec(WznmQVerBvr1NVersion* rec);
	void updateRst(ListWznmQVerBvr1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerBvr1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerBvr1NVersion& rst);
};
#endif

#endif

