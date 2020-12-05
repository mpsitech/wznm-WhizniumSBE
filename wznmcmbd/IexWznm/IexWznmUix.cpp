/**
	* \file IexWznmUix.cpp
	* data blocks and readers/writers for import/export complex IexWznmUix (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWznmUix.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmUix::VecVIme
 ******************************************************************************/

uint IexWznmUix::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamcontrolpar1") return IMEIAMCONTROLPAR1;
	if (s == "imeiamcontrolpar2") return IMEIAMCONTROLPAR2;
	if (s == "imeiamcontrolpar3") return IMEIAMCONTROLPAR3;
	if (s == "imeiamqueryclause") return IMEIAMQUERYCLAUSE;
	if (s == "imeiamqueryorder") return IMEIAMQUERYORDER;
	if (s == "imeiccontrol2") return IMEICCONTROL2;
	if (s == "imeiccontrol3") return IMEICCONTROL3;
	if (s == "imeijmcontrol2") return IMEIJMCONTROL2;
	if (s == "imeijmcontrol3") return IMEIJMCONTROL3;
	if (s == "imeijmcontroltitle1") return IMEIJMCONTROLTITLE1;
	if (s == "imeijmcontroltitle2") return IMEIJMCONTROLTITLE2;
	if (s == "imeijmcontroltitle3") return IMEIJMCONTROLTITLE3;
	if (s == "imeijmpresettitle") return IMEIJMPRESETTITLE;
	if (s == "imeijmquerycolstub") return IMEIJMQUERYCOLSTUB;
	if (s == "imeimcard") return IMEIMCARD;
	if (s == "imeimcontrol1") return IMEIMCONTROL1;
	if (s == "imeimcontrol2") return IMEIMCONTROL2;
	if (s == "imeimcontrol3") return IMEIMCONTROL3;
	if (s == "imeimdialog") return IMEIMDIALOG;
	if (s == "imeimfeed2") return IMEIMFEED2;
	if (s == "imeimfeed3") return IMEIMFEED3;
	if (s == "imeimpanel") return IMEIMPANEL;
	if (s == "imeimpreset") return IMEIMPRESET;
	if (s == "imeimquery") return IMEIMQUERY;
	if (s == "imeimquerycol") return IMEIMQUERYCOL;
	if (s == "imeimquerymod") return IMEIMQUERYMOD;
	if (s == "imeimvector2") return IMEIMVECTOR2;
	if (s == "imeimvector3") return IMEIMVECTOR3;
	if (s == "imeirmpanelmquery") return IMEIRMPANELMQUERY;
	if (s == "imeirmquerymtable") return IMEIRMQUERYMTABLE;
	if (s == "imeitmquerymodmquery") return IMEITMQUERYMODMQUERY;

	return(0);
};

string IexWznmUix::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMCONTROLPAR1) return("ImeIAMControlPar1");
	if (ix == IMEIAMCONTROLPAR2) return("ImeIAMControlPar2");
	if (ix == IMEIAMCONTROLPAR3) return("ImeIAMControlPar3");
	if (ix == IMEIAMQUERYCLAUSE) return("ImeIAMQueryClause");
	if (ix == IMEIAMQUERYORDER) return("ImeIAMQueryOrder");
	if (ix == IMEICCONTROL2) return("ImeICControl2");
	if (ix == IMEICCONTROL3) return("ImeICControl3");
	if (ix == IMEIJMCONTROL2) return("ImeIJMControl2");
	if (ix == IMEIJMCONTROL3) return("ImeIJMControl3");
	if (ix == IMEIJMCONTROLTITLE1) return("ImeIJMControlTitle1");
	if (ix == IMEIJMCONTROLTITLE2) return("ImeIJMControlTitle2");
	if (ix == IMEIJMCONTROLTITLE3) return("ImeIJMControlTitle3");
	if (ix == IMEIJMPRESETTITLE) return("ImeIJMPresetTitle");
	if (ix == IMEIJMQUERYCOLSTUB) return("ImeIJMQuerycolStub");
	if (ix == IMEIMCARD) return("ImeIMCard");
	if (ix == IMEIMCONTROL1) return("ImeIMControl1");
	if (ix == IMEIMCONTROL2) return("ImeIMControl2");
	if (ix == IMEIMCONTROL3) return("ImeIMControl3");
	if (ix == IMEIMDIALOG) return("ImeIMDialog");
	if (ix == IMEIMFEED2) return("ImeIMFeed2");
	if (ix == IMEIMFEED3) return("ImeIMFeed3");
	if (ix == IMEIMPANEL) return("ImeIMPanel");
	if (ix == IMEIMPRESET) return("ImeIMPreset");
	if (ix == IMEIMQUERY) return("ImeIMQuery");
	if (ix == IMEIMQUERYCOL) return("ImeIMQuerycol");
	if (ix == IMEIMQUERYMOD) return("ImeIMQuerymod");
	if (ix == IMEIMVECTOR2) return("ImeIMVector2");
	if (ix == IMEIMVECTOR3) return("ImeIMVector3");
	if (ix == IMEIRMPANELMQUERY) return("ImeIRMPanelMQuery");
	if (ix == IMEIRMQUERYMTABLE) return("ImeIRMQueryMTable");
	if (ix == IMEITMQUERYMODMQUERY) return("ImeITMQuerymodMQuery");

	return("");
};

/******************************************************************************
 class IexWznmUix::ImeitemIAMControlPar1
 ******************************************************************************/

IexWznmUix::ImeitemIAMControlPar1::ImeitemIAMControlPar1(
			const string& x1SrefKKey
			, const string& srefX2RefWznmMLocale
			, const string& osrefKVal
		) : WznmAMControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->osrefKVal = osrefKVal;
};

IexWznmUix::ImeitemIAMControlPar1::ImeitemIAMControlPar1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMControlPar1()
		{
	WznmAMControlPar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamcontrolpar->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1SrefKKey = rec->x1SrefKKey;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		osrefKVal = rec->osrefKVal;

		delete rec;
	};
};

void IexWznmUix::ImeitemIAMControlPar1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMControlPar1::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMControlPar1::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {osrefKVal = txtrd.fields[2]; ixWIelValid += ImeIAMControlPar1::VecWIel::OSREFKVAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMControlPar1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIAMControlPar1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMControlPar1::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMControlPar1::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "osrefKVal", "val", osrefKVal)) ixWIelValid += ImeIAMControlPar1::VecWIel::OSREFKVAL;
	};
};

void IexWznmUix::ImeitemIAMControlPar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1SrefKKey << "\t" << srefX2RefWznmMLocale << "\t" << osrefKVal << endl;
};

void IexWznmUix::ImeitemIAMControlPar1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","loc","val"};
	else tags = {"ImeitemIAMControlPar1","x1SrefKKey","srefX2RefWznmMLocale","osrefKVal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], osrefKVal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIAMControlPar1::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIAMControlPar1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "srefx2refwznmmlocale") ix |= SREFX2REFWZNMMLOCALE;
		else if (ss[i] == "osrefkval") ix |= OSREFKVAL;
	};

	return(ix);
};

void IexWznmUix::ImeIAMControlPar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*OSREFKVAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIAMControlPar1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & SREFX2REFWZNMMLOCALE) ss.push_back("srefX2RefWznmMLocale");
	if (ix & OSREFKVAL) ss.push_back("osrefKVal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIAMControlPar1
 ******************************************************************************/

IexWznmUix::ImeIAMControlPar1::ImeIAMControlPar1() {
};

IexWznmUix::ImeIAMControlPar1::~ImeIAMControlPar1() {
	clear();
};

void IexWznmUix::ImeIAMControlPar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIAMControlPar1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIAMControlPar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemIAMControlPar1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMControlPar1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCONTROLPAR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIAMControlPar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIAMControlPar1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMControlPar1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMControlPar1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMControlPar1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIAMControlPar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIAMControlPar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMControlPar1." << StrMod::replaceChar(ImeIAMControlPar1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMControlPar1.end" << endl;
	};
};

void IexWznmUix::ImeIAMControlPar1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMControlPar1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIJMControlTitle1
 ******************************************************************************/

IexWznmUix::ImeitemIJMControlTitle1::ImeitemIJMControlTitle1(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMControlTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmUix::ImeitemIJMControlTitle1::ImeitemIJMControlTitle1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMControlTitle1()
		{
	WznmJMControlTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmcontroltitle->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMControlTitle1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMControlTitle1::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMControlTitle1::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControlTitle1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMControlTitle1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMControlTitle1::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMControlTitle1::VecWIel::TITLE;
	};
};

void IexWznmUix::ImeitemIJMControlTitle1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmUix::ImeitemIJMControlTitle1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMControlTitle1","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControlTitle1::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMControlTitle1::VecWIel::getIx(
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

void IexWznmUix::ImeIJMControlTitle1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMControlTitle1::VecWIel::getSrefs(
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
 class IexWznmUix::ImeIJMControlTitle1
 ******************************************************************************/

IexWznmUix::ImeIJMControlTitle1::ImeIJMControlTitle1() {
};

IexWznmUix::ImeIJMControlTitle1::~ImeIJMControlTitle1() {
	clear();
};

void IexWznmUix::ImeIJMControlTitle1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMControlTitle1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMControlTitle1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemIJMControlTitle1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControlTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCONTROLTITLE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMControlTitle1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMControlTitle1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMControlTitle1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMControlTitle1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMControlTitle1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMControlTitle1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMControlTitle1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMControlTitle1." << StrMod::replaceChar(ImeIJMControlTitle1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMControlTitle1.end" << endl;
	};
};

void IexWznmUix::ImeIJMControlTitle1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMControlTitle1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMControl1
 ******************************************************************************/

IexWznmUix::ImeitemIMControl1::ImeitemIMControl1(
			const uint ixVBasetype
			, const uint hkIxVSection
			, const uint refIxVTbl
			, const string& srefRefUref
			, const string& srefSupRefWznmMControl
			, const uint supNum
			, const uint ixVScope
			, const string& sref
			, const uint ixVSubtype
			, const string& srefsWznmMTag
			, const string& Title
			, const string& Avail
			, const string& Active
			, const string& srefsKOption
		) : WznmMControl() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->hkIxVSection = hkIxVSection;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->srefSupRefWznmMControl = srefSupRefWznmMControl;
	this->supNum = supNum;
	this->ixVScope = ixVScope;
	this->sref = sref;
	this->ixVSubtype = ixVSubtype;
	this->srefsWznmMTag = srefsWznmMTag;
	this->Title = Title;
	this->Avail = Avail;
	this->Active = Active;
	this->srefsKOption = srefsKOption;
};

IexWznmUix::ImeitemIMControl1::ImeitemIMControl1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMControl1()
		{
	WznmMControl* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcontrol->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		hkNum = rec->hkNum;
		hkIxVSection = rec->hkIxVSection;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		supRefWznmMControl = rec->supRefWznmMControl;
		supNum = rec->supNum;
		ixVScope = rec->ixVScope;
		sref = rec->sref;
		ixVSubtype = rec->ixVSubtype;
		srefsWznmMTag = rec->srefsWznmMTag;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		Avail = rec->Avail;
		Active = rec->Active;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMControl1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMControl1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefHkIxVSection = txtrd.fields[1]; ixWIelValid += ImeIMControl1::VecWIel::SREFHKIXVSECTION;};
	if (txtrd.fields.size() > 2) {srefRefIxVTbl = txtrd.fields[2]; ixWIelValid += ImeIMControl1::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 3) {srefRefUref = txtrd.fields[3]; ixWIelValid += ImeIMControl1::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 4) {srefSupRefWznmMControl = txtrd.fields[4]; ixWIelValid += ImeIMControl1::VecWIel::SREFSUPREFWZNMMCONTROL;};
	if (txtrd.fields.size() > 5) {supNum = atol(txtrd.fields[5].c_str()); ixWIelValid += ImeIMControl1::VecWIel::SUPNUM;};
	if (txtrd.fields.size() > 6) {srefIxVScope = txtrd.fields[6]; ixWIelValid += ImeIMControl1::VecWIel::SREFIXVSCOPE;};
	if (txtrd.fields.size() > 7) {sref = txtrd.fields[7]; ixWIelValid += ImeIMControl1::VecWIel::SREF;};
	if (txtrd.fields.size() > 8) {srefIxVSubtype = txtrd.fields[8]; ixWIelValid += ImeIMControl1::VecWIel::SREFIXVSUBTYPE;};
	if (txtrd.fields.size() > 9) {srefsWznmMTag = txtrd.fields[9]; ixWIelValid += ImeIMControl1::VecWIel::SREFSWZNMMTAG;};
	if (txtrd.fields.size() > 10) {Title = txtrd.fields[10]; ixWIelValid += ImeIMControl1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 11) {Avail = txtrd.fields[11]; ixWIelValid += ImeIMControl1::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 12) {Active = txtrd.fields[12]; ixWIelValid += ImeIMControl1::VecWIel::ACTIVE;};
	if (txtrd.fields.size() > 13) {srefsKOption = txtrd.fields[13]; ixWIelValid += ImeIMControl1::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMCONTROLPAR1)) {
					imeiamcontrolpar1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMCONTROLTITLE1)) {
					imeijmcontroltitle1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMControl1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMControl1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMControl1::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefHkIxVSection", "sct", srefHkIxVSection)) ixWIelValid += ImeIMControl1::VecWIel::SREFHKIXVSECTION;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMControl1::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMControl1::VecWIel::SREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "srefSupRefWznmMControl", "sup", srefSupRefWznmMControl)) ixWIelValid += ImeIMControl1::VecWIel::SREFSUPREFWZNMMCONTROL;
		if (extractUintUclc(docctx, basexpath, "supNum", "spn", supNum)) ixWIelValid += ImeIMControl1::VecWIel::SUPNUM;
		if (extractStringUclc(docctx, basexpath, "srefIxVScope", "sco", srefIxVScope)) ixWIelValid += ImeIMControl1::VecWIel::SREFIXVSCOPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMControl1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVSubtype", "sty", srefIxVSubtype)) ixWIelValid += ImeIMControl1::VecWIel::SREFIXVSUBTYPE;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMTag", "tag", srefsWznmMTag)) ixWIelValid += ImeIMControl1::VecWIel::SREFSWZNMMTAG;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMControl1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMControl1::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Active", "act", Active)) ixWIelValid += ImeIMControl1::VecWIel::ACTIVE;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMControl1::VecWIel::SREFSKOPTION;
		imeiamcontrolpar1.readXML(docctx, basexpath);
		imeijmcontroltitle1.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMControl1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMControlBasetype::getSref(ixVBasetype) << "\t" << VecWznmVMControlHkSection::getSref(hkIxVSection) << "\t" << VecWznmVMControlRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << srefSupRefWznmMControl << "\t" << supNum << "\t" << VecWznmVMControlScope::getSref(ixVScope) << "\t" << sref << "\t" << VecWznmVMControlSubtype::getSref(ixVSubtype) << "\t" << srefsWznmMTag << "\t" << Title << "\t" << Avail << "\t" << Active << "\t" << srefsKOption << endl;
	imeiamcontrolpar1.writeTxt(outfile);
	imeijmcontroltitle1.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMControl1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","sct","ret","reu","sup","spn","sco","srf","sty","tag","tit","avl","act","opt"};
	else tags = {"ImeitemIMControl1","srefIxVBasetype","srefHkIxVSection","srefRefIxVTbl","srefRefUref","srefSupRefWznmMControl","supNum","srefIxVScope","sref","srefIxVSubtype","srefsWznmMTag","Title","Avail","Active","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMControlBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], VecWznmVMControlHkSection::getSref(hkIxVSection));
		writeString(wr, tags[3], VecWznmVMControlRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[4], srefRefUref);
		writeString(wr, tags[5], srefSupRefWznmMControl);
		writeUint(wr, tags[6], supNum);
		writeString(wr, tags[7], VecWznmVMControlScope::getSref(ixVScope));
		writeString(wr, tags[8], sref);
		writeString(wr, tags[9], VecWznmVMControlSubtype::getSref(ixVSubtype));
		writeString(wr, tags[10], srefsWznmMTag);
		writeString(wr, tags[11], Title);
		writeString(wr, tags[12], Avail);
		writeString(wr, tags[13], Active);
		writeString(wr, tags[14], srefsKOption);
		imeiamcontrolpar1.writeXML(wr, shorttags);
		imeijmcontroltitle1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMControl1::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMControl1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefhkixvsection") ix |= SREFHKIXVSECTION;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "srefsuprefwznmmcontrol") ix |= SREFSUPREFWZNMMCONTROL;
		else if (ss[i] == "supnum") ix |= SUPNUM;
		else if (ss[i] == "srefixvscope") ix |= SREFIXVSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvsubtype") ix |= SREFIXVSUBTYPE;
		else if (ss[i] == "srefswznmmtag") ix |= SREFSWZNMMTAG;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "active") ix |= ACTIVE;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmUix::ImeIMControl1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMControl1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFHKIXVSECTION) ss.push_back("srefHkIxVSection");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & SREFSUPREFWZNMMCONTROL) ss.push_back("srefSupRefWznmMControl");
	if (ix & SUPNUM) ss.push_back("supNum");
	if (ix & SREFIXVSCOPE) ss.push_back("srefIxVScope");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSUBTYPE) ss.push_back("srefIxVSubtype");
	if (ix & SREFSWZNMMTAG) ss.push_back("srefsWznmMTag");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & ACTIVE) ss.push_back("Active");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMControl1
 ******************************************************************************/

IexWznmUix::ImeIMControl1::ImeIMControl1() {
};

IexWznmUix::ImeIMControl1::~ImeIMControl1() {
	clear();
};

void IexWznmUix::ImeIMControl1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMControl1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMControl1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIMControl1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMControl1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCONTROL1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMControl1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMControl1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMControl1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMControl1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMControl1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMControl1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMControl1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMControl1." << StrMod::replaceChar(ImeIMControl1::VecWIel::getSrefs(16383), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMControl1.end" << endl;
	};
};

void IexWznmUix::ImeIMControl1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMControl1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemICControl3
 ******************************************************************************/

IexWznmUix::ImeitemICControl3::ImeitemICControl3(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmUix::ImeitemICControl3::ImeitemICControl3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICControl3()
		{
};

void IexWznmUix::ImeitemICControl3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICControl3::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICControl3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemICControl3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICControl3::VecWIel::IREF;
	};
};

void IexWznmUix::ImeitemICControl3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmUix::ImeitemICControl3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICControl3","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeICControl3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeICControl3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWznmUix::ImeICControl3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeICControl3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeICControl3
 ******************************************************************************/

IexWznmUix::ImeICControl3::ImeICControl3() {
};

IexWznmUix::ImeICControl3::~ImeICControl3() {
	clear();
};

void IexWznmUix::ImeICControl3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeICControl3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemICControl3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemICControl3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICControl3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICControl3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICCONTROL3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICControl3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICControl3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeICControl3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemICControl3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICControl3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICControl3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICControl3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemICControl3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeICControl3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICControl3." << StrMod::replaceChar(ImeICControl3::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICControl3.end" << endl;
	};
};

void IexWznmUix::ImeICControl3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICControl3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIAMControlPar3
 ******************************************************************************/

IexWznmUix::ImeitemIAMControlPar3::ImeitemIAMControlPar3(
			const string& x1SrefKKey
			, const string& srefX2RefWznmMLocale
			, const string& osrefKVal
		) : WznmAMControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->osrefKVal = osrefKVal;
};

IexWznmUix::ImeitemIAMControlPar3::ImeitemIAMControlPar3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMControlPar3()
		{
	WznmAMControlPar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamcontrolpar->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1SrefKKey = rec->x1SrefKKey;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		osrefKVal = rec->osrefKVal;

		delete rec;
	};
};

void IexWznmUix::ImeitemIAMControlPar3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMControlPar3::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMControlPar3::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {osrefKVal = txtrd.fields[2]; ixWIelValid += ImeIAMControlPar3::VecWIel::OSREFKVAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMControlPar3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIAMControlPar3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMControlPar3::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMControlPar3::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "osrefKVal", "val", osrefKVal)) ixWIelValid += ImeIAMControlPar3::VecWIel::OSREFKVAL;
	};
};

void IexWznmUix::ImeitemIAMControlPar3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << x1SrefKKey << "\t" << srefX2RefWznmMLocale << "\t" << osrefKVal << endl;
};

void IexWznmUix::ImeitemIAMControlPar3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","loc","val"};
	else tags = {"ImeitemIAMControlPar3","x1SrefKKey","srefX2RefWznmMLocale","osrefKVal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], osrefKVal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIAMControlPar3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIAMControlPar3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "srefx2refwznmmlocale") ix |= SREFX2REFWZNMMLOCALE;
		else if (ss[i] == "osrefkval") ix |= OSREFKVAL;
	};

	return(ix);
};

void IexWznmUix::ImeIAMControlPar3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*OSREFKVAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIAMControlPar3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & SREFX2REFWZNMMLOCALE) ss.push_back("srefX2RefWznmMLocale");
	if (ix & OSREFKVAL) ss.push_back("osrefKVal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIAMControlPar3
 ******************************************************************************/

IexWznmUix::ImeIAMControlPar3::ImeIAMControlPar3() {
};

IexWznmUix::ImeIAMControlPar3::~ImeIAMControlPar3() {
	clear();
};

void IexWznmUix::ImeIAMControlPar3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIAMControlPar3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIAMControlPar3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIAMControlPar3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMControlPar3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCONTROLPAR3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIAMControlPar3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIAMControlPar3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMControlPar3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMControlPar3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMControlPar3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIAMControlPar3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIAMControlPar3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMControlPar3." << StrMod::replaceChar(ImeIAMControlPar3::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMControlPar3.end" << endl;
	};
};

void IexWznmUix::ImeIAMControlPar3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMControlPar3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIJMControl3
 ******************************************************************************/

IexWznmUix::ImeitemIJMControl3::ImeitemIJMControl3(
			const string& srefX1RefWznmMVectoritem
			, const string& srefStdRefWznmMStub
			, const string& srefShoRefWznmMStub
		) : WznmJMControl() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMVectoritem = srefX1RefWznmMVectoritem;
	this->srefStdRefWznmMStub = srefStdRefWznmMStub;
	this->srefShoRefWznmMStub = srefShoRefWznmMStub;
};

IexWznmUix::ImeitemIJMControl3::ImeitemIJMControl3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMControl3()
		{
	WznmJMControl* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmcontrol->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1RefWznmMVectoritem = rec->x1RefWznmMVectoritem;
		stdRefWznmMStub = rec->stdRefWznmMStub;
		shoRefWznmMStub = rec->shoRefWznmMStub;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMControl3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMVectoritem = txtrd.fields[0]; ixWIelValid += ImeIJMControl3::VecWIel::SREFX1REFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 1) {srefStdRefWznmMStub = txtrd.fields[1]; ixWIelValid += ImeIJMControl3::VecWIel::SREFSTDREFWZNMMSTUB;};
	if (txtrd.fields.size() > 2) {srefShoRefWznmMStub = txtrd.fields[2]; ixWIelValid += ImeIJMControl3::VecWIel::SREFSHOREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControl3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMControl3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMVectoritem", "vit", srefX1RefWznmMVectoritem)) ixWIelValid += ImeIJMControl3::VecWIel::SREFX1REFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefStdRefWznmMStub", "sts", srefStdRefWznmMStub)) ixWIelValid += ImeIJMControl3::VecWIel::SREFSTDREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "srefShoRefWznmMStub", "shs", srefShoRefWznmMStub)) ixWIelValid += ImeIJMControl3::VecWIel::SREFSHOREFWZNMMSTUB;
	};
};

void IexWznmUix::ImeitemIJMControl3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMVectoritem << "\t" << srefStdRefWznmMStub << "\t" << srefShoRefWznmMStub << endl;
};

void IexWznmUix::ImeitemIJMControl3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vit","sts","shs"};
	else tags = {"ImeitemIJMControl3","srefX1RefWznmMVectoritem","srefStdRefWznmMStub","srefShoRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMVectoritem);
		writeString(wr, tags[2], srefStdRefWznmMStub);
		writeString(wr, tags[3], srefShoRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControl3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMControl3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmvectoritem") ix |= SREFX1REFWZNMMVECTORITEM;
		else if (ss[i] == "srefstdrefwznmmstub") ix |= SREFSTDREFWZNMMSTUB;
		else if (ss[i] == "srefshorefwznmmstub") ix |= SREFSHOREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmUix::ImeIJMControl3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSHOREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMControl3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMVECTORITEM) ss.push_back("srefX1RefWznmMVectoritem");
	if (ix & SREFSTDREFWZNMMSTUB) ss.push_back("srefStdRefWznmMStub");
	if (ix & SREFSHOREFWZNMMSTUB) ss.push_back("srefShoRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControl3
 ******************************************************************************/

IexWznmUix::ImeIJMControl3::ImeIJMControl3() {
};

IexWznmUix::ImeIJMControl3::~ImeIJMControl3() {
	clear();
};

void IexWznmUix::ImeIJMControl3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMControl3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMControl3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIJMControl3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControl3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControl3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCONTROL3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControl3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControl3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMControl3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMControl3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMControl3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMControl3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMControl3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMControl3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMControl3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMControl3." << StrMod::replaceChar(ImeIJMControl3::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMControl3.end" << endl;
	};
};

void IexWznmUix::ImeIJMControl3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMControl3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIJMControlTitle3
 ******************************************************************************/

IexWznmUix::ImeitemIJMControlTitle3::ImeitemIJMControlTitle3(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMControlTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmUix::ImeitemIJMControlTitle3::ImeitemIJMControlTitle3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMControlTitle3()
		{
	WznmJMControlTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmcontroltitle->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMControlTitle3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMControlTitle3::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMControlTitle3::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControlTitle3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMControlTitle3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMControlTitle3::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMControlTitle3::VecWIel::TITLE;
	};
};

void IexWznmUix::ImeitemIJMControlTitle3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmUix::ImeitemIJMControlTitle3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMControlTitle3","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControlTitle3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMControlTitle3::VecWIel::getIx(
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

void IexWznmUix::ImeIJMControlTitle3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMControlTitle3::VecWIel::getSrefs(
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
 class IexWznmUix::ImeIJMControlTitle3
 ******************************************************************************/

IexWznmUix::ImeIJMControlTitle3::ImeIJMControlTitle3() {
};

IexWznmUix::ImeIJMControlTitle3::~ImeIJMControlTitle3() {
	clear();
};

void IexWznmUix::ImeIJMControlTitle3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMControlTitle3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMControlTitle3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIJMControlTitle3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControlTitle3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCONTROLTITLE3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMControlTitle3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMControlTitle3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMControlTitle3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMControlTitle3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMControlTitle3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMControlTitle3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMControlTitle3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMControlTitle3." << StrMod::replaceChar(ImeIJMControlTitle3::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMControlTitle3.end" << endl;
	};
};

void IexWznmUix::ImeIJMControlTitle3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMControlTitle3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMVector3
 ******************************************************************************/

IexWznmUix::ImeitemIMVector3::ImeitemIMVector3(
			const uint ixVBasetype
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const string& srefsKOption
		) : WznmMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->srefsKOption = srefsKOption;
};

IexWznmUix::ImeitemIMVector3::ImeitemIMVector3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVector3()
		{
	WznmMVector* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmvector->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		hkIxVTbl = rec->hkIxVTbl;
		sref = rec->sref;
		osrefWznmKTaggrp = rec->osrefWznmKTaggrp;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMVector3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector3::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector3::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {osrefWznmKTaggrp = txtrd.fields[2]; ixWIelValid += ImeIMVector3::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 3) {srefsKOption = txtrd.fields[3]; ixWIelValid += ImeIMVector3::VecWIel::SREFSKOPTION;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMVector3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector3::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector3::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp)) ixWIelValid += ImeIMVector3::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector3::VecWIel::SREFSKOPTION;
	};
};

void IexWznmUix::ImeitemIMVector3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << VecWznmVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << osrefWznmKTaggrp << "\t" << srefsKOption << endl;
};

void IexWznmUix::ImeitemIMVector3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tgr","opt"};
	else tags = {"ImeitemIMVector3","srefIxVBasetype","sref","osrefWznmKTaggrp","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], osrefWznmKTaggrp);
		writeString(wr, tags[4], srefsKOption);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMVector3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMVector3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "osrefwznmktaggrp") ix |= OSREFWZNMKTAGGRP;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmUix::ImeIMVector3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMVector3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & OSREFWZNMKTAGGRP) ss.push_back("osrefWznmKTaggrp");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMVector3
 ******************************************************************************/

IexWznmUix::ImeIMVector3::ImeIMVector3() {
};

IexWznmUix::ImeIMVector3::~ImeIMVector3() {
	clear();
};

void IexWznmUix::ImeIMVector3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMVector3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMVector3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWznmUix::ImeitemIMVector3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMVector3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMVector3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMVector3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMVector3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMVector3." << StrMod::replaceChar(ImeIMVector3::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIMVector3.end" << endl;
	};
};

void IexWznmUix::ImeIMVector3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMFeed3
 ******************************************************************************/

IexWznmUix::ImeitemIMFeed3::ImeitemIMFeed3(
			const uint srcIxVTbl
			, const string& srefSrcUref
			, const string& sref
			, const string& srefsWznmMVectoritem
			, const string& srefsWznmMTag
			, const string& Comment
		) : WznmMFeed() {
	lineno = 0;
	ixWIelValid = 0;

	this->srcIxVTbl = srcIxVTbl;
	this->srefSrcUref = srefSrcUref;
	this->sref = sref;
	this->srefsWznmMVectoritem = srefsWznmMVectoritem;
	this->srefsWznmMTag = srefsWznmMTag;
	this->Comment = Comment;
};

IexWznmUix::ImeitemIMFeed3::ImeitemIMFeed3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMFeed3()
		{
	WznmMFeed* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmfeed->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		srcIxVTbl = rec->srcIxVTbl;
		srcUref = rec->srcUref;
		sref = rec->sref;
		srefsWznmMVectoritem = rec->srefsWznmMVectoritem;
		srefsWznmMTag = rec->srefsWznmMTag;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMFeed3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSrcIxVTbl = txtrd.fields[0]; ixWIelValid += ImeIMFeed3::VecWIel::SREFSRCIXVTBL;};
	if (txtrd.fields.size() > 1) {srefSrcUref = txtrd.fields[1]; ixWIelValid += ImeIMFeed3::VecWIel::SREFSRCUREF;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMFeed3::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefsWznmMVectoritem = txtrd.fields[3]; ixWIelValid += ImeIMFeed3::VecWIel::SREFSWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 4) {srefsWznmMTag = txtrd.fields[4]; ixWIelValid += ImeIMFeed3::VecWIel::SREFSWZNMMTAG;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMFeed3::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR3)) {
					imeimvector3.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFeed3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMFeed3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSrcIxVTbl", "srt", srefSrcIxVTbl)) ixWIelValid += ImeIMFeed3::VecWIel::SREFSRCIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefSrcUref", "sru", srefSrcUref)) ixWIelValid += ImeIMFeed3::VecWIel::SREFSRCUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMFeed3::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMVectoritem", "vit", srefsWznmMVectoritem)) ixWIelValid += ImeIMFeed3::VecWIel::SREFSWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMTag", "tag", srefsWznmMTag)) ixWIelValid += ImeIMFeed3::VecWIel::SREFSWZNMMTAG;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFeed3::VecWIel::COMMENT;
		imeimvector3.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMFeed3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWznmVMFeedSrcTbl::getSref(srcIxVTbl) << "\t" << srefSrcUref << "\t" << sref << "\t" << srefsWznmMVectoritem << "\t" << srefsWznmMTag << "\t" << Comment << endl;
	imeimvector3.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMFeed3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srt","sru","srf","vit","tag","cmt"};
	else tags = {"ImeitemIMFeed3","srefSrcIxVTbl","srefSrcUref","sref","srefsWznmMVectoritem","srefsWznmMTag","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMFeedSrcTbl::getSref(srcIxVTbl));
		writeString(wr, tags[2], srefSrcUref);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], srefsWznmMVectoritem);
		writeString(wr, tags[5], srefsWznmMTag);
		writeString(wr, tags[6], Comment);
		imeimvector3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMFeed3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMFeed3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsrcixvtbl") ix |= SREFSRCIXVTBL;
		else if (ss[i] == "srefsrcuref") ix |= SREFSRCUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefswznmmvectoritem") ix |= SREFSWZNMMVECTORITEM;
		else if (ss[i] == "srefswznmmtag") ix |= SREFSWZNMMTAG;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmUix::ImeIMFeed3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMFeed3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSRCIXVTBL) ss.push_back("srefSrcIxVTbl");
	if (ix & SREFSRCUREF) ss.push_back("srefSrcUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSWZNMMVECTORITEM) ss.push_back("srefsWznmMVectoritem");
	if (ix & SREFSWZNMMTAG) ss.push_back("srefsWznmMTag");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMFeed3
 ******************************************************************************/

IexWznmUix::ImeIMFeed3::ImeIMFeed3() {
};

IexWznmUix::ImeIMFeed3::~ImeIMFeed3() {
	clear();
};

void IexWznmUix::ImeIMFeed3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMFeed3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMFeed3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIMFeed3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFeed3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFeed3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFEED3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFeed3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFeed3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMFeed3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMFeed3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFeed3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFeed3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFeed3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMFeed3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMFeed3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMFeed3." << StrMod::replaceChar(ImeIMFeed3::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMFeed3.end" << endl;
	};
};

