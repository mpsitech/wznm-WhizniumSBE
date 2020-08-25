/**
	* \file WznmQCmpMNOppack.h
	* Dbs and XML wrapper for table TblWznmQCmpMNOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCMPMNOPPACK_H
#define WZNMQCMPMNOPPACK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCmpMNOppack: record of TblWznmQCmpMNOppack
	*/
class WznmQCmpMNOppack {

public:
	WznmQCmpMNOppack(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCmpMNOppack: recordset of TblWznmQCmpMNOppack
	*/
class ListWznmQCmpMNOppack {

public:
	ListWznmQCmpMNOppack();
	ListWznmQCmpMNOppack(const ListWznmQCmpMNOppack& src);
	~ListWznmQCmpMNOppack();

	void clear();
	unsigned int size() const;
	void append(WznmQCmpMNOppack* rec);

	ListWznmQCmpMNOppack& operator=(const ListWznmQCmpMNOppack& src);

public:
	std::vector<WznmQCmpMNOppack*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCmpMNOppack: C++ wrapper for table TblWznmQCmpMNOppack
	*/
class TblWznmQCmpMNOppack {

public:
	TblWznmQCmpMNOppack();
	virtual ~TblWznmQCmpMNOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCmpMNOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpMNOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmQCmpMNOppack* rec);
	Sbecore::ubigint insertNewRec(WznmQCmpMNOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQCmpMNOppack& rst, WznmQCmpMNOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQCmpMNOppack& rst);
	virtual void updateRec(WznmQCmpMNOppack* rec);
	virtual void updateRst(ListWznmQCmpMNOppack& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpMNOppack** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpMNOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCmpMNOppack: C++ wrapper for table TblWznmQCmpMNOppack (MySQL database)
	*/
class MyTblWznmQCmpMNOppack : public TblWznmQCmpMNOppack, public Sbecore::MyTable {

public:
	MyTblWznmQCmpMNOppack();
	~MyTblWznmQCmpMNOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmpMNOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpMNOppack& rst);

	Sbecore::ubigint insertRec(WznmQCmpMNOppack* rec);
	void insertRst(ListWznmQCmpMNOppack& rst);
	void updateRec(WznmQCmpMNOppack* rec);
	void updateRst(ListWznmQCmpMNOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpMNOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpMNOppack& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCmpMNOppack: C++ wrapper for table TblWznmQCmpMNOppack (PgSQL database)
	*/
class PgTblWznmQCmpMNOppack : public TblWznmQCmpMNOppack, public Sbecore::PgTable {

public:
	PgTblWznmQCmpMNOppack();
	~PgTblWznmQCmpMNOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCmpMNOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCmpMNOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCmpMNOppack** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCmpMNOppack& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmpMNOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpMNOppack& rst);

	Sbecore::ubigint insertRec(WznmQCmpMNOppack* rec);
	void insertRst(ListWznmQCmpMNOppack& rst);
	void updateRec(WznmQCmpMNOppack* rec);
	void updateRst(ListWznmQCmpMNOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpMNOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpMNOppack& rst);
};
#endif

#endif

