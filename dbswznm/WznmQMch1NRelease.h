/**
	* \file WznmQMch1NRelease.h
	* Dbs and XML wrapper for table TblWznmQMch1NRelease (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQMCH1NRELEASE_H
#define WZNMQMCH1NRELEASE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMch1NRelease: record of TblWznmQMch1NRelease
	*/
class WznmQMch1NRelease {

public:
	WznmQMch1NRelease(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQMch1NRelease: recordset of TblWznmQMch1NRelease
	*/
class ListWznmQMch1NRelease {

public:
	ListWznmQMch1NRelease();
	ListWznmQMch1NRelease(const ListWznmQMch1NRelease& src);
	~ListWznmQMch1NRelease();

	void clear();
	unsigned int size() const;
	void append(WznmQMch1NRelease* rec);

	ListWznmQMch1NRelease& operator=(const ListWznmQMch1NRelease& src);

public:
	std::vector<WznmQMch1NRelease*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMch1NRelease: C++ wrapper for table TblWznmQMch1NRelease
	*/
class TblWznmQMch1NRelease {

public:
	TblWznmQMch1NRelease();
	virtual ~TblWznmQMch1NRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMch1NRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMch1NRelease& rst);

	virtual Sbecore::ubigint insertRec(WznmQMch1NRelease* rec);
	Sbecore::ubigint insertNewRec(WznmQMch1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMch1NRelease& rst, WznmQMch1NRelease** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQMch1NRelease& rst);
	virtual void updateRec(WznmQMch1NRelease* rec);
	virtual void updateRst(ListWznmQMch1NRelease& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMch1NRelease** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMch1NRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMch1NRelease: C++ wrapper for table TblWznmQMch1NRelease (MySQL database)
	*/
class MyTblWznmQMch1NRelease : public TblWznmQMch1NRelease, public Sbecore::MyTable {

public:
	MyTblWznmQMch1NRelease();
	~MyTblWznmQMch1NRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMch1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMch1NRelease& rst);

	Sbecore::ubigint insertRec(WznmQMch1NRelease* rec);
	void insertRst(ListWznmQMch1NRelease& rst);
	void updateRec(WznmQMch1NRelease* rec);
	void updateRst(ListWznmQMch1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMch1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMch1NRelease& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMch1NRelease: C++ wrapper for table TblWznmQMch1NRelease (PgSQL database)
	*/
class PgTblWznmQMch1NRelease : public TblWznmQMch1NRelease, public Sbecore::PgTable {

public:
	PgTblWznmQMch1NRelease();
	~PgTblWznmQMch1NRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMch1NRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMch1NRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMch1NRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMch1NRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMch1NRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMch1NRelease& rst);

	Sbecore::ubigint insertRec(WznmQMch1NRelease* rec);
	void insertRst(ListWznmQMch1NRelease& rst);
	void updateRec(WznmQMch1NRelease* rec);
	void updateRst(ListWznmQMch1NRelease& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMch1NRelease** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMch1NRelease& rst);
};
#endif

#endif

