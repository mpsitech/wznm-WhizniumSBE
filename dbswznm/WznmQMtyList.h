/**
	* \file WznmQMtyList.h
	* Dbs and XML wrapper for table TblWznmQMtyList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQMTYLIST_H
#define WZNMQMTYLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMtyList: record of TblWznmQMtyList
	*/
class WznmQMtyList {

public:
	WznmQMtyList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVArch = 0, const std::string srefIxVArch = "", const std::string titIxVArch = "", const std::string srefKOs = "", const std::string titSrefKOs = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVArch;
	std::string srefIxVArch;
	std::string titIxVArch;
	std::string srefKOs;
	std::string titSrefKOs;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMtyList: recordset of TblWznmQMtyList
	*/
class ListWznmQMtyList {

public:
	ListWznmQMtyList();
	ListWznmQMtyList(const ListWznmQMtyList& src);
	~ListWznmQMtyList();

	void clear();
	unsigned int size() const;
	void append(WznmQMtyList* rec);

	ListWznmQMtyList& operator=(const ListWznmQMtyList& src);

public:
	std::vector<WznmQMtyList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMtyList: C++ wrapper for table TblWznmQMtyList
	*/
class TblWznmQMtyList {

public:
	TblWznmQMtyList();
	virtual ~TblWznmQMtyList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMtyList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtyList& rst);

	virtual Sbecore::ubigint insertRec(WznmQMtyList* rec);
	Sbecore::ubigint insertNewRec(WznmQMtyList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVArch = 0, const std::string srefIxVArch = "", const std::string titIxVArch = "", const std::string srefKOs = "", const std::string titSrefKOs = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMtyList& rst, WznmQMtyList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVArch = 0, const std::string srefIxVArch = "", const std::string titIxVArch = "", const std::string srefKOs = "", const std::string titSrefKOs = "");
	virtual void insertRst(ListWznmQMtyList& rst);
	virtual void updateRec(WznmQMtyList* rec);
	virtual void updateRst(ListWznmQMtyList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMtyList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtyList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMtyList: C++ wrapper for table TblWznmQMtyList (MySQL database)
	*/
class MyTblWznmQMtyList : public TblWznmQMtyList, public Sbecore::MyTable {

public:
	MyTblWznmQMtyList();
	~MyTblWznmQMtyList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtyList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtyList& rst);

	Sbecore::ubigint insertRec(WznmQMtyList* rec);
	void insertRst(ListWznmQMtyList& rst);
	void updateRec(WznmQMtyList* rec);
	void updateRst(ListWznmQMtyList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtyList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtyList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMtyList: C++ wrapper for table TblWznmQMtyList (PgSQL database)
	*/
class PgTblWznmQMtyList : public TblWznmQMtyList, public Sbecore::PgTable {

public:
	PgTblWznmQMtyList();
	~PgTblWznmQMtyList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMtyList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMtyList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMtyList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMtyList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtyList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtyList& rst);

	Sbecore::ubigint insertRec(WznmQMtyList* rec);
	void insertRst(ListWznmQMtyList& rst);
	void updateRec(WznmQMtyList* rec);
	void updateRst(ListWznmQMtyList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtyList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtyList& rst);
};
#endif

#endif

