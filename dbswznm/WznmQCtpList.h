/**
	* \file WznmQCtpList.h
	* Dbs and XML wrapper for table TblWznmQCtpList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCTPLIST_H
#define WZNMQCTPLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCtpList: record of TblWznmQCtpList
	*/
class WznmQCtpList {

public:
	WznmQCtpList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint ixWArtefact = 0, const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::uint ixWArtefact;
	std::string srefsIxWArtefact;
	std::string titsIxWArtefact;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCtpList: recordset of TblWznmQCtpList
	*/
class ListWznmQCtpList {

public:
	ListWznmQCtpList();
	ListWznmQCtpList(const ListWznmQCtpList& src);
	~ListWznmQCtpList();

	void clear();
	unsigned int size() const;
	void append(WznmQCtpList* rec);

	ListWznmQCtpList& operator=(const ListWznmQCtpList& src);

public:
	std::vector<WznmQCtpList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCtpList: C++ wrapper for table TblWznmQCtpList
	*/
class TblWznmQCtpList {

public:
	TblWznmQCtpList();
	virtual ~TblWznmQCtpList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCtpList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpList& rst);

	virtual Sbecore::ubigint insertRec(WznmQCtpList* rec);
	Sbecore::ubigint insertNewRec(WznmQCtpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint ixWArtefact = 0, const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCtpList& rst, WznmQCtpList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint ixWArtefact = 0, const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");
	virtual void insertRst(ListWznmQCtpList& rst);
	virtual void updateRec(WznmQCtpList* rec);
	virtual void updateRst(ListWznmQCtpList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCtpList: C++ wrapper for table TblWznmQCtpList (MySQL database)
	*/
class MyTblWznmQCtpList : public TblWznmQCtpList, public Sbecore::MyTable {

public:
	MyTblWznmQCtpList();
	~MyTblWznmQCtpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpList& rst);

	Sbecore::ubigint insertRec(WznmQCtpList* rec);
	void insertRst(ListWznmQCtpList& rst);
	void updateRec(WznmQCtpList* rec);
	void updateRst(ListWznmQCtpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCtpList: C++ wrapper for table TblWznmQCtpList (PgSQL database)
	*/
class PgTblWznmQCtpList : public TblWznmQCtpList, public Sbecore::PgTable {

public:
	PgTblWznmQCtpList();
	~PgTblWznmQCtpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCtpList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCtpList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCtpList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCtpList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpList& rst);

	Sbecore::ubigint insertRec(WznmQCtpList* rec);
	void insertRst(ListWznmQCtpList& rst);
	void updateRec(WznmQCtpList* rec);
	void updateRst(ListWznmQCtpList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpList& rst);
};
#endif

#endif

