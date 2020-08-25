/**
	* \file WznmQRtj1NRtblock.h
	* Dbs and XML wrapper for table TblWznmQRtj1NRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQRTJ1NRTBLOCK_H
#define WZNMQRTJ1NRTBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRtj1NRtblock: record of TblWznmQRtj1NRtblock
	*/
class WznmQRtj1NRtblock {

public:
	WznmQRtj1NRtblock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQRtj1NRtblock: recordset of TblWznmQRtj1NRtblock
	*/
class ListWznmQRtj1NRtblock {

public:
	ListWznmQRtj1NRtblock();
	ListWznmQRtj1NRtblock(const ListWznmQRtj1NRtblock& src);
	~ListWznmQRtj1NRtblock();

	void clear();
	unsigned int size() const;
	void append(WznmQRtj1NRtblock* rec);

	ListWznmQRtj1NRtblock& operator=(const ListWznmQRtj1NRtblock& src);

public:
	std::vector<WznmQRtj1NRtblock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRtj1NRtblock: C++ wrapper for table TblWznmQRtj1NRtblock
	*/
class TblWznmQRtj1NRtblock {

public:
	TblWznmQRtj1NRtblock();
	virtual ~TblWznmQRtj1NRtblock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRtj1NRtblock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtj1NRtblock& rst);

	virtual Sbecore::ubigint insertRec(WznmQRtj1NRtblock* rec);
	Sbecore::ubigint insertNewRec(WznmQRtj1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRtj1NRtblock& rst, WznmQRtj1NRtblock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRtj1NRtblock& rst);
	virtual void updateRec(WznmQRtj1NRtblock* rec);
	virtual void updateRst(ListWznmQRtj1NRtblock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRtj1NRtblock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtj1NRtblock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRtj1NRtblock: C++ wrapper for table TblWznmQRtj1NRtblock (MySQL database)
	*/
class MyTblWznmQRtj1NRtblock : public TblWznmQRtj1NRtblock, public Sbecore::MyTable {

public:
	MyTblWznmQRtj1NRtblock();
	~MyTblWznmQRtj1NRtblock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtj1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtj1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQRtj1NRtblock* rec);
	void insertRst(ListWznmQRtj1NRtblock& rst);
	void updateRec(WznmQRtj1NRtblock* rec);
	void updateRst(ListWznmQRtj1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtj1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtj1NRtblock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRtj1NRtblock: C++ wrapper for table TblWznmQRtj1NRtblock (PgSQL database)
	*/
class PgTblWznmQRtj1NRtblock : public TblWznmQRtj1NRtblock, public Sbecore::PgTable {

public:
	PgTblWznmQRtj1NRtblock();
	~PgTblWznmQRtj1NRtblock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRtj1NRtblock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRtj1NRtblock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRtj1NRtblock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRtj1NRtblock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtj1NRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtj1NRtblock& rst);

	Sbecore::ubigint insertRec(WznmQRtj1NRtblock* rec);
	void insertRst(ListWznmQRtj1NRtblock& rst);
	void updateRec(WznmQRtj1NRtblock* rec);
	void updateRst(ListWznmQRtj1NRtblock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtj1NRtblock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtj1NRtblock& rst);
};
#endif

#endif

