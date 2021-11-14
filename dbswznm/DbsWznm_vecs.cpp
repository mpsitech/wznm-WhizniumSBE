/**
	* \file DbsWznm_vecs.cpp
	* C++ wrapper for database DbsWznm (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DbsWznm::VecVApptarget
 ******************************************************************************/

uint DbsWznm::VecVApptarget::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cocoa.objc") return COCOA_OBJC;
	if (s == "cocoa.swift") return COCOA_SWIFT;
	if (s == "dotnet.cppcli") return DOTNET_CPPCLI;
	if (s == "java") return JAVA;
	if (s == "js") return JS;
	if (s == "posix.cpp") return POSIX_CPP;
	if (s == "winrt.cpp") return WINRT_CPP;

	return(0);
};

string DbsWznm::VecVApptarget::getSref(
			const uint ix
		) {
	if (ix == COCOA_OBJC) return("cocoa.objc");
	if (ix == COCOA_SWIFT) return("cocoa.swift");
	if (ix == DOTNET_CPPCLI) return("dotnet.cppcli");
	if (ix == JAVA) return("java");
	if (ix == JS) return("js");
	if (ix == POSIX_CPP) return("posix.cpp");
	if (ix == WINRT_CPP) return("winrt.cpp");

	return("");
};

string DbsWznm::VecVApptarget::getTitle(
			const uint ix
		) {
	if (ix == COCOA_OBJC) return("Cocoa / Objective-C");
	if (ix == COCOA_SWIFT) return("Cocoa / Swift");
	if (ix == DOTNET_CPPCLI) return(".NET / C++ CLI");
	if (ix == JAVA) return("Java");
	if (ix == JS) return("JavaScript");
	if (ix == POSIX_CPP) return("POSIX / C++");
	if (ix == WINRT_CPP) return("WinRT / C++");
	return(getSref(ix));

	return("");
};

void DbsWznm::VecVApptarget::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

/******************************************************************************
 class DbsWznm::VecVCard
 ******************************************************************************/

uint DbsWznm::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdwznmusg") return CRDWZNMUSG;
	if (s == "crdwznmusr") return CRDWZNMUSR;
	if (s == "crdwznmprs") return CRDWZNMPRS;
	if (s == "crdwznmfil") return CRDWZNMFIL;
	if (s == "crdwznmnav") return CRDWZNMNAV;
	if (s == "crdwznmloc") return CRDWZNMLOC;
	if (s == "crdwznmtag") return CRDWZNMTAG;
	if (s == "crdwznmctp") return CRDWZNMCTP;
	if (s == "crdwznmmch") return CRDWZNMMCH;
	if (s == "crdwznmlib") return CRDWZNMLIB;
	if (s == "crdwznmprj") return CRDWZNMPRJ;
	if (s == "crdwznmver") return CRDWZNMVER;
	if (s == "crdwznmcap") return CRDWZNMCAP;
	if (s == "crdwznmerr") return CRDWZNMERR;
	if (s == "crdwznmtbl") return CRDWZNMTBL;
	if (s == "crdwznmtco") return CRDWZNMTCO;
	if (s == "crdwznmsbs") return CRDWZNMSBS;
	if (s == "crdwznmrel") return CRDWZNMREL;
	if (s == "crdwznmvec") return CRDWZNMVEC;
	if (s == "crdwznmvit") return CRDWZNMVIT;
	if (s == "crdwznmchk") return CRDWZNMCHK;
	if (s == "crdwznmstb") return CRDWZNMSTB;
	if (s == "crdwznmiex") return CRDWZNMIEX;
	if (s == "crdwznmime") return CRDWZNMIME;
	if (s == "crdwznmiel") return CRDWZNMIEL;
	if (s == "crdwznmpst") return CRDWZNMPST;
	if (s == "crdwznmmdl") return CRDWZNMMDL;
	if (s == "crdwznmcar") return CRDWZNMCAR;
	if (s == "crdwznmdlg") return CRDWZNMDLG;
	if (s == "crdwznmpnl") return CRDWZNMPNL;
	if (s == "crdwznmqry") return CRDWZNMQRY;
	if (s == "crdwznmqco") return CRDWZNMQCO;
	if (s == "crdwznmqmd") return CRDWZNMQMD;
	if (s == "crdwznmcon") return CRDWZNMCON;
	if (s == "crdwznmopk") return CRDWZNMOPK;
	if (s == "crdwznmopx") return CRDWZNMOPX;
	if (s == "crdwznmjob") return CRDWZNMJOB;
	if (s == "crdwznmsge") return CRDWZNMSGE;
	if (s == "crdwznmmtd") return CRDWZNMMTD;
	if (s == "crdwznmblk") return CRDWZNMBLK;
	if (s == "crdwznmcal") return CRDWZNMCAL;
	if (s == "crdwznmcmp") return CRDWZNMCMP;
	if (s == "crdwznmrls") return CRDWZNMRLS;
	if (s == "crdwznmapp") return CRDWZNMAPP;
	if (s == "crdwznmrtj") return CRDWZNMRTJ;
	if (s == "crdwznmevt") return CRDWZNMEVT;
	if (s == "crdwznmseq") return CRDWZNMSEQ;
	if (s == "crdwznmste") return CRDWZNMSTE;
	if (s == "crdwznmutl") return CRDWZNMUTL;

	return(0);
};

string DbsWznm::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDWZNMUSG) return("CrdWznmUsg");
	if (ix == CRDWZNMUSR) return("CrdWznmUsr");
	if (ix == CRDWZNMPRS) return("CrdWznmPrs");
	if (ix == CRDWZNMFIL) return("CrdWznmFil");
	if (ix == CRDWZNMNAV) return("CrdWznmNav");
	if (ix == CRDWZNMLOC) return("CrdWznmLoc");
	if (ix == CRDWZNMTAG) return("CrdWznmTag");
	if (ix == CRDWZNMCTP) return("CrdWznmCtp");
	if (ix == CRDWZNMMCH) return("CrdWznmMch");
	if (ix == CRDWZNMLIB) return("CrdWznmLib");
	if (ix == CRDWZNMPRJ) return("CrdWznmPrj");
	if (ix == CRDWZNMVER) return("CrdWznmVer");
	if (ix == CRDWZNMCAP) return("CrdWznmCap");
	if (ix == CRDWZNMERR) return("CrdWznmErr");
	if (ix == CRDWZNMTBL) return("CrdWznmTbl");
	if (ix == CRDWZNMTCO) return("CrdWznmTco");
	if (ix == CRDWZNMSBS) return("CrdWznmSbs");
	if (ix == CRDWZNMREL) return("CrdWznmRel");
	if (ix == CRDWZNMVEC) return("CrdWznmVec");
	if (ix == CRDWZNMVIT) return("CrdWznmVit");
	if (ix == CRDWZNMCHK) return("CrdWznmChk");
	if (ix == CRDWZNMSTB) return("CrdWznmStb");
	if (ix == CRDWZNMIEX) return("CrdWznmIex");
	if (ix == CRDWZNMIME) return("CrdWznmIme");
	if (ix == CRDWZNMIEL) return("CrdWznmIel");
	if (ix == CRDWZNMPST) return("CrdWznmPst");
	if (ix == CRDWZNMMDL) return("CrdWznmMdl");
	if (ix == CRDWZNMCAR) return("CrdWznmCar");
	if (ix == CRDWZNMDLG) return("CrdWznmDlg");
	if (ix == CRDWZNMPNL) return("CrdWznmPnl");
	if (ix == CRDWZNMQRY) return("CrdWznmQry");
	if (ix == CRDWZNMQCO) return("CrdWznmQco");
	if (ix == CRDWZNMQMD) return("CrdWznmQmd");
	if (ix == CRDWZNMCON) return("CrdWznmCon");
	if (ix == CRDWZNMOPK) return("CrdWznmOpk");
	if (ix == CRDWZNMOPX) return("CrdWznmOpx");
	if (ix == CRDWZNMJOB) return("CrdWznmJob");
	if (ix == CRDWZNMSGE) return("CrdWznmSge");
	if (ix == CRDWZNMMTD) return("CrdWznmMtd");
	if (ix == CRDWZNMBLK) return("CrdWznmBlk");
	if (ix == CRDWZNMCAL) return("CrdWznmCal");
	if (ix == CRDWZNMCMP) return("CrdWznmCmp");
	if (ix == CRDWZNMRLS) return("CrdWznmRls");
	if (ix == CRDWZNMAPP) return("CrdWznmApp");
	if (ix == CRDWZNMRTJ) return("CrdWznmRtj");
	if (ix == CRDWZNMEVT) return("CrdWznmEvt");
	if (ix == CRDWZNMSEQ) return("CrdWznmSeq");
	if (ix == CRDWZNMSTE) return("CrdWznmSte");
	if (ix == CRDWZNMUTL) return("CrdWznmUtl");

	return("");
};

string DbsWznm::VecVCard::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CRDWZNMUSG) return("user groups");
		if (ix == CRDWZNMUSR) return("users");
		if (ix == CRDWZNMPRS) return("persons");
		if (ix == CRDWZNMFIL) return("files");
		if (ix == CRDWZNMLOC) return("locales");
		if (ix == CRDWZNMTAG) return("tags");
		if (ix == CRDWZNMCTP) return("capability templates");
		if (ix == CRDWZNMMCH) return("machines");
		if (ix == CRDWZNMLIB) return("libraries");
		if (ix == CRDWZNMPRJ) return("projects");
		if (ix == CRDWZNMVER) return("versions");
		if (ix == CRDWZNMCAP) return("capabilities");
		if (ix == CRDWZNMERR) return("errors");
		if (ix == CRDWZNMTBL) return("tables");
		if (ix == CRDWZNMTCO) return("table columns");
		if (ix == CRDWZNMSBS) return("subsets");
		if (ix == CRDWZNMREL) return("relations");
		if (ix == CRDWZNMVEC) return("vectors");
		if (ix == CRDWZNMVIT) return("vector items");
		if (ix == CRDWZNMCHK) return("feature checks");
		if (ix == CRDWZNMSTB) return("stubs");
		if (ix == CRDWZNMIEX) return("import/export complexes");
		if (ix == CRDWZNMIME) return("import/exports");
		if (ix == CRDWZNMIEL) return("import/export columns");
		if (ix == CRDWZNMPST) return("presettings");
		if (ix == CRDWZNMMDL) return("modules");
		if (ix == CRDWZNMCAR) return("cards");
		if (ix == CRDWZNMDLG) return("dialogs");
		if (ix == CRDWZNMPNL) return("panels");
		if (ix == CRDWZNMQRY) return("queries");
		if (ix == CRDWZNMQCO) return("query columns");
		if (ix == CRDWZNMQMD) return("query modifiers");
		if (ix == CRDWZNMCON) return("controls");
		if (ix == CRDWZNMOPK) return("operation packs");
		if (ix == CRDWZNMOPX) return("operations");
		if (ix == CRDWZNMJOB) return("jobs");
		if (ix == CRDWZNMSGE) return("stages");
		if (ix == CRDWZNMMTD) return("methods");
		if (ix == CRDWZNMBLK) return("blocks");
		if (ix == CRDWZNMCAL) return("calls");
		if (ix == CRDWZNMCMP) return("components");
		if (ix == CRDWZNMRLS) return("releases");
		if (ix == CRDWZNMAPP) return("accessor apps");
		if (ix == CRDWZNMRTJ) return("run-time jobs");
		if (ix == CRDWZNMEVT) return("events");
		if (ix == CRDWZNMSEQ) return("sequences");
		if (ix == CRDWZNMSTE) return("states");
		if (ix == CRDWZNMUTL) return("utilities");
		return(getSref(ix));
	};

	return("");
};

void DbsWznm::VecVCard::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 49; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecVControl
 ******************************************************************************/

uint DbsWznm::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlwznmusglist.tcogrp") return PNLWZNMUSGLIST_TCOGRP;
	if (s == "pnlwznmusglist.tcoown") return PNLWZNMUSGLIST_TCOOWN;
	if (s == "pnlwznmusglist.tcosrf") return PNLWZNMUSGLIST_TCOSRF;
	if (s == "pnlwznmusgaaccess.tcofeg") return PNLWZNMUSGAACCESS_TCOFEG;
	if (s == "pnlwznmusgaaccess.tcofea") return PNLWZNMUSGAACCESS_TCOFEA;
	if (s == "pnlwznmusgaaccess.tcoacc") return PNLWZNMUSGAACCESS_TCOACC;
	if (s == "pnlwznmusgmnuser.tcomref") return PNLWZNMUSGMNUSER_TCOMREF;
	if (s == "pnlwznmusgmnuser.tcoulv") return PNLWZNMUSGMNUSER_TCOULV;
	if (s == "pnlwznmusrlist.tcogrp") return PNLWZNMUSRLIST_TCOGRP;
	if (s == "pnlwznmusrlist.tcoown") return PNLWZNMUSRLIST_TCOOWN;
	if (s == "pnlwznmusrlist.tcoprs") return PNLWZNMUSRLIST_TCOPRS;
	if (s == "pnlwznmusrlist.tcosrf") return PNLWZNMUSRLIST_TCOSRF;
	if (s == "pnlwznmusrlist.tcousg") return PNLWZNMUSRLIST_TCOUSG;
	if (s == "pnlwznmusrlist.tcoste") return PNLWZNMUSRLIST_TCOSTE;
	if (s == "pnlwznmusrlist.tcolcl") return PNLWZNMUSRLIST_TCOLCL;
	if (s == "pnlwznmusrlist.tcoulv") return PNLWZNMUSRLIST_TCOULV;
	if (s == "pnlwznmusraaccess.tcofeg") return PNLWZNMUSRAACCESS_TCOFEG;
	if (s == "pnlwznmusraaccess.tcofea") return PNLWZNMUSRAACCESS_TCOFEA;
	if (s == "pnlwznmusraaccess.tcoacc") return PNLWZNMUSRAACCESS_TCOACC;
	if (s == "pnlwznmusr1nsession.tcoref") return PNLWZNMUSR1NSESSION_TCOREF;
	if (s == "pnlwznmusrmnusergroup.tcomref") return PNLWZNMUSRMNUSERGROUP_TCOMREF;
	if (s == "pnlwznmusrmnusergroup.tcoulv") return PNLWZNMUSRMNUSERGROUP_TCOULV;
	if (s == "pnlwznmprslist.tcogrp") return PNLWZNMPRSLIST_TCOGRP;
	if (s == "pnlwznmprslist.tcoown") return PNLWZNMPRSLIST_TCOOWN;
	if (s == "pnlwznmprslist.tcotit") return PNLWZNMPRSLIST_TCOTIT;
	if (s == "pnlwznmprslist.tcofnm") return PNLWZNMPRSLIST_TCOFNM;
	if (s == "pnlwznmprslist.tcolnm") return PNLWZNMPRSLIST_TCOLNM;
	if (s == "pnlwznmprslist.tcosex") return PNLWZNMPRSLIST_TCOSEX;
	if (s == "pnlwznmprslist.tcotel") return PNLWZNMPRSLIST_TCOTEL;
	if (s == "pnlwznmprslist.tcoeml") return PNLWZNMPRSLIST_TCOEML;
	if (s == "pnlwznmprsadetail.tcotyp") return PNLWZNMPRSADETAIL_TCOTYP;
	if (s == "pnlwznmprsadetail.tcoval") return PNLWZNMPRSADETAIL_TCOVAL;
	if (s == "pnlwznmprsmnproject.tcomref") return PNLWZNMPRSMNPROJECT_TCOMREF;
	if (s == "pnlwznmprsmnproject.tcosta") return PNLWZNMPRSMNPROJECT_TCOSTA;
	if (s == "pnlwznmprsmnproject.tcosto") return PNLWZNMPRSMNPROJECT_TCOSTO;
	if (s == "pnlwznmprsmnproject.tcofct") return PNLWZNMPRSMNPROJECT_TCOFCT;
	if (s == "pnlwznmfillist.tcogrp") return PNLWZNMFILLIST_TCOGRP;
	if (s == "pnlwznmfillist.tcoown") return PNLWZNMFILLIST_TCOOWN;
	if (s == "pnlwznmfillist.tcofnm") return PNLWZNMFILLIST_TCOFNM;
	if (s == "pnlwznmfillist.tcoret") return PNLWZNMFILLIST_TCORET;
	if (s == "pnlwznmfillist.tcoreu") return PNLWZNMFILLIST_TCOREU;
	if (s == "pnlwznmfillist.tcocnt") return PNLWZNMFILLIST_TCOCNT;
	if (s == "pnlwznmfillist.tcomim") return PNLWZNMFILLIST_TCOMIM;
	if (s == "pnlwznmfillist.tcosiz") return PNLWZNMFILLIST_TCOSIZ;
	if (s == "pnlwznmloclist.tcosrf") return PNLWZNMLOCLIST_TCOSRF;
	if (s == "pnlwznmloclist.tcotit") return PNLWZNMLOCLIST_TCOTIT;
	if (s == "pnlwznmlocmnversion.tcomref") return PNLWZNMLOCMNVERSION_TCOMREF;
	if (s == "pnlwznmtaglist.tcosrf") return PNLWZNMTAGLIST_TCOSRF;
	if (s == "pnlwznmtaglist.tcotit") return PNLWZNMTAGLIST_TCOTIT;
	if (s == "pnlwznmtaglist.tcocpb") return PNLWZNMTAGLIST_TCOCPB;
	if (s == "pnlwznmtaglist.tcogrp") return PNLWZNMTAGLIST_TCOGRP;
	if (s == "pnlwznmctplist.tcosrf") return PNLWZNMCTPLIST_TCOSRF;
	if (s == "pnlwznmctplist.tcotit") return PNLWZNMCTPLIST_TCOTIT;
	if (s == "pnlwznmctplist.tcover") return PNLWZNMCTPLIST_TCOVER;
	if (s == "pnlwznmctplist.tcoatf") return PNLWZNMCTPLIST_TCOATF;
	if (s == "pnlwznmctpkparkey.tcofix") return PNLWZNMCTPKPARKEY_TCOFIX;
	if (s == "pnlwznmctpkparkey.tcosrf") return PNLWZNMCTPKPARKEY_TCOSRF;
	if (s == "pnlwznmctpkparkey.tcoavl") return PNLWZNMCTPKPARKEY_TCOAVL;
	if (s == "pnlwznmctpkparkey.tcoimp") return PNLWZNMCTPKPARKEY_TCOIMP;
	if (s == "pnlwznmctpkparkey.tcotit") return PNLWZNMCTPKPARKEY_TCOTIT;
	if (s == "pnlwznmctpkparkey.tcocmt") return PNLWZNMCTPKPARKEY_TCOCMT;
	if (s == "pnlwznmctpkkey.tcofix") return PNLWZNMCTPKKEY_TCOFIX;
	if (s == "pnlwznmctpkkey.tcosrf") return PNLWZNMCTPKKEY_TCOSRF;
	if (s == "pnlwznmctpkkey.tcoavl") return PNLWZNMCTPKKEY_TCOAVL;
	if (s == "pnlwznmctpkkey.tcoimp") return PNLWZNMCTPKKEY_TCOIMP;
	if (s == "pnlwznmctpkkey.tcotit") return PNLWZNMCTPKKEY_TCOTIT;
	if (s == "pnlwznmctpkkey.tcocmt") return PNLWZNMCTPKKEY_TCOCMT;
	if (s == "pnlwznmctpapar.tcokey") return PNLWZNMCTPAPAR_TCOKEY;
	if (s == "pnlwznmctpapar.tcoval") return PNLWZNMCTPAPAR_TCOVAL;
	if (s == "pnlwznmctp1ntag.tcoref") return PNLWZNMCTP1NTAG_TCOREF;
	if (s == "pnlwznmctptpl1ncapability.tcoref") return PNLWZNMCTPTPL1NCAPABILITY_TCOREF;
	if (s == "pnlwznmmchlist.tcosrf") return PNLWZNMMCHLIST_TCOSRF;
	if (s == "pnlwznmmchlist.tcosup") return PNLWZNMMCHLIST_TCOSUP;
	if (s == "pnlwznmmchamakefile.tcotag") return PNLWZNMMCHAMAKEFILE_TCOTAG;
	if (s == "pnlwznmmchamakefile.tcoval") return PNLWZNMMCHAMAKEFILE_TCOVAL;
	if (s == "pnlwznmmchapar.tcokey") return PNLWZNMMCHAPAR_TCOKEY;
	if (s == "pnlwznmmchapar.tcoval") return PNLWZNMMCHAPAR_TCOVAL;
	if (s == "pnlwznmmch1nrelease.tcoref") return PNLWZNMMCH1NRELEASE_TCOREF;
	if (s == "pnlwznmmchsup1nmachine.tcoref") return PNLWZNMMCHSUP1NMACHINE_TCOREF;
	if (s == "pnlwznmliblist.tcosrf") return PNLWZNMLIBLIST_TCOSRF;
	if (s == "pnlwznmliblist.tcotit") return PNLWZNMLIBLIST_TCOTIT;
	if (s == "pnlwznmliblist.tcover") return PNLWZNMLIBLIST_TCOVER;
	if (s == "pnlwznmliblist.tcolty") return PNLWZNMLIBLIST_TCOLTY;
	if (s == "pnlwznmlibamakefile.tcomch") return PNLWZNMLIBAMAKEFILE_TCOMCH;
	if (s == "pnlwznmlibamakefile.tcotag") return PNLWZNMLIBAMAKEFILE_TCOTAG;
	if (s == "pnlwznmlibamakefile.tcoval") return PNLWZNMLIBAMAKEFILE_TCOVAL;
	if (s == "pnlwznmlibapkglist.tcomch") return PNLWZNMLIBAPKGLIST_TCOMCH;
	if (s == "pnlwznmlibapkglist.tcopkl") return PNLWZNMLIBAPKGLIST_TCOPKL;
	if (s == "pnlwznmlibref1nfile.tcoref") return PNLWZNMLIBREF1NFILE_TCOREF;
	if (s == "pnlwznmlibmnoppack.tcomref") return PNLWZNMLIBMNOPPACK_TCOMREF;
	if (s == "pnlwznmlibmncomponent.tcomref") return PNLWZNMLIBMNCOMPONENT_TCOMREF;
	if (s == "pnlwznmprjlist.tcogrp") return PNLWZNMPRJLIST_TCOGRP;
	if (s == "pnlwznmprjlist.tcoown") return PNLWZNMPRJLIST_TCOOWN;
	if (s == "pnlwznmprjlist.tcosho") return PNLWZNMPRJLIST_TCOSHO;
	if (s == "pnlwznmprjlist.tcotit") return PNLWZNMPRJLIST_TCOTIT;
	if (s == "pnlwznmprjlist.tcover") return PNLWZNMPRJLIST_TCOVER;
	if (s == "pnlwznmprjlist.tcogrl") return PNLWZNMPRJLIST_TCOGRL;
	if (s == "pnlwznmprjprj1nversion.tcoref") return PNLWZNMPRJPRJ1NVERSION_TCOREF;
	if (s == "pnlwznmprjmnperson.tcomref") return PNLWZNMPRJMNPERSON_TCOMREF;
	if (s == "pnlwznmprjmnperson.tcosta") return PNLWZNMPRJMNPERSON_TCOSTA;
	if (s == "pnlwznmprjmnperson.tcosto") return PNLWZNMPRJMNPERSON_TCOSTO;
	if (s == "pnlwznmprjmnperson.tcofct") return PNLWZNMPRJMNPERSON_TCOFCT;
	if (s == "pnlwznmverlist.tcogrp") return PNLWZNMVERLIST_TCOGRP;
	if (s == "pnlwznmverlist.tcoown") return PNLWZNMVERLIST_TCOOWN;
	if (s == "pnlwznmverlist.tcoprj") return PNLWZNMVERLIST_TCOPRJ;
	if (s == "pnlwznmverlist.tcomaj") return PNLWZNMVERLIST_TCOMAJ;
	if (s == "pnlwznmverlist.tcomin") return PNLWZNMVERLIST_TCOMIN;
	if (s == "pnlwznmverlist.tcosub") return PNLWZNMVERLIST_TCOSUB;
	if (s == "pnlwznmverlist.tcobvr") return PNLWZNMVERLIST_TCOBVR;
	if (s == "pnlwznmverlist.tcoloc") return PNLWZNMVERLIST_TCOLOC;
	if (s == "pnlwznmverlist.tcoste") return PNLWZNMVERLIST_TCOSTE;
	if (s == "pnlwznmverlist.tcodty") return PNLWZNMVERLIST_TCODTY;
	if (s == "pnlwznmverver1nerror.tcoref") return PNLWZNMVERVER1NERROR_TCOREF;
	if (s == "pnlwznmver1ncomponent.tcoref") return PNLWZNMVER1NCOMPONENT_TCOREF;
	if (s == "pnlwznmver1ncall.tcoref") return PNLWZNMVER1NCALL_TCOREF;
	if (s == "pnlwznmver1nimpexpcplx.tcoref") return PNLWZNMVER1NIMPEXPCPLX_TCOREF;
	if (s == "pnlwznmver1njob.tcoref") return PNLWZNMVER1NJOB_TCOREF;
	if (s == "pnlwznmver1noppack.tcoref") return PNLWZNMVER1NOPPACK_TCOREF;
	if (s == "pnlwznmverver1nmodule.tcoref") return PNLWZNMVERVER1NMODULE_TCOREF;
	if (s == "pnlwznmver1npreset.tcoref") return PNLWZNMVER1NPRESET_TCOREF;
	if (s == "pnlwznmver1nquery.tcoref") return PNLWZNMVER1NQUERY_TCOREF;
	if (s == "pnlwznmver1nrelation.tcoref") return PNLWZNMVER1NRELATION_TCOREF;
	if (s == "pnlwznmver1ntable.tcoref") return PNLWZNMVER1NTABLE_TCOREF;
	if (s == "pnlwznmver1nvector.tcoref") return PNLWZNMVER1NVECTOR_TCOREF;
	if (s == "pnlwznmverver1napp.tcoref") return PNLWZNMVERVER1NAPP_TCOREF;
	if (s == "pnlwznmver1ncapability.tcoref") return PNLWZNMVER1NCAPABILITY_TCOREF;
	if (s == "pnlwznmverbvr1nversion.tcoref") return PNLWZNMVERBVR1NVERSION_TCOREF;
	if (s == "pnlwznmver1nblock.tcoref") return PNLWZNMVER1NBLOCK_TCOREF;
	if (s == "pnlwznmverref1nfile.tcoref") return PNLWZNMVERREF1NFILE_TCOREF;
	if (s == "pnlwznmvermnlocale.tcomref") return PNLWZNMVERMNLOCALE_TCOMREF;
	if (s == "pnlwznmcaplist.tcosrf") return PNLWZNMCAPLIST_TCOSRF;
	if (s == "pnlwznmcaplist.tcotit") return PNLWZNMCAPLIST_TCOTIT;
	if (s == "pnlwznmcaplist.tcover") return PNLWZNMCAPLIST_TCOVER;
	if (s == "pnlwznmcaplist.tcotpl") return PNLWZNMCAPLIST_TCOTPL;
	if (s == "pnlwznmcaplist.tcoatf") return PNLWZNMCAPLIST_TCOATF;
	if (s == "pnlwznmcapapar.tcokey") return PNLWZNMCAPAPAR_TCOKEY;
	if (s == "pnlwznmcapapar.tcoval") return PNLWZNMCAPAPAR_TCOVAL;
	if (s == "pnlwznmerrlist.tcosrf") return PNLWZNMERRLIST_TCOSRF;
	if (s == "pnlwznmerrlist.tcotit") return PNLWZNMERRLIST_TCOTIT;
	if (s == "pnlwznmerrlist.tcover") return PNLWZNMERRLIST_TCOVER;
	if (s == "pnlwznmtbllist.tcosrf") return PNLWZNMTBLLIST_TCOSRF;
	if (s == "pnlwznmtbllist.tcosho") return PNLWZNMTBLLIST_TCOSHO;
	if (s == "pnlwznmtbllist.tcotyp") return PNLWZNMTBLLIST_TCOTYP;
	if (s == "pnlwznmtbllist.tcover") return PNLWZNMTBLLIST_TCOVER;
	if (s == "pnlwznmtbllist.tcoret") return PNLWZNMTBLLIST_TCORET;
	if (s == "pnlwznmtbllist.tcoreu") return PNLWZNMTBLLIST_TCOREU;
	if (s == "pnlwznmtblaloadfct.tcolot") return PNLWZNMTBLALOADFCT_TCOLOT;
	if (s == "pnlwznmtblaloadfct.tcofna") return PNLWZNMTBLALOADFCT_TCOFNA;
	if (s == "pnlwznmtblaloadfct.tcoldx") return PNLWZNMTBLALOADFCT_TCOLDX;
	if (s == "pnlwznmtblaloadfct.tcolby") return PNLWZNMTBLALOADFCT_TCOLBY;
	if (s == "pnlwznmtblaloadfct.tcoord") return PNLWZNMTBLALOADFCT_TCOORD;
	if (s == "pnlwznmtblaloadfct.tcolit") return PNLWZNMTBLALOADFCT_TCOLIT;
	if (s == "pnlwznmtblatitle.tcotyp") return PNLWZNMTBLATITLE_TCOTYP;
	if (s == "pnlwznmtblatitle.tcoloc") return PNLWZNMTBLATITLE_TCOLOC;
	if (s == "pnlwznmtblatitle.tcognd") return PNLWZNMTBLATITLE_TCOGND;
	if (s == "pnlwznmtblatitle.tcotit") return PNLWZNMTBLATITLE_TCOTIT;
	if (s == "pnlwznmtbl1nimpexp.tcoref") return PNLWZNMTBL1NIMPEXP_TCOREF;
	if (s == "pnlwznmtbl1ncheck.tcoref") return PNLWZNMTBL1NCHECK_TCOREF;
	if (s == "pnlwznmtblfr1nrelation.tcoref") return PNLWZNMTBLFR1NRELATION_TCOREF;
	if (s == "pnlwznmtblto1nrelation.tcoref") return PNLWZNMTBLTO1NRELATION_TCOREF;
	if (s == "pnlwznmtbl1nstub.tcoref") return PNLWZNMTBL1NSTUB_TCOREF;
	if (s == "pnlwznmtbl1nsubset.tcoref") return PNLWZNMTBL1NSUBSET_TCOREF;
	if (s == "pnlwznmtbltbl1ntablecol.tcoref") return PNLWZNMTBLTBL1NTABLECOL_TCOREF;
	if (s == "pnlwznmtblref1ndialog.tcoref") return PNLWZNMTBLREF1NDIALOG_TCOREF;
	if (s == "pnlwznmtblref1ncall.tcoref") return PNLWZNMTBLREF1NCALL_TCOREF;
	if (s == "pnlwznmtblsrc1nfeed.tcoref") return PNLWZNMTBLSRC1NFEED_TCOREF;
	if (s == "pnlwznmtblref1npanel.tcoref") return PNLWZNMTBLREF1NPANEL_TCOREF;
	if (s == "pnlwznmtblfct1ntablecol.tcoref") return PNLWZNMTBLFCT1NTABLECOL_TCOREF;
	if (s == "pnlwznmtblhk1nvector.tcoref") return PNLWZNMTBLHK1NVECTOR_TCOREF;
	if (s == "pnlwznmtblref1nrtblock.tcoref") return PNLWZNMTBLREF1NRTBLOCK_TCOREF;
	if (s == "pnlwznmtblref1nquerymod.tcoref") return PNLWZNMTBLREF1NQUERYMOD_TCOREF;
	if (s == "pnlwznmtblpst1nquerymod.tcoref") return PNLWZNMTBLPST1NQUERYMOD_TCOREF;
	if (s == "pnlwznmtblmnvector.tcomref") return PNLWZNMTBLMNVECTOR_TCOMREF;
	if (s == "pnlwznmtblmnvector.tcosbs") return PNLWZNMTBLMNVECTOR_TCOSBS;
	if (s == "pnlwznmtblmnquery.tcomref") return PNLWZNMTBLMNQUERY_TCOMREF;
	if (s == "pnlwznmtblmnquery.tcotqmd") return PNLWZNMTBLMNQUERY_TCOTQMD;
	if (s == "pnlwznmtblmnquery.tcosrc") return PNLWZNMTBLMNQUERY_TCOSRC;
	if (s == "pnlwznmtblmnquery.tcopfx") return PNLWZNMTBLMNQUERY_TCOPFX;
	if (s == "pnlwznmtcolist.tcosrf") return PNLWZNMTCOLIST_TCOSRF;
	if (s == "pnlwznmtcolist.tcosho") return PNLWZNMTCOLIST_TCOSHO;
	if (s == "pnlwznmtcolist.tcotyp") return PNLWZNMTCOLIST_TCOTYP;
	if (s == "pnlwznmtcolist.tcotbl") return PNLWZNMTCOLIST_TCOTBL;
	if (s == "pnlwznmtcolist.tcofct") return PNLWZNMTCOLIST_TCOFCT;
	if (s == "pnlwznmtcolist.tcosty") return PNLWZNMTCOLIST_TCOSTY;
	if (s == "pnlwznmtcolist.tcoaxf") return PNLWZNMTCOLIST_TCOAXF;
	if (s == "pnlwznmtcoatitle.tcotyp") return PNLWZNMTCOATITLE_TCOTYP;
	if (s == "pnlwznmtcoatitle.tcoloc") return PNLWZNMTCOATITLE_TCOLOC;
	if (s == "pnlwznmtcoatitle.tcotit") return PNLWZNMTCOATITLE_TCOTIT;
	if (s == "pnlwznmtco1nimpexpcol.tcoref") return PNLWZNMTCO1NIMPEXPCOL_TCOREF;
	if (s == "pnlwznmtco1nquerycol.tcoref") return PNLWZNMTCO1NQUERYCOL_TCOREF;
	if (s == "pnlwznmtcoref1ncontrol.tcoref") return PNLWZNMTCOREF1NCONTROL_TCOREF;
	if (s == "pnlwznmtcoref1nquerymod.tcoref") return PNLWZNMTCOREF1NQUERYMOD_TCOREF;
	if (s == "pnlwznmtco1ncheck.tcoref") return PNLWZNMTCO1NCHECK_TCOREF;
	if (s == "pnlwznmsbslist.tcosrf") return PNLWZNMSBSLIST_TCOSRF;
	if (s == "pnlwznmsbslist.tcosho") return PNLWZNMSBSLIST_TCOSHO;
	if (s == "pnlwznmsbslist.tcotbl") return PNLWZNMSBSLIST_TCOTBL;
	if (s == "pnlwznmsbsatitle.tcotyp") return PNLWZNMSBSATITLE_TCOTYP;
	if (s == "pnlwznmsbsatitle.tcoloc") return PNLWZNMSBSATITLE_TCOLOC;
	if (s == "pnlwznmsbsatitle.tcognd") return PNLWZNMSBSATITLE_TCOGND;
	if (s == "pnlwznmsbsatitle.tcotit") return PNLWZNMSBSATITLE_TCOTIT;
	if (s == "pnlwznmsbsfrs1nrelation.tcoref") return PNLWZNMSBSFRS1NRELATION_TCOREF;
	if (s == "pnlwznmsbstos1nrelation.tcoref") return PNLWZNMSBSTOS1NRELATION_TCOREF;
	if (s == "pnlwznmsbs1ntablecol.tcoref") return PNLWZNMSBS1NTABLECOL_TCOREF;
	if (s == "pnlwznmsbs1nstub.tcoref") return PNLWZNMSBS1NSTUB_TCOREF;
	if (s == "pnlwznmsbspst1nquerymod.tcoref") return PNLWZNMSBSPST1NQUERYMOD_TCOREF;
	if (s == "pnlwznmsbsasbmnsubset.tcomref") return PNLWZNMSBSASBMNSUBSET_TCOMREF;
	if (s == "pnlwznmsbsasbmnsubset.tcorty") return PNLWZNMSBSASBMNSUBSET_TCORTY;
	if (s == "pnlwznmsbsbsbmnsubset.tcomref") return PNLWZNMSBSBSBMNSUBSET_TCOMREF;
	if (s == "pnlwznmsbsbsbmnsubset.tcorty") return PNLWZNMSBSBSBMNSUBSET_TCORTY;
	if (s == "pnlwznmrellist.tcofrt") return PNLWZNMRELLIST_TCOFRT;
	if (s == "pnlwznmrellist.tcofrs") return PNLWZNMRELLIST_TCOFRS;
	if (s == "pnlwznmrellist.tcotot") return PNLWZNMRELLIST_TCOTOT;
	if (s == "pnlwznmrellist.tcotos") return PNLWZNMRELLIST_TCOTOS;
	if (s == "pnlwznmrellist.tcotyp") return PNLWZNMRELLIST_TCOTYP;
	if (s == "pnlwznmrellist.tcover") return PNLWZNMRELLIST_TCOVER;
	if (s == "pnlwznmrellist.tcosup") return PNLWZNMRELLIST_TCOSUP;
	if (s == "pnlwznmrellist.tcosrl") return PNLWZNMRELLIST_TCOSRL;
	if (s == "pnlwznmrellist.tcotbl") return PNLWZNMRELLIST_TCOTBL;
	if (s == "pnlwznmrellist.tcopfx") return PNLWZNMRELLIST_TCOPFX;
	if (s == "pnlwznmrelatitle.tcotyp") return PNLWZNMRELATITLE_TCOTYP;
	if (s == "pnlwznmrelatitle.tcoloc") return PNLWZNMRELATITLE_TCOLOC;
	if (s == "pnlwznmrelatitle.tcotit") return PNLWZNMRELATITLE_TCOTIT;
	if (s == "pnlwznmrelsup1nrelation.tcoref") return PNLWZNMRELSUP1NRELATION_TCOREF;
	if (s == "pnlwznmrel1ntablecol.tcoref") return PNLWZNMREL1NTABLECOL_TCOREF;
	if (s == "pnlwznmrelref1ncontrol.tcoref") return PNLWZNMRELREF1NCONTROL_TCOREF;
	if (s == "pnlwznmrelref1ndialog.tcoref") return PNLWZNMRELREF1NDIALOG_TCOREF;
	if (s == "pnlwznmrelref1npanel.tcoref") return PNLWZNMRELREF1NPANEL_TCOREF;
	if (s == "pnlwznmveclist.tcosrf") return PNLWZNMVECLIST_TCOSRF;
	if (s == "pnlwznmveclist.tcotyp") return PNLWZNMVECLIST_TCOTYP;
	if (s == "pnlwznmveclist.tcover") return PNLWZNMVECLIST_TCOVER;
	if (s == "pnlwznmveclist.tcohkt") return PNLWZNMVECLIST_TCOHKT;
	if (s == "pnlwznmveclist.tcohku") return PNLWZNMVECLIST_TCOHKU;
	if (s == "pnlwznmveclist.tcotgr") return PNLWZNMVECLIST_TCOTGR;
	if (s == "pnlwznmvecatitle.tcotyp") return PNLWZNMVECATITLE_TCOTYP;
	if (s == "pnlwznmvecatitle.tcoloc") return PNLWZNMVECATITLE_TCOLOC;
	if (s == "pnlwznmvecatitle.tcotit") return PNLWZNMVECATITLE_TCOTIT;
	if (s == "pnlwznmvecvec1nvectoritem.tcoref") return PNLWZNMVECVEC1NVECTORITEM_TCOREF;
	if (s == "pnlwznmvecsrc1nfeed.tcoref") return PNLWZNMVECSRC1NFEED_TCOREF;
	if (s == "pnlwznmvecref1npanel.tcoref") return PNLWZNMVECREF1NPANEL_TCOREF;
	if (s == "pnlwznmvecfct1ntablecol.tcoref") return PNLWZNMVECFCT1NTABLECOL_TCOREF;
	if (s == "pnlwznmvecpst1nquerymod.tcoref") return PNLWZNMVECPST1NQUERYMOD_TCOREF;
	if (s == "pnlwznmvecmntable.tcomref") return PNLWZNMVECMNTABLE_TCOMREF;
	if (s == "pnlwznmvecmntable.tcosbs") return PNLWZNMVECMNTABLE_TCOSBS;
	if (s == "pnlwznmvitlist.tcosrf") return PNLWZNMVITLIST_TCOSRF;
	if (s == "pnlwznmvitlist.tcotit") return PNLWZNMVITLIST_TCOTIT;
	if (s == "pnlwznmvitlist.tcovec") return PNLWZNMVITLIST_TCOVEC;
	if (s == "pnlwznmchklist.tcosrf") return PNLWZNMCHKLIST_TCOSRF;
	if (s == "pnlwznmchklist.tcotyp") return PNLWZNMCHKLIST_TCOTYP;
	if (s == "pnlwznmchklist.tcotbl") return PNLWZNMCHKLIST_TCOTBL;
	if (s == "pnlwznmchklist.tcotco") return PNLWZNMCHKLIST_TCOTCO;
	if (s == "pnlwznmchkref1ncall.tcoref") return PNLWZNMCHKREF1NCALL_TCOREF;
	if (s == "pnlwznmstblist.tcosrf") return PNLWZNMSTBLIST_TCOSRF;
	if (s == "pnlwznmstblist.tcotyp") return PNLWZNMSTBLIST_TCOTYP;
	if (s == "pnlwznmstblist.tcotbl") return PNLWZNMSTBLIST_TCOTBL;
	if (s == "pnlwznmstblist.tcosbs") return PNLWZNMSTBLIST_TCOSBS;
	if (s == "pnlwznmstblist.tcoexa") return PNLWZNMSTBLIST_TCOEXA;
	if (s == "pnlwznmstbsupmnstub.tcomref") return PNLWZNMSTBSUPMNSTUB_TCOMREF;
	if (s == "pnlwznmstbmnsquawk.tcomref") return PNLWZNMSTBMNSQUAWK_TCOMREF;
	if (s == "pnlwznmstbsubmnstub.tcomref") return PNLWZNMSTBSUBMNSTUB_TCOMREF;
	if (s == "pnlwznmstbmncall.tcomref") return PNLWZNMSTBMNCALL_TCOMREF;
	if (s == "pnlwznmiexlist.tcosrf") return PNLWZNMIEXLIST_TCOSRF;
	if (s == "pnlwznmiexlist.tcosho") return PNLWZNMIEXLIST_TCOSHO;
	if (s == "pnlwznmiexlist.tcotit") return PNLWZNMIEXLIST_TCOTIT;
	if (s == "pnlwznmiexlist.tcover") return PNLWZNMIEXLIST_TCOVER;
	if (s == "pnlwznmiexlist.tcomiv") return PNLWZNMIEXLIST_TCOMIV;
	if (s == "pnlwznmiex1nimpexp.tcoref") return PNLWZNMIEX1NIMPEXP_TCOREF;
	if (s == "pnlwznmiexhk1nvector.tcoref") return PNLWZNMIEXHK1NVECTOR_TCOREF;
	if (s == "pnlwznmiexref1ndialog.tcoref") return PNLWZNMIEXREF1NDIALOG_TCOREF;
	if (s == "pnlwznmimelist.tcosrf") return PNLWZNMIMELIST_TCOSRF;
	if (s == "pnlwznmimelist.tcoiex") return PNLWZNMIMELIST_TCOIEX;
	if (s == "pnlwznmimelist.tcosup") return PNLWZNMIMELIST_TCOSUP;
	if (s == "pnlwznmimelist.tcotbl") return PNLWZNMIMELIST_TCOTBL;
	if (s == "pnlwznmimeime1nimpexpcol.tcoref") return PNLWZNMIMEIME1NIMPEXPCOL_TCOREF;
	if (s == "pnlwznmimesup1nimpexp.tcoref") return PNLWZNMIMESUP1NIMPEXP_TCOREF;
	if (s == "pnlwznmimehk1nvector.tcoref") return PNLWZNMIMEHK1NVECTOR_TCOREF;
	if (s == "pnlwznmiellist.tcosrf") return PNLWZNMIELLIST_TCOSRF;
	if (s == "pnlwznmiellist.tcosho") return PNLWZNMIELLIST_TCOSHO;
	if (s == "pnlwznmiellist.tcotyp") return PNLWZNMIELLIST_TCOTYP;
	if (s == "pnlwznmiellist.tcoime") return PNLWZNMIELLIST_TCOIME;
	if (s == "pnlwznmiellist.tcotco") return PNLWZNMIELLIST_TCOTCO;
	if (s == "pnlwznmiellist.tcocty") return PNLWZNMIELLIST_TCOCTY;
	if (s == "pnlwznmpstlist.tcosrf") return PNLWZNMPSTLIST_TCOSRF;
	if (s == "pnlwznmpstlist.tcotit") return PNLWZNMPSTLIST_TCOTIT;
	if (s == "pnlwznmpstlist.tcover") return PNLWZNMPSTLIST_TCOVER;
	if (s == "pnlwznmpstlist.tcoret") return PNLWZNMPSTLIST_TCORET;
	if (s == "pnlwznmpstlist.tcoreu") return PNLWZNMPSTLIST_TCOREU;
	if (s == "pnlwznmpstlist.tcoaty") return PNLWZNMPSTLIST_TCOATY;
	if (s == "pnlwznmpst1nquerymod.tcoref") return PNLWZNMPST1NQUERYMOD_TCOREF;
	if (s == "pnlwznmmdllist.tcosrf") return PNLWZNMMDLLIST_TCOSRF;
	if (s == "pnlwznmmdllist.tcotit") return PNLWZNMMDLLIST_TCOTIT;
	if (s == "pnlwznmmdllist.tcover") return PNLWZNMMDLLIST_TCOVER;
	if (s == "pnlwznmmdlmdl1ncard.tcoref") return PNLWZNMMDLMDL1NCARD_TCOREF;
	if (s == "pnlwznmmdlref1npanel.tcoref") return PNLWZNMMDLREF1NPANEL_TCOREF;
	if (s == "pnlwznmcarlist.tcosrf") return PNLWZNMCARLIST_TCOSRF;
	if (s == "pnlwznmcarlist.tcotit") return PNLWZNMCARLIST_TCOTIT;
	if (s == "pnlwznmcarlist.tcomdl") return PNLWZNMCARLIST_TCOMDL;
	if (s == "pnlwznmcarlist.tcoret") return PNLWZNMCARLIST_TCORET;
	if (s == "pnlwznmcarlist.tcoreu") return PNLWZNMCARLIST_TCOREU;
	if (s == "pnlwznmcar1ndialog.tcoref") return PNLWZNMCAR1NDIALOG_TCOREF;
	if (s == "pnlwznmcarcar1npanel.tcoref") return PNLWZNMCARCAR1NPANEL_TCOREF;
	if (s == "pnlwznmcarhk1ncontrol.tcoref") return PNLWZNMCARHK1NCONTROL_TCOREF;
	if (s == "pnlwznmdlglist.tcosrf") return PNLWZNMDLGLIST_TCOSRF;
	if (s == "pnlwznmdlglist.tcotyp") return PNLWZNMDLGLIST_TCOTYP;
	if (s == "pnlwznmdlglist.tcocar") return PNLWZNMDLGLIST_TCOCAR;
	if (s == "pnlwznmdlglist.tcoret") return PNLWZNMDLGLIST_TCORET;
	if (s == "pnlwznmdlglist.tcoreu") return PNLWZNMDLGLIST_TCOREU;
	if (s == "pnlwznmdlgref1ncontrol.tcoref") return PNLWZNMDLGREF1NCONTROL_TCOREF;
	if (s == "pnlwznmdlghk1ncontrol.tcoref") return PNLWZNMDLGHK1NCONTROL_TCOREF;
	if (s == "pnlwznmdlgmnquery.tcomref") return PNLWZNMDLGMNQUERY_TCOMREF;
	if (s == "pnlwznmpnllist.tcosrf") return PNLWZNMPNLLIST_TCOSRF;
	if (s == "pnlwznmpnllist.tcotyp") return PNLWZNMPNLLIST_TCOTYP;
	if (s == "pnlwznmpnllist.tcocar") return PNLWZNMPNLLIST_TCOCAR;
	if (s == "pnlwznmpnllist.tcoret") return PNLWZNMPNLLIST_TCORET;
	if (s == "pnlwznmpnllist.tcoreu") return PNLWZNMPNLLIST_TCOREU;
	if (s == "pnlwznmpnlhk1ncontrol.tcoref") return PNLWZNMPNLHK1NCONTROL_TCOREF;
	if (s == "pnlwznmpnlmnquery.tcomref") return PNLWZNMPNLMNQUERY_TCOMREF;
	if (s == "pnlwznmqrylist.tcosrf") return PNLWZNMQRYLIST_TCOSRF;
	if (s == "pnlwznmqrylist.tcotyp") return PNLWZNMQRYLIST_TCOTYP;
	if (s == "pnlwznmqrylist.tcover") return PNLWZNMQRYLIST_TCOVER;
	if (s == "pnlwznmqrylist.tcosup") return PNLWZNMQRYLIST_TCOSUP;
	if (s == "pnlwznmqrylist.tcosrl") return PNLWZNMQRYLIST_TCOSRL;
	if (s == "pnlwznmqrylist.tcotbl") return PNLWZNMQRYLIST_TCOTBL;
	if (s == "pnlwznmqrylist.tcoqtb") return PNLWZNMQRYLIST_TCOQTB;
	if (s == "pnlwznmqryaorder.tcosho") return PNLWZNMQRYAORDER_TCOSHO;
	if (s == "pnlwznmqryaorder.tcotco") return PNLWZNMQRYAORDER_TCOTCO;
	if (s == "pnlwznmqryaclause.tcoqmd") return PNLWZNMQRYACLAUSE_TCOQMD;
	if (s == "pnlwznmqryaclause.tcotyp") return PNLWZNMQRYACLAUSE_TCOTYP;
	if (s == "pnlwznmqryaclause.tcocse") return PNLWZNMQRYACLAUSE_TCOCSE;
	if (s == "pnlwznmqryaclause.tcopst") return PNLWZNMQRYACLAUSE_TCOPST;
	if (s == "pnlwznmqryaclause.tcovec") return PNLWZNMQRYACLAUSE_TCOVEC;
	if (s == "pnlwznmqryaclause.tcovit") return PNLWZNMQRYACLAUSE_TCOVIT;
	if (s == "pnlwznmqrysup1nquery.tcoref") return PNLWZNMQRYSUP1NQUERY_TCOREF;
	if (s == "pnlwznmqryqry1nquerycol.tcoref") return PNLWZNMQRYQRY1NQUERYCOL_TCOREF;
	if (s == "pnlwznmqry1nquerymod.tcoref") return PNLWZNMQRY1NQUERYMOD_TCOREF;
	if (s == "pnlwznmqrymntable.tcomref") return PNLWZNMQRYMNTABLE_TCOMREF;
	if (s == "pnlwznmqrymntable.tcotqmd") return PNLWZNMQRYMNTABLE_TCOTQMD;
	if (s == "pnlwznmqrymntable.tcosrc") return PNLWZNMQRYMNTABLE_TCOSRC;
	if (s == "pnlwznmqrymntable.tcopfx") return PNLWZNMQRYMNTABLE_TCOPFX;
	if (s == "pnlwznmqrymnpanel.tcomref") return PNLWZNMQRYMNPANEL_TCOMREF;
	if (s == "pnlwznmqrymndialog.tcomref") return PNLWZNMQRYMNDIALOG_TCOMREF;
	if (s == "pnlwznmqcolist.tcosrf") return PNLWZNMQCOLIST_TCOSRF;
	if (s == "pnlwznmqcolist.tcosho") return PNLWZNMQCOLIST_TCOSHO;
	if (s == "pnlwznmqcolist.tcotyp") return PNLWZNMQCOLIST_TCOTYP;
	if (s == "pnlwznmqcolist.tcoqry") return PNLWZNMQCOLIST_TCOQRY;
	if (s == "pnlwznmqcolist.tcotco") return PNLWZNMQCOLIST_TCOTCO;
	if (s == "pnlwznmqcoref1ncontrol.tcoref") return PNLWZNMQCOREF1NCONTROL_TCOREF;
	if (s == "pnlwznmqmdlist.tcotyp") return PNLWZNMQMDLIST_TCOTYP;
	if (s == "pnlwznmqmdlist.tcoqry") return PNLWZNMQMDLIST_TCOQRY;
	if (s == "pnlwznmqmdlist.tcopst") return PNLWZNMQMDLIST_TCOPST;
	if (s == "pnlwznmqmdlist.tcoret") return PNLWZNMQMDLIST_TCORET;
	if (s == "pnlwznmqmdlist.tcoreu") return PNLWZNMQMDLIST_TCOREU;
	if (s == "pnlwznmconlist.tcosrf") return PNLWZNMCONLIST_TCOSRF;
	if (s == "pnlwznmconlist.tcotit") return PNLWZNMCONLIST_TCOTIT;
	if (s == "pnlwznmconlist.tcotyp") return PNLWZNMCONLIST_TCOTYP;
	if (s == "pnlwznmconlist.tcohkt") return PNLWZNMCONLIST_TCOHKT;
	if (s == "pnlwznmconlist.tcohku") return PNLWZNMCONLIST_TCOHKU;
	if (s == "pnlwznmconlist.tcosct") return PNLWZNMCONLIST_TCOSCT;
	if (s == "pnlwznmconlist.tcoret") return PNLWZNMCONLIST_TCORET;
	if (s == "pnlwznmconlist.tcoreu") return PNLWZNMCONLIST_TCOREU;
	if (s == "pnlwznmconlist.tcosup") return PNLWZNMCONLIST_TCOSUP;
	if (s == "pnlwznmconlist.tcosty") return PNLWZNMCONLIST_TCOSTY;
	if (s == "pnlwznmconapar.tcokey") return PNLWZNMCONAPAR_TCOKEY;
	if (s == "pnlwznmconapar.tcoloc") return PNLWZNMCONAPAR_TCOLOC;
	if (s == "pnlwznmconapar.tcoval") return PNLWZNMCONAPAR_TCOVAL;
	if (s == "pnlwznmconsup1ncontrol.tcoref") return PNLWZNMCONSUP1NCONTROL_TCOREF;
	if (s == "pnlwznmconfedref1nrtblock.tcoref") return PNLWZNMCONFEDREF1NRTBLOCK_TCOREF;
	if (s == "pnlwznmopklist.tcosrf") return PNLWZNMOPKLIST_TCOSRF;
	if (s == "pnlwznmopklist.tcotit") return PNLWZNMOPKLIST_TCOTIT;
	if (s == "pnlwznmopklist.tcotyp") return PNLWZNMOPKLIST_TCOTYP;
	if (s == "pnlwznmopklist.tcover") return PNLWZNMOPKLIST_TCOVER;
	if (s == "pnlwznmopklist.tcoshd") return PNLWZNMOPKLIST_TCOSHD;
	if (s == "pnlwznmopkainvarg.tcosrf") return PNLWZNMOPKAINVARG_TCOSRF;
	if (s == "pnlwznmopkainvarg.tcovty") return PNLWZNMOPKAINVARG_TCOVTY;
	if (s == "pnlwznmopkainvarg.tcovec") return PNLWZNMOPKAINVARG_TCOVEC;
	if (s == "pnlwznmopkainvarg.tcodvl") return PNLWZNMOPKAINVARG_TCODVL;
	if (s == "pnlwznmopkainvarg.tcovit") return PNLWZNMOPKAINVARG_TCOVIT;
	if (s == "pnlwznmopkainvarg.tcocmt") return PNLWZNMOPKAINVARG_TCOCMT;
	if (s == "pnlwznmopkaretval.tcosrf") return PNLWZNMOPKARETVAL_TCOSRF;
	if (s == "pnlwznmopkaretval.tcovty") return PNLWZNMOPKARETVAL_TCOVTY;
	if (s == "pnlwznmopkaretval.tcovec") return PNLWZNMOPKARETVAL_TCOVEC;
	if (s == "pnlwznmopkaretval.tcocmt") return PNLWZNMOPKARETVAL_TCOCMT;
	if (s == "pnlwznmopk1nop.tcoref") return PNLWZNMOPK1NOP_TCOREF;
	if (s == "pnlwznmopkref1nblock.tcoref") return PNLWZNMOPKREF1NBLOCK_TCOREF;
	if (s == "pnlwznmopkmnjob.tcomref") return PNLWZNMOPKMNJOB_TCOMREF;
	if (s == "pnlwznmopkmncomponent.tcomref") return PNLWZNMOPKMNCOMPONENT_TCOMREF;
	if (s == "pnlwznmopkmnlibrary.tcomref") return PNLWZNMOPKMNLIBRARY_TCOMREF;
	if (s == "pnlwznmopksqkmnstub.tcomref") return PNLWZNMOPKSQKMNSTUB_TCOMREF;
	if (s == "pnlwznmopxlist.tcosrf") return PNLWZNMOPXLIST_TCOSRF;
	if (s == "pnlwznmopxlist.tcoopk") return PNLWZNMOPXLIST_TCOOPK;
	if (s == "pnlwznmopxlist.tcoshd") return PNLWZNMOPXLIST_TCOSHD;
	if (s == "pnlwznmopxainvarg.tcosrf") return PNLWZNMOPXAINVARG_TCOSRF;
	if (s == "pnlwznmopxainvarg.tcovty") return PNLWZNMOPXAINVARG_TCOVTY;
	if (s == "pnlwznmopxainvarg.tcovec") return PNLWZNMOPXAINVARG_TCOVEC;
	if (s == "pnlwznmopxainvarg.tcodvl") return PNLWZNMOPXAINVARG_TCODVL;
	if (s == "pnlwznmopxainvarg.tcovit") return PNLWZNMOPXAINVARG_TCOVIT;
	if (s == "pnlwznmopxainvarg.tcocmt") return PNLWZNMOPXAINVARG_TCOCMT;
	if (s == "pnlwznmopxaretval.tcosrf") return PNLWZNMOPXARETVAL_TCOSRF;
	if (s == "pnlwznmopxaretval.tcovty") return PNLWZNMOPXARETVAL_TCOVTY;
	if (s == "pnlwznmopxaretval.tcovec") return PNLWZNMOPXARETVAL_TCOVEC;
	if (s == "pnlwznmopxaretval.tcocmt") return PNLWZNMOPXARETVAL_TCOCMT;
	if (s == "pnlwznmopxref1nblock.tcoref") return PNLWZNMOPXREF1NBLOCK_TCOREF;
	if (s == "pnlwznmopxmnjob.tcomref") return PNLWZNMOPXMNJOB_TCOMREF;
	if (s == "pnlwznmopxsqkmnstub.tcomref") return PNLWZNMOPXSQKMNSTUB_TCOMREF;
	if (s == "pnlwznmjoblist.tcosrf") return PNLWZNMJOBLIST_TCOSRF;
	if (s == "pnlwznmjoblist.tcotyp") return PNLWZNMJOBLIST_TCOTYP;
	if (s == "pnlwznmjoblist.tcover") return PNLWZNMJOBLIST_TCOVER;
	if (s == "pnlwznmjoblist.tcoret") return PNLWZNMJOBLIST_TCORET;
	if (s == "pnlwznmjoblist.tcoreu") return PNLWZNMJOBLIST_TCOREU;
	if (s == "pnlwznmjoblist.tcogbl") return PNLWZNMJOBLIST_TCOGBL;
	if (s == "pnlwznmjoblist.tcocls") return PNLWZNMJOBLIST_TCOCLS;
	if (s == "pnlwznmjoblist.tcoshd") return PNLWZNMJOBLIST_TCOSHD;
	if (s == "pnlwznmjobavar.tcosrf") return PNLWZNMJOBAVAR_TCOSRF;
	if (s == "pnlwznmjobavar.tcovty") return PNLWZNMJOBAVAR_TCOVTY;
	if (s == "pnlwznmjobavar.tcovec") return PNLWZNMJOBAVAR_TCOVEC;
	if (s == "pnlwznmjobavar.tcolen") return PNLWZNMJOBAVAR_TCOLEN;
	if (s == "pnlwznmjobavar.tcoshr") return PNLWZNMJOBAVAR_TCOSHR;
	if (s == "pnlwznmjobavar.tcocmt") return PNLWZNMJOBAVAR_TCOCMT;
	if (s == "pnlwznmjobacmd.tcosrf") return PNLWZNMJOBACMD_TCOSRF;
	if (s == "pnlwznmjobacmd.tcocmt") return PNLWZNMJOBACMD_TCOCMT;
	if (s == "pnlwznmjob1nmethod.tcoref") return PNLWZNMJOB1NMETHOD_TCOREF;
	if (s == "pnlwznmjob1nsensitivity.tcoref") return PNLWZNMJOB1NSENSITIVITY_TCOREF;
	if (s == "pnlwznmjobjob1nstage.tcoref") return PNLWZNMJOBJOB1NSTAGE_TCOREF;
	if (s == "pnlwznmjob1nrtjob.tcoref") return PNLWZNMJOB1NRTJOB_TCOREF;
	if (s == "pnlwznmjobhk1nvector.tcoref") return PNLWZNMJOBHK1NVECTOR_TCOREF;
	if (s == "pnlwznmjobref1nblock.tcoref") return PNLWZNMJOBREF1NBLOCK_TCOREF;
	if (s == "pnlwznmjobmnoppack.tcomref") return PNLWZNMJOBMNOPPACK_TCOMREF;
	if (s == "pnlwznmjobmnop.tcomref") return PNLWZNMJOBMNOP_TCOMREF;
	if (s == "pnlwznmjobsupmnjob.tcomref") return PNLWZNMJOBSUPMNJOB_TCOMREF;
	if (s == "pnlwznmjobsupmnjob.tcosho") return PNLWZNMJOBSUPMNJOB_TCOSHO;
	if (s == "pnlwznmjobsupmnjob.tcomlt") return PNLWZNMJOBSUPMNJOB_TCOMLT;
	if (s == "pnlwznmjobsupmnjob.tcocsa") return PNLWZNMJOBSUPMNJOB_TCOCSA;
	if (s == "pnlwznmjobsubmnjob.tcomref") return PNLWZNMJOBSUBMNJOB_TCOMREF;
	if (s == "pnlwznmjobsubmnjob.tcosho") return PNLWZNMJOBSUBMNJOB_TCOSHO;
	if (s == "pnlwznmjobsubmnjob.tcomlt") return PNLWZNMJOBSUBMNJOB_TCOMLT;
	if (s == "pnlwznmjobsubmnjob.tcocsa") return PNLWZNMJOBSUBMNJOB_TCOCSA;
	if (s == "pnlwznmsgelist.tcosrf") return PNLWZNMSGELIST_TCOSRF;
	if (s == "pnlwznmsgelist.tcotyp") return PNLWZNMSGELIST_TCOTYP;
	if (s == "pnlwznmsgelist.tcojob") return PNLWZNMSGELIST_TCOJOB;
	if (s == "pnlwznmsge1nsensitivity.tcoref") return PNLWZNMSGE1NSENSITIVITY_TCOREF;
	if (s == "pnlwznmsgesqkmnstub.tcomref") return PNLWZNMSGESQKMNSTUB_TCOMREF;
	if (s == "pnlwznmmtdlist.tcosrf") return PNLWZNMMTDLIST_TCOSRF;
	if (s == "pnlwznmmtdlist.tcojob") return PNLWZNMMTDLIST_TCOJOB;
	if (s == "pnlwznmmtdlist.tcoexs") return PNLWZNMMTDLIST_TCOEXS;
	if (s == "pnlwznmmtdainvpar.tcosrf") return PNLWZNMMTDAINVPAR_TCOSRF;
	if (s == "pnlwznmmtdainvpar.tcovty") return PNLWZNMMTDAINVPAR_TCOVTY;
	if (s == "pnlwznmmtdainvpar.tcovec") return PNLWZNMMTDAINVPAR_TCOVEC;
	if (s == "pnlwznmmtdainvpar.tcolen") return PNLWZNMMTDAINVPAR_TCOLEN;
	if (s == "pnlwznmmtdainvpar.tcocmt") return PNLWZNMMTDAINVPAR_TCOCMT;
	if (s == "pnlwznmmtdaretpar.tcosrf") return PNLWZNMMTDARETPAR_TCOSRF;
	if (s == "pnlwznmmtdaretpar.tcovty") return PNLWZNMMTDARETPAR_TCOVTY;
	if (s == "pnlwznmmtdaretpar.tcovec") return PNLWZNMMTDARETPAR_TCOVEC;
	if (s == "pnlwznmmtdaretpar.tcolen") return PNLWZNMMTDARETPAR_TCOLEN;
	if (s == "pnlwznmmtdaretpar.tcocmt") return PNLWZNMMTDARETPAR_TCOCMT;
	if (s == "pnlwznmblklist.tcosrf") return PNLWZNMBLKLIST_TCOSRF;
	if (s == "pnlwznmblklist.tcotyp") return PNLWZNMBLKLIST_TCOTYP;
	if (s == "pnlwznmblklist.tcover") return PNLWZNMBLKLIST_TCOVER;
	if (s == "pnlwznmblklist.tcoret") return PNLWZNMBLKLIST_TCORET;
	if (s == "pnlwznmblklist.tcoreu") return PNLWZNMBLKLIST_TCOREU;
	if (s == "pnlwznmblkaitem.tcotyp") return PNLWZNMBLKAITEM_TCOTYP;
	if (s == "pnlwznmblkaitem.tcosrf") return PNLWZNMBLKAITEM_TCOSRF;
	if (s == "pnlwznmblkaitem.tcovty") return PNLWZNMBLKAITEM_TCOVTY;
	if (s == "pnlwznmblkaitem.tcocon") return PNLWZNMBLKAITEM_TCOCON;
	if (s == "pnlwznmblkaitem.tcovec") return PNLWZNMBLKAITEM_TCOVEC;
	if (s == "pnlwznmblkaitem.tcofed") return PNLWZNMBLKAITEM_TCOFED;
	if (s == "pnlwznmblkaitem.tcotbl") return PNLWZNMBLKAITEM_TCOTBL;
	if (s == "pnlwznmblkaitem.tcobl2") return PNLWZNMBLKAITEM_TCOBL2;
	if (s == "pnlwznmblkaitem.tcodfv") return PNLWZNMBLKAITEM_TCODFV;
	if (s == "pnlwznmblkaitem.tcovit") return PNLWZNMBLKAITEM_TCOVIT;
	if (s == "pnlwznmblkaitem.tcocmt") return PNLWZNMBLKAITEM_TCOCMT;
	if (s == "pnlwznmblk1nrtdpch.tcoref") return PNLWZNMBLK1NRTDPCH_TCOREF;
	if (s == "pnlwznmblkref1nrtblock.tcoref") return PNLWZNMBLKREF1NRTBLOCK_TCOREF;
	if (s == "pnlwznmcallist.tcosrf") return PNLWZNMCALLIST_TCOSRF;
	if (s == "pnlwznmcallist.tcotyp") return PNLWZNMCALLIST_TCOTYP;
	if (s == "pnlwznmcallist.tcover") return PNLWZNMCALLIST_TCOVER;
	if (s == "pnlwznmcallist.tcoret") return PNLWZNMCALLIST_TCORET;
	if (s == "pnlwznmcallist.tcoreu") return PNLWZNMCALLIST_TCOREU;
	if (s == "pnlwznmcallist.tcoiat") return PNLWZNMCALLIST_TCOIAT;
	if (s == "pnlwznmcallist.tcorat") return PNLWZNMCALLIST_TCORAT;
	if (s == "pnlwznmcal1nsensitivity.tcoref") return PNLWZNMCAL1NSENSITIVITY_TCOREF;
	if (s == "pnlwznmcalmnstub.tcomref") return PNLWZNMCALMNSTUB_TCOMREF;
	if (s == "pnlwznmcmplist.tcosrf") return PNLWZNMCMPLIST_TCOSRF;
	if (s == "pnlwznmcmplist.tcotit") return PNLWZNMCMPLIST_TCOTIT;
	if (s == "pnlwznmcmplist.tcotyp") return PNLWZNMCMPLIST_TCOTYP;
	if (s == "pnlwznmcmplist.tcover") return PNLWZNMCMPLIST_TCOVER;
	if (s == "pnlwznmcmp1nrelease.tcoref") return PNLWZNMCMP1NRELEASE_TCOREF;
	if (s == "pnlwznmcmpmnlibrary.tcomref") return PNLWZNMCMPMNLIBRARY_TCOMREF;
	if (s == "pnlwznmcmpmnoppack.tcomref") return PNLWZNMCMPMNOPPACK_TCOMREF;
	if (s == "pnlwznmrlslist.tcosrf") return PNLWZNMRLSLIST_TCOSRF;
	if (s == "pnlwznmrlslist.tcocmp") return PNLWZNMRLSLIST_TCOCMP;
	if (s == "pnlwznmrlslist.tcomch") return PNLWZNMRLSLIST_TCOMCH;
	if (s == "pnlwznmapplist.tcogrp") return PNLWZNMAPPLIST_TCOGRP;
	if (s == "pnlwznmapplist.tcoown") return PNLWZNMAPPLIST_TCOOWN;
	if (s == "pnlwznmapplist.tcosho") return PNLWZNMAPPLIST_TCOSHO;
	if (s == "pnlwznmapplist.tcotit") return PNLWZNMAPPLIST_TCOTIT;
	if (s == "pnlwznmapplist.tcotrg") return PNLWZNMAPPLIST_TCOTRG;
	if (s == "pnlwznmapplist.tcover") return PNLWZNMAPPLIST_TCOVER;
	if (s == "pnlwznmapp1nevent.tcoref") return PNLWZNMAPP1NEVENT_TCOREF;
	if (s == "pnlwznmappapp1nsequence.tcoref") return PNLWZNMAPPAPP1NSEQUENCE_TCOREF;
	if (s == "pnlwznmapp1nrtjob.tcoref") return PNLWZNMAPP1NRTJOB_TCOREF;
	if (s == "pnlwznmappref1nfile.tcoref") return PNLWZNMAPPREF1NFILE_TCOREF;
	if (s == "pnlwznmrtjlist.tcosrf") return PNLWZNMRTJLIST_TCOSRF;
	if (s == "pnlwznmrtjlist.tcoapp") return PNLWZNMRTJLIST_TCOAPP;
	if (s == "pnlwznmrtjlist.tcosup") return PNLWZNMRTJLIST_TCOSUP;
	if (s == "pnlwznmrtjlist.tcojob") return PNLWZNMRTJLIST_TCOJOB;
	if (s == "pnlwznmrtj1nrtdpch.tcoref") return PNLWZNMRTJ1NRTDPCH_TCOREF;
	if (s == "pnlwznmrtj1nrtblock.tcoref") return PNLWZNMRTJ1NRTBLOCK_TCOREF;
	if (s == "pnlwznmrtjsup1nrtjob.tcoref") return PNLWZNMRTJSUP1NRTJOB_TCOREF;
	if (s == "pnlwznmevtlist.tcosrf") return PNLWZNMEVTLIST_TCOSRF;
	if (s == "pnlwznmevtlist.tcoapp") return PNLWZNMEVTLIST_TCOAPP;
	if (s == "pnlwznmseqlist.tcosrf") return PNLWZNMSEQLIST_TCOSRF;
	if (s == "pnlwznmseqlist.tcotit") return PNLWZNMSEQLIST_TCOTIT;
	if (s == "pnlwznmseqlist.tcoapp") return PNLWZNMSEQLIST_TCOAPP;
	if (s == "pnlwznmseqseq1nstate.tcoref") return PNLWZNMSEQSEQ1NSTATE_TCOREF;
	if (s == "pnlwznmstelist.tcosrf") return PNLWZNMSTELIST_TCOSRF;
	if (s == "pnlwznmstelist.tcoseq") return PNLWZNMSTELIST_TCOSEQ;
	if (s == "pnlwznmsteatrig.tcosrf") return PNLWZNMSTEATRIG_TCOSRF;
	if (s == "pnlwznmsteatrig.tcotyp") return PNLWZNMSTEATRIG_TCOTYP;
	if (s == "pnlwznmsteatrig.tcoevt") return PNLWZNMSTEATRIG_TCOEVT;
	if (s == "pnlwznmsteatrig.tcortj") return PNLWZNMSTEATRIG_TCORTJ;
	if (s == "pnlwznmsteatrig.tcovit") return PNLWZNMSTEATRIG_TCOVIT;
	if (s == "pnlwznmsteatrig.tcoxsr") return PNLWZNMSTEATRIG_TCOXSR;
	if (s == "pnlwznmsteatrig.tcortd") return PNLWZNMSTEATRIG_TCORTD;
	if (s == "pnlwznmsteatrig.tcomsk") return PNLWZNMSTEATRIG_TCOMSK;
	if (s == "pnlwznmsteatrig.tcocnd") return PNLWZNMSTEATRIG_TCOCND;
	if (s == "pnlwznmsteaaction.tcosct") return PNLWZNMSTEAACTION_TCOSCT;
	if (s == "pnlwznmsteaaction.tcotyp") return PNLWZNMSTEAACTION_TCOTYP;
	if (s == "pnlwznmsteaaction.tcotrj") return PNLWZNMSTEAACTION_TCOTRJ;
	if (s == "pnlwznmsteaaction.tcovec") return PNLWZNMSTEAACTION_TCOVEC;
	if (s == "pnlwznmsteaaction.tcovit") return PNLWZNMSTEAACTION_TCOVIT;
	if (s == "pnlwznmsteaaction.tcosnx") return PNLWZNMSTEAACTION_TCOSNX;
	if (s == "pnlwznmsteaaction.tcoseq") return PNLWZNMSTEAACTION_TCOSEQ;
	if (s == "pnlwznmsteaaction.tcotr1") return PNLWZNMSTEAACTION_TCOTR1;
	if (s == "pnlwznmsteaaction.tcoip1") return PNLWZNMSTEAACTION_TCOIP1;
	if (s == "pnlwznmsteaaction.tcotr2") return PNLWZNMSTEAACTION_TCOTR2;
	if (s == "pnlwznmsteaaction.tcoip2") return PNLWZNMSTEAACTION_TCOIP2;
	if (s == "pnlwznmsteaaction.tcotr3") return PNLWZNMSTEAACTION_TCOTR3;
	if (s == "pnlwznmsteaaction.tcoip3") return PNLWZNMSTEAACTION_TCOIP3;
	if (s == "pnlwznmsteaaction.tcotr4") return PNLWZNMSTEAACTION_TCOTR4;
	if (s == "pnlwznmsteaaction.tcoip4") return PNLWZNMSTEAACTION_TCOIP4;

	return(0);
};

string DbsWznm::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLWZNMUSGLIST_TCOGRP) return("PnlWznmUsgList.TcoGrp");
	if (ix == PNLWZNMUSGLIST_TCOOWN) return("PnlWznmUsgList.TcoOwn");
	if (ix == PNLWZNMUSGLIST_TCOSRF) return("PnlWznmUsgList.TcoSrf");
	if (ix == PNLWZNMUSGAACCESS_TCOFEG) return("PnlWznmUsgAAccess.TcoFeg");
	if (ix == PNLWZNMUSGAACCESS_TCOFEA) return("PnlWznmUsgAAccess.TcoFea");
	if (ix == PNLWZNMUSGAACCESS_TCOACC) return("PnlWznmUsgAAccess.TcoAcc");
	if (ix == PNLWZNMUSGMNUSER_TCOMREF) return("PnlWznmUsgMNUser.TcoMref");
	if (ix == PNLWZNMUSGMNUSER_TCOULV) return("PnlWznmUsgMNUser.TcoUlv");
	if (ix == PNLWZNMUSRLIST_TCOGRP) return("PnlWznmUsrList.TcoGrp");
	if (ix == PNLWZNMUSRLIST_TCOOWN) return("PnlWznmUsrList.TcoOwn");
	if (ix == PNLWZNMUSRLIST_TCOPRS) return("PnlWznmUsrList.TcoPrs");
	if (ix == PNLWZNMUSRLIST_TCOSRF) return("PnlWznmUsrList.TcoSrf");
	if (ix == PNLWZNMUSRLIST_TCOUSG) return("PnlWznmUsrList.TcoUsg");
	if (ix == PNLWZNMUSRLIST_TCOSTE) return("PnlWznmUsrList.TcoSte");
	if (ix == PNLWZNMUSRLIST_TCOLCL) return("PnlWznmUsrList.TcoLcl");
	if (ix == PNLWZNMUSRLIST_TCOULV) return("PnlWznmUsrList.TcoUlv");
	if (ix == PNLWZNMUSRAACCESS_TCOFEG) return("PnlWznmUsrAAccess.TcoFeg");
	if (ix == PNLWZNMUSRAACCESS_TCOFEA) return("PnlWznmUsrAAccess.TcoFea");
	if (ix == PNLWZNMUSRAACCESS_TCOACC) return("PnlWznmUsrAAccess.TcoAcc");
	if (ix == PNLWZNMUSR1NSESSION_TCOREF) return("PnlWznmUsr1NSession.TcoRef");
	if (ix == PNLWZNMUSRMNUSERGROUP_TCOMREF) return("PnlWznmUsrMNUsergroup.TcoMref");
	if (ix == PNLWZNMUSRMNUSERGROUP_TCOULV) return("PnlWznmUsrMNUsergroup.TcoUlv");
	if (ix == PNLWZNMPRSLIST_TCOGRP) return("PnlWznmPrsList.TcoGrp");
	if (ix == PNLWZNMPRSLIST_TCOOWN) return("PnlWznmPrsList.TcoOwn");
	if (ix == PNLWZNMPRSLIST_TCOTIT) return("PnlWznmPrsList.TcoTit");
	if (ix == PNLWZNMPRSLIST_TCOFNM) return("PnlWznmPrsList.TcoFnm");
	if (ix == PNLWZNMPRSLIST_TCOLNM) return("PnlWznmPrsList.TcoLnm");
	if (ix == PNLWZNMPRSLIST_TCOSEX) return("PnlWznmPrsList.TcoSex");
	if (ix == PNLWZNMPRSLIST_TCOTEL) return("PnlWznmPrsList.TcoTel");
	if (ix == PNLWZNMPRSLIST_TCOEML) return("PnlWznmPrsList.TcoEml");
	if (ix == PNLWZNMPRSADETAIL_TCOTYP) return("PnlWznmPrsADetail.TcoTyp");
	if (ix == PNLWZNMPRSADETAIL_TCOVAL) return("PnlWznmPrsADetail.TcoVal");
	if (ix == PNLWZNMPRSMNPROJECT_TCOMREF) return("PnlWznmPrsMNProject.TcoMref");
	if (ix == PNLWZNMPRSMNPROJECT_TCOSTA) return("PnlWznmPrsMNProject.TcoSta");
	if (ix == PNLWZNMPRSMNPROJECT_TCOSTO) return("PnlWznmPrsMNProject.TcoSto");
	if (ix == PNLWZNMPRSMNPROJECT_TCOFCT) return("PnlWznmPrsMNProject.TcoFct");
	if (ix == PNLWZNMFILLIST_TCOGRP) return("PnlWznmFilList.TcoGrp");
	if (ix == PNLWZNMFILLIST_TCOOWN) return("PnlWznmFilList.TcoOwn");
	if (ix == PNLWZNMFILLIST_TCOFNM) return("PnlWznmFilList.TcoFnm");
	if (ix == PNLWZNMFILLIST_TCORET) return("PnlWznmFilList.TcoRet");
	if (ix == PNLWZNMFILLIST_TCOREU) return("PnlWznmFilList.TcoReu");
	if (ix == PNLWZNMFILLIST_TCOCNT) return("PnlWznmFilList.TcoCnt");
	if (ix == PNLWZNMFILLIST_TCOMIM) return("PnlWznmFilList.TcoMim");
	if (ix == PNLWZNMFILLIST_TCOSIZ) return("PnlWznmFilList.TcoSiz");
	if (ix == PNLWZNMLOCLIST_TCOSRF) return("PnlWznmLocList.TcoSrf");
	if (ix == PNLWZNMLOCLIST_TCOTIT) return("PnlWznmLocList.TcoTit");
	if (ix == PNLWZNMLOCMNVERSION_TCOMREF) return("PnlWznmLocMNVersion.TcoMref");
	if (ix == PNLWZNMTAGLIST_TCOSRF) return("PnlWznmTagList.TcoSrf");
	if (ix == PNLWZNMTAGLIST_TCOTIT) return("PnlWznmTagList.TcoTit");
	if (ix == PNLWZNMTAGLIST_TCOCPB) return("PnlWznmTagList.TcoCpb");
	if (ix == PNLWZNMTAGLIST_TCOGRP) return("PnlWznmTagList.TcoGrp");
	if (ix == PNLWZNMCTPLIST_TCOSRF) return("PnlWznmCtpList.TcoSrf");
	if (ix == PNLWZNMCTPLIST_TCOTIT) return("PnlWznmCtpList.TcoTit");
	if (ix == PNLWZNMCTPLIST_TCOVER) return("PnlWznmCtpList.TcoVer");
	if (ix == PNLWZNMCTPLIST_TCOATF) return("PnlWznmCtpList.TcoAtf");
	if (ix == PNLWZNMCTPKPARKEY_TCOFIX) return("PnlWznmCtpKParKey.TcoFix");
	if (ix == PNLWZNMCTPKPARKEY_TCOSRF) return("PnlWznmCtpKParKey.TcoSrf");
	if (ix == PNLWZNMCTPKPARKEY_TCOAVL) return("PnlWznmCtpKParKey.TcoAvl");
	if (ix == PNLWZNMCTPKPARKEY_TCOIMP) return("PnlWznmCtpKParKey.TcoImp");
	if (ix == PNLWZNMCTPKPARKEY_TCOTIT) return("PnlWznmCtpKParKey.TcoTit");
	if (ix == PNLWZNMCTPKPARKEY_TCOCMT) return("PnlWznmCtpKParKey.TcoCmt");
	if (ix == PNLWZNMCTPKKEY_TCOFIX) return("PnlWznmCtpKKey.TcoFix");
	if (ix == PNLWZNMCTPKKEY_TCOSRF) return("PnlWznmCtpKKey.TcoSrf");
	if (ix == PNLWZNMCTPKKEY_TCOAVL) return("PnlWznmCtpKKey.TcoAvl");
	if (ix == PNLWZNMCTPKKEY_TCOIMP) return("PnlWznmCtpKKey.TcoImp");
	if (ix == PNLWZNMCTPKKEY_TCOTIT) return("PnlWznmCtpKKey.TcoTit");
	if (ix == PNLWZNMCTPKKEY_TCOCMT) return("PnlWznmCtpKKey.TcoCmt");
	if (ix == PNLWZNMCTPAPAR_TCOKEY) return("PnlWznmCtpAPar.TcoKey");
	if (ix == PNLWZNMCTPAPAR_TCOVAL) return("PnlWznmCtpAPar.TcoVal");
	if (ix == PNLWZNMCTP1NTAG_TCOREF) return("PnlWznmCtp1NTag.TcoRef");
	if (ix == PNLWZNMCTPTPL1NCAPABILITY_TCOREF) return("PnlWznmCtpTpl1NCapability.TcoRef");
	if (ix == PNLWZNMMCHLIST_TCOSRF) return("PnlWznmMchList.TcoSrf");
	if (ix == PNLWZNMMCHLIST_TCOSUP) return("PnlWznmMchList.TcoSup");
	if (ix == PNLWZNMMCHAMAKEFILE_TCOTAG) return("PnlWznmMchAMakefile.TcoTag");
	if (ix == PNLWZNMMCHAMAKEFILE_TCOVAL) return("PnlWznmMchAMakefile.TcoVal");
	if (ix == PNLWZNMMCHAPAR_TCOKEY) return("PnlWznmMchAPar.TcoKey");
	if (ix == PNLWZNMMCHAPAR_TCOVAL) return("PnlWznmMchAPar.TcoVal");
	if (ix == PNLWZNMMCH1NRELEASE_TCOREF) return("PnlWznmMch1NRelease.TcoRef");
	if (ix == PNLWZNMMCHSUP1NMACHINE_TCOREF) return("PnlWznmMchSup1NMachine.TcoRef");
	if (ix == PNLWZNMLIBLIST_TCOSRF) return("PnlWznmLibList.TcoSrf");
	if (ix == PNLWZNMLIBLIST_TCOTIT) return("PnlWznmLibList.TcoTit");
	if (ix == PNLWZNMLIBLIST_TCOVER) return("PnlWznmLibList.TcoVer");
	if (ix == PNLWZNMLIBLIST_TCOLTY) return("PnlWznmLibList.TcoLty");
	if (ix == PNLWZNMLIBAMAKEFILE_TCOMCH) return("PnlWznmLibAMakefile.TcoMch");
	if (ix == PNLWZNMLIBAMAKEFILE_TCOTAG) return("PnlWznmLibAMakefile.TcoTag");
	if (ix == PNLWZNMLIBAMAKEFILE_TCOVAL) return("PnlWznmLibAMakefile.TcoVal");
	if (ix == PNLWZNMLIBAPKGLIST_TCOMCH) return("PnlWznmLibAPkglist.TcoMch");
	if (ix == PNLWZNMLIBAPKGLIST_TCOPKL) return("PnlWznmLibAPkglist.TcoPkl");
	if (ix == PNLWZNMLIBREF1NFILE_TCOREF) return("PnlWznmLibRef1NFile.TcoRef");
	if (ix == PNLWZNMLIBMNOPPACK_TCOMREF) return("PnlWznmLibMNOppack.TcoMref");
	if (ix == PNLWZNMLIBMNCOMPONENT_TCOMREF) return("PnlWznmLibMNComponent.TcoMref");
	if (ix == PNLWZNMPRJLIST_TCOGRP) return("PnlWznmPrjList.TcoGrp");
	if (ix == PNLWZNMPRJLIST_TCOOWN) return("PnlWznmPrjList.TcoOwn");
	if (ix == PNLWZNMPRJLIST_TCOSHO) return("PnlWznmPrjList.TcoSho");
	if (ix == PNLWZNMPRJLIST_TCOTIT) return("PnlWznmPrjList.TcoTit");
	if (ix == PNLWZNMPRJLIST_TCOVER) return("PnlWznmPrjList.TcoVer");
	if (ix == PNLWZNMPRJLIST_TCOGRL) return("PnlWznmPrjList.TcoGrl");
	if (ix == PNLWZNMPRJPRJ1NVERSION_TCOREF) return("PnlWznmPrjPrj1NVersion.TcoRef");
	if (ix == PNLWZNMPRJMNPERSON_TCOMREF) return("PnlWznmPrjMNPerson.TcoMref");
	if (ix == PNLWZNMPRJMNPERSON_TCOSTA) return("PnlWznmPrjMNPerson.TcoSta");
	if (ix == PNLWZNMPRJMNPERSON_TCOSTO) return("PnlWznmPrjMNPerson.TcoSto");
	if (ix == PNLWZNMPRJMNPERSON_TCOFCT) return("PnlWznmPrjMNPerson.TcoFct");
	if (ix == PNLWZNMVERLIST_TCOGRP) return("PnlWznmVerList.TcoGrp");
	if (ix == PNLWZNMVERLIST_TCOOWN) return("PnlWznmVerList.TcoOwn");
	if (ix == PNLWZNMVERLIST_TCOPRJ) return("PnlWznmVerList.TcoPrj");
	if (ix == PNLWZNMVERLIST_TCOMAJ) return("PnlWznmVerList.TcoMaj");
	if (ix == PNLWZNMVERLIST_TCOMIN) return("PnlWznmVerList.TcoMin");
	if (ix == PNLWZNMVERLIST_TCOSUB) return("PnlWznmVerList.TcoSub");
	if (ix == PNLWZNMVERLIST_TCOBVR) return("PnlWznmVerList.TcoBvr");
	if (ix == PNLWZNMVERLIST_TCOLOC) return("PnlWznmVerList.TcoLoc");
	if (ix == PNLWZNMVERLIST_TCOSTE) return("PnlWznmVerList.TcoSte");
	if (ix == PNLWZNMVERLIST_TCODTY) return("PnlWznmVerList.TcoDty");
	if (ix == PNLWZNMVERVER1NERROR_TCOREF) return("PnlWznmVerVer1NError.TcoRef");
	if (ix == PNLWZNMVER1NCOMPONENT_TCOREF) return("PnlWznmVer1NComponent.TcoRef");
	if (ix == PNLWZNMVER1NCALL_TCOREF) return("PnlWznmVer1NCall.TcoRef");
	if (ix == PNLWZNMVER1NIMPEXPCPLX_TCOREF) return("PnlWznmVer1NImpexpcplx.TcoRef");
	if (ix == PNLWZNMVER1NJOB_TCOREF) return("PnlWznmVer1NJob.TcoRef");
	if (ix == PNLWZNMVER1NOPPACK_TCOREF) return("PnlWznmVer1NOppack.TcoRef");
	if (ix == PNLWZNMVERVER1NMODULE_TCOREF) return("PnlWznmVerVer1NModule.TcoRef");
	if (ix == PNLWZNMVER1NPRESET_TCOREF) return("PnlWznmVer1NPreset.TcoRef");
	if (ix == PNLWZNMVER1NQUERY_TCOREF) return("PnlWznmVer1NQuery.TcoRef");
	if (ix == PNLWZNMVER1NRELATION_TCOREF) return("PnlWznmVer1NRelation.TcoRef");
	if (ix == PNLWZNMVER1NTABLE_TCOREF) return("PnlWznmVer1NTable.TcoRef");
	if (ix == PNLWZNMVER1NVECTOR_TCOREF) return("PnlWznmVer1NVector.TcoRef");
	if (ix == PNLWZNMVERVER1NAPP_TCOREF) return("PnlWznmVerVer1NApp.TcoRef");
	if (ix == PNLWZNMVER1NCAPABILITY_TCOREF) return("PnlWznmVer1NCapability.TcoRef");
	if (ix == PNLWZNMVERBVR1NVERSION_TCOREF) return("PnlWznmVerBvr1NVersion.TcoRef");
	if (ix == PNLWZNMVER1NBLOCK_TCOREF) return("PnlWznmVer1NBlock.TcoRef");
	if (ix == PNLWZNMVERREF1NFILE_TCOREF) return("PnlWznmVerRef1NFile.TcoRef");
	if (ix == PNLWZNMVERMNLOCALE_TCOMREF) return("PnlWznmVerMNLocale.TcoMref");
	if (ix == PNLWZNMCAPLIST_TCOSRF) return("PnlWznmCapList.TcoSrf");
	if (ix == PNLWZNMCAPLIST_TCOTIT) return("PnlWznmCapList.TcoTit");
	if (ix == PNLWZNMCAPLIST_TCOVER) return("PnlWznmCapList.TcoVer");
	if (ix == PNLWZNMCAPLIST_TCOTPL) return("PnlWznmCapList.TcoTpl");
	if (ix == PNLWZNMCAPLIST_TCOATF) return("PnlWznmCapList.TcoAtf");
	if (ix == PNLWZNMCAPAPAR_TCOKEY) return("PnlWznmCapAPar.TcoKey");
	if (ix == PNLWZNMCAPAPAR_TCOVAL) return("PnlWznmCapAPar.TcoVal");
	if (ix == PNLWZNMERRLIST_TCOSRF) return("PnlWznmErrList.TcoSrf");
	if (ix == PNLWZNMERRLIST_TCOTIT) return("PnlWznmErrList.TcoTit");
	if (ix == PNLWZNMERRLIST_TCOVER) return("PnlWznmErrList.TcoVer");
	if (ix == PNLWZNMTBLLIST_TCOSRF) return("PnlWznmTblList.TcoSrf");
	if (ix == PNLWZNMTBLLIST_TCOSHO) return("PnlWznmTblList.TcoSho");
	if (ix == PNLWZNMTBLLIST_TCOTYP) return("PnlWznmTblList.TcoTyp");
	if (ix == PNLWZNMTBLLIST_TCOVER) return("PnlWznmTblList.TcoVer");
	if (ix == PNLWZNMTBLLIST_TCORET) return("PnlWznmTblList.TcoRet");
	if (ix == PNLWZNMTBLLIST_TCOREU) return("PnlWznmTblList.TcoReu");
	if (ix == PNLWZNMTBLALOADFCT_TCOLOT) return("PnlWznmTblALoadfct.TcoLot");
	if (ix == PNLWZNMTBLALOADFCT_TCOFNA) return("PnlWznmTblALoadfct.TcoFna");
	if (ix == PNLWZNMTBLALOADFCT_TCOLDX) return("PnlWznmTblALoadfct.TcoLdx");
	if (ix == PNLWZNMTBLALOADFCT_TCOLBY) return("PnlWznmTblALoadfct.TcoLby");
	if (ix == PNLWZNMTBLALOADFCT_TCOORD) return("PnlWznmTblALoadfct.TcoOrd");
	if (ix == PNLWZNMTBLALOADFCT_TCOLIT) return("PnlWznmTblALoadfct.TcoLit");
	if (ix == PNLWZNMTBLATITLE_TCOTYP) return("PnlWznmTblATitle.TcoTyp");
	if (ix == PNLWZNMTBLATITLE_TCOLOC) return("PnlWznmTblATitle.TcoLoc");
	if (ix == PNLWZNMTBLATITLE_TCOGND) return("PnlWznmTblATitle.TcoGnd");
	if (ix == PNLWZNMTBLATITLE_TCOTIT) return("PnlWznmTblATitle.TcoTit");
	if (ix == PNLWZNMTBL1NIMPEXP_TCOREF) return("PnlWznmTbl1NImpexp.TcoRef");
	if (ix == PNLWZNMTBL1NCHECK_TCOREF) return("PnlWznmTbl1NCheck.TcoRef");
	if (ix == PNLWZNMTBLFR1NRELATION_TCOREF) return("PnlWznmTblFr1NRelation.TcoRef");
	if (ix == PNLWZNMTBLTO1NRELATION_TCOREF) return("PnlWznmTblTo1NRelation.TcoRef");
	if (ix == PNLWZNMTBL1NSTUB_TCOREF) return("PnlWznmTbl1NStub.TcoRef");
	if (ix == PNLWZNMTBL1NSUBSET_TCOREF) return("PnlWznmTbl1NSubset.TcoRef");
	if (ix == PNLWZNMTBLTBL1NTABLECOL_TCOREF) return("PnlWznmTblTbl1NTablecol.TcoRef");
	if (ix == PNLWZNMTBLREF1NDIALOG_TCOREF) return("PnlWznmTblRef1NDialog.TcoRef");
	if (ix == PNLWZNMTBLREF1NCALL_TCOREF) return("PnlWznmTblRef1NCall.TcoRef");
	if (ix == PNLWZNMTBLSRC1NFEED_TCOREF) return("PnlWznmTblSrc1NFeed.TcoRef");
	if (ix == PNLWZNMTBLREF1NPANEL_TCOREF) return("PnlWznmTblRef1NPanel.TcoRef");
	if (ix == PNLWZNMTBLFCT1NTABLECOL_TCOREF) return("PnlWznmTblFct1NTablecol.TcoRef");
	if (ix == PNLWZNMTBLHK1NVECTOR_TCOREF) return("PnlWznmTblHk1NVector.TcoRef");
	if (ix == PNLWZNMTBLREF1NRTBLOCK_TCOREF) return("PnlWznmTblRef1NRtblock.TcoRef");
	if (ix == PNLWZNMTBLREF1NQUERYMOD_TCOREF) return("PnlWznmTblRef1NQuerymod.TcoRef");
	if (ix == PNLWZNMTBLPST1NQUERYMOD_TCOREF) return("PnlWznmTblPst1NQuerymod.TcoRef");
	if (ix == PNLWZNMTBLMNVECTOR_TCOMREF) return("PnlWznmTblMNVector.TcoMref");
	if (ix == PNLWZNMTBLMNVECTOR_TCOSBS) return("PnlWznmTblMNVector.TcoSbs");
	if (ix == PNLWZNMTBLMNQUERY_TCOMREF) return("PnlWznmTblMNQuery.TcoMref");
	if (ix == PNLWZNMTBLMNQUERY_TCOTQMD) return("PnlWznmTblMNQuery.TcoTqmd");
	if (ix == PNLWZNMTBLMNQUERY_TCOSRC) return("PnlWznmTblMNQuery.TcoSrc");
	if (ix == PNLWZNMTBLMNQUERY_TCOPFX) return("PnlWznmTblMNQuery.TcoPfx");
	if (ix == PNLWZNMTCOLIST_TCOSRF) return("PnlWznmTcoList.TcoSrf");
	if (ix == PNLWZNMTCOLIST_TCOSHO) return("PnlWznmTcoList.TcoSho");
	if (ix == PNLWZNMTCOLIST_TCOTYP) return("PnlWznmTcoList.TcoTyp");
	if (ix == PNLWZNMTCOLIST_TCOTBL) return("PnlWznmTcoList.TcoTbl");
	if (ix == PNLWZNMTCOLIST_TCOFCT) return("PnlWznmTcoList.TcoFct");
	if (ix == PNLWZNMTCOLIST_TCOSTY) return("PnlWznmTcoList.TcoSty");
	if (ix == PNLWZNMTCOLIST_TCOAXF) return("PnlWznmTcoList.TcoAxf");
	if (ix == PNLWZNMTCOATITLE_TCOTYP) return("PnlWznmTcoATitle.TcoTyp");
	if (ix == PNLWZNMTCOATITLE_TCOLOC) return("PnlWznmTcoATitle.TcoLoc");
	if (ix == PNLWZNMTCOATITLE_TCOTIT) return("PnlWznmTcoATitle.TcoTit");
	if (ix == PNLWZNMTCO1NIMPEXPCOL_TCOREF) return("PnlWznmTco1NImpexpcol.TcoRef");
	if (ix == PNLWZNMTCO1NQUERYCOL_TCOREF) return("PnlWznmTco1NQuerycol.TcoRef");
	if (ix == PNLWZNMTCOREF1NCONTROL_TCOREF) return("PnlWznmTcoRef1NControl.TcoRef");
	if (ix == PNLWZNMTCOREF1NQUERYMOD_TCOREF) return("PnlWznmTcoRef1NQuerymod.TcoRef");
	if (ix == PNLWZNMTCO1NCHECK_TCOREF) return("PnlWznmTco1NCheck.TcoRef");
	if (ix == PNLWZNMSBSLIST_TCOSRF) return("PnlWznmSbsList.TcoSrf");
	if (ix == PNLWZNMSBSLIST_TCOSHO) return("PnlWznmSbsList.TcoSho");
	if (ix == PNLWZNMSBSLIST_TCOTBL) return("PnlWznmSbsList.TcoTbl");
	if (ix == PNLWZNMSBSATITLE_TCOTYP) return("PnlWznmSbsATitle.TcoTyp");
	if (ix == PNLWZNMSBSATITLE_TCOLOC) return("PnlWznmSbsATitle.TcoLoc");
	if (ix == PNLWZNMSBSATITLE_TCOGND) return("PnlWznmSbsATitle.TcoGnd");
	if (ix == PNLWZNMSBSATITLE_TCOTIT) return("PnlWznmSbsATitle.TcoTit");
	if (ix == PNLWZNMSBSFRS1NRELATION_TCOREF) return("PnlWznmSbsFrs1NRelation.TcoRef");
	if (ix == PNLWZNMSBSTOS1NRELATION_TCOREF) return("PnlWznmSbsTos1NRelation.TcoRef");
	if (ix == PNLWZNMSBS1NTABLECOL_TCOREF) return("PnlWznmSbs1NTablecol.TcoRef");
	if (ix == PNLWZNMSBS1NSTUB_TCOREF) return("PnlWznmSbs1NStub.TcoRef");
	if (ix == PNLWZNMSBSPST1NQUERYMOD_TCOREF) return("PnlWznmSbsPst1NQuerymod.TcoRef");
	if (ix == PNLWZNMSBSASBMNSUBSET_TCOMREF) return("PnlWznmSbsAsbMNSubset.TcoMref");
	if (ix == PNLWZNMSBSASBMNSUBSET_TCORTY) return("PnlWznmSbsAsbMNSubset.TcoRty");
	if (ix == PNLWZNMSBSBSBMNSUBSET_TCOMREF) return("PnlWznmSbsBsbMNSubset.TcoMref");
	if (ix == PNLWZNMSBSBSBMNSUBSET_TCORTY) return("PnlWznmSbsBsbMNSubset.TcoRty");
	if (ix == PNLWZNMRELLIST_TCOFRT) return("PnlWznmRelList.TcoFrt");
	if (ix == PNLWZNMRELLIST_TCOFRS) return("PnlWznmRelList.TcoFrs");
	if (ix == PNLWZNMRELLIST_TCOTOT) return("PnlWznmRelList.TcoTot");
	if (ix == PNLWZNMRELLIST_TCOTOS) return("PnlWznmRelList.TcoTos");
	if (ix == PNLWZNMRELLIST_TCOTYP) return("PnlWznmRelList.TcoTyp");
	if (ix == PNLWZNMRELLIST_TCOVER) return("PnlWznmRelList.TcoVer");
	if (ix == PNLWZNMRELLIST_TCOSUP) return("PnlWznmRelList.TcoSup");
	if (ix == PNLWZNMRELLIST_TCOSRL) return("PnlWznmRelList.TcoSrl");
	if (ix == PNLWZNMRELLIST_TCOTBL) return("PnlWznmRelList.TcoTbl");
	if (ix == PNLWZNMRELLIST_TCOPFX) return("PnlWznmRelList.TcoPfx");
	if (ix == PNLWZNMRELATITLE_TCOTYP) return("PnlWznmRelATitle.TcoTyp");
	if (ix == PNLWZNMRELATITLE_TCOLOC) return("PnlWznmRelATitle.TcoLoc");
	if (ix == PNLWZNMRELATITLE_TCOTIT) return("PnlWznmRelATitle.TcoTit");
	if (ix == PNLWZNMRELSUP1NRELATION_TCOREF) return("PnlWznmRelSup1NRelation.TcoRef");
	if (ix == PNLWZNMREL1NTABLECOL_TCOREF) return("PnlWznmRel1NTablecol.TcoRef");
	if (ix == PNLWZNMRELREF1NCONTROL_TCOREF) return("PnlWznmRelRef1NControl.TcoRef");
	if (ix == PNLWZNMRELREF1NDIALOG_TCOREF) return("PnlWznmRelRef1NDialog.TcoRef");
	if (ix == PNLWZNMRELREF1NPANEL_TCOREF) return("PnlWznmRelRef1NPanel.TcoRef");
	if (ix == PNLWZNMVECLIST_TCOSRF) return("PnlWznmVecList.TcoSrf");
	if (ix == PNLWZNMVECLIST_TCOTYP) return("PnlWznmVecList.TcoTyp");
	if (ix == PNLWZNMVECLIST_TCOVER) return("PnlWznmVecList.TcoVer");
	if (ix == PNLWZNMVECLIST_TCOHKT) return("PnlWznmVecList.TcoHkt");
	if (ix == PNLWZNMVECLIST_TCOHKU) return("PnlWznmVecList.TcoHku");
	if (ix == PNLWZNMVECLIST_TCOTGR) return("PnlWznmVecList.TcoTgr");
	if (ix == PNLWZNMVECATITLE_TCOTYP) return("PnlWznmVecATitle.TcoTyp");
	if (ix == PNLWZNMVECATITLE_TCOLOC) return("PnlWznmVecATitle.TcoLoc");
	if (ix == PNLWZNMVECATITLE_TCOTIT) return("PnlWznmVecATitle.TcoTit");
	if (ix == PNLWZNMVECVEC1NVECTORITEM_TCOREF) return("PnlWznmVecVec1NVectoritem.TcoRef");
	if (ix == PNLWZNMVECSRC1NFEED_TCOREF) return("PnlWznmVecSrc1NFeed.TcoRef");
	if (ix == PNLWZNMVECREF1NPANEL_TCOREF) return("PnlWznmVecRef1NPanel.TcoRef");
	if (ix == PNLWZNMVECFCT1NTABLECOL_TCOREF) return("PnlWznmVecFct1NTablecol.TcoRef");
	if (ix == PNLWZNMVECPST1NQUERYMOD_TCOREF) return("PnlWznmVecPst1NQuerymod.TcoRef");
	if (ix == PNLWZNMVECMNTABLE_TCOMREF) return("PnlWznmVecMNTable.TcoMref");
	if (ix == PNLWZNMVECMNTABLE_TCOSBS) return("PnlWznmVecMNTable.TcoSbs");
	if (ix == PNLWZNMVITLIST_TCOSRF) return("PnlWznmVitList.TcoSrf");
	if (ix == PNLWZNMVITLIST_TCOTIT) return("PnlWznmVitList.TcoTit");
	if (ix == PNLWZNMVITLIST_TCOVEC) return("PnlWznmVitList.TcoVec");
	if (ix == PNLWZNMCHKLIST_TCOSRF) return("PnlWznmChkList.TcoSrf");
	if (ix == PNLWZNMCHKLIST_TCOTYP) return("PnlWznmChkList.TcoTyp");
	if (ix == PNLWZNMCHKLIST_TCOTBL) return("PnlWznmChkList.TcoTbl");
	if (ix == PNLWZNMCHKLIST_TCOTCO) return("PnlWznmChkList.TcoTco");
	if (ix == PNLWZNMCHKREF1NCALL_TCOREF) return("PnlWznmChkRef1NCall.TcoRef");
	if (ix == PNLWZNMSTBLIST_TCOSRF) return("PnlWznmStbList.TcoSrf");
	if (ix == PNLWZNMSTBLIST_TCOTYP) return("PnlWznmStbList.TcoTyp");
	if (ix == PNLWZNMSTBLIST_TCOTBL) return("PnlWznmStbList.TcoTbl");
	if (ix == PNLWZNMSTBLIST_TCOSBS) return("PnlWznmStbList.TcoSbs");
	if (ix == PNLWZNMSTBLIST_TCOEXA) return("PnlWznmStbList.TcoExa");
	if (ix == PNLWZNMSTBSUPMNSTUB_TCOMREF) return("PnlWznmStbSupMNStub.TcoMref");
	if (ix == PNLWZNMSTBMNSQUAWK_TCOMREF) return("PnlWznmStbMNSquawk.TcoMref");
	if (ix == PNLWZNMSTBSUBMNSTUB_TCOMREF) return("PnlWznmStbSubMNStub.TcoMref");
	if (ix == PNLWZNMSTBMNCALL_TCOMREF) return("PnlWznmStbMNCall.TcoMref");
	if (ix == PNLWZNMIEXLIST_TCOSRF) return("PnlWznmIexList.TcoSrf");
	if (ix == PNLWZNMIEXLIST_TCOSHO) return("PnlWznmIexList.TcoSho");
	if (ix == PNLWZNMIEXLIST_TCOTIT) return("PnlWznmIexList.TcoTit");
	if (ix == PNLWZNMIEXLIST_TCOVER) return("PnlWznmIexList.TcoVer");
	if (ix == PNLWZNMIEXLIST_TCOMIV) return("PnlWznmIexList.TcoMiv");
	if (ix == PNLWZNMIEX1NIMPEXP_TCOREF) return("PnlWznmIex1NImpexp.TcoRef");
	if (ix == PNLWZNMIEXHK1NVECTOR_TCOREF) return("PnlWznmIexHk1NVector.TcoRef");
	if (ix == PNLWZNMIEXREF1NDIALOG_TCOREF) return("PnlWznmIexRef1NDialog.TcoRef");
	if (ix == PNLWZNMIMELIST_TCOSRF) return("PnlWznmImeList.TcoSrf");
	if (ix == PNLWZNMIMELIST_TCOIEX) return("PnlWznmImeList.TcoIex");
	if (ix == PNLWZNMIMELIST_TCOSUP) return("PnlWznmImeList.TcoSup");
	if (ix == PNLWZNMIMELIST_TCOTBL) return("PnlWznmImeList.TcoTbl");
	if (ix == PNLWZNMIMEIME1NIMPEXPCOL_TCOREF) return("PnlWznmImeIme1NImpexpcol.TcoRef");
	if (ix == PNLWZNMIMESUP1NIMPEXP_TCOREF) return("PnlWznmImeSup1NImpexp.TcoRef");
	if (ix == PNLWZNMIMEHK1NVECTOR_TCOREF) return("PnlWznmImeHk1NVector.TcoRef");
	if (ix == PNLWZNMIELLIST_TCOSRF) return("PnlWznmIelList.TcoSrf");
	if (ix == PNLWZNMIELLIST_TCOSHO) return("PnlWznmIelList.TcoSho");
	if (ix == PNLWZNMIELLIST_TCOTYP) return("PnlWznmIelList.TcoTyp");
	if (ix == PNLWZNMIELLIST_TCOIME) return("PnlWznmIelList.TcoIme");
	if (ix == PNLWZNMIELLIST_TCOTCO) return("PnlWznmIelList.TcoTco");
	if (ix == PNLWZNMIELLIST_TCOCTY) return("PnlWznmIelList.TcoCty");
	if (ix == PNLWZNMPSTLIST_TCOSRF) return("PnlWznmPstList.TcoSrf");
	if (ix == PNLWZNMPSTLIST_TCOTIT) return("PnlWznmPstList.TcoTit");
	if (ix == PNLWZNMPSTLIST_TCOVER) return("PnlWznmPstList.TcoVer");
	if (ix == PNLWZNMPSTLIST_TCORET) return("PnlWznmPstList.TcoRet");
	if (ix == PNLWZNMPSTLIST_TCOREU) return("PnlWznmPstList.TcoReu");
	if (ix == PNLWZNMPSTLIST_TCOATY) return("PnlWznmPstList.TcoAty");
	if (ix == PNLWZNMPST1NQUERYMOD_TCOREF) return("PnlWznmPst1NQuerymod.TcoRef");
	if (ix == PNLWZNMMDLLIST_TCOSRF) return("PnlWznmMdlList.TcoSrf");
	if (ix == PNLWZNMMDLLIST_TCOTIT) return("PnlWznmMdlList.TcoTit");
	if (ix == PNLWZNMMDLLIST_TCOVER) return("PnlWznmMdlList.TcoVer");
	if (ix == PNLWZNMMDLMDL1NCARD_TCOREF) return("PnlWznmMdlMdl1NCard.TcoRef");
	if (ix == PNLWZNMMDLREF1NPANEL_TCOREF) return("PnlWznmMdlRef1NPanel.TcoRef");
	if (ix == PNLWZNMCARLIST_TCOSRF) return("PnlWznmCarList.TcoSrf");
	if (ix == PNLWZNMCARLIST_TCOTIT) return("PnlWznmCarList.TcoTit");
	if (ix == PNLWZNMCARLIST_TCOMDL) return("PnlWznmCarList.TcoMdl");
	if (ix == PNLWZNMCARLIST_TCORET) return("PnlWznmCarList.TcoRet");
	if (ix == PNLWZNMCARLIST_TCOREU) return("PnlWznmCarList.TcoReu");
	if (ix == PNLWZNMCAR1NDIALOG_TCOREF) return("PnlWznmCar1NDialog.TcoRef");
	if (ix == PNLWZNMCARCAR1NPANEL_TCOREF) return("PnlWznmCarCar1NPanel.TcoRef");
	if (ix == PNLWZNMCARHK1NCONTROL_TCOREF) return("PnlWznmCarHk1NControl.TcoRef");
	if (ix == PNLWZNMDLGLIST_TCOSRF) return("PnlWznmDlgList.TcoSrf");
	if (ix == PNLWZNMDLGLIST_TCOTYP) return("PnlWznmDlgList.TcoTyp");
	if (ix == PNLWZNMDLGLIST_TCOCAR) return("PnlWznmDlgList.TcoCar");
	if (ix == PNLWZNMDLGLIST_TCORET) return("PnlWznmDlgList.TcoRet");
	if (ix == PNLWZNMDLGLIST_TCOREU) return("PnlWznmDlgList.TcoReu");
	if (ix == PNLWZNMDLGREF1NCONTROL_TCOREF) return("PnlWznmDlgRef1NControl.TcoRef");
	if (ix == PNLWZNMDLGHK1NCONTROL_TCOREF) return("PnlWznmDlgHk1NControl.TcoRef");
	if (ix == PNLWZNMDLGMNQUERY_TCOMREF) return("PnlWznmDlgMNQuery.TcoMref");
	if (ix == PNLWZNMPNLLIST_TCOSRF) return("PnlWznmPnlList.TcoSrf");
	if (ix == PNLWZNMPNLLIST_TCOTYP) return("PnlWznmPnlList.TcoTyp");
	if (ix == PNLWZNMPNLLIST_TCOCAR) return("PnlWznmPnlList.TcoCar");
	if (ix == PNLWZNMPNLLIST_TCORET) return("PnlWznmPnlList.TcoRet");
	if (ix == PNLWZNMPNLLIST_TCOREU) return("PnlWznmPnlList.TcoReu");
	if (ix == PNLWZNMPNLHK1NCONTROL_TCOREF) return("PnlWznmPnlHk1NControl.TcoRef");
	if (ix == PNLWZNMPNLMNQUERY_TCOMREF) return("PnlWznmPnlMNQuery.TcoMref");
	if (ix == PNLWZNMQRYLIST_TCOSRF) return("PnlWznmQryList.TcoSrf");
	if (ix == PNLWZNMQRYLIST_TCOTYP) return("PnlWznmQryList.TcoTyp");
	if (ix == PNLWZNMQRYLIST_TCOVER) return("PnlWznmQryList.TcoVer");
	if (ix == PNLWZNMQRYLIST_TCOSUP) return("PnlWznmQryList.TcoSup");
	if (ix == PNLWZNMQRYLIST_TCOSRL) return("PnlWznmQryList.TcoSrl");
	if (ix == PNLWZNMQRYLIST_TCOTBL) return("PnlWznmQryList.TcoTbl");
	if (ix == PNLWZNMQRYLIST_TCOQTB) return("PnlWznmQryList.TcoQtb");
	if (ix == PNLWZNMQRYAORDER_TCOSHO) return("PnlWznmQryAOrder.TcoSho");
	if (ix == PNLWZNMQRYAORDER_TCOTCO) return("PnlWznmQryAOrder.TcoTco");
	if (ix == PNLWZNMQRYACLAUSE_TCOQMD) return("PnlWznmQryAClause.TcoQmd");
	if (ix == PNLWZNMQRYACLAUSE_TCOTYP) return("PnlWznmQryAClause.TcoTyp");
	if (ix == PNLWZNMQRYACLAUSE_TCOCSE) return("PnlWznmQryAClause.TcoCse");
	if (ix == PNLWZNMQRYACLAUSE_TCOPST) return("PnlWznmQryAClause.TcoPst");
	if (ix == PNLWZNMQRYACLAUSE_TCOVEC) return("PnlWznmQryAClause.TcoVec");
	if (ix == PNLWZNMQRYACLAUSE_TCOVIT) return("PnlWznmQryAClause.TcoVit");
	if (ix == PNLWZNMQRYSUP1NQUERY_TCOREF) return("PnlWznmQrySup1NQuery.TcoRef");
	if (ix == PNLWZNMQRYQRY1NQUERYCOL_TCOREF) return("PnlWznmQryQry1NQuerycol.TcoRef");
	if (ix == PNLWZNMQRY1NQUERYMOD_TCOREF) return("PnlWznmQry1NQuerymod.TcoRef");
	if (ix == PNLWZNMQRYMNTABLE_TCOMREF) return("PnlWznmQryMNTable.TcoMref");
	if (ix == PNLWZNMQRYMNTABLE_TCOTQMD) return("PnlWznmQryMNTable.TcoTqmd");
	if (ix == PNLWZNMQRYMNTABLE_TCOSRC) return("PnlWznmQryMNTable.TcoSrc");
	if (ix == PNLWZNMQRYMNTABLE_TCOPFX) return("PnlWznmQryMNTable.TcoPfx");
	if (ix == PNLWZNMQRYMNPANEL_TCOMREF) return("PnlWznmQryMNPanel.TcoMref");
	if (ix == PNLWZNMQRYMNDIALOG_TCOMREF) return("PnlWznmQryMNDialog.TcoMref");
	if (ix == PNLWZNMQCOLIST_TCOSRF) return("PnlWznmQcoList.TcoSrf");
	if (ix == PNLWZNMQCOLIST_TCOSHO) return("PnlWznmQcoList.TcoSho");
	if (ix == PNLWZNMQCOLIST_TCOTYP) return("PnlWznmQcoList.TcoTyp");
	if (ix == PNLWZNMQCOLIST_TCOQRY) return("PnlWznmQcoList.TcoQry");
	if (ix == PNLWZNMQCOLIST_TCOTCO) return("PnlWznmQcoList.TcoTco");
	if (ix == PNLWZNMQCOREF1NCONTROL_TCOREF) return("PnlWznmQcoRef1NControl.TcoRef");
	if (ix == PNLWZNMQMDLIST_TCOTYP) return("PnlWznmQmdList.TcoTyp");
	if (ix == PNLWZNMQMDLIST_TCOQRY) return("PnlWznmQmdList.TcoQry");
	if (ix == PNLWZNMQMDLIST_TCOPST) return("PnlWznmQmdList.TcoPst");
	if (ix == PNLWZNMQMDLIST_TCORET) return("PnlWznmQmdList.TcoRet");
	if (ix == PNLWZNMQMDLIST_TCOREU) return("PnlWznmQmdList.TcoReu");
	if (ix == PNLWZNMCONLIST_TCOSRF) return("PnlWznmConList.TcoSrf");
	if (ix == PNLWZNMCONLIST_TCOTIT) return("PnlWznmConList.TcoTit");
	if (ix == PNLWZNMCONLIST_TCOTYP) return("PnlWznmConList.TcoTyp");
	if (ix == PNLWZNMCONLIST_TCOHKT) return("PnlWznmConList.TcoHkt");
	if (ix == PNLWZNMCONLIST_TCOHKU) return("PnlWznmConList.TcoHku");
	if (ix == PNLWZNMCONLIST_TCOSCT) return("PnlWznmConList.TcoSct");
	if (ix == PNLWZNMCONLIST_TCORET) return("PnlWznmConList.TcoRet");
	if (ix == PNLWZNMCONLIST_TCOREU) return("PnlWznmConList.TcoReu");
	if (ix == PNLWZNMCONLIST_TCOSUP) return("PnlWznmConList.TcoSup");
	if (ix == PNLWZNMCONLIST_TCOSTY) return("PnlWznmConList.TcoSty");
	if (ix == PNLWZNMCONAPAR_TCOKEY) return("PnlWznmConAPar.TcoKey");
	if (ix == PNLWZNMCONAPAR_TCOLOC) return("PnlWznmConAPar.TcoLoc");
	if (ix == PNLWZNMCONAPAR_TCOVAL) return("PnlWznmConAPar.TcoVal");
	if (ix == PNLWZNMCONSUP1NCONTROL_TCOREF) return("PnlWznmConSup1NControl.TcoRef");
	if (ix == PNLWZNMCONFEDREF1NRTBLOCK_TCOREF) return("PnlWznmConFedRef1NRtblock.TcoRef");
	if (ix == PNLWZNMOPKLIST_TCOSRF) return("PnlWznmOpkList.TcoSrf");
	if (ix == PNLWZNMOPKLIST_TCOTIT) return("PnlWznmOpkList.TcoTit");
	if (ix == PNLWZNMOPKLIST_TCOTYP) return("PnlWznmOpkList.TcoTyp");
	if (ix == PNLWZNMOPKLIST_TCOVER) return("PnlWznmOpkList.TcoVer");
	if (ix == PNLWZNMOPKLIST_TCOSHD) return("PnlWznmOpkList.TcoShd");
	if (ix == PNLWZNMOPKAINVARG_TCOSRF) return("PnlWznmOpkAInvarg.TcoSrf");
	if (ix == PNLWZNMOPKAINVARG_TCOVTY) return("PnlWznmOpkAInvarg.TcoVty");
	if (ix == PNLWZNMOPKAINVARG_TCOVEC) return("PnlWznmOpkAInvarg.TcoVec");
	if (ix == PNLWZNMOPKAINVARG_TCODVL) return("PnlWznmOpkAInvarg.TcoDvl");
	if (ix == PNLWZNMOPKAINVARG_TCOVIT) return("PnlWznmOpkAInvarg.TcoVit");
	if (ix == PNLWZNMOPKAINVARG_TCOCMT) return("PnlWznmOpkAInvarg.TcoCmt");
	if (ix == PNLWZNMOPKARETVAL_TCOSRF) return("PnlWznmOpkARetval.TcoSrf");
	if (ix == PNLWZNMOPKARETVAL_TCOVTY) return("PnlWznmOpkARetval.TcoVty");
	if (ix == PNLWZNMOPKARETVAL_TCOVEC) return("PnlWznmOpkARetval.TcoVec");
	if (ix == PNLWZNMOPKARETVAL_TCOCMT) return("PnlWznmOpkARetval.TcoCmt");
	if (ix == PNLWZNMOPK1NOP_TCOREF) return("PnlWznmOpk1NOp.TcoRef");
	if (ix == PNLWZNMOPKREF1NBLOCK_TCOREF) return("PnlWznmOpkRef1NBlock.TcoRef");
	if (ix == PNLWZNMOPKMNJOB_TCOMREF) return("PnlWznmOpkMNJob.TcoMref");
	if (ix == PNLWZNMOPKMNCOMPONENT_TCOMREF) return("PnlWznmOpkMNComponent.TcoMref");
	if (ix == PNLWZNMOPKMNLIBRARY_TCOMREF) return("PnlWznmOpkMNLibrary.TcoMref");
	if (ix == PNLWZNMOPKSQKMNSTUB_TCOMREF) return("PnlWznmOpkSqkMNStub.TcoMref");
	if (ix == PNLWZNMOPXLIST_TCOSRF) return("PnlWznmOpxList.TcoSrf");
	if (ix == PNLWZNMOPXLIST_TCOOPK) return("PnlWznmOpxList.TcoOpk");
	if (ix == PNLWZNMOPXLIST_TCOSHD) return("PnlWznmOpxList.TcoShd");
	if (ix == PNLWZNMOPXAINVARG_TCOSRF) return("PnlWznmOpxAInvarg.TcoSrf");
	if (ix == PNLWZNMOPXAINVARG_TCOVTY) return("PnlWznmOpxAInvarg.TcoVty");
	if (ix == PNLWZNMOPXAINVARG_TCOVEC) return("PnlWznmOpxAInvarg.TcoVec");
	if (ix == PNLWZNMOPXAINVARG_TCODVL) return("PnlWznmOpxAInvarg.TcoDvl");
	if (ix == PNLWZNMOPXAINVARG_TCOVIT) return("PnlWznmOpxAInvarg.TcoVit");
	if (ix == PNLWZNMOPXAINVARG_TCOCMT) return("PnlWznmOpxAInvarg.TcoCmt");
	if (ix == PNLWZNMOPXARETVAL_TCOSRF) return("PnlWznmOpxARetval.TcoSrf");
	if (ix == PNLWZNMOPXARETVAL_TCOVTY) return("PnlWznmOpxARetval.TcoVty");
	if (ix == PNLWZNMOPXARETVAL_TCOVEC) return("PnlWznmOpxARetval.TcoVec");
	if (ix == PNLWZNMOPXARETVAL_TCOCMT) return("PnlWznmOpxARetval.TcoCmt");
	if (ix == PNLWZNMOPXREF1NBLOCK_TCOREF) return("PnlWznmOpxRef1NBlock.TcoRef");
	if (ix == PNLWZNMOPXMNJOB_TCOMREF) return("PnlWznmOpxMNJob.TcoMref");
	if (ix == PNLWZNMOPXSQKMNSTUB_TCOMREF) return("PnlWznmOpxSqkMNStub.TcoMref");
	if (ix == PNLWZNMJOBLIST_TCOSRF) return("PnlWznmJobList.TcoSrf");
	if (ix == PNLWZNMJOBLIST_TCOTYP) return("PnlWznmJobList.TcoTyp");
	if (ix == PNLWZNMJOBLIST_TCOVER) return("PnlWznmJobList.TcoVer");
	if (ix == PNLWZNMJOBLIST_TCORET) return("PnlWznmJobList.TcoRet");
	if (ix == PNLWZNMJOBLIST_TCOREU) return("PnlWznmJobList.TcoReu");
	if (ix == PNLWZNMJOBLIST_TCOGBL) return("PnlWznmJobList.TcoGbl");
	if (ix == PNLWZNMJOBLIST_TCOCLS) return("PnlWznmJobList.TcoCls");
	if (ix == PNLWZNMJOBLIST_TCOSHD) return("PnlWznmJobList.TcoShd");
	if (ix == PNLWZNMJOBAVAR_TCOSRF) return("PnlWznmJobAVar.TcoSrf");
	if (ix == PNLWZNMJOBAVAR_TCOVTY) return("PnlWznmJobAVar.TcoVty");
	if (ix == PNLWZNMJOBAVAR_TCOVEC) return("PnlWznmJobAVar.TcoVec");
	if (ix == PNLWZNMJOBAVAR_TCOLEN) return("PnlWznmJobAVar.TcoLen");
	if (ix == PNLWZNMJOBAVAR_TCOSHR) return("PnlWznmJobAVar.TcoShr");
	if (ix == PNLWZNMJOBAVAR_TCOCMT) return("PnlWznmJobAVar.TcoCmt");
	if (ix == PNLWZNMJOBACMD_TCOSRF) return("PnlWznmJobACmd.TcoSrf");
	if (ix == PNLWZNMJOBACMD_TCOCMT) return("PnlWznmJobACmd.TcoCmt");
	if (ix == PNLWZNMJOB1NMETHOD_TCOREF) return("PnlWznmJob1NMethod.TcoRef");
	if (ix == PNLWZNMJOB1NSENSITIVITY_TCOREF) return("PnlWznmJob1NSensitivity.TcoRef");
	if (ix == PNLWZNMJOBJOB1NSTAGE_TCOREF) return("PnlWznmJobJob1NStage.TcoRef");
	if (ix == PNLWZNMJOB1NRTJOB_TCOREF) return("PnlWznmJob1NRtjob.TcoRef");
	if (ix == PNLWZNMJOBHK1NVECTOR_TCOREF) return("PnlWznmJobHk1NVector.TcoRef");
	if (ix == PNLWZNMJOBREF1NBLOCK_TCOREF) return("PnlWznmJobRef1NBlock.TcoRef");
	if (ix == PNLWZNMJOBMNOPPACK_TCOMREF) return("PnlWznmJobMNOppack.TcoMref");
	if (ix == PNLWZNMJOBMNOP_TCOMREF) return("PnlWznmJobMNOp.TcoMref");
	if (ix == PNLWZNMJOBSUPMNJOB_TCOMREF) return("PnlWznmJobSupMNJob.TcoMref");
	if (ix == PNLWZNMJOBSUPMNJOB_TCOSHO) return("PnlWznmJobSupMNJob.TcoSho");
	if (ix == PNLWZNMJOBSUPMNJOB_TCOMLT) return("PnlWznmJobSupMNJob.TcoMlt");
	if (ix == PNLWZNMJOBSUPMNJOB_TCOCSA) return("PnlWznmJobSupMNJob.TcoCsa");
	if (ix == PNLWZNMJOBSUBMNJOB_TCOMREF) return("PnlWznmJobSubMNJob.TcoMref");
	if (ix == PNLWZNMJOBSUBMNJOB_TCOSHO) return("PnlWznmJobSubMNJob.TcoSho");
	if (ix == PNLWZNMJOBSUBMNJOB_TCOMLT) return("PnlWznmJobSubMNJob.TcoMlt");
	if (ix == PNLWZNMJOBSUBMNJOB_TCOCSA) return("PnlWznmJobSubMNJob.TcoCsa");
	if (ix == PNLWZNMSGELIST_TCOSRF) return("PnlWznmSgeList.TcoSrf");
	if (ix == PNLWZNMSGELIST_TCOTYP) return("PnlWznmSgeList.TcoTyp");
	if (ix == PNLWZNMSGELIST_TCOJOB) return("PnlWznmSgeList.TcoJob");
	if (ix == PNLWZNMSGE1NSENSITIVITY_TCOREF) return("PnlWznmSge1NSensitivity.TcoRef");
	if (ix == PNLWZNMSGESQKMNSTUB_TCOMREF) return("PnlWznmSgeSqkMNStub.TcoMref");
	if (ix == PNLWZNMMTDLIST_TCOSRF) return("PnlWznmMtdList.TcoSrf");
	if (ix == PNLWZNMMTDLIST_TCOJOB) return("PnlWznmMtdList.TcoJob");
	if (ix == PNLWZNMMTDLIST_TCOEXS) return("PnlWznmMtdList.TcoExs");
	if (ix == PNLWZNMMTDAINVPAR_TCOSRF) return("PnlWznmMtdAInvpar.TcoSrf");
	if (ix == PNLWZNMMTDAINVPAR_TCOVTY) return("PnlWznmMtdAInvpar.TcoVty");
	if (ix == PNLWZNMMTDAINVPAR_TCOVEC) return("PnlWznmMtdAInvpar.TcoVec");
	if (ix == PNLWZNMMTDAINVPAR_TCOLEN) return("PnlWznmMtdAInvpar.TcoLen");
	if (ix == PNLWZNMMTDAINVPAR_TCOCMT) return("PnlWznmMtdAInvpar.TcoCmt");
	if (ix == PNLWZNMMTDARETPAR_TCOSRF) return("PnlWznmMtdARetpar.TcoSrf");
	if (ix == PNLWZNMMTDARETPAR_TCOVTY) return("PnlWznmMtdARetpar.TcoVty");
	if (ix == PNLWZNMMTDARETPAR_TCOVEC) return("PnlWznmMtdARetpar.TcoVec");
	if (ix == PNLWZNMMTDARETPAR_TCOLEN) return("PnlWznmMtdARetpar.TcoLen");
	if (ix == PNLWZNMMTDARETPAR_TCOCMT) return("PnlWznmMtdARetpar.TcoCmt");
	if (ix == PNLWZNMBLKLIST_TCOSRF) return("PnlWznmBlkList.TcoSrf");
	if (ix == PNLWZNMBLKLIST_TCOTYP) return("PnlWznmBlkList.TcoTyp");
	if (ix == PNLWZNMBLKLIST_TCOVER) return("PnlWznmBlkList.TcoVer");
	if (ix == PNLWZNMBLKLIST_TCORET) return("PnlWznmBlkList.TcoRet");
	if (ix == PNLWZNMBLKLIST_TCOREU) return("PnlWznmBlkList.TcoReu");
	if (ix == PNLWZNMBLKAITEM_TCOTYP) return("PnlWznmBlkAItem.TcoTyp");
	if (ix == PNLWZNMBLKAITEM_TCOSRF) return("PnlWznmBlkAItem.TcoSrf");
	if (ix == PNLWZNMBLKAITEM_TCOVTY) return("PnlWznmBlkAItem.TcoVty");
	if (ix == PNLWZNMBLKAITEM_TCOCON) return("PnlWznmBlkAItem.TcoCon");
	if (ix == PNLWZNMBLKAITEM_TCOVEC) return("PnlWznmBlkAItem.TcoVec");
	if (ix == PNLWZNMBLKAITEM_TCOFED) return("PnlWznmBlkAItem.TcoFed");
	if (ix == PNLWZNMBLKAITEM_TCOTBL) return("PnlWznmBlkAItem.TcoTbl");
	if (ix == PNLWZNMBLKAITEM_TCOBL2) return("PnlWznmBlkAItem.TcoBl2");
	if (ix == PNLWZNMBLKAITEM_TCODFV) return("PnlWznmBlkAItem.TcoDfv");
	if (ix == PNLWZNMBLKAITEM_TCOVIT) return("PnlWznmBlkAItem.TcoVit");
	if (ix == PNLWZNMBLKAITEM_TCOCMT) return("PnlWznmBlkAItem.TcoCmt");
	if (ix == PNLWZNMBLK1NRTDPCH_TCOREF) return("PnlWznmBlk1NRtdpch.TcoRef");
	if (ix == PNLWZNMBLKREF1NRTBLOCK_TCOREF) return("PnlWznmBlkRef1NRtblock.TcoRef");
	if (ix == PNLWZNMCALLIST_TCOSRF) return("PnlWznmCalList.TcoSrf");
	if (ix == PNLWZNMCALLIST_TCOTYP) return("PnlWznmCalList.TcoTyp");
	if (ix == PNLWZNMCALLIST_TCOVER) return("PnlWznmCalList.TcoVer");
	if (ix == PNLWZNMCALLIST_TCORET) return("PnlWznmCalList.TcoRet");
	if (ix == PNLWZNMCALLIST_TCOREU) return("PnlWznmCalList.TcoReu");
	if (ix == PNLWZNMCALLIST_TCOIAT) return("PnlWznmCalList.TcoIat");
	if (ix == PNLWZNMCALLIST_TCORAT) return("PnlWznmCalList.TcoRat");
	if (ix == PNLWZNMCAL1NSENSITIVITY_TCOREF) return("PnlWznmCal1NSensitivity.TcoRef");
	if (ix == PNLWZNMCALMNSTUB_TCOMREF) return("PnlWznmCalMNStub.TcoMref");
	if (ix == PNLWZNMCMPLIST_TCOSRF) return("PnlWznmCmpList.TcoSrf");
	if (ix == PNLWZNMCMPLIST_TCOTIT) return("PnlWznmCmpList.TcoTit");
	if (ix == PNLWZNMCMPLIST_TCOTYP) return("PnlWznmCmpList.TcoTyp");
	if (ix == PNLWZNMCMPLIST_TCOVER) return("PnlWznmCmpList.TcoVer");
	if (ix == PNLWZNMCMP1NRELEASE_TCOREF) return("PnlWznmCmp1NRelease.TcoRef");
	if (ix == PNLWZNMCMPMNLIBRARY_TCOMREF) return("PnlWznmCmpMNLibrary.TcoMref");
	if (ix == PNLWZNMCMPMNOPPACK_TCOMREF) return("PnlWznmCmpMNOppack.TcoMref");
	if (ix == PNLWZNMRLSLIST_TCOSRF) return("PnlWznmRlsList.TcoSrf");
	if (ix == PNLWZNMRLSLIST_TCOCMP) return("PnlWznmRlsList.TcoCmp");
	if (ix == PNLWZNMRLSLIST_TCOMCH) return("PnlWznmRlsList.TcoMch");
	if (ix == PNLWZNMAPPLIST_TCOGRP) return("PnlWznmAppList.TcoGrp");
	if (ix == PNLWZNMAPPLIST_TCOOWN) return("PnlWznmAppList.TcoOwn");
	if (ix == PNLWZNMAPPLIST_TCOSHO) return("PnlWznmAppList.TcoSho");
	if (ix == PNLWZNMAPPLIST_TCOTIT) return("PnlWznmAppList.TcoTit");
	if (ix == PNLWZNMAPPLIST_TCOTRG) return("PnlWznmAppList.TcoTrg");
	if (ix == PNLWZNMAPPLIST_TCOVER) return("PnlWznmAppList.TcoVer");
	if (ix == PNLWZNMAPP1NEVENT_TCOREF) return("PnlWznmApp1NEvent.TcoRef");
	if (ix == PNLWZNMAPPAPP1NSEQUENCE_TCOREF) return("PnlWznmAppApp1NSequence.TcoRef");
	if (ix == PNLWZNMAPP1NRTJOB_TCOREF) return("PnlWznmApp1NRtjob.TcoRef");
	if (ix == PNLWZNMAPPREF1NFILE_TCOREF) return("PnlWznmAppRef1NFile.TcoRef");
	if (ix == PNLWZNMRTJLIST_TCOSRF) return("PnlWznmRtjList.TcoSrf");
	if (ix == PNLWZNMRTJLIST_TCOAPP) return("PnlWznmRtjList.TcoApp");
	if (ix == PNLWZNMRTJLIST_TCOSUP) return("PnlWznmRtjList.TcoSup");
	if (ix == PNLWZNMRTJLIST_TCOJOB) return("PnlWznmRtjList.TcoJob");
	if (ix == PNLWZNMRTJ1NRTDPCH_TCOREF) return("PnlWznmRtj1NRtdpch.TcoRef");
	if (ix == PNLWZNMRTJ1NRTBLOCK_TCOREF) return("PnlWznmRtj1NRtblock.TcoRef");
	if (ix == PNLWZNMRTJSUP1NRTJOB_TCOREF) return("PnlWznmRtjSup1NRtjob.TcoRef");
	if (ix == PNLWZNMEVTLIST_TCOSRF) return("PnlWznmEvtList.TcoSrf");
	if (ix == PNLWZNMEVTLIST_TCOAPP) return("PnlWznmEvtList.TcoApp");
	if (ix == PNLWZNMSEQLIST_TCOSRF) return("PnlWznmSeqList.TcoSrf");
	if (ix == PNLWZNMSEQLIST_TCOTIT) return("PnlWznmSeqList.TcoTit");
	if (ix == PNLWZNMSEQLIST_TCOAPP) return("PnlWznmSeqList.TcoApp");
	if (ix == PNLWZNMSEQSEQ1NSTATE_TCOREF) return("PnlWznmSeqSeq1NState.TcoRef");
	if (ix == PNLWZNMSTELIST_TCOSRF) return("PnlWznmSteList.TcoSrf");
	if (ix == PNLWZNMSTELIST_TCOSEQ) return("PnlWznmSteList.TcoSeq");
	if (ix == PNLWZNMSTEATRIG_TCOSRF) return("PnlWznmSteATrig.TcoSrf");
	if (ix == PNLWZNMSTEATRIG_TCOTYP) return("PnlWznmSteATrig.TcoTyp");
	if (ix == PNLWZNMSTEATRIG_TCOEVT) return("PnlWznmSteATrig.TcoEvt");
	if (ix == PNLWZNMSTEATRIG_TCORTJ) return("PnlWznmSteATrig.TcoRtj");
	if (ix == PNLWZNMSTEATRIG_TCOVIT) return("PnlWznmSteATrig.TcoVit");
	if (ix == PNLWZNMSTEATRIG_TCOXSR) return("PnlWznmSteATrig.TcoXsr");
	if (ix == PNLWZNMSTEATRIG_TCORTD) return("PnlWznmSteATrig.TcoRtd");
	if (ix == PNLWZNMSTEATRIG_TCOMSK) return("PnlWznmSteATrig.TcoMsk");
	if (ix == PNLWZNMSTEATRIG_TCOCND) return("PnlWznmSteATrig.TcoCnd");
	if (ix == PNLWZNMSTEAACTION_TCOSCT) return("PnlWznmSteAAction.TcoSct");
	if (ix == PNLWZNMSTEAACTION_TCOTYP) return("PnlWznmSteAAction.TcoTyp");
	if (ix == PNLWZNMSTEAACTION_TCOTRJ) return("PnlWznmSteAAction.TcoTrj");
	if (ix == PNLWZNMSTEAACTION_TCOVEC) return("PnlWznmSteAAction.TcoVec");
	if (ix == PNLWZNMSTEAACTION_TCOVIT) return("PnlWznmSteAAction.TcoVit");
	if (ix == PNLWZNMSTEAACTION_TCOSNX) return("PnlWznmSteAAction.TcoSnx");
	if (ix == PNLWZNMSTEAACTION_TCOSEQ) return("PnlWznmSteAAction.TcoSeq");
	if (ix == PNLWZNMSTEAACTION_TCOTR1) return("PnlWznmSteAAction.TcoTr1");
	if (ix == PNLWZNMSTEAACTION_TCOIP1) return("PnlWznmSteAAction.TcoIp1");
	if (ix == PNLWZNMSTEAACTION_TCOTR2) return("PnlWznmSteAAction.TcoTr2");
	if (ix == PNLWZNMSTEAACTION_TCOIP2) return("PnlWznmSteAAction.TcoIp2");
	if (ix == PNLWZNMSTEAACTION_TCOTR3) return("PnlWznmSteAAction.TcoTr3");
	if (ix == PNLWZNMSTEAACTION_TCOIP3) return("PnlWznmSteAAction.TcoIp3");
	if (ix == PNLWZNMSTEAACTION_TCOTR4) return("PnlWznmSteAAction.TcoTr4");
	if (ix == PNLWZNMSTEAACTION_TCOIP4) return("PnlWznmSteAAction.TcoIp4");

	return("");
};

