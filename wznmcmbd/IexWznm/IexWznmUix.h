/**
	* \file IexWznmUix.h
	* data blocks and readers/writers for import/export complex IexWznmUix (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWZNMUIX_H
#define IEXWZNMUIX_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmUixIme IexWznmUix::VecVIme

#define ImeitemIWznmUixAMControlPar1 IexWznmUix::ImeitemIAMControlPar1
#define ImeIWznmUixAMControlPar1 IexWznmUix::ImeIAMControlPar1
#define VecWImeIWznmUixAMControlPar1Iel IexWznmUix::ImeIAMControlPar1::VecWIel

#define ImeitemIWznmUixJMControlTitle1 IexWznmUix::ImeitemIJMControlTitle1
#define ImeIWznmUixJMControlTitle1 IexWznmUix::ImeIJMControlTitle1
#define VecWImeIWznmUixJMControlTitle1Iel IexWznmUix::ImeIJMControlTitle1::VecWIel

#define ImeitemIWznmUixMControl1 IexWznmUix::ImeitemIMControl1
#define ImeIWznmUixMControl1 IexWznmUix::ImeIMControl1
#define VecWImeIWznmUixMControl1Iel IexWznmUix::ImeIMControl1::VecWIel

#define ImeitemIWznmUixCControl3 IexWznmUix::ImeitemICControl3
#define ImeIWznmUixCControl3 IexWznmUix::ImeICControl3
#define VecWImeIWznmUixCControl3Iel IexWznmUix::ImeICControl3::VecWIel

#define ImeitemIWznmUixAMControlPar3 IexWznmUix::ImeitemIAMControlPar3
#define ImeIWznmUixAMControlPar3 IexWznmUix::ImeIAMControlPar3
#define VecWImeIWznmUixAMControlPar3Iel IexWznmUix::ImeIAMControlPar3::VecWIel

#define ImeitemIWznmUixJMControl3 IexWznmUix::ImeitemIJMControl3
#define ImeIWznmUixJMControl3 IexWznmUix::ImeIJMControl3
#define VecWImeIWznmUixJMControl3Iel IexWznmUix::ImeIJMControl3::VecWIel

#define ImeitemIWznmUixJMControlTitle3 IexWznmUix::ImeitemIJMControlTitle3
#define ImeIWznmUixJMControlTitle3 IexWznmUix::ImeIJMControlTitle3
#define VecWImeIWznmUixJMControlTitle3Iel IexWznmUix::ImeIJMControlTitle3::VecWIel

#define ImeitemIWznmUixMVector3 IexWznmUix::ImeitemIMVector3
#define ImeIWznmUixMVector3 IexWznmUix::ImeIMVector3
#define VecWImeIWznmUixMVector3Iel IexWznmUix::ImeIMVector3::VecWIel

#define ImeitemIWznmUixMFeed3 IexWznmUix::ImeitemIMFeed3
#define ImeIWznmUixMFeed3 IexWznmUix::ImeIMFeed3
#define VecWImeIWznmUixMFeed3Iel IexWznmUix::ImeIMFeed3::VecWIel

#define ImeitemIWznmUixMControl3 IexWznmUix::ImeitemIMControl3
#define ImeIWznmUixMControl3 IexWznmUix::ImeIMControl3
#define VecWImeIWznmUixMControl3Iel IexWznmUix::ImeIMControl3::VecWIel

#define ImeitemIWznmUixMDialog IexWznmUix::ImeitemIMDialog
#define ImeIWznmUixMDialog IexWznmUix::ImeIMDialog
#define VecWImeIWznmUixMDialogIel IexWznmUix::ImeIMDialog::VecWIel

#define ImeitemIWznmUixCControl2 IexWznmUix::ImeitemICControl2
#define ImeIWznmUixCControl2 IexWznmUix::ImeICControl2
#define VecWImeIWznmUixCControl2Iel IexWznmUix::ImeICControl2::VecWIel

#define ImeitemIWznmUixAMControlPar2 IexWznmUix::ImeitemIAMControlPar2
#define ImeIWznmUixAMControlPar2 IexWznmUix::ImeIAMControlPar2
#define VecWImeIWznmUixAMControlPar2Iel IexWznmUix::ImeIAMControlPar2::VecWIel

#define ImeitemIWznmUixJMControl2 IexWznmUix::ImeitemIJMControl2
#define ImeIWznmUixJMControl2 IexWznmUix::ImeIJMControl2
#define VecWImeIWznmUixJMControl2Iel IexWznmUix::ImeIJMControl2::VecWIel

#define ImeitemIWznmUixJMControlTitle2 IexWznmUix::ImeitemIJMControlTitle2
#define ImeIWznmUixJMControlTitle2 IexWznmUix::ImeIJMControlTitle2
#define VecWImeIWznmUixJMControlTitle2Iel IexWznmUix::ImeIJMControlTitle2::VecWIel

#define ImeitemIWznmUixMVector2 IexWznmUix::ImeitemIMVector2
#define ImeIWznmUixMVector2 IexWznmUix::ImeIMVector2
#define VecWImeIWznmUixMVector2Iel IexWznmUix::ImeIMVector2::VecWIel

#define ImeitemIWznmUixMFeed2 IexWznmUix::ImeitemIMFeed2
#define ImeIWznmUixMFeed2 IexWznmUix::ImeIMFeed2
#define VecWImeIWznmUixMFeed2Iel IexWznmUix::ImeIMFeed2::VecWIel

#define ImeitemIWznmUixMControl2 IexWznmUix::ImeitemIMControl2
#define ImeIWznmUixMControl2 IexWznmUix::ImeIMControl2
#define VecWImeIWznmUixMControl2Iel IexWznmUix::ImeIMControl2::VecWIel

#define ImeitemIWznmUixMPanel IexWznmUix::ImeitemIMPanel
#define ImeIWznmUixMPanel IexWznmUix::ImeIMPanel
#define VecWImeIWznmUixMPanelIel IexWznmUix::ImeIMPanel::VecWIel

#define ImeitemIWznmUixMCard IexWznmUix::ImeitemIMCard
#define ImeIWznmUixMCard IexWznmUix::ImeIMCard
#define VecWImeIWznmUixMCardIel IexWznmUix::ImeIMCard::VecWIel

#define ImeitemIWznmUixJMPresetTitle IexWznmUix::ImeitemIJMPresetTitle
#define ImeIWznmUixJMPresetTitle IexWznmUix::ImeIJMPresetTitle
#define VecWImeIWznmUixJMPresetTitleIel IexWznmUix::ImeIJMPresetTitle::VecWIel

#define ImeitemIWznmUixMPreset IexWznmUix::ImeitemIMPreset
#define ImeIWznmUixMPreset IexWznmUix::ImeIMPreset
#define VecWImeIWznmUixMPresetIel IexWznmUix::ImeIMPreset::VecWIel

#define ImeitemIWznmUixAMQueryClause IexWznmUix::ImeitemIAMQueryClause
#define ImeIWznmUixAMQueryClause IexWznmUix::ImeIAMQueryClause
#define VecWImeIWznmUixAMQueryClauseIel IexWznmUix::ImeIAMQueryClause::VecWIel

#define ImeitemIWznmUixAMQueryOrder IexWznmUix::ImeitemIAMQueryOrder
#define ImeIWznmUixAMQueryOrder IexWznmUix::ImeIAMQueryOrder
#define VecWImeIWznmUixAMQueryOrderIel IexWznmUix::ImeIAMQueryOrder::VecWIel

#define ImeitemIWznmUixJMQuerycolStub IexWznmUix::ImeitemIJMQuerycolStub
#define ImeIWznmUixJMQuerycolStub IexWznmUix::ImeIJMQuerycolStub
#define VecWImeIWznmUixJMQuerycolStubIel IexWznmUix::ImeIJMQuerycolStub::VecWIel

#define ImeitemIWznmUixMQuerycol IexWznmUix::ImeitemIMQuerycol
#define ImeIWznmUixMQuerycol IexWznmUix::ImeIMQuerycol
#define VecWImeIWznmUixMQuerycolIel IexWznmUix::ImeIMQuerycol::VecWIel

#define ImeitemIWznmUixMQuerymod IexWznmUix::ImeitemIMQuerymod
#define ImeIWznmUixMQuerymod IexWznmUix::ImeIMQuerymod
#define VecWImeIWznmUixMQuerymodIel IexWznmUix::ImeIMQuerymod::VecWIel

#define ImeitemIWznmUixTMQuerymodMQuery IexWznmUix::ImeitemITMQuerymodMQuery
#define ImeIWznmUixTMQuerymodMQuery IexWznmUix::ImeITMQuerymodMQuery
#define VecWImeIWznmUixTMQuerymodMQueryIel IexWznmUix::ImeITMQuerymodMQuery::VecWIel

#define ImeitemIWznmUixRMQueryMTable IexWznmUix::ImeitemIRMQueryMTable
#define ImeIWznmUixRMQueryMTable IexWznmUix::ImeIRMQueryMTable
#define VecWImeIWznmUixRMQueryMTableIel IexWznmUix::ImeIRMQueryMTable::VecWIel

#define ImeitemIWznmUixMQuery IexWznmUix::ImeitemIMQuery
#define ImeIWznmUixMQuery IexWznmUix::ImeIMQuery
#define VecWImeIWznmUixMQueryIel IexWznmUix::ImeIMQuery::VecWIel

#define ImeitemIWznmUixRMPanelMQuery IexWznmUix::ImeitemIRMPanelMQuery
#define ImeIWznmUixRMPanelMQuery IexWznmUix::ImeIRMPanelMQuery
#define VecWImeIWznmUixRMPanelMQueryIel IexWznmUix::ImeIRMPanelMQuery::VecWIel

/**
	* IexWznmUix
	*/
namespace IexWznmUix {
	/**
		* VecVIme (full: VecVIexWznmUixIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMCONTROLPAR1 = 1;
		static const Sbecore::uint IMEIAMCONTROLPAR2 = 2;
		static const Sbecore::uint IMEIAMCONTROLPAR3 = 3;
		static const Sbecore::uint IMEIAMQUERYCLAUSE = 4;
		static const Sbecore::uint IMEIAMQUERYORDER = 5;
		static const Sbecore::uint IMEICCONTROL2 = 6;
		static const Sbecore::uint IMEICCONTROL3 = 7;
		static const Sbecore::uint IMEIJMCONTROL2 = 8;
		static const Sbecore::uint IMEIJMCONTROL3 = 9;
		static const Sbecore::uint IMEIJMCONTROLTITLE1 = 10;
		static const Sbecore::uint IMEIJMCONTROLTITLE2 = 11;
		static const Sbecore::uint IMEIJMCONTROLTITLE3 = 12;
		static const Sbecore::uint IMEIJMPRESETTITLE = 13;
		static const Sbecore::uint IMEIJMQUERYCOLSTUB = 14;
		static const Sbecore::uint IMEIMCARD = 15;
		static const Sbecore::uint IMEIMCONTROL1 = 16;
		static const Sbecore::uint IMEIMCONTROL2 = 17;
		static const Sbecore::uint IMEIMCONTROL3 = 18;
		static const Sbecore::uint IMEIMDIALOG = 19;
		static const Sbecore::uint IMEIMFEED2 = 20;
		static const Sbecore::uint IMEIMFEED3 = 21;
		static const Sbecore::uint IMEIMPANEL = 22;
		static const Sbecore::uint IMEIMPRESET = 23;
		static const Sbecore::uint IMEIMQUERY = 24;
		static const Sbecore::uint IMEIMQUERYCOL = 25;
		static const Sbecore::uint IMEIMQUERYMOD = 26;
		static const Sbecore::uint IMEIMVECTOR2 = 27;
		static const Sbecore::uint IMEIMVECTOR3 = 28;
		static const Sbecore::uint IMEIRMPANELMQUERY = 29;
		static const Sbecore::uint IMEIRMQUERYMTABLE = 30;
		static const Sbecore::uint IMEITMQUERYMODMQUERY = 31;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMControlPar1 (full: ImeitemIWznmUixAMControlPar1)
		*/
	class ImeitemIAMControlPar1 : public WznmAMControlPar {

	public:
		ImeitemIAMControlPar1(const std::string& x1SrefKKey = "", const std::string& srefX2RefWznmMLocale = "", const std::string& osrefKVal = "");
		ImeitemIAMControlPar1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX2RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMControlPar1 (full: ImeIWznmUixAMControlPar1)
		*/
	class ImeIAMControlPar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixAMControlPar1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKKEY = 1;
			static const Sbecore::uint SREFX2REFWZNMMLOCALE = 2;
			static const Sbecore::uint OSREFKVAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMControlPar1();
		~ImeIAMControlPar1();

	public:
		std::vector<ImeitemIAMControlPar1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMControlTitle1 (full: ImeitemIWznmUixJMControlTitle1)
		*/
	class ImeitemIJMControlTitle1 : public WznmJMControlTitle {

	public:
		ImeitemIJMControlTitle1(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMControlTitle1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMControlTitle1 (full: ImeIWznmUixJMControlTitle1)
		*/
	class ImeIJMControlTitle1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMControlTitle1Iel)
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
		ImeIJMControlTitle1();
		~ImeIJMControlTitle1();

	public:
		std::vector<ImeitemIJMControlTitle1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMControl1 (full: ImeitemIWznmUixMControl1)
		*/
	class ImeitemIMControl1 : public WznmMControl {

	public:
		ImeitemIMControl1(const Sbecore::uint ixVBasetype = 0, const Sbecore::uint hkIxVSection = 0, const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const std::string& srefSupRefWznmMControl = "", const Sbecore::uint supNum = 0, const Sbecore::uint ixVScope = 0, const std::string& sref = "", const Sbecore::uint ixVSubtype = 0, const std::string& srefsWznmMTag = "", const std::string& Title = "", const std::string& Avail = "", const std::string& Active = "", const std::string& srefsKOption = "");
		ImeitemIMControl1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefHkIxVSection;
		std::string srefRefIxVTbl;
		std::string srefRefUref;
		std::string srefSupRefWznmMControl;
		std::string srefIxVScope;
		std::string srefIxVSubtype;

		ImeIAMControlPar1 imeiamcontrolpar1;
		ImeIJMControlTitle1 imeijmcontroltitle1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMControl1 (full: ImeIWznmUixMControl1)
		*/
	class ImeIMControl1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMControl1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFHKIXVSECTION = 2;
			static const Sbecore::uint SREFREFIXVTBL = 4;
			static const Sbecore::uint SREFREFUREF = 8;
			static const Sbecore::uint SREFSUPREFWZNMMCONTROL = 16;
			static const Sbecore::uint SUPNUM = 32;
			static const Sbecore::uint SREFIXVSCOPE = 64;
			static const Sbecore::uint SREF = 128;
			static const Sbecore::uint SREFIXVSUBTYPE = 256;
			static const Sbecore::uint SREFSWZNMMTAG = 512;
			static const Sbecore::uint TITLE = 1024;
			static const Sbecore::uint AVAIL = 2048;
			static const Sbecore::uint ACTIVE = 4096;
			static const Sbecore::uint SREFSKOPTION = 8192;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMControl1();
		~ImeIMControl1();

	public:
		std::vector<ImeitemIMControl1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICControl3 (full: ImeitemIWznmUixCControl3)
		*/
	class ImeitemICControl3 {

	public:
		ImeitemICControl3(const Sbecore::ubigint iref = 0);
		ImeitemICControl3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICControl3 (full: ImeIWznmUixCControl3)
		*/
	class ImeICControl3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixCControl3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICControl3();
		~ImeICControl3();

	public:
		std::vector<ImeitemICControl3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMControlPar3 (full: ImeitemIWznmUixAMControlPar3)
		*/
	class ImeitemIAMControlPar3 : public WznmAMControlPar {

	public:
		ImeitemIAMControlPar3(const std::string& x1SrefKKey = "", const std::string& srefX2RefWznmMLocale = "", const std::string& osrefKVal = "");
		ImeitemIAMControlPar3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX2RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMControlPar3 (full: ImeIWznmUixAMControlPar3)
		*/
	class ImeIAMControlPar3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixAMControlPar3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKKEY = 1;
			static const Sbecore::uint SREFX2REFWZNMMLOCALE = 2;
			static const Sbecore::uint OSREFKVAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMControlPar3();
		~ImeIAMControlPar3();

	public:
		std::vector<ImeitemIAMControlPar3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMControl3 (full: ImeitemIWznmUixJMControl3)
		*/
	class ImeitemIJMControl3 : public WznmJMControl {

	public:
		ImeitemIJMControl3(const std::string& srefX1RefWznmMVectoritem = "", const std::string& srefStdRefWznmMStub = "", const std::string& srefShoRefWznmMStub = "");
		ImeitemIJMControl3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWznmMVectoritem;
		std::string srefStdRefWznmMStub;
		std::string srefShoRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMControl3 (full: ImeIWznmUixJMControl3)
		*/
	class ImeIJMControl3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMControl3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMVECTORITEM = 1;
			static const Sbecore::uint SREFSTDREFWZNMMSTUB = 2;
			static const Sbecore::uint SREFSHOREFWZNMMSTUB = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMControl3();
		~ImeIJMControl3();

	public:
		std::vector<ImeitemIJMControl3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMControlTitle3 (full: ImeitemIWznmUixJMControlTitle3)
		*/
	class ImeitemIJMControlTitle3 : public WznmJMControlTitle {

	public:
		ImeitemIJMControlTitle3(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMControlTitle3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMControlTitle3 (full: ImeIWznmUixJMControlTitle3)
		*/
	class ImeIJMControlTitle3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMControlTitle3Iel)
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
		ImeIJMControlTitle3();
		~ImeIJMControlTitle3();

	public:
		std::vector<ImeitemIJMControlTitle3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector3 (full: ImeitemIWznmUixMVector3)
		*/
	class ImeitemIMVector3 : public WznmMVector {

	public:
		ImeitemIMVector3(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& srefsKOption = "");
		ImeitemIMVector3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector3 (full: ImeIWznmUixMVector3)
		*/
	class ImeIMVector3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMVector3Iel)
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
		ImeIMVector3();
		~ImeIMVector3();

	public:
		std::vector<ImeitemIMVector3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFeed3 (full: ImeitemIWznmUixMFeed3)
		*/
	class ImeitemIMFeed3 : public WznmMFeed {

	public:
		ImeitemIMFeed3(const Sbecore::uint srcIxVTbl = 0, const std::string& srefSrcUref = "", const std::string& sref = "", const std::string& srefsWznmMVectoritem = "", const std::string& srefsWznmMTag = "", const std::string& Comment = "");
		ImeitemIMFeed3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSrcIxVTbl;
		std::string srefSrcUref;

		ImeIMVector3 imeimvector3;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFeed3 (full: ImeIWznmUixMFeed3)
		*/
	class ImeIMFeed3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMFeed3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSRCIXVTBL = 1;
			static const Sbecore::uint SREFSRCUREF = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFSWZNMMVECTORITEM = 8;
			static const Sbecore::uint SREFSWZNMMTAG = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFeed3();
		~ImeIMFeed3();

	public:
		std::vector<ImeitemIMFeed3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMControl3 (full: ImeitemIWznmUixMControl3)
		*/
	class ImeitemIMControl3 : public WznmMControl {

	public:
		ImeitemIMControl3(const Sbecore::ubigint iref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefRefWznmCControl = 0, const Sbecore::uint hkIxVSection = 0, const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const Sbecore::ubigint irefSupRefWznmMControl = 0, const Sbecore::uint ixVScope = 0, const std::string& sref = "", const Sbecore::uint ixVSubtype = 0, const std::string& srefsWznmMTag = "", const std::string& Title = "", const std::string& srefStdRefWznmMStub = "", const std::string& srefShoRefWznmMStub = "", const std::string& Avail = "", const std::string& Active = "", const std::string& srefsKOption = "");
		ImeitemIMControl3(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		std::string srefIxVBasetype;
		Sbecore::ubigint irefRefWznmCControl;
		std::string srefHkIxVSection;
		std::string srefRefIxVTbl;
		std::string srefRefUref;
		Sbecore::ubigint irefSupRefWznmMControl;
		std::string srefIxVScope;
		std::string srefIxVSubtype;
		std::string srefStdRefWznmMStub;
		std::string srefShoRefWznmMStub;

		ImeIAMControlPar3 imeiamcontrolpar3;
		ImeIJMControl3 imeijmcontrol3;
		ImeIJMControlTitle3 imeijmcontroltitle3;
		ImeIMFeed3 imeimfeed3;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMControl3 (full: ImeIWznmUixMControl3)
		*/
	class ImeIMControl3 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMControl3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint IREFREFWZNMCCONTROL = 4;
			static const Sbecore::uint SREFHKIXVSECTION = 8;
			static const Sbecore::uint SREFREFIXVTBL = 16;
			static const Sbecore::uint SREFREFUREF = 32;
			static const Sbecore::uint IREFSUPREFWZNMMCONTROL = 64;
			static const Sbecore::uint SREFIXVSCOPE = 128;
			static const Sbecore::uint SREF = 256;
			static const Sbecore::uint SREFIXVSUBTYPE = 512;
			static const Sbecore::uint SREFSWZNMMTAG = 1024;
			static const Sbecore::uint TITLE = 2048;
			static const Sbecore::uint SREFSTDREFWZNMMSTUB = 4096;
			static const Sbecore::uint SREFSHOREFWZNMMSTUB = 8192;
			static const Sbecore::uint AVAIL = 16384;
			static const Sbecore::uint ACTIVE = 32768;
			static const Sbecore::uint SREFSKOPTION = 65536;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMControl3();
		~ImeIMControl3();

	public:
		std::vector<ImeitemIMControl3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMDialog (full: ImeitemIWznmUixMDialog)
		*/
	class ImeitemIMDialog : public WznmMDialog {

	public:
		ImeitemIMDialog(const Sbecore::uint ixVBasetype = 0, const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMDialog(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefIxVTbl;
		std::string srefRefUref;

		ImeICControl3 imeiccontrol3;
		ImeIMControl3 imeimcontrol3;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMDialog (full: ImeIWznmUixMDialog)
		*/
	class ImeIMDialog {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMDialogIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFIXVTBL = 2;
			static const Sbecore::uint SREFREFUREF = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMDialog();
		~ImeIMDialog();

	public:
		std::vector<ImeitemIMDialog*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICControl2 (full: ImeitemIWznmUixCControl2)
		*/
	class ImeitemICControl2 {

	public:
		ImeitemICControl2(const Sbecore::ubigint iref = 0);
		ImeitemICControl2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICControl2 (full: ImeIWznmUixCControl2)
		*/
	class ImeICControl2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixCControl2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICControl2();
		~ImeICControl2();

	public:
		std::vector<ImeitemICControl2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMControlPar2 (full: ImeitemIWznmUixAMControlPar2)
		*/
	class ImeitemIAMControlPar2 : public WznmAMControlPar {

	public:
		ImeitemIAMControlPar2(const Sbecore::uint ixWznmVIop = 0, const std::string& x1SrefKKey = "", const std::string& srefX2RefWznmMLocale = "", const std::string& osrefKVal = "");
		ImeitemIAMControlPar2(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefX2RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMControlPar2 (full: ImeIWznmUixAMControlPar2)
		*/
	class ImeIAMControlPar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixAMControlPar2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint X1SREFKKEY = 2;
			static const Sbecore::uint SREFX2REFWZNMMLOCALE = 4;
			static const Sbecore::uint OSREFKVAL = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMControlPar2();
		~ImeIAMControlPar2();

	public:
		std::vector<ImeitemIAMControlPar2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMControl2 (full: ImeitemIWznmUixJMControl2)
		*/
	class ImeitemIJMControl2 : public WznmJMControl {

	public:
		ImeitemIJMControl2(const Sbecore::uint ixWznmVIop = 0, const std::string& srefX1RefWznmMVectoritem = "", const std::string& srefStdRefWznmMStub = "", const std::string& srefShoRefWznmMStub = "");
		ImeitemIJMControl2(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefX1RefWznmMVectoritem;
		std::string srefStdRefWznmMStub;
		std::string srefShoRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMControl2 (full: ImeIWznmUixJMControl2)
		*/
	class ImeIJMControl2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMControl2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFX1REFWZNMMVECTORITEM = 2;
			static const Sbecore::uint SREFSTDREFWZNMMSTUB = 4;
			static const Sbecore::uint SREFSHOREFWZNMMSTUB = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMControl2();
		~ImeIJMControl2();

	public:
		std::vector<ImeitemIJMControl2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMControlTitle2 (full: ImeitemIWznmUixJMControlTitle2)
		*/
	class ImeitemIJMControlTitle2 : public WznmJMControlTitle {

	public:
		ImeitemIJMControlTitle2(const Sbecore::uint ixWznmVIop = 0, const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMControlTitle2(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefX1RefWznmMLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMControlTitle2 (full: ImeIWznmUixJMControlTitle2)
		*/
	class ImeIJMControlTitle2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMControlTitle2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFX1REFWZNMMLOCALE = 2;
			static const Sbecore::uint TITLE = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMControlTitle2();
		~ImeIJMControlTitle2();

	public:
		std::vector<ImeitemIJMControlTitle2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector2 (full: ImeitemIWznmUixMVector2)
		*/
	class ImeitemIMVector2 : public WznmMVector {

	public:
		ImeitemIMVector2(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& srefsKOption = "");
		ImeitemIMVector2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector2 (full: ImeIWznmUixMVector2)
		*/
	class ImeIMVector2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMVector2Iel)
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
		* ImeitemIMFeed2 (full: ImeitemIWznmUixMFeed2)
		*/
	class ImeitemIMFeed2 : public WznmMFeed {

	public:
		ImeitemIMFeed2(const Sbecore::uint srcIxVTbl = 0, const std::string& srefSrcUref = "", const std::string& sref = "", const std::string& srefsWznmMVectoritem = "", const std::string& srefsWznmMTag = "", const std::string& Comment = "");
		ImeitemIMFeed2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSrcIxVTbl;
		std::string srefSrcUref;

		ImeIMVector2 imeimvector2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFeed2 (full: ImeIWznmUixMFeed2)
		*/
	class ImeIMFeed2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMFeed2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSRCIXVTBL = 1;
			static const Sbecore::uint SREFSRCUREF = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFSWZNMMVECTORITEM = 8;
			static const Sbecore::uint SREFSWZNMMTAG = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFeed2();
		~ImeIMFeed2();

	public:
		std::vector<ImeitemIMFeed2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMControl2 (full: ImeitemIWznmUixMControl2)
		*/
	class ImeitemIMControl2 : public WznmMControl {

	public:
		ImeitemIMControl2(const Sbecore::uint ixWznmVIop = 0, const Sbecore::ubigint iref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefRefWznmCControl = 0, const Sbecore::uint hkIxVSection = 0, const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const Sbecore::ubigint irefSupRefWznmMControl = 0, const Sbecore::uint ixVScope = 0, const std::string& sref = "", const Sbecore::uint ixVSubtype = 0, const std::string& srefsWznmMTag = "", const std::string& Title = "", const std::string& srefStdRefWznmMStub = "", const std::string& srefShoRefWznmMStub = "", const std::string& Avail = "", const std::string& Active = "", const std::string& srefsKOption = "");
		ImeitemIMControl2(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		Sbecore::ubigint iref;
		std::string srefIxVBasetype;
		Sbecore::ubigint irefRefWznmCControl;
		std::string srefHkIxVSection;
		std::string srefRefIxVTbl;
		std::string srefRefUref;
		Sbecore::ubigint irefSupRefWznmMControl;
		std::string srefIxVScope;
		std::string srefIxVSubtype;
		std::string srefStdRefWznmMStub;
		std::string srefShoRefWznmMStub;

		ImeIAMControlPar2 imeiamcontrolpar2;
		ImeIJMControl2 imeijmcontrol2;
		ImeIJMControlTitle2 imeijmcontroltitle2;
		ImeIMFeed2 imeimfeed2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMControl2 (full: ImeIWznmUixMControl2)
		*/
	class ImeIMControl2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMControl2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint IREF = 2;
			static const Sbecore::uint SREFIXVBASETYPE = 4;
			static const Sbecore::uint IREFREFWZNMCCONTROL = 8;
			static const Sbecore::uint SREFHKIXVSECTION = 16;
			static const Sbecore::uint SREFREFIXVTBL = 32;
			static const Sbecore::uint SREFREFUREF = 64;
			static const Sbecore::uint IREFSUPREFWZNMMCONTROL = 128;
			static const Sbecore::uint SREFIXVSCOPE = 256;
			static const Sbecore::uint SREF = 512;
			static const Sbecore::uint SREFIXVSUBTYPE = 1024;
			static const Sbecore::uint SREFSWZNMMTAG = 2048;
			static const Sbecore::uint TITLE = 4096;
			static const Sbecore::uint SREFSTDREFWZNMMSTUB = 8192;
			static const Sbecore::uint SREFSHOREFWZNMMSTUB = 16384;
			static const Sbecore::uint AVAIL = 32768;
			static const Sbecore::uint ACTIVE = 65536;
			static const Sbecore::uint SREFSKOPTION = 131072;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMControl2();
		~ImeIMControl2();

	public:
		std::vector<ImeitemIMControl2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPanel (full: ImeitemIWznmUixMPanel)
		*/
	class ImeitemIMPanel : public WznmMPanel {

	public:
		ImeitemIMPanel(const Sbecore::uint ixWznmVIop = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint carNum = 0, const std::string& sref = "", const bool Detach = false, const std::string& Avail = "", const std::string& Comment = "");
		ImeitemIMPanel(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefIxVBasetype;

		ImeICControl2 imeiccontrol2;
		ImeIMControl2 imeimcontrol2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPanel (full: ImeIWznmUixMPanel)
		*/
	class ImeIMPanel {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMPanelIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint CARNUM = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint DETACH = 16;
			static const Sbecore::uint AVAIL = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPanel();
		~ImeIMPanel();

	public:
		std::vector<ImeitemIMPanel*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCard (full: ImeitemIWznmUixMCard)
		*/
	class ImeitemIMCard : public WznmMCard {

	public:
		ImeitemIMCard(const std::string& sref = "");
		ImeitemIMCard(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMControl1 imeimcontrol1;
		ImeIMDialog imeimdialog;
		ImeIMPanel imeimpanel;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCard (full: ImeIWznmUixMCard)
		*/
	class ImeIMCard {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMCardIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;

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
		* ImeitemIJMPresetTitle (full: ImeitemIWznmUixJMPresetTitle)
		*/
	class ImeitemIJMPresetTitle : public WznmJMPresetTitle {

	public:
		ImeitemIJMPresetTitle(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMPresetTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMPresetTitle (full: ImeIWznmUixJMPresetTitle)
		*/
	class ImeIJMPresetTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMPresetTitleIel)
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
		ImeIJMPresetTitle();
		~ImeIJMPresetTitle();

	public:
		std::vector<ImeitemIJMPresetTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPreset (full: ImeitemIWznmUixMPreset)
		*/
	class ImeitemIMPreset : public WznmMPreset {

	public:
		ImeitemIMPreset(const Sbecore::uint ixWznmVIop = 0, const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const Sbecore::uint ixVScope = 0, const std::string& sref = "", const Sbecore::uint ixWznmWArgtype = 0, const std::string& Title = "");
		ImeitemIMPreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefRefIxVTbl;
		std::string srefRefUref;
		std::string srefIxVScope;
		std::string srefIxWznmWArgtype;

		ImeIJMPresetTitle imeijmpresettitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPreset (full: ImeIWznmUixMPreset)
		*/
	class ImeIMPreset {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMPresetIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFREFIXVTBL = 2;
			static const Sbecore::uint SREFREFUREF = 4;
			static const Sbecore::uint SREFIXVSCOPE = 8;
			static const Sbecore::uint SREF = 16;
			static const Sbecore::uint SREFIXWZNMWARGTYPE = 32;
			static const Sbecore::uint TITLE = 64;

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

	/**
		* ImeitemIAMQueryClause (full: ImeitemIWznmUixAMQueryClause)
		*/
	class ImeitemIAMQueryClause : public WznmAMQueryClause {

	public:
		ImeitemIAMQueryClause(const Sbecore::ubigint irefX1RefWznmMQuerymod = 0, const Sbecore::uint ixVBasetype = 0, const std::string& Clause = "", const std::string& srefRefWznmMPreset = "", const std::string& srefRefWznmMVector = "", const std::string& srefRefWznmMVectoritem = "");
		ImeitemIAMQueryClause(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefX1RefWznmMQuerymod;
		std::string srefIxVBasetype;
		std::string srefRefWznmMPreset;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMQueryClause (full: ImeIWznmUixAMQueryClause)
		*/
	class ImeIAMQueryClause {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixAMQueryClauseIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFX1REFWZNMMQUERYMOD = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint CLAUSE = 4;
			static const Sbecore::uint SREFREFWZNMMPRESET = 8;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 16;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMQueryClause();
		~ImeIAMQueryClause();

	public:
		std::vector<ImeitemIAMQueryClause*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMQueryOrder (full: ImeitemIWznmUixAMQueryOrder)
		*/
	class ImeitemIAMQueryOrder : public WznmAMQueryOrder {

	public:
		ImeitemIAMQueryOrder(const Sbecore::uint ixWznmVIop = 0, const std::string& Short = "", const std::string& srefsWznmMTablecol = "");
		ImeitemIAMQueryOrder(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMQueryOrder (full: ImeIWznmUixAMQueryOrder)
		*/
	class ImeIAMQueryOrder {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixAMQueryOrderIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SHORT = 2;
			static const Sbecore::uint SREFSWZNMMTABLECOL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMQueryOrder();
		~ImeIAMQueryOrder();

	public:
		std::vector<ImeitemIAMQueryOrder*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMQuerycolStub (full: ImeitemIWznmUixJMQuerycolStub)
		*/
	class ImeitemIJMQuerycolStub : public WznmJMQuerycolStub {

	public:
		ImeitemIJMQuerycolStub(const Sbecore::uint ixWznmVIop = 0, const std::string& srefX1RefWznmMVectoritem = "", const std::string& srefX2RefWznmMPreset = "", const std::string& srefRefWznmMStub = "");
		ImeitemIJMQuerycolStub(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefX1RefWznmMVectoritem;
		std::string srefX2RefWznmMPreset;
		std::string srefRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMQuerycolStub (full: ImeIWznmUixJMQuerycolStub)
		*/
	class ImeIJMQuerycolStub {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixJMQuerycolStubIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFX1REFWZNMMVECTORITEM = 2;
			static const Sbecore::uint SREFX2REFWZNMMPRESET = 4;
			static const Sbecore::uint SREFREFWZNMMSTUB = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMQuerycolStub();
		~ImeIJMQuerycolStub();

	public:
		std::vector<ImeitemIJMQuerycolStub*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMQuerycol (full: ImeitemIWznmUixMQuerycol)
		*/
	class ImeitemIMQuerycol : public WznmMQuerycol {

	public:
		ImeitemIMQuerycol(const Sbecore::uint ixWznmVIop = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const std::string& srefRefWznmMTablecol = "", const std::string& sref = "", const std::string& Short = "", const std::string& srefRefWznmMStub = "");
		ImeitemIMQuerycol(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefIxVBasetype;
		std::string srefsIxWOccurrence;
		std::string srefRefWznmMTablecol;
		std::string srefRefWznmMStub;

		ImeIJMQuerycolStub imeijmquerycolstub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMQuerycol (full: ImeIWznmUixMQuerycol)
		*/
	class ImeIMQuerycol {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMQuerycolIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint SREFSIXWOCCURRENCE = 4;
			static const Sbecore::uint SREFREFWZNMMTABLECOL = 8;
			static const Sbecore::uint SREF = 16;
			static const Sbecore::uint SHORT = 32;
			static const Sbecore::uint SREFREFWZNMMSTUB = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMQuerycol();
		~ImeIMQuerycol();

	public:
		std::vector<ImeitemIMQuerycol*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMQuerymod (full: ImeitemIWznmUixMQuerymod)
		*/
	class ImeitemIMQuerymod : public WznmMQuerymod {

	public:
		ImeitemIMQuerymod(const Sbecore::uint ixWznmVIop = 0, const Sbecore::ubigint iref = 0, const Sbecore::uint ixVBasetype = 0, const std::string& srefRefWznmMPreset = "", const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const std::string& Avail = "");
		ImeitemIMQuerymod(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		Sbecore::ubigint iref;
		std::string srefIxVBasetype;
		std::string srefRefWznmMPreset;
		std::string srefRefIxVTbl;
		std::string srefRefUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMQuerymod (full: ImeIWznmUixMQuerymod)
		*/
	class ImeIMQuerymod {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMQuerymodIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint IREF = 2;
			static const Sbecore::uint SREFIXVBASETYPE = 4;
			static const Sbecore::uint SREFREFWZNMMPRESET = 8;
			static const Sbecore::uint SREFREFIXVTBL = 16;
			static const Sbecore::uint SREFREFUREF = 32;
			static const Sbecore::uint AVAIL = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMQuerymod();
		~ImeIMQuerymod();

	public:
		std::vector<ImeitemIMQuerymod*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemITMQuerymodMQuery (full: ImeitemIWznmUixTMQuerymodMQuery)
		*/
	class ImeitemITMQuerymodMQuery : public WznmTMQuerymodMQuery {

	public:
		ImeitemITMQuerymodMQuery(const Sbecore::ubigint irefRefWznmMQuerymod = 0);
		ImeitemITMQuerymodMQuery(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmMQuerymod;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeITMQuerymodMQuery (full: ImeIWznmUixTMQuerymodMQuery)
		*/
	class ImeITMQuerymodMQuery {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixTMQuerymodMQueryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMMQUERYMOD = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeITMQuerymodMQuery();
		~ImeITMQuerymodMQuery();

	public:
		std::vector<ImeitemITMQuerymodMQuery*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMQueryMTable (full: ImeitemIWznmUixRMQueryMTable)
		*/
	class ImeitemIRMQueryMTable : public WznmRMQueryMTable {

	public:
		ImeitemIRMQueryMTable(const std::string& srefRefWznmMTable = "", const bool Source = false, const std::string& Prefix = "");
		ImeitemIRMQueryMTable(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMTable;

		ImeITMQuerymodMQuery imeitmquerymodmquery;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMQueryMTable (full: ImeIWznmUixRMQueryMTable)
		*/
	class ImeIRMQueryMTable {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixRMQueryMTableIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMTABLE = 1;
			static const Sbecore::uint SOURCE = 2;
			static const Sbecore::uint PREFIX = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMQueryMTable();
		~ImeIRMQueryMTable();

	public:
		std::vector<ImeitemIRMQueryMTable*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMQuery (full: ImeitemIWznmUixMQuery)
		*/
	class ImeitemIMQuery : public WznmMQuery {

	public:
		ImeitemIMQuery(const Sbecore::uint ixWznmVIop = 0, const Sbecore::ubigint iref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefSupRefWznmMQuery = 0, const Sbecore::uint supIxVSubrole = 0, const std::string& sref = "", const bool Limofs = false, const std::string& Comment = "");
		ImeitemIMQuery(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		Sbecore::ubigint iref;
		std::string srefIxVBasetype;
		Sbecore::ubigint irefSupRefWznmMQuery;
		std::string srefSupIxVSubrole;

		ImeIAMQueryClause imeiamqueryclause;
		ImeIAMQueryOrder imeiamqueryorder;
		ImeIMQuerycol imeimquerycol;
		ImeIMQuerymod imeimquerymod;
		ImeIRMQueryMTable imeirmquerymtable;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMQuery (full: ImeIWznmUixMQuery)
		*/
	class ImeIMQuery {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixMQueryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint IREF = 2;
			static const Sbecore::uint SREFIXVBASETYPE = 4;
			static const Sbecore::uint IREFSUPREFWZNMMQUERY = 8;
			static const Sbecore::uint SREFSUPIXVSUBROLE = 16;
			static const Sbecore::uint SREF = 32;
			static const Sbecore::uint LIMOFS = 64;
			static const Sbecore::uint COMMENT = 128;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMQuery();
		~ImeIMQuery();

	public:
		std::vector<ImeitemIMQuery*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMPanelMQuery (full: ImeitemIWznmUixRMPanelMQuery)
		*/
	class ImeitemIRMPanelMQuery : public WznmRMPanelMQuery {

	public:
		ImeitemIRMPanelMQuery(const std::string& srefRefWznmMPanel = "", const std::string& srefRefWznmMQuery = "");
		ImeitemIRMPanelMQuery(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMPanel;
		std::string srefRefWznmMQuery;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMPanelMQuery (full: ImeIWznmUixRMPanelMQuery)
		*/
	class ImeIRMPanelMQuery {

	public:
		/**
			* VecWIel (full: VecWImeIWznmUixRMPanelMQueryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMPANEL = 1;
			static const Sbecore::uint SREFREFWZNMMQUERY = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMPanelMQuery();
		~ImeIRMPanelMQuery();

	public:
		std::vector<ImeitemIRMPanelMQuery*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMCard& imeimcard, ImeIMPreset& imeimpreset, ImeIMQuery& imeimquery, ImeIRMPanelMQuery& imeirmpanelmquery);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMCard& imeimcard, ImeIMPreset& imeimpreset, ImeIMQuery& imeimquery, ImeIRMPanelMQuery& imeirmpanelmquery);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMCard& imeimcard, ImeIMPreset& imeimpreset, ImeIMQuery& imeimquery, ImeIRMPanelMQuery& imeirmpanelmquery);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMCard& imeimcard, ImeIMPreset& imeimpreset, ImeIMQuery& imeimquery, ImeIRMPanelMQuery& imeirmpanelmquery);

	void writeTxt(std::fstream& outfile, ImeIMCard& imeimcard, ImeIMPreset& imeimpreset, ImeIMQuery& imeimquery, ImeIRMPanelMQuery& imeirmpanelmquery);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMCard& imeimcard, ImeIMPreset& imeimpreset, ImeIMQuery& imeimquery, ImeIRMPanelMQuery& imeirmpanelmquery);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif



