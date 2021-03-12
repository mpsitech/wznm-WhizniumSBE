/**
	* \file WznmQUsrMNUsergroup.h
	* Dbs and XML wrapper for table TblWznmQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSRMNUSERGROUP_H
#define WZNMQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsrMNUsergroup: record of TblWznmQUsrMNUsergroup
	*/
class WznmQUsrMNUsergroup {

public:
	WznmQUsrMNUsergroup(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQUsrMNUsergroup: recordset of TblWznmQUsrMNUsergroup
	*/
class ListWznmQUsrMNUsergroup {

public:
	ListWznmQUsrMNUsergroup();
	ListWznmQUsrMNUsergroup(const ListWznmQUsrMNUsergroup& src);
	~ListWznmQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(WznmQUsrMNUsergroup* rec);

	ListWznmQUsrMNUsergroup& operator=(const ListWznmQUsrMNUsergroup& src);

public:
	std::vector<WznmQUsrMNUsergroup*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsrMNUsergroup: C++ wrapper for table TblWznmQUsrMNUsergroup
	*/
class TblWznmQUsrMNUsergroup {

public:
	TblWznmQUsrMNUsergroup();
	virtual ~TblWznmQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrMNUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsrMNUsergroup* rec);
	Sbecore::ubigint insertNewRec(WznmQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsrMNUsergroup& rst, WznmQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");
	virtual void insertRst(ListWznmQUsrMNUsergroup& rst);
	virtual void updateRec(WznmQUsrMNUsergroup* rec);
	virtual void updateRst(ListWznmQUsrMNUsergroup& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrMNUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsrMNUsergroup: C++ wrapper for table TblWznmQUsrMNUsergroup (MySQL database)
	*/
class MyTblWznmQUsrMNUsergroup : public TblWznmQUsrMNUsergroup, public Sbecore::MyTable {

public:
	MyTblWznmQUsrMNUsergroup();
	~MyTblWznmQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WznmQUsrMNUsergroup* rec);
	void insertRst(ListWznmQUsrMNUsergroup& rst);
	void updateRec(WznmQUsrMNUsergroup* rec);
	void updateRst(ListWznmQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrMNUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsrMNUsergroup: C++ wrapper for table TblWznmQUsrMNUsergroup (PgSQL database)
	*/
class PgTblWznmQUsrMNUsergroup : public TblWznmQUsrMNUsergroup, public Sbecore::PgTable {

public:
	PgTblWznmQUsrMNUsergroup();
	~PgTblWznmQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsrMNUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WznmQUsrMNUsergroup* rec);
	void insertRst(ListWznmQUsrMNUsergroup& rst);
	void updateRec(WznmQUsrMNUsergroup* rec);
	void updateRst(ListWznmQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrMNUsergroup& rst);
};
#endif

#endif
