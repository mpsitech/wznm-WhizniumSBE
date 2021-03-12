/**
	* \file WznmWrsrvInixml.cpp
	* Wznm operation processor - write initialization XML file (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvInixml.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrvInixml
 ******************************************************************************/

DpchRetWznm* WznmWrsrvInixml::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvInixml* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream xmlfile;
	fstream txtfile;

	vector<ubigint> refs;
	ubigint ref;

	string version;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	bool preflclonly;

	ListWznmMLocale locs;
	WznmMLocale* loc = NULL;

	map<ubigint,string> locsrefs;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	map<ubigint,string> vecsrefs;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vitJs;
	WznmJMVectoritem* vitJ = NULL;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	map<ubigint,string> mrsTits;
	map<ubigint,string> fnmTits;
	map<ubigint,string> lnmTits;

	unsigned int num;

	string srefKlsAkey, srefKakJkey;

	string s;

	size_t ptr;

	string prjshort = StrMod::lc(Prjshort);

	s = xchg->tmppath + "/" + folder + "/Iex" + Prjshort + "Ini.xml";
	xmlfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/Iex" + Prjshort + "Ini.txt";
	txtfile.open(s.c_str(), ios::out);

	version = StubWznm::getStubVerStd(dbswznm, refWznmMVersion);
	ptr = version.rfind(" v");
	if (ptr != string::npos) version = version.substr(ptr+2);

	Wznm::getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, locs);
	for (unsigned int i = 0; i < locs.nodes.size(); i++) {
		loc = locs.nodes[i];
		locsrefs[loc->ref] = loc->sref;
	};

	if (dbswznm->loadRefBySQL("SELECT refWznmMLocale FROM TblWznmMVersion WHERE ref = " + to_string(refWznmMVersion), ref)) locsrefs[0] = locsrefs[ref];

	xmlfile << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << endl;
	xmlfile << "<Iex" << Prjshort << "Ini version=\"" << version << "\">" << endl;

	txtfile << "Iex" << Prjshort << "Ini v" << version << endl;

	// --- ImeIAVKeylistKey
	srefKlsAkey = "ImeIAVKeylistKey";
	srefKakJkey = "ImeIJAVKeylistKey";

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMImpexpcplx WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Iex" + Prjshort + "Ini'", ref)) {
		dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(ref) + " AND supLvl = 0 AND sref LIKE 'ImeIAVKeylistKey%'", srefKlsAkey);
		dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(ref) + " AND supLvl = 1 AND sref LIKE 'ImeIJAVKeylistKey%'", srefKakJkey);
	};

	dbswznm->tblwznmmvector->loadRstByTypVer(VecWznmVMVectorBasetype::KLST, refWznmMVersion, false, vecs);

	vecsrefs.clear();
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		vecsrefs[vec->ref] = vec->sref;
	};

	vits.clear();
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) dbswznm->tblwznmmvectoritem->loadRstByVec(vecs.nodes[i]->ref, true, vits);

	if (vits.nodes.size() > 0) {
		xmlfile << "\t<" << srefKlsAkey << ">" << endl;
		txtfile << srefKlsAkey << ".srefKlsIx" << Prjshort << "VKeylist\tsref\tAvail\tImplied\tTitle\tComment" << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			dbswznm->tblwznmjmvectoritem->loadRstByVit(vit->ref, false, vitJs);

			preflclonly = (vitJs.nodes.size() <= 1);

			// primary locale first
			for (unsigned int j = 1; j < vitJs.nodes.size(); j++) {
				vitJ = vitJs.nodes[j];

				if (vitJ->x1RefWznmMLocale == refLcl) {
					vitJs.nodes[j] = vitJs.nodes[0];
					vitJs.nodes[0] = vitJ;
					
					break;
				};
			};

			xmlfile << "\t\t<Ii num=\"" << (i+1) << "\">" << endl;
			xmlfile << "\t\t\t<kls>" << vecsrefs[vit->vecRefWznmMVector] << "</kls>" << endl;
			xmlfile << "\t\t\t<srf>" << vit->sref << "</srf>" << endl;
			if (vit->Avail != "") xmlfile << "\t\t\t<avl>" << vit->Avail << "</avl>" << endl;
			if (vit->Implied != "") xmlfile << "\t\t\t<imp>" << vit->Implied << "</imp>" << endl;
			if (preflclonly) {
				xmlfile << "\t\t\t<tit>" << vit->Title << "</tit>" << endl;
				if (vit->Comment != "") xmlfile << "\t\t\t<cmt>" << vit->Comment << "</cmt>" << endl;
			};

			txtfile << vecsrefs[vit->vecRefWznmMVector] << "\t" << vit->sref << "\t" << vit->Avail << "\t" << vit->Implied;
			if (preflclonly) txtfile << "\t" << vit->Title << "\t" << vit->Comment;
			else txtfile << "\t\t";
			txtfile << endl;

			if (!preflclonly) {
				xmlfile << "\t\t\t<" << srefKakJkey << ">" << endl;
				txtfile << "\t- " << srefKakJkey << ".srefX1" << Prjshort << "VLocale\tTitle\tComment" << endl;

				for (unsigned int j = 0; j < vitJs.nodes.size(); j++) {
					vitJ = vitJs.nodes[j];

					xmlfile << "\t\t\t\t<Ii num=\"" << (j+1) << "\">" << endl;
					xmlfile << "\t\t\t\t\t<lcl>" << locsrefs[vitJ->x1RefWznmMLocale] << "</lcl>" << endl;
					xmlfile << "\t\t\t\t\t<tit>" << vitJ->Title << "</tit>" << endl;
					if (vitJ->Comment != "") xmlfile << "\t\t\t\t\t<cmt>" << vitJ->Comment << "</cmt>" << endl;
					xmlfile << "\t\t\t\t</Ii>" << endl;

					txtfile << "\t" << locsrefs[vitJ->x1RefWznmMLocale] << "\t" << vitJ->Title << "\t" << vitJ->Comment << endl;
				};

				xmlfile << "\t\t\t</" << srefKakJkey << ">" << endl;
				txtfile << "\t" << srefKakJkey << ".end" << endl;
			};

			xmlfile << "\t\t</Ii>" << endl;
		};

		xmlfile << "\t</" << srefKlsAkey << ">" << endl;
		txtfile << srefKlsAkey << ".end" << endl;
	};

	// --- ImeIAVValuelistVal
	dbswznm->tblwznmmvector->loadRstByTypVer(VecWznmVMVectorBasetype::VLST, refWznmMVersion, false, vecs);

	// ...

	// --- ImeIAVControlPar
	// ...

	// --- ImeIMUsergroup
	cars.clear();
	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	Wznm::getTagtits(dbswznm, "mrs", "prstit", "", {}, refLcl, refsLcl, mrsTits);
	Wznm::getTagtits(dbswznm, "fnm", "prs", "", {}, refLcl, refsLcl, fnmTits);
	Wznm::getTagtits(dbswznm, "lnm", "prs", "", {}, refLcl, refsLcl, lnmTits);

	xmlfile << "\t<ImeIMUsergroup>" << endl;
	xmlfile << "\t\t<Ii num=\"1\">" << endl;
	xmlfile << "\t\t\t<srf>" << prjshort << "users</srf>" << endl;

	txtfile << "ImeIMUsergroup.sref\tComment" << endl;
	txtfile << prjshort << "users" << endl;

	xmlfile << "\t\t\t<ImeIAMUsergroupAccess>" << endl;

	txtfile << "\tImeIAMUsergroupAccess.srefX1Ix" << Prjshort << "VFeatgroup\tx2FeaSrefUix\tsrefsIx" << Prjshort << "WAccess" << endl;

	num = 1;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref != ("Crd" + Prjshort + "Nav")) {
			xmlfile << "\t\t\t\t<Ii num=\"" << num << "\">" << endl;
			xmlfile << "\t\t\t\t\t<feg>Vec" << Prjshort << "VCard</feg>" << endl;
			xmlfile << "\t\t\t\t\t<fea>" << car->sref << "</fea>" << endl;
			xmlfile << "\t\t\t\t\t<acc>edit;exec;view</acc>" << endl;
			xmlfile << "\t\t\t\t</Ii>" << endl;

			txtfile << "\tVec" << Prjshort << "VCard\t" << car->sref << "\tedit;exec;view" << endl;

			num++;
		};
	};

	xmlfile << "\t\t\t</ImeIAMUsergroupAccess>" << endl;
	txtfile << "\tImeIAMUsergroupAccess.end" << endl;

	xmlfile << "\t\t\t<ImeIMUser>" << endl;

	txtfile << "\tImeIMUser.sref\tsrefIxVState\tsrefIx" << Prjshort << "VLocale\tsrefIx" << Prjshort << "VUserlevel\tPassword\tComment" << endl;

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		xmlfile << "\t\t\t\t<Ii num=\"" << (i+1) << "\">" << endl;

		if (refsLcl[i] == refLcl) xmlfile << "\t\t\t\t\t<srf>" << prjshort << "user</srf>" << endl;
		else xmlfile << "\t\t\t\t\t<srf>" << prjshort << "user" << locsrefs[refsLcl[i]] << "</srf>" << endl;

		xmlfile << "\t\t\t\t\t<ste>act</ste>" << endl;
		xmlfile << "\t\t\t\t\t<lcl>" << locsrefs[refsLcl[i]] << "</lcl>" << endl;
		xmlfile << "\t\t\t\t\t<ulv>adm</ulv>" << endl;
		xmlfile << "\t\t\t\t\t<pwd>asdf1234</pwd>" << endl;

		if (refsLcl[i] == refLcl) txtfile << "\t" << prjshort << "user\tact\t" << locsrefs[refsLcl[i]] << "\tadm\tasdf1234" << endl;
		else txtfile << "\t" << prjshort << "user" << locsrefs[refsLcl[i]] << "\tact\t" << locsrefs[refsLcl[i]] << "\tadm\tasdf1234" << endl;

		xmlfile << "\t\t\t\t\t<ImeIMPerson>" << endl;
		xmlfile << "\t\t\t\t\t\t<Ii num=\"1\">" << endl;
		xmlfile << "\t\t\t\t\t\t\t<sex>f</sex>" << endl;
		xmlfile << "\t\t\t\t\t\t\t<tit>" << mrsTits[refsLcl[i]] << "</tit>" << endl;
		xmlfile << "\t\t\t\t\t\t\t<fnm>" << fnmTits[refsLcl[i]] << "</fnm>" << endl;
		xmlfile << "\t\t\t\t\t\t\t<lnm>" << lnmTits[refsLcl[i]] << "</lnm>" << endl;

		txtfile << "\t\tImeIMPerson.srefIxVSex\tTitle\tFirstname\tLastname" << endl;
		txtfile << "\t\tf\t" << mrsTits[refsLcl[i]] << "\t" << fnmTits[refsLcl[i]] << "\t" << lnmTits[refsLcl[i]] << endl;

		xmlfile << "\t\t\t\t\t\t</Ii>" << endl;

		xmlfile << "\t\t\t\t\t</ImeIMPerson>" << endl;
		txtfile << "\t\tImeIMPerson.end" << endl;

		xmlfile << "\t\t\t\t</Ii>" << endl;
	};

	xmlfile << "\t\t\t</ImeIMUser>" << endl;
	txtfile << "\tImeIMUser.end" << endl;

	xmlfile << "\t\t</Ii>" << endl;

	xmlfile << "\t</ImeIMUsergroup>" << endl;
	txtfile << "ImeIMUsergroup.end" << endl;

	xmlfile << "</Iex" << Prjshort << "Ini>" << endl;

	txtfile.close();
	xmlfile.close();
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
