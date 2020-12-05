/**
	* \file WznmQCmp1NRelease.h
	* Dbs and XML wrapper for table TblWznmQCmp1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCMP1NRELEASE_H
#define WZNMQCMP1NRELEASE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCmp1NRelease: record of TblWznmQCmp1NRelease
	*/
class WznmQCmp1NRelease {

public:
	WznmQCmp1NRelease(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQCmp1NRelease: recordset of TblWznmQCmp1NRelease
	*/
class ListWznmQCmp1NRelease {

public:
	ListWznmQCmp1NRelease();
	ListWznmQCmp1NRelease(const ListWznmQCmp1NRelease& src);
	~ListWznmQCmp1NRelease();

	void clear();
	unsigned int size() const;
	void append(WznmQCmp1NRelease* rec);

	ListWznmQCmp1NRelease& operator=(const ListWznmQCmp1NRelease& src);

public:
	std::vector<WznmQCmp1NRelease*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCmp1NRelease: C++ wrapper for table TblWznmQCmp1NRelease
	*/
class TblWznmQCmp1NRelease {

public:
	TblWznmQCmp1NRelease();
	virtual ~TblWznmQCmp1NRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCmp1NRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmp1NRelease& rst);

	virtual Sbecore::ubigint insertRec(WznmQCmp1NRelease* rec);
	Sbecore::ubigint insertNewRec(WznmQCmp1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCmp1NRelease& rst, WznmQCmp1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQCmp1NRelease& rst);
	virtual void updateRec(WznmQCmp1NRelease* rec);
	virtual void updateRst(ListWznmQCmp1NRelease& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCmp1NRelease** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmp1NRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCmp1NRelease: C++ wrapper for table TblWznmQCmp1NRelease (MySQL database)
	*/
class MyTblWznmQCmp1NRelease : public TblWznmQCmp1NRelease, public Sbecore::MyTable {

public:
	MyTblWznmQCmp1NRelease();
	~MyTblWznmQCmp1NRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmp1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmp1NRelease& rst);

	Sbecore::ubigint insertRec(WznmQCmp1NRelease* rec);
	void insertRst(ListWznmQCmp1NRelease& rst);
	void updateRec(WznmQCmp1NRelease* rec);
	void updateRst(ListWznmQCmp1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmp1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmp1NRelease& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCmp1NRelease: C++ wrapper for table TblWznmQCmp1NRelease (PgSQL database)
	*/
class PgTblWznmQCmp1NRelease : public TblWznmQCmp1NRelease, public Sbecore::PgTable {

public:
	PgTblWznmQCmp1NRelease();
	~PgTblWznmQCmp1NRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCmp1NRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCmp1NRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCmp1NRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCmp1NRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmp1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmp1NRelease& rst);

	Sbecore::ubigint insertRec(WznmQCmp1NRelease* rec);
	void insertRst(ListWznmQCmp1NRelease& rst);
	void updateRec(WznmQCmp1NRelease* rec);
	void updateRst(ListWznmQCmp1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmp1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmp1NRelease& rst);
};
#endif

#endif

