/**
	* \file WznmQVisBoxctx.h
	* Dbs and XML wrapper for table TblWznmQVisBoxctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISBOXCTX_H
#define WZNMQVISBOXCTX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVisBoxctx: record of TblWznmQVisBoxctx
	*/
class WznmQVisBoxctx {

public:
	WznmQVisBoxctx(const Sbecore::ubigint qref = 0, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint tref = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const std::string stubUnvUref = "", const Sbecore::smallint x = 0, const Sbecore::smallint y = 0, const std::string jnumsSub = "", const std::string jnumsLink = "", const int w = 0, const int h = 0, const std::string Content1 = "", const std::string Content2 = "");

public:
	Sbecore::ubigint qref;
	bool qwr;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint tref;
	Sbecore::ubigint ref;
	Sbecore::uint unvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	std::string stubUnvUref;
	Sbecore::smallint x;
	Sbecore::smallint y;
	std::string jnumsSub;
	std::string jnumsLink;
	int w;
	int h;
	std::string Content1;
	std::string Content2;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVisBoxctx: recordset of TblWznmQVisBoxctx
	*/
class ListWznmQVisBoxctx {

public:
	ListWznmQVisBoxctx();
	ListWznmQVisBoxctx(const ListWznmQVisBoxctx& src);
	~ListWznmQVisBoxctx();

	void clear();
	unsigned int size() const;
	void append(WznmQVisBoxctx* rec);

	ListWznmQVisBoxctx& operator=(const ListWznmQVisBoxctx& src);

public:
	std::vector<WznmQVisBoxctx*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVisBoxctx: C++ wrapper for table TblWznmQVisBoxctx
	*/
class TblWznmQVisBoxctx {

public:
	TblWznmQVisBoxctx();
	virtual ~TblWznmQVisBoxctx();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVisBoxctx** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisBoxctx& rst);

	virtual Sbecore::ubigint insertRec(WznmQVisBoxctx* rec);
	Sbecore::ubigint insertNewRec(WznmQVisBoxctx** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint tref = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const std::string stubUnvUref = "", const Sbecore::smallint x = 0, const Sbecore::smallint y = 0, const std::string jnumsSub = "", const std::string jnumsLink = "", const int w = 0, const int h = 0, const std::string Content1 = "", const std::string Content2 = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVisBoxctx& rst, WznmQVisBoxctx** rec = NULL, const bool qwr = false, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint tref = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const std::string stubUnvUref = "", const Sbecore::smallint x = 0, const Sbecore::smallint y = 0, const std::string jnumsSub = "", const std::string jnumsLink = "", const int w = 0, const int h = 0, const std::string Content1 = "", const std::string Content2 = "");
	virtual void insertRst(ListWznmQVisBoxctx& rst);
	virtual void updateRec(WznmQVisBoxctx* rec);
	virtual void updateRst(ListWznmQVisBoxctx& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVisBoxctx** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisBoxctx& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVisBoxctx: C++ wrapper for table TblWznmQVisBoxctx (MySQL database)
	*/
class MyTblWznmQVisBoxctx : public TblWznmQVisBoxctx, public Sbecore::MyTable {

public:
	MyTblWznmQVisBoxctx();
	~MyTblWznmQVisBoxctx();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisBoxctx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisBoxctx& rst);

	Sbecore::ubigint insertRec(WznmQVisBoxctx* rec);
	void insertRst(ListWznmQVisBoxctx& rst);
	void updateRec(WznmQVisBoxctx* rec);
	void updateRst(ListWznmQVisBoxctx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisBoxctx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisBoxctx& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVisBoxctx: C++ wrapper for table TblWznmQVisBoxctx (PgSQL database)
	*/
class PgTblWznmQVisBoxctx : public TblWznmQVisBoxctx, public Sbecore::PgTable {

public:
	PgTblWznmQVisBoxctx();
	~PgTblWznmQVisBoxctx();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVisBoxctx** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVisBoxctx& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVisBoxctx** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVisBoxctx& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisBoxctx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisBoxctx& rst);

	Sbecore::ubigint insertRec(WznmQVisBoxctx* rec);
	void insertRst(ListWznmQVisBoxctx& rst);
	void updateRec(WznmQVisBoxctx* rec);
	void updateRst(ListWznmQVisBoxctx& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisBoxctx** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisBoxctx& rst);
};
#endif

#endif
