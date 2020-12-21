/**
	* \file WznmWrsrvDeploy.h
	* Wznm operation processor - write server deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRSRVDEPLOY_H
#define WZNMWRSRVDEPLOY_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvDeploy {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeChkoutSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars, ListWznmMOppack& opks, const bool hasm2m, const bool hasdds, const bool hasua);
	void writeMakeInc(std::fstream& outfile, const bool hasdds, const bool hasua);
	void writeMake(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& sysroot, const std::string& inclibeq, WznmMRelease* rls, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, ListWznmMCard& cars, ListWznmMOppack& opks, ListWznmMJob& gbljobs, const bool hasdds, const bool hasua);
	void writeMkSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars);
	void writeMkcar(DbsWznm* dbswznm, std::fstream& outfile, const bool cmbdNotD, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& sysroot, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths, WznmMCard* car);
	void writeMkiex(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const bool dCmbdNotOpd, const bool cmbdNotD, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& sysroot, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths);
	void writeMkvec(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& sysroot, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths);

	void writeCoopSh(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const std::string& cmpsref, ListWznmMOppack& opks);
	void writeMkop(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, WznmMComponent* cmp, const std::string& sysroot, const std::string& inclibeq, WznmMRelease* rls, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, ListWznmMOppack& opks);
	void writeMkopSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMOppack& opks);
	void writeMkopk(DbsWznm* dbswznm, std::fstream& outfile, const bool cmbdNotOpd, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& sysroot, const std::string& inclibeq, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& incpaths, WznmMOppack* opk);

	void writeCocmbSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars, ListWznmMOppack& opks, const bool hasm2m, const bool hasdds, const bool hasua);
	void writeMkcmb(DbsWznm* dbswznm, std::fstream& outfile, WznmMVersion* ver, const std::string& sysroot, const std::string& inclibeq, WznmMRelease* rls, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& Prjshort, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, ListWznmMCard& cars, ListWznmMOppack& opks, ListWznmMJob& gbljobs, const bool hasdds, const bool hasua);
	void writeMkcmbSh(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, ListWznmMCard& cars, ListWznmMOppack& opks);

	void addLibBySref(DbsWznm* dbswznm, const std::string& srefLib, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& sbeconfig, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, unsigned int ix0);
	void addLibByRef(DbsWznm* dbswznm, const Sbecore::ubigint refLib, const Sbecore::ubigint refMch, std::vector<Sbecore::ubigint>& hrefsMch, const std::string& sbeconfig, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss, unsigned int ix0);
	void trimLibss(std::vector<std::string>& libss);
	std::string pathToPathstr(const std::string& path, const bool libNotInc, const std::string& inclibeq);
	std::string libsToLibstr(const std::string& libs, const bool statNotShr);
	// IP cust --- IEND
};

#endif
