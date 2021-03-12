/**
	* \file WznmQStbSubMNStub.h
	* Dbs and XML wrapper for table TblWznmQStbSubMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSTBSUBMNSTUB_H
#define WZNMQSTBSUBMNSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQStbSubMNStub: record of TblWznmQStbSubMNStub
	*/
class WznmQStbSubMNStub {

public:
	WznmQStbSubMNStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQStbSubMNStub: recordset of TblWznmQStbSubMNStub
	*/
class ListWznmQStbSubMNStub {

public:
	ListWznmQStbSubMNStub();
	ListWznmQStbSubMNStub(const ListWznmQStbSubMNStub& src);
	~ListWznmQStbSubMNStub();

	void clear();
	unsigned int size() const;
	void append(WznmQStbSubMNStub* rec);

	ListWznmQStbSubMNStub& operator=(const ListWznmQStbSubMNStub& src);

public:
	std::vector<WznmQStbSubMNStub*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQStbSubMNStub: C++ wrapper for table TblWznmQStbSubMNStub
	*/
class TblWznmQStbSubMNStub {

public:
	TblWznmQStbSubMNStub();
	virtual ~TblWznmQStbSubMNStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQStbSubMNStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbSubMNStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQStbSubMNStub* rec);
	Sbecore::ubigint insertNewRec(WznmQStbSubMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQStbSubMNStub& rst, WznmQStbSubMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQStbSubMNStub& rst);
	virtual void updateRec(WznmQStbSubMNStub* rec);
	virtual void updateRst(ListWznmQStbSubMNStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQStbSubMNStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbSubMNStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQStbSubMNStub: C++ wrapper for table TblWznmQStbSubMNStub (MySQL database)
	*/
class MyTblWznmQStbSubMNStub : public TblWznmQStbSubMNStub, public Sbecore::MyTable {

public:
	MyTblWznmQStbSubMNStub();
	~MyTblWznmQStbSubMNStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbSubMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbSubMNStub& rst);

	Sbecore::ubigint insertRec(WznmQStbSubMNStub* rec);
	void insertRst(ListWznmQStbSubMNStub& rst);
	void updateRec(WznmQStbSubMNStub* rec);
	void updateRst(ListWznmQStbSubMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbSubMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbSubMNStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQStbSubMNStub: C++ wrapper for table TblWznmQStbSubMNStub (PgSQL database)
	*/
class PgTblWznmQStbSubMNStub : public TblWznmQStbSubMNStub, public Sbecore::PgTable {

public:
	PgTblWznmQStbSubMNStub();
	~PgTblWznmQStbSubMNStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQStbSubMNStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQStbSubMNStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQStbSubMNStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQStbSubMNStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbSubMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbSubMNStub& rst);

	Sbecore::ubigint insertRec(WznmQStbSubMNStub* rec);
	void insertRst(ListWznmQStbSubMNStub& rst);
	void updateRec(WznmQStbSubMNStub* rec);
	void updateRst(ListWznmQStbSubMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbSubMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbSubMNStub& rst);
};
#endif

#endif
