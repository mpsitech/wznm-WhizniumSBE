/**
	* \file WznmQQryMNDialog.h
	* Dbs and XML wrapper for table TblWznmQQryMNDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYMNDIALOG_H
#define WZNMQQRYMNDIALOG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryMNDialog: record of TblWznmQQryMNDialog
	*/
class WznmQQryMNDialog {

public:
	WznmQQryMNDialog(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQQryMNDialog: recordset of TblWznmQQryMNDialog
	*/
class ListWznmQQryMNDialog {

public:
	ListWznmQQryMNDialog();
	ListWznmQQryMNDialog(const ListWznmQQryMNDialog& src);
	~ListWznmQQryMNDialog();

	void clear();
	unsigned int size() const;
	void append(WznmQQryMNDialog* rec);

	ListWznmQQryMNDialog& operator=(const ListWznmQQryMNDialog& src);

public:
	std::vector<WznmQQryMNDialog*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryMNDialog: C++ wrapper for table TblWznmQQryMNDialog
	*/
class TblWznmQQryMNDialog {

public:
	TblWznmQQryMNDialog();
	virtual ~TblWznmQQryMNDialog();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNDialog** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNDialog& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryMNDialog* rec);
	Sbecore::ubigint insertNewRec(WznmQQryMNDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryMNDialog& rst, WznmQQryMNDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQQryMNDialog& rst);
	virtual void updateRec(WznmQQryMNDialog* rec);
	virtual void updateRst(ListWznmQQryMNDialog& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNDialog** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNDialog& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryMNDialog: C++ wrapper for table TblWznmQQryMNDialog (MySQL database)
	*/
class MyTblWznmQQryMNDialog : public TblWznmQQryMNDialog, public Sbecore::MyTable {

public:
	MyTblWznmQQryMNDialog();
	~MyTblWznmQQryMNDialog();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNDialog& rst);

	Sbecore::ubigint insertRec(WznmQQryMNDialog* rec);
	void insertRst(ListWznmQQryMNDialog& rst);
	void updateRec(WznmQQryMNDialog* rec);
	void updateRst(ListWznmQQryMNDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNDialog& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryMNDialog: C++ wrapper for table TblWznmQQryMNDialog (PgSQL database)
	*/
class PgTblWznmQQryMNDialog : public TblWznmQQryMNDialog, public Sbecore::PgTable {

public:
	PgTblWznmQQryMNDialog();
	~PgTblWznmQQryMNDialog();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryMNDialog** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryMNDialog& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryMNDialog** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryMNDialog& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryMNDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryMNDialog& rst);

	Sbecore::ubigint insertRec(WznmQQryMNDialog* rec);
	void insertRst(ListWznmQQryMNDialog& rst);
	void updateRec(WznmQQryMNDialog* rec);
	void updateRst(ListWznmQQryMNDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryMNDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryMNDialog& rst);
};
#endif

#endif

