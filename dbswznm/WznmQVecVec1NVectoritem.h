/**
	* \file WznmQVecVec1NVectoritem.h
	* Dbs and XML wrapper for table TblWznmQVecVec1NVectoritem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECVEC1NVECTORITEM_H
#define WZNMQVECVEC1NVECTORITEM_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecVec1NVectoritem: record of TblWznmQVecVec1NVectoritem
	*/
class WznmQVecVec1NVectoritem {

public:
	WznmQVecVec1NVectoritem(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint vecNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint vecNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVecVec1NVectoritem: recordset of TblWznmQVecVec1NVectoritem
	*/
class ListWznmQVecVec1NVectoritem {

public:
	ListWznmQVecVec1NVectoritem();
	ListWznmQVecVec1NVectoritem(const ListWznmQVecVec1NVectoritem& src);
	~ListWznmQVecVec1NVectoritem();

	void clear();
	unsigned int size() const;
	void append(WznmQVecVec1NVectoritem* rec);

	ListWznmQVecVec1NVectoritem& operator=(const ListWznmQVecVec1NVectoritem& src);

public:
	std::vector<WznmQVecVec1NVectoritem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecVec1NVectoritem: C++ wrapper for table TblWznmQVecVec1NVectoritem
	*/
class TblWznmQVecVec1NVectoritem {

public:
	TblWznmQVecVec1NVectoritem();
	virtual ~TblWznmQVecVec1NVectoritem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecVec1NVectoritem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecVec1NVectoritem& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecVec1NVectoritem* rec);
	Sbecore::ubigint insertNewRec(WznmQVecVec1NVectoritem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint vecNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecVec1NVectoritem& rst, WznmQVecVec1NVectoritem** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint vecNum = 0);
	virtual void insertRst(ListWznmQVecVec1NVectoritem& rst);
	virtual void updateRec(WznmQVecVec1NVectoritem* rec);
	virtual void updateRst(ListWznmQVecVec1NVectoritem& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecVec1NVectoritem** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecVec1NVectoritem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecVec1NVectoritem: C++ wrapper for table TblWznmQVecVec1NVectoritem (MySQL database)
	*/
class MyTblWznmQVecVec1NVectoritem : public TblWznmQVecVec1NVectoritem, public Sbecore::MyTable {

public:
	MyTblWznmQVecVec1NVectoritem();
	~MyTblWznmQVecVec1NVectoritem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecVec1NVectoritem& rst);

	Sbecore::ubigint insertRec(WznmQVecVec1NVectoritem* rec);
	void insertRst(ListWznmQVecVec1NVectoritem& rst);
	void updateRec(WznmQVecVec1NVectoritem* rec);
	void updateRst(ListWznmQVecVec1NVectoritem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecVec1NVectoritem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecVec1NVectoritem: C++ wrapper for table TblWznmQVecVec1NVectoritem (PgSQL database)
	*/
class PgTblWznmQVecVec1NVectoritem : public TblWznmQVecVec1NVectoritem, public Sbecore::PgTable {

public:
	PgTblWznmQVecVec1NVectoritem();
	~PgTblWznmQVecVec1NVectoritem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecVec1NVectoritem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecVec1NVectoritem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecVec1NVectoritem& rst);

	Sbecore::ubigint insertRec(WznmQVecVec1NVectoritem* rec);
	void insertRst(ListWznmQVecVec1NVectoritem& rst);
	void updateRec(WznmQVecVec1NVectoritem* rec);
	void updateRst(ListWznmQVecVec1NVectoritem& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecVec1NVectoritem** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecVec1NVectoritem& rst);
};
#endif

#endif

