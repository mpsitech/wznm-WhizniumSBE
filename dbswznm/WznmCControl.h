/**
	* \file WznmCControl.h
	* Dbs and XML wrapper for table TblWznmCControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMCCONTROL_H
#define WZNMCCONTROL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCControl: C++ wrapper for table TblWznmCControl
	*/
class TblWznmCControl {

public:
	TblWznmCControl();
	virtual ~TblWznmCControl();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCControl: C++ wrapper for table TblWznmCControl (MySQL database)
	*/
class MyTblWznmCControl : public TblWznmCControl, public Sbecore::MyTable {

public:
	MyTblWznmCControl();
	~MyTblWznmCControl();

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
	* PgTblWznmCControl: C++ wrapper for table TblWznmCControl (PgSQL database)
	*/
class PgTblWznmCControl : public TblWznmCControl, public Sbecore::PgTable {

public:
	PgTblWznmCControl();
	~PgTblWznmCControl();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

