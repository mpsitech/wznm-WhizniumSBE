/**
	* \file WznmQRel1NTablecol.h
	* Dbs and XML wrapper for table TblWznmQRel1NTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQREL1NTABLECOL_H
#define WZNMQREL1NTABLECOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRel1NTablecol: record of TblWznmQRel1NTablecol
	*/
class WznmQRel1NTablecol {

public:
	WznmQRel1NTablecol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQRel1NTablecol: recordset of TblWznmQRel1NTablecol
	*/
class ListWznmQRel1NTablecol {

public:
	ListWznmQRel1NTablecol();
	ListWznmQRel1NTablecol(const ListWznmQRel1NTablecol& src);
	~ListWznmQRel1NTablecol();

	void clear();
	unsigned int size() const;
	void append(WznmQRel1NTablecol* rec);

	ListWznmQRel1NTablecol& operator=(const ListWznmQRel1NTablecol& src);

public:
	std::vector<WznmQRel1NTablecol*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRel1NTablecol: C++ wrapper for table TblWznmQRel1NTablecol
	*/
class TblWznmQRel1NTablecol {

public:
	TblWznmQRel1NTablecol();
	virtual ~TblWznmQRel1NTablecol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRel1NTablecol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRel1NTablecol& rst);

	virtual Sbecore::ubigint insertRec(WznmQRel1NTablecol* rec);
	Sbecore::ubigint insertNewRec(WznmQRel1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRel1NTablecol& rst, WznmQRel1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRel1NTablecol& rst);
	virtual void updateRec(WznmQRel1NTablecol* rec);
	virtual void updateRst(ListWznmQRel1NTablecol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRel1NTablecol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRel1NTablecol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRel1NTablecol: C++ wrapper for table TblWznmQRel1NTablecol (MySQL database)
	*/
class MyTblWznmQRel1NTablecol : public TblWznmQRel1NTablecol, public Sbecore::MyTable {

public:
	MyTblWznmQRel1NTablecol();
	~MyTblWznmQRel1NTablecol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRel1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRel1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQRel1NTablecol* rec);
	void insertRst(ListWznmQRel1NTablecol& rst);
	void updateRec(WznmQRel1NTablecol* rec);
	void updateRst(ListWznmQRel1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRel1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRel1NTablecol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRel1NTablecol: C++ wrapper for table TblWznmQRel1NTablecol (PgSQL database)
	*/
class PgTblWznmQRel1NTablecol : public TblWznmQRel1NTablecol, public Sbecore::PgTable {

public:
	PgTblWznmQRel1NTablecol();
	~PgTblWznmQRel1NTablecol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRel1NTablecol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRel1NTablecol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRel1NTablecol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRel1NTablecol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRel1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRel1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQRel1NTablecol* rec);
	void insertRst(ListWznmQRel1NTablecol& rst);
	void updateRec(WznmQRel1NTablecol* rec);
	void updateRst(ListWznmQRel1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRel1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRel1NTablecol& rst);
};
#endif

#endif
