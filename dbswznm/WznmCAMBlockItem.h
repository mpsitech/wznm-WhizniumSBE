/**
	* \file WznmCAMBlockItem.h
	* Dbs and XML wrapper for table TblWznmCAMBlockItem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMCAMBLOCKITEM_H
#define WZNMCAMBLOCKITEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCAMBlockItem: C++ wrapper for table TblWznmCAMBlockItem
	*/
class TblWznmCAMBlockItem {

public:
	TblWznmCAMBlockItem();
	virtual ~TblWznmCAMBlockItem();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCAMBlockItem: C++ wrapper for table TblWznmCAMBlockItem (MySQL database)
	*/
class MyTblWznmCAMBlockItem : public TblWznmCAMBlockItem, public Sbecore::MyTable {

public:
	MyTblWznmCAMBlockItem();
	~MyTblWznmCAMBlockItem();

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
	* PgTblWznmCAMBlockItem: C++ wrapper for table TblWznmCAMBlockItem (PgSQL database)
	*/
class PgTblWznmCAMBlockItem : public TblWznmCAMBlockItem, public Sbecore::PgTable {

public:
	PgTblWznmCAMBlockItem();
	~PgTblWznmCAMBlockItem();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
