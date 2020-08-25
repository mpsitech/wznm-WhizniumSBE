/**
	* \file WznmQMdlRef1NPanel.h
	* Dbs and XML wrapper for table TblWznmQMdlRef1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMDLREF1NPANEL_H
#define WZNMQMDLREF1NPANEL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMdlRef1NPanel: record of TblWznmQMdlRef1NPanel
	*/
class WznmQMdlRef1NPanel {

public:
	WznmQMdlRef1NPanel(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQMdlRef1NPanel: recordset of TblWznmQMdlRef1NPanel
	*/
class ListWznmQMdlRef1NPanel {

public:
	ListWznmQMdlRef1NPanel();
	ListWznmQMdlRef1NPanel(const ListWznmQMdlRef1NPanel& src);
	~ListWznmQMdlRef1NPanel();

	void clear();
	unsigned int size() const;
	void append(WznmQMdlRef1NPanel* rec);

	ListWznmQMdlRef1NPanel& operator=(const ListWznmQMdlRef1NPanel& src);

public:
	std::vector<WznmQMdlRef1NPanel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMdlRef1NPanel: C++ wrapper for table TblWznmQMdlRef1NPanel
	*/
class TblWznmQMdlRef1NPanel {

public:
	TblWznmQMdlRef1NPanel();
	virtual ~TblWznmQMdlRef1NPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMdlRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlRef1NPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmQMdlRef1NPanel* rec);
	Sbecore::ubigint insertNewRec(WznmQMdlRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMdlRef1NPanel& rst, WznmQMdlRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQMdlRef1NPanel& rst);
	virtual void updateRec(WznmQMdlRef1NPanel* rec);
	virtual void updateRst(ListWznmQMdlRef1NPanel& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlRef1NPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMdlRef1NPanel: C++ wrapper for table TblWznmQMdlRef1NPanel (MySQL database)
	*/
class MyTblWznmQMdlRef1NPanel : public TblWznmQMdlRef1NPanel, public Sbecore::MyTable {

public:
	MyTblWznmQMdlRef1NPanel();
	~MyTblWznmQMdlRef1NPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMdlRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQMdlRef1NPanel* rec);
	void insertRst(ListWznmQMdlRef1NPanel& rst);
	void updateRec(WznmQMdlRef1NPanel* rec);
	void updateRst(ListWznmQMdlRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlRef1NPanel& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMdlRef1NPanel: C++ wrapper for table TblWznmQMdlRef1NPanel (PgSQL database)
	*/
class PgTblWznmQMdlRef1NPanel : public TblWznmQMdlRef1NPanel, public Sbecore::PgTable {

public:
	PgTblWznmQMdlRef1NPanel();
	~PgTblWznmQMdlRef1NPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMdlRef1NPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMdlRef1NPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMdlRef1NPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMdlRef1NPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMdlRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQMdlRef1NPanel* rec);
	void insertRst(ListWznmQMdlRef1NPanel& rst);
	void updateRec(WznmQMdlRef1NPanel* rec);
	void updateRst(ListWznmQMdlRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlRef1NPanel& rst);
};
#endif

#endif

