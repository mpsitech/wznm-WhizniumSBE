/**
	* \file IexWznmBui.cpp
	* data blocks and readers/writers for import/export complex IexWznmBui (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWznmBui.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmBui::VecVIme
 ******************************************************************************/

uint IexWznmBui::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeijmcardtitle") return IMEIJMCARDTITLE;
	if (s == "imeijmmodule") return IMEIJMMODULE;
	if (s == "imeimcard") return IMEIMCARD;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimpreset") return IMEIMPRESET;

	return(0);
};

string IexWznmBui::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIJMCARDTITLE) return("ImeIJMCardTitle");
	if (ix == IMEIJMMODULE) return("ImeIJMModule");
	if (ix == IMEIMCARD) return("ImeIMCard");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPRESET) return("ImeIMPreset");

	return("");
};

/******************************************************************************
 class IexWznmBui::ImeitemIJMModule
 ******************************************************************************/

IexWznmBui::ImeitemIJMModule::ImeitemIJMModule(
			const string& srefX1RefWznmMLocale
			, const string& Title
			, const string& Comment
		) : WznmJMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmBui::ImeitemIJMModule::ImeitemIJMModule(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMModule()
		{
	WznmJMModule* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmmodule->loadRecByRef(ref, &rec)) {
		refWznmMModule = rec->refWznmMModule;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmBui::ImeitemIJMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMModule::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMModule::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJMModule::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMModule"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmBui::ImeitemIJMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMModule::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMModule::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJMModule::VecWIel::COMMENT;
	};
};

void IexWznmBui::ImeitemIJMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWznmMLocale << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmBui::ImeitemIJMModule::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit","cmt"};
	else tags = {"ImeitemIJMModule","srefX1RefWznmMLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmBui::ImeIJMModule::VecWIel
 ******************************************************************************/

uint IexWznmBui::ImeIJMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmBui::ImeIJMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmBui::ImeIJMModule::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMLOCALE) ss.push_back("srefX1RefWznmMLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmBui::ImeIJMModule
 ******************************************************************************/

IexWznmBui::ImeIJMModule::ImeIJMModule() {
};

IexWznmBui::ImeIJMModule::~ImeIJMModule() {
	clear();
};

void IexWznmBui::ImeIJMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmBui::ImeIJMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWznmBui::ImeitemIJMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmBui::ImeitemIJMModule();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMModule"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMModule"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMMODULE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMModule"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMModule"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmBui::ImeIJMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmBui::ImeitemIJMModule* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMModule");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMModule", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMModule";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmBui::ImeitemIJMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmBui::ImeIJMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMModule." << StrMod::replaceChar(ImeIJMModule::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMModule.end" << endl;
	};
};

void IexWznmBui::ImeIJMModule::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMModule");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmBui::ImeitemIJMCardTitle
 ******************************************************************************/

IexWznmBui::ImeitemIJMCardTitle::ImeitemIJMCardTitle(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMCardTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmBui::ImeitemIJMCardTitle::ImeitemIJMCardTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMCardTitle()
		{
	WznmJMCardTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmcardtitle->loadRecByRef(ref, &rec)) {
		refWznmMCard = rec->refWznmMCard;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmBui::ImeitemIJMCardTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMCardTitle::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMCardTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMCardTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmBui::ImeitemIJMCardTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMCardTitle::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMCardTitle::VecWIel::TITLE;
	};
};

void IexWznmBui::ImeitemIJMCardTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmBui::ImeitemIJMCardTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMCardTitle","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmBui::ImeIJMCardTitle::VecWIel
 ******************************************************************************/

uint IexWznmBui::ImeIJMCardTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmBui::ImeIJMCardTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmBui::ImeIJMCardTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMLOCALE) ss.push_back("srefX1RefWznmMLocale");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmBui::ImeIJMCardTitle
 ******************************************************************************/

IexWznmBui::ImeIJMCardTitle::ImeIJMCardTitle() {
};

IexWznmBui::ImeIJMCardTitle::~ImeIJMCardTitle() {
	clear();
};

void IexWznmBui::ImeIJMCardTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmBui::ImeIJMCardTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmBui::ImeitemIJMCardTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmBui::ImeitemIJMCardTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMCardTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMCardTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCARDTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMCardTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMCardTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmBui::ImeIJMCardTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmBui::ImeitemIJMCardTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMCardTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMCardTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMCardTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmBui::ImeitemIJMCardTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmBui::ImeIJMCardTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMCardTitle." << StrMod::replaceChar(ImeIJMCardTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMCardTitle.end" << endl;
	};
};

void IexWznmBui::ImeIJMCardTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMCardTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmBui::ImeitemIMCard
 ******************************************************************************/

IexWznmBui::ImeitemIMCard::ImeitemIMCard(
			const uint refIxVTbl
			, const string& srefRefUref
			, const string& sref
			, const string& Title
			, const string& Avail
			, const string& Active
		) : WznmMCard() {
	lineno = 0;
	ixWIelValid = 0;

	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->sref = sref;
	this->Title = Title;
	this->Avail = Avail;
	this->Active = Active;
};

IexWznmBui::ImeitemIMCard::ImeitemIMCard(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCard()
		{
	WznmMCard* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcard->loadRecByRef(ref, &rec)) {
		mdlRefWznmMModule = rec->mdlRefWznmMModule;
		mdlNum = rec->mdlNum;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		sref = rec->sref;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		Avail = rec->Avail;
		Active = rec->Active;

		delete rec;
	};
};

void IexWznmBui::ImeitemIMCard::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefIxVTbl = txtrd.fields[0]; ixWIelValid += ImeIMCard::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 1) {srefRefUref = txtrd.fields[1]; ixWIelValid += ImeIMCard::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMCard::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIMCard::VecWIel::TITLE;};
	if (txtrd.fields.size() > 4) {Avail = txtrd.fields[4]; ixWIelValid += ImeIMCard::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 5) {Active = txtrd.fields[5]; ixWIelValid += ImeIMCard::VecWIel::ACTIVE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMCARDTITLE)) {
					imeijmcardtitle.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCard"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmBui::ImeitemIMCard::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMCard::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMCard::VecWIel::SREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCard::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMCard::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMCard::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Active", "act", Active)) ixWIelValid += ImeIMCard::VecWIel::ACTIVE;
		imeijmcardtitle.readXML(docctx, basexpath);
	};
};

void IexWznmBui::ImeitemIMCard::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMCardRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << sref << "\t" << Title << "\t" << Avail << "\t" << Active << endl;
	imeijmcardtitle.writeTxt(outfile);
};

void IexWznmBui::ImeitemIMCard::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ret","reu","srf","tit","avl","act"};
	else tags = {"ImeitemIMCard","srefRefIxVTbl","srefRefUref","sref","Title","Avail","Active"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMCardRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[2], srefRefUref);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Title);
		writeString(wr, tags[5], Avail);
		writeString(wr, tags[6], Active);
		imeijmcardtitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmBui::ImeIMCard::VecWIel
 ******************************************************************************/

uint IexWznmBui::ImeIMCard::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "active") ix |= ACTIVE;
	};

	return(ix);
};

void IexWznmBui::ImeIMCard::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*ACTIVE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmBui::ImeIMCard::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & ACTIVE) ss.push_back("Active");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmBui::ImeIMCard
 ******************************************************************************/

IexWznmBui::ImeIMCard::ImeIMCard() {
};

IexWznmBui::ImeIMCard::~ImeIMCard() {
	clear();
};

void IexWznmBui::ImeIMCard::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmBui::ImeIMCard::readTxt(
			Txtrd& txtrd
		) {
	IexWznmBui::ImeitemIMCard* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmBui::ImeitemIMCard();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCard"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCard"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCARD) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCard"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCard"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmBui::ImeIMCard::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmBui::ImeitemIMCard* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCard");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCard", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCard";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmBui::ImeitemIMCard();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmBui::ImeIMCard::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMCard." << StrMod::replaceChar(ImeIMCard::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMCard.end" << endl;
	};
};

void IexWznmBui::ImeIMCard::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCard");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmBui::ImeitemIMModule
 ******************************************************************************/

IexWznmBui::ImeitemIMModule::ImeitemIMModule(
			const string& sref
			, const string& Title
			, const string& Comment
		) : WznmMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmBui::ImeitemIMModule::ImeitemIMModule(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMModule()
		{
	WznmMModule* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmmodule->loadRecByRef(ref, &rec)) {
		verRefWznmMVersion = rec->verRefWznmMVersion;
		verNum = rec->verNum;
		sref = rec->sref;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmBui::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMModule::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMMODULE)) {
					imeijmmodule.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCARD)) {
					imeimcard.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMModule"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmBui::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMModule::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMModule::VecWIel::COMMENT;
		imeijmmodule.readXML(docctx, basexpath);
		imeimcard.readXML(docctx, basexpath);
	};
};

void IexWznmBui::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << "\t" << Comment << endl;
	imeijmmodule.writeTxt(outfile);
	imeimcard.writeTxt(outfile);
};

void IexWznmBui::ImeitemIMModule::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIMModule","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
		imeijmmodule.writeXML(wr, shorttags);
		imeimcard.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmBui::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWznmBui::ImeIMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmBui::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmBui::ImeIMModule::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmBui::ImeIMModule
 ******************************************************************************/

IexWznmBui::ImeIMModule::ImeIMModule() {
};

IexWznmBui::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWznmBui::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmBui::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWznmBui::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmBui::ImeitemIMModule();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMMODULE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmBui::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmBui::ImeitemIMModule* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMModule");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMModule", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMModule";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmBui::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmBui::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMModule.end" << endl;
	};
};

void IexWznmBui::ImeIMModule::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMModule");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmBui::ImeitemIMPreset
 ******************************************************************************/

IexWznmBui::ImeitemIMPreset::ImeitemIMPreset(
			const uint ixWznmVIop
			, const uint refIxVTbl
			, const string& srefRefUref
			, const uint ixVScope
			, const string& sref
			, const uint ixWznmWArgtype
		) : WznmMPreset() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->ixVScope = ixVScope;
	this->sref = sref;
	this->ixWznmWArgtype = ixWznmWArgtype;
};

IexWznmBui::ImeitemIMPreset::ImeitemIMPreset(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMPreset()
		{
	WznmMPreset* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmpreset->loadRecByRef(ref, &rec)) {
		refWznmMVersion = rec->refWznmMVersion;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		ixVScope = rec->ixVScope;
		sref = rec->sref;
		ixWznmWArgtype = rec->ixWznmWArgtype;

		delete rec;
	};
};

void IexWznmBui::ImeitemIMPreset::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMPreset::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefRefIxVTbl = txtrd.fields[1]; ixWIelValid += ImeIMPreset::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 2) {srefRefUref = txtrd.fields[2]; ixWIelValid += ImeIMPreset::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 3) {srefIxVScope = txtrd.fields[3]; ixWIelValid += ImeIMPreset::VecWIel::SREFIXVSCOPE;};
	if (txtrd.fields.size() > 4) {sref = txtrd.fields[4]; ixWIelValid += ImeIMPreset::VecWIel::SREF;};
	if (txtrd.fields.size() > 5) {srefIxWznmWArgtype = txtrd.fields[5]; ixWIelValid += ImeIMPreset::VecWIel::SREFIXWZNMWARGTYPE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPreset"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmBui::ImeitemIMPreset::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMPreset::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMPreset::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMPreset::VecWIel::SREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVScope", "sco", srefIxVScope)) ixWIelValid += ImeIMPreset::VecWIel::SREFIXVSCOPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPreset::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmWArgtype", "aty", srefIxWznmWArgtype)) ixWIelValid += ImeIMPreset::VecWIel::SREFIXWZNMWARGTYPE;
	};
};

void IexWznmBui::ImeitemIMPreset::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVIop::getSref(ixWznmVIop) << "\t" << VecWznmVMPresetRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << VecWznmVMPresetScope::getSref(ixVScope) << "\t" << sref << "\t" << VecWznmWArgtype::getSrefs(ixWznmWArgtype) << endl;
};

void IexWznmBui::ImeitemIMPreset::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","ret","reu","sco","srf","aty"};
	else tags = {"ImeitemIMPreset","srefIxWznmVIop","srefRefIxVTbl","srefRefUref","srefIxVScope","sref","srefIxWznmWArgtype"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], VecWznmVMPresetRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[3], srefRefUref);
		writeString(wr, tags[4], VecWznmVMPresetScope::getSref(ixVScope));
		writeString(wr, tags[5], sref);
		writeString(wr, tags[6], VecWznmWArgtype::getSrefs(ixWznmWArgtype));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmBui::ImeIMPreset::VecWIel
 ******************************************************************************/

uint IexWznmBui::ImeIMPreset::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "srefixvscope") ix |= SREFIXVSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmwargtype") ix |= SREFIXWZNMWARGTYPE;
	};

	return(ix);
};

void IexWznmBui::ImeIMPreset::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXWZNMWARGTYPE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmBui::ImeIMPreset::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & SREFIXVSCOPE) ss.push_back("srefIxVScope");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMWARGTYPE) ss.push_back("srefIxWznmWArgtype");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmBui::ImeIMPreset
 ******************************************************************************/

IexWznmBui::ImeIMPreset::ImeIMPreset() {
};

IexWznmBui::ImeIMPreset::~ImeIMPreset() {
	clear();
};

void IexWznmBui::ImeIMPreset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmBui::ImeIMPreset::readTxt(
			Txtrd& txtrd
		) {
	IexWznmBui::ImeitemIMPreset* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmBui::ImeitemIMPreset();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPreset"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPRESET) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPreset"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPreset"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmBui::ImeIMPreset::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmBui::ImeitemIMPreset* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPreset");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPreset", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPreset";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmBui::ImeitemIMPreset();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmBui::ImeIMPreset::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMPreset." << StrMod::replaceChar(ImeIMPreset::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMPreset.end" << endl;
	};
};

void IexWznmBui::ImeIMPreset::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPreset");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmBui
 ******************************************************************************/

void IexWznmBui::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMModule& imeimmodule
			, ImeIMPreset& imeimpreset
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimmodule, imeimpreset);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmBui", Version("0.9.23"), VecVIme::getIx);
			readTxt(rd, imeimmodule, imeimpreset);
	};
};

void IexWznmBui::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMModule& imeimmodule
			, ImeIMPreset& imeimpreset
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimmodule, imeimpreset);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimmodule, imeimpreset);
		txtfile.close();
	};
};

void IexWznmBui::readTxt(
			Txtrd& txtrd
			, ImeIMModule& imeimmodule
			, ImeIMPreset& imeimpreset
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) imeimmodule.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMPRESET)) imeimpreset.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmBui::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMModule& imeimmodule
			, ImeIMPreset& imeimpreset
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmBui")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.23")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.23"}});
		};

		// look for XML sub-blocks
		imeimmodule.readXML(docctx, basexpath);
		imeimpreset.readXML(docctx, basexpath);

	} else {
		imeimmodule = ImeIMModule();
		imeimpreset = ImeIMPreset();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmBui"}});
	};
};

void IexWznmBui::writeTxt(
			fstream& outfile
			, ImeIMModule& imeimmodule
			, ImeIMPreset& imeimpreset
		) {
	outfile << "IexWznmBui v" WZNM_VERSION << endl;

	imeimmodule.writeTxt(outfile);
	imeimpreset.writeTxt(outfile);
};

void IexWznmBui::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMModule& imeimmodule
			, ImeIMPreset& imeimpreset
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmBui");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimmodule.writeXML(wr, shorttags);
		imeimpreset.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmBui::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIJMCARDTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMMODULE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCARD,VecWznmVIop::INS},{(uint)VecVIme::IMEIMMODULE,VecWznmVIop::INS}};
};

uint IexWznmBui::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};
