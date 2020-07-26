/**
	* \file WznmQVer1NPreset.h
	* Dbs and XML wrapper for table TblWznmQVer1NPreset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQVER1NPRESET_H
#define WZNMQVER1NPRESET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NPreset: record of TblWznmQVer1NPreset
	*/
class WznmQVer1NPreset {

public:
	WznmQVer1NPreset(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVer1NPreset: recordset of TblWznmQVer1NPreset
	*/
class ListWznmQVer1NPreset {

public:
	ListWznmQVer1NPreset();
	ListWznmQVer1NPreset(const ListWznmQVer1NPreset& src);
	~ListWznmQVer1NPreset();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NPreset* rec);

	ListWznmQVer1NPreset& operator=(const ListWznmQVer1NPreset& src);

public:
	std::vector<WznmQVer1NPreset*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NPreset: C++ wrapper for table TblWznmQVer1NPreset
	*/
class TblWznmQVer1NPreset {

public:
	TblWznmQVer1NPreset();
	virtual ~TblWznmQVer1NPreset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NPreset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NPreset& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NPreset* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NPreset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NPreset& rst, WznmQVer1NPreset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NPreset& rst);
	virtual void updateRec(WznmQVer1NPreset* rec);
	virtual void updateRst(ListWznmQVer1NPreset& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NPreset** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NPreset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NPreset: C++ wrapper for table TblWznmQVer1NPreset (MySQL database)
	*/
class MyTblWznmQVer1NPreset : public TblWznmQVer1NPreset, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NPreset();
	~MyTblWznmQVer1NPreset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NPreset& rst);

	Sbecore::ubigint insertRec(WznmQVer1NPreset* rec);
	void insertRst(ListWznmQVer1NPreset& rst);
	void updateRec(WznmQVer1NPreset* rec);
	void updateRst(ListWznmQVer1NPreset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NPreset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NPreset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NPreset: C++ wrapper for table TblWznmQVer1NPreset (PgSQL database)
	*/
class PgTblWznmQVer1NPreset : public TblWznmQVer1NPreset, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NPreset();
	~PgTblWznmQVer1NPreset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NPreset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NPreset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NPreset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NPreset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NPreset& rst);

	Sbecore::ubigint insertRec(WznmQVer1NPreset* rec);
	void insertRst(ListWznmQVer1NPreset& rst);
	void updateRec(WznmQVer1NPreset* rec);
	void updateRst(ListWznmQVer1NPreset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NPreset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NPreset& rst);
};
#endif

#endif

