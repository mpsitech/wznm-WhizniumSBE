/**
	* \file WznmCRelation.h
	* Dbs and XML wrapper for table TblWznmCRelation (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMCRELATION_H
#define WZNMCRELATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCRelation: C++ wrapper for table TblWznmCRelation
	*/
class TblWznmCRelation {

public:
	TblWznmCRelation();
	virtual ~TblWznmCRelation();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCRelation: C++ wrapper for table TblWznmCRelation (MySQL database)
	*/
class MyTblWznmCRelation : public TblWznmCRelation, public Sbecore::MyTable {

public:
	MyTblWznmCRelation();
	~MyTblWznmCRelation();

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
	* PgTblWznmCRelation: C++ wrapper for table TblWznmCRelation (PgSQL database)
	*/
class PgTblWznmCRelation : public TblWznmCRelation, public Sbecore::PgTable {

public:
	PgTblWznmCRelation();
	~PgTblWznmCRelation();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

