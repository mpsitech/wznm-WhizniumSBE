/**
	* \file WznmQVer1NComponent.h
	* Dbs and XML wrapper for table TblWznmQVer1NComponent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQVER1NCOMPONENT_H
#define WZNMQVER1NCOMPONENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NComponent: record of TblWznmQVer1NComponent
	*/
class WznmQVer1NComponent {

public:
	WznmQVer1NComponent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NComponent: recordset of TblWznmQVer1NComponent
	*/
class ListWznmQVer1NComponent {

public:
	ListWznmQVer1NComponent();
	ListWznmQVer1NComponent(const ListWznmQVer1NComponent& src);
	~ListWznmQVer1NComponent();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NComponent* rec);

	ListWznmQVer1NComponent& operator=(const ListWznmQVer1NComponent& src);

public:
	std::vector<WznmQVer1NComponent*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NComponent: C++ wrapper for table TblWznmQVer1NComponent
	*/
class TblWznmQVer1NComponent {

public:
	TblWznmQVer1NComponent();
	virtual ~TblWznmQVer1NComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NComponent& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NComponent* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NComponent& rst, WznmQVer1NComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NComponent& rst);
	virtual void updateRec(WznmQVer1NComponent* rec);
	virtual void updateRst(ListWznmQVer1NComponent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NComponent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NComponent: C++ wrapper for table TblWznmQVer1NComponent (MySQL database)
	*/
class MyTblWznmQVer1NComponent : public TblWznmQVer1NComponent, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NComponent();
	~MyTblWznmQVer1NComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NComponent& rst);

	Sbecore::ubigint insertRec(WznmQVer1NComponent* rec);
	void insertRst(ListWznmQVer1NComponent& rst);
	void updateRec(WznmQVer1NComponent* rec);
	void updateRst(ListWznmQVer1NComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NComponent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NComponent: C++ wrapper for table TblWznmQVer1NComponent (PgSQL database)
	*/
class PgTblWznmQVer1NComponent : public TblWznmQVer1NComponent, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NComponent();
	~PgTblWznmQVer1NComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NComponent& rst);

	Sbecore::ubigint insertRec(WznmQVer1NComponent* rec);
	void insertRst(ListWznmQVer1NComponent& rst);
	void updateRec(WznmQVer1NComponent* rec);
	void updateRst(ListWznmQVer1NComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NComponent& rst);
};
#endif

#endif

