/**
	* \file WznmQRtj1NRtdpch.h
	* Dbs and XML wrapper for table TblWznmQRtj1NRtdpch (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQRTJ1NRTDPCH_H
#define WZNMQRTJ1NRTDPCH_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRtj1NRtdpch: record of TblWznmQRtj1NRtdpch
	*/
class WznmQRtj1NRtdpch {

public:
	WznmQRtj1NRtdpch(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQRtj1NRtdpch: recordset of TblWznmQRtj1NRtdpch
	*/
class ListWznmQRtj1NRtdpch {

public:
	ListWznmQRtj1NRtdpch();
	ListWznmQRtj1NRtdpch(const ListWznmQRtj1NRtdpch& src);
	~ListWznmQRtj1NRtdpch();

	void clear();
	unsigned int size() const;
	void append(WznmQRtj1NRtdpch* rec);

	ListWznmQRtj1NRtdpch& operator=(const ListWznmQRtj1NRtdpch& src);

public:
	std::vector<WznmQRtj1NRtdpch*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRtj1NRtdpch: C++ wrapper for table TblWznmQRtj1NRtdpch
	*/
class TblWznmQRtj1NRtdpch {

public:
	TblWznmQRtj1NRtdpch();
	virtual ~TblWznmQRtj1NRtdpch();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRtj1NRtdpch** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtj1NRtdpch& rst);

	virtual Sbecore::ubigint insertRec(WznmQRtj1NRtdpch* rec);
	Sbecore::ubigint insertNewRec(WznmQRtj1NRtdpch** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRtj1NRtdpch& rst, WznmQRtj1NRtdpch** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRtj1NRtdpch& rst);
	virtual void updateRec(WznmQRtj1NRtdpch* rec);
	virtual void updateRst(ListWznmQRtj1NRtdpch& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRtj1NRtdpch** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtj1NRtdpch& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRtj1NRtdpch: C++ wrapper for table TblWznmQRtj1NRtdpch (MySQL database)
	*/
class MyTblWznmQRtj1NRtdpch : public TblWznmQRtj1NRtdpch, public Sbecore::MyTable {

public:
	MyTblWznmQRtj1NRtdpch();
	~MyTblWznmQRtj1NRtdpch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtj1NRtdpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtj1NRtdpch& rst);

	Sbecore::ubigint insertRec(WznmQRtj1NRtdpch* rec);
	void insertRst(ListWznmQRtj1NRtdpch& rst);
	void updateRec(WznmQRtj1NRtdpch* rec);
	void updateRst(ListWznmQRtj1NRtdpch& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtj1NRtdpch** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtj1NRtdpch& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRtj1NRtdpch: C++ wrapper for table TblWznmQRtj1NRtdpch (PgSQL database)
	*/
class PgTblWznmQRtj1NRtdpch : public TblWznmQRtj1NRtdpch, public Sbecore::PgTable {

public:
	PgTblWznmQRtj1NRtdpch();
	~PgTblWznmQRtj1NRtdpch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRtj1NRtdpch** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRtj1NRtdpch& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRtj1NRtdpch** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRtj1NRtdpch& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtj1NRtdpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtj1NRtdpch& rst);

	Sbecore::ubigint insertRec(WznmQRtj1NRtdpch* rec);
	void insertRst(ListWznmQRtj1NRtdpch& rst);
	void updateRec(WznmQRtj1NRtdpch* rec);
	void updateRst(ListWznmQRtj1NRtdpch& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtj1NRtdpch** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtj1NRtdpch& rst);
};
#endif

#endif

