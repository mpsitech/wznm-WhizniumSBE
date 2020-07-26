/**
	* \file WznmQOpxAInvarg.h
	* Dbs and XML wrapper for table TblWznmQOpxAInvarg (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQOPXAINVARG_H
#define WZNMQOPXAINVARG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpxAInvarg: record of TblWznmQOpxAInvarg
	*/
class WznmQOpxAInvarg {

public:
	WznmQOpxAInvarg(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint opxNum;
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
	* ListWznmQOpxAInvarg: recordset of TblWznmQOpxAInvarg
	*/
class ListWznmQOpxAInvarg {

public:
	ListWznmQOpxAInvarg();
	ListWznmQOpxAInvarg(const ListWznmQOpxAInvarg& src);
	~ListWznmQOpxAInvarg();

	void clear();
	unsigned int size() const;
	void append(WznmQOpxAInvarg* rec);

	ListWznmQOpxAInvarg& operator=(const ListWznmQOpxAInvarg& src);

public:
	std::vector<WznmQOpxAInvarg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpxAInvarg: C++ wrapper for table TblWznmQOpxAInvarg
	*/
class TblWznmQOpxAInvarg {

public:
	TblWznmQOpxAInvarg();
	virtual ~TblWznmQOpxAInvarg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpxAInvarg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxAInvarg& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpxAInvarg* rec);
	Sbecore::ubigint insertNewRec(WznmQOpxAInvarg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpxAInvarg& rst, WznmQOpxAInvarg** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQOpxAInvarg& rst);
	virtual void updateRec(WznmQOpxAInvarg* rec);
	virtual void updateRst(ListWznmQOpxAInvarg& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxAInvarg** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxAInvarg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpxAInvarg: C++ wrapper for table TblWznmQOpxAInvarg (MySQL database)
	*/
class MyTblWznmQOpxAInvarg : public TblWznmQOpxAInvarg, public Sbecore::MyTable {

public:
	MyTblWznmQOpxAInvarg();
	~MyTblWznmQOpxAInvarg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxAInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxAInvarg& rst);

	Sbecore::ubigint insertRec(WznmQOpxAInvarg* rec);
	void insertRst(ListWznmQOpxAInvarg& rst);
	void updateRec(WznmQOpxAInvarg* rec);
	void updateRst(ListWznmQOpxAInvarg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxAInvarg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxAInvarg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpxAInvarg: C++ wrapper for table TblWznmQOpxAInvarg (PgSQL database)
	*/
class PgTblWznmQOpxAInvarg : public TblWznmQOpxAInvarg, public Sbecore::PgTable {

public:
	PgTblWznmQOpxAInvarg();
	~PgTblWznmQOpxAInvarg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpxAInvarg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpxAInvarg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpxAInvarg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpxAInvarg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxAInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxAInvarg& rst);

	Sbecore::ubigint insertRec(WznmQOpxAInvarg* rec);
	void insertRst(ListWznmQOpxAInvarg& rst);
	void updateRec(WznmQOpxAInvarg* rec);
	void updateRst(ListWznmQOpxAInvarg& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxAInvarg** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxAInvarg& rst);
};
#endif

#endif

