/**
	* \file WznmQTcoList.h
	* Dbs and XML wrapper for table TblWznmQTcoList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTCOLIST_H
#define WZNMQTCOLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTcoList: record of TblWznmQTcoList
	*/
class WznmQTcoList {

public:
	WznmQTcoList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint tblRefWznmMTable = 0, const std::string stubTblRefWznmMTable = "", const Sbecore::uint fctIxVTbl = 0, const std::string srefFctIxVTbl = "", const std::string titFctIxVTbl = "", const Sbecore::uint ixVSubtype = 0, const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "", const Sbecore::uint ixVAxisfct = 0, const std::string srefIxVAxisfct = "", const std::string titIxVAxisfct = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Short;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint tblRefWznmMTable;
	std::string stubTblRefWznmMTable;
	Sbecore::uint fctIxVTbl;
	std::string srefFctIxVTbl;
	std::string titFctIxVTbl;
	Sbecore::uint ixVSubtype;
	std::string srefIxVSubtype;
	std::string titIxVSubtype;
	Sbecore::uint ixVAxisfct;
	std::string srefIxVAxisfct;
	std::string titIxVAxisfct;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTcoList: recordset of TblWznmQTcoList
	*/
class ListWznmQTcoList {

public:
	ListWznmQTcoList();
	ListWznmQTcoList(const ListWznmQTcoList& src);
	~ListWznmQTcoList();

	void clear();
	unsigned int size() const;
	void append(WznmQTcoList* rec);

	ListWznmQTcoList& operator=(const ListWznmQTcoList& src);

public:
	std::vector<WznmQTcoList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTcoList: C++ wrapper for table TblWznmQTcoList
	*/
class TblWznmQTcoList {

public:
	TblWznmQTcoList();
	virtual ~TblWznmQTcoList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTcoList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoList& rst);

	virtual Sbecore::ubigint insertRec(WznmQTcoList* rec);
	Sbecore::ubigint insertNewRec(WznmQTcoList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint tblRefWznmMTable = 0, const std::string stubTblRefWznmMTable = "", const Sbecore::uint fctIxVTbl = 0, const std::string srefFctIxVTbl = "", const std::string titFctIxVTbl = "", const Sbecore::uint ixVSubtype = 0, const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "", const Sbecore::uint ixVAxisfct = 0, const std::string srefIxVAxisfct = "", const std::string titIxVAxisfct = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTcoList& rst, WznmQTcoList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint tblRefWznmMTable = 0, const std::string stubTblRefWznmMTable = "", const Sbecore::uint fctIxVTbl = 0, const std::string srefFctIxVTbl = "", const std::string titFctIxVTbl = "", const Sbecore::uint ixVSubtype = 0, const std::string srefIxVSubtype = "", const std::string titIxVSubtype = "", const Sbecore::uint ixVAxisfct = 0, const std::string srefIxVAxisfct = "", const std::string titIxVAxisfct = "");
	virtual void insertRst(ListWznmQTcoList& rst);
	virtual void updateRec(WznmQTcoList* rec);
	virtual void updateRst(ListWznmQTcoList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTcoList: C++ wrapper for table TblWznmQTcoList (MySQL database)
	*/
class MyTblWznmQTcoList : public TblWznmQTcoList, public Sbecore::MyTable {

public:
	MyTblWznmQTcoList();
	~MyTblWznmQTcoList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoList& rst);

	Sbecore::ubigint insertRec(WznmQTcoList* rec);
	void insertRst(ListWznmQTcoList& rst);
	void updateRec(WznmQTcoList* rec);
	void updateRst(ListWznmQTcoList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTcoList: C++ wrapper for table TblWznmQTcoList (PgSQL database)
	*/
class PgTblWznmQTcoList : public TblWznmQTcoList, public Sbecore::PgTable {

public:
	PgTblWznmQTcoList();
	~PgTblWznmQTcoList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTcoList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTcoList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTcoList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTcoList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoList& rst);

	Sbecore::ubigint insertRec(WznmQTcoList* rec);
	void insertRst(ListWznmQTcoList& rst);
	void updateRec(WznmQTcoList* rec);
	void updateRst(ListWznmQTcoList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoList& rst);
};
#endif

#endif

