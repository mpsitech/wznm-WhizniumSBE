/**
	* \file WznmQStbMNSquawk.h
	* Dbs and XML wrapper for table TblWznmQStbMNSquawk (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSTBMNSQUAWK_H
#define WZNMQSTBMNSQUAWK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQStbMNSquawk: record of TblWznmQStbMNSquawk
	*/
class WznmQStbMNSquawk {

public:
	WznmQStbMNSquawk(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQStbMNSquawk: recordset of TblWznmQStbMNSquawk
	*/
class ListWznmQStbMNSquawk {

public:
	ListWznmQStbMNSquawk();
	ListWznmQStbMNSquawk(const ListWznmQStbMNSquawk& src);
	~ListWznmQStbMNSquawk();

	void clear();
	unsigned int size() const;
	void append(WznmQStbMNSquawk* rec);

	ListWznmQStbMNSquawk& operator=(const ListWznmQStbMNSquawk& src);

public:
	std::vector<WznmQStbMNSquawk*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQStbMNSquawk: C++ wrapper for table TblWznmQStbMNSquawk
	*/
class TblWznmQStbMNSquawk {

public:
	TblWznmQStbMNSquawk();
	virtual ~TblWznmQStbMNSquawk();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQStbMNSquawk** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbMNSquawk& rst);

	virtual Sbecore::ubigint insertRec(WznmQStbMNSquawk* rec);
	Sbecore::ubigint insertNewRec(WznmQStbMNSquawk** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQStbMNSquawk& rst, WznmQStbMNSquawk** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQStbMNSquawk& rst);
	virtual void updateRec(WznmQStbMNSquawk* rec);
	virtual void updateRst(ListWznmQStbMNSquawk& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQStbMNSquawk** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbMNSquawk& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQStbMNSquawk: C++ wrapper for table TblWznmQStbMNSquawk (MySQL database)
	*/
class MyTblWznmQStbMNSquawk : public TblWznmQStbMNSquawk, public Sbecore::MyTable {

public:
	MyTblWznmQStbMNSquawk();
	~MyTblWznmQStbMNSquawk();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbMNSquawk** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbMNSquawk& rst);

	Sbecore::ubigint insertRec(WznmQStbMNSquawk* rec);
	void insertRst(ListWznmQStbMNSquawk& rst);
	void updateRec(WznmQStbMNSquawk* rec);
	void updateRst(ListWznmQStbMNSquawk& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbMNSquawk** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbMNSquawk& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQStbMNSquawk: C++ wrapper for table TblWznmQStbMNSquawk (PgSQL database)
	*/
class PgTblWznmQStbMNSquawk : public TblWznmQStbMNSquawk, public Sbecore::PgTable {

public:
	PgTblWznmQStbMNSquawk();
	~PgTblWznmQStbMNSquawk();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQStbMNSquawk** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQStbMNSquawk& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQStbMNSquawk** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQStbMNSquawk& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbMNSquawk** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbMNSquawk& rst);

	Sbecore::ubigint insertRec(WznmQStbMNSquawk* rec);
	void insertRst(ListWznmQStbMNSquawk& rst);
	void updateRec(WznmQStbMNSquawk* rec);
	void updateRst(ListWznmQStbMNSquawk& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbMNSquawk** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbMNSquawk& rst);
};
#endif

#endif

