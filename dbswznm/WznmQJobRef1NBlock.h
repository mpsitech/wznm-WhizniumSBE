/**
	* \file WznmQJobRef1NBlock.h
	* Dbs and XML wrapper for table TblWznmQJobRef1NBlock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQJOBREF1NBLOCK_H
#define WZNMQJOBREF1NBLOCK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobRef1NBlock: record of TblWznmQJobRef1NBlock
	*/
class WznmQJobRef1NBlock {

public:
	WznmQJobRef1NBlock(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQJobRef1NBlock: recordset of TblWznmQJobRef1NBlock
	*/
class ListWznmQJobRef1NBlock {

public:
	ListWznmQJobRef1NBlock();
	ListWznmQJobRef1NBlock(const ListWznmQJobRef1NBlock& src);
	~ListWznmQJobRef1NBlock();

	void clear();
	unsigned int size() const;
	void append(WznmQJobRef1NBlock* rec);

	ListWznmQJobRef1NBlock& operator=(const ListWznmQJobRef1NBlock& src);

public:
	std::vector<WznmQJobRef1NBlock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobRef1NBlock: C++ wrapper for table TblWznmQJobRef1NBlock
	*/
class TblWznmQJobRef1NBlock {

public:
	TblWznmQJobRef1NBlock();
	virtual ~TblWznmQJobRef1NBlock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobRef1NBlock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobRef1NBlock& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobRef1NBlock* rec);
	Sbecore::ubigint insertNewRec(WznmQJobRef1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobRef1NBlock& rst, WznmQJobRef1NBlock** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQJobRef1NBlock& rst);
	virtual void updateRec(WznmQJobRef1NBlock* rec);
	virtual void updateRst(ListWznmQJobRef1NBlock& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobRef1NBlock** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobRef1NBlock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobRef1NBlock: C++ wrapper for table TblWznmQJobRef1NBlock (MySQL database)
	*/
class MyTblWznmQJobRef1NBlock : public TblWznmQJobRef1NBlock, public Sbecore::MyTable {

public:
	MyTblWznmQJobRef1NBlock();
	~MyTblWznmQJobRef1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobRef1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobRef1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQJobRef1NBlock* rec);
	void insertRst(ListWznmQJobRef1NBlock& rst);
	void updateRec(WznmQJobRef1NBlock* rec);
	void updateRst(ListWznmQJobRef1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobRef1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobRef1NBlock& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobRef1NBlock: C++ wrapper for table TblWznmQJobRef1NBlock (PgSQL database)
	*/
class PgTblWznmQJobRef1NBlock : public TblWznmQJobRef1NBlock, public Sbecore::PgTable {

public:
	PgTblWznmQJobRef1NBlock();
	~PgTblWznmQJobRef1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobRef1NBlock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobRef1NBlock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobRef1NBlock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobRef1NBlock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobRef1NBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobRef1NBlock& rst);

	Sbecore::ubigint insertRec(WznmQJobRef1NBlock* rec);
	void insertRst(ListWznmQJobRef1NBlock& rst);
	void updateRec(WznmQJobRef1NBlock* rec);
	void updateRst(ListWznmQJobRef1NBlock& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobRef1NBlock** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobRef1NBlock& rst);
};
#endif

#endif

