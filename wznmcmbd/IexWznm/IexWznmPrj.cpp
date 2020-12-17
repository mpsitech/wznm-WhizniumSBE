/**
	* \file IexWznmPrj.cpp
	* data blocks and readers/writers for import/export complex IexWznmPrj (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWznmPrj.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmPrj::VecVIme
 ******************************************************************************/

uint IexWznmPrj::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeijmversion") return IMEIJMVERSION;
	if (s == "imeijmversionstate") return IMEIJMVERSIONSTATE;
	if (s == "imeimproject") return IMEIMPROJECT;
	if (s == "imeimversion") return IMEIMVERSION;
	if (s == "imeirmlocalemversion") return IMEIRMLOCALEMVERSION;
	if (s == "imeirmpersonmproject") return IMEIRMPERSONMPROJECT;

	return(0);
};

string IexWznmPrj::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIJMVERSION) return("ImeIJMVersion");
	if (ix == IMEIJMVERSIONSTATE) return("ImeIJMVersionState");
	if (ix == IMEIMPROJECT) return("ImeIMProject");
	if (ix == IMEIMVERSION) return("ImeIMVersion");
	if (ix == IMEIRMLOCALEMVERSION) return("ImeIRMLocaleMVersion");
	if (ix == IMEIRMPERSONMPROJECT) return("ImeIRMPersonMProject");

	return("");
};

/******************************************************************************
 class IexWznmPrj::ImeitemIJMVersion
 ******************************************************************************/

IexWznmPrj::ImeitemIJMVersion::ImeitemIJMVersion(
			const string& srefX1RefWznmMLocale
			, const string& About1
			, const string& About2
			, const string& About3
		) : WznmJMVersion() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->About1 = About1;
	this->About2 = About2;
	this->About3 = About3;
};

IexWznmPrj::ImeitemIJMVersion::ImeitemIJMVersion(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMVersion()
		{
	WznmJMVersion* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmversion->loadRecByRef(ref, &rec)) {
		refWznmMVersion = rec->refWznmMVersion;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		About1 = rec->About1;
		About2 = rec->About2;
		About3 = rec->About3;

		delete rec;
	};
};

void IexWznmPrj::ImeitemIJMVersion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMVersion::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {About1 = txtrd.fields[1]; ixWIelValid += ImeIJMVersion::VecWIel::ABOUT1;};
	if (txtrd.fields.size() > 2) {About2 = txtrd.fields[2]; ixWIelValid += ImeIJMVersion::VecWIel::ABOUT2;};
	if (txtrd.fields.size() > 3) {About3 = txtrd.fields[3]; ixWIelValid += ImeIJMVersion::VecWIel::ABOUT3;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVersion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmPrj::ImeitemIJMVersion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMVersion::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "About1", "ab1", About1)) ixWIelValid += ImeIJMVersion::VecWIel::ABOUT1;
		if (extractStringUclc(docctx, basexpath, "About2", "ab2", About2)) ixWIelValid += ImeIJMVersion::VecWIel::ABOUT2;
		if (extractStringUclc(docctx, basexpath, "About3", "ab3", About3)) ixWIelValid += ImeIJMVersion::VecWIel::ABOUT3;
	};
};

void IexWznmPrj::ImeitemIJMVersion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << About1 << "\t" << About2 << "\t" << About3 << endl;
};

void IexWznmPrj::ImeitemIJMVersion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","ab1","ab2","ab3"};
	else tags = {"ImeitemIJMVersion","srefX1RefWznmMLocale","About1","About2","About3"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], About1);
		writeString(wr, tags[3], About2);
		writeString(wr, tags[4], About3);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmPrj::ImeIJMVersion::VecWIel
 ******************************************************************************/

uint IexWznmPrj::ImeIJMVersion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "about1") ix |= ABOUT1;
		else if (ss[i] == "about2") ix |= ABOUT2;
		else if (ss[i] == "about3") ix |= ABOUT3;
	};

	return(ix);
};

