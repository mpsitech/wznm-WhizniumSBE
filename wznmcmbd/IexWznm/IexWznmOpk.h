/**
	* \file IexWznmOpk.h
	* data blocks and readers/writers for import/export complex IexWznmOpk (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWZNMOPK_H
#define IEXWZNMOPK_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmOpkIme IexWznmOpk::VecVIme

#define ImeitemIWznmOpkAMOppackInvarg IexWznmOpk::ImeitemIAMOppackInvarg
#define ImeIWznmOpkAMOppackInvarg IexWznmOpk::ImeIAMOppackInvarg
#define VecWImeIWznmOpkAMOppackInvargIel IexWznmOpk::ImeIAMOppackInvarg::VecWIel

#define ImeitemIWznmOpkAMOppackRetval IexWznmOpk::ImeitemIAMOppackRetval
#define ImeIWznmOpkAMOppackRetval IexWznmOpk::ImeIAMOppackRetval
#define VecWImeIWznmOpkAMOppackRetvalIel IexWznmOpk::ImeIAMOppackRetval::VecWIel

#define ImeitemIWznmOpkCAMOppackInvarg IexWznmOpk::ImeitemICAMOppackInvarg
#define ImeIWznmOpkCAMOppackInvarg IexWznmOpk::ImeICAMOppackInvarg
#define VecWImeIWznmOpkCAMOppackInvargIel IexWznmOpk::ImeICAMOppackInvarg::VecWIel

#define ImeitemIWznmOpkCAMOppackRetval IexWznmOpk::ImeitemICAMOppackRetval
#define ImeIWznmOpkCAMOppackRetval IexWznmOpk::ImeICAMOppackRetval
#define VecWImeIWznmOpkCAMOppackRetvalIel IexWznmOpk::ImeICAMOppackRetval::VecWIel

#define ImeitemIWznmOpkJAMBlockItem1 IexWznmOpk::ImeitemIJAMBlockItem1
#define ImeIWznmOpkJAMBlockItem1 IexWznmOpk::ImeIJAMBlockItem1
#define VecWImeIWznmOpkJAMBlockItem1Iel IexWznmOpk::ImeIJAMBlockItem1::VecWIel

#define ImeitemIWznmOpkAMBlockItem1 IexWznmOpk::ImeitemIAMBlockItem1
#define ImeIWznmOpkAMBlockItem1 IexWznmOpk::ImeIAMBlockItem1
#define VecWImeIWznmOpkAMBlockItem1Iel IexWznmOpk::ImeIAMBlockItem1::VecWIel

#define ImeitemIWznmOpkCAMBlockItem1 IexWznmOpk::ImeitemICAMBlockItem1
#define ImeIWznmOpkCAMBlockItem1 IexWznmOpk::ImeICAMBlockItem1
#define VecWImeIWznmOpkCAMBlockItem1Iel IexWznmOpk::ImeICAMBlockItem1::VecWIel

#define ImeitemIWznmOpkMBlock1 IexWznmOpk::ImeitemIMBlock1
#define ImeIWznmOpkMBlock1 IexWznmOpk::ImeIMBlock1
#define VecWImeIWznmOpkMBlock1Iel IexWznmOpk::ImeIMBlock1::VecWIel

#define ImeitemIWznmOpkAMOpInvarg IexWznmOpk::ImeitemIAMOpInvarg
#define ImeIWznmOpkAMOpInvarg IexWznmOpk::ImeIAMOpInvarg
#define VecWImeIWznmOpkAMOpInvargIel IexWznmOpk::ImeIAMOpInvarg::VecWIel

#define ImeitemIWznmOpkAMOpRetval IexWznmOpk::ImeitemIAMOpRetval
#define ImeIWznmOpkAMOpRetval IexWznmOpk::ImeIAMOpRetval
#define VecWImeIWznmOpkAMOpRetvalIel IexWznmOpk::ImeIAMOpRetval::VecWIel

#define ImeitemIWznmOpkCAMOpInvarg IexWznmOpk::ImeitemICAMOpInvarg
#define ImeIWznmOpkCAMOpInvarg IexWznmOpk::ImeICAMOpInvarg
#define VecWImeIWznmOpkCAMOpInvargIel IexWznmOpk::ImeICAMOpInvarg::VecWIel

#define ImeitemIWznmOpkCAMOpRetval IexWznmOpk::ImeitemICAMOpRetval
#define ImeIWznmOpkCAMOpRetval IexWznmOpk::ImeICAMOpRetval
#define VecWImeIWznmOpkCAMOpRetvalIel IexWznmOpk::ImeICAMOpRetval::VecWIel

#define ImeitemIWznmOpkJAMBlockItem2 IexWznmOpk::ImeitemIJAMBlockItem2
#define ImeIWznmOpkJAMBlockItem2 IexWznmOpk::ImeIJAMBlockItem2
#define VecWImeIWznmOpkJAMBlockItem2Iel IexWznmOpk::ImeIJAMBlockItem2::VecWIel

#define ImeitemIWznmOpkAMBlockItem2 IexWznmOpk::ImeitemIAMBlockItem2
#define ImeIWznmOpkAMBlockItem2 IexWznmOpk::ImeIAMBlockItem2
#define VecWImeIWznmOpkAMBlockItem2Iel IexWznmOpk::ImeIAMBlockItem2::VecWIel

#define ImeitemIWznmOpkCAMBlockItem2 IexWznmOpk::ImeitemICAMBlockItem2
#define ImeIWznmOpkCAMBlockItem2 IexWznmOpk::ImeICAMBlockItem2
#define VecWImeIWznmOpkCAMBlockItem2Iel IexWznmOpk::ImeICAMBlockItem2::VecWIel

#define ImeitemIWznmOpkMBlock2 IexWznmOpk::ImeitemIMBlock2
#define ImeIWznmOpkMBlock2 IexWznmOpk::ImeIMBlock2
#define VecWImeIWznmOpkMBlock2Iel IexWznmOpk::ImeIMBlock2::VecWIel

#define ImeitemIWznmOpkJMSquawkTitle2 IexWznmOpk::ImeitemIJMSquawkTitle2
#define ImeIWznmOpkJMSquawkTitle2 IexWznmOpk::ImeIJMSquawkTitle2
#define VecWImeIWznmOpkJMSquawkTitle2Iel IexWznmOpk::ImeIJMSquawkTitle2::VecWIel

#define ImeitemIWznmOpkRMSquawkMStub2 IexWznmOpk::ImeitemIRMSquawkMStub2
#define ImeIWznmOpkRMSquawkMStub2 IexWznmOpk::ImeIRMSquawkMStub2
#define VecWImeIWznmOpkRMSquawkMStub2Iel IexWznmOpk::ImeIRMSquawkMStub2::VecWIel

#define ImeitemIWznmOpkMSquawk2 IexWznmOpk::ImeitemIMSquawk2
#define ImeIWznmOpkMSquawk2 IexWznmOpk::ImeIMSquawk2
#define VecWImeIWznmOpkMSquawk2Iel IexWznmOpk::ImeIMSquawk2::VecWIel

#define ImeitemIWznmOpkMOp IexWznmOpk::ImeitemIMOp
#define ImeIWznmOpkMOp IexWznmOpk::ImeIMOp
#define VecWImeIWznmOpkMOpIel IexWznmOpk::ImeIMOp::VecWIel

#define ImeitemIWznmOpkJMSquawkTitle1 IexWznmOpk::ImeitemIJMSquawkTitle1
#define ImeIWznmOpkJMSquawkTitle1 IexWznmOpk::ImeIJMSquawkTitle1
#define VecWImeIWznmOpkJMSquawkTitle1Iel IexWznmOpk::ImeIJMSquawkTitle1::VecWIel

#define ImeitemIWznmOpkRMSquawkMStub1 IexWznmOpk::ImeitemIRMSquawkMStub1
#define ImeIWznmOpkRMSquawkMStub1 IexWznmOpk::ImeIRMSquawkMStub1
#define VecWImeIWznmOpkRMSquawkMStub1Iel IexWznmOpk::ImeIRMSquawkMStub1::VecWIel

#define ImeitemIWznmOpkMSquawk1 IexWznmOpk::ImeitemIMSquawk1
#define ImeIWznmOpkMSquawk1 IexWznmOpk::ImeIMSquawk1
#define VecWImeIWznmOpkMSquawk1Iel IexWznmOpk::ImeIMSquawk1::VecWIel

#define ImeitemIWznmOpkRMComponentMOppack IexWznmOpk::ImeitemIRMComponentMOppack
#define ImeIWznmOpkRMComponentMOppack IexWznmOpk::ImeIRMComponentMOppack
#define VecWImeIWznmOpkRMComponentMOppackIel IexWznmOpk::ImeIRMComponentMOppack::VecWIel

#define ImeitemIWznmOpkRMLibraryMOppack IexWznmOpk::ImeitemIRMLibraryMOppack
#define ImeIWznmOpkRMLibraryMOppack IexWznmOpk::ImeIRMLibraryMOppack
#define VecWImeIWznmOpkRMLibraryMOppackIel IexWznmOpk::ImeIRMLibraryMOppack::VecWIel

#define ImeitemIWznmOpkMOppack IexWznmOpk::ImeitemIMOppack
#define ImeIWznmOpkMOppack IexWznmOpk::ImeIMOppack
#define VecWImeIWznmOpkMOppackIel IexWznmOpk::ImeIMOppack::VecWIel

/**
	* IexWznmOpk
	*/
