/**
	* \file WznmQOpkMNComponent.h
	* Dbs and XML wrapper for table TblWznmQOpkMNComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKMNCOMPONENT_H
#define WZNMQOPKMNCOMPONENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkMNComponent: record of TblWznmQOpkMNComponent
	*/
class WznmQOpkMNComponent {

public:
	WznmQOpkMNComponent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQOpkMNComponent: recordset of TblWznmQOpkMNComponent
	*/
class ListWznmQOpkMNComponent {

public:
	ListWznmQOpkMNComponent();
	ListWznmQOpkMNComponent(const ListWznmQOpkMNComponent& src);
	~ListWznmQOpkMNComponent();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkMNComponent* rec);

	ListWznmQOpkMNComponent& operator=(const ListWznmQOpkMNComponent& src);

public:
	std::vector<WznmQOpkMNComponent*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkMNComponent: C++ wrapper for table TblWznmQOpkMNComponent
	*/
class TblWznmQOpkMNComponent {

public:
	TblWznmQOpkMNComponent();
	virtual ~TblWznmQOpkMNComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNComponent& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkMNComponent* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkMNComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkMNComponent& rst, WznmQOpkMNComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQOpkMNComponent& rst);
	virtual void updateRec(WznmQOpkMNComponent* rec);
	virtual void updateRst(ListWznmQOpkMNComponent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNComponent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkMNComponent: C++ wrapper for table TblWznmQOpkMNComponent (MySQL database)
	*/
class MyTblWznmQOpkMNComponent : public TblWznmQOpkMNComponent, public Sbecore::MyTable {

public:
	MyTblWznmQOpkMNComponent();
	~MyTblWznmQOpkMNComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNComponent& rst);

	Sbecore::ubigint insertRec(WznmQOpkMNComponent* rec);
	void insertRst(ListWznmQOpkMNComponent& rst);
	void updateRec(WznmQOpkMNComponent* rec);
	void updateRst(ListWznmQOpkMNComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNComponent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkMNComponent: C++ wrapper for table TblWznmQOpkMNComponent (PgSQL database)
	*/
class PgTblWznmQOpkMNComponent : public TblWznmQOpkMNComponent, public Sbecore::PgTable {

public:
	PgTblWznmQOpkMNComponent();
	~PgTblWznmQOpkMNComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkMNComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkMNComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkMNComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkMNComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNComponent& rst);

	Sbecore::ubigint insertRec(WznmQOpkMNComponent* rec);
	void insertRst(ListWznmQOpkMNComponent& rst);
	void updateRec(WznmQOpkMNComponent* rec);
	void updateRst(ListWznmQOpkMNComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNComponent& rst);
};
#endif

#endif

