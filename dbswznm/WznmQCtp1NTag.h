/**
	* \file WznmQCtp1NTag.h
	* Dbs and XML wrapper for table TblWznmQCtp1NTag (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCTP1NTAG_H
#define WZNMQCTP1NTAG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCtp1NTag: record of TblWznmQCtp1NTag
	*/
class WznmQCtp1NTag {

public:
	WznmQCtp1NTag(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQCtp1NTag: recordset of TblWznmQCtp1NTag
	*/
class ListWznmQCtp1NTag {

public:
	ListWznmQCtp1NTag();
	ListWznmQCtp1NTag(const ListWznmQCtp1NTag& src);
	~ListWznmQCtp1NTag();

	void clear();
	unsigned int size() const;
	void append(WznmQCtp1NTag* rec);

	ListWznmQCtp1NTag& operator=(const ListWznmQCtp1NTag& src);

public:
	std::vector<WznmQCtp1NTag*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCtp1NTag: C++ wrapper for table TblWznmQCtp1NTag
	*/
class TblWznmQCtp1NTag {

public:
	TblWznmQCtp1NTag();
	virtual ~TblWznmQCtp1NTag();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCtp1NTag** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtp1NTag& rst);

	virtual Sbecore::ubigint insertRec(WznmQCtp1NTag* rec);
	Sbecore::ubigint insertNewRec(WznmQCtp1NTag** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCtp1NTag& rst, WznmQCtp1NTag** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQCtp1NTag& rst);
	virtual void updateRec(WznmQCtp1NTag* rec);
	virtual void updateRst(ListWznmQCtp1NTag& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCtp1NTag** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtp1NTag& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCtp1NTag: C++ wrapper for table TblWznmQCtp1NTag (MySQL database)
	*/
class MyTblWznmQCtp1NTag : public TblWznmQCtp1NTag, public Sbecore::MyTable {

public:
	MyTblWznmQCtp1NTag();
	~MyTblWznmQCtp1NTag();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtp1NTag** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtp1NTag& rst);

	Sbecore::ubigint insertRec(WznmQCtp1NTag* rec);
	void insertRst(ListWznmQCtp1NTag& rst);
	void updateRec(WznmQCtp1NTag* rec);
	void updateRst(ListWznmQCtp1NTag& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtp1NTag** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtp1NTag& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCtp1NTag: C++ wrapper for table TblWznmQCtp1NTag (PgSQL database)
	*/
class PgTblWznmQCtp1NTag : public TblWznmQCtp1NTag, public Sbecore::PgTable {

public:
	PgTblWznmQCtp1NTag();
	~PgTblWznmQCtp1NTag();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCtp1NTag** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCtp1NTag& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCtp1NTag** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCtp1NTag& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtp1NTag** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtp1NTag& rst);

	Sbecore::ubigint insertRec(WznmQCtp1NTag* rec);
	void insertRst(ListWznmQCtp1NTag& rst);
	void updateRec(WznmQCtp1NTag* rec);
	void updateRst(ListWznmQCtp1NTag& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtp1NTag** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtp1NTag& rst);
};
#endif

#endif