/******************************************************************************
 class DbsWznm::VecVFeatgroup
 ******************************************************************************/

uint DbsWznm::VecVFeatgroup::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vecwznmvcard") return VECWZNMVCARD;

	return(0);
};

string DbsWznm::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECWZNMVCARD) return("VecWznmVCard");

	return("");
};

string DbsWznm::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VECWZNMVCARD) return("card");
		return(getSref(ix));
	};

	return("");
};

void DbsWznm::VecVFeatgroup::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecVGender
 ******************************************************************************/

uint DbsWznm::VecVGender::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "m") return M;
	if (s == "f") return F;
	if (s == "n") return N;

	return(0);
};

string DbsWznm::VecVGender::getSref(
			const uint ix
		) {
	if (ix == M) return("m");
	if (ix == F) return("f");
	if (ix == N) return("n");

	return("");
};

string DbsWznm::VecVGender::getTitle(
			const uint ix
		) {
	if (ix == M) return("male");
	if (ix == F) return("female");
	if (ix == N) return("neuter");
	return(getSref(ix));

	return("");
};

void DbsWznm::VecVGender::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

/******************************************************************************
 class DbsWznm::VecVKeylist
 ******************************************************************************/

uint DbsWznm::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstwznmkamcapabilityparkey") return KLSTWZNMKAMCAPABILITYPARKEY;
	if (s == "klstwznmkamcontrolparkey") return KLSTWZNMKAMCONTROLPARKEY;
	if (s == "klstwznmkamcontrolparval") return KLSTWZNMKAMCONTROLPARVAL;
	if (s == "klstwznmkamlibrarymakefiletag") return KLSTWZNMKAMLIBRARYMAKEFILETAG;
	if (s == "klstwznmkammachinemakefiletag") return KLSTWZNMKAMMACHINEMAKEFILETAG;
	if (s == "klstwznmkammachineparkey") return KLSTWZNMKAMMACHINEPARKEY;
	if (s == "klstwznmkampersondetailtype") return KLSTWZNMKAMPERSONDETAILTYPE;
	if (s == "klstwznmkmcontroloption") return KLSTWZNMKMCONTROLOPTION;
	if (s == "klstwznmkmfilecontent") return KLSTWZNMKMFILECONTENT;
	if (s == "klstwznmkmfilemimetype") return KLSTWZNMKMFILEMIMETYPE;
	if (s == "klstwznmkmlibrarylictype") return KLSTWZNMKMLIBRARYLICTYPE;
	if (s == "klstwznmkmmachinepkgmgr") return KLSTWZNMKMMACHINEPKGMGR;
	if (s == "klstwznmkmrelationoption") return KLSTWZNMKMRELATIONOPTION;
	if (s == "klstwznmkmreleaseoption") return KLSTWZNMKMRELEASEOPTION;
	if (s == "klstwznmkmtablecoloption") return KLSTWZNMKMTABLECOLOPTION;
	if (s == "klstwznmkmvectoroption") return KLSTWZNMKMVECTOROPTION;
	if (s == "klstwznmkrmcapabilityuniversalkey") return KLSTWZNMKRMCAPABILITYUNIVERSALKEY;
	if (s == "klstwznmkrmpersonmprojectfunction") return KLSTWZNMKRMPERSONMPROJECTFUNCTION;
	if (s == "klstwznmktaggrp") return KLSTWZNMKTAGGRP;
	if (s == "klstkwznmctpgenjtrcustop") return KLSTKWZNMCTPGENJTRCUSTOP;
	if (s == "klstkwznmctpgenuicustop") return KLSTKWZNMCTPGENUICUSTOP;
	if (s == "klstkwznmctpwrsrvcustop") return KLSTKWZNMCTPWRSRVCUSTOP;
	if (s == "klstkwznmctpwrstkitcustop") return KLSTKWZNMCTPWRSTKITCUSTOP;
	if (s == "klstkwznmctpwrwebcustop") return KLSTKWZNMCTPWRWEBCUSTOP;

	return(0);
};

