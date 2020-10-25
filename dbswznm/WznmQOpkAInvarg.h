/**
	* \file WznmQOpkAInvarg.h
	* Dbs and XML wrapper for table TblWznmQOpkAInvarg (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQOPKAINVARG_H
#define WZNMQOPKAINVARG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkAInvarg: record of TblWznmQOpkAInvarg
	*/
class WznmQOpkAInvarg {

public:
	WznmQOpkAInvarg(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint opkNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	std::string Defval;
	Sbecore::ubigint refWznmMVectoritem;
	std::string stubRefWznmMVectoritem;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQOpkAInvarg: recordset of TblWznmQOpkAInvarg
	*/
class ListWznmQOpkAInvarg {

public:
	ListWznmQOpkAInvarg();
	ListWznmQOpkAInvarg(const ListWznmQOpkAInvarg& src);
	~ListWznmQOpkAInvarg();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkAInvarg* rec);

	ListWznmQOpkAInvarg& operator=(const ListWznmQOpkAInvarg& src);

public:
	std::vector<WznmQOpkAInvarg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkAInvarg: C++ wrapper for table TblWznmQOpkAInvarg
	*/
class TblWznmQOpkAInvarg {

public:
	TblWznmQOpkAInvarg();
	virtual ~TblWznmQOpkAInvarg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkAInvarg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkAInvarg& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkAInvarg* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkAInvarg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkAInvarg& rst, WznmQOpkAInvarg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQOpkAInvarg& rst);
	virtual void updateRec(WznmQOpkAInvarg* rec);
	virtual void updateRst(ListWznmQOpkAInvarg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkAInvarg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkAInvarg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkAInvarg: C++ wrapper for table TblWznmQOpkAInvarg (MySQL database)
	*/
class MyTblWznmQOpkAInvarg : public TblWznmQOpkAInvarg, public Sbecore::MyTable {

public:
	MyTblWznmQOpkAInvarg();
	~MyTblWznmQOpkAInvarg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkAInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkAInvarg& rst);

	Sbecore::ubigint insertRec(WznmQOpkAInvarg* rec);
	void insertRst(ListWznmQOpkAInvarg& rst);
	void updateRec(WznmQOpkAInvarg* rec);
	void updateRst(ListWznmQOpkAInvarg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkAInvarg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkAInvarg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkAInvarg: C++ wrapper for table TblWznmQOpkAInvarg (PgSQL database)
	*/
class PgTblWznmQOpkAInvarg : public TblWznmQOpkAInvarg, public Sbecore::PgTable {

public:
	PgTblWznmQOpkAInvarg();
	~PgTblWznmQOpkAInvarg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkAInvarg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkAInvarg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkAInvarg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkAInvarg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkAInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkAInvarg& rst);

	Sbecore::ubigint insertRec(WznmQOpkAInvarg* rec);
	void insertRst(ListWznmQOpkAInvarg& rst);
	void updateRec(WznmQOpkAInvarg* rec);
	void updateRst(ListWznmQOpkAInvarg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkAInvarg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkAInvarg& rst);
};
#endif

#endif

