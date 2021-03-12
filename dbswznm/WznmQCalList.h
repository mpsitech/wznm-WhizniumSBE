/**
	* \file WznmQCalList.h
	* Dbs and XML wrapper for table TblWznmQCalList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCALLIST_H
#define WZNMQCALLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCalList: record of TblWznmQCalList
	*/
class WznmQCalList {

public:
	WznmQCalList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint invIxWznmWArgtype = 0, const std::string srefsInvIxWznmWArgtype = "", const std::string titsInvIxWznmWArgtype = "", const Sbecore::uint retIxWznmWArgtype = 0, const std::string srefsRetIxWznmWArgtype = "", const std::string titsRetIxWznmWArgtype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	Sbecore::uint invIxWznmWArgtype;
	std::string srefsInvIxWznmWArgtype;
	std::string titsInvIxWznmWArgtype;
	Sbecore::uint retIxWznmWArgtype;
	std::string srefsRetIxWznmWArgtype;
	std::string titsRetIxWznmWArgtype;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCalList: recordset of TblWznmQCalList
	*/
class ListWznmQCalList {

public:
	ListWznmQCalList();
	ListWznmQCalList(const ListWznmQCalList& src);
	~ListWznmQCalList();

	void clear();
	unsigned int size() const;
	void append(WznmQCalList* rec);

	ListWznmQCalList& operator=(const ListWznmQCalList& src);

public:
	std::vector<WznmQCalList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCalList: C++ wrapper for table TblWznmQCalList
	*/
class TblWznmQCalList {

public:
	TblWznmQCalList();
	virtual ~TblWznmQCalList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCalList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCalList& rst);

	virtual Sbecore::ubigint insertRec(WznmQCalList* rec);
	Sbecore::ubigint insertNewRec(WznmQCalList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint invIxWznmWArgtype = 0, const std::string srefsInvIxWznmWArgtype = "", const std::string titsInvIxWznmWArgtype = "", const Sbecore::uint retIxWznmWArgtype = 0, const std::string srefsRetIxWznmWArgtype = "", const std::string titsRetIxWznmWArgtype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCalList& rst, WznmQCalList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const Sbecore::uint invIxWznmWArgtype = 0, const std::string srefsInvIxWznmWArgtype = "", const std::string titsInvIxWznmWArgtype = "", const Sbecore::uint retIxWznmWArgtype = 0, const std::string srefsRetIxWznmWArgtype = "", const std::string titsRetIxWznmWArgtype = "");
	virtual void insertRst(ListWznmQCalList& rst);
	virtual void updateRec(WznmQCalList* rec);
	virtual void updateRst(ListWznmQCalList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCalList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCalList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCalList: C++ wrapper for table TblWznmQCalList (MySQL database)
	*/
class MyTblWznmQCalList : public TblWznmQCalList, public Sbecore::MyTable {

public:
	MyTblWznmQCalList();
	~MyTblWznmQCalList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCalList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCalList& rst);

	Sbecore::ubigint insertRec(WznmQCalList* rec);
	void insertRst(ListWznmQCalList& rst);
	void updateRec(WznmQCalList* rec);
	void updateRst(ListWznmQCalList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCalList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCalList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCalList: C++ wrapper for table TblWznmQCalList (PgSQL database)
	*/
class PgTblWznmQCalList : public TblWznmQCalList, public Sbecore::PgTable {

public:
	PgTblWznmQCalList();
	~PgTblWznmQCalList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCalList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCalList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCalList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCalList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCalList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCalList& rst);

	Sbecore::ubigint insertRec(WznmQCalList* rec);
	void insertRst(ListWznmQCalList& rst);
	void updateRec(WznmQCalList* rec);
	void updateRst(ListWznmQCalList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCalList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCalList& rst);
};
#endif

#endif
