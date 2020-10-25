/**
	* \file WznmQQryMNPanel.h
	* Dbs and XML wrapper for table TblWznmQQryMNPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQQRYMNPANEL_H
#define WZNMQQRYMNPANEL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryMNPanel: record of TblWznmQQryMNPanel
	*/
class WznmQQryMNPanel {

public:
	WznmQQryMNPanel(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQQryMNPanel: recordset of TblWznmQQryMNPanel
	*/
class ListWznmQQryMNPanel {

public:
	ListWznmQQryMNPanel();
	ListWznmQQryMNPanel(const ListWznmQQryMNPanel& src);
	~ListWznmQQryMNPanel();

	void clear();
	unsigned int size() const;
	void append(WznmQQryMNPanel* rec);

	ListWznmQQryMNPanel& operator=(const ListWznmQQryMNPanel& src);

public:
	std::vector<WznmQQryMNPanel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryMNPanel: C++ wrapper for table TblWznmQQryMNPanel
	*/
class TblWznmQQryMNPanel {

public:
	TblWznmQQryMNPanel();
	virtual ~TblWznmQQryMNPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryMNPanel* rec);
	Sbecore::ubigint insertNewRec(WznmQQryMNPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryMNPanel& rst, WznmQQryMNPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQQryMNPanel& rst);
	virtual void updateRec(WznmQQryMNPanel* rec);
	virtual void updateRst(ListWznmQQryMNPanel& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNPanel** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryMNPanel: C++ wrapper for table TblWznmQQryMNPanel (MySQL database)
	*/
class MyTblWznmQQryMNPanel : public TblWznmQQryMNPanel, public Sbecore::MyTable {

public:
	MyTblWznmQQryMNPanel();
	~MyTblWznmQQryMNPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNPanel& rst);

	Sbecore::ubigint insertRec(WznmQQryMNPanel* rec);
	void insertRst(ListWznmQQryMNPanel& rst);
	void updateRec(WznmQQryMNPanel* rec);
	void updateRst(ListWznmQQryMNPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNPanel& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryMNPanel: C++ wrapper for table TblWznmQQryMNPanel (PgSQL database)
	*/
class PgTblWznmQQryMNPanel : public TblWznmQQryMNPanel, public Sbecore::PgTable {

public:
	PgTblWznmQQryMNPanel();
	~PgTblWznmQQryMNPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryMNPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryMNPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryMNPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryMNPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNPanel& rst);

	Sbecore::ubigint insertRec(WznmQQryMNPanel* rec);
	void insertRst(ListWznmQQryMNPanel& rst);
	void updateRec(WznmQQryMNPanel* rec);
	void updateRst(ListWznmQQryMNPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNPanel& rst);
};
#endif

#endif

