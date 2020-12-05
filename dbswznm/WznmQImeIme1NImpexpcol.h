/**
	* \file WznmQImeIme1NImpexpcol.h
	* Dbs and XML wrapper for table TblWznmQImeIme1NImpexpcol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIMEIME1NIMPEXPCOL_H
#define WZNMQIMEIME1NIMPEXPCOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQImeIme1NImpexpcol: record of TblWznmQImeIme1NImpexpcol
	*/
class WznmQImeIme1NImpexpcol {

public:
	WznmQImeIme1NImpexpcol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint imeNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint imeNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQImeIme1NImpexpcol: recordset of TblWznmQImeIme1NImpexpcol
	*/
class ListWznmQImeIme1NImpexpcol {

public:
	ListWznmQImeIme1NImpexpcol();
	ListWznmQImeIme1NImpexpcol(const ListWznmQImeIme1NImpexpcol& src);
	~ListWznmQImeIme1NImpexpcol();

	void clear();
	unsigned int size() const;
	void append(WznmQImeIme1NImpexpcol* rec);

	ListWznmQImeIme1NImpexpcol& operator=(const ListWznmQImeIme1NImpexpcol& src);

public:
	std::vector<WznmQImeIme1NImpexpcol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQImeIme1NImpexpcol: C++ wrapper for table TblWznmQImeIme1NImpexpcol
	*/
class TblWznmQImeIme1NImpexpcol {

public:
	TblWznmQImeIme1NImpexpcol();
	virtual ~TblWznmQImeIme1NImpexpcol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQImeIme1NImpexpcol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeIme1NImpexpcol& rst);

	virtual Sbecore::ubigint insertRec(WznmQImeIme1NImpexpcol* rec);
	Sbecore::ubigint insertNewRec(WznmQImeIme1NImpexpcol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint imeNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQImeIme1NImpexpcol& rst, WznmQImeIme1NImpexpcol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint imeNum = 0);
	virtual void insertRst(ListWznmQImeIme1NImpexpcol& rst);
	virtual void updateRec(WznmQImeIme1NImpexpcol* rec);
	virtual void updateRst(ListWznmQImeIme1NImpexpcol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQImeIme1NImpexpcol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeIme1NImpexpcol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQImeIme1NImpexpcol: C++ wrapper for table TblWznmQImeIme1NImpexpcol (MySQL database)
	*/
class MyTblWznmQImeIme1NImpexpcol : public TblWznmQImeIme1NImpexpcol, public Sbecore::MyTable {

public:
	MyTblWznmQImeIme1NImpexpcol();
	~MyTblWznmQImeIme1NImpexpcol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeIme1NImpexpcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeIme1NImpexpcol& rst);

	Sbecore::ubigint insertRec(WznmQImeIme1NImpexpcol* rec);
	void insertRst(ListWznmQImeIme1NImpexpcol& rst);
	void updateRec(WznmQImeIme1NImpexpcol* rec);
	void updateRst(ListWznmQImeIme1NImpexpcol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeIme1NImpexpcol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeIme1NImpexpcol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQImeIme1NImpexpcol: C++ wrapper for table TblWznmQImeIme1NImpexpcol (PgSQL database)
	*/
class PgTblWznmQImeIme1NImpexpcol : public TblWznmQImeIme1NImpexpcol, public Sbecore::PgTable {

public:
	PgTblWznmQImeIme1NImpexpcol();
	~PgTblWznmQImeIme1NImpexpcol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQImeIme1NImpexpcol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQImeIme1NImpexpcol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQImeIme1NImpexpcol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQImeIme1NImpexpcol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeIme1NImpexpcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeIme1NImpexpcol& rst);

	Sbecore::ubigint insertRec(WznmQImeIme1NImpexpcol* rec);
	void insertRst(ListWznmQImeIme1NImpexpcol& rst);
	void updateRec(WznmQImeIme1NImpexpcol* rec);
	void updateRst(ListWznmQImeIme1NImpexpcol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeIme1NImpexpcol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeIme1NImpexpcol& rst);
};
#endif

#endif

