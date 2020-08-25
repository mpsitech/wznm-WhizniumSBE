/**
	* \file WznmQCal1NSensitivity.h
	* Dbs and XML wrapper for table TblWznmQCal1NSensitivity (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCAL1NSENSITIVITY_H
#define WZNMQCAL1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCal1NSensitivity: record of TblWznmQCal1NSensitivity
	*/
class WznmQCal1NSensitivity {

public:
	WznmQCal1NSensitivity(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQCal1NSensitivity: recordset of TblWznmQCal1NSensitivity
	*/
class ListWznmQCal1NSensitivity {

public:
	ListWznmQCal1NSensitivity();
	ListWznmQCal1NSensitivity(const ListWznmQCal1NSensitivity& src);
	~ListWznmQCal1NSensitivity();

	void clear();
	unsigned int size() const;
	void append(WznmQCal1NSensitivity* rec);

	ListWznmQCal1NSensitivity& operator=(const ListWznmQCal1NSensitivity& src);

public:
	std::vector<WznmQCal1NSensitivity*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCal1NSensitivity: C++ wrapper for table TblWznmQCal1NSensitivity
	*/
class TblWznmQCal1NSensitivity {

public:
	TblWznmQCal1NSensitivity();
	virtual ~TblWznmQCal1NSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCal1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCal1NSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WznmQCal1NSensitivity* rec);
	Sbecore::ubigint insertNewRec(WznmQCal1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCal1NSensitivity& rst, WznmQCal1NSensitivity** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQCal1NSensitivity& rst);
	virtual void updateRec(WznmQCal1NSensitivity* rec);
	virtual void updateRst(ListWznmQCal1NSensitivity& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCal1NSensitivity** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCal1NSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCal1NSensitivity: C++ wrapper for table TblWznmQCal1NSensitivity (MySQL database)
	*/
class MyTblWznmQCal1NSensitivity : public TblWznmQCal1NSensitivity, public Sbecore::MyTable {

public:
	MyTblWznmQCal1NSensitivity();
	~MyTblWznmQCal1NSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCal1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCal1NSensitivity& rst);

	Sbecore::ubigint insertRec(WznmQCal1NSensitivity* rec);
	void insertRst(ListWznmQCal1NSensitivity& rst);
	void updateRec(WznmQCal1NSensitivity* rec);
	void updateRst(ListWznmQCal1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCal1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCal1NSensitivity& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCal1NSensitivity: C++ wrapper for table TblWznmQCal1NSensitivity (PgSQL database)
	*/
class PgTblWznmQCal1NSensitivity : public TblWznmQCal1NSensitivity, public Sbecore::PgTable {

public:
	PgTblWznmQCal1NSensitivity();
	~PgTblWznmQCal1NSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCal1NSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCal1NSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCal1NSensitivity** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCal1NSensitivity& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCal1NSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCal1NSensitivity& rst);

	Sbecore::ubigint insertRec(WznmQCal1NSensitivity* rec);
	void insertRst(ListWznmQCal1NSensitivity& rst);
	void updateRec(WznmQCal1NSensitivity* rec);
	void updateRst(ListWznmQCal1NSensitivity& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCal1NSensitivity** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCal1NSensitivity& rst);
};
#endif

#endif