string DbsWznm::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTWZNMKAMCAPABILITYPARKEY) return("KlstWznmKAMCapabilityParKey");
	if (ix == KLSTWZNMKAMCONTROLPARKEY) return("KlstWznmKAMControlParKey");
	if (ix == KLSTWZNMKAMCONTROLPARVAL) return("KlstWznmKAMControlParVal");
	if (ix == KLSTWZNMKAMLIBRARYMAKEFILETAG) return("KlstWznmKAMLibraryMakefileTag");
	if (ix == KLSTWZNMKAMMACHINEMAKEFILETAG) return("KlstWznmKAMMachineMakefileTag");
	if (ix == KLSTWZNMKAMMACHINEPARKEY) return("KlstWznmKAMMachineParKey");
	if (ix == KLSTWZNMKAMPERSONDETAILTYPE) return("KlstWznmKAMPersonDetailType");
	if (ix == KLSTWZNMKMCONTROLOPTION) return("KlstWznmKMControlOption");
	if (ix == KLSTWZNMKMFILECONTENT) return("KlstWznmKMFileContent");
	if (ix == KLSTWZNMKMFILEMIMETYPE) return("KlstWznmKMFileMimetype");
	if (ix == KLSTWZNMKMLIBRARYLICTYPE) return("KlstWznmKMLibraryLictype");
	if (ix == KLSTWZNMKMMACHINEPKGMGR) return("KlstWznmKMMachinePkgmgr");
	if (ix == KLSTWZNMKMRELATIONOPTION) return("KlstWznmKMRelationOption");
	if (ix == KLSTWZNMKMRELEASEOPTION) return("KlstWznmKMReleaseOption");
	if (ix == KLSTWZNMKMTABLECOLOPTION) return("KlstWznmKMTablecolOption");
	if (ix == KLSTWZNMKMVECTOROPTION) return("KlstWznmKMVectorOption");
	if (ix == KLSTWZNMKRMCAPABILITYUNIVERSALKEY) return("KlstWznmKRMCapabilityUniversalKey");
	if (ix == KLSTWZNMKRMPERSONMPROJECTFUNCTION) return("KlstWznmKRMPersonMProjectFunction");
	if (ix == KLSTWZNMKTAGGRP) return("KlstWznmKTaggrp");
	if (ix == KLSTKWZNMCTPGENJTRCUSTOP) return("KlstKWznmCtpGenjtrCustop");
	if (ix == KLSTKWZNMCTPGENUICUSTOP) return("KlstKWznmCtpGenuiCustop");
	if (ix == KLSTKWZNMCTPWRSRVCUSTOP) return("KlstKWznmCtpWrsrvCustop");
	if (ix == KLSTKWZNMCTPWRSTKITCUSTOP) return("KlstKWznmCtpWrstkitCustop");
	if (ix == KLSTKWZNMCTPWRWEBCUSTOP) return("KlstKWznmCtpWrwebCustop");

	return("");
};

