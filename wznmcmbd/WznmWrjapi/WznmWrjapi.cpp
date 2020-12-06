/**
	* \file WznmWrjapi.cpp
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

#include "WznmWrjapi.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmWrjapi
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrjapi::writeVecJ(
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
		outfile << "\tpublic static class " << subsref << " {" << endl;
		outfile << endl;
	} else {
		pre = "\t";
	};

	// constant declarations
	ix = 1;
	for (unsigned int i = 0; i < vits.nodes.size(); i++) {
		vit = vits.nodes[i];

		outfile << pre << "public static final int " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " = " << ix << ";" << endl;

		if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) ix++;
		else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) ix *= 2;
	};
	outfile << endl;

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		// getIx
		outfile << pre << "public static int getIx(" << endl;
		outfile << pre << "\t\t\tString sref" << endl;
		outfile << pre << "\t\t) {" << endl;
		outfile << pre << "\tString s = sref.toLowerCase();" << endl;
		outfile << endl;
		
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << pre << "\tif (s.equals(\"" << StrMod::lc(vit->sref) << "\")) return " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ";" << endl;
		};
		outfile << endl;
		
		outfile << pre << "\treturn 0;" << endl;
		outfile << pre << "};" << endl;
		outfile << endl;

	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		// getIx
		outfile << pre << "public static int getIx(" << endl;
		outfile << pre << "\t\t\tString srefs" << endl;
		outfile << pre << "\t\t) {" << endl;
		// TBD
		outfile << pre << "\treturn 0;" << endl;
		outfile << pre << "};" << endl;
		outfile << endl;

		// getIcs
		outfile << pre << "public static Vector<Integer> getIcs(" << endl;
		outfile << pre << "\t\t\tString srefs" << endl;
		outfile << pre << "\t\t) {" << endl;
		// TBD
		outfile << pre << "\treturn new Vector<Integer>();" << endl;
		outfile << pre << "};" << endl;
		outfile << endl;
	};

	if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		// getSref
		outfile << pre << "public static String getSref(" << endl;
		outfile << pre << "\t\t\tint ix" << endl;
		outfile << pre << "\t\t) {" << endl;
		
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << pre << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;
		
		outfile << pre << "\treturn \"\";" << endl;
		outfile << pre << "};" << endl;
		outfile << endl;

	} else if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
		// getSrefs
		outfile << pre << "public static String getSrefs(" << endl;
		outfile << pre << "\t\t\tint ix" << endl;
		outfile << pre << "\t\t) {" << endl;
		outfile << pre << "\tArrayList<String> ss = new ArrayList<String>();" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << pre << "\tif (ix & " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") ss.add(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << pre << "\treturn StrMod.vectorToString(ss, ';');" << endl;
		outfile << pre << "};" << endl;
		outfile << endl;
	};

	if (subclass) {
		outfile << "\t};" << endl;
		outfile << endl;
	};
};

string WznmWrjapi::getJDefault(
			const string& jtype
		) {
	if (jtype == "boolean") return("false");
	if (jtype == "int") return("0");
	if (jtype == "long") return("0l");
	if (jtype == "float") return("0.0f");
	if (jtype == "double") return("0.0");
	if (jtype == "String") return("\"\"");

	return("new " + jtype + "()");
};
// IP cust --- IEND
