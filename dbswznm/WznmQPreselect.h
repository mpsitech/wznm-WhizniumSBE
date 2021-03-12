/**
	* \file WznmQPreselect.h
	* Dbs and XML wrapper for table TblWznmQPreselect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRESELECT_H
#define WZNMQPRESELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPreselect: record of TblWznmQPreselect
	*/
class WznmQPreselect {

public:
	WznmQPreselect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPreselect: recordset of TblWznmQPreselect
	*/
class ListWznmQPreselect {

public:
	ListWznmQPreselect();
	ListWznmQPreselect(const ListWznmQPreselect& src);
	~ListWznmQPreselect();

	void clear();
	unsigned int size() const;
	void append(WznmQPreselect* rec);

	ListWznmQPreselect& operator=(const ListWznmQPreselect& src);

public:
	std::vector<WznmQPreselect*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPreselect: C++ wrapper for table TblWznmQPreselect
	*/
class TblWznmQPreselect {

public:
	TblWznmQPreselect();
	virtual ~TblWznmQPreselect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPreselect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPreselect& rst);

	virtual Sbecore::ubigint insertRec(WznmQPreselect* rec);
	Sbecore::ubigint insertNewRec(WznmQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQPreselect& rst, WznmQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQPreselect& rst);
	virtual void updateRec(WznmQPreselect* rec);
	virtual void updateRst(ListWznmQPreselect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPreselect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPreselect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPreselect: C++ wrapper for table TblWznmQPreselect (MySQL database)
	*/
class MyTblWznmQPreselect : public TblWznmQPreselect, public Sbecore::MyTable {

public:
	MyTblWznmQPreselect();
	~MyTblWznmQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPreselect& rst);

	Sbecore::ubigint insertRec(WznmQPreselect* rec);
	void insertRst(ListWznmQPreselect& rst);
	void updateRec(WznmQPreselect* rec);
	void updateRst(ListWznmQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPreselect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPreselect: C++ wrapper for table TblWznmQPreselect (PgSQL database)
	*/
class PgTblWznmQPreselect : public TblWznmQPreselect, public Sbecore::PgTable {

public:
	PgTblWznmQPreselect();
	~PgTblWznmQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPreselect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPreselect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPreselect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPreselect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPreselect& rst);

	Sbecore::ubigint insertRec(WznmQPreselect* rec);
	void insertRst(ListWznmQPreselect& rst);
	void updateRec(WznmQPreselect* rec);
	void updateRst(ListWznmQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPreselect& rst);
};
#endif

#endif
