/**
	* \file IexWznmJtr.h
	* data blocks and readers/writers for import/export complex IexWznmJtr (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWZNMJTR_H
#define IEXWZNMJTR_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmJtrIme IexWznmJtr::VecVIme

#define ImeitemIWznmJtrJAMBlockItem2 IexWznmJtr::ImeitemIJAMBlockItem2
#define ImeIWznmJtrJAMBlockItem2 IexWznmJtr::ImeIJAMBlockItem2
#define VecWImeIWznmJtrJAMBlockItem2Iel IexWznmJtr::ImeIJAMBlockItem2::VecWIel

#define ImeitemIWznmJtrAMBlockItem2 IexWznmJtr::ImeitemIAMBlockItem2
#define ImeIWznmJtrAMBlockItem2 IexWznmJtr::ImeIAMBlockItem2
#define VecWImeIWznmJtrAMBlockItem2Iel IexWznmJtr::ImeIAMBlockItem2::VecWIel

#define ImeitemIWznmJtrCAMBlockItem2 IexWznmJtr::ImeitemICAMBlockItem2
#define ImeIWznmJtrCAMBlockItem2 IexWznmJtr::ImeICAMBlockItem2
#define VecWImeIWznmJtrCAMBlockItem2Iel IexWznmJtr::ImeICAMBlockItem2::VecWIel

#define ImeitemIWznmJtrMBlock2 IexWznmJtr::ImeitemIMBlock2
#define ImeIWznmJtrMBlock2 IexWznmJtr::ImeIMBlock2
#define VecWImeIWznmJtrMBlock2Iel IexWznmJtr::ImeIMBlock2::VecWIel

#define ImeitemIWznmJtrMCall IexWznmJtr::ImeitemIMCall
#define ImeIWznmJtrMCall IexWznmJtr::ImeIMCall
#define VecWImeIWznmJtrMCallIel IexWznmJtr::ImeIMCall::VecWIel

#define ImeitemIWznmJtrAMJobCmd IexWznmJtr::ImeitemIAMJobCmd
#define ImeIWznmJtrAMJobCmd IexWznmJtr::ImeIAMJobCmd
#define VecWImeIWznmJtrAMJobCmdIel IexWznmJtr::ImeIAMJobCmd::VecWIel

#define ImeitemIWznmJtrAMJobVar IexWznmJtr::ImeitemIAMJobVar
#define ImeIWznmJtrAMJobVar IexWznmJtr::ImeIAMJobVar
#define VecWImeIWznmJtrAMJobVarIel IexWznmJtr::ImeIAMJobVar::VecWIel

#define ImeitemIWznmJtrCAMJobVar IexWznmJtr::ImeitemICAMJobVar
#define ImeIWznmJtrCAMJobVar IexWznmJtr::ImeICAMJobVar
#define VecWImeIWznmJtrCAMJobVarIel IexWznmJtr::ImeICAMJobVar::VecWIel

#define ImeitemIWznmJtrJAMBlockItem1 IexWznmJtr::ImeitemIJAMBlockItem1
#define ImeIWznmJtrJAMBlockItem1 IexWznmJtr::ImeIJAMBlockItem1
#define VecWImeIWznmJtrJAMBlockItem1Iel IexWznmJtr::ImeIJAMBlockItem1::VecWIel

#define ImeitemIWznmJtrAMBlockItem1 IexWznmJtr::ImeitemIAMBlockItem1
#define ImeIWznmJtrAMBlockItem1 IexWznmJtr::ImeIAMBlockItem1
#define VecWImeIWznmJtrAMBlockItem1Iel IexWznmJtr::ImeIAMBlockItem1::VecWIel

#define ImeitemIWznmJtrCAMBlockItem1 IexWznmJtr::ImeitemICAMBlockItem1
#define ImeIWznmJtrCAMBlockItem1 IexWznmJtr::ImeICAMBlockItem1
#define VecWImeIWznmJtrCAMBlockItem1Iel IexWznmJtr::ImeICAMBlockItem1::VecWIel

#define ImeitemIWznmJtrMBlock1 IexWznmJtr::ImeitemIMBlock1
#define ImeIWznmJtrMBlock1 IexWznmJtr::ImeIMBlock1
#define VecWImeIWznmJtrMBlock1Iel IexWznmJtr::ImeIMBlock1::VecWIel

#define ImeitemIWznmJtrAMMethodInvpar IexWznmJtr::ImeitemIAMMethodInvpar
#define ImeIWznmJtrAMMethodInvpar IexWznmJtr::ImeIAMMethodInvpar
#define VecWImeIWznmJtrAMMethodInvparIel IexWznmJtr::ImeIAMMethodInvpar::VecWIel

#define ImeitemIWznmJtrAMMethodRetpar IexWznmJtr::ImeitemIAMMethodRetpar
#define ImeIWznmJtrAMMethodRetpar IexWznmJtr::ImeIAMMethodRetpar
#define VecWImeIWznmJtrAMMethodRetparIel IexWznmJtr::ImeIAMMethodRetpar::VecWIel

#define ImeitemIWznmJtrMMethod IexWznmJtr::ImeitemIMMethod
#define ImeIWznmJtrMMethod IexWznmJtr::ImeIMMethod
#define VecWImeIWznmJtrMMethodIel IexWznmJtr::ImeIMMethod::VecWIel

#define ImeitemIWznmJtrMSensitivity1 IexWznmJtr::ImeitemIMSensitivity1
#define ImeIWznmJtrMSensitivity1 IexWznmJtr::ImeIMSensitivity1
#define VecWImeIWznmJtrMSensitivity1Iel IexWznmJtr::ImeIMSensitivity1::VecWIel

#define ImeitemIWznmJtrMSensitivity2 IexWznmJtr::ImeitemIMSensitivity2
#define ImeIWznmJtrMSensitivity2 IexWznmJtr::ImeIMSensitivity2
#define VecWImeIWznmJtrMSensitivity2Iel IexWznmJtr::ImeIMSensitivity2::VecWIel

#define ImeitemIWznmJtrJMSquawkTitle IexWznmJtr::ImeitemIJMSquawkTitle
#define ImeIWznmJtrJMSquawkTitle IexWznmJtr::ImeIJMSquawkTitle
#define VecWImeIWznmJtrJMSquawkTitleIel IexWznmJtr::ImeIJMSquawkTitle::VecWIel

#define ImeitemIWznmJtrRMSquawkMStub IexWznmJtr::ImeitemIRMSquawkMStub
#define ImeIWznmJtrRMSquawkMStub IexWznmJtr::ImeIRMSquawkMStub
#define VecWImeIWznmJtrRMSquawkMStubIel IexWznmJtr::ImeIRMSquawkMStub::VecWIel

#define ImeitemIWznmJtrMSquawk IexWznmJtr::ImeitemIMSquawk
#define ImeIWznmJtrMSquawk IexWznmJtr::ImeIMSquawk
#define VecWImeIWznmJtrMSquawkIel IexWznmJtr::ImeIMSquawk::VecWIel

#define ImeitemIWznmJtrMStage IexWznmJtr::ImeitemIMStage
#define ImeIWznmJtrMStage IexWznmJtr::ImeIMStage
#define VecWImeIWznmJtrMStageIel IexWznmJtr::ImeIMStage::VecWIel

#define ImeitemIWznmJtrJMVectoritem IexWznmJtr::ImeitemIJMVectoritem
#define ImeIWznmJtrJMVectoritem IexWznmJtr::ImeIJMVectoritem
#define VecWImeIWznmJtrJMVectoritemIel IexWznmJtr::ImeIJMVectoritem::VecWIel

#define ImeitemIWznmJtrMVectoritem IexWznmJtr::ImeitemIMVectoritem
#define ImeIWznmJtrMVectoritem IexWznmJtr::ImeIMVectoritem
#define VecWImeIWznmJtrMVectoritemIel IexWznmJtr::ImeIMVectoritem::VecWIel

#define ImeitemIWznmJtrMVector IexWznmJtr::ImeitemIMVector
#define ImeIWznmJtrMVector IexWznmJtr::ImeIMVector
#define VecWImeIWznmJtrMVectorIel IexWznmJtr::ImeIMVector::VecWIel

#define ImeitemIWznmJtrRMJobMJob IexWznmJtr::ImeitemIRMJobMJob
#define ImeIWznmJtrRMJobMJob IexWznmJtr::ImeIRMJobMJob
#define VecWImeIWznmJtrRMJobMJobIel IexWznmJtr::ImeIRMJobMJob::VecWIel

#define ImeitemIWznmJtrRMJobMOp IexWznmJtr::ImeitemIRMJobMOp
#define ImeIWznmJtrRMJobMOp IexWznmJtr::ImeIRMJobMOp
#define VecWImeIWznmJtrRMJobMOpIel IexWznmJtr::ImeIRMJobMOp::VecWIel

#define ImeitemIWznmJtrRMJobMOppack IexWznmJtr::ImeitemIRMJobMOppack
#define ImeIWznmJtrRMJobMOppack IexWznmJtr::ImeIRMJobMOppack
#define VecWImeIWznmJtrRMJobMOppackIel IexWznmJtr::ImeIRMJobMOppack::VecWIel

#define ImeitemIWznmJtrMJob IexWznmJtr::ImeitemIMJob
#define ImeIWznmJtrMJob IexWznmJtr::ImeIMJob
#define VecWImeIWznmJtrMJobIel IexWznmJtr::ImeIMJob::VecWIel

#define ImeitemIWznmJtrRMCallMStub IexWznmJtr::ImeitemIRMCallMStub
#define ImeIWznmJtrRMCallMStub IexWznmJtr::ImeIRMCallMStub
#define VecWImeIWznmJtrRMCallMStubIel IexWznmJtr::ImeIRMCallMStub::VecWIel

/**
	* IexWznmJtr
	*/
namespace IexWznmJtr {
	/**
		* VecVIme (full: VecVIexWznmJtrIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMBLOCKITEM1 = 1;
		static const Sbecore::uint IMEIAMBLOCKITEM2 = 2;
		static const Sbecore::uint IMEIAMJOBCMD = 3;
		static const Sbecore::uint IMEIAMJOBVAR = 4;
		static const Sbecore::uint IMEIAMMETHODINVPAR = 5;
		static const Sbecore::uint IMEIAMMETHODRETPAR = 6;
		static const Sbecore::uint IMEICAMBLOCKITEM1 = 7;
		static const Sbecore::uint IMEICAMBLOCKITEM2 = 8;
		static const Sbecore::uint IMEICAMJOBVAR = 9;
		static const Sbecore::uint IMEIJAMBLOCKITEM1 = 10;
		static const Sbecore::uint IMEIJAMBLOCKITEM2 = 11;
		static const Sbecore::uint IMEIJMSQUAWKTITLE = 12;
		static const Sbecore::uint IMEIJMVECTORITEM = 13;
		static const Sbecore::uint IMEIMBLOCK1 = 14;
		static const Sbecore::uint IMEIMBLOCK2 = 15;
		static const Sbecore::uint IMEIMCALL = 16;
		static const Sbecore::uint IMEIMJOB = 17;
		static const Sbecore::uint IMEIMMETHOD = 18;
		static const Sbecore::uint IMEIMSENSITIVITY1 = 19;
		static const Sbecore::uint IMEIMSENSITIVITY2 = 20;
		static const Sbecore::uint IMEIMSQUAWK = 21;
		static const Sbecore::uint IMEIMSTAGE = 22;
		static const Sbecore::uint IMEIMVECTOR = 23;
		static const Sbecore::uint IMEIMVECTORITEM = 24;
		static const Sbecore::uint IMEIRMCALLMSTUB = 25;
		static const Sbecore::uint IMEIRMJOBMJOB = 26;
		static const Sbecore::uint IMEIRMJOBMOP = 27;
		static const Sbecore::uint IMEIRMJOBMOPPACK = 28;
		static const Sbecore::uint IMEIRMSQUAWKMSTUB = 29;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIJAMBlockItem2 (full: ImeitemIWznmJtrJAMBlockItem2)
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
		* ImeIJAMBlockItem2 (full: ImeIWznmJtrJAMBlockItem2)
		*/
	class ImeIJAMBlockItem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrJAMBlockItem2Iel)
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
		* ImeitemIAMBlockItem2 (full: ImeitemIWznmJtrAMBlockItem2)
		*/
	class ImeitemIAMBlockItem2 : public WznmAMBlockItem {

	public:
		ImeitemIAMBlockItem2(const Sbecore::uint ixWznmVIop = 0, const Sbecore::ubigint irefRefWznmCAMBlockItem = 0, const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMBlockItem2(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		Sbecore::ubigint irefRefWznmCAMBlockItem;
		std::string srefIxVBasetype;
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
		* ImeIAMBlockItem2 (full: ImeIWznmJtrAMBlockItem2)
		*/
	class ImeIAMBlockItem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrAMBlockItem2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint IREFREFWZNMCAMBLOCKITEM = 2;
			static const Sbecore::uint SREFIXVBASETYPE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 16;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 32;
			static const Sbecore::uint DEFVAL = 64;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 128;
			static const Sbecore::uint COMMENT = 256;

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
		* ImeitemICAMBlockItem2 (full: ImeitemIWznmJtrCAMBlockItem2)
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
		* ImeICAMBlockItem2 (full: ImeIWznmJtrCAMBlockItem2)
		*/
	class ImeICAMBlockItem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrCAMBlockItem2Iel)
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
		* ImeitemIMBlock2 (full: ImeitemIWznmJtrMBlock2)
		*/
	class ImeitemIMBlock2 : public WznmMBlock {

	public:
		ImeitemIMBlock2(const std::string& sref = "");
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
		* ImeIMBlock2 (full: ImeIWznmJtrMBlock2)
		*/
	class ImeIMBlock2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMBlock2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;

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
		* ImeitemIMCall (full: ImeitemIWznmJtrMCall)
		*/
	class ImeitemIMCall : public WznmMCall {

	public:
		ImeitemIMCall(const Sbecore::uint ixVBasetype = 0, const Sbecore::uint invIxWznmWArgtype = 0, const Sbecore::uint retIxWznmWArgtype = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMCall(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefsInvIxWznmWArgtype;
		std::string srefsRetIxWznmWArgtype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCall (full: ImeIWznmJtrMCall)
		*/
	class ImeIMCall {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMCallIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFSINVIXWZNMWARGTYPE = 2;
			static const Sbecore::uint SREFSRETIXWZNMWARGTYPE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCall();
		~ImeIMCall();

	public:
		std::vector<ImeitemIMCall*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMJobCmd (full: ImeitemIWznmJtrAMJobCmd)
		*/
	class ImeitemIAMJobCmd : public WznmAMJobCmd {

	public:
		ImeitemIAMJobCmd(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIAMJobCmd(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIAMJobCmd (full: ImeIWznmJtrAMJobCmd)
		*/
	class ImeIAMJobCmd {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrAMJobCmdIel)
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
		ImeIAMJobCmd();
		~ImeIAMJobCmd();

	public:
		std::vector<ImeitemIAMJobCmd*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMJobVar (full: ImeitemIWznmJtrAMJobVar)
		*/
	class ImeitemIAMJobVar : public WznmAMJobVar {

	public:
		ImeitemIAMJobVar(const Sbecore::ubigint irefRefWznmCAMJobVar = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const Sbecore::uint Length = 0, const bool Shr = false, const std::string& Comment = "");
		ImeitemIAMJobVar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWznmCAMJobVar;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMJobVar (full: ImeIWznmJtrAMJobVar)
		*/
	class ImeIAMJobVar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrAMJobVarIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWZNMCAMJOBVAR = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint LENGTH = 16;
			static const Sbecore::uint SHR = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMJobVar();
		~ImeIAMJobVar();

	public:
		std::vector<ImeitemIAMJobVar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICAMJobVar (full: ImeitemIWznmJtrCAMJobVar)
		*/
	class ImeitemICAMJobVar {

	public:
		ImeitemICAMJobVar(const Sbecore::ubigint iref = 0);
		ImeitemICAMJobVar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeICAMJobVar (full: ImeIWznmJtrCAMJobVar)
		*/
	class ImeICAMJobVar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrCAMJobVarIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICAMJobVar();
		~ImeICAMJobVar();

	public:
		std::vector<ImeitemICAMJobVar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAMBlockItem1 (full: ImeitemIWznmJtrJAMBlockItem1)
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
		* ImeIJAMBlockItem1 (full: ImeIWznmJtrJAMBlockItem1)
		*/
	class ImeIJAMBlockItem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrJAMBlockItem1Iel)
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
		* ImeitemIAMBlockItem1 (full: ImeitemIWznmJtrAMBlockItem1)
		*/
	class ImeitemIAMBlockItem1 : public WznmAMBlockItem {

	public:
		ImeitemIAMBlockItem1(const Sbecore::uint ixWznmVIop = 0, const Sbecore::ubigint irefRefWznmCAMBlockItem = 0, const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMControl = "", const std::string& srefRefWznmMVector = "", const std::string& srefRefWznmMFeed = "", const std::string& srefRefWznmMTable = "", const std::string& srefRefWznmMBlock = "", const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMBlockItem1(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		Sbecore::ubigint irefRefWznmCAMBlockItem;
		std::string srefIxVBasetype;
		std::string srefIxWznmVVartype;
		std::string srefRefWznmMControl;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMFeed;
		std::string srefRefWznmMTable;
		std::string srefRefWznmMBlock;
		std::string srefRefWznmMVectoritem;

		ImeIJAMBlockItem1 imeijamblockitem1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMBlockItem1 (full: ImeIWznmJtrAMBlockItem1)
		*/
	class ImeIAMBlockItem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrAMBlockItem1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint IREFREFWZNMCAMBLOCKITEM = 2;
			static const Sbecore::uint SREFIXVBASETYPE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 16;
			static const Sbecore::uint SREFREFWZNMMCONTROL = 32;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 64;
			static const Sbecore::uint SREFREFWZNMMFEED = 128;
			static const Sbecore::uint SREFREFWZNMMTABLE = 256;
			static const Sbecore::uint SREFREFWZNMMBLOCK = 512;
			static const Sbecore::uint DEFVAL = 1024;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 2048;
			static const Sbecore::uint COMMENT = 4096;

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
		* ImeitemICAMBlockItem1 (full: ImeitemIWznmJtrCAMBlockItem1)
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
		* ImeICAMBlockItem1 (full: ImeIWznmJtrCAMBlockItem1)
		*/
	class ImeICAMBlockItem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrCAMBlockItem1Iel)
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
		* ImeitemIMBlock1 (full: ImeitemIWznmJtrMBlock1)
		*/
	class ImeitemIMBlock1 : public WznmMBlock {

	public:
		ImeitemIMBlock1(const Sbecore::uint ixWznmVIop = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint reaIxWznmWScope = 0, const Sbecore::uint wriIxWznmWScope = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMBlock1(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefIxVBasetype;
		std::string srefsReaIxWznmWScope;
		std::string srefsWriIxWznmWScope;

		ImeIAMBlockItem1 imeiamblockitem1;
		ImeICAMBlockItem1 imeicamblockitem1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBlock1 (full: ImeIWznmJtrMBlock1)
		*/
	class ImeIMBlock1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMBlock1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint SREFSREAIXWZNMWSCOPE = 4;
			static const Sbecore::uint SREFSWRIIXWZNMWSCOPE = 8;
			static const Sbecore::uint SREF = 16;
			static const Sbecore::uint COMMENT = 32;

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
		* ImeitemIAMMethodInvpar (full: ImeitemIWznmJtrAMMethodInvpar)
		*/
	class ImeitemIAMMethodInvpar : public WznmAMMethodInvpar {

	public:
		ImeitemIAMMethodInvpar(const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string& Comment = "");
		ImeitemIAMMethodInvpar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMethodInvpar (full: ImeIWznmJtrAMMethodInvpar)
		*/
	class ImeIAMMethodInvpar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrAMMethodInvparIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 2;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 4;
			static const Sbecore::uint LENGTH = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMMethodInvpar();
		~ImeIAMMethodInvpar();

	public:
		std::vector<ImeitemIAMMethodInvpar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMMethodRetpar (full: ImeitemIWznmJtrAMMethodRetpar)
		*/
	class ImeitemIAMMethodRetpar : public WznmAMMethodRetpar {

	public:
		ImeitemIAMMethodRetpar(const std::string& sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string& srefRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string& Comment = "");
		ImeitemIAMMethodRetpar(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWznmVVartype;
		std::string srefRefWznmMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMethodRetpar (full: ImeIWznmJtrAMMethodRetpar)
		*/
	class ImeIAMMethodRetpar {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrAMMethodRetparIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXWZNMVVARTYPE = 2;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 4;
			static const Sbecore::uint LENGTH = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMMethodRetpar();
		~ImeIAMMethodRetpar();

	public:
		std::vector<ImeitemIAMMethodRetpar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMMethod (full: ImeitemIWznmJtrMMethod)
		*/
	class ImeitemIMMethod : public WznmMMethod {

	public:
		ImeitemIMMethod(const std::string& sref = "", const bool Execsrv = false, const std::string& Comment = "");
		ImeitemIMMethod(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMMethodInvpar imeiammethodinvpar;
		ImeIAMMethodRetpar imeiammethodretpar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMMethod (full: ImeIWznmJtrMMethod)
		*/
	class ImeIMMethod {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMMethodIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint EXECSRV = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMMethod();
		~ImeIMMethod();

	public:
		std::vector<ImeitemIMMethod*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSensitivity1 (full: ImeitemIWznmJtrMSensitivity1)
		*/
	class ImeitemIMSensitivity1 : public WznmMSensitivity {

	public:
		ImeitemIMSensitivity1(const Sbecore::uint ixVBasetype = 0, const std::string& srefRefWznmMCall = "", const Sbecore::uint ixVJactype = 0, const Sbecore::uint ixVJobmask = 0, const std::string& Jobshort = "", const std::string& Argpatt = "", const std::string& srefRefWznmMControl = "", const std::string& Srefmask = "", const Sbecore::uint ixVAction = 0, const std::string& srefCsgRefWznmMStage = "", const bool Custcode = false);
		ImeitemIMSensitivity1(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefWznmMCall;
		std::string srefIxVJactype;
		std::string srefIxVJobmask;
		std::string srefRefWznmMControl;
		std::string srefIxVAction;
		std::string srefCsgRefWznmMStage;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSensitivity1 (full: ImeIWznmJtrMSensitivity1)
		*/
	class ImeIMSensitivity1 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMSensitivity1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFWZNMMCALL = 2;
			static const Sbecore::uint SREFIXVJACTYPE = 4;
			static const Sbecore::uint SREFIXVJOBMASK = 8;
			static const Sbecore::uint JOBSHORT = 16;
			static const Sbecore::uint ARGPATT = 32;
			static const Sbecore::uint SREFREFWZNMMCONTROL = 64;
			static const Sbecore::uint SREFMASK = 128;
			static const Sbecore::uint SREFIXVACTION = 256;
			static const Sbecore::uint SREFCSGREFWZNMMSTAGE = 512;
			static const Sbecore::uint CUSTCODE = 1024;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSensitivity1();
		~ImeIMSensitivity1();

	public:
		std::vector<ImeitemIMSensitivity1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSensitivity2 (full: ImeitemIWznmJtrMSensitivity2)
		*/
	class ImeitemIMSensitivity2 : public WznmMSensitivity {

	public:
		ImeitemIMSensitivity2(const Sbecore::uint ixVBasetype = 0, const std::string& srefRefWznmMCall = "", const Sbecore::uint ixVJactype = 0, const Sbecore::uint ixVJobmask = 0, const std::string& Jobshort = "", const std::string& Argpatt = "", const std::string& srefRefWznmMControl = "", const std::string& Srefmask = "", const Sbecore::uint ixVAction = 0, const std::string& srefCsgRefWznmMStage = "", const bool Custcode = false);
		ImeitemIMSensitivity2(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefWznmMCall;
		std::string srefIxVJactype;
		std::string srefIxVJobmask;
		std::string srefRefWznmMControl;
		std::string srefIxVAction;
		std::string srefCsgRefWznmMStage;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSensitivity2 (full: ImeIWznmJtrMSensitivity2)
		*/
	class ImeIMSensitivity2 {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMSensitivity2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFWZNMMCALL = 2;
			static const Sbecore::uint SREFIXVJACTYPE = 4;
			static const Sbecore::uint SREFIXVJOBMASK = 8;
			static const Sbecore::uint JOBSHORT = 16;
			static const Sbecore::uint ARGPATT = 32;
			static const Sbecore::uint SREFREFWZNMMCONTROL = 64;
			static const Sbecore::uint SREFMASK = 128;
			static const Sbecore::uint SREFIXVACTION = 256;
			static const Sbecore::uint SREFCSGREFWZNMMSTAGE = 512;
			static const Sbecore::uint CUSTCODE = 1024;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSensitivity2();
		~ImeIMSensitivity2();

	public:
		std::vector<ImeitemIMSensitivity2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMSquawkTitle (full: ImeitemIWznmJtrJMSquawkTitle)
		*/
	class ImeitemIJMSquawkTitle : public WznmJMSquawkTitle {

	public:
		ImeitemIJMSquawkTitle(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMSquawkTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMSquawkTitle (full: ImeIWznmJtrJMSquawkTitle)
		*/
	class ImeIJMSquawkTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrJMSquawkTitleIel)
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
		ImeIJMSquawkTitle();
		~ImeIJMSquawkTitle();

	public:
		std::vector<ImeitemIJMSquawkTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMSquawkMStub (full: ImeitemIWznmJtrRMSquawkMStub)
		*/
	class ImeitemIRMSquawkMStub : public WznmRMSquawkMStub {

	public:
		ImeitemIRMSquawkMStub(const std::string& srefRefWznmMStub = "");
		ImeitemIRMSquawkMStub(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIRMSquawkMStub (full: ImeIWznmJtrRMSquawkMStub)
		*/
	class ImeIRMSquawkMStub {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrRMSquawkMStubIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMSTUB = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMSquawkMStub();
		~ImeIRMSquawkMStub();

	public:
		std::vector<ImeitemIRMSquawkMStub*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSquawk (full: ImeitemIWznmJtrMSquawk)
		*/
	class ImeitemIMSquawk : public WznmMSquawk {

	public:
		ImeitemIMSquawk(const std::string& Title = "", const std::string& Example = "");
		ImeitemIMSquawk(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMSquawkTitle imeijmsquawktitle;
		ImeIRMSquawkMStub imeirmsquawkmstub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSquawk (full: ImeIWznmJtrMSquawk)
		*/
	class ImeIMSquawk {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMSquawkIel)
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
		ImeIMSquawk();
		~ImeIMSquawk();

	public:
		std::vector<ImeitemIMSquawk*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMStage (full: ImeitemIWznmJtrMStage)
		*/
	class ImeitemIMStage : public WznmMStage {

	public:
		ImeitemIMStage(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const Sbecore::uint Monitvl = 0, const std::string& srefSnxRefWznmMStage = "", const std::string& srefFnxRefWznmMStage = "", const std::string& srefEnxRefWznmMStage = "", const std::string& Comment = "");
		ImeitemIMStage(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefSnxRefWznmMStage;
		std::string srefFnxRefWznmMStage;
		std::string srefEnxRefWznmMStage;

		ImeIMSensitivity2 imeimsensitivity2;
		ImeIMSquawk imeimsquawk;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMStage (full: ImeIWznmJtrMStage)
		*/
	class ImeIMStage {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMStageIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint MONITVL = 4;
			static const Sbecore::uint SREFSNXREFWZNMMSTAGE = 8;
			static const Sbecore::uint SREFFNXREFWZNMMSTAGE = 16;
			static const Sbecore::uint SREFENXREFWZNMMSTAGE = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMStage();
		~ImeIMStage();

	public:
		std::vector<ImeitemIMStage*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMVectoritem (full: ImeitemIWznmJtrJMVectoritem)
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
		* ImeIJMVectoritem (full: ImeIWznmJtrJMVectoritem)
		*/
	class ImeIJMVectoritem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrJMVectoritemIel)
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
		* ImeitemIMVectoritem (full: ImeitemIWznmJtrMVectoritem)
		*/
	class ImeitemIMVectoritem : public WznmMVectoritem {

	public:
		ImeitemIMVectoritem(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
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
		* ImeIMVectoritem (full: ImeIWznmJtrMVectoritem)
		*/
	class ImeIMVectoritem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMVectoritemIel)
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
		* ImeitemIMVector (full: ImeitemIWznmJtrMVector)
		*/
	class ImeitemIMVector : public WznmMVector {

	public:
		ImeitemIMVector(const Sbecore::uint ixWznmVIop = 0, const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& osrefWznmKTaggrp = "", const std::string& srefsKOption = "");
		ImeitemIMVector(DbsWznm* dbswznm, const Sbecore::uint ixWznmVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWznmVIop;
		std::string srefIxWznmVIop;
		std::string srefIxVBasetype;

		ImeIMVectoritem imeimvectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector (full: ImeIWznmJtrMVector)
		*/
	class ImeIMVector {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMVectorIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZNMVIOP = 1;
			static const Sbecore::uint SREFIXVBASETYPE = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint OSREFWZNMKTAGGRP = 8;
			static const Sbecore::uint SREFSKOPTION = 16;

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

	/**
		* ImeitemIRMJobMJob (full: ImeitemIWznmJtrRMJobMJob)
		*/
	class ImeitemIRMJobMJob : public WznmRMJobMJob {

	public:
		ImeitemIRMJobMJob(const std::string& srefSubRefWznmMJob = "", const std::string& Short = "", const bool Multi = false, const Sbecore::uint ixVConstract = 0);
		ImeitemIRMJobMJob(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSubRefWznmMJob;
		std::string srefIxVConstract;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMJobMJob (full: ImeIWznmJtrRMJobMJob)
		*/
	class ImeIRMJobMJob {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrRMJobMJobIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSUBREFWZNMMJOB = 1;
			static const Sbecore::uint SHORT = 2;
			static const Sbecore::uint MULTI = 4;
			static const Sbecore::uint SREFIXVCONSTRACT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMJobMJob();
		~ImeIRMJobMJob();

	public:
		std::vector<ImeitemIRMJobMJob*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMJobMOp (full: ImeitemIWznmJtrRMJobMOp)
		*/
	class ImeitemIRMJobMOp : public WznmRMJobMOp {

	public:
		ImeitemIRMJobMOp(const std::string& srefRefWznmMOp = "");
		ImeitemIRMJobMOp(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMOp;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMJobMOp (full: ImeIWznmJtrRMJobMOp)
		*/
	class ImeIRMJobMOp {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrRMJobMOpIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMOP = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMJobMOp();
		~ImeIRMJobMOp();

	public:
		std::vector<ImeitemIRMJobMOp*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMJobMOppack (full: ImeitemIWznmJtrRMJobMOppack)
		*/
	class ImeitemIRMJobMOppack : public WznmRMJobMOppack {

	public:
		ImeitemIRMJobMOppack(const std::string& srefRefWznmMOppack = "");
		ImeitemIRMJobMOppack(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMOppack;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMJobMOppack (full: ImeIWznmJtrRMJobMOppack)
		*/
	class ImeIRMJobMOppack {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrRMJobMOppackIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMOPPACK = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMJobMOppack();
		~ImeIRMJobMOppack();

	public:
		std::vector<ImeitemIRMJobMOppack*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMJob (full: ImeitemIWznmJtrMJob)
		*/
	class ImeitemIMJob : public WznmMJob {

	public:
		ImeitemIMJob(const std::string& sref = "");
		ImeitemIMJob(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMJobCmd imeiamjobcmd;
		ImeIAMJobVar imeiamjobvar;
		ImeICAMJobVar imeicamjobvar;
		ImeIMBlock1 imeimblock1;
		ImeIMMethod imeimmethod;
		ImeIMSensitivity1 imeimsensitivity1;
		ImeIMStage imeimstage;
		ImeIMVector imeimvector;
		ImeIRMJobMJob imeirmjobmjob;
		ImeIRMJobMOp imeirmjobmop;
		ImeIRMJobMOppack imeirmjobmoppack;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMJob (full: ImeIWznmJtrMJob)
		*/
	class ImeIMJob {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrMJobIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMJob();
		~ImeIMJob();

	public:
		std::vector<ImeitemIMJob*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMCallMStub (full: ImeitemIWznmJtrRMCallMStub)
		*/
	class ImeitemIRMCallMStub : public WznmRMCallMStub {

	public:
		ImeitemIRMCallMStub(const std::string& srefRefWznmMCall = "", const std::string& srefRefWznmMStub = "");
		ImeitemIRMCallMStub(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMCall;
		std::string srefRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCallMStub (full: ImeIWznmJtrRMCallMStub)
		*/
	class ImeIRMCallMStub {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJtrRMCallMStubIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMCALL = 1;
			static const Sbecore::uint SREFREFWZNMMSTUB = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMCallMStub();
		~ImeIRMCallMStub();

	public:
		std::vector<ImeitemIRMCallMStub*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMBlock2& imeimblock2, ImeIMCall& imeimcall, ImeIMJob& imeimjob, ImeIRMCallMStub& imeirmcallmstub);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMBlock2& imeimblock2, ImeIMCall& imeimcall, ImeIMJob& imeimjob, ImeIRMCallMStub& imeirmcallmstub);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMBlock2& imeimblock2, ImeIMCall& imeimcall, ImeIMJob& imeimjob, ImeIRMCallMStub& imeirmcallmstub);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMBlock2& imeimblock2, ImeIMCall& imeimcall, ImeIMJob& imeimjob, ImeIRMCallMStub& imeirmcallmstub);

	void writeTxt(std::fstream& outfile, ImeIMBlock2& imeimblock2, ImeIMCall& imeimcall, ImeIMJob& imeimjob, ImeIRMCallMStub& imeirmcallmstub);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMBlock2& imeimblock2, ImeIMCall& imeimcall, ImeIMJob& imeimjob, ImeIRMCallMStub& imeirmcallmstub);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif



