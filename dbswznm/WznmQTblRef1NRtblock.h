/**
	* \file WznmQTblRef1NRtblock.h
	* Dbs and XML wrapper for table TblWznmQTblRef1NRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTBLREF1NRTBLOCK_H
#define WZNMQTBLREF1NRTBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblRef1NRtblock: record of TblWznmQTblRef1NRtblock
	*/
class WznmQTblRef1NRtblock {

public:
	WznmQTblRef1NRtblock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblRef1NRtblock: recordset of TblWznmQTblRef1NRtblock
	*/
class ListWznmQTblRef1NRtblock {

public:
	ListWznmQTblRef1NRtblock();
	ListWznmQTblRef1NRtblock(const ListWznmQTblRef1NRtblock& src);
	~ListWznmQTblRef1NRtblock();

	void clear();
	unsigned int size() const;
	void append(WznmQTblRef1NRtblock* rec);

	ListWznmQTblRef1NRtblock& operator=(const ListWznmQTblRef1NRtblock& src);

public:
	std::vector<WznmQTblRef1NRtblock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblRef1NRtblock: C++ wrapper for table TblWznmQTblRef1NRtblock
	*/
class TblWznmQTblRef1NRtblock {

public:
	TblWznmQTblRef1NRtblock();
	virtual ~TblWznmQTblRef1NRtblock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NRtblock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NRtblock& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblRef1NRtblock* rec);
	Sbecore::ubigint insertNewRec(WznmQTblRef1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblRef1NRtblock& rst, WznmQTblRef1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblRef1NRtblock& rst);
	virtual void updateRec(WznmQTblRef1NRtblock* rec);
	virtual void updateRst(ListWznmQTblRef1NRtblock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NRtblock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NRtblock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblRef1NRtblock: C++ wrapper for table TblWznmQTblRef1NRtblock (MySQL database)
	*/
class MyTblWznmQTblRef1NRtblock : public TblWznmQTblRef1NRtblock, public Sbecore::MyTable {

public:
	MyTblWznmQTblRef1NRtblock();
	~MyTblWznmQTblRef1NRtblock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NRtblock* rec);
	void insertRst(ListWznmQTblRef1NRtblock& rst);
	void updateRec(WznmQTblRef1NRtblock* rec);
	void updateRst(ListWznmQTblRef1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NRtblock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblRef1NRtblock: C++ wrapper for table TblWznmQTblRef1NRtblock (PgSQL database)
	*/
class PgTblWznmQTblRef1NRtblock : public TblWznmQTblRef1NRtblock, public Sbecore::PgTable {

public:
	PgTblWznmQTblRef1NRtblock();
	~PgTblWznmQTblRef1NRtblock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblRef1NRtblock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblRef1NRtblock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblRef1NRtblock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblRef1NRtblock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NRtblock* rec);
	void insertRst(ListWznmQTblRef1NRtblock& rst);
	void updateRec(WznmQTblRef1NRtblock* rec);
	void updateRst(ListWznmQTblRef1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NRtblock& rst);
};
#endif

#endif