namespace IexWznmOpk {
	/**
		* VecVIme (full: VecVIexWznmOpkIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMBLOCKITEM1 = 1;
		static const Sbecore::uint IMEIAMBLOCKITEM2 = 2;
		static const Sbecore::uint IMEIAMOPINVARG = 3;
		static const Sbecore::uint IMEIAMOPPACKINVARG = 4;
		static const Sbecore::uint IMEIAMOPPACKRETVAL = 5;
		static const Sbecore::uint IMEIAMOPRETVAL = 6;
		static const Sbecore::uint IMEICAMBLOCKITEM1 = 7;
		static const Sbecore::uint IMEICAMBLOCKITEM2 = 8;
		static const Sbecore::uint IMEICAMOPINVARG = 9;
		static const Sbecore::uint IMEICAMOPPACKINVARG = 10;
		static const Sbecore::uint IMEICAMOPPACKRETVAL = 11;
		static const Sbecore::uint IMEICAMOPRETVAL = 12;
		static const Sbecore::uint IMEIJAMBLOCKITEM1 = 13;
		static const Sbecore::uint IMEIJAMBLOCKITEM2 = 14;
		static const Sbecore::uint IMEIJMSQUAWKTITLE1 = 15;
		static const Sbecore::uint IMEIJMSQUAWKTITLE2 = 16;
		static const Sbecore::uint IMEIMBLOCK1 = 17;
		static const Sbecore::uint IMEIMBLOCK2 = 18;
		static const Sbecore::uint IMEIMOP = 19;
		static const Sbecore::uint IMEIMOPPACK = 20;
		static const Sbecore::uint IMEIMSQUAWK1 = 21;
		static const Sbecore::uint IMEIMSQUAWK2 = 22;
		static const Sbecore::uint IMEIRMCOMPONENTMOPPACK = 23;
		static const Sbecore::uint IMEIRMLIBRARYMOPPACK = 24;
		static const Sbecore::uint IMEIRMSQUAWKMSTUB1 = 25;
		static const Sbecore::uint IMEIRMSQUAWKMSTUB2 = 26;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMOppackInvarg (full: ImeitemIWznmOpkAMOppackInvarg)
		*/
	class ImeitemIAMOppackInvarg : public WznmAMOppackInvarg {

