/**
	* \file DlgWznmRlsWrite.h
	* API code for job DlgWznmRlsWrite (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMRLSWRITE_H
#define DLGWZNMRLSWRITE_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmRlsWriteDit DlgWznmRlsWrite::VecVDit
#define VecVDlgWznmRlsWriteDo DlgWznmRlsWrite::VecVDo
#define VecVDlgWznmRlsWriteDoWrc DlgWznmRlsWrite::VecVDoWrc
#define VecVDlgWznmRlsWriteSge DlgWznmRlsWrite::VecVSge

#define ContIacDlgWznmRlsWrite DlgWznmRlsWrite::ContIac
#define ContIacDlgWznmRlsWriteDet DlgWznmRlsWrite::ContIacDet
#define ContInfDlgWznmRlsWrite DlgWznmRlsWrite::ContInf
#define ContInfDlgWznmRlsWriteFia DlgWznmRlsWrite::ContInfFia
#define ContInfDlgWznmRlsWriteLfi DlgWznmRlsWrite::ContInfLfi
#define ContInfDlgWznmRlsWriteWrc DlgWznmRlsWrite::ContInfWrc
#define StatAppDlgWznmRlsWrite DlgWznmRlsWrite::StatApp
#define StatShrDlgWznmRlsWrite DlgWznmRlsWrite::StatShr
#define StatShrDlgWznmRlsWriteCuc DlgWznmRlsWrite::StatShrCuc
#define StatShrDlgWznmRlsWriteFia DlgWznmRlsWrite::StatShrFia
#define StatShrDlgWznmRlsWriteLfi DlgWznmRlsWrite::StatShrLfi
#define StatShrDlgWznmRlsWriteWrc DlgWznmRlsWrite::StatShrWrc
#define TagDlgWznmRlsWrite DlgWznmRlsWrite::Tag
#define TagDlgWznmRlsWriteCuc DlgWznmRlsWrite::TagCuc
#define TagDlgWznmRlsWriteDet DlgWznmRlsWrite::TagDet
#define TagDlgWznmRlsWriteFia DlgWznmRlsWrite::TagFia
#define TagDlgWznmRlsWriteLfi DlgWznmRlsWrite::TagLfi
#define TagDlgWznmRlsWriteWrc DlgWznmRlsWrite::TagWrc

#define DpchAppDlgWznmRlsWriteData DlgWznmRlsWrite::DpchAppData
#define DpchAppDlgWznmRlsWriteDo DlgWznmRlsWrite::DpchAppDo
#define DpchEngDlgWznmRlsWriteData DlgWznmRlsWrite::DpchEngData

/**
	* DlgWznmRlsWrite
	*/
namespace DlgWznmRlsWrite {
	/**
		* VecVDit (full: VecVDlgWznmRlsWriteDit)
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
		* VecVDo (full: VecVDlgWznmRlsWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWznmRlsWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTAUTCLICK = 1;
		static const Sbecore::uint BUTRUNCLICK = 2;
		static const Sbecore::uint BUTSTOCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmRlsWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint ALRMER = 3;
		static const Sbecore::uint UPKIDLE = 4;
		static const Sbecore::uint UNPACK = 5;
		static const Sbecore::uint UPKDONE = 6;
		static const Sbecore::uint AUTH = 7;
		static const Sbecore::uint AUTDONE = 8;
		static const Sbecore::uint CREIDLE = 9;
		static const Sbecore::uint CREATE = 10;
		static const Sbecore::uint WRITE = 11;
		static const Sbecore::uint MRGGNR = 12;
		static const Sbecore::uint MRGSPEC = 13;
		static const Sbecore::uint MRGCTP = 14;
		static const Sbecore::uint MRGCUST = 15;
		static const Sbecore::uint PACK = 16;
		static const Sbecore::uint FAIL = 17;
		static const Sbecore::uint DONE = 18;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmRlsWrite)
	  */
	class ContIac : public Sbecore::Block {

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
	  * ContIacDet (full: ContIacDlgWznmRlsWriteDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint CHKBSO = 1;

	public:
		ContIacDet(const bool ChkBso = false);

	public:
		bool ChkBso;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmRlsWrite)
	  */
	class ContInf : public Sbecore::Block {

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
	  * ContInfFia (full: ContInfDlgWznmRlsWriteFia)
	  */
	class ContInfFia : public Sbecore::Block {

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
	  * ContInfLfi (full: ContInfDlgWznmRlsWriteLfi)
	  */
	class ContInfLfi : public Sbecore::Block {

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
	  * ContInfWrc (full: ContInfDlgWznmRlsWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Block {

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
	  * StatApp (full: StatAppDlgWznmRlsWrite)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrDlgWznmRlsWrite)
	  */
	class StatShr : public Sbecore::Block {

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
	  * StatShrCuc (full: StatShrDlgWznmRlsWriteCuc)
	  */
	class StatShrCuc : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;

	public:
		StatShrCuc(const bool UldAvail = true, const bool UldActive = true);

	public:
		bool UldAvail;
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
	  * StatShrFia (full: StatShrDlgWznmRlsWriteFia)
	  */
	class StatShrFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;

	public:
		StatShrFia(const bool DldAvail = true, const bool DldActive = true);

	public:
		bool DldAvail;
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmRlsWriteLfi)
	  */
	class StatShrLfi : public Sbecore::Block {

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
	  * StatShrWrc (full: StatShrDlgWznmRlsWriteWrc)
	  */
	class StatShrWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTAUTACTIVE = 1;
		static const Sbecore::uint BUTRUNACTIVE = 2;
		static const Sbecore::uint BUTSTOACTIVE = 3;

	public:
		StatShrWrc(const bool ButAutActive = true, const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButAutActive;
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
	  * Tag (full: TagDlgWznmRlsWrite)
	  */
	class Tag : public Sbecore::Block {

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
	  * TagCuc (full: TagDlgWznmRlsWriteCuc)
	  */
	class TagCuc : public Sbecore::Block {

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
	  * TagDet (full: TagDlgWznmRlsWriteDet)
	  */
	class TagDet : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTBSO = 1;

	public:
		TagDet(const std::string& CptBso = "");

	public:
		std::string CptBso;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagFia (full: TagDlgWznmRlsWriteFia)
	  */
	class TagFia : public Sbecore::Block {

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
	  * TagLfi (full: TagDlgWznmRlsWriteLfi)
	  */
	class TagLfi : public Sbecore::Block {

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
	  * TagWrc (full: TagDlgWznmRlsWriteWrc)
	  */
	class TagWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTAUT = 2;
		static const Sbecore::uint BUTRUN = 3;
		static const Sbecore::uint BUTSTO = 4;

	public:
		TagWrc(const std::string& CptPrg = "", const std::string& ButAut = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButAut;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmRlsWriteData)
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
		* DpchAppDo (full: DpchAppDlgWznmRlsWriteDo)
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
		* DpchEngData (full: DpchEngDlgWznmRlsWriteData)
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
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
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
