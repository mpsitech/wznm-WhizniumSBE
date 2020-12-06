/**
	* \file WznmQVer1NImpexpcplx.h
	* Dbs and XML wrapper for table TblWznmQVer1NImpexpcplx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NIMPEXPCPLX_H
#define WZNMQVER1NIMPEXPCPLX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NImpexpcplx: record of TblWznmQVer1NImpexpcplx
	*/
class WznmQVer1NImpexpcplx {

public:
	WznmQVer1NImpexpcplx(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NImpexpcplx: recordset of TblWznmQVer1NImpexpcplx
	*/
class ListWznmQVer1NImpexpcplx {

public:
	ListWznmQVer1NImpexpcplx();
	ListWznmQVer1NImpexpcplx(const ListWznmQVer1NImpexpcplx& src);
	~ListWznmQVer1NImpexpcplx();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NImpexpcplx* rec);

	ListWznmQVer1NImpexpcplx& operator=(const ListWznmQVer1NImpexpcplx& src);

public:
	std::vector<WznmQVer1NImpexpcplx*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NImpexpcplx: C++ wrapper for table TblWznmQVer1NImpexpcplx
	*/
class TblWznmQVer1NImpexpcplx {

public:
	TblWznmQVer1NImpexpcplx();
	virtual ~TblWznmQVer1NImpexpcplx();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NImpexpcplx** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NImpexpcplx& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NImpexpcplx* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NImpexpcplx** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NImpexpcplx& rst, WznmQVer1NImpexpcplx** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NImpexpcplx& rst);
	virtual void updateRec(WznmQVer1NImpexpcplx* rec);
	virtual void updateRst(ListWznmQVer1NImpexpcplx& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NImpexpcplx** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NImpexpcplx& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NImpexpcplx: C++ wrapper for table TblWznmQVer1NImpexpcplx (MySQL database)
	*/
class MyTblWznmQVer1NImpexpcplx : public TblWznmQVer1NImpexpcplx, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NImpexpcplx();
	~MyTblWznmQVer1NImpexpcplx();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NImpexpcplx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NImpexpcplx& rst);

	Sbecore::ubigint insertRec(WznmQVer1NImpexpcplx* rec);
	void insertRst(ListWznmQVer1NImpexpcplx& rst);
	void updateRec(WznmQVer1NImpexpcplx* rec);
	void updateRst(ListWznmQVer1NImpexpcplx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NImpexpcplx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NImpexpcplx& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NImpexpcplx: C++ wrapper for table TblWznmQVer1NImpexpcplx (PgSQL database)
	*/
class PgTblWznmQVer1NImpexpcplx : public TblWznmQVer1NImpexpcplx, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NImpexpcplx();
	~PgTblWznmQVer1NImpexpcplx();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NImpexpcplx** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NImpexpcplx& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NImpexpcplx** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NImpexpcplx& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NImpexpcplx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NImpexpcplx& rst);

	Sbecore::ubigint insertRec(WznmQVer1NImpexpcplx* rec);
	void insertRst(ListWznmQVer1NImpexpcplx& rst);
	void updateRec(WznmQVer1NImpexpcplx* rec);
	void updateRst(ListWznmQVer1NImpexpcplx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NImpexpcplx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NImpexpcplx& rst);
};
#endif

#endif
