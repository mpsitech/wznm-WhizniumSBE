/**
	* \file WznmQJob1NSensitivity.h
	* Dbs and XML wrapper for table TblWznmQJob1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOB1NSENSITIVITY_H
#define WZNMQJOB1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJob1NSensitivity: record of TblWznmQJob1NSensitivity
	*/
class WznmQJob1NSensitivity {

public:
	WznmQJob1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQJob1NSensitivity: recordset of TblWznmQJob1NSensitivity
	*/
class ListWznmQJob1NSensitivity {

public:
	ListWznmQJob1NSensitivity();
	ListWznmQJob1NSensitivity(const ListWznmQJob1NSensitivity& src);
	~ListWznmQJob1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WznmQJob1NSensitivity* rec);

	ListWznmQJob1NSensitivity& operator=(const ListWznmQJob1NSensitivity& src);

public:
	std::vector<WznmQJob1NSensitivity*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJob1NSensitivity: C++ wrapper for table TblWznmQJob1NSensitivity
	*/
class TblWznmQJob1NSensitivity {

public:
	TblWznmQJob1NSensitivity();
	virtual ~TblWznmQJob1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WznmQJob1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WznmQJob1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJob1NSensitivity& rst, WznmQJob1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQJob1NSensitivity& rst);
	virtual void updateRec(WznmQJob1NSensitivity* rec);
	virtual void updateRst(ListWznmQJob1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJob1NSensitivity: C++ wrapper for table TblWznmQJob1NSensitivity (MySQL database)
	*/
class MyTblWznmQJob1NSensitivity : public TblWznmQJob1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWznmQJob1NSensitivity();
	~MyTblWznmQJob1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NSensitivity& rst);

	Sbecore::ubigint insertRec(WznmQJob1NSensitivity* rec);
	void insertRst(ListWznmQJob1NSensitivity& rst);
	void updateRec(WznmQJob1NSensitivity* rec);
	void updateRst(ListWznmQJob1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJob1NSensitivity: C++ wrapper for table TblWznmQJob1NSensitivity (PgSQL database)
	*/
class PgTblWznmQJob1NSensitivity : public TblWznmQJob1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWznmQJob1NSensitivity();
	~PgTblWznmQJob1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJob1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJob1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJob1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJob1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NSensitivity& rst);

	Sbecore::ubigint insertRec(WznmQJob1NSensitivity* rec);
	void insertRst(ListWznmQJob1NSensitivity& rst);
	void updateRec(WznmQJob1NSensitivity* rec);
	void updateRst(ListWznmQJob1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NSensitivity& rst);
};
#endif

#endif

