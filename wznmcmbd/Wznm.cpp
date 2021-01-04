/**
	* \file Wznm.cpp
	* Wznm global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wznm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsWznm* dbswznm
			, const string& acvpath
			, const string& path
			, const ubigint grp
			, const ubigint own
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	WznmMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	dbswznm->tblwznmmfile->insertNewRec(&fil, grp, own, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbswznm->tblwznmmfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	// copy file
	s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

	res = system(s.c_str());
	if (res != 0) cout << "Acv::addfile() error copying file (" << res << ")" << endl;

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsWznm* dbswznm
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	WznmMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbswznm->tblwznmmfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbswznm->tblwznmmfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

		// copy file
		s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

		res = system(s.c_str());
		if (res != 0) cout << "Acv::alterfile() error copying file (" << res << ")" << endl;

		delete fil;
	};
};

string Acv::getfile(
			DbsWznm* dbswznm
			, const ubigint refWznmMFile
		) {
	WznmMFile* fil = NULL;

	ostringstream str;

	dbswznm->tblwznmmfile->loadRecByRef(refWznmMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixWznmVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixWznmVLop == VecWznmVLop::INS) insert(refsList, refsPool, ref);
	else if (ixWznmVLop == VecWznmVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsPool.size(); i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixWznmVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixWznmVOolop == VecWznmVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixWznmVOolop == VecWznmVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixWznmVOolop == VecWznmVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixWznmVOolop == VecWznmVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixWznmVOolop == VecWznmVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixWznmVOolop == VecWznmVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref1) {
			for (auto itList2 = refsList.begin(); itList2 != refsList.end(); itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	FILE* file;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename += "." + ext;

		file = fopen(filename.c_str(), "w+x");

		if (file) {
			fclose(file);
			valid = true;
		} else if (errno != EEXIST) break;
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// mkdir() fails if folder exists
#ifdef _WIN32
		valid = (mkdir(foldername.c_str()) == 0);
#else
		valid = (mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
#endif

		if (!valid) if (errno != EEXIST) break;
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i = 0; i < 8; i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- IBEGIN

/******************************************************************************
 namespace Concplxtype
 ******************************************************************************/

string Concplxtype::getSref(
			const unsigned int ix
		) {
	if (ix == INVALID) return("invalid");
	if (ix == BUT_CLUST) return("But_clust");
	if (ix == CHK) return("Chk");
	if (ix == CUS) return("Cus");
	if (ix == DLD) return("Dld");
	if (ix == HDG) return("Hdg");
	if (ix == LST) return("Lst");
	if (ix == LST_NOALT) return("Lst_noalt");
	if (ix == LST_TXFALT) return("Lst_txfalt");
	if (ix == LST_TXTALT) return("Lst_txtalt");
	if (ix == PUP) return("Pup");
	if (ix == PUP_PUP) return("Pup_pup");
	if (ix == PUP_TXFALT) return("Pup_txfalt");
	if (ix == PUP_VBAR) return("Pup_vbar");
	if (ix == SEP) return("Sep");
	if (ix == SLD) return("Sld");
	if (ix == SPC) return("Spc");
	if (ix == TXF) return("Txf");
	if (ix == TXT) return("Txt");
	if (ix == TXT_PUP) return("Txt_pup");
	if (ix == TXT_TXFALT) return("Txt_txfalt");
	if (ix == ULD) return("Uld");
	if (ix == UPD) return("Upd");

	return("");
};

/******************************************************************************
 class Trg
 ******************************************************************************/

Trg::Trg(
			const ubigint refWznmMTable
			, const ubigint refWznmMSubset
			, const ubigint incRefWznmMTablecol
			, const string& cond1
			, const string& cond2
			, const string& srefWznmMCard
			, const string& carrecpstcond
			, const string carpstcond
			, const string& sesspstcond
		) {
	this->refWznmMTable = refWznmMTable;
	this->refWznmMSubset = refWznmMSubset;
	this->incRefWznmMTablecol = incRefWznmMTablecol;
	this->cond1 = cond1;
	this->cond2 = cond2;
	this->srefWznmMCard = srefWznmMCard;
	this->carrecpstcond = carrecpstcond;
	this->carpstcond = carpstcond;
	this->sesspstcond = sesspstcond;
};
// IP cust --- IEND

/******************************************************************************
 namespace Wznm
 ******************************************************************************/

// IP gbl --- IBEGIN
string Wznm::getPrjshort(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
		) {
	string Prjshort;

	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = "
				+ to_string(refWznmMVersion), Prjshort);

	return(StrMod::cap(Prjshort));
};

void Wznm::getVerlclref(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, ubigint& refLcl
		) {
	refLcl = 0;

	dbswznm->loadRefBySQL("SELECT refWznmMLocale FROM TblWznmMVersion WHERE ref = " + to_string(refWznmMVersion), refLcl);
};

void Wznm::getVerlclsref(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, string& srefLcl
		) {
	srefLcl = "";

	dbswznm->loadStringBySQL("SELECT TblWznmMLocale.sref FROM TblWznmMVersion, TblWznmMLocale WHERE TblWznmMLocale.ref = TblWznmMVersion.refWznmMLocale AND TblWznmMVersion.ref = "
				+ to_string(refWznmMVersion), srefLcl);
};

void Wznm::getVerlclrefs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, ubigint& refLcl
			, vector<ubigint>& refsLcl
		) {
	getVerlclref(dbswznm, refWznmMVersion, refLcl);

	refsLcl.clear();
	if (refLcl != 0) refsLcl.push_back(refLcl);

	dbswznm->loadRefsBySQL("SELECT TblWznmMLocale.ref FROM TblWznmRMLocaleMVersion, TblWznmMLocale WHERE TblWznmMLocale.ref = TblWznmRMLocaleMVersion.refWznmMLocale AND TblWznmRMLocaleMVersion.refWznmMVersion = "
				+ to_string(refWznmMVersion) + " AND TblWznmMLocale.ref <> " + to_string(refLcl) + " ORDER BY TblWznmMLocale.sref ASC", true, refsLcl);
};

void Wznm::getVerlcls(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, ubigint& refLcl
			, vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);
	dbswznm->tblwznmmlocale->loadRstByRefs(refsLcl, false, lcls);
};

void Wznm::updateVerste(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const uint ixVState
		) {
	vector<ubigint> refs;
	ubigint ref;

	WznmJMVersionState* verJste = NULL;

	time_t rawtime;
	time(&rawtime);

	bool skip = false;

	if (dbswznm->tblwznmjmversionstate->loadRecBySQL("SELECT * FROM TblWznmJMVersionState WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND x1Start <= " + to_string(rawtime) + " ORDER BY x1Start DESC LIMIT 0,1", &verJste)) {
		if (verJste->ixVState == ixVState) skip = true;
	};

	if (!skip) {
		if (ixVState == VecWznmVMVersionState::READY) {
			// make sure other versions with the same number in state build-ready become abandonned
			dbswznm->loadRefsBySQL("SELECT TblWznmMVersion2.ref FROM TblWznmMVersion AS TblWznmMVersion1, TblWznmMVersion AS TblWznmMVersion2 WHERE TblWznmMVersion1.ref = " + to_string(refWznmMVersion)
						+ " AND TblWznmMVersion1.ref <> TblWznmMVersion2.ref AND TblWznmMVersion2.prjRefWznmMProject = TblWznmMVersion1.prjRefWznmMProject AND TblWznmMVersion2.Major = TblWznmMVersion1.Major"
						+ " AND TblWznmMVersion2.Minor = TblWznmMVersion1.Minor AND TblWznmMVersion2.Sub = TblWznmMVersion1.Sub AND TblWznmMVersion2.ixVState = " + to_string(VecWznmVMVersionState::READY), false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) updateVerste(dbswznm, refs[i], VecWznmVMVersionState::ABANDON);
		};

		// commence new state
		ref = dbswznm->tblwznmjmversionstate->insertNewRec(NULL, refWznmMVersion, rawtime, ixVState);
		dbswznm->executeQuery("UPDATE TblWznmMVersion SET refJState = " + to_string(ref) + ", ixVState = " + to_string(ixVState) + " WHERE ref = " + to_string(refWznmMVersion));
	};
};

void Wznm::getTagtits(
			DbsWznm* dbswznm
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const string& prj
			, const map<ubigint,string>& iextits
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, map<ubigint,string>& tagTits
			, const bool esc
		) {
	// if the tag can be found, it is ensured that tagTits receives one entry for each ref in refsLcl
	WznmMTag* tag = NULL;

	string s;

	tagTits.clear();

	if (dbswznm->tblwznmmtag->loadRecBySrfGrp(sref, osrefWznmKTaggrp, &tag)) {
		dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, refLcl, tag->Title);
		if (prj.length() > 0) tag->Title = StrMod::replacePlh(tag->Title, "prj", prj);
		if (!iextits.empty()) tag->Title = StrMod::replacePlh(tag->Title, "iextit", iextits.find(refLcl)->second);

		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			s = tag->Title;

			if (dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, refsLcl[i], s)) {
				if (prj.length() > 0) s = StrMod::replacePlh(s, "prj", prj);
				if (!iextits.empty()) s = StrMod::replacePlh(tag->Title, "iextit", iextits.find(refsLcl[i])->second);
			};

			if (esc) tagTits[refsLcl[i]] = StrMod::esc(s);
			else tagTits[refsLcl[i]] = s;
		};

		delete tag;
	};
};

void Wznm::fillVecFromTaggrp(
			DbsWznm* dbswznm
			, WznmMVector* vec
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	ListWznmMTag tags;
	WznmMTag* tag = NULL;

	map<ubigint,string> tagTits;

	WznmMVectoritem* vit = NULL;

	bool noloc = StrMod::srefInSrefs(vec->srefsKOption, "noloc");

	dbswznm->tblwznmmtag->loadRstByGrp(osrefWznmKTaggrp, false, tags);

	for (unsigned int i = 0; i < tags.nodes.size(); i++) {
		tag = tags.nodes[i];

		dbswznm->tblwznmmvectoritem->insertNewRec(&vit, vec->ref, i+1, tag->sref, "", "", 0, "", "");

		getTagtits(dbswznm, tag->sref, osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

		if (!tagTits.empty()) {
			if (noloc) {
				ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refLcl, tagTits[refLcl], "");

				vit->refJ = ref;
				vit->Title = tagTits[refLcl];
				dbswznm->tblwznmmvectoritem->updateRec(vit);

			} else {
				for (unsigned int j = 0; j < refsLcl.size(); j++) {
					ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refsLcl[j], tagTits[refsLcl[j]], "");

					if (refsLcl[j] == refLcl) {
						vit->refJ = ref;
						vit->Title = tagTits[refsLcl[j]];
						dbswznm->tblwznmmvectoritem->updateRec(vit);
					};
				};
			};
		};

		delete vit;
	};
};

bool Wznm::hasSubset(
			DbsWznm* dbswznm
			, const ubigint refWznmMTable
		) {
	uint cnt;

	dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(refWznmMTable), cnt);

	return(cnt > 0);
};

