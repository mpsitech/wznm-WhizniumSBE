/**
	* \file WznmQVisRowctx.h
	* Dbs and XML wrapper for table TblWznmQVisRowctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISROWCTX_H
#define WZNMQVISROWCTX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVisRowctx: record of TblWznmQVisRowctx
	*/
class WznmQVisRowctx {

public:
	WznmQVisRowctx(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const int jnumBox = 0, const std::string Content1 = "", const std::string Content2 = "", const std::string Content3 = "");

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	int jnumBox;
	std::string Content1;
	std::string Content2;
	std::string Content3;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVisRowctx: recordset of TblWznmQVisRowctx
	*/
class ListWznmQVisRowctx {

public:
	ListWznmQVisRowctx();
	ListWznmQVisRowctx(const ListWznmQVisRowctx& src);
	~ListWznmQVisRowctx();

	void clear();
	unsigned int size() const;
	void append(WznmQVisRowctx* rec);

	ListWznmQVisRowctx& operator=(const ListWznmQVisRowctx& src);

public:
	std::vector<WznmQVisRowctx*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVisRowctx: C++ wrapper for table TblWznmQVisRowctx
	*/
class TblWznmQVisRowctx {

public:
	TblWznmQVisRowctx();
	virtual ~TblWznmQVisRowctx();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVisRowctx** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisRowctx& rst);

	virtual Sbecore::ubigint insertRec(WznmQVisRowctx* rec);
	Sbecore::ubigint insertNewRec(WznmQVisRowctx** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const int jnumBox = 0, const std::string Content1 = "", const std::string Content2 = "", const std::string Content3 = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVisRowctx& rst, WznmQVisRowctx** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const int jnumBox = 0, const std::string Content1 = "", const std::string Content2 = "", const std::string Content3 = "");
	virtual void insertRst(ListWznmQVisRowctx& rst);
	virtual void updateRec(WznmQVisRowctx* rec);
	virtual void updateRst(ListWznmQVisRowctx& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVisRowctx** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisRowctx& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVisRowctx: C++ wrapper for table TblWznmQVisRowctx (MySQL database)
	*/
class MyTblWznmQVisRowctx : public TblWznmQVisRowctx, public Sbecore::MyTable {

public:
	MyTblWznmQVisRowctx();
	~MyTblWznmQVisRowctx();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisRowctx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisRowctx& rst);

	Sbecore::ubigint insertRec(WznmQVisRowctx* rec);
	void insertRst(ListWznmQVisRowctx& rst);
	void updateRec(WznmQVisRowctx* rec);
	void updateRst(ListWznmQVisRowctx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisRowctx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisRowctx& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVisRowctx: C++ wrapper for table TblWznmQVisRowctx (PgSQL database)
	*/
class PgTblWznmQVisRowctx : public TblWznmQVisRowctx, public Sbecore::PgTable {

public:
	PgTblWznmQVisRowctx();
	~PgTblWznmQVisRowctx();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVisRowctx** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVisRowctx& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVisRowctx** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVisRowctx& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisRowctx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisRowctx& rst);

	Sbecore::ubigint insertRec(WznmQVisRowctx* rec);
	void insertRst(ListWznmQVisRowctx& rst);
	void updateRec(WznmQVisRowctx* rec);
	void updateRst(ListWznmQVisRowctx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisRowctx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisRowctx& rst);
};
#endif

#endif