void IexWznmPrj::ImeIJMVersion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*ABOUT3); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmPrj::ImeIJMVersion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMLOCALE) ss.push_back("srefX1RefWznmMLocale");
	if (ix & ABOUT1) ss.push_back("About1");
	if (ix & ABOUT2) ss.push_back("About2");
	if (ix & ABOUT3) ss.push_back("About3");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmPrj::ImeIJMVersion
 ******************************************************************************/

IexWznmPrj::ImeIJMVersion::ImeIJMVersion() {
};

IexWznmPrj::ImeIJMVersion::~ImeIJMVersion() {
	clear();
};

void IexWznmPrj::ImeIJMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmPrj::ImeIJMVersion::readTxt(
			Txtrd& txtrd
		) {
	IexWznmPrj::ImeitemIJMVersion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmPrj::ImeitemIJMVersion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMVERSION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmPrj::ImeIJMVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmPrj::ImeitemIJMVersion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMVersion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMVersion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMVersion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmPrj::ImeitemIJMVersion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmPrj::ImeIJMVersion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMVersion." << StrMod::replaceChar(ImeIJMVersion::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMVersion.end" << endl;
	};
};

void IexWznmPrj::ImeIJMVersion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMVersion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmPrj::ImeitemIJMVersionState
 ******************************************************************************/

IexWznmPrj::ImeitemIJMVersionState::ImeitemIJMVersionState(
			const uint ixVState
		) : WznmJMVersionState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWznmPrj::ImeitemIJMVersionState::ImeitemIJMVersionState(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMVersionState()
		{
	WznmJMVersionState* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmversionstate->loadRecByRef(ref, &rec)) {
		refWznmMVersion = rec->refWznmMVersion;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWznmPrj::ImeitemIJMVersionState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMVersionState::VecWIel::SREFIXVSTATE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmPrj::ImeitemIJMVersionState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMVersionState::VecWIel::SREFIXVSTATE;
	};
};

void IexWznmPrj::ImeitemIJMVersionState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVMVersionState::getSref(ixVState) << endl;
};

void IexWznmPrj::ImeitemIJMVersionState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMVersionState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMVersionState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmPrj::ImeIJMVersionState::VecWIel
 ******************************************************************************/

uint IexWznmPrj::ImeIJMVersionState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexWznmPrj::ImeIJMVersionState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmPrj::ImeIJMVersionState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmPrj::ImeIJMVersionState
 ******************************************************************************/

IexWznmPrj::ImeIJMVersionState::ImeIJMVersionState() {
};

IexWznmPrj::ImeIJMVersionState::~ImeIJMVersionState() {
	clear();
};

void IexWznmPrj::ImeIJMVersionState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmPrj::ImeIJMVersionState::readTxt(
			Txtrd& txtrd
		) {
	IexWznmPrj::ImeitemIJMVersionState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmPrj::ImeitemIJMVersionState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMVERSIONSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmPrj::ImeIJMVersionState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmPrj::ImeitemIJMVersionState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMVersionState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMVersionState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMVersionState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmPrj::ImeitemIJMVersionState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmPrj::ImeIJMVersionState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMVersionState." << StrMod::replaceChar(ImeIJMVersionState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMVersionState.end" << endl;
	};
};

void IexWznmPrj::ImeIJMVersionState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMVersionState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmPrj::ImeitemIRMLocaleMVersion
 ******************************************************************************/

IexWznmPrj::ImeitemIRMLocaleMVersion::ImeitemIRMLocaleMVersion(
			const string& srefRefWznmMLocale
		) : WznmRMLocaleMVersion() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMLocale = srefRefWznmMLocale;
};

IexWznmPrj::ImeitemIRMLocaleMVersion::ImeitemIRMLocaleMVersion(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMLocaleMVersion()
		{
	WznmRMLocaleMVersion* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmlocalemversion->loadRecByRef(ref, &rec)) {
		refWznmMLocale = rec->refWznmMLocale;
		refWznmMVersion = rec->refWznmMVersion;

		delete rec;
	};
};

