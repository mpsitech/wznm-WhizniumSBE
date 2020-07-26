/**
	* \file IexWznmApp.h
	* data blocks and readers/writers for import/export complex IexWznmApp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef IEXWZNMAPP_H
#define IEXWZNMAPP_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmAppIme IexWznmApp::VecVIme

#define ImeitemIWznmAppMRtblock IexWznmApp::ImeitemIMRtblock
#define ImeIWznmAppMRtblock IexWznmApp::ImeIMRtblock
#define VecWImeIWznmAppMRtblockIel IexWznmApp::ImeIMRtblock::VecWIel

#define ImeitemIWznmAppMRtdpch IexWznmApp::ImeitemIMRtdpch
#define ImeIWznmAppMRtdpch IexWznmApp::ImeIMRtdpch
#define VecWImeIWznmAppMRtdpchIel IexWznmApp::ImeIMRtdpch::VecWIel

#define ImeitemIWznmAppMRtjob IexWznmApp::ImeitemIMRtjob
#define ImeIWznmAppMRtjob IexWznmApp::ImeIMRtjob
#define VecWImeIWznmAppMRtjobIel IexWznmApp::ImeIMRtjob::VecWIel

#define ImeitemIWznmAppAMStateStep IexWznmApp::ImeitemIAMStateStep
#define ImeIWznmAppAMStateStep IexWznmApp::ImeIAMStateStep
#define VecWImeIWznmAppAMStateStepIel IexWznmApp::ImeIAMStateStep::VecWIel

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
		static const Sbecore::uint IMEIAMSTATESTEP = 1;
		static const Sbecore::uint IMEIMRTBLOCK = 2;
		static const Sbecore::uint IMEIMRTDPCH = 3;
		static const Sbecore::uint IMEIMRTJOB = 4;
		static const Sbecore::uint IMEIMSEQUENCE = 5;
		static const Sbecore::uint IMEIMSTATE = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
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
		* ImeitemIAMStateStep (full: ImeitemIWznmAppAMStateStep)
		*/
	class ImeitemIAMStateStep : public WznmAMStateStep {

	public:
		ImeitemIAMStateStep(const std::string& srefSnxRefWznmMState = "", const Sbecore::uint ixVTrigger = 0, const Sbecore::ubigint irefRefWznmMRtjob = 0, const std::string& srefRefWznmMVectoritem = "", const std::string& xsref = "", const std::string& srefRefWznmMRtdpch = "", const std::string& srefsMask = "", const std::string& Cond = "", const bool Custcode = false);
		ImeitemIAMStateStep(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSnxRefWznmMState;
		std::string srefIxVTrigger;
		Sbecore::ubigint irefRefWznmMRtjob;
		std::string srefRefWznmMVectoritem;
		std::string srefRefWznmMRtdpch;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMStateStep (full: ImeIWznmAppAMStateStep)
		*/
	class ImeIAMStateStep {

	public:
		/**
			* VecWIel (full: VecWImeIWznmAppAMStateStepIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSNXREFWZNMMSTATE = 1;
			static const Sbecore::uint SREFIXVTRIGGER = 2;
			static const Sbecore::uint IREFREFWZNMMRTJOB = 4;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 8;
			static const Sbecore::uint XSREF = 16;
			static const Sbecore::uint SREFREFWZNMMRTDPCH = 32;
			static const Sbecore::uint SREFSMASK = 64;
			static const Sbecore::uint COND = 128;
			static const Sbecore::uint CUSTCODE = 256;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMStateStep();
		~ImeIAMStateStep();

	public:
		std::vector<ImeitemIAMStateStep*> nodes;

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
		ImeitemIMState(const std::string& sref = "", const Sbecore::uint eacIxVAction = 0, const Sbecore::ubigint irefErjRefWznmMRtjob = 0, const std::string& srefEveRefWznmMVector = "", const std::string& srefEviRefWznmMVectoritem = "", const std::string& srefEsnRefWznmMState = "", const Sbecore::uint lacIxVAction = 0, const bool Custstep = false, const std::string& Comment = "");
		ImeitemIMState(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefEacIxVAction;
		Sbecore::ubigint irefErjRefWznmMRtjob;
		std::string srefEveRefWznmMVector;
		std::string srefEviRefWznmMVectoritem;
		std::string srefEsnRefWznmMState;
		std::string srefLacIxVAction;

		ImeIAMStateStep imeiamstatestep;

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
			static const Sbecore::uint SREFEACIXVACTION = 2;
			static const Sbecore::uint IREFERJREFWZNMMRTJOB = 4;
			static const Sbecore::uint SREFEVEREFWZNMMVECTOR = 8;
			static const Sbecore::uint SREFEVIREFWZNMMVECTORITEM = 16;
			static const Sbecore::uint SREFESNREFWZNMMSTATE = 32;
			static const Sbecore::uint SREFLACIXVACTION = 64;
			static const Sbecore::uint CUSTSTEP = 128;
			static const Sbecore::uint COMMENT = 256;

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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);

	void writeTxt(std::fstream& outfile, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMRtjob& imeimrtjob, ImeIMSequence& imeimsequence);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

