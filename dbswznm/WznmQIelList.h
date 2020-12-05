/**
	* \file WznmQIelList.h
	* Dbs and XML wrapper for table TblWznmQIelList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIELLIST_H
#define WZNMQIELLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQIelList: record of TblWznmQIelList
	*/
class WznmQIelList {

public:
	WznmQIelList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint imeRefWznmMImpexp = 0, const std::string stubImeRefWznmMImpexp = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "", const Sbecore::uint ixVConvtype = 0, const std::string srefIxVConvtype = "", const std::string titIxVConvtype = "");

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
	Sbecore::ubigint imeRefWznmMImpexp;
	std::string stubImeRefWznmMImpexp;
	Sbecore::ubigint refWznmMTablecol;
	std::string stubRefWznmMTablecol;
	Sbecore::uint ixVConvtype;
	std::string srefIxVConvtype;
	std::string titIxVConvtype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQIelList: recordset of TblWznmQIelList
	*/
class ListWznmQIelList {

public:
	ListWznmQIelList();
	ListWznmQIelList(const ListWznmQIelList& src);
	~ListWznmQIelList();

	void clear();
	unsigned int size() const;
	void append(WznmQIelList* rec);

	ListWznmQIelList& operator=(const ListWznmQIelList& src);

public:
	std::vector<WznmQIelList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQIelList: C++ wrapper for table TblWznmQIelList
	*/
class TblWznmQIelList {

public:
	TblWznmQIelList();
	virtual ~TblWznmQIelList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQIelList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIelList& rst);

	virtual Sbecore::ubigint insertRec(WznmQIelList* rec);
	Sbecore::ubigint insertNewRec(WznmQIelList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint imeRefWznmMImpexp = 0, const std::string stubImeRefWznmMImpexp = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "", const Sbecore::uint ixVConvtype = 0, const std::string srefIxVConvtype = "", const std::string titIxVConvtype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQIelList& rst, WznmQIelList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint imeRefWznmMImpexp = 0, const std::string stubImeRefWznmMImpexp = "", const Sbecore::ubigint refWznmMTablecol = 0, const std::string stubRefWznmMTablecol = "", const Sbecore::uint ixVConvtype = 0, const std::string srefIxVConvtype = "", const std::string titIxVConvtype = "");
	virtual void insertRst(ListWznmQIelList& rst);
	virtual void updateRec(WznmQIelList* rec);
	virtual void updateRst(ListWznmQIelList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQIelList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIelList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQIelList: C++ wrapper for table TblWznmQIelList (MySQL database)
	*/
class MyTblWznmQIelList : public TblWznmQIelList, public Sbecore::MyTable {

public:
	MyTblWznmQIelList();
	~MyTblWznmQIelList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIelList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIelList& rst);

	Sbecore::ubigint insertRec(WznmQIelList* rec);
	void insertRst(ListWznmQIelList& rst);
	void updateRec(WznmQIelList* rec);
	void updateRst(ListWznmQIelList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIelList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIelList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQIelList: C++ wrapper for table TblWznmQIelList (PgSQL database)
	*/
class PgTblWznmQIelList : public TblWznmQIelList, public Sbecore::PgTable {

public:
	PgTblWznmQIelList();
	~PgTblWznmQIelList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQIelList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQIelList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQIelList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQIelList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIelList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIelList& rst);

	Sbecore::ubigint insertRec(WznmQIelList* rec);
	void insertRst(ListWznmQIelList& rst);
	void updateRec(WznmQIelList* rec);
	void updateRst(ListWznmQIelList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIelList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIelList& rst);
};
#endif

#endif

