/**
	* \file IexWznmIex.cpp
	* data blocks and readers/writers for import/export complex IexWznmIex (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "IexWznmIex.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmIex::VecVIme
 ******************************************************************************/

uint IexWznmIex::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeijmimpexpcolstub") return IMEIJMIMPEXPCOLSTUB;
	if (s == "imeijmimpexpcplxtitle") return IMEIJMIMPEXPCPLXTITLE;
	if (s == "imeimimpexp") return IMEIMIMPEXP;
	if (s == "imeimimpexpcol") return IMEIMIMPEXPCOL;
	if (s == "imeimimpexpcplx") return IMEIMIMPEXPCPLX;

	return(0);
};

string IexWznmIex::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIJMIMPEXPCOLSTUB) return("ImeIJMImpexpcolStub");
	if (ix == IMEIJMIMPEXPCPLXTITLE) return("ImeIJMImpexpcplxTitle");
	if (ix == IMEIMIMPEXP) return("ImeIMImpexp");
	if (ix == IMEIMIMPEXPCOL) return("ImeIMImpexpcol");
	if (ix == IMEIMIMPEXPCPLX) return("ImeIMImpexpcplx");

	return("");
};

/******************************************************************************
 class IexWznmIex::ImeitemIJMImpexpcplxTitle
 ******************************************************************************/

IexWznmIex::ImeitemIJMImpexpcplxTitle::ImeitemIJMImpexpcplxTitle(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMImpexpcplxTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmIex::ImeitemIJMImpexpcplxTitle::ImeitemIJMImpexpcplxTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMImpexpcplxTitle()
		{
	WznmJMImpexpcplxTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmimpexpcplxtitle->loadRecByRef(ref, &rec)) {
		refWznmMImpexpcplx = rec->refWznmMImpexpcplx;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIex::ImeitemIJMImpexpcplxTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMImpexpcplxTitle::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMImpexpcplxTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMImpexpcplxTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIex::ImeitemIJMImpexpcplxTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMImpexpcplxTitle::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMImpexpcplxTitle::VecWIel::TITLE;
	};
};

void IexWznmIex::ImeitemIJMImpexpcplxTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmIex::ImeitemIJMImpexpcplxTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMImpexpcplxTitle","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIex::ImeIJMImpexpcplxTitle::VecWIel
 ******************************************************************************/

uint IexWznmIex::ImeIJMImpexpcplxTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmIex::ImeIJMImpexpcplxTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIex::ImeIJMImpexpcplxTitle::VecWIel::getSrefs(
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
 class IexWznmIex::ImeIJMImpexpcplxTitle
 ******************************************************************************/

IexWznmIex::ImeIJMImpexpcplxTitle::ImeIJMImpexpcplxTitle() {
};

IexWznmIex::ImeIJMImpexpcplxTitle::~ImeIJMImpexpcplxTitle() {
	clear();
};

void IexWznmIex::ImeIJMImpexpcplxTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIex::ImeIJMImpexpcplxTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIex::ImeitemIJMImpexpcplxTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIex::ImeitemIJMImpexpcplxTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMImpexpcplxTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMImpexpcplxTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMIMPEXPCPLXTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMImpexpcplxTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMImpexpcplxTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIex::ImeIJMImpexpcplxTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIex::ImeitemIJMImpexpcplxTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMImpexpcplxTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMImpexpcplxTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMImpexpcplxTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIex::ImeitemIJMImpexpcplxTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIex::ImeIJMImpexpcplxTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMImpexpcplxTitle." << StrMod::replaceChar(ImeIJMImpexpcplxTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMImpexpcplxTitle.end" << endl;
	};
};

void IexWznmIex::ImeIJMImpexpcplxTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMImpexpcplxTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIex::ImeitemIJMImpexpcolStub
 ******************************************************************************/

