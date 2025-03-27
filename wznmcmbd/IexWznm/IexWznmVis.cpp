/**
	* \file IexWznmVis.cpp
	* data blocks and readers/writers for import/export complex IexWznmVis (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "IexWznmVis.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmVis::VecVIme
 ******************************************************************************/

uint IexWznmVis::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimbox") return IMEIMBOX;
	if (s == "imeimsheet") return IMEIMSHEET;
	if (s == "imeirmboxmbox") return IMEIRMBOXMBOX;

	return(0);
};

string IexWznmVis::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMBOX) return("ImeIMBox");
	if (ix == IMEIMSHEET) return("ImeIMSheet");
	if (ix == IMEIRMBOXMBOX) return("ImeIRMBoxMBox");

	return("");
};

/******************************************************************************
 class IexWznmVis::ImeitemIRMBoxMBox
 ******************************************************************************/

IexWznmVis::ImeitemIRMBoxMBox::ImeitemIRMBoxMBox(
			const ubigint irefDstRefWznmMBox
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
		) : WznmRMBoxMBox() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefDstRefWznmMBox = irefDstRefWznmMBox;
	this->orgClk = orgClk;
	this->dstClk = dstClk;
	this->Weight = Weight;
};

IexWznmVis::ImeitemIRMBoxMBox::ImeitemIRMBoxMBox(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMBoxMBox()
		{
	WznmRMBoxMBox* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmboxmbox->loadRecByRef(ref, &rec)) {
		orgRefWznmMBox = rec->orgRefWznmMBox;
		dstRefWznmMBox = rec->dstRefWznmMBox;
		orgClk = rec->orgClk;
		dstClk = rec->dstClk;
		Weight = rec->Weight;

		delete rec;
	};
};

void IexWznmVis::ImeitemIRMBoxMBox::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefDstRefWznmMBox = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIRMBoxMBox::VecWIel::IREFDSTREFWZNMMBOX;};
	if (txtrd.fields.size() > 1) {orgClk = atoi(txtrd.fields[1].c_str()); ixWIelValid += ImeIRMBoxMBox::VecWIel::ORGCLK;};
	if (txtrd.fields.size() > 2) {dstClk = atoi(txtrd.fields[2].c_str()); ixWIelValid += ImeIRMBoxMBox::VecWIel::DSTCLK;};
	if (txtrd.fields.size() > 3) {Weight = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIRMBoxMBox::VecWIel::WEIGHT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMBoxMBox"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmVis::ImeitemIRMBoxMBox::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefDstRefWznmMBox", "dst", irefDstRefWznmMBox)) ixWIelValid += ImeIRMBoxMBox::VecWIel::IREFDSTREFWZNMMBOX;
		if (extractUtinyintUclc(docctx, basexpath, "orgClk", "ocl", orgClk)) ixWIelValid += ImeIRMBoxMBox::VecWIel::ORGCLK;
		if (extractUtinyintUclc(docctx, basexpath, "dstClk", "dcl", dstClk)) ixWIelValid += ImeIRMBoxMBox::VecWIel::DSTCLK;
		if (extractUtinyintUclc(docctx, basexpath, "Weight", "wgt", Weight)) ixWIelValid += ImeIRMBoxMBox::VecWIel::WEIGHT;
	};
};

void IexWznmVis::ImeitemIRMBoxMBox::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefDstRefWznmMBox << "\t" << orgClk << "\t" << dstClk << "\t" << Weight << endl;
};

void IexWznmVis::ImeitemIRMBoxMBox::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","dst","ocl","dcl","wgt"};
	else tags = {"ImeitemIRMBoxMBox","irefDstRefWznmMBox","orgClk","dstClk","Weight"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefDstRefWznmMBox);
		writeUtinyint(wr, tags[2], orgClk);
		writeUtinyint(wr, tags[3], dstClk);
		writeUtinyint(wr, tags[4], Weight);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmVis::ImeIRMBoxMBox::VecWIel
 ******************************************************************************/

uint IexWznmVis::ImeIRMBoxMBox::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefdstrefwznmmbox") ix |= IREFDSTREFWZNMMBOX;
		else if (ss[i] == "orgclk") ix |= ORGCLK;
		else if (ss[i] == "dstclk") ix |= DSTCLK;
		else if (ss[i] == "weight") ix |= WEIGHT;
	};

	return(ix);
};

void IexWznmVis::ImeIRMBoxMBox::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*WEIGHT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmVis::ImeIRMBoxMBox::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFDSTREFWZNMMBOX) ss.push_back("irefDstRefWznmMBox");
	if (ix & ORGCLK) ss.push_back("orgClk");
	if (ix & DSTCLK) ss.push_back("dstClk");
	if (ix & WEIGHT) ss.push_back("Weight");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmVis::ImeIRMBoxMBox
 ******************************************************************************/

IexWznmVis::ImeIRMBoxMBox::ImeIRMBoxMBox() {
};

IexWznmVis::ImeIRMBoxMBox::~ImeIRMBoxMBox() {
	clear();
};

void IexWznmVis::ImeIRMBoxMBox::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmVis::ImeIRMBoxMBox::readTxt(
			Txtrd& txtrd
		) {
	IexWznmVis::ImeitemIRMBoxMBox* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmVis::ImeitemIRMBoxMBox();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMBoxMBox"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMBoxMBox"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMBOXMBOX) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMBoxMBox"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMBoxMBox"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmVis::ImeIRMBoxMBox::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmVis::ImeitemIRMBoxMBox* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMBoxMBox");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMBoxMBox", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMBoxMBox";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmVis::ImeitemIRMBoxMBox();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmVis::ImeIRMBoxMBox::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMBoxMBox." << StrMod::replaceChar(ImeIRMBoxMBox::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMBoxMBox.end" << endl;
	};
};

void IexWznmVis::ImeIRMBoxMBox::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMBoxMBox");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmVis::ImeitemIMBox
 ******************************************************************************/

IexWznmVis::ImeitemIMBox::ImeitemIMBox(
			const ubigint iref
			, const uint unvIxWznmVMaintable
			, const string& srefUnvUref
			, const smallint x
			, const smallint y
		) : WznmMBox() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->unvIxWznmVMaintable = unvIxWznmVMaintable;
	this->srefUnvUref = srefUnvUref;
	this->x = x;
	this->y = y;
};

IexWznmVis::ImeitemIMBox::ImeitemIMBox(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMBox()
		{
	WznmMBox* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmbox->loadRecByRef(ref, &rec)) {
		refWznmMSheet = rec->refWznmMSheet;
		unvIxWznmVMaintable = rec->unvIxWznmVMaintable;
		unvUref = rec->unvUref;
		x = rec->x;
		y = rec->y;

		delete rec;
	};
};

void IexWznmVis::ImeitemIMBox::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMBox::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {srefUnvIxWznmVMaintable = txtrd.fields[1]; ixWIelValid += ImeIMBox::VecWIel::SREFUNVIXWZNMVMAINTABLE;};
	if (txtrd.fields.size() > 2) {srefUnvUref = txtrd.fields[2]; ixWIelValid += ImeIMBox::VecWIel::SREFUNVUREF;};
	if (txtrd.fields.size() > 3) {x = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIMBox::VecWIel::X;};
	if (txtrd.fields.size() > 4) {y = atoi(txtrd.fields[4].c_str()); ixWIelValid += ImeIMBox::VecWIel::Y;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMBOXMBOX)) {
					imeirmboxmbox.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBox"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmVis::ImeitemIMBox::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMBox::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefUnvIxWznmVMaintable", "mtb", srefUnvIxWznmVMaintable)) ixWIelValid += ImeIMBox::VecWIel::SREFUNVIXWZNMVMAINTABLE;
		if (extractStringUclc(docctx, basexpath, "srefUnvUref", "unv", srefUnvUref)) ixWIelValid += ImeIMBox::VecWIel::SREFUNVUREF;
		if (extractSmallintUclc(docctx, basexpath, "x", "x", x)) ixWIelValid += ImeIMBox::VecWIel::X;
		if (extractSmallintUclc(docctx, basexpath, "y", "y", y)) ixWIelValid += ImeIMBox::VecWIel::Y;
		imeirmboxmbox.readXML(docctx, basexpath);
	};
};

void IexWznmVis::ImeitemIMBox::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << "\t" << VecWznmVMaintable::getSref(unvIxWznmVMaintable) << "\t" << srefUnvUref << "\t" << x << "\t" << y << endl;
	imeirmboxmbox.writeTxt(outfile);
};

void IexWznmVis::ImeitemIMBox::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","mtb","unv","x","y"};
	else tags = {"ImeitemIMBox","iref","srefUnvIxWznmVMaintable","srefUnvUref","x","y"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], VecWznmVMaintable::getSref(unvIxWznmVMaintable));
		writeString(wr, tags[3], srefUnvUref);
		writeSmallint(wr, tags[4], x);
		writeSmallint(wr, tags[5], y);
		imeirmboxmbox.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmVis::ImeIMBox::VecWIel
 ******************************************************************************/

uint IexWznmVis::ImeIMBox::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefunvixwznmvmaintable") ix |= SREFUNVIXWZNMVMAINTABLE;
		else if (ss[i] == "srefunvuref") ix |= SREFUNVUREF;
		else if (ss[i] == "x") ix |= X;
		else if (ss[i] == "y") ix |= Y;
	};

	return(ix);
};

void IexWznmVis::ImeIMBox::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*Y); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmVis::ImeIMBox::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFUNVIXWZNMVMAINTABLE) ss.push_back("srefUnvIxWznmVMaintable");
	if (ix & SREFUNVUREF) ss.push_back("srefUnvUref");
	if (ix & X) ss.push_back("x");
	if (ix & Y) ss.push_back("y");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmVis::ImeIMBox
 ******************************************************************************/

IexWznmVis::ImeIMBox::ImeIMBox() {
};

IexWznmVis::ImeIMBox::~ImeIMBox() {
	clear();
};

void IexWznmVis::ImeIMBox::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmVis::ImeIMBox::readTxt(
			Txtrd& txtrd
		) {
	IexWznmVis::ImeitemIMBox* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmVis::ImeitemIMBox();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBox"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBox"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMBOX) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBox"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBox"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmVis::ImeIMBox::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmVis::ImeitemIMBox* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMBox");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMBox", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMBox";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmVis::ImeitemIMBox();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmVis::ImeIMBox::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBox." << StrMod::replaceChar(ImeIMBox::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBox.end" << endl;
	};
};

void IexWznmVis::ImeIMBox::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMBox");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmVis::ImeitemIMSheet
 ******************************************************************************/

IexWznmVis::ImeitemIMSheet::ImeitemIMSheet(
			const string& Title
		) : WznmMSheet() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
};

IexWznmVis::ImeitemIMSheet::ImeitemIMSheet(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSheet()
		{
	WznmMSheet* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmsheet->loadRecByRef(ref, &rec)) {
		visRefWznmMVisual = rec->visRefWznmMVisual;
		visNum = rec->visNum;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmVis::ImeitemIMSheet::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIMSheet::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBOX)) {
					imeimbox.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSheet"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmVis::ImeitemIMSheet::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMSheet::VecWIel::TITLE;
		imeimbox.readXML(docctx, basexpath);
	};
};

void IexWznmVis::ImeitemIMSheet::writeTxt(
			fstream& outfile
		) {
	outfile << Title << endl;
	imeimbox.writeTxt(outfile);
};

void IexWznmVis::ImeitemIMSheet::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit"};
	else tags = {"ImeitemIMSheet","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		imeimbox.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmVis::ImeIMSheet::VecWIel
 ******************************************************************************/

uint IexWznmVis::ImeIMSheet::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmVis::ImeIMSheet::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmVis::ImeIMSheet::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmVis::ImeIMSheet
 ******************************************************************************/

IexWznmVis::ImeIMSheet::ImeIMSheet() {
};

IexWznmVis::ImeIMSheet::~ImeIMSheet() {
	clear();
};

void IexWznmVis::ImeIMSheet::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmVis::ImeIMSheet::readTxt(
			Txtrd& txtrd
		) {
	IexWznmVis::ImeitemIMSheet* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmVis::ImeitemIMSheet();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSheet"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSHEET) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSheet"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSheet"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmVis::ImeIMSheet::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmVis::ImeitemIMSheet* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSheet");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSheet", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSheet";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmVis::ImeitemIMSheet();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmVis::ImeIMSheet::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMSheet." << StrMod::replaceChar(ImeIMSheet::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMSheet.end" << endl;
	};
};

void IexWznmVis::ImeIMSheet::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSheet");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmVis
 ******************************************************************************/

void IexWznmVis::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMSheet& imeimsheet
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimsheet);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmVis", Version("1.1.13"), VecVIme::getIx);
			readTxt(rd, imeimsheet);
	};
};

void IexWznmVis::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMSheet& imeimsheet
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimsheet);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimsheet);
		txtfile.close();
	};
};

void IexWznmVis::readTxt(
			Txtrd& txtrd
			, ImeIMSheet& imeimsheet
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMSHEET)) imeimsheet.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmVis::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMSheet& imeimsheet
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmVis")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.13")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.13"}});
		};

		// look for XML sub-blocks
		imeimsheet.readXML(docctx, basexpath);

	} else {
		imeimsheet = ImeIMSheet();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmVis"}});
	};
};

void IexWznmVis::writeTxt(
			fstream& outfile
			, ImeIMSheet& imeimsheet
		) {
	outfile << "IexWznmVis v" WZNM_VERSION << endl;

	imeimsheet.writeTxt(outfile);
};

void IexWznmVis::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMSheet& imeimsheet
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmVis");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimsheet.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmVis::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIMBOX,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSHEET,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMBOXMBOX,VecWznmVIop::INS}};
};

uint IexWznmVis::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};
