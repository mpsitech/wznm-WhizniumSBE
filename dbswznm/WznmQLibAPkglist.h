/**
	* \file WznmQLibAPkglist.h
	* Dbs and XML wrapper for table TblWznmQLibAPkglist (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLIBAPKGLIST_H
#define WZNMQLIBAPKGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLibAPkglist: record of TblWznmQLibAPkglist
	*/
class WznmQLibAPkglist {

public:
	WznmQLibAPkglist(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint x1RefWznmMMachine = 0, const std::string stubX1RefWznmMMachine = "", const std::string Pkglist = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint x1RefWznmMMachine;
	std::string stubX1RefWznmMMachine;
	std::string Pkglist;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQLibAPkglist: recordset of TblWznmQLibAPkglist
	*/
class ListWznmQLibAPkglist {

public:
	ListWznmQLibAPkglist();
	ListWznmQLibAPkglist(const ListWznmQLibAPkglist& src);
	~ListWznmQLibAPkglist();

	void clear();
	unsigned int size() const;
	void append(WznmQLibAPkglist* rec);

	ListWznmQLibAPkglist& operator=(const ListWznmQLibAPkglist& src);

public:
	std::vector<WznmQLibAPkglist*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLibAPkglist: C++ wrapper for table TblWznmQLibAPkglist
	*/
class TblWznmQLibAPkglist {

public:
	TblWznmQLibAPkglist();
	virtual ~TblWznmQLibAPkglist();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLibAPkglist** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibAPkglist& rst);

	virtual Sbecore::ubigint insertRec(WznmQLibAPkglist* rec);
	Sbecore::ubigint insertNewRec(WznmQLibAPkglist** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint x1RefWznmMMachine = 0, const std::string stubX1RefWznmMMachine = "", const std::string Pkglist = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQLibAPkglist& rst, WznmQLibAPkglist** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint x1RefWznmMMachine = 0, const std::string stubX1RefWznmMMachine = "", const std::string Pkglist = "");
	virtual void insertRst(ListWznmQLibAPkglist& rst);
	virtual void updateRec(WznmQLibAPkglist* rec);
	virtual void updateRst(ListWznmQLibAPkglist& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLibAPkglist** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibAPkglist& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLibAPkglist: C++ wrapper for table TblWznmQLibAPkglist (MySQL database)
	*/
class MyTblWznmQLibAPkglist : public TblWznmQLibAPkglist, public Sbecore::MyTable {

public:
	MyTblWznmQLibAPkglist();
	~MyTblWznmQLibAPkglist();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibAPkglist** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibAPkglist& rst);

	Sbecore::ubigint insertRec(WznmQLibAPkglist* rec);
	void insertRst(ListWznmQLibAPkglist& rst);
	void updateRec(WznmQLibAPkglist* rec);
	void updateRst(ListWznmQLibAPkglist& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibAPkglist** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibAPkglist& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLibAPkglist: C++ wrapper for table TblWznmQLibAPkglist (PgSQL database)
	*/
class PgTblWznmQLibAPkglist : public TblWznmQLibAPkglist, public Sbecore::PgTable {

public:
	PgTblWznmQLibAPkglist();
	~PgTblWznmQLibAPkglist();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLibAPkglist** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLibAPkglist& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLibAPkglist** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLibAPkglist& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibAPkglist** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibAPkglist& rst);

	Sbecore::ubigint insertRec(WznmQLibAPkglist* rec);
	void insertRst(ListWznmQLibAPkglist& rst);
	void updateRec(WznmQLibAPkglist* rec);
	void updateRst(ListWznmQLibAPkglist& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibAPkglist** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibAPkglist& rst);
};
#endif

#endif
