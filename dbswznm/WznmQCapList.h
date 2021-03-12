/**
	* \file WznmQCapList.h
	* Dbs and XML wrapper for table TblWznmQCapList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCAPLIST_H
#define WZNMQCAPLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCapList: record of TblWznmQCapList
	*/
class WznmQCapList {

public:
	WznmQCapList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint tplRefWznmMCapability = 0, const std::string stubTplRefWznmMCapability = "", const Sbecore::uint ixWArtefact = 0, const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint refWznmMVersion;
	std::string stubRefWznmMVersion;
	Sbecore::ubigint tplRefWznmMCapability;
	std::string stubTplRefWznmMCapability;
	Sbecore::uint ixWArtefact;
	std::string srefsIxWArtefact;
	std::string titsIxWArtefact;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCapList: recordset of TblWznmQCapList
	*/
class ListWznmQCapList {

public:
	ListWznmQCapList();
	ListWznmQCapList(const ListWznmQCapList& src);
	~ListWznmQCapList();

	void clear();
	unsigned int size() const;
	void append(WznmQCapList* rec);

	ListWznmQCapList& operator=(const ListWznmQCapList& src);

public:
	std::vector<WznmQCapList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCapList: C++ wrapper for table TblWznmQCapList
	*/
class TblWznmQCapList {

public:
	TblWznmQCapList();
	virtual ~TblWznmQCapList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCapList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCapList& rst);

	virtual Sbecore::ubigint insertRec(WznmQCapList* rec);
	Sbecore::ubigint insertNewRec(WznmQCapList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint tplRefWznmMCapability = 0, const std::string stubTplRefWznmMCapability = "", const Sbecore::uint ixWArtefact = 0, const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCapList& rst, WznmQCapList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint refWznmMVersion = 0, const std::string stubRefWznmMVersion = "", const Sbecore::ubigint tplRefWznmMCapability = 0, const std::string stubTplRefWznmMCapability = "", const Sbecore::uint ixWArtefact = 0, const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");
	virtual void insertRst(ListWznmQCapList& rst);
	virtual void updateRec(WznmQCapList* rec);
	virtual void updateRst(ListWznmQCapList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCapList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCapList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCapList: C++ wrapper for table TblWznmQCapList (MySQL database)
	*/
class MyTblWznmQCapList : public TblWznmQCapList, public Sbecore::MyTable {

public:
	MyTblWznmQCapList();
	~MyTblWznmQCapList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCapList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCapList& rst);

	Sbecore::ubigint insertRec(WznmQCapList* rec);
	void insertRst(ListWznmQCapList& rst);
	void updateRec(WznmQCapList* rec);
	void updateRst(ListWznmQCapList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCapList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCapList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCapList: C++ wrapper for table TblWznmQCapList (PgSQL database)
	*/
class PgTblWznmQCapList : public TblWznmQCapList, public Sbecore::PgTable {

public:
	PgTblWznmQCapList();
	~PgTblWznmQCapList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCapList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCapList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCapList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCapList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCapList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCapList& rst);

	Sbecore::ubigint insertRec(WznmQCapList* rec);
	void insertRst(ListWznmQCapList& rst);
	void updateRec(WznmQCapList* rec);
	void updateRst(ListWznmQCapList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCapList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCapList& rst);
};
#endif

#endif
