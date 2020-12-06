/**
	* \file IexWznmIni.cpp
	* data blocks and readers/writers for import/export complex IexWznmIni (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWznmIni.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmIni::VecVIme
 ******************************************************************************/

uint IexWznmIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamcapabilitypar") return IMEIAMCAPABILITYPAR;
	if (s == "imeiamlibrarymakefile") return IMEIAMLIBRARYMAKEFILE;
	if (s == "imeiamlibrarypkglist") return IMEIAMLIBRARYPKGLIST;
	if (s == "imeiammachinemakefile") return IMEIAMMACHINEMAKEFILE;
	if (s == "imeiammachinepar") return IMEIAMMACHINEPAR;
	if (s == "imeiamuseraccess") return IMEIAMUSERACCESS;
	if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	if (s == "imeiavkeylistkey1") return IMEIAVKEYLISTKEY1;
	if (s == "imeiavkeylistkey2") return IMEIAVKEYLISTKEY2;
	if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	if (s == "imeijavkeylistkey1") return IMEIJAVKEYLISTKEY1;
	if (s == "imeijavkeylistkey2") return IMEIJAVKEYLISTKEY2;
	if (s == "imeijmlocaletitle") return IMEIJMLOCALETITLE;
	if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	if (s == "imeijmtagtitle1") return IMEIJMTAGTITLE1;
	if (s == "imeijmtagtitle2") return IMEIJMTAGTITLE2;
	if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	if (s == "imeimcapability") return IMEIMCAPABILITY;
	if (s == "imeimfile") return IMEIMFILE;
	if (s == "imeimlibrary") return IMEIMLIBRARY;
	if (s == "imeimlocale") return IMEIMLOCALE;
	if (s == "imeimmachine") return IMEIMMACHINE;
	if (s == "imeimperson") return IMEIMPERSON;
	if (s == "imeimtag1") return IMEIMTAG1;
	if (s == "imeimtag2") return IMEIMTAG2;
	if (s == "imeimuser") return IMEIMUSER;
	if (s == "imeimusergroup") return IMEIMUSERGROUP;
	if (s == "imeirmcapabilityuniversal") return IMEIRMCAPABILITYUNIVERSAL;

	return(0);
};

string IexWznmIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMCAPABILITYPAR) return("ImeIAMCapabilityPar");
	if (ix == IMEIAMLIBRARYMAKEFILE) return("ImeIAMLibraryMakefile");
	if (ix == IMEIAMLIBRARYPKGLIST) return("ImeIAMLibraryPkglist");
	if (ix == IMEIAMMACHINEMAKEFILE) return("ImeIAMMachineMakefile");
	if (ix == IMEIAMMACHINEPAR) return("ImeIAMMachinePar");
	if (ix == IMEIAMUSERACCESS) return("ImeIAMUserAccess");
	if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	if (ix == IMEIAVKEYLISTKEY1) return("ImeIAVKeylistKey1");
	if (ix == IMEIAVKEYLISTKEY2) return("ImeIAVKeylistKey2");
	if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	if (ix == IMEIJAVKEYLISTKEY1) return("ImeIJAVKeylistKey1");
	if (ix == IMEIJAVKEYLISTKEY2) return("ImeIJAVKeylistKey2");
	if (ix == IMEIJMLOCALETITLE) return("ImeIJMLocaleTitle");
	if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	if (ix == IMEIJMTAGTITLE1) return("ImeIJMTagTitle1");
	if (ix == IMEIJMTAGTITLE2) return("ImeIJMTagTitle2");
	if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	if (ix == IMEIMCAPABILITY) return("ImeIMCapability");
	if (ix == IMEIMFILE) return("ImeIMFile");
	if (ix == IMEIMLIBRARY) return("ImeIMLibrary");
	if (ix == IMEIMLOCALE) return("ImeIMLocale");
	if (ix == IMEIMMACHINE) return("ImeIMMachine");
	if (ix == IMEIMPERSON) return("ImeIMPerson");
	if (ix == IMEIMTAG1) return("ImeIMTag1");
	if (ix == IMEIMTAG2) return("ImeIMTag2");
	if (ix == IMEIMUSER) return("ImeIMUser");
	if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");
	if (ix == IMEIRMCAPABILITYUNIVERSAL) return("ImeIRMCapabilityUniversal");

	return("");
};

/******************************************************************************
 class IexWznmIni::ImeitemIAVControlPar
 ******************************************************************************/

IexWznmIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixWznmVControl
			, const string& Par
			, const string& Val
		) : WznmAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVControl = ixWznmVControl;
	this->Par = Par;
	this->Val = Val;
};

IexWznmIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAVControlPar()
		{
	WznmAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmavcontrolpar->loadRecByRef(ref, &rec)) {
		ixWznmVControl = rec->ixWznmVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVControl = txtrd.fields[0]; ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWZNMVCONTROL;};
	if (txtrd.fields.size() > 1) {Par = txtrd.fields[1]; ixWIelValid += ImeIAVControlPar::VecWIel::PAR;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVControlPar::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVControl", "ctl", srefIxWznmVControl)) ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWZNMVCONTROL;
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexWznmIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVControl::getSref(ixWznmVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexWznmIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxWznmVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVControl::getSref(ixWznmVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmvcontrol") ix |= SREFIXWZNMVCONTROL;
		else if (ss[i] == "par") ix |= PAR;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVCONTROL) ss.push_back("srefIxWznmVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAVControlPar
 ******************************************************************************/

IexWznmIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexWznmIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexWznmIni::ImeIAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIAVControlPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVControlPar.end" << endl;
	};
};

void IexWznmIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJAVKeylistKey1
 ******************************************************************************/

IexWznmIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			const uint x1IxWznmVLocale
			, const string& Title
			, const string& Comment
		) : WznmJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWznmVLocale = x1IxWznmVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey1()
		{
	WznmJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjavkeylistkey->loadRecByRef(ref, &rec)) {
		refWznmAVKeylistKey = rec->refWznmAVKeylistKey;
		x1IxWznmVLocale = rec->x1IxWznmVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWznmVLocale = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey1::VecWIel::SREFX1IXWZNMVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJAVKeylistKey1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWznmVLocale", "lcl", srefX1IxWznmVLocale)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::SREFX1IXWZNMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::COMMENT;
	};
};

void IexWznmIni::ImeitemIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVLocale::getSref(x1IxWznmVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmIni::ImeitemIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey1","srefX1IxWznmVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVLocale::getSref(x1IxWznmVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwznmvlocale") ix |= SREFX1IXWZNMVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIJAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZNMVLOCALE) ss.push_back("srefX1IxWznmVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIJAVKeylistKey1
 ******************************************************************************/

IexWznmIni::ImeIJAVKeylistKey1::ImeIJAVKeylistKey1() {
};

IexWznmIni::ImeIJAVKeylistKey1::~ImeIJAVKeylistKey1() {
	clear();
};

void IexWznmIni::ImeIJAVKeylistKey1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIJAVKeylistKey1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey1." << StrMod::replaceChar(ImeIJAVKeylistKey1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJAVKeylistKey1.end" << endl;
	};
};

void IexWznmIni::ImeIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAVKeylistKey1
 ******************************************************************************/

IexWznmIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			const uint klsIxWznmVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
			, const string& Title
			, const string& Comment
		) : WznmAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxWznmVKeylist = klsIxWznmVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey1()
		{
	WznmAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWznmVKeylist = rec->klsIxWznmVKeylist;
		klsNum = rec->klsNum;
		x1IxWznmVMaintable = rec->x1IxWznmVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxWznmVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREFKLSIXWZNMVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Avail = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 3) {Implied = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1)) {
					imeijavkeylistkey1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxWznmVKeylist", "kls", srefKlsIxWznmVKeylist)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREFKLSIXWZNMVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::COMMENT;
		imeijavkeylistkey1.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVKeylist::getSref(klsIxWznmVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey1.writeTxt(outfile);
};

void IexWznmIni::ImeitemIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey1","srefKlsIxWznmVKeylist","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVKeylist::getSref(klsIxWznmVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		writeString(wr, tags[5], Title);
		writeString(wr, tags[6], Comment);
		imeijavkeylistkey1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixwznmvkeylist") ix |= SREFKLSIXWZNMVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXWZNMVKEYLIST) ss.push_back("srefKlsIxWznmVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAVKeylistKey1
 ******************************************************************************/

IexWznmIni::ImeIAVKeylistKey1::ImeIAVKeylistKey1() {
};

IexWznmIni::ImeIAVKeylistKey1::~ImeIAVKeylistKey1() {
	clear();
};

void IexWznmIni::ImeIAVKeylistKey1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIAVKeylistKey1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey1." << StrMod::replaceChar(ImeIAVKeylistKey1::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVKeylistKey1.end" << endl;
	};
};

void IexWznmIni::ImeIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexWznmIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxWznmVValuelist
			, const uint x1IxWznmVLocale
			, const string& Val
		) : WznmAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxWznmVValuelist = vlsIxWznmVValuelist;
	this->x1IxWznmVLocale = x1IxWznmVLocale;
	this->Val = Val;
};

IexWznmIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAVValuelistVal()
		{
	WznmAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxWznmVValuelist = rec->vlsIxWznmVValuelist;
		vlsNum = rec->vlsNum;
		x1IxWznmVLocale = rec->x1IxWznmVLocale;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefVlsIxWznmVValuelist = txtrd.fields[0]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWZNMVVALUELIST;};
	if (txtrd.fields.size() > 1) {srefX1IxWznmVLocale = txtrd.fields[1]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWZNMVLOCALE;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxWznmVValuelist", "vls", srefVlsIxWznmVValuelist)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWZNMVVALUELIST;
		if (extractStringUclc(docctx, basexpath, "srefX1IxWznmVLocale", "lcl", srefX1IxWznmVLocale)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWZNMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexWznmIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVValuelist::getSref(vlsIxWznmVValuelist) << "\t" << VecWznmVLocale::getSref(x1IxWznmVLocale) << "\t" << Val << endl;
};

void IexWznmIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxWznmVValuelist","srefX1IxWznmVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVValuelist::getSref(vlsIxWznmVValuelist));
		writeString(wr, tags[2], VecWznmVLocale::getSref(x1IxWznmVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefvlsixwznmvvaluelist") ix |= SREFVLSIXWZNMVVALUELIST;
		else if (ss[i] == "srefx1ixwznmvlocale") ix |= SREFX1IXWZNMVLOCALE;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXWZNMVVALUELIST) ss.push_back("srefVlsIxWznmVValuelist");
	if (ix & SREFX1IXWZNMVLOCALE) ss.push_back("srefX1IxWznmVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAVValuelistVal
 ******************************************************************************/

IexWznmIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexWznmIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexWznmIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIAVValuelistVal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVValuelistVal.end" << endl;
	};
};

void IexWznmIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMCapabilityPar
 ******************************************************************************/

IexWznmIni::ImeitemIAMCapabilityPar::ImeitemIAMCapabilityPar(
			const string& x1SrefKKey
			, const string& Val
		) : WznmAMCapabilityPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWznmIni::ImeitemIAMCapabilityPar::ImeitemIAMCapabilityPar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMCapabilityPar()
		{
	WznmAMCapabilityPar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamcapabilitypar->loadRecByRef(ref, &rec)) {
		cpbRefWznmMCapability = rec->cpbRefWznmMCapability;
		cpbNum = rec->cpbNum;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMCapabilityPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMCapabilityPar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMCapabilityPar::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMCapabilityPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMCapabilityPar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMCapabilityPar::VecWIel::VAL;
	};
};

void IexWznmIni::ImeitemIAMCapabilityPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWznmIni::ImeitemIAMCapabilityPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMCapabilityPar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMCapabilityPar::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMCapabilityPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmIni::ImeIAMCapabilityPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMCapabilityPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMCapabilityPar
 ******************************************************************************/

IexWznmIni::ImeIAMCapabilityPar::ImeIAMCapabilityPar() {
};

IexWznmIni::ImeIAMCapabilityPar::~ImeIAMCapabilityPar() {
	clear();
};

void IexWznmIni::ImeIAMCapabilityPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMCapabilityPar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMCapabilityPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAMCapabilityPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCAPABILITYPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMCapabilityPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMCapabilityPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCapabilityPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCapabilityPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCapabilityPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMCapabilityPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMCapabilityPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMCapabilityPar." << StrMod::replaceChar(ImeIAMCapabilityPar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMCapabilityPar.end" << endl;
	};
};

void IexWznmIni::ImeIAMCapabilityPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCapabilityPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJAVKeylistKey2
 ******************************************************************************/

IexWznmIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			const uint x1IxWznmVLocale
			, const string& Title
			, const string& Comment
		) : WznmJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWznmVLocale = x1IxWznmVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey2()
		{
	WznmJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjavkeylistkey->loadRecByRef(ref, &rec)) {
		refWznmAVKeylistKey = rec->refWznmAVKeylistKey;
		x1IxWznmVLocale = rec->x1IxWznmVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWznmVLocale = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey2::VecWIel::SREFX1IXWZNMVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJAVKeylistKey2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWznmVLocale", "lcl", srefX1IxWznmVLocale)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::SREFX1IXWZNMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::COMMENT;
	};
};

void IexWznmIni::ImeitemIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVLocale::getSref(x1IxWznmVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmIni::ImeitemIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey2","srefX1IxWznmVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVLocale::getSref(x1IxWznmVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwznmvlocale") ix |= SREFX1IXWZNMVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIJAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZNMVLOCALE) ss.push_back("srefX1IxWznmVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIJAVKeylistKey2
 ******************************************************************************/

IexWznmIni::ImeIJAVKeylistKey2::ImeIJAVKeylistKey2() {
};

IexWznmIni::ImeIJAVKeylistKey2::~ImeIJAVKeylistKey2() {
	clear();
};

void IexWznmIni::ImeIJAVKeylistKey2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmIni::ImeitemIJAVKeylistKey2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey2." << StrMod::replaceChar(ImeIJAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJAVKeylistKey2.end" << endl;
	};
};

void IexWznmIni::ImeIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAVKeylistKey2
 ******************************************************************************/

IexWznmIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			const uint klsIxWznmVKeylist
			, const string& sref
			, const string& Title
			, const string& Comment
		) : WznmAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxWznmVKeylist = klsIxWznmVKeylist;
	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey2()
		{
	WznmAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWznmVKeylist = rec->klsIxWznmVKeylist;
		klsNum = rec->klsNum;
		x1IxWznmVMaintable = rec->x1IxWznmVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxWznmVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREFKLSIXWZNMVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2)) {
					imeijavkeylistkey2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxWznmVKeylist", "kls", srefKlsIxWznmVKeylist)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREFKLSIXWZNMVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::COMMENT;
		imeijavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVKeylist::getSref(klsIxWznmVKeylist) << "\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey2.writeTxt(outfile);
};

void IexWznmIni::ImeitemIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey2","srefKlsIxWznmVKeylist","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVKeylist::getSref(klsIxWznmVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Comment);
		imeijavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixwznmvkeylist") ix |= SREFKLSIXWZNMVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXWZNMVKEYLIST) ss.push_back("srefKlsIxWznmVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAVKeylistKey2
 ******************************************************************************/

IexWznmIni::ImeIAVKeylistKey2::ImeIAVKeylistKey2() {
};

IexWznmIni::ImeIAVKeylistKey2::~ImeIAVKeylistKey2() {
	clear();
};

void IexWznmIni::ImeIAVKeylistKey2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAVKeylistKey2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey2." << StrMod::replaceChar(ImeIAVKeylistKey2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAVKeylistKey2.end" << endl;
	};
};

void IexWznmIni::ImeIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJMTagTitle2
 ******************************************************************************/

IexWznmIni::ImeitemIJMTagTitle2::ImeitemIJMTagTitle2(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMTagTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmIni::ImeitemIJMTagTitle2::ImeitemIJMTagTitle2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMTagTitle2()
		{
	WznmJMTagTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmtagtitle->loadRecByRef(ref, &rec)) {
		refWznmMTag = rec->refWznmMTag;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJMTagTitle2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMTagTitle2::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMTagTitle2::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMTagTitle2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJMTagTitle2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMTagTitle2::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMTagTitle2::VecWIel::TITLE;
	};
};

void IexWznmIni::ImeitemIJMTagTitle2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmIni::ImeitemIJMTagTitle2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMTagTitle2","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJMTagTitle2::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJMTagTitle2::VecWIel::getIx(
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

void IexWznmIni::ImeIJMTagTitle2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJMTagTitle2::VecWIel::getSrefs(
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
 class IexWznmIni::ImeIJMTagTitle2
 ******************************************************************************/

IexWznmIni::ImeIJMTagTitle2::ImeIJMTagTitle2() {
};

IexWznmIni::ImeIJMTagTitle2::~ImeIJMTagTitle2() {
	clear();
};

void IexWznmIni::ImeIJMTagTitle2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJMTagTitle2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJMTagTitle2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmIni::ImeitemIJMTagTitle2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMTagTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMTagTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMTAGTITLE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMTagTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMTagTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJMTagTitle2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJMTagTitle2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMTagTitle2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMTagTitle2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMTagTitle2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJMTagTitle2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJMTagTitle2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMTagTitle2." << StrMod::replaceChar(ImeIJMTagTitle2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMTagTitle2.end" << endl;
	};
};

void IexWznmIni::ImeIJMTagTitle2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMTagTitle2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMTag2
 ******************************************************************************/

IexWznmIni::ImeitemIMTag2::ImeitemIMTag2(
			const string& sref
			, const string& Title
		) : WznmMTag() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
};

IexWznmIni::ImeitemIMTag2::ImeitemIMTag2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMTag2()
		{
	WznmMTag* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmtag->loadRecByRef(ref, &rec)) {
		refWznmMCapability = rec->refWznmMCapability;
		sref = rec->sref;
		refJTitle = rec->refJTitle;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMTag2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMTag2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMTag2::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMTAGTITLE2)) {
					imeijmtagtitle2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTag2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMTag2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMTag2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMTag2::VecWIel::TITLE;
		imeijmtagtitle2.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMTag2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Title << endl;
	imeijmtagtitle2.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMTag2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit"};
	else tags = {"ImeitemIMTag2","sref","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		imeijmtagtitle2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMTag2::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMTag2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmIni::ImeIMTag2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMTag2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMTag2
 ******************************************************************************/

IexWznmIni::ImeIMTag2::ImeIMTag2() {
};

IexWznmIni::ImeIMTag2::~ImeIMTag2() {
	clear();
};

void IexWznmIni::ImeIMTag2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMTag2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMTag2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIMTag2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTag2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTag2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMTAG2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTag2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTag2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMTag2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMTag2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTag2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTag2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTag2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMTag2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMTag2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMTag2." << StrMod::replaceChar(ImeIMTag2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMTag2.end" << endl;
	};
};

void IexWznmIni::ImeIMTag2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTag2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIRMCapabilityUniversal
 ******************************************************************************/

IexWznmIni::ImeitemIRMCapabilityUniversal::ImeitemIRMCapabilityUniversal(
			const uint unvIxWznmVMaintable
			, const string& srefKKey
		) : WznmRMCapabilityUniversal() {
	lineno = 0;
	ixWIelValid = 0;

	this->unvIxWznmVMaintable = unvIxWznmVMaintable;
	this->srefKKey = srefKKey;
};

IexWznmIni::ImeitemIRMCapabilityUniversal::ImeitemIRMCapabilityUniversal(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMCapabilityUniversal()
		{
	WznmRMCapabilityUniversal* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmcapabilityuniversal->loadRecByRef(ref, &rec)) {
		refWznmMCapability = rec->refWznmMCapability;
		unvIxWznmVMaintable = rec->unvIxWznmVMaintable;
		srefKKey = rec->srefKKey;

		delete rec;
	};
};

void IexWznmIni::ImeitemIRMCapabilityUniversal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefUnvIxWznmVMaintable = txtrd.fields[0]; ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFUNVIXWZNMVMAINTABLE;};
	if (txtrd.fields.size() > 1) {srefKKey = txtrd.fields[1]; ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFKKEY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIRMCapabilityUniversal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefUnvIxWznmVMaintable", "mtb", srefUnvIxWznmVMaintable)) ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFUNVIXWZNMVMAINTABLE;
		if (extractStringUclc(docctx, basexpath, "srefKKey", "key", srefKKey)) ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFKKEY;
	};
};

void IexWznmIni::ImeitemIRMCapabilityUniversal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMaintable::getSref(unvIxWznmVMaintable) << "\t" << srefKKey << endl;
};

void IexWznmIni::ImeitemIRMCapabilityUniversal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mtb","key"};
	else tags = {"ImeitemIRMCapabilityUniversal","srefUnvIxWznmVMaintable","srefKKey"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMaintable::getSref(unvIxWznmVMaintable));
		writeString(wr, tags[2], srefKKey);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIRMCapabilityUniversal::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIRMCapabilityUniversal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefunvixwznmvmaintable") ix |= SREFUNVIXWZNMVMAINTABLE;
		else if (ss[i] == "srefkkey") ix |= SREFKKEY;
	};

	return(ix);
};

void IexWznmIni::ImeIRMCapabilityUniversal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKKEY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIRMCapabilityUniversal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFUNVIXWZNMVMAINTABLE) ss.push_back("srefUnvIxWznmVMaintable");
	if (ix & SREFKKEY) ss.push_back("srefKKey");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIRMCapabilityUniversal
 ******************************************************************************/

IexWznmIni::ImeIRMCapabilityUniversal::ImeIRMCapabilityUniversal() {
};

IexWznmIni::ImeIRMCapabilityUniversal::~ImeIRMCapabilityUniversal() {
	clear();
};

void IexWznmIni::ImeIRMCapabilityUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIRMCapabilityUniversal::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIRMCapabilityUniversal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIRMCapabilityUniversal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCAPABILITYUNIVERSAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIRMCapabilityUniversal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIRMCapabilityUniversal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMCapabilityUniversal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMCapabilityUniversal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMCapabilityUniversal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIRMCapabilityUniversal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIRMCapabilityUniversal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMCapabilityUniversal." << StrMod::replaceChar(ImeIRMCapabilityUniversal::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMCapabilityUniversal.end" << endl;
	};
};

void IexWznmIni::ImeIRMCapabilityUniversal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMCapabilityUniversal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMCapability
 ******************************************************************************/

IexWznmIni::ImeitemIMCapability::ImeitemIMCapability(
			const string& sref
			, const uint ixWArtefact
			, const string& Title
		) : WznmMCapability() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixWArtefact = ixWArtefact;
	this->Title = Title;
};

IexWznmIni::ImeitemIMCapability::ImeitemIMCapability(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCapability()
		{
	WznmMCapability* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcapability->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		ixWArtefact = rec->ixWArtefact;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMCapability::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMCapability::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefsIxWArtefact = txtrd.fields[1]; ixWIelValid += ImeIMCapability::VecWIel::SREFSIXWARTEFACT;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMCapability::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMCAPABILITYPAR)) {
					imeiamcapabilitypar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2)) {
					imeiavkeylistkey2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMTAG2)) {
					imeimtag2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMCAPABILITYUNIVERSAL)) {
					imeirmcapabilityuniversal.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCapability"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMCapability::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCapability::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsIxWArtefact", "atf", srefsIxWArtefact)) ixWIelValid += ImeIMCapability::VecWIel::SREFSIXWARTEFACT;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMCapability::VecWIel::TITLE;
		imeiamcapabilitypar.readXML(docctx, basexpath);
		imeiavkeylistkey2.readXML(docctx, basexpath);
		imeimtag2.readXML(docctx, basexpath);
		imeirmcapabilityuniversal.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMCapability::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << VecWznmWMCapabilityArtefact::getSrefs(ixWArtefact) << "\t" << Title << endl;
	imeiamcapabilitypar.writeTxt(outfile);
	imeiavkeylistkey2.writeTxt(outfile);
	imeimtag2.writeTxt(outfile);
	imeirmcapabilityuniversal.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMCapability::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","atf","tit"};
	else tags = {"ImeitemIMCapability","sref","srefsIxWArtefact","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWznmWMCapabilityArtefact::getSrefs(ixWArtefact));
		writeString(wr, tags[3], Title);
		imeiamcapabilitypar.writeXML(wr, shorttags);
		imeiavkeylistkey2.writeXML(wr, shorttags);
		imeimtag2.writeXML(wr, shorttags);
		imeirmcapabilityuniversal.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMCapability::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMCapability::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefsixwartefact") ix |= SREFSIXWARTEFACT;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmIni::ImeIMCapability::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMCapability::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSIXWARTEFACT) ss.push_back("srefsIxWArtefact");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMCapability
 ******************************************************************************/

IexWznmIni::ImeIMCapability::ImeIMCapability() {
};

IexWznmIni::ImeIMCapability::~ImeIMCapability() {
	clear();
};

void IexWznmIni::ImeIMCapability::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMCapability::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMCapability* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMCapability();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCapability"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCAPABILITY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCapability"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCapability"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMCapability::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMCapability* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCapability");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCapability", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCapability";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMCapability();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMCapability::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCapability." << StrMod::replaceChar(ImeIMCapability::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMCapability.end" << endl;
	};
};

void IexWznmIni::ImeIMCapability::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCapability");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMFile
 ******************************************************************************/

IexWznmIni::ImeitemIMFile::ImeitemIMFile(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : WznmMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIMFile::ImeitemIMFile(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMFile()
		{
	WznmMFile* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMFile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {osrefKContent = txtrd.fields[0]; ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;};
	if (txtrd.fields.size() > 1) {Filename = txtrd.fields[1]; ixWIelValid += ImeIMFile::VecWIel::FILENAME;};
	if (txtrd.fields.size() > 2) {srefKMimetype = txtrd.fields[2]; ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFile::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMFile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile::VecWIel::COMMENT;
	};
};

void IexWznmIni::ImeitemIMFile::writeTxt(
			fstream& outfile
		) {
	outfile << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexWznmIni::ImeitemIMFile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMFile::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMFile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "osrefkcontent") ix |= OSREFKCONTENT;
		else if (ss[i] == "filename") ix |= FILENAME;
		else if (ss[i] == "srefkmimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIMFile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMFile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMFile
 ******************************************************************************/

IexWznmIni::ImeIMFile::ImeIMFile() {
};

IexWznmIni::ImeIMFile::~ImeIMFile() {
	clear();
};

void IexWznmIni::ImeIMFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMFile::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMFile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMFile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMFile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMFile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMFile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile." << StrMod::replaceChar(ImeIMFile::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMFile.end" << endl;
	};
};

void IexWznmIni::ImeIMFile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMLibraryMakefile
 ******************************************************************************/

IexWznmIni::ImeitemIAMLibraryMakefile::ImeitemIAMLibraryMakefile(
			const string& hsrefX1RefWznmMMachine
			, const string& x2SrefKTag
			, const string& Val
		) : WznmAMLibraryMakefile() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefX1RefWznmMMachine = hsrefX1RefWznmMMachine;
	this->x2SrefKTag = x2SrefKTag;
	this->Val = Val;
};

IexWznmIni::ImeitemIAMLibraryMakefile::ImeitemIAMLibraryMakefile(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMLibraryMakefile()
		{
	WznmAMLibraryMakefile* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamlibrarymakefile->loadRecByRef(ref, &rec)) {
		refWznmMLibrary = rec->refWznmMLibrary;
		x1RefWznmMMachine = rec->x1RefWznmMMachine;
		x2SrefKTag = rec->x2SrefKTag;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMLibraryMakefile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefX1RefWznmMMachine = txtrd.fields[0]; ixWIelValid += ImeIAMLibraryMakefile::VecWIel::HSREFX1REFWZNMMMACHINE;};
	if (txtrd.fields.size() > 1) {x2SrefKTag = txtrd.fields[1]; ixWIelValid += ImeIAMLibraryMakefile::VecWIel::X2SREFKTAG;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAMLibraryMakefile::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMLibraryMakefile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefX1RefWznmMMachine", "mch", hsrefX1RefWznmMMachine)) ixWIelValid += ImeIAMLibraryMakefile::VecWIel::HSREFX1REFWZNMMMACHINE;
		if (extractStringUclc(docctx, basexpath, "x2SrefKTag", "tag", x2SrefKTag)) ixWIelValid += ImeIAMLibraryMakefile::VecWIel::X2SREFKTAG;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMLibraryMakefile::VecWIel::VAL;
	};
};

void IexWznmIni::ImeitemIAMLibraryMakefile::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefX1RefWznmMMachine << "\t" << x2SrefKTag << "\t" << Val << endl;
};

void IexWznmIni::ImeitemIAMLibraryMakefile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mch","tag","val"};
	else tags = {"ImeitemIAMLibraryMakefile","hsrefX1RefWznmMMachine","x2SrefKTag","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefX1RefWznmMMachine);
		writeString(wr, tags[2], x2SrefKTag);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMLibraryMakefile::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMLibraryMakefile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefx1refwznmmmachine") ix |= HSREFX1REFWZNMMMACHINE;
		else if (ss[i] == "x2srefktag") ix |= X2SREFKTAG;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmIni::ImeIAMLibraryMakefile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMLibraryMakefile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFX1REFWZNMMMACHINE) ss.push_back("hsrefX1RefWznmMMachine");
	if (ix & X2SREFKTAG) ss.push_back("x2SrefKTag");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMLibraryMakefile
 ******************************************************************************/

IexWznmIni::ImeIAMLibraryMakefile::ImeIAMLibraryMakefile() {
};

IexWznmIni::ImeIAMLibraryMakefile::~ImeIAMLibraryMakefile() {
	clear();
};

void IexWznmIni::ImeIAMLibraryMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMLibraryMakefile::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMLibraryMakefile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAMLibraryMakefile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMLIBRARYMAKEFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMLibraryMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMLibraryMakefile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMLibraryMakefile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMLibraryMakefile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMLibraryMakefile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMLibraryMakefile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMLibraryMakefile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMLibraryMakefile." << StrMod::replaceChar(ImeIAMLibraryMakefile::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMLibraryMakefile.end" << endl;
	};
};

void IexWznmIni::ImeIAMLibraryMakefile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMLibraryMakefile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMLibraryPkglist
 ******************************************************************************/

IexWznmIni::ImeitemIAMLibraryPkglist::ImeitemIAMLibraryPkglist(
			const string& hsrefX1RefWznmMMachine
			, const string& Pkglist
		) : WznmAMLibraryPkglist() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefX1RefWznmMMachine = hsrefX1RefWznmMMachine;
	this->Pkglist = Pkglist;
};

IexWznmIni::ImeitemIAMLibraryPkglist::ImeitemIAMLibraryPkglist(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMLibraryPkglist()
		{
	WznmAMLibraryPkglist* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamlibrarypkglist->loadRecByRef(ref, &rec)) {
		refWznmMLibrary = rec->refWznmMLibrary;
		x1RefWznmMMachine = rec->x1RefWznmMMachine;
		Pkglist = rec->Pkglist;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMLibraryPkglist::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefX1RefWznmMMachine = txtrd.fields[0]; ixWIelValid += ImeIAMLibraryPkglist::VecWIel::HSREFX1REFWZNMMMACHINE;};
	if (txtrd.fields.size() > 1) {Pkglist = txtrd.fields[1]; ixWIelValid += ImeIAMLibraryPkglist::VecWIel::PKGLIST;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMLibraryPkglist"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMLibraryPkglist::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefX1RefWznmMMachine", "mch", hsrefX1RefWznmMMachine)) ixWIelValid += ImeIAMLibraryPkglist::VecWIel::HSREFX1REFWZNMMMACHINE;
		if (extractStringUclc(docctx, basexpath, "Pkglist", "pkl", Pkglist)) ixWIelValid += ImeIAMLibraryPkglist::VecWIel::PKGLIST;
	};
};

void IexWznmIni::ImeitemIAMLibraryPkglist::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefX1RefWznmMMachine << "\t" << Pkglist << endl;
};

void IexWznmIni::ImeitemIAMLibraryPkglist::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mch","pkl"};
	else tags = {"ImeitemIAMLibraryPkglist","hsrefX1RefWznmMMachine","Pkglist"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefX1RefWznmMMachine);
		writeString(wr, tags[2], Pkglist);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMLibraryPkglist::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMLibraryPkglist::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefx1refwznmmmachine") ix |= HSREFX1REFWZNMMMACHINE;
		else if (ss[i] == "pkglist") ix |= PKGLIST;
	};

	return(ix);
};

void IexWznmIni::ImeIAMLibraryPkglist::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*PKGLIST); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMLibraryPkglist::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFX1REFWZNMMMACHINE) ss.push_back("hsrefX1RefWznmMMachine");
	if (ix & PKGLIST) ss.push_back("Pkglist");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMLibraryPkglist
 ******************************************************************************/

IexWznmIni::ImeIAMLibraryPkglist::ImeIAMLibraryPkglist() {
};

IexWznmIni::ImeIAMLibraryPkglist::~ImeIAMLibraryPkglist() {
	clear();
};

void IexWznmIni::ImeIAMLibraryPkglist::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMLibraryPkglist::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMLibraryPkglist* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAMLibraryPkglist();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryPkglist"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMLibraryPkglist"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMLIBRARYPKGLIST) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryPkglist"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryPkglist"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMLibraryPkglist::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMLibraryPkglist* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMLibraryPkglist");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMLibraryPkglist", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMLibraryPkglist";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMLibraryPkglist();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMLibraryPkglist::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMLibraryPkglist." << StrMod::replaceChar(ImeIAMLibraryPkglist::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMLibraryPkglist.end" << endl;
	};
};

void IexWznmIni::ImeIAMLibraryPkglist::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMLibraryPkglist");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMLibrary
 ******************************************************************************/

IexWznmIni::ImeitemIMLibrary::ImeitemIMLibrary(
			const string& sref
			, const string& Title
			, const string& Version
			, const string& srefKLictype
			, const string& depSrefsWznmMLibrary
			, const string& Comment
		) : WznmMLibrary() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Version = Version;
	this->srefKLictype = srefKLictype;
	this->depSrefsWznmMLibrary = depSrefsWznmMLibrary;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIMLibrary::ImeitemIMLibrary(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMLibrary()
		{
	WznmMLibrary* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmlibrary->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Title = rec->Title;
		Version = rec->Version;
		srefKLictype = rec->srefKLictype;
		depSrefsWznmMLibrary = rec->depSrefsWznmMLibrary;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMLibrary::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMLibrary::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMLibrary::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Version = txtrd.fields[2]; ixWIelValid += ImeIMLibrary::VecWIel::VERSION;};
	if (txtrd.fields.size() > 3) {srefKLictype = txtrd.fields[3]; ixWIelValid += ImeIMLibrary::VecWIel::SREFKLICTYPE;};
	if (txtrd.fields.size() > 4) {depSrefsWznmMLibrary = txtrd.fields[4]; ixWIelValid += ImeIMLibrary::VecWIel::DEPSREFSWZNMMLIBRARY;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMLibrary::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMLIBRARYMAKEFILE)) {
					imeiamlibrarymakefile.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMLIBRARYPKGLIST)) {
					imeiamlibrarypkglist.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLibrary"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMLibrary::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMLibrary::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMLibrary::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Version", "ver", Version)) ixWIelValid += ImeIMLibrary::VecWIel::VERSION;
		if (extractStringUclc(docctx, basexpath, "srefKLictype", "lty", srefKLictype)) ixWIelValid += ImeIMLibrary::VecWIel::SREFKLICTYPE;
		if (extractStringUclc(docctx, basexpath, "depSrefsWznmMLibrary", "dep", depSrefsWznmMLibrary)) ixWIelValid += ImeIMLibrary::VecWIel::DEPSREFSWZNMMLIBRARY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMLibrary::VecWIel::COMMENT;
		imeiamlibrarymakefile.readXML(docctx, basexpath);
		imeiamlibrarypkglist.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMLibrary::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << "\t" << Version << "\t" << srefKLictype << "\t" << depSrefsWznmMLibrary << "\t" << Comment << endl;
	imeiamlibrarymakefile.writeTxt(outfile);
	imeiamlibrarypkglist.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMLibrary::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","ver","lty","dep","cmt"};
	else tags = {"ImeitemIMLibrary","sref","Title","Version","srefKLictype","depSrefsWznmMLibrary","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Version);
		writeString(wr, tags[4], srefKLictype);
		writeString(wr, tags[5], depSrefsWznmMLibrary);
		writeString(wr, tags[6], Comment);
		imeiamlibrarymakefile.writeXML(wr, shorttags);
		imeiamlibrarypkglist.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMLibrary::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMLibrary::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "version") ix |= VERSION;
		else if (ss[i] == "srefklictype") ix |= SREFKLICTYPE;
		else if (ss[i] == "depsrefswznmmlibrary") ix |= DEPSREFSWZNMMLIBRARY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIMLibrary::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMLibrary::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & VERSION) ss.push_back("Version");
	if (ix & SREFKLICTYPE) ss.push_back("srefKLictype");
	if (ix & DEPSREFSWZNMMLIBRARY) ss.push_back("depSrefsWznmMLibrary");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMLibrary
 ******************************************************************************/

IexWznmIni::ImeIMLibrary::ImeIMLibrary() {
};

IexWznmIni::ImeIMLibrary::~ImeIMLibrary() {
	clear();
};

void IexWznmIni::ImeIMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMLibrary::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMLibrary* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMLibrary();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMLIBRARY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMLibrary* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMLibrary");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMLibrary", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMLibrary";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMLibrary();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMLibrary::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMLibrary." << StrMod::replaceChar(ImeIMLibrary::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMLibrary.end" << endl;
	};
};

void IexWznmIni::ImeIMLibrary::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMLibrary");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJMLocaleTitle
 ******************************************************************************/

IexWznmIni::ImeitemIJMLocaleTitle::ImeitemIJMLocaleTitle(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMLocaleTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmIni::ImeitemIJMLocaleTitle::ImeitemIJMLocaleTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMLocaleTitle()
		{
	WznmJMLocaleTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmlocaletitle->loadRecByRef(ref, &rec)) {
		refWznmMLocale = rec->refWznmMLocale;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJMLocaleTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMLocaleTitle::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMLocaleTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMLocaleTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJMLocaleTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "lo2", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMLocaleTitle::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMLocaleTitle::VecWIel::TITLE;
	};
};

void IexWznmIni::ImeitemIJMLocaleTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmIni::ImeitemIJMLocaleTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lo2","tit"};
	else tags = {"ImeitemIJMLocaleTitle","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJMLocaleTitle::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJMLocaleTitle::VecWIel::getIx(
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

void IexWznmIni::ImeIJMLocaleTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJMLocaleTitle::VecWIel::getSrefs(
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
 class IexWznmIni::ImeIJMLocaleTitle
 ******************************************************************************/

IexWznmIni::ImeIJMLocaleTitle::ImeIJMLocaleTitle() {
};

IexWznmIni::ImeIJMLocaleTitle::~ImeIJMLocaleTitle() {
	clear();
};

void IexWznmIni::ImeIJMLocaleTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJMLocaleTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJMLocaleTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIJMLocaleTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMLocaleTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMLocaleTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMLOCALETITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMLocaleTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMLocaleTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJMLocaleTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJMLocaleTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMLocaleTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMLocaleTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMLocaleTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJMLocaleTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJMLocaleTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMLocaleTitle." << StrMod::replaceChar(ImeIJMLocaleTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMLocaleTitle.end" << endl;
	};
};

void IexWznmIni::ImeIJMLocaleTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMLocaleTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMLocale
 ******************************************************************************/

IexWznmIni::ImeitemIMLocale::ImeitemIMLocale(
			const string& sref
			, const string& Title
		) : WznmMLocale() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
};

IexWznmIni::ImeitemIMLocale::ImeitemIMLocale(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMLocale()
		{
	WznmMLocale* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmlocale->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		refJTitle = rec->refJTitle;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMLocale::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMLocale::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMLocale::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMLOCALETITLE)) {
					imeijmlocaletitle.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLocale"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMLocale::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMLocale::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMLocale::VecWIel::TITLE;
		imeijmlocaletitle.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMLocale::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << endl;
	imeijmlocaletitle.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMLocale::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit"};
	else tags = {"ImeitemIMLocale","sref","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		imeijmlocaletitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMLocale::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMLocale::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmIni::ImeIMLocale::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMLocale::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMLocale
 ******************************************************************************/

IexWznmIni::ImeIMLocale::ImeIMLocale() {
};

IexWznmIni::ImeIMLocale::~ImeIMLocale() {
	clear();
};

void IexWznmIni::ImeIMLocale::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMLocale::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMLocale* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMLocale();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLocale"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMLOCALE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLocale"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLocale"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMLocale::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMLocale* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMLocale");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMLocale", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMLocale";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMLocale();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMLocale::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMLocale." << StrMod::replaceChar(ImeIMLocale::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMLocale.end" << endl;
	};
};

void IexWznmIni::ImeIMLocale::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMLocale");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMMachineMakefile
 ******************************************************************************/

IexWznmIni::ImeitemIAMMachineMakefile::ImeitemIAMMachineMakefile(
			const string& x1SrefKTag
			, const string& Val
		) : WznmAMMachineMakefile() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKTag = x1SrefKTag;
	this->Val = Val;
};

IexWznmIni::ImeitemIAMMachineMakefile::ImeitemIAMMachineMakefile(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMMachineMakefile()
		{
	WznmAMMachineMakefile* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmammachinemakefile->loadRecByRef(ref, &rec)) {
		refWznmMMachine = rec->refWznmMMachine;
		x1SrefKTag = rec->x1SrefKTag;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMMachineMakefile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKTag = txtrd.fields[0]; ixWIelValid += ImeIAMMachineMakefile::VecWIel::X1SREFKTAG;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMMachineMakefile::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMMachineMakefile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKTag", "tag", x1SrefKTag)) ixWIelValid += ImeIAMMachineMakefile::VecWIel::X1SREFKTAG;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMMachineMakefile::VecWIel::VAL;
	};
};

void IexWznmIni::ImeitemIAMMachineMakefile::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKTag << "\t" << Val << endl;
};

void IexWznmIni::ImeitemIAMMachineMakefile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tag","val"};
	else tags = {"ImeitemIAMMachineMakefile","x1SrefKTag","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKTag);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMMachineMakefile::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMMachineMakefile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefktag") ix |= X1SREFKTAG;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmIni::ImeIAMMachineMakefile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMMachineMakefile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKTAG) ss.push_back("x1SrefKTag");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMMachineMakefile
 ******************************************************************************/

IexWznmIni::ImeIAMMachineMakefile::ImeIAMMachineMakefile() {
};

IexWznmIni::ImeIAMMachineMakefile::~ImeIAMMachineMakefile() {
	clear();
};

void IexWznmIni::ImeIAMMachineMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMMachineMakefile::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMMachineMakefile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAMMachineMakefile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMACHINEMAKEFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMMachineMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMMachineMakefile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMachineMakefile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMachineMakefile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMachineMakefile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMMachineMakefile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMMachineMakefile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMMachineMakefile." << StrMod::replaceChar(ImeIAMMachineMakefile::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMMachineMakefile.end" << endl;
	};
};

void IexWznmIni::ImeIAMMachineMakefile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMachineMakefile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMMachinePar
 ******************************************************************************/

IexWznmIni::ImeitemIAMMachinePar::ImeitemIAMMachinePar(
			const string& x1SrefKKey
			, const string& Val
		) : WznmAMMachinePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWznmIni::ImeitemIAMMachinePar::ImeitemIAMMachinePar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMMachinePar()
		{
	WznmAMMachinePar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmammachinepar->loadRecByRef(ref, &rec)) {
		refWznmMMachine = rec->refWznmMMachine;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMMachinePar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMMachinePar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMMachinePar::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMMachinePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMMachinePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMMachinePar::VecWIel::VAL;
	};
};

void IexWznmIni::ImeitemIAMMachinePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWznmIni::ImeitemIAMMachinePar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMMachinePar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMMachinePar::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMMachinePar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmIni::ImeIAMMachinePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMMachinePar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMMachinePar
 ******************************************************************************/

IexWznmIni::ImeIAMMachinePar::ImeIAMMachinePar() {
};

IexWznmIni::ImeIAMMachinePar::~ImeIAMMachinePar() {
	clear();
};

void IexWznmIni::ImeIAMMachinePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMMachinePar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMMachinePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAMMachinePar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMACHINEPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMMachinePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMMachinePar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMachinePar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMachinePar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMachinePar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMMachinePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMMachinePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMMachinePar." << StrMod::replaceChar(ImeIAMMachinePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMMachinePar.end" << endl;
	};
};

void IexWznmIni::ImeIAMMachinePar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMachinePar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMMachine
 ******************************************************************************/

IexWznmIni::ImeitemIMMachine::ImeitemIMMachine(
			const string& hsrefSupRefWznmMMachine
			, const string& sref
			, const string& hsrefCchRefWznmMMachine
			, const string& srefKPkgmgr
			, const string& Comment
		) : WznmMMachine() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefWznmMMachine = hsrefSupRefWznmMMachine;
	this->sref = sref;
	this->hsrefCchRefWznmMMachine = hsrefCchRefWznmMMachine;
	this->srefKPkgmgr = srefKPkgmgr;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIMMachine::ImeitemIMMachine(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMMachine()
		{
	WznmMMachine* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmmachine->loadRecByRef(ref, &rec)) {
		supRefWznmMMachine = rec->supRefWznmMMachine;
		sref = rec->sref;
		cchRefWznmMMachine = rec->cchRefWznmMMachine;
		srefKPkgmgr = rec->srefKPkgmgr;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMMachine::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefSupRefWznmMMachine = txtrd.fields[0]; ixWIelValid += ImeIMMachine::VecWIel::HSREFSUPREFWZNMMMACHINE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMMachine::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {hsrefCchRefWznmMMachine = txtrd.fields[2]; ixWIelValid += ImeIMMachine::VecWIel::HSREFCCHREFWZNMMMACHINE;};
	if (txtrd.fields.size() > 3) {srefKPkgmgr = txtrd.fields[3]; ixWIelValid += ImeIMMachine::VecWIel::SREFKPKGMGR;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMMachine::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMMACHINEMAKEFILE)) {
					imeiammachinemakefile.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMMACHINEPAR)) {
					imeiammachinepar.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMMachine"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMMachine::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWznmMMachine", "sup", hsrefSupRefWznmMMachine)) ixWIelValid += ImeIMMachine::VecWIel::HSREFSUPREFWZNMMMACHINE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMMachine::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "hsrefCchRefWznmMMachine", "cch", hsrefCchRefWznmMMachine)) ixWIelValid += ImeIMMachine::VecWIel::HSREFCCHREFWZNMMMACHINE;
		if (extractStringUclc(docctx, basexpath, "srefKPkgmgr", "pkm", srefKPkgmgr)) ixWIelValid += ImeIMMachine::VecWIel::SREFKPKGMGR;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMMachine::VecWIel::COMMENT;
		imeiammachinemakefile.readXML(docctx, basexpath);
		imeiammachinepar.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMMachine::writeTxt(
			fstream& outfile
		) {
	outfile << hsrefSupRefWznmMMachine << "\t" << sref << "\t" << hsrefCchRefWznmMMachine << "\t" << srefKPkgmgr << "\t" << Comment << endl;
	imeiammachinemakefile.writeTxt(outfile);
	imeiammachinepar.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMMachine::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sup","srf","cch","pkm","cmt"};
	else tags = {"ImeitemIMMachine","hsrefSupRefWznmMMachine","sref","hsrefCchRefWznmMMachine","srefKPkgmgr","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefSupRefWznmMMachine);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], hsrefCchRefWznmMMachine);
		writeString(wr, tags[4], srefKPkgmgr);
		writeString(wr, tags[5], Comment);
		imeiammachinemakefile.writeXML(wr, shorttags);
		imeiammachinepar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMMachine::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMMachine::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefsuprefwznmmmachine") ix |= HSREFSUPREFWZNMMMACHINE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "hsrefcchrefwznmmmachine") ix |= HSREFCCHREFWZNMMMACHINE;
		else if (ss[i] == "srefkpkgmgr") ix |= SREFKPKGMGR;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIMMachine::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMMachine::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFSUPREFWZNMMMACHINE) ss.push_back("hsrefSupRefWznmMMachine");
	if (ix & SREF) ss.push_back("sref");
	if (ix & HSREFCCHREFWZNMMMACHINE) ss.push_back("hsrefCchRefWznmMMachine");
	if (ix & SREFKPKGMGR) ss.push_back("srefKPkgmgr");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMMachine
 ******************************************************************************/

IexWznmIni::ImeIMMachine::ImeIMMachine() {
};

IexWznmIni::ImeIMMachine::~ImeIMMachine() {
	clear();
};

void IexWznmIni::ImeIMMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMMachine::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMMachine* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMMachine();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMMachine"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMMACHINE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMachine"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMachine"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMMachine::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMMachine* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMMachine");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMMachine", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMMachine";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMMachine();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMMachine::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMMachine." << StrMod::replaceChar(ImeIMMachine::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMMachine.end" << endl;
	};
};

void IexWznmIni::ImeIMMachine::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMMachine");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJMTagTitle1
 ******************************************************************************/

IexWznmIni::ImeitemIJMTagTitle1::ImeitemIJMTagTitle1(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMTagTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmIni::ImeitemIJMTagTitle1::ImeitemIJMTagTitle1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMTagTitle1()
		{
	WznmJMTagTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmtagtitle->loadRecByRef(ref, &rec)) {
		refWznmMTag = rec->refWznmMTag;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJMTagTitle1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMTagTitle1::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMTagTitle1::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMTagTitle1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJMTagTitle1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMTagTitle1::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMTagTitle1::VecWIel::TITLE;
	};
};

void IexWznmIni::ImeitemIJMTagTitle1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmIni::ImeitemIJMTagTitle1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMTagTitle1","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJMTagTitle1::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJMTagTitle1::VecWIel::getIx(
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

void IexWznmIni::ImeIJMTagTitle1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJMTagTitle1::VecWIel::getSrefs(
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
 class IexWznmIni::ImeIJMTagTitle1
 ******************************************************************************/

IexWznmIni::ImeIJMTagTitle1::ImeIJMTagTitle1() {
};

IexWznmIni::ImeIJMTagTitle1::~ImeIJMTagTitle1() {
	clear();
};

void IexWznmIni::ImeIJMTagTitle1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJMTagTitle1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJMTagTitle1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIJMTagTitle1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMTagTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMTagTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMTAGTITLE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMTagTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMTagTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJMTagTitle1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJMTagTitle1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMTagTitle1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMTagTitle1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMTagTitle1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJMTagTitle1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJMTagTitle1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMTagTitle1." << StrMod::replaceChar(ImeIJMTagTitle1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMTagTitle1.end" << endl;
	};
};

void IexWznmIni::ImeIJMTagTitle1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMTagTitle1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMTag1
 ******************************************************************************/

IexWznmIni::ImeitemIMTag1::ImeitemIMTag1(
			const string& sref
			, const string& osrefWznmKTaggrp
			, const string& Title
		) : WznmMTag() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->Title = Title;
};

IexWznmIni::ImeitemIMTag1::ImeitemIMTag1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMTag1()
		{
	WznmMTag* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmtag->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		osrefWznmKTaggrp = rec->osrefWznmKTaggrp;
		refJTitle = rec->refJTitle;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMTag1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMTag1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {osrefWznmKTaggrp = txtrd.fields[1]; ixWIelValid += ImeIMTag1::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMTag1::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMTAGTITLE1)) {
					imeijmtagtitle1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTag1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMTag1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMTag1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "grp", osrefWznmKTaggrp)) ixWIelValid += ImeIMTag1::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMTag1::VecWIel::TITLE;
		imeijmtagtitle1.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMTag1::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << osrefWznmKTaggrp << "\t" << Title << endl;
	imeijmtagtitle1.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMTag1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","grp","tit"};
	else tags = {"ImeitemIMTag1","sref","osrefWznmKTaggrp","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], osrefWznmKTaggrp);
		writeString(wr, tags[3], Title);
		imeijmtagtitle1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMTag1::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMTag1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "osrefwznmktaggrp") ix |= OSREFWZNMKTAGGRP;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmIni::ImeIMTag1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMTag1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & OSREFWZNMKTAGGRP) ss.push_back("osrefWznmKTaggrp");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMTag1
 ******************************************************************************/

IexWznmIni::ImeIMTag1::ImeIMTag1() {
};

IexWznmIni::ImeIMTag1::~ImeIMTag1() {
	clear();
};

void IexWznmIni::ImeIMTag1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMTag1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMTag1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMTag1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTag1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMTAG1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTag1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTag1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMTag1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMTag1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTag1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTag1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTag1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMTag1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMTag1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMTag1." << StrMod::replaceChar(ImeIMTag1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMTag1.end" << endl;
	};
};

void IexWznmIni::ImeIMTag1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTag1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexWznmIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxWznmVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWznmWAccess
		) : WznmAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWznmVFeatgroup = x1IxWznmVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWznmWAccess = ixWznmWAccess;
};

IexWznmIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMUsergroupAccess()
		{
	WznmAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamusergroupaccess->loadRecByRef(ref, &rec)) {
		refWznmMUsergroup = rec->refWznmMUsergroup;
		x1IxWznmVFeatgroup = rec->x1IxWznmVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWznmWAccess = rec->ixWznmWAccess;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWznmVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWZNMVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWznmWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWZNMWACCESS;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWznmVFeatgroup", "feg", srefX1IxWznmVFeatgroup)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWZNMVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWznmWAccess", "acc", srefsIxWznmWAccess)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWZNMWACCESS;
	};
};

void IexWznmIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVFeatgroup::getSref(x1IxWznmVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWznmWAccess::getSrefs(ixWznmWAccess) << endl;
};

void IexWznmIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxWznmVFeatgroup","x2FeaSrefUix","srefsIxWznmWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVFeatgroup::getSref(x1IxWznmVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWznmWAccess::getSrefs(ixWznmWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwznmvfeatgroup") ix |= SREFX1IXWZNMVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwznmwaccess") ix |= SREFSIXWZNMWACCESS;
	};

	return(ix);
};

void IexWznmIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWZNMWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZNMVFEATGROUP) ss.push_back("srefX1IxWznmVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWZNMWACCESS) ss.push_back("srefsIxWznmWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexWznmIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexWznmIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexWznmIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIAMUsergroupAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMUsergroupAccess.end" << endl;
	};
};

void IexWznmIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIAMUserAccess
 ******************************************************************************/

IexWznmIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			const uint x1IxWznmVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWznmWAccess
		) : WznmAMUserAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWznmVFeatgroup = x1IxWznmVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWznmWAccess = ixWznmWAccess;
};

IexWznmIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMUserAccess()
		{
	WznmAMUserAccess* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamuseraccess->loadRecByRef(ref, &rec)) {
		refWznmMUser = rec->refWznmMUser;
		x1IxWznmVFeatgroup = rec->x1IxWznmVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWznmWAccess = rec->ixWznmWAccess;

		delete rec;
	};
};

void IexWznmIni::ImeitemIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWznmVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWZNMVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWznmWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWZNMWACCESS;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWznmVFeatgroup", "feg", srefX1IxWznmVFeatgroup)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWZNMVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWznmWAccess", "acc", srefsIxWznmWAccess)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWZNMWACCESS;
	};
};

void IexWznmIni::ImeitemIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVFeatgroup::getSref(x1IxWznmVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWznmWAccess::getSrefs(ixWznmWAccess) << endl;
};

void IexWznmIni::ImeitemIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUserAccess","srefX1IxWznmVFeatgroup","x2FeaSrefUix","srefsIxWznmWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVFeatgroup::getSref(x1IxWznmVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWznmWAccess::getSrefs(ixWznmWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIAMUserAccess::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIAMUserAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwznmvfeatgroup") ix |= SREFX1IXWZNMVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwznmwaccess") ix |= SREFSIXWZNMWACCESS;
	};

	return(ix);
};

void IexWznmIni::ImeIAMUserAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWZNMWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIAMUserAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZNMVFEATGROUP) ss.push_back("srefX1IxWznmVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWZNMWACCESS) ss.push_back("srefsIxWznmWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIAMUserAccess
 ******************************************************************************/

IexWznmIni::ImeIAMUserAccess::ImeIAMUserAccess() {
};

IexWznmIni::ImeIAMUserAccess::~ImeIAMUserAccess() {
	clear();
};

void IexWznmIni::ImeIAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIAMUserAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmIni::ImeitemIAMUserAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIAMUserAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUserAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUserAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUserAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIAMUserAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMUserAccess." << StrMod::replaceChar(ImeIAMUserAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMUserAccess.end" << endl;
	};
};

void IexWznmIni::ImeIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUserAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJMUserState
 ******************************************************************************/

IexWznmIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : WznmJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWznmIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMUserState()
		{
	WznmJMUserState* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmuserstate->loadRecByRef(ref, &rec)) {
		refWznmMUser = rec->refWznmMUser;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
	};
};

void IexWznmIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVMUserState::getSref(ixVState) << endl;
};

void IexWznmIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexWznmIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIJMUserState
 ******************************************************************************/

IexWznmIni::ImeIJMUserState::ImeIJMUserState() {
};

IexWznmIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexWznmIni::ImeIJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmIni::ImeitemIJMUserState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMUserState.end" << endl;
	};
};

void IexWznmIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexWznmIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : WznmJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexWznmIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMPersonLastname()
		{
	WznmJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmpersonlastname->loadRecByRef(ref, &rec)) {
		refWznmMPerson = rec->refWznmMPerson;
		x1Startd = rec->x1Startd;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWznmIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Lastname = txtrd.fields[0]; ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexWznmIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexWznmIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWznmIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIJMPersonLastname
 ******************************************************************************/

IexWznmIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexWznmIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexWznmIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmIni::ImeitemIJMPersonLastname();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPersonLastname.end" << endl;
	};
};

void IexWznmIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMPerson
 ******************************************************************************/

IexWznmIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
			, const string& Lastname
		) : WznmMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
};

IexWznmIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMPerson()
		{
	WznmMPerson* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVSex = txtrd.fields[0]; ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMPerson::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Firstname = txtrd.fields[2]; ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;};
	if (txtrd.fields.size() > 3) {Lastname = txtrd.fields[3]; ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
					imeijmpersonlastname.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << "\t" << Lastname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm","lnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		writeString(wr, tags[4], Lastname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvsex") ix |= SREFIXVSEX;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "firstname") ix |= FIRSTNAME;
		else if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWznmIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");
	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMPerson
 ******************************************************************************/

IexWznmIni::ImeIMPerson::ImeIMPerson() {
};

IexWznmIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexWznmIni::ImeIMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmIni::ImeitemIMPerson();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPERSON) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPerson.end" << endl;
	};
};

void IexWznmIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMUser
 ******************************************************************************/

IexWznmIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixVState
			, const uint ixWznmVLocale
			, const uint ixWznmVUserlevel
			, const string& Password
			, const string& Fullkey
			, const string& Comment
		) : WznmMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVState = ixVState;
	this->ixWznmVLocale = ixWznmVLocale;
	this->ixWznmVUserlevel = ixWznmVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIMUser::ImeitemIMUser(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMUser()
		{
	WznmMUser* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refWznmMUsergroup = rec->refWznmMUsergroup;
		refWznmMPerson = rec->refWznmMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixWznmVLocale = rec->ixWznmVLocale;
		ixWznmVUserlevel = rec->ixWznmVUserlevel;
		Password = rec->Password;
		Fullkey = rec->Fullkey;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUser::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVState = txtrd.fields[1]; ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 2) {srefIxWznmVLocale = txtrd.fields[2]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWZNMVLOCALE;};
	if (txtrd.fields.size() > 3) {srefIxWznmVUserlevel = txtrd.fields[3]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWZNMVUSERLEVEL;};
	if (txtrd.fields.size() > 4) {Password = txtrd.fields[4]; ixWIelValid += ImeIMUser::VecWIel::PASSWORD;};
	if (txtrd.fields.size() > 5) {Fullkey = txtrd.fields[5]; ixWIelValid += ImeIMUser::VecWIel::FULLKEY;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMUser::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS)) {
					imeiamuseraccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
					imeijmuserstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
					imeimperson.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVLocale", "lcl", srefIxWznmVLocale)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWZNMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVUserlevel", "ulv", srefIxWznmVUserlevel)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWZNMVUSERLEVEL;
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		if (extractStringUclc(docctx, basexpath, "Fullkey", "fky", Fullkey)) ixWIelValid += ImeIMUser::VecWIel::FULLKEY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUser::VecWIel::COMMENT;
		imeiamuseraccess.readXML(docctx, basexpath);
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecWznmVMUserState::getSref(ixVState) << "\t" << VecWznmVLocale::getSref(ixWznmVLocale) << "\t" << VecWznmVUserlevel::getSref(ixWznmVUserlevel) << "\t" << Password << "\t" << Fullkey << "\t" << Comment << endl;
	imeiamuseraccess.writeTxt(outfile);
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ste","lcl","ulv","pwd","fky","cmt"};
	else tags = {"ImeitemIMUser","sref","srefIxVState","srefIxWznmVLocale","srefIxWznmVUserlevel","Password","Fullkey","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWznmVMUserState::getSref(ixVState));
		writeString(wr, tags[3], VecWznmVLocale::getSref(ixWznmVLocale));
		writeString(wr, tags[4], VecWznmVUserlevel::getSref(ixWznmVUserlevel));
		writeString(wr, tags[5], Password);
		writeString(wr, tags[6], Fullkey);
		writeString(wr, tags[7], Comment);
		imeiamuseraccess.writeXML(wr, shorttags);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefixwznmvlocale") ix |= SREFIXWZNMVLOCALE;
		else if (ss[i] == "srefixwznmvuserlevel") ix |= SREFIXWZNMVUSERLEVEL;
		else if (ss[i] == "password") ix |= PASSWORD;
		else if (ss[i] == "fullkey") ix |= FULLKEY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFIXWZNMVLOCALE) ss.push_back("srefIxWznmVLocale");
	if (ix & SREFIXWZNMVUSERLEVEL) ss.push_back("srefIxWznmVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");
	if (ix & FULLKEY) ss.push_back("Fullkey");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMUser
 ******************************************************************************/

IexWznmIni::ImeIMUser::ImeIMUser() {
};

IexWznmIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexWznmIni::ImeIMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmIni::ImeitemIMUser();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMUser.end" << endl;
	};
};

void IexWznmIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmIni::ImeitemIMUsergroup
 ******************************************************************************/

IexWznmIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : WznmMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWznmIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMUsergroup()
		{
	WznmMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUsergroup::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
					imeiamusergroupaccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
					imeimuser.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexWznmIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexWznmIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexWznmIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmIni::ImeIMUsergroup
 ******************************************************************************/

IexWznmIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexWznmIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexWznmIni::ImeIMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexWznmIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmIni::ImeitemIMUsergroup();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUsergroup.end" << endl;
	};
};

void IexWznmIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmIni
 ******************************************************************************/

void IexWznmIni::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCapability& imeimcapability
			, ImeIMFile& imeimfile
			, ImeIMLibrary& imeimlibrary
			, ImeIMLocale& imeimlocale
			, ImeIMMachine& imeimmachine
			, ImeIMTag1& imeimtag1
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcapability, imeimfile, imeimlibrary, imeimlocale, imeimmachine, imeimtag1, imeimusergroup);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmIni", Version("1.0.9"), VecVIme::getIx);
			readTxt(rd, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcapability, imeimfile, imeimlibrary, imeimlocale, imeimmachine, imeimtag1, imeimusergroup);
	};
};

void IexWznmIni::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCapability& imeimcapability
			, ImeIMFile& imeimfile
			, ImeIMLibrary& imeimlibrary
			, ImeIMLocale& imeimlocale
			, ImeIMMachine& imeimmachine
			, ImeIMTag1& imeimtag1
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcapability, imeimfile, imeimlibrary, imeimlocale, imeimmachine, imeimtag1, imeimusergroup);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcapability, imeimfile, imeimlibrary, imeimlocale, imeimmachine, imeimtag1, imeimusergroup);
		txtfile.close();
	};
};

void IexWznmIni::readTxt(
			Txtrd& txtrd
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCapability& imeimcapability
			, ImeIMFile& imeimfile
			, ImeIMLibrary& imeimlibrary
			, ImeIMLocale& imeimlocale
			, ImeIMMachine& imeimmachine
			, ImeIMTag1& imeimtag1
			, ImeIMUsergroup& imeimusergroup
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR)) imeiavcontrolpar.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1)) imeiavkeylistkey1.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL)) imeiavvaluelistval.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCAPABILITY)) imeimcapability.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMFILE)) imeimfile.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMLIBRARY)) imeimlibrary.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMLOCALE)) imeimlocale.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMMACHINE)) imeimmachine.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMTAG1)) imeimtag1.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP)) imeimusergroup.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCapability& imeimcapability
			, ImeIMFile& imeimfile
			, ImeIMLibrary& imeimlibrary
			, ImeIMLocale& imeimlocale
			, ImeIMMachine& imeimmachine
			, ImeIMTag1& imeimtag1
			, ImeIMUsergroup& imeimusergroup
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmIni")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.0.9")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.0.9"}});
		};

		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey1.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimcapability.readXML(docctx, basexpath);
		imeimfile.readXML(docctx, basexpath);
		imeimlibrary.readXML(docctx, basexpath);
		imeimlocale.readXML(docctx, basexpath);
		imeimmachine.readXML(docctx, basexpath);
		imeimtag1.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);

	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey1 = ImeIAVKeylistKey1();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimcapability = ImeIMCapability();
		imeimfile = ImeIMFile();
		imeimlibrary = ImeIMLibrary();
		imeimlocale = ImeIMLocale();
		imeimmachine = ImeIMMachine();
		imeimtag1 = ImeIMTag1();
		imeimusergroup = ImeIMUsergroup();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmIni"}});
	};
};

void IexWznmIni::writeTxt(
			fstream& outfile
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCapability& imeimcapability
			, ImeIMFile& imeimfile
			, ImeIMLibrary& imeimlibrary
			, ImeIMLocale& imeimlocale
			, ImeIMMachine& imeimmachine
			, ImeIMTag1& imeimtag1
			, ImeIMUsergroup& imeimusergroup
		) {
	outfile << "IexWznmIni v" WZNM_VERSION << endl;

	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey1.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimcapability.writeTxt(outfile);
	imeimfile.writeTxt(outfile);
	imeimlibrary.writeTxt(outfile);
	imeimlocale.writeTxt(outfile);
	imeimmachine.writeTxt(outfile);
	imeimtag1.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexWznmIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCapability& imeimcapability
			, ImeIMFile& imeimfile
			, ImeIMLibrary& imeimlibrary
			, ImeIMLocale& imeimlocale
			, ImeIMMachine& imeimmachine
			, ImeIMTag1& imeimtag1
			, ImeIMUsergroup& imeimusergroup
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmIni");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey1.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimcapability.writeXML(wr, shorttags);
		imeimfile.writeXML(wr, shorttags);
		imeimlibrary.writeXML(wr, shorttags);
		imeimlocale.writeXML(wr, shorttags);
		imeimmachine.writeXML(wr, shorttags);
		imeimtag1.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmIni::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMCAPABILITYPAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMLIBRARYMAKEFILE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMLIBRARYPKGLIST,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMMACHINEMAKEFILE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMMACHINEPAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMUSERACCESS,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecWznmVIop::INS},{(uint)VecVIme::IMEIAVCONTROLPAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY1,VecWznmVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY2,VecWznmVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY2,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMLOCALETITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMTAGTITLE1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMTAGTITLE2,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCAPABILITY,VecWznmVIop::INS},{(uint)VecVIme::IMEIMFILE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMLIBRARY,VecWznmVIop::INS},{(uint)VecVIme::IMEIMLOCALE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMMACHINE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecWznmVIop::INS},{(uint)VecVIme::IMEIMTAG1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMTAG2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMUSER,VecWznmVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMCAPABILITYUNIVERSAL,VecWznmVIop::INS}};
};

uint IexWznmIni::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};
