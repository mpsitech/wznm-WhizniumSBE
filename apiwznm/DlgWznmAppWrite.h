/**
	* \file DlgWznmAppWrite.h
	* API code for job DlgWznmAppWrite (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef DLGWZNMAPPWRITE_H
#define DLGWZNMAPPWRITE_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmAppWriteDit DlgWznmAppWrite::VecVDit
#define VecVDlgWznmAppWriteDo DlgWznmAppWrite::VecVDo
#define VecVDlgWznmAppWriteDoWrc DlgWznmAppWrite::VecVDoWrc
#define VecVDlgWznmAppWriteSge DlgWznmAppWrite::VecVSge

#define ContIacDlgWznmAppWrite DlgWznmAppWrite::ContIac
#define ContIacDlgWznmAppWriteDet DlgWznmAppWrite::ContIacDet
#define ContInfDlgWznmAppWrite DlgWznmAppWrite::ContInf
#define ContInfDlgWznmAppWriteFia DlgWznmAppWrite::ContInfFia
#define ContInfDlgWznmAppWriteLfi DlgWznmAppWrite::ContInfLfi
#define ContInfDlgWznmAppWriteWrc DlgWznmAppWrite::ContInfWrc
#define StatAppDlgWznmAppWrite DlgWznmAppWrite::StatApp
#define StatShrDlgWznmAppWrite DlgWznmAppWrite::StatShr
#define StatShrDlgWznmAppWriteCuc DlgWznmAppWrite::StatShrCuc
#define StatShrDlgWznmAppWriteFia DlgWznmAppWrite::StatShrFia
#define StatShrDlgWznmAppWriteLfi DlgWznmAppWrite::StatShrLfi
#define StatShrDlgWznmAppWriteWrc DlgWznmAppWrite::StatShrWrc
#define TagDlgWznmAppWrite DlgWznmAppWrite::Tag
#define TagDlgWznmAppWriteCuc DlgWznmAppWrite::TagCuc
#define TagDlgWznmAppWriteDet DlgWznmAppWrite::TagDet
#define TagDlgWznmAppWriteFia DlgWznmAppWrite::TagFia
#define TagDlgWznmAppWriteLfi DlgWznmAppWrite::TagLfi
#define TagDlgWznmAppWriteWrc DlgWznmAppWrite::TagWrc

#define DpchAppDlgWznmAppWriteData DlgWznmAppWrite::DpchAppData
#define DpchAppDlgWznmAppWriteDo DlgWznmAppWrite::DpchAppDo
#define DpchEngDlgWznmAppWriteData DlgWznmAppWrite::DpchEngData

/**
	* DlgWznmAppWrite
	*/
namespace DlgWznmAppWrite {
	/**
		* VecVDit (full: VecVDlgWznmAppWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint CUC = 2;
		static const Sbecore::uint WRC = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint FIA = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmAppWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWznmAppWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmAppWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRMER = 2;
		static const Sbecore::uint UPKIDLE = 3;
		static const Sbecore::uint UNPACK = 4;
		static const Sbecore::uint UPKDONE = 5;
		static const Sbecore::uint WRITE = 6;
		static const Sbecore::uint MRGGNR = 7;
		static const Sbecore::uint MRGCUST = 8;
		static const Sbecore::uint PACK = 9;
		static const Sbecore::uint FAIL = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmAppWrite)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgWznmAppWriteDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CHKUSF = 1;

	public:
		ContIacDet(const bool ChkUsf = false);

	public:
		bool ChkUsf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmAppWrite)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfFia (full: ContInfDlgWznmAppWriteFia)
	  */
	class ContInfFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfFia(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfFia* comp);
		std::set<Sbecore::uint> diff(const ContInfFia* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmAppWriteLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * ContInfWrc (full: ContInfDlgWznmAppWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWrc(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfWrc* comp);
		std::set<Sbecore::uint> diff(const ContInfWrc* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmAppWrite)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONE = 1;
		static const Sbecore::uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const std::string& shortMenu = "");

	public:
		bool initdone;
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWznmAppWrite)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrCuc (full: StatShrDlgWznmAppWriteCuc)
	  */
	class StatShrCuc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrCuc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
	  * StatShrFia (full: StatShrDlgWznmAppWriteFia)
	  */
	class StatShrFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmAppWriteLfi)
	  */
	class StatShrLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
	  * StatShrWrc (full: StatShrDlgWznmAppWriteWrc)
	  */
	class StatShrWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWrc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
	  * Tag (full: TagDlgWznmAppWrite)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint BUTDNE = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagCuc (full: TagDlgWznmAppWriteCuc)
	  */
	class TagCuc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagCuc(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagDet (full: TagDlgWznmAppWriteDet)
	  */
	class TagDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTUSF = 1;

	public:
		TagDet(const std::string& CptUsf = "");

	public:
		std::string CptUsf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagFia (full: TagDlgWznmAppWriteFia)
	  */
	class TagFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagFia(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWznmAppWriteLfi)
	  */
	class TagLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagLfi(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagWrc (full: TagDlgWznmAppWriteWrc)
	  */
	class TagWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagWrc(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmAppWriteData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmAppWriteDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOWRC = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoWrc = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoWrc;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmAppWriteData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFFIA = 5;
		static const Sbecore::uint CONTINFLFI = 6;
		static const Sbecore::uint CONTINFWRC = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRCUC = 12;
		static const Sbecore::uint STATSHRFIA = 13;
		static const Sbecore::uint STATSHRLFI = 14;
		static const Sbecore::uint STATSHRWRC = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGCUC = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGFIA = 19;
		static const Sbecore::uint TAGLFI = 20;
		static const Sbecore::uint TAGWRC = 21;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfFia continffia;
		ContInfLfi continflfi;
		ContInfWrc continfwrc;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrCuc statshrcuc;
		StatShrFia statshrfia;
		StatShrLfi statshrlfi;
		StatShrWrc statshrwrc;
		Tag tag;
		TagCuc tagcuc;
		TagDet tagdet;
		TagFia tagfia;
		TagLfi taglfi;
		TagWrc tagwrc;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