void IexWznmUix::ImeIMFeed3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFeed3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMControl3
 ******************************************************************************/

IexWznmUix::ImeitemIMControl3::ImeitemIMControl3(
			const ubigint iref
			, const uint ixVBasetype
			, const ubigint irefRefWznmCControl
			, const uint hkIxVSection
			, const uint refIxVTbl
			, const string& srefRefUref
			, const ubigint irefSupRefWznmMControl
			, const uint ixVScope
			, const string& sref
			, const uint ixVSubtype
			, const string& srefsWznmMTag
			, const string& Title
			, const string& srefStdRefWznmMStub
			, const string& srefShoRefWznmMStub
			, const string& Avail
			, const string& Active
			, const string& srefsKOption
		) : WznmMControl() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->ixVBasetype = ixVBasetype;
	this->irefRefWznmCControl = irefRefWznmCControl;
	this->hkIxVSection = hkIxVSection;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->irefSupRefWznmMControl = irefSupRefWznmMControl;
	this->ixVScope = ixVScope;
	this->sref = sref;
	this->ixVSubtype = ixVSubtype;
	this->srefsWznmMTag = srefsWznmMTag;
	this->Title = Title;
	this->srefStdRefWznmMStub = srefStdRefWznmMStub;
	this->srefShoRefWznmMStub = srefShoRefWznmMStub;
	this->Avail = Avail;
	this->Active = Active;
	this->srefsKOption = srefsKOption;
};

IexWznmUix::ImeitemIMControl3::ImeitemIMControl3(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMControl3()
		{
	WznmMControl* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcontrol->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmCControl = rec->refWznmCControl;
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		hkNum = rec->hkNum;
		hkIxVSection = rec->hkIxVSection;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		supRefWznmMControl = rec->supRefWznmMControl;
		ixVScope = rec->ixVScope;
		refWznmMFeed = rec->refWznmMFeed;
		sref = rec->sref;
		ixVSubtype = rec->ixVSubtype;
		srefsWznmMTag = rec->srefsWznmMTag;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		refJ = rec->refJ;
		stdRefWznmMStub = rec->stdRefWznmMStub;
		shoRefWznmMStub = rec->shoRefWznmMStub;
		Avail = rec->Avail;
		Active = rec->Active;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMControl3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMControl3::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIMControl3::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {irefRefWznmCControl = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIMControl3::VecWIel::IREFREFWZNMCCONTROL;};
	if (txtrd.fields.size() > 3) {srefHkIxVSection = txtrd.fields[3]; ixWIelValid += ImeIMControl3::VecWIel::SREFHKIXVSECTION;};
	if (txtrd.fields.size() > 4) {srefRefIxVTbl = txtrd.fields[4]; ixWIelValid += ImeIMControl3::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 5) {srefRefUref = txtrd.fields[5]; ixWIelValid += ImeIMControl3::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 6) {irefSupRefWznmMControl = atoll(txtrd.fields[6].c_str()); ixWIelValid += ImeIMControl3::VecWIel::IREFSUPREFWZNMMCONTROL;};
	if (txtrd.fields.size() > 7) {srefIxVScope = txtrd.fields[7]; ixWIelValid += ImeIMControl3::VecWIel::SREFIXVSCOPE;};
	if (txtrd.fields.size() > 8) {sref = txtrd.fields[8]; ixWIelValid += ImeIMControl3::VecWIel::SREF;};
	if (txtrd.fields.size() > 9) {srefIxVSubtype = txtrd.fields[9]; ixWIelValid += ImeIMControl3::VecWIel::SREFIXVSUBTYPE;};
	if (txtrd.fields.size() > 10) {srefsWznmMTag = txtrd.fields[10]; ixWIelValid += ImeIMControl3::VecWIel::SREFSWZNMMTAG;};
	if (txtrd.fields.size() > 11) {Title = txtrd.fields[11]; ixWIelValid += ImeIMControl3::VecWIel::TITLE;};
	if (txtrd.fields.size() > 12) {srefStdRefWznmMStub = txtrd.fields[12]; ixWIelValid += ImeIMControl3::VecWIel::SREFSTDREFWZNMMSTUB;};
	if (txtrd.fields.size() > 13) {srefShoRefWznmMStub = txtrd.fields[13]; ixWIelValid += ImeIMControl3::VecWIel::SREFSHOREFWZNMMSTUB;};
	if (txtrd.fields.size() > 14) {Avail = txtrd.fields[14]; ixWIelValid += ImeIMControl3::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 15) {Active = txtrd.fields[15]; ixWIelValid += ImeIMControl3::VecWIel::ACTIVE;};
	if (txtrd.fields.size() > 16) {srefsKOption = txtrd.fields[16]; ixWIelValid += ImeIMControl3::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMCONTROLPAR3)) {
					imeiamcontrolpar3.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMCONTROL3)) {
					imeijmcontrol3.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMCONTROLTITLE3)) {
					imeijmcontroltitle3.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMFEED3)) {
					imeimfeed3.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMControl3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMControl3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMControl3::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMControl3::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCControl", "clu", irefRefWznmCControl)) ixWIelValid += ImeIMControl3::VecWIel::IREFREFWZNMCCONTROL;
		if (extractStringUclc(docctx, basexpath, "srefHkIxVSection", "sct", srefHkIxVSection)) ixWIelValid += ImeIMControl3::VecWIel::SREFHKIXVSECTION;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMControl3::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMControl3::VecWIel::SREFREFUREF;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefWznmMControl", "sup", irefSupRefWznmMControl)) ixWIelValid += ImeIMControl3::VecWIel::IREFSUPREFWZNMMCONTROL;
		if (extractStringUclc(docctx, basexpath, "srefIxVScope", "sco", srefIxVScope)) ixWIelValid += ImeIMControl3::VecWIel::SREFIXVSCOPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMControl3::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVSubtype", "sty", srefIxVSubtype)) ixWIelValid += ImeIMControl3::VecWIel::SREFIXVSUBTYPE;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMTag", "tag", srefsWznmMTag)) ixWIelValid += ImeIMControl3::VecWIel::SREFSWZNMMTAG;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMControl3::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "srefStdRefWznmMStub", "sts", srefStdRefWznmMStub)) ixWIelValid += ImeIMControl3::VecWIel::SREFSTDREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "srefShoRefWznmMStub", "shs", srefShoRefWznmMStub)) ixWIelValid += ImeIMControl3::VecWIel::SREFSHOREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMControl3::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Active", "act", Active)) ixWIelValid += ImeIMControl3::VecWIel::ACTIVE;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMControl3::VecWIel::SREFSKOPTION;
		imeiamcontrolpar3.readXML(docctx, basexpath);
		imeijmcontrol3.readXML(docctx, basexpath);
		imeijmcontroltitle3.readXML(docctx, basexpath);
		imeimfeed3.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMControl3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << "\t" << VecWznmVMControlBasetype::getSref(ixVBasetype) << "\t" << irefRefWznmCControl << "\t" << VecWznmVMControlHkSection::getSref(hkIxVSection) << "\t" << VecWznmVMControlRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << irefSupRefWznmMControl << "\t" << VecWznmVMControlScope::getSref(ixVScope) << "\t" << sref << "\t" << VecWznmVMControlSubtype::getSref(ixVSubtype) << "\t" << srefsWznmMTag << "\t" << Title << "\t" << srefStdRefWznmMStub << "\t" << srefShoRefWznmMStub << "\t" << Avail << "\t" << Active << "\t" << srefsKOption << endl;
	imeiamcontrolpar3.writeTxt(outfile);
	imeijmcontrol3.writeTxt(outfile);
	imeijmcontroltitle3.writeTxt(outfile);
	imeimfeed3.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMControl3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","typ","clu","sct","ret","reu","sup","sco","srf","sty","tag","tit","sts","shs","avl","act","opt"};
	else tags = {"ImeitemIMControl3","iref","srefIxVBasetype","irefRefWznmCControl","srefHkIxVSection","srefRefIxVTbl","srefRefUref","irefSupRefWznmMControl","srefIxVScope","sref","srefIxVSubtype","srefsWznmMTag","Title","srefStdRefWznmMStub","srefShoRefWznmMStub","Avail","Active","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], VecWznmVMControlBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[3], irefRefWznmCControl);
		writeString(wr, tags[4], VecWznmVMControlHkSection::getSref(hkIxVSection));
		writeString(wr, tags[5], VecWznmVMControlRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[6], srefRefUref);
		writeUbigint(wr, tags[7], irefSupRefWznmMControl);
		writeString(wr, tags[8], VecWznmVMControlScope::getSref(ixVScope));
		writeString(wr, tags[9], sref);
		writeString(wr, tags[10], VecWznmVMControlSubtype::getSref(ixVSubtype));
		writeString(wr, tags[11], srefsWznmMTag);
		writeString(wr, tags[12], Title);
		writeString(wr, tags[13], srefStdRefWznmMStub);
		writeString(wr, tags[14], srefShoRefWznmMStub);
		writeString(wr, tags[15], Avail);
		writeString(wr, tags[16], Active);
		writeString(wr, tags[17], srefsKOption);
		imeiamcontrolpar3.writeXML(wr, shorttags);
		imeijmcontrol3.writeXML(wr, shorttags);
		imeijmcontroltitle3.writeXML(wr, shorttags);
		imeimfeed3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMControl3::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMControl3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefrefwznmccontrol") ix |= IREFREFWZNMCCONTROL;
		else if (ss[i] == "srefhkixvsection") ix |= SREFHKIXVSECTION;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "irefsuprefwznmmcontrol") ix |= IREFSUPREFWZNMMCONTROL;
		else if (ss[i] == "srefixvscope") ix |= SREFIXVSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvsubtype") ix |= SREFIXVSUBTYPE;
		else if (ss[i] == "srefswznmmtag") ix |= SREFSWZNMMTAG;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "srefstdrefwznmmstub") ix |= SREFSTDREFWZNMMSTUB;
		else if (ss[i] == "srefshorefwznmmstub") ix |= SREFSHOREFWZNMMSTUB;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "active") ix |= ACTIVE;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmUix::ImeIMControl3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMControl3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFREFWZNMCCONTROL) ss.push_back("irefRefWznmCControl");
	if (ix & SREFHKIXVSECTION) ss.push_back("srefHkIxVSection");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & IREFSUPREFWZNMMCONTROL) ss.push_back("irefSupRefWznmMControl");
	if (ix & SREFIXVSCOPE) ss.push_back("srefIxVScope");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSUBTYPE) ss.push_back("srefIxVSubtype");
	if (ix & SREFSWZNMMTAG) ss.push_back("srefsWznmMTag");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & SREFSTDREFWZNMMSTUB) ss.push_back("srefStdRefWznmMStub");
	if (ix & SREFSHOREFWZNMMSTUB) ss.push_back("srefShoRefWznmMStub");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & ACTIVE) ss.push_back("Active");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMControl3
 ******************************************************************************/

IexWznmUix::ImeIMControl3::ImeIMControl3() {
};

IexWznmUix::ImeIMControl3::~ImeIMControl3() {
	clear();
};

void IexWznmUix::ImeIMControl3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMControl3::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMControl3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemIMControl3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMControl3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCONTROL3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMControl3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMControl3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMControl3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMControl3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMControl3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMControl3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMControl3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMControl3." << StrMod::replaceChar(ImeIMControl3::VecWIel::getSrefs(131071), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMControl3.end" << endl;
	};
};

void IexWznmUix::ImeIMControl3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMControl3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMDialog
 ******************************************************************************/

IexWznmUix::ImeitemIMDialog::ImeitemIMDialog(
			const uint ixVBasetype
			, const uint refIxVTbl
			, const string& srefRefUref
			, const string& sref
			, const string& Comment
		) : WznmMDialog() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->sref = sref;
	this->Comment = Comment;
};

IexWznmUix::ImeitemIMDialog::ImeitemIMDialog(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMDialog()
		{
	WznmMDialog* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmdialog->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMCard = rec->refWznmMCard;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMDialog::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMDialog::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefIxVTbl = txtrd.fields[1]; ixWIelValid += ImeIMDialog::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 2) {srefRefUref = txtrd.fields[2]; ixWIelValid += ImeIMDialog::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMDialog::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMDialog::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICCONTROL3)) {
					imeiccontrol3.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCONTROL3)) {
					imeimcontrol3.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMDialog"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMDialog::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMDialog::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMDialog::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMDialog::VecWIel::SREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMDialog::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMDialog::VecWIel::COMMENT;
		imeiccontrol3.readXML(docctx, basexpath);
		imeimcontrol3.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMDialog::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMDialogBasetype::getSref(ixVBasetype) << "\t" << VecWznmVMDialogRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << sref << "\t" << Comment << endl;
	imeiccontrol3.writeTxt(outfile);
	imeimcontrol3.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMDialog::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","ret","reu","srf","cmt"};
	else tags = {"ImeitemIMDialog","srefIxVBasetype","srefRefIxVTbl","srefRefUref","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMDialogBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], VecWznmVMDialogRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[3], srefRefUref);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Comment);
		imeiccontrol3.writeXML(wr, shorttags);
		imeimcontrol3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMDialog::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMDialog::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmUix::ImeIMDialog::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMDialog::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMDialog
 ******************************************************************************/

IexWznmUix::ImeIMDialog::ImeIMDialog() {
};

IexWznmUix::ImeIMDialog::~ImeIMDialog() {
	clear();
};

void IexWznmUix::ImeIMDialog::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMDialog::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMDialog* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIMDialog();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMDialog"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMDialog"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMDIALOG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMDialog"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMDialog"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMDialog::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMDialog* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMDialog");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMDialog", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMDialog";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMDialog();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMDialog::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMDialog." << StrMod::replaceChar(ImeIMDialog::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMDialog.end" << endl;
	};
};

void IexWznmUix::ImeIMDialog::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMDialog");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemICControl2
 ******************************************************************************/

IexWznmUix::ImeitemICControl2::ImeitemICControl2(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmUix::ImeitemICControl2::ImeitemICControl2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICControl2()
		{
};

void IexWznmUix::ImeitemICControl2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICControl2::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICControl2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemICControl2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICControl2::VecWIel::IREF;
	};
};

void IexWznmUix::ImeitemICControl2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmUix::ImeitemICControl2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICControl2","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeICControl2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeICControl2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWznmUix::ImeICControl2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeICControl2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeICControl2
 ******************************************************************************/

IexWznmUix::ImeICControl2::ImeICControl2() {
};

IexWznmUix::ImeICControl2::~ImeICControl2() {
	clear();
};

void IexWznmUix::ImeICControl2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeICControl2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemICControl2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemICControl2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICControl2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICControl2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICCONTROL2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICControl2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICControl2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeICControl2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemICControl2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICControl2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICControl2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICControl2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemICControl2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeICControl2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICControl2." << StrMod::replaceChar(ImeICControl2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICControl2.end" << endl;
	};
};

void IexWznmUix::ImeICControl2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICControl2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIAMControlPar2
 ******************************************************************************/

IexWznmUix::ImeitemIAMControlPar2::ImeitemIAMControlPar2(
			const uint ixWznmVIop
			, const string& x1SrefKKey
			, const string& srefX2RefWznmMLocale
			, const string& osrefKVal
		) : WznmAMControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->x1SrefKKey = x1SrefKKey;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->osrefKVal = osrefKVal;
};

IexWznmUix::ImeitemIAMControlPar2::ImeitemIAMControlPar2(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIAMControlPar2(ixWznmVIop)
		{
	WznmAMControlPar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamcontrolpar->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1SrefKKey = rec->x1SrefKKey;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		osrefKVal = rec->osrefKVal;

		delete rec;
	};
};

void IexWznmUix::ImeitemIAMControlPar2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIAMControlPar2::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {x1SrefKKey = txtrd.fields[1]; ixWIelValid += ImeIAMControlPar2::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 2) {srefX2RefWznmMLocale = txtrd.fields[2]; ixWIelValid += ImeIAMControlPar2::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 3) {osrefKVal = txtrd.fields[3]; ixWIelValid += ImeIAMControlPar2::VecWIel::OSREFKVAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMControlPar2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIAMControlPar2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIAMControlPar2::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMControlPar2::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMControlPar2::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "osrefKVal", "val", osrefKVal)) ixWIelValid += ImeIAMControlPar2::VecWIel::OSREFKVAL;
	};
};

void IexWznmUix::ImeitemIAMControlPar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << x1SrefKKey << "\t" << srefX2RefWznmMLocale << "\t" << osrefKVal << endl;
};

void IexWznmUix::ImeitemIAMControlPar2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","key","loc","val"};
	else tags = {"ImeitemIAMControlPar2","srefIxWznmVIop","x1SrefKKey","srefX2RefWznmMLocale","osrefKVal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], x1SrefKKey);
		writeString(wr, tags[3], srefX2RefWznmMLocale);
		writeString(wr, tags[4], osrefKVal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIAMControlPar2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIAMControlPar2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "srefx2refwznmmlocale") ix |= SREFX2REFWZNMMLOCALE;
		else if (ss[i] == "osrefkval") ix |= OSREFKVAL;
	};

	return(ix);
};

void IexWznmUix::ImeIAMControlPar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*OSREFKVAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIAMControlPar2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & SREFX2REFWZNMMLOCALE) ss.push_back("srefX2RefWznmMLocale");
	if (ix & OSREFKVAL) ss.push_back("osrefKVal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIAMControlPar2
 ******************************************************************************/

IexWznmUix::ImeIAMControlPar2::ImeIAMControlPar2() {
};

IexWznmUix::ImeIAMControlPar2::~ImeIAMControlPar2() {
	clear();
};

void IexWznmUix::ImeIAMControlPar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIAMControlPar2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIAMControlPar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIAMControlPar2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMControlPar2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCONTROLPAR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMControlPar2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIAMControlPar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIAMControlPar2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMControlPar2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMControlPar2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMControlPar2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIAMControlPar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIAMControlPar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMControlPar2." << StrMod::replaceChar(ImeIAMControlPar2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMControlPar2.end" << endl;
	};
};

void IexWznmUix::ImeIAMControlPar2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMControlPar2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIJMControl2
 ******************************************************************************/

IexWznmUix::ImeitemIJMControl2::ImeitemIJMControl2(
			const uint ixWznmVIop
			, const string& srefX1RefWznmMVectoritem
			, const string& srefStdRefWznmMStub
			, const string& srefShoRefWznmMStub
		) : WznmJMControl() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->srefX1RefWznmMVectoritem = srefX1RefWznmMVectoritem;
	this->srefStdRefWznmMStub = srefStdRefWznmMStub;
	this->srefShoRefWznmMStub = srefShoRefWznmMStub;
};

IexWznmUix::ImeitemIJMControl2::ImeitemIJMControl2(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIJMControl2(ixWznmVIop)
		{
	WznmJMControl* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmcontrol->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1RefWznmMVectoritem = rec->x1RefWznmMVectoritem;
		stdRefWznmMStub = rec->stdRefWznmMStub;
		shoRefWznmMStub = rec->shoRefWznmMStub;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMControl2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIJMControl2::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefX1RefWznmMVectoritem = txtrd.fields[1]; ixWIelValid += ImeIJMControl2::VecWIel::SREFX1REFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 2) {srefStdRefWznmMStub = txtrd.fields[2]; ixWIelValid += ImeIJMControl2::VecWIel::SREFSTDREFWZNMMSTUB;};
	if (txtrd.fields.size() > 3) {srefShoRefWznmMStub = txtrd.fields[3]; ixWIelValid += ImeIJMControl2::VecWIel::SREFSHOREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControl2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMControl2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIJMControl2::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMVectoritem", "vit", srefX1RefWznmMVectoritem)) ixWIelValid += ImeIJMControl2::VecWIel::SREFX1REFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefStdRefWznmMStub", "sts", srefStdRefWznmMStub)) ixWIelValid += ImeIJMControl2::VecWIel::SREFSTDREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "srefShoRefWznmMStub", "shs", srefShoRefWznmMStub)) ixWIelValid += ImeIJMControl2::VecWIel::SREFSHOREFWZNMMSTUB;
	};
};

void IexWznmUix::ImeitemIJMControl2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << srefX1RefWznmMVectoritem << "\t" << srefStdRefWznmMStub << "\t" << srefShoRefWznmMStub << endl;
};

void IexWznmUix::ImeitemIJMControl2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","vit","sts","shs"};
	else tags = {"ImeitemIJMControl2","srefIxWznmVIop","srefX1RefWznmMVectoritem","srefStdRefWznmMStub","srefShoRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], srefX1RefWznmMVectoritem);
		writeString(wr, tags[3], srefStdRefWznmMStub);
		writeString(wr, tags[4], srefShoRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControl2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMControl2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefx1refwznmmvectoritem") ix |= SREFX1REFWZNMMVECTORITEM;
		else if (ss[i] == "srefstdrefwznmmstub") ix |= SREFSTDREFWZNMMSTUB;
		else if (ss[i] == "srefshorefwznmmstub") ix |= SREFSHOREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmUix::ImeIJMControl2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSHOREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMControl2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFX1REFWZNMMVECTORITEM) ss.push_back("srefX1RefWznmMVectoritem");
	if (ix & SREFSTDREFWZNMMSTUB) ss.push_back("srefStdRefWznmMStub");
	if (ix & SREFSHOREFWZNMMSTUB) ss.push_back("srefShoRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControl2
 ******************************************************************************/

IexWznmUix::ImeIJMControl2::ImeIJMControl2() {
};

IexWznmUix::ImeIJMControl2::~ImeIJMControl2() {
	clear();
};

void IexWznmUix::ImeIJMControl2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMControl2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMControl2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIJMControl2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControl2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControl2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCONTROL2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControl2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControl2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMControl2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMControl2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMControl2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMControl2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMControl2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMControl2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMControl2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMControl2." << StrMod::replaceChar(ImeIJMControl2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMControl2.end" << endl;
	};
};

void IexWznmUix::ImeIJMControl2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMControl2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIJMControlTitle2
 ******************************************************************************/

IexWznmUix::ImeitemIJMControlTitle2::ImeitemIJMControlTitle2(
			const uint ixWznmVIop
			, const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMControlTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmUix::ImeitemIJMControlTitle2::ImeitemIJMControlTitle2(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIJMControlTitle2(ixWznmVIop)
		{
	WznmJMControlTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmcontroltitle->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMControlTitle2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIJMControlTitle2::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefX1RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIJMControlTitle2::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIJMControlTitle2::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControlTitle2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMControlTitle2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIJMControlTitle2::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMControlTitle2::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMControlTitle2::VecWIel::TITLE;
	};
};

void IexWznmUix::ImeitemIJMControlTitle2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmUix::ImeitemIJMControlTitle2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","loc","tit"};
	else tags = {"ImeitemIJMControlTitle2","srefIxWznmVIop","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], srefX1RefWznmMLocale);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControlTitle2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMControlTitle2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmUix::ImeIJMControlTitle2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMControlTitle2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFX1REFWZNMMLOCALE) ss.push_back("srefX1RefWznmMLocale");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIJMControlTitle2
 ******************************************************************************/

IexWznmUix::ImeIJMControlTitle2::ImeIJMControlTitle2() {
};

IexWznmUix::ImeIJMControlTitle2::~ImeIJMControlTitle2() {
	clear();
};

void IexWznmUix::ImeIJMControlTitle2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMControlTitle2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMControlTitle2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIJMControlTitle2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMControlTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCONTROLTITLE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMControlTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMControlTitle2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMControlTitle2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMControlTitle2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMControlTitle2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMControlTitle2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMControlTitle2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMControlTitle2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMControlTitle2." << StrMod::replaceChar(ImeIJMControlTitle2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMControlTitle2.end" << endl;
	};
};

void IexWznmUix::ImeIJMControlTitle2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMControlTitle2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMVector2
 ******************************************************************************/

IexWznmUix::ImeitemIMVector2::ImeitemIMVector2(
			const uint ixVBasetype
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const string& srefsKOption
		) : WznmMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->srefsKOption = srefsKOption;
};

IexWznmUix::ImeitemIMVector2::ImeitemIMVector2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVector2()
		{
	WznmMVector* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmvector->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		hkIxVTbl = rec->hkIxVTbl;
		sref = rec->sref;
		osrefWznmKTaggrp = rec->osrefWznmKTaggrp;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMVector2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {osrefWznmKTaggrp = txtrd.fields[2]; ixWIelValid += ImeIMVector2::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 3) {srefsKOption = txtrd.fields[3]; ixWIelValid += ImeIMVector2::VecWIel::SREFSKOPTION;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMVector2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector2::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp)) ixWIelValid += ImeIMVector2::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector2::VecWIel::SREFSKOPTION;
	};
};

void IexWznmUix::ImeitemIMVector2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << VecWznmVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << osrefWznmKTaggrp << "\t" << srefsKOption << endl;
};

void IexWznmUix::ImeitemIMVector2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tgr","opt"};
	else tags = {"ImeitemIMVector2","srefIxVBasetype","sref","osrefWznmKTaggrp","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], osrefWznmKTaggrp);
		writeString(wr, tags[4], srefsKOption);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMVector2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMVector2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "osrefwznmktaggrp") ix |= OSREFWZNMKTAGGRP;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmUix::ImeIMVector2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMVector2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & OSREFWZNMKTAGGRP) ss.push_back("osrefWznmKTaggrp");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMVector2
 ******************************************************************************/

IexWznmUix::ImeIMVector2::ImeIMVector2() {
};

IexWznmUix::ImeIMVector2::~ImeIMVector2() {
	clear();
};

void IexWznmUix::ImeIMVector2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMVector2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMVector2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWznmUix::ImeitemIMVector2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMVector2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMVector2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMVector2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMVector2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMVector2." << StrMod::replaceChar(ImeIMVector2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIMVector2.end" << endl;
	};
};

void IexWznmUix::ImeIMVector2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMFeed2
 ******************************************************************************/

IexWznmUix::ImeitemIMFeed2::ImeitemIMFeed2(
			const uint srcIxVTbl
			, const string& srefSrcUref
			, const string& sref
			, const string& srefsWznmMVectoritem
			, const string& srefsWznmMTag
			, const string& Comment
		) : WznmMFeed() {
	lineno = 0;
	ixWIelValid = 0;

	this->srcIxVTbl = srcIxVTbl;
	this->srefSrcUref = srefSrcUref;
	this->sref = sref;
	this->srefsWznmMVectoritem = srefsWznmMVectoritem;
	this->srefsWznmMTag = srefsWznmMTag;
	this->Comment = Comment;
};

IexWznmUix::ImeitemIMFeed2::ImeitemIMFeed2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMFeed2()
		{
	WznmMFeed* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmfeed->loadRecByRef(ref, &rec)) {
		refWznmMControl = rec->refWznmMControl;
		srcIxVTbl = rec->srcIxVTbl;
		srcUref = rec->srcUref;
		sref = rec->sref;
		srefsWznmMVectoritem = rec->srefsWznmMVectoritem;
		srefsWznmMTag = rec->srefsWznmMTag;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMFeed2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSrcIxVTbl = txtrd.fields[0]; ixWIelValid += ImeIMFeed2::VecWIel::SREFSRCIXVTBL;};
	if (txtrd.fields.size() > 1) {srefSrcUref = txtrd.fields[1]; ixWIelValid += ImeIMFeed2::VecWIel::SREFSRCUREF;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMFeed2::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefsWznmMVectoritem = txtrd.fields[3]; ixWIelValid += ImeIMFeed2::VecWIel::SREFSWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 4) {srefsWznmMTag = txtrd.fields[4]; ixWIelValid += ImeIMFeed2::VecWIel::SREFSWZNMMTAG;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMFeed2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR2)) {
					imeimvector2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFeed2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMFeed2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSrcIxVTbl", "srt", srefSrcIxVTbl)) ixWIelValid += ImeIMFeed2::VecWIel::SREFSRCIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefSrcUref", "sru", srefSrcUref)) ixWIelValid += ImeIMFeed2::VecWIel::SREFSRCUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMFeed2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMVectoritem", "vit", srefsWznmMVectoritem)) ixWIelValid += ImeIMFeed2::VecWIel::SREFSWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMTag", "tag", srefsWznmMTag)) ixWIelValid += ImeIMFeed2::VecWIel::SREFSWZNMMTAG;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFeed2::VecWIel::COMMENT;
		imeimvector2.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMFeed2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWznmVMFeedSrcTbl::getSref(srcIxVTbl) << "\t" << srefSrcUref << "\t" << sref << "\t" << srefsWznmMVectoritem << "\t" << srefsWznmMTag << "\t" << Comment << endl;
	imeimvector2.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMFeed2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srt","sru","srf","vit","tag","cmt"};
	else tags = {"ImeitemIMFeed2","srefSrcIxVTbl","srefSrcUref","sref","srefsWznmMVectoritem","srefsWznmMTag","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMFeedSrcTbl::getSref(srcIxVTbl));
		writeString(wr, tags[2], srefSrcUref);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], srefsWznmMVectoritem);
		writeString(wr, tags[5], srefsWznmMTag);
		writeString(wr, tags[6], Comment);
		imeimvector2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMFeed2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMFeed2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsrcixvtbl") ix |= SREFSRCIXVTBL;
		else if (ss[i] == "srefsrcuref") ix |= SREFSRCUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefswznmmvectoritem") ix |= SREFSWZNMMVECTORITEM;
		else if (ss[i] == "srefswznmmtag") ix |= SREFSWZNMMTAG;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmUix::ImeIMFeed2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMFeed2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSRCIXVTBL) ss.push_back("srefSrcIxVTbl");
	if (ix & SREFSRCUREF) ss.push_back("srefSrcUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSWZNMMVECTORITEM) ss.push_back("srefsWznmMVectoritem");
	if (ix & SREFSWZNMMTAG) ss.push_back("srefsWznmMTag");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMFeed2
 ******************************************************************************/

IexWznmUix::ImeIMFeed2::ImeIMFeed2() {
};

IexWznmUix::ImeIMFeed2::~ImeIMFeed2() {
	clear();
};

void IexWznmUix::ImeIMFeed2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMFeed2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMFeed2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmUix::ImeitemIMFeed2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFeed2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFeed2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFEED2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFeed2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFeed2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMFeed2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMFeed2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFeed2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFeed2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFeed2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMFeed2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMFeed2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMFeed2." << StrMod::replaceChar(ImeIMFeed2::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMFeed2.end" << endl;
	};
};

void IexWznmUix::ImeIMFeed2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFeed2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMControl2
 ******************************************************************************/

IexWznmUix::ImeitemIMControl2::ImeitemIMControl2(
			const uint ixWznmVIop
			, const ubigint iref
			, const uint ixVBasetype
			, const ubigint irefRefWznmCControl
			, const uint hkIxVSection
			, const uint refIxVTbl
			, const string& srefRefUref
			, const ubigint irefSupRefWznmMControl
			, const uint ixVScope
			, const string& sref
			, const uint ixVSubtype
			, const string& srefsWznmMTag
			, const string& Title
			, const string& srefStdRefWznmMStub
			, const string& srefShoRefWznmMStub
			, const string& Avail
			, const string& Active
			, const string& srefsKOption
		) : WznmMControl() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->iref = iref;
	this->ixVBasetype = ixVBasetype;
	this->irefRefWznmCControl = irefRefWznmCControl;
	this->hkIxVSection = hkIxVSection;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->irefSupRefWznmMControl = irefSupRefWznmMControl;
	this->ixVScope = ixVScope;
	this->sref = sref;
	this->ixVSubtype = ixVSubtype;
	this->srefsWznmMTag = srefsWznmMTag;
	this->Title = Title;
	this->srefStdRefWznmMStub = srefStdRefWznmMStub;
	this->srefShoRefWznmMStub = srefShoRefWznmMStub;
	this->Avail = Avail;
	this->Active = Active;
	this->srefsKOption = srefsKOption;
};

IexWznmUix::ImeitemIMControl2::ImeitemIMControl2(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMControl2(ixWznmVIop)
		{
	WznmMControl* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcontrol->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmCControl = rec->refWznmCControl;
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		hkNum = rec->hkNum;
		hkIxVSection = rec->hkIxVSection;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		supRefWznmMControl = rec->supRefWznmMControl;
		ixVScope = rec->ixVScope;
		refWznmMFeed = rec->refWznmMFeed;
		sref = rec->sref;
		ixVSubtype = rec->ixVSubtype;
		srefsWznmMTag = rec->srefsWznmMTag;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		refJ = rec->refJ;
		stdRefWznmMStub = rec->stdRefWznmMStub;
		shoRefWznmMStub = rec->shoRefWznmMStub;
		Avail = rec->Avail;
		Active = rec->Active;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMControl2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMControl2::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {iref = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMControl2::VecWIel::IREF;};
	if (txtrd.fields.size() > 2) {srefIxVBasetype = txtrd.fields[2]; ixWIelValid += ImeIMControl2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 3) {irefRefWznmCControl = atoll(txtrd.fields[3].c_str()); ixWIelValid += ImeIMControl2::VecWIel::IREFREFWZNMCCONTROL;};
	if (txtrd.fields.size() > 4) {srefHkIxVSection = txtrd.fields[4]; ixWIelValid += ImeIMControl2::VecWIel::SREFHKIXVSECTION;};
	if (txtrd.fields.size() > 5) {srefRefIxVTbl = txtrd.fields[5]; ixWIelValid += ImeIMControl2::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 6) {srefRefUref = txtrd.fields[6]; ixWIelValid += ImeIMControl2::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 7) {irefSupRefWznmMControl = atoll(txtrd.fields[7].c_str()); ixWIelValid += ImeIMControl2::VecWIel::IREFSUPREFWZNMMCONTROL;};
	if (txtrd.fields.size() > 8) {srefIxVScope = txtrd.fields[8]; ixWIelValid += ImeIMControl2::VecWIel::SREFIXVSCOPE;};
	if (txtrd.fields.size() > 9) {sref = txtrd.fields[9]; ixWIelValid += ImeIMControl2::VecWIel::SREF;};
	if (txtrd.fields.size() > 10) {srefIxVSubtype = txtrd.fields[10]; ixWIelValid += ImeIMControl2::VecWIel::SREFIXVSUBTYPE;};
	if (txtrd.fields.size() > 11) {srefsWznmMTag = txtrd.fields[11]; ixWIelValid += ImeIMControl2::VecWIel::SREFSWZNMMTAG;};
	if (txtrd.fields.size() > 12) {Title = txtrd.fields[12]; ixWIelValid += ImeIMControl2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 13) {srefStdRefWznmMStub = txtrd.fields[13]; ixWIelValid += ImeIMControl2::VecWIel::SREFSTDREFWZNMMSTUB;};
	if (txtrd.fields.size() > 14) {srefShoRefWznmMStub = txtrd.fields[14]; ixWIelValid += ImeIMControl2::VecWIel::SREFSHOREFWZNMMSTUB;};
	if (txtrd.fields.size() > 15) {Avail = txtrd.fields[15]; ixWIelValid += ImeIMControl2::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 16) {Active = txtrd.fields[16]; ixWIelValid += ImeIMControl2::VecWIel::ACTIVE;};
	if (txtrd.fields.size() > 17) {srefsKOption = txtrd.fields[17]; ixWIelValid += ImeIMControl2::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMCONTROLPAR2)) {
					imeiamcontrolpar2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMCONTROL2)) {
					imeijmcontrol2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMCONTROLTITLE2)) {
					imeijmcontroltitle2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMFEED2)) {
					imeimfeed2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMControl2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMControl2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMControl2::VecWIel::SREFIXWZNMVIOP;
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMControl2::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMControl2::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCControl", "clu", irefRefWznmCControl)) ixWIelValid += ImeIMControl2::VecWIel::IREFREFWZNMCCONTROL;
		if (extractStringUclc(docctx, basexpath, "srefHkIxVSection", "sct", srefHkIxVSection)) ixWIelValid += ImeIMControl2::VecWIel::SREFHKIXVSECTION;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMControl2::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMControl2::VecWIel::SREFREFUREF;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefWznmMControl", "sup", irefSupRefWznmMControl)) ixWIelValid += ImeIMControl2::VecWIel::IREFSUPREFWZNMMCONTROL;
		if (extractStringUclc(docctx, basexpath, "srefIxVScope", "sco", srefIxVScope)) ixWIelValid += ImeIMControl2::VecWIel::SREFIXVSCOPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMControl2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVSubtype", "sty", srefIxVSubtype)) ixWIelValid += ImeIMControl2::VecWIel::SREFIXVSUBTYPE;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMTag", "tag", srefsWznmMTag)) ixWIelValid += ImeIMControl2::VecWIel::SREFSWZNMMTAG;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMControl2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "srefStdRefWznmMStub", "sts", srefStdRefWznmMStub)) ixWIelValid += ImeIMControl2::VecWIel::SREFSTDREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "srefShoRefWznmMStub", "shs", srefShoRefWznmMStub)) ixWIelValid += ImeIMControl2::VecWIel::SREFSHOREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMControl2::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Active", "act", Active)) ixWIelValid += ImeIMControl2::VecWIel::ACTIVE;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMControl2::VecWIel::SREFSKOPTION;
		imeiamcontrolpar2.readXML(docctx, basexpath);
		imeijmcontrol2.readXML(docctx, basexpath);
		imeijmcontroltitle2.readXML(docctx, basexpath);
		imeimfeed2.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMControl2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << iref << "\t" << VecWznmVMControlBasetype::getSref(ixVBasetype) << "\t" << irefRefWznmCControl << "\t" << VecWznmVMControlHkSection::getSref(hkIxVSection) << "\t" << VecWznmVMControlRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << irefSupRefWznmMControl << "\t" << VecWznmVMControlScope::getSref(ixVScope) << "\t" << sref << "\t" << VecWznmVMControlSubtype::getSref(ixVSubtype) << "\t" << srefsWznmMTag << "\t" << Title << "\t" << srefStdRefWznmMStub << "\t" << srefShoRefWznmMStub << "\t" << Avail << "\t" << Active << "\t" << srefsKOption << endl;
	imeiamcontrolpar2.writeTxt(outfile);
	imeijmcontrol2.writeTxt(outfile);
	imeijmcontroltitle2.writeTxt(outfile);
	imeimfeed2.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMControl2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","irf","typ","clu","sct","ret","reu","sup","sco","srf","sty","tag","tit","sts","shs","avl","act","opt"};
	else tags = {"ImeitemIMControl2","srefIxWznmVIop","iref","srefIxVBasetype","irefRefWznmCControl","srefHkIxVSection","srefRefIxVTbl","srefRefUref","irefSupRefWznmMControl","srefIxVScope","sref","srefIxVSubtype","srefsWznmMTag","Title","srefStdRefWznmMStub","srefShoRefWznmMStub","Avail","Active","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeUbigint(wr, tags[2], iref);
		writeString(wr, tags[3], VecWznmVMControlBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[4], irefRefWznmCControl);
		writeString(wr, tags[5], VecWznmVMControlHkSection::getSref(hkIxVSection));
		writeString(wr, tags[6], VecWznmVMControlRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[7], srefRefUref);
		writeUbigint(wr, tags[8], irefSupRefWznmMControl);
		writeString(wr, tags[9], VecWznmVMControlScope::getSref(ixVScope));
		writeString(wr, tags[10], sref);
		writeString(wr, tags[11], VecWznmVMControlSubtype::getSref(ixVSubtype));
		writeString(wr, tags[12], srefsWznmMTag);
		writeString(wr, tags[13], Title);
		writeString(wr, tags[14], srefStdRefWznmMStub);
		writeString(wr, tags[15], srefShoRefWznmMStub);
		writeString(wr, tags[16], Avail);
		writeString(wr, tags[17], Active);
		writeString(wr, tags[18], srefsKOption);
		imeiamcontrolpar2.writeXML(wr, shorttags);
		imeijmcontrol2.writeXML(wr, shorttags);
		imeijmcontroltitle2.writeXML(wr, shorttags);
		imeimfeed2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMControl2::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMControl2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefrefwznmccontrol") ix |= IREFREFWZNMCCONTROL;
		else if (ss[i] == "srefhkixvsection") ix |= SREFHKIXVSECTION;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "irefsuprefwznmmcontrol") ix |= IREFSUPREFWZNMMCONTROL;
		else if (ss[i] == "srefixvscope") ix |= SREFIXVSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvsubtype") ix |= SREFIXVSUBTYPE;
		else if (ss[i] == "srefswznmmtag") ix |= SREFSWZNMMTAG;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "srefstdrefwznmmstub") ix |= SREFSTDREFWZNMMSTUB;
		else if (ss[i] == "srefshorefwznmmstub") ix |= SREFSHOREFWZNMMSTUB;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "active") ix |= ACTIVE;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmUix::ImeIMControl2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMControl2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFREFWZNMCCONTROL) ss.push_back("irefRefWznmCControl");
	if (ix & SREFHKIXVSECTION) ss.push_back("srefHkIxVSection");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & IREFSUPREFWZNMMCONTROL) ss.push_back("irefSupRefWznmMControl");
	if (ix & SREFIXVSCOPE) ss.push_back("srefIxVScope");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSUBTYPE) ss.push_back("srefIxVSubtype");
	if (ix & SREFSWZNMMTAG) ss.push_back("srefsWznmMTag");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & SREFSTDREFWZNMMSTUB) ss.push_back("srefStdRefWznmMStub");
	if (ix & SREFSHOREFWZNMMSTUB) ss.push_back("srefShoRefWznmMStub");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & ACTIVE) ss.push_back("Active");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMControl2
 ******************************************************************************/

IexWznmUix::ImeIMControl2::ImeIMControl2() {
};

IexWznmUix::ImeIMControl2::~ImeIMControl2() {
	clear();
};

void IexWznmUix::ImeIMControl2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMControl2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMControl2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemIMControl2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMControl2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCONTROL2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMControl2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMControl2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMControl2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMControl2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMControl2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMControl2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMControl2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMControl2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMControl2." << StrMod::replaceChar(ImeIMControl2::VecWIel::getSrefs(262143), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMControl2.end" << endl;
	};
};

void IexWznmUix::ImeIMControl2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMControl2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMPanel
 ******************************************************************************/

IexWznmUix::ImeitemIMPanel::ImeitemIMPanel(
			const uint ixWznmVIop
			, const uint ixVBasetype
			, const uint carNum
			, const string& sref
			, const bool Detach
			, const string& Avail
			, const string& Comment
		) : WznmMPanel() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->ixVBasetype = ixVBasetype;
	this->carNum = carNum;
	this->sref = sref;
	this->Detach = Detach;
	this->Avail = Avail;
	this->Comment = Comment;
};

IexWznmUix::ImeitemIMPanel::ImeitemIMPanel(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMPanel(ixWznmVIop)
		{
	WznmMPanel* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmpanel->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		carRefWznmMCard = rec->carRefWznmMCard;
		carNum = rec->carNum;
		refIxVTbl = rec->refIxVTbl;
		sref = rec->sref;
		Detach = rec->Detach;
		Avail = rec->Avail;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMPanel::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMPanel::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIMPanel::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {carNum = atol(txtrd.fields[2].c_str()); ixWIelValid += ImeIMPanel::VecWIel::CARNUM;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMPanel::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Detach = (txtrd.fields[4] == "true"); ixWIelValid += ImeIMPanel::VecWIel::DETACH;};
	if (txtrd.fields.size() > 5) {Avail = txtrd.fields[5]; ixWIelValid += ImeIMPanel::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMPanel::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICCONTROL2)) {
					imeiccontrol2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCONTROL2)) {
					imeimcontrol2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPanel"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMPanel::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMPanel::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMPanel::VecWIel::SREFIXVBASETYPE;
		if (extractUintUclc(docctx, basexpath, "carNum", "crn", carNum)) ixWIelValid += ImeIMPanel::VecWIel::CARNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPanel::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Detach", "det", Detach)) ixWIelValid += ImeIMPanel::VecWIel::DETACH;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMPanel::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPanel::VecWIel::COMMENT;
		imeiccontrol2.readXML(docctx, basexpath);
		imeimcontrol2.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMPanel::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << VecWznmVMPanelBasetype::getSref(ixVBasetype) << "\t" << carNum << "\t" << sref << "\t" << StrMod::boolToString(Detach) << "\t" << Avail << "\t" << Comment << endl;
	imeiccontrol2.writeTxt(outfile);
	imeimcontrol2.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMPanel::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","typ","crn","srf","det","avl","cmt"};
	else tags = {"ImeitemIMPanel","srefIxWznmVIop","srefIxVBasetype","carNum","sref","Detach","Avail","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], VecWznmVMPanelBasetype::getSref(ixVBasetype));
		writeUint(wr, tags[3], carNum);
		writeString(wr, tags[4], sref);
		writeBool(wr, tags[5], Detach);
		writeString(wr, tags[6], Avail);
		writeString(wr, tags[7], Comment);
		imeiccontrol2.writeXML(wr, shorttags);
		imeimcontrol2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMPanel::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMPanel::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "carnum") ix |= CARNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "detach") ix |= DETACH;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmUix::ImeIMPanel::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMPanel::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & CARNUM) ss.push_back("carNum");
	if (ix & SREF) ss.push_back("sref");
	if (ix & DETACH) ss.push_back("Detach");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMPanel
 ******************************************************************************/

IexWznmUix::ImeIMPanel::ImeIMPanel() {
};

IexWznmUix::ImeIMPanel::~ImeIMPanel() {
	clear();
};

void IexWznmUix::ImeIMPanel::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMPanel::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMPanel* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIMPanel();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPanel"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPanel"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPANEL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPanel"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPanel"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMPanel::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMPanel* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPanel");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPanel", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPanel";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMPanel();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMPanel::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMPanel." << StrMod::replaceChar(ImeIMPanel::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMPanel.end" << endl;
	};
};

void IexWznmUix::ImeIMPanel::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPanel");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMCard
 ******************************************************************************/

IexWznmUix::ImeitemIMCard::ImeitemIMCard(
			const string& sref
		) : WznmMCard() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWznmUix::ImeitemIMCard::ImeitemIMCard(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCard()
		{
	WznmMCard* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcard->loadRecByRef(ref, &rec)) {
		sref = rec->sref;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMCard::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMCard::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCONTROL1)) {
					imeimcontrol1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMDIALOG)) {
					imeimdialog.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMPANEL)) {
					imeimpanel.readTxt(txtrd);
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

void IexWznmUix::ImeitemIMCard::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCard::VecWIel::SREF;
		imeimcontrol1.readXML(docctx, basexpath);
		imeimdialog.readXML(docctx, basexpath);
		imeimpanel.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMCard::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeimcontrol1.writeTxt(outfile);
	imeimdialog.writeTxt(outfile);
	imeimpanel.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMCard::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMCard","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		imeimcontrol1.writeXML(wr, shorttags);
		imeimdialog.writeXML(wr, shorttags);
		imeimpanel.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMCard::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMCard::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWznmUix::ImeIMCard::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMCard::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMCard
 ******************************************************************************/

IexWznmUix::ImeIMCard::ImeIMCard() {
};

IexWznmUix::ImeIMCard::~ImeIMCard() {
	clear();
};

void IexWznmUix::ImeIMCard::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMCard::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMCard* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmUix::ImeitemIMCard();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

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

void IexWznmUix::ImeIMCard::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMCard* ii = NULL;

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

			ii = new IexWznmUix::ImeitemIMCard();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMCard::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCard." << StrMod::replaceChar(ImeIMCard::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMCard.end" << endl;
	};
};

void IexWznmUix::ImeIMCard::writeXML(
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
 class IexWznmUix::ImeitemIJMPresetTitle
 ******************************************************************************/

IexWznmUix::ImeitemIJMPresetTitle::ImeitemIJMPresetTitle(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMPresetTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmUix::ImeitemIJMPresetTitle::ImeitemIJMPresetTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMPresetTitle()
		{
	WznmJMPresetTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmpresettitle->loadRecByRef(ref, &rec)) {
		refWznmMPreset = rec->refWznmMPreset;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMPresetTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMPresetTitle::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMPresetTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPresetTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMPresetTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMPresetTitle::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMPresetTitle::VecWIel::TITLE;
	};
};

void IexWznmUix::ImeitemIJMPresetTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmUix::ImeitemIJMPresetTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMPresetTitle","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMPresetTitle::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMPresetTitle::VecWIel::getIx(
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

void IexWznmUix::ImeIJMPresetTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMPresetTitle::VecWIel::getSrefs(
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
 class IexWznmUix::ImeIJMPresetTitle
 ******************************************************************************/

IexWznmUix::ImeIJMPresetTitle::ImeIJMPresetTitle() {
};

IexWznmUix::ImeIJMPresetTitle::~ImeIJMPresetTitle() {
	clear();
};

void IexWznmUix::ImeIJMPresetTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMPresetTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMPresetTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIJMPresetTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPresetTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPresetTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPRESETTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPresetTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPresetTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMPresetTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMPresetTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPresetTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPresetTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPresetTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMPresetTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMPresetTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMPresetTitle." << StrMod::replaceChar(ImeIJMPresetTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMPresetTitle.end" << endl;
	};
};

void IexWznmUix::ImeIJMPresetTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPresetTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMPreset
 ******************************************************************************/

IexWznmUix::ImeitemIMPreset::ImeitemIMPreset(
			const uint ixWznmVIop
			, const uint refIxVTbl
			, const string& srefRefUref
			, const uint ixVScope
			, const string& sref
			, const uint ixWznmWArgtype
			, const string& Title
		) : WznmMPreset() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->ixVScope = ixVScope;
	this->sref = sref;
	this->ixWznmWArgtype = ixWznmWArgtype;
	this->Title = Title;
};

IexWznmUix::ImeitemIMPreset::ImeitemIMPreset(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMPreset(ixWznmVIop)
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
		refJTitle = rec->refJTitle;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMPreset::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMPreset::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefRefIxVTbl = txtrd.fields[1]; ixWIelValid += ImeIMPreset::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 2) {srefRefUref = txtrd.fields[2]; ixWIelValid += ImeIMPreset::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 3) {srefIxVScope = txtrd.fields[3]; ixWIelValid += ImeIMPreset::VecWIel::SREFIXVSCOPE;};
	if (txtrd.fields.size() > 4) {sref = txtrd.fields[4]; ixWIelValid += ImeIMPreset::VecWIel::SREF;};
	if (txtrd.fields.size() > 5) {srefIxWznmWArgtype = txtrd.fields[5]; ixWIelValid += ImeIMPreset::VecWIel::SREFIXWZNMWARGTYPE;};
	if (txtrd.fields.size() > 6) {Title = txtrd.fields[6]; ixWIelValid += ImeIMPreset::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMPRESETTITLE)) {
					imeijmpresettitle.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPreset"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMPreset::readXML(
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
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPreset::VecWIel::TITLE;
		imeijmpresettitle.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMPreset::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVIop::getSref(ixWznmVIop) << "\t" << VecWznmVMPresetRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << VecWznmVMPresetScope::getSref(ixVScope) << "\t" << sref << "\t" << VecWznmWArgtype::getSrefs(ixWznmWArgtype) << "\t" << Title << endl;
	imeijmpresettitle.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMPreset::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","ret","reu","sco","srf","aty","tit"};
	else tags = {"ImeitemIMPreset","srefIxWznmVIop","srefRefIxVTbl","srefRefUref","srefIxVScope","sref","srefIxWznmWArgtype","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], VecWznmVMPresetRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[3], srefRefUref);
		writeString(wr, tags[4], VecWznmVMPresetScope::getSref(ixVScope));
		writeString(wr, tags[5], sref);
		writeString(wr, tags[6], VecWznmWArgtype::getSrefs(ixWznmWArgtype));
		writeString(wr, tags[7], Title);
		imeijmpresettitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMPreset::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMPreset::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "srefixvscope") ix |= SREFIXVSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmwargtype") ix |= SREFIXWZNMWARGTYPE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmUix::ImeIMPreset::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMPreset::VecWIel::getSrefs(
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
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMPreset
 ******************************************************************************/

IexWznmUix::ImeIMPreset::ImeIMPreset() {
};

IexWznmUix::ImeIMPreset::~ImeIMPreset() {
	clear();
};

void IexWznmUix::ImeIMPreset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMPreset::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMPreset* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmUix::ImeitemIMPreset();
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

void IexWznmUix::ImeIMPreset::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMPreset* ii = NULL;

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

			ii = new IexWznmUix::ImeitemIMPreset();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMPreset::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMPreset." << StrMod::replaceChar(ImeIMPreset::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMPreset.end" << endl;
	};
};

void IexWznmUix::ImeIMPreset::writeXML(
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
 class IexWznmUix::ImeitemIAMQueryClause
 ******************************************************************************/

IexWznmUix::ImeitemIAMQueryClause::ImeitemIAMQueryClause(
			const ubigint irefX1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string& Clause
			, const string& srefRefWznmMPreset
			, const string& srefRefWznmMVector
			, const string& srefRefWznmMVectoritem
		) : WznmAMQueryClause() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefX1RefWznmMQuerymod = irefX1RefWznmMQuerymod;
	this->ixVBasetype = ixVBasetype;
	this->Clause = Clause;
	this->srefRefWznmMPreset = srefRefWznmMPreset;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmUix::ImeitemIAMQueryClause::ImeitemIAMQueryClause(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMQueryClause()
		{
	WznmAMQueryClause* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamqueryclause->loadRecByRef(ref, &rec)) {
		qryRefWznmMQuery = rec->qryRefWznmMQuery;
		x1RefWznmMQuerymod = rec->x1RefWznmMQuerymod;
		ixVBasetype = rec->ixVBasetype;
		Clause = rec->Clause;
		refWznmMPreset = rec->refWznmMPreset;
		refWznmMVector = rec->refWznmMVector;
		refWznmMVectoritem = rec->refWznmMVectoritem;

		delete rec;
	};
};

void IexWznmUix::ImeitemIAMQueryClause::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefX1RefWznmMQuerymod = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMQueryClause::VecWIel::IREFX1REFWZNMMQUERYMOD;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIAMQueryClause::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {Clause = txtrd.fields[2]; ixWIelValid += ImeIAMQueryClause::VecWIel::CLAUSE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMPreset = txtrd.fields[3]; ixWIelValid += ImeIAMQueryClause::VecWIel::SREFREFWZNMMPRESET;};
	if (txtrd.fields.size() > 4) {srefRefWznmMVector = txtrd.fields[4]; ixWIelValid += ImeIAMQueryClause::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 5) {srefRefWznmMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMQueryClause::VecWIel::SREFREFWZNMMVECTORITEM;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMQueryClause"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIAMQueryClause::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefX1RefWznmMQuerymod", "qmd", irefX1RefWznmMQuerymod)) ixWIelValid += ImeIAMQueryClause::VecWIel::IREFX1REFWZNMMQUERYMOD;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIAMQueryClause::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "Clause", "cse", Clause)) ixWIelValid += ImeIAMQueryClause::VecWIel::CLAUSE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMPreset", "pst", srefRefWznmMPreset)) ixWIelValid += ImeIAMQueryClause::VecWIel::SREFREFWZNMMPRESET;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMQueryClause::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMQueryClause::VecWIel::SREFREFWZNMMVECTORITEM;
	};
};

void IexWznmUix::ImeitemIAMQueryClause::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefX1RefWznmMQuerymod << "\t" << VecWznmVAMQueryClauseBasetype::getSref(ixVBasetype) << "\t" << Clause << "\t" << srefRefWznmMPreset << "\t" << srefRefWznmMVector << "\t" << srefRefWznmMVectoritem << endl;
};

void IexWznmUix::ImeitemIAMQueryClause::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","qmd","typ","cse","pst","vec","vit"};
	else tags = {"ImeitemIAMQueryClause","irefX1RefWznmMQuerymod","srefIxVBasetype","Clause","srefRefWznmMPreset","srefRefWznmMVector","srefRefWznmMVectoritem"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefX1RefWznmMQuerymod);
		writeString(wr, tags[2], VecWznmVAMQueryClauseBasetype::getSref(ixVBasetype));
		writeString(wr, tags[3], Clause);
		writeString(wr, tags[4], srefRefWznmMPreset);
		writeString(wr, tags[5], srefRefWznmMVector);
		writeString(wr, tags[6], srefRefWznmMVectoritem);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIAMQueryClause::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIAMQueryClause::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefx1refwznmmquerymod") ix |= IREFX1REFWZNMMQUERYMOD;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "clause") ix |= CLAUSE;
		else if (ss[i] == "srefrefwznmmpreset") ix |= SREFREFWZNMMPRESET;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
	};

	return(ix);
};

void IexWznmUix::ImeIAMQueryClause::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIAMQueryClause::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFX1REFWZNMMQUERYMOD) ss.push_back("irefX1RefWznmMQuerymod");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & CLAUSE) ss.push_back("Clause");
	if (ix & SREFREFWZNMMPRESET) ss.push_back("srefRefWznmMPreset");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIAMQueryClause
 ******************************************************************************/

IexWznmUix::ImeIAMQueryClause::ImeIAMQueryClause() {
};

IexWznmUix::ImeIAMQueryClause::~ImeIAMQueryClause() {
	clear();
};

void IexWznmUix::ImeIAMQueryClause::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIAMQueryClause::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIAMQueryClause* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIAMQueryClause();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMQueryClause"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMQueryClause"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMQUERYCLAUSE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMQueryClause"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMQueryClause"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIAMQueryClause::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIAMQueryClause* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMQueryClause");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMQueryClause", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMQueryClause";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIAMQueryClause();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIAMQueryClause::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMQueryClause." << StrMod::replaceChar(ImeIAMQueryClause::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMQueryClause.end" << endl;
	};
};

void IexWznmUix::ImeIAMQueryClause::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMQueryClause");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIAMQueryOrder
 ******************************************************************************/

IexWznmUix::ImeitemIAMQueryOrder::ImeitemIAMQueryOrder(
			const uint ixWznmVIop
			, const string& Short
			, const string& srefsWznmMTablecol
		) : WznmAMQueryOrder() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->Short = Short;
	this->srefsWznmMTablecol = srefsWznmMTablecol;
};

IexWznmUix::ImeitemIAMQueryOrder::ImeitemIAMQueryOrder(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIAMQueryOrder(ixWznmVIop)
		{
	WznmAMQueryOrder* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamqueryorder->loadRecByRef(ref, &rec)) {
		refWznmMQuery = rec->refWznmMQuery;
		Short = rec->Short;
		srefsWznmMTablecol = rec->srefsWznmMTablecol;

		delete rec;
	};
};

void IexWznmUix::ImeitemIAMQueryOrder::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIAMQueryOrder::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {Short = txtrd.fields[1]; ixWIelValid += ImeIAMQueryOrder::VecWIel::SHORT;};
	if (txtrd.fields.size() > 2) {srefsWznmMTablecol = txtrd.fields[2]; ixWIelValid += ImeIAMQueryOrder::VecWIel::SREFSWZNMMTABLECOL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMQueryOrder"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIAMQueryOrder::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIAMQueryOrder::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "Short", "tco", Short)) ixWIelValid += ImeIAMQueryOrder::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "srefsWznmMTablecol", "tco", srefsWznmMTablecol)) ixWIelValid += ImeIAMQueryOrder::VecWIel::SREFSWZNMMTABLECOL;
	};
};

void IexWznmUix::ImeitemIAMQueryOrder::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << Short << "\t" << srefsWznmMTablecol << endl;
};

void IexWznmUix::ImeitemIAMQueryOrder::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","tco","tco"};
	else tags = {"ImeitemIAMQueryOrder","srefIxWznmVIop","Short","srefsWznmMTablecol"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], Short);
		writeString(wr, tags[3], srefsWznmMTablecol);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIAMQueryOrder::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIAMQueryOrder::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "srefswznmmtablecol") ix |= SREFSWZNMMTABLECOL;
	};

	return(ix);
};

void IexWznmUix::ImeIAMQueryOrder::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSWZNMMTABLECOL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIAMQueryOrder::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & SREFSWZNMMTABLECOL) ss.push_back("srefsWznmMTablecol");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIAMQueryOrder
 ******************************************************************************/

IexWznmUix::ImeIAMQueryOrder::ImeIAMQueryOrder() {
};

IexWznmUix::ImeIAMQueryOrder::~ImeIAMQueryOrder() {
	clear();
};

void IexWznmUix::ImeIAMQueryOrder::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIAMQueryOrder::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIAMQueryOrder* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIAMQueryOrder();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMQueryOrder"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMQueryOrder"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMQUERYORDER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMQueryOrder"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMQueryOrder"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIAMQueryOrder::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIAMQueryOrder* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMQueryOrder");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMQueryOrder", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMQueryOrder";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIAMQueryOrder();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIAMQueryOrder::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMQueryOrder." << StrMod::replaceChar(ImeIAMQueryOrder::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMQueryOrder.end" << endl;
	};
};

void IexWznmUix::ImeIAMQueryOrder::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMQueryOrder");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIJMQuerycolStub
 ******************************************************************************/

IexWznmUix::ImeitemIJMQuerycolStub::ImeitemIJMQuerycolStub(
			const uint ixWznmVIop
			, const string& srefX1RefWznmMVectoritem
			, const string& srefX2RefWznmMPreset
			, const string& srefRefWznmMStub
		) : WznmJMQuerycolStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->srefX1RefWznmMVectoritem = srefX1RefWznmMVectoritem;
	this->srefX2RefWznmMPreset = srefX2RefWznmMPreset;
	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmUix::ImeitemIJMQuerycolStub::ImeitemIJMQuerycolStub(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIJMQuerycolStub(ixWznmVIop)
		{
	WznmJMQuerycolStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmquerycolstub->loadRecByRef(ref, &rec)) {
		refWznmMQuerycol = rec->refWznmMQuerycol;
		x1RefWznmMVectoritem = rec->x1RefWznmMVectoritem;
		x2RefWznmMPreset = rec->x2RefWznmMPreset;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmUix::ImeitemIJMQuerycolStub::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefX1RefWznmMVectoritem = txtrd.fields[1]; ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFX1REFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 2) {srefX2RefWznmMPreset = txtrd.fields[2]; ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFX2REFWZNMMPRESET;};
	if (txtrd.fields.size() > 3) {srefRefWznmMStub = txtrd.fields[3]; ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIJMQuerycolStub::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMVectoritem", "vit", srefX1RefWznmMVectoritem)) ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFX1REFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMPreset", "pst", srefX2RefWznmMPreset)) ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFX2REFWZNMMPRESET;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIJMQuerycolStub::VecWIel::SREFREFWZNMMSTUB;
	};
};

void IexWznmUix::ImeitemIJMQuerycolStub::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << srefX1RefWznmMVectoritem << "\t" << srefX2RefWznmMPreset << "\t" << srefRefWznmMStub << endl;
};

