/**
	* \file IexWznmDpl.cpp
	* data blocks and readers/writers for import/export complex IexWznmDpl (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWznmDpl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmDpl::VecVIme
 ******************************************************************************/

uint IexWznmDpl::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimcomponent") return IMEIMCOMPONENT;
	if (s == "imeimrelease") return IMEIMRELEASE;
	if (s == "imeirmcomponentmlibrary") return IMEIRMCOMPONENTMLIBRARY;

	return(0);
};

string IexWznmDpl::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMCOMPONENT) return("ImeIMComponent");
	if (ix == IMEIMRELEASE) return("ImeIMRelease");
	if (ix == IMEIRMCOMPONENTMLIBRARY) return("ImeIRMComponentMLibrary");

	return("");
};

/******************************************************************************
 class IexWznmDpl::ImeitemIMRelease
 ******************************************************************************/

IexWznmDpl::ImeitemIMRelease::ImeitemIMRelease(
			const string& hsrefRefWznmMMachine
			, const string& sref
			, const string& srefsKOption
			, const string& Comment
		) : WznmMRelease() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefWznmMMachine = hsrefRefWznmMMachine;
	this->sref = sref;
	this->srefsKOption = srefsKOption;
	this->Comment = Comment;
};

IexWznmDpl::ImeitemIMRelease::ImeitemIMRelease(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMRelease()
		{
	WznmMRelease* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmrelease->loadRecByRef(ref, &rec)) {
		refWznmMComponent = rec->refWznmMComponent;
		refWznmMMachine = rec->refWznmMMachine;
		sref = rec->sref;
		srefsKOption = rec->srefsKOption;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmDpl::ImeitemIMRelease::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefRefWznmMMachine = txtrd.fields[0]; ixWIelValid += ImeIMRelease::VecWIel::HSREFREFWZNMMMACHINE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMRelease::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefsKOption = txtrd.fields[2]; ixWIelValid += ImeIMRelease::VecWIel::SREFSKOPTION;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMRelease::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRelease"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDpl::ImeitemIMRelease::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefWznmMMachine", "mch", hsrefRefWznmMMachine)) ixWIelValid += ImeIMRelease::VecWIel::HSREFREFWZNMMMACHINE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRelease::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMRelease::VecWIel::SREFSKOPTION;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMRelease::VecWIel::COMMENT;
	};
};

void IexWznmDpl::ImeitemIMRelease::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefRefWznmMMachine << "\t" << sref << "\t" << srefsKOption << "\t" << Comment << endl;
};

void IexWznmDpl::ImeitemIMRelease::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mch","srf","opt","cmt"};
	else tags = {"ImeitemIMRelease","hsrefRefWznmMMachine","sref","srefsKOption","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefWznmMMachine);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefsKOption);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDpl::ImeIMRelease::VecWIel
 ******************************************************************************/

uint IexWznmDpl::ImeIMRelease::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefrefwznmmmachine") ix |= HSREFREFWZNMMMACHINE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmDpl::ImeIMRelease::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDpl::ImeIMRelease::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFWZNMMMACHINE) ss.push_back("hsrefRefWznmMMachine");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDpl::ImeIMRelease
 ******************************************************************************/

IexWznmDpl::ImeIMRelease::ImeIMRelease() {
};

IexWznmDpl::ImeIMRelease::~ImeIMRelease() {
	clear();
};

void IexWznmDpl::ImeIMRelease::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDpl::ImeIMRelease::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDpl::ImeitemIMRelease* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDpl::ImeitemIMRelease();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMRELEASE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDpl::ImeIMRelease::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDpl::ImeitemIMRelease* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRelease");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRelease", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRelease";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDpl::ImeitemIMRelease();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDpl::ImeIMRelease::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMRelease." << StrMod::replaceChar(ImeIMRelease::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMRelease.end" << endl;
	};
};

void IexWznmDpl::ImeIMRelease::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRelease");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDpl::ImeitemIRMComponentMLibrary
 ******************************************************************************/

IexWznmDpl::ImeitemIRMComponentMLibrary::ImeitemIRMComponentMLibrary(
			const string& srefRefWznmMLibrary
		) : WznmRMComponentMLibrary() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMLibrary = srefRefWznmMLibrary;
};

IexWznmDpl::ImeitemIRMComponentMLibrary::ImeitemIRMComponentMLibrary(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMComponentMLibrary()
		{
	WznmRMComponentMLibrary* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmcomponentmlibrary->loadRecByRef(ref, &rec)) {
		refWznmMComponent = rec->refWznmMComponent;
		refWznmMLibrary = rec->refWznmMLibrary;

		delete rec;
	};
};

void IexWznmDpl::ImeitemIRMComponentMLibrary::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMLibrary = txtrd.fields[0]; ixWIelValid += ImeIRMComponentMLibrary::VecWIel::SREFREFWZNMMLIBRARY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDpl::ImeitemIRMComponentMLibrary::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMLibrary", "lib", srefRefWznmMLibrary)) ixWIelValid += ImeIRMComponentMLibrary::VecWIel::SREFREFWZNMMLIBRARY;
	};
};

void IexWznmDpl::ImeitemIRMComponentMLibrary::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMLibrary << endl;
};

void IexWznmDpl::ImeitemIRMComponentMLibrary::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lib"};
	else tags = {"ImeitemIRMComponentMLibrary","srefRefWznmMLibrary"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMLibrary);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDpl::ImeIRMComponentMLibrary::VecWIel
 ******************************************************************************/

uint IexWznmDpl::ImeIRMComponentMLibrary::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmlibrary") ix |= SREFREFWZNMMLIBRARY;
	};

	return(ix);
};

void IexWznmDpl::ImeIRMComponentMLibrary::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMLIBRARY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDpl::ImeIRMComponentMLibrary::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMLIBRARY) ss.push_back("srefRefWznmMLibrary");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDpl::ImeIRMComponentMLibrary
 ******************************************************************************/

IexWznmDpl::ImeIRMComponentMLibrary::ImeIRMComponentMLibrary() {
};

IexWznmDpl::ImeIRMComponentMLibrary::~ImeIRMComponentMLibrary() {
	clear();
};

void IexWznmDpl::ImeIRMComponentMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDpl::ImeIRMComponentMLibrary::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDpl::ImeitemIRMComponentMLibrary* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDpl::ImeitemIRMComponentMLibrary();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCOMPONENTMLIBRARY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDpl::ImeIRMComponentMLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDpl::ImeitemIRMComponentMLibrary* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMComponentMLibrary");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMComponentMLibrary", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMComponentMLibrary";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDpl::ImeitemIRMComponentMLibrary();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDpl::ImeIRMComponentMLibrary::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMComponentMLibrary." << StrMod::replaceChar(ImeIRMComponentMLibrary::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMComponentMLibrary.end" << endl;
	};
};

void IexWznmDpl::ImeIRMComponentMLibrary::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMComponentMLibrary");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDpl::ImeitemIMComponent
 ******************************************************************************/

IexWznmDpl::ImeitemIMComponent::ImeitemIMComponent(
			const uint ixVBasetype
			, const string& sref
			, const string& Title
			, const string& Comment
		) : WznmMComponent() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmDpl::ImeitemIMComponent::ImeitemIMComponent(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMComponent()
		{
	WznmMComponent* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcomponent->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		sref = rec->sref;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmDpl::ImeitemIMComponent::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMComponent::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMComponent::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMComponent::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMComponent::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMRELEASE)) {
					imeimrelease.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMCOMPONENTMLIBRARY)) {
					imeirmcomponentmlibrary.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMComponent"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDpl::ImeitemIMComponent::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMComponent::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMComponent::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMComponent::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMComponent::VecWIel::COMMENT;
		imeimrelease.readXML(docctx, basexpath);
		imeirmcomponentmlibrary.readXML(docctx, basexpath);
	};
};

void IexWznmDpl::ImeitemIMComponent::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMComponentBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeimrelease.writeTxt(outfile);
	imeirmcomponentmlibrary.writeTxt(outfile);
};

void IexWznmDpl::ImeitemIMComponent::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tit","cmt"};
	else tags = {"ImeitemIMComponent","srefIxVBasetype","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMComponentBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Comment);
		imeimrelease.writeXML(wr, shorttags);
		imeirmcomponentmlibrary.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDpl::ImeIMComponent::VecWIel
 ******************************************************************************/

uint IexWznmDpl::ImeIMComponent::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmDpl::ImeIMComponent::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDpl::ImeIMComponent::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDpl::ImeIMComponent
 ******************************************************************************/

IexWznmDpl::ImeIMComponent::ImeIMComponent() {
};

IexWznmDpl::ImeIMComponent::~ImeIMComponent() {
	clear();
};

void IexWznmDpl::ImeIMComponent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDpl::ImeIMComponent::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDpl::ImeitemIMComponent* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDpl::ImeitemIMComponent();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMComponent"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOMPONENT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMComponent"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMComponent"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDpl::ImeIMComponent::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDpl::ImeitemIMComponent* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMComponent");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMComponent", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMComponent";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDpl::ImeitemIMComponent();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDpl::ImeIMComponent::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMComponent." << StrMod::replaceChar(ImeIMComponent::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMComponent.end" << endl;
	};
};

void IexWznmDpl::ImeIMComponent::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMComponent");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmDpl
 ******************************************************************************/

void IexWznmDpl::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMComponent& imeimcomponent
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimcomponent);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmDpl", Version("1.0.9"), VecVIme::getIx);
			readTxt(rd, imeimcomponent);
	};
};

void IexWznmDpl::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMComponent& imeimcomponent
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimcomponent);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimcomponent);
		txtfile.close();
	};
};

void IexWznmDpl::readTxt(
			Txtrd& txtrd
			, ImeIMComponent& imeimcomponent
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCOMPONENT)) imeimcomponent.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmDpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMComponent& imeimcomponent
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmDpl")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.0.9")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.0.9"}});
		};

		// look for XML sub-blocks
		imeimcomponent.readXML(docctx, basexpath);

	} else {
		imeimcomponent = ImeIMComponent();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmDpl"}});
	};
};

void IexWznmDpl::writeTxt(
			fstream& outfile
			, ImeIMComponent& imeimcomponent
		) {
	outfile << "IexWznmDpl v" WZNM_VERSION << endl;

	imeimcomponent.writeTxt(outfile);
};

void IexWznmDpl::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMComponent& imeimcomponent
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmDpl");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimcomponent.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmDpl::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIMCOMPONENT,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRELEASE,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMCOMPONENTMLIBRARY,VecWznmVIop::INS}};
};

uint IexWznmDpl::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};



