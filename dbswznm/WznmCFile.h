/**
	* \file WznmCFile.h
	* Dbs and XML wrapper for table TblWznmCFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMCFILE_H
#define WZNMCFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCFile: C++ wrapper for table TblWznmCFile
	*/
class TblWznmCFile {

public:
	TblWznmCFile();
	virtual ~TblWznmCFile();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCFile: C++ wrapper for table TblWznmCFile (MySQL database)
	*/
class MyTblWznmCFile : public TblWznmCFile, public Sbecore::MyTable {

public:
	MyTblWznmCFile();
	~MyTblWznmCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_PG)
/**
	* PgTblWznmCFile: C++ wrapper for table TblWznmCFile (PgSQL database)
	*/
class PgTblWznmCFile : public TblWznmCFile, public Sbecore::PgTable {

public:
	PgTblWznmCFile();
	~PgTblWznmCFile();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
