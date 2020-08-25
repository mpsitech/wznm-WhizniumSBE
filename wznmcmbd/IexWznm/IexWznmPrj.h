/**
	* \file IexWznmPrj.h
	* data blocks and readers/writers for import/export complex IexWznmPrj (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef IEXWZNMPRJ_H
#define IEXWZNMPRJ_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmPrjIme IexWznmPrj::VecVIme

#define ImeitemIWznmPrjJMVersion IexWznmPrj::ImeitemIJMVersion
#define ImeIWznmPrjJMVersion IexWznmPrj::ImeIJMVersion
#define VecWImeIWznmPrjJMVersionIel IexWznmPrj::ImeIJMVersion::VecWIel

#define ImeitemIWznmPrjJMVersionState IexWznmPrj::ImeitemIJMVersionState
#define ImeIWznmPrjJMVersionState IexWznmPrj::ImeIJMVersionState
#define VecWImeIWznmPrjJMVersionStateIel IexWznmPrj::ImeIJMVersionState::VecWIel

#define ImeitemIWznmPrjRMLocaleMVersion IexWznmPrj::ImeitemIRMLocaleMVersion
#define ImeIWznmPrjRMLocaleMVersion IexWznmPrj::ImeIRMLocaleMVersion
#define VecWImeIWznmPrjRMLocaleMVersionIel IexWznmPrj::ImeIRMLocaleMVersion::VecWIel

#define ImeitemIWznmPrjMVersion IexWznmPrj::ImeitemIMVersion
#define ImeIWznmPrjMVersion IexWznmPrj::ImeIMVersion
#define VecWImeIWznmPrjMVersionIel IexWznmPrj::ImeIMVersion::VecWIel

#define ImeitemIWznmPrjRMPersonMProject IexWznmPrj::ImeitemIRMPersonMProject
#define ImeIWznmPrjRMPersonMProject IexWznmPrj::ImeIRMPersonMProject
#define VecWImeIWznmPrjRMPersonMProjectIel IexWznmPrj::ImeIRMPersonMProject::VecWIel

#define ImeitemIWznmPrjMProject IexWznmPrj::ImeitemIMProject
#define ImeIWznmPrjMProject IexWznmPrj::ImeIMProject
#define VecWImeIWznmPrjMProjectIel IexWznmPrj::ImeIMProject::VecWIel

/**
	* IexWznmPrj
	*/
namespace IexWznmPrj {
	/**
		* VecVIme (full: VecVIexWznmPrjIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIJMVERSION = 1;
		static const Sbecore::uint IMEIJMVERSIONSTATE = 2;
		static const Sbecore::uint IMEIMPROJECT = 3;
		static const Sbecore::uint IMEIMVERSION = 4;
		static const Sbecore::uint IMEIRMLOCALEMVERSION = 5;
		static const Sbecore::uint IMEIRMPERSONMPROJECT = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIJMVersion (full: ImeitemIWznmPrjJMVersion)
		*/
	class ImeitemIJMVersion : public WznmJMVersion {

	public:
		ImeitemIJMVersion(const std::string& srefX1RefWznmMLocale = "", const std::string& About1 = "", const std::string& About2 = "", const std::string& About3 = "");
		ImeitemIJMVersion(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMVersion (full: ImeIWznmPrjJMVersion)
		*/
	class ImeIJMVersion {

	public:
		/**
			* VecWIel (full: VecWImeIWznmPrjJMVersionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMLOCALE = 1;
			static const Sbecore::uint ABOUT1 = 2;
			static const Sbecore::uint ABOUT2 = 4;
			static const Sbecore::uint ABOUT3 = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMVersion();
		~ImeIJMVersion();

	public:
		std::vector<ImeitemIJMVersion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMVersionState (full: ImeitemIWznmPrjJMVersionState)
		*/
	class ImeitemIJMVersionState : public WznmJMVersionState {

	public:
		ImeitemIJMVersionState(const Sbecore::uint ixVState = 0);
		ImeitemIJMVersionState(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMVersionState (full: ImeIWznmPrjJMVersionState)
		*/
	class ImeIJMVersionState {

	public:
		/**
			* VecWIel (full: VecWImeIWznmPrjJMVersionStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMVersionState();
		~ImeIJMVersionState();

	public:
		std::vector<ImeitemIJMVersionState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMLocaleMVersion (full: ImeitemIWznmPrjRMLocaleMVersion)
		*/
	class ImeitemIRMLocaleMVersion : public WznmRMLocaleMVersion {

	public:
		ImeitemIRMLocaleMVersion(const std::string& srefRefWznmMLocale = "");
		ImeitemIRMLocaleMVersion(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMLocaleMVersion (full: ImeIWznmPrjRMLocaleMVersion)
		*/
	class ImeIRMLocaleMVersion {

	public:
		/**
			* VecWIel (full: VecWImeIWznmPrjRMLocaleMVersionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMLOCALE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMLocaleMVersion();
		~ImeIRMLocaleMVersion();

	public:
		std::vector<ImeitemIRMLocaleMVersion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVersion (full: ImeitemIWznmPrjMVersion)
		*/
	class ImeitemIMVersion : public WznmMVersion {

	public:
		ImeitemIMVersion(const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWDbmstype = 0, const Sbecore::uint ixWOption = 0, const std::string& About1 = "", const std::string& About2 = "", const std::string& About3 = "", const std::string& Comment = "");
		ImeitemIMVersion(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefsIxWDbmstype;
		std::string srefsIxWOption;

		ImeIJMVersion imeijmversion;
		ImeIJMVersionState imeijmversionstate;
		ImeIRMLocaleMVersion imeirmlocalemversion;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVersion (full: ImeIWznmPrjMVersion)
		*/
	class ImeIMVersion {

	public:
		/**
			* VecWIel (full: VecWImeIWznmPrjMVersionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint MAJOR = 1;
			static const Sbecore::uint MINOR = 2;
			static const Sbecore::uint SUB = 4;
			static const Sbecore::uint SREFIXVSTATE = 8;
			static const Sbecore::uint SREFSIXWDBMSTYPE = 16;
			static const Sbecore::uint SREFSIXWOPTION = 32;
			static const Sbecore::uint ABOUT1 = 64;
			static const Sbecore::uint ABOUT2 = 128;
			static const Sbecore::uint ABOUT3 = 256;
			static const Sbecore::uint COMMENT = 512;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVersion();
		~ImeIMVersion();

	public:
		std::vector<ImeitemIMVersion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMPersonMProject (full: ImeitemIWznmPrjRMPersonMProject)
		*/
	class ImeitemIRMPersonMProject : public WznmRMPersonMProject {

	public:
		ImeitemIRMPersonMProject(const std::string& hintRefWznmMPerson = "", const std::string& srefKFunction = "");
		ImeitemIRMPersonMProject(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hintRefWznmMPerson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMPersonMProject (full: ImeIWznmPrjRMPersonMProject)
		*/
	class ImeIRMPersonMProject {

	public:
		/**
			* VecWIel (full: VecWImeIWznmPrjRMPersonMProjectIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HINTREFWZNMMPERSON = 1;
			static const Sbecore::uint SREFKFUNCTION = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMPersonMProject();
		~ImeIRMPersonMProject();

	public:
		std::vector<ImeitemIRMPersonMProject*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMProject (full: ImeitemIWznmPrjMProject)
		*/
	class ImeitemIMProject : public WznmMProject {

	public:
		ImeitemIMProject(const std::string& Short = "", const std::string& Title = "", const std::string& Giturl = "", const std::string& Comment = "");
		ImeitemIMProject(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMVersion imeimversion;
		ImeIRMPersonMProject imeirmpersonmproject;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMProject (full: ImeIWznmPrjMProject)
		*/
	class ImeIMProject {

	public:
		/**
			* VecWIel (full: VecWImeIWznmPrjMProjectIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SHORT = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint GITURL = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMProject();
		~ImeIMProject();

	public:
		std::vector<ImeitemIMProject*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMProject& imeimproject);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMProject& imeimproject);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMProject& imeimproject);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMProject& imeimproject);

	void writeTxt(std::fstream& outfile, ImeIMProject& imeimproject);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMProject& imeimproject);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

