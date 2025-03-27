/**
	* \file WznmQBoxOrgMNBox.h
	* Dbs and XML wrapper for table TblWznmQBoxOrgMNBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQBOXORGMNBOX_H
#define WZNMQBOXORGMNBOX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBoxOrgMNBox: record of TblWznmQBoxOrgMNBox
	*/
class WznmQBoxOrgMNBox {

public:
	WznmQBoxOrgMNBox(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::utinyint orgClk;
	Sbecore::utinyint dstClk;
	Sbecore::utinyint Weight;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQBoxOrgMNBox: recordset of TblWznmQBoxOrgMNBox
	*/
class ListWznmQBoxOrgMNBox {

public:
	ListWznmQBoxOrgMNBox();
	ListWznmQBoxOrgMNBox(const ListWznmQBoxOrgMNBox& src);
	~ListWznmQBoxOrgMNBox();

	void clear();
	unsigned int size() const;
	void append(WznmQBoxOrgMNBox* rec);

	ListWznmQBoxOrgMNBox& operator=(const ListWznmQBoxOrgMNBox& src);

public:
	std::vector<WznmQBoxOrgMNBox*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBoxOrgMNBox: C++ wrapper for table TblWznmQBoxOrgMNBox
	*/
class TblWznmQBoxOrgMNBox {

public:
	TblWznmQBoxOrgMNBox();
	virtual ~TblWznmQBoxOrgMNBox();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBoxOrgMNBox** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxOrgMNBox& rst);

	virtual Sbecore::ubigint insertRec(WznmQBoxOrgMNBox* rec);
	Sbecore::ubigint insertNewRec(WznmQBoxOrgMNBox** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQBoxOrgMNBox& rst, WznmQBoxOrgMNBox** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
	virtual void insertRst(ListWznmQBoxOrgMNBox& rst);
	virtual void updateRec(WznmQBoxOrgMNBox* rec);
	virtual void updateRst(ListWznmQBoxOrgMNBox& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxOrgMNBox** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxOrgMNBox& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBoxOrgMNBox: C++ wrapper for table TblWznmQBoxOrgMNBox (MySQL database)
	*/
class MyTblWznmQBoxOrgMNBox : public TblWznmQBoxOrgMNBox, public Sbecore::MyTable {

public:
	MyTblWznmQBoxOrgMNBox();
	~MyTblWznmQBoxOrgMNBox();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBoxOrgMNBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxOrgMNBox& rst);

	Sbecore::ubigint insertRec(WznmQBoxOrgMNBox* rec);
	void insertRst(ListWznmQBoxOrgMNBox& rst);
	void updateRec(WznmQBoxOrgMNBox* rec);
	void updateRst(ListWznmQBoxOrgMNBox& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxOrgMNBox** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxOrgMNBox& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBoxOrgMNBox: C++ wrapper for table TblWznmQBoxOrgMNBox (PgSQL database)
	*/
class PgTblWznmQBoxOrgMNBox : public TblWznmQBoxOrgMNBox, public Sbecore::PgTable {

public:
	PgTblWznmQBoxOrgMNBox();
	~PgTblWznmQBoxOrgMNBox();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBoxOrgMNBox** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBoxOrgMNBox& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBoxOrgMNBox** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBoxOrgMNBox& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBoxOrgMNBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxOrgMNBox& rst);

	Sbecore::ubigint insertRec(WznmQBoxOrgMNBox* rec);
	void insertRst(ListWznmQBoxOrgMNBox& rst);
	void updateRec(WznmQBoxOrgMNBox* rec);
	void updateRst(ListWznmQBoxOrgMNBox& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxOrgMNBox** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxOrgMNBox& rst);
};
#endif

#endif
