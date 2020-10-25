/**
	* \file IexWznmApp.h
	* data blocks and readers/writers for import/export complex IexWznmApp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef IEXWZNMAPP_H
#define IEXWZNMAPP_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmAppIme IexWznmApp::VecVIme

#define ImeitemIWznmAppMEvent IexWznmApp::ImeitemIMEvent
#define ImeIWznmAppMEvent IexWznmApp::ImeIMEvent
#define VecWImeIWznmAppMEventIel IexWznmApp::ImeIMEvent::VecWIel

#define ImeitemIWznmAppMRtblock IexWznmApp::ImeitemIMRtblock
#define ImeIWznmAppMRtblock IexWznmApp::ImeIMRtblock
#define VecWImeIWznmAppMRtblockIel IexWznmApp::ImeIMRtblock::VecWIel

#define ImeitemIWznmAppMRtdpch IexWznmApp::ImeitemIMRtdpch
#define ImeIWznmAppMRtdpch IexWznmApp::ImeIMRtdpch
#define VecWImeIWznmAppMRtdpchIel IexWznmApp::ImeIMRtdpch::VecWIel

#define ImeitemIWznmAppMRtjob IexWznmApp::ImeitemIMRtjob
#define ImeIWznmAppMRtjob IexWznmApp::ImeIMRtjob
#define VecWImeIWznmAppMRtjobIel IexWznmApp::ImeIMRtjob::VecWIel

#define ImeitemIWznmAppAMStateAction IexWznmApp::ImeitemIAMStateAction
#define ImeIWznmAppAMStateAction IexWznmApp::ImeIAMStateAction
#define VecWImeIWznmAppAMStateActionIel IexWznmApp::ImeIAMStateAction::VecWIel

#define ImeitemIWznmAppJAMStateTrigCond IexWznmApp::ImeitemIJAMStateTrigCond
#define ImeIWznmAppJAMStateTrigCond IexWznmApp::ImeIJAMStateTrigCond
#define VecWImeIWznmAppJAMStateTrigCondIel IexWznmApp::ImeIJAMStateTrigCond::VecWIel

#define ImeitemIWznmAppAMStateTrig IexWznmApp::ImeitemIAMStateTrig
#define ImeIWznmAppAMStateTrig IexWznmApp::ImeIAMStateTrig
#define VecWImeIWznmAppAMStateTrigIel IexWznmApp::ImeIAMStateTrig::VecWIel

#define ImeitemIWznmAppMState IexWznmApp::ImeitemIMState
#define ImeIWznmAppMState IexWznmApp::ImeIMState
#define VecWImeIWznmAppMStateIel IexWznmApp::ImeIMState::VecWIel

#define ImeitemIWznmAppMSequence IexWznmApp::ImeitemIMSequence
#define ImeIWznmAppMSequence IexWznmApp::ImeIMSequence
#define VecWImeIWznmAppMSequenceIel IexWznmApp::ImeIMSequence::VecWIel

/**
	* IexWznmApp
	*/
namespace IexWznmApp {
	/**
		* VecVIme (full: VecVIexWznmAppIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMSTATEACTION = 1;
		static const Sbecore::uint IMEIAMSTATETRIG = 2;
		static const Sbecore::uint IMEIJAMSTATETRIGCOND = 3;
		static const Sbecore::uint IMEIMEVENT = 4;
		static const Sbecore::uint IMEIMRTBLOCK = 5;
		static const Sbecore::uint IMEIMRTDPCH = 6;
		static const Sbecore::uint IMEIMRTJOB = 7;
		static const Sbecore::uint IMEIMSEQUENCE = 8;
		static const Sbecore::uint IMEIMSTATE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIMEvent (full: ImeitemIWznmAppMEvent)
		*/
	class ImeitemIMEvent : public WznmMEvent {

