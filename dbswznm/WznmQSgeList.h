/**
	* \file WznmQSgeList.h
	* Dbs and XML wrapper for table TblWznmQSgeList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSGELIST_H
#define WZNMQSGELIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSgeList: record of TblWznmQSgeList
	*/
class WznmQSgeList {

public:
	WznmQSgeList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint jobRefWznmMJob = 0, const std::string stubJobRefWznmMJob = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint jobRefWznmMJob;
	std::string stubJobRefWznmMJob;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSgeList: recordset of TblWznmQSgeList
	*/
class ListWznmQSgeList {

public:
	ListWznmQSgeList();
	ListWznmQSgeList(const ListWznmQSgeList& src);
	~ListWznmQSgeList();

	void clear();
	unsigned int size() const;
	void append(WznmQSgeList* rec);

	ListWznmQSgeList& operator=(const ListWznmQSgeList& src);

public:
	std::vector<WznmQSgeList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSgeList: C++ wrapper for table TblWznmQSgeList
	*/
class TblWznmQSgeList {

public:
	TblWznmQSgeList();
	virtual ~TblWznmQSgeList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSgeList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSgeList& rst);

	virtual Sbecore::ubigint insertRec(WznmQSgeList* rec);
	Sbecore::ubigint insertNewRec(WznmQSgeList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint jobRefWznmMJob = 0, const std::string stubJobRefWznmMJob = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSgeList& rst, WznmQSgeList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint jobRefWznmMJob = 0, const std::string stubJobRefWznmMJob = "");
	virtual void insertRst(ListWznmQSgeList& rst);
	virtual void updateRec(WznmQSgeList* rec);
	virtual void updateRst(ListWznmQSgeList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSgeList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSgeList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSgeList: C++ wrapper for table TblWznmQSgeList (MySQL database)
	*/
class MyTblWznmQSgeList : public TblWznmQSgeList, public Sbecore::MyTable {

public:
	MyTblWznmQSgeList();
	~MyTblWznmQSgeList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSgeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSgeList& rst);

	Sbecore::ubigint insertRec(WznmQSgeList* rec);
	void insertRst(ListWznmQSgeList& rst);
	void updateRec(WznmQSgeList* rec);
	void updateRst(ListWznmQSgeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSgeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSgeList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSgeList: C++ wrapper for table TblWznmQSgeList (PgSQL database)
	*/
class PgTblWznmQSgeList : public TblWznmQSgeList, public Sbecore::PgTable {

public:
	PgTblWznmQSgeList();
	~PgTblWznmQSgeList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSgeList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSgeList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSgeList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSgeList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSgeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSgeList& rst);

	Sbecore::ubigint insertRec(WznmQSgeList* rec);
	void insertRst(ListWznmQSgeList& rst);
	void updateRec(WznmQSgeList* rec);
	void updateRst(ListWznmQSgeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSgeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSgeList& rst);
};
#endif

#endif

