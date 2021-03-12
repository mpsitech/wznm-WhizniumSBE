/**
	* \file WznmQVecFct1NTablecol.h
	* Dbs and XML wrapper for table TblWznmQVecFct1NTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECFCT1NTABLECOL_H
#define WZNMQVECFCT1NTABLECOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecFct1NTablecol: record of TblWznmQVecFct1NTablecol
	*/
class WznmQVecFct1NTablecol {

public:
	WznmQVecFct1NTablecol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVecFct1NTablecol: recordset of TblWznmQVecFct1NTablecol
	*/
class ListWznmQVecFct1NTablecol {

public:
	ListWznmQVecFct1NTablecol();
	ListWznmQVecFct1NTablecol(const ListWznmQVecFct1NTablecol& src);
	~ListWznmQVecFct1NTablecol();

	void clear();
	unsigned int size() const;
	void append(WznmQVecFct1NTablecol* rec);

	ListWznmQVecFct1NTablecol& operator=(const ListWznmQVecFct1NTablecol& src);

public:
	std::vector<WznmQVecFct1NTablecol*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecFct1NTablecol: C++ wrapper for table TblWznmQVecFct1NTablecol
	*/
class TblWznmQVecFct1NTablecol {

public:
	TblWznmQVecFct1NTablecol();
	virtual ~TblWznmQVecFct1NTablecol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecFct1NTablecol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecFct1NTablecol& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecFct1NTablecol* rec);
	Sbecore::ubigint insertNewRec(WznmQVecFct1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecFct1NTablecol& rst, WznmQVecFct1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVecFct1NTablecol& rst);
	virtual void updateRec(WznmQVecFct1NTablecol* rec);
	virtual void updateRst(ListWznmQVecFct1NTablecol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecFct1NTablecol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecFct1NTablecol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecFct1NTablecol: C++ wrapper for table TblWznmQVecFct1NTablecol (MySQL database)
	*/
class MyTblWznmQVecFct1NTablecol : public TblWznmQVecFct1NTablecol, public Sbecore::MyTable {

public:
	MyTblWznmQVecFct1NTablecol();
	~MyTblWznmQVecFct1NTablecol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecFct1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecFct1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQVecFct1NTablecol* rec);
	void insertRst(ListWznmQVecFct1NTablecol& rst);
	void updateRec(WznmQVecFct1NTablecol* rec);
	void updateRst(ListWznmQVecFct1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecFct1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecFct1NTablecol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecFct1NTablecol: C++ wrapper for table TblWznmQVecFct1NTablecol (PgSQL database)
	*/
class PgTblWznmQVecFct1NTablecol : public TblWznmQVecFct1NTablecol, public Sbecore::PgTable {

public:
	PgTblWznmQVecFct1NTablecol();
	~PgTblWznmQVecFct1NTablecol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecFct1NTablecol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecFct1NTablecol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecFct1NTablecol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecFct1NTablecol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecFct1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecFct1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQVecFct1NTablecol* rec);
	void insertRst(ListWznmQVecFct1NTablecol& rst);
	void updateRec(WznmQVecFct1NTablecol* rec);
	void updateRst(ListWznmQVecFct1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecFct1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecFct1NTablecol& rst);
};
#endif

#endif
