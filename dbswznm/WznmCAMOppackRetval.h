/**
	* \file WznmCAMOppackRetval.h
	* Dbs and XML wrapper for table TblWznmCAMOppackRetval (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMCAMOPPACKRETVAL_H
#define WZNMCAMOPPACKRETVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCAMOppackRetval: C++ wrapper for table TblWznmCAMOppackRetval
	*/
class TblWznmCAMOppackRetval {

public:
	TblWznmCAMOppackRetval();
	virtual ~TblWznmCAMOppackRetval();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCAMOppackRetval: C++ wrapper for table TblWznmCAMOppackRetval (MySQL database)
	*/
class MyTblWznmCAMOppackRetval : public TblWznmCAMOppackRetval, public Sbecore::MyTable {

public:
	MyTblWznmCAMOppackRetval();
	~MyTblWznmCAMOppackRetval();

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
	* PgTblWznmCAMOppackRetval: C++ wrapper for table TblWznmCAMOppackRetval (PgSQL database)
	*/
class PgTblWznmCAMOppackRetval : public TblWznmCAMOppackRetval, public Sbecore::PgTable {

public:
	PgTblWznmCAMOppackRetval();
	~PgTblWznmCAMOppackRetval();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
