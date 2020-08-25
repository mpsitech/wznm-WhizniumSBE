/**
	* \file WznmQSelect.h
	* Dbs and XML wrapper for table TblWznmQSelect (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSELECT_H
#define WZNMQSELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSelect: record of TblWznmQSelect
	*/
class WznmQSelect {

public:
	WznmQSelect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::uint ix;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSelect: recordset of TblWznmQSelect
	*/
class ListWznmQSelect {

public:
	ListWznmQSelect();
	ListWznmQSelect(const ListWznmQSelect& src);
	~ListWznmQSelect();

	void clear();
	unsigned int size() const;
	void append(WznmQSelect* rec);

	ListWznmQSelect& operator=(const ListWznmQSelect& src);

public:
	std::vector<WznmQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSelect: C++ wrapper for table TblWznmQSelect
	*/
class TblWznmQSelect {

public:
	TblWznmQSelect();
	virtual ~TblWznmQSelect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSelect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSelect& rst);

	virtual Sbecore::ubigint insertRec(WznmQSelect* rec);
	Sbecore::ubigint insertNewRec(WznmQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQSelect& rst, WznmQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQSelect& rst);
	virtual void updateRec(WznmQSelect* rec);
	virtual void updateRst(ListWznmQSelect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSelect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSelect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSelect: C++ wrapper for table TblWznmQSelect (MySQL database)
	*/
class MyTblWznmQSelect : public TblWznmQSelect, public Sbecore::MyTable {

public:
	MyTblWznmQSelect();
	~MyTblWznmQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSelect& rst);

	Sbecore::ubigint insertRec(WznmQSelect* rec);
	void insertRst(ListWznmQSelect& rst);
	void updateRec(WznmQSelect* rec);
	void updateRst(ListWznmQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSelect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSelect: C++ wrapper for table TblWznmQSelect (PgSQL database)
	*/
class PgTblWznmQSelect : public TblWznmQSelect, public Sbecore::PgTable {

public:
	PgTblWznmQSelect();
	~PgTblWznmQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSelect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSelect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSelect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSelect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSelect& rst);

	Sbecore::ubigint insertRec(WznmQSelect* rec);
	void insertRst(ListWznmQSelect& rst);
	void updateRec(WznmQSelect* rec);
	void updateRst(ListWznmQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSelect& rst);
};
#endif

#endif

