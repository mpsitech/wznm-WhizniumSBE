/**
	* \file IexWznmVis.h
	* data blocks and readers/writers for import/export complex IexWznmVis (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef IEXWZNMVIS_H
#define IEXWZNMVIS_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWznm.h"
#include "VecWznmVIop.h"

#define VecVIexWznmVisIme IexWznmVis::VecVIme

#define ImeitemIWznmVisRMBoxMBox IexWznmVis::ImeitemIRMBoxMBox
#define ImeIWznmVisRMBoxMBox IexWznmVis::ImeIRMBoxMBox
#define VecWImeIWznmVisRMBoxMBoxIel IexWznmVis::ImeIRMBoxMBox::VecWIel

#define ImeitemIWznmVisMBox IexWznmVis::ImeitemIMBox
#define ImeIWznmVisMBox IexWznmVis::ImeIMBox
#define VecWImeIWznmVisMBoxIel IexWznmVis::ImeIMBox::VecWIel

#define ImeitemIWznmVisMSheet IexWznmVis::ImeitemIMSheet
#define ImeIWznmVisMSheet IexWznmVis::ImeIMSheet
#define VecWImeIWznmVisMSheetIel IexWznmVis::ImeIMSheet::VecWIel

/**
	* IexWznmVis
	*/
namespace IexWznmVis {
	/**
		* VecVIme (full: VecVIexWznmVisIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIMBOX = 1;
		static const Sbecore::uint IMEIMSHEET = 2;
		static const Sbecore::uint IMEIRMBOXMBOX = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIRMBoxMBox (full: ImeitemIWznmVisRMBoxMBox)
		*/
	class ImeitemIRMBoxMBox : public WznmRMBoxMBox {

	public:
		ImeitemIRMBoxMBox(const Sbecore::ubigint irefDstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
		ImeitemIRMBoxMBox(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefDstRefWznmMBox;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMBoxMBox (full: ImeIWznmVisRMBoxMBox)
		*/
	class ImeIRMBoxMBox {

	public:
		/**
			* VecWIel (full: VecWImeIWznmVisRMBoxMBoxIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFDSTREFWZNMMBOX = 1;
			static const Sbecore::uint ORGCLK = 2;
			static const Sbecore::uint DSTCLK = 4;
			static const Sbecore::uint WEIGHT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMBoxMBox();
		~ImeIRMBoxMBox();

	public:
		std::vector<ImeitemIRMBoxMBox*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMBox (full: ImeitemIWznmVisMBox)
		*/
	class ImeitemIMBox : public WznmMBox {

	public:
		ImeitemIMBox(const Sbecore::ubigint iref = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const std::string& srefUnvUref = "", const Sbecore::smallint x = 0, const Sbecore::smallint y = 0);
		ImeitemIMBox(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		std::string srefUnvIxWznmVMaintable;
		std::string srefUnvUref;

		ImeIRMBoxMBox imeirmboxmbox;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBox (full: ImeIWznmVisMBox)
		*/
	class ImeIMBox {

	public:
		/**
			* VecWIel (full: VecWImeIWznmVisMBoxIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint SREFUNVIXWZNMVMAINTABLE = 2;
			static const Sbecore::uint SREFUNVUREF = 4;
			static const Sbecore::uint X = 8;
			static const Sbecore::uint Y = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMBox();
		~ImeIMBox();

	public:
		std::vector<ImeitemIMBox*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSheet (full: ImeitemIWznmVisMSheet)
		*/
	class ImeitemIMSheet : public WznmMSheet {

	public:
		ImeitemIMSheet(const std::string& Title = "");
		ImeitemIMSheet(DbsWznm* dbswznm, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMBox imeimbox;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSheet (full: ImeIWznmVisMSheet)
		*/
	class ImeIMSheet {

	public:
		/**
			* VecWIel (full: VecWImeIWznmVisMSheetIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint TITLE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSheet();
		~ImeIMSheet();

	public:
		std::vector<ImeitemIMSheet*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMSheet& imeimsheet);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMSheet& imeimsheet);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMSheet& imeimsheet);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMSheet& imeimsheet);

	void writeTxt(std::fstream& outfile, ImeIMSheet& imeimsheet);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMSheet& imeimsheet);

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIopInsAll();
	Sbecore::uint getIxWznmVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWznmVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWznmVIop);
};

#endif
