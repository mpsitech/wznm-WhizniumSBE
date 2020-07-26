/**
	* \file WznmQUsgAAccess.h
	* Dbs and XML wrapper for table TblWznmQUsgAAccess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQUSGAACCESS_H
#define WZNMQUSGAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsgAAccess: record of TblWznmQUsgAAccess
	*/
class WznmQUsgAAccess {

public:
	WznmQUsgAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0, const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxWznmVFeatgroup;
	std::string srefX1IxWznmVFeatgroup;
	std::string titX1IxWznmVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWznmWAccess;
	std::string srefsIxWznmWAccess;
	std::string titsIxWznmWAccess;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQUsgAAccess: recordset of TblWznmQUsgAAccess
	*/
class ListWznmQUsgAAccess {

public:
	ListWznmQUsgAAccess();
	ListWznmQUsgAAccess(const ListWznmQUsgAAccess& src);
	~ListWznmQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(WznmQUsgAAccess* rec);

	ListWznmQUsgAAccess& operator=(const ListWznmQUsgAAccess& src);

public:
	std::vector<WznmQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsgAAccess: C++ wrapper for table TblWznmQUsgAAccess
	*/
class TblWznmQUsgAAccess {

public:
	TblWznmQUsgAAccess();
	virtual ~TblWznmQUsgAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgAAccess& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsgAAccess* rec);
	Sbecore::ubigint insertNewRec(WznmQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0, const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsgAAccess& rst, WznmQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0, const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");
	virtual void insertRst(ListWznmQUsgAAccess& rst);
	virtual void updateRec(WznmQUsgAAccess* rec);
	virtual void updateRst(ListWznmQUsgAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsgAAccess: C++ wrapper for table TblWznmQUsgAAccess (MySQL database)
	*/
class MyTblWznmQUsgAAccess : public TblWznmQUsgAAccess, public Sbecore::MyTable {

public:
	MyTblWznmQUsgAAccess();
	~MyTblWznmQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WznmQUsgAAccess* rec);
	void insertRst(ListWznmQUsgAAccess& rst);
	void updateRec(WznmQUsgAAccess* rec);
	void updateRst(ListWznmQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsgAAccess: C++ wrapper for table TblWznmQUsgAAccess (PgSQL database)
	*/
class PgTblWznmQUsgAAccess : public TblWznmQUsgAAccess, public Sbecore::PgTable {

public:
	PgTblWznmQUsgAAccess();
	~PgTblWznmQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsgAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsgAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsgAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsgAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WznmQUsgAAccess* rec);
	void insertRst(ListWznmQUsgAAccess& rst);
	void updateRec(WznmQUsgAAccess* rec);
	void updateRst(ListWznmQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsgAAccess& rst);
};
#endif

#endif

