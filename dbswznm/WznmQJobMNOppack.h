/**
	* \file WznmQJobMNOppack.h
	* Dbs and XML wrapper for table TblWznmQJobMNOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBMNOPPACK_H
#define WZNMQJOBMNOPPACK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobMNOppack: record of TblWznmQJobMNOppack
	*/
class WznmQJobMNOppack {

public:
	WznmQJobMNOppack(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJobMNOppack: recordset of TblWznmQJobMNOppack
	*/
class ListWznmQJobMNOppack {

public:
	ListWznmQJobMNOppack();
	ListWznmQJobMNOppack(const ListWznmQJobMNOppack& src);
	~ListWznmQJobMNOppack();

	void clear();
	unsigned int size() const;
	void append(WznmQJobMNOppack* rec);

	ListWznmQJobMNOppack& operator=(const ListWznmQJobMNOppack& src);

public:
	std::vector<WznmQJobMNOppack*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobMNOppack: C++ wrapper for table TblWznmQJobMNOppack
	*/
class TblWznmQJobMNOppack {

public:
	TblWznmQJobMNOppack();
	virtual ~TblWznmQJobMNOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobMNOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobMNOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobMNOppack* rec);
	Sbecore::ubigint insertNewRec(WznmQJobMNOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobMNOppack& rst, WznmQJobMNOppack** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQJobMNOppack& rst);
	virtual void updateRec(WznmQJobMNOppack* rec);
	virtual void updateRst(ListWznmQJobMNOppack& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobMNOppack** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobMNOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobMNOppack: C++ wrapper for table TblWznmQJobMNOppack (MySQL database)
	*/
class MyTblWznmQJobMNOppack : public TblWznmQJobMNOppack, public Sbecore::MyTable {

public:
	MyTblWznmQJobMNOppack();
	~MyTblWznmQJobMNOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobMNOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobMNOppack& rst);

	Sbecore::ubigint insertRec(WznmQJobMNOppack* rec);
	void insertRst(ListWznmQJobMNOppack& rst);
	void updateRec(WznmQJobMNOppack* rec);
	void updateRst(ListWznmQJobMNOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobMNOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobMNOppack& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobMNOppack: C++ wrapper for table TblWznmQJobMNOppack (PgSQL database)
	*/
class PgTblWznmQJobMNOppack : public TblWznmQJobMNOppack, public Sbecore::PgTable {

public:
	PgTblWznmQJobMNOppack();
	~PgTblWznmQJobMNOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobMNOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobMNOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobMNOppack** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobMNOppack& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobMNOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobMNOppack& rst);

	Sbecore::ubigint insertRec(WznmQJobMNOppack* rec);
	void insertRst(ListWznmQJobMNOppack& rst);
	void updateRec(WznmQJobMNOppack* rec);
	void updateRst(ListWznmQJobMNOppack& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobMNOppack** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobMNOppack& rst);
};
#endif

#endif