string DbsWznm::VecVKeylist::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == KLSTWZNMKAMCAPABILITYPARKEY) return("key");
		if (ix == KLSTWZNMKAMCONTROLPARKEY) return("key");
		if (ix == KLSTWZNMKAMCONTROLPARVAL) return("value");
		if (ix == KLSTWZNMKAMLIBRARYMAKEFILETAG) return("tag");
		if (ix == KLSTWZNMKAMMACHINEMAKEFILETAG) return("tag");
		if (ix == KLSTWZNMKAMMACHINEPARKEY) return("key");
		if (ix == KLSTWZNMKAMPERSONDETAILTYPE) return("type");
		if (ix == KLSTWZNMKMCONTROLOPTION) return("options");
		if (ix == KLSTWZNMKMFILECONTENT) return("content");
		if (ix == KLSTWZNMKMFILEMIMETYPE) return("MIME type");
		if (ix == KLSTWZNMKMLIBRARYLICTYPE) return("license type");
		if (ix == KLSTWZNMKMMACHINEPKGMGR) return("package manager");
		if (ix == KLSTWZNMKMRELATIONOPTION) return("options");
		if (ix == KLSTWZNMKMRELEASEOPTION) return("options");
		if (ix == KLSTWZNMKMTABLECOLOPTION) return("options");
		if (ix == KLSTWZNMKMVECTOROPTION) return("options");
		if (ix == KLSTWZNMKRMCAPABILITYUNIVERSALKEY) return("key");
		if (ix == KLSTWZNMKRMPERSONMPROJECTFUNCTION) return("function");
		if (ix == KLSTWZNMKTAGGRP) return("tag group");
		if (ix == KLSTKWZNMCTPGENJTRCUSTOP) return("WznmCtpGenjtr custom operations");
		if (ix == KLSTKWZNMCTPGENUICUSTOP) return("WznmCtpGenui custom operations");
		if (ix == KLSTKWZNMCTPWRSRVCUSTOP) return("WznmCtpWrsrv custom operations");
		if (ix == KLSTKWZNMCTPWRSTKITCUSTOP) return("WznmCtpWrstkit custom operations");
		if (ix == KLSTKWZNMCTPWRWEBCUSTOP) return("WznmCtpWrweb custom operations");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWznm::VecVLat
 ******************************************************************************/

uint DbsWznm::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string DbsWznm::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsWznm::VecVLocale
 ******************************************************************************/

uint DbsWznm::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;

	return(0);
};

string DbsWznm::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");

	return("");
};

string DbsWznm::VecVLocale::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		return(getSref(ix));
	};

	return("");
};

void DbsWznm::VecVLocale::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecVLop
 ******************************************************************************/

uint DbsWznm::VecVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string DbsWznm::VecVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

/******************************************************************************
 class DbsWznm::VecVMaintable
 ******************************************************************************/

uint DbsWznm::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tblwznmmapp") return TBLWZNMMAPP;
	if (s == "tblwznmmblock") return TBLWZNMMBLOCK;
	if (s == "tblwznmmcall") return TBLWZNMMCALL;
	if (s == "tblwznmmcapability") return TBLWZNMMCAPABILITY;
	if (s == "tblwznmmcard") return TBLWZNMMCARD;
	if (s == "tblwznmmcheck") return TBLWZNMMCHECK;
	if (s == "tblwznmmcomponent") return TBLWZNMMCOMPONENT;
	if (s == "tblwznmmcontrol") return TBLWZNMMCONTROL;
	if (s == "tblwznmmdialog") return TBLWZNMMDIALOG;
	if (s == "tblwznmmerror") return TBLWZNMMERROR;
	if (s == "tblwznmmevent") return TBLWZNMMEVENT;
	if (s == "tblwznmmfeed") return TBLWZNMMFEED;
	if (s == "tblwznmmfile") return TBLWZNMMFILE;
	if (s == "tblwznmmimpexp") return TBLWZNMMIMPEXP;
	if (s == "tblwznmmimpexpcol") return TBLWZNMMIMPEXPCOL;
	if (s == "tblwznmmimpexpcplx") return TBLWZNMMIMPEXPCPLX;
	if (s == "tblwznmmjob") return TBLWZNMMJOB;
	if (s == "tblwznmmlibrary") return TBLWZNMMLIBRARY;
	if (s == "tblwznmmlocale") return TBLWZNMMLOCALE;
	if (s == "tblwznmmmachine") return TBLWZNMMMACHINE;
	if (s == "tblwznmmmethod") return TBLWZNMMMETHOD;
	if (s == "tblwznmmmodule") return TBLWZNMMMODULE;
	if (s == "tblwznmmop") return TBLWZNMMOP;
	if (s == "tblwznmmoppack") return TBLWZNMMOPPACK;
	if (s == "tblwznmmpanel") return TBLWZNMMPANEL;
	if (s == "tblwznmmperson") return TBLWZNMMPERSON;
	if (s == "tblwznmmpreset") return TBLWZNMMPRESET;
	if (s == "tblwznmmproject") return TBLWZNMMPROJECT;
	if (s == "tblwznmmquery") return TBLWZNMMQUERY;
	if (s == "tblwznmmquerycol") return TBLWZNMMQUERYCOL;
	if (s == "tblwznmmquerymod") return TBLWZNMMQUERYMOD;
	if (s == "tblwznmmrelation") return TBLWZNMMRELATION;
	if (s == "tblwznmmrelease") return TBLWZNMMRELEASE;
	if (s == "tblwznmmrtblock") return TBLWZNMMRTBLOCK;
	if (s == "tblwznmmrtdpch") return TBLWZNMMRTDPCH;
	if (s == "tblwznmmrtjob") return TBLWZNMMRTJOB;
	if (s == "tblwznmmsensitivity") return TBLWZNMMSENSITIVITY;
	if (s == "tblwznmmsequence") return TBLWZNMMSEQUENCE;
	if (s == "tblwznmmsession") return TBLWZNMMSESSION;
	if (s == "tblwznmmsquawk") return TBLWZNMMSQUAWK;
	if (s == "tblwznmmstage") return TBLWZNMMSTAGE;
	if (s == "tblwznmmstate") return TBLWZNMMSTATE;
	if (s == "tblwznmmstub") return TBLWZNMMSTUB;
	if (s == "tblwznmmsubset") return TBLWZNMMSUBSET;
	if (s == "tblwznmmtable") return TBLWZNMMTABLE;
	if (s == "tblwznmmtablecol") return TBLWZNMMTABLECOL;
	if (s == "tblwznmmtag") return TBLWZNMMTAG;
	if (s == "tblwznmmuser") return TBLWZNMMUSER;
	if (s == "tblwznmmusergroup") return TBLWZNMMUSERGROUP;
	if (s == "tblwznmmvector") return TBLWZNMMVECTOR;
	if (s == "tblwznmmvectoritem") return TBLWZNMMVECTORITEM;
	if (s == "tblwznmmversion") return TBLWZNMMVERSION;

	return(0);
};

string DbsWznm::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLWZNMMAPP) return("TblWznmMApp");
	if (ix == TBLWZNMMBLOCK) return("TblWznmMBlock");
	if (ix == TBLWZNMMCALL) return("TblWznmMCall");
	if (ix == TBLWZNMMCAPABILITY) return("TblWznmMCapability");
	if (ix == TBLWZNMMCARD) return("TblWznmMCard");
	if (ix == TBLWZNMMCHECK) return("TblWznmMCheck");
	if (ix == TBLWZNMMCOMPONENT) return("TblWznmMComponent");
	if (ix == TBLWZNMMCONTROL) return("TblWznmMControl");
	if (ix == TBLWZNMMDIALOG) return("TblWznmMDialog");
	if (ix == TBLWZNMMERROR) return("TblWznmMError");
	if (ix == TBLWZNMMEVENT) return("TblWznmMEvent");
	if (ix == TBLWZNMMFEED) return("TblWznmMFeed");
	if (ix == TBLWZNMMFILE) return("TblWznmMFile");
	if (ix == TBLWZNMMIMPEXP) return("TblWznmMImpexp");
	if (ix == TBLWZNMMIMPEXPCOL) return("TblWznmMImpexpcol");
	if (ix == TBLWZNMMIMPEXPCPLX) return("TblWznmMImpexpcplx");
	if (ix == TBLWZNMMJOB) return("TblWznmMJob");
	if (ix == TBLWZNMMLIBRARY) return("TblWznmMLibrary");
	if (ix == TBLWZNMMLOCALE) return("TblWznmMLocale");
	if (ix == TBLWZNMMMACHINE) return("TblWznmMMachine");
	if (ix == TBLWZNMMMETHOD) return("TblWznmMMethod");
	if (ix == TBLWZNMMMODULE) return("TblWznmMModule");
	if (ix == TBLWZNMMOP) return("TblWznmMOp");
	if (ix == TBLWZNMMOPPACK) return("TblWznmMOppack");
	if (ix == TBLWZNMMPANEL) return("TblWznmMPanel");
	if (ix == TBLWZNMMPERSON) return("TblWznmMPerson");
	if (ix == TBLWZNMMPRESET) return("TblWznmMPreset");
	if (ix == TBLWZNMMPROJECT) return("TblWznmMProject");
	if (ix == TBLWZNMMQUERY) return("TblWznmMQuery");
	if (ix == TBLWZNMMQUERYCOL) return("TblWznmMQuerycol");
	if (ix == TBLWZNMMQUERYMOD) return("TblWznmMQuerymod");
	if (ix == TBLWZNMMRELATION) return("TblWznmMRelation");
	if (ix == TBLWZNMMRELEASE) return("TblWznmMRelease");
	if (ix == TBLWZNMMRTBLOCK) return("TblWznmMRtblock");
	if (ix == TBLWZNMMRTDPCH) return("TblWznmMRtdpch");
	if (ix == TBLWZNMMRTJOB) return("TblWznmMRtjob");
	if (ix == TBLWZNMMSENSITIVITY) return("TblWznmMSensitivity");
	if (ix == TBLWZNMMSEQUENCE) return("TblWznmMSequence");
	if (ix == TBLWZNMMSESSION) return("TblWznmMSession");
	if (ix == TBLWZNMMSQUAWK) return("TblWznmMSquawk");
	if (ix == TBLWZNMMSTAGE) return("TblWznmMStage");
	if (ix == TBLWZNMMSTATE) return("TblWznmMState");
	if (ix == TBLWZNMMSTUB) return("TblWznmMStub");
	if (ix == TBLWZNMMSUBSET) return("TblWznmMSubset");
	if (ix == TBLWZNMMTABLE) return("TblWznmMTable");
	if (ix == TBLWZNMMTABLECOL) return("TblWznmMTablecol");
	if (ix == TBLWZNMMTAG) return("TblWznmMTag");
	if (ix == TBLWZNMMUSER) return("TblWznmMUser");
	if (ix == TBLWZNMMUSERGROUP) return("TblWznmMUsergroup");
	if (ix == TBLWZNMMVECTOR) return("TblWznmMVector");
	if (ix == TBLWZNMMVECTORITEM) return("TblWznmMVectoritem");
	if (ix == TBLWZNMMVERSION) return("TblWznmMVersion");

	return("");
};

string DbsWznm::VecVMaintable::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBLWZNMMAPP) return("accessor app");
		if (ix == TBLWZNMMBLOCK) return("block");
		if (ix == TBLWZNMMCALL) return("call");
		if (ix == TBLWZNMMCAPABILITY) return("capability");
		if (ix == TBLWZNMMCARD) return("card");
		if (ix == TBLWZNMMCHECK) return("feature check");
		if (ix == TBLWZNMMCOMPONENT) return("component");
		if (ix == TBLWZNMMCONTROL) return("control");
		if (ix == TBLWZNMMDIALOG) return("dialog");
		if (ix == TBLWZNMMERROR) return("error");
		if (ix == TBLWZNMMEVENT) return("event");
		if (ix == TBLWZNMMFEED) return("feed");
		if (ix == TBLWZNMMFILE) return("file");
		if (ix == TBLWZNMMIMPEXP) return("import/export");
		if (ix == TBLWZNMMIMPEXPCOL) return("import/export column");
		if (ix == TBLWZNMMIMPEXPCPLX) return("import/export complex");
		if (ix == TBLWZNMMJOB) return("job");
		if (ix == TBLWZNMMLIBRARY) return("library");
		if (ix == TBLWZNMMLOCALE) return("locale");
		if (ix == TBLWZNMMMACHINE) return("machine");
		if (ix == TBLWZNMMMETHOD) return("method");
		if (ix == TBLWZNMMMODULE) return("module");
		if (ix == TBLWZNMMOP) return("operation");
		if (ix == TBLWZNMMOPPACK) return("operation pack");
		if (ix == TBLWZNMMPANEL) return("panel");
		if (ix == TBLWZNMMPERSON) return("person");
		if (ix == TBLWZNMMPRESET) return("presetting");
		if (ix == TBLWZNMMPROJECT) return("project");
		if (ix == TBLWZNMMQUERY) return("query");
		if (ix == TBLWZNMMQUERYCOL) return("query column");
		if (ix == TBLWZNMMQUERYMOD) return("query modifier");
		if (ix == TBLWZNMMRELATION) return("relation");
		if (ix == TBLWZNMMRELEASE) return("release");
		if (ix == TBLWZNMMRTBLOCK) return("run-time data block");
		if (ix == TBLWZNMMRTDPCH) return("run-time dispatch");
		if (ix == TBLWZNMMRTJOB) return("run-time job");
		if (ix == TBLWZNMMSENSITIVITY) return("sensitivity");
		if (ix == TBLWZNMMSEQUENCE) return("sequence");
		if (ix == TBLWZNMMSESSION) return("session");
		if (ix == TBLWZNMMSQUAWK) return("squawk");
		if (ix == TBLWZNMMSTAGE) return("stage");
		if (ix == TBLWZNMMSTATE) return("state");
		if (ix == TBLWZNMMSTUB) return("stub");
		if (ix == TBLWZNMMSUBSET) return("subset");
		if (ix == TBLWZNMMTABLE) return("table");
		if (ix == TBLWZNMMTABLECOL) return("table column");
		if (ix == TBLWZNMMTAG) return("tag");
		if (ix == TBLWZNMMUSER) return("user");
		if (ix == TBLWZNMMUSERGROUP) return("user group");
		if (ix == TBLWZNMMVECTOR) return("vector");
		if (ix == TBLWZNMMVECTORITEM) return("vector item");
		if (ix == TBLWZNMMVERSION) return("version");
		return(getSref(ix));
	};

	return("");
};

void DbsWznm::VecVMaintable::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 53; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecVOolop
 ******************************************************************************/

uint DbsWznm::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string DbsWznm::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsWznm::VecVPreset
 ******************************************************************************/

