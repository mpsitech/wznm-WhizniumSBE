/**
	* \file WznmQVer1NBlock.h
	* Dbs and XML wrapper for table TblWznmQVer1NBlock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NBLOCK_H
#define WZNMQVER1NBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NBlock: record of TblWznmQVer1NBlock
	*/
class WznmQVer1NBlock {

public:
	WznmQVer1NBlock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NBlock: recordset of TblWznmQVer1NBlock
	*/
class ListWznmQVer1NBlock {

public:
	ListWznmQVer1NBlock();
	ListWznmQVer1NBlock(const ListWznmQVer1NBlock& src);
	~ListWznmQVer1NBlock();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NBlock* rec);

	ListWznmQVer1NBlock& operator=(const ListWznmQVer1NBlock& src);

public:
	std::vector<WznmQVer1NBlock*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NBlock: C++ wrapper for table TblWznmQVer1NBlock
	*/
class TblWznmQVer1NBlock {

public:
	TblWznmQVer1NBlock();
	virtual ~TblWznmQVer1NBlock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NBlock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NBlock& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NBlock* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NBlock& rst, WznmQVer1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NBlock& rst);
	virtual void updateRec(WznmQVer1NBlock* rec);
	virtual void updateRst(ListWznmQVer1NBlock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NBlock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NBlock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NBlock: C++ wrapper for table TblWznmQVer1NBlock (MySQL database)
	*/
class MyTblWznmQVer1NBlock : public TblWznmQVer1NBlock, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NBlock();
	~MyTblWznmQVer1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQVer1NBlock* rec);
	void insertRst(ListWznmQVer1NBlock& rst);
	void updateRec(WznmQVer1NBlock* rec);
	void updateRst(ListWznmQVer1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NBlock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NBlock: C++ wrapper for table TblWznmQVer1NBlock (PgSQL database)
	*/
class PgTblWznmQVer1NBlock : public TblWznmQVer1NBlock, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NBlock();
	~PgTblWznmQVer1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NBlock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NBlock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NBlock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NBlock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQVer1NBlock* rec);
	void insertRst(ListWznmQVer1NBlock& rst);
	void updateRec(WznmQVer1NBlock* rec);
	void updateRst(ListWznmQVer1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NBlock& rst);
};
#endif

#endif
