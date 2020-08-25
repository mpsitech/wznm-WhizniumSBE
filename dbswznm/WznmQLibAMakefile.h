/**
	* \file WznmQLibAMakefile.h
	* Dbs and XML wrapper for table TblWznmQLibAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQLIBAMAKEFILE_H
#define WZNMQLIBAMAKEFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLibAMakefile: record of TblWznmQLibAMakefile
	*/
class WznmQLibAMakefile {

public:
	WznmQLibAMakefile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1RefIxVTbl = 0, const std::string srefX1RefIxVTbl = "", const std::string titX1RefIxVTbl = "", const Sbecore::ubigint x1RefUref = 0, const std::string stubX1RefUref = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1RefIxVTbl;
	std::string srefX1RefIxVTbl;
	std::string titX1RefIxVTbl;
	Sbecore::ubigint x1RefUref;
	std::string stubX1RefUref;
	std::string x2SrefKTag;
	std::string titX2SrefKTag;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQLibAMakefile: recordset of TblWznmQLibAMakefile
	*/
class ListWznmQLibAMakefile {

public:
	ListWznmQLibAMakefile();
	ListWznmQLibAMakefile(const ListWznmQLibAMakefile& src);
	~ListWznmQLibAMakefile();

	void clear();
	unsigned int size() const;
	void append(WznmQLibAMakefile* rec);

	ListWznmQLibAMakefile& operator=(const ListWznmQLibAMakefile& src);

public:
	std::vector<WznmQLibAMakefile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLibAMakefile: C++ wrapper for table TblWznmQLibAMakefile
	*/
class TblWznmQLibAMakefile {

public:
	TblWznmQLibAMakefile();
	virtual ~TblWznmQLibAMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLibAMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibAMakefile& rst);

	virtual Sbecore::ubigint insertRec(WznmQLibAMakefile* rec);
	Sbecore::ubigint insertNewRec(WznmQLibAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1RefIxVTbl = 0, const std::string srefX1RefIxVTbl = "", const std::string titX1RefIxVTbl = "", const Sbecore::ubigint x1RefUref = 0, const std::string stubX1RefUref = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQLibAMakefile& rst, WznmQLibAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1RefIxVTbl = 0, const std::string srefX1RefIxVTbl = "", const std::string titX1RefIxVTbl = "", const Sbecore::ubigint x1RefUref = 0, const std::string stubX1RefUref = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWznmQLibAMakefile& rst);
	virtual void updateRec(WznmQLibAMakefile* rec);
	virtual void updateRst(ListWznmQLibAMakefile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLibAMakefile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibAMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLibAMakefile: C++ wrapper for table TblWznmQLibAMakefile (MySQL database)
	*/
class MyTblWznmQLibAMakefile : public TblWznmQLibAMakefile, public Sbecore::MyTable {

public:
	MyTblWznmQLibAMakefile();
	~MyTblWznmQLibAMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibAMakefile& rst);

	Sbecore::ubigint insertRec(WznmQLibAMakefile* rec);
	void insertRst(ListWznmQLibAMakefile& rst);
	void updateRec(WznmQLibAMakefile* rec);
	void updateRst(ListWznmQLibAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibAMakefile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLibAMakefile: C++ wrapper for table TblWznmQLibAMakefile (PgSQL database)
	*/
class PgTblWznmQLibAMakefile : public TblWznmQLibAMakefile, public Sbecore::PgTable {

public:
	PgTblWznmQLibAMakefile();
	~PgTblWznmQLibAMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLibAMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLibAMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLibAMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLibAMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibAMakefile& rst);

	Sbecore::ubigint insertRec(WznmQLibAMakefile* rec);
	void insertRst(ListWznmQLibAMakefile& rst);
	void updateRec(WznmQLibAMakefile* rec);
	void updateRst(ListWznmQLibAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibAMakefile& rst);
};
#endif

#endif

