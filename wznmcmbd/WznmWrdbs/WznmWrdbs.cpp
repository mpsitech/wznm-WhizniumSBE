/**
	* \file WznmWrdbs.cpp
	* Wznm operation pack global code (implementation)
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

#include "WznmWrdbs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmWrdbs
 ******************************************************************************/

// IP cust --- IBEGIN
// stripped down version from WznmWrsrv.cpp
void WznmWrdbs::writeVecH(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMVector* vec
			, const string& subsref
		) {
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	string indent;
	string pre;

	unsigned int ix;

	bool lin, noloc, notit, cmt, apdfed, filfed;

	lin = (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN);
	noloc = StrMod::srefInSrefs(vec->srefsKOption, "noloc");
	notit = StrMod::srefInSrefs(vec->srefsKOption, "notit");
	cmt = StrMod::srefInSrefs(vec->srefsKOption, "cmt");
	apdfed = StrMod::srefInSrefs(vec->srefsKOption, "apdfed");
	filfed = StrMod::srefInSrefs(vec->srefsKOption, "filfed");

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	indent = "\t";

	outfile << indent << "/**" << endl;
	outfile << indent << "\t* " << subsref << " (full: " << vec->sref << ")" << endl;
	outfile << indent << "\t*/" << endl;

	outfile << indent << "class " << subsref << " {" << endl;
	outfile << endl;
	outfile << indent << "public:" << endl;

	ix = 1;
	for (unsigned int i = 0; i < vits.nodes.size(); i++) {
		vit = vits.nodes[i];

		outfile << indent << "\tstatic const Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " = " << ix << ";" << endl;

		if (lin) ix++;
		else ix *= 2;
	};
	outfile << endl;

	pre = indent + "\tstatic ";

	if (lin) {
		outfile << pre << "Sbecore::uint getIx(const std::string& sref);" << endl;
	} else {
		outfile << pre << "Sbecore::uint getIx(const std::string& srefs);" << endl;
		outfile << pre << "void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);" << endl;
	};
	if (lin) {
		outfile << pre << "std::string getSref(const Sbecore::uint ix);" << endl;
	} else {
		outfile << pre << "std::string getSrefs(const Sbecore::uint ix);" << endl;
	};

	if (!notit || cmt) {
		outfile << endl;
		if (!notit) {
			// getTitle
			outfile << pre << "std::string getTitle(const Sbecore::uint ix";
			if (!noloc) outfile << ", const Sbecore::uint ix" << Prjshort << "VLocale";
			outfile << ");" << endl;
		};
		if (cmt) {
			// getComment
			outfile << pre << "std::string getComment(const Sbecore::uint ix";
			if (!noloc) outfile << ", const Sbecore::uint ix" << Prjshort << "VLocale";
			outfile << ");" << endl;
		};
	};

	if (apdfed || filfed) {
		outfile << endl;
		if (apdfed) {
			outfile << pre << "void appendToFeed(const Sbecore::uint ix";
			if (!noloc) outfile << ", const Sbecore::uint ix" << Prjshort << "VLocale";
			outfile << ", Sbecore::Xmlio::Feed& feed);" << endl;
		};
		if (filfed) {
			outfile << pre << "void fillFeed(";
			if (!noloc) outfile << "const Sbecore::uint ix" << Prjshort << "VLocale, ";
			outfile << "Sbecore::Xmlio::Feed& feed);" << endl;
		};
	};

	outfile << indent << "};" << endl;

	outfile << endl;
};

