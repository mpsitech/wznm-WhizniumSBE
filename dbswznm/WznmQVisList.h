/**
	* \file WznmQVisList.h
	* Dbs and XML wrapper for table TblWznmQVisList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISLIST_H
#define WZNMQVISLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVisList: record of TblWznmQVisList
	*/
class WznmQVisList {

public:
	WznmQVisList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	Sbecore::ubigint verRefWznmMVersion;
	std::string stubVerRefWznmMVersion;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVisList: recordset of TblWznmQVisList
	*/
class ListWznmQVisList {

public:
	ListWznmQVisList();
	ListWznmQVisList(const ListWznmQVisList& src);
	~ListWznmQVisList();

	void clear();
	unsigned int size() const;
	void append(WznmQVisList* rec);

	ListWznmQVisList& operator=(const ListWznmQVisList& src);

public:
	std::vector<WznmQVisList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVisList: C++ wrapper for table TblWznmQVisList
	*/
class TblWznmQVisList {

public:
	TblWznmQVisList();
	virtual ~TblWznmQVisList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVisList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisList& rst);

	virtual Sbecore::ubigint insertRec(WznmQVisList* rec);
	Sbecore::ubigint insertNewRec(WznmQVisList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVisList& rst, WznmQVisList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const Sbecore::ubigint verRefWznmMVersion = 0, const std::string stubVerRefWznmMVersion = "");
	virtual void insertRst(ListWznmQVisList& rst);
	virtual void updateRec(WznmQVisList* rec);
	virtual void updateRst(ListWznmQVisList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVisList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVisList: C++ wrapper for table TblWznmQVisList (MySQL database)
	*/
class MyTblWznmQVisList : public TblWznmQVisList, public Sbecore::MyTable {

public:
	MyTblWznmQVisList();
	~MyTblWznmQVisList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisList& rst);

	Sbecore::ubigint insertRec(WznmQVisList* rec);
	void insertRst(ListWznmQVisList& rst);
	void updateRec(WznmQVisList* rec);
	void updateRst(ListWznmQVisList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVisList: C++ wrapper for table TblWznmQVisList (PgSQL database)
	*/
class PgTblWznmQVisList : public TblWznmQVisList, public Sbecore::PgTable {

public:
	PgTblWznmQVisList();
	~PgTblWznmQVisList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVisList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVisList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVisList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVisList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisList& rst);

	Sbecore::ubigint insertRec(WznmQVisList* rec);
	void insertRst(ListWznmQVisList& rst);
	void updateRec(WznmQVisList* rec);
	void updateRst(ListWznmQVisList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisList& rst);
};
#endif

#endif
