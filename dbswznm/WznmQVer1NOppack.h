/**
	* \file WznmQVer1NOppack.h
	* Dbs and XML wrapper for table TblWznmQVer1NOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVER1NOPPACK_H
#define WZNMQVER1NOPPACK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NOppack: record of TblWznmQVer1NOppack
	*/
class WznmQVer1NOppack {

public:
	WznmQVer1NOppack(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NOppack: recordset of TblWznmQVer1NOppack
	*/
class ListWznmQVer1NOppack {

public:
	ListWznmQVer1NOppack();
	ListWznmQVer1NOppack(const ListWznmQVer1NOppack& src);
	~ListWznmQVer1NOppack();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NOppack* rec);

	ListWznmQVer1NOppack& operator=(const ListWznmQVer1NOppack& src);

public:
	std::vector<WznmQVer1NOppack*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NOppack: C++ wrapper for table TblWznmQVer1NOppack
	*/
class TblWznmQVer1NOppack {

public:
	TblWznmQVer1NOppack();
	virtual ~TblWznmQVer1NOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NOppack* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NOppack& rst, WznmQVer1NOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NOppack& rst);
	virtual void updateRec(WznmQVer1NOppack* rec);
	virtual void updateRst(ListWznmQVer1NOppack& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NOppack** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NOppack: C++ wrapper for table TblWznmQVer1NOppack (MySQL database)
	*/
class MyTblWznmQVer1NOppack : public TblWznmQVer1NOppack, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NOppack();
	~MyTblWznmQVer1NOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NOppack& rst);

	Sbecore::ubigint insertRec(WznmQVer1NOppack* rec);
	void insertRst(ListWznmQVer1NOppack& rst);
	void updateRec(WznmQVer1NOppack* rec);
	void updateRst(ListWznmQVer1NOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NOppack& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NOppack: C++ wrapper for table TblWznmQVer1NOppack (PgSQL database)
	*/
class PgTblWznmQVer1NOppack : public TblWznmQVer1NOppack, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NOppack();
	~PgTblWznmQVer1NOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NOppack** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NOppack& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NOppack& rst);

	Sbecore::ubigint insertRec(WznmQVer1NOppack* rec);
	void insertRst(ListWznmQVer1NOppack& rst);
	void updateRec(WznmQVer1NOppack* rec);
	void updateRst(ListWznmQVer1NOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NOppack& rst);
};
#endif

#endif

