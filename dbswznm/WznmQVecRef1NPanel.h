/**
	* \file WznmQVecRef1NPanel.h
	* Dbs and XML wrapper for table TblWznmQVecRef1NPanel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECREF1NPANEL_H
#define WZNMQVECREF1NPANEL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecRef1NPanel: record of TblWznmQVecRef1NPanel
	*/
class WznmQVecRef1NPanel {

public:
	WznmQVecRef1NPanel(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVecRef1NPanel: recordset of TblWznmQVecRef1NPanel
	*/
class ListWznmQVecRef1NPanel {

public:
	ListWznmQVecRef1NPanel();
	ListWznmQVecRef1NPanel(const ListWznmQVecRef1NPanel& src);
	~ListWznmQVecRef1NPanel();

	void clear();
	unsigned int size() const;
	void append(WznmQVecRef1NPanel* rec);

	ListWznmQVecRef1NPanel& operator=(const ListWznmQVecRef1NPanel& src);

public:
	std::vector<WznmQVecRef1NPanel*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecRef1NPanel: C++ wrapper for table TblWznmQVecRef1NPanel
	*/
class TblWznmQVecRef1NPanel {

public:
	TblWznmQVecRef1NPanel();
	virtual ~TblWznmQVecRef1NPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecRef1NPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecRef1NPanel* rec);
	Sbecore::ubigint insertNewRec(WznmQVecRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecRef1NPanel& rst, WznmQVecRef1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVecRef1NPanel& rst);
	virtual void updateRec(WznmQVecRef1NPanel* rec);
	virtual void updateRst(ListWznmQVecRef1NPanel& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecRef1NPanel** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecRef1NPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecRef1NPanel: C++ wrapper for table TblWznmQVecRef1NPanel (MySQL database)
	*/
class MyTblWznmQVecRef1NPanel : public TblWznmQVecRef1NPanel, public Sbecore::MyTable {

public:
	MyTblWznmQVecRef1NPanel();
	~MyTblWznmQVecRef1NPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQVecRef1NPanel* rec);
	void insertRst(ListWznmQVecRef1NPanel& rst);
	void updateRec(WznmQVecRef1NPanel* rec);
	void updateRst(ListWznmQVecRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecRef1NPanel& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecRef1NPanel: C++ wrapper for table TblWznmQVecRef1NPanel (PgSQL database)
	*/
class PgTblWznmQVecRef1NPanel : public TblWznmQVecRef1NPanel, public Sbecore::PgTable {

public:
	PgTblWznmQVecRef1NPanel();
	~PgTblWznmQVecRef1NPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecRef1NPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecRef1NPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecRef1NPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecRef1NPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecRef1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecRef1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQVecRef1NPanel* rec);
	void insertRst(ListWznmQVecRef1NPanel& rst);
	void updateRec(WznmQVecRef1NPanel* rec);
	void updateRst(ListWznmQVecRef1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecRef1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecRef1NPanel& rst);
};
#endif

#endif
