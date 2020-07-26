/**
	* \file WznmQLibMNComponent.h
	* Dbs and XML wrapper for table TblWznmQLibMNComponent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQLIBMNCOMPONENT_H
#define WZNMQLIBMNCOMPONENT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLibMNComponent: record of TblWznmQLibMNComponent
	*/
class WznmQLibMNComponent {

public:
	WznmQLibMNComponent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQLibMNComponent: recordset of TblWznmQLibMNComponent
	*/
class ListWznmQLibMNComponent {

public:
	ListWznmQLibMNComponent();
	ListWznmQLibMNComponent(const ListWznmQLibMNComponent& src);
	~ListWznmQLibMNComponent();

	void clear();
	unsigned int size() const;
	void append(WznmQLibMNComponent* rec);

	ListWznmQLibMNComponent& operator=(const ListWznmQLibMNComponent& src);

public:
	std::vector<WznmQLibMNComponent*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLibMNComponent: C++ wrapper for table TblWznmQLibMNComponent
	*/
class TblWznmQLibMNComponent {

public:
	TblWznmQLibMNComponent();
	virtual ~TblWznmQLibMNComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLibMNComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibMNComponent& rst);

	virtual Sbecore::ubigint insertRec(WznmQLibMNComponent* rec);
	Sbecore::ubigint insertNewRec(WznmQLibMNComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQLibMNComponent& rst, WznmQLibMNComponent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQLibMNComponent& rst);
	virtual void updateRec(WznmQLibMNComponent* rec);
	virtual void updateRst(ListWznmQLibMNComponent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLibMNComponent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibMNComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLibMNComponent: C++ wrapper for table TblWznmQLibMNComponent (MySQL database)
	*/
class MyTblWznmQLibMNComponent : public TblWznmQLibMNComponent, public Sbecore::MyTable {

public:
	MyTblWznmQLibMNComponent();
	~MyTblWznmQLibMNComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibMNComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibMNComponent& rst);

	Sbecore::ubigint insertRec(WznmQLibMNComponent* rec);
	void insertRst(ListWznmQLibMNComponent& rst);
	void updateRec(WznmQLibMNComponent* rec);
	void updateRst(ListWznmQLibMNComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibMNComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibMNComponent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLibMNComponent: C++ wrapper for table TblWznmQLibMNComponent (PgSQL database)
	*/
class PgTblWznmQLibMNComponent : public TblWznmQLibMNComponent, public Sbecore::PgTable {

public:
	PgTblWznmQLibMNComponent();
	~PgTblWznmQLibMNComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLibMNComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLibMNComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLibMNComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLibMNComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibMNComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibMNComponent& rst);

	Sbecore::ubigint insertRec(WznmQLibMNComponent* rec);
	void insertRst(ListWznmQLibMNComponent& rst);
	void updateRec(WznmQLibMNComponent* rec);
	void updateRst(ListWznmQLibMNComponent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibMNComponent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibMNComponent& rst);
};
#endif

#endif

