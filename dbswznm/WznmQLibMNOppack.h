/**
	* \file WznmQLibMNOppack.h
	* Dbs and XML wrapper for table TblWznmQLibMNOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQLIBMNOPPACK_H
#define WZNMQLIBMNOPPACK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLibMNOppack: record of TblWznmQLibMNOppack
	*/
class WznmQLibMNOppack {

public:
	WznmQLibMNOppack(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQLibMNOppack: recordset of TblWznmQLibMNOppack
	*/
class ListWznmQLibMNOppack {

public:
	ListWznmQLibMNOppack();
	ListWznmQLibMNOppack(const ListWznmQLibMNOppack& src);
	~ListWznmQLibMNOppack();

	void clear();
	unsigned int size() const;
	void append(WznmQLibMNOppack* rec);

	ListWznmQLibMNOppack& operator=(const ListWznmQLibMNOppack& src);

public:
	std::vector<WznmQLibMNOppack*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLibMNOppack: C++ wrapper for table TblWznmQLibMNOppack
	*/
class TblWznmQLibMNOppack {

public:
	TblWznmQLibMNOppack();
	virtual ~TblWznmQLibMNOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLibMNOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibMNOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmQLibMNOppack* rec);
	Sbecore::ubigint insertNewRec(WznmQLibMNOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQLibMNOppack& rst, WznmQLibMNOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQLibMNOppack& rst);
	virtual void updateRec(WznmQLibMNOppack* rec);
	virtual void updateRst(ListWznmQLibMNOppack& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLibMNOppack** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibMNOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLibMNOppack: C++ wrapper for table TblWznmQLibMNOppack (MySQL database)
	*/
class MyTblWznmQLibMNOppack : public TblWznmQLibMNOppack, public Sbecore::MyTable {

public:
	MyTblWznmQLibMNOppack();
	~MyTblWznmQLibMNOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibMNOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibMNOppack& rst);

	Sbecore::ubigint insertRec(WznmQLibMNOppack* rec);
	void insertRst(ListWznmQLibMNOppack& rst);
	void updateRec(WznmQLibMNOppack* rec);
	void updateRst(ListWznmQLibMNOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibMNOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibMNOppack& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLibMNOppack: C++ wrapper for table TblWznmQLibMNOppack (PgSQL database)
	*/
class PgTblWznmQLibMNOppack : public TblWznmQLibMNOppack, public Sbecore::PgTable {

public:
	PgTblWznmQLibMNOppack();
	~PgTblWznmQLibMNOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLibMNOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLibMNOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLibMNOppack** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLibMNOppack& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibMNOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibMNOppack& rst);

	Sbecore::ubigint insertRec(WznmQLibMNOppack* rec);
	void insertRst(ListWznmQLibMNOppack& rst);
	void updateRec(WznmQLibMNOppack* rec);
	void updateRst(ListWznmQLibMNOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibMNOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibMNOppack& rst);
};
#endif

#endif

