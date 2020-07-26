/**
	* \file WznmQRelRef1NPanel.h
	* Dbs and XML wrapper for table TblWznmQRelRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQRELREF1NPANEL_H
#define WZNMQRELREF1NPANEL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRelRef1NPanel: record of TblWznmQRelRef1NPanel
	*/
class WznmQRelRef1NPanel {

public:
	WznmQRelRef1NPanel(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQRelRef1NPanel: recordset of TblWznmQRelRef1NPanel
	*/
class ListWznmQRelRef1NPanel {

public:
	ListWznmQRelRef1NPanel();
	ListWznmQRelRef1NPanel(const ListWznmQRelRef1NPanel& src);
	~ListWznmQRelRef1NPanel();

	void clear();
	unsigned int size() const;
	void append(WznmQRelRef1NPanel* rec);

	ListWznmQRelRef1NPanel& operator=(const ListWznmQRelRef1NPanel& src);

public:
	std::vector<WznmQRelRef1NPanel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRelRef1NPanel: C++ wrapper for table TblWznmQRelRef1NPanel
	*/
class TblWznmQRelRef1NPanel {

public:
	TblWznmQRelRef1NPanel();
	virtual ~TblWznmQRelRef1NPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmQRelRef1NPanel* rec);
	Sbecore::ubigint insertNewRec(WznmQRelRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRelRef1NPanel& rst, WznmQRelRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRelRef1NPanel& rst);
	virtual void updateRec(WznmQRelRef1NPanel* rec);
	virtual void updateRst(ListWznmQRelRef1NPanel& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRelRef1NPanel: C++ wrapper for table TblWznmQRelRef1NPanel (MySQL database)
	*/
class MyTblWznmQRelRef1NPanel : public TblWznmQRelRef1NPanel, public Sbecore::MyTable {

public:
	MyTblWznmQRelRef1NPanel();
	~MyTblWznmQRelRef1NPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQRelRef1NPanel* rec);
	void insertRst(ListWznmQRelRef1NPanel& rst);
	void updateRec(WznmQRelRef1NPanel* rec);
	void updateRst(ListWznmQRelRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NPanel& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRelRef1NPanel: C++ wrapper for table TblWznmQRelRef1NPanel (PgSQL database)
	*/
class PgTblWznmQRelRef1NPanel : public TblWznmQRelRef1NPanel, public Sbecore::PgTable {

public:
	PgTblWznmQRelRef1NPanel();
	~PgTblWznmQRelRef1NPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRelRef1NPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRelRef1NPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRelRef1NPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRelRef1NPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQRelRef1NPanel* rec);
	void insertRst(ListWznmQRelRef1NPanel& rst);
	void updateRec(WznmQRelRef1NPanel* rec);
	void updateRst(ListWznmQRelRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NPanel& rst);
};
#endif

#endif