void IexWznmPrj::ImeitemIRMLocaleMVersion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIRMLocaleMVersion::VecWIel::SREFREFWZNMMLOCALE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMLocaleMVersion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmPrj::ImeitemIRMLocaleMVersion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMLocale", "loc", srefRefWznmMLocale)) ixWIelValid += ImeIRMLocaleMVersion::VecWIel::SREFREFWZNMMLOCALE;
	};
};

void IexWznmPrj::ImeitemIRMLocaleMVersion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefRefWznmMLocale << endl;
};

void IexWznmPrj::ImeitemIRMLocaleMVersion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc"};
	else tags = {"ImeitemIRMLocaleMVersion","srefRefWznmMLocale"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMLocale);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmPrj::ImeIRMLocaleMVersion::VecWIel
 ******************************************************************************/

uint IexWznmPrj::ImeIRMLocaleMVersion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmlocale") ix |= SREFREFWZNMMLOCALE;
	};

	return(ix);
};

void IexWznmPrj::ImeIRMLocaleMVersion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMLOCALE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmPrj::ImeIRMLocaleMVersion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMLOCALE) ss.push_back("srefRefWznmMLocale");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmPrj::ImeIRMLocaleMVersion
 ******************************************************************************/

IexWznmPrj::ImeIRMLocaleMVersion::ImeIRMLocaleMVersion() {
};

IexWznmPrj::ImeIRMLocaleMVersion::~ImeIRMLocaleMVersion() {
	clear();
};

void IexWznmPrj::ImeIRMLocaleMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmPrj::ImeIRMLocaleMVersion::readTxt(
			Txtrd& txtrd
		) {
	IexWznmPrj::ImeitemIRMLocaleMVersion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmPrj::ImeitemIRMLocaleMVersion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLocaleMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMLocaleMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMLOCALEMVERSION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLocaleMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLocaleMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmPrj::ImeIRMLocaleMVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmPrj::ImeitemIRMLocaleMVersion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMLocaleMVersion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMLocaleMVersion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMLocaleMVersion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmPrj::ImeitemIRMLocaleMVersion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmPrj::ImeIRMLocaleMVersion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMLocaleMVersion." << StrMod::replaceChar(ImeIRMLocaleMVersion::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMLocaleMVersion.end" << endl;
	};
};

void IexWznmPrj::ImeIRMLocaleMVersion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMLocaleMVersion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmPrj::ImeitemIMVersion
 ******************************************************************************/

IexWznmPrj::ImeitemIMVersion::ImeitemIMVersion(
			const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const uint ixVState
			, const uint ixWDbmstype
			, const uint ixWOption
			, const string& About1
			, const string& About2
			, const string& About3
			, const string& Comment
		) : WznmMVersion() {
	lineno = 0;
	ixWIelValid = 0;

	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->ixVState = ixVState;
	this->ixWDbmstype = ixWDbmstype;
	this->ixWOption = ixWOption;
	this->About1 = About1;
	this->About2 = About2;
	this->About3 = About3;
	this->Comment = Comment;
};

