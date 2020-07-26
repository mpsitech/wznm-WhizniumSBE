/**
	* \file IexWznmBui.h
	* data blocks and readers/writers for import/export complex IexWznmBui (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef IEXWZNMBUI_H
#define IEXWZNMBUI_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmBuiIme IexWznmBui::VecVIme

#define ImeitemIWznmBuiJMModule IexWznmBui::ImeitemIJMModule
#define ImeIWznmBuiJMModule IexWznmBui::ImeIJMModule
#define VecWImeIWznmBuiJMModuleIel IexWznmBui::ImeIJMModule::VecWIel

#define ImeitemIWznmBuiJMCardTitle IexWznmBui::ImeitemIJMCardTitle
#define ImeIWznmBuiJMCardTitle IexWznmBui::ImeIJMCardTitle
#define VecWImeIWznmBuiJMCardTitleIel IexWznmBui::ImeIJMCardTitle::VecWIel

#define ImeitemIWznmBuiMCard IexWznmBui::ImeitemIMCard
#define ImeIWznmBuiMCard IexWznmBui::ImeIMCard
#define VecWImeIWznmBuiMCardIel IexWznmBui::ImeIMCard::VecWIel

#define ImeitemIWznmBuiMModule IexWznmBui::ImeitemIMModule
#define ImeIWznmBuiMModule IexWznmBui::ImeIMModule
#define VecWImeIWznmBuiMModuleIel IexWznmBui::ImeIMModule::VecWIel

#define ImeitemIWznmBuiMPreset IexWznmBui::ImeitemIMPreset
#define ImeIWznmBuiMPreset IexWznmBui::ImeIMPreset
#define VecWImeIWznmBuiMPresetIel IexWznmBui::ImeIMPreset::VecWIel

/**
	* IexWznmBui
	*/
namespace IexWznmBui {
	/**
		* VecVIme (full: VecVIexWznmBuiIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIJMCARDTITLE = 1;
		static const Sbecore::uint IMEIJMMODULE = 2;
		static const Sbecore::uint IMEIMCARD = 3;
		static const Sbecore::uint IMEIMMODULE = 4;
		static const Sbecore::uint IMEIMPRESET = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIJMModule (full: ImeitemIWznmBuiJMModule)
		*/
	class ImeitemIJMModule : public WznmJMModule {

	public:
		ImeitemIJMModule(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJMModule(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMModule (full: ImeIWznmBuiJMModule)
		*/
	class ImeIJMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWznmBuiJMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMModule();
		~ImeIJMModule();

	public:
		std::vector<ImeitemIJMModule*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMCardTitle (full: ImeitemIWznmBuiJMCardTitle)
		*/
	class ImeitemIJMCardTitle : public WznmJMCardTitle {

	public:
		ImeitemIJMCardTitle(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMCardTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMCardTitle (full: ImeIWznmBuiJMCardTitle)
		*/
	class ImeIJMCardTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmBuiJMCardTitleIel)
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
		ImeIJMCardTitle();
		~ImeIJMCardTitle();

	public:
		std::vector<ImeitemIJMCardTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCard (full: ImeitemIWznmBuiMCard)
		*/
	class ImeitemIMCard : public WznmMCard {

	public:
		ImeitemIMCard(const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const std::string& sref = "", const std::string& Title = "", const std::string& Avail = "", const std::string& Active = "");
		ImeitemIMCard(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefIxVTbl;
		std::string srefRefUref;

		ImeIJMCardTitle imeijmcardtitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCard (full: ImeIWznmBuiMCard)
		*/
	class ImeIMCard {

	public:
		/**
			* VecWIel (full: VecWImeIWznmBuiMCardIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFIXVTBL = 1;
			static const Sbecore::uint SREFREFUREF = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint TITLE = 8;
			static const Sbecore::uint AVAIL = 16;
			static const Sbecore::uint ACTIVE = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCard();
		~ImeIMCard();

	public:
		std::vector<ImeitemIMCard*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMModule (full: ImeitemIWznmBuiMModule)
		*/
	class ImeitemIMModule : public WznmMModule {

	public:
		ImeitemIMModule(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMModule(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMModule imeijmmodule;
		ImeIMCard imeimcard;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWznmBuiMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWznmBuiMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMModule();
		~ImeIMModule();

	public:
		std::vector<ImeitemIMModule*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPreset (full: ImeitemIWznmBuiMPreset)
		*/
	class ImeitemIMPreset : public WznmMPreset {

	public:
		ImeitemIMPreset(const Sbecore::uint ixWznmVIop = 0, const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const Sbecore::uint ixVScope = 0, const std::string& sref = "", const Sbecore::uint ixWznmWArgtype = 0);
		ImeitemIMPreset(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefRefIxVTbl;
		std::string srefRefUref;
		std::string srefIxVScope;
		std::string srefIxWznmWArgtype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPreset (full: ImeIWznmBuiMPreset)
		*/
	class ImeIMPreset {

	public:
		/**
			* VecWIel (full: VecWImeIWznmBuiMPresetIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFREFIXVTBL = 2;
			static const Sbecore::uint SREFREFUREF = 4;
			static const Sbecore::uint SREFIXVSCOPE = 8;
			static const Sbecore::uint SREF = 16;
			static const Sbecore::uint SREFIXWZNMWARGTYPE = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPreset();
		~ImeIMPreset();

	public:
		std::vector<ImeitemIMPreset*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMModule& imeimmodule, ImeIMPreset& imeimpreset);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMModule& imeimmodule, ImeIMPreset& imeimpreset);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMModule& imeimmodule, ImeIMPreset& imeimpreset);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMModule& imeimmodule, ImeIMPreset& imeimpreset);

	void writeTxt(std::fstream& outfile, ImeIMModule& imeimmodule, ImeIMPreset& imeimpreset);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMModule& imeimmodule, ImeIMPreset& imeimpreset);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