void IexWznmUix::ImeitemIJMQuerycolStub::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","vit","pst","stb"};
	else tags = {"ImeitemIJMQuerycolStub","srefIxWznmVIop","srefX1RefWznmMVectoritem","srefX2RefWznmMPreset","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], srefX1RefWznmMVectoritem);
		writeString(wr, tags[3], srefX2RefWznmMPreset);
		writeString(wr, tags[4], srefRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIJMQuerycolStub::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIJMQuerycolStub::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefx1refwznmmvectoritem") ix |= SREFX1REFWZNMMVECTORITEM;
		else if (ss[i] == "srefx2refwznmmpreset") ix |= SREFX2REFWZNMMPRESET;
		else if (ss[i] == "srefrefwznmmstub") ix |= SREFREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmUix::ImeIJMQuerycolStub::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIJMQuerycolStub::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFX1REFWZNMMVECTORITEM) ss.push_back("srefX1RefWznmMVectoritem");
	if (ix & SREFX2REFWZNMMPRESET) ss.push_back("srefX2RefWznmMPreset");
	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIJMQuerycolStub
 ******************************************************************************/

IexWznmUix::ImeIJMQuerycolStub::ImeIJMQuerycolStub() {
};

IexWznmUix::ImeIJMQuerycolStub::~ImeIJMQuerycolStub() {
	clear();
};

void IexWznmUix::ImeIJMQuerycolStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIJMQuerycolStub::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIJMQuerycolStub* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemIJMQuerycolStub();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMQUERYCOLSTUB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIJMQuerycolStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIJMQuerycolStub* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMQuerycolStub");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMQuerycolStub", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMQuerycolStub";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIJMQuerycolStub();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIJMQuerycolStub::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMQuerycolStub." << StrMod::replaceChar(ImeIJMQuerycolStub::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMQuerycolStub.end" << endl;
	};
};

void IexWznmUix::ImeIJMQuerycolStub::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMQuerycolStub");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMQuerycol
 ******************************************************************************/

IexWznmUix::ImeitemIMQuerycol::ImeitemIMQuerycol(
			const uint ixWznmVIop
			, const uint ixVBasetype
			, const uint ixWOccurrence
			, const string& srefRefWznmMTablecol
			, const string& sref
			, const string& Short
			, const string& srefRefWznmMStub
		) : WznmMQuerycol() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->ixVBasetype = ixVBasetype;
	this->ixWOccurrence = ixWOccurrence;
	this->srefRefWznmMTablecol = srefRefWznmMTablecol;
	this->sref = sref;
	this->Short = Short;
	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmUix::ImeitemIMQuerycol::ImeitemIMQuerycol(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMQuerycol(ixWznmVIop)
		{
	WznmMQuerycol* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmquerycol->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		ixWOccurrence = rec->ixWOccurrence;
		qryRefWznmMQuery = rec->qryRefWznmMQuery;
		qryNum = rec->qryNum;
		refWznmMTablecol = rec->refWznmMTablecol;
		sref = rec->sref;
		Short = rec->Short;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMQuerycol::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMQuerycol::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIMQuerycol::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {srefsIxWOccurrence = txtrd.fields[2]; ixWIelValid += ImeIMQuerycol::VecWIel::SREFSIXWOCCURRENCE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMTablecol = txtrd.fields[3]; ixWIelValid += ImeIMQuerycol::VecWIel::SREFREFWZNMMTABLECOL;};
	if (txtrd.fields.size() > 4) {sref = txtrd.fields[4]; ixWIelValid += ImeIMQuerycol::VecWIel::SREF;};
	if (txtrd.fields.size() > 5) {Short = txtrd.fields[5]; ixWIelValid += ImeIMQuerycol::VecWIel::SHORT;};
	if (txtrd.fields.size() > 6) {srefRefWznmMStub = txtrd.fields[6]; ixWIelValid += ImeIMQuerycol::VecWIel::SREFREFWZNMMSTUB;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMQUERYCOLSTUB)) {
					imeijmquerycolstub.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMQuerycol"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMQuerycol::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMQuerycol::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMQuerycol::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefsIxWOccurrence", "occ", srefsIxWOccurrence)) ixWIelValid += ImeIMQuerycol::VecWIel::SREFSIXWOCCURRENCE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTablecol", "tco", srefRefWznmMTablecol)) ixWIelValid += ImeIMQuerycol::VecWIel::SREFREFWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMQuerycol::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMQuerycol::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIMQuerycol::VecWIel::SREFREFWZNMMSTUB;
		imeijmquerycolstub.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMQuerycol::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << VecWznmVMQuerycolBasetype::getSref(ixVBasetype) << "\t" << VecWznmWMQuerycolOccurrence::getSrefs(ixWOccurrence) << "\t" << srefRefWznmMTablecol << "\t" << sref << "\t" << Short << "\t" << srefRefWznmMStub << endl;
	imeijmquerycolstub.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMQuerycol::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","typ","occ","tco","srf","sho","stb"};
	else tags = {"ImeitemIMQuerycol","srefIxWznmVIop","srefIxVBasetype","srefsIxWOccurrence","srefRefWznmMTablecol","sref","Short","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], VecWznmVMQuerycolBasetype::getSref(ixVBasetype));
		writeString(wr, tags[3], VecWznmWMQuerycolOccurrence::getSrefs(ixWOccurrence));
		writeString(wr, tags[4], srefRefWznmMTablecol);
		writeString(wr, tags[5], sref);
		writeString(wr, tags[6], Short);
		writeString(wr, tags[7], srefRefWznmMStub);
		imeijmquerycolstub.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMQuerycol::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMQuerycol::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefsixwoccurrence") ix |= SREFSIXWOCCURRENCE;
		else if (ss[i] == "srefrefwznmmtablecol") ix |= SREFREFWZNMMTABLECOL;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "srefrefwznmmstub") ix |= SREFREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmUix::ImeIMQuerycol::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMQuerycol::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFSIXWOCCURRENCE) ss.push_back("srefsIxWOccurrence");
	if (ix & SREFREFWZNMMTABLECOL) ss.push_back("srefRefWznmMTablecol");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMQuerycol
 ******************************************************************************/

IexWznmUix::ImeIMQuerycol::ImeIMQuerycol() {
};

IexWznmUix::ImeIMQuerycol::~ImeIMQuerycol() {
	clear();
};

void IexWznmUix::ImeIMQuerycol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMQuerycol::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMQuerycol* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIMQuerycol();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuerycol"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMQuerycol"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMQUERYCOL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuerycol"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuerycol"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMQuerycol::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMQuerycol* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMQuerycol");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMQuerycol", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMQuerycol";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMQuerycol();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMQuerycol::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMQuerycol." << StrMod::replaceChar(ImeIMQuerycol::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMQuerycol.end" << endl;
	};
};

void IexWznmUix::ImeIMQuerycol::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMQuerycol");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMQuerymod
 ******************************************************************************/

IexWznmUix::ImeitemIMQuerymod::ImeitemIMQuerymod(
			const uint ixWznmVIop
			, const ubigint iref
			, const uint ixVBasetype
			, const string& srefRefWznmMPreset
			, const uint refIxVTbl
			, const string& srefRefUref
			, const string& Avail
		) : WznmMQuerymod() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->iref = iref;
	this->ixVBasetype = ixVBasetype;
	this->srefRefWznmMPreset = srefRefWznmMPreset;
	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->Avail = Avail;
};

IexWznmUix::ImeitemIMQuerymod::ImeitemIMQuerymod(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMQuerymod(ixWznmVIop)
		{
	WznmMQuerymod* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmquerymod->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		qryRefWznmMQuery = rec->qryRefWznmMQuery;
		qryNum = rec->qryNum;
		refWznmMPreset = rec->refWznmMPreset;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		Avail = rec->Avail;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMQuerymod::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMQuerymod::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {iref = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMQuerymod::VecWIel::IREF;};
	if (txtrd.fields.size() > 2) {srefIxVBasetype = txtrd.fields[2]; ixWIelValid += ImeIMQuerymod::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMPreset = txtrd.fields[3]; ixWIelValid += ImeIMQuerymod::VecWIel::SREFREFWZNMMPRESET;};
	if (txtrd.fields.size() > 4) {srefRefIxVTbl = txtrd.fields[4]; ixWIelValid += ImeIMQuerymod::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 5) {srefRefUref = txtrd.fields[5]; ixWIelValid += ImeIMQuerymod::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 6) {Avail = txtrd.fields[6]; ixWIelValid += ImeIMQuerymod::VecWIel::AVAIL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMQuerymod"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMQuerymod::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMQuerymod::VecWIel::SREFIXWZNMVIOP;
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMQuerymod::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMQuerymod::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMPreset", "pst", srefRefWznmMPreset)) ixWIelValid += ImeIMQuerymod::VecWIel::SREFREFWZNMMPRESET;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMQuerymod::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMQuerymod::VecWIel::SREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMQuerymod::VecWIel::AVAIL;
	};
};

void IexWznmUix::ImeitemIMQuerymod::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << iref << "\t" << VecWznmVMQuerymodBasetype::getSref(ixVBasetype) << "\t" << srefRefWznmMPreset << "\t" << VecWznmVMQuerymodRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << Avail << endl;
};

void IexWznmUix::ImeitemIMQuerymod::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","irf","typ","pst","ret","reu","avl"};
	else tags = {"ImeitemIMQuerymod","srefIxWznmVIop","iref","srefIxVBasetype","srefRefWznmMPreset","srefRefIxVTbl","srefRefUref","Avail"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeUbigint(wr, tags[2], iref);
		writeString(wr, tags[3], VecWznmVMQuerymodBasetype::getSref(ixVBasetype));
		writeString(wr, tags[4], srefRefWznmMPreset);
		writeString(wr, tags[5], VecWznmVMQuerymodRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[6], srefRefUref);
		writeString(wr, tags[7], Avail);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMQuerymod::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMQuerymod::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwznmmpreset") ix |= SREFREFWZNMMPRESET;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "avail") ix |= AVAIL;
	};

	return(ix);
};

void IexWznmUix::ImeIMQuerymod::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*AVAIL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMQuerymod::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWZNMMPRESET) ss.push_back("srefRefWznmMPreset");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & AVAIL) ss.push_back("Avail");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMQuerymod
 ******************************************************************************/

IexWznmUix::ImeIMQuerymod::ImeIMQuerymod() {
};

IexWznmUix::ImeIMQuerymod::~ImeIMQuerymod() {
	clear();
};

void IexWznmUix::ImeIMQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMQuerymod::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMQuerymod* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIMQuerymod();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuerymod"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMQuerymod"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMQUERYMOD) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuerymod"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuerymod"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMQuerymod* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMQuerymod");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMQuerymod", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMQuerymod";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMQuerymod();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMQuerymod::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMQuerymod." << StrMod::replaceChar(ImeIMQuerymod::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMQuerymod.end" << endl;
	};
};

void IexWznmUix::ImeIMQuerymod::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMQuerymod");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemITMQuerymodMQuery
 ******************************************************************************/

IexWznmUix::ImeitemITMQuerymodMQuery::ImeitemITMQuerymodMQuery(
			const ubigint irefRefWznmMQuerymod
		) : WznmTMQuerymodMQuery() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmMQuerymod = irefRefWznmMQuerymod;
};

IexWznmUix::ImeitemITMQuerymodMQuery::ImeitemITMQuerymodMQuery(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemITMQuerymodMQuery()
		{
	WznmTMQuerymodMQuery* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmtmquerymodmquery->loadRecByRef(ref, &rec)) {
		refWznmMQuerymod = rec->refWznmMQuerymod;
		refR = rec->refR;

		delete rec;
	};
};

void IexWznmUix::ImeitemITMQuerymodMQuery::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmMQuerymod = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeITMQuerymodMQuery::VecWIel::IREFREFWZNMMQUERYMOD;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeITMQuerymodMQuery"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemITMQuerymodMQuery::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmMQuerymod", "qmd", irefRefWznmMQuerymod)) ixWIelValid += ImeITMQuerymodMQuery::VecWIel::IREFREFWZNMMQUERYMOD;
	};
};

void IexWznmUix::ImeitemITMQuerymodMQuery::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWznmMQuerymod << endl;
};

void IexWznmUix::ImeitemITMQuerymodMQuery::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","qmd"};
	else tags = {"ImeitemITMQuerymodMQuery","irefRefWznmMQuerymod"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmMQuerymod);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeITMQuerymodMQuery::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeITMQuerymodMQuery::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmmquerymod") ix |= IREFREFWZNMMQUERYMOD;
	};

	return(ix);
};

void IexWznmUix::ImeITMQuerymodMQuery::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREFREFWZNMMQUERYMOD); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeITMQuerymodMQuery::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMMQUERYMOD) ss.push_back("irefRefWznmMQuerymod");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeITMQuerymodMQuery
 ******************************************************************************/

IexWznmUix::ImeITMQuerymodMQuery::ImeITMQuerymodMQuery() {
};

IexWznmUix::ImeITMQuerymodMQuery::~ImeITMQuerymodMQuery() {
	clear();
};

void IexWznmUix::ImeITMQuerymodMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeITMQuerymodMQuery::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemITMQuerymodMQuery* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmUix::ImeitemITMQuerymodMQuery();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeITMQuerymodMQuery"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeITMQuerymodMQuery"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEITMQUERYMODMQUERY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeITMQuerymodMQuery"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeITMQuerymodMQuery"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeITMQuerymodMQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemITMQuerymodMQuery* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeITMQuerymodMQuery");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemITMQuerymodMQuery", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemITMQuerymodMQuery";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemITMQuerymodMQuery();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeITMQuerymodMQuery::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeITMQuerymodMQuery." << StrMod::replaceChar(ImeITMQuerymodMQuery::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeITMQuerymodMQuery.end" << endl;
	};
};

void IexWznmUix::ImeITMQuerymodMQuery::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeITMQuerymodMQuery");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIRMQueryMTable
 ******************************************************************************/

IexWznmUix::ImeitemIRMQueryMTable::ImeitemIRMQueryMTable(
			const string& srefRefWznmMTable
			, const bool Source
			, const string& Prefix
		) : WznmRMQueryMTable() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMTable = srefRefWznmMTable;
	this->Source = Source;
	this->Prefix = Prefix;
};

IexWznmUix::ImeitemIRMQueryMTable::ImeitemIRMQueryMTable(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMQueryMTable()
		{
	WznmRMQueryMTable* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmquerymtable->loadRecByRef(ref, &rec)) {
		refWznmMQuery = rec->refWznmMQuery;
		refWznmMTable = rec->refWznmMTable;
		Source = rec->Source;
		Prefix = rec->Prefix;

		delete rec;
	};
};

void IexWznmUix::ImeitemIRMQueryMTable::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMTable = txtrd.fields[0]; ixWIelValid += ImeIRMQueryMTable::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 1) {Source = (txtrd.fields[1] == "true"); ixWIelValid += ImeIRMQueryMTable::VecWIel::SOURCE;};
	if (txtrd.fields.size() > 2) {Prefix = txtrd.fields[2]; ixWIelValid += ImeIRMQueryMTable::VecWIel::PREFIX;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEITMQUERYMODMQUERY)) {
					imeitmquerymodmquery.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMQueryMTable"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIRMQueryMTable::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIRMQueryMTable::VecWIel::SREFREFWZNMMTABLE;
		if (extractBoolUclc(docctx, basexpath, "Source", "src", Source)) ixWIelValid += ImeIRMQueryMTable::VecWIel::SOURCE;
		if (extractStringUclc(docctx, basexpath, "Prefix", "pfx", Prefix)) ixWIelValid += ImeIRMQueryMTable::VecWIel::PREFIX;
		imeitmquerymodmquery.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIRMQueryMTable::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMTable << "\t" << StrMod::boolToString(Source) << "\t" << Prefix << endl;
	imeitmquerymodmquery.writeTxt(outfile);
};

