/**
	* \file WznmQQryAOrder.h
	* Dbs and XML wrapper for table TblWznmQQryAOrder (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYAORDER_H
#define WZNMQQRYAORDER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryAOrder: record of TblWznmQQryAOrder
	*/
class WznmQQryAOrder {

public:
	WznmQQryAOrder(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string Short;
	std::string srefsWznmMTablecol;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQryAOrder: recordset of TblWznmQQryAOrder
	*/
class ListWznmQQryAOrder {

public:
	ListWznmQQryAOrder();
	ListWznmQQryAOrder(const ListWznmQQryAOrder& src);
	~ListWznmQQryAOrder();

	void clear();
	unsigned int size() const;
	void append(WznmQQryAOrder* rec);

	ListWznmQQryAOrder& operator=(const ListWznmQQryAOrder& src);

public:
	std::vector<WznmQQryAOrder*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryAOrder: C++ wrapper for table TblWznmQQryAOrder
	*/
class TblWznmQQryAOrder {

public:
	TblWznmQQryAOrder();
	virtual ~TblWznmQQryAOrder();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryAOrder** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryAOrder& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryAOrder* rec);
	Sbecore::ubigint insertNewRec(WznmQQryAOrder** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryAOrder& rst, WznmQQryAOrder** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");
	virtual void insertRst(ListWznmQQryAOrder& rst);
	virtual void updateRec(WznmQQryAOrder* rec);
	virtual void updateRst(ListWznmQQryAOrder& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryAOrder** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryAOrder& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryAOrder: C++ wrapper for table TblWznmQQryAOrder (MySQL database)
	*/
class MyTblWznmQQryAOrder : public TblWznmQQryAOrder, public Sbecore::MyTable {

public:
	MyTblWznmQQryAOrder();
	~MyTblWznmQQryAOrder();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryAOrder** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryAOrder& rst);

	Sbecore::ubigint insertRec(WznmQQryAOrder* rec);
	void insertRst(ListWznmQQryAOrder& rst);
	void updateRec(WznmQQryAOrder* rec);
	void updateRst(ListWznmQQryAOrder& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryAOrder** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryAOrder& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryAOrder: C++ wrapper for table TblWznmQQryAOrder (PgSQL database)
	*/
class PgTblWznmQQryAOrder : public TblWznmQQryAOrder, public Sbecore::PgTable {

public:
	PgTblWznmQQryAOrder();
	~PgTblWznmQQryAOrder();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryAOrder** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryAOrder& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryAOrder** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryAOrder& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryAOrder** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryAOrder& rst);

	Sbecore::ubigint insertRec(WznmQQryAOrder* rec);
	void insertRst(ListWznmQQryAOrder& rst);
	void updateRec(WznmQQryAOrder* rec);
	void updateRst(ListWznmQQryAOrder& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryAOrder** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryAOrder& rst);
};
#endif

#endif
