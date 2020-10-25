/**
	* \file WznmQQryMNTable.h
	* Dbs and XML wrapper for table TblWznmQQryMNTable (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQQRYMNTABLE_H
#define WZNMQQRYMNTABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryMNTable: record of TblWznmQQryMNTable
	*/
class WznmQQryMNTable {

public:
	WznmQQryMNTable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const Sbecore::ubigint ref = 0, const bool Source = false, const std::string yesnoSource = "", const std::string Prefix = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	std::string stubsTrefWznmMQuerymod;
	Sbecore::ubigint ref;
	bool Source;
	std::string yesnoSource;
	std::string Prefix;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQryMNTable: recordset of TblWznmQQryMNTable
	*/
class ListWznmQQryMNTable {

public:
	ListWznmQQryMNTable();
	ListWznmQQryMNTable(const ListWznmQQryMNTable& src);
	~ListWznmQQryMNTable();

	void clear();
	unsigned int size() const;
	void append(WznmQQryMNTable* rec);

	ListWznmQQryMNTable& operator=(const ListWznmQQryMNTable& src);

public:
	std::vector<WznmQQryMNTable*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryMNTable: C++ wrapper for table TblWznmQQryMNTable
	*/
class TblWznmQQryMNTable {

public:
	TblWznmQQryMNTable();
	virtual ~TblWznmQQryMNTable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNTable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNTable& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryMNTable* rec);
	Sbecore::ubigint insertNewRec(WznmQQryMNTable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const Sbecore::ubigint ref = 0, const bool Source = false, const std::string yesnoSource = "", const std::string Prefix = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryMNTable& rst, WznmQQryMNTable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const Sbecore::ubigint ref = 0, const bool Source = false, const std::string yesnoSource = "", const std::string Prefix = "");
	virtual void insertRst(ListWznmQQryMNTable& rst);
	virtual void updateRec(WznmQQryMNTable* rec);
	virtual void updateRst(ListWznmQQryMNTable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNTable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNTable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryMNTable: C++ wrapper for table TblWznmQQryMNTable (MySQL database)
	*/
class MyTblWznmQQryMNTable : public TblWznmQQryMNTable, public Sbecore::MyTable {

public:
	MyTblWznmQQryMNTable();
	~MyTblWznmQQryMNTable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNTable& rst);

	Sbecore::ubigint insertRec(WznmQQryMNTable* rec);
	void insertRst(ListWznmQQryMNTable& rst);
	void updateRec(WznmQQryMNTable* rec);
	void updateRst(ListWznmQQryMNTable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNTable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNTable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryMNTable: C++ wrapper for table TblWznmQQryMNTable (PgSQL database)
	*/
class PgTblWznmQQryMNTable : public TblWznmQQryMNTable, public Sbecore::PgTable {

public:
	PgTblWznmQQryMNTable();
	~PgTblWznmQQryMNTable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryMNTable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryMNTable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryMNTable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryMNTable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNTable& rst);

	Sbecore::ubigint insertRec(WznmQQryMNTable* rec);
	void insertRst(ListWznmQQryMNTable& rst);
	void updateRec(WznmQQryMNTable* rec);
	void updateRst(ListWznmQQryMNTable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNTable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNTable& rst);
};
#endif

#endif