void IexWznmUix::ImeitemIRMQueryMTable::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tbl","src","pfx"};
	else tags = {"ImeitemIRMQueryMTable","srefRefWznmMTable","Source","Prefix"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMTable);
		writeBool(wr, tags[2], Source);
		writeString(wr, tags[3], Prefix);
		imeitmquerymodmquery.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIRMQueryMTable::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIRMQueryMTable::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "source") ix |= SOURCE;
		else if (ss[i] == "prefix") ix |= PREFIX;
	};

	return(ix);
};

void IexWznmUix::ImeIRMQueryMTable::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*PREFIX); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIRMQueryMTable::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & SOURCE) ss.push_back("Source");
	if (ix & PREFIX) ss.push_back("Prefix");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIRMQueryMTable
 ******************************************************************************/

IexWznmUix::ImeIRMQueryMTable::ImeIRMQueryMTable() {
};

IexWznmUix::ImeIRMQueryMTable::~ImeIRMQueryMTable() {
	clear();
};

void IexWznmUix::ImeIRMQueryMTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIRMQueryMTable::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIRMQueryMTable* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmUix::ImeitemIRMQueryMTable();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMQueryMTable"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMQueryMTable"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMQUERYMTABLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMQueryMTable"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMQueryMTable"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIRMQueryMTable::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIRMQueryMTable* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMQueryMTable");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMQueryMTable", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMQueryMTable";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIRMQueryMTable();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIRMQueryMTable::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMQueryMTable." << StrMod::replaceChar(ImeIRMQueryMTable::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMQueryMTable.end" << endl;
	};
};

void IexWznmUix::ImeIRMQueryMTable::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMQueryMTable");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIMQuery
 ******************************************************************************/

IexWznmUix::ImeitemIMQuery::ImeitemIMQuery(
			const uint ixWznmVIop
			, const ubigint iref
			, const uint ixVBasetype
			, const ubigint irefSupRefWznmMQuery
			, const uint supIxVSubrole
			, const string& sref
			, const bool Limofs
			, const string& Comment
		) : WznmMQuery() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->iref = iref;
	this->ixVBasetype = ixVBasetype;
	this->irefSupRefWznmMQuery = irefSupRefWznmMQuery;
	this->supIxVSubrole = supIxVSubrole;
	this->sref = sref;
	this->Limofs = Limofs;
	this->Comment = Comment;
};

IexWznmUix::ImeitemIMQuery::ImeitemIMQuery(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMQuery(ixWznmVIop)
		{
	WznmMQuery* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmquery->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		supRefWznmMQuery = rec->supRefWznmMQuery;
		supIxVSubrole = rec->supIxVSubrole;
		refRTable = rec->refRTable;
		refWznmMTable = rec->refWznmMTable;
		sref = rec->sref;
		inoRefAOrder = rec->inoRefAOrder;
		Limofs = rec->Limofs;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmUix::ImeitemIMQuery::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMQuery::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {iref = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMQuery::VecWIel::IREF;};
	if (txtrd.fields.size() > 2) {srefIxVBasetype = txtrd.fields[2]; ixWIelValid += ImeIMQuery::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 3) {irefSupRefWznmMQuery = atoll(txtrd.fields[3].c_str()); ixWIelValid += ImeIMQuery::VecWIel::IREFSUPREFWZNMMQUERY;};
	if (txtrd.fields.size() > 4) {srefSupIxVSubrole = txtrd.fields[4]; ixWIelValid += ImeIMQuery::VecWIel::SREFSUPIXVSUBROLE;};
	if (txtrd.fields.size() > 5) {sref = txtrd.fields[5]; ixWIelValid += ImeIMQuery::VecWIel::SREF;};
	if (txtrd.fields.size() > 6) {Limofs = (txtrd.fields[6] == "true"); ixWIelValid += ImeIMQuery::VecWIel::LIMOFS;};
	if (txtrd.fields.size() > 7) {Comment = txtrd.fields[7]; ixWIelValid += ImeIMQuery::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMQUERYCLAUSE)) {
					imeiamqueryclause.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMQUERYORDER)) {
					imeiamqueryorder.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMQUERYCOL)) {
					imeimquerycol.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMQUERYMOD)) {
					imeimquerymod.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMQUERYMTABLE)) {
					imeirmquerymtable.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMQuery"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIMQuery::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMQuery::VecWIel::SREFIXWZNMVIOP;
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMQuery::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMQuery::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefWznmMQuery", "sup", irefSupRefWznmMQuery)) ixWIelValid += ImeIMQuery::VecWIel::IREFSUPREFWZNMMQUERY;
		if (extractStringUclc(docctx, basexpath, "srefSupIxVSubrole", "srl", srefSupIxVSubrole)) ixWIelValid += ImeIMQuery::VecWIel::SREFSUPIXVSUBROLE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMQuery::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Limofs", "lof", Limofs)) ixWIelValid += ImeIMQuery::VecWIel::LIMOFS;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMQuery::VecWIel::COMMENT;
		imeiamqueryclause.readXML(docctx, basexpath);
		imeiamqueryorder.readXML(docctx, basexpath);
		imeimquerycol.readXML(docctx, basexpath);
		imeimquerymod.readXML(docctx, basexpath);
		imeirmquerymtable.readXML(docctx, basexpath);
	};
};

void IexWznmUix::ImeitemIMQuery::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVIop::getSref(ixWznmVIop) << "\t" << iref << "\t" << VecWznmVMQueryBasetype::getSref(ixVBasetype) << "\t" << irefSupRefWznmMQuery << "\t" << VecWznmVMQuerySupSubrole::getSref(supIxVSubrole) << "\t" << sref << "\t" << StrMod::boolToString(Limofs) << "\t" << Comment << endl;
	imeiamqueryclause.writeTxt(outfile);
	imeiamqueryorder.writeTxt(outfile);
	imeimquerycol.writeTxt(outfile);
	imeimquerymod.writeTxt(outfile);
	imeirmquerymtable.writeTxt(outfile);
};

void IexWznmUix::ImeitemIMQuery::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","irf","typ","sup","srl","srf","lof","cmt"};
	else tags = {"ImeitemIMQuery","srefIxWznmVIop","iref","srefIxVBasetype","irefSupRefWznmMQuery","srefSupIxVSubrole","sref","Limofs","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeUbigint(wr, tags[2], iref);
		writeString(wr, tags[3], VecWznmVMQueryBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[4], irefSupRefWznmMQuery);
		writeString(wr, tags[5], VecWznmVMQuerySupSubrole::getSref(supIxVSubrole));
		writeString(wr, tags[6], sref);
		writeBool(wr, tags[7], Limofs);
		writeString(wr, tags[8], Comment);
		imeiamqueryclause.writeXML(wr, shorttags);
		imeiamqueryorder.writeXML(wr, shorttags);
		imeimquerycol.writeXML(wr, shorttags);
		imeimquerymod.writeXML(wr, shorttags);
		imeirmquerymtable.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIMQuery::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIMQuery::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefsuprefwznmmquery") ix |= IREFSUPREFWZNMMQUERY;
		else if (ss[i] == "srefsupixvsubrole") ix |= SREFSUPIXVSUBROLE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "limofs") ix |= LIMOFS;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmUix::ImeIMQuery::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIMQuery::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFSUPREFWZNMMQUERY) ss.push_back("irefSupRefWznmMQuery");
	if (ix & SREFSUPIXVSUBROLE) ss.push_back("srefSupIxVSubrole");
	if (ix & SREF) ss.push_back("sref");
	if (ix & LIMOFS) ss.push_back("Limofs");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIMQuery
 ******************************************************************************/

IexWznmUix::ImeIMQuery::ImeIMQuery() {
};

IexWznmUix::ImeIMQuery::~ImeIMQuery() {
	clear();
};

void IexWznmUix::ImeIMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIMQuery::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIMQuery* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmUix::ImeitemIMQuery();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMQuery"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMQUERY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuery"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMQuery"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIMQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIMQuery* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMQuery");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMQuery", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMQuery";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIMQuery();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIMQuery::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMQuery." << StrMod::replaceChar(ImeIMQuery::VecWIel::getSrefs(255), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMQuery.end" << endl;
	};
};

void IexWznmUix::ImeIMQuery::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMQuery");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmUix::ImeitemIRMPanelMQuery
 ******************************************************************************/

IexWznmUix::ImeitemIRMPanelMQuery::ImeitemIRMPanelMQuery(
			const string& srefRefWznmMPanel
			, const string& srefRefWznmMQuery
		) : WznmRMPanelMQuery() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMPanel = srefRefWznmMPanel;
	this->srefRefWznmMQuery = srefRefWznmMQuery;
};

IexWznmUix::ImeitemIRMPanelMQuery::ImeitemIRMPanelMQuery(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMPanelMQuery()
		{
	WznmRMPanelMQuery* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmpanelmquery->loadRecByRef(ref, &rec)) {
		refWznmMPanel = rec->refWznmMPanel;
		refWznmMQuery = rec->refWznmMQuery;

		delete rec;
	};
};

void IexWznmUix::ImeitemIRMPanelMQuery::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMPanel = txtrd.fields[0]; ixWIelValid += ImeIRMPanelMQuery::VecWIel::SREFREFWZNMMPANEL;};
	if (txtrd.fields.size() > 1) {srefRefWznmMQuery = txtrd.fields[1]; ixWIelValid += ImeIRMPanelMQuery::VecWIel::SREFREFWZNMMQUERY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMPanelMQuery"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmUix::ImeitemIRMPanelMQuery::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMPanel", "pnl", srefRefWznmMPanel)) ixWIelValid += ImeIRMPanelMQuery::VecWIel::SREFREFWZNMMPANEL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMQuery", "qry", srefRefWznmMQuery)) ixWIelValid += ImeIRMPanelMQuery::VecWIel::SREFREFWZNMMQUERY;
	};
};

void IexWznmUix::ImeitemIRMPanelMQuery::writeTxt(
			fstream& outfile
		) {
	outfile << srefRefWznmMPanel << "\t" << srefRefWznmMQuery << endl;
};

void IexWznmUix::ImeitemIRMPanelMQuery::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","pnl","qry"};
	else tags = {"ImeitemIRMPanelMQuery","srefRefWznmMPanel","srefRefWznmMQuery"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMPanel);
		writeString(wr, tags[2], srefRefWznmMQuery);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmUix::ImeIRMPanelMQuery::VecWIel
 ******************************************************************************/

uint IexWznmUix::ImeIRMPanelMQuery::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmpanel") ix |= SREFREFWZNMMPANEL;
		else if (ss[i] == "srefrefwznmmquery") ix |= SREFREFWZNMMQUERY;
	};

	return(ix);
};

void IexWznmUix::ImeIRMPanelMQuery::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMQUERY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmUix::ImeIRMPanelMQuery::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMPANEL) ss.push_back("srefRefWznmMPanel");
	if (ix & SREFREFWZNMMQUERY) ss.push_back("srefRefWznmMQuery");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmUix::ImeIRMPanelMQuery
 ******************************************************************************/

IexWznmUix::ImeIRMPanelMQuery::ImeIRMPanelMQuery() {
};

IexWznmUix::ImeIRMPanelMQuery::~ImeIRMPanelMQuery() {
	clear();
};

void IexWznmUix::ImeIRMPanelMQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmUix::ImeIRMPanelMQuery::readTxt(
			Txtrd& txtrd
		) {
	IexWznmUix::ImeitemIRMPanelMQuery* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmUix::ImeitemIRMPanelMQuery();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMPanelMQuery"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMPANELMQUERY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPanelMQuery"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPanelMQuery"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmUix::ImeIRMPanelMQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmUix::ImeitemIRMPanelMQuery* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMPanelMQuery");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMPanelMQuery", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMPanelMQuery";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmUix::ImeitemIRMPanelMQuery();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmUix::ImeIRMPanelMQuery::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIRMPanelMQuery." << StrMod::replaceChar(ImeIRMPanelMQuery::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIRMPanelMQuery.end" << endl;
	};
};

void IexWznmUix::ImeIRMPanelMQuery::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMPanelMQuery");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmUix
 ******************************************************************************/

void IexWznmUix::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMCard& imeimcard
			, ImeIMPreset& imeimpreset
			, ImeIMQuery& imeimquery
			, ImeIRMPanelMQuery& imeirmpanelmquery
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimcard, imeimpreset, imeimquery, imeirmpanelmquery);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmUix", Version("0.9.23"), VecVIme::getIx);
			readTxt(rd, imeimcard, imeimpreset, imeimquery, imeirmpanelmquery);
	};
};

void IexWznmUix::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMCard& imeimcard
			, ImeIMPreset& imeimpreset
			, ImeIMQuery& imeimquery
			, ImeIRMPanelMQuery& imeirmpanelmquery
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimcard, imeimpreset, imeimquery, imeirmpanelmquery);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimcard, imeimpreset, imeimquery, imeirmpanelmquery);
		txtfile.close();
	};
};

void IexWznmUix::readTxt(
			Txtrd& txtrd
			, ImeIMCard& imeimcard
			, ImeIMPreset& imeimpreset
			, ImeIMQuery& imeimquery
			, ImeIRMPanelMQuery& imeirmpanelmquery
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCARD)) imeimcard.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMPRESET)) imeimpreset.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMQUERY)) imeimquery.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIRMPANELMQUERY)) imeirmpanelmquery.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmUix::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMCard& imeimcard
			, ImeIMPreset& imeimpreset
			, ImeIMQuery& imeimquery
			, ImeIRMPanelMQuery& imeirmpanelmquery
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmUix")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.23")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.23"}});
		};

		// look for XML sub-blocks
		imeimcard.readXML(docctx, basexpath);
		imeimpreset.readXML(docctx, basexpath);
		imeimquery.readXML(docctx, basexpath);
		imeirmpanelmquery.readXML(docctx, basexpath);

	} else {
		imeimcard = ImeIMCard();
		imeimpreset = ImeIMPreset();
		imeimquery = ImeIMQuery();
		imeirmpanelmquery = ImeIRMPanelMQuery();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmUix"}});
	};
};

void IexWznmUix::writeTxt(
			fstream& outfile
			, ImeIMCard& imeimcard
			, ImeIMPreset& imeimpreset
			, ImeIMQuery& imeimquery
			, ImeIRMPanelMQuery& imeirmpanelmquery
		) {
	outfile << "IexWznmUix v" WZNM_VERSION << endl;

	imeimcard.writeTxt(outfile);
	imeimpreset.writeTxt(outfile);
	imeimquery.writeTxt(outfile);
	imeirmpanelmquery.writeTxt(outfile);
};

void IexWznmUix::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMCard& imeimcard
			, ImeIMPreset& imeimpreset
			, ImeIMQuery& imeimquery
			, ImeIRMPanelMQuery& imeirmpanelmquery
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmUix");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimcard.writeXML(wr, shorttags);
		imeimpreset.writeXML(wr, shorttags);
		imeimquery.writeXML(wr, shorttags);
		imeirmpanelmquery.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmUix::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMCONTROLPAR1,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMCONTROLPAR2,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMCONTROLPAR3,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMQUERYCLAUSE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMQUERYORDER,VecWznmVIop::INS},{(uint)VecVIme::IMEICCONTROL2,VecWznmVIop::INS},{(uint)VecVIme::IMEICCONTROL3,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMCONTROL2,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMCONTROL3,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMCONTROLTITLE1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMCONTROLTITLE2,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMCONTROLTITLE3,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMPRESETTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMQUERYCOLSTUB,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCONTROL1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCONTROL2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCONTROL3,VecWznmVIop::INS},{(uint)VecVIme::IMEIMDIALOG,VecWznmVIop::INS},{(uint)VecVIme::IMEIMFEED2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMFEED3,VecWznmVIop::INS},{(uint)VecVIme::IMEIMPANEL,VecWznmVIop::INS},{(uint)VecVIme::IMEIMPRESET,VecWznmVIop::INS},{(uint)VecVIme::IMEIMQUERY,VecWznmVIop::INS},{(uint)VecVIme::IMEIMQUERYCOL,VecWznmVIop::INS},{(uint)VecVIme::IMEIMQUERYMOD,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTOR2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTOR3,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMPANELMQUERY,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMQUERYMTABLE,VecWznmVIop::INS},{(uint)VecVIme::IMEITMQUERYMODMQUERY,VecWznmVIop::INS}};
};

uint IexWznmUix::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};



