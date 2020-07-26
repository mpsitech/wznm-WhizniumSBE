/**
	* \file IexWznmIex.h
	* data blocks and readers/writers for import/export complex IexWznmIex (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef IEXWZNMIEX_H
#define IEXWZNMIEX_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmIexIme IexWznmIex::VecVIme

#define ImeitemIWznmIexJMImpexpcplxTitle IexWznmIex::ImeitemIJMImpexpcplxTitle
#define ImeIWznmIexJMImpexpcplxTitle IexWznmIex::ImeIJMImpexpcplxTitle
#define VecWImeIWznmIexJMImpexpcplxTitleIel IexWznmIex::ImeIJMImpexpcplxTitle::VecWIel

#define ImeitemIWznmIexJMImpexpcolStub IexWznmIex::ImeitemIJMImpexpcolStub
#define ImeIWznmIexJMImpexpcolStub IexWznmIex::ImeIJMImpexpcolStub
#define VecWImeIWznmIexJMImpexpcolStubIel IexWznmIex::ImeIJMImpexpcolStub::VecWIel

#define ImeitemIWznmIexMImpexpcol IexWznmIex::ImeitemIMImpexpcol
#define ImeIWznmIexMImpexpcol IexWznmIex::ImeIMImpexpcol
#define VecWImeIWznmIexMImpexpcolIel IexWznmIex::ImeIMImpexpcol::VecWIel

#define ImeitemIWznmIexMImpexp IexWznmIex::ImeitemIMImpexp
#define ImeIWznmIexMImpexp IexWznmIex::ImeIMImpexp
#define VecWImeIWznmIexMImpexpIel IexWznmIex::ImeIMImpexp::VecWIel

#define ImeitemIWznmIexMImpexpcplx IexWznmIex::ImeitemIMImpexpcplx
#define ImeIWznmIexMImpexpcplx IexWznmIex::ImeIMImpexpcplx
#define VecWImeIWznmIexMImpexpcplxIel IexWznmIex::ImeIMImpexpcplx::VecWIel

/**
	* IexWznmIex
	*/
namespace IexWznmIex {
	/**
		* VecVIme (full: VecVIexWznmIexIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIJMIMPEXPCOLSTUB = 1;
		static const Sbecore::uint IMEIJMIMPEXPCPLXTITLE = 2;
		static const Sbecore::uint IMEIMIMPEXP = 3;
		static const Sbecore::uint IMEIMIMPEXPCOL = 4;
		static const Sbecore::uint IMEIMIMPEXPCPLX = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIJMImpexpcplxTitle (full: ImeitemIWznmIexJMImpexpcplxTitle)
		*/
	class ImeitemIJMImpexpcplxTitle : public WznmJMImpexpcplxTitle {

	public:
		ImeitemIJMImpexpcplxTitle(const std::string& srefX1RefWznmMLocale = "", const std::string& Title = "");
		ImeitemIJMImpexpcplxTitle(DbsWznm* dbswznm, const Sbecore::ubigint ref);

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
		* ImeIJMImpexpcplxTitle (full: ImeIWznmIexJMImpexpcplxTitle)
		*/
	class ImeIJMImpexpcplxTitle {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIexJMImpexpcplxTitleIel)
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
		ImeIJMImpexpcplxTitle();
		~ImeIJMImpexpcplxTitle();

	public:
		std::vector<ImeitemIJMImpexpcplxTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMImpexpcolStub (full: ImeitemIWznmIexJMImpexpcolStub)
		*/
	class ImeitemIJMImpexpcolStub : public WznmJMImpexpcolStub {

	public:
		ImeitemIJMImpexpcolStub(const std::string& srefX1RefWznmMVectoritem = "", const std::string& srefRefWznmMStub = "");
		ImeitemIJMImpexpcolStub(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWznmMVectoritem;
		std::string srefRefWznmMStub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMImpexpcolStub (full: ImeIWznmIexJMImpexpcolStub)
		*/
	class ImeIJMImpexpcolStub {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIexJMImpexpcolStubIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWZNMMVECTORITEM = 1;
			static const Sbecore::uint SREFREFWZNMMSTUB = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMImpexpcolStub();
		~ImeIJMImpexpcolStub();

	public:
		std::vector<ImeitemIJMImpexpcolStub*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMImpexpcol (full: ImeitemIWznmIexMImpexpcol)
		*/
	class ImeitemIMImpexpcol : public WznmMImpexpcol {

	public:
		ImeitemIMImpexpcol(const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const std::string& srefRefWznmMTablecol = "", const std::string& sref = "", const std::string& Short = "", const Sbecore::ubigint irefRefWznmMImpexp = 0, const Sbecore::uint ixVConvtype = 0, const std::string& Defval = "", const std::string& srefRefWznmMPreset = "", const std::string& srefRefWznmMStub = "", const std::string& srefRefWznmMVectoritem = "");
		ImeitemIMImpexpcol(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefsIxWOccurrence;
		std::string srefRefWznmMTablecol;
		Sbecore::ubigint irefRefWznmMImpexp;
		std::string srefIxVConvtype;
		std::string srefRefWznmMPreset;
		std::string srefRefWznmMStub;
		std::string srefRefWznmMVectoritem;

		ImeIJMImpexpcolStub imeijmimpexpcolstub;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMImpexpcol (full: ImeIWznmIexMImpexpcol)
		*/
	class ImeIMImpexpcol {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIexMImpexpcolIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFSIXWOCCURRENCE = 2;
			static const Sbecore::uint SREFREFWZNMMTABLECOL = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SHORT = 16;
			static const Sbecore::uint IREFREFWZNMMIMPEXP = 32;
			static const Sbecore::uint SREFIXVCONVTYPE = 64;
			static const Sbecore::uint DEFVAL = 128;
			static const Sbecore::uint SREFREFWZNMMPRESET = 256;
			static const Sbecore::uint SREFREFWZNMMSTUB = 512;
			static const Sbecore::uint SREFREFWZNMMVECTORITEM = 1024;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMImpexpcol();
		~ImeIMImpexpcol();

	public:
		std::vector<ImeitemIMImpexpcol*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMImpexp (full: ImeitemIWznmIexMImpexp)
		*/
	class ImeitemIMImpexp : public WznmMImpexp {

	public:
		ImeitemIMImpexp(const Sbecore::ubigint iref = 0, const Sbecore::ubigint irefSupRefWznmMImpexp = 0, const std::string& srefRefWznmMTable = "", const std::string& sref = "", const std::string& rtrSrefsWznmMImpexpcol = "", const Sbecore::uint ixWIop = 0, const std::string& Comment = "");
		ImeitemIMImpexp(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		Sbecore::ubigint irefSupRefWznmMImpexp;
		std::string srefRefWznmMTable;
		std::string srefsIxWIop;

		ImeIMImpexpcol imeimimpexpcol;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMImpexp (full: ImeIWznmIexMImpexp)
		*/
	class ImeIMImpexp {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIexMImpexpIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint IREFSUPREFWZNMMIMPEXP = 2;
			static const Sbecore::uint SREFREFWZNMMTABLE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint RTRSREFSWZNMMIMPEXPCOL = 16;
			static const Sbecore::uint SREFSIXWIOP = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMImpexp();
		~ImeIMImpexp();

	public:
		std::vector<ImeitemIMImpexp*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMImpexpcplx (full: ImeitemIWznmIexMImpexpcplx)
		*/
	class ImeitemIMImpexpcplx : public WznmMImpexpcplx {

	public:
		ImeitemIMImpexpcplx(const std::string& sref = "", const std::string& Short = "", const std::string& Title = "", const std::string& Minversion = "", const std::string& Comment = "");
		ImeitemIMImpexpcplx(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMImpexpcplxTitle imeijmimpexpcplxtitle;
		ImeIMImpexp imeimimpexp;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMImpexpcplx (full: ImeIWznmIexMImpexpcplx)
		*/
	class ImeIMImpexpcplx {

	public:
		/**
			* VecWIel (full: VecWImeIWznmIexMImpexpcplxIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SHORT = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint MINVERSION = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMImpexpcplx();
		~ImeIMImpexpcplx();

	public:
		std::vector<ImeitemIMImpexpcplx*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMImpexpcplx& imeimimpexpcplx);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMImpexpcplx& imeimimpexpcplx);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMImpexpcplx& imeimimpexpcplx);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMImpexpcplx& imeimimpexpcplx);

	void writeTxt(std::fstream& outfile, ImeIMImpexpcplx& imeimimpexpcplx);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMImpexpcplx& imeimimpexpcplx);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif

