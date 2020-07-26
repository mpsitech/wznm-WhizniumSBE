/**
	* \file WznmWrsrvDeploy.h
	* Wznm operation processor - write server deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVDEPLOY_H
#define WZNMWRSRVDEPLOY_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeChkoutSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars, ListWznmMOppack& opks, const bool hasdds, const bool hasua);
	void writeMakeInc(std::fstream& outfile, const bool hasdds, const bool hasua);
	void writeMake(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, WznmMRelease* rls, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, ListWznmMCard& cars, ListWznmMOppack& opks, ListWznmMJob& gbljobs, const bool hasdds, const bool hasua);
	void writeMkSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars);
	void writeMkcar(DbsWznm* dbswznm, std::fstream& outfile, const bool cmbdNotD, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths, WznmMCard* car);
	void writeMkiex(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const bool dCmbdNotOpd, const bool cmbdNotD, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths);
	void writeMkvec(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths);

	void writeCoopSh(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const std::string& cmpsref, ListWznmMOppack& opks);
	void writeMkop(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, WznmMComponent* cmp, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, WznmMRelease* rls, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, ListWznmMOppack& opks);
	void writeMkopSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMOppack& opks);
	void writeMkopk(DbsWznm* dbswznm, std::fstream& outfile, const bool cmbdNotOpd, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths, WznmMOppack* opk);

	void writeCocmbSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars, ListWznmMOppack& opks, const bool hasdds, const bool hasua);
	void writeMkcmb(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const Sbecore::ubigint refMty, const std::string& rootfs, const std::string& inclibeq, WznmMRelease* rls, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, ListWznmMCard& cars, ListWznmMOppack& opks, ListWznmMJob& gbljobs, const bool hasdds, const bool hasua);
	void writeMkcmbSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars, ListWznmMOppack& opks);

	void addLibBySref(DbsWznm* dbswznm, const std::string& srefLib, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, unsigned int ix0);
	void addLibByRef(DbsWznm* dbswznm, const Sbecore::ubigint refLib, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, unsigned int ix0);
	std::string getLibAMkfTagVal(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMLibrary, const Sbecore::ubigint refMty, const Sbecore::ubigint refMch, const std::string& tag);
	void trimLibss(std::vector<std::string>& libss);
	std::string pathToPathstr(const std::string& path, const bool libNotInc, const std::string& inclibeq);
	std::string libsToLibstr(const std::string& libs, const bool statNotShr);
	// IP cust --- IEND
};

#endif