	public:
		ImeitemIAMOppackInvarg(const Sbecore::ubigint irefRefWznmCAMOppackInvarg = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMOppackInvarg(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMOppackInvarg;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMOppackInvarg (full: ImeIWznmOpkAMOppackInvarg)
		*/
	class ImeIAMOppackInvarg {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkAMOppackInvargIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMOPPACKINVARG = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint DEFVAL = 16;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMOppackInvarg();
		~ImeIAMOppackInvarg();

	public:
		std::vector<ImeitemIAMOppackInvarg*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMOppackRetval (full: ImeitemIWznmOpkAMOppackRetval)
		*/
	class ImeitemIAMOppackRetval : public WznmAMOppackRetval {

	public:
		ImeitemIAMOppackRetval(const Sbecore::ubigint irefRefWznmCAMOppackRetval = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Comment = "");
		ImeitemIAMOppackRetval(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMOppackRetval;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMOppackRetval (full: ImeIWznmOpkAMOppackRetval)
		*/
	class ImeIAMOppackRetval {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkAMOppackRetvalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMOPPACKRETVAL = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMOppackRetval();
		~ImeIAMOppackRetval();

	public:
		std::vector<ImeitemIAMOppackRetval*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMOppackInvarg (full: ImeitemIWznmOpkCAMOppackInvarg)
		*/
	class ImeitemICAMOppackInvarg {

	public:
		ImeitemICAMOppackInvarg(const Sbecore::ubigint iref = 0);
		ImeitemICAMOppackInvarg(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMOppackInvarg (full: ImeIWznmOpkCAMOppackInvarg)
		*/
	class ImeICAMOppackInvarg {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkCAMOppackInvargIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMOppackInvarg();
		~ImeICAMOppackInvarg();

	public:
		std::vector<ImeitemICAMOppackInvarg*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMOppackRetval (full: ImeitemIWznmOpkCAMOppackRetval)
		*/
	class ImeitemICAMOppackRetval {

	public:
		ImeitemICAMOppackRetval(const Sbecore::ubigint iref = 0);
		ImeitemICAMOppackRetval(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMOppackRetval (full: ImeIWznmOpkCAMOppackRetval)
		*/
	class ImeICAMOppackRetval {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkCAMOppackRetvalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMOppackRetval();
		~ImeICAMOppackRetval();

	public:
		std::vector<ImeitemICAMOppackRetval*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAMBlockItem1 (full: ImeitemIWznmOpkJAMBlockItem1)
		*/
	class ImeitemIJAMBlockItem1 : public WznmJAMBlockItem {

	public:
		ImeitemIJAMBlockItem1(const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "");
		ImeitemIJAMBlockItem1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAMBlockItem1 (full: ImeIWznmOpkJAMBlockItem1)
		*/
	class ImeIJAMBlockItem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkJAMBlockItem1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint DEFVAL = 1;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAMBlockItem1();
		~ImeIJAMBlockItem1();

	public:
		std::vector<ImeitemIJAMBlockItem1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMBlockItem1 (full: ImeitemIWznmOpkAMBlockItem1)
		*/
	class ImeitemIAMBlockItem1 : public WznmAMBlockItem {

	public:
		ImeitemIAMBlockItem1(const Sbecore::ubigint irefRefWznmCAMBlockItem = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMBlockItem1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMBlockItem;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;

		ImeIJAMBlockItem1 imeijamblockitem1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMBlockItem1 (full: ImeIWznmOpkAMBlockItem1)
		*/
	class ImeIAMBlockItem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkAMBlockItem1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMBLOCKITEM = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint DEFVAL = 16;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMBlockItem1();
		~ImeIAMBlockItem1();

	public:
		std::vector<ImeitemIAMBlockItem1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMBlockItem1 (full: ImeitemIWznmOpkCAMBlockItem1)
		*/
	class ImeitemICAMBlockItem1 {

	public:
		ImeitemICAMBlockItem1(const Sbecore::ubigint iref = 0);
		ImeitemICAMBlockItem1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMBlockItem1 (full: ImeIWznmOpkCAMBlockItem1)
		*/
	class ImeICAMBlockItem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkCAMBlockItem1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMBlockItem1();
		~ImeICAMBlockItem1();

	public:
		std::vector<ImeitemICAMBlockItem1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMBlock1 (full: ImeitemIWznmOpkMBlock1)
		*/
	class ImeitemIMBlock1 : public WznmMBlock {

	public:
		ImeitemIMBlock1(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMBlock1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMBlockItem1 imeiamblockitem1;
		ImeICAMBlockItem1 imeicamblockitem1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBlock1 (full: ImeIWznmOpkMBlock1)
		*/
	class ImeIMBlock1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkMBlock1Iel)
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
		ImeIMBlock1();
		~ImeIMBlock1();

	public:
		std::vector<ImeitemIMBlock1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMOpInvarg (full: ImeitemIWznmOpkAMOpInvarg)
		*/
	class ImeitemIAMOpInvarg : public WznmAMOpInvarg {

	public:
		ImeitemIAMOpInvarg(const Sbecore::ubigint irefRefWznmCAMOpInvarg = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMOpInvarg(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMOpInvarg;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMOpInvarg (full: ImeIWznmOpkAMOpInvarg)
		*/
	class ImeIAMOpInvarg {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkAMOpInvargIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMOPINVARG = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint DEFVAL = 16;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMOpInvarg();
		~ImeIAMOpInvarg();

	public:
		std::vector<ImeitemIAMOpInvarg*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMOpRetval (full: ImeitemIWznmOpkAMOpRetval)
		*/
	class ImeitemIAMOpRetval : public WznmAMOpRetval {

	public:
		ImeitemIAMOpRetval(const Sbecore::ubigint irefRefWznmCAMOpRetval = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Comment = "");
		ImeitemIAMOpRetval(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMOpRetval;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMOpRetval (full: ImeIWznmOpkAMOpRetval)
		*/
	class ImeIAMOpRetval {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkAMOpRetvalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMOPRETVAL = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMOpRetval();
		~ImeIAMOpRetval();

	public:
		std::vector<ImeitemIAMOpRetval*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMOpInvarg (full: ImeitemIWznmOpkCAMOpInvarg)
		*/
	class ImeitemICAMOpInvarg {

	public:
		ImeitemICAMOpInvarg(const Sbecore::ubigint iref = 0);
		ImeitemICAMOpInvarg(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMOpInvarg (full: ImeIWznmOpkCAMOpInvarg)
		*/
	class ImeICAMOpInvarg {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkCAMOpInvargIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMOpInvarg();
		~ImeICAMOpInvarg();

	public:
		std::vector<ImeitemICAMOpInvarg*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMOpRetval (full: ImeitemIWznmOpkCAMOpRetval)
		*/
	class ImeitemICAMOpRetval {

	public:
		ImeitemICAMOpRetval(const Sbecore::ubigint iref = 0);
		ImeitemICAMOpRetval(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMOpRetval (full: ImeIWznmOpkCAMOpRetval)
		*/
	class ImeICAMOpRetval {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkCAMOpRetvalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMOpRetval();
		~ImeICAMOpRetval();

	public:
		std::vector<ImeitemICAMOpRetval*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAMBlockItem2 (full: ImeitemIWznmOpkJAMBlockItem2)
		*/
	class ImeitemIJAMBlockItem2 : public WznmJAMBlockItem {

	public:
		ImeitemIJAMBlockItem2(const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "");
		ImeitemIJAMBlockItem2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAMBlockItem2 (full: ImeIWznmOpkJAMBlockItem2)
		*/
	class ImeIJAMBlockItem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkJAMBlockItem2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint DEFVAL = 1;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAMBlockItem2();
		~ImeIJAMBlockItem2();

	public:
		std::vector<ImeitemIJAMBlockItem2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMBlockItem2 (full: ImeitemIWznmOpkAMBlockItem2)
		*/
	class ImeitemIAMBlockItem2 : public WznmAMBlockItem {

	public:
		ImeitemIAMBlockItem2(const Sbecore::ubigint irefRefWznmCAMBlockItem = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMBlockItem2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMBlockItem;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;

		ImeIJAMBlockItem2 imeijamblockitem2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMBlockItem2 (full: ImeIWznmOpkAMBlockItem2)
		*/
	class ImeIAMBlockItem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkAMBlockItem2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMBLOCKITEM = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint DEFVAL = 16;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMBlockItem2();
		~ImeIAMBlockItem2();

	public:
		std::vector<ImeitemIAMBlockItem2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMBlockItem2 (full: ImeitemIWznmOpkCAMBlockItem2)
		*/
	class ImeitemICAMBlockItem2 {

	public:
		ImeitemICAMBlockItem2(const Sbecore::ubigint iref = 0);
		ImeitemICAMBlockItem2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMBlockItem2 (full: ImeIWznmOpkCAMBlockItem2)
		*/
	class ImeICAMBlockItem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkCAMBlockItem2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMBlockItem2();
		~ImeICAMBlockItem2();

	public:
		std::vector<ImeitemICAMBlockItem2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMBlock2 (full: ImeitemIWznmOpkMBlock2)
		*/
	class ImeitemIMBlock2 : public WznmMBlock {

	public:
		ImeitemIMBlock2(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMBlock2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMBlockItem2 imeiamblockitem2;
		ImeICAMBlockItem2 imeicamblockitem2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBlock2 (full: ImeIWznmOpkMBlock2)
		*/
	class ImeIMBlock2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkMBlock2Iel)
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
		ImeIMBlock2();
		~ImeIMBlock2();

	public:
		std::vector<ImeitemIMBlock2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMSquawkTitle2 (full: ImeitemIWznmOpkJMSquawkTitle2)
		*/
	class ImeitemIJMSquawkTitle2 : public WznmJMSquawkTitle {

	public:
		ImeitemIJMSquawkTitle2(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMSquawkTitle2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMSquawkTitle2 (full: ImeIWznmOpkJMSquawkTitle2)
		*/
	class ImeIJMSquawkTitle2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkJMSquawkTitle2Iel)
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
		ImeIJMSquawkTitle2();
		~ImeIJMSquawkTitle2();

	public:
		std::vector<ImeitemIJMSquawkTitle2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMSquawkMStub2 (full: ImeitemIWznmOpkRMSquawkMStub2)
		*/
	class ImeitemIRMSquawkMStub2 : public WznmRMSquawkMStub {

	public:
		ImeitemIRMSquawkMStub2(const std::string& srefRefWznmMStub = "");
		ImeitemIRMSquawkMStub2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMSquawkMStub2 (full: ImeIWznmOpkRMSquawkMStub2)
		*/
	class ImeIRMSquawkMStub2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkRMSquawkMStub2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMSTUB = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMSquawkMStub2();
		~ImeIRMSquawkMStub2();

	public:
		std::vector<ImeitemIRMSquawkMStub2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSquawk2 (full: ImeitemIWznmOpkMSquawk2)
		*/
	class ImeitemIMSquawk2 : public WznmMSquawk {

	public:
		ImeitemIMSquawk2(const std::string& Title = "", const std::string& Example = "");
		ImeitemIMSquawk2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMSquawkTitle2 imeijmsquawktitle2;
		ImeIRMSquawkMStub2 imeirmsquawkmstub2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSquawk2 (full: ImeIWznmOpkMSquawk2)
		*/
	class ImeIMSquawk2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkMSquawk2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint TITLE = 1;
			static const Sbecore::uint EXAMPLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSquawk2();
		~ImeIMSquawk2();

	public:
		std::vector<ImeitemIMSquawk2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMOp (full: ImeitemIWznmOpkMOp)
		*/
	class ImeitemIMOp : public WznmMOp {

	public:
		ImeitemIMOp(const std::string& sref = "", const bool Shrdat = false, const std::string& Comment = "");
		ImeitemIMOp(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMOpInvarg imeiamopinvarg;
		ImeIAMOpRetval imeiamopretval;
		ImeICAMOpInvarg imeicamopinvarg;
		ImeICAMOpRetval imeicamopretval;
		ImeIMBlock2 imeimblock2;
		ImeIMSquawk2 imeimsquawk2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMOp (full: ImeIWznmOpkMOp)
		*/
	class ImeIMOp {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkMOpIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SHRDAT = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMOp();
		~ImeIMOp();

	public:
		std::vector<ImeitemIMOp*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMSquawkTitle1 (full: ImeitemIWznmOpkJMSquawkTitle1)
		*/
	class ImeitemIJMSquawkTitle1 : public WznmJMSquawkTitle {

	public:
		ImeitemIJMSquawkTitle1(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMSquawkTitle1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMSquawkTitle1 (full: ImeIWznmOpkJMSquawkTitle1)
		*/
	class ImeIJMSquawkTitle1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkJMSquawkTitle1Iel)
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
		ImeIJMSquawkTitle1();
		~ImeIJMSquawkTitle1();

	public:
		std::vector<ImeitemIJMSquawkTitle1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMSquawkMStub1 (full: ImeitemIWznmOpkRMSquawkMStub1)
		*/
	class ImeitemIRMSquawkMStub1 : public WznmRMSquawkMStub {

	public:
		ImeitemIRMSquawkMStub1(const std::string& srefRefWznmMStub = "");
		ImeitemIRMSquawkMStub1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMSquawkMStub1 (full: ImeIWznmOpkRMSquawkMStub1)
		*/
	class ImeIRMSquawkMStub1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkRMSquawkMStub1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMSTUB = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMSquawkMStub1();
		~ImeIRMSquawkMStub1();

	public:
		std::vector<ImeitemIRMSquawkMStub1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSquawk1 (full: ImeitemIWznmOpkMSquawk1)
		*/
	class ImeitemIMSquawk1 : public WznmMSquawk {

	public:
		ImeitemIMSquawk1(const std::string& Title = "", const std::string& Example = "");
		ImeitemIMSquawk1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMSquawkTitle1 imeijmsquawktitle1;
		ImeIRMSquawkMStub1 imeirmsquawkmstub1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSquawk1 (full: ImeIWznmOpkMSquawk1)
		*/
	class ImeIMSquawk1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkMSquawk1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint TITLE = 1;
			static const Sbecore::uint EXAMPLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSquawk1();
		~ImeIMSquawk1();

	public:
		std::vector<ImeitemIMSquawk1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMComponentMOppack (full: ImeitemIWznmOpkRMComponentMOppack)
		*/
	class ImeitemIRMComponentMOppack : public WznmRMComponentMOppack {

	public:
		ImeitemIRMComponentMOppack(const std::string& srefRefWznmMComponent = "");
		ImeitemIRMComponentMOppack(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMComponent;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMComponentMOppack (full: ImeIWznmOpkRMComponentMOppack)
		*/
	class ImeIRMComponentMOppack {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkRMComponentMOppackIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMCOMPONENT = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMComponentMOppack();
		~ImeIRMComponentMOppack();

	public:
		std::vector<ImeitemIRMComponentMOppack*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMLibraryMOppack (full: ImeitemIWznmOpkRMLibraryMOppack)
		*/
	class ImeitemIRMLibraryMOppack : public WznmRMLibraryMOppack {

	public:
		ImeitemIRMLibraryMOppack(const std::string& srefRefWznmMLibrary = "");
		ImeitemIRMLibraryMOppack(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIRMLibraryMOppack (full: ImeIWznmOpkRMLibraryMOppack)
		*/
	class ImeIRMLibraryMOppack {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkRMLibraryMOppackIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMLIBRARY = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMLibraryMOppack();
		~ImeIRMLibraryMOppack();

	public:
		std::vector<ImeitemIRMLibraryMOppack*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMOppack (full: ImeitemIWznmOpkMOppack)
		*/
	class ImeitemIMOppack : public WznmMOppack {

	public:
		ImeitemIMOppack(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& Title = "", const bool Shrdat = false, const std::string& Comment = "");
		ImeitemIMOppack(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIAMOppackInvarg imeiamoppackinvarg;
		ImeIAMOppackRetval imeiamoppackretval;
		ImeICAMOppackInvarg imeicamoppackinvarg;
		ImeICAMOppackRetval imeicamoppackretval;
		ImeIMBlock1 imeimblock1;
		ImeIMOp imeimop;
		ImeIMSquawk1 imeimsquawk1;
		ImeIRMComponentMOppack imeirmcomponentmoppack;
		ImeIRMLibraryMOppack imeirmlibrarymoppack;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMOppack (full: ImeIWznmOpkMOppack)
		*/
	class ImeIMOppack {

	public:
		/**
			* VecWIel (full: VecWImeIWznmOpkMOppackIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint SHRDAT = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMOppack();
		~ImeIMOppack();

	public:
		std::vector<ImeitemIMOppack*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMOppack& imeimoppack);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMOppack& imeimoppack);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMOppack& imeimoppack);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMOppack& imeimoppack);

	void writeTxt(std::fstream& outfile, ImeIMOppack& imeimoppack);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMOppack& imeimoppack);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif
