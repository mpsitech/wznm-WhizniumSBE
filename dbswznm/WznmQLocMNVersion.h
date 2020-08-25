/**
	* \file WznmQLocMNVersion.h
	* Dbs and XML wrapper for table TblWznmQLocMNVersion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQLOCMNVERSION_H
#define WZNMQLOCMNVERSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLocMNVersion: record of TblWznmQLocMNVersion
	*/
class WznmQLocMNVersion {

public:
	WznmQLocMNVersion(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQLocMNVersion: recordset of TblWznmQLocMNVersion
	*/
class ListWznmQLocMNVersion {

public:
	ListWznmQLocMNVersion();
	ListWznmQLocMNVersion(const ListWznmQLocMNVersion& src);
	~ListWznmQLocMNVersion();

	void clear();
	unsigned int size() const;
	void append(WznmQLocMNVersion* rec);

	ListWznmQLocMNVersion& operator=(const ListWznmQLocMNVersion& src);

public:
	std::vector<WznmQLocMNVersion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLocMNVersion: C++ wrapper for table TblWznmQLocMNVersion
	*/
class TblWznmQLocMNVersion {

public:
	TblWznmQLocMNVersion();
	virtual ~TblWznmQLocMNVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLocMNVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLocMNVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmQLocMNVersion* rec);
	Sbecore::ubigint insertNewRec(WznmQLocMNVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQLocMNVersion& rst, WznmQLocMNVersion** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQLocMNVersion& rst);
	virtual void updateRec(WznmQLocMNVersion* rec);
	virtual void updateRst(ListWznmQLocMNVersion& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLocMNVersion** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLocMNVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLocMNVersion: C++ wrapper for table TblWznmQLocMNVersion (MySQL database)
	*/
class MyTblWznmQLocMNVersion : public TblWznmQLocMNVersion, public Sbecore::MyTable {

public:
	MyTblWznmQLocMNVersion();
	~MyTblWznmQLocMNVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLocMNVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLocMNVersion& rst);

	Sbecore::ubigint insertRec(WznmQLocMNVersion* rec);
	void insertRst(ListWznmQLocMNVersion& rst);
	void updateRec(WznmQLocMNVersion* rec);
	void updateRst(ListWznmQLocMNVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLocMNVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLocMNVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLocMNVersion: C++ wrapper for table TblWznmQLocMNVersion (PgSQL database)
	*/
class PgTblWznmQLocMNVersion : public TblWznmQLocMNVersion, public Sbecore::PgTable {

public:
	PgTblWznmQLocMNVersion();
	~PgTblWznmQLocMNVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLocMNVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLocMNVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLocMNVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLocMNVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLocMNVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLocMNVersion& rst);

	Sbecore::ubigint insertRec(WznmQLocMNVersion* rec);
	void insertRst(ListWznmQLocMNVersion& rst);
	void updateRec(WznmQLocMNVersion* rec);
	void updateRst(ListWznmQLocMNVersion& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLocMNVersion** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLocMNVersion& rst);
};
#endif

#endif

