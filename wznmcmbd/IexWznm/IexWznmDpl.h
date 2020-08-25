/**
	* \file IexWznmDpl.h
	* data blocks and readers/writers for import/export complex IexWznmDpl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef IEXWZNMDPL_H
#define IEXWZNMDPL_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmDplIme IexWznmDpl::VecVIme

#define ImeitemIWznmDplMRelease IexWznmDpl::ImeitemIMRelease
#define ImeIWznmDplMRelease IexWznmDpl::ImeIMRelease
#define VecWImeIWznmDplMReleaseIel IexWznmDpl::ImeIMRelease::VecWIel

#define ImeitemIWznmDplRMComponentMLibrary IexWznmDpl::ImeitemIRMComponentMLibrary
#define ImeIWznmDplRMComponentMLibrary IexWznmDpl::ImeIRMComponentMLibrary
#define VecWImeIWznmDplRMComponentMLibraryIel IexWznmDpl::ImeIRMComponentMLibrary::VecWIel

#define ImeitemIWznmDplMComponent IexWznmDpl::ImeitemIMComponent
#define ImeIWznmDplMComponent IexWznmDpl::ImeIMComponent
#define VecWImeIWznmDplMComponentIel IexWznmDpl::ImeIMComponent::VecWIel

/**
	* IexWznmDpl
	*/
namespace IexWznmDpl {
	/**
		* VecVIme (full: VecVIexWznmDplIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIMCOMPONENT = 1;
		static const Sbecore::uint IMEIMRELEASE = 2;
		static const Sbecore::uint IMEIRMCOMPONENTMLIBRARY = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIMRelease (full: ImeitemIWznmDplMRelease)
		*/
	class ImeitemIMRelease : public WznmMRelease {

	public:
		ImeitemIMRelease(const std::string& srefRefWznmMMachine = "", const std::string& sref = "", const std::string& srefsKOption = "", const std::string& Comment = "");
		ImeitemIMRelease(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMMachine;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRelease (full: ImeIWznmDplMRelease)
		*/
	class ImeIMRelease {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDplMReleaseIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMMACHINE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFSKOPTION = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRelease();
		~ImeIMRelease();

	public:
		std::vector<ImeitemIMRelease*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMComponentMLibrary (full: ImeitemIWznmDplRMComponentMLibrary)
		*/
	class ImeitemIRMComponentMLibrary : public WznmRMComponentMLibrary {

	public:
		ImeitemIRMComponentMLibrary(const std::string& srefRefWznmMLibrary = "");
		ImeitemIRMComponentMLibrary(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMLibrary;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMComponentMLibrary (full: ImeIWznmDplRMComponentMLibrary)
		*/
	class ImeIRMComponentMLibrary {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDplRMComponentMLibraryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMLIBRARY = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMComponentMLibrary();
		~ImeIRMComponentMLibrary();

	public:
		std::vector<ImeitemIRMComponentMLibrary*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMComponent (full: ImeitemIWznmDplMComponent)
		*/
	class ImeitemIMComponent : public WznmMComponent {

	public:
		ImeitemIMComponent(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMComponent(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIMRelease imeimrelease;
		ImeIRMComponentMLibrary imeirmcomponentmlibrary;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMComponent (full: ImeIWznmDplMComponent)
		*/
	class ImeIMComponent {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDplMComponentIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMComponent();
		~ImeIMComponent();

	public:
		std::vector<ImeitemIMComponent*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMComponent& imeimcomponent);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMComponent& imeimcomponent);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMComponent& imeimcomponent);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMComponent& imeimcomponent);

	void writeTxt(std::fstream& outfile, ImeIMComponent& imeimcomponent);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMComponent& imeimcomponent);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

