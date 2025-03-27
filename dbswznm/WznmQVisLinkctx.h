/**
	* \file WznmQVisLinkctx.h
	* Dbs and XML wrapper for table TblWznmQVisLinkctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISLINKCTX_H
#define WZNMQVISLINKCTX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVisLinkctx: record of TblWznmQVisLinkctx
	*/
class WznmQVisLinkctx {

public:
	WznmQVisLinkctx(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint tref = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint orgRefWznmMBox = 0, const Sbecore::ubigint dstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0, const int jnumBoxOrg = 0, const int jnumBoxDst = 0, const std::string Title = "", const std::string Content1 = "", const std::string Content2 = "");

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint tref;
	Sbecore::ubigint ref;
	Sbecore::ubigint orgRefWznmMBox;
	Sbecore::ubigint dstRefWznmMBox;
	Sbecore::utinyint orgClk;
	Sbecore::utinyint dstClk;
	Sbecore::utinyint Weight;
	int jnumBoxOrg;
	int jnumBoxDst;
	std::string Title;
	std::string Content1;
	std::string Content2;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVisLinkctx: recordset of TblWznmQVisLinkctx
	*/
class ListWznmQVisLinkctx {

public:
	ListWznmQVisLinkctx();
	ListWznmQVisLinkctx(const ListWznmQVisLinkctx& src);
	~ListWznmQVisLinkctx();

	void clear();
	unsigned int size() const;
	void append(WznmQVisLinkctx* rec);

	ListWznmQVisLinkctx& operator=(const ListWznmQVisLinkctx& src);

public:
	std::vector<WznmQVisLinkctx*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVisLinkctx: C++ wrapper for table TblWznmQVisLinkctx
	*/
class TblWznmQVisLinkctx {

public:
	TblWznmQVisLinkctx();
	virtual ~TblWznmQVisLinkctx();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVisLinkctx** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisLinkctx& rst);

	virtual Sbecore::ubigint insertRec(WznmQVisLinkctx* rec);
	Sbecore::ubigint insertNewRec(WznmQVisLinkctx** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint tref = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint orgRefWznmMBox = 0, const Sbecore::ubigint dstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0, const int jnumBoxOrg = 0, const int jnumBoxDst = 0, const std::string Title = "", const std::string Content1 = "", const std::string Content2 = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVisLinkctx& rst, WznmQVisLinkctx** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint tref = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint orgRefWznmMBox = 0, const Sbecore::ubigint dstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0, const int jnumBoxOrg = 0, const int jnumBoxDst = 0, const std::string Title = "", const std::string Content1 = "", const std::string Content2 = "");
	virtual void insertRst(ListWznmQVisLinkctx& rst);
	virtual void updateRec(WznmQVisLinkctx* rec);
	virtual void updateRst(ListWznmQVisLinkctx& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVisLinkctx** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisLinkctx& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVisLinkctx: C++ wrapper for table TblWznmQVisLinkctx (MySQL database)
	*/
class MyTblWznmQVisLinkctx : public TblWznmQVisLinkctx, public Sbecore::MyTable {

public:
	MyTblWznmQVisLinkctx();
	~MyTblWznmQVisLinkctx();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisLinkctx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisLinkctx& rst);

	Sbecore::ubigint insertRec(WznmQVisLinkctx* rec);
	void insertRst(ListWznmQVisLinkctx& rst);
	void updateRec(WznmQVisLinkctx* rec);
	void updateRst(ListWznmQVisLinkctx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisLinkctx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisLinkctx& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVisLinkctx: C++ wrapper for table TblWznmQVisLinkctx (PgSQL database)
	*/
class PgTblWznmQVisLinkctx : public TblWznmQVisLinkctx, public Sbecore::PgTable {

public:
	PgTblWznmQVisLinkctx();
	~PgTblWznmQVisLinkctx();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVisLinkctx** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVisLinkctx& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVisLinkctx** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVisLinkctx& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisLinkctx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisLinkctx& rst);

	Sbecore::ubigint insertRec(WznmQVisLinkctx* rec);
	void insertRst(ListWznmQVisLinkctx& rst);
	void updateRec(WznmQVisLinkctx* rec);
	void updateRst(ListWznmQVisLinkctx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisLinkctx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisLinkctx& rst);
};
#endif

#endif