	public:
		ImeitemIMEvent(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMEvent(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIMEvent (full: ImeIWznmAppMEvent)
		*/
	class ImeIMEvent {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppMEventIel)
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
		ImeIMEvent();
		~ImeIMEvent();

	public:
		std::vector<ImeitemIMEvent*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRtblock (full: ImeitemIWznmAppMRtblock)
		*/
	class ImeitemIMRtblock : public WznmMRtblock {

	public:
		ImeitemIMRtblock(const Sbecore::uint refIxVTbl = 0, const std::string& srefRefUref = "", const std::string& sref = "", const std::string& srcSrefsWznmAMBlockItem = "");
		ImeitemIMRtblock(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefIxVTbl;
		std::string srefRefUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRtblock (full: ImeIWznmAppMRtblock)
		*/
	class ImeIMRtblock {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppMRtblockIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFIXVTBL = 1;
			static const Sbecore::uint SREFREFUREF = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SRCSREFSWZNMAMBLOCKITEM = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRtblock();
		~ImeIMRtblock();

	public:
		std::vector<ImeitemIMRtblock*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRtdpch (full: ImeitemIWznmAppMRtdpch)
		*/
	class ImeitemIMRtdpch : public WznmMRtdpch {

	public:
		ImeitemIMRtdpch(const std::string& srefRefWznmMBlock = "", const std::string& sref = "", const bool Merge = false);
		ImeitemIMRtdpch(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWznmMBlock;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRtdpch (full: ImeIWznmAppMRtdpch)
		*/
	class ImeIMRtdpch {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppMRtdpchIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWZNMMBLOCK = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint MERGE = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRtdpch();
		~ImeIMRtdpch();

	public:
		std::vector<ImeitemIMRtdpch*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRtjob (full: ImeitemIWznmAppMRtjob)
		*/
	class ImeitemIMRtjob : public WznmMRtjob {

	public:
		ImeitemIMRtjob(const Sbecore::ubigint iref = 0, const Sbecore::ubigint irefSupRefWznmMRtjob = 0, const std::string& srefRefWznmMJob = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMRtjob(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		Sbecore::ubigint irefSupRefWznmMRtjob;
		std::string srefRefWznmMJob;

		ImeIMRtblock imeimrtblock;
		ImeIMRtdpch imeimrtdpch;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRtjob (full: ImeIWznmAppMRtjob)
		*/
	class ImeIMRtjob {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppMRtjobIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint IREFSUPREFWZNMMRTJOB = 2;
			static const Sbecore::uint SREFREFWZNMMJOB = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRtjob();
		~ImeIMRtjob();

	public:
		std::vector<ImeitemIMRtjob*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMStateAction (full: ImeitemIWznmAppAMStateAction)
		*/
	class ImeitemIAMStateAction : public WznmAMStateAction {

	public:
		ImeitemIAMStateAction(const Sbecore::uint ixVSection = 0, const Sbecore::uint ixVType = 0, const Sbecore::ubigint irefRefWznmMRtjob = 0, const std::string& srefRefWznmMVector = "", const std::string& srefRefWznmMVectoritem = "", const std::string& srefSnxRefWznmMState = "", const std::string& srefRefWznmMSequence = "", const std::string& tr1SrefATrig = "", const std::string& Ip1 = "", const std::string& tr2SrefATrig = "", const std::string& Ip2 = "", const std::string& tr3SrefATrig = "", const std::string& Ip3 = "", const std::string& tr4SrefATrig = "", const std::string& Ip4 = "");
		ImeitemIAMStateAction(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVSection;
		std::string srefIxVType;
		Sbecore::ubigint irefRefWznmMRtjob;
		std::string srefRefWznmMVector;
		std::string srefRefWznmMVectoritem;
		std::string srefSnxRefWznmMState;
		std::string srefRefWznmMSequence;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMStateAction (full: ImeIWznmAppAMStateAction)
		*/
	class ImeIAMStateAction {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppAMStateActionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSECTION = 1;
			static const Sbecore::uint SREFIXVTYPE = 2;
			static const Sbecore::uint IREFREFWZNMMRTJOB = 4;
			static const Sbecore::uint SREFREFWZNMMVECTOR = 8;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 16;
			static const Sbecore::uint SREFSNXREFWZNMMSTATE = 32;
			static const Sbecore::uint SREFREFWZNMMSEQUENCE = 64;
			static const Sbecore::uint TR1SREFATRIG = 128;
			static const Sbecore::uint IP1 = 256;
			static const Sbecore::uint TR2SREFATRIG = 512;
			static const Sbecore::uint IP2 = 1024;
			static const Sbecore::uint TR3SREFATRIG = 2048;
			static const Sbecore::uint IP3 = 4096;
			static const Sbecore::uint TR4SREFATRIG = 8192;
			static const Sbecore::uint IP4 = 16384;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMStateAction();
		~ImeIAMStateAction();

	public:
		std::vector<ImeitemIAMStateAction*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAMStateTrigCond (full: ImeitemIWznmAppJAMStateTrigCond)
		*/
	class ImeitemIJAMStateTrigCond : public WznmJAMStateTrigCond {

	public:
		ImeitemIJAMStateTrigCond(const Sbecore::uint x1IxWznmVApptarget = 0, const std::string& Cond = "");
		ImeitemIJAMStateTrigCond(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWznmVApptarget;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAMStateTrigCond (full: ImeIWznmAppJAMStateTrigCond)
		*/
	class ImeIJAMStateTrigCond {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppJAMStateTrigCondIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZNMVAPPTARGET = 1;
			static const Sbecore::uint COND = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAMStateTrigCond();
		~ImeIJAMStateTrigCond();

	public:
		std::vector<ImeitemIJAMStateTrigCond*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMStateTrig (full: ImeitemIWznmAppAMStateTrig)
		*/
	class ImeitemIAMStateTrig : public WznmAMStateTrig {

	public:
		ImeitemIAMStateTrig(const std::string& sref = "", const Sbecore::uint ixVType = 0, const std::string& srefRefWznmMEvent = "", const Sbecore::ubigint irefRefWznmMRtjob = 0, const std::string& srefRefWznmMVectoritem = "", const std::string& xsref = "", const std::string& srefRefWznmMRtdpch = "", const std::string& srefsMask = "", const std::string& Cond = "");
		ImeitemIAMStateTrig(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVType;
		std::string srefRefWznmMEvent;
		Sbecore::ubigint irefRefWznmMRtjob;
		std::string srefRefWznmMVectoritem;
		std::string srefRefWznmMRtdpch;

		ImeIJAMStateTrigCond imeijamstatetrigcond;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMStateTrig (full: ImeIWznmAppAMStateTrig)
		*/
	class ImeIAMStateTrig {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppAMStateTrigIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVTYPE = 2;
			static const Sbecore::uint SREFREFWZNMMEVENT = 4;
			static const Sbecore::uint IREFREFWZNMMRTJOB = 8;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 16;
			static const Sbecore::uint XSREF = 32;
			static const Sbecore::uint SREFREFWZNMMRTDPCH = 64;
			static const Sbecore::uint SREFSMASK = 128;
			static const Sbecore::uint COND = 256;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMStateTrig();
		~ImeIAMStateTrig();

	public:
		std::vector<ImeitemIAMStateTrig*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMState (full: ImeitemIWznmAppMState)
		*/
	class ImeitemIMState : public WznmMState {

	public:
		ImeitemIMState(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMState(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMStateAction imeiamstateaction;
		ImeIAMStateTrig imeiamstatetrig;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMState (full: ImeIWznmAppMState)
		*/
	class ImeIMState {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppMStateIel)
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
		ImeIMState();
		~ImeIMState();

	public:
		std::vector<ImeitemIMState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSequence (full: ImeitemIWznmAppMSequence)
		*/
	class ImeitemIMSequence : public WznmMSequence {

	public:
		ImeitemIMSequence(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMSequence(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMState imeimstate;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSequence (full: ImeIWznmAppMSequence)
		*/
	class ImeIMSequence {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppMSequenceIel)
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
		ImeIMSequence();
		~ImeIMSequence();

	public:
		std::vector<ImeitemIMSequence*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMEvent& imeimevent, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMEvent& imeimevent, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMEvent& imeimevent, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMEvent& imeimevent, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);

	void writeTxt(std::fstream& outfile, ImeIMEvent& imeimevent, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMEvent& imeimevent, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

