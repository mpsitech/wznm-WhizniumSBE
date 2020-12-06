/**
	* \file IexWznmDbs.h
	* data blocks and readers/writers for import/export complex IexWznmDbs (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWZNMDBS_H
#define IEXWZNMDBS_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmDbsIme IexWznmDbs::VecVIme

#define ImeitemIWznmDbsCRelation IexWznmDbs::ImeitemICRelation
#define ImeIWznmDbsCRelation IexWznmDbs::ImeICRelation
#define VecWImeIWznmDbsCRelationIel IexWznmDbs::ImeICRelation::VecWIel

#define ImeitemIWznmDbsAMRelationTitle IexWznmDbs::ImeitemIAMRelationTitle
#define ImeIWznmDbsAMRelationTitle IexWznmDbs::ImeIAMRelationTitle
#define VecWImeIWznmDbsAMRelationTitleIel IexWznmDbs::ImeIAMRelationTitle::VecWIel

#define ImeitemIWznmDbsMRelation IexWznmDbs::ImeitemIMRelation
#define ImeIWznmDbsMRelation IexWznmDbs::ImeIMRelation
#define VecWImeIWznmDbsMRelationIel IexWznmDbs::ImeIMRelation::VecWIel

#define ImeitemIWznmDbsMStub IexWznmDbs::ImeitemIMStub
#define ImeIWznmDbsMStub IexWznmDbs::ImeIMStub
#define VecWImeIWznmDbsMStubIel IexWznmDbs::ImeIMStub::VecWIel

#define ImeitemIWznmDbsAMTableLoadfct IexWznmDbs::ImeitemIAMTableLoadfct
#define ImeIWznmDbsAMTableLoadfct IexWznmDbs::ImeIAMTableLoadfct
#define VecWImeIWznmDbsAMTableLoadfctIel IexWznmDbs::ImeIAMTableLoadfct::VecWIel

#define ImeitemIWznmDbsAMTableTitle IexWznmDbs::ImeitemIAMTableTitle
#define ImeIWznmDbsAMTableTitle IexWznmDbs::ImeIAMTableTitle
#define VecWImeIWznmDbsAMTableTitleIel IexWznmDbs::ImeIAMTableTitle::VecWIel

#define ImeitemIWznmDbsMCheck IexWznmDbs::ImeitemIMCheck
#define ImeIWznmDbsMCheck IexWznmDbs::ImeIMCheck
#define VecWImeIWznmDbsMCheckIel IexWznmDbs::ImeIMCheck::VecWIel

#define ImeitemIWznmDbsAMSubsetTitle IexWznmDbs::ImeitemIAMSubsetTitle
#define ImeIWznmDbsAMSubsetTitle IexWznmDbs::ImeIAMSubsetTitle
#define VecWImeIWznmDbsAMSubsetTitleIel IexWznmDbs::ImeIAMSubsetTitle::VecWIel

#define ImeitemIWznmDbsRMSubsetMSubset IexWznmDbs::ImeitemIRMSubsetMSubset
#define ImeIWznmDbsRMSubsetMSubset IexWznmDbs::ImeIRMSubsetMSubset
#define VecWImeIWznmDbsRMSubsetMSubsetIel IexWznmDbs::ImeIRMSubsetMSubset::VecWIel

#define ImeitemIWznmDbsMSubset IexWznmDbs::ImeitemIMSubset
#define ImeIWznmDbsMSubset IexWznmDbs::ImeIMSubset
#define VecWImeIWznmDbsMSubsetIel IexWznmDbs::ImeIMSubset::VecWIel

#define ImeitemIWznmDbsAMTablecolTitle IexWznmDbs::ImeitemIAMTablecolTitle
#define ImeIWznmDbsAMTablecolTitle IexWznmDbs::ImeIAMTablecolTitle
#define VecWImeIWznmDbsAMTablecolTitleIel IexWznmDbs::ImeIAMTablecolTitle::VecWIel

#define ImeitemIWznmDbsMTablecol IexWznmDbs::ImeitemIMTablecol
#define ImeIWznmDbsMTablecol IexWznmDbs::ImeIMTablecol
#define VecWImeIWznmDbsMTablecolIel IexWznmDbs::ImeIMTablecol::VecWIel

#define ImeitemIWznmDbsAMVectorTitle2 IexWznmDbs::ImeitemIAMVectorTitle2
#define ImeIWznmDbsAMVectorTitle2 IexWznmDbs::ImeIAMVectorTitle2
#define VecWImeIWznmDbsAMVectorTitle2Iel IexWznmDbs::ImeIAMVectorTitle2::VecWIel

#define ImeitemIWznmDbsJMVectoritem2 IexWznmDbs::ImeitemIJMVectoritem2
#define ImeIWznmDbsJMVectoritem2 IexWznmDbs::ImeIJMVectoritem2
#define VecWImeIWznmDbsJMVectoritem2Iel IexWznmDbs::ImeIJMVectoritem2::VecWIel

#define ImeitemIWznmDbsMVectoritem2 IexWznmDbs::ImeitemIMVectoritem2
#define ImeIWznmDbsMVectoritem2 IexWznmDbs::ImeIMVectoritem2
#define VecWImeIWznmDbsMVectoritem2Iel IexWznmDbs::ImeIMVectoritem2::VecWIel

#define ImeitemIWznmDbsRMTableMVector2 IexWznmDbs::ImeitemIRMTableMVector2
#define ImeIWznmDbsRMTableMVector2 IexWznmDbs::ImeIRMTableMVector2
#define VecWImeIWznmDbsRMTableMVector2Iel IexWznmDbs::ImeIRMTableMVector2::VecWIel

#define ImeitemIWznmDbsMVector2 IexWznmDbs::ImeitemIMVector2
#define ImeIWznmDbsMVector2 IexWznmDbs::ImeIMVector2
#define VecWImeIWznmDbsMVector2Iel IexWznmDbs::ImeIMVector2::VecWIel

#define ImeitemIWznmDbsMTable IexWznmDbs::ImeitemIMTable
#define ImeIWznmDbsMTable IexWznmDbs::ImeIMTable
#define VecWImeIWznmDbsMTableIel IexWznmDbs::ImeIMTable::VecWIel

#define ImeitemIWznmDbsAMVectorTitle1 IexWznmDbs::ImeitemIAMVectorTitle1
#define ImeIWznmDbsAMVectorTitle1 IexWznmDbs::ImeIAMVectorTitle1
#define VecWImeIWznmDbsAMVectorTitle1Iel IexWznmDbs::ImeIAMVectorTitle1::VecWIel

#define ImeitemIWznmDbsJMVectoritem1 IexWznmDbs::ImeitemIJMVectoritem1
#define ImeIWznmDbsJMVectoritem1 IexWznmDbs::ImeIJMVectoritem1
#define VecWImeIWznmDbsJMVectoritem1Iel IexWznmDbs::ImeIJMVectoritem1::VecWIel

#define ImeitemIWznmDbsMVectoritem1 IexWznmDbs::ImeitemIMVectoritem1
#define ImeIWznmDbsMVectoritem1 IexWznmDbs::ImeIMVectoritem1
#define VecWImeIWznmDbsMVectoritem1Iel IexWznmDbs::ImeIMVectoritem1::VecWIel

#define ImeitemIWznmDbsRMTableMVector1 IexWznmDbs::ImeitemIRMTableMVector1
#define ImeIWznmDbsRMTableMVector1 IexWznmDbs::ImeIRMTableMVector1
#define VecWImeIWznmDbsRMTableMVector1Iel IexWznmDbs::ImeIRMTableMVector1::VecWIel

#define ImeitemIWznmDbsMVector1 IexWznmDbs::ImeitemIMVector1
#define ImeIWznmDbsMVector1 IexWznmDbs::ImeIMVector1
#define VecWImeIWznmDbsMVector1Iel IexWznmDbs::ImeIMVector1::VecWIel

#define ImeitemIWznmDbsRMStubMStub IexWznmDbs::ImeitemIRMStubMStub
#define ImeIWznmDbsRMStubMStub IexWznmDbs::ImeIRMStubMStub
#define VecWImeIWznmDbsRMStubMStubIel IexWznmDbs::ImeIRMStubMStub::VecWIel

/**
	* IexWznmDbs
	*/
namespace IexWznmDbs {
	/**
		* VecVIme (full: VecVIexWznmDbsIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMRELATIONTITLE = 1;
		static const Sbecore::uint IMEIAMSUBSETTITLE = 2;
		static const Sbecore::uint IMEIAMTABLECOLTITLE = 3;
		static const Sbecore::uint IMEIAMTABLELOADFCT = 4;
		static const Sbecore::uint IMEIAMTABLETITLE = 5;
		static const Sbecore::uint IMEIAMVECTORTITLE1 = 6;
		static const Sbecore::uint IMEIAMVECTORTITLE2 = 7;
		static const Sbecore::uint IMEICRELATION = 8;
		static const Sbecore::uint IMEIJMVECTORITEM1 = 9;
		static const Sbecore::uint IMEIJMVECTORITEM2 = 10;
		static const Sbecore::uint IMEIMCHECK = 11;
		static const Sbecore::uint IMEIMRELATION = 12;
		static const Sbecore::uint IMEIMSTUB = 13;
		static const Sbecore::uint IMEIMSUBSET = 14;
		static const Sbecore::uint IMEIMTABLE = 15;
		static const Sbecore::uint IMEIMTABLECOL = 16;
		static const Sbecore::uint IMEIMVECTOR1 = 17;
		static const Sbecore::uint IMEIMVECTOR2 = 18;
		static const Sbecore::uint IMEIMVECTORITEM1 = 19;
		static const Sbecore::uint IMEIMVECTORITEM2 = 20;
		static const Sbecore::uint IMEIRMSTUBMSTUB = 21;
		static const Sbecore::uint IMEIRMSUBSETMSUBSET = 22;
		static const Sbecore::uint IMEIRMTABLEMVECTOR1 = 23;
		static const Sbecore::uint IMEIRMTABLEMVECTOR2 = 24;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemICRelation (full: ImeitemIWznmDbsCRelation)
		*/
	class ImeitemICRelation {

	public:
		ImeitemICRelation(const Sbecore::ubigint iref = 0);
		ImeitemICRelation(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICRelation (full: ImeIWznmDbsCRelation)
		*/
	class ImeICRelation {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsCRelationIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICRelation();
		~ImeICRelation();

	public:
		std::vector<ImeitemICRelation*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMRelationTitle (full: ImeitemIWznmDbsAMRelationTitle)
		*/
	class ImeitemIAMRelationTitle : public WznmAMRelationTitle {

	public:
		ImeitemIAMRelationTitle(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIAMRelationTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIAMRelationTitle (full: ImeIWznmDbsAMRelationTitle)
		*/
	class ImeIAMRelationTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMRelationTitleIel)
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
		ImeIAMRelationTitle();
		~ImeIAMRelationTitle();

	public:
		std::vector<ImeitemIAMRelationTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRelation (full: ImeitemIWznmDbsMRelation)
		*/
	class ImeitemIMRelation : public WznmMRelation {

	public:
		ImeitemIMRelation(const Sbecore::ubigint iref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefRefWznmCRelation = 0, const Sbecore::ubigint irefSupRefWznmMRelation = 0, const Sbecore::uint supIxVSubrole = 0, const std::string& srefFrRefWznmMTable = "", const std::string& srefFrsRefWznmMSubset = "", const std::string& srefToRefWznmMTable = "", const std::string& srefTosRefWznmMSubset = "", const std::string& srefRefWznmMTable = "", const std::string& Prefix = "", const std::string& srefsKOption = "");
		ImeitemIMRelation(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		std::string srefIxVBasetype;
		Sbecore::ubigint irefRefWznmCRelation;
		Sbecore::ubigint irefSupRefWznmMRelation;
		std::string srefSupIxVSubrole;
		std::string srefFrRefWznmMTable;
		std::string srefFrsRefWznmMSubset;
		std::string srefToRefWznmMTable;
		std::string srefTosRefWznmMSubset;
		std::string srefRefWznmMTable;

		ImeIAMRelationTitle imeiamrelationtitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRelation (full: ImeIWznmDbsMRelation)
		*/
	class ImeIMRelation {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMRelationIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint IREFREFWZNMCRELATION = 4;
			static const Sbecore::uint IREFSUPREFWZNMMRELATION = 8;
			static const Sbecore::uint SREFSUPIXVSUBROLE = 16;
			static const Sbecore::uint SREFFRREFWZNMMTABLE = 32;
			static const Sbecore::uint SREFFRSREFWZNMMSUBSET = 64;
			static const Sbecore::uint SREFTOREFWZNMMTABLE = 128;
			static const Sbecore::uint SREFTOSREFWZNMMSUBSET = 256;
			static const Sbecore::uint SREFREFWZNMMTABLE = 512;
			static const Sbecore::uint PREFIX = 1024;
			static const Sbecore::uint SREFSKOPTION = 2048;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRelation();
		~ImeIMRelation();

	public:
		std::vector<ImeitemIMRelation*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMStub (full: ImeitemIWznmDbsMStub)
		*/
	class ImeitemIMStub : public WznmMStub {

	public:
		ImeitemIMStub(const Sbecore::uint ixVBasetype = 0, const std::string& srefRefWznmMTable = "", const std::string& srefRefWznmMSubset = "", const std::string& sref = "", const bool Hierarch = false, const std::string& srefRefWznmMTablecol = "", const bool Localized = false, const std::string& Example = "");
		ImeitemIMStub(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefWznmMTable;
		std::string srefRefWznmMSubset;
		std::string srefRefWznmMTablecol;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMStub (full: ImeIWznmDbsMStub)
		*/
	class ImeIMStub {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMStubIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFWZNMMTABLE = 2;
			static const Sbecore::uint SREFREFWZNMMSUBSET = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint HIERARCH = 16;
			static const Sbecore::uint SREFREFWZNMMTABLECOL = 32;
			static const Sbecore::uint LOCALIZED = 64;
			static const Sbecore::uint EXAMPLE = 128;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMStub();
		~ImeIMStub();

	public:
		std::vector<ImeitemIMStub*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMTableLoadfct (full: ImeitemIWznmDbsAMTableLoadfct)
		*/
	class ImeitemIAMTableLoadfct : public WznmAMTableLoadfct {

	public:
		ImeitemIAMTableLoadfct(const Sbecore::uint ixVLoadtype = 0, const std::string& Fctname = "", const std::string& ldSrefWznmMTablecol = "", const std::string& lbySrefsWznmMTablecol = "", const std::string& ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0);
		ImeitemIAMTableLoadfct(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVLoadtype;
		std::string srefIxVLimtype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMTableLoadfct (full: ImeIWznmDbsAMTableLoadfct)
		*/
	class ImeIAMTableLoadfct {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMTableLoadfctIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVLOADTYPE = 1;
			static const Sbecore::uint FCTNAME = 2;
			static const Sbecore::uint LDSREFWZNMMTABLECOL = 4;
			static const Sbecore::uint LBYSREFSWZNMMTABLECOL = 8;
			static const Sbecore::uint ORDSREFSWZNMMTABLECOL = 16;
			static const Sbecore::uint SREFIXVLIMTYPE = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMTableLoadfct();
		~ImeIAMTableLoadfct();

	public:
		std::vector<ImeitemIAMTableLoadfct*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMTableTitle (full: ImeitemIWznmDbsAMTableTitle)
		*/
	class ImeitemIAMTableTitle : public WznmAMTableTitle {

	public:
		ImeitemIAMTableTitle(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string& Title = "");
		ImeitemIAMTableTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxVType;
		std::string srefX2RefWznmMLocale;
		std::string srefIxWznmVGender;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMTableTitle (full: ImeIWznmDbsAMTableTitle)
		*/
	class ImeIAMTableTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMTableTitleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXVTYPE = 1;
			static const Sbecore::uint SREFX2REFWZNMMLOCALE = 2;
			static const Sbecore::uint SREFIXWZNMVGENDER = 4;
			static const Sbecore::uint TITLE = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMTableTitle();
		~ImeIAMTableTitle();

	public:
		std::vector<ImeitemIAMTableTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCheck (full: ImeitemIWznmDbsMCheck)
		*/
	class ImeitemIMCheck : public WznmMCheck {

	public:
		ImeitemIMCheck(const Sbecore::uint ixVBasetype = 0, const std::string& srefRefWznmMTablecol = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMCheck(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefWznmMTablecol;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCheck (full: ImeIWznmDbsMCheck)
		*/
	class ImeIMCheck {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMCheckIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFWZNMMTABLECOL = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCheck();
		~ImeIMCheck();

	public:
		std::vector<ImeitemIMCheck*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMSubsetTitle (full: ImeitemIWznmDbsAMSubsetTitle)
		*/
	class ImeitemIAMSubsetTitle : public WznmAMSubsetTitle {

	public:
		ImeitemIAMSubsetTitle(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string& Title = "");
		ImeitemIAMSubsetTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxVType;
		std::string srefX2RefWznmMLocale;
		std::string srefIxWznmVGender;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMSubsetTitle (full: ImeIWznmDbsAMSubsetTitle)
		*/
	class ImeIAMSubsetTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMSubsetTitleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXVTYPE = 1;
			static const Sbecore::uint SREFX2REFWZNMMLOCALE = 2;
			static const Sbecore::uint SREFIXWZNMVGENDER = 4;
			static const Sbecore::uint TITLE = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMSubsetTitle();
		~ImeIAMSubsetTitle();

	public:
		std::vector<ImeitemIAMSubsetTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMSubsetMSubset (full: ImeitemIWznmDbsRMSubsetMSubset)
		*/
	class ImeitemIRMSubsetMSubset : public WznmRMSubsetMSubset {

	public:
		ImeitemIRMSubsetMSubset(const std::string& srefBsbRefWznmMSubset = "", const Sbecore::uint ixVReltype = 0);
		ImeitemIRMSubsetMSubset(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefBsbRefWznmMSubset;
		std::string srefIxVReltype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMSubsetMSubset (full: ImeIWznmDbsRMSubsetMSubset)
		*/
	class ImeIRMSubsetMSubset {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsRMSubsetMSubsetIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFBSBREFWZNMMSUBSET = 1;
			static const Sbecore::uint SREFIXVRELTYPE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMSubsetMSubset();
		~ImeIRMSubsetMSubset();

	public:
		std::vector<ImeitemIRMSubsetMSubset*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSubset (full: ImeitemIWznmDbsMSubset)
		*/
	class ImeitemIMSubset : public WznmMSubset {

	public:
		ImeitemIMSubset(const std::string& sref = "", const std::string& Short = "", const std::string& Cond = "", const std::string& Comment = "");
		ImeitemIMSubset(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMSubsetTitle imeiamsubsettitle;
		ImeIRMSubsetMSubset imeirmsubsetmsubset;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSubset (full: ImeIWznmDbsMSubset)
		*/
	class ImeIMSubset {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMSubsetIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SHORT = 2;
			static const Sbecore::uint COND = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSubset();
		~ImeIMSubset();

	public:
		std::vector<ImeitemIMSubset*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMTablecolTitle (full: ImeitemIWznmDbsAMTablecolTitle)
		*/
	class ImeitemIAMTablecolTitle : public WznmAMTablecolTitle {

	public:
		ImeitemIAMTablecolTitle(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIAMTablecolTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIAMTablecolTitle (full: ImeIWznmDbsAMTablecolTitle)
		*/
	class ImeIAMTablecolTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMTablecolTitleIel)
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
		ImeIAMTablecolTitle();
		~ImeIAMTablecolTitle();

	public:
		std::vector<ImeitemIAMTablecolTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMTablecol (full: ImeitemIWznmDbsMTablecol)
		*/
	class ImeitemIMTablecol : public WznmMTablecol {

	public:
		ImeitemIMTablecol(const Sbecore::uint ixVBasetype = 0, const std::string& srefRefWznmMSubset = "", const Sbecore::ubigint irefRefWznmMRelation = 0, const Sbecore::uint fctIxVTbl = 0, const std::string& srefFctUref = "", const std::string& sref = "", const std::string& Short = "", const Sbecore::uint ixVSubtype = 0, const Sbecore::uint ixVAxisfct = 0, const std::string& srefsKOption = "", const bool Principal = false, const bool Eponymous = false);
		ImeitemIMTablecol(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefWznmMSubset;
		Sbecore::ubigint irefRefWznmMRelation;
		std::string srefFctIxVTbl;
		std::string srefFctUref;
		std::string srefIxVSubtype;
		std::string srefIxVAxisfct;

		ImeIAMTablecolTitle imeiamtablecoltitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTablecol (full: ImeIWznmDbsMTablecol)
		*/
	class ImeIMTablecol {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMTablecolIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFWZNMMSUBSET = 2;
			static const Sbecore::uint IREFREFWZNMMRELATION = 4;
			static const Sbecore::uint SREFFCTIXVTBL = 8;
			static const Sbecore::uint SREFFCTUREF = 16;
			static const Sbecore::uint SREF = 32;
			static const Sbecore::uint SHORT = 64;
			static const Sbecore::uint SREFIXVSUBTYPE = 128;
			static const Sbecore::uint SREFIXVAXISFCT = 256;
			static const Sbecore::uint SREFSKOPTION = 512;
			static const Sbecore::uint PRINCIPAL = 1024;
			static const Sbecore::uint EPONYMOUS = 2048;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMTablecol();
		~ImeIMTablecol();

	public:
		std::vector<ImeitemIMTablecol*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMVectorTitle2 (full: ImeitemIWznmDbsAMVectorTitle2)
		*/
	class ImeitemIAMVectorTitle2 : public WznmAMVectorTitle {

	public:
		ImeitemIAMVectorTitle2(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIAMVectorTitle2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIAMVectorTitle2 (full: ImeIWznmDbsAMVectorTitle2)
		*/
	class ImeIAMVectorTitle2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMVectorTitle2Iel)
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
		ImeIAMVectorTitle2();
		~ImeIAMVectorTitle2();

	public:
		std::vector<ImeitemIAMVectorTitle2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMVectoritem2 (full: ImeitemIWznmDbsJMVectoritem2)
		*/
	class ImeitemIJMVectoritem2 : public WznmJMVectoritem {

	public:
		ImeitemIJMVectoritem2(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJMVectoritem2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMVectoritem2 (full: ImeIWznmDbsJMVectoritem2)
		*/
	class ImeIJMVectoritem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsJMVectoritem2Iel)
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
		ImeIJMVectoritem2();
		~ImeIJMVectoritem2();

	public:
		std::vector<ImeitemIJMVectoritem2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVectoritem2 (full: ImeitemIWznmDbsMVectoritem2)
		*/
	class ImeitemIMVectoritem2 : public WznmMVectoritem {

	public:
		ImeitemIMVectoritem2(const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMVectoritem2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMVectoritem2 imeijmvectoritem2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVectoritem2 (full: ImeIWznmDbsMVectoritem2)
		*/
	class ImeIMVectoritem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMVectoritem2Iel)
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
		ImeIMVectoritem2();
		~ImeIMVectoritem2();

	public:
		std::vector<ImeitemIMVectoritem2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMTableMVector2 (full: ImeitemIWznmDbsRMTableMVector2)
		*/
	class ImeitemIRMTableMVector2 : public WznmRMTableMVector {

	public:
		ImeitemIRMTableMVector2(const std::string& srefRefWznmMTable = "", const std::string& srefRefWznmMSubset = "");
		ImeitemIRMTableMVector2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMTable;
		std::string srefRefWznmMSubset;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMTableMVector2 (full: ImeIWznmDbsRMTableMVector2)
		*/
	class ImeIRMTableMVector2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsRMTableMVector2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMTABLE = 1;
			static const Sbecore::uint SREFREFWZNMMSUBSET = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMTableMVector2();
		~ImeIRMTableMVector2();

	public:
		std::vector<ImeitemIRMTableMVector2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector2 (full: ImeitemIWznmDbsMVector2)
		*/
	class ImeitemIMVector2 : public WznmMVector {

	public:
		ImeitemIMVector2(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& srefsKOption = "");
		ImeitemIMVector2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIAMVectorTitle2 imeiamvectortitle2;
		ImeIMVectoritem2 imeimvectoritem2;
		ImeIRMTableMVector2 imeirmtablemvector2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector2 (full: ImeIWznmDbsMVector2)
		*/
	class ImeIMVector2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMVector2Iel)
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
		ImeIMVector2();
		~ImeIMVector2();

	public:
		std::vector<ImeitemIMVector2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMTable (full: ImeitemIWznmDbsMTable)
		*/
	class ImeitemIMTable : public WznmMTable {

	public:
		ImeitemIMTable(const Sbecore::uint ixVBasetype = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint irefRefUref = 0, const std::string& sref = "", const std::string& Short = "", const std::string& unqSrefsWznmMTablecol = "", const std::string& Comment = "");
		ImeitemIMTable(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefIxVTbl;
		Sbecore::ubigint irefRefUref;

		ImeIAMTableLoadfct imeiamtableloadfct;
		ImeIAMTableTitle imeiamtabletitle;
		ImeIMCheck imeimcheck;
		ImeIMSubset imeimsubset;
		ImeIMTablecol imeimtablecol;
		ImeIMVector2 imeimvector2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTable (full: ImeIWznmDbsMTable)
		*/
	class ImeIMTable {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMTableIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFIXVTBL = 2;
			static const Sbecore::uint IREFREFUREF = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SHORT = 16;
			static const Sbecore::uint UNQSREFSWZNMMTABLECOL = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMTable();
		~ImeIMTable();

	public:
		std::vector<ImeitemIMTable*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMVectorTitle1 (full: ImeitemIWznmDbsAMVectorTitle1)
		*/
	class ImeitemIAMVectorTitle1 : public WznmAMVectorTitle {

	public:
		ImeitemIAMVectorTitle1(const Sbecore::uint x1IxVType = 0, const std::string& srefX2RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIAMVectorTitle1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIAMVectorTitle1 (full: ImeIWznmDbsAMVectorTitle1)
		*/
	class ImeIAMVectorTitle1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsAMVectorTitle1Iel)
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
		ImeIAMVectorTitle1();
		~ImeIAMVectorTitle1();

	public:
		std::vector<ImeitemIAMVectorTitle1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMVectoritem1 (full: ImeitemIWznmDbsJMVectoritem1)
		*/
	class ImeitemIJMVectoritem1 : public WznmJMVectoritem {

	public:
		ImeitemIJMVectoritem1(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJMVectoritem1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMVectoritem1 (full: ImeIWznmDbsJMVectoritem1)
		*/
	class ImeIJMVectoritem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsJMVectoritem1Iel)
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
		ImeIJMVectoritem1();
		~ImeIJMVectoritem1();

	public:
		std::vector<ImeitemIJMVectoritem1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVectoritem1 (full: ImeitemIWznmDbsMVectoritem1)
		*/
	class ImeitemIMVectoritem1 : public WznmMVectoritem {

	public:
		ImeitemIMVectoritem1(const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMVectoritem1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMVectoritem1 imeijmvectoritem1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVectoritem1 (full: ImeIWznmDbsMVectoritem1)
		*/
	class ImeIMVectoritem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMVectoritem1Iel)
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
		ImeIMVectoritem1();
		~ImeIMVectoritem1();

	public:
		std::vector<ImeitemIMVectoritem1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMTableMVector1 (full: ImeitemIWznmDbsRMTableMVector1)
		*/
	class ImeitemIRMTableMVector1 : public WznmRMTableMVector {

	public:
		ImeitemIRMTableMVector1(const std::string& srefRefWznmMTable = "", const std::string& srefRefWznmMSubset = "");
		ImeitemIRMTableMVector1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMTable;
		std::string srefRefWznmMSubset;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMTableMVector1 (full: ImeIWznmDbsRMTableMVector1)
		*/
	class ImeIRMTableMVector1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsRMTableMVector1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMTABLE = 1;
			static const Sbecore::uint SREFREFWZNMMSUBSET = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMTableMVector1();
		~ImeIRMTableMVector1();

	public:
		std::vector<ImeitemIRMTableMVector1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector1 (full: ImeitemIWznmDbsMVector1)
		*/
	class ImeitemIMVector1 : public WznmMVector {

	public:
		ImeitemIMVector1(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& srefsKOption = "");
		ImeitemIMVector1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIAMVectorTitle1 imeiamvectortitle1;
		ImeIMVectoritem1 imeimvectoritem1;
		ImeIRMTableMVector1 imeirmtablemvector1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector1 (full: ImeIWznmDbsMVector1)
		*/
	class ImeIMVector1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsMVector1Iel)
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
		ImeIMVector1();
		~ImeIMVector1();

	public:
		std::vector<ImeitemIMVector1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMStubMStub (full: ImeitemIWznmDbsRMStubMStub)
		*/
	class ImeitemIRMStubMStub : public WznmRMStubMStub {

	public:
		ImeitemIRMStubMStub(const std::string& srefSupRefWznmMStub = "", const std::string& srefSubRefWznmMStub = "");
		ImeitemIRMStubMStub(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSupRefWznmMStub;
		std::string srefSubRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMStubMStub (full: ImeIWznmDbsRMStubMStub)
		*/
	class ImeIRMStubMStub {

	public:
		/**
			* VecWIel (full: VecWImeIWznmDbsRMStubMStubIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSUPREFWZNMMSTUB = 1;
			static const Sbecore::uint SREFSUBREFWZNMMSTUB = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMStubMStub();
		~ImeIRMStubMStub();

	public:
		std::vector<ImeitemIRMStubMStub*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeICRelation& imeicrelation, ImeIMRelation& imeimrelation, ImeIMStub& imeimstub, ImeIMTable& imeimtable, ImeIMVector1& imeimvector1, ImeIRMStubMStub& imeirmstubmstub);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeICRelation& imeicrelation, ImeIMRelation& imeimrelation, ImeIMStub& imeimstub, ImeIMTable& imeimtable, ImeIMVector1& imeimvector1, ImeIRMStubMStub& imeirmstubmstub);

	void readTxt(Sbecore::Txtrd& txtrd, ImeICRelation& imeicrelation, ImeIMRelation& imeimrelation, ImeIMStub& imeimstub, ImeIMTable& imeimtable, ImeIMVector1& imeimvector1, ImeIRMStubMStub& imeirmstubmstub);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeICRelation& imeicrelation, ImeIMRelation& imeimrelation, ImeIMStub& imeimstub, ImeIMTable& imeimtable, ImeIMVector1& imeimvector1, ImeIRMStubMStub& imeirmstubmstub);

	void writeTxt(std::fstream& outfile, ImeICRelation& imeicrelation, ImeIMRelation& imeimrelation, ImeIMStub& imeimstub, ImeIMTable& imeimtable, ImeIMVector1& imeimvector1, ImeIRMStubMStub& imeirmstubmstub);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeICRelation& imeicrelation, ImeIMRelation& imeimrelation, ImeIMStub& imeimstub, ImeIMTable& imeimtable, ImeIMVector1& imeimvector1, ImeIRMStubMStub& imeirmstubmstub);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif
