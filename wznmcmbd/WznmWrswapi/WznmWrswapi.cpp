/**
	* \file WznmWrswapi.cpp
	* Wznm operation pack global code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrswapi.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrswapi
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrswapi::writeVecSw(
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

	unsigned int ix;

	string pre;

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	if (subclass) {
		pre = "\t\t";

		outfile << "\t/**" << endl;
		outfile << "\t\t* " << subsref << " (full: " << vec->sref << ")" << endl;
		outfile << "\t\t*/" << endl;
		outfile << "\tpublic class " << subsref << " {" << endl;
		outfile << endl;
	} else {
		pre = "\t";
	};

	// constant declarations
	ix = 1;
	for (unsigned int i = 0; i < vits.nodes.size(); i++) {
		vit = vits.nodes[i];

		outfile << pre << "public static let " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ": Int = " << ix << endl;

		if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) ix++;
		else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) ix *= 2;
	};
	outfile << endl;

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		// getIx
		outfile << pre << "public static func getIx(" << endl;
		outfile << pre << "\t\t\t_ sref: String" << endl;
		outfile << pre << "\t\t) -> Int {" << endl;
		outfile << pre << "\tlet s: String = sref.lowercased()" << endl;
		outfile << endl;
		
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << pre << "\tif s == \"" << StrMod::lc(vit->sref) << "\" {return " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << "}" << endl;
		};
		outfile << endl;
		
		outfile << pre << "\treturn 0" << endl;
		outfile << pre << "}" << endl;
		outfile << endl;

	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		// getIx
		outfile << pre << "public static func getIx(" << endl;
		outfile << pre << "\t\t\t_ srefs: String" << endl;
		outfile << pre << "\t\t) -> Int {" << endl;
		// TBD
		outfile << pre << "\treturn 0" << endl;
		outfile << pre << "}" << endl;
		outfile << endl;

		// getIcs
		outfile << pre << "public static func getIcs(" << endl;
		outfile << pre << "\t\t\t_ srefs: String" << endl;
		outfile << pre << "\t\t) -> [Int] {" << endl;
		// TBD
		outfile << pre << "\treturn []" << endl;
		outfile << pre << "}" << endl;
		outfile << endl;
	};

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		// getSref
		outfile << pre << "public static func getSref(" << endl;
		outfile << pre << "\t\t\t_ ix: Int" << endl;
		outfile << pre << "\t\t) -> String {" << endl;
		
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << pre << "\tif ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " {return \"" << vit->sref << "\"}" << endl;
		};
		outfile << endl;
		
		outfile << pre << "\treturn \"\"" << endl;
		outfile << pre << "}" << endl;
		outfile << endl;

	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		// getSrefs
		outfile << pre << "public static func getSrefs(" << endl;
		outfile << pre << "\t\t\t_ ix: Int" << endl;
		outfile << pre << "\t\t) -> String{" << endl;
		outfile << pre << "\tvar ss: [String]" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << pre << "\tif (ix & " << StrMod::uc(StrMod::dotToUsc(vit->sref))  << ") != 0 {ss.append(\"" << vit->sref << "\")}" << endl;
		};
		outfile << endl;

		outfile << pre << "\treturn StrMod.vectorToString(ss)" << endl;
		outfile << pre << "}" << endl;
		outfile << endl;
	};

	if (subclass) {
		outfile << "\t}" << endl;
		outfile << endl;
	};
};

string WznmWrswapi::getSwDefault(
			const string& swtype
		) {
	if (swtype == "Bool") return("false");
	if ((swtype == "Int") || (swtype == "Long")) return("0");
	if ((swtype == "Float") || (swtype == "Double")) return("0.0");
	if (swtype == "String") return("\"\"");

	return(swtype + "()");
};
// IP cust --- IEND
