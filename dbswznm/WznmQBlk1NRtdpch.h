/**
	* \file WznmQBlk1NRtdpch.h
	* Dbs and XML wrapper for table TblWznmQBlk1NRtdpch (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQBLK1NRTDPCH_H
#define WZNMQBLK1NRTDPCH_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBlk1NRtdpch: record of TblWznmQBlk1NRtdpch
	*/
class WznmQBlk1NRtdpch {

public:
	WznmQBlk1NRtdpch(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQBlk1NRtdpch: recordset of TblWznmQBlk1NRtdpch
	*/
class ListWznmQBlk1NRtdpch {

public:
	ListWznmQBlk1NRtdpch();
	ListWznmQBlk1NRtdpch(const ListWznmQBlk1NRtdpch& src);
	~ListWznmQBlk1NRtdpch();

	void clear();
	unsigned int size() const;
	void append(WznmQBlk1NRtdpch* rec);

	ListWznmQBlk1NRtdpch& operator=(const ListWznmQBlk1NRtdpch& src);

public:
	std::vector<WznmQBlk1NRtdpch*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBlk1NRtdpch: C++ wrapper for table TblWznmQBlk1NRtdpch
	*/
class TblWznmQBlk1NRtdpch {

public:
	TblWznmQBlk1NRtdpch();
	virtual ~TblWznmQBlk1NRtdpch();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBlk1NRtdpch** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlk1NRtdpch& rst);

	virtual Sbecore::ubigint insertRec(WznmQBlk1NRtdpch* rec);
	Sbecore::ubigint insertNewRec(WznmQBlk1NRtdpch** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQBlk1NRtdpch& rst, WznmQBlk1NRtdpch** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQBlk1NRtdpch& rst);
	virtual void updateRec(WznmQBlk1NRtdpch* rec);
	virtual void updateRst(ListWznmQBlk1NRtdpch& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBlk1NRtdpch** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlk1NRtdpch& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBlk1NRtdpch: C++ wrapper for table TblWznmQBlk1NRtdpch (MySQL database)
	*/
class MyTblWznmQBlk1NRtdpch : public TblWznmQBlk1NRtdpch, public Sbecore::MyTable {

public:
	MyTblWznmQBlk1NRtdpch();
	~MyTblWznmQBlk1NRtdpch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlk1NRtdpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlk1NRtdpch& rst);

	Sbecore::ubigint insertRec(WznmQBlk1NRtdpch* rec);
	void insertRst(ListWznmQBlk1NRtdpch& rst);
	void updateRec(WznmQBlk1NRtdpch* rec);
	void updateRst(ListWznmQBlk1NRtdpch& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlk1NRtdpch** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlk1NRtdpch& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBlk1NRtdpch: C++ wrapper for table TblWznmQBlk1NRtdpch (PgSQL database)
	*/
class PgTblWznmQBlk1NRtdpch : public TblWznmQBlk1NRtdpch, public Sbecore::PgTable {

public:
	PgTblWznmQBlk1NRtdpch();
	~PgTblWznmQBlk1NRtdpch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBlk1NRtdpch** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBlk1NRtdpch& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBlk1NRtdpch** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBlk1NRtdpch& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBlk1NRtdpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBlk1NRtdpch& rst);

	Sbecore::ubigint insertRec(WznmQBlk1NRtdpch* rec);
	void insertRst(ListWznmQBlk1NRtdpch& rst);
	void updateRec(WznmQBlk1NRtdpch* rec);
	void updateRst(ListWznmQBlk1NRtdpch& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBlk1NRtdpch** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBlk1NRtdpch& rst);
};
#endif

#endif

