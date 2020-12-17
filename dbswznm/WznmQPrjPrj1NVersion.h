/**
	* \file WznmQPrjPrj1NVersion.h
	* Dbs and XML wrapper for table TblWznmQPrjPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRJPRJ1NVERSION_H
#define WZNMQPRJPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrjPrj1NVersion: record of TblWznmQPrjPrj1NVersion
	*/
class WznmQPrjPrj1NVersion {

public:
	WznmQPrjPrj1NVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);

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
	* ListWznmQPrjPrj1NVersion: recordset of TblWznmQPrjPrj1NVersion
	*/
class ListWznmQPrjPrj1NVersion {

public:
	ListWznmQPrjPrj1NVersion();
	ListWznmQPrjPrj1NVersion(const ListWznmQPrjPrj1NVersion& src);
	~ListWznmQPrjPrj1NVersion();

	void clear();
	unsigned int size() const;
	void append(WznmQPrjPrj1NVersion* rec);

	ListWznmQPrjPrj1NVersion& operator=(const ListWznmQPrjPrj1NVersion& src);

public:
	std::vector<WznmQPrjPrj1NVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrjPrj1NVersion: C++ wrapper for table TblWznmQPrjPrj1NVersion
	*/
class TblWznmQPrjPrj1NVersion {

public:
	TblWznmQPrjPrj1NVersion();
	virtual ~TblWznmQPrjPrj1NVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrjPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjPrj1NVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrjPrj1NVersion* rec);
	Sbecore::ubigint insertNewRec(WznmQPrjPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrjPrj1NVersion& rst, WznmQPrjPrj1NVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint prjNum = 0);
	virtual void insertRst(ListWznmQPrjPrj1NVersion& rst);
	virtual void updateRec(WznmQPrjPrj1NVersion* rec);
	virtual void updateRst(ListWznmQPrjPrj1NVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjPrj1NVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjPrj1NVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrjPrj1NVersion: C++ wrapper for table TblWznmQPrjPrj1NVersion (MySQL database)
	*/
class MyTblWznmQPrjPrj1NVersion : public TblWznmQPrjPrj1NVersion, public Sbecore::MyTable {

public:
	MyTblWznmQPrjPrj1NVersion();
	~MyTblWznmQPrjPrj1NVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WznmQPrjPrj1NVersion* rec);
	void insertRst(ListWznmQPrjPrj1NVersion& rst);
	void updateRec(WznmQPrjPrj1NVersion* rec);
	void updateRst(ListWznmQPrjPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjPrj1NVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrjPrj1NVersion: C++ wrapper for table TblWznmQPrjPrj1NVersion (PgSQL database)
	*/
class PgTblWznmQPrjPrj1NVersion : public TblWznmQPrjPrj1NVersion, public Sbecore::PgTable {

public:
	PgTblWznmQPrjPrj1NVersion();
	~PgTblWznmQPrjPrj1NVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrjPrj1NVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrjPrj1NVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrjPrj1NVersion& rst);

	Sbecore::ubigint insertRec(WznmQPrjPrj1NVersion* rec);
	void insertRst(ListWznmQPrjPrj1NVersion& rst);
	void updateRec(WznmQPrjPrj1NVersion* rec);
	void updateRst(ListWznmQPrjPrj1NVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrjPrj1NVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrjPrj1NVersion& rst);
};
#endif

#endif
