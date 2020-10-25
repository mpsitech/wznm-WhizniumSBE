/**
	* \file IexWznmJob.h
	* data blocks and readers/writers for import/export complex IexWznmJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef IEXWZNMJOB_H
#define IEXWZNMJOB_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmJobIme IexWznmJob::VecVIme

#define ImeitemIWznmJobRMCapabilityUniversal IexWznmJob::ImeitemIRMCapabilityUniversal
#define ImeIWznmJobRMCapabilityUniversal IexWznmJob::ImeIRMCapabilityUniversal
#define VecWImeIWznmJobRMCapabilityUniversalIel IexWznmJob::ImeIRMCapabilityUniversal::VecWIel

#define ImeitemIWznmJobMCapability IexWznmJob::ImeitemIMCapability
#define ImeIWznmJobMCapability IexWznmJob::ImeIMCapability
#define VecWImeIWznmJobMCapabilityIel IexWznmJob::ImeIMCapability::VecWIel

#define ImeitemIWznmJobJAMBlockItem IexWznmJob::ImeitemIJAMBlockItem
#define ImeIWznmJobJAMBlockItem IexWznmJob::ImeIJAMBlockItem
#define VecWImeIWznmJobJAMBlockItemIel IexWznmJob::ImeIJAMBlockItem::VecWIel

#define ImeitemIWznmJobAMBlockItem IexWznmJob::ImeitemIAMBlockItem
#define ImeIWznmJobAMBlockItem IexWznmJob::ImeIAMBlockItem
#define VecWImeIWznmJobAMBlockItemIel IexWznmJob::ImeIAMBlockItem::VecWIel

#define ImeitemIWznmJobCAMBlockItem IexWznmJob::ImeitemICAMBlockItem
#define ImeIWznmJobCAMBlockItem IexWznmJob::ImeICAMBlockItem
#define VecWImeIWznmJobCAMBlockItemIel IexWznmJob::ImeICAMBlockItem::VecWIel

#define ImeitemIWznmJobMBlock IexWznmJob::ImeitemIMBlock
#define ImeIWznmJobMBlock IexWznmJob::ImeIMBlock
#define VecWImeIWznmJobMBlockIel IexWznmJob::ImeIMBlock::VecWIel

#define ImeitemIWznmJobMJob IexWznmJob::ImeitemIMJob
#define ImeIWznmJobMJob IexWznmJob::ImeIMJob
#define VecWImeIWznmJobMJobIel IexWznmJob::ImeIMJob::VecWIel

/**
	* IexWznmJob
	*/
namespace IexWznmJob {
	/**
		* VecVIme (full: VecVIexWznmJobIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMBLOCKITEM = 1;
		static const Sbecore::uint IMEICAMBLOCKITEM = 2;
		static const Sbecore::uint IMEIJAMBLOCKITEM = 3;
		static const Sbecore::uint IMEIMBLOCK = 4;
		static const Sbecore::uint IMEIMCAPABILITY = 5;
		static const Sbecore::uint IMEIMJOB = 6;
		static const Sbecore::uint IMEIRMCAPABILITYUNIVERSAL = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIRMCapabilityUniversal (full: ImeitemIWznmJobRMCapabilityUniversal)
		*/
	class ImeitemIRMCapabilityUniversal : public WznmRMCapabilityUniversal {

	public:
		ImeitemIRMCapabilityUniversal(const std::string& srefUnvUref = "", const std::string& srefKKey = "");
		ImeitemIRMCapabilityUniversal(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefUnvUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCapabilityUniversal (full: ImeIWznmJobRMCapabilityUniversal)
		*/
	class ImeIRMCapabilityUniversal {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobRMCapabilityUniversalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFUNVUREF = 1;
			static const Sbecore::uint SREFKKEY = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMCapabilityUniversal();
		~ImeIRMCapabilityUniversal();

	public:
		std::vector<ImeitemIRMCapabilityUniversal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCapability (full: ImeitemIWznmJobMCapability)
		*/
	class ImeitemIMCapability : public WznmMCapability {

	public:
		ImeitemIMCapability(const std::string& sref = "");
		ImeitemIMCapability(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIRMCapabilityUniversal imeirmcapabilityuniversal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCapability (full: ImeIWznmJobMCapability)
		*/
	class ImeIMCapability {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobMCapabilityIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;

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
		* ImeitemIJAMBlockItem (full: ImeitemIWznmJobJAMBlockItem)
		*/
	class ImeitemIJAMBlockItem : public WznmJAMBlockItem {

	public:
		ImeitemIJAMBlockItem(const std::string& Defval = "", const std::string& srefRefWznmMVectoritem = "");
		ImeitemIJAMBlockItem(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJAMBlockItem (full: ImeIWznmJobJAMBlockItem)
		*/
	class ImeIJAMBlockItem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobJAMBlockItemIel)
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
		* ImeitemIAMBlockItem (full: ImeitemIWznmJobAMBlockItem)
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
		* ImeIAMBlockItem (full: ImeIWznmJobAMBlockItem)
		*/
	class ImeIAMBlockItem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobAMBlockItemIel)
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
		* ImeitemICAMBlockItem (full: ImeitemIWznmJobCAMBlockItem)
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
		* ImeICAMBlockItem (full: ImeIWznmJobCAMBlockItem)
		*/
	class ImeICAMBlockItem {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobCAMBlockItemIel)
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
		* ImeitemIMBlock (full: ImeitemIWznmJobMBlock)
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
		* ImeIMBlock (full: ImeIWznmJobMBlock)
		*/
	class ImeIMBlock {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobMBlockIel)
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
		* ImeitemIMJob (full: ImeitemIWznmJobMJob)
		*/
	class ImeitemIMJob : public WznmMJob {

	public:
		ImeitemIMJob(const std::string& sref = "", const bool Clisrv = false, const bool Shrdat = false, const std::string& Comment = "");
		ImeitemIMJob(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMBlock imeimblock;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMJob (full: ImeIWznmJobMJob)
		*/
	class ImeIMJob {

	public:
		/**
			* VecWIel (full: VecWImeIWznmJobMJobIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint CLISRV = 2;
			static const Sbecore::uint SHRDAT = 4;
			static const Sbecore::uint COMMENT = 8;

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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMCapability& imeimcapability, ImeIMJob& imeimjob);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMCapability& imeimcapability, ImeIMJob& imeimjob);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMCapability& imeimcapability, ImeIMJob& imeimjob);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMCapability& imeimcapability, ImeIMJob& imeimjob);

	void writeTxt(std::fstream& outfile, ImeIMCapability& imeimcapability, ImeIMJob& imeimjob);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMCapability& imeimcapability, ImeIMJob& imeimjob);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

