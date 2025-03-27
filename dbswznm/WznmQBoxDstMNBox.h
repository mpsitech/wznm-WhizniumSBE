/**
	* \file WznmQBoxDstMNBox.h
	* Dbs and XML wrapper for table TblWznmQBoxDstMNBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQBOXDSTMNBOX_H
#define WZNMQBOXDSTMNBOX_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQBoxDstMNBox: record of TblWznmQBoxDstMNBox
	*/
class WznmQBoxDstMNBox {

public:
	WznmQBoxDstMNBox(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);

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
	* ListWznmQBoxDstMNBox: recordset of TblWznmQBoxDstMNBox
	*/
class ListWznmQBoxDstMNBox {

public:
	ListWznmQBoxDstMNBox();
	ListWznmQBoxDstMNBox(const ListWznmQBoxDstMNBox& src);
	~ListWznmQBoxDstMNBox();

	void clear();
	unsigned int size() const;
	void append(WznmQBoxDstMNBox* rec);

	ListWznmQBoxDstMNBox& operator=(const ListWznmQBoxDstMNBox& src);

public:
	std::vector<WznmQBoxDstMNBox*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQBoxDstMNBox: C++ wrapper for table TblWznmQBoxDstMNBox
	*/
class TblWznmQBoxDstMNBox {

public:
	TblWznmQBoxDstMNBox();
	virtual ~TblWznmQBoxDstMNBox();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQBoxDstMNBox** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxDstMNBox& rst);

	virtual Sbecore::ubigint insertRec(WznmQBoxDstMNBox* rec);
	Sbecore::ubigint insertNewRec(WznmQBoxDstMNBox** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQBoxDstMNBox& rst, WznmQBoxDstMNBox** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
	virtual void insertRst(ListWznmQBoxDstMNBox& rst);
	virtual void updateRec(WznmQBoxDstMNBox* rec);
	virtual void updateRst(ListWznmQBoxDstMNBox& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxDstMNBox** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxDstMNBox& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQBoxDstMNBox: C++ wrapper for table TblWznmQBoxDstMNBox (MySQL database)
	*/
class MyTblWznmQBoxDstMNBox : public TblWznmQBoxDstMNBox, public Sbecore::MyTable {

public:
	MyTblWznmQBoxDstMNBox();
	~MyTblWznmQBoxDstMNBox();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBoxDstMNBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxDstMNBox& rst);

	Sbecore::ubigint insertRec(WznmQBoxDstMNBox* rec);
	void insertRst(ListWznmQBoxDstMNBox& rst);
	void updateRec(WznmQBoxDstMNBox* rec);
	void updateRst(ListWznmQBoxDstMNBox& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxDstMNBox** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxDstMNBox& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQBoxDstMNBox: C++ wrapper for table TblWznmQBoxDstMNBox (PgSQL database)
	*/
class PgTblWznmQBoxDstMNBox : public TblWznmQBoxDstMNBox, public Sbecore::PgTable {

public:
	PgTblWznmQBoxDstMNBox();
	~PgTblWznmQBoxDstMNBox();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQBoxDstMNBox** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQBoxDstMNBox& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQBoxDstMNBox** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQBoxDstMNBox& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQBoxDstMNBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQBoxDstMNBox& rst);

	Sbecore::ubigint insertRec(WznmQBoxDstMNBox* rec);
	void insertRst(ListWznmQBoxDstMNBox& rst);
	void updateRec(WznmQBoxDstMNBox* rec);
	void updateRst(ListWznmQBoxDstMNBox& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQBoxDstMNBox** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQBoxDstMNBox& rst);
};
#endif

#endif
