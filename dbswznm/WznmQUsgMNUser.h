/**
	* \file WznmQUsgMNUser.h
	* Dbs and XML wrapper for table TblWznmQUsgMNUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSGMNUSER_H
#define WZNMQUSGMNUSER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsgMNUser: record of TblWznmQUsgMNUser
	*/
class WznmQUsgMNUser {

public:
	WznmQUsgMNUser(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixWznmVUserlevel;
	std::string srefIxWznmVUserlevel;
	std::string titIxWznmVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQUsgMNUser: recordset of TblWznmQUsgMNUser
	*/
class ListWznmQUsgMNUser {

public:
	ListWznmQUsgMNUser();
	ListWznmQUsgMNUser(const ListWznmQUsgMNUser& src);
	~ListWznmQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(WznmQUsgMNUser* rec);

	ListWznmQUsgMNUser& operator=(const ListWznmQUsgMNUser& src);

public:
	std::vector<WznmQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsgMNUser: C++ wrapper for table TblWznmQUsgMNUser
	*/
class TblWznmQUsgMNUser {

public:
	TblWznmQUsgMNUser();
	virtual ~TblWznmQUsgMNUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgMNUser& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsgMNUser* rec);
	Sbecore::ubigint insertNewRec(WznmQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsgMNUser& rst, WznmQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");
	virtual void insertRst(ListWznmQUsgMNUser& rst);
	virtual void updateRec(WznmQUsgMNUser* rec);
	virtual void updateRst(ListWznmQUsgMNUser& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgMNUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsgMNUser: C++ wrapper for table TblWznmQUsgMNUser (MySQL database)
	*/
class MyTblWznmQUsgMNUser : public TblWznmQUsgMNUser, public Sbecore::MyTable {

public:
	MyTblWznmQUsgMNUser();
	~MyTblWznmQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WznmQUsgMNUser* rec);
	void insertRst(ListWznmQUsgMNUser& rst);
	void updateRec(WznmQUsgMNUser* rec);
	void updateRst(ListWznmQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgMNUser& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsgMNUser: C++ wrapper for table TblWznmQUsgMNUser (PgSQL database)
	*/
class PgTblWznmQUsgMNUser : public TblWznmQUsgMNUser, public Sbecore::PgTable {

public:
	PgTblWznmQUsgMNUser();
	~PgTblWznmQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsgMNUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsgMNUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsgMNUser** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsgMNUser& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WznmQUsgMNUser* rec);
	void insertRst(ListWznmQUsgMNUser& rst);
	void updateRec(WznmQUsgMNUser* rec);
	void updateRst(ListWznmQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgMNUser& rst);
};
#endif

#endif