// stripped down version from WznmWrsrv.cpp
void WznmWrdbs::writeVecCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMVector* vec
			, const string& supsref
			, const string& subsref
			, ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	unsigned int ix;
	string val;

	bool lin, noloc, notit, cmt, apdfed, filfed;

	lin = (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN);
	noloc = StrMod::srefInSrefs(vec->srefsKOption, "noloc");
	notit = StrMod::srefInSrefs(vec->srefsKOption, "notit");
	cmt = StrMod::srefInSrefs(vec->srefsKOption, "cmt");
	apdfed = StrMod::srefInSrefs(vec->srefsKOption, "apdfed");
	filfed = StrMod::srefInSrefs(vec->srefsKOption, "filfed");

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << supsref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	if (lin) {
		// getIx
		outfile << "uint " << supsref << "::" << subsref << "::getIx(" << endl;
		outfile << "\t\t\tconst string& sref" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tstring s = StrMod::lc(sref);" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << "\tif (s == \"" << StrMod::lc(vit->sref) << "\") return " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ";" << endl;
		};
		outfile << endl;

		outfile << "\treturn(0);" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// getIx
		outfile << "uint " << supsref << "::" << subsref << "::getIx(" << endl;
		outfile << "\t\t\tconst string& srefs" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tuint ix = 0;" << endl;
		outfile << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tStrMod::stringToVector(StrMod::lc(srefs), ss);" << endl;
		outfile << endl;

		outfile << "\tfor (unsigned int i = 0; i < ss.size(); i++) {" << endl;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (ss[i] == \"" << StrMod::lc(vit->sref) << "\") ix |= " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ";" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn(ix);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// getIcs
		outfile << "void " << supsref << "::" << subsref << "::getIcs(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t\t, set<uint>& ics" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tics.clear();" << endl;
		if (vits.nodes.size() == 0) {
			outfile << "\tfor (unsigned int i = 1; false;) if (ix & i) ics.insert(i);" << endl;
		} else {
			outfile << "\tfor (unsigned int i = 1; i < (2*" << StrMod::uc(StrMod::dotToUsc(vits.nodes[vits.nodes.size()-1]->sref)) << "); i *= 2) if (ix & i) ics.insert(i);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};

	if (lin) {
		// getSref
		outfile << "string " << supsref << "::" << subsref << "::getSref(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t) {" << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// getSrefs
		outfile << "string " << supsref << "::" << subsref << "::getSrefs(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tstring srefs;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << "\tif (ix & " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") ss.push_back(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\tStrMod::vectorToString(ss, srefs);" << endl;
		outfile << endl;

		outfile << "\treturn(srefs);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// getTitle
	if (!notit) {
		outfile << "string " << supsref << "::" << subsref << "::getTitle(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		if (!noloc) outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t) {" << endl;

		if (!noloc) {
			// localized version: ixXxxxVLocale == 1 default locale, other locales refsLcl
			outfile << "\tif (ix" << Prjshort << "VLocale == 1) {" << endl;
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (!dbswznm->loadStringBySQL("SELECT Title FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refLcl), val)) val = vit->Title;

				if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
			};

			if (lin) outfile << "\t\treturn(getSref(ix));" << endl;
			else outfile << "\t\treturn(getSrefs(ix));" << endl;

			ix = 2;
			for (unsigned int i = 0; i < refsLcl.size(); i++) {
				if (refsLcl[i] != refLcl) {
					outfile << "\t} else if (ix" << Prjshort << "VLocale == " << ix << ") {" << endl;
					for (unsigned int j = 0; j < vits.nodes.size(); j++) {
						vit = vits.nodes[j];

						if (!dbswznm->loadStringBySQL("SELECT Title FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refsLcl[i]), val)) val = "";

						if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
					};

					outfile << "\t\treturn(getTitle(ix, 1));" << endl;

					ix++;
				};
			};

			outfile << "\t};" << endl;

		} else {
			// non-localized version
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (vit->Title.length() != 0) outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(vit->Title) << "\");" << endl;
			};

			if (lin) outfile << "\treturn(getSref(ix));" << endl;
			else outfile << "\treturn(getSrefs(ix));" << endl;
		};

		outfile << endl;
		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// getComment
	if (cmt) {
		outfile << "string " << supsref << "::" << subsref << "::getComment(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		if (!noloc) outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t) {" << endl;

		if (!noloc) {
			// localized version: ixXxxxVLocale == 1 default locale, other locales refsLcl
			outfile << "\tif (ix" << Prjshort << "VLocale == 1) {" << endl;
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (!dbswznm->loadStringBySQL("SELECT Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refLcl), val)) val = vit->Comment;

				if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
			};

			ix = 2;
			for (unsigned int i = 0; i < refsLcl.size(); i++) {
				if (refsLcl[i] != refLcl) {
					outfile << "\t} else if (ix" << Prjshort << "VLocale == " << ix << ") {" << endl;
					for (unsigned int j = 0; j < vits.nodes.size(); j++) {
						vit = vits.nodes[j];

						if (!dbswznm->loadStringBySQL("SELECT Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refsLcl[i]), val)) val = "";

						if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
					};

					ix++;
				};
			};

			outfile << "\t};" << endl;

		} else {
			// non-localized version
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (vit->Comment.length() != 0) outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(vit->Comment) << "\");" << endl;
			};
		};

		outfile << endl;
		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// appendToFeed
	if (apdfed) {
		outfile << "void " << supsref << "::" << subsref << "::appendToFeed(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		if (!noloc) outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t\t, Feed& feed" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tfeed.appendIxSrefTitles(ix";
		if (lin) outfile << ", getSref(ix)";
		else outfile << ", getSrefs(ix)";
		if (!notit) {
			outfile << ", getTitle(ix";
			if (!noloc) outfile << ", ix" << Prjshort << "VLocale";
			outfile << ")";
		} else {
			if (lin) outfile << ", getSref(ix)";
			else outfile << ", getSrefs(ix)";
		};
		outfile << ");" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	// fillFeed
	if (filfed) {
		outfile << "void " << supsref << "::" << subsref << "::fillFeed(" << endl;
		if (!noloc) {
			outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
			outfile << "\t\t\t, Feed& feed" << endl;
		} else {
			outfile << "\t\t\tFeed& feed" << endl;
		};
		outfile << "\t\t) {" << endl;

		outfile << "\tfeed.clear();" << endl;
		outfile << endl;

		if (lin) {
			outfile << "\tfor (unsigned int i = 1; i <= " << vits.nodes.size() << "; i++) ";
		} else {
			if (vits.nodes.size() == 0) {
				outfile << "\tfor (unsigned int i = 1; false;) ";
			} else {
				outfile << "\tfor (unsigned int i = 1; i <= " << StrMod::uc(StrMod::dotToUsc(vits.nodes[vits.nodes.size()-1]->sref)) << "; i *= 2) ";
			};
		};

		outfile << "feed.appendIxSrefTitles(i";
		if (lin) outfile << ", getSref(i)";
		else outfile << ", getSrefs(i)";
		if (!notit) {
			outfile << ", getTitle(i";
			if (!noloc) outfile << ", ix" << Prjshort << "VLocale";
			outfile << ")";
		} else {
			if (lin) outfile << ", getSref(i)";
			else outfile << ", getSrefs(i)";
		};
		outfile << ");" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};
};
// IP cust --- IEND