IexWznmIex::ImeitemIJMImpexpcolStub::ImeitemIJMImpexpcolStub(
			const string& srefX1RefWznmMVectoritem
			, const string& srefRefWznmMStub
		) : WznmJMImpexpcolStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMVectoritem = srefX1RefWznmMVectoritem;
	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmIex::ImeitemIJMImpexpcolStub::ImeitemIJMImpexpcolStub(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMImpexpcolStub()
		{
	WznmJMImpexpcolStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmimpexpcolstub->loadRecByRef(ref, &rec)) {
		refWznmMImpexpcol = rec->refWznmMImpexpcol;
		x1RefWznmMVectoritem = rec->x1RefWznmMVectoritem;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmIex::ImeitemIJMImpexpcolStub::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMVectoritem = txtrd.fields[0]; ixWIelValid += ImeIJMImpexpcolStub::VecWIel::SREFX1REFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 1) {srefRefWznmMStub = txtrd.fields[1]; ixWIelValid += ImeIJMImpexpcolStub::VecWIel::SREFREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMImpexpcolStub"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIex::ImeitemIJMImpexpcolStub::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMVectoritem", "vit", srefX1RefWznmMVectoritem)) ixWIelValid += ImeIJMImpexpcolStub::VecWIel::SREFX1REFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIJMImpexpcolStub::VecWIel::SREFREFWZNMMSTUB;
	};
};

void IexWznmIex::ImeitemIJMImpexpcolStub::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMVectoritem << "\t" << srefRefWznmMStub << endl;
};

void IexWznmIex::ImeitemIJMImpexpcolStub::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vit","stb"};
	else tags = {"ImeitemIJMImpexpcolStub","srefX1RefWznmMVectoritem","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMVectoritem);
		writeString(wr, tags[2], srefRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIex::ImeIJMImpexpcolStub::VecWIel
 ******************************************************************************/

uint IexWznmIex::ImeIJMImpexpcolStub::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmvectoritem") ix |= SREFX1REFWZNMMVECTORITEM;
		else if (ss[i] == "srefrefwznmmstub") ix |= SREFREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmIex::ImeIJMImpexpcolStub::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIex::ImeIJMImpexpcolStub::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMVECTORITEM) ss.push_back("srefX1RefWznmMVectoritem");
	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIex::ImeIJMImpexpcolStub
 ******************************************************************************/

IexWznmIex::ImeIJMImpexpcolStub::ImeIJMImpexpcolStub() {
};

IexWznmIex::ImeIJMImpexpcolStub::~ImeIJMImpexpcolStub() {
	clear();
};

void IexWznmIex::ImeIJMImpexpcolStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIex::ImeIJMImpexpcolStub::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIex::ImeitemIJMImpexpcolStub* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmIex::ImeitemIJMImpexpcolStub();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMImpexpcolStub"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMImpexpcolStub"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMIMPEXPCOLSTUB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMImpexpcolStub"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMImpexpcolStub"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIex::ImeIJMImpexpcolStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIex::ImeitemIJMImpexpcolStub* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMImpexpcolStub");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMImpexpcolStub", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMImpexpcolStub";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIex::ImeitemIJMImpexpcolStub();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIex::ImeIJMImpexpcolStub::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMImpexpcolStub." << StrMod::replaceChar(ImeIJMImpexpcolStub::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMImpexpcolStub.end" << endl;
	};
};

void IexWznmIex::ImeIJMImpexpcolStub::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMImpexpcolStub");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIex::ImeitemIMImpexpcol
 ******************************************************************************/

IexWznmIex::ImeitemIMImpexpcol::ImeitemIMImpexpcol(
			const uint ixVBasetype
			, const uint ixWOccurrence
			, const string& srefRefWznmMTablecol
			, const string& sref
			, const string& Short
			, const ubigint irefRefWznmMImpexp
			, const uint ixVConvtype
			, const string& Defval
			, const string& srefRefWznmMPreset
			, const string& srefRefWznmMStub
			, const string& srefRefWznmMVectoritem
		) : WznmMImpexpcol() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->ixWOccurrence = ixWOccurrence;
	this->srefRefWznmMTablecol = srefRefWznmMTablecol;
	this->sref = sref;
	this->Short = Short;
	this->irefRefWznmMImpexp = irefRefWznmMImpexp;
	this->ixVConvtype = ixVConvtype;
	this->Defval = Defval;
	this->srefRefWznmMPreset = srefRefWznmMPreset;
	this->srefRefWznmMStub = srefRefWznmMStub;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmIex::ImeitemIMImpexpcol::ImeitemIMImpexpcol(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMImpexpcol()
		{
	WznmMImpexpcol* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmimpexpcol->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		ixWOccurrence = rec->ixWOccurrence;
		imeRefWznmMImpexp = rec->imeRefWznmMImpexp;
		imeNum = rec->imeNum;
		refWznmMTablecol = rec->refWznmMTablecol;
		sref = rec->sref;
		Short = rec->Short;
		refWznmMImpexp = rec->refWznmMImpexp;
		ixVConvtype = rec->ixVConvtype;
		Defval = rec->Defval;
		refWznmMPreset = rec->refWznmMPreset;
		refJStub = rec->refJStub;
		refWznmMStub = rec->refWznmMStub;
		refWznmMVectoritem = rec->refWznmMVectoritem;

		delete rec;
	};
};

void IexWznmIex::ImeitemIMImpexpcol::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefsIxWOccurrence = txtrd.fields[1]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFSIXWOCCURRENCE;};
	if (txtrd.fields.size() > 2) {srefRefWznmMTablecol = txtrd.fields[2]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMTABLECOL;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Short = txtrd.fields[4]; ixWIelValid += ImeIMImpexpcol::VecWIel::SHORT;};
	if (txtrd.fields.size() > 5) {irefRefWznmMImpexp = atoll(txtrd.fields[5].c_str()); ixWIelValid += ImeIMImpexpcol::VecWIel::IREFREFWZNMMIMPEXP;};
	if (txtrd.fields.size() > 6) {srefIxVConvtype = txtrd.fields[6]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFIXVCONVTYPE;};
	if (txtrd.fields.size() > 7) {Defval = txtrd.fields[7]; ixWIelValid += ImeIMImpexpcol::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 8) {srefRefWznmMPreset = txtrd.fields[8]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMPRESET;};
	if (txtrd.fields.size() > 9) {srefRefWznmMStub = txtrd.fields[9]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMSTUB;};
	if (txtrd.fields.size() > 10) {srefRefWznmMVectoritem = txtrd.fields[10]; ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMVECTORITEM;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMIMPEXPCOLSTUB)) {
					imeijmimpexpcolstub.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImpexpcol"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIex::ImeitemIMImpexpcol::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefsIxWOccurrence", "occ", srefsIxWOccurrence)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFSIXWOCCURRENCE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTablecol", "tco", srefRefWznmMTablecol)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMImpexpcol::VecWIel::SHORT;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmMImpexp", "ime", irefRefWznmMImpexp)) ixWIelValid += ImeIMImpexpcol::VecWIel::IREFREFWZNMMIMPEXP;
		if (extractStringUclc(docctx, basexpath, "srefIxVConvtype", "cty", srefIxVConvtype)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFIXVCONVTYPE;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIMImpexpcol::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMPreset", "pst", srefRefWznmMPreset)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMPRESET;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIMImpexpcol::VecWIel::SREFREFWZNMMVECTORITEM;
		imeijmimpexpcolstub.readXML(docctx, basexpath);
	};
};

void IexWznmIex::ImeitemIMImpexpcol::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVMImpexpcolBasetype::getSref(ixVBasetype) << "\t" << VecWznmWMImpexpcolOccurrence::getSrefs(ixWOccurrence) << "\t" << srefRefWznmMTablecol << "\t" << sref << "\t" << Short << "\t" << irefRefWznmMImpexp << "\t" << VecWznmVMImpexpcolConvtype::getSref(ixVConvtype) << "\t" << Defval << "\t" << srefRefWznmMPreset << "\t" << srefRefWznmMStub << "\t" << srefRefWznmMVectoritem << endl;
	imeijmimpexpcolstub.writeTxt(outfile);
};

void IexWznmIex::ImeitemIMImpexpcol::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","occ","tco","srf","sho","ime","cty","dfv","pst","stb","vit"};
	else tags = {"ImeitemIMImpexpcol","srefIxVBasetype","srefsIxWOccurrence","srefRefWznmMTablecol","sref","Short","irefRefWznmMImpexp","srefIxVConvtype","Defval","srefRefWznmMPreset","srefRefWznmMStub","srefRefWznmMVectoritem"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMImpexpcolBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], VecWznmWMImpexpcolOccurrence::getSrefs(ixWOccurrence));
		writeString(wr, tags[3], srefRefWznmMTablecol);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Short);
		writeUbigint(wr, tags[6], irefRefWznmMImpexp);
		writeString(wr, tags[7], VecWznmVMImpexpcolConvtype::getSref(ixVConvtype));
		writeString(wr, tags[8], Defval);
		writeString(wr, tags[9], srefRefWznmMPreset);
		writeString(wr, tags[10], srefRefWznmMStub);
		writeString(wr, tags[11], srefRefWznmMVectoritem);
		imeijmimpexpcolstub.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIex::ImeIMImpexpcol::VecWIel
 ******************************************************************************/

uint IexWznmIex::ImeIMImpexpcol::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefsixwoccurrence") ix |= SREFSIXWOCCURRENCE;
		else if (ss[i] == "srefrefwznmmtablecol") ix |= SREFREFWZNMMTABLECOL;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "irefrefwznmmimpexp") ix |= IREFREFWZNMMIMPEXP;
		else if (ss[i] == "srefixvconvtype") ix |= SREFIXVCONVTYPE;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmpreset") ix |= SREFREFWZNMMPRESET;
		else if (ss[i] == "srefrefwznmmstub") ix |= SREFREFWZNMMSTUB;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
	};

	return(ix);
};

void IexWznmIex::ImeIMImpexpcol::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIex::ImeIMImpexpcol::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFSIXWOCCURRENCE) ss.push_back("srefsIxWOccurrence");
	if (ix & SREFREFWZNMMTABLECOL) ss.push_back("srefRefWznmMTablecol");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & IREFREFWZNMMIMPEXP) ss.push_back("irefRefWznmMImpexp");
	if (ix & SREFIXVCONVTYPE) ss.push_back("srefIxVConvtype");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & SREFREFWZNMMPRESET) ss.push_back("srefRefWznmMPreset");
	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIex::ImeIMImpexpcol
 ******************************************************************************/

IexWznmIex::ImeIMImpexpcol::ImeIMImpexpcol() {
};

IexWznmIex::ImeIMImpexpcol::~ImeIMImpexpcol() {
	clear();
};

void IexWznmIex::ImeIMImpexpcol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIex::ImeIMImpexpcol::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIex::ImeitemIMImpexpcol* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmIex::ImeitemIMImpexpcol();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexpcol"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImpexpcol"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMIMPEXPCOL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexpcol"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexpcol"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIex::ImeIMImpexpcol::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIex::ImeitemIMImpexpcol* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMImpexpcol");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMImpexpcol", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMImpexpcol";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIex::ImeitemIMImpexpcol();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIex::ImeIMImpexpcol::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMImpexpcol." << StrMod::replaceChar(ImeIMImpexpcol::VecWIel::getSrefs(2047), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMImpexpcol.end" << endl;
	};
};

void IexWznmIex::ImeIMImpexpcol::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMImpexpcol");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIex::ImeitemIMImpexp
 ******************************************************************************/

IexWznmIex::ImeitemIMImpexp::ImeitemIMImpexp(
			const ubigint iref
			, const ubigint irefSupRefWznmMImpexp
			, const string& srefRefWznmMTable
			, const string& sref
			, const string& rtrSrefsWznmMImpexpcol
			, const uint ixWIop
			, const string& Comment
		) : WznmMImpexp() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->irefSupRefWznmMImpexp = irefSupRefWznmMImpexp;
	this->srefRefWznmMTable = srefRefWznmMTable;
	this->sref = sref;
	this->rtrSrefsWznmMImpexpcol = rtrSrefsWznmMImpexpcol;
	this->ixWIop = ixWIop;
	this->Comment = Comment;
};

IexWznmIex::ImeitemIMImpexp::ImeitemIMImpexp(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMImpexp()
		{
	WznmMImpexp* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmimpexp->loadRecByRef(ref, &rec)) {
		refWznmMImpexpcplx = rec->refWznmMImpexpcplx;
		supRefWznmMImpexp = rec->supRefWznmMImpexp;
		refWznmMTable = rec->refWznmMTable;
		sref = rec->sref;
		rtrSrefsWznmMImpexpcol = rec->rtrSrefsWznmMImpexpcol;
		ixWIop = rec->ixWIop;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIex::ImeitemIMImpexp::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMImpexp::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {irefSupRefWznmMImpexp = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMImpexp::VecWIel::IREFSUPREFWZNMMIMPEXP;};
	if (txtrd.fields.size() > 2) {srefRefWznmMTable = txtrd.fields[2]; ixWIelValid += ImeIMImpexp::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMImpexp::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {rtrSrefsWznmMImpexpcol = txtrd.fields[4]; ixWIelValid += ImeIMImpexp::VecWIel::RTRSREFSWZNMMIMPEXPCOL;};
	if (txtrd.fields.size() > 5) {srefsIxWIop = txtrd.fields[5]; ixWIelValid += ImeIMImpexp::VecWIel::SREFSIXWIOP;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMImpexp::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMIMPEXPCOL)) {
					imeimimpexpcol.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImpexp"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIex::ImeitemIMImpexp::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMImpexp::VecWIel::IREF;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefWznmMImpexp", "sup", irefSupRefWznmMImpexp)) ixWIelValid += ImeIMImpexp::VecWIel::IREFSUPREFWZNMMIMPEXP;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIMImpexp::VecWIel::SREFREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMImpexp::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "rtrSrefsWznmMImpexpcol", "rtr", rtrSrefsWznmMImpexpcol)) ixWIelValid += ImeIMImpexp::VecWIel::RTRSREFSWZNMMIMPEXPCOL;
		if (extractStringUclc(docctx, basexpath, "srefsIxWIop", "iop", srefsIxWIop)) ixWIelValid += ImeIMImpexp::VecWIel::SREFSIXWIOP;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMImpexp::VecWIel::COMMENT;
		imeimimpexpcol.readXML(docctx, basexpath);
	};
};

void IexWznmIex::ImeitemIMImpexp::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << "\t" << irefSupRefWznmMImpexp << "\t" << srefRefWznmMTable << "\t" << sref << "\t" << rtrSrefsWznmMImpexpcol << "\t" << VecWznmWMImpexpIop::getSrefs(ixWIop) << "\t" << Comment << endl;
	imeimimpexpcol.writeTxt(outfile);
};

void IexWznmIex::ImeitemIMImpexp::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","sup","tbl","srf","rtr","iop","cmt"};
	else tags = {"ImeitemIMImpexp","iref","irefSupRefWznmMImpexp","srefRefWznmMTable","sref","rtrSrefsWznmMImpexpcol","srefsIxWIop","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeUbigint(wr, tags[2], irefSupRefWznmMImpexp);
		writeString(wr, tags[3], srefRefWznmMTable);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], rtrSrefsWznmMImpexpcol);
		writeString(wr, tags[6], VecWznmWMImpexpIop::getSrefs(ixWIop));
		writeString(wr, tags[7], Comment);
		imeimimpexpcol.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIex::ImeIMImpexp::VecWIel
 ******************************************************************************/

uint IexWznmIex::ImeIMImpexp::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "irefsuprefwznmmimpexp") ix |= IREFSUPREFWZNMMIMPEXP;
		else if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "rtrsrefswznmmimpexpcol") ix |= RTRSREFSWZNMMIMPEXPCOL;
		else if (ss[i] == "srefsixwiop") ix |= SREFSIXWIOP;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIex::ImeIMImpexp::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIex::ImeIMImpexp::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & IREFSUPREFWZNMMIMPEXP) ss.push_back("irefSupRefWznmMImpexp");
	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & SREF) ss.push_back("sref");
	if (ix & RTRSREFSWZNMMIMPEXPCOL) ss.push_back("rtrSrefsWznmMImpexpcol");
	if (ix & SREFSIXWIOP) ss.push_back("srefsIxWIop");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIex::ImeIMImpexp
 ******************************************************************************/

IexWznmIex::ImeIMImpexp::ImeIMImpexp() {
};

IexWznmIex::ImeIMImpexp::~ImeIMImpexp() {
	clear();
};

void IexWznmIex::ImeIMImpexp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIex::ImeIMImpexp::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIex::ImeitemIMImpexp* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIex::ImeitemIMImpexp();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexp"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImpexp"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMIMPEXP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexp"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexp"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIex::ImeIMImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIex::ImeitemIMImpexp* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMImpexp");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMImpexp", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMImpexp";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIex::ImeitemIMImpexp();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIex::ImeIMImpexp::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMImpexp." << StrMod::replaceChar(ImeIMImpexp::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMImpexp.end" << endl;
	};
};

void IexWznmIex::ImeIMImpexp::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMImpexp");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIex::ImeitemIMImpexpcplx
 ******************************************************************************/

IexWznmIex::ImeitemIMImpexpcplx::ImeitemIMImpexpcplx(
			const string& sref
			, const string& Short
			, const string& Title
			, const string& Minversion
			, const string& Comment
		) : WznmMImpexpcplx() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Short = Short;
	this->Title = Title;
	this->Minversion = Minversion;
	this->Comment = Comment;
};

IexWznmIex::ImeitemIMImpexpcplx::ImeitemIMImpexpcplx(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMImpexpcplx()
		{
	WznmMImpexpcplx* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmimpexpcplx->loadRecByRef(ref, &rec)) {
		refWznmMVersion = rec->refWznmMVersion;
		sref = rec->sref;
		Short = rec->Short;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		Minversion = rec->Minversion;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIex::ImeitemIMImpexpcplx::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMImpexpcplx::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Short = txtrd.fields[1]; ixWIelValid += ImeIMImpexpcplx::VecWIel::SHORT;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMImpexpcplx::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Minversion = txtrd.fields[3]; ixWIelValid += ImeIMImpexpcplx::VecWIel::MINVERSION;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMImpexpcplx::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMIMPEXPCPLXTITLE)) {
					imeijmimpexpcplxtitle.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMIMPEXP)) {
					imeimimpexp.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImpexpcplx"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIex::ImeitemIMImpexpcplx::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMImpexpcplx::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMImpexpcplx::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMImpexpcplx::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Minversion", "mvr", Minversion)) ixWIelValid += ImeIMImpexpcplx::VecWIel::MINVERSION;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMImpexpcplx::VecWIel::COMMENT;
		imeijmimpexpcplxtitle.readXML(docctx, basexpath);
		imeimimpexp.readXML(docctx, basexpath);
	};
};

void IexWznmIex::ImeitemIMImpexpcplx::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Short << "\t" << Title << "\t" << Minversion << "\t" << Comment << endl;
	imeijmimpexpcplxtitle.writeTxt(outfile);
	imeimimpexp.writeTxt(outfile);
};

void IexWznmIex::ImeitemIMImpexpcplx::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","sho","tit","mvr","cmt"};
	else tags = {"ImeitemIMImpexpcplx","sref","Short","Title","Minversion","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Short);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Minversion);
		writeString(wr, tags[5], Comment);
		imeijmimpexpcplxtitle.writeXML(wr, shorttags);
		imeimimpexp.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIex::ImeIMImpexpcplx::VecWIel
 ******************************************************************************/

uint IexWznmIex::ImeIMImpexpcplx::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "minversion") ix |= MINVERSION;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIex::ImeIMImpexpcplx::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIex::ImeIMImpexpcplx::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & MINVERSION) ss.push_back("Minversion");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIex::ImeIMImpexpcplx
 ******************************************************************************/

IexWznmIex::ImeIMImpexpcplx::ImeIMImpexpcplx() {
};

IexWznmIex::ImeIMImpexpcplx::~ImeIMImpexpcplx() {
	clear();
};

void IexWznmIex::ImeIMImpexpcplx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIex::ImeIMImpexpcplx::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIex::ImeitemIMImpexpcplx* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIex::ImeitemIMImpexpcplx();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImpexpcplx"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMIMPEXPCPLX) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexpcplx"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImpexpcplx"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIex::ImeIMImpexpcplx::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIex::ImeitemIMImpexpcplx* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMImpexpcplx");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMImpexpcplx", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMImpexpcplx";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIex::ImeitemIMImpexpcplx();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIex::ImeIMImpexpcplx::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMImpexpcplx." << StrMod::replaceChar(ImeIMImpexpcplx::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMImpexpcplx.end" << endl;
	};
};

void IexWznmIex::ImeIMImpexpcplx::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMImpexpcplx");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmIex
 ******************************************************************************/

void IexWznmIex::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIMImpexpcplx& imeimimpexpcplx
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimimpexpcplx);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmIex", Version("0.9.23"), VecVIme::getIx);
			readTxt(rd, imeimimpexpcplx);
	};
};

void IexWznmIex::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMImpexpcplx& imeimimpexpcplx
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimimpexpcplx);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimimpexpcplx);
		txtfile.close();
	};
};

void IexWznmIex::readTxt(
			Txtrd& txtrd
			, ImeIMImpexpcplx& imeimimpexpcplx
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMIMPEXPCPLX)) imeimimpexpcplx.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmIex::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMImpexpcplx& imeimimpexpcplx
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmIex")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.23")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.23"}});
		};

		// look for XML sub-blocks
		imeimimpexpcplx.readXML(docctx, basexpath);

	} else {
		imeimimpexpcplx = ImeIMImpexpcplx();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmIex"}});
	};
};

void IexWznmIex::writeTxt(
			fstream& outfile
			, ImeIMImpexpcplx& imeimimpexpcplx
		) {
	outfile << "IexWznmIex v" WZNM_VERSION << endl;

	imeimimpexpcplx.writeTxt(outfile);
};

void IexWznmIex::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMImpexpcplx& imeimimpexpcplx
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmIex");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimimpexpcplx.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmIex::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIJMIMPEXPCOLSTUB,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMIMPEXPCPLXTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMIMPEXP,VecWznmVIop::INS},{(uint)VecVIme::IMEIMIMPEXPCOL,VecWznmVIop::INS},{(uint)VecVIme::IMEIMIMPEXPCPLX,VecWznmVIop::INS}};
};

uint IexWznmIex::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};

