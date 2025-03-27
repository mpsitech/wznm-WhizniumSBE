/**
	* \file WznmQVisRef1NFile.h
	* Dbs and XML wrapper for table TblWznmQVisRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 29 Dec 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISREF1NFILE_H
#define WZNMQVISREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVisRef1NFile: record of TblWznmQVisRef1NFile
	*/
class WznmQVisRef1NFile {

public:
	WznmQVisRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVisRef1NFile: recordset of TblWznmQVisRef1NFile
	*/
class ListWznmQVisRef1NFile {

public:
	ListWznmQVisRef1NFile();
	ListWznmQVisRef1NFile(const ListWznmQVisRef1NFile& src);
	~ListWznmQVisRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WznmQVisRef1NFile* rec);

	ListWznmQVisRef1NFile& operator=(const ListWznmQVisRef1NFile& src);

public:
	std::vector<WznmQVisRef1NFile*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVisRef1NFile: C++ wrapper for table TblWznmQVisRef1NFile
	*/
class TblWznmQVisRef1NFile {

public:
	TblWznmQVisRef1NFile();
	virtual ~TblWznmQVisRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVisRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WznmQVisRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WznmQVisRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVisRef1NFile& rst, WznmQVisRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVisRef1NFile& rst);
	virtual void updateRec(WznmQVisRef1NFile* rec);
	virtual void updateRst(ListWznmQVisRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVisRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVisRef1NFile: C++ wrapper for table TblWznmQVisRef1NFile (MySQL database)
	*/
class MyTblWznmQVisRef1NFile : public TblWznmQVisRef1NFile, public Sbecore::MyTable {

public:
	MyTblWznmQVisRef1NFile();
	~MyTblWznmQVisRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQVisRef1NFile* rec);
	void insertRst(ListWznmQVisRef1NFile& rst);
	void updateRec(WznmQVisRef1NFile* rec);
	void updateRst(ListWznmQVisRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVisRef1NFile: C++ wrapper for table TblWznmQVisRef1NFile (PgSQL database)
	*/
class PgTblWznmQVisRef1NFile : public TblWznmQVisRef1NFile, public Sbecore::PgTable {

public:
	PgTblWznmQVisRef1NFile();
	~PgTblWznmQVisRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVisRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVisRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVisRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVisRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVisRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVisRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQVisRef1NFile* rec);
	void insertRst(ListWznmQVisRef1NFile& rst);
	void updateRec(WznmQVisRef1NFile* rec);
	void updateRst(ListWznmQVisRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVisRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVisRef1NFile& rst);
};
#endif

#endif
