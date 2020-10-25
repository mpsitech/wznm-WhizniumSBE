/**
	* \file WznmQStbSupMNStub.h
	* Dbs and XML wrapper for table TblWznmQStbSupMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSTBSUPMNSTUB_H
#define WZNMQSTBSUPMNSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQStbSupMNStub: record of TblWznmQStbSupMNStub
	*/
class WznmQStbSupMNStub {

public:
	WznmQStbSupMNStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQStbSupMNStub: recordset of TblWznmQStbSupMNStub
	*/
class ListWznmQStbSupMNStub {

public:
	ListWznmQStbSupMNStub();
	ListWznmQStbSupMNStub(const ListWznmQStbSupMNStub& src);
	~ListWznmQStbSupMNStub();

	void clear();
	unsigned int size() const;
	void append(WznmQStbSupMNStub* rec);

	ListWznmQStbSupMNStub& operator=(const ListWznmQStbSupMNStub& src);

public:
	std::vector<WznmQStbSupMNStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQStbSupMNStub: C++ wrapper for table TblWznmQStbSupMNStub
	*/
class TblWznmQStbSupMNStub {

public:
	TblWznmQStbSupMNStub();
	virtual ~TblWznmQStbSupMNStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQStbSupMNStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbSupMNStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQStbSupMNStub* rec);
	Sbecore::ubigint insertNewRec(WznmQStbSupMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQStbSupMNStub& rst, WznmQStbSupMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQStbSupMNStub& rst);
	virtual void updateRec(WznmQStbSupMNStub* rec);
	virtual void updateRst(ListWznmQStbSupMNStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQStbSupMNStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbSupMNStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQStbSupMNStub: C++ wrapper for table TblWznmQStbSupMNStub (MySQL database)
	*/
class MyTblWznmQStbSupMNStub : public TblWznmQStbSupMNStub, public Sbecore::MyTable {

public:
	MyTblWznmQStbSupMNStub();
	~MyTblWznmQStbSupMNStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbSupMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbSupMNStub& rst);

	Sbecore::ubigint insertRec(WznmQStbSupMNStub* rec);
	void insertRst(ListWznmQStbSupMNStub& rst);
	void updateRec(WznmQStbSupMNStub* rec);
	void updateRst(ListWznmQStbSupMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbSupMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbSupMNStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQStbSupMNStub: C++ wrapper for table TblWznmQStbSupMNStub (PgSQL database)
	*/
class PgTblWznmQStbSupMNStub : public TblWznmQStbSupMNStub, public Sbecore::PgTable {

public:
	PgTblWznmQStbSupMNStub();
	~PgTblWznmQStbSupMNStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQStbSupMNStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQStbSupMNStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQStbSupMNStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQStbSupMNStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbSupMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbSupMNStub& rst);

	Sbecore::ubigint insertRec(WznmQStbSupMNStub* rec);
	void insertRst(ListWznmQStbSupMNStub& rst);
	void updateRec(WznmQStbSupMNStub* rec);
	void updateRst(ListWznmQStbSupMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbSupMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbSupMNStub& rst);
};
#endif

#endif