void Wznm::getSbsrels(
			DbsWznm* dbswznm
			, const ubigint refTbl
			, const ubigint refAsb
			, set<ubigint>& refsSbsainb
			, set<ubigint>& refsSbsbina
			, set<ubigint>& refsSbsxsec
		) {
	// used @ WznmGenDetui

	vector<ubigint> refs;

	ListWznmRMSubsetMSubset srss;
	WznmRMSubsetMSubset* srs = NULL;

	refsSbsainb.clear();
	refsSbsbina.clear();
	refsSbsxsec.clear();

	if (refAsb == 0) {
		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMSubset WHERE refWznmMTable = " + to_string(refTbl), false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) refsSbsbina.insert(refs[i]);

	} else {
		dbswznm->tblwznmrmsubsetmsubset->loadRstByAsb(refAsb, false, srss);
		for (unsigned int i = 0; i < srss.nodes.size(); i++) {
			srs = srss.nodes[i];

			if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::AINB) refsSbsainb.insert(srs->bsbRefWznmMSubset);
			else if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::BINA) refsSbsbina.insert(srs->bsbRefWznmMSubset);
			else if (srs->ixVReltype == VecWznmVRMSubsetMSubsetReltype::XSEC) refsSbsxsec.insert(srs->bsbRefWznmMSubset);
		};
	};
};

bool Wznm::getPnlconAvail(
			DbsWznm* dbswznm
			, const ubigint refSbs
			, set<ubigint>& refsSbsainb
			, set<ubigint>& refsSbsbina
			, set<ubigint>& refsSbsxsec
			, WznmMTable* basetbl
			, const ubigint refSbsTest
			, string& Avail
		) {
	// used for pnlavail/conavail @ WznmGenDetui

	bool retval = true;

	WznmMSubset* sbs = NULL;

	Avail = "";

	if ((refSbsTest != 0) && (refSbs != refSbsTest)) {
		if (refsSbsainb.find(refSbsTest) == refsSbsainb.end()) {
			if ((refsSbsbina.find(refSbsTest) != refsSbsbina.end()) || (refsSbsxsec.find(refSbsTest) != refsSbsxsec.end())) {
				if (dbswznm->tblwznmmsubset->loadRecByRef(refSbsTest, &sbs)) {
					Avail = basetbl->Short + ".inSbs(" + sbs->Short + ")";
					delete sbs;
				} else {
					retval = false;
				};

			} else {
				retval = false;
			};
		};
	};

	return retval;
};

void Wznm::getSesspsts(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, vector<string>& sesspsts
		) {
	ListWznmMPreset psts;

	sesspsts.clear();

	dbswznm->tblwznmmpreset->loadRstBySQL("SELECT * FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVScope = " + to_string(VecWznmVMPresetScope::SESS)
				+ " AND ((refIxVTbl = " + to_string(VecWznmVMPresetRefTbl::TBL) + ") OR (refIxVTbl = " + to_string(VecWznmVMPresetRefTbl::SBS) + ")) ORDER BY sref ASC", false, psts);

	// PreXxxxRefYyy -> refYyy
	for (unsigned int i = 0; i < psts.nodes.size(); i++) sesspsts.push_back(StrMod::uncap(psts.nodes[i]->sref.substr(3+4)));
};

ubigint Wznm::getRefCtp(
			DbsWznm* dbswznm
			, const string& sref
		) {
	ubigint retval = 0;

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCapability WHERE tplRefWznmMCapability = 0 AND sref = '" + sref + "'", retval);

	return retval;
};

void Wznm::getSrefsCtpCustops(
			DbsWznm* dbswznm
			, map<ubigint,string>& srefsCtpCustops
			, const uint ixWznmVKeylist
		) {
	ListWznmMCapability ctps;
	WznmMCapability* ctp = NULL;

	Feed feed;

	string Opksref;

	srefsCtpCustops.clear();

	dbswznm->tblwznmmcapability->loadRstBySQL("SELECT * FROM TblWznmMCapability WHERE tplRefWznmMCapability = 0", false, ctps);

	dbswznm->fillFeedFromKlst(ixWznmVKeylist, 1, feed);

	// keylist sref ex. KlstKWznmCtpWrstkitCustop
	// keylist key ex.       WznmCtpWrstkitArm

	Opksref = VecWznmVKeylist::getSref(ixWznmVKeylist);
	Opksref = Opksref.substr(4+1);
	if (Opksref.length() > 6) Opksref = Opksref.substr(0, Opksref.length()-6);

	for (unsigned int i = 0; i < ctps.nodes.size(); i++) {
		ctp = ctps.nodes[i];
		if (feed.getNumBySref(Opksref + StrMod::cap(ctp->sref)) != 0) srefsCtpCustops[ctp->ref] = Opksref + StrMod::cap(ctp->sref);
	};
};

bool Wznm::getCpa(
			DbsWznm* dbswznm
			, const ubigint refWznmMCapability
			, const string& x1SrefKKey
			, string& Val
		) {
	return(dbswznm->loadStringBySQL("SELECT Val FROM TblWznmAMCapabilityPar WHERE cpbRefWznmMCapability = " + to_string(refWznmMCapability) + " AND x1SrefKKey = '" + x1SrefKKey + "'", Val));
};

bool Wznm::getLibmkf(
			DbsWznm* dbswznm
			, const ubigint refWznmMLibrary
			, const ubigint x1RefWznmMMachine
			, vector<ubigint>& hrefsMch
			, const string& x2SrefKTag
			, string& Val
		) {
	Val = "";

	if (dbswznm->tblwznmamlibrarymakefile->loadValByLibMchTag(refWznmMLibrary, x1RefWznmMMachine, x2SrefKTag, Val)) return true;
	for (unsigned int i = 0; i < hrefsMch.size(); i++) if (dbswznm->tblwznmamlibrarymakefile->loadValByLibMchTag(refWznmMLibrary, hrefsMch[i], x2SrefKTag, Val)) return true;

	return false;
};

bool Wznm::getMchmkf(
			DbsWznm* dbswznm
			, const ubigint refWznmMMachine
			, vector<ubigint>& hrefsMch
			, const string& x1SrefKTag
			, string& Val
		) {
	Val = "";

	if (dbswznm->tblwznmammachinemakefile->loadValByMchTag(refWznmMMachine, x1SrefKTag, Val)) return true;
	for (unsigned int i = 0; i < hrefsMch.size(); i++) if (dbswznm->tblwznmammachinemakefile->loadValByMchTag(hrefsMch[i], x1SrefKTag, Val)) return true;

	return false;
};

bool Wznm::getMchpar(
			DbsWznm* dbswznm
			, const ubigint refWznmMMachine
			, vector<ubigint>& hrefsMch
			, const string& x1SrefKKey
			, string& Val
		) {
	Val = "";

	if (dbswznm->tblwznmammachinepar->loadValByMchKey(refWznmMMachine, x1SrefKKey, Val)) return true;
	for (unsigned int i = 0; i < hrefsMch.size(); i++) if (dbswznm->tblwznmammachinepar->loadValByMchKey(hrefsMch[i], x1SrefKKey, Val)) return true;

	return false;
};

void Wznm::getCarincs(
			DbsWznm* dbswznm
			, WznmMCard* car
			, ListWznmMTable& inctbls
			, map<ubigint,string>& incconds
			, map<ubigint,string>& incsbsconds
		) {
	WznmMTable* tbl = NULL;
	ubigint refSbs = 0;

	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	WznmMTable* inctbl = NULL;
	WznmMTablecol* tco = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	string inccond;
	string incsbscond;

	inctbls.clear();
	incconds.clear();
	incsbsconds.clear();

	if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
		dbswznm->tblwznmmtable->loadRecByRef(car->refUref, &tbl);

	} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
		dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = TblWznmMSubset.refWznmMTable AND TblWznmMSubset.ref = " + to_string(car->refUref), &tbl);

		refSbs = car->refUref;
	};

	if (tbl) {
		getSbsrels(dbswznm, tbl->ref, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec);

		dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::INC) + " AND frRefWznmMTable = " + to_string(tbl->ref), false, rels);
		dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1NSUBINC) + " AND frRefWznmMTable = " + to_string(tbl->ref), true, rels);

		for (unsigned int i = 0; i < rels.nodes.size(); i++) {
			rel = rels.nodes[i];

			if (getPnlconAvail(dbswznm, refSbs, refsSbsainb, refsSbsbina, refsSbsxsec, tbl, rel->frsRefWznmMSubset, incsbscond)) {
				if (dbswznm->tblwznmmtable->loadRecByRef(rel->toRefWznmMTable, &inctbl)) {
					inctbls.nodes.push_back(inctbl);

					inccond = "";
					if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND refWznmMRelation = " + to_string(rel->ref), &tco)) {
						inccond = "!" + tbl->Short + "." + tco->Short + "Eq(0)";
						delete tco;
					};
					incconds[inctbl->ref] = inccond;
					
					incsbsconds[inctbl->ref] = incsbscond;
				};
			};
		};

		delete tbl;
	};
};

void Wznm::getCarrecpsts(
			DbsWznm* dbswznm
			, WznmMCard* car
			, vector<string>& carrecpsts
		) {
	WznmMSubset* sbs = NULL;

	ListWznmMTable inctbls;
	WznmMTable* inctbl = NULL;
	map<ubigint,string> incconds;
	map<ubigint,string> incsbsconds;

	string s;

	carrecpsts.clear();

	if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
		if (dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMTable WHERE ref = " + to_string(car->refUref), s)) carrecpsts.push_back("ref" + StrMod::cap(s));

	} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
		if (dbswznm->tblwznmmsubset->loadRecByRef(car->refUref, &sbs)) {
			if (dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMTable WHERE ref = " + to_string(sbs->refWznmMTable), s)) carrecpsts.push_back("ref" + StrMod::cap(s));
			carrecpsts.push_back("ref" + StrMod::cap(sbs->Short));

			delete sbs;
		};
	};

	getCarincs(dbswznm, car, inctbls, incconds, incsbsconds);
	for (unsigned int i = 0; i < inctbls.nodes.size(); i++) {
		inctbl = inctbls.nodes[i];
		carrecpsts.push_back("ref" + StrMod::cap(inctbl->Short));
	};
};

void Wznm::getCarpsts(
			const vector<string>& sesspsts
			, WznmMCard* car
			, vector<string>& carsesspsts
			, vector<string>& carpsts
			, bool& always
			, bool& never
		) {
	Expr expr;

	carsesspsts.clear();
	carpsts.clear();

	if (car->Active != "") if (expr.tokenize(car->Active)) if (expr.parse()) if (expr.root != NULL) getCarpsts_collect(sesspsts, car, expr.root, carsesspsts, carpsts);

	always = ((car->Active == "") || StrMod::has(carpsts, "void"));
	never = ((car->Active != "") && carsesspsts.empty() && !StrMod::has(carpsts, "void"));
};

void Wznm::getCarpsts_collect(
			const vector<string>& sesspsts
			, WznmMCard* car
			, Expr::Node* node
			, vector<string>& carsesspsts
			, vector<string>& carpsts
		) {
	if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		if ((node->key.find("pre.") == 0) && (node->key.length() > 4)) {
			if (StrMod::has(sesspsts, node->key.substr(4))) carsesspsts.push_back(node->key.substr(4));
			carpsts.push_back(node->key.substr(4));
		};
	};

	for (unsigned int i = 0; i < node->subs.size(); i++) getCarpsts_collect(sesspsts, car, node->subs[i], carsesspsts, carpsts);
};

