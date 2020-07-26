/**
	* \file WznmQBlkRef1NRtblock.h
	* Dbs and XML wrapper for table TblWznmQBlkRef1NRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQBLKREF1NRTBLOCK_H
#define WZNMQBLKREF1NRTBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBlkRef1NRtblock: record of TblWznmQBlkRef1NRtblock
	*/
class WznmQBlkRef1NRtblock {

public:
	WznmQBlkRef1NRtblock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQBlkRef1NRtblock: recordset of TblWznmQBlkRef1NRtblock
	*/
class ListWznmQBlkRef1NRtblock {

public:
	ListWznmQBlkRef1NRtblock();
	ListWznmQBlkRef1NRtblock(const ListWznmQBlkRef1NRtblock& src);
	~ListWznmQBlkRef1NRtblock();

	void clear();
	unsigned int size() const;
	void append(WznmQBlkRef1NRtblock* rec);

	ListWznmQBlkRef1NRtblock& operator=(const ListWznmQBlkRef1NRtblock& src);

public:
	std::vector<WznmQBlkRef1NRtblock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBlkRef1NRtblock: C++ wrapper for table TblWznmQBlkRef1NRtblock
	*/
class TblWznmQBlkRef1NRtblock {

public:
	TblWznmQBlkRef1NRtblock();
	virtual ~TblWznmQBlkRef1NRtblock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBlkRef1NRtblock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkRef1NRtblock& rst);

	virtual Sbecore::ubigint insertRec(WznmQBlkRef1NRtblock* rec);
	Sbecore::ubigint insertNewRec(WznmQBlkRef1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQBlkRef1NRtblock& rst, WznmQBlkRef1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQBlkRef1NRtblock& rst);
	virtual void updateRec(WznmQBlkRef1NRtblock* rec);
	virtual void updateRst(ListWznmQBlkRef1NRtblock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkRef1NRtblock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkRef1NRtblock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBlkRef1NRtblock: C++ wrapper for table TblWznmQBlkRef1NRtblock (MySQL database)
	*/
class MyTblWznmQBlkRef1NRtblock : public TblWznmQBlkRef1NRtblock, public Sbecore::MyTable {

public:
	MyTblWznmQBlkRef1NRtblock();
	~MyTblWznmQBlkRef1NRtblock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlkRef1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkRef1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQBlkRef1NRtblock* rec);
	void insertRst(ListWznmQBlkRef1NRtblock& rst);
	void updateRec(WznmQBlkRef1NRtblock* rec);
	void updateRst(ListWznmQBlkRef1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkRef1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkRef1NRtblock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBlkRef1NRtblock: C++ wrapper for table TblWznmQBlkRef1NRtblock (PgSQL database)
	*/
class PgTblWznmQBlkRef1NRtblock : public TblWznmQBlkRef1NRtblock, public Sbecore::PgTable {

public:
	PgTblWznmQBlkRef1NRtblock();
	~PgTblWznmQBlkRef1NRtblock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBlkRef1NRtblock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBlkRef1NRtblock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBlkRef1NRtblock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBlkRef1NRtblock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlkRef1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlkRef1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQBlkRef1NRtblock* rec);
	void insertRst(ListWznmQBlkRef1NRtblock& rst);
	void updateRec(WznmQBlkRef1NRtblock* rec);
	void updateRst(ListWznmQBlkRef1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlkRef1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlkRef1NRtblock& rst);
};
#endif

#endif