uint DbsWznm::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prewznmadmin") return PREWZNMADMIN;
	if (s == "prewznmapplist.grp") return PREWZNMAPPLIST_GRP;
	if (s == "prewznmapplist.own") return PREWZNMAPPLIST_OWN;
	if (s == "prewznmapplist.tit") return PREWZNMAPPLIST_TIT;
	if (s == "prewznmapplist.trg") return PREWZNMAPPLIST_TRG;
	if (s == "prewznmapplist.ver") return PREWZNMAPPLIST_VER;
	if (s == "prewznmblklist.ret") return PREWZNMBLKLIST_RET;
	if (s == "prewznmblklist.reu") return PREWZNMBLKLIST_REU;
	if (s == "prewznmblklist.srf") return PREWZNMBLKLIST_SRF;
	if (s == "prewznmblklist.typ") return PREWZNMBLKLIST_TYP;
	if (s == "prewznmblklist.ver") return PREWZNMBLKLIST_VER;
	if (s == "prewznmcallist.iat") return PREWZNMCALLIST_IAT;
	if (s == "prewznmcallist.rat") return PREWZNMCALLIST_RAT;
	if (s == "prewznmcallist.ret") return PREWZNMCALLIST_RET;
	if (s == "prewznmcallist.reu") return PREWZNMCALLIST_REU;
	if (s == "prewznmcallist.srf") return PREWZNMCALLIST_SRF;
	if (s == "prewznmcallist.typ") return PREWZNMCALLIST_TYP;
	if (s == "prewznmcallist.ver") return PREWZNMCALLIST_VER;
	if (s == "prewznmcapapar.x1") return PREWZNMCAPAPAR_X1;
	if (s == "prewznmcaplist.srf") return PREWZNMCAPLIST_SRF;
	if (s == "prewznmcaplist.tpl") return PREWZNMCAPLIST_TPL;
	if (s == "prewznmcaplist.ver") return PREWZNMCAPLIST_VER;
	if (s == "prewznmcarlist.mdl") return PREWZNMCARLIST_MDL;
	if (s == "prewznmcarlist.ret") return PREWZNMCARLIST_RET;
	if (s == "prewznmcarlist.reu") return PREWZNMCARLIST_REU;
	if (s == "prewznmcarlist.srf") return PREWZNMCARLIST_SRF;
	if (s == "prewznmchklist.srf") return PREWZNMCHKLIST_SRF;
	if (s == "prewznmchklist.tbl") return PREWZNMCHKLIST_TBL;
	if (s == "prewznmchklist.tco") return PREWZNMCHKLIST_TCO;
	if (s == "prewznmchklist.typ") return PREWZNMCHKLIST_TYP;
	if (s == "prewznmcmplist.srf") return PREWZNMCMPLIST_SRF;
	if (s == "prewznmcmplist.typ") return PREWZNMCMPLIST_TYP;
	if (s == "prewznmcmplist.ver") return PREWZNMCMPLIST_VER;
	if (s == "prewznmconapar.x1") return PREWZNMCONAPAR_X1;
	if (s == "prewznmconapar.x2") return PREWZNMCONAPAR_X2;
	if (s == "prewznmconlist.hkt") return PREWZNMCONLIST_HKT;
	if (s == "prewznmconlist.hku") return PREWZNMCONLIST_HKU;
	if (s == "prewznmconlist.ret") return PREWZNMCONLIST_RET;
	if (s == "prewznmconlist.reu") return PREWZNMCONLIST_REU;
	if (s == "prewznmconlist.sct") return PREWZNMCONLIST_SCT;
	if (s == "prewznmconlist.srf") return PREWZNMCONLIST_SRF;
	if (s == "prewznmconlist.sup") return PREWZNMCONLIST_SUP;
	if (s == "prewznmconlist.typ") return PREWZNMCONLIST_TYP;
	if (s == "prewznmctpapar.x1") return PREWZNMCTPAPAR_X1;
	if (s == "prewznmctplist.srf") return PREWZNMCTPLIST_SRF;
	if (s == "prewznmctplist.ver") return PREWZNMCTPLIST_VER;
	if (s == "prewznmdlglist.car") return PREWZNMDLGLIST_CAR;
	if (s == "prewznmdlglist.ret") return PREWZNMDLGLIST_RET;
	if (s == "prewznmdlglist.reu") return PREWZNMDLGLIST_REU;
	if (s == "prewznmdlglist.srf") return PREWZNMDLGLIST_SRF;
	if (s == "prewznmdlglist.typ") return PREWZNMDLGLIST_TYP;
	if (s == "prewznmerrlist.srf") return PREWZNMERRLIST_SRF;
	if (s == "prewznmerrlist.ver") return PREWZNMERRLIST_VER;
	if (s == "prewznmevtlist.app") return PREWZNMEVTLIST_APP;
	if (s == "prewznmevtlist.srf") return PREWZNMEVTLIST_SRF;
	if (s == "prewznmextfolder") return PREWZNMEXTFOLDER;
	if (s == "prewznmfillist.fnm") return PREWZNMFILLIST_FNM;
	if (s == "prewznmfillist.grp") return PREWZNMFILLIST_GRP;
	if (s == "prewznmfillist.own") return PREWZNMFILLIST_OWN;
	if (s == "prewznmfillist.ret") return PREWZNMFILLIST_RET;
	if (s == "prewznmfillist.reu") return PREWZNMFILLIST_REU;
	if (s == "prewznmgiturl") return PREWZNMGITURL;
	if (s == "prewznmgroup") return PREWZNMGROUP;
	if (s == "prewznmiellist.ime") return PREWZNMIELLIST_IME;
	if (s == "prewznmiellist.srf") return PREWZNMIELLIST_SRF;
	if (s == "prewznmiellist.tco") return PREWZNMIELLIST_TCO;
	if (s == "prewznmiellist.typ") return PREWZNMIELLIST_TYP;
	if (s == "prewznmiexlist.srf") return PREWZNMIEXLIST_SRF;
	if (s == "prewznmiexlist.ver") return PREWZNMIEXLIST_VER;
	if (s == "prewznmimelist.iex") return PREWZNMIMELIST_IEX;
	if (s == "prewznmimelist.srf") return PREWZNMIMELIST_SRF;
	if (s == "prewznmimelist.sup") return PREWZNMIMELIST_SUP;
	if (s == "prewznmimelist.tbl") return PREWZNMIMELIST_TBL;
	if (s == "prewznmip") return PREWZNMIP;
	if (s == "prewznmixbasereptype") return PREWZNMIXBASEREPTYPE;
	if (s == "prewznmixcrdaccapp") return PREWZNMIXCRDACCAPP;
	if (s == "prewznmixcrdaccblk") return PREWZNMIXCRDACCBLK;
	if (s == "prewznmixcrdacccal") return PREWZNMIXCRDACCCAL;
	if (s == "prewznmixcrdacccap") return PREWZNMIXCRDACCCAP;
	if (s == "prewznmixcrdacccar") return PREWZNMIXCRDACCCAR;
	if (s == "prewznmixcrdaccchk") return PREWZNMIXCRDACCCHK;
	if (s == "prewznmixcrdacccmp") return PREWZNMIXCRDACCCMP;
	if (s == "prewznmixcrdacccon") return PREWZNMIXCRDACCCON;
	if (s == "prewznmixcrdaccctp") return PREWZNMIXCRDACCCTP;
	if (s == "prewznmixcrdaccdlg") return PREWZNMIXCRDACCDLG;
	if (s == "prewznmixcrdaccerr") return PREWZNMIXCRDACCERR;
	if (s == "prewznmixcrdaccevt") return PREWZNMIXCRDACCEVT;
	if (s == "prewznmixcrdaccfil") return PREWZNMIXCRDACCFIL;
	if (s == "prewznmixcrdacciel") return PREWZNMIXCRDACCIEL;
	if (s == "prewznmixcrdacciex") return PREWZNMIXCRDACCIEX;
	if (s == "prewznmixcrdaccime") return PREWZNMIXCRDACCIME;
	if (s == "prewznmixcrdaccjob") return PREWZNMIXCRDACCJOB;
	if (s == "prewznmixcrdacclib") return PREWZNMIXCRDACCLIB;
	if (s == "prewznmixcrdaccloc") return PREWZNMIXCRDACCLOC;
	if (s == "prewznmixcrdaccmch") return PREWZNMIXCRDACCMCH;
	if (s == "prewznmixcrdaccmdl") return PREWZNMIXCRDACCMDL;
	if (s == "prewznmixcrdaccmtd") return PREWZNMIXCRDACCMTD;
	if (s == "prewznmixcrdaccopk") return PREWZNMIXCRDACCOPK;
	if (s == "prewznmixcrdaccopx") return PREWZNMIXCRDACCOPX;
	if (s == "prewznmixcrdaccpnl") return PREWZNMIXCRDACCPNL;
	if (s == "prewznmixcrdaccprj") return PREWZNMIXCRDACCPRJ;
	if (s == "prewznmixcrdaccprs") return PREWZNMIXCRDACCPRS;
	if (s == "prewznmixcrdaccpst") return PREWZNMIXCRDACCPST;
	if (s == "prewznmixcrdaccqco") return PREWZNMIXCRDACCQCO;
	if (s == "prewznmixcrdaccqmd") return PREWZNMIXCRDACCQMD;
	if (s == "prewznmixcrdaccqry") return PREWZNMIXCRDACCQRY;
	if (s == "prewznmixcrdaccrel") return PREWZNMIXCRDACCREL;
	if (s == "prewznmixcrdaccrls") return PREWZNMIXCRDACCRLS;
	if (s == "prewznmixcrdaccrtj") return PREWZNMIXCRDACCRTJ;
	if (s == "prewznmixcrdaccsbs") return PREWZNMIXCRDACCSBS;
	if (s == "prewznmixcrdaccseq") return PREWZNMIXCRDACCSEQ;
	if (s == "prewznmixcrdaccsge") return PREWZNMIXCRDACCSGE;
	if (s == "prewznmixcrdaccstb") return PREWZNMIXCRDACCSTB;
	if (s == "prewznmixcrdaccste") return PREWZNMIXCRDACCSTE;
	if (s == "prewznmixcrdacctag") return PREWZNMIXCRDACCTAG;
	if (s == "prewznmixcrdacctbl") return PREWZNMIXCRDACCTBL;
	if (s == "prewznmixcrdacctco") return PREWZNMIXCRDACCTCO;
	if (s == "prewznmixcrdaccusg") return PREWZNMIXCRDACCUSG;
	if (s == "prewznmixcrdaccusr") return PREWZNMIXCRDACCUSR;
	if (s == "prewznmixcrdaccutl") return PREWZNMIXCRDACCUTL;
	if (s == "prewznmixcrdaccvec") return PREWZNMIXCRDACCVEC;
	if (s == "prewznmixcrdaccver") return PREWZNMIXCRDACCVER;
	if (s == "prewznmixcrdaccvit") return PREWZNMIXCRDACCVIT;
	if (s == "prewznmixlcl") return PREWZNMIXLCL;
	if (s == "prewznmixord") return PREWZNMIXORD;
	if (s == "prewznmixpre") return PREWZNMIXPRE;
	if (s == "prewznmixrecacc") return PREWZNMIXRECACC;
	if (s == "prewznmjoblist.gbl") return PREWZNMJOBLIST_GBL;
	if (s == "prewznmjoblist.ret") return PREWZNMJOBLIST_RET;
	if (s == "prewznmjoblist.reu") return PREWZNMJOBLIST_REU;
	if (s == "prewznmjoblist.srf") return PREWZNMJOBLIST_SRF;
	if (s == "prewznmjoblist.typ") return PREWZNMJOBLIST_TYP;
	if (s == "prewznmjoblist.ver") return PREWZNMJOBLIST_VER;
	if (s == "prewznmjrefnotify") return PREWZNMJREFNOTIFY;
	if (s == "prewznmjrefsess") return PREWZNMJREFSESS;
	if (s == "prewznmlibamakefile.x1") return PREWZNMLIBAMAKEFILE_X1;
	if (s == "prewznmlibamakefile.x2") return PREWZNMLIBAMAKEFILE_X2;
	if (s == "prewznmlibapkglist.x1") return PREWZNMLIBAPKGLIST_X1;
	if (s == "prewznmliblist.srf") return PREWZNMLIBLIST_SRF;
	if (s == "prewznmloclist.srf") return PREWZNMLOCLIST_SRF;
	if (s == "prewznmmchamakefile.x1") return PREWZNMMCHAMAKEFILE_X1;
	if (s == "prewznmmchapar.x1") return PREWZNMMCHAPAR_X1;
	if (s == "prewznmmchlist.srf") return PREWZNMMCHLIST_SRF;
	if (s == "prewznmmchlist.sup") return PREWZNMMCHLIST_SUP;
	if (s == "prewznmmdllist.srf") return PREWZNMMDLLIST_SRF;
	if (s == "prewznmmdllist.ver") return PREWZNMMDLLIST_VER;
	if (s == "prewznmmtdlist.job") return PREWZNMMTDLIST_JOB;
	if (s == "prewznmmtdlist.srf") return PREWZNMMTDLIST_SRF;
	if (s == "prewznmnoadm") return PREWZNMNOADM;
	if (s == "prewznmopklist.srf") return PREWZNMOPKLIST_SRF;
	if (s == "prewznmopklist.typ") return PREWZNMOPKLIST_TYP;
	if (s == "prewznmopklist.ver") return PREWZNMOPKLIST_VER;
	if (s == "prewznmopxlist.opk") return PREWZNMOPXLIST_OPK;
	if (s == "prewznmopxlist.srf") return PREWZNMOPXLIST_SRF;
	if (s == "prewznmowner") return PREWZNMOWNER;
	if (s == "prewznmpnllist.car") return PREWZNMPNLLIST_CAR;
	if (s == "prewznmpnllist.ret") return PREWZNMPNLLIST_RET;
	if (s == "prewznmpnllist.reu") return PREWZNMPNLLIST_REU;
	if (s == "prewznmpnllist.srf") return PREWZNMPNLLIST_SRF;
	if (s == "prewznmpnllist.typ") return PREWZNMPNLLIST_TYP;
	if (s == "prewznmprjlist.grp") return PREWZNMPRJLIST_GRP;
	if (s == "prewznmprjlist.own") return PREWZNMPRJLIST_OWN;
	if (s == "prewznmprjlist.sho") return PREWZNMPRJLIST_SHO;
	if (s == "prewznmprjlist.tit") return PREWZNMPRJLIST_TIT;
	if (s == "prewznmprjlist.ver") return PREWZNMPRJLIST_VER;
	if (s == "prewznmprjmnperson.x1") return PREWZNMPRJMNPERSON_X1;
	if (s == "prewznmprsadetail.x1") return PREWZNMPRSADETAIL_X1;
	if (s == "prewznmprslist.grp") return PREWZNMPRSLIST_GRP;
	if (s == "prewznmprslist.lnm") return PREWZNMPRSLIST_LNM;
	if (s == "prewznmprslist.own") return PREWZNMPRSLIST_OWN;
	if (s == "prewznmprsmnproject.x1") return PREWZNMPRSMNPROJECT_X1;
	if (s == "prewznmpstlist.aty") return PREWZNMPSTLIST_ATY;
	if (s == "prewznmpstlist.ret") return PREWZNMPSTLIST_RET;
	if (s == "prewznmpstlist.reu") return PREWZNMPSTLIST_REU;
	if (s == "prewznmpstlist.srf") return PREWZNMPSTLIST_SRF;
	if (s == "prewznmpstlist.ver") return PREWZNMPSTLIST_VER;
	if (s == "prewznmqcolist.qry") return PREWZNMQCOLIST_QRY;
	if (s == "prewznmqcolist.srf") return PREWZNMQCOLIST_SRF;
	if (s == "prewznmqcolist.tco") return PREWZNMQCOLIST_TCO;
	if (s == "prewznmqcolist.typ") return PREWZNMQCOLIST_TYP;
	if (s == "prewznmqmdlist.pst") return PREWZNMQMDLIST_PST;
	if (s == "prewznmqmdlist.qry") return PREWZNMQMDLIST_QRY;
	if (s == "prewznmqmdlist.ret") return PREWZNMQMDLIST_RET;
	if (s == "prewznmqmdlist.reu") return PREWZNMQMDLIST_REU;
	if (s == "prewznmqmdlist.typ") return PREWZNMQMDLIST_TYP;
	if (s == "prewznmqryaclause.x1") return PREWZNMQRYACLAUSE_X1;
	if (s == "prewznmqrylist.qtb") return PREWZNMQRYLIST_QTB;
	if (s == "prewznmqrylist.srf") return PREWZNMQRYLIST_SRF;
	if (s == "prewznmqrylist.srl") return PREWZNMQRYLIST_SRL;
	if (s == "prewznmqrylist.sup") return PREWZNMQRYLIST_SUP;
	if (s == "prewznmqrylist.tbl") return PREWZNMQRYLIST_TBL;
	if (s == "prewznmqrylist.typ") return PREWZNMQRYLIST_TYP;
	if (s == "prewznmqrylist.ver") return PREWZNMQRYLIST_VER;
	if (s == "prewznmrefapp") return PREWZNMREFAPP;
	if (s == "prewznmrefblk") return PREWZNMREFBLK;
	if (s == "prewznmrefcai") return PREWZNMREFCAI;
	if (s == "prewznmrefcal") return PREWZNMREFCAL;
	if (s == "prewznmrefcap") return PREWZNMREFCAP;
	if (s == "prewznmrefcar") return PREWZNMREFCAR;
	if (s == "prewznmrefccp") return PREWZNMREFCCP;
	if (s == "prewznmrefcdc") return PREWZNMREFCDC;
	if (s == "prewznmrefcfb") return PREWZNMREFCFB;
	if (s == "prewznmrefchk") return PREWZNMREFCHK;
	if (s == "prewznmrefcmp") return PREWZNMREFCMP;
	if (s == "prewznmrefcon") return PREWZNMREFCON;
	if (s == "prewznmrefcpb") return PREWZNMREFCPB;
	if (s == "prewznmrefctp") return PREWZNMREFCTP;
	if (s == "prewznmrefdlg") return PREWZNMREFDLG;
	if (s == "prewznmreferr") return PREWZNMREFERR;
	if (s == "prewznmrefevt") return PREWZNMREFEVT;
	if (s == "prewznmreffed") return PREWZNMREFFED;
	if (s == "prewznmreffil") return PREWZNMREFFIL;
	if (s == "prewznmrefiel") return PREWZNMREFIEL;
	if (s == "prewznmrefiex") return PREWZNMREFIEX;
	if (s == "prewznmrefime") return PREWZNMREFIME;
	if (s == "prewznmrefjob") return PREWZNMREFJOB;
	if (s == "prewznmrefkls") return PREWZNMREFKLS;
	if (s == "prewznmreflib") return PREWZNMREFLIB;
	if (s == "prewznmrefloc") return PREWZNMREFLOC;
	if (s == "prewznmrefmch") return PREWZNMREFMCH;
	if (s == "prewznmrefmdl") return PREWZNMREFMDL;
	if (s == "prewznmrefmtb") return PREWZNMREFMTB;
	if (s == "prewznmrefmtd") return PREWZNMREFMTD;
	if (s == "prewznmrefoen") return PREWZNMREFOEN;
	if (s == "prewznmrefopk") return PREWZNMREFOPK;
	if (s == "prewznmrefopx") return PREWZNMREFOPX;
	if (s == "prewznmrefpnl") return PREWZNMREFPNL;
	if (s == "prewznmrefprj") return PREWZNMREFPRJ;
	if (s == "prewznmrefprs") return PREWZNMREFPRS;
	if (s == "prewznmrefpst") return PREWZNMREFPST;
	if (s == "prewznmrefqco") return PREWZNMREFQCO;
	if (s == "prewznmrefqmd") return PREWZNMREFQMD;
	if (s == "prewznmrefqry") return PREWZNMREFQRY;
	if (s == "prewznmrefqtb") return PREWZNMREFQTB;
	if (s == "prewznmrefrel") return PREWZNMREFREL;
	if (s == "prewznmrefrls") return PREWZNMREFRLS;
	if (s == "prewznmrefrlt") return PREWZNMREFRLT;
	if (s == "prewznmrefrtb") return PREWZNMREFRTB;
	if (s == "prewznmrefrtd") return PREWZNMREFRTD;
	if (s == "prewznmrefrtj") return PREWZNMREFRTJ;
	if (s == "prewznmrefsbs") return PREWZNMREFSBS;
	if (s == "prewznmrefsel") return PREWZNMREFSEL;
	if (s == "prewznmrefseq") return PREWZNMREFSEQ;
	if (s == "prewznmrefses") return PREWZNMREFSES;
	if (s == "prewznmrefsge") return PREWZNMREFSGE;
	if (s == "prewznmrefsns") return PREWZNMREFSNS;
	if (s == "prewznmrefsqk") return PREWZNMREFSQK;
	if (s == "prewznmrefstb") return PREWZNMREFSTB;
	if (s == "prewznmrefstc") return PREWZNMREFSTC;
	if (s == "prewznmrefste") return PREWZNMREFSTE;
	if (s == "prewznmrefstt") return PREWZNMREFSTT;
	if (s == "prewznmreftag") return PREWZNMREFTAG;
	if (s == "prewznmreftbl") return PREWZNMREFTBL;
	if (s == "prewznmreftco") return PREWZNMREFTCO;
	if (s == "prewznmrefusg") return PREWZNMREFUSG;
	if (s == "prewznmrefusr") return PREWZNMREFUSR;
	if (s == "prewznmrefvec") return PREWZNMREFVEC;
	if (s == "prewznmrefver") return PREWZNMREFVER;
	if (s == "prewznmrefvit") return PREWZNMREFVIT;
	if (s == "prewznmrelatitle.x1") return PREWZNMRELATITLE_X1;
	if (s == "prewznmrelatitle.x2") return PREWZNMRELATITLE_X2;
	if (s == "prewznmrellist.frs") return PREWZNMRELLIST_FRS;
	if (s == "prewznmrellist.frt") return PREWZNMRELLIST_FRT;
	if (s == "prewznmrellist.srl") return PREWZNMRELLIST_SRL;
	if (s == "prewznmrellist.sup") return PREWZNMRELLIST_SUP;
	if (s == "prewznmrellist.tbl") return PREWZNMRELLIST_TBL;
	if (s == "prewznmrellist.tos") return PREWZNMRELLIST_TOS;
	if (s == "prewznmrellist.tot") return PREWZNMRELLIST_TOT;
	if (s == "prewznmrellist.typ") return PREWZNMRELLIST_TYP;
	if (s == "prewznmrellist.ver") return PREWZNMRELLIST_VER;
	if (s == "prewznmrepfolder") return PREWZNMREPFOLDER;
	if (s == "prewznmrlslist.cmp") return PREWZNMRLSLIST_CMP;
	if (s == "prewznmrlslist.mch") return PREWZNMRLSLIST_MCH;
	if (s == "prewznmrlslist.srf") return PREWZNMRLSLIST_SRF;
	if (s == "prewznmrtjlist.app") return PREWZNMRTJLIST_APP;
	if (s == "prewznmrtjlist.job") return PREWZNMRTJLIST_JOB;
	if (s == "prewznmrtjlist.srf") return PREWZNMRTJLIST_SRF;
	if (s == "prewznmrtjlist.sup") return PREWZNMRTJLIST_SUP;
	if (s == "prewznmsbsatitle.x1") return PREWZNMSBSATITLE_X1;
	if (s == "prewznmsbsatitle.x2") return PREWZNMSBSATITLE_X2;
	if (s == "prewznmsbslist.srf") return PREWZNMSBSLIST_SRF;
	if (s == "prewznmsbslist.tbl") return PREWZNMSBSLIST_TBL;
	if (s == "prewznmseqlist.app") return PREWZNMSEQLIST_APP;
	if (s == "prewznmseqlist.srf") return PREWZNMSEQLIST_SRF;
	if (s == "prewznmsess") return PREWZNMSESS;
	if (s == "prewznmsgelist.job") return PREWZNMSGELIST_JOB;
	if (s == "prewznmsgelist.srf") return PREWZNMSGELIST_SRF;
	if (s == "prewznmsgelist.typ") return PREWZNMSGELIST_TYP;
	if (s == "prewznmstblist.sbs") return PREWZNMSTBLIST_SBS;
	if (s == "prewznmstblist.srf") return PREWZNMSTBLIST_SRF;
	if (s == "prewznmstblist.tbl") return PREWZNMSTBLIST_TBL;
	if (s == "prewznmstblist.typ") return PREWZNMSTBLIST_TYP;
	if (s == "prewznmstelist.seq") return PREWZNMSTELIST_SEQ;
	if (s == "prewznmstelist.srf") return PREWZNMSTELIST_SRF;
	if (s == "prewznmsuspsess") return PREWZNMSUSPSESS;
	if (s == "prewznmsysdate") return PREWZNMSYSDATE;
	if (s == "prewznmsysstamp") return PREWZNMSYSSTAMP;
	if (s == "prewznmsystime") return PREWZNMSYSTIME;
	if (s == "prewznmtaglist.cpb") return PREWZNMTAGLIST_CPB;
	if (s == "prewznmtaglist.grp") return PREWZNMTAGLIST_GRP;
	if (s == "prewznmtaglist.srf") return PREWZNMTAGLIST_SRF;
	if (s == "prewznmtblatitle.x1") return PREWZNMTBLATITLE_X1;
	if (s == "prewznmtblatitle.x2") return PREWZNMTBLATITLE_X2;
	if (s == "prewznmtbllist.ret") return PREWZNMTBLLIST_RET;
	if (s == "prewznmtbllist.reu") return PREWZNMTBLLIST_REU;
	if (s == "prewznmtbllist.srf") return PREWZNMTBLLIST_SRF;
	if (s == "prewznmtbllist.typ") return PREWZNMTBLLIST_TYP;
	if (s == "prewznmtbllist.ver") return PREWZNMTBLLIST_VER;
	if (s == "prewznmtcoatitle.x1") return PREWZNMTCOATITLE_X1;
	if (s == "prewznmtcoatitle.x2") return PREWZNMTCOATITLE_X2;
	if (s == "prewznmtcolist.fct") return PREWZNMTCOLIST_FCT;
	if (s == "prewznmtcolist.srf") return PREWZNMTCOLIST_SRF;
	if (s == "prewznmtcolist.tbl") return PREWZNMTCOLIST_TBL;
	if (s == "prewznmtcolist.typ") return PREWZNMTCOLIST_TYP;
	if (s == "prewznmtlast") return PREWZNMTLAST;
	if (s == "prewznmusgaaccess.x1") return PREWZNMUSGAACCESS_X1;
	if (s == "prewznmusgaaccess.x2") return PREWZNMUSGAACCESS_X2;
	if (s == "prewznmusglist.grp") return PREWZNMUSGLIST_GRP;
	if (s == "prewznmusglist.own") return PREWZNMUSGLIST_OWN;
	if (s == "prewznmusglist.srf") return PREWZNMUSGLIST_SRF;
	if (s == "prewznmusraaccess.x1") return PREWZNMUSRAACCESS_X1;
	if (s == "prewznmusraaccess.x2") return PREWZNMUSRAACCESS_X2;
	if (s == "prewznmusrlist.grp") return PREWZNMUSRLIST_GRP;
	if (s == "prewznmusrlist.own") return PREWZNMUSRLIST_OWN;
	if (s == "prewznmusrlist.prs") return PREWZNMUSRLIST_PRS;
	if (s == "prewznmusrlist.srf") return PREWZNMUSRLIST_SRF;
	if (s == "prewznmusrlist.usg") return PREWZNMUSRLIST_USG;
	if (s == "prewznmvecatitle.x1") return PREWZNMVECATITLE_X1;
	if (s == "prewznmvecatitle.x2") return PREWZNMVECATITLE_X2;
	if (s == "prewznmveclist.hkt") return PREWZNMVECLIST_HKT;
	if (s == "prewznmveclist.hku") return PREWZNMVECLIST_HKU;
	if (s == "prewznmveclist.srf") return PREWZNMVECLIST_SRF;
	if (s == "prewznmveclist.tgr") return PREWZNMVECLIST_TGR;
	if (s == "prewznmveclist.typ") return PREWZNMVECLIST_TYP;
	if (s == "prewznmveclist.ver") return PREWZNMVECLIST_VER;
	if (s == "prewznmverlist.bvr") return PREWZNMVERLIST_BVR;
	if (s == "prewznmverlist.grp") return PREWZNMVERLIST_GRP;
	if (s == "prewznmverlist.loc") return PREWZNMVERLIST_LOC;
	if (s == "prewznmverlist.own") return PREWZNMVERLIST_OWN;
	if (s == "prewznmverlist.prj") return PREWZNMVERLIST_PRJ;
	if (s == "prewznmverlist.ste") return PREWZNMVERLIST_STE;
	if (s == "prewznmvitlist.srf") return PREWZNMVITLIST_SRF;
	if (s == "prewznmvitlist.vec") return PREWZNMVITLIST_VEC;

	return(0);
};

