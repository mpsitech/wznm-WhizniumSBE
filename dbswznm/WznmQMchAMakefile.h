/**
	* \file WznmQMchAMakefile.h
	* Dbs and XML wrapper for table TblWznmQMchAMakefile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMCHAMAKEFILE_H
#define WZNMQMCHAMAKEFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMchAMakefile: record of TblWznmQMchAMakefile
	*/
class WznmQMchAMakefile {

public:
	WznmQMchAMakefile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKTag;
	std::string titX1SrefKTag;
	std::string Val;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMchAMakefile: recordset of TblWznmQMchAMakefile
	*/
class ListWznmQMchAMakefile {

public:
	ListWznmQMchAMakefile();
	ListWznmQMchAMakefile(const ListWznmQMchAMakefile& src);
	~ListWznmQMchAMakefile();

	void clear();
	unsigned int size() const;
	void append(WznmQMchAMakefile* rec);

	ListWznmQMchAMakefile& operator=(const ListWznmQMchAMakefile& src);

public:
	std::vector<WznmQMchAMakefile*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMchAMakefile: C++ wrapper for table TblWznmQMchAMakefile
	*/
class TblWznmQMchAMakefile {

public:
	TblWznmQMchAMakefile();
	virtual ~TblWznmQMchAMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMchAMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchAMakefile& rst);

	virtual Sbecore::ubigint insertRec(WznmQMchAMakefile* rec);
	Sbecore::ubigint insertNewRec(WznmQMchAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMchAMakefile& rst, WznmQMchAMakefile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWznmQMchAMakefile& rst);
	virtual void updateRec(WznmQMchAMakefile* rec);
	virtual void updateRst(ListWznmQMchAMakefile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMchAMakefile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchAMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMchAMakefile: C++ wrapper for table TblWznmQMchAMakefile (MySQL database)
	*/
class MyTblWznmQMchAMakefile : public TblWznmQMchAMakefile, public Sbecore::MyTable {

public:
	MyTblWznmQMchAMakefile();
	~MyTblWznmQMchAMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchAMakefile& rst);

	Sbecore::ubigint insertRec(WznmQMchAMakefile* rec);
	void insertRst(ListWznmQMchAMakefile& rst);
	void updateRec(WznmQMchAMakefile* rec);
	void updateRst(ListWznmQMchAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchAMakefile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMchAMakefile: C++ wrapper for table TblWznmQMchAMakefile (PgSQL database)
	*/
class PgTblWznmQMchAMakefile : public TblWznmQMchAMakefile, public Sbecore::PgTable {

public:
	PgTblWznmQMchAMakefile();
	~PgTblWznmQMchAMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMchAMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMchAMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMchAMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMchAMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMchAMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMchAMakefile& rst);

	Sbecore::ubigint insertRec(WznmQMchAMakefile* rec);
	void insertRst(ListWznmQMchAMakefile& rst);
	void updateRec(WznmQMchAMakefile* rec);
	void updateRst(ListWznmQMchAMakefile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMchAMakefile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMchAMakefile& rst);
};
#endif

#endif
