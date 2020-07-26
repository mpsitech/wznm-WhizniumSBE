/**
	* \file WznmQTblALoadfct.h
	* Dbs and XML wrapper for table TblWznmQTblALoadfct (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBLALOADFCT_H
#define WZNMQTBLALOADFCT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblALoadfct: record of TblWznmQTblALoadfct
	*/
class WznmQTblALoadfct {

public:
	WznmQTblALoadfct(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVLoadtype = 0, const std::string srefIxVLoadtype = "", const std::string titIxVLoadtype = "", const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0, const std::string srefIxVLimtype = "", const std::string titIxVLimtype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint ixVLoadtype;
	std::string srefIxVLoadtype;
	std::string titIxVLoadtype;
	std::string Fctname;
	std::string ldSrefWznmMTablecol;
	std::string lbySrefsWznmMTablecol;
	std::string ordSrefsWznmMTablecol;
	Sbecore::uint ixVLimtype;
	std::string srefIxVLimtype;
	std::string titIxVLimtype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblALoadfct: recordset of TblWznmQTblALoadfct
	*/
class ListWznmQTblALoadfct {

public:
	ListWznmQTblALoadfct();
	ListWznmQTblALoadfct(const ListWznmQTblALoadfct& src);
	~ListWznmQTblALoadfct();

	void clear();
	unsigned int size() const;
	void append(WznmQTblALoadfct* rec);

	ListWznmQTblALoadfct& operator=(const ListWznmQTblALoadfct& src);

public:
	std::vector<WznmQTblALoadfct*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblALoadfct: C++ wrapper for table TblWznmQTblALoadfct
	*/
class TblWznmQTblALoadfct {

public:
	TblWznmQTblALoadfct();
	virtual ~TblWznmQTblALoadfct();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblALoadfct** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblALoadfct& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblALoadfct* rec);
	Sbecore::ubigint insertNewRec(WznmQTblALoadfct** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVLoadtype = 0, const std::string srefIxVLoadtype = "", const std::string titIxVLoadtype = "", const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0, const std::string srefIxVLimtype = "", const std::string titIxVLimtype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblALoadfct& rst, WznmQTblALoadfct** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVLoadtype = 0, const std::string srefIxVLoadtype = "", const std::string titIxVLoadtype = "", const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0, const std::string srefIxVLimtype = "", const std::string titIxVLimtype = "");
	virtual void insertRst(ListWznmQTblALoadfct& rst);
	virtual void updateRec(WznmQTblALoadfct* rec);
	virtual void updateRst(ListWznmQTblALoadfct& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblALoadfct** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblALoadfct& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblALoadfct: C++ wrapper for table TblWznmQTblALoadfct (MySQL database)
	*/
class MyTblWznmQTblALoadfct : public TblWznmQTblALoadfct, public Sbecore::MyTable {

public:
	MyTblWznmQTblALoadfct();
	~MyTblWznmQTblALoadfct();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblALoadfct** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblALoadfct& rst);

	Sbecore::ubigint insertRec(WznmQTblALoadfct* rec);
	void insertRst(ListWznmQTblALoadfct& rst);
	void updateRec(WznmQTblALoadfct* rec);
	void updateRst(ListWznmQTblALoadfct& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblALoadfct** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblALoadfct& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblALoadfct: C++ wrapper for table TblWznmQTblALoadfct (PgSQL database)
	*/
class PgTblWznmQTblALoadfct : public TblWznmQTblALoadfct, public Sbecore::PgTable {

public:
	PgTblWznmQTblALoadfct();
	~PgTblWznmQTblALoadfct();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblALoadfct** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblALoadfct& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblALoadfct** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblALoadfct& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblALoadfct** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblALoadfct& rst);

	Sbecore::ubigint insertRec(WznmQTblALoadfct* rec);
	void insertRst(ListWznmQTblALoadfct& rst);
	void updateRec(WznmQTblALoadfct* rec);
	void updateRst(ListWznmQTblALoadfct& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblALoadfct** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblALoadfct& rst);
};
#endif

#endif

