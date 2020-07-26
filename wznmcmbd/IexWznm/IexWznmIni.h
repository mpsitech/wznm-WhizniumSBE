/**
	* \file IexWznmIni.h
	* data blocks and readers/writers for import/export complex IexWznmIni (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef IEXWZNMINI_H
#define IEXWZNMINI_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmIniIme IexWznmIni::VecVIme

#define ImeitemIWznmIniAVControlPar IexWznmIni::ImeitemIAVControlPar
#define ImeIWznmIniAVControlPar IexWznmIni::ImeIAVControlPar
#define VecWImeIWznmIniAVControlParIel IexWznmIni::ImeIAVControlPar::VecWIel

#define ImeitemIWznmIniJAVKeylistKey1 IexWznmIni::ImeitemIJAVKeylistKey1
#define ImeIWznmIniJAVKeylistKey1 IexWznmIni::ImeIJAVKeylistKey1
#define VecWImeIWznmIniJAVKeylistKey1Iel IexWznmIni::ImeIJAVKeylistKey1::VecWIel

#define ImeitemIWznmIniAVKeylistKey1 IexWznmIni::ImeitemIAVKeylistKey1
#define ImeIWznmIniAVKeylistKey1 IexWznmIni::ImeIAVKeylistKey1
#define VecWImeIWznmIniAVKeylistKey1Iel IexWznmIni::ImeIAVKeylistKey1::VecWIel

#define ImeitemIWznmIniAVValuelistVal IexWznmIni::ImeitemIAVValuelistVal
#define ImeIWznmIniAVValuelistVal IexWznmIni::ImeIAVValuelistVal
#define VecWImeIWznmIniAVValuelistValIel IexWznmIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIWznmIniAMCapabilityPar IexWznmIni::ImeitemIAMCapabilityPar
#define ImeIWznmIniAMCapabilityPar IexWznmIni::ImeIAMCapabilityPar
#define VecWImeIWznmIniAMCapabilityParIel IexWznmIni::ImeIAMCapabilityPar::VecWIel

#define ImeitemIWznmIniJAVKeylistKey2 IexWznmIni::ImeitemIJAVKeylistKey2
#define ImeIWznmIniJAVKeylistKey2 IexWznmIni::ImeIJAVKeylistKey2
#define VecWImeIWznmIniJAVKeylistKey2Iel IexWznmIni::ImeIJAVKeylistKey2::VecWIel

#define ImeitemIWznmIniAVKeylistKey2 IexWznmIni::ImeitemIAVKeylistKey2
#define ImeIWznmIniAVKeylistKey2 IexWznmIni::ImeIAVKeylistKey2
#define VecWImeIWznmIniAVKeylistKey2Iel IexWznmIni::ImeIAVKeylistKey2::VecWIel

#define ImeitemIWznmIniJMTagTitle2 IexWznmIni::ImeitemIJMTagTitle2
#define ImeIWznmIniJMTagTitle2 IexWznmIni::ImeIJMTagTitle2
#define VecWImeIWznmIniJMTagTitle2Iel IexWznmIni::ImeIJMTagTitle2::VecWIel

#define ImeitemIWznmIniMTag2 IexWznmIni::ImeitemIMTag2
#define ImeIWznmIniMTag2 IexWznmIni::ImeIMTag2
#define VecWImeIWznmIniMTag2Iel IexWznmIni::ImeIMTag2::VecWIel

#define ImeitemIWznmIniRMCapabilityUniversal IexWznmIni::ImeitemIRMCapabilityUniversal
#define ImeIWznmIniRMCapabilityUniversal IexWznmIni::ImeIRMCapabilityUniversal
#define VecWImeIWznmIniRMCapabilityUniversalIel IexWznmIni::ImeIRMCapabilityUniversal::VecWIel

#define ImeitemIWznmIniMCapability IexWznmIni::ImeitemIMCapability
#define ImeIWznmIniMCapability IexWznmIni::ImeIMCapability
#define VecWImeIWznmIniMCapabilityIel IexWznmIni::ImeIMCapability::VecWIel

#define ImeitemIWznmIniMFile IexWznmIni::ImeitemIMFile
#define ImeIWznmIniMFile IexWznmIni::ImeIMFile
#define VecWImeIWznmIniMFileIel IexWznmIni::ImeIMFile::VecWIel

#define ImeitemIWznmIniAMLibraryMakefile IexWznmIni::ImeitemIAMLibraryMakefile
#define ImeIWznmIniAMLibraryMakefile IexWznmIni::ImeIAMLibraryMakefile
#define VecWImeIWznmIniAMLibraryMakefileIel IexWznmIni::ImeIAMLibraryMakefile::VecWIel

#define ImeitemIWznmIniAMLibraryPkglist IexWznmIni::ImeitemIAMLibraryPkglist
#define ImeIWznmIniAMLibraryPkglist IexWznmIni::ImeIAMLibraryPkglist
#define VecWImeIWznmIniAMLibraryPkglistIel IexWznmIni::ImeIAMLibraryPkglist::VecWIel

#define ImeitemIWznmIniMLibrary IexWznmIni::ImeitemIMLibrary
#define ImeIWznmIniMLibrary IexWznmIni::ImeIMLibrary
#define VecWImeIWznmIniMLibraryIel IexWznmIni::ImeIMLibrary::VecWIel

#define ImeitemIWznmIniJMLocaleTitle IexWznmIni::ImeitemIJMLocaleTitle
#define ImeIWznmIniJMLocaleTitle IexWznmIni::ImeIJMLocaleTitle
#define VecWImeIWznmIniJMLocaleTitleIel IexWznmIni::ImeIJMLocaleTitle::VecWIel

#define ImeitemIWznmIniMLocale IexWznmIni::ImeitemIMLocale
#define ImeIWznmIniMLocale IexWznmIni::ImeIMLocale
#define VecWImeIWznmIniMLocaleIel IexWznmIni::ImeIMLocale::VecWIel

#define ImeitemIWznmIniAMMachtypeMakefile IexWznmIni::ImeitemIAMMachtypeMakefile
#define ImeIWznmIniAMMachtypeMakefile IexWznmIni::ImeIAMMachtypeMakefile
#define VecWImeIWznmIniAMMachtypeMakefileIel IexWznmIni::ImeIAMMachtypeMakefile::VecWIel

#define ImeitemIWznmIniAMMachinePar IexWznmIni::ImeitemIAMMachinePar
#define ImeIWznmIniAMMachinePar IexWznmIni::ImeIAMMachinePar
#define VecWImeIWznmIniAMMachineParIel IexWznmIni::ImeIAMMachinePar::VecWIel

#define ImeitemIWznmIniMMachine IexWznmIni::ImeitemIMMachine
#define ImeIWznmIniMMachine IexWznmIni::ImeIMMachine
#define VecWImeIWznmIniMMachineIel IexWznmIni::ImeIMMachine::VecWIel

#define ImeitemIWznmIniMMachtype IexWznmIni::ImeitemIMMachtype
#define ImeIWznmIniMMachtype IexWznmIni::ImeIMMachtype
#define VecWImeIWznmIniMMachtypeIel IexWznmIni::ImeIMMachtype::VecWIel

#define ImeitemIWznmIniJMTagTitle1 IexWznmIni::ImeitemIJMTagTitle1
#define ImeIWznmIniJMTagTitle1 IexWznmIni::ImeIJMTagTitle1
#define VecWImeIWznmIniJMTagTitle1Iel IexWznmIni::ImeIJMTagTitle1::VecWIel

#define ImeitemIWznmIniMTag1 IexWznmIni::ImeitemIMTag1
#define ImeIWznmIniMTag1 IexWznmIni::ImeIMTag1
#define VecWImeIWznmIniMTag1Iel IexWznmIni::ImeIMTag1::VecWIel

#define ImeitemIWznmIniAMUsergroupAccess IexWznmIni::ImeitemIAMUsergroupAccess
#define ImeIWznmIniAMUsergroupAccess IexWznmIni::ImeIAMUsergroupAccess
#define VecWImeIWznmIniAMUsergroupAccessIel IexWznmIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIWznmIniAMUserAccess IexWznmIni::ImeitemIAMUserAccess
#define ImeIWznmIniAMUserAccess IexWznmIni::ImeIAMUserAccess
#define VecWImeIWznmIniAMUserAccessIel IexWznmIni::ImeIAMUserAccess::VecWIel

#define ImeitemIWznmIniJMUserState IexWznmIni::ImeitemIJMUserState
#define ImeIWznmIniJMUserState IexWznmIni::ImeIJMUserState
#define VecWImeIWznmIniJMUserStateIel IexWznmIni::ImeIJMUserState::VecWIel

#define ImeitemIWznmIniJMPersonLastname IexWznmIni::ImeitemIJMPersonLastname
#define ImeIWznmIniJMPersonLastname IexWznmIni::ImeIJMPersonLastname
#define VecWImeIWznmIniJMPersonLastnameIel IexWznmIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIWznmIniMPerson IexWznmIni::ImeitemIMPerson
#define ImeIWznmIniMPerson IexWznmIni::ImeIMPerson
#define VecWImeIWznmIniMPersonIel IexWznmIni::ImeIMPerson::VecWIel

#define ImeitemIWznmIniMUser IexWznmIni::ImeitemIMUser
#define ImeIWznmIniMUser IexWznmIni::ImeIMUser
#define VecWImeIWznmIniMUserIel IexWznmIni::ImeIMUser::VecWIel

#define ImeitemIWznmIniMUsergroup IexWznmIni::ImeitemIMUsergroup
#define ImeIWznmIniMUsergroup IexWznmIni::ImeIMUsergroup
#define VecWImeIWznmIniMUsergroupIel IexWznmIni::ImeIMUsergroup::VecWIel

/**
	* IexWznmIni
	*/
