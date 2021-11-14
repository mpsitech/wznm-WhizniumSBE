/**
	* \file IexWznmGbl.h
	* data blocks and readers/writers for import/export complex IexWznmGbl (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWZNMGBL_H
#define IEXWZNMGBL_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmGblIme IexWznmGbl::VecVIme

#define ImeitemIWznmGblJAMBlockItem IexWznmGbl::ImeitemIJAMBlockItem
#define ImeIWznmGblJAMBlockItem IexWznmGbl::ImeIJAMBlockItem
#define VecWImeIWznmGblJAMBlockItemIel IexWznmGbl::ImeIJAMBlockItem::VecWIel

#define ImeitemIWznmGblAMBlockItem IexWznmGbl::ImeitemIAMBlockItem
#define ImeIWznmGblAMBlockItem IexWznmGbl::ImeIAMBlockItem
#define VecWImeIWznmGblAMBlockItemIel IexWznmGbl::ImeIAMBlockItem::VecWIel

#define ImeitemIWznmGblCAMBlockItem IexWznmGbl::ImeitemICAMBlockItem
#define ImeIWznmGblCAMBlockItem IexWznmGbl::ImeICAMBlockItem
#define VecWImeIWznmGblCAMBlockItemIel IexWznmGbl::ImeICAMBlockItem::VecWIel

#define ImeitemIWznmGblMBlock IexWznmGbl::ImeitemIMBlock
#define ImeIWznmGblMBlock IexWznmGbl::ImeIMBlock
#define VecWImeIWznmGblMBlockIel IexWznmGbl::ImeIMBlock::VecWIel

#define ImeitemIWznmGblAMCapabilityPar IexWznmGbl::ImeitemIAMCapabilityPar
#define ImeIWznmGblAMCapabilityPar IexWznmGbl::ImeIAMCapabilityPar
#define VecWImeIWznmGblAMCapabilityParIel IexWznmGbl::ImeIAMCapabilityPar::VecWIel

#define ImeitemIWznmGblMCapability IexWznmGbl::ImeitemIMCapability
#define ImeIWznmGblMCapability IexWznmGbl::ImeIMCapability
#define VecWImeIWznmGblMCapabilityIel IexWznmGbl::ImeIMCapability::VecWIel

#define ImeitemIWznmGblJMErrorTitle IexWznmGbl::ImeitemIJMErrorTitle
#define ImeIWznmGblJMErrorTitle IexWznmGbl::ImeIJMErrorTitle
#define VecWImeIWznmGblJMErrorTitleIel IexWznmGbl::ImeIJMErrorTitle::VecWIel

#define ImeitemIWznmGblMError IexWznmGbl::ImeitemIMError
#define ImeIWznmGblMError IexWznmGbl::ImeIMError
#define VecWImeIWznmGblMErrorIel IexWznmGbl::ImeIMError::VecWIel

#define ImeitemIWznmGblAMVectorTitle IexWznmGbl::ImeitemIAMVectorTitle
#define ImeIWznmGblAMVectorTitle IexWznmGbl::ImeIAMVectorTitle
#define VecWImeIWznmGblAMVectorTitleIel IexWznmGbl::ImeIAMVectorTitle::VecWIel

#define ImeitemIWznmGblJMVectoritem IexWznmGbl::ImeitemIJMVectoritem
#define ImeIWznmGblJMVectoritem IexWznmGbl::ImeIJMVectoritem
#define VecWImeIWznmGblJMVectoritemIel IexWznmGbl::ImeIJMVectoritem::VecWIel

#define ImeitemIWznmGblMVectoritem IexWznmGbl::ImeitemIMVectoritem
#define ImeIWznmGblMVectoritem IexWznmGbl::ImeIMVectoritem
#define VecWImeIWznmGblMVectoritemIel IexWznmGbl::ImeIMVectoritem::VecWIel

#define ImeitemIWznmGblMVector IexWznmGbl::ImeitemIMVector
#define ImeIWznmGblMVector IexWznmGbl::ImeIMVector
#define VecWImeIWznmGblMVectorIel IexWznmGbl::ImeIMVector::VecWIel

/**
	* IexWznmGbl
	*/
namespace IexWznmGbl {
	/**
		* VecVIme (full: VecVIexWznmGblIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMBLOCKITEM = 1;
		static const Sbecore::uint IMEIAMCAPABILITYPAR = 2;
		static const Sbecore::uint IMEIAMVECTORTITLE = 3;
		static const Sbecore::uint IMEICAMBLOCKITEM = 4;
		static const Sbecore::uint IMEIJAMBLOCKITEM = 5;
		static const Sbecore::uint IMEIJMERRORTITLE = 6;
		static const Sbecore::uint IMEIJMVECTORITEM = 7;
		static const Sbecore::uint IMEIMBLOCK = 8;
		static const Sbecore::uint IMEIMCAPABILITY = 9;
		static const Sbecore::uint IMEIMERROR = 10;
		static const Sbecore::uint IMEIMVECTOR = 11;
		static const Sbecore::uint IMEIMVECTORITEM = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIJAMBlockItem (full: ImeitemIWznmGblJAMBlockItem)
		*/
	class ImeitemIJAMBlockItem : public WznmJAMBlockItem {

	public:
		ImeitemIJAMBlockItem(const std::string& srefX1RefWznmMRelease = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "");
		ImeitemIJAMBlockItem(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWznmMRelease;
		std::string srefRefWznmMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAMBlockItem (full: ImeIWznmGblJAMBlockItem)
		*/
	class ImeIJAMBlockItem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblJAMBlockItemIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMRELEASE = 1;
			static const Sbecore::uint DEFVAL = 2;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAMBlockItem();
		~ImeIJAMBlockItem();

	public:
		std::vector<ImeitemIJAMBlockItem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMBlockItem (full: ImeitemIWznmGblAMBlockItem)
		*/
	class ImeitemIAMBlockItem : public WznmAMBlockItem {

	public:
		ImeitemIAMBlockItem(const Sbecore::ubigint irefRefWznmCAMBlockItem = 0, const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMBlockItem(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMBlockItem;
		std::string srefIxVBasetype;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;

		ImeIJAMBlockItem imeijamblockitem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMBlockItem (full: ImeIWznmGblAMBlockItem)
		*/
	class ImeIAMBlockItem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblAMBlockItemIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMBLOCKITEM = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 8;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 16;
			static const Sbecore::uint DEFVAL = 32;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 64;
			static const Sbecore::uint COMMENT = 128;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMBlockItem();
		~ImeIAMBlockItem();

	public:
		std::vector<ImeitemIAMBlockItem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMBlockItem (full: ImeitemIWznmGblCAMBlockItem)
		*/
	class ImeitemICAMBlockItem {

	public:
		ImeitemICAMBlockItem(const Sbecore::ubigint iref = 0);
		ImeitemICAMBlockItem(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		Sbecore::ubigint ref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeICAMBlockItem (full: ImeIWznmGblCAMBlockItem)
		*/
	class ImeICAMBlockItem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblCAMBlockItemIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMBlockItem();
		~ImeICAMBlockItem();

	public:
		std::vector<ImeitemICAMBlockItem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMBlock (full: ImeitemIWznmGblMBlock)
		*/
	class ImeitemIMBlock : public WznmMBlock {

	public:
		ImeitemIMBlock(const Sbecore::uint reaIxWznmWScope = 0, const Sbecore::uint wriIxWznmWScope = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMBlock(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefsReaIxWznmWScope;
		std::string srefsWriIxWznmWScope;

		ImeIAMBlockItem imeiamblockitem;
		ImeICAMBlockItem imeicamblockitem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBlock (full: ImeIWznmGblMBlock)
		*/
	class ImeIMBlock {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblMBlockIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSREAIXWZNMWSCOPE = 1;
			static const Sbecore::uint SREFSWRIIXWZNMWSCOPE = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMBlock();
		~ImeIMBlock();

	public:
		std::vector<ImeitemIMBlock*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCapabilityPar (full: ImeitemIWznmGblAMCapabilityPar)
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
		* ImeIAMCapabilityPar (full: ImeIWznmGblAMCapabilityPar)
		*/
	class ImeIAMCapabilityPar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblAMCapabilityParIel)
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
		* ImeitemIMCapability (full: ImeitemIWznmGblMCapability)
		*/
	class ImeitemIMCapability : public WznmMCapability {

	public:
		ImeitemIMCapability(const std::string& srefTplRefWznmMCapability = "", const std::string& sref = "", const std::string& Title = "");
		ImeitemIMCapability(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefTplRefWznmMCapability;

		ImeIAMCapabilityPar imeiamcapabilitypar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCapability (full: ImeIWznmGblMCapability)
		*/
	class ImeIMCapability {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblMCapabilityIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFTPLREFWZNMMCAPABILITY = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;

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
		* ImeitemIJMErrorTitle (full: ImeitemIWznmGblJMErrorTitle)
		*/
	class ImeitemIJMErrorTitle : public WznmJMErrorTitle {

	public:
		ImeitemIJMErrorTitle(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMErrorTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMErrorTitle (full: ImeIWznmGblJMErrorTitle)
		*/
	class ImeIJMErrorTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblJMErrorTitleIel)
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
		ImeIJMErrorTitle();
		~ImeIJMErrorTitle();

	public:
		std::vector<ImeitemIJMErrorTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMError (full: ImeitemIWznmGblMError)
		*/
	class ImeitemIMError : public WznmMError {

	public:
		ImeitemIMError(const std::string& sref = "", const std::string& Title = "");
		ImeitemIMError(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMErrorTitle imeijmerrortitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMError (full: ImeIWznmGblMError)
		*/
	class ImeIMError {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblMErrorIel)
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
		ImeIMError();
		~ImeIMError();

	public:
		std::vector<ImeitemIMError*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMVectorTitle (full: ImeitemIWznmGblAMVectorTitle)
		*/
	class ImeitemIAMVectorTitle : public WznmAMVectorTitle {

	public:
		ImeitemIAMVectorTitle(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIAMVectorTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxVType;
		std::string srefX2RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMVectorTitle (full: ImeIWznmGblAMVectorTitle)
		*/
	class ImeIAMVectorTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblAMVectorTitleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXVTYPE = 1;
			static const Sbecore::uint SREFX2REFWZNMMLOCALE = 2;
			static const Sbecore::uint TITLE = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMVectorTitle();
		~ImeIAMVectorTitle();

	public:
		std::vector<ImeitemIAMVectorTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMVectoritem (full: ImeitemIWznmGblJMVectoritem)
		*/
	class ImeitemIJMVectoritem : public WznmJMVectoritem {

	public:
		ImeitemIJMVectoritem(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJMVectoritem(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMVectoritem (full: ImeIWznmGblJMVectoritem)
		*/
	class ImeIJMVectoritem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblJMVectoritemIel)
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
		ImeIJMVectoritem();
		~ImeIJMVectoritem();

	public:
		std::vector<ImeitemIJMVectoritem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVectoritem (full: ImeitemIWznmGblMVectoritem)
		*/
	class ImeitemIMVectoritem : public WznmMVectoritem {

	public:
		ImeitemIMVectoritem(const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMVectoritem(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMVectoritem imeijmvectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVectoritem (full: ImeIWznmGblMVectoritem)
		*/
	class ImeIMVectoritem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblMVectoritemIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint AVAIL = 2;
			static const Sbecore::uint IMPLIED = 4;
			static const Sbecore::uint TITLE = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVectoritem();
		~ImeIMVectoritem();

	public:
		std::vector<ImeitemIMVectoritem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector (full: ImeitemIWznmGblMVector)
		*/
	class ImeitemIMVector : public WznmMVector {

	public:
		ImeitemIMVector(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& srefsKOption = "");
		ImeitemIMVector(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIAMVectorTitle imeiamvectortitle;
		ImeIMVectoritem imeimvectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector (full: ImeIWznmGblMVector)
		*/
	class ImeIMVector {

	public:
		/**
			* VecWIel (full: VecWImeIWznmGblMVectorIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint OSREFWZNMKTAGGRP = 4;
			static const Sbecore::uint SREFSKOPTION = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVector();
		~ImeIMVector();

	public:
		std::vector<ImeitemIMVector*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMBlock& imeimblock, ImeIMCapability& imeimcapability, ImeIMError& imeimerror, ImeIMVector& imeimvector);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMBlock& imeimblock, ImeIMCapability& imeimcapability, ImeIMError& imeimerror, ImeIMVector& imeimvector);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMBlock& imeimblock, ImeIMCapability& imeimcapability, ImeIMError& imeimerror, ImeIMVector& imeimvector);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMBlock& imeimblock, ImeIMCapability& imeimcapability, ImeIMError& imeimerror, ImeIMVector& imeimvector);

	void writeTxt(std::fstream& outfile, ImeIMBlock& imeimblock, ImeIMCapability& imeimcapability, ImeIMError& imeimerror, ImeIMVector& imeimvector);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMBlock& imeimblock, ImeIMCapability& imeimcapability, ImeIMError& imeimerror, ImeIMVector& imeimvector);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif
