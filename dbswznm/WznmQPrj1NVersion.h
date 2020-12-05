/**
	* \file WznmQPrj1NVersion.h
	* Dbs and XML wrapper for table TblWznmQPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRJ1NVERSION_H
#define WZNMQPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrj1NVersion: record of TblWznmQPrj1NVersion
	*/
class WznmQPrj1NVersion {

public:
	WznmQPrj1NVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint prjNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPrj1NVersion: recordset of TblWznmQPrj1NVersion
	*/
class ListWznmQPrj1NVersion {

public:
	ListWznmQPrj1NVersion();
	ListWznmQPrj1NVersion(const ListWznmQPrj1NVersion& src);
	~ListWznmQPrj1NVersion();

	void clear();
	unsigned int size() const;
	void append(WznmQPrj1NVersion* rec);

	ListWznmQPrj1NVersion& operator=(const ListWznmQPrj1NVersion& src);

public:
	std::vector<WznmQPrj1NVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrj1NVersion: C++ wrapper for table TblWznmQPrj1NVersion
	*/
class TblWznmQPrj1NVersion {

public:
	TblWznmQPrj1NVersion();
	virtual ~TblWznmQPrj1NVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrj1NVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrj1NVersion* rec);
	Sbecore::ubigint insertNewRec(WznmQPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrj1NVersion& rst, WznmQPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);
	virtual void insertRst(ListWznmQPrj1NVersion& rst);
	virtual void updateRec(WznmQPrj1NVersion* rec);
	virtual void updateRst(ListWznmQPrj1NVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrj1NVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrj1NVersion: C++ wrapper for table TblWznmQPrj1NVersion (MySQL database)
	*/
class MyTblWznmQPrj1NVersion : public TblWznmQPrj1NVersion, public Sbecore::MyTable {

public:
	MyTblWznmQPrj1NVersion();
	~MyTblWznmQPrj1NVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WznmQPrj1NVersion* rec);
	void insertRst(ListWznmQPrj1NVersion& rst);
	void updateRec(WznmQPrj1NVersion* rec);
	void updateRst(ListWznmQPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrj1NVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrj1NVersion: C++ wrapper for table TblWznmQPrj1NVersion (PgSQL database)
	*/
class PgTblWznmQPrj1NVersion : public TblWznmQPrj1NVersion, public Sbecore::PgTable {

public:
	PgTblWznmQPrj1NVersion();
	~PgTblWznmQPrj1NVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrj1NVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrj1NVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrj1NVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrj1NVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WznmQPrj1NVersion* rec);
	void insertRst(ListWznmQPrj1NVersion& rst);
	void updateRec(WznmQPrj1NVersion* rec);
	void updateRst(ListWznmQPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrj1NVersion& rst);
};
#endif

#endif