IexWznmPrj::ImeitemIMVersion::ImeitemIMVersion(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVersion()
		{
	WznmMVersion* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmversion->loadRecByRef(ref, &rec)) {
		grp = rec->grp;
		own = rec->own;
		prjRefWznmMProject = rec->prjRefWznmMProject;
		prjNum = rec->prjNum;
		refRLocale = rec->refRLocale;
		refWznmMLocale = rec->refWznmMLocale;
		Major = rec->Major;
		Minor = rec->Minor;
		Sub = rec->Sub;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixWDbmstype = rec->ixWDbmstype;
		ixWOption = rec->ixWOption;
		refJ = rec->refJ;
		About1 = rec->About1;
		About2 = rec->About2;
		About3 = rec->About3;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmPrj::ImeitemIMVersion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Major = atoi(txtrd.fields[0].c_str()); ixWIelValid += ImeIMVersion::VecWIel::MAJOR;};
	if (txtrd.fields.size() > 1) {Minor = atoi(txtrd.fields[1].c_str()); ixWIelValid += ImeIMVersion::VecWIel::MINOR;};
	if (txtrd.fields.size() > 2) {Sub = atoi(txtrd.fields[2].c_str()); ixWIelValid += ImeIMVersion::VecWIel::SUB;};
	if (txtrd.fields.size() > 3) {srefIxVState = txtrd.fields[3]; ixWIelValid += ImeIMVersion::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 4) {srefsIxWDbmstype = txtrd.fields[4]; ixWIelValid += ImeIMVersion::VecWIel::SREFSIXWDBMSTYPE;};
	if (txtrd.fields.size() > 5) {srefsIxWOption = txtrd.fields[5]; ixWIelValid += ImeIMVersion::VecWIel::SREFSIXWOPTION;};
	if (txtrd.fields.size() > 6) {About1 = txtrd.fields[6]; ixWIelValid += ImeIMVersion::VecWIel::ABOUT1;};
	if (txtrd.fields.size() > 7) {About2 = txtrd.fields[7]; ixWIelValid += ImeIMVersion::VecWIel::ABOUT2;};
	if (txtrd.fields.size() > 8) {About3 = txtrd.fields[8]; ixWIelValid += ImeIMVersion::VecWIel::ABOUT3;};
	if (txtrd.fields.size() > 9) {Comment = txtrd.fields[9]; ixWIelValid += ImeIMVersion::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMVERSION)) {
					imeijmversion.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMVERSIONSTATE)) {
					imeijmversionstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMLOCALEMVERSION)) {
					imeirmlocalemversion.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVersion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmPrj::ImeitemIMVersion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major)) ixWIelValid += ImeIMVersion::VecWIel::MAJOR;
		if (extractUsmallintUclc(docctx, basexpath, "Minor", "min", Minor)) ixWIelValid += ImeIMVersion::VecWIel::MINOR;
		if (extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub)) ixWIelValid += ImeIMVersion::VecWIel::SUB;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMVersion::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefsIxWDbmstype", "dty", srefsIxWDbmstype)) ixWIelValid += ImeIMVersion::VecWIel::SREFSIXWDBMSTYPE;
		if (extractStringUclc(docctx, basexpath, "srefsIxWOption", "opt", srefsIxWOption)) ixWIelValid += ImeIMVersion::VecWIel::SREFSIXWOPTION;
		if (extractStringUclc(docctx, basexpath, "About1", "ab1", About1)) ixWIelValid += ImeIMVersion::VecWIel::ABOUT1;
		if (extractStringUclc(docctx, basexpath, "About2", "ab2", About2)) ixWIelValid += ImeIMVersion::VecWIel::ABOUT2;
		if (extractStringUclc(docctx, basexpath, "About3", "ab3", About3)) ixWIelValid += ImeIMVersion::VecWIel::ABOUT3;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVersion::VecWIel::COMMENT;
		imeijmversion.readXML(docctx, basexpath);
		imeijmversionstate.readXML(docctx, basexpath);
		imeirmlocalemversion.readXML(docctx, basexpath);
	};
};

void IexWznmPrj::ImeitemIMVersion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Major << "\t" << Minor << "\t" << Sub << "\t" << VecWznmVMVersionState::getSref(ixVState) << "\t" << VecWznmWMVersionDbmstype::getSrefs(ixWDbmstype) << "\t" << VecWznmWMVersionOption::getSrefs(ixWOption) << "\t" << About1 << "\t" << About2 << "\t" << About3 << "\t" << Comment << endl;
	imeijmversion.writeTxt(outfile);
	imeijmversionstate.writeTxt(outfile);
	imeirmlocalemversion.writeTxt(outfile);
};

void IexWznmPrj::ImeitemIMVersion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","maj","min","sub","ste","dty","opt","ab1","ab2","ab3","cmt"};
	else tags = {"ImeitemIMVersion","Major","Minor","Sub","srefIxVState","srefsIxWDbmstype","srefsIxWOption","About1","About2","About3","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUsmallint(wr, tags[1], Major);
		writeUsmallint(wr, tags[2], Minor);
		writeUsmallint(wr, tags[3], Sub);
		writeString(wr, tags[4], VecWznmVMVersionState::getSref(ixVState));
		writeString(wr, tags[5], VecWznmWMVersionDbmstype::getSrefs(ixWDbmstype));
		writeString(wr, tags[6], VecWznmWMVersionOption::getSrefs(ixWOption));
		writeString(wr, tags[7], About1);
		writeString(wr, tags[8], About2);
		writeString(wr, tags[9], About3);
		writeString(wr, tags[10], Comment);
		imeijmversion.writeXML(wr, shorttags);
		imeijmversionstate.writeXML(wr, shorttags);
		imeirmlocalemversion.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmPrj::ImeIMVersion::VecWIel
 ******************************************************************************/

uint IexWznmPrj::ImeIMVersion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "major") ix |= MAJOR;
		else if (ss[i] == "minor") ix |= MINOR;
		else if (ss[i] == "sub") ix |= SUB;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefsixwdbmstype") ix |= SREFSIXWDBMSTYPE;
		else if (ss[i] == "srefsixwoption") ix |= SREFSIXWOPTION;
		else if (ss[i] == "about1") ix |= ABOUT1;
		else if (ss[i] == "about2") ix |= ABOUT2;
		else if (ss[i] == "about3") ix |= ABOUT3;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmPrj::ImeIMVersion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmPrj::ImeIMVersion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & MAJOR) ss.push_back("Major");
	if (ix & MINOR) ss.push_back("Minor");
	if (ix & SUB) ss.push_back("Sub");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFSIXWDBMSTYPE) ss.push_back("srefsIxWDbmstype");
	if (ix & SREFSIXWOPTION) ss.push_back("srefsIxWOption");
	if (ix & ABOUT1) ss.push_back("About1");
	if (ix & ABOUT2) ss.push_back("About2");
	if (ix & ABOUT3) ss.push_back("About3");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmPrj::ImeIMVersion
 ******************************************************************************/

IexWznmPrj::ImeIMVersion::ImeIMVersion() {
};

IexWznmPrj::ImeIMVersion::~ImeIMVersion() {
	clear();
};

void IexWznmPrj::ImeIMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmPrj::ImeIMVersion::readTxt(
			Txtrd& txtrd
		) {
	IexWznmPrj::ImeitemIMVersion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmPrj::ImeitemIMVersion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVERSION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmPrj::ImeIMVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmPrj::ImeitemIMVersion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVersion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVersion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVersion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmPrj::ImeitemIMVersion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmPrj::ImeIMVersion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVersion." << StrMod::replaceChar(ImeIMVersion::VecWIel::getSrefs(1023), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVersion.end" << endl;
	};
};

void IexWznmPrj::ImeIMVersion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVersion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmPrj::ImeitemIRMPersonMProject
 ******************************************************************************/

IexWznmPrj::ImeitemIRMPersonMProject::ImeitemIRMPersonMProject(
			const string& hintRefWznmMPerson
			, const string& srefKFunction
		) : WznmRMPersonMProject() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefWznmMPerson = hintRefWznmMPerson;
	this->srefKFunction = srefKFunction;
};

IexWznmPrj::ImeitemIRMPersonMProject::ImeitemIRMPersonMProject(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMPersonMProject()
		{
	WznmRMPersonMProject* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmpersonmproject->loadRecByRef(ref, &rec)) {
		refWznmMPerson = rec->refWznmMPerson;
		refWznmMProject = rec->refWznmMProject;
		srefKFunction = rec->srefKFunction;

		delete rec;
	};
};

void IexWznmPrj::ImeitemIRMPersonMProject::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hintRefWznmMPerson = txtrd.fields[0]; ixWIelValid += ImeIRMPersonMProject::VecWIel::HINTREFWZNMMPERSON;};
	if (txtrd.fields.size() > 1) {srefKFunction = txtrd.fields[1]; ixWIelValid += ImeIRMPersonMProject::VecWIel::SREFKFUNCTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmPrj::ImeitemIRMPersonMProject::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hintRefWznmMPerson", "prs", hintRefWznmMPerson)) ixWIelValid += ImeIRMPersonMProject::VecWIel::HINTREFWZNMMPERSON;
		if (extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction)) ixWIelValid += ImeIRMPersonMProject::VecWIel::SREFKFUNCTION;
	};
};

void IexWznmPrj::ImeitemIRMPersonMProject::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hintRefWznmMPerson << "\t" << srefKFunction << endl;
};

void IexWznmPrj::ImeitemIRMPersonMProject::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs","fct"};
	else tags = {"ImeitemIRMPersonMProject","hintRefWznmMPerson","srefKFunction"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefWznmMPerson);
		writeString(wr, tags[2], srefKFunction);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmPrj::ImeIRMPersonMProject::VecWIel
 ******************************************************************************/

uint IexWznmPrj::ImeIRMPersonMProject::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hintrefwznmmperson") ix |= HINTREFWZNMMPERSON;
		else if (ss[i] == "srefkfunction") ix |= SREFKFUNCTION;
	};

	return(ix);
};

void IexWznmPrj::ImeIRMPersonMProject::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKFUNCTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmPrj::ImeIRMPersonMProject::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFWZNMMPERSON) ss.push_back("hintRefWznmMPerson");
	if (ix & SREFKFUNCTION) ss.push_back("srefKFunction");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmPrj::ImeIRMPersonMProject
 ******************************************************************************/

IexWznmPrj::ImeIRMPersonMProject::ImeIRMPersonMProject() {
};

IexWznmPrj::ImeIRMPersonMProject::~ImeIRMPersonMProject() {
	clear();
};

void IexWznmPrj::ImeIRMPersonMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmPrj::ImeIRMPersonMProject::readTxt(
			Txtrd& txtrd
		) {
	IexWznmPrj::ImeitemIRMPersonMProject* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmPrj::ImeitemIRMPersonMProject();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMPERSONMPROJECT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmPrj::ImeIRMPersonMProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmPrj::ImeitemIRMPersonMProject* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMPersonMProject");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMPersonMProject", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMPersonMProject";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmPrj::ImeitemIRMPersonMProject();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmPrj::ImeIRMPersonMProject::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMPersonMProject." << StrMod::replaceChar(ImeIRMPersonMProject::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMPersonMProject.end" << endl;
	};
};

void IexWznmPrj::ImeIRMPersonMProject::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMPersonMProject");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmPrj::ImeitemIMProject
 ******************************************************************************/

IexWznmPrj::ImeitemIMProject::ImeitemIMProject(
			const string& Short
			, const string& Title
			, const string& Giturl
			, const string& Comment
		) : WznmMProject() {
	lineno = 0;
	ixWIelValid = 0;

	this->Short = Short;
	this->Title = Title;
	this->Giturl = Giturl;
	this->Comment = Comment;
};

IexWznmPrj::ImeitemIMProject::ImeitemIMProject(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMProject()
		{
	WznmMProject* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmproject->loadRecByRef(ref, &rec)) {
		grp = rec->grp;
		own = rec->own;
		refWznmMVersion = rec->refWznmMVersion;
		Short = rec->Short;
		Title = rec->Title;
		Giturl = rec->Giturl;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmPrj::ImeitemIMProject::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Short = txtrd.fields[0]; ixWIelValid += ImeIMProject::VecWIel::SHORT;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMProject::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Giturl = txtrd.fields[2]; ixWIelValid += ImeIMProject::VecWIel::GITURL;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMProject::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVERSION)) {
					imeimversion.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMPERSONMPROJECT)) {
					imeirmpersonmproject.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMProject"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmPrj::ImeitemIMProject::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMProject::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMProject::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Giturl", "grl", Giturl)) ixWIelValid += ImeIMProject::VecWIel::GITURL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMProject::VecWIel::COMMENT;
		imeimversion.readXML(docctx, basexpath);
		imeirmpersonmproject.readXML(docctx, basexpath);
	};
};

void IexWznmPrj::ImeitemIMProject::writeTxt(
			fstream& outfile
		) {
	outfile << Short << "\t" << Title << "\t" << Giturl << "\t" << Comment << endl;
	imeimversion.writeTxt(outfile);
	imeirmpersonmproject.writeTxt(outfile);
};

void IexWznmPrj::ImeitemIMProject::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sho","tit","grl","cmt"};
	else tags = {"ImeitemIMProject","Short","Title","Giturl","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Short);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Giturl);
		writeString(wr, tags[4], Comment);
		imeimversion.writeXML(wr, shorttags);
		imeirmpersonmproject.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmPrj::ImeIMProject::VecWIel
 ******************************************************************************/

uint IexWznmPrj::ImeIMProject::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "giturl") ix |= GITURL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmPrj::ImeIMProject::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmPrj::ImeIMProject::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SHORT) ss.push_back("Short");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & GITURL) ss.push_back("Giturl");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmPrj::ImeIMProject
 ******************************************************************************/

IexWznmPrj::ImeIMProject::ImeIMProject() {
};

IexWznmPrj::ImeIMProject::~ImeIMProject() {
	clear();
};

void IexWznmPrj::ImeIMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmPrj::ImeIMProject::readTxt(
			Txtrd& txtrd
		) {
	IexWznmPrj::ImeitemIMProject* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmPrj::ImeitemIMProject();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMProject"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPROJECT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProject"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProject"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmPrj::ImeIMProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmPrj::ImeitemIMProject* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMProject");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMProject", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMProject";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmPrj::ImeitemIMProject();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmPrj::ImeIMProject::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMProject." << StrMod::replaceChar(ImeIMProject::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMProject.end" << endl;
	};
};

void IexWznmPrj::ImeIMProject::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMProject");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmPrj
 ******************************************************************************/

void IexWznmPrj::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMProject& imeimproject
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimproject);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmPrj", Version("0.9.29"), VecVIme::getIx);
			readTxt(rd, imeimproject);
	};
};

void IexWznmPrj::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMProject& imeimproject
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimproject);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimproject);
		txtfile.close();
	};
};

void IexWznmPrj::readTxt(
			Txtrd& txtrd
			, ImeIMProject& imeimproject
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMPROJECT)) imeimproject.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmPrj::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMProject& imeimproject
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmPrj")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.29")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.29"}});
		};

		// look for XML sub-blocks
		imeimproject.readXML(docctx, basexpath);

	} else {
		imeimproject = ImeIMProject();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmPrj"}});
	};
};

void IexWznmPrj::writeTxt(
			fstream& outfile
			, ImeIMProject& imeimproject
		) {
	outfile << "IexWznmPrj v" WZNM_VERSION << endl;

	imeimproject.writeTxt(outfile);
};

void IexWznmPrj::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMProject& imeimproject
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmPrj");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimproject.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmPrj::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIJMVERSION,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMVERSIONSTATE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMPROJECT,VecWznmVIop::RETRINS},{(uint)VecVIme::IMEIMVERSION,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMLOCALEMVERSION,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMPERSONMPROJECT,VecWznmVIop::INS}};
};

uint IexWznmPrj::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};
