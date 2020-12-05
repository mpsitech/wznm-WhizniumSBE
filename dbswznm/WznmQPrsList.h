/**
	* \file WznmQPrsList.h
	* Dbs and XML wrapper for table TblWznmQPrsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRSLIST_H
#define WZNMQPRSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrsList: record of TblWznmQPrsList
	*/
class WznmQPrsList {

public:
	WznmQPrsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	Sbecore::uint ixVSex;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPrsList: recordset of TblWznmQPrsList
	*/
class ListWznmQPrsList {

public:
	ListWznmQPrsList();
	ListWznmQPrsList(const ListWznmQPrsList& src);
	~ListWznmQPrsList();

	void clear();
	unsigned int size() const;
	void append(WznmQPrsList* rec);

	ListWznmQPrsList& operator=(const ListWznmQPrsList& src);

public:
	std::vector<WznmQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrsList: C++ wrapper for table TblWznmQPrsList
	*/
class TblWznmQPrsList {

public:
	TblWznmQPrsList();
	virtual ~TblWznmQPrsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsList& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrsList* rec);
	Sbecore::ubigint insertNewRec(WznmQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrsList& rst, WznmQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	virtual void insertRst(ListWznmQPrsList& rst);
	virtual void updateRec(WznmQPrsList* rec);
	virtual void updateRst(ListWznmQPrsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrsList: C++ wrapper for table TblWznmQPrsList (MySQL database)
	*/
class MyTblWznmQPrsList : public TblWznmQPrsList, public Sbecore::MyTable {

public:
	MyTblWznmQPrsList();
	~MyTblWznmQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsList& rst);

	Sbecore::ubigint insertRec(WznmQPrsList* rec);
	void insertRst(ListWznmQPrsList& rst);
	void updateRec(WznmQPrsList* rec);
	void updateRst(ListWznmQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrsList: C++ wrapper for table TblWznmQPrsList (PgSQL database)
	*/
class PgTblWznmQPrsList : public TblWznmQPrsList, public Sbecore::PgTable {

public:
	PgTblWznmQPrsList();
	~PgTblWznmQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsList& rst);

	Sbecore::ubigint insertRec(WznmQPrsList* rec);
	void insertRst(ListWznmQPrsList& rst);
	void updateRec(WznmQPrsList* rec);
	void updateRst(ListWznmQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsList& rst);
};
#endif

#endif

