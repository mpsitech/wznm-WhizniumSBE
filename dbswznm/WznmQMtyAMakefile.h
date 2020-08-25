/**
	* \file WznmQMtyAMakefile.h
	* Dbs and XML wrapper for table TblWznmQMtyAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMTYAMAKEFILE_H
#define WZNMQMTYAMAKEFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMtyAMakefile: record of TblWznmQMtyAMakefile
	*/
class WznmQMtyAMakefile {

public:
	WznmQMtyAMakefile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKTag;
	std::string titX1SrefKTag;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMtyAMakefile: recordset of TblWznmQMtyAMakefile
	*/
class ListWznmQMtyAMakefile {

public:
	ListWznmQMtyAMakefile();
	ListWznmQMtyAMakefile(const ListWznmQMtyAMakefile& src);
	~ListWznmQMtyAMakefile();

	void clear();
	unsigned int size() const;
	void append(WznmQMtyAMakefile* rec);

	ListWznmQMtyAMakefile& operator=(const ListWznmQMtyAMakefile& src);

public:
	std::vector<WznmQMtyAMakefile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMtyAMakefile: C++ wrapper for table TblWznmQMtyAMakefile
	*/
class TblWznmQMtyAMakefile {

public:
	TblWznmQMtyAMakefile();
	virtual ~TblWznmQMtyAMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMtyAMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtyAMakefile& rst);

	virtual Sbecore::ubigint insertRec(WznmQMtyAMakefile* rec);
	Sbecore::ubigint insertNewRec(WznmQMtyAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMtyAMakefile& rst, WznmQMtyAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWznmQMtyAMakefile& rst);
	virtual void updateRec(WznmQMtyAMakefile* rec);
	virtual void updateRst(ListWznmQMtyAMakefile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMtyAMakefile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtyAMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMtyAMakefile: C++ wrapper for table TblWznmQMtyAMakefile (MySQL database)
	*/
class MyTblWznmQMtyAMakefile : public TblWznmQMtyAMakefile, public Sbecore::MyTable {

public:
	MyTblWznmQMtyAMakefile();
	~MyTblWznmQMtyAMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtyAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtyAMakefile& rst);

	Sbecore::ubigint insertRec(WznmQMtyAMakefile* rec);
	void insertRst(ListWznmQMtyAMakefile& rst);
	void updateRec(WznmQMtyAMakefile* rec);
	void updateRst(ListWznmQMtyAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtyAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtyAMakefile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMtyAMakefile: C++ wrapper for table TblWznmQMtyAMakefile (PgSQL database)
	*/
class PgTblWznmQMtyAMakefile : public TblWznmQMtyAMakefile, public Sbecore::PgTable {

public:
	PgTblWznmQMtyAMakefile();
	~PgTblWznmQMtyAMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMtyAMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMtyAMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMtyAMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMtyAMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtyAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtyAMakefile& rst);

	Sbecore::ubigint insertRec(WznmQMtyAMakefile* rec);
	void insertRst(ListWznmQMtyAMakefile& rst);
	void updateRec(WznmQMtyAMakefile* rec);
	void updateRst(ListWznmQMtyAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtyAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtyAMakefile& rst);
};
#endif

#endif