string DbsWznm::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREWZNMADMIN) return("PreWznmAdmin");
	if (ix == PREWZNMAPPLIST_GRP) return("PreWznmAppList.grp");
	if (ix == PREWZNMAPPLIST_OWN) return("PreWznmAppList.own");
	if (ix == PREWZNMAPPLIST_TIT) return("PreWznmAppList.tit");
	if (ix == PREWZNMAPPLIST_TRG) return("PreWznmAppList.trg");
	if (ix == PREWZNMAPPLIST_VER) return("PreWznmAppList.ver");
	if (ix == PREWZNMBLKLIST_RET) return("PreWznmBlkList.ret");
	if (ix == PREWZNMBLKLIST_REU) return("PreWznmBlkList.reu");
	if (ix == PREWZNMBLKLIST_SRF) return("PreWznmBlkList.srf");
	if (ix == PREWZNMBLKLIST_TYP) return("PreWznmBlkList.typ");
	if (ix == PREWZNMBLKLIST_VER) return("PreWznmBlkList.ver");
	if (ix == PREWZNMCALLIST_IAT) return("PreWznmCalList.iat");
	if (ix == PREWZNMCALLIST_RAT) return("PreWznmCalList.rat");
	if (ix == PREWZNMCALLIST_RET) return("PreWznmCalList.ret");
	if (ix == PREWZNMCALLIST_REU) return("PreWznmCalList.reu");
	if (ix == PREWZNMCALLIST_SRF) return("PreWznmCalList.srf");
	if (ix == PREWZNMCALLIST_TYP) return("PreWznmCalList.typ");
	if (ix == PREWZNMCALLIST_VER) return("PreWznmCalList.ver");
	if (ix == PREWZNMCAPAPAR_X1) return("PreWznmCapAPar.x1");
	if (ix == PREWZNMCAPLIST_SRF) return("PreWznmCapList.srf");
	if (ix == PREWZNMCAPLIST_TPL) return("PreWznmCapList.tpl");
	if (ix == PREWZNMCAPLIST_VER) return("PreWznmCapList.ver");
	if (ix == PREWZNMCARLIST_MDL) return("PreWznmCarList.mdl");
	if (ix == PREWZNMCARLIST_RET) return("PreWznmCarList.ret");
	if (ix == PREWZNMCARLIST_REU) return("PreWznmCarList.reu");
	if (ix == PREWZNMCARLIST_SRF) return("PreWznmCarList.srf");
	if (ix == PREWZNMCHKLIST_SRF) return("PreWznmChkList.srf");
	if (ix == PREWZNMCHKLIST_TBL) return("PreWznmChkList.tbl");
	if (ix == PREWZNMCHKLIST_TCO) return("PreWznmChkList.tco");
	if (ix == PREWZNMCHKLIST_TYP) return("PreWznmChkList.typ");
	if (ix == PREWZNMCMPLIST_SRF) return("PreWznmCmpList.srf");
	if (ix == PREWZNMCMPLIST_TYP) return("PreWznmCmpList.typ");
	if (ix == PREWZNMCMPLIST_VER) return("PreWznmCmpList.ver");
	if (ix == PREWZNMCONAPAR_X1) return("PreWznmConAPar.x1");
	if (ix == PREWZNMCONAPAR_X2) return("PreWznmConAPar.x2");
	if (ix == PREWZNMCONLIST_HKT) return("PreWznmConList.hkt");
	if (ix == PREWZNMCONLIST_HKU) return("PreWznmConList.hku");
	if (ix == PREWZNMCONLIST_RET) return("PreWznmConList.ret");
	if (ix == PREWZNMCONLIST_REU) return("PreWznmConList.reu");
	if (ix == PREWZNMCONLIST_SCT) return("PreWznmConList.sct");
	if (ix == PREWZNMCONLIST_SRF) return("PreWznmConList.srf");
	if (ix == PREWZNMCONLIST_SUP) return("PreWznmConList.sup");
	if (ix == PREWZNMCONLIST_TYP) return("PreWznmConList.typ");
	if (ix == PREWZNMCTPAPAR_X1) return("PreWznmCtpAPar.x1");
	if (ix == PREWZNMCTPLIST_SRF) return("PreWznmCtpList.srf");
	if (ix == PREWZNMCTPLIST_VER) return("PreWznmCtpList.ver");
	if (ix == PREWZNMDLGLIST_CAR) return("PreWznmDlgList.car");
	if (ix == PREWZNMDLGLIST_RET) return("PreWznmDlgList.ret");
	if (ix == PREWZNMDLGLIST_REU) return("PreWznmDlgList.reu");
	if (ix == PREWZNMDLGLIST_SRF) return("PreWznmDlgList.srf");
	if (ix == PREWZNMDLGLIST_TYP) return("PreWznmDlgList.typ");
	if (ix == PREWZNMERRLIST_SRF) return("PreWznmErrList.srf");
	if (ix == PREWZNMERRLIST_VER) return("PreWznmErrList.ver");
	if (ix == PREWZNMEVTLIST_APP) return("PreWznmEvtList.app");
	if (ix == PREWZNMEVTLIST_SRF) return("PreWznmEvtList.srf");
	if (ix == PREWZNMEXTFOLDER) return("PreWznmExtfolder");
	if (ix == PREWZNMFILLIST_FNM) return("PreWznmFilList.fnm");
	if (ix == PREWZNMFILLIST_GRP) return("PreWznmFilList.grp");
	if (ix == PREWZNMFILLIST_OWN) return("PreWznmFilList.own");
	if (ix == PREWZNMFILLIST_RET) return("PreWznmFilList.ret");
	if (ix == PREWZNMFILLIST_REU) return("PreWznmFilList.reu");
	if (ix == PREWZNMGITURL) return("PreWznmGiturl");
	if (ix == PREWZNMGROUP) return("PreWznmGroup");
	if (ix == PREWZNMIELLIST_IME) return("PreWznmIelList.ime");
	if (ix == PREWZNMIELLIST_SRF) return("PreWznmIelList.srf");
	if (ix == PREWZNMIELLIST_TCO) return("PreWznmIelList.tco");
	if (ix == PREWZNMIELLIST_TYP) return("PreWznmIelList.typ");
	if (ix == PREWZNMIEXLIST_SRF) return("PreWznmIexList.srf");
	if (ix == PREWZNMIEXLIST_VER) return("PreWznmIexList.ver");
	if (ix == PREWZNMIMELIST_IEX) return("PreWznmImeList.iex");
	if (ix == PREWZNMIMELIST_SRF) return("PreWznmImeList.srf");
	if (ix == PREWZNMIMELIST_SUP) return("PreWznmImeList.sup");
	if (ix == PREWZNMIMELIST_TBL) return("PreWznmImeList.tbl");
	if (ix == PREWZNMIP) return("PreWznmIp");
	if (ix == PREWZNMIXBASEREPTYPE) return("PreWznmIxBasereptype");
	if (ix == PREWZNMIXCRDACCAPP) return("PreWznmIxCrdaccApp");
	if (ix == PREWZNMIXCRDACCBLK) return("PreWznmIxCrdaccBlk");
	if (ix == PREWZNMIXCRDACCCAL) return("PreWznmIxCrdaccCal");
	if (ix == PREWZNMIXCRDACCCAP) return("PreWznmIxCrdaccCap");
	if (ix == PREWZNMIXCRDACCCAR) return("PreWznmIxCrdaccCar");
	if (ix == PREWZNMIXCRDACCCHK) return("PreWznmIxCrdaccChk");
	if (ix == PREWZNMIXCRDACCCMP) return("PreWznmIxCrdaccCmp");
	if (ix == PREWZNMIXCRDACCCON) return("PreWznmIxCrdaccCon");
	if (ix == PREWZNMIXCRDACCCTP) return("PreWznmIxCrdaccCtp");
	if (ix == PREWZNMIXCRDACCDLG) return("PreWznmIxCrdaccDlg");
	if (ix == PREWZNMIXCRDACCERR) return("PreWznmIxCrdaccErr");
	if (ix == PREWZNMIXCRDACCEVT) return("PreWznmIxCrdaccEvt");
	if (ix == PREWZNMIXCRDACCFIL) return("PreWznmIxCrdaccFil");
	if (ix == PREWZNMIXCRDACCIEL) return("PreWznmIxCrdaccIel");
	if (ix == PREWZNMIXCRDACCIEX) return("PreWznmIxCrdaccIex");
	if (ix == PREWZNMIXCRDACCIME) return("PreWznmIxCrdaccIme");
	if (ix == PREWZNMIXCRDACCJOB) return("PreWznmIxCrdaccJob");
	if (ix == PREWZNMIXCRDACCLIB) return("PreWznmIxCrdaccLib");
	if (ix == PREWZNMIXCRDACCLOC) return("PreWznmIxCrdaccLoc");
	if (ix == PREWZNMIXCRDACCMCH) return("PreWznmIxCrdaccMch");
	if (ix == PREWZNMIXCRDACCMDL) return("PreWznmIxCrdaccMdl");
	if (ix == PREWZNMIXCRDACCMTD) return("PreWznmIxCrdaccMtd");
	if (ix == PREWZNMIXCRDACCOPK) return("PreWznmIxCrdaccOpk");
	if (ix == PREWZNMIXCRDACCOPX) return("PreWznmIxCrdaccOpx");
	if (ix == PREWZNMIXCRDACCPNL) return("PreWznmIxCrdaccPnl");
	if (ix == PREWZNMIXCRDACCPRJ) return("PreWznmIxCrdaccPrj");
	if (ix == PREWZNMIXCRDACCPRS) return("PreWznmIxCrdaccPrs");
	if (ix == PREWZNMIXCRDACCPST) return("PreWznmIxCrdaccPst");
	if (ix == PREWZNMIXCRDACCQCO) return("PreWznmIxCrdaccQco");
	if (ix == PREWZNMIXCRDACCQMD) return("PreWznmIxCrdaccQmd");
	if (ix == PREWZNMIXCRDACCQRY) return("PreWznmIxCrdaccQry");
	if (ix == PREWZNMIXCRDACCREL) return("PreWznmIxCrdaccRel");
	if (ix == PREWZNMIXCRDACCRLS) return("PreWznmIxCrdaccRls");
	if (ix == PREWZNMIXCRDACCRTJ) return("PreWznmIxCrdaccRtj");
	if (ix == PREWZNMIXCRDACCSBS) return("PreWznmIxCrdaccSbs");
	if (ix == PREWZNMIXCRDACCSEQ) return("PreWznmIxCrdaccSeq");
	if (ix == PREWZNMIXCRDACCSGE) return("PreWznmIxCrdaccSge");
	if (ix == PREWZNMIXCRDACCSTB) return("PreWznmIxCrdaccStb");
	if (ix == PREWZNMIXCRDACCSTE) return("PreWznmIxCrdaccSte");
	if (ix == PREWZNMIXCRDACCTAG) return("PreWznmIxCrdaccTag");
	if (ix == PREWZNMIXCRDACCTBL) return("PreWznmIxCrdaccTbl");
	if (ix == PREWZNMIXCRDACCTCO) return("PreWznmIxCrdaccTco");
	if (ix == PREWZNMIXCRDACCUSG) return("PreWznmIxCrdaccUsg");
	if (ix == PREWZNMIXCRDACCUSR) return("PreWznmIxCrdaccUsr");
	if (ix == PREWZNMIXCRDACCUTL) return("PreWznmIxCrdaccUtl");
	if (ix == PREWZNMIXCRDACCVEC) return("PreWznmIxCrdaccVec");
	if (ix == PREWZNMIXCRDACCVER) return("PreWznmIxCrdaccVer");
	if (ix == PREWZNMIXCRDACCVIT) return("PreWznmIxCrdaccVit");
	if (ix == PREWZNMIXLCL) return("PreWznmIxLcl");
	if (ix == PREWZNMIXORD) return("PreWznmIxOrd");
	if (ix == PREWZNMIXPRE) return("PreWznmIxPre");
	if (ix == PREWZNMIXRECACC) return("PreWznmIxRecacc");
	if (ix == PREWZNMJOBLIST_GBL) return("PreWznmJobList.gbl");
	if (ix == PREWZNMJOBLIST_RET) return("PreWznmJobList.ret");
	if (ix == PREWZNMJOBLIST_REU) return("PreWznmJobList.reu");
	if (ix == PREWZNMJOBLIST_SRF) return("PreWznmJobList.srf");
	if (ix == PREWZNMJOBLIST_TYP) return("PreWznmJobList.typ");
	if (ix == PREWZNMJOBLIST_VER) return("PreWznmJobList.ver");
	if (ix == PREWZNMJREFNOTIFY) return("PreWznmJrefNotify");
	if (ix == PREWZNMJREFSESS) return("PreWznmJrefSess");
	if (ix == PREWZNMLIBAMAKEFILE_X1) return("PreWznmLibAMakefile.x1");
	if (ix == PREWZNMLIBAMAKEFILE_X2) return("PreWznmLibAMakefile.x2");
	if (ix == PREWZNMLIBAPKGLIST_X1) return("PreWznmLibAPkglist.x1");
	if (ix == PREWZNMLIBLIST_SRF) return("PreWznmLibList.srf");
	if (ix == PREWZNMLOCLIST_SRF) return("PreWznmLocList.srf");
	if (ix == PREWZNMMCHAMAKEFILE_X1) return("PreWznmMchAMakefile.x1");
	if (ix == PREWZNMMCHAPAR_X1) return("PreWznmMchAPar.x1");
	if (ix == PREWZNMMCHLIST_SRF) return("PreWznmMchList.srf");
	if (ix == PREWZNMMCHLIST_SUP) return("PreWznmMchList.sup");
	if (ix == PREWZNMMDLLIST_SRF) return("PreWznmMdlList.srf");
	if (ix == PREWZNMMDLLIST_VER) return("PreWznmMdlList.ver");
	if (ix == PREWZNMMTDLIST_JOB) return("PreWznmMtdList.job");
	if (ix == PREWZNMMTDLIST_SRF) return("PreWznmMtdList.srf");
	if (ix == PREWZNMNOADM) return("PreWznmNoadm");
	if (ix == PREWZNMOPKLIST_SRF) return("PreWznmOpkList.srf");
	if (ix == PREWZNMOPKLIST_TYP) return("PreWznmOpkList.typ");
	if (ix == PREWZNMOPKLIST_VER) return("PreWznmOpkList.ver");
	if (ix == PREWZNMOPXLIST_OPK) return("PreWznmOpxList.opk");
	if (ix == PREWZNMOPXLIST_SRF) return("PreWznmOpxList.srf");
	if (ix == PREWZNMOWNER) return("PreWznmOwner");
	if (ix == PREWZNMPNLLIST_CAR) return("PreWznmPnlList.car");
	if (ix == PREWZNMPNLLIST_RET) return("PreWznmPnlList.ret");
	if (ix == PREWZNMPNLLIST_REU) return("PreWznmPnlList.reu");
	if (ix == PREWZNMPNLLIST_SRF) return("PreWznmPnlList.srf");
	if (ix == PREWZNMPNLLIST_TYP) return("PreWznmPnlList.typ");
	if (ix == PREWZNMPRJLIST_GRP) return("PreWznmPrjList.grp");
	if (ix == PREWZNMPRJLIST_OWN) return("PreWznmPrjList.own");
	if (ix == PREWZNMPRJLIST_SHO) return("PreWznmPrjList.sho");
	if (ix == PREWZNMPRJLIST_TIT) return("PreWznmPrjList.tit");
	if (ix == PREWZNMPRJLIST_VER) return("PreWznmPrjList.ver");
	if (ix == PREWZNMPRJMNPERSON_X1) return("PreWznmPrjMNPerson.x1");
	if (ix == PREWZNMPRSADETAIL_X1) return("PreWznmPrsADetail.x1");
	if (ix == PREWZNMPRSLIST_GRP) return("PreWznmPrsList.grp");
	if (ix == PREWZNMPRSLIST_LNM) return("PreWznmPrsList.lnm");
	if (ix == PREWZNMPRSLIST_OWN) return("PreWznmPrsList.own");
	if (ix == PREWZNMPRSMNPROJECT_X1) return("PreWznmPrsMNProject.x1");
	if (ix == PREWZNMPSTLIST_ATY) return("PreWznmPstList.aty");
	if (ix == PREWZNMPSTLIST_RET) return("PreWznmPstList.ret");
	if (ix == PREWZNMPSTLIST_REU) return("PreWznmPstList.reu");
	if (ix == PREWZNMPSTLIST_SRF) return("PreWznmPstList.srf");
	if (ix == PREWZNMPSTLIST_VER) return("PreWznmPstList.ver");
	if (ix == PREWZNMQCOLIST_QRY) return("PreWznmQcoList.qry");
	if (ix == PREWZNMQCOLIST_SRF) return("PreWznmQcoList.srf");
	if (ix == PREWZNMQCOLIST_TCO) return("PreWznmQcoList.tco");
	if (ix == PREWZNMQCOLIST_TYP) return("PreWznmQcoList.typ");
	if (ix == PREWZNMQMDLIST_PST) return("PreWznmQmdList.pst");
	if (ix == PREWZNMQMDLIST_QRY) return("PreWznmQmdList.qry");
	if (ix == PREWZNMQMDLIST_RET) return("PreWznmQmdList.ret");
	if (ix == PREWZNMQMDLIST_REU) return("PreWznmQmdList.reu");
	if (ix == PREWZNMQMDLIST_TYP) return("PreWznmQmdList.typ");
	if (ix == PREWZNMQRYACLAUSE_X1) return("PreWznmQryAClause.x1");
	if (ix == PREWZNMQRYLIST_QTB) return("PreWznmQryList.qtb");
	if (ix == PREWZNMQRYLIST_SRF) return("PreWznmQryList.srf");
	if (ix == PREWZNMQRYLIST_SRL) return("PreWznmQryList.srl");
	if (ix == PREWZNMQRYLIST_SUP) return("PreWznmQryList.sup");
	if (ix == PREWZNMQRYLIST_TBL) return("PreWznmQryList.tbl");
	if (ix == PREWZNMQRYLIST_TYP) return("PreWznmQryList.typ");
	if (ix == PREWZNMQRYLIST_VER) return("PreWznmQryList.ver");
	if (ix == PREWZNMREFAPP) return("PreWznmRefApp");
	if (ix == PREWZNMREFBLK) return("PreWznmRefBlk");
	if (ix == PREWZNMREFCAI) return("PreWznmRefCai");
	if (ix == PREWZNMREFCAL) return("PreWznmRefCal");
	if (ix == PREWZNMREFCAP) return("PreWznmRefCap");
	if (ix == PREWZNMREFCAR) return("PreWznmRefCar");
	if (ix == PREWZNMREFCCP) return("PreWznmRefCcp");
	if (ix == PREWZNMREFCDC) return("PreWznmRefCdc");
	if (ix == PREWZNMREFCFB) return("PreWznmRefCfb");
	if (ix == PREWZNMREFCHK) return("PreWznmRefChk");
	if (ix == PREWZNMREFCMP) return("PreWznmRefCmp");
	if (ix == PREWZNMREFCON) return("PreWznmRefCon");
	if (ix == PREWZNMREFCPB) return("PreWznmRefCpb");
	if (ix == PREWZNMREFCTP) return("PreWznmRefCtp");
	if (ix == PREWZNMREFDLG) return("PreWznmRefDlg");
	if (ix == PREWZNMREFERR) return("PreWznmRefErr");
	if (ix == PREWZNMREFEVT) return("PreWznmRefEvt");
	if (ix == PREWZNMREFFED) return("PreWznmRefFed");
	if (ix == PREWZNMREFFIL) return("PreWznmRefFil");
	if (ix == PREWZNMREFIEL) return("PreWznmRefIel");
	if (ix == PREWZNMREFIEX) return("PreWznmRefIex");
	if (ix == PREWZNMREFIME) return("PreWznmRefIme");
	if (ix == PREWZNMREFJOB) return("PreWznmRefJob");
	if (ix == PREWZNMREFKLS) return("PreWznmRefKls");
	if (ix == PREWZNMREFLIB) return("PreWznmRefLib");
	if (ix == PREWZNMREFLOC) return("PreWznmRefLoc");
	if (ix == PREWZNMREFMCH) return("PreWznmRefMch");
	if (ix == PREWZNMREFMDL) return("PreWznmRefMdl");
	if (ix == PREWZNMREFMTB) return("PreWznmRefMtb");
	if (ix == PREWZNMREFMTD) return("PreWznmRefMtd");
	if (ix == PREWZNMREFOEN) return("PreWznmRefOen");
	if (ix == PREWZNMREFOPK) return("PreWznmRefOpk");
	if (ix == PREWZNMREFOPX) return("PreWznmRefOpx");
	if (ix == PREWZNMREFPNL) return("PreWznmRefPnl");
	if (ix == PREWZNMREFPRJ) return("PreWznmRefPrj");
	if (ix == PREWZNMREFPRS) return("PreWznmRefPrs");
	if (ix == PREWZNMREFPST) return("PreWznmRefPst");
	if (ix == PREWZNMREFQCO) return("PreWznmRefQco");
	if (ix == PREWZNMREFQMD) return("PreWznmRefQmd");
	if (ix == PREWZNMREFQRY) return("PreWznmRefQry");
	if (ix == PREWZNMREFQTB) return("PreWznmRefQtb");
	if (ix == PREWZNMREFREL) return("PreWznmRefRel");
	if (ix == PREWZNMREFRLS) return("PreWznmRefRls");
	if (ix == PREWZNMREFRLT) return("PreWznmRefRlt");
	if (ix == PREWZNMREFRTB) return("PreWznmRefRtb");
	if (ix == PREWZNMREFRTD) return("PreWznmRefRtd");
	if (ix == PREWZNMREFRTJ) return("PreWznmRefRtj");
	if (ix == PREWZNMREFSBS) return("PreWznmRefSbs");
	if (ix == PREWZNMREFSEL) return("PreWznmRefSel");
	if (ix == PREWZNMREFSEQ) return("PreWznmRefSeq");
	if (ix == PREWZNMREFSES) return("PreWznmRefSes");
	if (ix == PREWZNMREFSGE) return("PreWznmRefSge");
	if (ix == PREWZNMREFSNS) return("PreWznmRefSns");
	if (ix == PREWZNMREFSQK) return("PreWznmRefSqk");
	if (ix == PREWZNMREFSTB) return("PreWznmRefStb");
	if (ix == PREWZNMREFSTC) return("PreWznmRefStc");
	if (ix == PREWZNMREFSTE) return("PreWznmRefSte");
	if (ix == PREWZNMREFSTT) return("PreWznmRefStt");
	if (ix == PREWZNMREFTAG) return("PreWznmRefTag");
	if (ix == PREWZNMREFTBL) return("PreWznmRefTbl");
	if (ix == PREWZNMREFTCO) return("PreWznmRefTco");
	if (ix == PREWZNMREFUSG) return("PreWznmRefUsg");
	if (ix == PREWZNMREFUSR) return("PreWznmRefUsr");
	if (ix == PREWZNMREFVEC) return("PreWznmRefVec");
	if (ix == PREWZNMREFVER) return("PreWznmRefVer");
	if (ix == PREWZNMREFVIT) return("PreWznmRefVit");
	if (ix == PREWZNMRELATITLE_X1) return("PreWznmRelATitle.x1");
	if (ix == PREWZNMRELATITLE_X2) return("PreWznmRelATitle.x2");
	if (ix == PREWZNMRELLIST_FRS) return("PreWznmRelList.frs");
	if (ix == PREWZNMRELLIST_FRT) return("PreWznmRelList.frt");
	if (ix == PREWZNMRELLIST_SRL) return("PreWznmRelList.srl");
	if (ix == PREWZNMRELLIST_SUP) return("PreWznmRelList.sup");
	if (ix == PREWZNMRELLIST_TBL) return("PreWznmRelList.tbl");
	if (ix == PREWZNMRELLIST_TOS) return("PreWznmRelList.tos");
	if (ix == PREWZNMRELLIST_TOT) return("PreWznmRelList.tot");
	if (ix == PREWZNMRELLIST_TYP) return("PreWznmRelList.typ");
	if (ix == PREWZNMRELLIST_VER) return("PreWznmRelList.ver");
	if (ix == PREWZNMREPFOLDER) return("PreWznmRepfolder");
	if (ix == PREWZNMRLSLIST_CMP) return("PreWznmRlsList.cmp");
	if (ix == PREWZNMRLSLIST_MCH) return("PreWznmRlsList.mch");
	if (ix == PREWZNMRLSLIST_SRF) return("PreWznmRlsList.srf");
	if (ix == PREWZNMRTJLIST_APP) return("PreWznmRtjList.app");
	if (ix == PREWZNMRTJLIST_JOB) return("PreWznmRtjList.job");
	if (ix == PREWZNMRTJLIST_SRF) return("PreWznmRtjList.srf");
	if (ix == PREWZNMRTJLIST_SUP) return("PreWznmRtjList.sup");
	if (ix == PREWZNMSBSATITLE_X1) return("PreWznmSbsATitle.x1");
	if (ix == PREWZNMSBSATITLE_X2) return("PreWznmSbsATitle.x2");
	if (ix == PREWZNMSBSLIST_SRF) return("PreWznmSbsList.srf");
	if (ix == PREWZNMSBSLIST_TBL) return("PreWznmSbsList.tbl");
	if (ix == PREWZNMSEQLIST_APP) return("PreWznmSeqList.app");
	if (ix == PREWZNMSEQLIST_SRF) return("PreWznmSeqList.srf");
	if (ix == PREWZNMSESS) return("PreWznmSess");
	if (ix == PREWZNMSGELIST_JOB) return("PreWznmSgeList.job");
	if (ix == PREWZNMSGELIST_SRF) return("PreWznmSgeList.srf");
	if (ix == PREWZNMSGELIST_TYP) return("PreWznmSgeList.typ");
	if (ix == PREWZNMSTBLIST_SBS) return("PreWznmStbList.sbs");
	if (ix == PREWZNMSTBLIST_SRF) return("PreWznmStbList.srf");
	if (ix == PREWZNMSTBLIST_TBL) return("PreWznmStbList.tbl");
	if (ix == PREWZNMSTBLIST_TYP) return("PreWznmStbList.typ");
	if (ix == PREWZNMSTELIST_SEQ) return("PreWznmSteList.seq");
	if (ix == PREWZNMSTELIST_SRF) return("PreWznmSteList.srf");
	if (ix == PREWZNMSUSPSESS) return("PreWznmSuspsess");
	if (ix == PREWZNMSYSDATE) return("PreWznmSysdate");
	if (ix == PREWZNMSYSSTAMP) return("PreWznmSysstamp");
	if (ix == PREWZNMSYSTIME) return("PreWznmSystime");
	if (ix == PREWZNMTAGLIST_CPB) return("PreWznmTagList.cpb");
	if (ix == PREWZNMTAGLIST_GRP) return("PreWznmTagList.grp");
	if (ix == PREWZNMTAGLIST_SRF) return("PreWznmTagList.srf");
	if (ix == PREWZNMTBLATITLE_X1) return("PreWznmTblATitle.x1");
	if (ix == PREWZNMTBLATITLE_X2) return("PreWznmTblATitle.x2");
	if (ix == PREWZNMTBLLIST_RET) return("PreWznmTblList.ret");
	if (ix == PREWZNMTBLLIST_REU) return("PreWznmTblList.reu");
	if (ix == PREWZNMTBLLIST_SRF) return("PreWznmTblList.srf");
	if (ix == PREWZNMTBLLIST_TYP) return("PreWznmTblList.typ");
	if (ix == PREWZNMTBLLIST_VER) return("PreWznmTblList.ver");
	if (ix == PREWZNMTCOATITLE_X1) return("PreWznmTcoATitle.x1");
	if (ix == PREWZNMTCOATITLE_X2) return("PreWznmTcoATitle.x2");
	if (ix == PREWZNMTCOLIST_FCT) return("PreWznmTcoList.fct");
	if (ix == PREWZNMTCOLIST_SRF) return("PreWznmTcoList.srf");
	if (ix == PREWZNMTCOLIST_TBL) return("PreWznmTcoList.tbl");
	if (ix == PREWZNMTCOLIST_TYP) return("PreWznmTcoList.typ");
	if (ix == PREWZNMTLAST) return("PreWznmTlast");
	if (ix == PREWZNMUSGAACCESS_X1) return("PreWznmUsgAAccess.x1");
	if (ix == PREWZNMUSGAACCESS_X2) return("PreWznmUsgAAccess.x2");
	if (ix == PREWZNMUSGLIST_GRP) return("PreWznmUsgList.grp");
	if (ix == PREWZNMUSGLIST_OWN) return("PreWznmUsgList.own");
	if (ix == PREWZNMUSGLIST_SRF) return("PreWznmUsgList.srf");
	if (ix == PREWZNMUSRAACCESS_X1) return("PreWznmUsrAAccess.x1");
	if (ix == PREWZNMUSRAACCESS_X2) return("PreWznmUsrAAccess.x2");
	if (ix == PREWZNMUSRLIST_GRP) return("PreWznmUsrList.grp");
	if (ix == PREWZNMUSRLIST_OWN) return("PreWznmUsrList.own");
	if (ix == PREWZNMUSRLIST_PRS) return("PreWznmUsrList.prs");
	if (ix == PREWZNMUSRLIST_SRF) return("PreWznmUsrList.srf");
	if (ix == PREWZNMUSRLIST_USG) return("PreWznmUsrList.usg");
	if (ix == PREWZNMVECATITLE_X1) return("PreWznmVecATitle.x1");
	if (ix == PREWZNMVECATITLE_X2) return("PreWznmVecATitle.x2");
	if (ix == PREWZNMVECLIST_HKT) return("PreWznmVecList.hkt");
	if (ix == PREWZNMVECLIST_HKU) return("PreWznmVecList.hku");
	if (ix == PREWZNMVECLIST_SRF) return("PreWznmVecList.srf");
	if (ix == PREWZNMVECLIST_TGR) return("PreWznmVecList.tgr");
	if (ix == PREWZNMVECLIST_TYP) return("PreWznmVecList.typ");
	if (ix == PREWZNMVECLIST_VER) return("PreWznmVecList.ver");
	if (ix == PREWZNMVERLIST_BVR) return("PreWznmVerList.bvr");
	if (ix == PREWZNMVERLIST_GRP) return("PreWznmVerList.grp");
	if (ix == PREWZNMVERLIST_LOC) return("PreWznmVerList.loc");
	if (ix == PREWZNMVERLIST_OWN) return("PreWznmVerList.own");
	if (ix == PREWZNMVERLIST_PRJ) return("PreWznmVerList.prj");
	if (ix == PREWZNMVERLIST_STE) return("PreWznmVerList.ste");
	if (ix == PREWZNMVITLIST_SRF) return("PreWznmVitList.srf");
	if (ix == PREWZNMVITLIST_VEC) return("PreWznmVitList.vec");

	return("");
};

string DbsWznm::VecVPreset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == PREWZNMEXTFOLDER) return("extract folder");
		if (ix == PREWZNMGITURL) return("Git URL");
		if (ix == PREWZNMIXBASEREPTYPE) return("base repository type");
		if (ix == PREWZNMREFAPP) return("accessor app");
		if (ix == PREWZNMREFBLK) return("block");
		if (ix == PREWZNMREFCAI) return("action-invoking control");
		if (ix == PREWZNMREFCAL) return("call");
		if (ix == PREWZNMREFCAP) return("capability");
		if (ix == PREWZNMREFCAR) return("card");
		if (ix == PREWZNMREFCCP) return("compileable component");
		if (ix == PREWZNMREFCDC) return("data change call");
		if (ix == PREWZNMREFCFB) return("feed-backed control");
		if (ix == PREWZNMREFCHK) return("feature check");
		if (ix == PREWZNMREFCMP) return("component");
		if (ix == PREWZNMREFCON) return("control");
		if (ix == PREWZNMREFCPB) return("capability");
		if (ix == PREWZNMREFCTP) return("capability template");
		if (ix == PREWZNMREFDLG) return("dialog");
		if (ix == PREWZNMREFERR) return("error");
		if (ix == PREWZNMREFEVT) return("event");
		if (ix == PREWZNMREFFED) return("feed");
		if (ix == PREWZNMREFFIL) return("file");
		if (ix == PREWZNMREFIEL) return("import/export column");
		if (ix == PREWZNMREFIEX) return("import/export complex");
		if (ix == PREWZNMREFIME) return("import/export");
		if (ix == PREWZNMREFJOB) return("job");
		if (ix == PREWZNMREFKLS) return("key list");
		if (ix == PREWZNMREFLIB) return("library");
		if (ix == PREWZNMREFLOC) return("locale");
		if (ix == PREWZNMREFMCH) return("machine");
		if (ix == PREWZNMREFMDL) return("module");
		if (ix == PREWZNMREFMTB) return("main table");
		if (ix == PREWZNMREFMTD) return("method");
		if (ix == PREWZNMREFOEN) return("operation engine");
		if (ix == PREWZNMREFOPK) return("operation pack");
		if (ix == PREWZNMREFOPX) return("operation");
		if (ix == PREWZNMREFPNL) return("panel");
		if (ix == PREWZNMREFPRJ) return("project");
		if (ix == PREWZNMREFPRS) return("person");
		if (ix == PREWZNMREFPST) return("presetting");
		if (ix == PREWZNMREFQCO) return("query column");
		if (ix == PREWZNMREFQMD) return("query modifier");
		if (ix == PREWZNMREFQRY) return("query");
		if (ix == PREWZNMREFQTB) return("query table");
		if (ix == PREWZNMREFREL) return("relation");
		if (ix == PREWZNMREFRLS) return("release");
		if (ix == PREWZNMREFRLT) return("relation table");
		if (ix == PREWZNMREFRTB) return("run-time data block");
		if (ix == PREWZNMREFRTD) return("run-time dispatch");
		if (ix == PREWZNMREFRTJ) return("run-time job");
		if (ix == PREWZNMREFSBS) return("subset");
		if (ix == PREWZNMREFSEQ) return("sequence");
		if (ix == PREWZNMREFSES) return("session");
		if (ix == PREWZNMREFSGE) return("stage");
		if (ix == PREWZNMREFSNS) return("sensitivity");
		if (ix == PREWZNMREFSQK) return("squawk");
		if (ix == PREWZNMREFSTB) return("stub");
		if (ix == PREWZNMREFSTC) return("storage table column");
		if (ix == PREWZNMREFSTE) return("state");
		if (ix == PREWZNMREFSTT) return("storage table");
		if (ix == PREWZNMREFTAG) return("tag");
		if (ix == PREWZNMREFTBL) return("table");
		if (ix == PREWZNMREFTCO) return("table column");
		if (ix == PREWZNMREFUSG) return("user group");
		if (ix == PREWZNMREFUSR) return("user");
		if (ix == PREWZNMREFVEC) return("vector");
		if (ix == PREWZNMREFVER) return("version");
		if (ix == PREWZNMREFVIT) return("vector item");
		if (ix == PREWZNMREPFOLDER) return("repository folder");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWznm::VecVRecaccess
 ******************************************************************************/

uint DbsWznm::VecVRecaccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	if (s == "none") return NONE;
	if (s == "view") return VIEW;

	return(0);
};

string DbsWznm::VecVRecaccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	if (ix == NONE) return("none");
	if (ix == VIEW) return("view");

	return("");
};

string DbsWznm::VecVRecaccess::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == FULL) return("full");
		if (ix == NONE) return("none");
		if (ix == VIEW) return("view");
		return(getSref(ix));
	};

	return("");
};

void DbsWznm::VecVRecaccess::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecVUserlevel
 ******************************************************************************/

uint DbsWznm::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	if (s == "gadm") return GADM;
	if (s == "reg") return REG;
	if (s == "vtor") return VTOR;

	return(0);
};

string DbsWznm::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	if (ix == GADM) return("gadm");
	if (ix == REG) return("reg");
	if (ix == VTOR) return("vtor");

	return("");
};

string DbsWznm::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ADM) return("administrator");
		if (ix == GADM) return("user group administrator");
		if (ix == REG) return("regular user");
		if (ix == VTOR) return("visitor");
		return(getSref(ix));
	};

	return("");
};

void DbsWznm::VecVUserlevel::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecVValuelist
 ******************************************************************************/

uint DbsWznm::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstwznmumpersontitle") return VLSTWZNMUMPERSONTITLE;

	return(0);
};

string DbsWznm::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTWZNMUMPERSONTITLE) return("VlstWznmUMPersonTitle");

	return("");
};

string DbsWznm::VecVValuelist::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VLSTWZNMUMPERSONTITLE) return("title");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWznm::VecVVartype
 ******************************************************************************/

uint DbsWznm::VecVVartype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "boolean") return BOOLEAN;
	if (s == "tinyint") return TINYINT;
	if (s == "utinyint") return UTINYINT;
	if (s == "smallint") return SMALLINT;
	if (s == "usmallint") return USMALLINT;
	if (s == "int") return INT;
	if (s == "uint") return UINT;
	if (s == "bigint") return BIGINT;
	if (s == "ubigint") return UBIGINT;
	if (s == "float") return FLOAT;
	if (s == "double") return DOUBLE;
	if (s == "string") return STRING;
	if (s == "booleanvec") return BOOLEANVEC;
	if (s == "utinyintvec") return UTINYINTVEC;
	if (s == "usmallintvec") return USMALLINTVEC;
	if (s == "intvec") return INTVEC;
	if (s == "uintvec") return UINTVEC;
	if (s == "ubigintvec") return UBIGINTVEC;
	if (s == "floatvec") return FLOATVEC;
	if (s == "doublevec") return DOUBLEVEC;
	if (s == "floatmat") return FLOATMAT;
	if (s == "doublemat") return DOUBLEMAT;
	if (s == "stringvec") return STRINGVEC;
	if (s == "vecsref") return VECSREF;
	if (s == "scrref") return SCRREF;

	return(0);
};

string DbsWznm::VecVVartype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == BOOLEAN) return("boolean");
	if (ix == TINYINT) return("tinyint");
	if (ix == UTINYINT) return("utinyint");
	if (ix == SMALLINT) return("smallint");
	if (ix == USMALLINT) return("usmallint");
	if (ix == INT) return("int");
	if (ix == UINT) return("uint");
	if (ix == BIGINT) return("bigint");
	if (ix == UBIGINT) return("ubigint");
	if (ix == FLOAT) return("float");
	if (ix == DOUBLE) return("double");
	if (ix == STRING) return("string");
	if (ix == BOOLEANVEC) return("booleanvec");
	if (ix == UTINYINTVEC) return("utinyintvec");
	if (ix == USMALLINTVEC) return("usmallintvec");
	if (ix == INTVEC) return("intvec");
	if (ix == UINTVEC) return("uintvec");
	if (ix == UBIGINTVEC) return("ubigintvec");
	if (ix == FLOATVEC) return("floatvec");
	if (ix == DOUBLEVEC) return("doublevec");
	if (ix == FLOATMAT) return("floatmat");
	if (ix == DOUBLEMAT) return("doublemat");
	if (ix == STRINGVEC) return("stringvec");
	if (ix == VECSREF) return("vecsref");
	if (ix == SCRREF) return("scrref");

	return("");
};

string DbsWznm::VecVVartype::getTitle(
			const uint ix
		) {
	if (ix == VOID) return("not applicable");
	if (ix == BOOLEAN) return("boolean");
	if (ix == TINYINT) return("integer / byte (8bit)");
	if (ix == UTINYINT) return("unsigned integer / byte (8bit)");
	if (ix == SMALLINT) return("integer (16bit)");
	if (ix == USMALLINT) return("unsigned integer (16bit)");
	if (ix == INT) return("integer (32bit)");
	if (ix == UINT) return("unsigned integer (32bit)");
	if (ix == BIGINT) return("integer (64bit)");
	if (ix == UBIGINT) return("unsigned integer (64bit)");
	if (ix == FLOAT) return("float");
	if (ix == DOUBLE) return("double");
	if (ix == STRING) return("string");
	if (ix == BOOLEANVEC) return("boolean vector");
	if (ix == UTINYINTVEC) return("unsigned int / byte 8bit vector");
	if (ix == USMALLINTVEC) return("unsigned int 16bit vector");
	if (ix == INTVEC) return("integer 32bit vector");
	if (ix == UINTVEC) return("unsigned int 32bit vector");
	if (ix == UBIGINTVEC) return("unsigned int 64bit vector");
	if (ix == FLOATVEC) return("float vector");
	if (ix == DOUBLEVEC) return("double vector");
	if (ix == FLOATMAT) return("float matrix");
	if (ix == DOUBLEMAT) return("double matrix");
	if (ix == STRINGVEC) return("string vector");
	if (ix == VECSREF) return("vector entry string reference");
	if (ix == SCRREF) return("scrambled reference");
	return(getSref(ix));

	return("");
};

void DbsWznm::VecVVartype::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 26; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

/******************************************************************************
 class DbsWznm::VecWAccess
 ******************************************************************************/

uint DbsWznm::VecWAccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsWznm::VecWAccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VIEW); i *= 2) if (ix & i) ics.insert(i);
};

string DbsWznm::VecWAccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsWznm::VecWAccess::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == EDIT) return("edit");
		if (ix == EXEC) return("execute");
		if (ix == VIEW) return("view");
		return(getSrefs(ix));
	};

	return("");
};

void DbsWznm::VecWAccess::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= VIEW; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DbsWznm::VecWArgtype
 ******************************************************************************/

uint DbsWznm::VecWArgtype::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "ix") ix |= IX;
		else if (ss[i] == "ref") ix |= REF;
		else if (ss[i] == "refs") ix |= REFS;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "intval") ix |= INTVAL;
		else if (ss[i] == "dblval") ix |= DBLVAL;
		else if (ss[i] == "boolval") ix |= BOOLVAL;
		else if (ss[i] == "txtval") ix |= TXTVAL;
	};

	return(ix);
};

void DbsWznm::VecWArgtype::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TXTVAL); i *= 2) if (ix & i) ics.insert(i);
};

string DbsWznm::VecWArgtype::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IX) ss.push_back("ix");
	if (ix & REF) ss.push_back("ref");
	if (ix & REFS) ss.push_back("refs");
	if (ix & SREF) ss.push_back("sref");
	if (ix & INTVAL) ss.push_back("intval");
	if (ix & DBLVAL) ss.push_back("dblval");
	if (ix & BOOLVAL) ss.push_back("boolval");
	if (ix & TXTVAL) ss.push_back("txtval");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsWznm::VecWArgtype::getTitle(
			const uint ix
		) {
	if (ix == IX) return("vector item index");
	if (ix == REF) return("record reference");
	if (ix == REFS) return("set of record references");
	if (ix == SREF) return("string reference");
	if (ix == INTVAL) return("integer value");
	if (ix == DBLVAL) return("double value");
	if (ix == BOOLVAL) return("boolean value");
	if (ix == TXTVAL) return("text value");
	return(getSrefs(ix));

	return("");
};

void DbsWznm::VecWArgtype::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= TXTVAL; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i));
};

/******************************************************************************
 class DbsWznm::VecWScope
 ******************************************************************************/

uint DbsWznm::VecWScope::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "app") ix |= APP;
		else if (ss[i] == "cmbeng") ix |= CMBENG;
		else if (ss[i] == "eng") ix |= ENG;
		else if (ss[i] == "openg") ix |= OPENG;
	};

	return(ix);
};

void DbsWznm::VecWScope::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*OPENG); i *= 2) if (ix & i) ics.insert(i);
};

string DbsWznm::VecWScope::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & APP) ss.push_back("app");
	if (ix & CMBENG) ss.push_back("cmbeng");
	if (ix & ENG) ss.push_back("eng");
	if (ix & OPENG) ss.push_back("openg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsWznm::VecWScope::getTitle(
			const uint ix
		) {
	if (ix == APP) return("app");
	if (ix == CMBENG) return("combined engine");
	if (ix == ENG) return("main engine");
	if (ix == OPENG) return("operation engine");
	return(getSrefs(ix));

	return("");
};

void DbsWznm::VecWScope::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= OPENG; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i));
};
