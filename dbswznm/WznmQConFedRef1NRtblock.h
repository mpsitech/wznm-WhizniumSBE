/**
	* \file WznmQConFedRef1NRtblock.h
	* Dbs and XML wrapper for table TblWznmQConFedRef1NRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCONFEDREF1NRTBLOCK_H
#define WZNMQCONFEDREF1NRTBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQConFedRef1NRtblock: record of TblWznmQConFedRef1NRtblock
	*/
class WznmQConFedRef1NRtblock {

public:
	WznmQConFedRef1NRtblock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQConFedRef1NRtblock: recordset of TblWznmQConFedRef1NRtblock
	*/
class ListWznmQConFedRef1NRtblock {

public:
	ListWznmQConFedRef1NRtblock();
	ListWznmQConFedRef1NRtblock(const ListWznmQConFedRef1NRtblock& src);
	~ListWznmQConFedRef1NRtblock();

	void clear();
	unsigned int size() const;
	void append(WznmQConFedRef1NRtblock* rec);

	ListWznmQConFedRef1NRtblock& operator=(const ListWznmQConFedRef1NRtblock& src);

public:
	std::vector<WznmQConFedRef1NRtblock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQConFedRef1NRtblock: C++ wrapper for table TblWznmQConFedRef1NRtblock
	*/
class TblWznmQConFedRef1NRtblock {

public:
	TblWznmQConFedRef1NRtblock();
	virtual ~TblWznmQConFedRef1NRtblock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQConFedRef1NRtblock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConFedRef1NRtblock& rst);

	virtual Sbecore::ubigint insertRec(WznmQConFedRef1NRtblock* rec);
	Sbecore::ubigint insertNewRec(WznmQConFedRef1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQConFedRef1NRtblock& rst, WznmQConFedRef1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQConFedRef1NRtblock& rst);
	virtual void updateRec(WznmQConFedRef1NRtblock* rec);
	virtual void updateRst(ListWznmQConFedRef1NRtblock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQConFedRef1NRtblock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConFedRef1NRtblock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQConFedRef1NRtblock: C++ wrapper for table TblWznmQConFedRef1NRtblock (MySQL database)
	*/
class MyTblWznmQConFedRef1NRtblock : public TblWznmQConFedRef1NRtblock, public Sbecore::MyTable {

public:
	MyTblWznmQConFedRef1NRtblock();
	~MyTblWznmQConFedRef1NRtblock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConFedRef1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConFedRef1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQConFedRef1NRtblock* rec);
	void insertRst(ListWznmQConFedRef1NRtblock& rst);
	void updateRec(WznmQConFedRef1NRtblock* rec);
	void updateRst(ListWznmQConFedRef1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConFedRef1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConFedRef1NRtblock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQConFedRef1NRtblock: C++ wrapper for table TblWznmQConFedRef1NRtblock (PgSQL database)
	*/
class PgTblWznmQConFedRef1NRtblock : public TblWznmQConFedRef1NRtblock, public Sbecore::PgTable {

public:
	PgTblWznmQConFedRef1NRtblock();
	~PgTblWznmQConFedRef1NRtblock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQConFedRef1NRtblock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQConFedRef1NRtblock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQConFedRef1NRtblock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQConFedRef1NRtblock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConFedRef1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConFedRef1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQConFedRef1NRtblock* rec);
	void insertRst(ListWznmQConFedRef1NRtblock& rst);
	void updateRec(WznmQConFedRef1NRtblock* rec);
	void updateRst(ListWznmQConFedRef1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConFedRef1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConFedRef1NRtblock& rst);
};
#endif

#endif

