/**
	* \file WznmQOpxRef1NBlock.h
	* Dbs and XML wrapper for table TblWznmQOpxRef1NBlock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQOPXREF1NBLOCK_H
#define WZNMQOPXREF1NBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpxRef1NBlock: record of TblWznmQOpxRef1NBlock
	*/
class WznmQOpxRef1NBlock {

public:
	WznmQOpxRef1NBlock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQOpxRef1NBlock: recordset of TblWznmQOpxRef1NBlock
	*/
class ListWznmQOpxRef1NBlock {

public:
	ListWznmQOpxRef1NBlock();
	ListWznmQOpxRef1NBlock(const ListWznmQOpxRef1NBlock& src);
	~ListWznmQOpxRef1NBlock();

	void clear();
	unsigned int size() const;
	void append(WznmQOpxRef1NBlock* rec);

	ListWznmQOpxRef1NBlock& operator=(const ListWznmQOpxRef1NBlock& src);

public:
	std::vector<WznmQOpxRef1NBlock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpxRef1NBlock: C++ wrapper for table TblWznmQOpxRef1NBlock
	*/
class TblWznmQOpxRef1NBlock {

public:
	TblWznmQOpxRef1NBlock();
	virtual ~TblWznmQOpxRef1NBlock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpxRef1NBlock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxRef1NBlock& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpxRef1NBlock* rec);
	Sbecore::ubigint insertNewRec(WznmQOpxRef1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpxRef1NBlock& rst, WznmQOpxRef1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQOpxRef1NBlock& rst);
	virtual void updateRec(WznmQOpxRef1NBlock* rec);
	virtual void updateRst(ListWznmQOpxRef1NBlock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxRef1NBlock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxRef1NBlock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpxRef1NBlock: C++ wrapper for table TblWznmQOpxRef1NBlock (MySQL database)
	*/
class MyTblWznmQOpxRef1NBlock : public TblWznmQOpxRef1NBlock, public Sbecore::MyTable {

public:
	MyTblWznmQOpxRef1NBlock();
	~MyTblWznmQOpxRef1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxRef1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxRef1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQOpxRef1NBlock* rec);
	void insertRst(ListWznmQOpxRef1NBlock& rst);
	void updateRec(WznmQOpxRef1NBlock* rec);
	void updateRst(ListWznmQOpxRef1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxRef1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxRef1NBlock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpxRef1NBlock: C++ wrapper for table TblWznmQOpxRef1NBlock (PgSQL database)
	*/
class PgTblWznmQOpxRef1NBlock : public TblWznmQOpxRef1NBlock, public Sbecore::PgTable {

public:
	PgTblWznmQOpxRef1NBlock();
	~PgTblWznmQOpxRef1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpxRef1NBlock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpxRef1NBlock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpxRef1NBlock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpxRef1NBlock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxRef1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxRef1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQOpxRef1NBlock* rec);
	void insertRst(ListWznmQOpxRef1NBlock& rst);
	void updateRec(WznmQOpxRef1NBlock* rec);
	void updateRst(ListWznmQOpxRef1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxRef1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxRef1NBlock& rst);
};
#endif

#endif