namespace IexWznmIni {
	/**
		* VecVIme (full: VecVIexWznmIniIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMCAPABILITYPAR = 1;
		static const Sbecore::uint IMEIAMLIBRARYMAKEFILE = 2;
		static const Sbecore::uint IMEIAMLIBRARYPKGLIST = 3;
		static const Sbecore::uint IMEIAMMACHINEPAR = 4;
		static const Sbecore::uint IMEIAMMACHTYPEMAKEFILE = 5;
		static const Sbecore::uint IMEIAMUSERACCESS = 6;
		static const Sbecore::uint IMEIAMUSERGROUPACCESS = 7;
		static const Sbecore::uint IMEIAVCONTROLPAR = 8;
		static const Sbecore::uint IMEIAVKEYLISTKEY1 = 9;
		static const Sbecore::uint IMEIAVKEYLISTKEY2 = 10;
		static const Sbecore::uint IMEIAVVALUELISTVAL = 11;
		static const Sbecore::uint IMEIJAVKEYLISTKEY1 = 12;
		static const Sbecore::uint IMEIJAVKEYLISTKEY2 = 13;
		static const Sbecore::uint IMEIJMLOCALETITLE = 14;
		static const Sbecore::uint IMEIJMPERSONLASTNAME = 15;
		static const Sbecore::uint IMEIJMTAGTITLE1 = 16;
		static const Sbecore::uint IMEIJMTAGTITLE2 = 17;
		static const Sbecore::uint IMEIJMUSERSTATE = 18;
		static const Sbecore::uint IMEIMCAPABILITY = 19;
		static const Sbecore::uint IMEIMFILE = 20;
		static const Sbecore::uint IMEIMLIBRARY = 21;
		static const Sbecore::uint IMEIMLOCALE = 22;
		static const Sbecore::uint IMEIMMACHINE = 23;
		static const Sbecore::uint IMEIMMACHTYPE = 24;
		static const Sbecore::uint IMEIMPERSON = 25;
		static const Sbecore::uint IMEIMTAG1 = 26;
		static const Sbecore::uint IMEIMTAG2 = 27;
		static const Sbecore::uint IMEIMUSER = 28;
		static const Sbecore::uint IMEIMUSERGROUP = 29;
		static const Sbecore::uint IMEIRMCAPABILITYUNIVERSAL = 30;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAVControlPar (full: ImeitemIWznmIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public WznmAVControlPar {

	public:
		ImeitemIAVControlPar(const Sbecore::uint ixWznmVControl = 0, const std::string& Par = "", const std::string& Val = "");
		ImeitemIAVControlPar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWznmVControl;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIWznmIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVCONTROL = 1;
			static const Sbecore::uint PAR = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		std::vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey1 (full: ImeitemIWznmIniJAVKeylistKey1)
		*/
	class ImeitemIJAVKeylistKey1 : public WznmJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey1(const Sbecore::uint x1IxWznmVLocale = 0, const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWznmVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey1 (full: ImeIWznmIniJAVKeylistKey1)
		*/
	class ImeIJAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZNMVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey1();
		~ImeIJAVKeylistKey1();

	public:
		std::vector<ImeitemIJAVKeylistKey1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey1 (full: ImeitemIWznmIniAVKeylistKey1)
		*/
	class ImeitemIAVKeylistKey1 : public WznmAVKeylistKey {

	public:
		ImeitemIAVKeylistKey1(const Sbecore::uint klsIxWznmVKeylist = 0, const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxWznmVKeylist;

		ImeIJAVKeylistKey1 imeijavkeylistkey1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey1 (full: ImeIWznmIniAVKeylistKey1)
		*/
	class ImeIAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXWZNMVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint AVAIL = 4;
			static const Sbecore::uint IMPLIED = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey1();
		~ImeIAVKeylistKey1();

	public:
		std::vector<ImeitemIAVKeylistKey1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIWznmIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public WznmAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const Sbecore::uint vlsIxWznmVValuelist = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string& Val = "");
		ImeitemIAVValuelistVal(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefVlsIxWznmVValuelist;
		std::string srefX1IxWznmVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIWznmIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFVLSIXWZNMVVALUELIST = 1;
			static const Sbecore::uint SREFX1IXWZNMVLOCALE = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		std::vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCapabilityPar (full: ImeitemIWznmIniAMCapabilityPar)
		*/
	class ImeitemIAMCapabilityPar : public WznmAMCapabilityPar {

	public:
		ImeitemIAMCapabilityPar(const std::string& x1SrefKKey = "", const std::string& Val = "");
		ImeitemIAMCapabilityPar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMCapabilityPar (full: ImeIWznmIniAMCapabilityPar)
		*/
	class ImeIAMCapabilityPar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMCapabilityParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKKEY = 1;
			static const Sbecore::uint VAL = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMCapabilityPar();
		~ImeIAMCapabilityPar();

	public:
		std::vector<ImeitemIAMCapabilityPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey2 (full: ImeitemIWznmIniJAVKeylistKey2)
		*/
	class ImeitemIJAVKeylistKey2 : public WznmJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey2(const Sbecore::uint x1IxWznmVLocale = 0, const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWznmVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey2 (full: ImeIWznmIniJAVKeylistKey2)
		*/
	class ImeIJAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJAVKeylistKey2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZNMVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey2();
		~ImeIJAVKeylistKey2();

	public:
		std::vector<ImeitemIJAVKeylistKey2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey2 (full: ImeitemIWznmIniAVKeylistKey2)
		*/
	class ImeitemIAVKeylistKey2 : public WznmAVKeylistKey {

	public:
		ImeitemIAVKeylistKey2(const Sbecore::uint klsIxWznmVKeylist = 0, const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxWznmVKeylist;

		ImeIJAVKeylistKey2 imeijavkeylistkey2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey2 (full: ImeIWznmIniAVKeylistKey2)
		*/
	class ImeIAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAVKeylistKey2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXWZNMVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey2();
		~ImeIAVKeylistKey2();

	public:
		std::vector<ImeitemIAVKeylistKey2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMTagTitle2 (full: ImeitemIWznmIniJMTagTitle2)
		*/
	class ImeitemIJMTagTitle2 : public WznmJMTagTitle {

	public:
		ImeitemIJMTagTitle2(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMTagTitle2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMTagTitle2 (full: ImeIWznmIniJMTagTitle2)
		*/
	class ImeIJMTagTitle2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJMTagTitle2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMLOCALE = 1;
			static const Sbecore::uint TITLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMTagTitle2();
		~ImeIJMTagTitle2();

	public:
		std::vector<ImeitemIJMTagTitle2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMTag2 (full: ImeitemIWznmIniMTag2)
		*/
	class ImeitemIMTag2 : public WznmMTag {

	public:
		ImeitemIMTag2(const std::string& sref = "", const std::string& Title = "");
		ImeitemIMTag2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMTagTitle2 imeijmtagtitle2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTag2 (full: ImeIWznmIniMTag2)
		*/
	class ImeIMTag2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMTag2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMTag2();
		~ImeIMTag2();

	public:
		std::vector<ImeitemIMTag2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMCapabilityUniversal (full: ImeitemIWznmIniRMCapabilityUniversal)
		*/
	class ImeitemIRMCapabilityUniversal : public WznmRMCapabilityUniversal {

	public:
		ImeitemIRMCapabilityUniversal(const Sbecore::uint unvIxWznmVMaintable = 0, const std::string& srefKKey = "");
		ImeitemIRMCapabilityUniversal(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefUnvIxWznmVMaintable;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCapabilityUniversal (full: ImeIWznmIniRMCapabilityUniversal)
		*/
	class ImeIRMCapabilityUniversal {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniRMCapabilityUniversalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFUNVIXWZNMVMAINTABLE = 1;
			static const Sbecore::uint SREFKKEY = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMCapabilityUniversal();
		~ImeIRMCapabilityUniversal();

	public:
		std::vector<ImeitemIRMCapabilityUniversal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCapability (full: ImeitemIWznmIniMCapability)
		*/
	class ImeitemIMCapability : public WznmMCapability {

	public:
		ImeitemIMCapability(const std::string& sref = "", const std::string& Title = "", const Sbecore::uint ixWArtefact = 0);
		ImeitemIMCapability(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefsIxWArtefact;

		ImeIAMCapabilityPar imeiamcapabilitypar;
		ImeIAVKeylistKey2 imeiavkeylistkey2;
		ImeIMTag2 imeimtag2;
		ImeIRMCapabilityUniversal imeirmcapabilityuniversal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCapability (full: ImeIWznmIniMCapability)
		*/
	class ImeIMCapability {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMCapabilityIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint SREFSIXWARTEFACT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCapability();
		~ImeIMCapability();

	public:
		std::vector<ImeitemIMCapability*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile (full: ImeitemIWznmIniMFile)
		*/
	class ImeitemIMFile : public WznmMFile {

	public:
		ImeitemIMFile(const std::string& osrefKContent = "", const std::string& Filename = "", const std::string& srefKMimetype = "", const std::string& Comment = "");
		ImeitemIMFile(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile (full: ImeIWznmIniMFile)
		*/
	class ImeIMFile {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMFileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint OSREFKCONTENT = 1;
			static const Sbecore::uint FILENAME = 2;
			static const Sbecore::uint SREFKMIMETYPE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFile();
		~ImeIMFile();

	public:
		std::vector<ImeitemIMFile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMLibraryMakefile (full: ImeitemIWznmIniAMLibraryMakefile)
		*/
	class ImeitemIAMLibraryMakefile : public WznmAMLibraryMakefile {

	public:
		ImeitemIAMLibraryMakefile(const Sbecore::uint x1RefIxVTbl = 0, const std::string& srefX1RefUref = "", const std::string& x2SrefKTag = "", const std::string& Val = "");
		ImeitemIAMLibraryMakefile(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefIxVTbl;
		std::string srefX1RefUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMLibraryMakefile (full: ImeIWznmIniAMLibraryMakefile)
		*/
	class ImeIAMLibraryMakefile {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMLibraryMakefileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFIXVTBL = 1;
			static const Sbecore::uint SREFX1REFUREF = 2;
			static const Sbecore::uint X2SREFKTAG = 4;
			static const Sbecore::uint VAL = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMLibraryMakefile();
		~ImeIAMLibraryMakefile();

	public:
		std::vector<ImeitemIAMLibraryMakefile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMLibraryPkglist (full: ImeitemIWznmIniAMLibraryPkglist)
		*/
	class ImeitemIAMLibraryPkglist : public WznmAMLibraryPkglist {

	public:
		ImeitemIAMLibraryPkglist(const Sbecore::uint x1RefIxVTbl = 0, const std::string& srefX1RefUref = "", const std::string& Pkglist = "");
		ImeitemIAMLibraryPkglist(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefIxVTbl;
		std::string srefX1RefUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMLibraryPkglist (full: ImeIWznmIniAMLibraryPkglist)
		*/
	class ImeIAMLibraryPkglist {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMLibraryPkglistIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFIXVTBL = 1;
			static const Sbecore::uint SREFX1REFUREF = 2;
			static const Sbecore::uint PKGLIST = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMLibraryPkglist();
		~ImeIAMLibraryPkglist();

	public:
		std::vector<ImeitemIAMLibraryPkglist*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLibrary (full: ImeitemIWznmIniMLibrary)
		*/
	class ImeitemIMLibrary : public WznmMLibrary {

	public:
		ImeitemIMLibrary(const std::string& sref = "", const std::string& Title = "", const std::string& Version = "", const std::string& srefKLictype = "", const std::string& depSrefsWznmMLibrary = "", const std::string& Comment = "");
		ImeitemIMLibrary(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMLibraryMakefile imeiamlibrarymakefile;
		ImeIAMLibraryPkglist imeiamlibrarypkglist;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLibrary (full: ImeIWznmIniMLibrary)
		*/
	class ImeIMLibrary {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMLibraryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint VERSION = 4;
			static const Sbecore::uint SREFKLICTYPE = 8;
			static const Sbecore::uint DEPSREFSWZNMMLIBRARY = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMLibrary();
		~ImeIMLibrary();

	public:
		std::vector<ImeitemIMLibrary*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMLocaleTitle (full: ImeitemIWznmIniJMLocaleTitle)
		*/
	class ImeitemIJMLocaleTitle : public WznmJMLocaleTitle {

	public:
		ImeitemIJMLocaleTitle(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMLocaleTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMLocaleTitle (full: ImeIWznmIniJMLocaleTitle)
		*/
	class ImeIJMLocaleTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJMLocaleTitleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMLOCALE = 1;
			static const Sbecore::uint TITLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMLocaleTitle();
		~ImeIJMLocaleTitle();

	public:
		std::vector<ImeitemIJMLocaleTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLocale (full: ImeitemIWznmIniMLocale)
		*/
	class ImeitemIMLocale : public WznmMLocale {

	public:
		ImeitemIMLocale(const std::string& sref = "", const std::string& Title = "");
		ImeitemIMLocale(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMLocaleTitle imeijmlocaletitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLocale (full: ImeIWznmIniMLocale)
		*/
	class ImeIMLocale {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMLocaleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMLocale();
		~ImeIMLocale();

	public:
		std::vector<ImeitemIMLocale*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMMachtypeMakefile (full: ImeitemIWznmIniAMMachtypeMakefile)
		*/
	class ImeitemIAMMachtypeMakefile : public WznmAMMachtypeMakefile {

	public:
		ImeitemIAMMachtypeMakefile(const std::string& x1SrefKTag = "", const std::string& Val = "");
		ImeitemIAMMachtypeMakefile(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMachtypeMakefile (full: ImeIWznmIniAMMachtypeMakefile)
		*/
	class ImeIAMMachtypeMakefile {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMMachtypeMakefileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKTAG = 1;
			static const Sbecore::uint VAL = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMMachtypeMakefile();
		~ImeIAMMachtypeMakefile();

	public:
		std::vector<ImeitemIAMMachtypeMakefile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMMachinePar (full: ImeitemIWznmIniAMMachinePar)
		*/
	class ImeitemIAMMachinePar : public WznmAMMachinePar {

	public:
		ImeitemIAMMachinePar(const std::string& x1SrefKKey = "", const std::string& Val = "");
		ImeitemIAMMachinePar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMachinePar (full: ImeIWznmIniAMMachinePar)
		*/
	class ImeIAMMachinePar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMMachineParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKKEY = 1;
			static const Sbecore::uint VAL = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMMachinePar();
		~ImeIAMMachinePar();

	public:
		std::vector<ImeitemIAMMachinePar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMMachine (full: ImeitemIWznmIniMMachine)
		*/
	class ImeitemIMMachine : public WznmMMachine {

	public:
		ImeitemIMMachine(const std::string& sref = "", const Sbecore::uint ixWznmWCloudtype = 0, const std::string& Comment = "");
		ImeitemIMMachine(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWznmWCloudtype;

		ImeIAMMachinePar imeiammachinepar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMMachine (full: ImeIWznmIniMMachine)
		*/
	class ImeIMMachine {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMMachineIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXWZNMWCLOUDTYPE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMMachine();
		~ImeIMMachine();

	public:
		std::vector<ImeitemIMMachine*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMMachtype (full: ImeitemIWznmIniMMachtype)
		*/
	class ImeitemIMMachtype : public WznmMMachtype {

	public:
		ImeitemIMMachtype(const std::string& sref = "", const Sbecore::uint ixVArch = 0, const std::string& srefKOs = "", const std::string& srefCchRefWznmMMachine = "", const std::string& srefKPkgmgr = "", const std::string& Comment = "");
		ImeitemIMMachtype(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVArch;
		std::string srefCchRefWznmMMachine;

		ImeIAMMachtypeMakefile imeiammachtypemakefile;
		ImeIMMachine imeimmachine;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMMachtype (full: ImeIWznmIniMMachtype)
		*/
	class ImeIMMachtype {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMMachtypeIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVARCH = 2;
			static const Sbecore::uint SREFKOS = 4;
			static const Sbecore::uint SREFCCHREFWZNMMMACHINE = 8;
			static const Sbecore::uint SREFKPKGMGR = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMMachtype();
		~ImeIMMachtype();

	public:
		std::vector<ImeitemIMMachtype*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMTagTitle1 (full: ImeitemIWznmIniJMTagTitle1)
		*/
	class ImeitemIJMTagTitle1 : public WznmJMTagTitle {

	public:
		ImeitemIJMTagTitle1(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMTagTitle1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMTagTitle1 (full: ImeIWznmIniJMTagTitle1)
		*/
	class ImeIJMTagTitle1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJMTagTitle1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMLOCALE = 1;
			static const Sbecore::uint TITLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMTagTitle1();
		~ImeIJMTagTitle1();

	public:
		std::vector<ImeitemIJMTagTitle1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMTag1 (full: ImeitemIWznmIniMTag1)
		*/
	class ImeitemIMTag1 : public WznmMTag {

	public:
		ImeitemIMTag1(const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& Title = "");
		ImeitemIMTag1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMTagTitle1 imeijmtagtitle1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTag1 (full: ImeIWznmIniMTag1)
		*/
	class ImeIMTag1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMTag1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint OSREFWZNMKTAGGRP = 2;
			static const Sbecore::uint TITLE = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMTag1();
		~ImeIMTag1();

	public:
		std::vector<ImeitemIMTag1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIWznmIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public WznmAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);
		ImeitemIAMUsergroupAccess(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWznmVFeatgroup;
		std::string srefsIxWznmWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIWznmIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZNMVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWZNMWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		std::vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUserAccess (full: ImeitemIWznmIniAMUserAccess)
		*/
	class ImeitemIAMUserAccess : public WznmAMUserAccess {

	public:
		ImeitemIAMUserAccess(const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);
		ImeitemIAMUserAccess(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWznmVFeatgroup;
		std::string srefsIxWznmWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUserAccess (full: ImeIWznmIniAMUserAccess)
		*/
	class ImeIAMUserAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniAMUserAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZNMVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWZNMWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUserAccess();
		~ImeIAMUserAccess();

	public:
		std::vector<ImeitemIAMUserAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIWznmIniJMUserState)
		*/
	class ImeitemIJMUserState : public WznmJMUserState {

	public:
		ImeitemIJMUserState(const Sbecore::uint ixVState = 0);
		ImeitemIJMUserState(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIWznmIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		std::vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIWznmIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public WznmJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const std::string& Lastname = "");
		ImeitemIJMPersonLastname(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIWznmIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint LASTNAME = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		std::vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIWznmIniMPerson)
		*/
	class ImeitemIMPerson : public WznmMPerson {

	public:
		ImeitemIMPerson(const Sbecore::uint ixVSex = 0, const std::string& Title = "", const std::string& Firstname = "", const std::string& Lastname = "");
		ImeitemIMPerson(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVSex;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIWznmIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSEX = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint FIRSTNAME = 4;
			static const Sbecore::uint LASTNAME = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		std::vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIWznmIniMUser)
		*/
	class ImeitemIMUser : public WznmMUser {

	public:
		ImeitemIMUser(const std::string& sref = "", const Sbecore::uint ixVState = 0, const Sbecore::uint ixWznmVLocale = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string& Password = "", const std::string& Fullkey = "", const std::string& Comment = "");
		ImeitemIMUser(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefIxWznmVLocale;
		std::string srefIxWznmVUserlevel;

		ImeIAMUserAccess imeiamuseraccess;
		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIWznmIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMUserIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVSTATE = 2;
			static const Sbecore::uint SREFIXWZNMVLOCALE = 4;
			static const Sbecore::uint SREFIXWZNMVUSERLEVEL = 8;
			static const Sbecore::uint PASSWORD = 16;
			static const Sbecore::uint FULLKEY = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		std::vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIWznmIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public WznmMUsergroup {

	public:
		ImeitemIMUsergroup(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMUsergroup(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIWznmIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		std::vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCapability& imeimcapability, ImeIMFile& imeimfile, ImeIMLibrary& imeimlibrary, ImeIMLocale& imeimlocale, ImeIMMachtype& imeimmachtype, ImeIMTag1& imeimtag1, ImeIMUsergroup& imeimusergroup);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCapability& imeimcapability, ImeIMFile& imeimfile, ImeIMLibrary& imeimlibrary, ImeIMLocale& imeimlocale, ImeIMMachtype& imeimmachtype, ImeIMTag1& imeimtag1, ImeIMUsergroup& imeimusergroup);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCapability& imeimcapability, ImeIMFile& imeimfile, ImeIMLibrary& imeimlibrary, ImeIMLocale& imeimlocale, ImeIMMachtype& imeimmachtype, ImeIMTag1& imeimtag1, ImeIMUsergroup& imeimusergroup);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCapability& imeimcapability, ImeIMFile& imeimfile, ImeIMLibrary& imeimlibrary, ImeIMLocale& imeimlocale, ImeIMMachtype& imeimmachtype, ImeIMTag1& imeimtag1, ImeIMUsergroup& imeimusergroup);

	void writeTxt(std::fstream& outfile, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCapability& imeimcapability, ImeIMFile& imeimfile, ImeIMLibrary& imeimlibrary, ImeIMLocale& imeimlocale, ImeIMMachtype& imeimmachtype, ImeIMTag1& imeimtag1, ImeIMUsergroup& imeimusergroup);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCapability& imeimcapability, ImeIMFile& imeimfile, ImeIMLibrary& imeimlibrary, ImeIMLocale& imeimlocale, ImeIMMachtype& imeimmachtype, ImeIMTag1& imeimtag1, ImeIMUsergroup& imeimusergroup);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

