/**
	* \file PnlWznmPrsDetail.h
	* job handler for job PnlWznmPrsDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMPRSDETAIL_H
#define PNLWZNMPRSDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmPrsDetailDo PnlWznmPrsDetail::VecVDo

#define ContIacWznmPrsDetail PnlWznmPrsDetail::ContIac
#define ContInfWznmPrsDetail PnlWznmPrsDetail::ContInf
#define StatAppWznmPrsDetail PnlWznmPrsDetail::StatApp
#define StatShrWznmPrsDetail PnlWznmPrsDetail::StatShr
#define TagWznmPrsDetail PnlWznmPrsDetail::Tag

#define DpchAppWznmPrsDetailData PnlWznmPrsDetail::DpchAppData
#define DpchAppWznmPrsDetailDo PnlWznmPrsDetail::DpchAppDo
#define DpchEngWznmPrsDetailData PnlWznmPrsDetail::DpchEngData

/**
	* PnlWznmPrsDetail
	*/
class PnlWznmPrsDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJLNEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmPrsDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFNM = 2;
		static const Sbecore::uint NUMFPUPJLN = 3;
		static const Sbecore::uint NUMSFLSTDRV = 4;
		static const Sbecore::uint NUMFPUPSEX = 5;
		static const Sbecore::uint TXFTEL = 6;
		static const Sbecore::uint TXFEML = 7;
		static const Sbecore::uint TXFSAL = 8;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFnm = "", const Sbecore::uint numFPupJln = 1, const std::vector<Sbecore::uint>& numsFLstDrv = {}, const Sbecore::uint numFPupSex = 1, const std::string& TxfTel = "", const std::string& TxfEml = "", const std::string& TxfSal = "");

	public:
		std::string TxfTit;
		std::string TxfFnm;
		Sbecore::uint numFPupJln;
		std::vector<Sbecore::uint> numsFLstDrv;
		Sbecore::uint numFPupSex;
		std::string TxfTel;
		std::string TxfEml;
		std::string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmPrsDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTLNM = 1;
		static const Sbecore::uint TXTDRV = 2;

	public:
		ContInf(const std::string& TxtLnm = "", const std::string& TxtDrv = "");

	public:
		std::string TxtLnm;
		std::string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmPrsDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstDrvAlt = true, const Sbecore::uint LstDrvNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmPrsDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFTITACTIVE = 3;
		static const Sbecore::uint TXFFNMACTIVE = 4;
		static const Sbecore::uint PUPJLNACTIVE = 5;
		static const Sbecore::uint BUTJLNEDITAVAIL = 6;
		static const Sbecore::uint TXTLNMACTIVE = 7;
		static const Sbecore::uint LSTDRVACTIVE = 8;
		static const Sbecore::uint PUPSEXACTIVE = 9;
		static const Sbecore::uint TXFTELACTIVE = 10;
		static const Sbecore::uint TXFEMLACTIVE = 11;
		static const Sbecore::uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJlnActive = true, const bool ButJlnEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJlnActive;
		bool ButJlnEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmPrsDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmPrsDetailData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmPrsDetailDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmPrsDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDRV = 4;
		static const Sbecore::uint FEEDFPUPJLN = 5;
		static const Sbecore::uint FEEDFPUPSEX = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstDrv = NULL, Sbecore::Xmlio::Feed* feedFPupJln = NULL, Sbecore::Xmlio::Feed* feedFPupSex = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDrv;
		Sbecore::Xmlio::Feed feedFPupJln;
		Sbecore::Xmlio::Feed feedFPupSex;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxfTitActive(DbsWznm* dbswznm);
	bool evalTxfFnmActive(DbsWznm* dbswznm);
	bool evalPupJlnActive(DbsWznm* dbswznm);
	bool evalButJlnEditAvail(DbsWznm* dbswznm);
	bool evalTxtLnmActive(DbsWznm* dbswznm);
	bool evalLstDrvActive(DbsWznm* dbswznm);
	bool evalPupSexActive(DbsWznm* dbswznm);
	bool evalTxfTelActive(DbsWznm* dbswznm);
	bool evalTxfEmlActive(DbsWznm* dbswznm);
	bool evalTxfSalActive(DbsWznm* dbswznm);

public:
	PnlWznmPrsDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmPrsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstDrv;
	Sbecore::Xmlio::Feed feedFPupJln;
	Sbecore::Xmlio::Feed feedFPupSex;

	WznmMPerson recPrs;

	WznmJMPersonLastname recPrsJlnm;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJln(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxtDrv(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecPrs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecPrsJlnm(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJlnEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmPrsJlnmMod_prsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPrsUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif

