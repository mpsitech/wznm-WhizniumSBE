/**
	* \file WznmQSeqSeq1NState.h
	* Dbs and XML wrapper for table TblWznmQSeqSeq1NState (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSEQSEQ1NSTATE_H
#define WZNMQSEQSEQ1NSTATE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSeqSeq1NState: record of TblWznmQSeqSeq1NState
	*/
class WznmQSeqSeq1NState {

public:
	WznmQSeqSeq1NState(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint seqNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint seqNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSeqSeq1NState: recordset of TblWznmQSeqSeq1NState
	*/
class ListWznmQSeqSeq1NState {

public:
	ListWznmQSeqSeq1NState();
	ListWznmQSeqSeq1NState(const ListWznmQSeqSeq1NState& src);
	~ListWznmQSeqSeq1NState();

	void clear();
	unsigned int size() const;
	void append(WznmQSeqSeq1NState* rec);

	ListWznmQSeqSeq1NState& operator=(const ListWznmQSeqSeq1NState& src);

public:
	std::vector<WznmQSeqSeq1NState*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSeqSeq1NState: C++ wrapper for table TblWznmQSeqSeq1NState
	*/
class TblWznmQSeqSeq1NState {

public:
	TblWznmQSeqSeq1NState();
	virtual ~TblWznmQSeqSeq1NState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSeqSeq1NState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSeqSeq1NState& rst);

	virtual Sbecore::ubigint insertRec(WznmQSeqSeq1NState* rec);
	Sbecore::ubigint insertNewRec(WznmQSeqSeq1NState** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint seqNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQSeqSeq1NState& rst, WznmQSeqSeq1NState** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint seqNum = 0);
	virtual void insertRst(ListWznmQSeqSeq1NState& rst);
	virtual void updateRec(WznmQSeqSeq1NState* rec);
	virtual void updateRst(ListWznmQSeqSeq1NState& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSeqSeq1NState** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSeqSeq1NState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSeqSeq1NState: C++ wrapper for table TblWznmQSeqSeq1NState (MySQL database)
	*/
class MyTblWznmQSeqSeq1NState : public TblWznmQSeqSeq1NState, public Sbecore::MyTable {

public:
	MyTblWznmQSeqSeq1NState();
	~MyTblWznmQSeqSeq1NState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSeqSeq1NState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSeqSeq1NState& rst);

	Sbecore::ubigint insertRec(WznmQSeqSeq1NState* rec);
	void insertRst(ListWznmQSeqSeq1NState& rst);
	void updateRec(WznmQSeqSeq1NState* rec);
	void updateRst(ListWznmQSeqSeq1NState& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSeqSeq1NState** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSeqSeq1NState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSeqSeq1NState: C++ wrapper for table TblWznmQSeqSeq1NState (PgSQL database)
	*/
class PgTblWznmQSeqSeq1NState : public TblWznmQSeqSeq1NState, public Sbecore::PgTable {

public:
	PgTblWznmQSeqSeq1NState();
	~PgTblWznmQSeqSeq1NState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSeqSeq1NState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSeqSeq1NState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSeqSeq1NState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSeqSeq1NState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSeqSeq1NState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSeqSeq1NState& rst);

	Sbecore::ubigint insertRec(WznmQSeqSeq1NState* rec);
	void insertRst(ListWznmQSeqSeq1NState& rst);
	void updateRec(WznmQSeqSeq1NState* rec);
	void updateRst(ListWznmQSeqSeq1NState& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSeqSeq1NState** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSeqSeq1NState& rst);
};
#endif

#endif

