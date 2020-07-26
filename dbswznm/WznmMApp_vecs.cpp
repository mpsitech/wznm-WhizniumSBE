/**
	* \file WznmMApp_vecs.cpp
	* database access for table TblWznmMApp (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMApp::VecVTarget
 ******************************************************************************/

uint TblWznmMApp::VecVTarget::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cocoa.objc") return COCOA_OBJC;
	if (s == "dotnet.cppcli") return DOTNET_CPPCLI;
	if (s == "java") return JAVA;
	if (s == "js") return JS;
	if (s == "posix.cpp") return POSIX_CPP;
	if (s == "winrt.cpp") return WINRT_CPP;

	return(0);
};

string TblWznmMApp::VecVTarget::getSref(
			const uint ix
		) {
	if (ix == COCOA_OBJC) return("cocoa.objc");
	if (ix == DOTNET_CPPCLI) return("dotnet.cppcli");
	if (ix == JAVA) return("java");
	if (ix == JS) return("js");
	if (ix == POSIX_CPP) return("posix.cpp");
	if (ix == WINRT_CPP) return("winrt.cpp");

	return("");
};

string TblWznmMApp::VecVTarget::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == COCOA_OBJC) return("Cocoa / Objective-C");
		if (ix == DOTNET_CPPCLI) return(".NET / C++ CLI");
		if (ix == JAVA) return("Java");
		if (ix == JS) return("JavaScript");
		if (ix == POSIX_CPP) return("POSIX / C++");
		if (ix == WINRT_CPP) return("WinRT / C++");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMApp::VecVTarget::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

