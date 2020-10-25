/**
	* \file WznmQUsrAAccess.h
	* Dbs and XML wrapper for table TblWznmQUsrAAccess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQUSRAACCESS_H
#define WZNMQUSRAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsrAAccess: record of TblWznmQUsrAAccess
	*/
class WznmQUsrAAccess {

public:
	WznmQUsrAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0, const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");

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
	* ListWznmQUsrAAccess: recordset of TblWznmQUsrAAccess
	*/
class ListWznmQUsrAAccess {

public:
	ListWznmQUsrAAccess();
	ListWznmQUsrAAccess(const ListWznmQUsrAAccess& src);
	~ListWznmQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(WznmQUsrAAccess* rec);

	ListWznmQUsrAAccess& operator=(const ListWznmQUsrAAccess& src);

public:
	std::vector<WznmQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsrAAccess: C++ wrapper for table TblWznmQUsrAAccess
	*/
class TblWznmQUsrAAccess {

public:
	TblWznmQUsrAAccess();
	virtual ~TblWznmQUsrAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrAAccess& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsrAAccess* rec);
	Sbecore::ubigint insertNewRec(WznmQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0, const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsrAAccess& rst, WznmQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0, const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");
	virtual void insertRst(ListWznmQUsrAAccess& rst);
	virtual void updateRec(WznmQUsrAAccess* rec);
	virtual void updateRst(ListWznmQUsrAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsrAAccess: C++ wrapper for table TblWznmQUsrAAccess (MySQL database)
	*/
class MyTblWznmQUsrAAccess : public TblWznmQUsrAAccess, public Sbecore::MyTable {

public:
	MyTblWznmQUsrAAccess();
	~MyTblWznmQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WznmQUsrAAccess* rec);
	void insertRst(ListWznmQUsrAAccess& rst);
	void updateRec(WznmQUsrAAccess* rec);
	void updateRst(ListWznmQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsrAAccess: C++ wrapper for table TblWznmQUsrAAccess (PgSQL database)
	*/
class PgTblWznmQUsrAAccess : public TblWznmQUsrAAccess, public Sbecore::PgTable {

public:
	PgTblWznmQUsrAAccess();
	~PgTblWznmQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsrAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsrAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsrAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsrAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WznmQUsrAAccess* rec);
	void insertRst(ListWznmQUsrAAccess& rst);
	void updateRec(WznmQUsrAAccess* rec);
	void updateRst(ListWznmQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsrAAccess& rst);
};
#endif

#endif