void Wznm::collectTrgs(
			DbsWznm* dbswznm
			, const vector<string>& sesspsts
			, WznmMCard* basecar
			, const vector<string>& basecarrecpsts
			, const vector<string>& basecarpsts // incl. void
			, WznmMTable* basetbl // in pnldetail, the trefspec/trefuniv ; in pnl1n/mn, the rec (equivalent to the target table, without subset information)
			, WznmMTablecol* basetco
			, WznmMRelation* rel
			, bool toNotFr
			, list<Trg*>& trgs
		) {
	// used for ButNew/ButView @ WznmGenDetui, WznmWrsrvPnl

	ubigint ref;

	WznmMRelation* suprel = NULL;

	ListWznmMRelation subrels;
	WznmMRelation* subrel = NULL;

	ListWznmMRelation increls;
	WznmMRelation* increl = NULL;

	WznmMTablecol* tco = NULL;

	WznmMCard* trgcar = NULL;

	WznmMSubset* sbs = NULL;

	set<ubigint> refsSbsainb;
	set<ubigint> refsSbsbina;
	set<ubigint> refsSbsxsec;

	Trg* trg = NULL;
	Trg* trg2 = NULL;

	string cond2;

	for (auto it = trgs.begin(); it != trgs.end(); it++) delete(*it);
	trgs.clear();

	// --- 1st step: find target tables and subsets
	if ((rel->supIxVSubrole == VecWznmVMRelationSupSubrole::FROM1N) || (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::TO1N)) {
		// find opposite side of mn relation (overrides toNotFr)
		toNotFr = (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::FROM1N);

		if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &suprel)) {
			if (toNotFr) trgs.push_back(new Trg(suprel->toRefWznmMTable, suprel->tosRefWznmMSubset));
			else trgs.push_back(new Trg(suprel->frRefWznmMTable, suprel->frsRefWznmMSubset));

			delete suprel;
		};

	} else if (!toNotFr && ((rel->ixVBasetype == VecWznmVMRelationBasetype::U1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::AU1N))) {
		// cond1 based on hkIxVTbl/refIxVTbl/..., ex. 'con.hktEq(dlg)'
		if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND tblRefWznmMTable = " + to_string(basetbl->ref) + " AND refWznmMRelation = "
					+ to_string(rel->ref) + " AND sref LIKE '%VTbl'", &tco)) {

			dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->ref), false, subrels);

			for (unsigned int i = 0; i < subrels.nodes.size(); i++) {
				subrel = subrels.nodes[i];

				trgs.push_back(new Trg(subrel->frRefWznmMTable, subrel->frsRefWznmMSubset, 0, basetbl->Short + "." + tco->Short + "Eq(" + subrel->Prefix + ")"));
			};

			delete tco;
		};

	} else if (toNotFr) {
		trgs.push_back(new Trg(rel->toRefWznmMTable, rel->tosRefWznmMSubset));

	} else if (!toNotFr) {
		trgs.push_back(new Trg(rel->frRefWznmMTable, rel->frsRefWznmMSubset));
	};

	// consider cases in which target table is inc'ed
	for (auto it = trgs.begin(); it != trgs.end(); it++) {
		trg = *it;

		dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(trg->refWznmMTable) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::INC), false, increls);
		dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(trg->refWznmMTable) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::U1NSUBINC), true, increls);

		for (unsigned int j = 0; j < increls.nodes.size(); j++) {
			increl = increls.nodes[j];

			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND tblRefWznmMTable = " + to_string(increl->frRefWznmMTable) + " AND refWznmMRelation = "
						+ to_string(increl->ref), ref)) {

				trg2 = new Trg(*trg);
				trg2->refWznmMTable = increl->frRefWznmMTable;
				trg2->incRefWznmMTablecol = ref;

				it = trgs.insert(++it, trg2);
			};
		};
	};

	// --- 2nd step: find matching cards
	for (auto it = trgs.begin(); it != trgs.end();) {
		trg = *it;

		getSbsrels(dbswznm, trg->refWznmMTable, trg->refWznmMSubset, refsSbsainb, refsSbsbina, refsSbsxsec);

		tco = NULL;
		if (trg->incRefWznmMTablecol != 0) {
			// find opposite side tco
			if (dbswznm->tblwznmmrelation->loadRecBySQL("SELECT TblWznmMRelation.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.ref = " + to_string(trg->incRefWznmMTablecol) + " AND TblWznmMRelation.ref = TblWznmMTablecol.refWznmMRelation", &increl)) {
				if (increl->ixVBasetype == VecWznmVMRelationBasetype::INC) {
					dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(increl->toRefWznmMTable) + " AND refWznmMRelation = " + to_string(increl->ref), &tco);
				} else if (increl->ixVBasetype == VecWznmVMRelationBasetype::U1NSUBINC) {
					dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(increl->toRefWznmMTable) + " AND refWznmMRelation = " + to_string(increl->supRefWznmMRelation), &tco);
				};

				delete increl;
			};
		};

		if (trg->refWznmMSubset != 0) {
			// card with target subset match
			if (dbswznm->loadRefBySQL("SELECT refWznmMCard FROM TblWznmMSubset WHERE ref = " + to_string(trg->refWznmMSubset), ref)) if (ref != 0) if (dbswznm->tblwznmmcard->loadRecByRef(ref, &trgcar)) {
				collectTrgs_matchPsts(sesspsts, basecarrecpsts, basecarpsts, trgcar, "", trgs, it);
				delete trgcar;
			};

			// cards with subsets that comprise target subset
			for (auto it2 = refsSbsainb.begin(); it2 != refsSbsainb.end(); it2++) if (dbswznm->loadRefBySQL("SELECT refWznmMCard FROM TblWznmMSubset WHERE ref = " + to_string(*it2), ref)) if (ref != 0)
						if (dbswznm->tblwznmmcard->loadRecByRef(ref, &trgcar)) {

				collectTrgs_matchPsts(sesspsts, basecarrecpsts, basecarpsts, trgcar, "", trgs, it);
				delete trgcar;
			};

			// cards with subsets that intersect with target subset (require cond2, ex. prt.reu.inSbs(mtp) ; for 1n/mn, basetco can be left empty for mdl.inSbs(mtp)) ; complication for inc: prt.reu.mdl.inSbs(mtp)
			for (auto it2 = refsSbsxsec.begin(); it2 != refsSbsxsec.end(); it2++) if (dbswznm->loadRefBySQL("SELECT refWznmMCard FROM TblWznmMSubset WHERE ref = " + to_string(*it2), ref)) if (ref != 0)
						if (dbswznm->tblwznmmcard->loadRecByRef(ref, &trgcar)) {

				if (dbswznm->tblwznmmsubset->loadRecByRef(*it2, &sbs)) {
					cond2 = basetbl->Short;
					if (basetco) cond2 += "." + basetco->Short;
					if (tco) cond2 += "." + tco->Short;
					cond2 += ".inSbs(" + sbs->Short + ")";

					collectTrgs_matchPsts(sesspsts, basecarrecpsts, basecarpsts, trgcar, cond2, trgs, it);

					delete sbs;
				};

				delete trgcar;
			};

		} else {
			// card without subset
			if (dbswznm->loadRefBySQL("SELECT refWznmMCard FROM TblWznmMTable WHERE ref = " + to_string(trg->refWznmMTable), ref)) if (ref != 0) if (dbswznm->tblwznmmcard->loadRecByRef(ref, &trgcar)) {
				collectTrgs_matchPsts(sesspsts, basecarrecpsts, basecarpsts, trgcar, "", trgs, it);
				delete trgcar;
			};

			// cards with subsets that are part of target subset (require cond2, ex. fed.ctl.inSbs(xyz) / ctl.inSbs(xyz)) ; complication for inc: prt.reu.mdl.inSbs(mtp)
			for (auto it2 = refsSbsbina.begin(); it2 != refsSbsbina.end(); it2++) if (dbswznm->loadRefBySQL("SELECT refWznmMCard FROM TblWznmMSubset WHERE ref = " + to_string(*it2), ref)) if (ref != 0)
						if (dbswznm->tblwznmmcard->loadRecByRef(ref, &trgcar)) {

				if (dbswznm->tblwznmmsubset->loadRecByRef(*it2, &sbs)) {
					cond2 = basetbl->Short;
					if (basetco) cond2 += "." + basetco->Short;
					if (tco) cond2 += "." + tco->Short;
					cond2 += ".inSbs(" + sbs->Short + ")";

					collectTrgs_matchPsts(sesspsts, basecarrecpsts, basecarpsts, trgcar, cond2, trgs, it);

					delete sbs;
				};

				delete trgcar;
			};
		};

		if (tco) delete tco;

		// in case of success, original trg will have been duplicated and inserted before it at this stage
		delete trg;
		it = trgs.erase(it);
	};
};

void Wznm::collectTrgs_matchPsts(
			const vector<string>& sesspsts // ex.: refPrj, refVer
			, const vector<string>& basecarrecpsts // ex.: refLoc, refEqp
			, const vector<string>& basecarpsts // may include void ; ex.: refVer, void
			, WznmMCard* trgcar
			, const string& cond2
			, list<Trg*>& trgs
			, list<Trg*>::iterator it
		) {
	Trg* trg = *it;
	Trg* trg2 = NULL;

	vector<string> trgcarsesspsts;

	vector<string> trgcarpsts;
	string trgcarpst;

	bool always;
	bool never;

	bool found;

	if (trgcar->Active == "") {
		trg2 = new Trg(*trg);
		trg2->srefWznmMCard = trgcar->sref;
		trg2->cond2 = cond2;
		trgs.insert(it, trg2);

	} else {
		getCarpsts(sesspsts, trgcar, trgcarsesspsts, trgcarpsts, always, never);

		found = false;

		// match to psts set by base card through record selection
		for (unsigned int i = 0; i < trgcarpsts.size(); i++) {
			trgcarpst = trgcarpsts[i];

			if (trgcarpst != "void") if (StrMod::has(basecarrecpsts, trgcarpst)) {
				trg2 = new Trg(*trg);
				trg2->srefWznmMCard = trgcar->sref;
				trg2->cond2 = cond2;
				trg2->carrecpstcond = "pre." + trgcarpst + "()";
				trgs.insert(it, trg2);

				found = true;
			};
		};

		if (!found) {
			// match to base card psts
			for (unsigned int i = 0; i < trgcarpsts.size(); i++) {
				trgcarpst = trgcarpsts[i];

				if (trgcarpst != "void") if (StrMod::has(basecarpsts, trgcarpst)) {
					trg2 = new Trg(*trg);
					trg2->srefWznmMCard = trgcar->sref;
					trg2->cond2 = cond2;
					trg2->carpstcond = "pre." + trgcarpst + "()";
					trgs.insert(it, trg2);
				};
			};

			// match to session psts
			for (unsigned int i = 0; i < trgcarpsts.size(); i++) {
				trgcarpst = trgcarpsts[i];

				if (trgcarpst != "void") if (StrMod::has(sesspsts, trgcarpst)) if (!StrMod::has(basecarpsts, trgcarpst)) {
					trg2 = new Trg(*trg);
					trg2->srefWznmMCard = trgcar->sref;
					trg2->cond2 = cond2;
					trg2->sesspstcond = "pre." + trgcarpst + "()";
					trgs.insert(it, trg2);
				};
			};

			// void pst
			if (StrMod::has(trgcarpsts, "void")) {
				trg2 = new Trg(*trg);
				trg2->srefWznmMCard = trgcar->sref;
				trg2->cond2 = cond2;
				trgs.insert(it, trg2);
			};
		};
	};
};

void Wznm::getCrdsubjobs(
			DbsWznm* dbswznm
			, ListWznmMJob& jobs
			, const ubigint refWznmMJob
		) {
	// return card's sub-jobs which are non-iex and not global exactly once
	vector<ubigint> refs;

	WznmMJob* job;

	bool found;

	if (dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job)) {
		if ((job->ixVBasetype != VecWznmVMJobBasetype::IEX) && (job->Global == false)) {
			found = false;

			for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
				if (jobs.nodes[i]->ref == job->ref) {
					found = true;
					break;
				};
			};

			if (found) {
				delete job;

			} else {
				jobs.nodes.push_back(job);
				
				// recursively look for sub-jobs
				dbswznm->loadRefsBySQL("SELECT subRefWznmMJob FROM TblWznmRMJobMJob WHERE supRefWznmMJob = " + to_string(refWznmMJob), false, refs);

				for (unsigned int i = 0; i < refs.size(); i++) getCrdsubjobs(dbswznm, jobs, refs[i]);
			};

		} else {
			delete job;
		};
	};
};

void Wznm::getPnlrecs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, WznmMCard* car
			, WznmMPanel* pnl
			, ListWznmMTable& tbls
			, const bool jump
		) {
	// used @ WznmGenChk, WznmWrsrvPnl
	vector<ubigint> refs;
	ubigint ref;

	ListWznmMTable inctbls;
	map<ubigint,string> incconds;
	map<ubigint,string> incsbsconds;

	WznmMRelation* rel = NULL;

	WznmMTable* tbl = NULL;

	unsigned int ix1;

	tbls.clear();

	if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) || ((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length())) ) {
		// rec or detail panel
		refs.push_back(pnl->refUref);

		getCarincs(dbswznm, car, inctbls, incconds, incsbsconds);
		for (unsigned int i = 0; i < inctbls.nodes.size(); i++) refs.push_back(inctbls.nodes[i]->ref);

	} else if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) && (pnl->refIxVTbl == VecWznmVMPanelRefTbl::REL)) {
		// aux/1n/mn panel
		if (dbswznm->tblwznmmrelation->loadRecByRef(pnl->refUref, &rel)) {
			refs.push_back(rel->toRefWznmMTable);

			// mn: find opposite side of mn relation
			if (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::FROM1N) {
				if (dbswznm->loadRefBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->supRefWznmMRelation)
							+ " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N), ref)) refs.push_back(ref);

			} else if (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::TO1N) {
				if (dbswznm->loadRefBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(rel->supRefWznmMRelation)
							+ " AND supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N), ref)) refs.push_back(ref);
			};

			delete rel;
		};

	} else if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) && (pnl->refIxVTbl == VecWznmVMPanelRefTbl::VEC)) {
		// klst panel
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "AVKeylistKey'", ref)) refs.push_back(ref);
	};

	dbswznm->tblwznmmtable->loadRstByRefs(refs, false, tbls);

	if (jump) {
		ix1 = tbls.nodes.size();

		for (unsigned int i = 0; i < ix1; i++) {
			tbl = tbls.nodes[i];

			dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMRelation WHERE TblWznmMRelation.frRefWznmMTable = "
						+ to_string(tbl->ref) + " AND TblWznmMTable.ref = TblWznmMRelation.toRefWznmMTable AND TblWznmMRelation.ixVBasetype = "
						+ to_string(VecWznmVMRelationBasetype::J), true, tbls);
		};
	};
};

void Wznm::collectPsts(
			Expr::Node* node
			, set<string>& psts
		) {
	// includes void
	if (node->ixVNodetype == Expr::VecVNodetype::FCT) if ((node->key.find("pre.") == 0) && (node->key.length() > 4)) psts.insert(node->key.substr(4));

	for (unsigned int i = 0; i < node->subs.size(); i++) collectPsts(node->subs[i], psts);
};

void Wznm::collectChks(
			set<string>& tblshorts
			, set<string>& skiptblshorts
			, Expr::Node* node
			, set<string>& chks
		) {
	// recursive, used in WznmGenChk

	size_t ptr, ptr2;

	if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		ptr = node->key.find('.');
		ptr2 = node->key.rfind('.');
		
		if (ptr != string::npos)
			if (tblshorts.find(node->key.substr(0, ptr)) != tblshorts.end())
				if (skiptblshorts.find(node->key.substr(0, ptr)) == skiptblshorts.end())
					if ( ((node->key.rfind("Eq")+2) == node->key.length()) || ((node->key.rfind("Incl")+4) == node->key.length()) || (node->key.substr(ptr+1) == "isLeaf") || (node->key.substr(ptr2+1) == "inSbs") )
						chks.insert(node->key);
	};

	for (unsigned int i = 0; i < node->subs.size(); i++) collectChks(tblshorts, skiptblshorts, node->subs[i], chks);
};

uint Wznm::getPnlreltype(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
		) {
	// returns _1N, MN or AUX if a relation is found
	uint retval = 0;

	WznmMRelation* rel = NULL;
	WznmMRelation* rel2 = NULL;

	if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) && (pnl->refIxVTbl == VecWznmVMPanelRefTbl::REL) ) {
		if (dbswznm->tblwznmmrelation->loadRecByRef(pnl->refUref, &rel)) {
			retval = rel->ixVBasetype;

			if ( (rel->ixVBasetype == VecWznmVMRelationBasetype::H1N) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::L1N)
						|| (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NSUB) || (rel->ixVBasetype == VecWznmVMRelationBasetype::LU1NLSUB) ) {

				retval = VecWznmVMRelationBasetype::_1N;

			} else if ( (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::FROM1N) || (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::TO1N) ) {
				retval = VecWznmVMRelationBasetype::MN;
				
			} else if (rel->supIxVSubrole == VecWznmVMRelationSupSubrole::SPEC) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(rel->supRefWznmMRelation, &rel2)) {
					if (rel2->ixVBasetype == VecWznmVMRelationBasetype::AUX) retval = VecWznmVMRelationBasetype::AUX;
					delete rel2;
				};
			};

			delete rel;
		};
	};

	return(retval);
};

bool Wznm::getPnllhs(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
		) {
	bool retval = false;

	uint ixReltype;

	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) {
		retval = true;
	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		if (pnl->refIxVTbl == VecWznmVMPanelRefTbl::VEC) {
			retval = true;
		} else if (pnl->refIxVTbl == VecWznmVMPanelRefTbl::REL) {
			ixReltype = getPnlreltype(dbswznm, pnl);
			retval = ((ixReltype != VecWznmVMRelationBasetype::_1N) && (ixReltype != VecWznmVMRelationBasetype::MN));
		};
	};

	return(retval);
};

bool Wznm::getPnlrhs(
			DbsWznm* dbswznm
			, WznmMPanel* pnl
		) {
	bool retval = false;

	uint ixReltype;

	if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) && (pnl->refIxVTbl == VecWznmVMPanelRefTbl::REL) ) {
		ixReltype = getPnlreltype(dbswznm, pnl);
		retval = ((ixReltype == VecWznmVMRelationBasetype::_1N) || (ixReltype == VecWznmVMRelationBasetype::MN));
	};

	return(retval);
};

string Wznm::getConsref(
			WznmMControl* con
			, const string& ditshort
		) {
	if (ditshort.length() == 3) return con->sref.substr(3);
	else return con->sref;
};

string Wznm::getConstatblk(
			WznmMControl* con
		) {
	string retval = "StatShr";

	if (con->ixVScope == VecWznmVMControlScope::APP) {
		switch (con->ixVBasetype) {
			case VecWznmVMControlBasetype::BUT:
			case VecWznmVMControlBasetype::CHK:
			case VecWznmVMControlBasetype::LST:
			case VecWznmVMControlBasetype::PUP:
			case VecWznmVMControlBasetype::RBU:
			case VecWznmVMControlBasetype::SLD:
			case VecWznmVMControlBasetype::TXF:
			case VecWznmVMControlBasetype::TXT:
			case VecWznmVMControlBasetype::UPD:
				retval = "StatApp";
				break;

			default:
				break;
		};
	};

	return retval;
};

unsigned int Wznm::getConheight(
			DbsWznm* dbswznm
			, WznmMControl* con // base controls only
		) {
	unsigned int retval = 0;

	string s;

	if (con->ixVBasetype == VecWznmVMControlBasetype::CUS) {
		retval = 100;
		if (dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "height", 0, s)) retval = atoi(s.c_str());
	} else if (con->ixVBasetype == VecWznmVMControlBasetype::LST) {
		retval = 96;
	} else if (con->ixVBasetype == VecWznmVMControlBasetype::SEP) {
		retval = 7;
	} else if (con->ixVBasetype == VecWznmVMControlBasetype::SPC) {
		retval = 10;
		if (dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "height", 0, s)) retval = atoi(s.c_str());
	} else if ((con->ixVBasetype == VecWznmVMControlBasetype::TXF) || (con->ixVBasetype == VecWznmVMControlBasetype::TXT)) {
		if (StrMod::srefInSrefs(con->srefsKOption, "t")) retval = 75;
		else retval = 25;
	} else {
		// BUT, CHK, CPT, DLD, PUP, RBU, SLD, ULD, UPD
		retval = 25;
	};

	return retval;
};

void Wznm::loadDitcons(
			DbsWznm* dbswznm
			, const ubigint refDit
			, ListWznmMControl& cons
		) {
	// complement to loadHrstdown which restores order in hkNum
	WznmMControl* con = NULL;
	WznmMControl* con2 = NULL;

	uint hkNumMin;
	unsigned int ixHkNumMin;

	dbswznm->tblwznmmcontrol->loadHrstdown(refDit, false, cons);

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		hkNumMin = con->hkNum;
		ixHkNumMin = i;

		for (unsigned int j=i+1;j<cons.nodes.size(); j++) {
			con2 = cons.nodes[j];

			if (con2->hkNum < hkNumMin) {
				hkNumMin = con2->hkNum;
				ixHkNumMin = j;
			};
		};

		if (ixHkNumMin != i) {
			con2 = cons.nodes[ixHkNumMin];
			cons.nodes[ixHkNumMin] = con;
			cons.nodes[i] = con2;
		};
	};
};

void Wznm::getBasecons(
			DbsWznm* dbswznm
			, ListWznmMControl& cons
			, const set<uint>& hkIcsVSection
			, const ubigint refDit
			, vector<unsigned int>& icsBasecons
		) {
	WznmMControl* con = NULL;

	ubigint refCBut, refBut;
	
	ubigint refVbar;

	bool found;

	icsBasecons.clear();

	refCBut = 0;
	refBut = 0;

	refVbar = 0; refVbar--;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		found = false;

		if (refCBut != 0) {
			// reset button cluster for refC mismatch ; exception: caption to first button
			if (con->refWznmCControl != refCBut) {
				if (!((con->supRefWznmMControl == refBut) && (con->ixVBasetype == VecWznmVMControlBasetype::CPT))) {
					refCBut = 0;
					refBut = 0;
				};
			};
		};

		if (hkIcsVSection.find(con->hkIxVSection) != hkIcsVSection.end()) {
			if ( (con->supRefWznmMControl == refDit) || (con->supRefWznmMControl == refVbar) ) {
				// dit (hk is dialog w/ dit's) as super control, pup (vbar) as super control, or no super control

				if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->refWznmCControl != 0)) {
					// special case of button cluster (BUT_CLUST): no hierarchy but first button in cluster is the complex's base control
					if (refCBut == 0) {
						found = true;

						refCBut = con->refWznmCControl;
						refBut = con->ref;
					};

				} else if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->supRefWznmMControl == refVbar) && ((refVbar+1) != 0)) {
					// avoid making ButEdit of pup (vbar) a base control

				} else {
					found = true;
				};
			};
		};

		if (found) {
			icsBasecons.push_back(i);

			if (con->supRefWznmMControl != refVbar) {
				// previous refVbar ends here
				refVbar = 0; refVbar--;

				// check for beginning of new refVbar
				if ((con->ixVBasetype == VecWznmVMControlBasetype::PUP) && (con->refWznmCControl != 0)) refVbar = con->ref;
			};
		};
	};
};

void Wznm::analyzeBasecon(
			DbsWznm* dbswznm
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const unsigned int ixIcsBasecons
			, const string& ditshort
			, unsigned int& cplxtype
			, string& baseconsref
			, string& baseconshort
			, bool& ldyn
			, bool& dyn
			, bool& rdyn
			, bool& vbar
			, unsigned int& ix0
			, unsigned int& ix1
			, unsigned int& ixBut
			, unsigned int& ixButCollapse
			, unsigned int& ixButEdit
			, unsigned int& ixButExpand
			, unsigned int& ixButToggle
			, unsigned int& ixButView
			, vector<unsigned int>& icsButs
			, unsigned int& ixChk
			, unsigned int& ixCpt
			, unsigned int& ixHdg
			, unsigned int& ixLsb
			, unsigned int& ixPup
			, unsigned int& ixTxf
			, unsigned int& ixTxt
			, vector<unsigned int>& icsVbarcons
		) {
	WznmMControl* basecon = NULL;
	WznmMControl* con = NULL;

	size_t ptr;

	ix0 = icsBasecons[ixIcsBasecons];

	if ((ixIcsBasecons+1) == icsBasecons.size()) {
		for (ix1=ix0;ix1<cons.nodes.size();ix1++) if (cons.nodes[ix0]->hkIxVSection != cons.nodes[ix1]->hkIxVSection) break;
		ix1--;
	} else {
		ix1 = icsBasecons[ixIcsBasecons+1]-1;
	};

	basecon = cons.nodes[ix0];

	cplxtype = Concplxtype::INVALID;

	baseconsref = getConsref(basecon, ditshort);
	
	ptr = baseconsref.find(StrMod::cap(VecWznmVMControlBasetype::getSref(basecon->ixVBasetype)));
	if (ptr != string::npos) baseconshort = baseconsref.substr(0, ptr) + baseconsref.substr(ptr+3);
	else baseconshort = "";

	ldyn = false;
	dyn = false;
	rdyn = false;

	vbar = false;
	if (basecon->supRefWznmMControl != 0) {
		for (unsigned int i = 0; i < ixIcsBasecons; i++) {
			con = cons.nodes[icsBasecons[i]];

			if ((con->ref == basecon->supRefWznmMControl) && (con->ixVBasetype == VecWznmVMControlBasetype::PUP)) {
				vbar = true;
				break;
			};
		};
	};

	ixBut = 0; ixBut--;
	ixButCollapse = 0; ixButCollapse--;
	ixButEdit = 0; ixButEdit--;
	ixButExpand = 0; ixButExpand--;
	ixButToggle = 0; ixButToggle--;
	ixButView = 0; ixButView--;
	icsButs.clear();
	ixChk = 0; ixChk--;
	ixCpt = 0; ixCpt--;
	ixHdg = 0; ixHdg--;
	ixLsb = 0; ixLsb--;
	ixPup = 0; ixPup--;
	ixTxf = 0; ixTxf--;
	ixTxt = 0; ixTxt--;
	icsVbarcons.clear();

	// -- categorize control complex
	if (basecon->ixVBasetype == VecWznmVMControlBasetype::BUT) {
		baseconshort = "";

		for (unsigned int i=ix0;i<=ix1; i++) {
			con = cons.nodes[i];

			if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->refWznmCControl == basecon->refWznmCControl)) {
				icsButs.push_back(i);
				if (con->Avail.length() > 0) dyn = true;

				baseconshort += getConsref(con, ditshort).substr(3);

			} else if ((con->ixVBasetype == VecWznmVMControlBasetype::CPT) && (con->supRefWznmMControl == basecon->ref)) ixCpt = i;
			else break;
		};

		if (icsButs.size() > 0) {
			cplxtype = Concplxtype::BUT_CLUST;

			// short is concatenation of button shorts ; overwritten with cpt's short if found
			if ((ixCpt+1) != 0) baseconshort = getConsref(cons.nodes[ixCpt], ditshort).substr(3);
			else baseconshort = StrMod::cap(StrMod::lc(baseconshort));
		};

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::CHK) {
		con = cons.nodes[ix1];
		if ((con->ixVBasetype == VecWznmVMControlBasetype::CPT) && (con->supRefWznmMControl == basecon->ref)) ixCpt = ix1;

		if ((ixCpt+1) != 0) cplxtype = Concplxtype::CHK;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::CUS) {
		cplxtype = Concplxtype::CUS;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::DLD) {
		cplxtype = Concplxtype::DLD;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::HDG) {
		cplxtype = Concplxtype::HDG;
		ixHdg = icsBasecons[ixIcsBasecons];

		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->supRefWznmMControl == basecon->ref)) {
				icsButs.push_back(i);
				if (con->Avail.length() > 0) dyn = true;
			} else break;
		};

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::LST) {
		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::LSB) ixLsb = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) ixTxf = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::TXT) ixTxt = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if (con->sref.rfind("Edit") == (con->sref.length()-4)) ixButEdit = i;
					if (con->sref.rfind("View") == (con->sref.length()-4)) ixButView = i;
					icsButs.push_back(i);
					if (con->Avail.length() > 0) rdyn = true;
				};

			} else {
				if ((ixCpt+1) != 0) {
					if (con->supRefWznmMControl == cons.nodes[ixCpt]->ref) {
						if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) ixChk = i;
						else if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
							if (con->sref.rfind("Expand") == (con->sref.length()-6)) ixButExpand = i;
							else if (con->sref.rfind("Collapse") == (con->sref.length()-8)) ixButCollapse = i;
						};
					};
				};
			};
		};

		if ( ((ixLsb+1) != 0) && ((ixCpt+1) != 0) ) {
			if ( ((ixButExpand+1) != 0) && ((ixButCollapse+1) != 0) ) {
				ldyn = true;
				dyn = true;
				if ((ixButView+1) != 0) rdyn = true;

				if ((ixTxf+1) != 0) cplxtype = Concplxtype::LST_TXFALT;
				else if ((ixTxt+1) != 0) cplxtype = Concplxtype::LST_TXTALT;
				else {
					cplxtype = Concplxtype::LST_NOALT;
					if (icsButs.size() > 0) rdyn = true;
				};

			} else cplxtype = Concplxtype::LST;
		};

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::PUP) {
		//ixPup = icsBasecons[ixIcsBasecons];

		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::PUP) ixPup = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) ixTxf = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if (con->sref.rfind("Edit") == (con->sref.length()-4)) ixButEdit = i;
					icsButs.push_back(i);
					if (con->Avail.length() > 0) rdyn = true;
				};

			} else {
				if ((ixCpt+1) != 0) {
					if (con->supRefWznmMControl == cons.nodes[ixCpt]->ref) {
						if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) ixChk = i;
						else if ( (con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->sref.rfind("Toggle") == (con->sref.length()-6)) ) ixButToggle = i;
					};
				};
			};
		};

		if ( ((ixCpt+1) == 0) && ((ixButEdit+1) != 0) ) {
			cplxtype = Concplxtype::PUP_VBAR;
			vbar = true;
			for (unsigned int i = 0; i < icsBasecons.size(); i++) if (cons.nodes[icsBasecons[i]]->supRefWznmMControl == basecon->ref) icsVbarcons.push_back(icsBasecons[i]);

		} else if ((ixCpt+1) != 0) {
			if ((ixPup+1) != 0) cplxtype = Concplxtype::PUP_PUP;
			else if ( ((ixTxf+1) != 0) && ((ixButToggle+1) != 0) ) {
				cplxtype = Concplxtype::PUP_TXFALT;
				dyn = true;
			} else cplxtype = Concplxtype::PUP;
		};

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::RBU) {
		con = cons.nodes[ix1];
		if ((con->ixVBasetype == VecWznmVMControlBasetype::CPT) && (con->supRefWznmMControl == basecon->ref)) ixCpt = ix1;

		if ((ixCpt+1) != 0) cplxtype = Concplxtype::RBU;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::SEP) {
		cplxtype = Concplxtype::SEP;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::SLD) {
		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;

			} else {
				if ((ixCpt+1) != 0) {
					if (con->supRefWznmMControl == cons.nodes[ixCpt]->ref) {
						if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) ixChk = i;
					};
				};
			};
		};

		if ((ixCpt+1) != 0) cplxtype = Concplxtype::SLD;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::SPC) {
		cplxtype = Concplxtype::SPC;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::TXF) {
		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					icsButs.push_back(i);
					if (con->Avail.length() > 0) rdyn = true;
				};

			} else {
				if ((ixCpt+1) != 0) {
					if (con->supRefWznmMControl == cons.nodes[ixCpt]->ref) {
						if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) ixChk = i;
					};
				};
			};
		};

		if ((ixCpt+1) != 0) cplxtype = Concplxtype::TXF;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::TXT) {
		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::PUP) ixPup = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) ixTxf = i;
				else if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if (con->sref.rfind("View") == (con->sref.length()-4)) ixButView = i;
					icsButs.push_back(i);
					if (con->Avail.length() > 0) rdyn = true;
				};

			} else {
				if ((ixCpt+1) != 0) {
					if (con->supRefWznmMControl == cons.nodes[ixCpt]->ref) {
						if ( (con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->sref.rfind("Toggle") == (con->sref.length()-6)) ) ixButToggle = i;
					};
				};
			};
		};
		
		if ((ixCpt+1) != 0) {
			if ((ixPup+1) != 0) cplxtype = Concplxtype::TXT_PUP;
			else if ( ((ixTxf+1) != 0) && ((ixButToggle+1) != 0) ) {
				cplxtype = Concplxtype::TXT_TXFALT;
				dyn = true;
				if ((ixButView+1) != 0) rdyn = true;

			} else cplxtype = Concplxtype::TXT;
		};

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::ULD) {
		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;
			};
		};

		if ((ixCpt+1) != 0) cplxtype = Concplxtype::ULD;

	} else if (basecon->ixVBasetype == VecWznmVMControlBasetype::UPD) {
		for (unsigned int i=ix0+1;i<=ix1; i++) {
			con = cons.nodes[i];

			if (con->supRefWznmMControl == basecon->ref) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) ixCpt = i;

			} else {
				if ((ixCpt+1) != 0) {
					if (con->supRefWznmMControl == cons.nodes[ixCpt]->ref) {
						if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) ixChk = i;
					};
				};
			};
		};

		if ((ixCpt+1) != 0) cplxtype = Concplxtype::UPD;
	};
};

void Wznm::showBasecons(
			DbsWznm* dbswznm
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const string& ditshort
		) {
	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;
	WznmMControl* con = NULL;

	for (unsigned int i = 0; i < icsBasecons.size(); i++) {
		basecon = cons.nodes[icsBasecons[i]];

		Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
					icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
		
		cout << "\t+ " << i << " " << basecon->sref << " (" << Concplxtype::getSref(cplxtype) << "): baseconsref = '" << baseconsref << "', baseconshort = '" << baseconshort << "'";
		if (ldyn) cout << ", ldyn";
		if (dyn) cout << ", dyn";
		if (rdyn) cout << ", rdyn";
		if (vbar) cout << ", vbar";
		cout << endl;

		if (icsVbarcons.size() > 0) {
			cout << "\t\t\t\tvbar group content: ";
			for (unsigned int j = 0; j < icsVbarcons.size(); j++) {
				if (j != 0) cout << ", ";
				cout << icsVbarcons[j];
			};
			cout << endl;
		};

		for (unsigned int j=ix0;j<=ix1; j++) {
			con = cons.nodes[j];
			
			cout << "\t\t";
			for (unsigned int k = 0; k < con->supLvl;k++) cout << "\t";
			cout << "- " << j << " " << con->sref << " (" << VecWznmVMControlBasetype::getSref(con->ixVBasetype) << ")";
			if (j == ixBut) cout << ", ixBut";
			if (j == ixButCollapse) cout << ", ixButCollapse";
			if (j == ixButEdit) cout << ", ixButEdit";
			if (j == ixButExpand) cout << ", ixButExpand";
			if (j == ixButToggle) cout << ", ixButToggle";
			if (j == ixButView) cout << ", ixButView";
			for (unsigned int k = 0; k < icsButs.size(); k++) {
				if (icsButs[k] == j) {
					cout << ", in icsButs";
					break;
				};
			};
			if (j == ixChk) cout << ", ixChk";
			if (j == ixCpt) cout << ", ixCpt";
			if (j == ixLsb) cout << ", ixLsb";
			if (j == ixPup) cout << ", ixPup";
			if (j == ixTxf) cout << ", ixTxf";
			if (j == ixTxt) cout << ", ixTxt";
			cout << endl;
		};
	};
};

void Wznm::getJobvars(
			DbsWznm* dbswznm
			, const ubigint refWznmMJob
			, ListWznmAMJobVar& vars
			, vector<string>& varsrefs
			, vector<bool>& Shrs
			, vector<unsigned int>& Ns
		) {
	ubigint refC;

	WznmAMJobVar* var = NULL;

	string s;
	bool Shr;
	unsigned int N;

	bool first;

	dbswznm->tblwznmamjobvar->loadRstByJob(refWznmMJob, false, vars);

	varsrefs.clear();
	Shrs.clear();
	Ns.clear();

	refC = 0;
	first = true;

	for (unsigned int i = 0; i < vars.nodes.size(); i++) {
		var = vars.nodes[i];

		if ((s != "") && (var->refWznmCAMJobVar != refC)) {
			varsrefs.push_back(s);
			Shrs.push_back(Shr);
			Ns.push_back(N);

			s = "";
			Shr = false;
			N = 0;

			first = true;
		};

		if (var->refWznmCAMJobVar == 0) {
			varsrefs.push_back(var->sref);
			Shrs.push_back(var->Shr);
			Ns.push_back(1);

		} else {
			if (first) {
				s = var->sref;
				Shr = var->Shr;
				N = 1;

				first = false;

			} else {
				s += StrMod::cap(var->sref);
				N++;
			};
		};

		refC = var->refWznmCAMJobVar;
	};

	if (s != "") {
		varsrefs.push_back(s);
		Shrs.push_back(Shr);
		Ns.push_back(N);
	};
};

void Wznm::getJobevals(
			DbsWznm* dbswznm
			, WznmMJob* job
			, vector<string>& bitsEval
			, vector<string>& rulesEval
			, vector<string>& exprsEval
		) {
	ubigint ref;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	string subsref;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMPanel* pnl = NULL;
	WznmMControl* con = NULL;

	ListWznmMControl subcons;
	WznmMControl* subcon = NULL;

	string s;

	bitsEval.resize(0);
	rulesEval.resize(0);
	exprsEval.resize(0);

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STAT) + " AND sref LIKE 'StatShr%'", false, blks);

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = StrMod::lc(getSubsref(job, blk->sref));

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->refWznmMControl == 0) {
				if ( (bit->sref.find("pnl") == 0) && ((bit->sref.rfind("Avail")+5) == bit->sref.length()) ) {
					// panel availability either for card job or pnlrec job
					pnl = NULL;

					if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) {
						dbswznm->tblwznmmpanel->loadRecBySQL("SELECT * FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(job->refUref)
									+ " AND LOWER(sref) LIKE 'pnl%" + StrMod::lc(bit->sref.substr(3, bit->sref.length()-3-5)) + "'", &pnl);

					} else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
						if (dbswznm->loadRefBySQL("SELECT carRefWznmMCard FROM TblWznmMPanel WHERE ref = " + to_string(job->refUref), ref)) {
							dbswznm->tblwznmmpanel->loadRecBySQL("SELECT * FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(ref)
										+ " AND LOWER(sref) LIKE 'pnl%" + StrMod::lc(bit->sref.substr(3, bit->sref.length()-3-5)) + "'", &pnl);
						};
					};

					if (pnl) {
						bitsEval.push_back(subsref + "." + bit->sref);
						rulesEval.push_back(bit->sref);
						exprsEval.push_back(pnl->Avail);

						delete pnl;
					};
				};

			} else {
				if ( ((bit->sref.rfind("Avail")+5) == bit->sref.length()) || ((bit->sref.rfind("Active")+6) == bit->sref.length()) ) {
					if (dbswznm->tblwznmmcontrol->loadRecByRef(bit->refWznmMControl, &con)) {
						bitsEval.push_back(subsref + "." + bit->sref);

						if ((bit->sref.rfind("Avail")+5) == bit->sref.length()) {
							rulesEval.push_back(con->sref + "Avail");
							exprsEval.push_back(con->Avail);

						} else {
							// ex. w/ ditshort: statshrimp.ButRunActive -> ImpButRunActive
							rulesEval.push_back(con->sref + "Active");
							exprsEval.push_back(con->Active);
						};

						// special case of menu availability (in pnlheadbar) which may depend on mit availability (in crd)
						if (con->ixVBasetype == VecWznmVMControlBasetype::MEN) {
							dbswznm->tblwznmmcontrol->loadRstBySup(con->ref, false, subcons);

							for (unsigned int k = 0; k < subcons.nodes.size(); k++) {
								subcon = subcons.nodes[k];

								if (subcon->Avail.length() > 0) {
									bitsEval.push_back("");
									rulesEval.push_back(subcon->sref + "Avail");
									exprsEval.push_back(subcon->Avail);
								};
							};
						};

						delete con;
					};
				};
			};
		};
	};
};

string Wznm::getSubsref(
			WznmMJob* job
			, const string& sref
		) {
	string retval = sref;

	size_t ptr;

	// determination of subsref by example:
	// crd: Dpch<PlnrDtp>Rdata: DpchRdata ; VecV<PlnrDtp>Sge: VecVSge
	// pnl: Dpch<PlnrDtpRec>Rdata: DpchRdata ; VecV<PlnrDtpList>Do: VecVDo
	// root, sess: Dpch<RootPlnr>Login: DpchLogin
	// qry/dlg/job: StatShrQryPlnrDtpList: StatShr ; VecV<DlgCamcConCalib>DoRec: VecVDoRec

	if ((job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) {
		ptr = sref.find(job->sref.substr(3));
		if (ptr != string::npos) retval = sref.substr(0, ptr) + sref.substr(ptr + job->sref.length()-3);

	} else {
		ptr = sref.find(job->sref);
		if (ptr != string::npos) retval = sref.substr(0, ptr) + sref.substr(ptr + job->sref.length());
	};

	return retval;
};

int Wznm::run(
			const string& cmd
		) {
	int retval = 0;

	pid_t pid;
	int stat;

	//retval = system(cmd.c_str());

	pid = fork();

	if (pid == -1) {
		// no child process
		cout << "error" << endl;

	} else if (pid == 0) {
		// child process
		setsid();
		execl("/bin/bash", "bash", "-c", cmd.c_str(), (char*) NULL);
		_exit(0);

	} else {
		// parent process, wait for child process to terminate
		while (waitpid(pid, &stat, 0) == -1) if (errno != EINTR) break;
		if (WIFEXITED(stat)) retval = WEXITSTATUS(stat);
	};

	if (retval != 0) cout << "command '" << cmd << "' returned exit code " << retval << endl;

	return retval;
};

bool Wznm::tgz(
			const string& infolder
			, const string& tgzfile
			, const bool verbose
		) {
	string cmd;

	cmd = "tar -pcz";
	if (verbose) cmd += "v";
	cmd += "f " + tgzfile + " -C " + infolder + " .";

	return(run(cmd) == 0);
};

bool Wznm::untgz(
			const string& tgzfile
			, const string& outfolder
			, const bool verbose
		) {
	bool retval;

	string cmd;

	bool newdir = false;

	if (access(outfolder.c_str(), R_OK | W_OK) == -1) {
#ifdef _WIN32
		mkdir(outfolder.c_str());
#else
		mkdir(outfolder.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
		newdir = true;
	};

	cmd = "tar -pxz";
	if (verbose) cmd += "v";
	cmd += "f " + tgzfile + " -C " + outfolder;

	retval = (run(cmd) == 0);

	if (!retval && newdir) rmdir(outfolder.c_str());

	return retval;
};

string Wznm::encrypt(
			const string& de
		) {
	// ex. in: 'X5JKZ7;1546772844' (license sref with expiry time)

	unsigned char* buf = NULL;
	const unsigned int buflen = 64;

	char* strbuf = NULL;
	unsigned int strbuflen;

	unsigned short a, b, c;
	unsigned char d;

	string magic = string("x@h-7Kw%G6Zz.AbX5 eth,YU0@gMnqk1");

	string en;

	// copy to buffer of length 64 ; last byte equals length inverted
	buf = new unsigned char[buflen];
	memset(buf, 0x00, buflen);

	for (unsigned int i = 0; i < buflen/2; i++) {
		if ((i+1) == (buflen/2)) {
			if (de.length() > 31) buf[2*i+1] = ~(31);
			else buf[2*i+1] = ~de.length();
		} else if (i < de.length()) buf[2*i+1] = de[i];
		else buf[2*i+1] = rand();
	};

	// multiply word-wise with magic word
	for (unsigned int i = 0; i < buflen/2; i++) {
		a = buf[2*i+1];
		b = magic[i];
		c = ((unsigned short) a) * ((unsigned short) b);
		
		buf[2*i] = c >> 8;
		buf[2*i+1] = c & 0x00FF;
	};

	// add cross-sum of all other bytes to each byte
	for (unsigned int i = 0; i < buflen; i++) {
		d = 0;
		for (unsigned int j = 0; j < buflen; j++) if (i != j) d += buf[j];
		buf[i] += d;
	};

	// convert to base64
	toBase64(buf, buflen, &strbuf, strbuflen);

	en = string(strbuf, strbuflen);
	
	delete[] buf;
	delete[] strbuf;

	return en;
};

string Wznm::decrypt(
			const string& en
		) {
	unsigned char* buf = NULL;
	unsigned int buflen;

	unsigned short a, b, c;
	unsigned char d;

	string magic = string("x@h-7Kw%G6Zz.AbX5 eth,YU0@gMnqk1");

	string de;

	// convert from base64
	fromBase64(en.c_str(), en.length(), &buf, buflen);
	if (buflen != 64) return de;

	// substract cross-sum of all other bytes from each byte
	for (unsigned int i=buflen;i>0;i--) {
		d = 0;
		for (unsigned int j = 0; j < buflen; j++) if ((i-1) != j) d += buf[j];
		buf[i-1] -= d;
	};

	// divide word-wise by magic word
	for (unsigned int i = 0; i < buflen/2; i++) {
		c = (buf[2*i] << 8) + buf[2*i+1];
		b = magic[i];
		a = c / b;

		buf[2*i] = a >> 8; // should be 0x00
		buf[2*i+1] = a & 0x00FF;
	};

	// crop to original length
	de = string(((unsigned char) ~(buf[buflen-1])), ' ');
	for (unsigned int i = 0; i < de.length(); i++) de[i] = buf[2*i+1];

	delete[] buf;

	return de;
};
// IP gbl --- IEND

/******************************************************************************
 namespace OpengWznm
 ******************************************************************************/

void OpengWznm::getIcsWznmVOppackByIxWznmVOpengtype(
			const uint ixWznmVOpengtype
			, vector<uint>& icsWznmVOppack
		) {
	icsWznmVOppack.clear();

	if (ixWznmVOpengtype == VecWznmVOpengtype::WZNMOPD1) {
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMCOMPL);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMGEN);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMPRCFILE);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMPRCTREE);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMWRAPI);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMWRAPP);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMWRDBS);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMWRJAPI);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMWRSRV);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMWRWEB);
	} else if (ixWznmVOpengtype == VecWznmVOpengtype::WZNMOPD2) {
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMCTPGENJTR);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMCTPGENUI);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMCTPWRSRV);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMCTPWRSTKIT);
		push_back(icsWznmVOppack, VecWznmVOppack::WZNMCTPWRWEB);
	};
};

void OpengWznm::getIcsWznmVDpchByIxWznmVOppack(
			const uint ixWznmVOppack
			, set<uint>& icsWznmVDpch
		) {
	if (ixWznmVOppack == VecWznmVOppack::WZNMCOMPL) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCOMPLBSCUI);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCOMPLDBS);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCOMPLDEPLOY);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCOMPLIEX);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCOMPLJTR);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMCTPGENJTR) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCTPGENJTR);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMCTPGENUI) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCTPGENUI);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMCTPWRSRV) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCTPWRSRV);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMCTPWRSTKIT) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCTPWRSTKIT);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMCTPWRWEB) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMCTPWRWEB);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMGEN) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENCAL);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENCHK);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENDETUI);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENJOB);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENQTB);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMGENSYSVEC);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMPRCFILE) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMPRCFILECONCAT);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMPRCFILEPLHRPL);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMPRCTREE) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMPRCTREEEXTRACT);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMPRCTREEMERGE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMPRCTREEVALIDATE);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMWRAPI) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRAPIBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRAPIDEPLOY);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRAPIJOB);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRAPIQTB);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMWRAPP) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRAPPBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRAPPJBASE);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMWRDBS) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRDBSDBS);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRDBSDEPLOY);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRDBSDIFFSQL);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRDBSSQL);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRDBSTBL);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMWRJAPI) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRJAPIBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRJAPIJOB);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRJAPIQTB);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRJAPIVEC);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMWRSRV) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVCMBENGBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVCRD);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVDDS);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVDEPLOY);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVDLG);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVENGBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVIEX);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVINIXML);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVJOB);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVOP);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVOPENGBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVOPK);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVPNL);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVPREF);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVQRY);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVROOTSESS);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVUA);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRSRVVEC);
	} else if (ixWznmVOppack == VecWznmVOppack::WZNMWRWEB) {
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRWEBBASE);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRWEBCRD);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRWEBDEPLOY);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRWEBDLG);
		insert(icsWznmVDpch, VecWznmVDpch::DPCHINVWZNMWRWEBPNL);
	};
};

/******************************************************************************
 namespace StubWznm
 ******************************************************************************/

