/**
	* \file WznmQVitList.h
	* Dbs and XML wrapper for table TblWznmQVitList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVITLIST_H
#define WZNMQVITLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVitList: record of TblWznmQVitList
	*/
class WznmQVitList {

public:
	WznmQVitList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint vecRefWznmMVector = 0, const std::string stubVecRefWznmMVector = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint vecRefWznmMVector;
	std::string stubVecRefWznmMVector;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVitList: recordset of TblWznmQVitList
	*/
class ListWznmQVitList {

public:
	ListWznmQVitList();
	ListWznmQVitList(const ListWznmQVitList& src);
	~ListWznmQVitList();

	void clear();
	unsigned int size() const;
	void append(WznmQVitList* rec);

	ListWznmQVitList& operator=(const ListWznmQVitList& src);

public:
	std::vector<WznmQVitList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVitList: C++ wrapper for table TblWznmQVitList
	*/
class TblWznmQVitList {

public:
	TblWznmQVitList();
	virtual ~TblWznmQVitList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVitList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVitList& rst);

	virtual Sbecore::ubigint insertRec(WznmQVitList* rec);
	Sbecore::ubigint insertNewRec(WznmQVitList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint vecRefWznmMVector = 0, const std::string stubVecRefWznmMVector = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVitList& rst, WznmQVitList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint vecRefWznmMVector = 0, const std::string stubVecRefWznmMVector = "");
	virtual void insertRst(ListWznmQVitList& rst);
	virtual void updateRec(WznmQVitList* rec);
	virtual void updateRst(ListWznmQVitList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVitList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVitList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVitList: C++ wrapper for table TblWznmQVitList (MySQL database)
	*/
class MyTblWznmQVitList : public TblWznmQVitList, public Sbecore::MyTable {

public:
	MyTblWznmQVitList();
	~MyTblWznmQVitList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVitList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVitList& rst);

	Sbecore::ubigint insertRec(WznmQVitList* rec);
	void insertRst(ListWznmQVitList& rst);
	void updateRec(WznmQVitList* rec);
	void updateRst(ListWznmQVitList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVitList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVitList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVitList: C++ wrapper for table TblWznmQVitList (PgSQL database)
	*/
class PgTblWznmQVitList : public TblWznmQVitList, public Sbecore::PgTable {

public:
	PgTblWznmQVitList();
	~PgTblWznmQVitList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVitList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVitList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVitList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVitList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVitList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVitList& rst);

	Sbecore::ubigint insertRec(WznmQVitList* rec);
	void insertRst(ListWznmQVitList& rst);
	void updateRec(WznmQVitList* rec);
	void updateRst(ListWznmQVitList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVitList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVitList& rst);
};
#endif

#endif

