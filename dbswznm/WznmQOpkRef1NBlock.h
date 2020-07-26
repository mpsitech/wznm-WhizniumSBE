/**
	* \file WznmQOpkRef1NBlock.h
	* Dbs and XML wrapper for table TblWznmQOpkRef1NBlock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQOPKREF1NBLOCK_H
#define WZNMQOPKREF1NBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkRef1NBlock: record of TblWznmQOpkRef1NBlock
	*/
class WznmQOpkRef1NBlock {

public:
	WznmQOpkRef1NBlock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQOpkRef1NBlock: recordset of TblWznmQOpkRef1NBlock
	*/
class ListWznmQOpkRef1NBlock {

public:
	ListWznmQOpkRef1NBlock();
	ListWznmQOpkRef1NBlock(const ListWznmQOpkRef1NBlock& src);
	~ListWznmQOpkRef1NBlock();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkRef1NBlock* rec);

	ListWznmQOpkRef1NBlock& operator=(const ListWznmQOpkRef1NBlock& src);

public:
	std::vector<WznmQOpkRef1NBlock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkRef1NBlock: C++ wrapper for table TblWznmQOpkRef1NBlock
	*/
class TblWznmQOpkRef1NBlock {

public:
	TblWznmQOpkRef1NBlock();
	virtual ~TblWznmQOpkRef1NBlock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkRef1NBlock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkRef1NBlock& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkRef1NBlock* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkRef1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkRef1NBlock& rst, WznmQOpkRef1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQOpkRef1NBlock& rst);
	virtual void updateRec(WznmQOpkRef1NBlock* rec);
	virtual void updateRst(ListWznmQOpkRef1NBlock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkRef1NBlock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkRef1NBlock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkRef1NBlock: C++ wrapper for table TblWznmQOpkRef1NBlock (MySQL database)
	*/
class MyTblWznmQOpkRef1NBlock : public TblWznmQOpkRef1NBlock, public Sbecore::MyTable {

public:
	MyTblWznmQOpkRef1NBlock();
	~MyTblWznmQOpkRef1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkRef1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkRef1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQOpkRef1NBlock* rec);
	void insertRst(ListWznmQOpkRef1NBlock& rst);
	void updateRec(WznmQOpkRef1NBlock* rec);
	void updateRst(ListWznmQOpkRef1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkRef1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkRef1NBlock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkRef1NBlock: C++ wrapper for table TblWznmQOpkRef1NBlock (PgSQL database)
	*/
class PgTblWznmQOpkRef1NBlock : public TblWznmQOpkRef1NBlock, public Sbecore::PgTable {

public:
	PgTblWznmQOpkRef1NBlock();
	~PgTblWznmQOpkRef1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkRef1NBlock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkRef1NBlock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkRef1NBlock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkRef1NBlock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkRef1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkRef1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQOpkRef1NBlock* rec);
	void insertRst(ListWznmQOpkRef1NBlock& rst);
	void updateRec(WznmQOpkRef1NBlock* rec);
	void updateRst(ListWznmQOpkRef1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkRef1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkRef1NBlock& rst);
};
#endif

#endif