string StubWznm::getStub(
			DbsWznm* dbswznm
			, const uint ixWznmVStub
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	if (ixWznmVStub == VecWznmVStub::STUBWZNMAPPSTD) return getStubAppStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMBLKSTD) return getStubBlkStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCALSTD) return getStubCalStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCAPSTD) return getStubCapStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCARSTD) return getStubCarStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCHKSTD) return getStubChkStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCMPSTD) return getStubCmpStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCONSREF) return getStubConSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCONSTD) return getStubConStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCPBSTD) return getStubCpbStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMCTPSTD) return getStubCtpStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMDLGSTD) return getStubDlgStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMEVTSTD) return getStubEvtStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMFEDSREF) return getStubFedSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMFEDSTD) return getStubFedStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMFILSTD) return getStubFilStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMGROUP) return getStubGroup(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMIELSTD) return getStubIelStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMIEXSTD) return getStubIexStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMIMESTD) return getStubImeStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMJOBSTD) return getStubJobStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMLIBSREF) return getStubLibSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMLIBSTD) return getStubLibStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMLOCSREF) return getStubLocSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMLOCSTD) return getStubLocStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMMCHSREF) return getStubMchSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMMCHSTD) return getStubMchStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMMDLSTD) return getStubMdlStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMMTDSTD) return getStubMtdStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMOPKSTD) return getStubOpkStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMOPXSTD) return getStubOpxStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMOWNER) return getStubOwner(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMPNLSTD) return getStubPnlStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMPRJSHORT) return getStubPrjShort(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMPRJSTD) return getStubPrjStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMPRSSTD) return getStubPrsStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMPSTSTD) return getStubPstStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMQCOSTD) return getStubQcoStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMQMDSTD) return getStubQmdStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMQRYSTD) return getStubQryStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMRELSTD) return getStubRelStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMRLSSTD) return getStubRlsStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMRTBSTD) return getStubRtbStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMRTDSTD) return getStubRtdStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMRTJSTD) return getStubRtjStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSBSSTD) return getStubSbsStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSEQSTD) return getStubSeqStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSESMENU) return getStubSesMenu(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSESSTD) return getStubSesStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSGESTD) return getStubSgeStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSQKSTD) return getStubSqkStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSTBSTD) return getStubStbStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMSTESTD) return getStubSteStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMTAGSTD) return getStubTagStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMTBLSTD) return getStubTblStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMTCOSREF) return getStubTcoSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMTCOSTD) return getStubTcoStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMUSGSTD) return getStubUsgStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMUSRSTD) return getStubUsrStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMVECSTD) return getStubVecStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMVERNO) return getStubVerNo(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMVERSHORT) return getStubVerShort(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMVERSTD) return getStubVerStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMVITSREF) return getStubVitSref(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWznmVStub == VecWznmVStub::STUBWZNMVITSTD) return getStubVitStd(dbswznm, ref, ixWznmVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubWznm::getStubAppStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "WhizniumDBE Iterator (wdbe v0.1.1) variant 3"
	string stub;

	WznmMApp* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMAPPSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no accessor app)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmapp->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubAppStd --- IBEGIN
			stub = rec->Title + " (" + getStubVerShort(dbswznm, rec->verRefWznmMVersion, ixWznmVLocale, ixVNonetype, stcch, &stref) + ") variant " + to_string(rec->verNum);
			// IP getStubAppStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubBlkStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "DpchInvBrlyBaseLocloc"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMBLKSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no block)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmblock->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubCalStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "CallBrlyLoc.typEq"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCALSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no call)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcall->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubCapStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "acv (acv - managed file archive)"
	string stub;

	WznmMCapability* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCAPSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no capability)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcapability->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref + " (" + getStubCtpStd(dbswznm, rec->tplRefWznmMCapability, ixWznmVLocale, ixVNonetype, stcch, &stref) + ")"; // IP getStubCapStd --- ILINE
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubCarStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "CrdBrlyLoc"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCARSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no card)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcard->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubChkStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "isLeaf"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCHKSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no feature check)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcheck->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubCmpStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Brlycmbd"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCMPSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no component)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcomponent->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubConSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "CptReg"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCONSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no control)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcontrol->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubConStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PnlBrlyLocDetail.CptReg"
	string stub;

	WznmMControl* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCONSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no control)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcontrol->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubConStd --- IBEGIN
			if (rec->hkIxVTbl == VecWznmVMControlHkTbl::CAR) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecWznmVMControlHkTbl::PNL) {
				stub = getStubPnlStd(dbswznm, rec->hkUref, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			} else if (rec->hkIxVTbl == VecWznmVMControlHkTbl::DLG) {
				stub = getStubDlgStd(dbswznm, rec->hkUref, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
			// IP getStubConStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubCpbStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Acv (acv - managed file archive) - vs. - acv - managed file archive"
	string stub;

	WznmMCapability* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCPBSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no capability)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcapability->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCpbStd --- IBEGIN
			if (rec->refWznmMVersion != 0) {
				stub = rec->sref;
				if (rec->tplRefWznmMCapability != 0) stub += " (" + getStubCtpStd(dbswznm, rec->tplRefWznmMCapability, ixWznmVLocale, ixVNonetype, stcch, &stref) + ")";			
			} else {
				stub = getStubCtpStd(dbswznm, rec->ref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			};
			// IP getStubCpbStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubCtpStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "acv - managed file archive"
	string stub;

	WznmMCapability* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMCTPSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no capability template)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmcapability->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref + " - " + rec->Title; // IP getStubCtpStd --- ILINE
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubDlgStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "DlgBrlyLocNew"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMDLGSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no dialog)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmdialog->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubEvtStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ButConnectClick"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMEVTSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no event)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmevent->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubFedSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "FeedFPupTyp"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMFEDSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no feed)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmfeed->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubFedStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PnlBrlyLocDetail.FeedFPupTyp"
	string stub;

	WznmMFeed* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMFEDSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no feed)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmfeed->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubFedStd --- IBEGIN
			stub = getStubConStd(dbswznm, rec->refWznmMControl, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubFedStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubFilStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "VecXxxxVYyyyy.cpp"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMFILSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no file)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmfile->loadFnmByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubGroup(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "agroup"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMGROUP, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubIelStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ImeIBrlyLocMLocation.srefIxVBasetype"
	string stub;

	WznmMImpexpcol* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMIELSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no import/export column)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmimpexpcol->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubIelStd --- IBEGIN
			stub = getStubImeStd(dbswznm, rec->imeRefWznmMImpexp, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubIelStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubIexStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "IexBrlyLoc"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMIEXSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no import/export complex)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmimpexpcplx->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubImeStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ImeIBrlyLocMLocation"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMIMESTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no import/export)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmimpexp->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubJobStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "JobBrlyLocCalc"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMJOBSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no job)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmjob->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubLibSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "netcdf"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMLIBSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no library)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmlibrary->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubLibStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "netcdf 4.2.1.1"
	string stub;

	WznmMLibrary* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMLIBSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no library)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmlibrary->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubLibStd --- IBEGIN
			stub = rec->sref;
			if (rec->Version.length() > 0) stub += " " + rec->Version;
			// IP getStubLibStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubLocSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "enus"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMLOCSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no locale)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmlocale->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubLocStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "enus / English (United States)"
	string stub;

	WznmMLocale* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMLOCSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no locale)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmlocale->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubLocStd --- IBEGIN
			stub = rec->sref + " / " + rec->Title;
			// IP getStubLocStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubMchSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "jack"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMMCHSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no machine)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmmachine->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubMchStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "any;ubuntu;mpsitech;jack"
	string stub;

	WznmMMachine* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMMCHSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no machine)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmmachine->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefWznmMMachine != 0) stub = getStubMchStd(dbswznm, rec->supRefWznmMMachine, ixWznmVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubMdlStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "MdlBrlyAdmin"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMMDLSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no module)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmmodule->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubMtdStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "JobMsdcAcqLwir.start"
	string stub;

	WznmMMethod* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMMTDSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no method)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmmethod->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = getStubJobStd(dbswznm, rec->refWznmMJob, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref; // IP getStubMtdStd --- ILINE
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubOpkStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "BrlyBase"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMOPKSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no operation pack)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmoppack->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubOpxStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "BrlyBaseLocloc"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMOPXSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no operation)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmop->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubOwner(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "auser"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMOWNER, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubPnlStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PnlBrlyLocList"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMPNLSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no panel)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmpanel->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubPrjShort(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "brly"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMPRJSHORT, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no project)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmproject->loadShoByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubPrjStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "BeamRelay"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMPRJSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no project)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmproject->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubPrsStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	WznmMPerson* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMPRSSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no person)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWznmPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			// IP getStubWznmPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubPstStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PreBrlyIxUacUsg"
	string stub;

	WznmMPreset* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMPSTSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no presetting)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmpreset->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPstStd --- IBEGIN
			if (rec->refIxVTbl == VecWznmVMPresetRefTbl::VOID) {
				stub = rec->sref;
			} else if (rec->refIxVTbl == VecWznmVMPresetRefTbl::TBL) {
				stub = getStubTblStd(dbswznm, rec->refUref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			} else if (rec->refIxVTbl == VecWznmVMPresetRefTbl::SBS) {
				stub = getStubSbsStd(dbswznm, rec->refUref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			} else if (rec->refIxVTbl == VecWznmVMPresetRefTbl::VEC) {
				stub = getStubVecStd(dbswznm, rec->refUref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			};
			// IP getStubPstStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubQcoStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "QryBrlyLocList.titIxVBasetype"
	string stub;

	WznmMQuerycol* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMQCOSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no query column)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmquerycol->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubQcoStd --- IBEGIN
			stub = getStubQryStd(dbswznm, rec->qryRefWznmMQuery, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubQcoStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubQmdStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "QryBrlyLocMNFlight by PreBrlyTime"
	string stub;

	WznmMQuerymod* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMQMDSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no query modifier)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmquerymod->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubQmdStd --- IBEGIN
			stub = getStubQryStd(dbswznm, rec->qryRefWznmMQuery, ixWznmVLocale, ixVNonetype, stcch, &stref) + " by " + getStubPstStd(dbswznm, rec->qryRefWznmMQuery, ixWznmVLocale, ixVNonetype, stcch, &stref);
			// IP getStubQmdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubQryStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "QryBrlyLocList"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMQRYSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no query)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmquery->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubRelStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "(_1n/void) TblBrlyMLocation-TblBrlyMLeg bgn"
	string stub;

	WznmMRelation* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMRELSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no relation)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmrelation->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubRelStd --- IBEGIN
			stub = "(" + VecWznmVMRelationBasetype::getSref(rec->ixVBasetype);
			if (rec->supRefWznmMRelation != 0) stub += + "/" + VecWznmVMRelationSupSubrole::getSref(rec->supIxVSubrole);
			stub += ") ";

			if (rec->frRefWznmMTable == 0) stub += "<"; else stub += getStubTblStd(dbswznm, rec->frRefWznmMTable, ixWznmVLocale, ixVNonetype, stcch, &stref);
			stub += "-";
			if (rec->toRefWznmMTable == 0) stub += ">"; else stub += getStubTblStd(dbswznm, rec->toRefWznmMTable, ixWznmVLocale, ixVNonetype, stcch, &stref);

			if (rec->Prefix.length() > 0) stub += " " + rec->Prefix;
			// IP getStubRelStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubRlsStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Brlyd_jefe"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMRLSSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no release)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmrelease->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubRtbStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PnlRlsList_rst"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMRTBSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no run-time data block)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmrtblock->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubRtdStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "DpchEngDlgVerNew"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMRTDSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no run-time dispatch)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmrtdpch->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubRtjStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PnlVerList1"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMRTJSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no run-time job)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmrtjob->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubSbsStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "SbstBrlyBMLocationAp"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSBSSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no subset)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmsubset->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubSeqStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "select mission"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSEQSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no sequence)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmsequence->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubSesMenu(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "user fkuntz / Franz Kuntz;logged in from 127.0.0.1;since 01-01-2010 10:34"
	string stub;

	WznmMSession* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSESMENU, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWznmSesMenu --- BEGIN
			if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "user " + getStubUsrStd(dbswznm, rec->refWznmMUser, ixWznmVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			// IP getStubWznmSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubSesStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "01-01-2010 10:34 from 127.0.0.1"
	string stub;

	WznmMSession* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSESSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWznmSesStd --- BEGIN
			if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			// IP getStubWznmSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubSgeStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "JobBrlyLocCalc.run"
	string stub;

	WznmMStage* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSGESTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no stage)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmstage->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubSgeStd --- IBEGIN
			stub = getStubJobStd(dbswznm, rec->jobRefWznmMJob, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubSgeStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubSqkStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "BrlyBase -vs.- JobBrlyLocCalc.run"
	string stub;

	WznmMSquawk* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSQKSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no squawk)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmsquawk->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubSqkStd --- IBEGIN
			if (rec->refIxVTbl == VecWznmVMSquawkRefTbl::OPK) stub = getStubOpkStd(dbswznm, rec->refUref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			else if (rec->refIxVTbl == VecWznmVMSquawkRefTbl::OPX) stub = getStubOpxStd(dbswznm, rec->refUref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			else if (rec->refIxVTbl == VecWznmVMSquawkRefTbl::SGE) stub = getStubSgeStd(dbswznm, rec->refUref, ixWznmVLocale, ixVNonetype, stcch, &stref);
			// IP getStubSqkStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubStbStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "StubBrlyLocStd"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSTBSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no stub)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmstub->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubSteStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "selMis.DpchMisListData.select"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMSTESTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no state)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmstate->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubTagStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "editddd"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMTAGSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no tag)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmtag->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubTblStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "TblBrlyMLocation"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMTBLSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no table)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmtable->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubTcoSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "refBrlyMRegion"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMTCOSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no table column)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmtablecol->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubTcoStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "TblBrlyMLocation.refBrlyMRegion"
	string stub;

	WznmMTablecol* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMTCOSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no table column)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmtablecol->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubTcoStd --- IBEGIN
			stub = getStubTblStd(dbswznm, rec->tblRefWznmMTable, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubTcoStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubUsgStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "admin"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMUSGSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubUsrStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "fkuntz / Franz Kuntz"
	string stub;

	WznmMUser* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMUSRSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWznmUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbswznm, rec->refWznmMPerson, ixWznmVLocale, ixVNonetype, stcch, &stref);
			// IP getStubWznmUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubVecStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "VecBrlyVMLocationBasetype"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMVECSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no vector)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmvector->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubVerNo(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "0.1.1"
	string stub;

	WznmMVersion* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMVERNO, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no version)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubVerNo --- IBEGIN
			stub = to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub));
			// IP getStubVerNo --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubVerShort(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "brly v0.1.1 (77)"
	string stub;

	WznmMVersion* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMVERSHORT, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no version)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = getStubPrjShort(dbswznm, rec->prjRefWznmMProject, ixWznmVLocale, ixVNonetype, stcch, &stref) + " v" + to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub)) + " (" + to_string(rec->prjNum) + ")"; // IP getStubVerShort --- ILINE
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubVerStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "BeamRelay v0.1.1 (s/n 77, abandonned)"
	string stub;

	WznmMVersion* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMVERSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no version)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubVerStd --- IBEGIN

			stub = getStubPrjStd(dbswznm, rec->prjRefWznmMProject, ixWznmVLocale, ixVNonetype, stcch, &stref) + " v" + to_string(rec->Major) + "." + to_string(rec->Minor) + "." + to_string(rec->Sub);

			if (rec->ixVState != VecWznmVMVersionState::READY) {
				stub += " (s/n " + to_string(rec->prjNum);
				if ((rec->ixVState == VecWznmVMVersionState::NEWCRE) || (rec->ixVState == VecWznmVMVersionState::NEWIMP) || (rec->ixVState == VecWznmVMVersionState::ABANDON)) stub += ", " + VecWznmVMVersionState::getTitle(rec->ixVState, ixWznmVLocale);
				stub += ")"; 
			};
			// IP getStubVerStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWznm::getStubVitSref(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ap"
	string stub;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMVITSREF, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no vector item)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmvectoritem->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWznm::getStubVitStd(
			DbsWznm* dbswznm
			, const ubigint ref
			, const uint ixWznmVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "VecBrlyVMLocationBasetype.ap"
	string stub;

	WznmMVectoritem* rec = NULL;

	stcchitemref_t stref(VecWznmVStub::STUBWZNMVITSTD, ref, ixWznmVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) stub = "(no vector item)";
	};

	if (ref != 0) {
		if (dbswznm->tblwznmmvectoritem->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubVitStd --- IBEGIN
			stub = getStubVecStd(dbswznm, rec->vecRefWznmMVector, ixWznmVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubVitStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class WznmException
 ******************************************************************************/

WznmException::WznmException(
			const uint ix
			, const map<string,string>& vals
		) :
			SbeException(ix, vals)
		{
};

string WznmException::getSref() {
	string sref = SbeException::getSref();
	if (sref != "") return sref;
	
	if (ix == LIC_AUTH) return("lic.auth");
	if (ix == LIC_CTWARN) return("lic.ctwarn");
	if (ix == LIC_CTLOST) return("lic.ctlost");
	
	return("");
};

/******************************************************************************
 class ContInfWznmAlert
 ******************************************************************************/

ContInfWznmAlert::ContInfWznmAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) :
			Block()
		{
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;
	this->TxtMsg11 = TxtMsg11;
	this->TxtMsg12 = TxtMsg12;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfWznmAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

void ContInfWznmAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfWznmAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg11", TxtMsg11);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg12", TxtMsg12);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfWznmAlert::compare(
			const ContInfWznmAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchWznm
 ******************************************************************************/

DpchWznm::DpchWznm(
			const uint ixWznmVDpch
		) {
	this->ixWznmVDpch = ixWznmVDpch;
};

DpchWznm::~DpchWznm() {
};

/******************************************************************************
 class DpchInvWznm
 ******************************************************************************/

DpchInvWznm::DpchInvWznm(
			const uint ixWznmVDpch
			, const ubigint oref
			, const ubigint jref
		) :
			DpchWznm(ixWznmVDpch)
		{
	this->oref = oref;
	this->jref = jref;
};

DpchInvWznm::~DpchInvWznm() {
};

void DpchInvWznm::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznm");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvWznm::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWznm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWznm
 ******************************************************************************/

DpchRetWznm::DpchRetWznm(
			const uint ixWznmVDpch
			, const string& scrOref
			, const string& scrJref
			, const utinyint ixOpVOpres
			, const utinyint pdone
		) :
			DpchWznm(ixWznmVDpch)
		{
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->ixOpVOpres = ixOpVOpres;
	this->pdone = pdone;
};

DpchRetWznm::~DpchRetWznm() {
};

void DpchRetWznm::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWznm");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
	};
};

void DpchRetWznm::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWznm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
	xmlTextWriterEndElement(wr);
};
