/**
	* \file WznmQTblRef1NPanel.h
	* Dbs and XML wrapper for table TblWznmQTblRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTBLREF1NPANEL_H
#define WZNMQTBLREF1NPANEL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblRef1NPanel: record of TblWznmQTblRef1NPanel
	*/
class WznmQTblRef1NPanel {

public:
	WznmQTblRef1NPanel(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblRef1NPanel: recordset of TblWznmQTblRef1NPanel
	*/
class ListWznmQTblRef1NPanel {

public:
	ListWznmQTblRef1NPanel();
	ListWznmQTblRef1NPanel(const ListWznmQTblRef1NPanel& src);
	~ListWznmQTblRef1NPanel();

	void clear();
	unsigned int size() const;
	void append(WznmQTblRef1NPanel* rec);

	ListWznmQTblRef1NPanel& operator=(const ListWznmQTblRef1NPanel& src);

public:
	std::vector<WznmQTblRef1NPanel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblRef1NPanel: C++ wrapper for table TblWznmQTblRef1NPanel
	*/
class TblWznmQTblRef1NPanel {

public:
	TblWznmQTblRef1NPanel();
	virtual ~TblWznmQTblRef1NPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblRef1NPanel* rec);
	Sbecore::ubigint insertNewRec(WznmQTblRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblRef1NPanel& rst, WznmQTblRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblRef1NPanel& rst);
	virtual void updateRec(WznmQTblRef1NPanel* rec);
	virtual void updateRst(ListWznmQTblRef1NPanel& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblRef1NPanel: C++ wrapper for table TblWznmQTblRef1NPanel (MySQL database)
	*/
class MyTblWznmQTblRef1NPanel : public TblWznmQTblRef1NPanel, public Sbecore::MyTable {

public:
	MyTblWznmQTblRef1NPanel();
	~MyTblWznmQTblRef1NPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NPanel* rec);
	void insertRst(ListWznmQTblRef1NPanel& rst);
	void updateRec(WznmQTblRef1NPanel* rec);
	void updateRst(ListWznmQTblRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NPanel& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblRef1NPanel: C++ wrapper for table TblWznmQTblRef1NPanel (PgSQL database)
	*/
class PgTblWznmQTblRef1NPanel : public TblWznmQTblRef1NPanel, public Sbecore::PgTable {

public:
	PgTblWznmQTblRef1NPanel();
	~PgTblWznmQTblRef1NPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblRef1NPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblRef1NPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblRef1NPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblRef1NPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NPanel* rec);
	void insertRst(ListWznmQTblRef1NPanel& rst);
	void updateRec(WznmQTblRef1NPanel* rec);
	void updateRst(ListWznmQTblRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NPanel& rst);
};
#endif

#endif

