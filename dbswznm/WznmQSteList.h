/**
	* \file WznmQSteList.h
	* Dbs and XML wrapper for table TblWznmQSteList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSTELIST_H
#define WZNMQSTELIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSteList: record of TblWznmQSteList
	*/
class WznmQSteList {

public:
	WznmQSteList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint seqRefWznmMSequence = 0, const std::string stubSeqRefWznmMSequence = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint seqRefWznmMSequence;
	std::string stubSeqRefWznmMSequence;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSteList: recordset of TblWznmQSteList
	*/
class ListWznmQSteList {

public:
	ListWznmQSteList();
	ListWznmQSteList(const ListWznmQSteList& src);
	~ListWznmQSteList();

	void clear();
	unsigned int size() const;
	void append(WznmQSteList* rec);

	ListWznmQSteList& operator=(const ListWznmQSteList& src);

public:
	std::vector<WznmQSteList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSteList: C++ wrapper for table TblWznmQSteList
	*/
class TblWznmQSteList {

public:
	TblWznmQSteList();
	virtual ~TblWznmQSteList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSteList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteList& rst);

	virtual Sbecore::ubigint insertRec(WznmQSteList* rec);
	Sbecore::ubigint insertNewRec(WznmQSteList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint seqRefWznmMSequence = 0, const std::string stubSeqRefWznmMSequence = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSteList& rst, WznmQSteList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint seqRefWznmMSequence = 0, const std::string stubSeqRefWznmMSequence = "");
	virtual void insertRst(ListWznmQSteList& rst);
	virtual void updateRec(WznmQSteList* rec);
	virtual void updateRst(ListWznmQSteList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSteList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSteList: C++ wrapper for table TblWznmQSteList (MySQL database)
	*/
class MyTblWznmQSteList : public TblWznmQSteList, public Sbecore::MyTable {

public:
	MyTblWznmQSteList();
	~MyTblWznmQSteList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteList& rst);

	Sbecore::ubigint insertRec(WznmQSteList* rec);
	void insertRst(ListWznmQSteList& rst);
	void updateRec(WznmQSteList* rec);
	void updateRst(ListWznmQSteList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSteList: C++ wrapper for table TblWznmQSteList (PgSQL database)
	*/
class PgTblWznmQSteList : public TblWznmQSteList, public Sbecore::PgTable {

public:
	PgTblWznmQSteList();
	~PgTblWznmQSteList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSteList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSteList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSteList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSteList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteList& rst);

	Sbecore::ubigint insertRec(WznmQSteList* rec);
	void insertRst(ListWznmQSteList& rst);
	void updateRec(WznmQSteList* rec);
	void updateRst(ListWznmQSteList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteList& rst);
};
#endif

#endif

