/**
	* \file WznmWrapi.cpp
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

#include "WznmWrapi.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmWrapi
 ******************************************************************************/

// IP cust --- IBEGIN
// stripped down version from WznmWrsrv.cpp
void WznmWrapi::writeVecH(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMVector* vec
			, const bool subclass
			, const string& subsref
		) {
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	unsigned int ix;

	string pre;

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	if (subclass) {
		outfile << "\t/**" << endl;
		outfile << "\t\t* " << subsref << " (full: " << vec->sref << ")" << endl;
		outfile << "\t\t*/" << endl;

		outfile << "\tclass " << subsref << " {" << endl;
		outfile << endl;
		outfile << "\tpublic:" << endl;

		ix = 1;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\t\tstatic const Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " = " << ix << ";" << endl;

			if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) ix++;
			else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) ix *= 2;
		};
		outfile << endl;

	} else {
		outfile << "/**" << endl;
		outfile << "\t* " << vec->sref << endl;
		outfile << "\t*/" << endl;

		outfile << "namespace " << vec->sref << " {" << endl;

		ix = 1;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\tconst Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " = " << ix << ";" << endl;

			if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) ix++;
			else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) ix *= 2;
		};
		outfile << endl;
	};

	if (subclass) {
		pre = "\t\tstatic ";
	} else {
		pre = "\t";
	};

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		outfile << pre << "Sbecore::uint getIx(const std::string& sref);" << endl;
	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		outfile << pre << "Sbecore::uint getIx(const std::string& srefs);" << endl;
		outfile << pre << "void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);" << endl;
	};
	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		outfile << pre << "std::string getSref(const Sbecore::uint ix);" << endl;
	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		outfile << pre << "std::string getSrefs(const Sbecore::uint ix);" << endl;
	};

	if (subclass) {
		outfile << "\t};" << endl;
	} else {
		outfile << "};" << endl;
	};
	outfile << endl;
};

// stripped down version from WznmWrsrv.cpp
void WznmWrapi::writeVecCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMVector* vec
			, const bool subclass
			, const string& supsref
			, const string& subsref
		) {
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	string val;

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	outfile << "/******************************************************************************" << endl;
	if (subclass) outfile << " class " << supsref << "::" << subsref << endl;
	else outfile << " namespace " << vec->sref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		// getIx
		if (subclass) outfile << "uint " << supsref << "::" << subsref << "::getIx(" << endl;
		else outfile << "uint " << vec->sref << "::getIx(" << endl;
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

	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		// getIx
		if (subclass) outfile << "uint " << supsref << "::" << subsref << "::getIx(" << endl;
		else outfile << "uint " << vec->sref << "::getIx(" << endl;
		outfile << "\t\t\tconst string& srefs" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tuint ix = 0;" << endl;
		outfile << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tStrMod::srefsToVector(StrMod::lc(srefs), ss);" << endl;
		outfile << endl;

		outfile << "\tfor (unsigned int i = 0; i < ss.size(); i++) {" << endl;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\t\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (ss[i] == \"" << StrMod::lc(vit->sref) << "\") ix |= " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ";" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn(ix);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// getIcs
		if (subclass) outfile << "void " << supsref << "::" << subsref << "::getIcs(" << endl;
		else outfile << "void " << vec->sref << "::getIcs(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t\t, vector<uint>& ics" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tics.clear();" << endl;
		if (vits.nodes.size() == 0) {
			outfile << "\tfor (unsigned int i = 1; false;) if (ix & i) ics.insert(i);" << endl;
		} else {
			outfile << "\tfor (unsigned int i = 1; i < (2*" << StrMod::uc(StrMod::dotToUsc(vits.nodes[vits.nodes.size()-1]->sref)) << "); i*=2) if (ix & i) ics.insert(i);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		// getSref
		if (subclass) outfile << "string " << supsref << "::" << subsref << "::getSref(" << endl;
		else outfile << "string " << vec->sref << "::getSref(" << endl;
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

	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		// getSrefs
		if (subclass) outfile << "string " << supsref << "::" << subsref << "::getSrefs(" << endl;
		else outfile << "string " << vec->sref << "::getSrefs(" << endl;
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
};
// IP cust --- IEND
