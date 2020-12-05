/**
	* \file WznmQSge1NSensitivity.h
	* Dbs and XML wrapper for table TblWznmQSge1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSGE1NSENSITIVITY_H
#define WZNMQSGE1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSge1NSensitivity: record of TblWznmQSge1NSensitivity
	*/
class WznmQSge1NSensitivity {

public:
	WznmQSge1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSge1NSensitivity: recordset of TblWznmQSge1NSensitivity
	*/
class ListWznmQSge1NSensitivity {

public:
	ListWznmQSge1NSensitivity();
	ListWznmQSge1NSensitivity(const ListWznmQSge1NSensitivity& src);
	~ListWznmQSge1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WznmQSge1NSensitivity* rec);

	ListWznmQSge1NSensitivity& operator=(const ListWznmQSge1NSensitivity& src);

public:
	std::vector<WznmQSge1NSensitivity*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSge1NSensitivity: C++ wrapper for table TblWznmQSge1NSensitivity
	*/
class TblWznmQSge1NSensitivity {

public:
	TblWznmQSge1NSensitivity();
	virtual ~TblWznmQSge1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSge1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSge1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WznmQSge1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WznmQSge1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSge1NSensitivity& rst, WznmQSge1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSge1NSensitivity& rst);
	virtual void updateRec(WznmQSge1NSensitivity* rec);
	virtual void updateRst(ListWznmQSge1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSge1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSge1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSge1NSensitivity: C++ wrapper for table TblWznmQSge1NSensitivity (MySQL database)
	*/
class MyTblWznmQSge1NSensitivity : public TblWznmQSge1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWznmQSge1NSensitivity();
	~MyTblWznmQSge1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSge1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSge1NSensitivity& rst);

	Sbecore::ubigint insertRec(WznmQSge1NSensitivity* rec);
	void insertRst(ListWznmQSge1NSensitivity& rst);
	void updateRec(WznmQSge1NSensitivity* rec);
	void updateRst(ListWznmQSge1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSge1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSge1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSge1NSensitivity: C++ wrapper for table TblWznmQSge1NSensitivity (PgSQL database)
	*/
class PgTblWznmQSge1NSensitivity : public TblWznmQSge1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWznmQSge1NSensitivity();
	~PgTblWznmQSge1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSge1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSge1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSge1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSge1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSge1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSge1NSensitivity& rst);

	Sbecore::ubigint insertRec(WznmQSge1NSensitivity* rec);
	void insertRst(ListWznmQSge1NSensitivity& rst);
	void updateRec(WznmQSge1NSensitivity* rec);
	void updateRst(ListWznmQSge1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSge1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSge1NSensitivity& rst);
};
#endif

#endif

