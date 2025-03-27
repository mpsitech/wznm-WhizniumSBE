/**
	* \file WznmQSht1NBox.h
	* Dbs and XML wrapper for table TblWznmQSht1NBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQSHT1NBOX_H
#define WZNMQSHT1NBOX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSht1NBox: record of TblWznmQSht1NBox
	*/
class WznmQSht1NBox {

public:
	WznmQSht1NBox(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQSht1NBox: recordset of TblWznmQSht1NBox
	*/
class ListWznmQSht1NBox {

public:
	ListWznmQSht1NBox();
	ListWznmQSht1NBox(const ListWznmQSht1NBox& src);
	~ListWznmQSht1NBox();

	void clear();
	unsigned int size() const;
	void append(WznmQSht1NBox* rec);

	ListWznmQSht1NBox& operator=(const ListWznmQSht1NBox& src);

public:
	std::vector<WznmQSht1NBox*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSht1NBox: C++ wrapper for table TblWznmQSht1NBox
	*/
class TblWznmQSht1NBox {

public:
	TblWznmQSht1NBox();
	virtual ~TblWznmQSht1NBox();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSht1NBox** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSht1NBox& rst);

	virtual Sbecore::ubigint insertRec(WznmQSht1NBox* rec);
	Sbecore::ubigint insertNewRec(WznmQSht1NBox** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSht1NBox& rst, WznmQSht1NBox** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSht1NBox& rst);
	virtual void updateRec(WznmQSht1NBox* rec);
	virtual void updateRst(ListWznmQSht1NBox& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSht1NBox** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSht1NBox& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSht1NBox: C++ wrapper for table TblWznmQSht1NBox (MySQL database)
	*/
class MyTblWznmQSht1NBox : public TblWznmQSht1NBox, public Sbecore::MyTable {

public:
	MyTblWznmQSht1NBox();
	~MyTblWznmQSht1NBox();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSht1NBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSht1NBox& rst);

	Sbecore::ubigint insertRec(WznmQSht1NBox* rec);
	void insertRst(ListWznmQSht1NBox& rst);
	void updateRec(WznmQSht1NBox* rec);
	void updateRst(ListWznmQSht1NBox& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSht1NBox** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSht1NBox& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSht1NBox: C++ wrapper for table TblWznmQSht1NBox (PgSQL database)
	*/
class PgTblWznmQSht1NBox : public TblWznmQSht1NBox, public Sbecore::PgTable {

public:
	PgTblWznmQSht1NBox();
	~PgTblWznmQSht1NBox();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSht1NBox** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSht1NBox& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSht1NBox** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSht1NBox& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSht1NBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSht1NBox& rst);

	Sbecore::ubigint insertRec(WznmQSht1NBox* rec);
	void insertRst(ListWznmQSht1NBox& rst);
	void updateRec(WznmQSht1NBox* rec);
	void updateRst(ListWznmQSht1NBox& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSht1NBox** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSht1NBox& rst);
};
#endif

#endif
